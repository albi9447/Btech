//Stop and wait Server

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
    char misc[10];
    int size,ack;
    struct sockaddr_in server_address,client_address;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_family = AF_INET;
    server_address.sin_port = 2000;

    int sockfd = socket(AF_INET,SOCK_DGRAM,0);
    bind(sockfd,(struct sockaddr *)&server_address, sizeof(server_address));

    int size_of_client = sizeof(client_address);

    recvfrom(sockfd,message,sizeof(message),0,(struct sockaddr *)&client_address, &size_of_client);
    size = atoi(message);
    printf("%d\n",size);
    printf("Sending packages");
    for(int i=0;i<size;i++){
        printf("Sending package %d\n",i);
        sprintf(misc,"%d",i);
        sendto(sockfd,misc,sizeof(misc),0,(struct sockaddr *)&client_address,size_of_client);
        recvfrom(sockfd,message,sizeof(message),0,(struct sockaddr *)&client_address, &size_of_client);
        ack = atoi(message);
        if(ack==-1)
            i=i-1;
    }
    close(sockfd);
}