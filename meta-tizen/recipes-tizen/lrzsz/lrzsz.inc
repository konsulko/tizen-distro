DESCRIPTION = "Serial file transfer protocols"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Network & Connectivity/Utilities"
LICENSE = "GPL-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by lrzsz 
PROVIDES += "lrzsz"
RPROVIDES_lrzsz += "lrzsz"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of lrzsz 
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 
 
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
 
 autotools_do_configure --program-transform-name=s/l//
 make
 
 
 
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
         BINDIR=/usr/bin \
         prefix=/usr \
         exec_prefix=/usr \
         bindir=/usr/bin \
         sbindir=/usr/sbin \
         sysconfdir=/etc \
         datadir=/usr/share \
         includedir=/usr/include \
         libdir=/usr/lib \
         libexecdir=/usr/libexec \
         localstatedir=}/var \
         sharedstatedir=/usr/com \
         mandir=/usr/share/man \
         infodir=/usr/share/info \
   install
 
 
}

PACKAGES = ""
PACKAGES += "lrzsz"

lrzsz_files = ""
lrzsz_files += "AUTHORS COMPATABILITY ChangeLog NEWS README README.gettext TODO THANKS README.cvs README.isdn4linux README.tests"
lrzsz_files += "/usr/bin/sz"
lrzsz_files += "/usr/bin/sb"
lrzsz_files += "/usr/bin/sx"
lrzsz_files += "/usr/bin/rz"
lrzsz_files += "/usr/bin/rb"
lrzsz_files += "/usr/bin/rx"
lrzsz_files += "/usr/share/man/man1/sz.1.gz"
lrzsz_files += "/usr/share/man/man1/rz.1.gz"

FILES_${PN} = "${lrzsz_files}"

PKG_lrzsz= "lrzsz"

require lrzsz-extraconf.inc
