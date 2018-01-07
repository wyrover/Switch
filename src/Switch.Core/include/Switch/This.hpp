/// @file
/// @brief Contains #using_ keyword.
#pragma once

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The specified keyword represent a reference on this (same as *this).
  /// @par Examples
  /// @code
  /// class Form1 : public System::Windows::Forms {
  /// public:
  ///   Form1() {
  ///     button1.Location = Ssytem::Drawing::Point(30, 30);
  ///     button1.Text = "Click me";
  ///     this_.Controls().Add(button1);
  ///     button1.Click += System::EventHandler(this_, &Form1::button1_click);
  ///   }
  ///
  /// private:
  ///   void button1_Click(const object& sender, const System::EventArgs& e) {
  ///     System::Windows::Forms::MessageBox::Show("Hello World");
  ///   }
  ///
  ///   Button button1;
  /// };
  /// @endcode
  /// @ingroup Keywords
#define this_ \
  (*this)
}

using namespace Switch;
