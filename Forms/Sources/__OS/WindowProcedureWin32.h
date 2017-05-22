#if defined(_WIN32) && defined(__use_native_interface__)

#include <Pcf/System/Collections/Generic/Dictionary.h>

typedef HWND__ *HWND;

namespace __OS {
  class WindowProcedure pcf_static {
  public:
    static System::Collections::Generic::Dictionary<int64, intptr(__stdcall*)(HWND, uint32, uintptr, int64)> DefWindowProcs;

    static void SetWindowTheme(HWND handle);
    static int64 __stdcall WndProc(HWND hwnd, uint32 msg, uintptr wParam, int64 lParam);
  };
}

#endif
