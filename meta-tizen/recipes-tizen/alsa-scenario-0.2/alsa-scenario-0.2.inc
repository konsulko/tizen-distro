DESCRIPTION = "ALSA Scenario pkg"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Multimedia/Audio"
LICENSE = "LGPLv2+"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND += ""
PROVIDES = ""

#PROVIDES by alsa-scenario-dev 


#PROVIDES by alsa-scenario 


RDEPENDS = ""
#RDEPENDS of alsa-scenario-dev (alsa-scenario-dev)
RDEPENDS_alsa-scenario-dev += "alsa-scenario"


DEPENDS = ""
#DEPENDS of alsa-scenario 
DEPENDS += "alsa-lib"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/alsa-scenario.manifest .
 
 
 
}
do_patch_append() {
    bb.build.exec_func('do_prep', d)
}

do_configure() {
}

do_compile() {
 cd ${S}
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
         --prefix=${prefix} \
         --exec-prefix=${prefix} \
         --bindir=${prefix}/bin \
         --sbindir=${prefix}/sbin \
         --sysconfdir=${sysconfdir} \
         --datadir=${prefix}/share \
         --includedir=${prefix}/include \
         --libdir=${prefix}/lib \
         --libexecdir=${prefix}/libexec \
         --localstatedir=${localstatedir} \
         --sharedstatedir=${prefix}/com \
         --mandir=${mandir} \
         --infodir=${infodir} --disable-static
 make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=${prefix}/bin \
   install  
   rm -f ${D}${infodir}/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 
}

PACKAGES += " alsa-scenario-dev "
PACKAGES += " alsa-scenario "

alsa-scenario-dev_files = ""
alsa-scenario-dev_files += "alsa-scenario.manifest"
alsa-scenario-dev_files += "${prefix}/include/alsa/*.h"
alsa-scenario-dev_files += "${prefix}/lib/libascenario.so"
alsa-scenario-dev_files += "${prefix}/lib/pkgconfig/libascenario.pc"

alsa-scenario_files = ""
alsa-scenario_files += "alsa-scenario.manifest"
alsa-scenario_files += "${prefix}/lib/libascenario-0.2.so.*"

FILES_${PN}-dev = "${alsa-scenario-dev_files}"
FILES_${PN} = "${alsa-scenario_files}"

PKG_alsa-scenario-dev= "alsa-scenario-dev"
PKG_alsa-scenario= "alsa-scenario"

require alsa-scenario-0.2-extraconf.inc

