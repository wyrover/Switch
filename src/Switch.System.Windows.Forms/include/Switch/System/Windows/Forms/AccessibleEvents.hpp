/// @file
/// @brief Contains Switch::System::Windows::Forms::AccessibleEvents enum.
#pragma once

#include <Switch/System/Enum.hpp>

namespace Switch {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @brief Enumeration.
        /// Specifie the AccessibleEvents values
        enum class AccessibleEvents {
          SystemSound = 1,
          SystemAlert = 2,
          SystemForeground = 3,
          SystemMenuStart = 4,
          SystemMenuEnd = 5,
          SystemMenuPopupStart = 6,
          SystemMenuPopupEnd = 7,
          SystemCaptureStart = 8,
          SystemCaptureEnd = 9,
          SystemMoveSizeStart = 10,
          SystemMoveSizeEnd = 11,
          SystemContextHelpStart = 12,
          SystemContextHelpEnd = 13,
          SystemDragDropStart = 14,
          SystemDragDropEnd = 15,
          SystemDialogStart = 16,
          SystemDialogEnd = 17,
          SystemScrollingStart = 18,
          SystemScrollingEnd = 19,
          SystemSwitchStart = 20,
          SystemSwitchEnd = 21,
          SystemMinimizeStart = 22,
          SystemMinimizeEnd = 23,
          Create = 32768,
          Destroy = 32769,
          Show = 32770,
          Hide = 32771,
          Reorder = 32772,
          Focus = 32773,
          Selection = 32774,
          SelectionAdd = 32775,
          SelectionRemove = 32776,
          SelectionWithin = 32777,
          StateChange = 32778,
          LocationChange = 32779,
          NameChange = 32780,
          DescriptionChange = 32781,
          ValueChange = 32782,
          ParentChange = 32783,
          HelpChange = 32784,
          DefaultActionChange = 32785,
          AcceleratorChange = 32786,
        };
      }
    }
  }
}

/// @cond
template<>
class EnumToStrings<System::Windows::Forms::AccessibleEvents> {
public:
  void operator ()(System::Collections::Generic::Dictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::Windows::Forms::AccessibleEvents::SystemSound, "SystemSound"}, {(int64)System::Windows::Forms::AccessibleEvents::SystemAlert, "SystemAlert"}, {(int64)System::Windows::Forms::AccessibleEvents::SystemForeground, "SystemForeground"}, {(int64)System::Windows::Forms::AccessibleEvents::SystemMenuStart, "SystemMenuStart"}, {(int64)System::Windows::Forms::AccessibleEvents::SystemMenuEnd, "SystemMenuEnd"}, {(int64)System::Windows::Forms::AccessibleEvents::SystemMenuPopupStart, "SystemMenuPopupStart"}, {(int64)System::Windows::Forms::AccessibleEvents::SystemMenuPopupEnd, "SystemMenuPopupEnd"}, {(int64)System::Windows::Forms::AccessibleEvents::SystemCaptureStart, "SystemCaptureStart"}, {(int64)System::Windows::Forms::AccessibleEvents::SystemCaptureEnd, "SystemCaptureEnd"}, {(int64)System::Windows::Forms::AccessibleEvents::SystemMoveSizeStart, "SystemMoveSizeStart"}, {(int64)System::Windows::Forms::AccessibleEvents::SystemMoveSizeEnd, "SystemMoveSizeEnd"}, {(int64)System::Windows::Forms::AccessibleEvents::SystemContextHelpStart, "SystemContextHelpStart"}, {(int64)System::Windows::Forms::AccessibleEvents::SystemContextHelpEnd, "SystemContextHelpEnd"}, {(int64)System::Windows::Forms::AccessibleEvents::SystemDragDropStart, "SystemDragDropStart"}, {(int64)System::Windows::Forms::AccessibleEvents::SystemDragDropEnd, "SystemDragDropEnd"}, {(int64)System::Windows::Forms::AccessibleEvents::SystemDialogStart, "SystemDialogStart"}, {(int64)System::Windows::Forms::AccessibleEvents::SystemDialogEnd, "SystemDialogEnd"}, {(int64)System::Windows::Forms::AccessibleEvents::SystemScrollingStart, "SystemScrollingStart"}, {(int64)System::Windows::Forms::AccessibleEvents::SystemScrollingEnd, "SystemScrollingEnd"}, {(int64)System::Windows::Forms::AccessibleEvents::SystemSwitchStart, "SystemSwitchStart"}, {(int64)System::Windows::Forms::AccessibleEvents::SystemSwitchEnd, "SystemSwitchEnd"}, {(int64)System::Windows::Forms::AccessibleEvents::SystemMinimizeStart, "SystemMinimizeStart"}, {(int64)System::Windows::Forms::AccessibleEvents::SystemMinimizeEnd, "SystemMinimizeEnd"}, {(int64)System::Windows::Forms::AccessibleEvents::Create, "Create"}, {(int64)System::Windows::Forms::AccessibleEvents::Destroy, "Destroy"}, {(int64)System::Windows::Forms::AccessibleEvents::Show, "Show"}, {(int64)System::Windows::Forms::AccessibleEvents::Hide, "Hide"}, {(int64)System::Windows::Forms::AccessibleEvents::Reorder, "Reorder"}, {(int64)System::Windows::Forms::AccessibleEvents::Focus, "Focus"}, {(int64)System::Windows::Forms::AccessibleEvents::Selection, "Selection"}, {(int64)System::Windows::Forms::AccessibleEvents::SelectionAdd, "SelectionAdd"}, {(int64)System::Windows::Forms::AccessibleEvents::SelectionRemove, "SelectionRemove"}, {(int64)System::Windows::Forms::AccessibleEvents::SelectionWithin, "SelectionWithin"}, {(int64)System::Windows::Forms::AccessibleEvents::StateChange, "StateChange"}, {(int64)System::Windows::Forms::AccessibleEvents::LocationChange, "LocationChange"}, {(int64)System::Windows::Forms::AccessibleEvents::NameChange, "NameChange"}, {(int64)System::Windows::Forms::AccessibleEvents::DescriptionChange, "DescriptionChange"}, {(int64)System::Windows::Forms::AccessibleEvents::ValueChange, "ValueChange"}, {(int64)System::Windows::Forms::AccessibleEvents::ParentChange, "ParentChange"}, {(int64)System::Windows::Forms::AccessibleEvents::HelpChange, "HelpChange"}, {(int64)System::Windows::Forms::AccessibleEvents::DefaultActionChange, "DefaultActionChange"}, {(int64)System::Windows::Forms::AccessibleEvents::AcceleratorChange, "AcceleratorChange"}};
    flags = false;
  }
};
/// @endcond

using namespace Switch;
