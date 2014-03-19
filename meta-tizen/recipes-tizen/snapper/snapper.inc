DESCRIPTION = "Tool for filesystem snapshot management"
HOMEPAGE = "http://en.opensuse.org/Portal:Snapper"
SECTION = "System/Utilities"
LICENSE = "GPL-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libsnapper 
PROVIDES += "libsnapper"
RPROVIDES_libsnapper += "libsnapper"

#PROVIDES by snapper-locale  
PROVIDES += "snapper-locale "
RPROVIDES_snapper-locale  += "snapper-locale "
# the PROVIDES rules is ignore "snapper-lang-all = 0.1.5"
PROVIDES += "snapper-lang-all"
RPROVIDES_snapper-locale  += "snapper-lang-all"

#PROVIDES by snapper-zypp-plugin 
PROVIDES += "snapper-zypp-plugin"
RPROVIDES_snapper-zypp-plugin += "snapper-zypp-plugin"

#PROVIDES by libsnapper-devel 
PROVIDES += "libsnapper-devel"
RPROVIDES_libsnapper-devel += "libsnapper-devel"
RPROVIDES_libsnapper-devel += "libsnapper-dev"

#PROVIDES by snapper 
PROVIDES += "snapper"
RPROVIDES_snapper += "snapper"

RDEPENDS = ""
#RDEPENDS of libsnapper (lib${PN})
RDEPENDS_lib${PN} += "util-linux"

#RDEPENDS of snapper-locale  (${PN}-locale )
RDEPENDS_${PN}-locale  += "snapper"

#RDEPENDS of snapper-zypp-plugin (${PN}-zypp-plugin)
RDEPENDS_${PN}-zypp-plugin += "zypp-plugin-python"
RDEPENDS_${PN}-zypp-plugin += "snapper"
RDEPENDS_${PN}-zypp-plugin += "dbus-python"
RDEPENDS_${PN}-zypp-plugin += "libzypp(plugin:commit)"

#RDEPENDS of libsnapper-devel (lib${PN}-devel)
RDEPENDS_lib${PN}-devel += "libsnapper"
RDEPENDS_lib${PN}-devel += "libxml2-dev"
RDEPENDS_lib${PN}-devel += "boost-dev"
RDEPENDS_lib${PN}-devel += "gcc-c++"
RDEPENDS_lib${PN}-devel += "libstdc++-dev"

#RDEPENDS of snapper (${PN})
RDEPENDS_${PN} += "libsnapper"
RDEPENDS_${PN} += "diffutils"


DEPENDS = ""
#DEPENDS of snapper 
DEPENDS += "gcc-cross"
DEPENDS += "doxygen"
DEPENDS += "pkgconfig(dbus-1)"
DEPENDS += "libxml2"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "libzypp"
DEPENDS += "sed"
DEPENDS += "libtool-cross"
DEPENDS += "boost"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -n snapper-0.1.5
 cp ${S}/packaging/snapper.manifest .
 
 
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
 
 export CFLAGS="$RPM_OPT_FLAGS -DNDEBUG"
 export CXXFLAGS="$RPM_OPT_FLAGS -DNDEBUG"
 
 
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
         --infodir=/usr/share/info --disable-ext4 --disable-silent-rules --disable-pam
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
 
 mkdir -p $RPM_BUILD_ROOT/usr/lib/systemd/system/
 mkdir -p $RPM_BUILD_ROOT/usr/lib/systemd/system/multi-user.target.wants
 
 install -D scripts/snapper-hourly $RPM_BUILD_ROOT/usr/sbin/snapper-hourly
 install -D scripts/snapper-daily $RPM_BUILD_ROOT/usr/sbin/snapper-daily
 install -D data/snapper-hourly.timer $RPM_BUILD_ROOT/usr/lib/systemd/system/snapper-hourly.timer
 install -D data/snapper-hourly.service $RPM_BUILD_ROOT/usr/lib/systemd/system/snapper-hourly.service
 install -D data/snapper-daily.timer $RPM_BUILD_ROOT/usr/lib/systemd/system/snapper-daily.timer
 install -D data/snapper-daily.service $RPM_BUILD_ROOT/usr/lib/systemd/system/snapper-daily.service
 install -D data/sysconfig.snapper $RPM_BUILD_ROOT/etc/sysconfig/snapper
 install -D $RPM_BUILD_ROOT/etc/snapper/config-templates/default $RPM_BUILD_ROOT/etc/snapper/configs/root
 
 sed -i 's|ALLOW_USERS=""|ALLOW_USERS="root"|' $RPM_BUILD_ROOT/etc/snapper/configs/root
 sed -i 's|SNAPPER_CONFIGS=""|SNAPPER_CONFIGS="root"|' $RPM_BUILD_ROOT/etc/sysconfig/snapper
 
 
 mkdir -p ${D}//lib/systemd/system/multi-user.target.wants 
 ln -s ../snapper-hourly.timer  ${D}//lib/systemd/system/multi-user.target.wants/snapper-hourly.timer  
 
 mkdir -p ${D}//lib/systemd/system/multi-user.target.wants 
 ln -s ../snapper-daily.timer  ${D}//lib/systemd/system/multi-user.target.wants/snapper-daily.timer  
 
 rm -rf ${D}/usr/share/doc/snapper
 
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} snapper
 
 
}

PACKAGES = ""
PACKAGES += "libsnapper"
PACKAGES += "snapper-locale"
PACKAGES += "libsnapper-devel"
PACKAGES += "snapper-zypp-plugin"
PACKAGES += "snapper"

libsnapper_files = ""
libsnapper_files += "snapper.manifest"
libsnapper_files += "/usr/lib/libsnapper.so.*"
libsnapper_files += "/etc/snapper"
libsnapper_files += "/etc/snapper/configs"
libsnapper_files += "/etc/snapper/configs/root"
libsnapper_files += "/etc/snapper/config-templates"
libsnapper_files += "/etc/snapper/config-templates/default"
libsnapper_files += "/etc/snapper/filters"
libsnapper_files += "/etc/snapper/filters/*.txt"
libsnapper_files += "/etc/sysconfig/snapper"

snapper-locale_files = ""

libsnapper-devel_files = ""
libsnapper-devel_files += "snapper.manifest"
libsnapper-devel_files += "/usr/lib/libsnapper.so"
libsnapper-devel_files += "/usr/include/snapper"

snapper-zypp-plugin_files = ""
snapper-zypp-plugin_files += "snapper.manifest"
snapper-zypp-plugin_files += "/usr/lib/zypp/plugins/commit/snapper.py*"

snapper_files = ""
snapper_files += "snapper.manifest"
snapper_files += "/usr/bin/snapper"
snapper_files += "/usr/sbin/snapperd"
snapper_files += "/usr/sbin/snapper-hourly"
snapper_files += "/usr/sbin/snapper-daily"
snapper_files += "/etc/dbus-1/system.d/org.opensuse.Snapper.conf"
snapper_files += "/usr/share/dbus-1/system-services/org.opensuse.Snapper.service"
snapper_files += "/lib/systemd/system/snapper-hourly.timer"
snapper_files += "/lib/systemd/system/multi-user.target.wants/snapper-hourly.timer"
snapper_files += "/lib/systemd/system/snapper-hourly.service"
snapper_files += "/lib/systemd/system/snapper-daily.timer"
snapper_files += "/lib/systemd/system/multi-user.target.wants/snapper-daily.timer"
snapper_files += "/lib/systemd/system/snapper-daily.service"

FILES_lib${PN} = "${libsnapper_files}"
FILES_${PN}-locale = "${snapper-locale_files}"
FILES_lib${PN}-devel = "${libsnapper-devel_files}"
FILES_${PN}-zypp-plugin = "${snapper-zypp-plugin_files}"
FILES_${PN} = "${snapper_files}"

PKG_libsnapper= "libsnapper"
PKG_snapper-locale= "snapper-locale"
PKG_libsnapper-devel= "libsnapper-devel"
PKG_snapper-zypp-plugin= "snapper-zypp-plugin"
PKG_snapper= "snapper"

require snapper-extraconf.inc
