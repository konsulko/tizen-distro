DESCRIPTION = "Command line software manager using libzypp"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Package Management"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by zypper 
PROVIDES += "zypper"
RPROVIDES_zypper += "zypper"

#PROVIDES by zypper-locale  
PROVIDES += "zypper-locale "
RPROVIDES_zypper-locale  += "zypper-locale "
# the PROVIDES rules is ignore "zypper-lang-all = 1.8.14"
PROVIDES += "zypper-lang-all"
RPROVIDES_zypper-locale  += "zypper-lang-all"

#PROVIDES by zypper-log 
PROVIDES += "zypper-log"
RPROVIDES_zypper-log += "zypper-log"

RDEPENDS = ""
#RDEPENDS of zypper (${PN})
RDEPENDS_${PN} += "libzypp"
RDEPENDS_${PN} += "procps"

#RDEPENDS of zypper-locale  (${PN}-locale )
RDEPENDS_${PN}-locale  += "zypper"

#RDEPENDS of zypper-log (${PN}-log)
RDEPENDS_${PN}-log += "python"


DEPENDS = ""
#DEPENDS of zypper 
DEPENDS += "gcc-cross"
DEPENDS += "cmake"
DEPENDS += "augeas"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "libzypp"
DEPENDS += "readline"
DEPENDS += "boost"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/zypper.manifest .
 
 
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
 
 mkdir build
 cd build
 
 # The code base is the same, but SLES11-SP1 (suse_version == 1110)
 # may use it's own set of .po files from po/sle-zypper-po.tar.bz2.
 unset TRANSLATION_SET
 
 cmake -DCMAKE_INSTALL_PREFIX=/usr \
       -DSYSCONFDIR=/etc \
       -DMANDIR=/usr/share/man \
       -DCMAKE_VERBOSE_MAKEFILE=TRUE \
       -DCMAKE_C_FLAGS_RELEASE:STRING="$RPM_OPT_FLAGS" \
       -DCMAKE_CXX_FLAGS_RELEASE:STRING="$RPM_OPT_FLAGS" \
       -DCMAKE_BUILD_TYPE=Release \
       -DUSE_TRANSLATION_SET=${TRANSLATION_SET:-zypper} \
       ..
 
 #gettextize -f
 make -j16
 make -C po -j16 translations
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 cd build
 make install DESTDIR=$RPM_BUILD_ROOT
 make -C po install DESTDIR=$RPM_BUILD_ROOT
 rm -f ${D}//usr/bin/aptitude
 # Create filelist with translations
 cd ..
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} zypper
 /bin/install -d -m755 $RPM_BUILD_ROOT/var/log
 touch $RPM_BUILD_ROOT/var/log/zypper.log
 rm ${D}/usr/share/doc/packages/zypper/COPYING
 
 
 
}

PACKAGES = ""
PACKAGES += "zypper-locale"
PACKAGES += "zypper"
PACKAGES += "zypper-log"

zypper-locale_files = ""

zypper_files = ""
zypper_files += "zypper.manifest"
zypper_files += "/etc/zypp/zypper.conf"
zypper_files += "/etc/logrotate.d/zypper.lr"
zypper_files += "/etc/logrotate.d/zypp-refresh.lr"
zypper_files += "/etc/bash_completion.d/zypper.sh"
zypper_files += "/usr/bin/zypper"
zypper_files += "/usr/bin/installation_sources"
zypper_files += "/usr/sbin/zypp-refresh"
zypper_files += "/usr/share/zypper"
zypper_files += "/usr/share/zypper/zypper.aug"
zypper_files += "/usr/share/zypper/xml"
zypper_files += "/usr/share/zypper/xml/xmlout.rnc"
zypper_files += "/usr/share/man/man8/zypper.8*"
zypper_files += "%dir /usr/share/doc/packages/zypper"
zypper_files += "/usr/share/doc/packages/zypper/TODO"
zypper_files += "/usr/share/doc/packages/zypper/zypper-rug"
zypper_files += "/usr/share/doc/packages/zypper/HACKING"

zypper-log_files = ""
zypper-log_files += "zypper.manifest"
zypper-log_files += "/usr/sbin/zypper-log"
zypper-log_files += "/usr/share/man/man8/zypper-log.8*"

FILES_${PN}-locale = "${zypper-locale_files}"
FILES_${PN} = "${zypper_files}"
FILES_${PN}-log = "${zypper-log_files}"

PKG_zypper-locale= "zypper-locale"
PKG_zypper= "zypper"
PKG_zypper-log= "zypper-log"

require zypper-extraconf.inc
