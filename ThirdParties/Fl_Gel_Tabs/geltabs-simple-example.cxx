// Fl_Gel_Tabs Simple Example

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Box.H>
#include "FL/Fl_Gel_Tabs.H"

int main() {
  Fl_Window win(0,0,300,200,"geltabs-simple-example");
  Fl_Gel_Tabs *tabs = new Fl_Gel_Tabs(10,10,win.w()-20,win.h()-45);
  {
      int gx=tabs->x(), gy=tabs->y()+20, gw=tabs->w(), gh=tabs->h()-20;
      Fl_Group *g;

      g = new Fl_Group(gx,gy,gw,gh,"Tab 1");
      g->box(FL_THIN_DOWN_BOX); g->color(Fl_Color(48));
      new Fl_Box(gx+10,gy+10,gw-20,gh-20,"The Tab#1 group.");
      g->end();

      g = new Fl_Group(gx,gy,gw,gh,"Tab 2");
      g->box(FL_THIN_DOWN_BOX); g->color(Fl_Color(48));
      new Fl_Box(gx+10,gy+10,gw-20,gh-20,"The Tab#2 group.");
      g->end();

      g = new Fl_Group(gx,gy,gw,gh,"Wide Tab 3");
      g->box(FL_THIN_DOWN_BOX); g->color(Fl_Color(48));
      new Fl_Box(gx+10,gy+10,gw-20,gh-20,"The wide Tab#3 group.");
      g->end();

      g = new Fl_Group(gx,gy,gw,gh,"Tab 4");
      g->box(FL_THIN_DOWN_BOX); g->color(Fl_Color(48));
      new Fl_Box(gx+10,gy+10,gw-20,gh-20,"The Tab#4 group.");
      g->end();
      tabs->resizable(g);
  }
  tabs->end();
  win.resizable(tabs);
  win.show();
  return(Fl::run());
}
