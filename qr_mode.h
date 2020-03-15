#pragma once

#include "i_mode.h"

class QRMode : public IMode
{
public:
	void Begin() override
	{
		M5.Lcd.qrcode("htttps://twitter.com/nnm_t", 8, 16, 160);
	}
};
