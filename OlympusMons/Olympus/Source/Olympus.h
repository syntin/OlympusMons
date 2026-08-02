#pragma once

#ifdef WIN32
	#define WIN32_LEAN_AND_MEAN
	#include <Windows.h>
#endif

#ifdef BUILD_DLL
	#define OLYMPUS_API __declspec(dllexport)
#else
	#define OLYMPUS_API __declspec(dllimport)
#endif

#define MAX_NAME_STRING 256
#define HInstance() GetModuleHandle(NULL)

#include "Common/Logger.h"
#include "Common/Time.h"
#include "Core/PerGameSettings.h"
