DESCRIPTION = "File manager service server."
HOMEPAGE = "http://nohomepage.org"
SECTION = "Multimedia/Service"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by libmedia-utils-dev


#PROVIDES by media-server


#PROVIDES by libmedia-utils


RDEPENDS = ""
#RDEPENDS of libmedia-utils-dev (libmedia-utils-dev)
RDEPENDS_libmedia-utils-dev += "libtzplatform-config-dev"
RDEPENDS_libmedia-utils-dev += "libmedia-utils"

#RDEPENDS of media-server (${PN})
RDEPENDS_${PN} += "vconf"

#RDEPENDS of libmedia-utils (libmedia-utils)
RDEPENDS_libmedia-utils += "media-server"


DEPENDS = ""
#DEPENDS of media-server
DEPENDS += "drm-client"
DEPENDS += "notification"
DEPENDS += "dbus"
DEPENDS += "tizen-platform-config"
DEPENDS += "aul"
DEPENDS += "dlog"
DEPENDS += "glib-2.0"
DEPENDS += "heynoti"
DEPENDS += "sqlite3"
DEPENDS += "libslp-pm"
DEPENDS += "vconf"
DEPENDS += "libslp-db-util"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/media-server.manifest ${S}/packaging/libmedia-utils.manifest ${S}/packaging/libmedia-utils-devel.manifest .
 
 
}
do_patch_append() {
    bb.build.exec_func('do_prep', d)
}

do_configure() {
}

do_compile() {
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables" ; export CFLAGS ;
 CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ;
 FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -I%_fmoddir}" ; export FFLAGS ;
 LD_AS_NEEDED=1; export LD_AS_NEEDED ;
 
 
 
   
   CFLAGS="${CFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CFLAGS ; 
   CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
   FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -I%_fmoddir}" ; export FFLAGS ; 
   autotools_do_configure --build=${TARGET_SYS} --host=${HOST_SYS} \
         --target=x86_64-tizen-linux \
         --program-prefix= \
         --prefix=${prefix} \
         --exec-prefix=${prefix} \
         --bindir=${prefix}/bin \
         --sbindir=${prefix}/sbin \
         --sysconfdir=${sysconfdir} \
         --datadir=${prefix}/share \
         --includedir=${prefix}/include \
         --libdir=${prefix}/lib \
         --libexecdir=${prefix}/libexec \
         --localstatedir=${localstatedir} \
         --sharedstatedir=${prefix}/com \
         --mandir=${mandir} \
         --infodir=${infodir}
 
   CFLAGS="${CFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CFLAGS ; 
   CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
   FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -I%_fmoddir}" ; export FFLAGS ; 
   autotools_do_configure --build=${TARGET_SYS} --host=${HOST_SYS} \
         --target=x86_64-tizen-linux \
         --program-prefix= \
         --prefix=${prefix} \
         --exec-prefix=${prefix} \
         --bindir=${prefix}/bin \
         --sbindir=${prefix}/sbin \
         --sysconfdir=${sysconfdir} \
         --datadir=${prefix}/share \
         --includedir=${prefix}/include \
         --libdir=${prefix}/lib \
         --libexecdir=${prefix}/libexec \
         --localstatedir=${localstatedir} \
         --sharedstatedir=${prefix}/com \
         --mandir=${mandir} \
         --infodir=${infodir} --prefix=${prefix} --disable-static
 
 make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
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
 
 mkdir -p ${D}/usr/lib/systemd/system/multi-user.target.wants
 install -m 644 ${S}/packaging/media-server.service ${D}/usr/lib/systemd/system/media-server.service
 ln -s ../media-server.service ${D}/usr/lib/systemd/system/multi-user.target.wants/media-server.service
 mkdir -p ${D}${prefix}/data/data-media/Camera
 mkdir -p ${D}${prefix}/data/data-media/Downloads
 mkdir -p ${D}${prefix}/data/data-media/Images
 mkdir -p ${D}${prefix}/data/data-media/Sounds/Voice\ recorder
 mkdir -p ${D}${prefix}/data/data-media/Videos
 mkdir -p ${D}${prefix}/data/data-media/file-manager-service/.thumb/mmc
 mkdir -p ${D}${prefix}/data/data-media/file-manager-service/.thumb/phone
 install -m 0775 ./data-media/Images/* ${D}${prefix}/data/data-media/Images/
 install -m 0775 ./data-media/dbspace/file-manager-service/.thumb/thumb_default.png ${D}${prefix}/data/data-media/file-manager-service/.thumb/
 install -D -m 0775 ./data-media/dbspace/file-manager-service/.thumb/mmc/* ${D}${prefix}/data/data-media/file-manager-service/.thumb/mmc/
 install -m 0775 ./data-media/dbspace/file-manager-service/.thumb/phone/PHONE_THUMB_HERE ${D}${prefix}/data/data-media/file-manager-service/.thumb/phone/
 install -m 0775 ./data-media/dbspace/file-manager-service/.thumb/phone/.jpg* ${D}${prefix}/data/data-media/file-manager-service/.thumb/phone/
 install -D -m 0775 ./data-media/dbspace/file-manager-service/* ${D}${prefix}/data/data-media/file-manager-service/
 install -m 0775 ${S}/packaging/media-data-sdk_create_db.sh ${D}${prefix}/bin/media-data-sdk_create_db.sh
 
 
}

pkg_postinst_libmedia-utils() {
    #!/bin/sh -e

    [ "x\$D" == "x" ] && ldconfig
}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    vconftool set -t int db/filemanager/dbupdate "1" -f
    vconftool set -t int memory/filemanager/Mmc "0" -i -f
    vconftool set -t string db/private/mediaserver/mmc_info "" -f
    vconftool set -t int file/private/mediaserver/scan_internal "1" -f
    vconftool set -t int file/private/mediaserver/scan_directory "1" -f
    chgrp users $D${prefix}/bin/media-data-sdk_create_db.sh
    chgrp -R users $D${prefix}/data/data-media

}

pkg_postrm_libmedia-utils() {
    #!/bin/sh -e

    [ "x\$D" == "x" ] && ldconfig
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " libmedia-utils-dev "
PACKAGES += " media-server "
PACKAGES += " libmedia-utils "

libmedia-utils-dev_files = ""
libmedia-utils-dev_files += "libmedia-utils-devel.manifest"
libmedia-utils-dev_files += "${prefix}/lib/libmedia-utils.so"
libmedia-utils-dev_files += "${prefix}/lib/pkgconfig/libmedia-utils.pc"
libmedia-utils-dev_files += "${prefix}/include/media-utils/*.h"

media-server_files = ""
media-server_files += "media-server.manifest"
media-server_files += "${prefix}/bin/media-server"
media-server_files += "${prefix}/bin/media-scanner"
media-server_files += "${prefix}/bin/mediadb-update"
media-server_files += "/usr/lib/systemd/system/media-server.service"
media-server_files += "/usr/lib/systemd/system/multi-user.target.wants/media-server.service"
media-server_files += "${prefix}/bin/media-data-sdk_create_db.sh"
media-server_files += "${prefix}/data/data-media/*"
media-server_files += "${prefix}/data/data-media/file-manager-service/.thumb/*"

libmedia-utils_files = ""
libmedia-utils_files += "libmedia-utils.manifest"
libmedia-utils_files += "${prefix}/lib/libmedia-utils.so.0"
libmedia-utils_files += "${prefix}/lib/libmedia-utils.so.0.0.0"

FILES_libmedia-utils-dev = "${libmedia-utils-dev_files}"
FILES_${PN} = "${media-server_files}"
FILES_libmedia-utils = "${libmedia-utils_files}"

PKG_libmedia-utils-dev= "libmedia-utils-dev"
PKG_media-server= "media-server"
PKG_libmedia-utils= "libmedia-utils"

require media-server-extraconf.inc

