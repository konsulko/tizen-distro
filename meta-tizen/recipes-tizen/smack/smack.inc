DESCRIPTION = "Selection of tools for developers working with Smack"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Security/Access Control"
LICENSE = "LGPL-2.1"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by smack-dev


#PROVIDES by smack


#PROVIDES by libsmack


#PROVIDES by smack-docs


RDEPENDS = ""
#RDEPENDS of smack-dev (${PN}-dev)
RDEPENDS_${PN}-dev += "libsmack"


DEPENDS = ""
#DEPENDS of smack
DEPENDS_append_class-native = " autoconf-native"
DEPENDS_append_class-target = " autoconf-native"
DEPENDS_append_class-native = " libtool"
DEPENDS_append_class-target = " libtool-cross"
DEPENDS_append_class-native = " automake-native"
DEPENDS_append_class-target = " automake-native"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/smack.manifest .
 
 
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
         --infodir=${infodir} --with-systemdsystemunitdir=/lib/systemd/system
 
 make ${PARALLEL_MAKE}
 
 
 
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
 install -d ${D}${sysconfdir}/smack/accesses.d
 install -d ${D}${sysconfdir}/smack/cipso.d
 install -d ${D}${sysconfdir}/smack/netlabel.d
 
 
}

pkg_postinst_libsmack() {
    #!/bin/sh -e

    [ "x\$D" == "x" ] && ldconfig
}

pkg_postrm_libsmack() {
    #!/bin/sh -e

    [ "x\$D" == "x" ] && ldconfig
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " smack-dev "
PACKAGES += " smack "
PACKAGES += " libsmack "
PACKAGES += " smack-docs "

smack-dev_files = ""
smack-dev_files += "smack.manifest"
smack-dev_files += "${prefix}/include/sys/smack.h"
smack-dev_files += "${prefix}/lib/libsmack.so"
smack-dev_files += "${prefix}/lib/pkgconfig/libsmack.pc"

smack_files = ""
smack_files += "smack.manifest"
smack_files += "${sysconfdir}/smack"
smack_files += "${sysconfdir}/smack/accesses.d"
smack_files += "${sysconfdir}/smack/cipso.d"
smack_files += "${sysconfdir}/smack/netlabel.d"
smack_files += "${prefix}/bin/*"

libsmack_files = ""
libsmack_files += "smack.manifest"
libsmack_files += "${prefix}/lib/libsmack.so.*"

smack-docs_files = ""

FILES_${PN}-dev = "${smack-dev_files}"
FILES_${PN} = "${smack_files}"
FILES_lib${PN} = "${libsmack_files}"
FILES_${PN}-docs = "${smack-docs_files}"

PKG_smack-dev= "smack-dev"
PKG_smack= "smack"
PKG_libsmack= "libsmack"
PKG_smack-docs= "smack-docs"

require smack-extraconf.inc

