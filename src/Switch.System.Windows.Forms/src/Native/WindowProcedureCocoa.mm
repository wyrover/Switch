#if defined(__APPLE__)
#include "WindowProcedureCocoa.hpp"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace Native;

Native::WindowProcedure::ControlDictionary Native::WindowProcedure::Controls;
bool Native::WindowProcedure::messageLoopRunning = false;
bool Native::WindowProcedure::hover = false;

#endif
