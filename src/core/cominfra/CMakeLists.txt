#############################################################################
# Core
#############################################################################
forte_add_include_directories(${CMAKE_CURRENT_SOURCE_DIR})

forte_add_sourcefile_h(comtypes.h comlayersmanager.h)
forte_add_sourcefile_hcpp(commfb   comlayer)

# Will be created in top-level-cmake-file
forte_add_sourcefile_with_path_cpp(${CMAKE_BINARY_DIR}/core/cominfra/comlayersmanager.cpp) # created file

forte_add_network_layer(FBDK ON "fbdk" CFBDKASN1ComLayer fbdkasn1layer "Enable Forte Com FBDK")
forte_add_network_layer(ETH ON "ip" CIPComLayer ipcomlayer "Enable Forte Com Ethernet")

forte_add_network_layer(LOCAL ON "loc" CLocalComLayer localcomlayer "Enable Forte local communication")
