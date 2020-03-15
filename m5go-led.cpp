#include "m5go-led.h"

void M5GoLed::Begin()
{
	_neopixel->begin();

    SetColor(_color);
    SetBrightness(_brightness);
    Show();
}

void M5GoLed::SetColor(const uint32_t color)
{
    for (size_t i = 0; i < _neopixel_num; i++)
	{
        _neopixel->setPixelColor(i, color);
    }

}

void M5GoLed::Show()
{
    _neopixel->show();
}

void M5GoLed::SetBrightness(const uint8_t brightness)
{
    _neopixel->setBrightness(brightness);
}

void M5GoLed::Update()
{
    Show();
}

void M5GoLed::ToggleColor()
{
    switch (_color)
    {
    case M5GoLedColor::None:
        _color = M5GoLedColor::White;
        break;
    case M5GoLedColor::White:
        _color = M5GoLedColor::Red;
        break;
    case M5GoLedColor::Red:
        _color = M5GoLedColor::Green;
        break;
    case M5GoLedColor::Green:
        _color = M5GoLedColor::Blue;
        break;
    case M5GoLedColor::Blue:
        _color = M5GoLedColor::Yellow;
        break;
    case M5GoLedColor::Yellow:
        _color = M5GoLedColor::Fuchsia;
        break;
    case M5GoLedColor::Fuchsia:
        _color = M5GoLedColor::Aqua;
        break;
    case M5GoLedColor::Aqua:
        _color = M5GoLedColor::Orange;
        break;
    case M5GoLedColor::Orange:
        _color = M5GoLedColor::Red2;
        break;
    case M5GoLedColor::Red2:
        _color = M5GoLedColor::Green2;
        break;
    case M5GoLedColor::Green2:
        _color = M5GoLedColor::Blue15;
        break;
    case M5GoLedColor::Blue15:
        _color = M5GoLedColor::Blue22;
        break;
    case M5GoLedColor::Blue22:
        _color = M5GoLedColor::KeioRed;
        break;
    case M5GoLedColor::KeioRed:
        _color = M5GoLedColor::KeioBlue;
        break;
    default:
        _color = M5GoLedColor::None;
        break;
    }

    SetColor(_color);
}