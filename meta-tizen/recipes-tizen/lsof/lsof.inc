DESCRIPTION = "A utility which lists open files on a Linux/UNIX system"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Base/Tools"
LICENSE = "Zlib"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by lsof-docs  
PROVIDES += "lsof-docs "
RPROVIDES_lsof-docs  += "lsof-docs "

#PROVIDES by lsof 
PROVIDES += "lsof"
RPROVIDES_lsof += "lsof"

RDEPENDS = ""

DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n lsof_4.87-linux-only
 cp ${S}/packaging/lsof.manifest .
 
 
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
 
 LSOF_VSTR=2.6.16 LINUX_BASE=/proc ./Configure -n linux
 
 make DEBUG="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables" -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 install -Dm755 lsof ${D}/usr/sbin/lsof
 install -Dm644 lsof.8 ${D}/usr/share/man/man8/lsof.8
 
 
 
 
}

PACKAGES = ""
PACKAGES += "lsof-docs"
PACKAGES += "lsof"

lsof-docs_files = ""
lsof-docs_files += "/usr/share/info"
lsof-docs_files += "/usr/share/man"

lsof_files = ""
lsof_files += "lsof.manifest"
lsof_files += "/usr/sbin/lsof"

FILES_${PN}-docs = "${lsof-docs_files}"
FILES_${PN} = "${lsof_files}"

PKG_lsof-docs= "lsof-docs"
PKG_lsof= "lsof"

require lsof-extraconf.inc
