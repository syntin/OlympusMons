#pragma once 

class OLYMPUS_API OEngine;
namespace Engine {

	enum  EngineMode : INT {
		NONE,
		DEBUG,
		RELEASE,
		EDITOR,
		SERVER
	};

	// True Global Variable for the Engine
	extern OEngine g_OlympusEngine;

	VOID OLYMPUS_API SetMode(EngineMode mode);
	EngineMode OLYMPUS_API GetMode();

	std::wstring OLYMPUS_API EngineModeToString();

}

using namespace Engine;
class OLYMPUS_API OEngine
{
public:
	OEngine();
	~OEngine();

private:
	EngineMode engineMode;

public:
	EngineMode GetEngineMode();
	VOID SetEngineMode(EngineMode mode);

};
