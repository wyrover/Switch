#pragma once

#if _WIN32
#pragma warning(push)
#pragma warning(disable:4100)
#pragma warning(disable:4211)
#pragma warning(disable:4244)
#pragma warning(disable:4800)
#endif
#include "Fl.H"
#include "Fl_Adjuster.H"
#include "Fl_Bitmap.H"
#include "Fl_BMP_Image.H"
#include "Fl_Box.H"
#include "Fl_Browser.H"
#include "Fl_Browser_.H"
#include "Fl_Button.H"
#include "Fl_Chart.H"
#include "Fl_Check_Browser.H"
#include "Fl_Check_Button.H"
#include "Fl_Choice.H"
#include "Fl_Clock.H"
#include "Fl_Color_Chooser.H"
#include "Fl_Copy_Surface.H"
#include "Fl_Double_Window.H"
#include "Fl_File_Icon.H"
#include "Fl_Group.H"
#include "Fl_Native_File_Chooser.H"
#include "Fl_Scroll.H"
#include "fl_types.h"
#include "Fl_Tabs.H"
#include "Fl_Text_Display.H"
#include "forms.H"
#if _WIN32
#pragma warning(pop)
#endif

#if !_WIN32
#include <cxxabi.h>
#endif

#if __linux__
#  undef BadRequest
#  undef Bool
#  undef False
#  undef KeyPress
#  undef None
#  undef Success
#  undef True
#endif

#if _WIN32
#  undef hypot
#  undef MessageBox
#endif
