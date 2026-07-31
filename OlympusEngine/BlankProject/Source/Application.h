#pragma once

#include "IApplication.h"


class Application : public IApplication
{
public:
	Application();
	virtual ~Application();

public:
	void Initialize();
	void Update();
};