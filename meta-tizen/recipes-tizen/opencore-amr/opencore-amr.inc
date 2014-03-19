DESCRIPTION = "opencore AMRNB dev package"
HOMEPAGE = "http://nohomepage.org"
SECTION = "libdevel"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by opencore-amr-devel 
PROVIDES += "opencore-amr-devel"
RPROVIDES_opencore-amr-devel += "opencore-amr-devel"
RPROVIDES_opencore-amr-devel += "opencore-amr-dev"

#PROVIDES by opencore-amr 
PROVIDES += "opencore-amr"
RPROVIDES_opencore-amr += "opencore-amr"

RDEPENDS = ""
#RDEPENDS of opencore-amr-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "opencore-amr"


DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/opencore-amr.manifest .
 
 
}

do_configure() {
}

do_compile() {
 LANG=C
 export LANG
 unset DISPLAY
 CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables" ; export CFLAGS ; 
 CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
 FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -I%_fmoddir}" ; export FFLAGS ; 
 LD_AS_NEEDED=1; export LD_AS_NEEDED ; 
 
 ./autogen.sh
 
   CFLAGS="${CFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CFLAGS ; 
   CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
   FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -I%_fmoddir}" ; export FFLAGS ; 
   autotools_do_configure --build=${TARGET_SYS} --host=${HOST_SYS} \
         --target=x86_64-tizen-linux \
         --program-prefix= \
         --prefix=/usr \
         --exec-prefix=/usr \
         --bindir=/usr/bin \
         --sbindir=/usr/sbin \
         --sysconfdir=/etc \
         --datadir=/usr/share \
         --includedir=/usr/include \
         --libdir=/usr/lib \
         --libexecdir=/usr/libexec \
         --localstatedir=/var \
         --sharedstatedir=/usr/com \
         --mandir=/usr/share/man \
         --infodir=/usr/share/info
 make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 rm -rf ${D}
 mkdir -p ${D}/usr/share/license
 cp LICENSE ${D}/usr/share/license/opencore-amr
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 
}

PACKAGES = ""
PACKAGES += "opencore-amr-devel"
PACKAGES += "opencore-amr"

opencore-amr-devel_files = ""
opencore-amr-devel_files += "opencore-amr.manifest"
opencore-amr-devel_files += "/usr/include/opencore-amrnb/*.h"
opencore-amr-devel_files += "/usr/include/opencore-amrwb/*.h"
opencore-amr-devel_files += "/usr/lib/libopencore-amrnb.so"
opencore-amr-devel_files += "/usr/lib/libopencore-amrwb.so"
opencore-amr-devel_files += "/usr/lib/pkgconfig/opencore-amrnb.pc"
opencore-amr-devel_files += "/usr/lib/pkgconfig/opencore-amrwb.pc"

opencore-amr_files = ""
opencore-amr_files += "opencore-amr.manifest"
opencore-amr_files += "/usr/lib/libopencore-amrnb.so.0"
opencore-amr_files += "/usr/lib/libopencore-amrnb.so.0.0.2"
opencore-amr_files += "/usr/lib/libopencore-amrwb.so.0"
opencore-amr_files += "/usr/lib/libopencore-amrwb.so.0.0.2"
opencore-amr_files += "/usr/share/license/opencore-amr"

FILES_${PN}-devel = "${opencore-amr-devel_files}"
FILES_${PN} = "${opencore-amr_files}"

PKG_opencore-amr-devel= "opencore-amr-devel"
PKG_opencore-amr= "opencore-amr"

require opencore-amr-extraconf.inc
