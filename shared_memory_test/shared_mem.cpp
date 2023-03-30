#include <iostream>
#include<sys/shm.h> 
#define KEY_NUM 1234 
#define MEM_SIZE 1024


int main() {

	int shmid;
	void *address;

    uint8_t shmLiveboxid;
    uint8_t *shmLiveboxaddr;
/*
	if( (shmid = shmget(KEY_NUM,MEM_SIZE,IPC_CREAT | 0666)) != (-1) ) {
    
		address = shmat(shmid,NULL,0);
		printf("공유메모리 만들기 성공 ! \n");
		printf("shmid = %d\n",shmid);
		printf("공유메모리 주소 : %p\n", address);
        
	} else printf("에러 입니다 !\n");

    printf("=================================\n");
*/
    if( (shmLiveboxid = shmget(IPC_PRIVATE, sizeof(uint8_t) ,IPC_CREAT|0644)) != (-1) ) {
    
		shmLiveboxaddr = (uint8_t *)shmat(shmLiveboxid,(uint8_t *)NULL,0);
		printf("공유메모리 만들기 성공 ! \n");
		printf("shmLiveboxid = %d\n",shmLiveboxid);
		printf("공유메모리 주소(*shmLiveboxaddr) : %p\n", shmLiveboxaddr);
        
	} else printf("에러 입니다 !\n");

	return 0;
    
}

