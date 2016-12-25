// Fl_Gel_Tabs TEST PROGRAM

#include <stdio.h>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include "FL/Fl_Gel_Tabs.H"

Fl_Group *groups[10];
Fl_Gel_Tabs *gtabs = 0;

void value_cb(Fl_Widget*,void*data) {
    Fl_Group *g = (Fl_Group*)data;
    fprintf(stderr, "Enabling tab '%s'\n", g->label());
    gtabs->value(g);
}

int main() {

  Fl::scheme("plastic");
  Fl_Window win(0,0,400,300,"geltabs-value-test");

  gtabs = new Fl_Gel_Tabs(10,10,win.w()-20,win.h()-45);
  //  gtabs->clear_visible_focus();
  int gx = 20, gy = 31, gw = win.w() - 40, gh = win.h()-65;
  int gix = 0;
  groups[gix] = new Fl_Group(gx,gy,gw,gh,"Hostname");
  new Fl_Input(gx+100,gy+50, 200,25,"Hostname");
  new Fl_Input(gx+100,gy+85, 200,25,"IP Address");
  new Fl_Input(gx+100,gy+120,200,25,"Net Mask");
  groups[gix++]->end();
  groups[gix] = new Fl_Group(gx,gy,gw,gh,"DNS");
  new Fl_Input(gx+100,gy+50,200,25,"DNS Servers");
  new Fl_Input(gx+100,gy+85,200,25,"Search Domain");
  groups[gix++]->end();
  groups[gix] = new Fl_Group(gx,gy,gw,gh,"Router");
  new Fl_Input(gx+100,gy+50, 150,25,"Router IP");
  groups[gix++]->end();
  groups[gix] = new Fl_Group(gx,gy,gw,gh,"Resolver");
  new Fl_Input(gx+100,gy+50, 150,25,"Host Order");
  groups[gix++]->end();
  groups[gix] = new Fl_Group(gx,gy,gw,gh,"Firewall");
  new Fl_Input(gx+100,gy+50, 200,25,"Allow Tcp:");
  new Fl_Input(gx+100,gy+85, 200,25,"Allow Udp:");
  new Fl_Input(gx+100,gy+120,200,25,"Allow ICMP:");
  groups[gix++]->end();
  groups[gix++] = 0;
  gtabs->end();

  // Test the Fl_Gel_Tabs::value() method
  for ( int x=0; groups[x]; x++ ) {
      Fl_Button *b = new Fl_Button(10+x*75,275,65,20,groups[x]->label());
      b->labelsize(10);
      b->callback(value_cb, (void*)groups[x]);
  }
  win.resizable(win);
  win.show();
  return(Fl::run());
}
