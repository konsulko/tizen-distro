SECTION = "Multimedia/Service"

# Use bluez5 instead of bluez4
DEPENDS_remove = "bluez4"
PACKAGECONFIG[bluez] = "--enable-bluez,--disable-bluez,bluez5"
