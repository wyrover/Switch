#ifndef FL_GEL_BTN_H
#define FL_GEL_BTN_H

#if _WIN32
#pragma warning(push)
#pragma warning(disable:4100)
#pragma warning(disable:4211)
#pragma warning(disable:4244)
#endif
#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#if _WIN32
#pragma warning(pop)
#endif

class Fl_Gel_Button : public Fl_Button {

protected:
  void draw();
  int hl; // is button "highlighted" or not?

public:
    Fl_Gel_Button(int x,int y,int w,int h, const char *l = 0);
    Fl_Gel_Button(int x,int y,int w,int h, int hi, const char *l = 0);
	//~Fl_Gel_Button;

	int highlight(void);
	void highlight(int);
};

#endif // FL_GEL_BTN_H

/* End of File */


