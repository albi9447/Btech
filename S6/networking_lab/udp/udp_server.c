// UDP Server

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/stat.h>
#include<arpa/inet.h>
#include<netinet/in.h>	

void main(){
    char message[100];
    struct sockaddr_in server_address,client_address;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_family = AF_INET;
    server_address.sin_port = 2000;

    int sockfd = socket(AF_INET,SOCK_DGRAM,0);
    bind(sockfd,(struct sockaddr *)&server_address, sizeof(server_address));

    int size_of_client = sizeof(client_address);

    while(1){
        recvfrom(sockfd,message,sizeof(message),0,(struct sockaddr *)&client_address, &size_of_client);
        printf("%s\n",message);
        scanf("%s",message);
        sendto(sockfd,message,sizeof(message),0,(struct sockaddr *)&client_address, size_of_client);
    }
}