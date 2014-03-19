DESCRIPTION = "A Tool for Automating Interactive Programs"
HOMEPAGE = "http://expect.nist.gov"
SECTION = "Development/Languages/Tcl"
LICENSE = "SUSE-Public-Domain"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by expect-devel 
PROVIDES += "expect-devel"
RPROVIDES_expect-devel += "expect-devel"
RPROVIDES_expect-devel += "expect-dev"

#PROVIDES by expect 
PROVIDES += "expect"
RPROVIDES_expect += "expect"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of expect 
DEPENDS += "tcl-devel"
DEPENDS += "autoconf-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n expect5.45
 cp ${S}/packaging/expect.manifest .
 
 
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
 
 autoreconf
 
   CFLAGS="${CFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CFLAGS ; 
   CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
   FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -I%_fmoddir}" ; export FFLAGS ; 
   autotools_do_configure --build=${TARGET_SYS} --host=${HOST_SYS} \
         --target=x86_64-tizen-linux \
         --program-prefix= \
         --prefix=/usr \
         --exec-prefix=/usr \
         --bindir=/usr/bin \
         --sbindir=/usr/sbin \
         --sysconfdir=/etc \
         --datadir=/usr/share \
         --includedir=/usr/include \
         --libdir=/usr/lib \
         --libexecdir=/usr/libexec \
         --localstatedir=/var \
         --sharedstatedir=/usr/com \
         --mandir=/usr/share/man \
         --infodir=/usr/share/info \
 	--with-tcl=/usr/lib \
 	--with-tk=no_tk \
 	--with-tclinclude=/usr/include \
 	--enable-shared
 make -j16 all pkglibdir=/usr/lib/tcl/expect5.45
 
 
 exit 0
 make test
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 # set the right path to the expect binary...
 sed -i \
     -e '1s,^#![^ ]*expectk,#!/usr/bin/wish\npackage require Expect,' \
     -e '1s,^#![^ ]*expect,#!/usr/bin/expect,' \
     example/*
 make install DESTDIR=$RPM_BUILD_ROOT pkglibdir=/usr/lib/tcl/expect5.45
 # Remove some executables and manpages we don't want to ship
 rm $RPM_BUILD_ROOT/usr/bin/*passwd
 rm $RPM_BUILD_ROOT/usr/share/man/*/*passwd*
 
 
}

PACKAGES = ""
PACKAGES += "expect-devel"
PACKAGES += "expect"

expect-devel_files = ""
expect-devel_files += "expect.manifest"
expect-devel_files += "/usr/include/*"
expect-devel_files += "/usr/share/man/man3/*"

expect_files = ""
expect_files += "expect.manifest"
expect_files += "/usr/bin/*"
expect_files += "/usr/lib/tcl/*"
expect_files += "/usr/lib/lib*.so"
expect_files += "/usr/share/man/man1/*"

FILES_${PN}-devel = "${expect-devel_files}"
FILES_${PN} = "${expect_files}"

PKG_expect-devel= "expect-devel"
PKG_expect= "expect"

require expect-extraconf.inc
