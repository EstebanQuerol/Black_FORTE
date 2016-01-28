#############################################################################
# Beagle Bone Black
#############################################################################
forte_add_module(BeagleBoneBlack "BeagleBone Black Function Blocks")


if(FORTE_MODULE_BeagleBoneBlack)

SET(FORTE_BeagleBoneBlack_IO_Libaries "" CACHE PATH "Path to IO lib: http://mkaczanowski.com/beaglebone-black-cpp-gpio-library-for-beginners/ (leave empty for installed source code)")

forte_add_include_directories(${CMAKE_CURRENT_SOURCE_DIR})

forte_add_sourcefile_hcpp(../../stdfblib/io/IX)
forte_add_sourcefile_hcpp(../../stdfblib/io/QX)
forte_add_sourcefile_hcpp(processinterface)

if("${FORTE_ARCHITECTURE}" STREQUAL "Posix")
    if(EXISTS ${FORTE_BeagleBoneBlack_IO_Libaries})
		forte_add_include_directories( ${FORTE_BeagleBoneBlack_IO_Libaries})
		forte_add_link_directories( ${FORTE_BeagleBoneBlack_IO_Libaries}/lib )
    else(EXISTS ${FORTE_BeagleBoneBlack_IO_Libaries})
        #TODO forte_add_include_directories( /usr/include/bbblib )
	endif(EXISTS ${FORTE_BeagleBoneBlack_IO_Libaries})
	
	forte_add_link_library(libbbbgpiomaster.a)
	
else()
	MESSAGE("BeagleBone Blak requires Posix architecture!")
    set(FORTE_MODULE_BeagleBoneBlack OFF) 
endif()
	

endif()
