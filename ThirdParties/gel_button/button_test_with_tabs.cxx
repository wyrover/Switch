// Fl_Gel_Tabs Simple Example
#include <stdlib.h>
#include <stdio.h>

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Box.H>
#include "FL/Fl_Gel_Tabs.H"

#include "gel_button.h"

void ex_callback(Fl_Widget *)
{
    exit(0);
}

void b1_callback(Fl_Widget *)
{
    printf ("got click!\n");
	fflush(stdout);
}

void b2_callback(Fl_Widget *, void *v)
{
    Fl_Gel_Button *btn = (Fl_Gel_Button *)v;

	if (btn->active()) btn->deactivate();
	else btn->activate();
}

void b3_callback(Fl_Widget *, void *v)
{
    Fl_Gel_Button *btn = (Fl_Gel_Button *)v;

	if (btn->highlight()) btn->highlight(0);
	else btn->highlight(1);
//	btn->redraw();
}

int main(int argc, char **argv)
{
  Fl::scheme("plastic");

  int startx = Fl::w() / 2 - 150;
  int starty = Fl::h() / 2 - 100;

  Fl_Window win(startx, starty, 300, 200, "gel button example");
  Fl_Gel_Tabs *tabs = new Fl_Gel_Tabs(10,10,win.w()-20,win.h()-45);
  {
      tabs->clear_visible_focus();

      int gx=tabs->x(), gy=tabs->y()+20, gw=tabs->w(), gh=tabs->h()-20;
      Fl_Group *g;

      g = new Fl_Group(gx,gy,gw,gh,"Tab 1");
      g->box(FL_ENGRAVED_FRAME);
	  //g->color(Fl_Color(48));
//      new Fl_Box(gx+10,gy+10,gw-20,gh-20,"The Tab#1 group.");

	  Fl_Gel_Button *btn = new Fl_Gel_Button(gx+15, gy+40, 70, 30, "Test");
	  //btn->clear_visible_focus();
	  btn->callback(b1_callback);
//	  btn->color(FL_CYAN);
//	  btn->labelcolor(FL_WHITE);

	  Fl_Gel_Button *b2 = new Fl_Gel_Button(gx+105, gy+40, 70, 30, "disable");
	  b2->clear_visible_focus();
	  b2->callback(b2_callback, (void *)btn);

	  Fl_Gel_Button *b3 = new Fl_Gel_Button(gx+195, gy+40, 70, 30, "highlight");
	  b3->clear_visible_focus();
	  b3->callback(b3_callback, (void *)btn);

	  Fl_Gel_Button *ex = new Fl_Gel_Button(gx+195, gy+100, 70, 30, 1, "Quit");
	  ex->clear_visible_focus();
	  ex->callback(ex_callback);

	  g->end();

      g = new Fl_Group(gx,gy,gw,gh,"Tab 2");
      g->box(FL_THIN_DOWN_BOX); g->color(Fl_Color(48));
      new Fl_Box(gx+10,gy+10,gw-20,gh-20,"The Tab#2 group.");
      g->end();

      g = new Fl_Group(gx,gy,gw,gh,"Wide Tab 3");
      g->box(FL_DOWN_BOX); g->color(Fl_Color(48));
      new Fl_Box(gx+10,gy+10,gw-20,gh-20,"The wide Tab#3 group.");
      g->end();

      g = new Fl_Group(gx,gy,gw,gh,"Tab 4");
      g->box(FL_NO_BOX); g->color(Fl_Color(48));
      new Fl_Box(gx+10,gy+10,gw-20,gh-20,"The Tab#4 group.");
      g->end();

      tabs->resizable(g);
  }
  tabs->end();
  win.resizable(tabs);
  win.show(argc, argv);
  return(Fl::run());
}
