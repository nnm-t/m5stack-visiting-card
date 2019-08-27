#include <HTTPClient.h>
#include <M5Stack.h>
#include <Wifi.h>
#include <ArduinoJson.h>

// Wi-Fi 設定として, 以下の2行を記述した wifi_ssid.h を別途作成して下さい.
// const char* wifi_ssid = "SSID";
// const char* wifi_password = "Password";
#include "wifi_ssid.h"

#include "colors.h"
#include "mode_selector.h"
#include "route_info.h"
#include "text.h"
#include "scroll_text.h"

constexpr unsigned long baud_rate = 115200;

constexpr uint32_t wifi_delay = 500;
constexpr uint32_t wifi_timeout = 10000;

constexpr Vector2 scroll_position = Vector2(0, 204);
constexpr Vector2 scroll_draw = Vector2(320, 0);
constexpr Rect scroll_rect = Rect(1280, 24);
constexpr uint16_t scroll_dx = 4;
constexpr uint16_t scroll_color_depth = 8;

constexpr uint32_t connected_delay = 3000;
constexpr uint32_t loop_delay = 50;

constexpr char* font_24pt = "mplus-1c24";
constexpr char* font_32pt = "mplus-1c32";

HTTPClient http;

RouteInfo route(&http);
ModeSelector mode;

TFT_eSprite route_sprite(&M5.Lcd);
ScrollText route_scroll(&route_sprite, scroll_position,
	scroll_rect, scroll_dx);
String route_string;

void setup() {
	M5.begin();

	Serial.begin(baud_rate);

	// Wifi接続
	WiFi.begin(wifi_ssid, wifi_password);

	M5.Lcd.print("Wi-Fi Connecting... ");
	M5.Lcd.println(wifi_ssid);

	M5.Lcd.println("MAC Address: " + WiFi.macAddress());

	uint32_t wifi_wait = 0;

	while (WiFi.status() != WL_CONNECTED)
	{
		delay(wifi_delay);
		wifi_wait += wifi_delay;

		if (wifi_wait > wifi_timeout)
		{
			// タイムアウト
			M5.Lcd.println("Connection Timeout.");
			break;
		}
	}

	if (WiFi.status() == WL_CONNECTED)
	{
		// IP表示
		M5.Lcd.println("IP Address: " + WiFi.localIP().toString());

		// JSON取得
		route.Get();
		route_string = route.ToString();
		Serial.println(route_string);
	}

	delay(connected_delay);

	OnModeChanged();
}

void loop() {
	M5.update();

	if (M5.BtnC.wasReleased())
	{
		mode.Next();

		OnModeChanged();
	}

	delay(loop_delay);

	route_scroll.Loop();
}

void OnModeChanged()
{
	M5.Lcd.clear();

	// 背景
	M5.Lcd.fillScreen(background_color);
	M5.Lcd.fillRect(0, 192, 320, 48, accent_color);

	// 名前
	Text::LoadFont(font_24pt);
	M5.Lcd.setTextColor(foreground_color, background_color);

	Text::DrawString("Noname", Vector2(180, 48));
	Text::DrawString("Kamisawa", Vector2(196, 72));

	// 運行情報
	route_scroll.Begin(font_24pt);
	route_scroll.SetColor(foreground_color, accent_color, scroll_color_depth);
	route_scroll.SetScrollRect(Vector2::Zero(), scroll_rect);
	route_scroll.DrawString(route_string, scroll_draw);

	Text::LoadFont(font_32pt);
	Text::DrawString("@nnm_t", Vector2(180, 108));

	mode.Current()->Begin();
}
