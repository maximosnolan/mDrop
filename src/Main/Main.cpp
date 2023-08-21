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

// Main
#include "Main.h"

int32_t main()
{
    BluetoothDeviceManager& bluetoothDeviceManager = BluetoothDeviceManager::Instance();
    bluetoothDeviceManager.ScanDevices();
    //bluetoothDeviceManager.LogDevices();
    std::cout << "MAIN FINISED\n";
    return 0;
}
