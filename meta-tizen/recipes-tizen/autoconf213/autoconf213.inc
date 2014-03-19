DESCRIPTION = "A GNU Tool for Automatically Configuring Source Code"
HOMEPAGE = "http://www.gnu.org/software/autoconf"
SECTION = "Development/Tools/Building"
LICENSE = "GPL v2 or later"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by autoconf213 
PROVIDES += "autoconf213"
RPROVIDES_autoconf213 += "autoconf213"

RDEPENDS = ""
#RDEPENDS of autoconf213 (${PN})
RDEPENDS_${PN} += "mktemp"
RDEPENDS_${PN} += "m4"
RDEPENDS_${PN} += "gawk"
RDEPENDS_${PN} += "perl"


DEPENDS = ""
#DEPENDS of autoconf213 
DEPENDS += "texinfo-native"
DEPENDS += "makeinfo"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -n autoconf-2.13 -q
 cp ${S}/packaging/autoconf213.manifest .
 
 
 mv autoconf.texi autoconf213.texi
 rm -f autoconf.info
 
 
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
 
 ./configure --prefix=/usr --infodir=/usr/share/info --mandir=/usr/share/man \
             --program-suffix=-2.13
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
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 # We don't want to include the standards.info stuff in the package,
 # because it comes from binutils...
 rm -f ${RPM_BUILD_ROOT}/usr/share/info/standards*
 
 
}

PACKAGES = ""
PACKAGES += "autoconf213"

autoconf213_files = ""
autoconf213_files += "autoconf213.manifest"
autoconf213_files += "AUTHORS COPYING NEWS README TODO"
autoconf213_files += "/usr/bin/*"
autoconf213_files += "/usr/share/autoconf-2.13"
autoconf213_files += "/usr/share/info/*.gz"

FILES_${PN} = "${autoconf213_files}"

PKG_autoconf213= "autoconf213"

require autoconf213-extraconf.inc
