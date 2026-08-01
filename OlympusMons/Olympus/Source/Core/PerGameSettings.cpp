#include "Olympus.h"


PerGameSettings* PerGameSettings::instance;

PerGameSettings::PerGameSettings()
{
	instance = this;

	wcscpy_s(instance->gameName, L"OlympusMons");
	wcscpy_s(instance->shortName, L"OlympusMons");
	wcscpy_s(instance->bootTime, L"0:00:00");
}

PerGameSettings::~PerGameSettings()
{
}


