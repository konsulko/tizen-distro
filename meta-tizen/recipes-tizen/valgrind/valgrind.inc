DESCRIPTION = "Memory Management Debugger"
HOMEPAGE = "http://valgrind.org/"
SECTION = "Development/Tools/Debuggers"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by valgrind-devel 
PROVIDES += "valgrind-devel"
RPROVIDES_valgrind-devel += "valgrind-devel"
RPROVIDES_valgrind-devel += "valgrind-dev"

#PROVIDES by valgrind 
PROVIDES += "valgrind"
RPROVIDES_valgrind += "valgrind"

#PROVIDES by valgrind-docs  
PROVIDES += "valgrind-docs "
RPROVIDES_valgrind-docs  += "valgrind-docs "

RDEPENDS = ""
#RDEPENDS of valgrind-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "valgrind"


DEPENDS = ""
#DEPENDS of valgrind 
DEPENDS += "gcc-cross"
DEPENDS += "docbook-4"
DEPENDS += "automake-native"
DEPENDS += "docbook-xsl-stylesheets"
DEPENDS += "libxslt"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/valgrind.manifest .
 
 
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
 
 export CFLAGS="-O2"
 export CXXFLAGS="-O2"
 
   CFLAGS="${CFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CFLAGS ; 
   CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
   FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -I%_fmoddir}" ; export FFLAGS ; 
   ./autogen.sh --build=${TARGET_SYS} --host=${HOST_SYS} \
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
         --infodir=/usr/share/info
 
 
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
         --infodir=/usr/share/info --enable-only64bit
 
 make -j16
 
 
 
 
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
 
 # extra documentation available online
 rm -rf ${D}/usr/share/doc/valgrind
 
 
 
}

PACKAGES = ""
PACKAGES += "valgrind-devel"
PACKAGES += "valgrind"
PACKAGES += "valgrind-docs"

valgrind-devel_files = ""
valgrind-devel_files += "valgrind.manifest"
valgrind-devel_files += "/usr/include/valgrind"
valgrind-devel_files += "/usr/lib/pkgconfig/valgrind.pc"

valgrind_files = ""
valgrind_files += "valgrind.manifest"
valgrind_files += "/usr/bin/*"
valgrind_files += "/usr/lib/valgrind"
valgrind_files += "/usr/lib/valgrind/*-amd64-linux"
valgrind_files += "/usr/lib/valgrind/*-linux.so"
valgrind_files += "/usr/lib/valgrind/*.supp"
valgrind_files += "/usr/lib/valgrind/32bit-core-valgrind-s*.xml"
valgrind_files += "/usr/lib/valgrind/32bit-core.xml"
valgrind_files += "/usr/lib/valgrind/32bit-linux-valgrind-s*.xml"
valgrind_files += "/usr/lib/valgrind/32bit-linux.xml"
valgrind_files += "/usr/lib/valgrind/32bit-sse-valgrind-s*.xml"
valgrind_files += "/usr/lib/valgrind/32bit-sse.xml"
valgrind_files += "/usr/lib/valgrind/64bit-avx-valgrind-s1.xml"
valgrind_files += "/usr/lib/valgrind/64bit-avx-valgrind-s2.xml"
valgrind_files += "/usr/lib/valgrind/64bit-avx.xml"
valgrind_files += "/usr/lib/valgrind/64bit-core-valgrind-s*.xml"
valgrind_files += "/usr/lib/valgrind/64bit-core.xml"
valgrind_files += "/usr/lib/valgrind/64bit-linux-valgrind-s*.xml"
valgrind_files += "/usr/lib/valgrind/64bit-linux.xml"
valgrind_files += "/usr/lib/valgrind/64bit-sse-valgrind-s*.xml"
valgrind_files += "/usr/lib/valgrind/64bit-sse.xml"
valgrind_files += "/usr/lib/valgrind/amd64-avx-coresse-valgrind.xml"
valgrind_files += "/usr/lib/valgrind/amd64-avx-coresse.xml"
valgrind_files += "/usr/lib/valgrind/amd64-avx-linux-valgrind.xml"
valgrind_files += "/usr/lib/valgrind/amd64-avx-linux.xml"
valgrind_files += "/usr/lib/valgrind/amd64-coresse-valgrind.xml"
valgrind_files += "/usr/lib/valgrind/amd64-linux-valgrind.xml"
valgrind_files += "/usr/lib/valgrind/arm-core-valgrind-s*.xml"
valgrind_files += "/usr/lib/valgrind/arm-core.xml"
valgrind_files += "/usr/lib/valgrind/arm-vfpv3-valgrind-s*.xml"
valgrind_files += "/usr/lib/valgrind/arm-vfpv3.xml"
valgrind_files += "/usr/lib/valgrind/arm-with-vfpv3-valgrind.xml"
valgrind_files += "/usr/lib/valgrind/arm-with-vfpv3.xml"
valgrind_files += "/usr/lib/valgrind/i386-coresse-valgrind.xml"
valgrind_files += "/usr/lib/valgrind/i386-linux-valgrind.xml"
valgrind_files += "/usr/lib/valgrind/mips-cp0-valgrind-s1.xml"
valgrind_files += "/usr/lib/valgrind/mips-cp0-valgrind-s2.xml"
valgrind_files += "/usr/lib/valgrind/mips-cp0.xml"
valgrind_files += "/usr/lib/valgrind/mips-cpu-valgrind-s1.xml"
valgrind_files += "/usr/lib/valgrind/mips-cpu-valgrind-s2.xml"
valgrind_files += "/usr/lib/valgrind/mips-cpu.xml"
valgrind_files += "/usr/lib/valgrind/mips-fpu-valgrind-s1.xml"
valgrind_files += "/usr/lib/valgrind/mips-fpu-valgrind-s2.xml"
valgrind_files += "/usr/lib/valgrind/mips-fpu.xml"
valgrind_files += "/usr/lib/valgrind/mips-linux-valgrind.xml"
valgrind_files += "/usr/lib/valgrind/mips-linux.xml"
valgrind_files += "/usr/lib/valgrind/power-altivec-valgrind-s*.xml"
valgrind_files += "/usr/lib/valgrind/power-altivec.xml"
valgrind_files += "/usr/lib/valgrind/power-core-valgrind-s1.xml"
valgrind_files += "/usr/lib/valgrind/power-core-valgrind-s2.xml"
valgrind_files += "/usr/lib/valgrind/power-core.xml"
valgrind_files += "/usr/lib/valgrind/power-fpu-valgrind-s*.xml"
valgrind_files += "/usr/lib/valgrind/power-fpu.xml"
valgrind_files += "/usr/lib/valgrind/power-linux-valgrind-s*.xml"
valgrind_files += "/usr/lib/valgrind/power-linux.xml"
valgrind_files += "/usr/lib/valgrind/power64-core-valgrind-s*.xml"
valgrind_files += "/usr/lib/valgrind/power64-core.xml"
valgrind_files += "/usr/lib/valgrind/power64-linux-valgrind-s*.xml"
valgrind_files += "/usr/lib/valgrind/power64-linux.xml"
valgrind_files += "/usr/lib/valgrind/powerpc-altivec32l-valgrind.xml"
valgrind_files += "/usr/lib/valgrind/powerpc-altivec32l.xml"
valgrind_files += "/usr/lib/valgrind/powerpc-altivec64l-valgrind.xml"
valgrind_files += "/usr/lib/valgrind/powerpc-altivec64l.xml"
valgrind_files += "/usr/lib/valgrind/s390-acr-valgrind-s1.xml"
valgrind_files += "/usr/lib/valgrind/s390-acr-valgrind-s2.xml"
valgrind_files += "/usr/lib/valgrind/s390-acr.xml"
valgrind_files += "/usr/lib/valgrind/s390-fpr-valgrind-s1.xml"
valgrind_files += "/usr/lib/valgrind/s390-fpr-valgrind-s2.xml"
valgrind_files += "/usr/lib/valgrind/s390-fpr.xml"
valgrind_files += "/usr/lib/valgrind/s390x-core64-valgrind-s1.xml"
valgrind_files += "/usr/lib/valgrind/s390x-core64-valgrind-s2.xml"
valgrind_files += "/usr/lib/valgrind/s390x-core64.xml"
valgrind_files += "/usr/lib/valgrind/s390x-generic-valgrind.xml"
valgrind_files += "/usr/lib/valgrind/s390x-generic.xml"
valgrind_files += "/usr/lib/valgrind/s390x-linux64-valgrind-s1.xml"
valgrind_files += "/usr/lib/valgrind/s390x-linux64-valgrind-s2.xml"
valgrind_files += "/usr/lib/valgrind/s390x-linux64.xml"

valgrind-docs_files = ""
valgrind-docs_files += "/usr/share/info"
valgrind-docs_files += "/usr/share/man"

FILES_${PN}-devel = "${valgrind-devel_files}"
FILES_${PN} = "${valgrind_files}"
FILES_${PN}-docs = "${valgrind-docs_files}"

PKG_valgrind-devel= "valgrind-devel"
PKG_valgrind= "valgrind"
PKG_valgrind-docs= "valgrind-docs"

require valgrind-extraconf.inc
