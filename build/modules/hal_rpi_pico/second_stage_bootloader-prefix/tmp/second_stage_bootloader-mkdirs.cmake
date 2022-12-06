# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/luukvancampen/zephyrproject/zephyr/modules/hal_rpi_pico/bootloader"
  "/Users/luukvancampen/Desktop/delftMsC/realTimeSystems/blink_threads/build/bootloader"
  "/Users/luukvancampen/Desktop/delftMsC/realTimeSystems/blink_threads/build/modules/hal_rpi_pico/second_stage_bootloader-prefix"
  "/Users/luukvancampen/Desktop/delftMsC/realTimeSystems/blink_threads/build/modules/hal_rpi_pico/second_stage_bootloader-prefix/tmp"
  "/Users/luukvancampen/Desktop/delftMsC/realTimeSystems/blink_threads/build/modules/hal_rpi_pico/second_stage_bootloader-prefix/src/second_stage_bootloader-stamp"
  "/Users/luukvancampen/Desktop/delftMsC/realTimeSystems/blink_threads/build/modules/hal_rpi_pico/second_stage_bootloader-prefix/src"
  "/Users/luukvancampen/Desktop/delftMsC/realTimeSystems/blink_threads/build/modules/hal_rpi_pico/second_stage_bootloader-prefix/src/second_stage_bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/luukvancampen/Desktop/delftMsC/realTimeSystems/blink_threads/build/modules/hal_rpi_pico/second_stage_bootloader-prefix/src/second_stage_bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/luukvancampen/Desktop/delftMsC/realTimeSystems/blink_threads/build/modules/hal_rpi_pico/second_stage_bootloader-prefix/src/second_stage_bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
