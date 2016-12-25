#include <FL/Fltk.h>
#include "../../../../../Includes/Pcf/System/Windows/Forms/FolderBrowserDialog.h"

using namespace System::Windows::Forms;

FolderBrowserDialog::FolderBrowserDialog() {
  this->handle = new Fl_Native_File_Chooser(Fl_Native_File_Chooser::BROWSE_DIRECTORY);
}

FolderBrowserDialog::~FolderBrowserDialog() {
  delete (Fl_Native_File_Chooser*)this->handle;
}

string FolderBrowserDialog::GetDescription() const {
  return (*(Fl_Native_File_Chooser*)this->handle).title();
}

void FolderBrowserDialog::SetDescription(const string& description) {
  (*(Fl_Native_File_Chooser*)this->handle).title(description.Data);
}

string FolderBrowserDialog::GetSelectedPath() const {
  return (*(Fl_Native_File_Chooser*)this->handle).filename();
}

void FolderBrowserDialog::SetSelectedPath(const string& selectedPath) {
  return (*(Fl_Native_File_Chooser*)this->handle).directory(selectedPath.Data);
}

bool FolderBrowserDialog::GetShowNewFolderButton() const {
  return ((*(Fl_Native_File_Chooser*)this->handle).options() & Fl_Native_File_Chooser::NEW_FOLDER) == Fl_Native_File_Chooser::NEW_FOLDER;
}

void FolderBrowserDialog::SetShowNewFolderButton(bool show) {
  if (show)
    (*(Fl_Native_File_Chooser*)this->handle).options((*(Fl_Native_File_Chooser*)this->handle).options() | Fl_Native_File_Chooser::NEW_FOLDER);
  else
    (*(Fl_Native_File_Chooser*)this->handle).options((*(Fl_Native_File_Chooser*)this->handle).options() & ~Fl_Native_File_Chooser::NEW_FOLDER);
}

DialogResult FolderBrowserDialog::ShowDialog() {
  DialogResult result = (*(Fl_Native_File_Chooser*)this->handle).show() == 0 ? DialogResult::OK : DialogResult::Cancel;
  if (result == DialogResult::OK) {
    ComponentModel::CancelEventArgs cancelEventArgs;
    Click(*this, cancelEventArgs);
    if (cancelEventArgs.Cancel)
      result = DialogResult::Cancel;
  }
  return result;
}
