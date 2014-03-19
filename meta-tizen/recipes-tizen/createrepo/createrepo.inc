DESCRIPTION = "Creates a common metadata repository"
HOMEPAGE = "http://createrepo.baseurl.org/"
SECTION = "System/Base"
LICENSE = "GPL-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by createrepo 
PROVIDES += "createrepo"
RPROVIDES_createrepo += "createrepo"

RDEPENDS = ""
#RDEPENDS of createrepo (${PN})
RDEPENDS_${PN} += "python-libxml2"
RDEPENDS_${PN} += "python"
RDEPENDS_${PN} += "python-deltarpm"
RDEPENDS_${PN} += "python-rpm"
RDEPENDS_${PN} += "deltarpm"
RDEPENDS_${PN} += "yum"
RDEPENDS_${PN} += "rpm"
RDEPENDS_${PN} += "yum-metadata-parser"


DEPENDS = ""
#DEPENDS of createrepo 
inherit pythonnative

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/createrepo.manifest .
 
 
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
 
 make DESTDIR=${D} sysconfdir=/etc install
 
 
}

PACKAGES = ""
PACKAGES += "createrepo"

createrepo_files = ""
createrepo_files += "createrepo.manifest"
createrepo_files += "/etc/bash_completion.d/"
createrepo_files += "/usr/share/createrepo/"
createrepo_files += "/usr/bin/createrepo"
createrepo_files += "/usr/bin/modifyrepo"
createrepo_files += "/usr/bin/mergerepo"
createrepo_files += "/usr/share/man/*/*"
createrepo_files += "/usr/lib/python2.7/site-packages/createrepo"

FILES_${PN} = "${createrepo_files}"

PKG_createrepo= "createrepo"

require createrepo-extraconf.inc
