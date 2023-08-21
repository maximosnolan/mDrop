////////////////////////////////////////////////////////////////////////////////
// Copyright Maximos Nolan 2023
////////////////////////////////////////////////////////////////////////////////
// BluetoothDeviceManager

////////////////////////////////////////////////////////////////////////////////
// Includes

// Standard Library
#include <string>
#include <vector>


// Utils
#include "../Utils/Singleton.h"

#define MAX_NUM_DEVICES 256

class BlueToothDeviceType
{
public:
    BlueToothDeviceType() = default;
    BlueToothDeviceType(const char * DeviceName, const char * MACAddress); 
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
private:
    BluetoothDeviceManager() = default;
    ~BluetoothDeviceManager() = default;
    std::vector<BlueToothDeviceType> mDeviceNames;
};
