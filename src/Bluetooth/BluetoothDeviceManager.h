////////////////////////////////////////////////////////////////////////////////
// Copyright Maximos Nolan 2023
////////////////////////////////////////////////////////////////////////////////
// BluetoothDeviceManager
#pragma once
////////////////////////////////////////////////////////////////////////////////
// Includes

// Standard Library
#include <string>
#include <vector>


// Utils
#include "../Utils/Singleton.h"

#define MAX_NUM_DEVICES 256
#define INQUIRY_DURATION 5
#define DEVICE_NAME_LENGTH 20
#define MAC_ADDRESS_LENGTH 18

class BlueToothDeviceType
{
public:
    BlueToothDeviceType() = default;
    BlueToothDeviceType(const char * DeviceName, const char * MACAddress); 

    [[nodiscard]] const std::string GetDeviceName() const { return mDeviceName; }
    [[nodiscard]] const std::string GetMacAddress() const { return mMACAddress; }
private:
    std::string mDeviceName; 
    std::string mMACAddress; 
};

class BluetoothDeviceManager : public Singleton<BluetoothDeviceManager>
{
    friend class Singleton<BluetoothDeviceManager>;
public:
    void ScanDevices();

    void LogDevices();
    [[nodiscard]] const std::vector<std::string> GetDeviceNames() const;
    [[nodiscard]] std::string GetDeviceFriendlyNameFromMacAddress(const char * targetMacAddress);

    [[nodiscard]] std::vector<BlueToothDeviceType> GetBluetoothDevices() const { return mDevices; }
private:
    BluetoothDeviceManager() = default;
    ~BluetoothDeviceManager() = default;
    std::vector<BlueToothDeviceType> mDevices;
};
