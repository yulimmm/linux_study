#include <iostream>
#include <csignal>
#include <ctime>
#include <unistd.h>
#include <chrono>

using namespace std;

void handleSignal(int signal) {
    if (signal == SIGALRM) {
        std::cout << "Received SIGALRM signal!" << std::endl;
    }
}

int main() {

    signal(SIGALRM, handleSignal);

    while (true) {
        std::time_t currentTime = std::time(nullptr);
        int remainder = currentTime % 5;
        auto time_point = chrono::system_clock::now();
        auto duration = chrono::duration_cast<chrono::seconds>(time_point.time_since_epoch());
        int recv_time = duration.count();
        cout<<recv_time<<endl;

        if (remainder == 0) {
            std::cout << "Time is divisible by 5 seconds, sending SIGALRM" << std::endl;
            kill(getpid(), SIGALRM);
        }

        sleep(1);
    }

    return 0;
}
