DESCRIPTION = "Edje python bindings"
HOMEPAGE = "http://www.enlightenment.org"
SECTION = "EFL"
LICENSE = "LGPL2.1"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by python-edje-devel 
PROVIDES += "python-edje-devel"
RPROVIDES_python-edje-devel += "python-edje-devel"
RPROVIDES_python-edje-devel += "python-edje-dev"

#PROVIDES by python-edje 
PROVIDES += "python-edje"
RPROVIDES_python-edje += "python-edje"

RDEPENDS = ""
#RDEPENDS of python-edje-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "pkgconfig(python-evas)"
RDEPENDS_${PN}-devel += "pkgconfig(edje)"


DEPENDS = ""
#DEPENDS of python-edje 
inherit pythonnative
DEPENDS += "pkgconfig(python-evas)"
DEPENDS += "pkgconfig(edje)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/python-edje.manifest .
 
 
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
PACKAGES += "python-edje-devel"
PACKAGES += "python-edje"

python-edje-devel_files = ""
python-edje-devel_files += "python-edje.manifest"
python-edje-devel_files += "/usr/share/python-edje/examples"
python-edje-devel_files += "/usr/lib/pkgconfig/*.pc"
python-edje-devel_files += "/usr/include/python-edje/edje"

python-edje_files = ""
python-edje_files += "python-edje.manifest"
python-edje_files += "/usr/lib/python2.7/site-packages/edje"

FILES_${PN}-devel = "${python-edje-devel_files}"
FILES_${PN} = "${python-edje_files}"

PKG_python-edje-devel= "python-edje-devel"
PKG_python-edje= "python-edje"

require python-edje-extraconf.inc
