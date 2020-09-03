#include "cocoa-finder.h"

using namespace std;

void CocoaFinder::Begin()
{
    BLEDevice::init("");
    _callback = [this](int rssi, const char* addr){ this->OnCocoaReceive(rssi, addr); };
}

void CocoaFinder::Update()
{
    count++;

    if (count < 10)
    {
        return;
    }
    count = 0;

    BLEScan* ble_scan_ptr = BLEDevice::getScan();

    ble_scan_ptr->setAdvertisedDeviceCallbacks(new CocoaAdvertisedDeviceCallbacks(_callback));
    ble_scan_ptr->setActiveScan(true);
    ble_scan_ptr->start(1, false);
}

void CocoaFinder::OnCocoaReceive(int rssi, const char* addr)
{
    Serial.println(String(addr) + ":" + String(rssi));
}