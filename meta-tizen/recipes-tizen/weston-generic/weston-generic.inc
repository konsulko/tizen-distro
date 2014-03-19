DESCRIPTION = "Tizen Generic Weston configuration and set-up"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Base/Configuration"
LICENSE = "MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by weston-generic 
PROVIDES += "weston-generic"
RPROVIDES_weston-generic += "weston-generic"
# the PROVIDES rules is ignore "weston-startup  "
PROVIDES += "weston-startup"
RPROVIDES_weston-generic += "weston-startup"

#PROVIDES by weston-generic-config 
PROVIDES += "weston-generic-config"
RPROVIDES_weston-generic-config += "weston-generic-config"

RDEPENDS = ""

DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/weston-generic.manifest .
 
 
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
 
 
 install -d ${D}/lib/systemd/user/weston.target.wants
 install -m 644 weston.service ${D}/lib/systemd/user/weston.service
 ln -sf ../weston.service ${D}//lib/systemd/user/weston.target.wants/
 
 mkdir -p ${D}/etc/profile.d/
 install -m 0644 weston.sh ${D}/etc/profile.d/
 
 mkdir -p ${D}/etc/xdg/weston
 install -m 0644 weston.ini ${D}/etc/xdg/weston
 
 
}

PACKAGES = ""
PACKAGES += "weston-generic-config"
PACKAGES += "weston-generic"

weston-generic-config_files = ""
weston-generic-config_files += "weston-generic.manifest"
weston-generic-config_files += "/etc/xdg/weston/weston.ini"

weston-generic_files = ""
weston-generic_files += "weston-generic.manifest"
weston-generic_files += "/lib/systemd/user/weston.service"
weston-generic_files += "/lib/systemd/user/weston.target.wants/weston.service"
weston-generic_files += "/etc/profile.d/*"

FILES_${PN}-config = "${weston-generic-config_files}"
FILES_${PN} = "${weston-generic_files}"

PKG_weston-generic-config= "weston-generic-config"
PKG_weston-generic= "weston-generic"

require weston-generic-extraconf.inc
