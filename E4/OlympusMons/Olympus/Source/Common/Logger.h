#pragma once
#include <string>

#pragma warning( disable : 4251 )

class OLYMPUS_API Logger
{
private:
	static Logger* instance;

public:
	Logger();
	virtual ~Logger();

public:
	static Logger* Instance() { return instance; }
	static VOID PrintLog(const WCHAR* fmt, ...);
	static std::wstring LogDirectory();
	static std::wstring LogFile();

	static VOID PrintDebugSeparator();
	static BOOL IsMTailRunning();
	static VOID StartMTail();
};

