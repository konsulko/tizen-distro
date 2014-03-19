DESCRIPTION = "Create kickstart files for image creation"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Base/Utilities"
LICENSE = "GPL-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by kickstarter 
PROVIDES += "kickstarter"
RPROVIDES_kickstarter += "kickstarter"

RDEPENDS = ""
#RDEPENDS of kickstarter (${PN})
RDEPENDS_${PN} += "python-yaml"
RDEPENDS_${PN} += "python-lxml"
RDEPENDS_${PN} += "python-cheetah"


DEPENDS = ""
#DEPENDS of kickstarter 
DEPENDS += "python-devel"
DEPENDS += "python-cheetah"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n kickstarter-0.17
 
 
 
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
 
 cp ${S}/packaging/kickstarter.manifest .
 make tmpls
 
 CFLAGS="$RPM_OPT_FLAGS" /usr/bin/python setup.py build
 
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 rm -rf $RPM_BUILD_ROOT
 /usr/bin/python setup.py install --root=$RPM_BUILD_ROOT -O1 --prefix=/usr
 
 
 
}

PACKAGES = ""
PACKAGES += "kickstarter"

kickstarter_files = ""
kickstarter_files += "kickstarter.manifest"
kickstarter_files += "/usr/bin/*"
kickstarter_files += "/usr/lib/python2.7/site-packages/*"

FILES_${PN} = "${kickstarter_files}"

PKG_kickstarter= "kickstarter"

require kickstarter-extraconf.inc
