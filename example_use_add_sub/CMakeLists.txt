CMAKE_MINIMUM_REQUIRED(VERSION 3.8)

project(Custmoer_project ASM C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DNRF52840_XXAA -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mthumb")  

FILE(GLOB app_sources bt_peripheral_custom/src/*.c)

include($ENV{ZEPHYR_BASE}/cmake/extensions.cmake)
import_kconfig(${CMAKE_CURRENT_LIST_DIR}/bt_peripheral_custom/.config )

# Just to handle the zephyr, kernel, offset, and subsys net as we don't do full build to shouw the
# principle
include(${CMAKE_CURRENT_LIST_DIR}/zephyr_custom.cmake)

# Here we go, creating and using Zephyr / Bluetooth modules as sub-directory.
add_subdirectory(zephyr/subsys/bluetooth)
add_subdirectory(bt_peripheral_custom)

# Example executable
# There are some special zephyr linking handling, I haven't fully been able to unwrap for this small example. 
# Change to True, to see the small example trying to build and link. (Warning: Linking will fail) 
if(False)

add_executable(bt_app)
target_sources(bt_app PRIVATE ${app_sources})
target_include_directories(bt_app PUBLIC $ENV{ZEPHYR_BASE}/samples/bluetooth)

# This is not the right place for circular referencing, in fact, the dependency tree should be made
# when defining the library, i.e. when oone know that bluetooth_host is a target, then the line:
# target_link_libraries(zephyr bluetooth_host)
# this could in zephyr lib also be done using generator expression, so the need for
#  set_property(GLOBAL APPEND PROPERTY ZEPHYR_LIBS ${library}) 
#as example:
# 
# target_link_libraries(zephyr $<$<BOOL:${CONFIG_BT_HCI}>: bluetooth_host>
#
#Then if the sub system is enabled using KConfig, this line ensures it is linked to Zephyr.
#
# could be made to ensure libzephyr.a correctly links (if that is indeed needed)
# For example use, we just depend all libs on each other, even though it might not be needed.

target_link_libraries(bt_app zephyr offsets net bluetooth)

endif()
