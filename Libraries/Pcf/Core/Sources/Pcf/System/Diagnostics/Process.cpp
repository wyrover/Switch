#include <cstdio>
#include <cstdlib>

#include "../../../../Includes/Pcf/System/Diagnostics/Process.h"

using namespace System;
using namespace System::Diagnostics;

Process::~Process() {
	if (!this->outputStream->IsClosed())
		this->outputStream->Close();
}

UniquePointer<Process> Process::Start(const String& fileName) {
	return Start(ProcessStartInfo(fileName));
}

UniquePointer<Process> Process::Start(const String& fileName, const String& argument) {
	return Start(ProcessStartInfo(fileName, argument));
}

UniquePointer<Process> Process::Start(const ProcessStartInfo& startInfo) {
	FILE* fs = OpenProcess("\"" + startInfo.FileName() + "\" " + startInfo.Arguments(), "r");
	return new Process(new ProcessOutputStream(fs));
}

void Process::WaitForExit() {
	this->outputStream->Close();
}

FILE* Process::OpenProcess(const String& command, const String& mode) {
#if _WIN32
	return _popen(String("\"" + command + "\"").ToCCharArray().Data(), mode.ToCCharArray().Data());
#else
	return popen(command.ToCCharArray().Data(), mode.ToCCharArray().Data());
#endif
}

int32 Process::CloseProcess(FILE* process) {
#if _WIN32
	return _pclose(process);
#else
	return pclose(process);
#endif
}

