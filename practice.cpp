#include<iostream>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<cstdlib>
#include<cstring>
#include<stdio.h>

using namespace std;


int main(){
    //coding client side 
    int clientsocketfd = socket(AF_INET,SOCK_STREAM,0);

    char* ip = "127.0.0.1";

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(2000);
    inet_pton(AF_INET,ip,&address.sin_addr.s_addr);

    int result = connect(clientsocketfd,(const struct sockaddr*)&address, sizeof(address));

    if (result==0) cout<<"the connection was successful\n";

    char* sentmessage=NULL;
    size_t messagesize = 0;

    cout<<"type exit to exit\n";

    while(true){
        ssize_t charcount = getline(&sentmessage,&messagesize,stdin);

        if(charcount>0) if(strcmp(sentmessage,"exit\n")==0) break;


        ssize_t amtsent = send(clientsocketfd,sentmessage,messagesize,0);

    }

    close(clientsocketfd);

    return 0;

}