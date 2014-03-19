DESCRIPTION = "Software Update Tool"
HOMEPAGE = "http://www.tizen.org"
SECTION = "System/Management"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by swup 
PROVIDES += "swup"
RPROVIDES_swup += "swup"

RDEPENDS = ""
#RDEPENDS of swup (${PN})
RDEPENDS_${PN} += "python-rpm"
RDEPENDS_${PN} += "deltarpm"
RDEPENDS_${PN} += "python-lxml"
RDEPENDS_${PN} += "snapper"
RDEPENDS_${PN} += "python-yaml"


DEPENDS = ""
#DEPENDS of swup 
DEPENDS += "systemd"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/swup.manifest .
 
 
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
 
 mkdir -p ${D}//lib/systemd/system/system-update.target.wants 
 ln -s ../system-update@update.service  ${D}//lib/systemd/system/system-update.target.wants/system-update@update.service  
 
 mkdir -p ${D}//lib/systemd/system/system-restore.target.wants 
 ln -s ../system-update@system.service  ${D}//lib/systemd/system/system-restore.target.wants/system-update@system.service  
 
 mkdir -p ${D}//lib/systemd/system/factory-reset.target.wants 
 ln -s ../system-update@factory.service  ${D}//lib/systemd/system/factory-reset.target.wants/system-update@factory.service  
 # fix symlinks
 ln -sf ../system-update@.service ${D}//lib/systemd/system/system-update.target.wants/system-update@update.service
 ln -sf ../system-update@.service ${D}//lib/systemd/system/system-restore.target.wants/system-update@system.service
 ln -sf ../system-update@.service ${D}//lib/systemd/system/factory-reset.target.wants/system-update@factory.service
 
 
}

PACKAGES = ""
PACKAGES += "swup"

swup_files = ""
swup_files += "swup.manifest"
swup_files += "/usr/bin/swup"
swup_files += "/usr/bin/system-update"
swup_files += "/lib/systemd/system/system-update@.service"
swup_files += "/lib/systemd/system/system-restore.target"
swup_files += "/lib/systemd/system/factory-reset.target"
swup_files += "/lib/systemd/system/system-update.target.wants/system-update@update.service"
swup_files += "/lib/systemd/system/system-restore.target.wants/system-update@system.service"
swup_files += "/lib/systemd/system/factory-reset.target.wants/system-update@factory.service"

FILES_${PN} = "${swup_files}"

PKG_swup= "swup"

require swup-extraconf.inc
