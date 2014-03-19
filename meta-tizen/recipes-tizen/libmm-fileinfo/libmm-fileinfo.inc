DESCRIPTION = "Media Fileinfo"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "Apache License, Version 2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libmm-fileinfo 
PROVIDES += "libmm-fileinfo"
RPROVIDES_libmm-fileinfo += "libmm-fileinfo"

#PROVIDES by libmm-fileinfo-devel 
PROVIDES += "libmm-fileinfo-devel"
RPROVIDES_libmm-fileinfo-devel += "libmm-fileinfo-devel"
RPROVIDES_libmm-fileinfo-devel += "libmm-fileinfo-dev"

RDEPENDS = ""
#RDEPENDS of libmm-fileinfo-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libmm-fileinfo"


DEPENDS = ""
#DEPENDS of libmm-fileinfo 
DEPENDS += "pkgconfig(mm-log)"
DEPENDS += "libmm-common"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "libav"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libmm-fileinfo.manifest .
 
 
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
 
 CFLAGS="${CFLAGS} -D_MM_PROJECT_FLOATER -DEXPORT_API=\"__attribute__((visibility(\\\"default\\\")))\" "
 export CFLAGS
 
 
   CFLAGS="${CFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CFLAGS ; 
   CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
   FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -I%_fmoddir}" ; export FFLAGS ; 
   ./autogen.sh --build=${TARGET_SYS} --host=${HOST_SYS} \
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
         --infodir=/usr/share/info.sh
 
 
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
         --infodir=/usr/share/info --disable-testmode --disable-dump --enable-dyn --disable-iommap  --disable-drm --disable-gtk         
 
 make
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 mkdir -p ${D}//usr/share/license
 cp -rf ${WORKDIR}/libmm-fileinfo-0.6.0/LICENSE.APLv2.0 ${D}//usr/share/license/libmm-fileinfo
 
 
 
}

PACKAGES = ""
PACKAGES += "libmm-fileinfo"
PACKAGES += "libmm-fileinfo-devel"

libmm-fileinfo_files = ""
libmm-fileinfo_files += "libmm-fileinfo.manifest"
libmm-fileinfo_files += "/usr/bin/memtrace_reader"
libmm-fileinfo_files += "/usr/bin/mm_file_test"
libmm-fileinfo_files += "/usr/lib/libmmffile.so.*"
libmm-fileinfo_files += "/usr/lib/libmmfile_codecs.so.*"
libmm-fileinfo_files += "/usr/lib/libmmfile_formats.so.*"
libmm-fileinfo_files += "/usr/lib/libmmfile_utils.so.*"
libmm-fileinfo_files += "/usr/lib/libmmffile.so"
libmm-fileinfo_files += "/usr/lib/libmmfile_codecs.so"
libmm-fileinfo_files += "/usr/lib/libmmfile_formats.so"
libmm-fileinfo_files += "/usr/lib/libmmfile_utils.so"
libmm-fileinfo_files += "/usr/share/license/libmm-fileinfo"

libmm-fileinfo-devel_files = ""
libmm-fileinfo-devel_files += "libmm-fileinfo.manifest"
libmm-fileinfo-devel_files += "/usr/include/mmf/mm_file.h"
libmm-fileinfo-devel_files += "/usr/lib/pkgconfig/mm-fileinfo.pc"

FILES_${PN} = "${libmm-fileinfo_files}"
FILES_${PN}-devel = "${libmm-fileinfo-devel_files}"

PKG_libmm-fileinfo= "libmm-fileinfo"
PKG_libmm-fileinfo-devel= "libmm-fileinfo-devel"

require libmm-fileinfo-extraconf.inc
