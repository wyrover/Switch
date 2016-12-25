// Simple gel_butttons example
#include <stdlib.h>
#include <stdio.h>

#include <FL/Fl.H>
#include <FL/Fl_Window.H>

#include "gel_button.h"

Fl_Window *main_win;

void ex_callback(Fl_Widget *)
{
    main_win->hide();
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

  main_win = new Fl_Window(startx, starty, 300, 200, "gel button example");
  main_win->begin();

  Fl_Gel_Button *btn = new Fl_Gel_Button(25, 60, 70, 30, "Test");
  btn->clear_visible_focus();
  btn->callback(b1_callback);

  Fl_Gel_Button *b2 = new Fl_Gel_Button(115, 60, 70, 30, "disable");
  b2->clear_visible_focus();
  b2->callback(b2_callback, (void *)btn);

  Fl_Gel_Button *b3 = new Fl_Gel_Button(205, 60, 70, 30, "highlight");
  b3->clear_visible_focus();
  b3->callback(b3_callback, (void *)btn);

  Fl_Gel_Button *ex = new Fl_Gel_Button(205, 120, 70, 30, 1, "Quit");
  ex->clear_visible_focus();
  ex->callback(ex_callback);

  main_win->resizable(main_win);
  main_win->show(argc, argv);

  return Fl::run();
}

/* End of File */
