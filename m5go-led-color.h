#pragma once

#include <Arduino.h>

enum class M5GoLedColor : uint32_t
{
    None = 0x000000,
    White = 0xFFFFFF,
    Red = 0xFF0000,
    Green = 0x00FF00,
    Blue = 0x0000FF,
    Yellow = 0xFFFF00,
    Fuchsia = 0xFF00FF,
    Aqua = 0x00FFFF,
    Orange = 0xFFA500,
    Red2 = 0xBB3322,
    Green2 = 0x336633,
    Blue15 = 0x224499,
    Blue22 = 0x22AABB,
    KeioRed = 0xDD3377,
    KeioBlue = 0x333388
};