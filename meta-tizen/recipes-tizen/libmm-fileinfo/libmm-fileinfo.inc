DESCRIPTION = "Media Fileinfo"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "Apache License 2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by libmm-fileinfo


#PROVIDES by libmm-fileinfo-dev


RDEPENDS = ""
#RDEPENDS of libmm-fileinfo-dev (${PN}-dev)
RDEPENDS_${PN}-dev += "libmm-fileinfo"


DEPENDS = ""
#DEPENDS of libmm-fileinfo
DEPENDS += "libmm-log"
DEPENDS += "libav"
DEPENDS += "libmm-common"
DEPENDS += "glib-2.0"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libmm-fileinfo.manifest .


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

 CFLAGS="${CFLAGS} -D_MM_PROJECT_FLOATER -DEXPORT_API=\"__attribute__((visibility(\\\"default\\\")))\" "
 export CFLAGS



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
         --infodir=${infodir}.sh


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
         --infodir=${infodir} --disable-testmode --disable-dump --enable-dyn --disable-iommap  --disable-drm --disable-gtk

 make



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
 mkdir -p ${D}/${prefix}/share/license
 cp -rf ${WORKDIR}/libmm-fileinfo-0.6.0/LICENSE.APLv2.0 ${D}/${prefix}/share/license/libmm-fileinfo



}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    ldconfig
}

pkg_postrm_${PN}() {
    #!/bin/sh -e

    ldconfig
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " libmm-fileinfo "
PACKAGES += " libmm-fileinfo-dev "

libmm-fileinfo_files = ""
libmm-fileinfo_files += "libmm-fileinfo.manifest"
libmm-fileinfo_files += "${prefix}/bin/memtrace_reader"
libmm-fileinfo_files += "${prefix}/bin/mm_file_test"
libmm-fileinfo_files += "${prefix}/lib/libmmffile.so.*"
libmm-fileinfo_files += "${prefix}/lib/libmmfile_codecs.so.*"
libmm-fileinfo_files += "${prefix}/lib/libmmfile_formats.so.*"
libmm-fileinfo_files += "${prefix}/lib/libmmfile_utils.so.*"
libmm-fileinfo_files += "${prefix}/lib/libmmffile.so"
libmm-fileinfo_files += "${prefix}/lib/libmmfile_codecs.so"
libmm-fileinfo_files += "${prefix}/lib/libmmfile_formats.so"
libmm-fileinfo_files += "${prefix}/lib/libmmfile_utils.so"
libmm-fileinfo_files += "${prefix}/share/license/libmm-fileinfo"

libmm-fileinfo-dev_files = ""
libmm-fileinfo-dev_files += "libmm-fileinfo.manifest"
libmm-fileinfo-dev_files += "${prefix}/include/mmf/mm_file.h"
libmm-fileinfo-dev_files += "${prefix}/lib/pkgconfig/mm-fileinfo.pc"

FILES_${PN} = "${libmm-fileinfo_files}"
FILES_${PN}-dev = "${libmm-fileinfo-dev_files}"

PKG_libmm-fileinfo= "libmm-fileinfo"
PKG_libmm-fileinfo-dev= "libmm-fileinfo-dev"

require libmm-fileinfo-extraconf.inc

