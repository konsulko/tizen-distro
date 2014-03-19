DESCRIPTION = "Edbus python bindings"
HOMEPAGE = "http://www.enlightenment.org"
SECTION = "EFL"
LICENSE = "LGPL2.1"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by python-edbus 
PROVIDES += "python-edbus"
RPROVIDES_python-edbus += "python-edbus"

#PROVIDES by python-edbus-devel 
PROVIDES += "python-edbus-devel"
RPROVIDES_python-edbus-devel += "python-edbus-devel"
RPROVIDES_python-edbus-devel += "python-edbus-dev"

RDEPENDS = ""
#RDEPENDS of python-edbus (${PN})
RDEPENDS_${PN} += "edbus"
RDEPENDS_${PN} += "dbus-python"

#RDEPENDS of python-edbus-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "python-edbus"


DEPENDS = ""
#DEPENDS of python-edbus 
inherit pythonnative
DEPENDS += "pkgconfig(edbus)"
DEPENDS += "dbus-python"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n python-e_dbus-1.7.0
 cp ${S}/packaging/python-edbus.manifest .
 
 
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
 
 
}

PACKAGES = ""
PACKAGES += "python-edbus"
PACKAGES += "python-edbus-devel"

python-edbus_files = ""
python-edbus_files += "python-edbus.manifest"
python-edbus_files += "/usr/lib/python2.7/site-packages/e_dbus.so"

python-edbus-devel_files = ""
python-edbus-devel_files += "python-edbus.manifest"
python-edbus-devel_files += "/usr/lib/pkgconfig/python-edbus.pc"

FILES_${PN} = "${python-edbus_files}"
FILES_${PN}-devel = "${python-edbus-devel_files}"

PKG_python-edbus= "python-edbus"
PKG_python-edbus-devel= "python-edbus-devel"

require python-edbus-extraconf.inc
