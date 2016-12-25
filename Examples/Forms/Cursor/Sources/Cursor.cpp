#include <Pcf/Pcf>

using namespace System;
using namespace System::Windows::Forms;

namespace CursorExample {
  class Form1 : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }
    
    Form1() {
      this->Text = "Cursor example";
      this->StartPosition = FormStartPosition::Manual;
      this->Location = System::Drawing::Point(200, 200);
      this->ClientSize = System::Drawing::Size(360, 240);
      
      this->listBoxCursors.Parent = *this;
      this->listBoxCursors.Anchor = AnchorStyles::Top | AnchorStyles::Left | AnchorStyles::Bottom;
      this->listBoxCursors.Bounds = System::Drawing::Rectangle(20, 20, 150, 200);
      
      this->listBoxCursors.Items().AddRange(Array<CursorNamePair> {
        {Cursors::AppStarting, "AppStarting"},
        {Cursors::Arrow, "Arrow"},
        {Cursors::Cross, "Cross"},
        {Cursors::Default, "Default"},
        {Cursors::Hand, "Hand"},
        {Cursors::Help, "Help"},
        {Cursors::HSplit, "HSplit"},
        {Cursors::IBeam, "IBeam"},
        {Cursors::No, "No"},
        {Cursors::NoMove2D, "NoMove2D"},
        {Cursors::NoMoveHoriz, "NoMoveHoriz"},
        {Cursors::NoMoveVert, "NoMoveVert"},
        {Cursors::PanEast, "PanEast"},
        {Cursors::PanNE, "PanNE"},
        {Cursors::PanNorth, "PanNorth"},
        {Cursors::PanNW, "PanNW"},
        {Cursors::PanSE, "PanSE"},
        {Cursors::PanSouth, "PanSouth"},
        {Cursors::PanSW, "PanSW"},
        {Cursors::PanWest, "PanWest"},
        {Cursors::SizeAll, "SizeAll"},
        {Cursors::SizeNESW, "SizeNESW"},
        {Cursors::SizeNS, "SizeNS"},
        {Cursors::SizeNWSE, "SizeNWSE"},
        {Cursors::SizeWE, "SizeWE"},
        {Cursors::UpArrow, "UpArrow"},
        {Cursors::VSplit, "VSplit"},
        {Cursors::WaitCursor, "WaitCursor"}
      });
      this->listBoxCursors.Click += pcf_delegate(const object& sender, const EventArgs& e) {
        this->testZone.Cursor = as<CursorNamePair>(this->listBoxCursors.SelectedItem())->Cursor;
      };
      
      this->testZone.Parent = *this;
      this->testZone.Anchor = AnchorStyles::Top | AnchorStyles::Left | AnchorStyles::Bottom | AnchorStyles::Right;
      this->testZone.BorderStyle = BorderStyle::Fixed3D;
      this->testZone.BackColor = Drawing::Color::White;
      this->testZone.Bounds = System::Drawing::Rectangle(190, 20, 150, 200);
    }
    
  private:
    class CursorNamePair : public object {
    public:
      CursorNamePair() {}
      CursorNamePair(const System::Windows::Forms::Cursor& cursor, const string& name) : cursor(cursor), name(name) {}
      CursorNamePair(const CursorNamePair& cursorNamePair) : cursor(cursorNamePair.cursor), name(cursorNamePair.name) {}
      CursorNamePair& operator =(const CursorNamePair& cursorNamePair) {
        this->cursor = cursorNamePair.cursor;
        this->name = cursorNamePair.name;
        return *this;
      }
      
      Property<System::Windows::Forms::Cursor, ReadOnly> Cursor {
        pcf_get {return this->cursor;}
      };
      
      Property<string, ReadOnly> Name {
        pcf_get {return this->name;}
      };
      
      string ToString() const override {return this->Name;}
      
    private:
      System::Windows::Forms::Cursor cursor = Cursors::Default;
      string name = "Default";
    };
    
    ListBox listBoxCursors;
    Panel testZone;
  };
}

pcf_startup (CursorExample::Form1)
