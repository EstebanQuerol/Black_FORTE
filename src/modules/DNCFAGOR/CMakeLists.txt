forte_add_module(DNCFAGOR "DNCFAGOR comunication utils function blocks")

#############################################################################
# Test FB
#############################################################################
if(FORTE_MODULE_DNCFAGOR)
forte_add_subdirectory(TXT_utils )
forte_add_sourcefile_hcpp(UINT_DEMUX_N STRING_DEMUX2N B_EQ_WSTRING)
forte_add_sourcefile_hcpp(B_SECCOM_INFORMEFIJO B_SECCOM_CONTROLREMOTO B_ALGDNC)
forte_add_sourcefile_hcpp(crc SI_CRC16 SI_CLOCK SI_parseSTRING2STRING)
forte_add_sourcefile_hcpp(C_RESTART_CLIENT B_CURRENTCALC B_STRINGERASESPACES)
endif()
