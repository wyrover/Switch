macro(BuildSwitchTests)
  #_____________________________________________________________________________________________________________________
  #                                                                                                         Switch Tests
  print("Switch Tests")
  if (BUILD_TESTS)
    enable_testing()
  endif()

  #_____________________________________________________________________________________________________________________
  #                                                                                              Switch.Core.ManualTests
  if (BUILD_TESTS AND BUILD_SWITCH_CORE)
    print("  [X] Switch.Core.ManualTests")
    add_subdirectory("tests/Switch.Core.ManualTests")
  else()
    print("  [ ] Switch.Core.ManualTests")
  endif()

  #_____________________________________________________________________________________________________________________
  #                                                                                                Switch.Core.UnitTests
  if (BUILD_TESTS AND BUILD_SWITCH_CORE)
    print("  [X] Switch.Core.UnitTests")
    add_subdirectory("tests/Switch.Core.UnitTests")
  else()
    print("  [ ] Switch.Core.UnitTests")
  endif()


  #_____________________________________________________________________________________________________________________
  #                                                                                            Switch.System.ManualTests
  if (BUILD_TESTS AND BUILD_SWITCH_SYSTEM)
    print("  [X] Switch.System.ManualTests")
    add_subdirectory("tests/Switch.System.ManualTests")
  else()
    print("  [ ] Switch.System.ManualTests")
  endif()

  #_____________________________________________________________________________________________________________________
  #                                                                                              Switch.System.UnitTests
  if (BUILD_TESTS AND BUILD_SWITCH_SYSTEM)
    print("  [X] Switch.System.UnitTests")
    add_subdirectory("tests/Switch.System.UnitTests")
  else()
    print("  [ ] Switch.System.UnitTests")
  endif()

  #_____________________________________________________________________________________________________________________
  #                                                                                    Switch.System.Drawing.ManualTests
  if (BUILD_TESTS AND BUILD_SWITCH_SYSTEM_DRAWING)
    print("  [X] Switch.System.Drawing.ManualTests")
    add_subdirectory("tests/Switch.System.Drawing.ManualTests")
  else()
    print("  [ ] Switch.System.Drawing.ManualTests")
  endif()

  #_____________________________________________________________________________________________________________________
  #                                                                                      Switch.System.Drawing.UnitTests
  if (BUILD_TESTS AND BUILD_SWITCH_SYSTEM_DRAWING)
    print("  [X] Switch.System.Drawing.UnitTests")
    add_subdirectory("tests/Switch.System.Drawing.UnitTests")
  else()
    print("  [ ] Switch.System.Drawing.UnitTests")
  endif()

  #_____________________________________________________________________________________________________________________
  #                                                                              Switch.System.Windows.Forms.ManualTests
  if (BUILD_TESTS AND BUILD_SWITCH_SYSTEM_WINDOWS_FORMS)
    print("  [X] Switch.System.Windows.Forms.ManualTests")
    add_subdirectory("tests/Switch.System.Windows.Forms.ManualTests")
  else()
    print("  [ ] Switch.System.Windows.Forms.ManualTests")
  endif()

  #_____________________________________________________________________________________________________________________
  #                                                                                Switch.System.Windows.Forms.UnitTests
  if (BUILD_TESTS AND BUILD_SWITCH_SYSTEM_WINDOWS_FORMS)
    print("  [X] Switch.System.Windows.Forms.UnitTests")
    add_subdirectory("tests/Switch.System.Windows.Forms.UnitTests")
  else()
    print("  [ ] Switch.System.Windows.Forms.UnitTests")
  endif()

  #_____________________________________________________________________________________________________________________
  #                                                                                        Switch.TUnit.Core.ManualTests
  if (BUILD_TESTS AND BUILD_SWITCH_TUNIT_CORE)
    print("  [X] Switch.TUnit.ManualTests")
    add_subdirectory("tests/Switch.TUnit.ManualTests")
  else()
    print("  [ ] Switch.TUnit.ManualTests")
  endif()

  #_____________________________________________________________________________________________________________________
  #                                                                                          Switch.TUnit.Core.UnitTests
  if (BUILD_TESTS AND BUILD_SWITCH_TUNIT_CORE)
    print("  [X] Switch.TUnit.Core.UnitTests")
    add_subdirectory("tests/Switch.TUnit.UnitTests")
  else()
    print("  [ ] Switch.TUnit.Core.UnitTests")
  endif()

  #_____________________________________________________________________________________________________________________
  #                                                                                   Switch.TUnit.Framework.ManualTests
  if (BUILD_TESTS AND BUILD_SWITCH_TUNIT_FRAMEWORK)
    print("  [X] Switch.TUnit.Framework.ManualTests")
    add_subdirectory("tests/Switch.TUnit.Framework.ManualTests")
  else()
    print("  [ ] Switch.TUnit.Framework.ManualTests")
  endif()
endmacro()
