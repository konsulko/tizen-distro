DESCRIPTION = "Multimedia Framework Common Library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Multimedia Framework/Libraries"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

PROVIDES = ""

#PROVIDES by libmm-common-dev 


#PROVIDES by libmm-common 


RDEPENDS = ""
#RDEPENDS of libmm-common-dev (${PN}-dev)
RDEPENDS_${PN}-dev += "libmm-common"


DEPENDS = ""
#DEPENDS of libmm-common 
DEPENDS += "libmm-log"
DEPENDS += "glib-2.0"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libmm-common.manifest .
 
 
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
 
 
 ./autogen.sh
 CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -DEXPORT_API=\"__attribute__((visibility(\\\"default\\\")))\" " 
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
 
 
 
}


libmm-common-dev_files = ""
libmm-common-dev_files += "libmm-common.manifest"
libmm-common-dev_files += "${prefix}/include/mmf/SLP_MultimediaFW_PG.h"
libmm-common-dev_files += "${prefix}/include/mmf/mm_types.h"
libmm-common-dev_files += "${prefix}/include/mmf/mm_error.h"
libmm-common-dev_files += "${prefix}/include/mmf/mm_message.h"
libmm-common-dev_files += "${prefix}/include/mmf/mm_attrs.h"
libmm-common-dev_files += "${prefix}/include/mmf/mm_attrs_private.h"
libmm-common-dev_files += "${prefix}/include/mmf/mm_debug.h"
libmm-common-dev_files += "${prefix}/include/mmf/mm.h"
libmm-common-dev_files += "${prefix}/lib/pkgconfig/mm-common.pc"
libmm-common-dev_files += "${prefix}/lib/libmmfcommon.so"

libmm-common_files = ""
libmm-common_files += "libmm-common.manifest"
libmm-common_files += "${prefix}/lib/libmmfcommon.so.*"

FILES_${PN}-dev = "${libmm-common-dev_files}"
FILES_${PN} = "${libmm-common_files}"

PKG_libmm-common-dev= "libmm-common-dev"
PKG_libmm-common= "libmm-common"

require libmm-common-extraconf.inc

