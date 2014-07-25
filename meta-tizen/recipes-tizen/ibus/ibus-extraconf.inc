EXTRA_OECONF += " --disable-introspection "

DEPENDS_append_class-target = " vala-native "

SRC_URI += " file://Remove_vala_test.patch "

FILES_${PN} += "/usr/lib/ibus/ibus-wayland"