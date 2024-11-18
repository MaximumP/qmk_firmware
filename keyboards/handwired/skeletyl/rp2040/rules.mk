# RP2040-specific options
# ALLOW_WARNINGS = yes
# PICO_INTRINSICS_ENABLED = no # ATM Unsupported by ChibiOS.

# Build Options
#   change yes to no to disable
#
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
TAP_DANCE_ENABLE = yes
UNICODE_ENABLE = yes
SERIAL_DRIVER = vendor
POINTING_DEVICE_ENABLE = yes
SPLIT_POINTING_ENABLE = yes
POINTING_DEVICE_DRIVER = pmw3360
CAPS_WORD_ENABLE = yes
WS2812_DRIVER = vendor
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = ws2812
