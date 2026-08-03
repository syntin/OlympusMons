#include "pch.h"
#include "Application.h"
#include "Platform/WIN32/WinEntry.h"

ENTRYAPP(Application)

Application::Application()
{

}

Application::~Application()
{

}

void Application::SetupPerGameSettings()
{
	PerGameSettings::SetGameName(IDS_PERGAMENAME);
	PerGameSettings::SetShortName(IDS_SHORTNAME);
	PerGameSettings::SetMainIcon(IDI_MAINICON);
}

void Application::Initialize()
{
	Logger::PrintDebugSeparator();
	Logger::PrintLog(L"Application Starting...");
	Logger::PrintLog(L"Game Name: %s", PerGameSettings::GameName());
	Logger::PrintLog(L"Boot Time: %s", Time::GetDateTimeString().c_str());
	Logger::PrintDebugSeparator();

	Logger::StartMTail();
}

void Application::Update()
{
}