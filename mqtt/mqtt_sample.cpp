#include <iostream>
#include <cstdlib>
#include <chrono> 
#include <atomic> 
#include "mqtt_ctl/mqtt_ctl.h"

using namespace std;

const string DFLT_SERVER_ADDRESS	{ "tcp://localhost:1883" };
const string TEST_CLIENT_ID				{ "paho_cpp_async_publish" };
const string PERSIST_DIR			{ "./persist" };

const string TOPIC { "hello" };

const char* PAYLOAD1 = "Hello World!";
const char* PAYLOAD2 = "Hi there!";
const char* PAYLOAD3 = "Is anyone listening?";
const char* PAYLOAD4 = "Someone is always listening.";

const char* LWT_PAYLOAD = "Last will and testament.";

const int  TEST_QOS = 1;

const auto TEST_TIMEOUT = std::chrono::seconds(10); 

/////////////////////////////////////////////////////////////////////////////

/**
 * A callback class for use with the main MQTT client.
 */

class test_callback : public virtual mqtt::callback
{
public:
	void connection_lost(const string& cause) override {
		cout << "\nConnection lost" << endl;
		if (!cause.empty())
			cout << "\tcause: " << cause << endl;
	}

	void delivery_complete(mqtt::delivery_token_ptr tok) override {
		cout << "\tDelivery complete for token: "
			<< (tok ? tok->get_message_id() : -1) << endl;
	}
};

/////////////////////////////////////////////////////////////////////////////

/**
 * A base action listener.
 */
class test_action_listener : public virtual mqtt::iaction_listener
{
protected:
	void on_failure(const mqtt::token& tok) override {
		cout << "\tListener failure for token: "
			<< tok.get_message_id() << endl;
	}

	void on_success(const mqtt::token& tok) override {
		cout << "\tListener success for token: "
			<< tok.get_message_id() << endl;
	}
};

/////////////////////////////////////////////////////////////////////////////

/**
 * A derived action listener for publish events.
 */
class delivery_action_listener : public test_action_listener
{
	atomic<bool> done_;

	void on_failure(const mqtt::token& tok) override {
		test_action_listener::on_failure(tok);
		done_ = true;
	}

	void on_success(const mqtt::token& tok) override {
		test_action_listener::on_success(tok);
		done_ = true;
	}

public:
	delivery_action_listener() : done_(false) {}
	bool is_done() const { return done_; }
};


int main(int argc, char* argv[])
{
// A client that just publishes normally doesn't need a persistent
	// session or Client ID unless it's using persistence, then the local
	// library requires an ID to identify the persistence files.

	string	address  = (argc > 1) ? string(argv[1]) : DFLT_SERVER_ADDRESS,
			clientID = (argc > 2) ? string(argv[2]) : TEST_CLIENT_ID;

	cout << "Initializing for server '" << address << "'..." << endl;
	mqtt::async_client client(address, clientID, PERSIST_DIR);

	test_callback cb;
	client.set_callback(cb);

	auto connOpts = mqtt::connect_options_builder() //mqtt 연결 옵션 설정
		.clean_session() //클린 세션 설정 (연결이 끊어진 경우 해당 클라이언트와 관련된 모든 세션 정보를 삭제)
		.will(mqtt::message(TOPIC, LWT_PAYLOAD, TEST_QOS)) //연결이 예기치않게 끊어질 경우 브로커에게 전달할 마지막 의사 표시 메시지를 설정. 
		.finalize(); //설정된 연결 옵션들을 최종적으로 완료. 

	cout << "  ...OK" << endl;

	try {
		cout << "\nConnecting..." << endl;
		mqtt::token_ptr conntok = client.connect(connOpts); //mqtt 클라이언트가 브로커에 연결을 시도. mqtt::token_ptr 은 mqtt 작업을 나타내느 포인터 타입. 
        //client 객체의 connect 함수를 호출하고 연결 옵션 connOpts를 전달하여 mqtt 브로커에 연결을 시도함. 
		cout << "Waiting for the connection..." << endl;
		conntok->wait();
		cout << "  ...OK" << endl;

		// First use a message pointer. 첫번째 방법

		cout << "\nSending message..." << endl;
		mqtt::message_ptr pubmsg = mqtt::make_message(TOPIC, PAYLOAD1);
		pubmsg->set_qos(TEST_QOS);
		client.publish(pubmsg)->wait_for(TEST_TIMEOUT);
		cout << "  ...OK" << endl;

		// Now try with itemized publish. 두번째 방법

		cout << "\nSending next message..." << endl;
		mqtt::delivery_token_ptr pubtok;
		pubtok = client.publish(TOPIC, PAYLOAD2, strlen(PAYLOAD2), TEST_QOS, false);
		cout << "  ...with token: " << pubtok->get_message_id() << endl;
		cout << "  ...for message with " << pubtok->get_message()->get_payload().size()
			<< " bytes" << endl;
		pubtok->wait_for(TEST_TIMEOUT);
		cout << "  ...OK" << endl;

		// Now try with a listener 세번째 방법

		cout << "\nSending next message..." << endl;
		test_action_listener listener;
		pubmsg = mqtt::make_message(TOPIC, PAYLOAD3);
		pubtok = client.publish(pubmsg, nullptr, listener);
		pubtok->wait();
		cout << "  ...OK" << endl;

		// Finally try with a listener, but no token 네번째 방법

		cout << "\nSending final message..." << endl;
		delivery_action_listener deliveryListener;
		pubmsg = mqtt::make_message(TOPIC, PAYLOAD4);
		client.publish(pubmsg, nullptr, deliveryListener);

		while (!deliveryListener.is_done()) {
			this_thread::sleep_for(std::chrono::milliseconds(100));
		}
		cout << "OK" << endl;

		// Double check that there are no pending tokens

		auto toks = client.get_pending_delivery_tokens();
		if (!toks.empty())
			cout << "Error: There are pending delivery tokens!" << endl;

		// Disconnect
		cout << "\nDisconnecting..." << endl;
		client.disconnect()->wait();
		cout << "  ...OK" << endl;
	}
	catch (const mqtt::exception& exc) {
		cerr << exc.what() << endl;
		return 1;
	}

 	return 0;
}

