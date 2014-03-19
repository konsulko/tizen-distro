DESCRIPTION = "Edbus python bindings"
HOMEPAGE = "http://www.enlightenment.org"
SECTION = "EFL"
LICENSE = "LGPL2.1"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by python-ecore 
PROVIDES += "python-ecore"
RPROVIDES_python-ecore += "python-ecore"

#PROVIDES by python-ecore-devel 
PROVIDES += "python-ecore-devel"
RPROVIDES_python-ecore-devel += "python-ecore-devel"
RPROVIDES_python-ecore-devel += "python-ecore-dev"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of python-ecore 
inherit pythonnative
DEPENDS += "ecore"
DEPENDS += "dbus-python"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/python-ecore.manifest .
 
 
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
PACKAGES += "python-ecore"
PACKAGES += "python-ecore-devel"

python-ecore_files = ""
python-ecore_files += "python-ecore.manifest"
python-ecore_files += "/usr/lib/python2.7/site-packages/ecore"

python-ecore-devel_files = ""
python-ecore-devel_files += "python-ecore.manifest"
python-ecore-devel_files += "/usr/share/python-ecore/examples"
python-ecore-devel_files += "/usr/include/python-ecore/ecore"
python-ecore-devel_files += "/usr/lib/pkgconfig/*.pc"

FILES_${PN} = "${python-ecore_files}"
FILES_${PN}-devel = "${python-ecore-devel_files}"

PKG_python-ecore= "python-ecore"
PKG_python-ecore-devel= "python-ecore-devel"

require python-ecore-extraconf.inc
