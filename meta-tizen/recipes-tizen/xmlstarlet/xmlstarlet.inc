DESCRIPTION = "Command Line Tool to Process XML Documents"
HOMEPAGE = "http://sourceforge.net/projects/xmlstar/"
SECTION = "Productivity/Publishing/XML"
LICENSE = "MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by xmlstarlet 
PROVIDES += "xmlstarlet"
RPROVIDES_xmlstarlet += "xmlstarlet"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of xmlstarlet 
DEPENDS += "gcc-cross"
DEPENDS += "libxml2"
DEPENDS += "automake-native"
DEPENDS += "libtool-cross"
DEPENDS += "libxslt"
DEPENDS += "autoconf-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 ##patch2
 
 
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
 
 export CFLAGS="$RPM_OPT_FLAGS -W -Wall"
 
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
     --disable-static-libs
 
 oe_runmake -j16
 
 exit 0
 oe_runmake tests
 
 
 
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
 #ln -s ${D}/usr/bin/xml ${D}/usr/bin/xmlstarlet
 
 #install -d _docs
 #/bin/mv "${D}/usr/share/doc"/* _docs/
 #/bin/rm -rf "${D}/usr/share/doc"
 rm -rf ${D}/usr/share
 
 
}

PACKAGES = ""
PACKAGES += "xmlstarlet"

xmlstarlet_files = ""
xmlstarlet_files += "/usr/bin/xml"

FILES_${PN} = "${xmlstarlet_files}"

PKG_xmlstarlet= "xmlstarlet"

require xmlstarlet-extraconf.inc
