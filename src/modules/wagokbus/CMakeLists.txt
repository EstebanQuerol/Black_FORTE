#############################################################################
# WAGO KBUS SIFBs
#############################################################################
forte_add_module(WagoKbus "Wago Kbus Function Blocks")
if(FORTE_MODULE_WagoKbus)

if("${FORTE_ARCHITECTURE}" STREQUAL "Posix")
##All Wago depedencies are added here
 
  forte_add_link_flags("-O0 -g3  -Wall")  
  forte_add_definition("-I../../../sysroot-target/usr/include/OsLinux")
  forte_add_definition("-I../../../sysroot-target/usr/include/dal") 
  
  forte_add_link_library(-ldal -llibloader -lpthread -lffi -ldbus-glib-1 -lglib-2.0 )
  forte_add_link_library(-ltypelabel -loslinux -ldbuskbuscommon)  
   
  forte_add_sourcefile_hcpp(kbushandler kbusfb)
 
  forte_add_sourcefile_hcpp(WAGO_750_400 WAGO_750_530)

#TODO: Further dependencies are to be checked and added later

else("${FORTE_ARCHITECTURE}" STREQUAL "Posix")
 #TODO add check if we are really building for wago
  MESSAGE("wAGO_KBUS is only supported for FORTE on Linux platforms. Disabled Module!")
    set(FORTE_MODULE_wAGO_KBUS OFF)
endif("${FORTE_ARCHITECTURE}" STREQUAL "Posix")

endif(FORTE_MODULE_WagoKbus)
