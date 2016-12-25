#include <FL/Fltk.h>
#include "../../../../../Includes/Pcf/System/Windows/Forms/OpenFileDialog.h"

using namespace System;
using namespace System::Windows::FormsD;

OpenFileDialog::OpenFileDialog() {
  this->handle = new Fl_Native_File_Chooser(Fl_Native_File_Chooser::BROWSE_FILE);
  (*(Fl_Native_File_Chooser*)this->handle).title("Open");
  (*(Fl_Native_File_Chooser*)this->handle).options((*(Fl_Native_File_Chooser*)this->handle).options() | Fl_Native_File_Chooser::USE_FILTER_EXT);
}

OpenFileDialog::~OpenFileDialog() {
  delete (Fl_Native_File_Chooser*)this->handle;
}

string OpenFileDialog::GetInitialDirectory() const {
  return (*(Fl_Native_File_Chooser*)this->handle).directory();
}

void OpenFileDialog::SetInitialDirectory(const string& directory) {
  (*(Fl_Native_File_Chooser*)this->handle).directory(directory.Data);
}

string OpenFileDialog::GetFileName() const {
  return (*(Fl_Native_File_Chooser*)this->handle).filename();
}

Array<string> OpenFileDialog::GetFileNames() const {
  Array<string> fileNames((*(Fl_Native_File_Chooser*)this->handle).count());
  for (int32 index = 0; index < fileNames.Length(); index++)
    fileNames[index] = (*(Fl_Native_File_Chooser*)this->handle).filename(index);
  return fileNames;
}

string OpenFileDialog::GetFilter() const {
  return string((*(Fl_Native_File_Chooser*)this->handle).filter()).Replace("\t", "|").Replace("{", "").Replace("}", "");
}

void OpenFileDialog::SetFilter(const string& filter) {
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

int32 OpenFileDialog::GetFilterIndex() const {
  return (*(Fl_Native_File_Chooser*)this->handle).filter_value();
}

void OpenFileDialog::SetFilterIndex(int32 index) {
 (*(Fl_Native_File_Chooser*)this->handle).filter_value(index);
}

bool OpenFileDialog::GetMultiselect() const {
  return (*(Fl_Native_File_Chooser*)this->handle).type() == Fl_Native_File_Chooser::BROWSE_MULTI_FILE;
}

void OpenFileDialog::SetMultiselect(bool multiselect) {
  (*(Fl_Native_File_Chooser*)this->handle).type((multiselect ? Fl_Native_File_Chooser::BROWSE_MULTI_FILE : Fl_Native_File_Chooser::BROWSE_FILE));
}

string OpenFileDialog::GetTitle() const {
  return (*(Fl_Native_File_Chooser*)this->handle).title();
}

void OpenFileDialog::SetTitle(const string& title) {
  (*(Fl_Native_File_Chooser*)this->handle).title(title.Data);
}

DialogResult OpenFileDialog::ShowDialog() {
  DialogResult result = (*(Fl_Native_File_Chooser*)this->handle).show() == 0 ? DialogResult::OK : DialogResult::Cancel;
  if (result == DialogResult::OK) {
    ComponentModel::CancelEventArgs cancelEventArgs;
    Click(*this, cancelEventArgs);
    if (cancelEventArgs.Cancel)
      result = DialogResult::Cancel;
  }
  return result;
}
