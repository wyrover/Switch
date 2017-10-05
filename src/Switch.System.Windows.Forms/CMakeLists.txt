set(INCLUDE_FILES
  include/Switch/System/ComponentModel/CancelEventArgs.hpp
  include/Switch/System/ComponentModel/CancelEventHandler.hpp
  include/Switch/System/ComponentModel/Component.hpp
  include/Switch/System/ComponentModel/ComponentCollection.hpp
  include/Switch/System/ComponentModel/EventHandlerList.hpp
  include/Switch/System/ComponentModel/IComponent.hpp
  include/Switch/System/ComponentModel/IContainer.hpp
  include/Switch/System/ComponentModel/ISite.hpp
  include/Switch/System/Media/SystemSound.hpp
  include/Switch/System/Media/SystemSounds.hpp
  include/Switch/System/Windows/Forms/VisualStyles/VisualStyleState.hpp
  include/Switch/System/Windows/Forms/AccessibleEvents.hpp
  include/Switch/System/Windows/Forms/AccessibleNavigation.hpp
  include/Switch/System/Windows/Forms/AccessibleRole.hpp
  include/Switch/System/Windows/Forms/AnchorStyles.hpp
  include/Switch/System/Windows/Forms/Application.hpp
  include/Switch/System/Windows/Forms/ArrangeDirection.hpp
  include/Switch/System/Windows/Forms/ArrangeStartingPosition.hpp
  include/Switch/System/Windows/Forms/AutoSizeMode.hpp
  include/Switch/System/Windows/Forms/BootMode.hpp
  include/Switch/System/Windows/Forms/BorderStyle.hpp
  include/Switch/System/Windows/Forms/Button.hpp
  include/Switch/System/Windows/Forms/ButtonBase.hpp
  include/Switch/System/Windows/Forms/CheckBox.hpp
#  include/Switch/System/Windows/Forms/CheckedListBox.hpp
  include/Switch/System/Windows/Forms/CheckState.hpp
  include/Switch/System/Windows/Forms/CloseReason.hpp
  include/Switch/System/Windows/Forms/ContainerControl.hpp
  include/Switch/System/Windows/Forms/Control.hpp
  include/Switch/System/Windows/Forms/ControlEventArgs.hpp
  include/Switch/System/Windows/Forms/ControlEventHandler.hpp
  include/Switch/System/Windows/Forms/ControlStyles.hpp
#  include/Switch/System/Windows/Forms/Cursor.hpp
#  include/Switch/System/Windows/Forms/Cursors.hpp
  include/Switch/System/Windows/Forms/DataFormats.hpp
  include/Switch/System/Windows/Forms/DialogResult.hpp
  include/Switch/System/Windows/Forms/DockStyle.hpp
  include/Switch/System/Windows/Forms/DragDropEffects.hpp
  include/Switch/System/Windows/Forms/DragEventArgs.hpp
  include/Switch/System/Windows/Forms/DragEventHandler.hpp
#  include/Switch/System/Windows/Forms/FolderBrowserDialog.hpp
  include/Switch/System/Windows/Forms/Form.hpp
  include/Switch/System/Windows/Forms/FormBorderStyle.hpp
  include/Switch/System/Windows/Forms/FormClosedEventArgs.hpp
  include/Switch/System/Windows/Forms/FormClosedEventHandler.hpp
  include/Switch/System/Windows/Forms/FormClosingEventArgs.hpp
  include/Switch/System/Windows/Forms/FormClosingEventHandler.hpp
  include/Switch/System/Windows/Forms/FormStartPosition.hpp
  include/Switch/System/Windows/Forms/GiveFeedbackEventArgs.hpp
  include/Switch/System/Windows/Forms/GiveFeedbackEventHandler.hpp
  include/Switch/System/Windows/Forms/GroupBox.hpp
  include/Switch/System/Windows/Forms/HelpEventArgs.hpp
  include/Switch/System/Windows/Forms/HelpEventHandler.hpp
  include/Switch/System/Windows/Forms/IDataObject.hpp
#  include/Switch/System/Windows/Forms/ImageList.hpp
  include/Switch/System/Windows/Forms/ImageLayout.hpp
  include/Switch/System/Windows/Forms/InvalidateEventArgs.hpp
  include/Switch/System/Windows/Forms/InvalidateEventHandler.hpp
  include/Switch/System/Windows/Forms/KeyEventArgs.hpp
  include/Switch/System/Windows/Forms/KeyEventHandler.hpp
  include/Switch/System/Windows/Forms/KeyPressEventArgs.hpp
  include/Switch/System/Windows/Forms/KeyPressEventHandler.hpp
  include/Switch/System/Windows/Forms/Keys.hpp
  include/Switch/System/Windows/Forms/Label.hpp
#  include/Switch/System/Windows/Forms/ListBox.hpp
  include/Switch/System/Windows/Forms/ListControl.hpp
#  include/Switch/System/Windows/Forms/MainMenu.hpp
#  include/Switch/System/Windows/Forms/MaskedTextBox.hpp
#  include/Switch/System/Windows/Forms/Menu.hpp
#  include/Switch/System/Windows/Forms/MenuItem.hpp
  include/Switch/System/Windows/Forms/Message.hpp
  include/Switch/System/Windows/Forms/MessageBox.hpp
  include/Switch/System/Windows/Forms/MessageBoxButtons.hpp
  include/Switch/System/Windows/Forms/MessageBoxDefaultButton.hpp
  include/Switch/System/Windows/Forms/MessageBoxIcon.hpp
  include/Switch/System/Windows/Forms/MessageBoxOptions.hpp
  include/Switch/System/Windows/Forms/MethodInvoker.hpp
  include/Switch/System/Windows/Forms/MouseButtons.hpp
  include/Switch/System/Windows/Forms/MouseEventArgs.hpp
  include/Switch/System/Windows/Forms/MouseEventHandler.hpp
#  include/Switch/System/Windows/Forms/NumericUpDown.hpp
#  include/Switch/System/Windows/Forms/OpenFileDialog.hpp
  include/Switch/System/Windows/Forms/Orientation.hpp
  include/Switch/System/Windows/Forms/PaintEventArgs.hpp
  include/Switch/System/Windows/Forms/PaintEventHandler.hpp
  include/Switch/System/Windows/Forms/Panel.hpp
#  include/Switch/System/Windows/Forms/PictureBox.hpp
  include/Switch/System/Windows/Forms/ProgressBar.hpp
  include/Switch/System/Windows/Forms/ProgressBarStyle.hpp
  include/Switch/System/Windows/Forms/RadioButton.hpp
#  include/Switch/System/Windows/Forms/RichTextBox.hpp
#  include/Switch/System/Windows/Forms/SaveFileDialog.hpp
#  include/Switch/System/Windows/Forms/Screen.hpp
  include/Switch/System/Windows/Forms/ScrollableControl.hpp
  include/Switch/System/Windows/Forms/Shortcut.hpp
  include/Switch/System/Windows/Forms/SystemInformation.hpp
  include/Switch/System/Windows/Forms/TabAlignment.hpp
  include/Switch/System/Windows/Forms/TabControl.hpp
  include/Switch/System/Windows/Forms/TabPage.hpp
#  include/Switch/System/Windows/Forms/TextBox.hpp
  include/Switch/System/Windows/Forms/TickStyle.hpp
  include/Switch/System/Windows/Forms/Timer.hpp
  include/Switch/System/Windows/Forms/TrackBar.hpp
  include/Switch/System/Windows/Forms/UICues.hpp
  include/Switch/System/Windows/Forms/UICuesEventArgs.hpp
  include/Switch/System/Windows/Forms/UICuesEventHandler.hpp
  include/Switch/System.Windows.Forms.hpp
)

set(SOURCE_FILES
  src/__OS/ApplicationCocoa.mm
  src/__OS/ApplicationGtk.cpp
  src/__OS/ApplicationWin32.cpp
  src/__OS/ButtonCocoa.mm
  src/__OS/ButtonGtk.cpp
  src/__OS/ButtonWin32.cpp
  src/__OS/CheckBoxCocoa.mm
  src/__OS/CheckBoxGtk.cpp
  src/__OS/CheckBoxWin32.cpp
  src/__OS/ControlCocoa.mm
  src/__OS/ControlGtk.cpp
  src/__OS/ControlWin32.cpp
  src/__OS/FormCocoa.mm
  src/__OS/FormsApi.hpp
  src/__OS/FormGtk.cpp
  src/__OS/FormWin32.cpp
  src/__OS/GroupBoxCocoa.mm
  src/__OS/GroupBoxGtk.cpp
  src/__OS/GroupBoxWin32.cpp
  src/__OS/LabelCocoa.mm
  src/__OS/LabelGtk.cpp
  src/__OS/LabelWin32.cpp
  src/__OS/MainWin32.cpp
  src/__OS/PanelCocoa.mm
  src/__OS/PanelGtk.cpp
  src/__OS/PanelWin32.cpp
  src/__OS/ProgressBarCocoa.mm
  src/__OS/ProgressBarGtk.cpp
  src/__OS/ProgressBarWin32.cpp
  src/__OS/RadioButtonCocoa.mm
  src/__OS/RadioButtonGtk.cpp
  src/__OS/RadioButtonWin32.cpp
  src/__OS/SystemInformationCocoa.mm
  src/__OS/SystemInformationGtk.cpp
  src/__OS/SystemInformationWin32.cpp
  src/__OS/TabControlCocoa.mm
  src/__OS/TabControlGtk.cpp
  src/__OS/TabControlWin32.cpp
  src/__OS/TabPageCocoa.mm
  src/__OS/TabPageGtk.cpp
  src/__OS/TabPageWin32.cpp
  src/__OS/TimerCocoa.mm
  src/__OS/TimerGtk.cpp
  src/__OS/TimerWin32.cpp
  src/__OS/TrackBarCocoa.mm
  src/__OS/TrackBarGtk.cpp
  src/__OS/TrackBarWin32.cpp
  src/__OS/WidgetCocoa.hpp
  src/__OS/WidgetGtk.hpp
  src/__OS/WindowMessage.hpp
  src/__OS/WindowMessageKey.hpp
  src/__OS/WindowProcedureCocoa.mm
  src/__OS/WindowProcedureWin32.cpp
  src/__OS/WindowProcedureCocoa.hpp
  src/__OS/WindowProcedureWin32.hpp
  src/Switch/System/Media/SystemSound.cpp
  src/Switch/System/Media/SystemSounds.cpp
  src/Switch/System/Windows/Forms/Application.cpp
  src/Switch/System/Windows/Forms/Button.cpp
  src/Switch/System/Windows/Forms/CheckBox.cpp
#  src/Switch/System/Windows/Forms/CheckedListBox.cpp
  src/Switch/System/Windows/Forms/Control.cpp
#  src/Switch/System/Windows/Forms/Cursor.cpp
#  src/Switch/System/Windows/Forms/Cursors.cpp
#  src/Switch/System/Windows/Forms/Exclamation.hpp
#  src/Switch/System/Windows/Forms/FolderBrowserDialog.cpp
  src/Switch/System/Windows/Forms/Form.cpp
  src/Switch/System/Windows/Forms/GroupBox.cpp
#  src/Switch/System/Windows/Forms/ImageList.cpp
#  src/Switch/System/Windows/Forms/Information.hpp
  src/Switch/System/Windows/Forms/Label.cpp
#  src/Switch/System/Windows/Forms/ListBox.cpp
#  src/Switch/System/Windows/Forms/MainMenu.cpp
#  src/Switch/System/Windows/Forms/MaskedTextBox.cpp
#  src/Switch/System/Windows/Forms/Menu.cpp
#  src/Switch/System/Windows/Forms/MenuItem.cpp
  src/Switch/System/Windows/Forms/Message.cpp
  src/Switch/System/Windows/Forms/MessageBox.cpp
#  src/Switch/System/Windows/Forms/NumericUpDown.cpp
#  src/Switch/System/Windows/Forms/OpenFileDialog.cpp
  src/Switch/System/Windows/Forms/Panel.cpp
#  src/Switch/System/Windows/Forms/PictureBox.cpp
  src/Switch/System/Windows/Forms/ProgressBar.cpp
#  src/Switch/System/Windows/Forms/Question.hpp
  src/Switch/System/Windows/Forms/RadioButton.cpp
#  src/Switch/System/Windows/Forms/RichTextBox.cpp
#  src/Switch/System/Windows/Forms/SaveFileDialog.cpp
#  src/Switch/System/Windows/Forms/Screen.cpp
#  src/Switch/System/Windows/Forms/Stop.hpp
  src/Switch/System/Windows/Forms/SystemInformation.cpp
  src/Switch/System/Windows/Forms/TabControl.cpp
  src/Switch/System/Windows/Forms/TabPage.cpp
#  src/Switch/System/Windows/Forms/TextBox.cpp
  src/Switch/System/Windows/Forms/Timer.cpp
  src/Switch/System/Windows/Forms/TrackBar.cpp
)

source_group(src REGULAR_EXPRESSION "src/[-_,A-Za-z0-9]+\\.c*")
source_group(src\\__OS REGULAR_EXPRESSION "src/__OS/[-_,A-Za-z0-9]+\\.*")
source_group(src\\Switch REGULAR_EXPRESSION "src/Switch/[-_,A-Za-z0-9]+\\.c*")
source_group(src\\Switch\\System REGULAR_EXPRESSION "src/Switch/System/[-_,A-Za-z0-9]+\\.c*")
source_group(src\\Switch\\System\\ComponentModel REGULAR_EXPRESSION "src/Switch/System/ComponentModel/[-_,A-Za-z0-9]+\\.c*")
source_group(src\\Switch\\System\\Media REGULAR_EXPRESSION "src/Switch/System/Media/[-_,A-Za-z0-9]+\\.c*")
source_group(src\\Switch\\System\\Windows REGULAR_EXPRESSION "src/Switch/System/Windows/[-_,A-Za-z0-9]+\\.c*")
source_group(src\\Switch\\System\\Windows\\Forms REGULAR_EXPRESSION "src/Switch/System/Windows/Forms/[-_,A-Za-z0-9]+\\.(c*|h*|m*)")
source_group(src\\Switch\\System\\Windows\\Forms\\VisualStyles REGULAR_EXPRESSION "src/Switch/System/Windows/Forms/VisualStyles/[-_,A-Za-z0-9]+\\.c*")

source_group(include REGULAR_EXPRESSION "include/[-_,A-Za-z0-9]+\\.hpp*")
source_group(include\\Switch\\System REGULAR_EXPRESSION "include/Switch/System/[-_,A-Za-z0-9]+\\.hpp*")
source_group(include\\Switch\\System\\ComponentModel REGULAR_EXPRESSION "include/Switch/System/ComponentModel/[-_,A-Za-z0-9]+\\.hpp*")
source_group(include\\Switch\\System\\Media REGULAR_EXPRESSION "include/Switch/System/Media/[-_,A-Za-z0-9]+\\.hpp*")
source_group(include\\Switch\\System\\Windows REGULAR_EXPRESSION "include/Switch/System/Windows/[-_,A-Za-z0-9]+\\.hpp*")
source_group(include\\Switch\\System\\Windows\\Forms REGULAR_EXPRESSION "include/Switch/System/Windows/Forms/[-_,A-Za-z0-9]+\\.hpp*")
source_group(include\\Switch\\System\\Windows\\Forms\\VisualStyles REGULAR_EXPRESSION "include/Switch/System/Windows/Forms/VisualStyles/[-_,A-Za-z0-9]+\\.hpp*")
source_group(include\\Switch REGULAR_EXPRESSION "include/Switch/[-_,A-Za-z0-9]+\\.hpp*")
source_group(include\\Switch REGULAR_EXPRESSION "include/Switch/[-_,A-Za-z0-9]")

add_library(Switch.System.Windows.Forms STATIC ${INCLUDE_FILES} ${SOURCE_FILES})
target_include_directories(Switch.System.Windows.Forms PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>)
target_link_libraries(Switch.System.Windows.Forms Switch.System.Drawing)
set_target_properties(Switch.System.Windows.Forms PROPERTIES FOLDER src)

install(TARGETS Switch.System.Windows.Forms EXPORT Switch DESTINATION lib)
install(DIRECTORY "include/Switch/." DESTINATION include/Switch)
if(MSVC)
  target_compile_options(Switch.System.Windows.Forms PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:Switch.System.Windows.Forms>/Switch.System.Windows.Forms${CMAKE_DEBUG_POSTFIX}.pdb>")
  target_compile_options(Switch.System.Windows.Forms PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:Switch.System.Windows.Forms>/Switch.System.Windows.Forms::pdb>")
  install(FILES "$<TARGET_FILE_DIR:Switch.System.Windows.Forms>/Switch.System.Windows.Forms${CMAKE_DEBUG_POSTFIX}.pdb" DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
  install(FILES "$<TARGET_FILE_DIR:Switch.System.Windows.Forms>/Switch.System.Windows.Forms::pdb" DESTINATION lib CONFIGURATIONS Release OPTIONAL)
endif()
