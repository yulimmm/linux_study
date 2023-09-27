#include <iostream>
#include <functional>
#include <csignal>
#include <chrono>

using namespace std;

// 콜백 함수 시그니처 정의
typedef std::function<void(const std::string&)> CallbackFunction;

// 콜백을 호출하는 함수
void CallCallback(const std::string& message, CallbackFunction callback) {
    std::cout << "전달된 메시지: " << message << std::endl;
    callback(message);  // 콜백 호출
}

// 실제로 호출될 콜백 함수
void MyCallback(const std::string& message) {
    std::cout << "콜백 함수 호출됨: " << message << std::endl;
}

CallbackFunction callback = MyCallback;

void timerHandler(int signo) {
    auto now = chrono::system_clock::now();
    auto timestamp = chrono::system_clock::to_time_t(now);
    cout<<"timestamp: "<<timestamp<<endl;
    CallCallback("안녕하세요!", callback);
}

void timer_settup(){
    timer_t timerId;
    struct sigevent sev;
    struct itimerspec its;

    // 타이머 이벤트를 시그널로 처리
    sev.sigev_notify = SIGEV_SIGNAL;
    sev.sigev_signo = SIGALRM;

    // 타이머 생성
    if (timer_create(CLOCK_REALTIME, &sev, &timerId) == -1) {
        perror("timer_create");
        exit(1);
    }

    // 타이머 설정
    its.it_value.tv_sec = 1; // 1초 후에 타이머 이벤트 발생
    its.it_value.tv_nsec = 0;
    its.it_interval.tv_sec = 2; // 2초마다 반복
    its.it_interval.tv_nsec = 0;

    // 타이머 설정 적용
    if (timer_settime(timerId, 0, &its, NULL) == -1) {
        perror("timer_settime");
        exit(1);
    }
    
    signal(SIGALRM, timerHandler);
}

int main() {
    timer_settup();

    while(1){

    }

    return 0;
}
