// Stop and Wait CLient

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
    int size,packet,ack;
    struct sockaddr_in server_address,client_address;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_family = AF_INET;
    server_address.sin_port = 2000;

    int sockfd = socket(AF_INET,SOCK_DGRAM,0);
    bind(sockfd,(struct sockaddr *)&server_address, sizeof(server_address));

    printf("Enter the window size: ");
    scanf("%s",message);
    size=atoi(message);
    sendto(sockfd,message,sizeof(message),0,(struct sockaddr *)&server_address,sizeof(server_address));
    while(1){
        recvfrom(sockfd,message,sizeof(message),0,NULL,NULL);
        packet = atoi(message);
        printf("Packet Recieved: %d\n",packet);
        printf("1 For Ack, -1 For negative Ack: ");
        scanf("%d",&ack);
        //Converting ack to string
        sprintf(message,"%d",ack);
        sendto(sockfd,message,sizeof(message),0,(struct sockaddr *)&server_address,sizeof(server_address));
        if(packet == size-1 && ack==1)
            break;
    }    
    close(sockfd);
}