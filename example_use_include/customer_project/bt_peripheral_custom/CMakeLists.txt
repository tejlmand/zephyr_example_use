CMAKE_MINIMUM_REQUIRED(VERSION 3.8)
#include($ENV{ZEPHYR_BASE}/cmake/app/boilerplate.cmake NO_POLICY_SCOPE)
project(Custmoer_project ASM C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DNRF52840_XXAA -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mthumb")  

FILE(GLOB app_sources src/*.c)

include($ENV{ZEPHYR_BASE}/cmake/extensions.cmake)
import_kconfig(${CMAKE_CURRENT_LIST_DIR}/.config )

# Just to handle the zephyr, kernel, offset, and subsys net as we don't do full build to shouw the
# principle
include(${CMAKE_CURRENT_LIST_DIR}/zephyr_custom.cmake)

# We include bluetooth CMakeLists.txt as include, this means we can adjust it to our needs without
# modifying the zephyr at all.
include($ENV{ZEPHYR_BASE}/subsys/bluetooth/CMakeLists.txt)

# Example, customer or Nordic has some tweaks they like to make without making this up-stream.
# Could also be linking of a dedicated library agains zephyr, instead of zephyrs projects own version.
set(CONFIG_BT_INTERNAL_STORAGE) # Clear flag if set though kconfig so we can override storage from bluetooth module

# Add our own storage module
target_sources(bluetooth PRIVATE
  # Our custom version.
  ${CMAKE_CURRENT_LIST_DIR}/custom/storage.c
)

# Remember to still link subsys__fs (just called fs as it is imported target) from zephyr
# This is needed here, as we are manually handling this, due to file subs above.
target_link_libraries(bluetooth PUBLIC fs)


# There are some special zephyr linking handling, I haven't fully been able to unwrap for this small example. 
# Change to True, to see the small example trying to build and link. (Warning: Linking will fail) 
if(False)

add_executable(bt_app)
target_sources(bt_app PRIVATE ${app_sources})
target_include_directories(bt_app PUBLIC $ENV{ZEPHYR_BASE}/samples/bluetooth)

target_link_libraries(bt_app zephyr offsets net bluetooth zephyr_interface)

endif()
