#pragma once

#define ENTRYAPP(x) IApplication* entryApplication() { return new x; }

class OLYMPUS_API IApplication
{
public:
	IApplication();
	virtual ~IApplication() {}

public:
	virtual void SetupPerGameSettings() = 0;
	virtual void Initialize() = 0;
	virtual void Update() = 0;
};

IApplication* entryApplication();