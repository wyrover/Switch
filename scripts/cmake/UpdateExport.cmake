macro(UpdateExport)
if (BUILD_SWITCH_SHARED_LIBS)
  file(WRITE src/Switch.Core/include/Switch/Export.hpp 
    "/// @file\n"
	"/// @brief Contains export_ keyword.\n"
	"#pragma once\n"
	"\n"
	"#if defined(WIN32)\n"
	"#  if defined(SWITCH_EXPORT)\n"
	"#    define export_ __declspec(dllexport)\n"
	"#  else\n"
	"#    define export_ __declspec(dllimport)\n"
	"#  endif\n"
	"#else\n"
	"#  if defined(SWITCH_EXPORT)\n"
	"#    define export_ __attribute__((visibility (\"default\")))\n"
	"#  else\n"
	"#    define export_\n"
	"#  endif\n"
	"#endif\n"
  )
else()
  file(WRITE src/Switch.Core/include/Switch/Export.hpp 
	"/// @file\n"
	"/// @brief Contains export_ keyword.\n"
	"#pragma once\n"
	"\n"
	"#define export_\n"
  )
endif()
endmacro()
