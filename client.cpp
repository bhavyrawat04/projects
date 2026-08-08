#include<iostream>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<cstdlib>
#include<cstring>
#include<stdio.h>

using namespace std;

int main(){
    int clientsocketfd = socket(AF_INET,SOCK_STREAM,0);

    char* ip = "127.0.0.1";//local client ip address 

    //defining the properties of address
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(2000); //port address for http 
    inet_pton(AF_INET,ip,&address.sin_addr.s_addr);

    int result = connect(clientsocketfd, (const struct sockaddr *)&address, sizeof(address));

    if(result==0) cout<<"The connection was successful\n";

    //sending message  to connected server using http protocol
    char* message = NULL;
    size_t messagesize = 0;

    cout<<"the message for server to send(type exit to exit).."<<endl;
    while(true){

        ssize_t charcount = getline(&message,&messagesize,stdin);  

        if(charcount>0){
            if(strcmp(message,"exit\n")==0) break;
        }

        ssize_t amtsent = send(clientsocketfd,message,messagesize,0);
    }

    close(clientsocketfd);
   

    //receiving message from server 

    
 return 0;

    



    return 0;
}