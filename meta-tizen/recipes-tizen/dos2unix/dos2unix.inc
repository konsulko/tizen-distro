DESCRIPTION = "Text converters to and from DOS/MAC to UNIX"
HOMEPAGE = "http://waterlan.home.xs4all.nl/dos2unix.html"
SECTION = "Productivity/Text/Convertors"
LICENSE = "BSD-3-Clause"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by dos2unix 
PROVIDES += "dos2unix"
RPROVIDES_dos2unix += "dos2unix"
# the PROVIDES rules is ignore "unix2dos = 6.0"
PROVIDES += "unix2dos"
RPROVIDES_dos2unix += "unix2dos"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of dos2unix 
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/dos2unix.manifest .
 find . -type f | xargs chmod -x
 
 
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
 
 export RPM_OPT_FLAGS
 make -j16 CC="gcc" HTMLEXT="html"
 
 
 
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
   find ${D} -regex ".*\.a$" | xargs rm -f -- docdir=/usr/share/doc/packages/dos2unix
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} dos2unix --all-name --with-man
 
 
}

PACKAGES = ""
PACKAGES += "dos2unix"

dos2unix_files = ""
dos2unix_files += "dos2unix.manifest"
dos2unix_files += "/usr/share/doc/dos2unix-6.0"
dos2unix_files += "/usr/bin/dos2unix"
dos2unix_files += "/usr/bin/mac2unix"
dos2unix_files += "/usr/bin/unix2mac"
dos2unix_files += "/usr/bin/unix2dos"
dos2unix_files += "/usr/share/man/*/dos2unix.1*"
dos2unix_files += "/usr/share/man/*/mac2unix.1*"
dos2unix_files += "/usr/share/man/*/unix2mac.1*"
dos2unix_files += "/usr/share/man/*/unix2dos.1*"
dos2unix_files += "%lang(nl) %dir /usr/share/man/nl"

FILES_${PN} = "${dos2unix_files}"

PKG_dos2unix= "dos2unix"

require dos2unix-extraconf.inc
