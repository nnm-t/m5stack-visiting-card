#pragma once

#include "i_mode.h"
#include "colors.h"

class IconMode : public IMode
{
public:
	IconMode()
	{

	}

	void Begin() override
	{
		// ÉAÉCÉRÉì
		M5.Lcd.fillRect(4, 12, 168, 168, foreground_color);
		M5.Lcd.drawBmpFile(SD, "/nnm_t.bmp", 8, 16);
	}
};
