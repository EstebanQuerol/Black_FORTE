#Some of the measurement FBs are architecture specific
if("${FORTE_ARCHITECTURE}" STREQUAL "Xenomai")
	forte_add_subdirectory(Xenomai_measurement_FBs)
endif()
forte_add_sourcefile_hcpp()
