DESCRIPTION = "The Oil Runtime Compiler"
HOMEPAGE = "http://code.entropywave.com/projects/orc/"
SECTION = "Multimedia/Libraries"
LICENSE = "BSD-3-Clause"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by orc-doc 
PROVIDES += "orc-doc"
RPROVIDES_orc-doc += "orc-doc"

#PROVIDES by liborc 
PROVIDES += "liborc"
RPROVIDES_liborc += "liborc"

#PROVIDES by orc 
PROVIDES += "orc"
RPROVIDES_orc += "orc"
# the PROVIDES rules is ignore "orc-devel = 0.4.16"
PROVIDES += "orc-devel"
RPROVIDES_orc += "orc-devel"
RPROVIDES_orc += "orc-dev"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of orc 
DEPENDS += "libxslt"
DEPENDS += "pkgconfig-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/orc.manifest .
 
 
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
     --disable-static \
     --disable-gtk-doc
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
 # These are some examples that seem not to make sense to be distributed
 rm -rf ${D}/usr/lib/orc
 
 
 
}

PACKAGES = ""
PACKAGES += "orc-doc"
PACKAGES += "liborc"
PACKAGES += "orc"

orc-doc_files = ""
orc-doc_files += "orc.manifest"
orc-doc_files += "/usr/share/gtk-doc/html/orc/"

liborc_files = ""
liborc_files += "orc.manifest"
liborc_files += "/usr/lib/liborc*-0.4.so.*"

orc_files = ""
orc_files += "orc.manifest"
orc_files += "/usr/bin/orc-bugreport"
orc_files += "/usr/bin/orcc"
orc_files += "/usr/include/orc-0.4/"
orc_files += "/usr/lib/*.so"
orc_files += "/usr/lib/pkgconfig/orc-0.4.pc"
orc_files += "/usr/share/aclocal/orc.m4"

FILES_${PN}-doc = "${orc-doc_files}"
FILES_lib${PN} = "${liborc_files}"
FILES_${PN} = "${orc_files}"

PKG_orc-doc= "orc-doc"
PKG_liborc= "liborc"
PKG_orc= "orc"

require orc-extraconf.inc
