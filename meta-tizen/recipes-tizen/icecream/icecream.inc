DESCRIPTION = "For Distributed Compile in the Network"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Development/Tools/Building"
LICENSE = "GPLv2+  LGPLv2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libicecream-devel 
PROVIDES += "libicecream-devel"
RPROVIDES_libicecream-devel += "libicecream-devel"
RPROVIDES_libicecream-devel += "libicecream-dev"

#PROVIDES by icecream 
PROVIDES += "icecream"
RPROVIDES_icecream += "icecream"

RDEPENDS = ""
#RDEPENDS of libicecream-devel (lib${PN}-devel)
RDEPENDS_lib${PN}-devel += "libstdc++-dev"

#RDEPENDS of icecream (${PN})
RDEPENDS_${PN} += "/usr/bin/bzip2"
RDEPENDS_${PN} += "gcc-c++"
RDEPENDS_${PN} += "/bin/tar"


DEPENDS = ""
#DEPENDS of icecream 
DEPENDS += "gcc-cross"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n icecc-0.9.7
 
 
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
 
 export CFLAGS="$RPM_OPT_FLAGS"
 export CXXFLAGS="$RPM_OPT_FLAGS"
 
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
         --infodir=/usr/share/info
 make -j 16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 make DESTDIR=$RPM_BUILD_ROOT install
 mkdir -p $RPM_BUILD_ROOT/opt/icecream/bin
 for i in g++ gcc cc c++; do 
   ln -s /usr/bin/icecc $RPM_BUILD_ROOT/opt/icecream/bin/$i
   rm -f $RPM_BUILD_ROOT/usr/bin/$i
 done
 #
 # Install icecream init script
 mkdir -p $RPM_BUILD_ROOT/etc/init.d/
 install -m 755 suse/init.icecream $RPM_BUILD_ROOT/etc/init.d/icecream
 ln -sf /etc/init.d/icecream $RPM_BUILD_ROOT/usr/sbin/rcicecream
 mkdir -p $RPM_BUILD_ROOT/var/adm/fillup-templates
 install -m 644 suse/sysconfig.icecream $RPM_BUILD_ROOT/var/adm/fillup-templates/sysconfig.icecream
 mkdir -p $RPM_BUILD_ROOT/var/cache/icecream
 mkdir -p $RPM_BUILD_ROOT/usr/share/man/man{1,7}
 for i in mans/*.1 mans/*.7; do
 	install -m 644 $i $RPM_BUILD_ROOT/usr/share/man/man`echo $i | sed -e 's,.*\(.\)$,\1,'`/`basename $i`
 done
 install -m 644 -D suse/logrotate $RPM_BUILD_ROOT/etc/logrotate.d/icecream
 
 
}

PACKAGES = ""
PACKAGES += "libicecream-devel"
PACKAGES += "icecream"

libicecream-devel_files = ""
libicecream-devel_files += "/usr/include/icecc"
libicecream-devel_files += "/usr/lib/libicecc.*"
libicecream-devel_files += "/usr/lib/pkgconfig/icecc.pc"

icecream_files = ""
icecream_files += "/etc/logrotate.d/icecream"
icecream_files += "/etc/init.d/icecream"
icecream_files += "/usr/bin/icecc"
icecream_files += "/usr/bin/icerun"
icecream_files += "/usr/sbin/scheduler"
icecream_files += "/usr/lib/icecc"
icecream_files += "/usr/sbin/iceccd"
icecream_files += "/usr/sbin/rcicecream"
icecream_files += "/usr/share/man/man*/*"
icecream_files += "/opt/icecream"
icecream_files += "/var/adm/fillup-templates/sysconfig.icecream"

FILES_lib${PN}-devel = "${libicecream-devel_files}"
FILES_${PN} = "${icecream_files}"

PKG_libicecream-devel= "libicecream-devel"
PKG_icecream= "icecream"

require icecream-extraconf.inc
