#include "Olympus.h"
#include "Window.h"

namespace Win32 {

	Window::Window(std::wstring className, std::wstring classTitle, HICON icon, INT width, INT height)
		: Win32::SubObject(className, classTitle, icon), _width(width), _height(height)
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

		RECT R = { 0, 0, _width, _height };
		AdjustWindowRect(&R, WS_OVERLAPPEDWINDOW, false);
		int _width = R.right - R.left;
		int _height = R.bottom - R.top;

		_handle = CreateWindow(_wClass.c_str(), _title.c_str(),
			WS_POPUP, ((desktop.right / 2) - (_width / 2)), ((desktop.bottom / 2) - (_height / 2)),
			_width, _height, nullptr, nullptr, HInstance(), (void*)this);

		ShowWindow(_handle, SW_SHOW);
		UpdateWindow(_handle);

	}

}
