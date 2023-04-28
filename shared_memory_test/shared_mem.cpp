#include <iostream>
#include<sys/shm.h> 
#define KEY_NUM 1234 
#define MEM_SIZE 1024


int main() {

//	int shmid;
//	void *address;

    uint8_t shmid;
    uint8_t *shmaddr;

    if( (shmid = shmget(IPC_PRIVATE, sizeof(uint8_t) ,IPC_CREAT|0644)) != (-1) ) { 
	shmaddr = (uint8_t *)shmat(shmid,(uint8_t *)NULL,0);
		printf("공유메모리 만들기 성공 ! \n");
		printf("shmid = %d\n",shmid);
		printf("공유메모리 주소(*shmaddr) : %p\n", shmaddr);
    } else printf("에러 입니다 !\n");

    return 0;
    
}

