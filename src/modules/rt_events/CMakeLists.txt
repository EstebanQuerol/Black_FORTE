forte_add_module(RT_Events "Real-Time Event Funktion blocks")

#############################################################################
# RT_Events FB
#############################################################################
forte_add_sourcefile_hcpp(RT_E_CYCLE  RT_E_DEMUX       RT_E_F_TRIG  RT_E_PERMIT  RT_E_R_TRIG  RT_E_SPLIT RT_E_SPLIT_3 RT_E_SPLIT_6)
forte_add_sourcefile_hcpp(RT_E_DELAY  RT_E_EC_COUPLER  RT_E_MERGE   RT_E_REND    RT_E_SELECT  RT_E_SWITCH RT_E_TRAIN)
if("${FORTE_ARCHITECTURE}" STREQUAL "Xenomai")
	forte_add_subdirectory(Xenomai_RT_FBS)
endif()