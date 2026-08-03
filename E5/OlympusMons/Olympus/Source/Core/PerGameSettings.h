#pragma once

class OLYMPUS_API PerGameSettings
{
private:
	static PerGameSettings* instance;
	static PerGameSettings* Instance() { return instance; }

public:
	PerGameSettings();
	~PerGameSettings();

private:
	WCHAR gameName[MAX_NAME_STRING];
	WCHAR shortName[MAX_NAME_STRING];
	HICON mainIcon;
	WCHAR bootTime[MAX_NAME_STRING];
	WCHAR splashURL[MAX_NAME_STRING];

public:
	static WCHAR* GameName() { return instance->gameName; }
	static VOID SetGameName(UINT id) { LoadString(HInstance(), id, instance->gameName, MAX_NAME_STRING); }

	static WCHAR* ShortName() { return instance->shortName; }
	static VOID SetShortName(UINT id) { LoadString(HInstance(), id, instance->shortName, MAX_NAME_STRING); }

	static HICON MainIcon() { return instance->mainIcon; }
	static VOID SetMainIcon(UINT id) { LoadIcon(HInstance(), MAKEINTRESOURCE(id)); }

	static WCHAR* BootTime() { return instance->bootTime; }
	static VOID SetBootTime(WCHAR* time) { wcscpy_s(instance->bootTime, time); }

	static WCHAR* SplashURL() { return instance->splashURL; }
	static VOID SetSplashURL(UINT id) { LoadStringW(HInstance(), id, instance->splashURL, MAX_NAME_STRING); }
};