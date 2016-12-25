#include <Pcf/Pcf.h>

using namespace System;
using namespace System::Diagnostics;
using namespace System::Threading;
using namespace System::Windows::FormsD;

class Form1 : public Form {
public:
  // The main entry point for the application.
  static void Main() {
    Application::EnableVisualStyles();
    Application::Run(Form1());
  }
  
  Form1() {
    this->StartPosition = FormStartPosition::Manual;
    this->Location = System::Drawing::Point(300, 200);
    this->Text = "Form and thread";
    this->FormClosed += pcf_delegate(const object& sender, const EventArgs& e) {
      this->closed = true;
    };
    
    this->progressBar.Parent = *this;
    this->progressBar.Location = System::Drawing::Point(100, 100);
    
    this->button.Parent = *this;
    this->button.Text = "Reset";
    this->button.Location = System::Drawing::Point(110, 150);
    this->button.Click += pcf_delegate(const object& sender, const EventArgs& e) {
      this->progressBar.Value = this->progressBar.Minimum;
    };
    
    this->thread = Thread(ThreadStart(pcf_delegate {
      Thread::Sleep(TimeSpan::FromMilliseconds(1000));
      while (!this->closed) {
        this->Invoke(MethodInvoker(pcf_delegate {
          this->progressBar.Value = this->progressBar.Value < this->progressBar.Maximum ? this->progressBar.Value + 1 : this->progressBar.Minimum;
          Debug::WriteLine("ThreadId = {0}, progressBar.Value = {1}", Thread::CurrentThread().ManagedThreadId, this->progressBar.Value);
        }));
        Thread::Sleep(TimeSpan::FromMilliseconds(50));
      }
    }));
    this->thread.Start();
  }
  
private:
  ProgressBar progressBar;
  Button button;
  Thread thread;
  bool closed = false;
};

pcf_startup (Form1)
