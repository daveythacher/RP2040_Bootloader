target_sources(bootloader PRIVATE 
    Interface.cpp)

add_subdirectory(UART)
add_subdirectory(CDC)