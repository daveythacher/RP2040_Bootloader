# RP2040_Bootloader
This is meant to be short and sweet. (May be a little dangerous.)

## Status
Warning: Experimental! (Ranking is Release, Release Canditate, Beta, Alpha and Experimental.)

Currently working with SDK version 1.4.0. 
* No known compatibility issues exist with applications using different versions.
* No known compatibility issues exist with bootloader using different versions.

## Requirements
### Initial State
You must replicate the runtime_init logic of the SDK. (See SDK pico_standard_link and pico_runtime.)

* The SDK does this for you. (You are not required to use the SDK.)
* Flash and USB subsystem must be configured correctly before handing over to application. (This is a precedent of bootrom.)

### Recommended Requirements
All versions of the bootloader should support picotool. This is done to allow the bootloader to be recovered.
