DESCRIPTION = "GNU awk"
HOMEPAGE = "http://www.gnu.org/software/gawk/"
SECTION = "Base/Utilities"
LICENSE = "GPL-3.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by gawk-devel 
PROVIDES += "gawk-devel"
RPROVIDES_gawk-devel += "gawk-devel"
RPROVIDES_gawk-devel += "gawk-dev"

#PROVIDES by gawk-docs  
PROVIDES += "gawk-docs "
RPROVIDES_gawk-docs  += "gawk-docs "

#PROVIDES by gawk-extras 
PROVIDES += "gawk-extras"
RPROVIDES_gawk-extras += "gawk-extras"

#PROVIDES by gawk 
PROVIDES += "gawk"
RPROVIDES_gawk += "gawk"
# the PROVIDES rules is ignore "awk  "
PROVIDES += "awk"
RPROVIDES_gawk += "awk"
# the PROVIDES rules is ignore "/bin/awk  "
PROVIDES += "/bin/awk"
RPROVIDES_gawk += "/bin/awk"
# the PROVIDES rules is ignore "/bin/gawk  "
PROVIDES += "/bin/gawk"
RPROVIDES_gawk += "/bin/gawk"

RDEPENDS = ""
#RDEPENDS of gawk-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "gawk"

#RDEPENDS of gawk-extras (${PN}-extras)
RDEPENDS_${PN}-extras += "gawk"


DEPENDS = ""
#DEPENDS of gawk 
DEPENDS += "makeinfo"
DEPENDS += "automake-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/gawk.manifest .
 chmod -x COPYING
 # force rebuild with non-broken makeinfo
 rm -f doc/*.info
 
 
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
 
 AUTOPOINT=true autoreconf --force --install
 
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
         --infodir=/usr/share/info --libexecdir=/usr/lib --disable-nls
   make -j16
 
 exit 0
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
 
 
 
 
}

PACKAGES = ""
PACKAGES += "gawk-devel"
PACKAGES += "gawk-docs"
PACKAGES += "gawk-extras"
PACKAGES += "gawk"

gawk-devel_files = ""
gawk-devel_files += "/usr/bin/dgawk"
gawk-devel_files += "/usr/bin/pgawk*"

gawk-docs_files = ""
gawk-docs_files += "/usr/share/info"
gawk-docs_files += "/usr/share/man"

gawk-extras_files = ""
gawk-extras_files += "/usr/bin/igawk"
gawk-extras_files += "/usr/lib/awk"
gawk-extras_files += "/usr/share/awk"

gawk_files = ""
gawk_files += "gawk.manifest"
gawk_files += "TIZEN-Public-Domain COPYING"
gawk_files += "/usr/bin/awk"
gawk_files += "/usr/bin/gawk*"

FILES_${PN}-devel = "${gawk-devel_files}"
FILES_${PN}-docs = "${gawk-docs_files}"
FILES_${PN}-extras = "${gawk-extras_files}"
FILES_${PN} = "${gawk_files}"

PKG_gawk-devel= "gawk-devel"
PKG_gawk-docs= "gawk-docs"
PKG_gawk-extras= "gawk-extras"
PKG_gawk= "gawk"

require gawk-extraconf.inc
