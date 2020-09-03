#pragma once

#include <functional>

#include <Arduino.h>
#include <M5Stack.h>
#include <BLEDevice.h>

#include "cocoa-advertised-device-callbacks.h"

class CocoaFinder
{
    const uint8_t interval = 10;
    std::function<void(int, const char*)> _callback;
    uint8_t count = 0;

public:
    CocoaFinder()
    {

    }

    void Begin();

    void Update();

    void OnCocoaReceive(int rssi, const char* addr);
};