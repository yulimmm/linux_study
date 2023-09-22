#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <mqueue.h>
#include <sys/stat.h>

int main()
{
    struct mq_attr attr;
    //attr 때문에 에러 발생할 수 있음
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = 128;
    char buf[128] = {0,};

    mqd_t mq;

    mq = mq_open("/reakwon_mq", O_RDWR | O_CREAT,  0666, &attr);
    if (mq == -1)
    {
            perror("message queue open error");
            exit(1);
    }

    if((mq_receive(mq, buf, attr.mq_msgsize,NULL)) == -1){
            perror("mq_receive error");
            exit(-1);
    }
    printf("mq received : %s\n", buf);
    mq_close(mq);
}
