DESCRIPTION = "EFI Kernel loader"
HOMEPAGE = "http://cgit.freedesktop.org/gummiboot/"
SECTION = "Base/Startup"
LICENSE = "LGPL-2.1"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by gummiboot-splash 
PROVIDES += "gummiboot-splash"
RPROVIDES_gummiboot-splash += "gummiboot-splash"

#PROVIDES by gummiboot 
PROVIDES += "gummiboot"
RPROVIDES_gummiboot += "gummiboot"

RDEPENDS = ""
#RDEPENDS of gummiboot-splash (${PN}-splash)
RDEPENDS_${PN}-splash += "gummiboot"


DEPENDS = ""
#DEPENDS of gummiboot 
DEPENDS += "gnu-efi"
DEPENDS += "pkgconfig(blkid)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n gummiboot-43
 
 
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
 
 cp ${S}/packaging/gummiboot.manifest .
 
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
         --infodir=/usr/share/info --with-efi-libdir=/usr/lib --with-efi-ldsdir=/usr/lib
 make
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 rm -fr ${D}
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 mkdir -p ${D}//usr/share/gummiboot
 cp test/splash.bmp ${D}//usr/share/gummiboot
 
 
}

PACKAGES = ""
PACKAGES += "gummiboot-splash"
PACKAGES += "gummiboot"

gummiboot-splash_files = ""
gummiboot-splash_files += "/usr/share/gummiboot/splash.bmp"

gummiboot_files = ""
gummiboot_files += "gummiboot.manifest"
gummiboot_files += "gummiboot.manifest"
gummiboot_files += "/usr/bin/gummiboot"
gummiboot_files += "/usr/lib/gummiboot/gummibootx64.efi"

FILES_${PN}-splash = "${gummiboot-splash_files}"
FILES_${PN} = "${gummiboot_files}"

PKG_gummiboot-splash= "gummiboot-splash"
PKG_gummiboot= "gummiboot"

require gummiboot-extraconf.inc
