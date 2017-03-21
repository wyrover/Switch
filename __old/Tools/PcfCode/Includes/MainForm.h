#include <Forms/System/Windows/Forms/ListBox.h>
#include <Forms/System/Windows/Forms/Form.h>
#include <Forms/System/Windows/Forms/RichTextBox.h>
#include <Forms/System/Windows/Forms/TabControl.h>
#include <Forms/System/Windows/Forms/TabPage.h>

#include "../Includes/GenerateSources.h"

namespace Pcf {
  namespace PcfCode {
    class MainForm : public System::Windows::Forms::Form {
    public:
      MainForm();
      
    private:
      void InitializeComponent();
      
      
      Sp<System::Windows::Forms::Control> CreateButton();
      Sp<System::Windows::Forms::Control> CreateCheckBox();
      Sp<System::Windows::Forms::Control> CreateCheckedListBox();
      Sp<System::Windows::Forms::Control> CreateLabel();
      Sp<System::Windows::Forms::Control> CreateListBox();
      Sp<System::Windows::Forms::Control> CreateMaskedTextBox();
      Sp<System::Windows::Forms::Control> CreateNumericUpDown();
      Sp<System::Windows::Forms::Control> CreatePictureBox();
      Sp<System::Windows::Forms::Control> CreateProgressBar();
      Sp<System::Windows::Forms::Control> CreateRadioButton();
      Sp<System::Windows::Forms::Control> CreateRichTextBox();
      Sp<System::Windows::Forms::Control> CreateTextBox();
      Sp<System::Windows::Forms::Control> CreateGroupBox();
      Sp<System::Windows::Forms::Control> CreatePanel();
      Sp<System::Windows::Forms::Control> CreateTabControl();
      
      void OnListBoxControlMouseDown(const object& sender, const System::Windows::Forms::MouseEventArgs& e);
      void OnPanelFormDragEnter(const object& sender, System::Windows::Forms::DragEventArgs& e);
      void OnPanelFormDragOver(const object& sender, System::Windows::Forms::DragEventArgs& e);
      void OnPanelFormDragDrop(const object& sender, System::Windows::Forms::DragEventArgs& e);
      void OnPanelFormDragLeave(const object& sender, const System::EventArgs& e);
      void OnTabPageDesignerPaint(const object& sender, System::Windows::Forms::PaintEventArgs& e);
      void OnPanelFormMouseDown(const object& sender, const System::Windows::Forms::MouseEventArgs& e);
      void OnControlMouseDown(const object& sender, const System::Windows::Forms::MouseEventArgs& e);
      
      void DrawSelectedBorder(System::Drawing::Graphics& graphics, const Sp<Control>& control);
      
      Sp<System::Windows::Forms::Panel> panelLeft;
      Sp<System::Windows::Forms::TabControl> tabControlFill;
      Sp<System::Windows::Forms::TabPage> tabPageDesigner;
      Sp<System::Windows::Forms::TabPage> tabPageGeneratedSource;
      Sp<System::Windows::Forms::Panel> panelForm;
      Sp<System::Windows::Forms::ListBox> listBoxControl;
      Sp<System::Windows::Forms::Control> controlDrop;
      Sp<System::Windows::Forms::RichTextBox> richTextBoxGeneratedSource;
      System::Collections::Generic::List<Sp<System::Windows::Forms::Control> > controls;
      Sp<System::Windows::Forms::Control> controlSelected;
      System::Drawing::Point offsetMouse;
      
      int32 cptButton;
      int32 cptCheckBox;
      int32 cptCheckedListBox;
      int32 cptLabel;
      int32 cptListBox;
      int32 cptMaskedTextBox;
      int32 cptNumericUpDown;
      int32 cptPictureBox;
      int32 cptProgressBar;
      int32 cptRadioButton;
      int32 cptRichTextBox;
      int32 cptTextBox;
      int32 cptGroupBox;
      int32 cptPanel;
      int32 cptTabControl;
    };
  }
}
