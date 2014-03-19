DESCRIPTION = "Utilities for Manipulating Desktop Files"
HOMEPAGE = "http://www.freedesktop.org/wiki/Software/desktop-file-utils"
SECTION = "Development/Tools/Other"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by desktop-file-utils 
PROVIDES += "desktop-file-utils"
RPROVIDES_desktop-file-utils += "desktop-file-utils"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of desktop-file-utils 
DEPENDS += "xz"
DEPENDS += "glib2-devel"
DEPENDS += "pkgconfig-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/desktop-file-utils.manifest .
 
 
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
         --with-lispdir=/usr/share/emacs/site-lisp
 oe_runmake -j16
 
 
 
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
         BINDIR=/usr/bin \
         prefix=/usr \
         exec_prefix=/usr \
         bindir=/usr/bin \
         sbindir=/usr/sbin \
         sysconfdir=/etc \
         datadir=/usr/share \
         includedir=/usr/include \
         libdir=/usr/lib \
         libexecdir=/usr/libexec \
         localstatedir=}/var \
         sharedstatedir=/usr/com \
         mandir=/usr/share/man \
         infodir=/usr/share/info \
   install
 # we don't want to buildrequire emacs, but recent automake make it
 # impossible to install a lisp file without emacs installed. So we
 # manually do it.
 test ! -f ${D}/usr/share/emacs/site-lisp/desktop-entry-mode.el
 install -D -m644 misc/desktop-entry-mode.el ${D}/usr/share/emacs/site-lisp/desktop-entry-mode.el
 # Install rpm macros
 install -D -m644 ${S}/packaging/macros.desktop-file-utils ${D}/etc/rpm/macros.desktop-file-utils
 # Create ghosts based on default $XDG_DATA_DIRS:
 mkdir -p ${D}/usr/share/applications
 touch ${D}/usr/share/applications/mimeinfo.cache
 
 
}

PACKAGES = ""
PACKAGES += "desktop-file-utils"

desktop-file-utils_files = ""
desktop-file-utils_files += "desktop-file-utils.manifest"
desktop-file-utils_files += "AUTHORS ChangeLog NEWS README"
desktop-file-utils_files += "/usr/bin/desktop-file-edit"
desktop-file-utils_files += "/usr/bin/desktop-file-install"
desktop-file-utils_files += "/usr/bin/desktop-file-validate"
desktop-file-utils_files += "/usr/bin/update-desktop-database"
desktop-file-utils_files += "/usr/share/man/man1/desktop-file-edit.1*"
desktop-file-utils_files += "/usr/share/man/man1/desktop-file-install.1*"
desktop-file-utils_files += "/usr/share/man/man1/desktop-file-validate.1*"
desktop-file-utils_files += "/usr/share/man/man1/update-desktop-database.1*"
desktop-file-utils_files += "/usr/share/emacs"
desktop-file-utils_files += "/usr/share/emacs/site-lisp"
desktop-file-utils_files += "/usr/share/emacs/site-lisp/*.el*"
desktop-file-utils_files += "/etc/rpm/macros.desktop-file-utils"

FILES_${PN} = "${desktop-file-utils_files}"

PKG_desktop-file-utils= "desktop-file-utils"

require desktop-file-utils-extraconf.inc
