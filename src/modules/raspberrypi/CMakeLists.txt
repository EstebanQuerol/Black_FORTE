forte_add_module(RaspberryPi "Raspberry Pi Function Blocks")

forte_add_include_directories(${CMAKE_CURRENT_SOURCE_DIR})

#######################################################
# Raspberry Pi
#######################################################

forte_add_link_library(-lwiringPi)

forte_add_sourcefile_hcpp(../../stdfblib/io/IX)
forte_add_sourcefile_hcpp( ../../stdfblib/io/QX)
forte_add_sourcefile_hcpp(processinterface)

