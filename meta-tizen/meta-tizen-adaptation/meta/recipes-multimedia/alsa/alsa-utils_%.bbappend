SECTION = "Applications/Multimedia"

# Tizen doesn't have udev-devel. Instead udev.pc is provided by systemd-devel.
# Instead of untangling that, hard-code the udev dir instead of taking it from
# the .pc file. That's also how the alsa-utils.spec worked.
DEPENDS_remove = "udev"
PACKAGECONFIG[udev] = "--with-udev-rules-dir=/lib/udev/rules.d,,udev"

# Not enabled in Tizen, also fails to build.
EXTRA_OECONF_append = " --disable-nls"
