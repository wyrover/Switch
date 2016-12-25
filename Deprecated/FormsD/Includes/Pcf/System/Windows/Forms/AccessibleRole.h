/// @file
/// @brief Contains Pcf::System::Windows::Forms::AccessibleRole enum.
#pragma once

#include <Pcf/System/Enum.h>

namespace Pcf {
  namespace System {
    namespace Windows {
      namespace FormsD {
        /// @brief Specifie the AccessibleNavigation values
        enum class AccessibleRole {
          None,
          TitleBar,
          MenuBar,
          ScrollBar,
          Grip,
          Sound,
          Cursor,
          Caret,
          Alert,
          Window,
          Client,
          MenuPopup,
          MenuItem,
          ToolTip,
          Application,
          Document,
          Pane,
          Chart,
          Dialog,
          Border,
          Grouping,
          Separator,
          ToolBar,
          StatusBar,
          Table,
          ColumnHeader,
          RowHeader,
          Column,
          Row,
          Cell,
          Link,
          HelpBalloon,
          Character,
          List,
          ListItem,
          Outline,
          OutlineItem,
          PageTab,
          PropertyPage,
          Indicator,
          Graphic,
          StaticText,
          Text,
          PushButton,
          CheckButton,
          RadioButton,
          ComboBox,
          DropList,
          ProgressBar,
          Dial,
          HotkeyField,
          Slider,
          SpinButton,
          Diagram,
          Animation,
          Equation,
          ButtonDropDown,
          ButtonMenu,
          ButtonDropDownGrid,
          WhiteSpace,
          PageTabList,
          Clock,
          Default = -1,
          SplitButton = 62,
          IpAddress,
          OutlineButton
        };
      }
    }
  }
}

/// @cond
template<>
class EnumToStrings<System::Windows::FormsD::AccessibleRole> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::Windows::FormsD::AccessibleRole::None, "None"}, {(int64)System::Windows::FormsD::AccessibleRole::TitleBar, "TitleBar"}, {(int64)System::Windows::FormsD::AccessibleRole::MenuBar, "MenuBar"}, {(int64)System::Windows::FormsD::AccessibleRole::ScrollBar, "ScrollBar"}, {(int64)System::Windows::FormsD::AccessibleRole::Grip, "Grip"}, {(int64)System::Windows::FormsD::AccessibleRole::Sound, "Sound"}, {(int64)System::Windows::FormsD::AccessibleRole::Cursor, "Cursor"}, {(int64)System::Windows::FormsD::AccessibleRole::Caret, "Caret"}, {(int64)System::Windows::FormsD::AccessibleRole::Alert, "Alert"}, {(int64)System::Windows::FormsD::AccessibleRole::Window, "Window"}, {(int64)System::Windows::FormsD::AccessibleRole::Client, "Client"}, {(int64)System::Windows::FormsD::AccessibleRole::MenuPopup, "MenuPopup"}, {(int64)System::Windows::FormsD::AccessibleRole::MenuItem, "MenuItem"}, {(int64)System::Windows::FormsD::AccessibleRole::ToolTip, "ToolTip"}, {(int64)System::Windows::FormsD::AccessibleRole::Application, "Application"}, {(int64)System::Windows::FormsD::AccessibleRole::Document, "Document"}, {(int64)System::Windows::FormsD::AccessibleRole::Pane, "Pane"}, {(int64)System::Windows::FormsD::AccessibleRole::Chart, "Chart"}, {(int64)System::Windows::FormsD::AccessibleRole::Dialog, "Dialog"}, {(int64)System::Windows::FormsD::AccessibleRole::Border, "Border"}, {(int64)System::Windows::FormsD::AccessibleRole::Grouping, "Grouping"}, {(int64)System::Windows::FormsD::AccessibleRole::Separator, "Separator"}, {(int64)System::Windows::FormsD::AccessibleRole::ToolBar, "ToolBar"}, {(int64)System::Windows::FormsD::AccessibleRole::StatusBar, "StatusBar"}, {(int64)System::Windows::FormsD::AccessibleRole::Table, "Table"}, {(int64)System::Windows::FormsD::AccessibleRole::ColumnHeader, "ColumnHeader"}, {(int64)System::Windows::FormsD::AccessibleRole::RowHeader, "RowHeader"}, {(int64)System::Windows::FormsD::AccessibleRole::Column, "Column"}, {(int64)System::Windows::FormsD::AccessibleRole::Row, "Row"}, {(int64)System::Windows::FormsD::AccessibleRole::Cell, "Cell"}, {(int64)System::Windows::FormsD::AccessibleRole::Link, "Link"}, {(int64)System::Windows::FormsD::AccessibleRole::HelpBalloon, "HelpBalloon"}, {(int64)System::Windows::FormsD::AccessibleRole::Character, "Character"}, {(int64)System::Windows::FormsD::AccessibleRole::List, "List"}, {(int64)System::Windows::FormsD::AccessibleRole::ListItem, "ListItem"}, {(int64)System::Windows::FormsD::AccessibleRole::Outline, "Outline"}, {(int64)System::Windows::FormsD::AccessibleRole::OutlineItem, "OutlineItem"}, {(int64)System::Windows::FormsD::AccessibleRole::PageTab, "PageTab"}, {(int64)System::Windows::FormsD::AccessibleRole::PropertyPage, "PropertyPage"}, {(int64)System::Windows::FormsD::AccessibleRole::Indicator, "Indicator"}, {(int64)System::Windows::FormsD::AccessibleRole::Graphic, "Graphic"}, {(int64)System::Windows::FormsD::AccessibleRole::StaticText, "StaticText"}, {(int64)System::Windows::FormsD::AccessibleRole::PushButton, "PushButton"}, {(int64)System::Windows::FormsD::AccessibleRole::CheckButton, "CheckButton"}, {(int64)System::Windows::FormsD::AccessibleRole::RadioButton, "RadioButton"}, {(int64)System::Windows::FormsD::AccessibleRole::ComboBox, "ComboBox"}, {(int64)System::Windows::FormsD::AccessibleRole::DropList, "DropList"}, {(int64)System::Windows::FormsD::AccessibleRole::ProgressBar, "ProgressBar"}, {(int64)System::Windows::FormsD::AccessibleRole::Dial, "Dial"}, {(int64)System::Windows::FormsD::AccessibleRole::HotkeyField, "HotkeyField"}, {(int64)System::Windows::FormsD::AccessibleRole::Slider, "Slider"}, {(int64)System::Windows::FormsD::AccessibleRole::SpinButton, "SpinButton"}, {(int64)System::Windows::FormsD::AccessibleRole::Diagram, "Diagram"}, {(int64)System::Windows::FormsD::AccessibleRole::Animation, "Animation"}, {(int64)System::Windows::FormsD::AccessibleRole::Equation, "Equation"}, {(int64)System::Windows::FormsD::AccessibleRole::ButtonDropDown, "ButtonDropDown"}, {(int64)System::Windows::FormsD::AccessibleRole::ButtonMenu, "ButtonMenu"}, {(int64)System::Windows::FormsD::AccessibleRole::ButtonDropDownGrid, "ButtonDropDownGrid"}, {(int64)System::Windows::FormsD::AccessibleRole::WhiteSpace, "WhiteSpace"}, {(int64)System::Windows::FormsD::AccessibleRole::PageTabList, "PageTabList"}, {(int64)System::Windows::FormsD::AccessibleRole::Clock, "Clock"}, {(int64)System::Windows::FormsD::AccessibleRole::Default, "Default"}, {(int64)System::Windows::FormsD::AccessibleRole::SplitButton, "SplitButton"}, {(int64)System::Windows::FormsD::AccessibleRole::IpAddress, "IpAddress"}, {(int64)System::Windows::FormsD::AccessibleRole::OutlineButton, "OutlineButton"}};
    flags = false;
  }
};
/// @endcond

using namespace Pcf;
