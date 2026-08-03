#include "Olympus.h"
#include "IApplication.h"

extern IApplication* entryApplication();

int CALLBACK wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nShowCmd)
{
	auto EntryApp = entryApplication();

	PerGameSettings GameSettings;

	EntryApp->SetupPerGameSettings();
	EntryApp->Initialize();

	Logger logger;

	MSG msg = { 0 };
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			EntryApp->Update();
		}
	}

	return 0;
}


