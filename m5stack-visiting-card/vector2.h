#pragma once

class Vector2
{
	const uint32_t _x;
	const uint32_t _y;

public:
	constexpr Vector2(const uint32_t x, const uint32_t y) :
		_x(x), _y(y)
	{

	}

	constexpr uint32_t GetX() const
	{
		return _x;
	}

	constexpr uint32_t GetY() const
	{
		return _y;
	}

	static constexpr Vector2 Zero()
	{
		return Vector2(0, 0);
	}
};
