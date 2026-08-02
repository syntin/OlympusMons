#include "Olympus.h"


PerGameSettings* PerGameSettings::instance;

PerGameSettings::PerGameSettings()
{
	instance = this;

	wcscpy_s(instance->gameName, L"OlympusMons");
	wcscpy_s(instance->shortName, L"OlympusMons");
	wcscpy_s(instance->bootTime, Time::GetDateTimeString(TRUE).c_str());
}

PerGameSettings::~PerGameSettings()
{
}


