do_install_append() {
    # Tmp fix:
    # Remove modules combine-sink and augment-properties from
    # pulseaudio-module-murphy-ivi since they conflict with modules with
    # the same name provided by pulseaudio. Modules provided by
    # pulseaudio-module-murphy-ivi are based on the ones provided by
    # pulseaudio but incorpoate muprhy/IVI specific changes. The muprhy
    # team plans on renaming those modules in order to prevent this
    # conflict and allows both pulseaudio-module-murphy-ivi and
    # pulseaudio modules to be installed alongside.
    # Bug-Tizen: PTREL-825
    rm -f ${D}${prefix}/lib/pulse-5.0/modules/module-combine-sink.so
    rm -f ${D}${prefix}/lib/pulse-5.0/modules/module-augment-properties.so
}

FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug"
