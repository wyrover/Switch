#include <Pcf/Pcf>

using namespace System;
using namespace System::Windows::FormsD;

namespace MainMenuExample {
  class Form1 : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }
    
    Form1() {
      this->StartPosition = FormStartPosition::Manual;
      this->Location = System::Drawing::Point(400, 200);
      this->Text = "MainMenu example";
      
      Array<MenuItem> openRecentsMenu = {
        MenuItem("File 1", EventHandler(*this, &Form1::OnFileOpenRecentSelected)),
        MenuItem("File 2", EventHandler(*this, &Form1::OnFileOpenRecentSelected))
      };
      
      Array<MenuItem> fileMenu = {
        MenuItem("New", EventHandler(*this, &Form1::OnFileNewSelected), Shortcut::CmdN),
        MenuItem("-"),
        MenuItem("Open...", EventHandler(*this, &Form1::OnFileOpenSelected), Shortcut::CmdO),
        MenuItem("Open recent", openRecentsMenu),
        MenuItem("-"),
        MenuItem("Close", EventHandler(*this, &Form1::OnFileCloseSelected), Shortcut::CmdW),
        MenuItem("-"),
        MenuItem("Save", EventHandler(*this, &Form1::OnFileSaveSelected), Shortcut::CmdS),
        MenuItem("Save as...", EventHandler(*this, &Form1::OnFileSaveAsSelected))};
      
      Array<MenuItem> editMenu = {
        MenuItem("Undo", EventHandler(*this, &Form1::OnEditUndoSelected), Shortcut::CmdZ),
        MenuItem("Redo", EventHandler(*this, &Form1::OnEditRedoSelected), Shortcut::CmdY),
        MenuItem("-"),
        MenuItem("Cut", EventHandler(*this, &Form1::OnEditCutSelected), Shortcut::CmdX),
        MenuItem("Copy", EventHandler(*this, &Form1::OnEditCopySelected), Shortcut::CmdC),
        MenuItem("Paste", EventHandler(*this, &Form1::OnEditPasteSelected), Shortcut::CmdV),
        MenuItem("-"),
        MenuItem("Select All", EventHandler(*this, &Form1::OnEditSelectAllSelected), Shortcut::CmdA)};
   
      Array<MenuItem> viewMenu = {
        MenuItem("Show", EventHandler(*this, &Form1::OnViewShowSelected)),
        MenuItem("Hide", EventHandler(*this, &Form1::OnViewHideSelected))
      };
      
      this->mainMenu.MenuItems().Add(MenuItem("File", fileMenu));
      this->mainMenu.MenuItems().Add(MenuItem("Edit", editMenu));
      this->mainMenu.MenuItems().Add(MenuItem("View", viewMenu));
      
      this->mainMenu.MenuItems()[0].MenuItems()[3].MenuItems().Add(MenuItem("File 3", EventHandler(*this, &Form1::OnFileOpenRecentSelected)));
      this->Menu = this->mainMenu;

      this->menuClicks.Parent = *this;
      this->menuClicks.Anchor = AnchorStyles::Left | AnchorStyles::Top | AnchorStyles::Right | AnchorStyles::Bottom;
      this->menuClicks.Bounds = System::Drawing::Rectangle(10, 10, this->ClientSize().Width - 20, this->ClientSize().Height - 20);
    }
    
  private:
    void OnFileNewSelected(const object& sender, const EventArgs& e) {
      menuClicks.Items().Add("File/New selected");
    }
    
    void OnFileOpenSelected(const object& sender, const EventArgs& e) {
      menuClicks.Items().Add("File/Open... selected");
    }
    
    void OnFileOpenRecentSelected(const object& sender, const EventArgs& e) {
      menuClicks.Items().Add(string::Format("File/OpenRecent [{0}] selected", as<MenuItem>(sender).Text()));
    }
    
    void OnFileCloseSelected(const object& sender, const EventArgs& e) {
      menuClicks.Items().Add("File/Close selected");
    }
    
    void OnFileSaveSelected(const object& sender, const EventArgs& e) {
      menuClicks.Items().Add("File/Save selected");
    }
    
    void OnFileSaveAsSelected(const object& sender, const EventArgs& e) {
      menuClicks.Items().Add("File/Save as... selected");
    }
    
    void OnEditUndoSelected(const object& sender, const EventArgs& e) {
      menuClicks.Items().Add("Edit/Undo selected");
    }
    
    void OnEditRedoSelected(const object& sender, const EventArgs& e) {
      menuClicks.Items().Add("Edit/Redo selected");
    }
    
    void OnEditCutSelected(const object& sender, const EventArgs& e) {
      menuClicks.Items().Add("Edit/Cut selected");
    }
    
    void OnEditCopySelected(const object& sender, const EventArgs& e) {
      menuClicks.Items().Add("Edit/Copy selected");
    }
    
    void OnEditPasteSelected(const object& sender, const EventArgs& e) {
      menuClicks.Items().Add("Edit/Paste selected");
    }
    
    void OnEditSelectAllSelected(const object& sender, const EventArgs& e) {
      menuClicks.Items().Add("Edit/Select All selected");
    }
    
    void OnViewShowSelected(const object& sender, const EventArgs& e) {
      menuClicks.Items().Add("View/Show selected");
    }
    
    void OnViewHideSelected(const object& sender, const EventArgs& e) {
      menuClicks.Items().Add("View/Hide selected");
    }
    
    MainMenu mainMenu;
    ListBox menuClicks;
  };
}

pcf_startup (MainMenuExample::Form1)
