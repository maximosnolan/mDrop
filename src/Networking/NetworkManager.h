////////////////////////////////////////////////////////////////////////////////
// Copyright Maximos Nolan 2023
////////////////////////////////////////////////////////////////////////////////
// NetworkManager
#pragma once
////////////////////////////////////////////////////////////////////////////////
// Includes

// Standard

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <unistd.h>

// Bluez
#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>

// Core
#include "../Logger/Logger.h"
#include "../Utils/Singleton.h"

class NetworkManager : public Singleton<NetworkManager>
{
public: 
    void SendFile(const char * targetAddress, const char * filePath);
    void RecieveFile();

private:
    static const char * const kRecievedFileName;
};