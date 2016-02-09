forte_add_module(BlackLib "BlackLib Function Blocks")
#############################################################################
# Black Lib FBs
#############################################################################
if(FORTE_MODULE_BlackLib)
	forte_add_definition(-std=c++11)
	forte_add_subdirectory(BlackLib_v_3p0)
	forte_add_sourcefile_hcpp(BL_AIn BL_PWM BL_IX BL_QX)
endif()


