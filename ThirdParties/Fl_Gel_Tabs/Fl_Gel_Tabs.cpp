#include "FL/Fl_Gel_Tabs.H"

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

//
// Fl_Gel_Tabs.cxx -- An Aqua-like Tab Widget
//
// Copyright 2005 by Greg Ercolano.
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Library General Public
// License as published by the Free Software Foundation; either
// version 2 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Library General Public License for more details.
//
// You should have received a copy of the GNU Library General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
//

// XPMS FOR Fl_Gel_Tabs                          //
//          _______________________              //
//         /           |           \             //
//        |   TAB 1    |   TAB 2    |            //
//        |            |            |            //
//         \___________|___________/             //
//                                               //
//        |___|  |__| |_|        |__|            //
//          lt    ct  sep         rt             //
//                                               //
//                                               //
// OBJECT     'ON'              'OFF'            //
// left       lt_crv_on_xpm     lt_crv_off_xpm   //
// center     ct_mid_on_xpm     ct_mid_off_xpm   //
// right      rt_crv_on_xpm     rt_crv_off_xpm   //
// rightsep   rt_sep_on_xpm     rt_sep_off_xpm   //
//                                               //

// Curved edges
#include "gel_xpms/rt_crv_off.xpm"
#include "gel_xpms/rt_crv_on.xpm"
#include "gel_xpms/lt_crv_off.xpm"
#include "gel_xpms/lt_crv_on.xpm"

// Middle span of button
#include "gel_xpms/ct_mid_off.xpm"
#include "gel_xpms/ct_mid_on.xpm"

// Separators
#include "gel_xpms/rt_sep_off.xpm"
#include "gel_xpms/rt_sep_on.xpm"

#define BORDER 0
#define EXTRASPACE 20	// box's inner padding on either side of label
#define TAB_HEIGHT 21	// fixed height of tab button icons

// return the left edges of each tab (plus a fake left edge for a tab
// past the right-hand one).  These position are actually of the left
// edge of the slope.  They are either seperated by the correct distance
// or by EXTRASPACE or by zero.
// Return value is the index of the selected item.
//
int Fl_Gel_Tabs::tab_positions(int* p, int* wp, int &tw) {
  int selected = 0;
  Fl_Widget*const* a = array();
  int i;

  // First pass: 'total width' calc
  tw = 0;
  for (i=0; i<children(); i++) {
    Fl_Widget* o = *(a+i);
    int wt = 0; int ht = 0;
    o->measure_label(wt,ht);
    tw += (wt+EXTRASPACE);
  }

  // Determine start of tabs relative to center
  //    If total width of tabs is wider than widget,
  //    then left justify the tabs, and let them truncate at right edge.
  //
  int center = x() + w() / 2;
  p[0] = ( tw > w() ) ? x() : center - tw / 2;		// starting position

  // Second pass: tab positions
  for (i=0; i<children(); i++) {
    Fl_Widget* o = *a++;
    if (o->visible()) selected = i;

    int wt = 0; int ht = 0;
    o->measure_label(wt,ht);

    wp[i]  = wt+EXTRASPACE;
    p[i+1] = p[i]+wp[i]+BORDER;
  }
  return selected;
}

// return space needed for tabs.  Negative to put them on the bottom:
void Fl_Gel_Tabs::tab_area(int& H, int& yedge) {
  H = h();
  int H2 = y();
  Fl_Widget*const* a = array();
  for (int i=children(); i--;) {
    Fl_Widget* o = *a++;
    if (o->y() < y()+H) H = o->y()-y();
    if (o->y()+o->h() > H2) H2 = o->y()+o->h();
  }
  H2 = y()+h()-H2;
  H = (H2 > H) ? ((H2<= 0) ? 0 : -TAB_HEIGHT) 
               : ((H <= 0) ? 0 :  TAB_HEIGHT);
  yedge = (H >= 0) ? y() + TAB_HEIGHT / 2 
                   : y() + h() - 2 - ( TAB_HEIGHT / 2 ) * 3;
}

// this is used by fluid to pick tabs:
Fl_Widget *Fl_Gel_Tabs::which(int event_x, int event_y) {
  int H, yedge; tab_area(H, yedge);
  if (event_y < yedge || event_y > yedge+TAB_HEIGHT ) return 0;
  if (event_x < x()) return 0;
  int p[128], wp[128], tw;
  tab_positions(p, wp, tw);
  for (int i=0; i<children(); i++) {
    if (event_x < p[i+1]) return child(i);
  }
  return 0;
}

int Fl_Gel_Tabs::handle(int event) {
  Fl_Widget *o;
  int i;
  switch (event) {
      case FL_PUSH: {
	int H, yedge; tab_area(H, yedge);
	if (H >= 0) {
	  if (Fl::event_y() > yedge+TAB_HEIGHT) return Fl_Group::handle(event);
	} else {
	  if (Fl::event_y() < yedge) return Fl_Group::handle(event);
	}
      }
      case FL_DRAG:
      case FL_RELEASE:
	o = which(Fl::event_x(), Fl::event_y());
	if (event == FL_RELEASE) {
	  push(0);
	  if (o && value(o)) {
	    set_changed();
	    do_callback();
	  }
	} else push(o);
	if (Fl::visible_focus() && event == FL_RELEASE) Fl::focus(this);
	return 1;
      case FL_FOCUS:
      case FL_UNFOCUS: {
	if (!Fl::visible_focus()) return Fl_Group::handle(event);
	if (Fl::event() == FL_RELEASE ||
	    Fl::event() == FL_SHORTCUT ||
	    Fl::event() == FL_KEYBOARD) {
	  // Damage just the tab area
	  int H, yedge; tab_area(H, yedge);
	  damage(FL_DAMAGE_SCROLL, x(), yedge, w(), TAB_HEIGHT);
	  return 1;
	} else return Fl_Group::handle(event);
      }
      case FL_KEYBOARD:
	switch (Fl::event_key()) {
	  case FL_Left:
	    if (child(0)->visible()) return 0;
	    for (i = 1; i < children(); i ++)
	      if (child(i)->visible()) break;
	    value(child(i - 1));
	    set_changed();
	    do_callback();
	    return 1;
	  case FL_Right:
	    if (child(children() - 1)->visible()) return 0;
	    for (i = 0; i < children(); i ++)
	      if (child(i)->visible()) break;
	    value(child(i + 1));
	    set_changed();
	    do_callback();
	    return 1;
	  case FL_Up: {
	    int H, yedge; tab_area(H, yedge);
	    if ( H < 0 ) { redraw(); return Fl_Group::handle(FL_FOCUS); }
	    return 0;
	  }
	  case FL_Down: {
	    int H, yedge; tab_area(H, yedge);
	    if ( H > 0 ) { redraw(); return Fl_Group::handle(FL_FOCUS); }
	    return 0;
	  }
	  default:
	    break;
	}
      default:
	return Fl_Group::handle(event);
  }
}

int Fl_Gel_Tabs::push(Fl_Widget *o) {
  if (push_ == o) return 0;
  if ((push_ && !push_->visible()) || (o && !o->visible()))
    redraw();
  push_ = o;
  return 1;
}

// The value() is the first visible child (or the last child if none
// are visible) and this also hides any other children.
// This allows the tabs to be deleted, moved to other groups, and
// show()/hide() called without it screwing up.
Fl_Widget* Fl_Gel_Tabs::value() {
  Fl_Widget* v = 0;
  Fl_Widget*const* a = array();
  for (int i=children(); i--;) {
    Fl_Widget* o = *a++;
    if (v) o->hide();
    else if (o->visible()) v = o;
    else if (!i) {o->show(); v = o;}
  }
  return v;
}

// Setting the value hides all other children, and makes this one
// visible, iff it is really a child:
int Fl_Gel_Tabs::value(Fl_Widget *newvalue) {
  Fl_Widget*const* a = array();
  int ret = 0;
  for (int i=children(); i--;) {
    Fl_Widget* o = *a++;
    if (o == newvalue) {
      if (!o->visible()) ret = 1;
      o->show();
    } else {
      o->hide();
    }
  }
  return ret;
}

enum {LEFT, RIGHT, SELECTED};

// Draw
void Fl_Gel_Tabs::draw() {
  Fl_Widget *v = value();
  int H, yedge; tab_area(H, yedge);
  if (damage() & FL_DAMAGE_ALL) { // redraw the entire thing:
    // Draw the tab's box
    draw_box(box(), x(), y()+(H>=0?H:0), w(), h()-(H>=0?H:-H), v ? v->color() : color());
    if (v) draw_child(*v);
  } else { // redraw the child
    if (v) update_child(*v);
  }
  if (damage() & (FL_DAMAGE_SCROLL|FL_DAMAGE_ALL)) {
    fl_push_clip(x(),y(),w(),h());
    int p[128]; int wp[128], tw;
    int selected = tab_positions(p,wp,tw);
    int i;
    Fl_Widget*const* a = array();
    for (i=0; i<selected; i++)
      draw_tab(i, p, tw, wp[i], H, yedge, a[i], LEFT);
    for (i=children()-1; i > selected; i--)
      draw_tab(i, p, tw, wp[i], H, yedge, a[i], RIGHT);
    if (v) {
      i = selected;
      draw_tab(i, p, tw, wp[i], H, yedge, a[i], SELECTED);
    }
    fl_pop_clip();
  }
}

// Draw tab's box
static void draw_tab_box(int x, int y, int w, int h, Fl_Color c, 
			 int onoff,		// is this tab 'on' or 'off'
			 int curveleft, 	// is the left side of the tab curved, or a divider?
			 int curveright) {	// is the right side of the tab curved, or a divider?

  if ( onoff ) {
    // ON
    static Fl_Pixmap lt_crv_on(lt_crv_on_xpm);
    static Fl_Pixmap ct_mid_on(ct_mid_on_xpm);
    static Fl_Pixmap rt_crv_on(rt_crv_on_xpm);
    static Fl_Pixmap rt_sep_on(rt_sep_on_xpm);

    int lt_w = lt_crv_on.w();
    int ct_w = ct_mid_on.w();
    int rt_w = rt_crv_on.w();

    // LEFT
    if ( curveleft ) { lt_crv_on.draw(x,y); }
    else             { ct_mid_on.draw(x,y); ct_mid_on.draw(x+ct_w,y); }

    // CENTER
    fl_push_clip(x,y,w-rt_w,h);
    for ( int xx=x+lt_w; xx<=x+w-rt_w; xx += ct_w ) ct_mid_on.draw(xx,y);
    fl_pop_clip();

    // RIGHT
    if ( curveright ) rt_crv_on.draw(x+w-rt_w,y);
    else              rt_sep_on.draw(x+w-rt_w,y);
  } else {
    // OFF
    static Fl_Pixmap lt_crv_off(lt_crv_off_xpm);
    static Fl_Pixmap ct_mid_off(ct_mid_off_xpm);
    static Fl_Pixmap rt_crv_off(rt_crv_off_xpm);
    static Fl_Pixmap rt_sep_off(rt_sep_off_xpm);

    int lt_w = lt_crv_off.w();
    int ct_w = ct_mid_off.w();
    int rt_w = rt_crv_off.w();

    // LEFT
    if ( curveleft ) { lt_crv_off.draw(x,y); }
    else             { ct_mid_off.draw(x,y); ct_mid_off.draw(x+ct_w,y); }

    // CENTER
    fl_push_clip(x,y,w-rt_w,h);
    for ( int xx=x+lt_w; xx<=x+w-rt_w; xx += ct_w ) ct_mid_off.draw(xx,y);
    fl_pop_clip();

    // RIGHT
    if ( curveright ) rt_crv_off.draw(x+w-rt_w,y);
    else              rt_sep_off.draw(x+w-rt_w,y);
  }
}

// Draw a single tab with label
void Fl_Gel_Tabs::draw_tab(int i, int *p, int tw, int W, int H, int yedge, Fl_Widget* o, int what) {
  int x1 = p[i];
  int sel = (what == SELECTED);

  // TAB
  draw_tab_box(x1, yedge, W, TAB_HEIGHT,
	       sel ? selection_color() : o->selection_color(),
	       what == SELECTED, (i==0), (i==children()-1));

  // LABEL
  o->draw_label(x1, yedge, W, TAB_HEIGHT, FL_ALIGN_CENTER);

  // FOCUS BOX
  if (Fl::focus() == this && o->visible()) {
    if ( i == 0 ) {
	draw_focus(box(), x1+4, yedge+1, W-6, TAB_HEIGHT-1);
    } else {
	draw_focus(box(), x1, yedge+1, W-1, TAB_HEIGHT-1);
    }
  }
}

// CTOR
Fl_Gel_Tabs::Fl_Gel_Tabs(int X,int Y,int W, int H, const char *l) : Fl_Group(X,Y,W,H,l) {
  box(FL_THIN_UP_BOX);
  push_ = 0;
}

