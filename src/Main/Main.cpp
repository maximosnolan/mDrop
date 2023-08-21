////////////////////////////////////////////////////////////////////////////////
// Copyright Maximos Nolan 2023
////////////////////////////////////////////////////////////////////////////////
// Main

////////////////////////////////////////////////////////////////////////////////
// Includes

// Standard Library
#include <iostream>

// Core
#include "../Bluetooth/BluetoothDeviceManager.h"
#include "../Logger/Logger.h"
#include "../Networking/NetworkManager.h"

void InitCoreServices()
{
    Logger& logger = Logger::Instance();
    const std::string logName = logger.GenerateLogFileName();
    logger.Initialize(logName);
}

int32_t main()
{
    InitCoreServices();
    BluetoothDeviceManager& bluetoothDeviceManager = BluetoothDeviceManager::Instance();
    bluetoothDeviceManager.ScanDevices();
    bluetoothDeviceManager.LogDevices();
    return 0;
}
