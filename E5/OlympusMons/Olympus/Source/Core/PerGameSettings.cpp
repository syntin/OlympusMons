#include "Olympus.h"

PerGameSettings* PerGameSettings::instance;

PerGameSettings::PerGameSettings()
{

	instance = this;

	wcscpy_s(instance->_gameName, L"undefined");
	wcscpy_s(instance->_shortName, L"undefined");
	wcscpy_s(instance->_bootTime, Time::GetDateTimeString(TRUE).c_str());
	wcscpy_s(instance->_splashURL, L"..\\Olympus\\Content\\Images\\OlympusSplash.bmp");
}

PerGameSettings::~PerGameSettings()
{
}
