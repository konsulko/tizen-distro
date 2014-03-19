DESCRIPTION = "Show x86 CPU Information"
HOMEPAGE = "http://www.codemonkey.org.uk/projects/x86info/"
SECTION = "System/Monitoring"
LICENSE = "GPL-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by x86info 
PROVIDES += "x86info"
RPROVIDES_x86info += "x86info"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of x86info 
inherit pythonnative
DEPENDS += "gcc-cross"
DEPENDS += "pciutils"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/x86info.manifest .
 
 
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
 
 make CFLAGS="$RPM_OPT_FLAGS"
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 mkdir -p $RPM_BUILD_ROOT/usr/bin
 mkdir -p $RPM_BUILD_ROOT/usr/share/man/man1
 mkdir -p $RPM_BUILD_ROOT/usr/sbin
 mkdir -p $RPM_BUILD_ROOT/usr/share/man/man8
 install -m 755 x86info $RPM_BUILD_ROOT/usr/bin
 install -m 644 x86info.1 $RPM_BUILD_ROOT/usr/share/man/man1
 install -m 755 lsmsr $RPM_BUILD_ROOT/usr/sbin
 install -m 644 lsmsr.8 $RPM_BUILD_ROOT/usr/share/man/man8
 
 
 
}

PACKAGES = ""
PACKAGES += "x86info"

x86info_files = ""
x86info_files += "x86info.manifest"
x86info_files += "/usr/share/man/man1/x86info.1.gz"
x86info_files += "/usr/share/man/man8/lsmsr.8.gz"
x86info_files += "README TODO"
x86info_files += "/usr/bin/x86info"
x86info_files += "/usr/sbin/lsmsr"

FILES_${PN} = "${x86info_files}"

PKG_x86info= "x86info"

require x86info-extraconf.inc
