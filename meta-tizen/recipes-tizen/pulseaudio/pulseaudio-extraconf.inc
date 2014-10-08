inherit gettext pkgconfig

EXTRA_OECONF = "--disable-orc \
                --prefix=${prefix} \
                --disable-static \
                --enable-alsa \
                --disable-ipv6 \
                --disable-oss-output \
                --disable-oss-wrapper \
                --disable-x11 \
                --disable-hal-compat \
                --disable-lirc \
                --disable-avahi \
                --disable-jack \
                --disable-xen \
                --without-fftw \
                --enable-bluez5 \
                --disable-bluez4 \
                --with-bluetooth-headset-backend=ofono \
                --enable-systemd \
                --with-database=tdb \
                --enable-samsung-policy \
                --with-udev-rules-dir=${prefix}/lib/udev/rules.d \
                --with-system-user=pulse \
                --with-system-group=pulse \
                --with-access-group=pulse-access \
                "

do_configure_append() {
    # Configure is done twice, once in bootsrap.sh and once in
    # autotools_do_configure, using only on eof those ends up in either
    # configure failing or build failing.
    ./bootstrap.sh ${EXTRA_OECONF}
    autotools_do_configure
}

do_compile() {
    cd ${S}
    LANG=C
    export LANG
    unset DISPLAY
    LD_AS_NEEDED=1; export LD_AS_NEEDED ;
    export CFLAGS="$CFLAGS -fno-strict-aliasing"
    export LD_AS_NEEDED=0

    oe_runmake V=0
}

FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-tunnel-sink-new.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-remap-source.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-pipe-sink.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-stream-restore.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/libalsa-util.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-role-cork.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-virtual-surround-sink.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-dbus-protocol.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-esound-protocol-unix.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-gconf.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-http-protocol-tcp.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-virtual-source.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-tunnel-source-new.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-raop-sink.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-bluez5-device.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-switch-on-port-available.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-udev-detect.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/libprotocol-native.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-systemd-login.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-remap-sink.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-volume-restore.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-match.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-main-volume-policy.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-volume-api.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-bluez5-discover.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-filter-heuristics.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-null-source.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-role-ducking.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-rtp-send.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-sine-source.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-policy.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/libcli.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-augment-properties.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-always-sink.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-rtp-recv.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-audio-groups.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-alsa-card.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-pipe-source.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-bluetooth-policy.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/libbluez5-util.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-loopback.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-esound-compat-spawnpid.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-combine-sink.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-tunnel-source.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-filter-apply.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-combine.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-native-protocol-fd.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-echo-cancel.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-simple-protocol-tcp.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/librtp.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/libmain-volume-policy.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-ladspa-sink.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-sine.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-simple-protocol-unix.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-default-device-restore.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-bluetooth-discover.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-alsa-source.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-mmkbd-evdev.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-esound-compat-spawnfd.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-alsa-sink.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-switch-on-connect.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/libprotocol-http.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-tunnel-sink.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-rygel-media-server.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/libprotocol-simple.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-intended-roles.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-esound-protocol-tcp.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-card-restore.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-cli.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/libprotocol-cli.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/libprotocol-esound.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-console-kit.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-device-restore.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-cli-protocol-unix.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-virtual-sink.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-native-protocol-tcp.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-suspend-on-idle.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-null-sink.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-esound-sink.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-detect.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-rescue-streams.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-native-protocol-unix.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-position-event-sounds.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/libraop.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/libvolume-api.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-http-protocol-unix.so"
FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug/module-cli-protocol-tcp.so"
FILES_${PN}-dbg += "${prefix}/lib/pulseaudio/pulse/.debug/gconf-helper"

FILES_${PN} += "${prefix}/lib/pulseaudio/pulse/gconf-helper"
