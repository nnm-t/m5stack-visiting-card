#pragma once

constexpr uint16_t Convert16bitColor(const uint32_t color)
{
	return ((((color >> 16) & 0xFF) >> 3) << 11) | ((((color >> 8) & 0xFF) >> 2) << 5) | ((color >> 3) & 0xFF);
}

constexpr uint16_t background_color = Convert16bitColor(0xC46A9F);
constexpr uint16_t accent_color = Convert16bitColor(0x525780);
constexpr uint16_t foreground_color = Convert16bitColor(0xFFFFFF);
