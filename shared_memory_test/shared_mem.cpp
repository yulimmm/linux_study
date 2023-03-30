#include <iostream>
#include<sys/shm.h> 
#define KEY_NUM 1234 
#define MEM_SIZE 1024  


int main() {

	int shmid;
	void *address;
	if( (shmid = shmget(KEY_NUM,MEM_SIZE,IPC_CREAT | 0666)) != (-1) ) {
    
		address = shmat(shmid,NULL,0);
		printf("공유메모리 만들기 성공 ! \n");
		printf("shmid = %d\n",shmid);
		printf("공유메모리 주소 : %p", address);
        
	} else printf("에러 입니다 !\n");
	return 0;
    
}