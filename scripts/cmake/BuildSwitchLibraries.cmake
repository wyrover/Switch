macro(BuildSwitchLibraries)
  print("Switch Libraries")
  file(WRITE src/Switch/include/Switch/Switch.hpp "#pragma once\n\n")

  #_______________________________________________________________________________________
  #                                                                                 Switch
  print("  [X] Switch")
  add_subdirectory("src/Switch")

  #_______________________________________________________________________________________
  #                                                                            Switch.Core
  if (BUILD_SWITCH_CORE)
    print("  [X] Switch.Core")
    add_subdirectory("src/Switch.Core")
    file(APPEND src/Switch/include/Switch/Switch.hpp "#include \"Switch/Switch.Core\"\n")
  else()
    print("  [ ] Switch.Core")
  endif()

  #_______________________________________________________________________________________
  #                                                                          Switch.System
  if (BUILD_SWITCH_SYSTEM)
    print("  [X] Switch.System")
    add_subdirectory("src/Switch.System")
    file(APPEND src/Switch/include/Switch/Switch.hpp "#include \"Switch/Switch.System\"\n")
  else()
    print("  [ ] Switch.System")
  endif()

  #_______________________________________________________________________________________
  #                                                                     Switch.System.Core
  if (BUILD_SWITCH_SYSTEM_CORE)
    print("  [X] Switch.System.Core")
    add_subdirectory("src/Switch.System.Core")
    file(APPEND src/Switch/include/Switch/Switch.hpp "#include \"Switch/Switch.System.Core\"\n")
  else()
    print("  [ ] Switch.System.Core")
  endif()

  #_______________________________________________________________________________________
  #                                                                  Switch.System.Drawing
  if (NOT IOS AND BUILD_SWITCH_SYSTEM_DRAWING)
    print("  [X] Switch.System.Drawing")
    add_subdirectory("src/Switch.System.Drawing")
    file(APPEND src/Switch/include/Switch/Switch.hpp "#include \"Switch/Switch.System.Drawing\"\n")
  else()
    print("  [ ] Switch.System.Drawing")
  endif()

  #_______________________________________________________________________________________
  #                                                             Switch.System.ServiceModel
  if (BUILD_SWITCH_SYSTEM_SERVICEMODEL)
    print("  [X] Switch.System.ServiceModel")
    add_subdirectory("src/Switch.System.ServiceModel")
    file(APPEND src/Switch/include/Switch/Switch.hpp "#include \"Switch/Switch.System.ServiceModel\"\n")
  else()
    print("  [ ] Switch.System.ServiceModel")
  endif()

  #_______________________________________________________________________________________
  #                                                            Switch.System.Windows.Forms
  if (NOT IOS AND BUILD_SWITCH_SYSTEM_WINDOWS_FORMS)
    print("  [X] Switch.System.Windows.Forms")
    add_subdirectory("src/Switch.System.Windows.Forms")
    file(APPEND src/Switch/include/Switch/Switch.hpp "#include \"Switch/Switch.System.Windows.Forms\"\n")
  else()
    print("  [ ] Switch.System.Windows.Forms")
  endif()

  #_______________________________________________________________________________________
  #                                                                      Switch.TUnit.Core
  if (BUILD_SWITCH_TUNIT_CORE)
    print("  [X] Switch.TUnit.Core")
    add_subdirectory("src/Switch.TUnit.Core")
    file(APPEND src/Switch/include/Switch/Switch.hpp "#include \"Switch/Switch.TUnit.Core\"\n")
  else()
    print("  [ ] Switch.TUnit.Core")
  endif()

  #_______________________________________________________________________________________
  #                                                                 Switch.TUnit.Framework
  if (BUILD_SWITCH_TUNIT_FRAMEWORK)
    print("  [X] Switch.TUnit.Framework")
    add_subdirectory("src/Switch.TUnit.Framework")
    file(APPEND src/Switch/include/Switch/Switch.hpp "#include \"Switch/Switch.TUnit.Framework\"\n")
  else()
    print("  [ ] Switch.TUnit.Framework")
  endif()

  #_______________________________________________________________________________________
  #                                                                      Switch.TUnit.Main
  if (BUILD_SWITCH_TUNIT_MAIN)
    print("  [X] Switch.TUnit.Main")
    add_subdirectory("src/Switch.TUnit.Main")
  else()
    print("  [ ] Switch.TUnit.Main")
  endif()
endmacro()
