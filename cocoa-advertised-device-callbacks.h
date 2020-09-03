
#pragma once

#include <functional>

#include <Arduino.h>
#include <M5Stack.h>
#include <BLEDevice.h>

class CocoaAdvertisedDeviceCallbacks : public BLEAdvertisedDeviceCallbacks
{
    static constexpr const char* cocoa_uuid = "0000fd6f-0000-1000-8000-00805f9b34fb";
    static constexpr const size_t uuid_length = 36;
    static constexpr const int rssi_threshold = -70;

    std::function<void(int, const char*)> _callback_func;
public:
    CocoaAdvertisedDeviceCallbacks(std::function<void(int, const char*)> callback_func) : _callback_func(callback_func)
    {

    }

    void onResult(BLEAdvertisedDevice advertisedDevice) override;
};