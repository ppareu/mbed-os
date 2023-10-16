# Copyright (c) 2020 ARM Limited. All rights reserved.
# SPDX-License-Identifier: Apache-2.0

add_library(TextLCD INTERFACE)

target_include_directories(TextLCD
    INTERFACE
        include
)

target_sources(TextLCD
    INTERFACE
        src/TextLCD.cpp
)

# target_link_libraries(mbed-usb
#    INTERFACE
#)
