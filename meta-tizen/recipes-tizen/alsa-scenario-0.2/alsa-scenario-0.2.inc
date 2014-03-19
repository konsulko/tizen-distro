DESCRIPTION = "ALSA Scenario pkg"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Multimedia/Audio"
LICENSE = "LGPLv2+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by alsa-scenario-devel 
PROVIDES += "alsa-scenario-devel"
RPROVIDES_alsa-scenario-devel += "alsa-scenario-devel"
RPROVIDES_alsa-scenario-devel += "alsa-scenario-dev"

#PROVIDES by alsa-scenario 
PROVIDES += "alsa-scenario"
RPROVIDES_alsa-scenario += "alsa-scenario"

RDEPENDS = ""
#RDEPENDS of alsa-scenario-devel (alsa-scenario-devel)
RDEPENDS_alsa-scenario-devel += "alsa-scenario"


DEPENDS = ""
#DEPENDS of alsa-scenario 
DEPENDS += "pkgconfig(alsa)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/alsa-scenario.manifest .
 
 
 
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
 
 cp -f /usr/share/libtool/config/config.guess ${WORKDIR}/alsa-scenario-0.2.1/
 cp -f /usr/share/libtool/config/config.sub ${WORKDIR}/alsa-scenario-0.2.1/
 
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
         --infodir=/usr/share/info --disable-static
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
 
 
}

PACKAGES = ""
PACKAGES += "alsa-scenario-devel"
PACKAGES += "alsa-scenario"

alsa-scenario-devel_files = ""
alsa-scenario-devel_files += "alsa-scenario.manifest"
alsa-scenario-devel_files += "/usr/include/alsa/*.h"
alsa-scenario-devel_files += "/usr/lib/libascenario.so"
alsa-scenario-devel_files += "/usr/lib/pkgconfig/libascenario.pc"

alsa-scenario_files = ""
alsa-scenario_files += "alsa-scenario.manifest"
alsa-scenario_files += "/usr/lib/libascenario-0.2.so.*"

FILES_${PN}-devel = "${alsa-scenario-devel_files}"
FILES_${PN} = "${alsa-scenario_files}"

PKG_alsa-scenario-devel= "alsa-scenario-devel"
PKG_alsa-scenario= "alsa-scenario"

require alsa-scenario-0.2-extraconf.inc
