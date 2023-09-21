#include <iostream>
#include <ctime>
#include <csignal>
#include <cstdlib>
#include <unistd.h>

void timerHandler(int signo) {
    std::cout << "Timer expired!" << std::endl;
}

int main() {
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
    its.it_value.tv_sec = 2; // 2초 후에 타이머 이벤트 발생
    its.it_value.tv_nsec = 0;
    its.it_interval.tv_sec = 1; // 1초마다 반복
    its.it_interval.tv_nsec = 0;

    // 타이머 설정 적용
    if (timer_settime(timerId, 0, &its, NULL) == -1) {
        perror("timer_settime");
        exit(1);
    }

    // SIGALRM 시그널을 처리하는 핸들러 등록
    signal(SIGALRM, timerHandler);

    // 프로그램이 종료되지 않게 대기
    while (true) {
        pause();
    }

    return 0;
}
