SRC_URI += " file://Remove_vala_test.patch "

DEPENDS_append_class-target = " vala-native "

EXTRA_OECONF += " --disable-introspection "

FILES_${PN} += "/usr/lib/ibus/ibus-wayland"

