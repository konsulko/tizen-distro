DESCRIPTION = "Create a tree of hardlinks"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Base/Tools"
LICENSE = "GPL+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by hardlink 
PROVIDES += "hardlink"
RPROVIDES_hardlink += "hardlink"

RDEPENDS = ""

DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -c -T
 cp ${S}/packaging/hardlink.manifest .
 install -pm 644 ${S}/packaging/hardlink.c hardlink.c
 
 
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
 
 gcc $RPM_OPT_FLAGS hardlink.c -o hardlink
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 rm -rf $RPM_BUILD_ROOT
 install -D -m 644 ${S}/packaging/hardlink.1 $RPM_BUILD_ROOT/usr/share/man/man1/hardlink.1
 install -D -m 755 hardlink $RPM_BUILD_ROOT/usr/sbin/hardlink
 
 
}

PACKAGES = ""
PACKAGES += "hardlink"

hardlink_files = ""
hardlink_files += "hardlink.manifest"
hardlink_files += "/usr/sbin/hardlink"
hardlink_files += "/usr/share/man/man1/hardlink.1*"
hardlink_files += ""

FILES_${PN} = "${hardlink_files}"

PKG_hardlink= "hardlink"

require hardlink-extraconf.inc
