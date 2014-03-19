DESCRIPTION = "Agent Application basic"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Application Framework/Service"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by appcore-agent 
PROVIDES += "appcore-agent"
RPROVIDES_appcore-agent += "appcore-agent"

#PROVIDES by appcore-agent-devel 
PROVIDES += "appcore-agent-devel"
RPROVIDES_appcore-agent-devel += "appcore-agent-devel"
RPROVIDES_appcore-agent-devel += "appcore-agent-dev"

RDEPENDS = ""
#RDEPENDS of appcore-agent-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "appcore-agent"


DEPENDS = ""
#DEPENDS of appcore-agent 
DEPENDS += "sysman-devel"
DEPENDS += "pkgconfig(aul)"
DEPENDS += "pkgconfig(sysman)"
DEPENDS += "pkgconfig(pmapi)"
DEPENDS += "pkgconfig(capi-appfw-application)"
DEPENDS += "cmake"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "pkgconfig(dlog)"
DEPENDS += "pkgconfig(vconf)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/appcore-agent.manifest .
 
 
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
   FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export FFLAGS ; 
   cmake \
         -DCMAKE_VERBOSE_MAKEFILE=ON \
         -DCMAKE_INSTALL_PREFIX:PATH=/usr \
         -DCMAKE_INSTALL_LIBDIR:PATH=/usr/lib \
         -DINCLUDE_INSTALL_DIR:PATH=/usr/include \
         -DLIB_INSTALL_DIR:PATH=/usr/lib \
         -DSYSCONF_INSTALL_DIR:PATH=/etc \
         -DSHARE_INSTALL_PREFIX:PATH=/usr/share \
         -DCMAKE_SKIP_RPATH:BOOL=ON \
         -DBUILD_SHARED_LIBS:BOOL=ON \
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake .
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
PACKAGES += "appcore-agent"
PACKAGES += "appcore-agent-devel"

appcore-agent_files = ""
appcore-agent_files += "appcore-agent.manifest"
appcore-agent_files += "appcore-agent.manifest"
appcore-agent_files += "/usr/lib/libappcore-agent.so.1"
appcore-agent_files += "/usr/lib/libappcore-agent.so.1.1"

appcore-agent-devel_files = ""
appcore-agent-devel_files += "appcore-agent.manifest"
appcore-agent-devel_files += "/usr/lib/pkgconfig/appcore-agent.pc"
appcore-agent-devel_files += "/usr/lib/libappcore-agent.so"
appcore-agent-devel_files += "/usr/include/appcore-agent/appcore-agent.h"
appcore-agent-devel_files += "/usr/include/appcore-agent/service_app.h"

FILES_${PN} = "${appcore-agent_files}"
FILES_${PN}-devel = "${appcore-agent-devel_files}"

PKG_appcore-agent= "appcore-agent"
PKG_appcore-agent-devel= "appcore-agent-devel"

require appcore-agent-extraconf.inc
