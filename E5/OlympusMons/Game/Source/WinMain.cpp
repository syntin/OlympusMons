#include "pch.h"

/* ------------------------------------------------ */
/* Global Variables									*/
/* ------------------------------------------------ */
#pragma region GlobalVariables
WCHAR gWindowClass[MAX_NAME_STRING];
WCHAR gWindowTitle[MAX_NAME_STRING];
INT	  gWindowWidth;
INT   gWindowHeight;
HICON gHIcon;
#pragma endregion
/* ------------------------------------------------ */


/* ------------------------------------------------ */
/* Forward Declarations								*/
/* ------------------------------------------------ */
#pragma region ForwardDeclarations
void Initialization();
void CreateWndClass();
int CreateAndDisplayWindow();
void WindowRun();
#pragma endregion
/* ------------------------------------------------ */


/* ------------------------------------------------ */
/* Main Entry Points and Callback					*/
/* ------------------------------------------------ */
#pragma region MainEntryPoints
LRESULT CALLBACK WindowProcess(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) {
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}
/*
int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
	Initialization();
	CreateWndClass();
	if (CreateAndDisplayWindow())
		WindowRun();
	else
		MessageBox(0, L"Failure to create and display window. Exiting", 0, 0);

	return 0;
}
*/
#pragma endregion
/* ------------------------------------------------ */


/* ------------------------------------------------ */
/* Initialization									*/
/* ------------------------------------------------ */
#pragma region Initialization
void Initialization()
{
	// Initialize Globals
	LoadString(HInstance(), IDS_PERGAMENAME, gWindowTitle, MAX_NAME_STRING);
	LoadString(HInstance(), IDS_WINDOWCLASS, gWindowClass, MAX_NAME_STRING);

	gWindowWidth = 1366;
	gWindowHeight = 768;
	gHIcon = LoadIcon(HInstance(), MAKEINTRESOURCE(IDI_MAINICON));
}
#pragma endregion
/* ------------------------------------------------ */


/* ------------------------------------------------ */
/* Creation of Window Class							*/
/* ------------------------------------------------ */
#pragma region WindowClassCreation
void CreateWndClass()
{
	WNDCLASSEX wcex {
		.cbSize = sizeof(WNDCLASSEX),
		.style = CS_HREDRAW | CS_VREDRAW,
		.lpfnWndProc = WindowProcess,
		.cbClsExtra = 0,
		.cbWndExtra = 0,
		.hInstance = HInstance(),
		.hIcon = gHIcon,
		.hCursor = LoadCursor(nullptr, IDC_ARROW),
		.hbrBackground = (HBRUSH) GetStockObject(NULL_BRUSH),
		.lpszMenuName = NULL,
		.lpszClassName = gWindowClass,
		.hIconSm = gHIcon
	};
	RegisterClassEx(&wcex);
}
#pragma endregion
/* ------------------------------------------------ */


/* ------------------------------------------------ */
/* Create and Display Window						*/
/* ------------------------------------------------ */
#pragma region CreateAndDisplay
int CreateAndDisplayWindow()
{
	HWND hWnd = CreateWindow(gWindowClass, gWindowTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT,
		0, gWindowWidth, gWindowHeight, nullptr, nullptr, HInstance(), nullptr);
	if (!hWnd) {
		MessageBox(0, L"Failed to Create Window.", 0, 0);
		return 0;
	}

	ShowWindow(hWnd, SW_SHOW);
	return 1;
}
#pragma endregion
/* ------------------------------------------------ */


/* ------------------------------------------------ */
/* Run Window Loop                                  */
/* ------------------------------------------------ */
#pragma region WindowLoop
void WindowRun()
{
	MSG msg = { 0 };
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}
#pragma endregion
/* ------------------------------------------------ */

