DESCRIPTION = "Evas python bindings"
HOMEPAGE = "http://www.enlightenment.org"
SECTION = "EFL"
LICENSE = "LGPL2.1"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by python-evas 
PROVIDES += "python-evas"
RPROVIDES_python-evas += "python-evas"

#PROVIDES by python-evas-devel 
PROVIDES += "python-evas-devel"
RPROVIDES_python-evas-devel += "python-evas-devel"
RPROVIDES_python-evas-devel += "python-evas-dev"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of python-evas 
inherit pythonnative
DEPENDS += "pkgconfig(evas)"
DEPENDS += "dbus-python"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/python-evas.manifest .
 
 
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
PACKAGES += "python-evas"
PACKAGES += "python-evas-devel"

python-evas_files = ""
python-evas_files += "python-evas.manifest"
python-evas_files += "/usr/lib/python2.7/site-packages/evas"

python-evas-devel_files = ""
python-evas-devel_files += "python-evas.manifest"
python-evas-devel_files += "/usr/share/python-evas/examples/01-smart_object.py"
python-evas-devel_files += "/usr/include/python-evas/evas"
python-evas-devel_files += "/usr/lib/pkgconfig/python-evas.pc"

FILES_${PN} = "${python-evas_files}"
FILES_${PN}-devel = "${python-evas-devel_files}"

PKG_python-evas= "python-evas"
PKG_python-evas-devel= "python-evas-devel"

require python-evas-extraconf.inc
