DESCRIPTION = "Utilities to uniformly interface desktop environments"
HOMEPAGE = "http://portland.freedesktop.org/"
SECTION = "System/GUI/Other"
LICENSE = "MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by xdg-utils 
PROVIDES += "xdg-utils"
RPROVIDES_xdg-utils += "xdg-utils"

#PROVIDES by xdg-utils-docs  
PROVIDES += "xdg-utils-docs "
RPROVIDES_xdg-utils-docs  += "xdg-utils-docs "

RDEPENDS = ""
#RDEPENDS of xdg-utils (${PN})
RDEPENDS_${PN} += "perl-Net-DBus"
RDEPENDS_${PN} += "perl-X11-Protocol"
RDEPENDS_${PN} += "perl"


DEPENDS = ""
#DEPENDS of xdg-utils 
DEPENDS += "xz"
DEPENDS += "make"
DEPENDS += "xmlto"
DEPENDS += "links"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n xdg-utils-20120310
 cp ${S}/packaging/xdg-utils.manifest .
 
 
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
         --target=noarch-tizen-linux \
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
 (cd scripts; make scripts-clean; make scripts)
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
 
 
 
 
}

PACKAGES = ""
PACKAGES += "xdg-utils"
PACKAGES += "xdg-utils-docs"

xdg-utils_files = ""
xdg-utils_files += "xdg-utils.manifest"
xdg-utils_files += "LICENSE"
xdg-utils_files += "/usr/bin/xdg-desktop-icon"
xdg-utils_files += "/usr/bin/xdg-desktop-menu"
xdg-utils_files += "/usr/bin/xdg-email"
xdg-utils_files += "/usr/bin/xdg-icon-resource"
xdg-utils_files += "/usr/bin/xdg-mime"
xdg-utils_files += "/usr/bin/xdg-open"
xdg-utils_files += "/usr/bin/xdg-su"
xdg-utils_files += "/usr/bin/xdg-screensaver"
xdg-utils_files += "/usr/bin/xdg-settings"
xdg-utils_files += "/usr/bin/xdg-terminal"

xdg-utils-docs_files = ""
xdg-utils-docs_files += "/usr/share/info"
xdg-utils-docs_files += "/usr/share/man"

FILES_${PN} = "${xdg-utils_files}"
FILES_${PN}-docs = "${xdg-utils-docs_files}"

PKG_xdg-utils= "xdg-utils"
PKG_xdg-utils-docs= "xdg-utils-docs"

require xdg-utils-extraconf.inc
