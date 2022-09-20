// TCP Client

#include<arpa/inet.h>
#include<netinet/in.h>	
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/stat.h>
#include<unistd.h>

void main(){
	char message[100];

	int sock,acc,size_of_client;

	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = 2000;
	server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

	//Creating Socket
	sock = socket(AF_INET,SOCK_STREAM,0);

	//Connecting socket to the server
    connect(sock,(struct sockaddr *)&server_address,sizeof(server_address));

	while(1){
        printf("Client: ");
		scanf("%s",message);
		send(sock,message,sizeof(message),0);
		recv(sock,message,sizeof(message),0);
        printf("%s: \n",message);
	}
}
