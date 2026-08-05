#pragma once

#define ENTRYAPP(x) Win32::IApplication* EntryApplication() { return new x; }

namespace Win32
{
	class OLYMPUS_API IApplication
	{
	public:
		IApplication();
		virtual ~IApplication() {}

	public:
		virtual void SetupPerGameSettings() = 0;
		virtual void PreInitialize() = 0;
		virtual void Initialize() = 0;
		virtual void Update() = 0;
	};

	IApplication* EntryApplication();
}