#include "Olympus.h"
#include "Window.h"

namespace Win32 {

	Window::Window(std::wstring className, std::wstring classTitle, HICON icon, INT w, INT ht)
		: Win32::SubObject(className, classTitle, icon), width(w), height(ht)
	{

	}

	Window::~Window()
	{

	}

	VOID Window::Initialize()
	{
		RECT desktop;
		const HWND hDesktop = GetDesktopWindow();
		GetWindowRect(hDesktop, &desktop);

		RECT R = { 0, 0, width, height };
		AdjustWindowRect(&R, WS_OVERLAPPEDWINDOW, false);
		int width = R.right - R.left;
		int height = R.bottom - R.top;

		handle = CreateWindow(wClass.c_str(), title.c_str(),
			WS_POPUP, ((desktop.right / 2) - (width / 2)), ((desktop.bottom / 2) - (height / 2)),
			width, height, nullptr, nullptr, HInstance(), (void*)this);

		ShowWindow(handle, SW_SHOW);
		UpdateWindow(handle);

	}

}
