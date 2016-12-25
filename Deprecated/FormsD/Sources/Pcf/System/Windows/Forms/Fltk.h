#pragma once

#if _WIN32
#pragma warning(push)
#pragma warning(disable:4100)
#pragma warning(disable:4211)
#pragma warning(disable:4244)
#pragma warning(disable:4800)
#endif
#include <FL/Fl.H>
#include <FL/Fl_Adjuster.H>
#include <FL/Fl_Bitmap.H>
#include <FL/Fl_BMP_Image.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Browser.H>
#include <FL/Fl_Browser_.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Chart.H>
#include <FL/Fl_Check_Browser.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Clock.H>
#include <FL/Fl_Color_Chooser.H>
#include <FL/Fl_Copy_Surface.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_File_Icon.H>
#include <FL/Fl_GIF_Image.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Image.H>
#include <FL/Fl_Native_File_Chooser.H>
#include <FL/Fl_Progress.H>
#include <FL/Fl_Radio_Round_Button.H>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Secret_Input.H>
#include <FL/Fl_Spinner.H>
#include <FL/Fl_Sys_Menu_Bar.H>
#include <FL/fl_types.h>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Text_Editor.H>
#include <FL/Fl_XBM_Image.H>
#include <FL/Fl_XPM_Image.H>
#include <FL/forms.H>

#include <FL/Fl_Gel_Tabs.H>

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
