#pragma once

#include "Core.h"

class OLYMPUS_API PerGameSettings
{
private:
	static PerGameSettings* instance;
	static PerGameSettings* Instance() { return instance; }

public:
	PerGameSettings();
	~PerGameSettings();

private:
	WCHAR _gameName[MAX_NAME_STRING];
	WCHAR _shortName[MAX_NAME_STRING];
	HICON _mainIcon;
	WCHAR _bootTime[MAX_NAME_STRING];
	WCHAR _splashURL[MAX_NAME_STRING];

public:
	static WCHAR* GameName() { return instance->_gameName; }
	static VOID SetGameName(UINT id) { LoadString(HInstance(), id, instance->_gameName, MAX_NAME_STRING); }

	static WCHAR* ShortName() { return instance->_shortName; }
	static VOID SetShortName(UINT id) { LoadString(HInstance(), id, instance->_shortName, MAX_NAME_STRING); }

	static HICON MainIcon() { return instance->_mainIcon; }
	static VOID SetMainIcon(UINT id) { LoadIcon(HInstance(), MAKEINTRESOURCE(id)); }

	static WCHAR* BootTime() { return instance->_bootTime; }
	static VOID SetBootTime(WCHAR* time) { wcscpy_s(instance->_bootTime, time); }

	static WCHAR* SplashURL() { return instance->_splashURL; }
	static VOID SetSplashURL(UINT id) { LoadStringW(HInstance(), id, instance->_splashURL, MAX_NAME_STRING); }
};