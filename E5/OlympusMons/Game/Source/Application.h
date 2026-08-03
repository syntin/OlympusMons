#pragma once


#include "Engine/Simulation.h"

class Application : public Olympus::Simulation
{
public:
	Application();
	virtual ~Application();

public:
	void Initialize();
	void Update();
	void SetupPerGameSettings();
};