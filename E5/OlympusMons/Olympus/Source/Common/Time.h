#pragma once
#include <string>

namespace Time
{
	std::wstring OLYMPUS_API GetTime(BOOL stripped = FALSE);
	std::wstring OLYMPUS_API GetDate(BOOL stripped = FALSE);
	std::wstring OLYMPUS_API GetDateTimeString(BOOL stripped = FALSE);
}