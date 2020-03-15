#pragma once

#include <Arduino.h>
#include <M5Stack.h>

#include <Adafruit_NeoPixel.h>

#include "m5go-led-color.h"

class M5GoLed
{
    Adafruit_NeoPixel* const _neopixel;
    const uint16_t _neopixel_num;

    M5GoLedColor _color = M5GoLedColor::White;
    uint8_t _brightness = 31;
    bool _is_brightness_up = true;

public:
    M5GoLed(Adafruit_NeoPixel* const neopixel, const uint16_t neopixel_num) : _neopixel(neopixel), _neopixel_num(neopixel_num)
    {

    }

    void Begin();

    void SetColor(const uint8_t red, const uint8_t green, const uint8_t blue)
    {
        SetColor(_neopixel->Color(red, green, blue));
    }

    void SetColor(const M5GoLedColor color)
    {
        SetColor(static_cast<uint32_t>(color));
    }

    void SetColor(const uint32_t color);

    void SetBrightness(const uint8_t brightness);

    void Show();

    void Update();

    void ToggleColor();
};