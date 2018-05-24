This is a small CMake example showing how the use cleanup of Zephyr CMakeLists.txt heriarchy can
be used to create a single application using add_executable.

Making fewer Zephyr libraries with clear names and correct CMake link dependencies can make it
easier to integrate and more visible to user of Zephyr what dependencies a project has.

It also provides an extra level of control, such as manually specifying a ISR table.
For Zephyr in general, the generated ISR is very strong, but users of Zephyr, especially within
Medical areas might require more strict control of their source.
Also, many users of Zephyr will target a specific chip, or limited number of variants.
To those, it may also be desired to have full control.


Cleaning up the link dependencies, and keep the knowledge where it belongs is also much more scalable.
When creating, e.g. within the CMakeLists.txt for the subsytem Bluetooth Low Energy library, it can
be stated directly that bluetooth depends on Zephyr, kernel, and net libraries.
The subsystem net library can then depend also on Zephyr and kernel.

Zephyr also depends on kernel, offsets, and app (libapp contains e.g. memcpy, memcmp, etc. in some cases)

This ensures that CMake can handle circular dependencies correctly, and thus an end-user just links
his app to the things he needs directly, e.g. Bluetooth.
The dependencies for Bluetooth are handled by CMakes internal dependency propagation.

Cleaning up subsystem CMakeLists.txt reduces the numbers of CMakeLists.txt files, and thus each 
CMakeLists.txt contains valueble information about the name of the subsystem and its dependencies.
Source files are then populated in nested *.cmake files, making architecture more clean, and thus
eases navigation and maintenance.

All testing has been done on BOARD=nrf52840_pca10056

############################################################
# bt_example - start                                       #
############################################################

To configure, generator and build, run the folllowing commands, starting from the folder
<reppo>/bt_example:

  source ../zephyr/zephyr-env.sh
  mkdir build
  cd build
  cmake -GNinja -DBOARD=nrf52840_pca10056 ..
  ninja

To generate a dot graph of dependencies while in build folder, execute:

  cmake --graphiz=bt_example.dot ..

Please note, due to \" in some link dependencies, the dot generator producesses invalid graph.
Modify the doubles qoutes in: bt_example.dot
on the line:
  
  "node162" [ label="-L"/opt/zephyr-sdk/sysroots/armv5-zephyr-eabi/usr/lib/arm-zephyr-eabi/6.2.0/armv7e-m"" shape="ellipse"];

into
  
   "node162" [ label="-L/opt/zephyr-sdk/sysroots/armv5-zephyr-eabi/usr/lib/arm-zephyr-eabi/6.2.0/armv7e-m" shape="ellipse"];

 valid graph.
 Thereafter, view the graph using, eg. xdot.

   xdot bt_example.dot


All existing Zephyr example still ought to work, but so far only peripheral_hr has been verified

############################################################
# bt_example - end                                         #
############################################################

All existing Zephyr example still ought to work, but so far only peripheral_hr has been verified.
To check the state of normal Zephyr example, execute below commands.

############################################################
# peripheral_hr - start                                    #
############################################################

To configure, generator and build, run the folllowing commands, starting from the folder
<reppo>/zephyr:

  source zephyr-env.sh
  mkdir build
  cd build
  cmake -GNinja -DBOARD=nrf52840_pca10056 ../sample/bluetooth/peripheral_hr/
  ninja

############################################################
# peripheral_hr - end                                      #
############################################################

