#Linux-ARM-EABIHF Toolchain
SET(ARM_EABIHF_UTILS_ROOT "" CACHE PATH "Linux-arm-eabihf toolchain directory")
#TODO: Check if path exists and show a message when it doesn't
set(toolchain_dir ${ARM_EABIHF_UTILS_ROOT})
set(toolchain_bin_dir ${toolchain_dir}/bin)
set(toolchain_libc_dir ${toolchain_dir}/arm-linux-gnueabihf/libc)
set(toolchain_inc_dir ${toolchain_libc_dir}/include)
set(toolchain_lib_dir ${toolchain_libc_dir}/usr/lib)
set(CMAKE_SYSTEM_NAME Linux CACHE INTERNAL "system name")
set(CMAKE_SYSTEM_PROCESSOR arm CACHE INTERNAL "processor")
set(CMAKE_C_COMPILER ${toolchain_bin_dir}/arm-linux-gnueabihf-gcc)
set(CMAKE_CXX_COMPILER ${toolchain_bin_dir}/arm-linux-gnueabihf-g++)
set(CMAKE_C_FLAGS "-isystem ${toolchain_inc_dir}" CACHE INTERNAL "c compiler flags")
set(CMAKE_CXX_FLAGS "-isystem ${toolchain_inc_dir}" CACHE INTERNAL "cxx compiler flags")
set(link_flags -L${toolchain_lib_dir})
set(CMAKE_EXE_LINKER_FLAGS ${link_flags} CACHE INTERNAL "exe link flags")
set(CMAKE_MODULE_LINKER_FLAGS ${link_flags} CACHE INTERNAL "module link flags")
set(CMAKE_SHARED_LINKER_FLAGS ${link_flags} CACHE INTERNAL "shared lnk flags")
set(CMAKE_FIND_ROOT_PATH ${toolchain_libc_dir} CACHE INTERNAL "cross root directory")
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM BOTH CACHE INTERNAL "")
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY CACHE INTERNAL "")
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY CACHE INTERNAL "")





