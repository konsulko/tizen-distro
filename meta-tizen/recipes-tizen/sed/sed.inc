DESCRIPTION = "A Stream-Oriented Non-Interactive Text Editor"
HOMEPAGE = "http://www.gnu.org/directory/sed.html"
SECTION = "Base/Tools"
LICENSE = "GPL-3.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by sed-docs  
PROVIDES += "sed-docs "
RPROVIDES_sed-docs  += "sed-docs "

#PROVIDES by sed 
PROVIDES += "sed"
RPROVIDES_sed += "sed"
# the PROVIDES rules is ignore "base:/bin/sed  "
PROVIDES += "base:/bin/sed"
RPROVIDES_sed += "base:/bin/sed"
# the PROVIDES rules is ignore "/bin/sed  "
PROVIDES += "/bin/sed"
RPROVIDES_sed += "/bin/sed"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of sed 
DEPENDS += "automake-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/sed.manifest .
 
 
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
 
 export CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -Wall -Wstrict-prototypes -Wpointer-arith -Wformat-security"
 ./configure	--prefix=/usr \
 		--mandir=/usr/share/man \
 		--infodir=/usr/share/info \
 		--disable-nls \
 		--without-included-regex \
 		x86_64-tizen-linux
   make -j16
 make -j16 check
 
 
 
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
 
 
 
 
}

PACKAGES = ""
PACKAGES += "sed-docs"
PACKAGES += "sed"

sed-docs_files = ""
sed-docs_files += "/usr/share/info"
sed-docs_files += "/usr/share/man"

sed_files = ""
sed_files += "sed.manifest"
sed_files += "/usr/bin/sed"
sed_files += "COPYING*"

FILES_${PN}-docs = "${sed-docs_files}"
FILES_${PN} = "${sed_files}"

PKG_sed-docs= "sed-docs"
PKG_sed= "sed"

require sed-extraconf.inc
