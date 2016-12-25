#ifndef Fl_Gel_Tabs_H
#define Fl_Gel_Tabs_H

//
// Fl_Gel_Tabs.H -- An Aqua-like Tab Widget
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

#if _WIN32
#pragma warning(push)
#pragma warning(disable:4100)
#pragma warning(disable:4211)
#pragma warning(disable:4244)
#endif
#include <FL/Fl.H>
#include <FL/Fl_Group.H>
#if _WIN32
#pragma warning(pop)
#endif

class FL_EXPORT Fl_Gel_Tabs : public Fl_Group {
  //Fl_Widget *value_;
  Fl_Widget *push_;
  int tab_positions(int*, int*, int &tw);
  void tab_area(int&H, int&yedge);
  void draw_tab(int i,int *,int tw,int W,int H,int yedge,Fl_Widget* o,int sel=0);
protected:
  void draw();

public:
  int handle(int);
  Fl_Widget *value();
  int value(Fl_Widget*);
  Fl_Widget *push() const {return push_;}
  int push(Fl_Widget*);
  Fl_Gel_Tabs(int,int,int,int,const char * = 0);
  Fl_Widget *which(int event_x, int event_y);
};

#endif

