#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fcntl.h>
#include <cstdio>
#include <mqueue.h>
#include <sys/stat.h>

int main() {
    struct mq_attr attr;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = 128;
    char buf[128] = {0};

    mqd_t mq;

    mq = mq_open("/test_mq", O_RDWR | O_CREAT, 0666, &attr);
    if (mq == (mqd_t)-1) {
        perror("message queue open error");
        exit(1);
    }

    if (mq_receive(mq, buf, attr.mq_msgsize, NULL) == -1) {
        perror("mq_receive error");
        exit(-1);
    }
    std::cout << "mq received : " << buf << std::endl;

    mq_close(mq);

    return 0;
}
