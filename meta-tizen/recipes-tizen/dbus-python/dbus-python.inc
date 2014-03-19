DESCRIPTION = "Python bindings for D-Bus"
HOMEPAGE = "http://www.freedesktop.org/wiki/Software/DBusBindings/"
SECTION = "System/Libraries"
LICENSE = "MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by dbus-python-devel 
PROVIDES += "dbus-python-devel"
RPROVIDES_dbus-python-devel += "dbus-python-devel"
RPROVIDES_dbus-python-devel += "dbus-python-dev"

#PROVIDES by dbus-python 
PROVIDES += "dbus-python"
RPROVIDES_dbus-python += "dbus-python"

RDEPENDS = ""
#RDEPENDS of dbus-python-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "dbus"
RDEPENDS_${PN}-devel += "dbus-dev"
RDEPENDS_${PN}-devel += "dbus-python"

#RDEPENDS of dbus-python (${PN})
RDEPENDS_${PN} += "python-xml"
RDEPENDS_${PN} += "dbus"
RDEPENDS_${PN} += "libxml2-python"


DEPENDS = ""
#DEPENDS of dbus-python 
DEPENDS += "pkgconfig(dbus-1)"
DEPENDS += "fdupes-native"
DEPENDS += "python-devel"
DEPENDS += "dbus-glib"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q 
 cp ${S}/packaging/dbus-python.manifest .
 
 
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
 
 export CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -fstack-protector -fno-strict-aliasing -fPIC"
 
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
         --infodir=/usr/share/info --docdir=/usr/share/doc/packages/dbus-python
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
 
 
 
   rm -rf ${D}/usr/share/info 
   rm -rf ${D}/usr/share/doc/packages 
   rm -rf ${D}/usr/share/doc/dbus-python 
   rm -rf ${D}/usr/share/doc/dbus-python-1.1.1 
   rm -rf ${D}/usr/share/gtk-doc 
   rm -rf ${D}/usr/share/doc 
   rm -rf ${D}/usr/share/man 
   find ${D} -regex ".*/man/man./.*.[0-9]" | xargs rm -f -- 
   find ${D} -regex ".*/man/../man./.*.[0-9]" | xargs rm -f -- 
   find ${D} -regex ".*/man/man./.*.[0-9]pm" | xargs rm -f --
 
  _target=""; 
  _symlinks=0; 
  _symlinks=1; 
  fdupes -q -n -r ${D} | 
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
PACKAGES += "dbus-python-devel"
PACKAGES += "dbus-python"

dbus-python-devel_files = ""
dbus-python-devel_files += "dbus-python.manifest"
dbus-python-devel_files += "/usr/include/dbus-1.0/dbus/dbus-python.h"
dbus-python-devel_files += "/usr/lib/pkgconfig/dbus-python.pc"

dbus-python_files = ""
dbus-python_files += "dbus-python.manifest"
dbus-python_files += "/usr/lib/python2.7/site-packages/*"
dbus-python_files += "/usr/lib/python2.7/site-packages/*"

FILES_${PN}-devel = "${dbus-python-devel_files}"
FILES_${PN} = "${dbus-python_files}"

PKG_dbus-python-devel= "dbus-python-devel"
PKG_dbus-python= "dbus-python"

require dbus-python-extraconf.inc
