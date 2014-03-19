DESCRIPTION = "A set of system configuration and setup files"
HOMEPAGE = "https://fedorahosted.org/setup/"
SECTION = "Base/Configuration"
LICENSE = "Public Domain"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by setup 
PROVIDES += "setup"
RPROVIDES_setup += "setup"

#PROVIDES by setup-docs  
PROVIDES += "setup-docs "
RPROVIDES_setup-docs  += "setup-docs "

#PROVIDES by setup-misc 
PROVIDES += "setup-misc"
RPROVIDES_setup-misc += "setup-misc"

RDEPENDS = ""
#RDEPENDS of setup-misc (${PN}-misc)
RDEPENDS_${PN}-misc += "setup"


DEPENDS = ""
#DEPENDS of setup 
DEPENDS += "bash"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 
 cp ${S}/packaging/setup.manifest .
 ./shadowconvert.sh
 
 
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
 
 
 exit 0
 # Run any sanity checks.
 make check
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 cp -ar files/* ${D}
 touch ${D}/etc/environment
 chmod 0644 ${D}/etc/environment
 chmod 0400 ${D}/etc/{shadow,gshadow}
 touch ${D}/etc/fstab
 ln -nsf /proc/self/mounts ${D}/etc/mtab
 
 
 rm ${D}//etc/filesystems
 
 #throw away useless and dangerous update stuff until rpm will be able to
 #handle it ( http://rpm.org/ticket/6 )
 
}

PACKAGES = ""
PACKAGES += "setup"
PACKAGES += "setup-misc"
PACKAGES += "setup-docs"

setup_files = ""
setup_files += "setup.manifest"
setup_files += "setup.manifest"
setup_files += "/etc/aliases"
setup_files += "/etc/environment"
setup_files += "/etc/host.conf"
setup_files += "/etc/printcap"
setup_files += "/etc/bashrc"
setup_files += "/etc/profile"
setup_files += "/etc/profile.d"
setup_files += "%verify(not md5 size mtime) /etc/shells"
setup_files += "/run/*"
setup_files += "/etc/profile.d/*"

setup-misc_files = ""
setup-misc_files += "setup.manifest"
setup-misc_files += "/usr/bin/*"
setup-misc_files += "/usr/sbin/*"

setup-docs_files = ""
setup-docs_files += "/usr/share/info"
setup-docs_files += "/usr/share/man"

FILES_${PN} = "${setup_files}"
FILES_${PN}-misc = "${setup-misc_files}"
FILES_${PN}-docs = "${setup-docs_files}"

PKG_setup= "setup"
PKG_setup-misc= "setup-misc"
PKG_setup-docs= "setup-docs"

require setup-extraconf.inc
