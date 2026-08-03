#include "Olympus.h"

PerGameSettings* PerGameSettings::instance;

PerGameSettings::PerGameSettings()
{

	instance = this;

	wcscpy_s(instance->gameName, L"undefined");
	wcscpy_s(instance->shortName, L"undefined");
	wcscpy_s(instance->bootTime, Time::GetDateTimeString(TRUE).c_str());
	wcscpy_s(instance->splashURL, L"..\\Olympus\\Content\\Images\\OlympusSplash.bmp");
}

PerGameSettings::~PerGameSettings()
{
}
