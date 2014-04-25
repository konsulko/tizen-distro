DESCRIPTION = "Python Bindings for Manipulating RPM Packages"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Base/Package Management"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools

PROVIDES = ""

#PROVIDES by python-rpm

RDEPENDS = ""
#RDEPENDS of python-rpm (${PN})
RDEPENDS_${PN} += "rpm"


DEPENDS = ""
#DEPENDS of python-rpm
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "attr"
DEPENDS += "ncurses"
DEPENDS += "libxml2"
DEPENDS += "elfutils"
DEPENDS += "zlib"
DEPENDS += "uthash"
DEPENDS += "bzip2"
DEPENDS += "acl"
DEPENDS += "xz"
DEPENDS += "lua"
DEPENDS += "smack"
DEPENDS += "libtool-cross"
DEPENDS += "file"
DEPENDS += "popt"
DEPENDS += "libcap"
DEPENDS += "nss"
DEPENDS += "python"
inherit pythonnative

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n rpm-4.11.0.1



}
do_patch_append() {
    bb.build.exec_func('do_prep', d)
}

do_configure() {
}

do_compile() {
 cd ${S}
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
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D}
 mkdir -p ${D}

 mkdir -p ${D}${prefix}/lib
 # only installing in python/ does not work because rpm links against
 # installed libs at install time

   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=${prefix}/bin \
   install
   rm -f ${D}${infodir}/dir
   find ${D} -regex ".*\.la$" | xargs rm -f --
   find ${D} -regex ".*\.a$" | xargs rm -f --
 find ${D} -not -type d -and -not -path ${D}${prefix}/lib/python*/site-packages/rpm/\* -print0 | xargs -0 rm
 pushd ${D}/${prefix}/lib/python*/site-packages/rpm
 rm -f _rpmmodule.a _rpmmodule.la
 #python ${prefix}/lib/python*/py_compile.py *.py
 #python -O ${prefix}/lib/python*/py_compile.py *.py
 popd

 rm -fr ${D}${prefix}/lib/rpm/platform
 rm -fr ${D}${prefix}/bin
 rm -fr ${D}/bin
 rm -fr ${D}/var
 rm -fr ${D}${prefix}/lib/rpm-plugins
 rm -fr ${D}${prefix}/lib/rpm
 rm -fr ${D}${prefix}/lib/rpm/fileattr
 rm -fr ${D}${prefix}${base_prefix}/bin
 rm -fr ${D}${prefix}${localstatedir}
 rm -fr ${D}${localstatedir}/tmp
 rm -fr ${D}${localstatedir}/volatile

}


python-rpm_files = ""
python-rpm_files += "${prefix}/lib/python*/*/*"

FILES_${PN} = "${python-rpm_files}"

PKG_python-rpm= "python-rpm"

require python-rpm-extraconf.inc
