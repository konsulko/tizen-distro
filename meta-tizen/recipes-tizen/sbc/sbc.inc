DESCRIPTION = "Bluetooth SBC Utilities"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Multimedia/Utilities"
LICENSE = "GPL-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by sbc 
PROVIDES += "sbc"
RPROVIDES_sbc += "sbc"

#PROVIDES by sbc-devel 
PROVIDES += "sbc-devel"
RPROVIDES_sbc-devel += "sbc-devel"
RPROVIDES_sbc-devel += "sbc-dev"

RDEPENDS = ""
#RDEPENDS of sbc-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "sbc"
RDEPENDS_${PN}-devel += "pkgconfig"


DEPENDS = ""
#DEPENDS of sbc 
DEPENDS += "pkgconfig(sndfile)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 
 
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
         --infodir=/usr/share/info --enable-shared --disable-static --prefix=/usr
 make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 make install DESTDIR=${D}
 rm -rf ${D}/usr/lib/*.la
 
 
}

PACKAGES = ""
PACKAGES += "sbc"
PACKAGES += "sbc-devel"

sbc_files = ""
sbc_files += "/usr/bin/sbcinfo"
sbc_files += "/usr/bin/sbcdec"
sbc_files += "/usr/bin/sbcenc"
sbc_files += "/usr/lib/libsbc.so.*"

sbc-devel_files = ""
sbc-devel_files += "/usr/include/sbc/*"
sbc-devel_files += "/usr/lib/libsbc.so"
sbc-devel_files += "/usr/lib/pkgconfig/sbc.pc"

FILES_${PN} = "${sbc_files}"
FILES_${PN}-devel = "${sbc-devel_files}"

PKG_sbc= "sbc"
PKG_sbc-devel= "sbc-devel"

require sbc-extraconf.inc
