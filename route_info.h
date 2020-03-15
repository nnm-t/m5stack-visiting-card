#pragma once

#include <HTTPClient.h>
#include <ArduinoJson.h>

class RouteInfo
{
	static constexpr char* page_url = "https://tetsudo.rti-giken.jp/free/delay.json";

	HTTPClient* _http_client;

	StaticJsonDocument<4096> json_document;

	String json_raw;
	String error;

	bool GetJson();

	DeserializationError Deserialize()
	{
		return deserializeJson(json_document, json_raw);
	}

public:
	RouteInfo(HTTPClient* http_client) : 
		_http_client(http_client), json_document(StaticJsonDocument<4096>()),
		json_raw(String()), error(String())
	{

	}

	bool Get();

	String GetRaw()
	{
		return json_raw;
	}

	String ToString();
};
