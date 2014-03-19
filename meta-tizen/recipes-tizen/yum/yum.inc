DESCRIPTION = "RPM package installer/updater/manager"
HOMEPAGE = "http://yum.baseurl.org/"
SECTION = "System/Base"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by yum 
PROVIDES += "yum"
RPROVIDES_yum += "yum"

RDEPENDS = ""
#RDEPENDS of yum (${PN})
RDEPENDS_${PN} += "python-urlgrabber"
RDEPENDS_${PN} += "python"
RDEPENDS_${PN} += "python-rpm"
RDEPENDS_${PN} += "python-iniparse"
RDEPENDS_${PN} += "rpm"
RDEPENDS_${PN} += "yum-metadata-parser"
RDEPENDS_${PN} += "python-gpgme"


DEPENDS = ""
#DEPENDS of yum 
DEPENDS += "intltool-native"
DEPENDS += "python-urlgrabber"
inherit pythonnative
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "python-rpm"
DEPENDS += "python-nose"
DEPENDS += "python-iniparse"
DEPENDS += "rpm"
DEPENDS += "yum-metadata-parser"
DEPENDS += "python-gpgme"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/yum.manifest .
 
 
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
 
 make
 
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
 
 make DESTDIR=${D} UNITDIR=/lib/systemd/system install
 install -m 644 ${S}/packaging/yum.conf ${D}//etc/yum.conf
 mkdir -p ${D}//etc/yum/pluginconf.d ${D}//usr/lib/yum-plugins
 mkdir -p ${D}//usr/share/yum-plugins
 
 mv ${D}//etc/yum/repos.d ${D}//etc/yum.repos.d
 
 # yum-updatesd has moved to the separate source version
 rm -f ${D}//etc/yum/yum.conf
 rm -f ${D}//etc/yum/yum-updatesd.conf
 rm -f ${D}//etc/rc.d/init.d/yum-updatesd
 rm -f ${D}//etc/dbus-1/system.d/yum-updatesd.conf
 rm -f ${D}//usr/sbin/yum-updatesd
 rm -f ${D}//usr/share/man/man*/yum-updatesd*
 rm -f ${D}//usr/share/yum-cli/yumupd.py*
 
 rm -rf ${D}/etc/cron.daily
 rm -rf ${D}/etc/sysconfig/yum-cron
 rm -rf ${D}/etc/yum/yum-daily.yum
 rm -rf ${D}/etc/yum/yum-weekly.yum
 rm -rf ${D}/etc/rc.d/init.d
 
 # Ghost files:
 mkdir -p ${D}/var/lib/yum/history
 mkdir -p ${D}/var/lib/yum/plugins
 mkdir -p ${D}/var/lib/yum/yumdb
 touch ${D}/var/lib/yum/uuid
 
 # rpmlint bogus stuff...
 chmod +x ${D}//usr/share/yum-cli/*.py
 chmod +x ${D}//usr/lib/python2.7/site-packages/yum/*.py
 chmod +x ${D}//usr/lib/python2.7/site-packages/rpmUtils/*.py
 
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} yum
 
 
 
 
}

PACKAGES = ""
PACKAGES += "yum"

yum_files = ""
yum_files += "yum.manifest"
yum_files += "/etc/yum.conf"
yum_files += "/etc/yum.repos.d"
yum_files += "/etc/yum/version-groups.conf"
yum_files += "/etc/yum"
yum_files += "/etc/yum/protected.d"
yum_files += "/etc/yum/vars"
yum_files += "/etc/logrotate.d/yum"
yum_files += "/etc/bash_completion.d"
yum_files += "/usr/share/yum-cli/"
yum_files += "/usr/bin/yum"
yum_files += "/usr/lib/python2.7/site-packages/yum"
yum_files += "/usr/lib/python2.7/site-packages/rpmUtils"
yum_files += "/var/cache/yum"
yum_files += "/var/lib/yum"
yum_files += "/usr/share/man/man*/yum.*"
yum_files += "/usr/share/man/man*/yum-shell*"
yum_files += "/etc/yum/pluginconf.d"
yum_files += "/usr/lib/yum-plugins"
yum_files += "/usr/share/yum-plugins"

FILES_${PN} = "${yum_files}"

PKG_yum= "yum"

require yum-extraconf.inc
