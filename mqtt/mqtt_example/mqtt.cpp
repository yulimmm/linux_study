#include <iostream>
#include <cstdlib>
#include <cstring>
#include "mqtt/async_client.h"

const std::string SERVER_ADDRESS("tcp://localhost:1883");
const std::string CLIENT_ID("paho_cpp_example");
const std::string TOPIC("example_topic");

class callback : public virtual mqtt::callback {
  public:
    void connection_lost(const std::string& cause) override {
        if (!cause.empty()) {
            std::cerr << "Connection lost: " << cause << std::endl;
        }
    }

    void message_arrived(mqtt::const_message_ptr msg) override {
        std::cout << "Message arrived on topic '" << msg->get_topic() << "': " << msg->to_string() << std::endl;
    }
};

int main() {
    mqtt::async_client client(SERVER_ADDRESS, CLIENT_ID);
    callback cb;

    client.set_callback(cb);

    mqtt::connect_options connopts;
    connopts.set_keep_alive_interval(20);
    connopts.set_clean_session(true);

    try {
        client.connect(connopts)->wait();
        std::cout << "Connected to the MQTT broker" << std::endl;

        client.subscribe(TOPIC, 1)->wait();
        std::cout << "Subscribed to topic '" << TOPIC << "'" << std::endl;

        mqtt::message_ptr pubmsg = mqtt::make_message(TOPIC, "Hello, MQTT!");
        pubmsg->set_qos(1);

        client.publish(pubmsg)->wait();
        std::cout << "Published message: " << pubmsg->to_string() << std::endl;

        // Wait for a few seconds to receive messages
        //std::this_thread::sleep_for(std::chrono::seconds(5));
		while(true){}

        client.unsubscribe(TOPIC)->wait();
        client.disconnect()->wait();
    } catch (const mqtt::exception& exc) {
        std::cerr << "Error: " << exc.what() << std::endl;
    }

    return 0;
}
