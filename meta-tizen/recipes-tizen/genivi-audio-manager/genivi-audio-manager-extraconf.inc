inherit pkgconfig cmake

INSANE_SKIP_${PN} = "dev-so"

EXTRA_OECMAKE += " \
                    -DUSE_BUILD_LIBS=OFF \
                    -DWITH_TESTS=OFF \
                    -DWITH_DBUS_WRAPPER=ON \
                    -DWITH_NSM=OFF \
                    -DCMAKE_INSTALL_PREFIX=/usr \
                    "

cmake_do_install_append() {

    export RPM_BUILD_ROOT=${D}

    rm -f ${D}${infodir}/dir

    find ${D} -regex ".*\.la$" | xargs rm -f --
    find ${D} -regex ".*\.a$" | xargs rm -f -- DESTDIR=$RPM_BUILD_ROOT

    mkdir $RPM_BUILD_ROOT${prefix}/include/genivi-audio-manager
    mv $RPM_BUILD_ROOT${prefix}/include/*.h $RPM_BUILD_ROOT${prefix}/include/command $RPM_BUILD_ROOT${prefix}/include/control $RPM_BUILD_ROOT${prefix}/include/routing $RPM_BUILD_ROOT${prefix}/include/shared $RPM_BUILD_ROOT${prefix}/include/genivi-audio-manager
    rm $RPM_BUILD_ROOT${prefix}/lib/audioManager/routing/libPluginRoutingInterfaceAsync.so*
}

FILES_${PN}-dbg += "${prefix}/lib/audioManager/command/.debug"
FILES_${PN}-dbg += "${prefix}/lib/audioManager/control/.debug"
FILES_${PN}-dbg += "${prefix}/lib/audioManager/routing/.debug"