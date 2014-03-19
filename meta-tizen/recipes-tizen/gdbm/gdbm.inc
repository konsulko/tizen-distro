DESCRIPTION = "GNU dbm key/data database"
HOMEPAGE = "http://directory.fsf.org/GNU/gdbm.html"
SECTION = "System/Libraries"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libgdbm 
PROVIDES += "libgdbm"
RPROVIDES_libgdbm += "libgdbm"
# the PROVIDES rules is ignore "gdbm = 1.10-0"
PROVIDES += "gdbm"
RPROVIDES_libgdbm += "gdbm"

#PROVIDES by gdbm 
PROVIDES += "gdbm"
RPROVIDES_gdbm += "gdbm"

#PROVIDES by gdbm-devel 
PROVIDES += "gdbm-devel"
RPROVIDES_gdbm-devel += "gdbm-devel"
RPROVIDES_gdbm-devel += "gdbm-dev"
# the PROVIDES rules is ignore "gdbm:/usr/lib/libgdbm.so  "
PROVIDES += "gdbm:/usr/lib/libgdbm.so"
RPROVIDES_gdbm-devel += "gdbm:/usr/lib/libgdbm.so"

RDEPENDS = ""
#RDEPENDS of gdbm-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "gdbm"


DEPENDS = ""
#DEPENDS of gdbm 
DEPENDS += "libtool-cross"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/gdbm.manifest .
 
 
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
 
 export CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -Wa,--noexecstack"
 
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
         --infodir=/usr/share/info --enable-libgdbm-compat --disable-nls
 make -j16;
 
 
 
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
   
 echo "/* GNU ld script
    Use the shared library, but some functions are only in
    the static library, so try that secondarily.  */
 GROUP ( /usr/lib/libgdbm.so /usr/lib/libgdbm_compat.so )" > ${D}//usr/lib/libndbm.so
 echo "/* GNU ld script
    Use the shared library, but some functions are only in
    the static library, so try that secondarily.  */
 GROUP ( /usr/lib/libgdbm.a /usr/lib/libgdbm_compat.a )" > ${D}//usr/lib/libndbm.a
 
 
}

PACKAGES = ""
PACKAGES += "libgdbm"
PACKAGES += "gdbm-devel"

libgdbm_files = ""
libgdbm_files += "gdbm.manifest"
libgdbm_files += "COPYING"
libgdbm_files += "/usr/lib/libgdbm.so.4"
libgdbm_files += "/usr/lib/libgdbm.so.4.0.0"
libgdbm_files += "/usr/lib/libgdbm_compat.so.4"
libgdbm_files += "/usr/lib/libgdbm_compat.so.4.0.0"

gdbm-devel_files = ""
gdbm-devel_files += "gdbm.manifest"
gdbm-devel_files += "/usr/bin/testgdbm"
gdbm-devel_files += "/usr/include/dbm.h"
gdbm-devel_files += "/usr/include/gdbm.h"
gdbm-devel_files += "/usr/include/ndbm.h"
gdbm-devel_files += "/usr/share/info/gdbm.info.gz"
gdbm-devel_files += "/usr/lib/libgdbm.a"
gdbm-devel_files += "/usr/lib/libgdbm.so"
gdbm-devel_files += "/usr/lib/libgdbm_compat.a"
gdbm-devel_files += "/usr/lib/libgdbm_compat.so"
gdbm-devel_files += "/usr/lib/libndbm.a"
gdbm-devel_files += "/usr/lib/libndbm.so"
gdbm-devel_files += "/usr/share/man/man3/gdbm.3.gz"

FILES_lib${PN} = "${libgdbm_files}"
FILES_${PN}-devel = "${gdbm-devel_files}"

PKG_libgdbm= "libgdbm"
PKG_gdbm-devel= "gdbm-devel"

require gdbm-extraconf.inc
