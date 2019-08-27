#include "route_info.h"

bool RouteInfo::GetJson()
{
	_http_client->begin(page_url);

	int status_code = _http_client->GET();
	bool isCorrect = false;

	if (status_code < 0)
	{
		error = _http_client->errorToString(status_code);
	}
	else if (_http_client->getSize() < 0)
	{
		error = "Invalid Size";
	}
	else
	{
		json_raw = _http_client->getString();
		isCorrect = true;
	}

	_http_client->end();

	return isCorrect;
}

bool RouteInfo::Get()
{
	bool result = GetJson();

	if (!result)
	{
		return result;
	}

	if (Deserialize() != DeserializationError::Ok)
	{
		error = "Deserialization Failed.";
		return false;
	}

	return true;
}

String RouteInfo::ToString()
{
	if (json_document.isNull())
	{
		return error;
	}

	String string;
	JsonArray json_array = json_document.as<JsonArray>();

	for (int i = 0; i < json_array.size(); i++)
	{
		JsonVariant variant = json_array[i];
		string.concat(variant["name"].as<String>());

		if (i != json_array.size() - 1)
		{
			string.concat(", ");
		}
	}

	return "Delay: " + string;
}