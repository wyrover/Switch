/// @file
/// @brief Contains Pcf::System::Windows::Forms::AccessibleEvents enum.
#pragma once

#include <Pcf/System/Enum.h>

namespace Pcf {
  namespace System {
    namespace Windows {
      namespace FormsD {
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
class EnumToStrings<System::Windows::FormsD::AccessibleEvents> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::Windows::FormsD::AccessibleEvents::SystemSound, "SystemSound"}, {(int64)System::Windows::FormsD::AccessibleEvents::SystemAlert, "SystemAlert"}, {(int64)System::Windows::FormsD::AccessibleEvents::SystemForeground, "SystemForeground"}, {(int64)System::Windows::FormsD::AccessibleEvents::SystemMenuStart, "SystemMenuStart"}, {(int64)System::Windows::FormsD::AccessibleEvents::SystemMenuEnd, "SystemMenuEnd"}, {(int64)System::Windows::FormsD::AccessibleEvents::SystemMenuPopupStart, "SystemMenuPopupStart"}, {(int64)System::Windows::FormsD::AccessibleEvents::SystemMenuPopupEnd, "SystemMenuPopupEnd"}, {(int64)System::Windows::FormsD::AccessibleEvents::SystemCaptureStart, "SystemCaptureStart"}, {(int64)System::Windows::FormsD::AccessibleEvents::SystemCaptureEnd, "SystemCaptureEnd"}, {(int64)System::Windows::FormsD::AccessibleEvents::SystemMoveSizeStart, "SystemMoveSizeStart"}, {(int64)System::Windows::FormsD::AccessibleEvents::SystemMoveSizeEnd, "SystemMoveSizeEnd"}, {(int64)System::Windows::FormsD::AccessibleEvents::SystemContextHelpStart, "SystemContextHelpStart"}, {(int64)System::Windows::FormsD::AccessibleEvents::SystemContextHelpEnd, "SystemContextHelpEnd"}, {(int64)System::Windows::FormsD::AccessibleEvents::SystemDragDropStart, "SystemDragDropStart"}, {(int64)System::Windows::FormsD::AccessibleEvents::SystemDragDropEnd, "SystemDragDropEnd"}, {(int64)System::Windows::FormsD::AccessibleEvents::SystemDialogStart, "SystemDialogStart"}, {(int64)System::Windows::FormsD::AccessibleEvents::SystemDialogEnd, "SystemDialogEnd"}, {(int64)System::Windows::FormsD::AccessibleEvents::SystemScrollingStart, "SystemScrollingStart"}, {(int64)System::Windows::FormsD::AccessibleEvents::SystemScrollingEnd, "SystemScrollingEnd"}, {(int64)System::Windows::FormsD::AccessibleEvents::SystemSwitchStart, "SystemSwitchStart"}, {(int64)System::Windows::FormsD::AccessibleEvents::SystemSwitchEnd, "SystemSwitchEnd"}, {(int64)System::Windows::FormsD::AccessibleEvents::SystemMinimizeStart, "SystemMinimizeStart"}, {(int64)System::Windows::FormsD::AccessibleEvents::SystemMinimizeEnd, "SystemMinimizeEnd"}, {(int64)System::Windows::FormsD::AccessibleEvents::Create, "Create"}, {(int64)System::Windows::FormsD::AccessibleEvents::Destroy, "Destroy"}, {(int64)System::Windows::FormsD::AccessibleEvents::Show, "Show"}, {(int64)System::Windows::FormsD::AccessibleEvents::Hide, "Hide"}, {(int64)System::Windows::FormsD::AccessibleEvents::Reorder, "Reorder"}, {(int64)System::Windows::FormsD::AccessibleEvents::Focus, "Focus"}, {(int64)System::Windows::FormsD::AccessibleEvents::Selection, "Selection"}, {(int64)System::Windows::FormsD::AccessibleEvents::SelectionAdd, "SelectionAdd"}, {(int64)System::Windows::FormsD::AccessibleEvents::SelectionRemove, "SelectionRemove"}, {(int64)System::Windows::FormsD::AccessibleEvents::SelectionWithin, "SelectionWithin"}, {(int64)System::Windows::FormsD::AccessibleEvents::StateChange, "StateChange"}, {(int64)System::Windows::FormsD::AccessibleEvents::LocationChange, "LocationChange"}, {(int64)System::Windows::FormsD::AccessibleEvents::NameChange, "NameChange"}, {(int64)System::Windows::FormsD::AccessibleEvents::DescriptionChange, "DescriptionChange"}, {(int64)System::Windows::FormsD::AccessibleEvents::ValueChange, "ValueChange"}, {(int64)System::Windows::FormsD::AccessibleEvents::ParentChange, "ParentChange"}, {(int64)System::Windows::FormsD::AccessibleEvents::HelpChange, "HelpChange"}, {(int64)System::Windows::FormsD::AccessibleEvents::DefaultActionChange, "DefaultActionChange"}, {(int64)System::Windows::FormsD::AccessibleEvents::AcceleratorChange, "AcceleratorChange"}};
    flags = false;
  }
};
/// @endcond

using namespace Pcf;
