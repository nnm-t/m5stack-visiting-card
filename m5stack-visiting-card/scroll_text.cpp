#include "scroll_text.h"

void ScrollText::SetColor(const uint16_t foreground_color, const uint16_t background_color, const uint8_t color_depth)
{
	_sprite->setColorDepth(color_depth);
	_sprite->fillSprite(background_color);
	_sprite->setTextColor(foreground_color, background_color);
}

void ScrollText::DrawString(String& string, const Vector2& position)
{
	_string = string;
	_sprite->drawString(string, position.GetX(), position.GetY());
	_x = position.GetX();
	_y = position.GetY();
	_is_scroll = true;
}

void ScrollText::Loop()
{
	_sprite->pushSprite(_position.GetX(), _position.GetY());

	if (!_is_scroll)
	{
		return;
	}

	_sprite->scroll(-_dx);
	_x -= _dx;

	if (_x <= (-_scroll_width - width))
	{
		// ‰E’[‚ÖˆÚ“®
		MoveReverseSide(width);
	}
}