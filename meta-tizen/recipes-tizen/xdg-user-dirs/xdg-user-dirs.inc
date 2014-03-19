DESCRIPTION = "Utilities to handle user data directories"
HOMEPAGE = "http://freedesktop.org/wiki/Software/xdg-user-dirs"
SECTION = "Graphics/X Window System"
LICENSE = "GPL-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by xdg-user-dirs-locale  
PROVIDES += "xdg-user-dirs-locale "
RPROVIDES_xdg-user-dirs-locale  += "xdg-user-dirs-locale "
# the PROVIDES rules is ignore "xdg-user-dirs-lang-all = 0.14"
PROVIDES += "xdg-user-dirs-lang-all"
RPROVIDES_xdg-user-dirs-locale  += "xdg-user-dirs-lang-all"

#PROVIDES by xdg-user-dirs 
PROVIDES += "xdg-user-dirs"
RPROVIDES_xdg-user-dirs += "xdg-user-dirs"

RDEPENDS = ""
#RDEPENDS of xdg-user-dirs-locale  (${PN}-locale )
RDEPENDS_${PN}-locale  += "xdg-user-dirs"


DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/xdg-user-dirs.manifest .
 
 
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
 
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} xdg-user-dirs
 mkdir -p ${D}/etc/X11/xinit/xinitrc.d
 install -m 0755 ${S}/packaging/xdg-user-dirs.sh ${D}/etc/X11/xinit/xinitrc.d/xdg-user-dirs.sh
 
 
 
}

PACKAGES = ""
PACKAGES += "xdg-user-dirs-locale"
PACKAGES += "xdg-user-dirs"

xdg-user-dirs-locale_files = ""

xdg-user-dirs_files = ""
xdg-user-dirs_files += "xdg-user-dirs.manifest"
xdg-user-dirs_files += "/etc/xdg/user-dirs.conf"
xdg-user-dirs_files += "/etc/xdg/user-dirs.defaults"
xdg-user-dirs_files += "/etc/X11/xinit"
xdg-user-dirs_files += "/etc/X11/xinit/xinitrc.d"
xdg-user-dirs_files += "/etc/X11/xinit/xinitrc.d/xdg-user-dirs.sh"
xdg-user-dirs_files += "/usr/bin/xdg-user-dir"
xdg-user-dirs_files += "/usr/bin/xdg-user-dirs-update"

FILES_${PN}-locale = "${xdg-user-dirs-locale_files}"
FILES_${PN} = "${xdg-user-dirs_files}"

PKG_xdg-user-dirs-locale= "xdg-user-dirs-locale"
PKG_xdg-user-dirs= "xdg-user-dirs"

require xdg-user-dirs-extraconf.inc
