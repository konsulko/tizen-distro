inherit gettext pkgconfig

RPROVIDES_libpulse += "libpulsecommon"

DEPENDS_remove = "tdb"

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
                --enable-samsung-policy \
                --with-udev-rules-dir=${prefix}/lib/udev/rules.d \
                --with-system-user=pulse \
                --with-system-group=pulse \
                --with-access-group=pulse-access \
                "
EXTRA_OECONF += "--host=${HOST_SYS}"

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

FILES_${PN}-dbg += "${prefix}/lib/pulse-5.0/modules/.debug"
FILES_${PN}-dbg += "${prefix}/lib/pulseaudio/pulse/.debug"

FILES_${PN} += "${prefix}/lib/pulseaudio/pulse/gconf-helper"
