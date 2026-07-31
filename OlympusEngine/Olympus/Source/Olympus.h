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