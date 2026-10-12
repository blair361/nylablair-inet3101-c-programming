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

    // bind socket to the specified port and IP 
    bind(serverSocketID, (struct sockaddr *)&serverAddr, sizeof(serverAddr));

    printf("Listening for Connections\n");
    // listen for connections 
    // second parameter that this server will keep a backlog of 1 request 
    listen(serverSocketID, 1);

    // define variable to hold client socket
    int clientSocket = accept(serverSocketID, NULL, NULL);

    char filename[256];
    int n = recv(clientSocket, filename, sizeof(filename) - 1,0);
    if (n<0) n = 0;
    filename[n] = '\0';

    char fileContent[2050];
    char *msg; //holds error messages

    if (strlen(filename) == 0 || strchr(filename, '/') != NULL || strstr(filename, "..") != NULL) { // check for invalid file name
        msg = "Error: Invalid file name";
        send(clientSocket, msg, strlen(msg), 0);
    }
    else {
        FILE *fp = fopen(filename, "r");
        if (fp == NULL) { // file not found
            msg = "Error: File not found";
            send(clientSocket, msg, strlen(msg), 0);
        }
        else {
            int size = fread(fileContent, 1, 2049, fp); // read one extra
            fclose(fp);
            if (size > 2048) { // file too large
                msg = "Error: File exceeds 2048 character limit";
                send(clientSocket, msg, strlen(msg), 0);
            }
            else {
                fileContent[size] = '\0';
                send(clientSocket, fileContent, size, 0);
            }
        }
    }
    
    printf("Responded to client request!\n");

    return 0;

}

