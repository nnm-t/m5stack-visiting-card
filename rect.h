#pragma once

class Rect
{
	const uint16_t _width;
	const uint16_t _height;

public:
	constexpr Rect(const uint16_t width, const uint16_t height) :
		_width(width), _height(height)
	{

	}

	constexpr uint16_t GetWidth() const
	{
		return _width;
	}

	constexpr uint16_t GetHeight() const
	{
		return _height;
	}
};
