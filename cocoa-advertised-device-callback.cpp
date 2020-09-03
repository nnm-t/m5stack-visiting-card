#include "cocoa-advertised-device-callbacks.h"

void CocoaAdvertisedDeviceCallbacks::onResult(BLEAdvertisedDevice advertisedDevice)
{
    if (!advertisedDevice.haveServiceUUID())
    {
        return;
    }

    const char* receive_uuid = advertisedDevice.getServiceUUID().toString().c_str();

    if (strncmp(receive_uuid, cocoa_uuid, uuid_length) != 0)
    {
        return;
    }

    // COCOA検出

    int rssi = advertisedDevice.getRSSI();
    const char* addr = advertisedDevice.getAddress().toString().c_str();
    if (rssi > rssi_threshold)
    {
        _callback_func(rssi, addr);
    }
}