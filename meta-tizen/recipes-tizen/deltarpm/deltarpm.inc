DESCRIPTION = "Tools to Create and Apply deltarpms"
HOMEPAGE = "ftp://ftp.suse.com/pub/projects/deltarpm"
SECTION = "System/Packages"
LICENSE = "BSD-3-Clause"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by deltarpm 
PROVIDES += "deltarpm"
RPROVIDES_deltarpm += "deltarpm"

#PROVIDES by python-deltarpm 
PROVIDES += "python-deltarpm"
RPROVIDES_python-deltarpm += "python-deltarpm"

RDEPENDS = ""
#RDEPENDS of python-deltarpm (python-${PN})
RDEPENDS_python-${PN} += "deltarpm"


DEPENDS = ""
#DEPENDS of deltarpm 
DEPENDS += "rpm-devel"
DEPENDS += "bzip2"
DEPENDS += "python-devel"
DEPENDS += "xz-devel"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/deltarpm.manifest .
 
 
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
 
 make CC="gcc" CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables" rpmdumpheader="/usr/lib/rpm/rpmdumpheader" -j16
 make CC="gcc" CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables" rpmdumpheader="/usr/lib/rpm/rpmdumpheader" -j16 python
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 mkdir -p ${D}/usr/lib/rpm
 make DESTDIR=${D} prefix="/usr" libdir="/usr/lib" mandir="/usr/share/man" rpmdumpheader="/usr/lib/rpm/rpmdumpheader" install
 rm -rf ${D}/usr/lib/python/site-packages/{_deltarpmmodule.so,deltarpm.py} # Remove wrongly installed Python module
 mv ${D}/usr/lib/python2.7/site-packages/_deltarpm{module,}.so # Fix binary Python module name
 
 
}

PACKAGES = ""
PACKAGES += "python-deltarpm"
PACKAGES += "deltarpm"

python-deltarpm_files = ""
python-deltarpm_files += "deltarpm.manifest"
python-deltarpm_files += "/usr/lib/python2.7/site-packages/deltarpm.py"
python-deltarpm_files += "/usr/lib/python2.7/site-packages/_deltarpm.so"

deltarpm_files = ""
deltarpm_files += "deltarpm.manifest"
deltarpm_files += "README LICENSE.BSD"
deltarpm_files += "/usr/bin/*"
deltarpm_files += "/usr/share/man/man8/*"
deltarpm_files += "/usr/lib/rpm/rpmdumpheader"

FILES_python-${PN} = "${python-deltarpm_files}"
FILES_${PN} = "${deltarpm_files}"

PKG_python-deltarpm= "python-deltarpm"
PKG_deltarpm= "deltarpm"

require deltarpm-extraconf.inc
