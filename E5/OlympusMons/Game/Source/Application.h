#pragma once

#include "Platform/WIN32/IApplication.h"


class Application : public IApplication
{
public:
	Application();
	virtual ~Application();

public:
	void Initialize();
	void Update();
	void SetupPerGameSettings();
};