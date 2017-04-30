#if defined(_WIN32) && defined(__use_native_interface__)

#include <Windows.h>
#include <Pcf/Undef.h>

#include <Pcf/System/Collections/Generic/SortedDictionary.h>

namespace __OS {
  class WindowProcedure {
  public:
    static System::Collections::Generic::SortedDictionary<intptr, WNDPROC> DefWindowProcs;
    static LRESULT CALLBACK WndProc(HWND hwnd, uint32 msg, WPARAM wParam, LPARAM lParam);
  };
}

#endif
