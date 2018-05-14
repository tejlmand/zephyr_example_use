
FILE(GLOB app_sources src/*.c)

# There are some special zephyr linking handling, I haven't fully been able to unwrap for this small example. 
# Change to True, to see the small example trying to build and link.
if(False)

add_executable(peripheral_hr)
target_sources(peripheral_hr PRIVATE ${app_sources})
target_include_directories(peripheral_hr PUBLIC $ENV{ZEPHYR_BASE}/samples/bluetooth)
#target_include_directories(peripheral_hr ${CMAKE_CURRENT_LIST_DIR}/../zephyr/samples/bluetooth) # Alternative

target_link_libraries(peripheral_hr bluetooth_host bluetooth_common bluetooth_controller )

endif()
