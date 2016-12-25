#include <FL/Fltk.h>
#include "../../../../../Includes/Pcf/System/Windows/Forms/SaveFileDialog.h"

using namespace System;
using namespace System::Windows::FormsD;

SaveFileDialog::SaveFileDialog() {
  this->handle = new Fl_Native_File_Chooser(Fl_Native_File_Chooser::BROWSE_SAVE_FILE);
  (*(Fl_Native_File_Chooser*)this->handle).title("Save");
  (*(Fl_Native_File_Chooser*)this->handle).options((*(Fl_Native_File_Chooser*)this->handle).options() | Fl_Native_File_Chooser::USE_FILTER_EXT);
}

SaveFileDialog::~SaveFileDialog() {
  delete (Fl_Native_File_Chooser*)this->handle;
}

string SaveFileDialog::GetInitialDirectory() const {
  return (*(Fl_Native_File_Chooser*)this->handle).directory();
}

void SaveFileDialog::SetInitialDirectory(const string& directory) {
  (*(Fl_Native_File_Chooser*)this->handle).directory(directory.Data);
}

string SaveFileDialog::GetFileName() const {
  return (*(Fl_Native_File_Chooser*)this->handle).filename();
}

string SaveFileDialog::GetFilter() const {
  return string((*(Fl_Native_File_Chooser*)this->handle).filter()).Replace("\t", "|").Replace("{", "").Replace("}", "");
}

void SaveFileDialog::SetFilter(const string& filter) {
  if (filter.Contains("{") || filter.Contains("}") || filter.Contains("\t"))
    throw FormatException(pcf_current_information);
  
  Array<string> filters = filter.Split('|');

  if (filters.Length() <= 0 || filters.Length() %2 != 0)
    throw FormatException(pcf_current_information);
  
  string fltkFilter;
  for (int32 indexFilter = 0; indexFilter < filters.Length(); indexFilter += 2) {
    Array<string> extensions = filters[indexFilter + 1].Split(';');
    string wildcards = "*.{";
    for (int32 indexExtension = 0; indexExtension < extensions.Length(); indexExtension++) {
      wildcards = string::Format("{0}{1},", wildcards, System::IO::Path::GetExtension(extensions[indexExtension]).Substring(1));
    }
    wildcards = wildcards.Remove(wildcards.Length()-1);
    wildcards = string::Format("{0}}}", wildcards);
    fltkFilter = string::Format("{0}{1}\t{2}\n", fltkFilter, filters[indexFilter], wildcards);
  }
  
  (*(Fl_Native_File_Chooser*)this->handle).filter(fltkFilter.Data());
}

int32 SaveFileDialog::GetFilterIndex() const {
  return (*(Fl_Native_File_Chooser*)this->handle).filter_value();
}

void SaveFileDialog::SetFilterIndex(int32 index) {
 (*(Fl_Native_File_Chooser*)this->handle).filter_value(index);
}

string SaveFileDialog::GetTitle() const {
  return (*(Fl_Native_File_Chooser*)this->handle).title();
}

void SaveFileDialog::SetTitle(const string& title) {
  (*(Fl_Native_File_Chooser*)this->handle).title(title.Data);
}

DialogResult SaveFileDialog::ShowDialog() {
  DialogResult result = (*(Fl_Native_File_Chooser*)this->handle).show() == 0 ? DialogResult::OK : DialogResult::Cancel;
  if (result == DialogResult::OK) {
    ComponentModel::CancelEventArgs cancelEventArgs;
    Click(*this, cancelEventArgs);
    if (cancelEventArgs.Cancel)
      result = DialogResult::Cancel;
  }
  return result;
}
