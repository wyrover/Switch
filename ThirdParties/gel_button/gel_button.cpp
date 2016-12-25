#include "gel_button.h"

#if _WIN32
#pragma warning(push)
#pragma warning(disable:4100)
#pragma warning(disable:4211)
#pragma warning(disable:4244)
#endif
#include <FL/fl_draw.H>
#include <FL/Fl_Pixmap.H>
#if _WIN32
#pragma warning(pop)
#endif

// Curved edges
#include "gel_xpms/R-but-off.xpm"
#include "gel_xpms/R-but-on.xpm"
#include "gel_xpms/L-but-off.xpm"
#include "gel_xpms/L-but-on.xpm"

// Middle span of button
#include "gel_xpms/ct_mid_off.xpm"
#include "gel_xpms/ct_mid_on.xpm"

#define GEL_HEIGHT 21	// fixed height of tab button icons

// Draw button's box
static void draw_gel_box(int x, int y, int w, int h, Fl_Color c,
			 int bluegray)	// is this button 'blue' or 'gray'
{
  if ( bluegray ) { // ON
    static Fl_Pixmap ct_mid_on(ct_mid_on_xpm);
    static Fl_Pixmap lt_crv_on(L_but_on_xpm);
    static Fl_Pixmap rt_crv_on(R_but_on_xpm);

    int lt_w = lt_crv_on.w();
    int ct_w = ct_mid_on.w();
    int rt_w = rt_crv_on.w();

    // LEFT
    lt_crv_on.draw(x,y);

    // CENTER
    fl_push_clip(x,y,w-rt_w,h);
    for ( int xx=x+lt_w; xx<=x+w-rt_w; xx += ct_w ) ct_mid_on.draw(xx,y);
    fl_pop_clip();

    // RIGHT
    rt_crv_on.draw(x+w-rt_w,y);
  }
  else { // OFF
    static Fl_Pixmap ct_mid_off(ct_mid_off_xpm);
    static Fl_Pixmap lt_crv_off(L_but_off_xpm);
    static Fl_Pixmap rt_crv_off(R_but_off_xpm);

    int lt_w = lt_crv_off.w();
    int ct_w = ct_mid_off.w();
    int rt_w = rt_crv_off.w();

    // LEFT
    lt_crv_off.draw(x,y);

    // CENTER
    fl_push_clip(x,y,w-rt_w,h);
    for ( int xx=x+lt_w; xx<=x+w-rt_w; xx += ct_w ) ct_mid_off.draw(xx,y);
    fl_pop_clip();

    // RIGHT
    rt_crv_off.draw(x+w-rt_w,y);
  }
}


// Draw
void Fl_Gel_Button::draw() {
  if (type() == FL_HIDDEN_BUTTON) return;
//  Fl_Color col = value() ? selection_color() : color();
  Fl_Color col = selection_color();
  Fl_Color old_lc = FL_BLACK; // in case we have to override the disabled label colour

  int x1 = x();
  int y1 = y();
  int w1 = w();

  int bluegray = value(); // are we blue or gray right now?
  if (hl) bluegray ^= 1;  // hl buttons go blue-gray-blue, non-hl buttons go g-b-g

  draw_gel_box(x1, y1, w1, h(), col, bluegray);

  // now try and force the label colour for inactive buttons
  int ok = active();
  if (!ok) {
    if (hl) // override the label colour, as the disabled contrast isn't so good
    {
      old_lc = labelcolor();
      labelcolor(FL_DARK_CYAN);
	  ok = 0;
    }
	else
      ok = 1;
  }

//  draw_label();
//  draw_label(x1, y1, w1, GEL_HEIGHT, FL_ALIGN_CENTER);
  draw_label(x1, y1, w1, GEL_HEIGHT, this->align());

  if (!ok) {
    labelcolor(old_lc); // put label colour back the way we found it
  }

  if (Fl::focus() == this) draw_focus((Fl_Boxtype)0, x1+4, y1+2, w1-7, GEL_HEIGHT-3);
}

int Fl_Gel_Button::highlight(void)
{
	return hl;
}

void Fl_Gel_Button::highlight(int hi)
{
	int newset;
	if (hi) newset = 1;
	else newset = 0;

	if (newset != hl)
	{
		hl = newset;
		redraw();
	}
}

// CTOR
Fl_Gel_Button::Fl_Gel_Button(int X,int Y,int W, int H, int hi, const char *l) : Fl_Button(X,Y,W,H,l) {
  box(FL_THIN_UP_BOX);
  if (hi) hl = 1;
  else hl = 0;
}

Fl_Gel_Button::Fl_Gel_Button(int X,int Y,int W, int H, const char *l) : Fl_Button(X,Y,W,H,l) {
  box(FL_THIN_UP_BOX);
  hl = 0;
}

/* End of File */
