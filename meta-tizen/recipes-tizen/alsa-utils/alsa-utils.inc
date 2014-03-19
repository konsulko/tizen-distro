DESCRIPTION = "Advanced Linux Sound Architecture (ALSA) utilities"
HOMEPAGE = "http://www.alsa-project.org/"
SECTION = "Applications/Multimedia"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by alsa-utils-doc 
PROVIDES += "alsa-utils-doc"
RPROVIDES_alsa-utils-doc += "alsa-utils-doc"

#PROVIDES by alsa-utils 
PROVIDES += "alsa-utils"
RPROVIDES_alsa-utils += "alsa-utils"

RDEPENDS = ""
#RDEPENDS of alsa-utils-doc (${PN}-doc)
RDEPENDS_${PN}-doc += "alsa-utils"

#RDEPENDS of alsa-utils (${PN})
RDEPENDS_${PN} += "systemd"


DEPENDS = ""
#DEPENDS of alsa-utils 
DEPENDS += "alsa-lib"
DEPENDS += "systemd"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/alsa-utils.manifest .
 
 
 
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
     --disable-nls \
     --disable-xmlto \
     --disable-alsamixer \
     --disable-alsatest \
     --with-udev-rules-dir=/lib/udev/rules.d \
     --with-systemdsystemunitdir=/lib/systemd/system
 
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
 mkdir -p ${D}/var/lib/alsa
 
 
   rm -rf ${D}/usr/share/info 
   rm -rf ${D}/usr/share/doc/packages 
   rm -rf ${D}/usr/share/doc/alsa-utils 
   rm -rf ${D}/usr/share/doc/alsa-utils-1.0.26 
   rm -rf ${D}/usr/share/gtk-doc 
   rm -rf ${D}/usr/share/doc 
   rm -rf ${D}/usr/share/man 
   find ${D} -regex ".*/man/man./.*.[0-9]" | xargs rm -f -- 
   find ${D} -regex ".*/man/../man./.*.[0-9]" | xargs rm -f -- 
   find ${D} -regex ".*/man/man./.*.[0-9]pm" | xargs rm -f --
 
 
}

PACKAGES = ""
PACKAGES += "alsa-utils"

alsa-utils_files = ""
alsa-utils_files += "alsa-utils.manifest"
alsa-utils_files += "/usr/bin/*"
alsa-utils_files += "/usr/sbin/*"
alsa-utils_files += "/usr/share/alsa/*"
alsa-utils_files += "/usr/share/sounds/*"
alsa-utils_files += "/lib/udev/rules.d/90-alsa-restore.rules"
alsa-utils_files += "/lib/systemd/system/*.service"
alsa-utils_files += "/lib/systemd/system/basic.target.wants/alsa-restore.service"
alsa-utils_files += "/lib/systemd/system/shutdown.target.wants/alsa-store.service"
alsa-utils_files += "/var/lib/alsa"

FILES_${PN} = "${alsa-utils_files}"

PKG_alsa-utils= "alsa-utils"

require alsa-utils-extraconf.inc
