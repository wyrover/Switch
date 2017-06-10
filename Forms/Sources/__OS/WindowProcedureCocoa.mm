#if defined(__APPLE__) && defined(__use_native_interface__)
#include "WindowProcedureCocoa.hpp"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

__OS::WindowProcedure::ControlDictionary __OS::WindowProcedure::Controls;
bool __OS::WindowProcedure::messageLoopRunning = false;
bool __OS::WindowProcedure::hover = false;

#endif
