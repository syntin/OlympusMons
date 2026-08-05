#include "Olympus.h"
#include "Simulation.h"
#include "Engine/SplashScreen.h"

namespace Olympus
{

	Olympus::Simulation::Simulation() :
		Win32::Window(L"MainApplication", NULL)
	{
	}

	Olympus::Simulation::~Simulation()
	{
	}

	VOID Olympus::Simulation::PreInitialize()
	{

		Logger::PrintDebugSeparator();
		Logger::PrintLog(L"Application Starting...\n");
		Logger::PrintLog(L"Game Name: %s\n", PerGameSettings::GameName());
		Logger::PrintLog(L"Boot Time: %s\n", Time::GetDateTimeString().c_str());
		Logger::PrintLog(L"Engine Mode: %s\n", Engine::EngineModeToString().c_str());

		Logger::PrintDebugSeparator();

		SplashScreen::Open();

		Win32::Window::RegisterNewClass();
		Win32::Window::Initialize();
	}

	LRESULT Simulation::MessageHandler(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		switch (message)
		{
		case 0:
		default:
			break;
		}

		return Window::MessageHandler(hwnd, message, wParam, lParam);
		//
	}
}