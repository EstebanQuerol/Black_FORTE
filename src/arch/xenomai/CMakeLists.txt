SET(SOURCE_GROUP ${SOURCE_GROUP}\\Xenomai)

forte_add_architecture(Xenomai)
if("${FORTE_ARCHITECTURE}" STREQUAL "Xenomai")
	IF(CMAKE_CROSSCOMPILING)
		SET(Xenomai_staging_root "" CACHE PATH "Xenomai staging directory")
		IF(NOT EXISTS ${Xenomai_staging_root})
			MESSAGE(SEND_ERROR "Cross compiled xenomai requires a staging diectory")
		ENDIF(NOT EXISTS ${Xenomai_staging_root})
	ENDIF(CMAKE_CROSSCOMPILING)
	#Xenomai defines, includes and libs
	forte_add_definition(-D_GNU_SOURCE -D_REENTRANT -D__XENO__)
	forte_add_include_directories(${Xenomai_staging_root}/usr/xenomai/include)
	forte_add_include_directories(${Xenomai_staging_root}/usr/xenomai/include/posix)
	forte_add_include_directories(${Xenomai_staging_root}/usr/xenomai/include/native)
	forte_add_link_flags(-Wl,@${Xenomai_staging_root}/usr/xenomai/lib/posix.wrappers)
	forte_add_link_directories(${Xenomai_staging_root}/usr/xenomai/lib)
	forte_add_link_library(-lpthread_rt -lxenomai -lpthread -lnative -lrt)

	#FORTE defines, includes and libs
	forte_add_definition("-W -Wall -Wextra -Woverloaded-virtual -Wconversion -DFORTE_LITTLE_ENDIAN -ggdb")
  	forte_add_include_directories(../${CMAKE_CURRENT_SOURCE_DIR})
	forte_add_include_directories(${CMAKE_CURRENT_SOURCE_DIR})
	forte_add_sourcefile_hcpp(thread pctimeha sync XenomaiECET)
	forte_add_sourcefile_cpp(main.cpp)

	#Ethernet support
 	if(FORTE_COM_ETH)
		forte_add_sourcefile_hcpp( ../fdselecthand ../bsdsocketinterf)
		forte_add_sourcefile_h(../gensockhand.h)
		forte_add_sourcefile_h(sockhand.h)
	endif(FORTE_COM_ETH)

	#Serial support
	forte_add_network_layer(SER OFF "ser" CSerCommLayer sercommlayer "Enable Forte serial line communication")
	forte_add_network_layer(MUXSER OFF "muxser" CMuxedSerCommLayer muxedsercommlayer "Enable Forte multiplexed serial line communication")

	set(FORTE_RTTI_AND_EXCEPTIONS FALSE CACHE BOOL "Enable RTTI and Exceptions")
	mark_as_advanced(FORTE_RTTI_AND_EXCEPTIONS)
	IF(NOT FORTE_RTTI_AND_EXCEPTIONS)
		forte_add_definition("-fno-rtti -fno-exceptions")
	ENDIF(NOT FORTE_RTTI_AND_EXCEPTIONS)


	set(FORTE_POSIX_GENERATE_MAP_FILE FALSE CACHE BOOL "Enable the generation of map files")
	mark_as_advanced(FORTE_POSIX_GENERATE_MAP_FILE)
	IF(FORTE_POSIX_GENERATE_MAP_FILE)
		forte_add_link_flags("-Wl,-M -Wl,-Map -Wl,forte.map -Wl,-cref")
	ENDIF(FORTE_POSIX_GENERATE_MAP_FILE)	  	
endif()
