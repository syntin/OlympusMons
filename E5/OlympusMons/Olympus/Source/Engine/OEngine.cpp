#include "Olympus.h"

namespace Engine {

	OEngine g_OlympusEngine;

	VOID SetMode(EngineMode mode)
	{
		g_OlympusEngine.SetEngineMode(mode);
	}


	EngineMode GetMode()
	{
		return g_OlympusEngine.GetEngineMode();
	}

	std::wstring OLYMPUS_API EngineModeToString()
	{
		switch (Engine::GetMode())
		{
		case EngineMode::DEBUG:
			return L"Debug";
		case EngineMode::RELEASE:
			return L"Release";
		case EngineMode::SERVER:
			return L"Server";
		case EngineMode::EDITOR:
			return L"Editor";
		default:
			return L"None";
		}
	}


}

OEngine::OEngine()
{
#ifdef _DEBUG
	engineMode = EngineMode::DEBUG;
#else
	engineMode = EngineMode::RELEASE;
#endif
}

OEngine::~OEngine()
{
}

EngineMode OEngine::GetEngineMode()
{
	return engineMode;
}

VOID OEngine::SetEngineMode(EngineMode mode)
{
	engineMode = mode;
}


