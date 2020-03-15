#pragma once

#include "i_mode.h"
#include "icon_mode.h"
#include "qr_mode.h"

class ModeSelector
{
	IMode* current;

	IconMode icon_mode;
	QRMode qr_mode;

public:
	ModeSelector()
	{
		icon_mode = IconMode();
		qr_mode = QRMode();

		current = &icon_mode;
	}

	void Next()
	{
		if (current == &icon_mode)
		{
			current = &qr_mode;
			return;
		}

		current = &icon_mode;
	}

	IMode* Current()
	{
		return current;
	}
};
