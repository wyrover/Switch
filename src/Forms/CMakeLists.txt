set(INCLUDE_FILES
  Includes/Switch/System/ComponentModel/CancelEventArgs.hpp
  Includes/Switch/System/ComponentModel/CancelEventHandler.hpp
  Includes/Switch/System/ComponentModel/Component.hpp
  Includes/Switch/System/ComponentModel/ComponentCollection.hpp
  Includes/Switch/System/ComponentModel/EventHandlerList.hpp
  Includes/Switch/System/ComponentModel/IComponent.hpp
  Includes/Switch/System/ComponentModel/IContainer.hpp
  Includes/Switch/System/ComponentModel/ISite.hpp
  Includes/Switch/System/Media/SystemSound.hpp
  Includes/Switch/System/Media/SystemSounds.hpp
  Includes/Switch/System/Windows/Forms/VisualStyles/VisualStyleState.hpp
  Includes/Switch/System/Windows/Forms/AccessibleEvents.hpp
  Includes/Switch/System/Windows/Forms/AccessibleNavigation.hpp
  Includes/Switch/System/Windows/Forms/AccessibleRole.hpp
  Includes/Switch/System/Windows/Forms/AnchorStyles.hpp
  Includes/Switch/System/Windows/Forms/Application.hpp
  Includes/Switch/System/Windows/Forms/ArrangeDirection.hpp
  Includes/Switch/System/Windows/Forms/ArrangeStartingPosition.hpp
  Includes/Switch/System/Windows/Forms/AutoSizeMode.hpp
  Includes/Switch/System/Windows/Forms/BootMode.hpp
  Includes/Switch/System/Windows/Forms/BorderStyle.hpp
  Includes/Switch/System/Windows/Forms/Button.hpp
  Includes/Switch/System/Windows/Forms/ButtonBase.hpp
  Includes/Switch/System/Windows/Forms/CheckBox.hpp
#  Includes/Switch/System/Windows/Forms/CheckedListBox.hpp
  Includes/Switch/System/Windows/Forms/CheckState.hpp
  Includes/Switch/System/Windows/Forms/CloseReason.hpp
  Includes/Switch/System/Windows/Forms/ContainerControl.hpp
  Includes/Switch/System/Windows/Forms/Control.hpp
  Includes/Switch/System/Windows/Forms/ControlEventArgs.hpp
  Includes/Switch/System/Windows/Forms/ControlEventHandler.hpp
  Includes/Switch/System/Windows/Forms/ControlStyles.hpp
#  Includes/Switch/System/Windows/Forms/Cursor.hpp
#  Includes/Switch/System/Windows/Forms/Cursors.hpp
  Includes/Switch/System/Windows/Forms/DataFormats.hpp
  Includes/Switch/System/Windows/Forms/DialogResult.hpp
  Includes/Switch/System/Windows/Forms/DockStyle.hpp
  Includes/Switch/System/Windows/Forms/DragDropEffects.hpp
  Includes/Switch/System/Windows/Forms/DragEventArgs.hpp
  Includes/Switch/System/Windows/Forms/DragEventHandler.hpp
#  Includes/Switch/System/Windows/Forms/FolderBrowserDialog.hpp
  Includes/Switch/System/Windows/Forms/Form.hpp
  Includes/Switch/System/Windows/Forms/FormBorderStyle.hpp
  Includes/Switch/System/Windows/Forms/FormClosedEventArgs.hpp
  Includes/Switch/System/Windows/Forms/FormClosedEventHandler.hpp
  Includes/Switch/System/Windows/Forms/FormClosingEventArgs.hpp
  Includes/Switch/System/Windows/Forms/FormClosingEventHandler.hpp
  Includes/Switch/System/Windows/Forms/FormStartPosition.hpp
  Includes/Switch/System/Windows/Forms/GiveFeedbackEventArgs.hpp
  Includes/Switch/System/Windows/Forms/GiveFeedbackEventHandler.hpp
  Includes/Switch/System/Windows/Forms/GroupBox.hpp
  Includes/Switch/System/Windows/Forms/HelpEventArgs.hpp
  Includes/Switch/System/Windows/Forms/HelpEventHandler.hpp
  Includes/Switch/System/Windows/Forms/IDataObject.hpp
#  Includes/Switch/System/Windows/Forms/ImageList.hpp
  Includes/Switch/System/Windows/Forms/ImageLayout.hpp
  Includes/Switch/System/Windows/Forms/InvalidateEventArgs.hpp
  Includes/Switch/System/Windows/Forms/InvalidateEventHandler.hpp
  Includes/Switch/System/Windows/Forms/KeyEventArgs.hpp
  Includes/Switch/System/Windows/Forms/KeyEventHandler.hpp
  Includes/Switch/System/Windows/Forms/KeyPressEventArgs.hpp
  Includes/Switch/System/Windows/Forms/KeyPressEventHandler.hpp
  Includes/Switch/System/Windows/Forms/Keys.hpp
  Includes/Switch/System/Windows/Forms/Label.hpp
#  Includes/Switch/System/Windows/Forms/ListBox.hpp
  Includes/Switch/System/Windows/Forms/ListControl.hpp
#  Includes/Switch/System/Windows/Forms/MainMenu.hpp
#  Includes/Switch/System/Windows/Forms/MaskedTextBox.hpp
#  Includes/Switch/System/Windows/Forms/Menu.hpp
#  Includes/Switch/System/Windows/Forms/MenuItem.hpp
  Includes/Switch/System/Windows/Forms/Message.hpp
  Includes/Switch/System/Windows/Forms/MessageBox.hpp
  Includes/Switch/System/Windows/Forms/MessageBoxButtons.hpp
  Includes/Switch/System/Windows/Forms/MessageBoxDefaultButton.hpp
  Includes/Switch/System/Windows/Forms/MessageBoxIcon.hpp
  Includes/Switch/System/Windows/Forms/MessageBoxOptions.hpp
  Includes/Switch/System/Windows/Forms/MethodInvoker.hpp
  Includes/Switch/System/Windows/Forms/MouseButtons.hpp
  Includes/Switch/System/Windows/Forms/MouseEventArgs.hpp
  Includes/Switch/System/Windows/Forms/MouseEventHandler.hpp
#  Includes/Switch/System/Windows/Forms/NumericUpDown.hpp
#  Includes/Switch/System/Windows/Forms/OpenFileDialog.hpp
  Includes/Switch/System/Windows/Forms/Orientation.hpp
  Includes/Switch/System/Windows/Forms/PaintEventArgs.hpp
  Includes/Switch/System/Windows/Forms/PaintEventHandler.hpp
  Includes/Switch/System/Windows/Forms/Panel.hpp
#  Includes/Switch/System/Windows/Forms/PictureBox.hpp
  Includes/Switch/System/Windows/Forms/ProgressBar.hpp
  Includes/Switch/System/Windows/Forms/ProgressBarStyle.hpp
  Includes/Switch/System/Windows/Forms/RadioButton.hpp
#  Includes/Switch/System/Windows/Forms/RichTextBox.hpp
#  Includes/Switch/System/Windows/Forms/SaveFileDialog.hpp
#  Includes/Switch/System/Windows/Forms/Screen.hpp
  Includes/Switch/System/Windows/Forms/ScrollableControl.hpp
  Includes/Switch/System/Windows/Forms/Shortcut.hpp
  Includes/Switch/System/Windows/Forms/SystemInformation.hpp
  Includes/Switch/System/Windows/Forms/TabAlignment.hpp
  Includes/Switch/System/Windows/Forms/TabControl.hpp
  Includes/Switch/System/Windows/Forms/TabPage.hpp
#  Includes/Switch/System/Windows/Forms/TextBox.hpp
  Includes/Switch/System/Windows/Forms/TickStyle.hpp
  Includes/Switch/System/Windows/Forms/Timer.hpp
  Includes/Switch/System/Windows/Forms/TrackBar.hpp
  Includes/Switch/System/Windows/Forms/UICues.hpp
  Includes/Switch/System/Windows/Forms/UICuesEventArgs.hpp
  Includes/Switch/System/Windows/Forms/UICuesEventHandler.hpp
  Includes/Switch/Forms.hpp
)

set(SOURCE_FILES
  Sources/__OS/ApplicationCocoa.mm
  Sources/__OS/ApplicationGtk.cpp
  Sources/__OS/ApplicationWin32.cpp
  Sources/__OS/ButtonCocoa.mm
  Sources/__OS/ButtonGtk.cpp
  Sources/__OS/ButtonWin32.cpp
  Sources/__OS/CheckBoxCocoa.mm
  Sources/__OS/CheckBoxGtk.cpp
  Sources/__OS/CheckBoxWin32.cpp
  Sources/__OS/ControlCocoa.mm
  Sources/__OS/ControlGtk.cpp
  Sources/__OS/ControlWin32.cpp
  Sources/__OS/FormCocoa.mm
  Sources/__OS/FormsApi.hpp
  Sources/__OS/FormGtk.cpp
  Sources/__OS/FormWin32.cpp
  Sources/__OS/GroupBoxCocoa.mm
  Sources/__OS/GroupBoxGtk.cpp
  Sources/__OS/GroupBoxWin32.cpp
  Sources/__OS/LabelCocoa.mm
  Sources/__OS/LabelGtk.cpp
  Sources/__OS/LabelWin32.cpp
  Sources/__OS/MainWin32.cpp
  Sources/__OS/PanelCocoa.mm
  Sources/__OS/PanelGtk.cpp
  Sources/__OS/PanelWin32.cpp
  Sources/__OS/ProgressBarCocoa.mm
  Sources/__OS/ProgressBarGtk.cpp
  Sources/__OS/ProgressBarWin32.cpp
  Sources/__OS/RadioButtonCocoa.mm
  Sources/__OS/RadioButtonGtk.cpp
  Sources/__OS/RadioButtonWin32.cpp
  Sources/__OS/SystemInformationCocoa.mm
  Sources/__OS/SystemInformationGtk.cpp
  Sources/__OS/SystemInformationWin32.cpp
  Sources/__OS/TabControlCocoa.mm
  Sources/__OS/TabControlGtk.cpp
  Sources/__OS/TabControlWin32.cpp
  Sources/__OS/TabPageCocoa.mm
  Sources/__OS/TabPageGtk.cpp
  Sources/__OS/TabPageWin32.cpp
  Sources/__OS/TimerCocoa.mm
  Sources/__OS/TimerGtk.cpp
  Sources/__OS/TimerWin32.cpp
  Sources/__OS/TrackBarCocoa.mm
  Sources/__OS/TrackBarGtk.cpp
  Sources/__OS/TrackBarWin32.cpp
  Sources/__OS/WidgetCocoa.hpp
  Sources/__OS/WidgetGtk.hpp
  Sources/__OS/WindowMessage.hpp
  Sources/__OS/WindowMessageKey.hpp
  Sources/__OS/WindowProcedureCocoa.mm
  Sources/__OS/WindowProcedureWin32.cpp
  Sources/__OS/WindowProcedureCocoa.hpp
  Sources/__OS/WindowProcedureWin32.hpp
  Sources/Switch/System/Media/SystemSound.cpp
  Sources/Switch/System/Media/SystemSounds.cpp
  Sources/Switch/System/Windows/Forms/Application.cpp
  Sources/Switch/System/Windows/Forms/Button.cpp
  Sources/Switch/System/Windows/Forms/CheckBox.cpp
#  Sources/Switch/System/Windows/Forms/CheckedListBox.cpp
  Sources/Switch/System/Windows/Forms/Control.cpp
#  Sources/Switch/System/Windows/Forms/Cursor.cpp
#  Sources/Switch/System/Windows/Forms/Cursors.cpp
#  Sources/Switch/System/Windows/Forms/Exclamation.hpp
#  Sources/Switch/System/Windows/Forms/FolderBrowserDialog.cpp
  Sources/Switch/System/Windows/Forms/Form.cpp
  Sources/Switch/System/Windows/Forms/GroupBox.cpp
#  Sources/Switch/System/Windows/Forms/ImageList.cpp
#  Sources/Switch/System/Windows/Forms/Information.hpp
  Sources/Switch/System/Windows/Forms/Label.cpp
#  Sources/Switch/System/Windows/Forms/ListBox.cpp
#  Sources/Switch/System/Windows/Forms/MainMenu.cpp
#  Sources/Switch/System/Windows/Forms/MaskedTextBox.cpp
#  Sources/Switch/System/Windows/Forms/Menu.cpp
#  Sources/Switch/System/Windows/Forms/MenuItem.cpp
  Sources/Switch/System/Windows/Forms/Message.cpp
  Sources/Switch/System/Windows/Forms/MessageBox.cpp
#  Sources/Switch/System/Windows/Forms/NumericUpDown.cpp
#  Sources/Switch/System/Windows/Forms/OpenFileDialog.cpp
  Sources/Switch/System/Windows/Forms/Panel.cpp
#  Sources/Switch/System/Windows/Forms/PictureBox.cpp
  Sources/Switch/System/Windows/Forms/ProgressBar.cpp
#  Sources/Switch/System/Windows/Forms/Question.hpp
  Sources/Switch/System/Windows/Forms/RadioButton.cpp
#  Sources/Switch/System/Windows/Forms/RichTextBox.cpp
#  Sources/Switch/System/Windows/Forms/SaveFileDialog.cpp
#  Sources/Switch/System/Windows/Forms/Screen.cpp
#  Sources/Switch/System/Windows/Forms/Stop.hpp
  Sources/Switch/System/Windows/Forms/SystemInformation.cpp
  Sources/Switch/System/Windows/Forms/TabControl.cpp
  Sources/Switch/System/Windows/Forms/TabPage.cpp
#  Sources/Switch/System/Windows/Forms/TextBox.cpp
  Sources/Switch/System/Windows/Forms/Timer.cpp
  Sources/Switch/System/Windows/Forms/TrackBar.cpp
)

source_group(Includes REGULAR_EXPRESSION "/Includes/[-_,A-Za-z0-9]+\\.hpp*")
source_group(Includes\\Switch\\System REGULAR_EXPRESSION "/Includes/Switch/System/[-_,A-Za-z0-9]+\\.hpp*")
source_group(Includes\\Switch\\System\\ComponentModel REGULAR_EXPRESSION "/Includes/Switch/System/ComponentModel/[-_,A-Za-z0-9]+\\.hpp*")
source_group(Includes\\Switch\\System\\Media REGULAR_EXPRESSION "/Includes/Switch/System/Media/[-_,A-Za-z0-9]+\\.hpp*")
source_group(Includes\\Switch\\System\\Windows REGULAR_EXPRESSION "/Includes/Switch/System/Windows/[-_,A-Za-z0-9]+\\.hpp*")
source_group(Includes\\Switch\\System\\Windows\\Forms REGULAR_EXPRESSION "/Includes/Switch/System/Windows/Forms/[-_,A-Za-z0-9]+\\.hpp*")
source_group(Includes\\Switch\\System\\Windows\\Forms\\VisualStyles REGULAR_EXPRESSION "/Includes/Switch/System/Windows/Forms/VisualStyles/[-_,A-Za-z0-9]+\\.hpp*")
source_group(Includes\\Switch REGULAR_EXPRESSION "/Includes/Switch/[-_,A-Za-z0-9]+\\.hpp*")
source_group(Includes\\Switch REGULAR_EXPRESSION "/Includes/Switch/[-_,A-Za-z0-9]")

source_group(Sources REGULAR_EXPRESSION "/Sources/[-_,A-Za-z0-9]+\\.c*")
source_group(Sources\\__OS REGULAR_EXPRESSION "/Sources/__OS/[-_,A-Za-z0-9]+\\.*")
source_group(Sources\\Switch REGULAR_EXPRESSION "/Sources/Switch/[-_,A-Za-z0-9]+\\.c*")
source_group(Sources\\Switch\\System REGULAR_EXPRESSION "/Sources/Switch/System/[-_,A-Za-z0-9]+\\.c*")
source_group(Sources\\Switch\\System\\ComponentModel REGULAR_EXPRESSION "/Sources/Switch/System/ComponentModel/[-_,A-Za-z0-9]+\\.c*")
source_group(Sources\\Switch\\System\\Media REGULAR_EXPRESSION "/Sources/Switch/System/Media/[-_,A-Za-z0-9]+\\.c*")
source_group(Sources\\Switch\\System\\Windows REGULAR_EXPRESSION "/Sources/Switch/System/Windows/[-_,A-Za-z0-9]+\\.c*")
source_group(Sources\\Switch\\System\\Windows\\Forms REGULAR_EXPRESSION "/Sources/Switch/System/Windows/Forms/[-_,A-Za-z0-9]+\\.(c*|h*|m*)")
source_group(Sources\\Switch\\System\\Windows\\Forms\\VisualStyles REGULAR_EXPRESSION "/Sources/Switch/System/Windows/Forms/VisualStyles/[-_,A-Za-z0-9]+\\.c*")

add_library(Switch.Forms STATIC ${INCLUDE_FILES} ${SOURCE_FILES})
target_include_directories(Switch.Forms PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Includes> $<INSTALL_INTERFACE:include>)
target_link_libraries(Switch.Forms Switch.Drawing)
set_target_properties(Switch.Forms PROPERTIES FOLDER src/Forms)

if (BUILD_TESTS)
  add_subdirectory("ManualTests")
  add_subdirectory("UnitTests")
endif()

install(TARGETS Switch.Forms EXPORT Switch DESTINATION lib)
install(DIRECTORY "Includes/Switch/." DESTINATION include/Switch)
if(MSVC)
  target_compile_options(Switch.Forms PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:Switch.Forms>/Switch.Forms${CMAKE_DEBUG_POSTFIX}.pdb>")
  target_compile_options(Switch.Forms PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:Switch.Forms>/Switch.Forms::pdb>")
  install(FILES "$<TARGET_FILE_DIR:Switch.Forms>/Switch.Forms${CMAKE_DEBUG_POSTFIX}.pdb" DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
  install(FILES "$<TARGET_FILE_DIR:Switch.Forms>/Switch.Forms::pdb" DESTINATION lib CONFIGURATIONS Release OPTIONAL)
endif()
