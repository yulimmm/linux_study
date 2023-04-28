#include <cstdio>
#include <netinet/in.h>

int main(int argc, char **argv){
	int sockfd; //socket descripter

	if(argc <2 ){
		print("Usage:%s port \n",argv[0]);
		return -1;
	}

	if((sockfd=socket(PF_INET, SOCK_STREAM, 0))<0){
		perror("Socket failed !");
		return -1;
	}

	return 0;
}

