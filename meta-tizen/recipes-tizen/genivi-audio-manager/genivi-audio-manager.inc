DESCRIPTION = "GENIVI Audio Manager"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Automotive/API"
LICENSE = "MPL-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by genivi-audio-manager-dev
PROVIDES += "genivi-audio-manager-dev"


#PROVIDES by genivi-audio-manager


RDEPENDS = ""
#RDEPENDS of genivi-audio-manager-dev (${PN}-dev)
RDEPENDS_${PN}-dev += "genivi-audio-manager"

#RDEPENDS of genivi-audio-manager (${PN})
RDEPENDS_${PN} += "eglibc"


DEPENDS = ""
#DEPENDS of genivi-audio-manager
DEPENDS += "systemd"
DEPENDS += "dlt-daemon"
DEPENDS_append_class-native = " cmake-native"
DEPENDS_append_class-target = " cmake-native"
inherit pythonnative
DEPENDS += "dbus"
DEPENDS += "zlib"
DEPENDS += "sqlite3"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n genivi-audio-manager-3.2
 
 
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
 LD_AS_NEEDED=1; export LD_AS_NEEDED ;
 
 mkdir build
 cd build
 
 cmake -DUSE_BUILD_LIBS=OFF -DWITH_TESTS=OFF -DWITH_DBUS_WRAPPER=ON -DWITH_NSM=OFF -DCMAKE_INSTALL_PREFIX=/usr ..
 #make VERBOSE=1
 make ${PARALLEL_MAKE} 
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D}
 mkdir -p ${D}
 
 rm -rf "$RPM_BUILD_ROOT"
 cd build
 make install DESTDIR=$RPM_BUILD_ROOT
 mkdir $RPM_BUILD_ROOT${prefix}/include/genivi-audio-manager
 mv $RPM_BUILD_ROOT${prefix}/include/*.h $RPM_BUILD_ROOT${prefix}/include/command $RPM_BUILD_ROOT${prefix}/include/control $RPM_BUILD_ROOT${prefix}/include/routing $RPM_BUILD_ROOT${prefix}/include/shared $RPM_BUILD_ROOT${prefix}/include/genivi-audio-manager
 rm $RPM_BUILD_ROOT${prefix}/lib/audioManager/routing/libPluginRoutingInterfaceAsync.so*
 
 
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " genivi-audio-manager-dev "
PACKAGES += " genivi-audio-manager "

genivi-audio-manager-dev_files = ""
genivi-audio-manager-dev_files += "${prefix}/include/genivi-audio-manager/*"

genivi-audio-manager_files = ""
genivi-audio-manager_files += "LICENCE README.html"
genivi-audio-manager_files += "${prefix}/bin/AudioManager"
genivi-audio-manager_files += "${prefix}/lib/audioManager/command/libPluginCommandInterfaceDbus.so*"
genivi-audio-manager_files += "${prefix}/lib/audioManager/routing/libPluginRoutingInterfaceDbus.so*"
genivi-audio-manager_files += "${prefix}/lib/audioManager/control/libPluginControlInterface.so*"
genivi-audio-manager_files += "${prefix}/lib/audioManager/control/libPluginControlInterfaceDbus.so*"
genivi-audio-manager_files += "${prefix}/share/audiomanager/*xml"

FILES_${PN}-dev = "${genivi-audio-manager-dev_files}"
FILES_${PN} = "${genivi-audio-manager_files}"

PKG_genivi-audio-manager-dev= "genivi-audio-manager-dev"
PKG_genivi-audio-manager= "genivi-audio-manager"

require genivi-audio-manager-extraconf.inc

