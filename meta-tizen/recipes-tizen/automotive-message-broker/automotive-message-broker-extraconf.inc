inherit pkgconfig cmake

B="${S}"

INSANE_SKIP_${PN} = "dev-so"

EXTRA_OECMAKE = " \
                -DCMAKE_VERBOSE_MAKEFILE=ON \
                -DCMAKE_INSTALL_PREFIX:PATH=${prefix} \
                -DCMAKE_INSTALL_LIBDIR:PATH=${prefix}/lib \
                -DINCLUDE_INSTALL_DIR:PATH=${prefix}/include \
                -DLIB_INSTALL_DIR:PATH=${prefix}/lib \
                -DSYSCONF_INSTALL_DIR:PATH=${sysconfdir} \
                -DSHARE_INSTALL_PREFIX:PATH=${prefix}/share \
                -DCMAKE_SKIP_RPATH:BOOL=ON \
                -DBUILD_SHARED_LIBS:BOOL=ON \
                -Ddatabase_plugin=ON \
                -Dmurphy_plugin=ON \
                -Dobd2_plugin=ON \
                -Dtest_plugin=ON \
                -Dgpsnmea_plugin=ON \
                -Dcangen_plugin=ON \
                -Dcansim_plugin=ON \
                -Denable_icecc=OFF \
                "

cmake_do_configure_prepend() {
    # Add pthread library to target_link_libraries
    sed -i 's@set(link_libraries -lamb ${libtool_LIBRARY} ${glib_LIBRARIES} ${json_LIBRARIES} -L${CMAKE_CURRENT_BINARY_DIR}/lib)@set(link_libraries -lamb ${libtool_LIBRARY} ${glib_LIBRARIES} ${json_LIBRARIES} -lpthread -L${CMAKE_CURRENT_BINARY_DIR}/lib)@' ${S}/CMakeLists.txt
}

cmake_do_install_append() {

    rm -f ${D}${infodir}/dir 
    find ${D} -regex ".*\.la$" | xargs rm -f -- 
    find ${D} -regex ".*\.a$" | xargs rm -f --
 
    mkdir -p ${D}/lib/systemd/system/network.target.wants
    cp packaging.in/ambd.service.systemd.tizen ${D}/lib/systemd/system/ambd.service
    ln -sf ../ambd.service ${D}/lib/systemd/system/network.target.wants/ambd.service
 
    mkdir -p ${D}/lib/systemd/system/multi-user.target.wants 
    ln -sf ../ambd.service  ${D}/lib/systemd/system/multi-user.target.wants/ambd.service  
 
    cp packaging.in/config.tizen ${D}${sysconfdir}/ambd/
}
