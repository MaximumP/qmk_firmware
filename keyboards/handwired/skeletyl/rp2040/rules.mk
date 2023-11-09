# RP2040-specific options
ALLOW_WARNINGS = yes
PICO_INTRINSICS_ENABLED = no # ATM Unsupported by ChibiOS.

# Build Options
#   change yes to no to disable
#
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = yes         # Commands for debug and configuration
TAP_DANCE_ENABLE = yes
UNICODE_ENABLE = yes
SERIAL_DRIVER = vendor
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = analog_joystick
CAPS_WORD_ENABLE = yes
