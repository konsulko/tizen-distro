DESCRIPTION = "Content Security Framework"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Security/Libraries"
LICENSE = "BSD-3-Clause"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by csr-framework 
PROVIDES += "csr-framework"
RPROVIDES_csr-framework += "csr-framework"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of csr-framework 
DEPENDS += "pkgconfig(libtzplatform-config)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/csr-framework.manifest .
 
 
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
  
 make all
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 rm -rf ${D}
 mkdir -p ${D}/usr/lib/
 install -D lib/libsecfw.so ${D}/usr/lib/
 
 
}

PACKAGES = ""
PACKAGES += "csr-framework"

csr-framework_files = ""
csr-framework_files += "csr-framework.manifest"
csr-framework_files += "/usr/lib/libsecfw.so"

FILES_${PN} = "${csr-framework_files}"

PKG_csr-framework= "csr-framework"

require csr-framework-extraconf.inc
