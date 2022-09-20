#include <arpa/inet.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>


void main(){
    
    char filename[100];
    char contents[100];
    struct sockaddr_in server_address,client_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = 3001;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    int sockfd = socket(AF_INET,SOCK_STREAM,0);

    bind(sockfd,(struct sockaddr *)&server_address,sizeof(server_address));

    listen(sockfd,1);

    int size_of_client = sizeof(client_address);

    int acc = accept(sockfd,(struct sockaddr *)&client_address,&size_of_client);

    recv(acc,filename,sizeof(filename),0);
    
    printf("%s",filename);    
    FILE *fd;
    if(fd= fopen(filename,"r")){
        fread(contents,sizeof(contents),1,fd);
        send(acc,contents,sizeof(contents),0);
    }
    else {
        printf("\nNot found");
    }
    close(sockfd);
}