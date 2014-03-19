DESCRIPTION = "A Program for Automatically Generating GNU-Style Makefile.in Files"
HOMEPAGE = "http://www.gnu.org/software/automake"
SECTION = "Development/Tools/Building"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by automake 
PROVIDES += "automake"
RPROVIDES_automake += "automake"

RDEPENDS = ""
#RDEPENDS of automake (${PN})
RDEPENDS_${PN} += "autoconf"


DEPENDS = ""
#DEPENDS of automake 
DEPENDS += "xz"
DEPENDS += "gcc-c++"
DEPENDS += "autoconf-native"
DEPENDS += "bison-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n automake-1.12.1
 cp ${S}/packaging/automake.manifest .
 
 
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
 
 sh bootstrap.sh
 
   CFLAGS="${CFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CFLAGS ; 
   CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
   FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -I%_fmoddir}" ; export FFLAGS ; 
   autotools_do_configure --build=${TARGET_SYS} --host=${HOST_SYS} \
         --target=noarch-tizen-linux \
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
         --infodir=/usr/share/info --docdir=/usr/share/doc/packages/automake
 make -j16
 
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 make install DESTDIR=${D}
 mkdir -p ${D}/etc ${D}/usr/share/aclocal
 echo /usr/local/share/aclocal >${D}/etc/aclocal_dirlist
 ln -s ../../../etc/aclocal_dirlist ${D}/usr/share/aclocal/dirlist
 mkdir -p ${D}/usr/share/man/man1
 install -m644 COPYING ${D}/usr/share/doc/packages/automake
 # info's dir file is not auto ignored on some systems
 rm -rf ${D}/usr/share/info/dir
 
 
}

PACKAGES = ""
PACKAGES += "automake"

automake_files = ""
automake_files += "automake.manifest"
automake_files += "/usr/share/doc/packages/automake"
automake_files += "/usr/bin/*"
automake_files += "/usr/share/info/*.gz"
automake_files += "/usr/share/man/man1/*"
automake_files += "/usr/share/aclocal*"
automake_files += "/usr/share/automake-*"
automake_files += "/etc/aclocal_dirlist"

FILES_${PN} = "${automake_files}"

PKG_automake= "automake"

require automake-extraconf.inc
