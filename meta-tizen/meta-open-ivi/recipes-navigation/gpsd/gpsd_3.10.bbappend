PACKAGECONFIG ?= "${@base_contains('DISTRO_FEATURES', 'bluetooth', 'bluez', '', d)}"
PACKAGECONFIG[bluez] = "bluez='true',bluez='false',bluez5"
