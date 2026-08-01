#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#undef MAX
#undef MIN

#include "../resource.h"

/* Helper Macros -------------------------------------------------------------------------- */
#define HInstance() GetModuleHandle(NULL)
//#define HWnd() (HWND) GetModuleHandle(NULL)
constexpr auto MAX_NAME_STRING = 256;
/* ---------------------------------------------------------------------------------------- */

#include "Olympus.h"
#include "Common/Logger.h"

