////////////////////////////////////////////////////////////////////////////////
// Copyright Maximos Nolan 2023
////////////////////////////////////////////////////////////////////////////////
// BluetoothDeviceManager

////////////////////////////////////////////////////////////////////////////////
// Includes

#include "BluetoothDeviceManager.h"

#include <iostream>
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>

BlueToothDeviceType::BlueToothDeviceType(const char * DeviceName, const char * MACAddress)
    : mDeviceName(DeviceName), mMACAddress(MACAddress) {};


void BluetoothDeviceManager::ScanDevices()
{
    int adapter_id = hci_get_route(NULL);
	if(adapter_id < 0){
		//TODO: Log
	}

	int socket = hci_open_dev(adapter_id);
	
	if(socket < 0){
		//TODO: Log
	}

	// Setting parameters for discovery.
	int status; 					// -1 if any error, else is set by HCI_INQUIRY to number of devices discovered
	long flags = IREQ_CACHE_FLUSH;
	inquiry_info* inq_inf = NULL; 	// will store data for discovered devices.
	
	inq_inf = reinterpret_cast<inquiry_info*>(malloc(MAX_NUM_DEVICES*sizeof(inquiry_info)));
	if (inq_inf == NULL){
		//TODO: Log
	}

	status = hci_inquiry(adapter_id, 5, MAX_NUM_DEVICES, NULL, &inq_inf,flags );
	if(status < 0){
		//TODO: Log
	}
	
	int nr_nearby = status;
	int i;
	char name[20];
    char address[18];
    std::cout << "starting scan\n";
	for(i = 0; i < nr_nearby; i++){
		//BlueToothDeviceType discoveredDevice; 

		memset(name,0,sizeof(name));
		bdaddr_t mac_addr = inq_inf[i].bdaddr;
		ba2str(&mac_addr, address);
		
		// try to get a name for the device ...
		status = hci_read_remote_name(socket, &mac_addr, sizeof(name),name,0);
		if(status < 0)
        {
			std::cout << "unable to connect to device\n";
		}
        else
        {
            std::cout << name << "\n";
		}
        std::cout << "NAME " << name << "ADDRESS " << address << "\n";
		mDeviceNames.push_back({name, address});
	}

	//close(socket);
	free(inq_inf);
}