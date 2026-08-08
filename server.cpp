#include<iostream>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

using namespace std;


int main(){
    //creating a ipv4 socket
    int serversocketfd = socket(AF_INET,SOCK_STREAM,0);


    //creating an ipv4 address
    char* ip ="";
    struct sockaddr_in serveraddress;
    serveraddress.sin_family = AF_INET;
    serveraddress.sin_port = htons(2000);
    inet_pton(AF_INET,ip,&serveraddress.sin_addr.s_addr);
    
    //binding the server to socket
    int result = bind(serversocketfd,(const struct sockaddr*)&serveraddress,sizeof(serveraddress));

    if (result==0) cout<<"the binding was succesfull\n";

    //listening to incoming client ports
    int listenresult = listen(serversocketfd,10);

    struct sockaddr_in clientaddress;
    int clientaddresssize = sizeof(struct sockaddr_in);
    int clientsocketfd = accept(serversocketfd, (struct sockaddr *)&clientaddress, (socklen_t *)&clientaddresssize);

    char received_message[1024];
    while(true){
        ssize_t amtrecieved = recv(clientsocketfd,received_message,1024,0);

        if(amtrecieved>0) cout<<"the response was: "<<received_message<<endl;
        else if(amtrecieved==0) break;
    }
    
    close(clientsocketfd);
    shutdown(serversocketfd,SHUT_RDWR);

    return 0;
}




