macro(UpdateFileExport path keyword export)
  if (BUILD_SWITCH_SHARED_LIBS)
    file(WRITE ${path} 
      "/// @file\n"
      "/// @brief Contains ${export} keyword.\n"
      "#pragma once\n"
      "\n"
      "#if defined(WIN32)\n"
      "#  if defined(${keyword})\n"
      "#    define ${export} __declspec(dllexport)\n"
      "#  else\n"
      "#    define ${export} __declspec(dllimport)\n"
      "#  endif\n"
      "#else\n"
      "#  if defined(${keyword})\n"
      "#    define ${export} __attribute__((visibility (\"default\")))\n"
      "#  else\n"
      "#    define ${export}\n"
      "#  endif\n"
      "#endif\n"
    )
  else()
    file(WRITE ${path} 
    "/// @file\n"
    "/// @brief Contains ${export} keyword.\n"
    "#pragma once\n"
    "\n"
    "#define ${export}\n"
    )
  endif()
endmacro()

macro(UpdateExport)
  UpdateFileExport(src/Switch.Core/include/Switch/Export.hpp SWITCH_EXPORT export_)
  UpdateFileExport(src/Switch/include/Switch/Export.hpp SWITCH_EXPORT export_)
  UpdateFileExport(src/Switch.Core/include/Switch/CoreExport.hpp SWITCH_CORE_EXPORT core_export_)
  UpdateFileExport(src/Switch.System/include/Switch/SystemExport.hpp SWITCH_SYSTEM_EXPORT system_export_)
  UpdateFileExport(src/Switch.System.Core/include/Switch/SystemCoreExport.hpp SWITCH_SYSTEM_CORE_EXPORT system_core_export_)
  UpdateFileExport(src/Switch.System.Drawing/include/Switch/SystemDrawingExport.hpp SWITCH_SYSTEM_DRAWING_EXPORT system_drawing_export_)
  UpdateFileExport(src/Switch.System.ServiceModel/include/Switch/SystemServiceModelExport.hpp SWITCH_SYSTEM_SERVICEMODEL_EXPORT system_servicemodel_export_)
  UpdateFileExport(src/Switch.System.Windows.Forms/include/Switch/SystemWindowsFormsExport.hpp SWITCH_SYSTEM_WINDOWS_FORMS_EXPORT system_windows_forms_export_)
  UpdateFileExport(src/Switch.TUnit.Core/include/Switch/TUnitCoreExport.hpp SWITCH_TUNIT_CORE_EXPORT tunit_core_export_)
  UpdateFileExport(src/Switch.TUnit.Framework/include/Switch/TUnitFrameworkExport.hpp SWITCH_TUNIT_FRAMEWORK_EXPORT tunit_framework_export_)
endmacro()
