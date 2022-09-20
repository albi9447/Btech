// Ftp Client
#include <arpa/inet.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

void main() {
    int sockfd = socket(AF_INET,SOCK_STREAM,0);
    char filename[100];
    char contents[100];
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = 3001;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(sockfd,(struct sockaddr *)&server_address,sizeof(server_address));

    printf("Enter filename: ");
    scanf("%s",filename);
    send(sockfd,filename,sizeof(filename),0);
    recv(sockfd,contents,sizeof(contents),0);
    printf("The contents are: \n");
    printf("%s",contents);
}