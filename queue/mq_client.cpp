#include <iostream>
#include <cstdlib>
#include <fcntl.h>
#include <mqueue.h>
#include <cstdio>
#include <cstring>

int main(int argc, char **argv) {
    struct mq_attr attr;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = 128;
    mqd_t mq;
    char buf[128] = {0};

    mq = mq_open("/test_mq", O_WRONLY, 0666, &attr);
    if (mq == (mqd_t)-1) {
        perror("open error");
        exit(0);
    }

    std::cin >> buf;  // C++ 스타일로 입력 받음

    if (mq_send(mq, buf, strlen(buf), 1) == -1) {
        perror("mq_send error");
        exit(-1);
    }

    mq_close(mq);

    return 0;
}
