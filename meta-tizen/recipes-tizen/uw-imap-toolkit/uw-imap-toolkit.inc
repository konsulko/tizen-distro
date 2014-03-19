DESCRIPTION = "IMAP-2007e developed by University of Washington"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Messaging/Libraries"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libuw-imap-toolkit 
PROVIDES += "libuw-imap-toolkit"
RPROVIDES_libuw-imap-toolkit += "libuw-imap-toolkit"

#PROVIDES by uw-imap-toolkit 
PROVIDES += "uw-imap-toolkit"
RPROVIDES_uw-imap-toolkit += "uw-imap-toolkit"

#PROVIDES by libuw-imap-toolkit-devel 
PROVIDES += "libuw-imap-toolkit-devel"
RPROVIDES_libuw-imap-toolkit-devel += "libuw-imap-toolkit-devel"
RPROVIDES_libuw-imap-toolkit-devel += "libuw-imap-toolkit-dev"

RDEPENDS = ""
#RDEPENDS of uw-imap-toolkit (${PN})
RDEPENDS_${PN} += "/sbin/ldconfig"

#RDEPENDS of libuw-imap-toolkit-devel (lib${PN}-devel)
RDEPENDS_lib${PN}-devel += "libuw-imap-toolkit"


DEPENDS = ""
#DEPENDS of uw-imap-toolkit 
DEPENDS += "libgcrypt"
DEPENDS += "dlog"
DEPENDS += "openssl"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libuw-imap-toolkit.manifest ${S}/packaging/libuw-imap-toolkit-devel.manifest .
 
 
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
         --infodir=/usr/share/info --disable-static
 
 
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
PACKAGES += "libuw-imap-toolkit"
PACKAGES += "libuw-imap-toolkit-devel"

libuw-imap-toolkit_files = ""
libuw-imap-toolkit_files += "libuw-imap-toolkit.manifest"
libuw-imap-toolkit_files += "/usr/lib/libuw-imap-toolkit.so.*"

libuw-imap-toolkit-devel_files = ""
libuw-imap-toolkit-devel_files += "libuw-imap-toolkit-devel.manifest"
libuw-imap-toolkit-devel_files += "/usr/lib/libuw-imap-toolkit.so"
libuw-imap-toolkit-devel_files += "/usr/lib/pkgconfig/uw-imap-toolkit.pc"
libuw-imap-toolkit-devel_files += "/usr/include/uw-imap-toolkit/*"

FILES_lib${PN} = "${libuw-imap-toolkit_files}"
FILES_lib${PN}-devel = "${libuw-imap-toolkit-devel_files}"

PKG_libuw-imap-toolkit= "libuw-imap-toolkit"
PKG_libuw-imap-toolkit-devel= "libuw-imap-toolkit-devel"

require uw-imap-toolkit-extraconf.inc
