#include "BlankProject.h"
#include "Engine/Simulation.h"
#include "Platform/Win32/WinEntry.h"

class BlankProject : public Olympus::Simulation
{
public:
	BlankProject() {}
	virtual ~BlankProject() {}

public:
	void SetupPerGameSettings();
	void Initialize() {}
	void Update() {}
};

ENTRYAPP(BlankProject)

void BlankProject::SetupPerGameSettings()
{
	PerGameSettings::SetGameName(IDS_PERGAMENAME);
	PerGameSettings::SetShortName(IDS_SHORTNAME);
	PerGameSettings::SetMainIcon(IDI_MAINICON);
	PerGameSettings::SetSplashURL(IDS_SPLASHURL);
}
