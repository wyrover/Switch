/// @file
/// @brief Contains Pcf::System::Windows::Forms::AccessibleRole enum.
#pragma once

#include <Pcf/System/Enum.h>

namespace Pcf {
  namespace System {
    namespace Windows {
      namespace Forms {
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
class EnumToStrings<System::Windows::Forms::AccessibleRole> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::Windows::Forms::AccessibleRole::None, "None"}, {(int64)System::Windows::Forms::AccessibleRole::TitleBar, "TitleBar"}, {(int64)System::Windows::Forms::AccessibleRole::MenuBar, "MenuBar"}, {(int64)System::Windows::Forms::AccessibleRole::ScrollBar, "ScrollBar"}, {(int64)System::Windows::Forms::AccessibleRole::Grip, "Grip"}, {(int64)System::Windows::Forms::AccessibleRole::Sound, "Sound"}, {(int64)System::Windows::Forms::AccessibleRole::Cursor, "Cursor"}, {(int64)System::Windows::Forms::AccessibleRole::Caret, "Caret"}, {(int64)System::Windows::Forms::AccessibleRole::Alert, "Alert"}, {(int64)System::Windows::Forms::AccessibleRole::Window, "Window"}, {(int64)System::Windows::Forms::AccessibleRole::Client, "Client"}, {(int64)System::Windows::Forms::AccessibleRole::MenuPopup, "MenuPopup"}, {(int64)System::Windows::Forms::AccessibleRole::MenuItem, "MenuItem"}, {(int64)System::Windows::Forms::AccessibleRole::ToolTip, "ToolTip"}, {(int64)System::Windows::Forms::AccessibleRole::Application, "Application"}, {(int64)System::Windows::Forms::AccessibleRole::Document, "Document"}, {(int64)System::Windows::Forms::AccessibleRole::Pane, "Pane"}, {(int64)System::Windows::Forms::AccessibleRole::Chart, "Chart"}, {(int64)System::Windows::Forms::AccessibleRole::Dialog, "Dialog"}, {(int64)System::Windows::Forms::AccessibleRole::Border, "Border"}, {(int64)System::Windows::Forms::AccessibleRole::Grouping, "Grouping"}, {(int64)System::Windows::Forms::AccessibleRole::Separator, "Separator"}, {(int64)System::Windows::Forms::AccessibleRole::ToolBar, "ToolBar"}, {(int64)System::Windows::Forms::AccessibleRole::StatusBar, "StatusBar"}, {(int64)System::Windows::Forms::AccessibleRole::Table, "Table"}, {(int64)System::Windows::Forms::AccessibleRole::ColumnHeader, "ColumnHeader"}, {(int64)System::Windows::Forms::AccessibleRole::RowHeader, "RowHeader"}, {(int64)System::Windows::Forms::AccessibleRole::Column, "Column"}, {(int64)System::Windows::Forms::AccessibleRole::Row, "Row"}, {(int64)System::Windows::Forms::AccessibleRole::Cell, "Cell"}, {(int64)System::Windows::Forms::AccessibleRole::Link, "Link"}, {(int64)System::Windows::Forms::AccessibleRole::HelpBalloon, "HelpBalloon"}, {(int64)System::Windows::Forms::AccessibleRole::Character, "Character"}, {(int64)System::Windows::Forms::AccessibleRole::List, "List"}, {(int64)System::Windows::Forms::AccessibleRole::ListItem, "ListItem"}, {(int64)System::Windows::Forms::AccessibleRole::Outline, "Outline"}, {(int64)System::Windows::Forms::AccessibleRole::OutlineItem, "OutlineItem"}, {(int64)System::Windows::Forms::AccessibleRole::PageTab, "PageTab"}, {(int64)System::Windows::Forms::AccessibleRole::PropertyPage, "PropertyPage"}, {(int64)System::Windows::Forms::AccessibleRole::Indicator, "Indicator"}, {(int64)System::Windows::Forms::AccessibleRole::Graphic, "Graphic"}, {(int64)System::Windows::Forms::AccessibleRole::StaticText, "StaticText"}, {(int64)System::Windows::Forms::AccessibleRole::PushButton, "PushButton"}, {(int64)System::Windows::Forms::AccessibleRole::CheckButton, "CheckButton"}, {(int64)System::Windows::Forms::AccessibleRole::RadioButton, "RadioButton"}, {(int64)System::Windows::Forms::AccessibleRole::ComboBox, "ComboBox"}, {(int64)System::Windows::Forms::AccessibleRole::DropList, "DropList"}, {(int64)System::Windows::Forms::AccessibleRole::ProgressBar, "ProgressBar"}, {(int64)System::Windows::Forms::AccessibleRole::Dial, "Dial"}, {(int64)System::Windows::Forms::AccessibleRole::HotkeyField, "HotkeyField"}, {(int64)System::Windows::Forms::AccessibleRole::Slider, "Slider"}, {(int64)System::Windows::Forms::AccessibleRole::SpinButton, "SpinButton"}, {(int64)System::Windows::Forms::AccessibleRole::Diagram, "Diagram"}, {(int64)System::Windows::Forms::AccessibleRole::Animation, "Animation"}, {(int64)System::Windows::Forms::AccessibleRole::Equation, "Equation"}, {(int64)System::Windows::Forms::AccessibleRole::ButtonDropDown, "ButtonDropDown"}, {(int64)System::Windows::Forms::AccessibleRole::ButtonMenu, "ButtonMenu"}, {(int64)System::Windows::Forms::AccessibleRole::ButtonDropDownGrid, "ButtonDropDownGrid"}, {(int64)System::Windows::Forms::AccessibleRole::WhiteSpace, "WhiteSpace"}, {(int64)System::Windows::Forms::AccessibleRole::PageTabList, "PageTabList"}, {(int64)System::Windows::Forms::AccessibleRole::Clock, "Clock"}, {(int64)System::Windows::Forms::AccessibleRole::Default, "Default"}, {(int64)System::Windows::Forms::AccessibleRole::SplitButton, "SplitButton"}, {(int64)System::Windows::Forms::AccessibleRole::IpAddress, "IpAddress"}, {(int64)System::Windows::Forms::AccessibleRole::OutlineButton, "OutlineButton"}};
    flags = false;
  }
};
/// @endcond

using namespace Pcf;
