DESCRIPTION = "A GNU Tool for Automatically Configuring Source Code"
HOMEPAGE = "http://www.gnu.org/software/autoconf"
SECTION = "Development/Tools/Building"
LICENSE = "GPL-3.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by autoconf 
PROVIDES += "autoconf"
RPROVIDES_autoconf += "autoconf"

RDEPENDS = ""
#RDEPENDS of autoconf (${PN})
RDEPENDS_${PN} += "m4"
RDEPENDS_${PN} += "perl"


DEPENDS = ""
#DEPENDS of autoconf 
DEPENDS += "xz"
DEPENDS += "m4"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n autoconf-2.69
 cp ${S}/packaging/autoconf.manifest .
 
 
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
         --infodir=/usr/share/info
 make -j16
 
 exit 0
 trap 'test $? -ne 0 && cat tests/testsuite.log' EXIT
 make check
 
 
 
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
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f -- 
 rm -f $RPM_BUILD_ROOT/usr/share/emacs/site-lisp/*.el*
 # info's dir file is not auto ignored on some systems
 rm -rf ${D}/usr/share/info/dir
 
 
}

PACKAGES = ""
PACKAGES += "autoconf"

autoconf_files = ""
autoconf_files += "autoconf.manifest"
autoconf_files += "COPYING"
autoconf_files += "/usr/bin/*"
autoconf_files += "/usr/share/autoconf"
autoconf_files += "/usr/share/info/*.gz"
autoconf_files += "/usr/share/man/man1/*.gz"

FILES_${PN} = "${autoconf_files}"

PKG_autoconf= "autoconf"

require autoconf-extraconf.inc
