DESCRIPTION = "Rpm correctness checker"
HOMEPAGE = "http://rpmlint.zarb.org/"
SECTION = "Development/Packaging"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by rpmlint 
PROVIDES += "rpmlint"
RPROVIDES_rpmlint += "rpmlint"

RDEPENDS = ""
#RDEPENDS of rpmlint (${PN})
RDEPENDS_${PN} += "python-rpm"
RDEPENDS_${PN} += "cpio"
RDEPENDS_${PN} += "dash"
RDEPENDS_${PN} += "findutils"
RDEPENDS_${PN} += "file"
RDEPENDS_${PN} += "python-magic"
RDEPENDS_${PN} += "desktop-file-utils"
RDEPENDS_${PN} += "/usr/bin/readelf"
RDEPENDS_${PN} += "bash"


DEPENDS = ""
#DEPENDS of rpmlint 
DEPENDS += "python-rpm"
DEPENDS += "xz"

do_patch() {
 #extracte source 1 
 pushd ${S}
 unp ${S}/packaging/rpmlint-checks-master.tar.gz 
 popd 
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n rpmlint-1.4  -a1
 cp ${S}/packaging/rpmlint.manifest .
 cp ${S}/packaging/config .
 # Only move top-level python files
 chmod 0755 rpmlint-checks-master/*.py
 mv rpmlint-checks-master/*.py .
 
 
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
 # the provided bash-completion does not work and only prints bash errors
 rm -rf  ${D}/etc/bash_completion.d
 mv ${D}/etc/rpmlint/config ${D}/usr/share/rpmlint/config
 head -n 8 ${D}/usr/share/rpmlint/config > ${D}/etc/rpmlint/config
 # make sure that the package is sane
 python -tt ${S}/packaging/syntax-validator.py ${D}/usr/share/rpmlint/*.py ${D}/usr/share/rpmlint/config
 install -m 644 ${S}/packaging/rpmgroups.config ${D}//etc/rpmlint/
 install -m 644 ${S}/packaging/pie.config ${D}//etc/rpmlint/
 install -m 644 ${S}/packaging/licenses.config ${D}//etc/rpmlint/
 
 
 
}

PACKAGES = ""
PACKAGES += "rpmlint"

rpmlint_files = ""
rpmlint_files += "rpmlint.manifest"
rpmlint_files += "/usr/bin/*"
rpmlint_files += "/usr/share/rpmlint"
rpmlint_files += "/etc/rpmlint/config"
rpmlint_files += "/etc/rpmlint/licenses.config"
rpmlint_files += "/etc/rpmlint/rpmgroups.config"
rpmlint_files += "/etc/rpmlint/pie.config"
rpmlint_files += "/etc/rpmlint"
rpmlint_files += "/usr/share/man/man1/rpmlint.1.gz"

FILES_${PN} = "${rpmlint_files}"

PKG_rpmlint= "rpmlint"

require rpmlint-extraconf.inc
