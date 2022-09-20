// TCP Server

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

	int server_socket,acc,size_of_client;

	struct sockaddr_in server_address,client_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = 2000;
	server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

	//Creating Socket
	server_socket = socket(AF_INET,SOCK_STREAM,0);

	//Binding Socket with server address
	bind(server_socket,(struct sockaddr *)&server_address,sizeof(server_address));

	//Listening for incoming connection
	listen(server_socket,1);

	size_of_client = sizeof(client_address);

	//Accepting first incoming connection
	acc = accept(server_socket,(struct sockaddr *)&client_address,&size_of_client);

	while(1){
		recv(acc,message,sizeof(message),0);
		printf("Client %s: \n",message);
		printf("Server: ");
		scanf("%s",message);
		send(acc,message,sizeof(message),0);
	}
}
