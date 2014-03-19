DESCRIPTION = "A Script to Build SUSE Linux RPMs"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Development/Tools/Building"
LICENSE = "GPL-2.0+ and GPL-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by build-mkbaselibs 
PROVIDES += "build-mkbaselibs"
RPROVIDES_build-mkbaselibs += "build-mkbaselibs"

#PROVIDES by build-mkdrpms 
PROVIDES += "build-mkdrpms"
RPROVIDES_build-mkdrpms += "build-mkdrpms"

#PROVIDES by build 
PROVIDES += "build"
RPROVIDES_build += "build"

RDEPENDS = ""
#RDEPENDS of build-mkdrpms (${PN}-mkdrpms)
RDEPENDS_${PN}-mkdrpms += "deltarpm"
RDEPENDS_${PN}-mkdrpms += "build"

#RDEPENDS of build (${PN})
RDEPENDS_${PN} += "tar"
RDEPENDS_${PN} += "build-mkbaselibs"
RDEPENDS_${PN} += "binutils"
RDEPENDS_${PN} += "bash"
RDEPENDS_${PN} += "perl"


DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n obs-build-20120927
 cp ${S}/packaging/build.manifest .
 
 
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
 
 make DESTDIR=$RPM_BUILD_ROOT install
 
 
}

PACKAGES = ""
PACKAGES += "build-mkbaselibs"
PACKAGES += "build-mkdrpms"
PACKAGES += "build"

build-mkbaselibs_files = ""
build-mkbaselibs_files += "build.manifest"
build-mkbaselibs_files += "/usr/lib/build"
build-mkbaselibs_files += "/usr/lib/build/mkbaselibs"
build-mkbaselibs_files += "/usr/lib/build/baselibs*"

build-mkdrpms_files = ""
build-mkdrpms_files += "build.manifest"
build-mkdrpms_files += "/usr/lib/build"
build-mkdrpms_files += "/usr/lib/build/mkdrpms"

build_files = ""
build_files += "build.manifest"
build_files += "README"
build_files += "/usr/bin/build"
build_files += "/usr/bin/buildvc"
build_files += "/usr/bin/unrpm"
build_files += "/usr/lib/build"
build_files += "/usr/share/man/man1/build.1*"

FILES_${PN}-mkbaselibs = "${build-mkbaselibs_files}"
FILES_${PN}-mkdrpms = "${build-mkdrpms_files}"
FILES_${PN} = "${build_files}"

PKG_build-mkbaselibs= "build-mkbaselibs"
PKG_build-mkdrpms= "build-mkdrpms"
PKG_build= "build"

require build-extraconf.inc
