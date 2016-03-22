forte_add_module(BBBioLib "BBBioLib Function Blocks")
#############################################################################
# Black Lib FBs
#############################################################################
if(FORTE_MODULE_BlackLib)
	forte_add_subdirectory(BBBio_lib)
	forte_add_sourcefile_hcpp(CBBBiolib BBBio_AIn BBBio_PWM)
endif()


