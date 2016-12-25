#include <Pcf/Pcf>

using namespace System;
using namespace System::Windows::Forms;

namespace ExceptionExample {
  class Form1 : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }
    
    Form1() {
      this->Text = "Exception example";
      this->StartPosition = FormStartPosition::Manual;
      this->Location = System::Drawing::Point(300, 200);
      
      this->buttonHandledException.Parent = *this;
      this->buttonHandledException.Text = "Handled Exception";
      this->buttonHandledException.Location = System::Drawing::Point(10, 10);
      this->buttonHandledException.Size = System::Drawing::Size(130, 23);
      this->buttonHandledException.Click += pcf_delegate(const object& sender, const EventArgs& e) {
        try {
          throw InvalidOperationException(pcf_current_information);
        } catch (const Exception& exception) {
          MessageBox::Show(exception.Message, "Exception occured");
        }
      };
      
      this->buttonUnhandledException.Parent = *this;
      this->buttonUnhandledException.Text = "Unhandled Exception";
      this->buttonUnhandledException.Location = System::Drawing::Point(10, 40);
      this->buttonUnhandledException.Size = System::Drawing::Size(130, 23);
      this->buttonUnhandledException.Click += pcf_delegate(const object& sender, const EventArgs& e) {
        throw InvalidOperationException(pcf_current_information);
      };
    }
    
  private:
    Button buttonHandledException;
    Button buttonUnhandledException;
  };
}

pcf_startup (ExceptionExample::Form1)
