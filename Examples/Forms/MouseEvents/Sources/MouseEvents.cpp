#include <Pcf/Pcf>

using namespace System;
using namespace System::Windows::FormsD;

namespace MouseEventsExample {
  class Form1 : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }
    
    Form1() {
      this->Text = "MouseEvents example";
      this->StartPosition = FormStartPosition::Manual;
      this->Location = System::Drawing::Point(300, 50);
      this->ClientSize = System::Drawing::Size(640, 825);
      
      this->panel1.Parent = *this;
      this->panel1.BorderStyle = BorderStyle::Fixed3D;
      this->panel1.BackColor = System::Drawing::Color::White;
      this->panel1.Dock = DockStyle::Fill;
      
      this->panel1.KeyDown += pcf_delegate(const object& sender, KeyEventArgs& e) {
        this->label1.Text = EventToString("panel1", "KeyDown", e);
      };
      this->panel1.KeyPress += pcf_delegate(const object& sender, KeyPressEventArgs& e) {
        this->label1.Text += EventToString("panel1", "KeyPress", e);
      };
      this->panel1.KeyUp += pcf_delegate(const object& sender, KeyEventArgs& e) {
        this->label1.Text += EventToString("panel1", "KeyUp", e);
      };
      this->panel1.MouseEnter += pcf_delegate(const object& sender, const EventArgs& e) {
        this->label1.Text += EventToString("panel1", "MouseEnter", e);
      };
      this->panel1.MouseDown += pcf_delegate(const object& sender, const MouseEventArgs& e) {
        this->label1.Text = EventToString("panel1", "MouseDown", e);
      };
      this->panel1.Click += pcf_delegate(const object& sender, const EventArgs& e) {
        this->label1.Text += EventToString("panel1", "Click", e);
      };
      this->panel1.MouseClick += pcf_delegate(const object& sender, const MouseEventArgs& e) {
        this->label1.Text += EventToString("panel1", "MouseClick", e);
      };
      this->panel1.DoubleClick += pcf_delegate(const object& sender, const EventArgs& e) {
        this->label1.Text += EventToString("panel1", "DoubleClick", e);
      };
      this->panel1.MouseDoubleClick += pcf_delegate(const object& sender, const MouseEventArgs& e) {
        this->label1.Text += EventToString("panel1", "MouseDoubleClick", e);
      };
      this->panel1.MouseUp += pcf_delegate(const object& sender, const MouseEventArgs& e) {
        this->label1.Text += EventToString("panel1", "MouseUp", e);
      };
      this->panel1.MouseWheel += pcf_delegate(const object& sender, const MouseEventArgs& e) {
        this->label1.Text = EventToString("panel1", "MouseWheel", e);
      };
      this->panel1.MouseLeave += pcf_delegate(const object& sender, const EventArgs& e) {
        this->label1.Text = EventToString("panel1", "MouseLeave", e);
      };
      
      this->label1.Parent = *this;
      this->label1.Size = System::Drawing::Size(640, 780);
      this->label1.BorderStyle = BorderStyle::Fixed3D;
      this->label1.BackColor = System::Drawing::Color::White;
      this->label1.Dock = DockStyle::Top;
      
      this->label1.KeyDown += pcf_delegate(const object& sender, KeyEventArgs& e) {
        this->label1.Text = EventToString("label1", "KeyDown", e);
      };
      this->label1.KeyPress += pcf_delegate(const object& sender, KeyPressEventArgs& e) {
        this->label1.Text += EventToString("label1", "KeyPress", e);
      };
      this->label1.KeyUp += pcf_delegate(const object& sender, KeyEventArgs& e) {
        this->label1.Text += EventToString("label1", "KeyUp", e);
      };
      this->label1.MouseEnter += pcf_delegate(const object& sender, const EventArgs& e) {
        this->label1.Text += EventToString("label1", "MouseEnter", e);
      };
      this->label1.MouseDown += pcf_delegate(const object& sender, const MouseEventArgs& e) {
        this->label1.Text = EventToString("label1", "MouseDown", e);
      };
      this->label1.Click += pcf_delegate(const object& sender, const EventArgs& e) {
        this->label1.Text += EventToString("label1", "Click", e);
      };
      this->label1.MouseClick += pcf_delegate(const object& sender, const MouseEventArgs& e) {
        this->label1.Text += EventToString("label1", "MouseClick", e);
      };
      this->label1.DoubleClick += pcf_delegate(const object& sender, const EventArgs& e) {
        this->label1.Text += EventToString("label1", "DoubleClick", e);
      };
      this->label1.MouseDoubleClick += pcf_delegate(const object& sender, const MouseEventArgs& e) {
        this->label1.Text += EventToString("label1", "MouseDoubleClick", e);
      };
      this->label1.MouseUp += pcf_delegate(const object& sender, const MouseEventArgs& e) {
        this->label1.Text += EventToString("label1", "MouseUp", e);
      };
      this->label1.MouseWheel += pcf_delegate(const object& sender, const MouseEventArgs& e) {
        this->label1.Text = EventToString("label1", "MouseWheel", e);
      };
      this->label1.MouseLeave += pcf_delegate(const object& sender, const EventArgs& e) {
        this->label1.Text = EventToString("label1", "MouseLeave", e);
      };
      
      this->button1.Parent = this->panel1;
      this->button1.Location = System::Drawing::Point(10, 10);
      this->button1.Text = "Button";
      
      this->label2.Parent = this->panel1;
      this->label2.AutoSize = true;
      this->label2.Location = System::Drawing::Point(120, 10);
      
      this->MouseMove += {*this, &Form1::OnFormMouseMove};
      this->label1.MouseMove += {*this, &Form1::OnFormMouseMove};
      this->panel1.MouseMove += {*this, &Form1::OnFormMouseMove};
      this->label2.MouseMove += {*this, &Form1::OnFormMouseMove};
      this->button1.MouseMove += {*this, &Form1::OnFormMouseMove};
    }
    
  private:
    static string EventToString(const string& n, const string& e, const KeyEventArgs& a) {
      return string::Format("[{0}]\n", n) +
      string::Format("  Event = {0}\n", e) +
      String::Format("  KeyData = {0}\n", a.KeyData) +
      String::Format("  KeyValue = {0:X}\n", a.KeyValue) +
      String::Format("  KeyCode = {0}\n", a.KeyCode) +
      string::Format("  Modifiers = {0}\n", a.Modifiers) +
      String::Format("  Shift = {0}\n", a.Shift) +
      String::Format("  Control = {0}\n", a.Control) +
      String::Format("  Alt = {0}\n", a.Alt) +
      String::Format("  Command = {0}\n\n", a.Command);
    }
    
    static string EventToString(const string& n, const string& e, const KeyPressEventArgs& a) {
      return string::Format("[{0}]\n", n) +
      string::Format("  Event = {0}\n", e) +
      String::Format("  KeyChar = {0}\n", a.KeyChar) +
      String::Format("  value = {0}\n\n", Convert::ToInt32(a.KeyChar));
    }
    
    static string EventToString(const string& n, const string& e, const MouseEventArgs& a) {
      return string::Format("[{0}]\n", n) +
      string::Format("  Event = {0}\n", e) +
      String::Format("  Button = {0}\n", a.Button) +
      String::Format("  Location = {0:X}\n", a.Location) +
      String::Format("  Clicks = {0}\n", a.Clicks) +
      String::Format("  Delta = {0}\n", a.Delta) +
      String::Format("  X = {0}\n", a.X) +
      String::Format("  Y = {0}\n\n", a.Y);
    }
    
    static string EventToString(const string& n, const string& e, const EventArgs& a) {
      return string::Format("[{0}]\n", n) +
      string::Format("  Event = {0}\n", e);
    }
    
    void OnFormMouseMove(const object& sender, const MouseEventArgs& e) {
      this->label2.Text = string::Format("Mouse Location {0}", e.Location);
    }
    
    Label label1;
    Panel panel1;
    Button button1;
    Label label2;
  };
}

pcf_startup (MouseEventsExample::Form1)
