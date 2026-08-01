#pragma once
#include <fstream>
#include <string>

#pragma warning( disable : 4251 )

class OLYMPUS_API Logger
{
public:
	Logger();
	virtual ~Logger();

public:
	static Logger* Instance() { return instance; }
	static VOID PrintLog(const WCHAR* fmt, ...);
	static std::wstring LogDirectory();
	static std::wstring LogFile();

private:
	static Logger* instance;
	std::wstring logDirectory;
	std::wstring logFile;
};

