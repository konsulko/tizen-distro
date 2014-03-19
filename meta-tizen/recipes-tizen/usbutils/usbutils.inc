DESCRIPTION = "Linux USB utilities"
HOMEPAGE = "http://www.linux-usb.org/"
SECTION = "Base/Device Management"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by usbutils 
PROVIDES += "usbutils"
RPROVIDES_usbutils += "usbutils"

#PROVIDES by usbutils-docs  
PROVIDES += "usbutils-docs "
RPROVIDES_usbutils-docs  += "usbutils-docs "

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of usbutils 
DEPENDS += "autoconf-native"
DEPENDS += "libtool-cross"
DEPENDS += "pkgconfig(libusb-1.0)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/usbutils.manifest .
 
 
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
         --infodir=/usr/share/info \
 	--datadir=/usr/share/hwdata \
     --disable-usbids
 
 make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 make install DESTDIR=${D} pkgconfigdir=/usr/share/pkgconfig
 
 
 
}

PACKAGES = ""
PACKAGES += "usbutils"
PACKAGES += "usbutils-docs"

usbutils_files = ""
usbutils_files += "usbutils.manifest"
usbutils_files += "/usr/bin/*"
usbutils_files += "/usr/share/*"

usbutils-docs_files = ""
usbutils-docs_files += "/usr/share/info"
usbutils-docs_files += "/usr/share/man"

FILES_${PN} = "${usbutils_files}"
FILES_${PN}-docs = "${usbutils-docs_files}"

PKG_usbutils= "usbutils"
PKG_usbutils-docs= "usbutils-docs"

require usbutils-extraconf.inc
