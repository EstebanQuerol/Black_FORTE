forte_add_module(RECONFIGURATION "FORTE Online Reconfiguration")

#############################################################################
# FORTE Reconfiguration FBs
#############################################################################
forte_add_sourcefile_hcpp(EC_KILL_ELEM EC_SET_EVT EC_START_ELEM EC_STOP_ELEM)
forte_add_sourcefile_hcpp(ST_CREATE_CONN ST_CREATE_FB ST_DEL_CONN ST_DEL_FB ST_REC_CONN ST_SET_PARM)