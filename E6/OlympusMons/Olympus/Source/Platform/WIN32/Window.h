#pragma once

#include "SubObject.h"

#include <Uxtheme.h>
#pragma comment(lib,"uxtheme.lib")
#pragma warning(disable:4275)

namespace Win32 {

	class OLYMPUS_API Window : public Win32::SubObject, public Win32::Caption {

	public:
		Window(WSTRING title, HICON icon, WindowType type = RESIZABLE);
		~Window();

		virtual VOID Initialize() override;
		virtual	LRESULT	MessageHandler(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) override;

		VOID RedrawWindow();
		VOID OnNonClientCreate();
		VOID OnNonClientActivate(BOOL active);
		VOID OnNonClientPaint(HRGN region);
		VOID PaintCaption(HDC hdc);
		VOID OnNonClientLeftMouseButtonDown();
		VOID OnGetMinMaxInfo(MINMAXINFO* minmax);
		VOID OnExitSizeMove();
		VOID OnPaint();

	protected:
		SIZE _size;
		WindowType _type;
		BOOL _active;

	public:
		SIZE Size() { return _size; }
		BOOL Active() { return _active; }

	public:
		VOID Size(SIZE size) { _size = size; }
		VOID Size(INT cx, INT cy) { _size.cx = cx; _size.cy = cy; }
		VOID Active(BOOL active) { _active = active; }
	};

}