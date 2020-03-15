#pragma once

#include <M5Stack.h>

#include "rect.h"
#include "vector2.h"

class ScrollText
{
	static constexpr int32_t width = TFT_HEIGHT;

	TFT_eSprite* _sprite;

	const Vector2 _position;
	const Rect _rect;
	const uint16_t _dx;

	int32_t _x;
	int32_t _y;

	bool _is_scroll;
	String _string;
	int32_t _scroll_width;

	void MoveReverseSide(uint32_t new_x)
	{
		_x = new_x;
		DrawString(_string, Vector2(_x, _y));
	}

public:
	ScrollText(TFT_eSprite* sprite, const Vector2& position, const Rect& rect, const uint16_t dx) :
		_sprite(sprite), _position(position), _rect(rect), _dx(dx)
	{
		_x = 0;
		_y = 0;

		_is_scroll = false;
		_string = String();
	}

	void Begin()
	{
		_sprite->createSprite(_rect.GetWidth(), _rect.GetHeight());
	}

	void Begin(String& font_name, FS& fs = SD)
	{
		Begin();
		_sprite->loadFont(font_name, fs);
	}

	void Begin(const char* font_name, FS& fs = SD)
	{
		Begin();
		_sprite->loadFont(font_name, fs);
	}

	void SetColor(const uint16_t foreground_color, const uint16_t background_color, const uint8_t color_depth);

	void DrawString(String& string, const Vector2& position);

	void SetScrollRect(const Vector2& position, const Rect& rect)
	{
		_sprite->setScrollRect(position.GetX(), position.GetY(), rect.GetWidth(), rect.GetHeight());
		_scroll_width = rect.GetWidth();
	}

	void Loop();

	void End()
	{
		_is_scroll = false;
		_sprite->deleteSprite();
	}
};
