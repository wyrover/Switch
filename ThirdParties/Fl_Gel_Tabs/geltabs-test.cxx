// Fl_Gel_Tabs TEST PROGRAM

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>
#include "FL/Fl_Gel_Tabs.H"

int main() {
  Fl::scheme("plastic");
  Fl_Window win(0,0,800,500,"geltabs-test");

  // Upper tabs
  int x;
  for ( x=0; x<=400; x+= 400 ) {
    Fl_Gel_Tabs *tabs = new Fl_Gel_Tabs(x+10,10,win.w()/2-20,win.h()/2-20);
    //  tabs->clear_visible_focus();
    int gx = x+20, gy = 31, gw = win.w()/2 - 40, gh = win.h()/2-45;
    Fl_Group *g1 = new Fl_Group(gx,gy,gw,gh,"Hostname");
    new Fl_Input(gx+100,gy+50, 200,25,"Hostname");
    new Fl_Input(gx+100,gy+85, 200,25,"IP Address");
    new Fl_Input(gx+100,gy+120,200,25,"Net Mask");
    g1->end();
    Fl_Group *g2 = new Fl_Group(gx,gy,gw,gh,"DNS");
    new Fl_Input(gx+100,gy+50,200,25,"DNS Servers");
    new Fl_Input(gx+100,gy+85,200,25,"Search Domain");
    g2->end();
    Fl_Group *g3 = new Fl_Group(gx,gy,gw,gh,"Router");
    new Fl_Input(gx+100,gy+50, 150,25,"Router IP");
    g3->end();
    Fl_Group *g4 = new Fl_Group(gx,gy,gw,gh,"Resolver");
    new Fl_Input(gx+100,gy+50, 150,25,"Host Order");
    g4->end();
    Fl_Group *g5 = new Fl_Group(gx,gy,gw,gh,"Firewall");
    new Fl_Input(gx+100,gy+50, 200,25,"Allow Tcp:");
    new Fl_Input(gx+100,gy+85, 200,25,"Allow Udp:");
    new Fl_Input(gx+100,gy+120,200,25,"Allow ICMP:");
    g5->end();
    tabs->end();
  }
  // Lower tabs
  for ( x=0; x<=400; x+= 400 ) {
    Fl_Gel_Tabs *tabs = new Fl_Gel_Tabs(x+10,win.h()/2 + 10,win.w()/2-20,win.h()/2-20);
    //  tabs->clear_visible_focus();
    int gx = x+20, gy = win.h()/2+20, gw = win.w()/2 - 40, gh = win.h()/2-65;
    Fl_Group *g1 = new Fl_Group(gx,gy,gw,gh,"Tab1");
    new Fl_Input(gx+100,gy+50, 200,25,"Tab 1a");
    new Fl_Input(gx+100,gy+85, 200,25,"Tab 1b");
    g1->end();
    Fl_Group *g2 = new Fl_Group(gx,gy,gw,gh,"Tab2");
    new Fl_Input(gx+100,gy+50, 150,25,"Tab 2a");
    g2->end();
    Fl_Group *g3 = new Fl_Group(gx,gy,gw,gh,"Wide Tab3");
    new Fl_Input(gx+100,gy+50, 100,25,"Wide Tab 3a");
    new Fl_Input(gx+100,gy+85, 100,25,"Wide Tab 3b");
    new Fl_Input(gx+100,gy+120,100,25,"Wide Tab 3c");
    g3->end();
    Fl_Group *g4 = new Fl_Group(gx,gy,gw,gh,"Tab4");
    new Fl_Input(gx+100,gy+50, 50, 25,"Wide Tab 4a");
    new Fl_Input(gx+100,gy+85, 50, 25,"Wide Tab 4b");
    new Fl_Input(gx+100,gy+120,150,25,"Wide Tab 4c");
    g4->end();
    Fl_Group *g5 = new Fl_Group(gx,gy,gw,gh,"Tab5");
    g5->end();
    tabs->end();
  }
  win.resizable(win);
  win.show();
  return(Fl::run());
}
