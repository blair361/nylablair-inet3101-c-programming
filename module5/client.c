#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char const* arg[])
{
    // create server socket 
    int serverSocketID = socket(AF_INET, SOCK_STREAM, 0);

    // define server address
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(9001);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    int connectStatus = connect(serverSocketID, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    if (connectStatus == -1) {
        printf("Error: Could not connect to the server. \n");
    }
    else {
        char filename[256];
        printf("Enter filename: ");
        fgets(filename, sizeof(filename), stdin);
        filename[strcspn(filename, "\n")] = '\0';
        send(serverSocketID, filename, strlen(filename), 0);
        char serverMsg[2100];
        int n = recv(serverSocketID, serverMsg, sizeof(serverMsg) - 1, 0);
        if (n<0) n = 0;
        serverMsg[n] = '\0';
        printf("Message from the Server: %s\n", serverMsg);
    }
    
    return 0;

}
