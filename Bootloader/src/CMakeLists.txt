add_executable(bootloader 
    main.cpp
    Interface.cpp
    Interface/UART.cpp)
        
target_compile_definitions(bootloader PUBLIC
	PICO_HEAP_SIZE=65536
	PICO_XOSC_STARTUP_DELAY_MULTIPLIER=64
)

target_compile_options(bootloader PUBLIC
    $<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>
    -fno-exceptions 
    -fno-check-new 
    $<$<COMPILE_LANGUAGE:CXX>:-fno-enforce-eh-specs>
    -g 
    -ffunction-sections 
    -fdata-sections 
    -O3
    -funroll-loops 
    -Werror 
    -Wall)

pico_set_binary_type(bootloader copy_to_ram)

# create map/bin/hex file etc.
pico_add_extra_outputs(bootloader)

# enable usb output, disable uart output
pico_enable_stdio_usb(bootloader 1)
pico_enable_stdio_uart(bootloader 0)

# create disassembly with source
function(pico_add_dis_output2 TARGET)
    add_custom_command(TARGET ${TARGET} POST_BUILD
        COMMAND ${CMAKE_OBJDUMP} -S $<TARGET_FILE:${TARGET}> >$<IF:$<BOOL:$<TARGET_PROPERTY:${TARGET},OUTPUT_NAME>>,$<TARGET_PROPERTY:${TARGET},OUTPUT_NAME>,$<TARGET_PROPERTY:${TARGET},NAME>>.dis2)
endfunction()
pico_add_dis_output2(bootloader)

# pull in dependencies
target_link_libraries(bootloader 
	pico_stdlib
    pico_time)