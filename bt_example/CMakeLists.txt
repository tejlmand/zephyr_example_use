CMAKE_MINIMUM_REQUIRED(VERSION 3.8)

include($ENV{ZEPHYR_BASE}/cmake/app/boilerplate.cmake NO_POLICY_SCOPE)
project(NONE)

FILE(GLOB app_sources src/*.c)


add_executable(bt_app.elf )
target_sources(bt_app.elf PRIVATE ${app_sources}
                                  # Example that show a user of zephyr could provide his own isr table.
                                  ${CMAKE_CURRENT_SOURCE_DIR}/isr_app_tables.c
)
target_include_directories(bt_app.elf PUBLIC $ENV{ZEPHYR_BASE}/samples/bluetooth)

# Due to the need of -Wl,--whole-lib on bluetooth lib we cannot using default CMake link 
# (and propagation), but must use, see further down:
#   -Wl,--whole-archive zephyr bluetooth net -Wl,--no-whole-archive
# target_link_libraries(bt_app.elf bluetooth)

# Those are link flags a customer would normally decide if he wants.
# Alternatively, providing an CMake interface lib could be used for flag propagation
target_link_libraries(bt_app.elf
  -Wl,-Map=${PROJECT_BINARY_DIR}/bt_app.map
  "-T ${CMAKE_CURRENT_SOURCE_DIR}/linker.cmd"
  -Wl,--print-memory-usage
)

# If Zephyr is cleaned up similar to bluetooth lib, then there will be no need for -Wl,--whole-archive
# Initial proposal does not remove the need for --whole-archive, see second proposal on how to move
# the whole archive knowledge to the library itself.
target_link_libraries(bt_app.elf
  -Wl,--whole-archive zephyr bluetooth net -Wl,--no-whole-archive
)

# This should ideally come from cmake library propagation.
target_link_libraries(bt_app.elf
  ${LIB_INCLUDE_DIR}
  ${TOOLCHAIN_LIBS}
)
