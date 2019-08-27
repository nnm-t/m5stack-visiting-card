#pragma once

#include "vector2.h"

class Text
{
public:
	static void LoadFont(const char* font_name, FS fs = SD)
	{
		M5.Lcd.loadFont(font_name, fs);
	}

	static void LoadFont(String& font_name, FS fs = SD)
	{
		M5.Lcd.loadFont(font_name, fs);
	}

	static void DrawString(const char* string, const Vector2& position)
	{
		M5.Lcd.drawString(string, position.GetX(), position.GetY());
	}

	static void DrawString(String& string, const Vector2& position)
	{
		M5.Lcd.drawString(string, position.GetX(), position.GetY());
	}
};
