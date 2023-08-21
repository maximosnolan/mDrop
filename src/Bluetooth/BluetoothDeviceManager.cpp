////////////////////////////////////////////////////////////////////////////////
// Copyright Maximos Nolan 2023
////////////////////////////////////////////////////////////////////////////////
// BluetoothDeviceManager

////////////////////////////////////////////////////////////////////////////////
// Includes

#include "BluetoothDeviceManager.h"

// Logger
#include "../Logger/Logger.h"

// Standard 
#include <iostream>
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>



BlueToothDeviceType::BlueToothDeviceType(const char * DeviceName, const char * MACAddress)
    : mDeviceName(DeviceName), mMACAddress(MACAddress) {};


void BluetoothDeviceManager::ScanDevices()
{
    int adapter_id = hci_get_route(NULL);
	if (adapter_id < 0)
	{
		Logger::Instance().Log("", "Cannot access bluetooth device");
	}

	int socket = hci_open_dev(adapter_id);
	
	if(socket < 0){
		Logger::Instance().Log("", "Error opening socket");
	}

					
	long flags = IREQ_CACHE_FLUSH;
	inquiry_info* inq_inf = NULL; 	
	

	inq_inf = reinterpret_cast<inquiry_info*>(malloc(MAX_NUM_DEVICES*sizeof(inquiry_info)));
	if (inq_inf == NULL)
	{
		Logger::Instance().Log("", "Unable to allocate inquery buffer");
	}

	int status = hci_inquiry(adapter_id, INQUIRY_DURATION, MAX_NUM_DEVICES, NULL, &inq_inf,flags );
	if(status < 0)
	{
		Logger::Instance().Log(": ", "HCI Inquiry errror", status);
	}
	
	int nr_nearby = status;

	char name[DEVICE_NAME_LENGTH];
    char address[MAC_ADDRESS_LENGTH];
	Logger::Instance().Log(": ", "Starting scan at time", Logger::Instance().GetCurrentTimeStampAsString());
	for (int i = 0; i < nr_nearby; ++i)
	{
		memset(name,0,sizeof(name));
		bdaddr_t mac_addr = inq_inf[i].bdaddr;
		ba2str(&mac_addr, address);
		
		status = hci_read_remote_name(socket, &mac_addr, sizeof(name),name,0);
		if(status < 0)
        {
			Logger::Instance().Log("", "Unknown device recieved.");
		}
        else
        {
            Logger::Instance().Log(": ", "Device with name", name, "found");
		}
		Logger::Instance().Log(": ", "Name", name, "Address", address);
		mDevices.push_back({name, address});
	}

	//close(socket);
	free(inq_inf);
}

void BluetoothDeviceManager::LogDevices()
{
	for (const BlueToothDeviceType& device : mDevices)
	{
		Logger::Instance().Log(": ", "Device name", device.GetDeviceName(), "MAC address", device.GetMacAddress());
	}
}