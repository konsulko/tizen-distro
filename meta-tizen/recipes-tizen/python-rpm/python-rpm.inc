DESCRIPTION = "Python Bindings for Manipulating RPM Packages"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Base/Package Management"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by python-rpm 
PROVIDES += "python-rpm"
RPROVIDES_python-rpm += "python-rpm"

RDEPENDS = ""
#RDEPENDS of python-rpm (${PN})
RDEPENDS_${PN} += "rpm"


DEPENDS = ""
#DEPENDS of python-rpm 
DEPENDS += "zlib-devel"
DEPENDS += "bzip2"
DEPENDS += "xz-devel"
DEPENDS += "uthash-devel"
DEPENDS += "ncurses"
DEPENDS += "libxml2"
DEPENDS += "elfutils"
DEPENDS += "attr"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "acl"
DEPENDS += "lua-native"
DEPENDS += "libtool-cross"
DEPENDS += "file"
DEPENDS += "popt"
DEPENDS += "libcap"
DEPENDS += "nss"
DEPENDS += "pkgconfig(libsmack)"
inherit pythonnative

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n rpm-4.11.0.1
 
 
 
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
 
 
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 mkdir -p ${D}/usr/lib
 # only installing in python/ does not work because rpm links against
 # installed libs at install time
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 find ${D} -not -type d -and -not -path ${D}/usr/lib/python*/site-packages/rpm/\* -print0 | xargs -0 rm
 pushd ${D}//usr/lib/python*/site-packages/rpm
 rm -f _rpmmodule.a _rpmmodule.la
 #python /usr/lib/python*/py_compile.py *.py
 #python -O /usr/lib/python*/py_compile.py *.py
 popd
 
 
}

PACKAGES = ""
PACKAGES += "python-rpm"

python-rpm_files = ""
python-rpm_files += "/usr/lib/python*/*/*"

FILES_${PN} = "${python-rpm_files}"

PKG_python-rpm= "python-rpm"

require python-rpm-extraconf.inc
