forte_add_module(UTILS "FORTE UTILITY FBs")

#############################################################################
# FORTE UTILITY FBs
#############################################################################
forte_add_sourcefile_hcpp(OUT_ANY_CONSOLE GEN_F_MUX GEN_CSV_WRITER GEN_APPEND_STRING)
forte_add_sourcefile_hcpp(GEN_ARRAY2VALUES GEN_VALUES2ARRAY GEN_ARRAY2ARRAY GET_AT_INDEX SET_AT_INDEX)
forte_add_sourcefile_hcpp(STEST_END)

forte_add_subdirectory(tests)
