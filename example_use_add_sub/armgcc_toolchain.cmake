# TODO license, copyright

# Cross compiling using cmake require setting CMAKE_SYSTEM_NAME
# We run bare metal, and don't have an OS so most appropriate is to use Generic for now
# set(CMAKE_SYSTEM_NAME Nordic) # Unsure why we want out own platform
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)


set(CMAKE_SYSROOT ${CMAKE_INSTALL_PREFIX}) # Instead of hiding in platform files.

# specify the toolchain prefix, this makes it easier to reuse this files for other compilers, e.g. std-gcc or armcc
set(TOOLCHAIN_PREFIX arm-none-eabi-)

set(CMAKE_C_COMPILER   ${TOOLCHAIN_PREFIX}gcc)
set(CMAKE_CXX_COMPILER ${TOOLCHAIN_PREFIX}g++)
set(CMAKE_LD           ${TOOLCHAIN_PREFIX}ld)

set(CMAKE_ASM_COMPILER ${TOOLCHAIN_PREFIX}as)
set(CMAKE_AR           ${TOOLCHAIN_PREFIX}ar CACHE INTERNAL "")
set(CMAKE_AR           ${TOOLCHAIN_PREFIX}ar CACHE INTERNAL "")
set(CMAKE_RANLIB       ${TOOLCHAIN_PREFIX}ranlib CACHE INTERNAL "")
set(CMAKE_OBJCOPY      ${TOOLCHAIN_PREFIX}objcopy)
set(CMAKE_OBJDUMP      ${TOOLCHAIN_PREFIX}objdump)

# Flags to be variants of library both compile and linking:
# "-fshort-wchar")
# "-fshort-wchar --no-wchar-size-warning")
# "": default
#"-mfloat-abi=softfp"
#"-mfloat-abi=soft"
#"-mfloat-abi=hard" : Default

# Some important flags, which are not project specific
# Shared c flags for ARMGCC compiler
#set(NORDIC_COMMON_FLAGS "-Wall -Werror -mthumb -mabi=aapcs -ffunction-sections -fdata-sections -fno-strict-aliasing -fno-builtin --short-enums -MP -MD" CACHE STRING "" FORCE)
#set(NORDIC_COMMON_FLAGS "${NORDIC_COMMON_FLAGS} -mfloat-abi=hard" CACHE STRING "" FORCE)

# Shared Link flags for ARMGCC compile
#set(NORDIC_COMMON_LINK_FLAGS "-mthumb -mabi=aapcs -Wl,--gc-section --specs=nano.specs -lc -lnosys " CACHE STRING "" FORCE)
#set(NORDIC_COMMON_LINK_FLAGS "${NORDIC_COMMON_LINK_FLAGS} -mfloat-abi=hard" CACHE STRING "" FORCE)

# Running bare bone makes it difficult for CMake to test the compiler
# Setting linker flags to nosys and nano on bare metal system ensure cmake can verify the compiler.
# This setting can be overwritten by the project for final compilation.
set(CMAKE_EXE_LINKER_FLAGS "--specs nosys.specs --specs=nano.specs " CACHE INTERNAL "") 

set(CMAKE_C_FLAGS_DEBUG   "-g -ggdb3 -O0" CACHE STRING "")
set(CMAKE_CXX_FLAGS_DEBUG "-g -ggdb3 -O0" CACHE STRING "")

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

