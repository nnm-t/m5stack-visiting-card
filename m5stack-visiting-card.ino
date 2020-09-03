#include <Arduino.h>
#include <M5Stack.h>
#include <Ticker.h>
#include <ArduinoJson.h>
#include <Adafruit_NeoPixel.h>
#include <BLEDevice.h>

#include "colors.h"
#include "mode_selector.h"
#include "route_info.h"
#include "text.h"
#include "scroll_text.h"
#include "m5go-led.h"
#include "cocoa-finder.h"

namespace
{
	constexpr unsigned long baud_rate = 115200;

	constexpr uint32_t loop_delay = 100;
	constexpr uint32_t battery_update_ms = 1000;

	constexpr char* font_24pt = "mplus-1c24";
	constexpr char* font_32pt = "mplus-1c32";

	constexpr uint16_t neopixel_num = 10;
	constexpr uint16_t neopixel_pin = 15;

	Adafruit_NeoPixel neopixel = Adafruit_NeoPixel(neopixel_num, 15);

	uint32_t battery_count_ms = 0;
}

Ticker ticker;
CocoaFinder cocoa_finder;

ModeSelector mode;
M5GoLed led(&neopixel, neopixel_num);

void setup() {
	M5.begin();
	M5.Power.begin();

	Serial.begin(baud_rate);

	led.Begin();
	cocoa_finder.Begin();

	// 背景
	M5.Lcd.fillScreen(background_color);
	M5.Lcd.fillRect(0, 192, 320, 48, accent_color);

	// 名前
	M5.Lcd.loadFont(font_32pt, SD);
	M5.Lcd.setTextColor(foreground_color, background_color);

	M5.Lcd.drawString("神沢野並", 180, 40);
	M5.Lcd.drawString("@nnm_t", 180, 80);

	// 電池アイコン
	M5.Lcd.fillRect(229, 8, 15, 10, foreground_color);
	M5.Lcd.fillRect(244, 11, 3, 4, foreground_color);

	M5.Lcd.loadFont(font_24pt, SD);

	// スペース
	M5.Lcd.drawString("4日目", 180, 128);
	M5.Lcd.drawString("南ウ-41a", 180, 152);

	M5.Lcd.setTextDatum(TC_DATUM);
	M5.Lcd.setTextColor(foreground_color, accent_color);

	// ボタン文字
	M5.Lcd.drawString("LED", 60, 205);
	M5.Lcd.drawString("QR", 260, 205);

	// 枠
	M5.Lcd.drawRect(20, 200, 80, 32, foreground_color);
	M5.Lcd.drawRect(120, 200, 80, 32, foreground_color);
	M5.Lcd.drawRect(220, 200, 80, 32, foreground_color);

	M5.Lcd.setTextDatum(TL_DATUM);

	OnModeChanged();

	ticker.attach_ms(loop_delay, &OnTimerTicked);
}

void loop()
{
	cocoa_finder.Update();
	delay(100);
}

void UpdateBatteryLevel()
{
	battery_count_ms += loop_delay;

	// 更新間隔に満たない場合は飛ばす
	if (battery_count_ms < battery_update_ms)
	{
		return;
	}

	battery_count_ms = 0;

	// 背景埋め
	M5.Lcd.fillRect(252, 0, 68, 25, background_color);
	M5.Lcd.setTextDatum(TR_DATUM);
	M5.Lcd.setTextColor(foreground_color, background_color);

	// 電池レベル
	int8_t battery_level = M5.Power.getBatteryLevel();
	M5.Lcd.drawString(String(battery_level, DEC) + "%", 316, 4);

	M5.Lcd.setTextDatum(TL_DATUM);
}

void OnModeChanged()
{
	mode.Current()->Begin();
}

void OnTimerTicked()
{
	M5.update();

	if (M5.BtnC.wasPressed())
	{
		mode.Next();

		OnModeChanged();
	}

	if (M5.BtnA.wasPressed())
	{
		led.ToggleColor();
	}

	UpdateBatteryLevel();

	led.Update();
}