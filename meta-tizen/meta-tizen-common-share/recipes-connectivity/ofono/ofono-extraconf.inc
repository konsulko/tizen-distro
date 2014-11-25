do_install() {
 export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D}
 mkdir -p ${D}
 
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=${prefix}/bin \
   install  
   rm -f ${D}${infodir}/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 mkdir -p ${D}/${systemd_unitdir}/system/network.target.wants
 ln -s ../ofono.service ${D}/${systemd_unitdir}/system/network.target.wants/ofono.service
 mkdir -p ${D}/${systemd_unitdir}/system/multi-user.target.wants 
 ln -s ../ofono.service  ${D}/${systemd_unitdir}/system/multi-user.target.wants/ofono.service  
 
 
 
}