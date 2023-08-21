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

typedef struct {
	char name[20];
	char addr[18]; // the MAC address in "XX:XX:...:XX" format
} discovered_dev_t; 

class BluetoothDeviceManager : public Singleton<BluetoothDeviceManager>
{
    friend class Singleton<BluetoothDeviceManager>;
public:
    void ScanDevices();

    void LogDevices();
    [[nodiscard]] const std::vector<std::string> GetDeviceNames() const;
    [[nodiscard]] std::string GetDeviceFriendlyNameFromMacAddress(const char * targetMacAddress);
private:
    BluetoothDeviceManager();
    ~BluetoothDeviceManager();
    std::vector<std::string> mDeviceNames;
};
