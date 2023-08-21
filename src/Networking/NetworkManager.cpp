////////////////////////////////////////////////////////////////////////////////
// Copyright Maximos Nolan 2023
////////////////////////////////////////////////////////////////////////////////
// Main

////////////////////////////////////////////////////////////////////////////////
// Includes

#include "NetworkManager.h"

// Core
#include "../Logger/Logger.h"

// Statics
/*static*/ char * const kRecievedFileName = "recivedFile";

void NetworkManager::SendFile(const char * targetAddress, const char * filePath)
{

    int socketFd = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);

    if (socketFd == -1) 
    {
        Logger::Instance().Log(": ", "Network Manager Socket Error, errno", strerror(errno));
        return; 
    }

    struct sockaddr_rc addr = {0};

    addr.rc_family = AF_BLUETOOTH;
    addr.rc_channel = (uint8_t)1;
    str2ba(targetAddress, &addr.rc_bdaddr);

    if (connect(socketFd, (struct sockaddr*)&addr, sizeof(addr)) == -1)
    {
        Logger::Instance().Log("", "Network Manager failed to connect");
        close(socketFd);
        return; 
    }

    FILE* file = fopen(filePath, "rb");

    if (!file)
    {
        Logger::Instance().Log(": ", "Network Manager Unable to open file at path", filePath);
        return; 
    }

    char buffer[1024];
    std::size_t bytesRead; 

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0)
    {
        ssize_t bytesSent = send(socketFd, buffer, bytesRead, 0);
        Logger::Instance().Log("", "Sending File Chunk...");
        if (bytesSent == -1)
        {
            Logger::Instance().Log("", "Network Manager unable to send data from file");
            return; 
        }
    }

    Logger::Instance().Log(": ", "Sucsessfully Sent file to target device", targetAddress);

    fclose(file);
    close(socketFd);
}

void NetworkManager::RecieveFile()
{
    Logger::Instance().Log("", "Calling Recieve File");
    struct sockaddr_rc serverAddr = {0};

    serverAddr.rc_family = AF_BLUETOOTH;
    serverAddr.rc_bdaddr = {{0, 0, 0, 0, 0, 0}}; 
    serverAddr.rc_channel = (uint8_t)1;  

    const char * fileName = strcat(kRecievedFileName,Logger::Instance().GetCurrentTimeStampAsString().c_str());

    int serverSocket = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);

    if (serverSocket == -1)
    {
        Logger::Instance().Log("", "Socket error");
        return; 
    }

    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1)
    {
        Logger::Instance().Log("", "Bind error");
        return; 
    }

    if (listen(serverSocket, 1) == -1)
    {
        Logger::Instance().Log("", "Listen error");
        return; 
    }

    struct sockaddr_rc clientAddr = {0};

    socklen_t addrLen = sizeof(clientAddr);
    int clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &addrLen);

    if (clientSocket == -1)
    {
        Logger::Instance().Log("", "Accept error");
        close(serverSocket);
        return; 
    }

    FILE * file = fopen(fileName, "wb");
    if (!file)
    {
        Logger::Instance().Log("", "File open error");
        close(clientSocket);
        close(serverSocket);
        return;
    }

    char buffer[1024];
    ssize_t bytesRead;
    while ((bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0)) > 0)
    {
        fwrite(buffer, 1, bytesRead, file);
    }

    fclose(file);
    close(clientSocket);
    close(serverSocket);

    Logger::Instance().Log("", "Sucsessfully Recieved File");
}