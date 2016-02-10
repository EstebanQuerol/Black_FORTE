forte_add_module(DNCFAGOR "DNCFAGOR comunication utils function blocks")

#############################################################################
# Test FB
#############################################################################
if(FORTE_MODULE_DNCFAGOR)
forte_add_subdirectory(TXT_utils)
forte_add_sourcefile_hcpp(UINT_DEMUX_N)
forte_add_sourcefile_hcpp(B_SECCOM_INFORMEFIJO B_SECCOM_CONTROLREMOTO)
forte_add_sourcefile_hcpp(crc SI_CRC16 SI_parseSTRING2STRING)
endif()
