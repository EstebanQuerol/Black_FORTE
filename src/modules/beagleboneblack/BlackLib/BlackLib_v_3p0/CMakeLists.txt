#############################################################################
# Black Library source files
#############################################################################
forte_add_subdirectory(BlackADC)
forte_add_subdirectory(BlackDirectory)
forte_add_subdirectory(BlackGPIO)
forte_add_subdirectory(BlackI2C)
forte_add_subdirectory(BlackMutex)
forte_add_subdirectory(BlackPWM)
forte_add_subdirectory(BlackSPI)
forte_add_subdirectory(BlackThread)
forte_add_subdirectory(BlackUART)
forte_add_subdirectory(BlackTime)
forte_add_sourcefile_hcpp(BlackCore)
forte_add_include_directories(${CMAKE_CURRENT_SOURCE_DIR})


