DESCRIPTION = "The X Keyboard Extension"
HOMEPAGE = "http://www.freedesktop.org/Software/XKeyboardConfig"
SECTION = "System/X11/Utilities"
LICENSE = "GPL-2.0+  LGPL-2.1+  MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by xkeyboard-config 
PROVIDES += "xkeyboard-config"
RPROVIDES_xkeyboard-config += "xkeyboard-config"
# the PROVIDES rules is ignore "XFree86:/etc/X11/xkb/symbols/us  "
PROVIDES += "XFree86:/etc/X11/xkb/symbols/us"
RPROVIDES_xkeyboard-config += "XFree86:/etc/X11/xkb/symbols/us"
# the PROVIDES rules is ignore "xorg-x11:/etc/X11/xkb/symbols/us  "
PROVIDES += "xorg-x11:/etc/X11/xkb/symbols/us"
RPROVIDES_xkeyboard-config += "xorg-x11:/etc/X11/xkb/symbols/us"

RDEPENDS = ""
#RDEPENDS of xkeyboard-config (${PN})
RDEPENDS_${PN} += "/usr/bin/rm"
RDEPENDS_${PN} += "/usr/bin/ln"


DEPENDS = ""
#DEPENDS of xkeyboard-config 
DEPENDS += "pkgconfig(xorg-macros)"
DEPENDS += "fdupes-native"
DEPENDS += "libxml-parser-perl"
DEPENDS += "intltool-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/xkeyboard-config.manifest .
 
 
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
         --infodir=/usr/share/info --with-xkb-rules-symlink=xfree86,xorg \
             --with-xkb-base=/usr/share/X11/xkb \
             --enable-compat_rules \
             --disable-runtime-deps \
             --disable-xkbcomp-symlink
 rm -f */*.dir
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
 mkdir -p ${D}/var/lib/xkb
 ln -snf /usr/bin/xkbcomp ${D}/usr/share/X11/xkb/xkbcomp
 # Bug 335553
 mkdir -p ${D}/var/lib/xkb/compiled/
 ln -snf /var/lib/xkb/compiled/ ${D}/usr/share/X11/xkb/compiled
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} xkeyboard-config
 
  _target=""; 
  _symlinks=0; 
  _symlinks=1; 
  fdupes -q -n -r ${D}/usr/share/X11/xkb | 
   while read _file; do 
     if test -z "$_target" ; then 
       _target="$_file"; 
     else 
       if test -z "$_file" ; then 
 	_target=""; 
 	continue ; 
       fi ; 
       if test "$_symlinks" = 1; then 
         ln -sf "${_target#${D}}" "$_file"; 
       else 
         ln -f "$_target" "$_file"; 
       fi ;
     fi ; 
  done 
 
 
}

PACKAGES = ""
PACKAGES += "xkeyboard-config"

xkeyboard-config_files = ""
xkeyboard-config_files += "xkeyboard-config.manifest"
xkeyboard-config_files += "AUTHORS COPYING README docs/HOWTO.* docs/README.*"
xkeyboard-config_files += "/var/lib/xkb"
xkeyboard-config_files += "/var/lib/xkb/compiled"
xkeyboard-config_files += "/usr/share/X11/xkb/"
xkeyboard-config_files += "/usr/share/pkgconfig/*.pc"

FILES_${PN} = "${xkeyboard-config_files}"

PKG_xkeyboard-config= "xkeyboard-config"

require xkeyboard-config-extraconf.inc
