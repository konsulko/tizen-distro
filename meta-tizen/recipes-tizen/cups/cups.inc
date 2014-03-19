DESCRIPTION = "The Common UNIX Printing System"
HOMEPAGE = "http://www.cups.org/"
SECTION = "Hardware/Printing"
LICENSE = "GPL-2.0+  LGPL-2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by cups-devel 
PROVIDES += "cups-devel"
RPROVIDES_cups-devel += "cups-devel"
RPROVIDES_cups-devel += "cups-dev"

#PROVIDES by cups-ddk 
PROVIDES += "cups-ddk"
RPROVIDES_cups-ddk += "cups-ddk"
# the PROVIDES rules is ignore "cupsddk = 1.6.4"
PROVIDES += "cupsddk"
RPROVIDES_cups-ddk += "cupsddk"

#PROVIDES by cups 
PROVIDES += "cups"
RPROVIDES_cups += "cups"

#PROVIDES by cups-libs 
PROVIDES += "cups-libs"
RPROVIDES_cups-libs += "cups-libs"

#PROVIDES by cups-client 
PROVIDES += "cups-client"
RPROVIDES_cups-client += "cups-client"

RDEPENDS = ""
#RDEPENDS of cups-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "zlib-dev"
RDEPENDS_${PN}-devel += "glibc-dev"
RDEPENDS_${PN}-devel += "libopenssl-dev"
RDEPENDS_${PN}-devel += "cups-libs"
RDEPENDS_${PN}-devel += "libjpeg-dev"
RDEPENDS_${PN}-devel += "systemd-dev"
RDEPENDS_${PN}-devel += "libpng-dev"
RDEPENDS_${PN}-devel += "libtiff-dev"
RDEPENDS_${PN}-devel += "pam-dev"

#RDEPENDS of cups (${PN})
RDEPENDS_${PN} += "systemd"
RDEPENDS_${PN} += "cups-libs"
RDEPENDS_${PN} += "/usr/sbin/groupadd"
RDEPENDS_${PN} += "cups-client"
RDEPENDS_${PN} += "/usr/bin/pdftops"
RDEPENDS_${PN} += "util-linux"

#RDEPENDS of cups-ddk (${PN}-ddk)
RDEPENDS_${PN}-ddk += "cups-dev"
RDEPENDS_${PN}-ddk += "cups"

#RDEPENDS of cups-client (${PN}-client)
RDEPENDS_${PN}-client += "cups-libs"


DEPENDS = ""
#DEPENDS of cups 
DEPENDS += "zlib-devel"
DEPENDS += "libpng-devel"
DEPENDS += "libopenssl-devel"
DEPENDS += "libjpeg-devel"
DEPENDS += "pkgconfig(dbus-1)"
DEPENDS += "gcc-c++"
DEPENDS += "pkgconfig-native"
DEPENDS += "update-desktop-files"
DEPENDS += "libtool-cross"
DEPENDS += "systemd-devel"
DEPENDS += "fdupes-native"
DEPENDS += "libtiff-devel"
DEPENDS += "pam-devel"

do_patch() {
 # Be quiet when unpacking:
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n cups-1.6.4
 cp ${S}/packaging/cups.manifest .
 
 
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
 
 # Disable SILENT run of make so that make runs verbose as usual:
 sed -i -e 's/^\.SILENT:/# .SILENT:/' Makedefs.in
 libtoolize --force
 aclocal
 autoconf
 export CXXFLAGS="$CXXFLAGS $RPM_OPT_FLAGS -O2 -fstack-protector"
 export CFLAGS="$RPM_OPT_FLAGS -fstack-protector -DLDAP_DEPRECATED"
 export CXX=g++
 # As long as cups-1.4.3-default-webcontent-path.patch is applied
 # configure --with-docdir=... would be no longer needed
 # because cups-1.4.3-default-webcontent-path.patch changes the
 # default with-docdir path whereto the web content is installed
 # from /usr/share/doc/cups to /usr/share/cups/webcontent because the
 # files of the CUPS web content are no documentation, see CUPS STR #3578
 # and http://bugzilla.novell.com/show_bug.cgi?id=546023#c6 and subsequent comments
 # so that the new default could be used as is but upstream may accept
 # cups-1.4.3-default-webcontent-path.patch in general but change its default
 # so that with-docdir is explicitly set here to be future proof:
 
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
 	--mandir=/usr/share/man \
 	--sysconfdir=/etc \
 	--libdir=/usr/lib \
 	--datadir=/usr/share \
 	--with-docdir=/usr/share/cups/webcontent \
 	--with-cups-user=lp \
 	--with-cups-group=lp \
 	--enable-debug \
 	--enable-relro \
 	--enable-gssapi \
 	--disable-static \
 	--without-rcdir \
 	--enable-dbus \
 	--enable-ldap \
 	--with-java \
 	--with-php \
 	--with-python \
 	--with-cachedir=/var/cache/cups \
 	--with-pdftops=/usr/bin/pdftops \
 	--without-xinetd \
 	--prefix=/
 make -j16 CXX=g++
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 make BUILDROOT=$RPM_BUILD_ROOT install
 # Use Ghostscript fonts instead of CUPS fonts:
 rm -rf $RPM_BUILD_ROOT/usr/share/cups/fonts
 mkdir -p $RPM_BUILD_ROOT/usr/share/ghostscript/fonts
 ln -sf /usr/share/ghostscript/fonts $RPM_BUILD_ROOT/usr/share/cups/
 # Make directory for ssl files:
 mkdir -p $RPM_BUILD_ROOT/etc/cups/ssl
 # Add a client.conf as template (Source108: cups-client.conf):
 install -m644 ${S}/packaging/cups-client.conf $RPM_BUILD_ROOT/etc/cups/client.conf
 # Make the libraries accessible also via generic named links:
 ln -sf libcupsimage.so.2 $RPM_BUILD_ROOT/usr/lib/libcupsimage.so
 ln -sf libcups.so.2 $RPM_BUILD_ROOT/usr/lib/libcups.so
 # Add missing usual directories:
 install -d -m755 $RPM_BUILD_ROOT/usr/share/cups/drivers
 install -d -m755 $RPM_BUILD_ROOT/var/cache/cups
 # Add conf/pam.tizen regarding support for PAM (see Patch100: cups-pam.diff):
 install -m 644 -D conf/pam.tizen $RPM_BUILD_ROOT/etc/pam.d/cups
 # Add missing usual documentation:
 install -d -m755 $RPM_BUILD_ROOT//usr/share/doc/packages/cups
 for f in CHANGES*.txt CREDITS.txt INSTALL.txt LICENSE.txt README.txt
 do install -m 644 "$f" $RPM_BUILD_ROOT/usr/share/doc/packages/cups/
 done
 # Source102: postscript.ppd.bz2
 bzip2 -cd < ${S}/packaging/postscript.ppd.bz2 > $RPM_BUILD_ROOT/usr/share/cups/model/Postscript.ppd
 # Source105: PSLEVEL1.PPD.bz2
 bzip2 -cd < ${S}/packaging/PSLEVEL1.PPD.bz2 > $RPM_BUILD_ROOT/usr/share/cups/model/Postscript-level1.ppd
 # Source106: PSLEVEL2.PPD.bz2
 bzip2 -cd < ${S}/packaging/PSLEVEL2.PPD.bz2 > $RPM_BUILD_ROOT/usr/share/cups/model/Postscript-level2.ppd
 find ${D}/usr/share/cups/model -name "*.ppd" | while read FILE
 do # Change default paper size from Letter to A4 if possible
    # https://bugzilla.novell.com/show_bug.cgi?id=suse30662
    # and delete trailing whitespace:
    perl -pi -e 's:^(\*Default.*)Letter\s*$:$1A4\n:; \
                 s:^(\*ImageableArea A4.*\:\s+)"0 0 595 842":$1"24 48 571 818":; \
                 s:^(\*ImageableArea Letter.*\:\s+)"0 0 612 792":$1"24 48 588 768":; \
                 s:\s\n:\n:' "$FILE"
    gzip -9 "$FILE"
 done
 # Add files for desktop menu:
 rm -f $RPM_BUILD_ROOT/usr/share/applications/cups.desktop
 
    /usr/lib/rpm/tizen_update_desktop_file.sh -i cups PrintingUtility 2>/dev/null || exit 1 
   mkdir $RPM_BUILD_ROOT/usr/share/pixmaps
 install -m 644 $RPM_BUILD_ROOT/usr/share/icons/hicolor/64x64/apps/cups.png $RPM_BUILD_ROOT/usr/share/pixmaps
 rm -rf $RPM_BUILD_ROOT/usr/share/icons
 # Remove unpackaged files:
 rm -rf $RPM_BUILD_ROOT//usr/share/man/es/cat?
 rm -rf $RPM_BUILD_ROOT//usr/share/man/fr/cat?
 rm -rf $RPM_BUILD_ROOT//usr/share/man/cat?
 
 # Run fdupes:
 
  _target=""; 
  _symlinks=0; 
   
  fdupes -q -n -r $RPM_BUILD_ROOT | 
   while read _file; do 
     if test -z "$_target" ; then 
       _target="$_file"; 
     else 
       if test -z "$_file" ; then 
 	_target=""; 
 	continue ; 
       fi ; 
       if test "$_symlinks" = 1; then 
         ln -sf "${_target#${D}}" "$_file"; 
       else 
         ln -f "$_target" "$_file"; 
       fi ;
     fi ; 
  done 
 
 
}

PACKAGES = ""
PACKAGES += "cups-devel"
PACKAGES += "cups-ddk"
PACKAGES += "cups"
PACKAGES += "cups-libs"
PACKAGES += "cups-client"

cups-devel_files = ""
cups-devel_files += "cups.manifest"
cups-devel_files += "/usr/include/cups/"
cups-devel_files += "/usr/lib/libcups.so"
cups-devel_files += "/usr/lib/libcupsimage.so"
cups-devel_files += "/usr/lib/libcupscgi.so"
cups-devel_files += "/usr/lib/libcupsmime.so"
cups-devel_files += "/usr/lib/libcupsppdc.so"
cups-devel_files += "/usr/share/cups/ppdc/"

cups-ddk_files = ""
cups-ddk_files += "cups.manifest"
cups-ddk_files += "/usr/bin/ppdc"
cups-ddk_files += "/usr/bin/ppdhtml"
cups-ddk_files += "/usr/bin/ppdi"
cups-ddk_files += "/usr/bin/ppdmerge"
cups-ddk_files += "/usr/bin/ppdpo"
cups-ddk_files += "/usr/share/man/man1/ppdc.1.gz"
cups-ddk_files += "/usr/share/man/man1/ppdhtml.1.gz"
cups-ddk_files += "/usr/share/man/man1/ppdi.1.gz"
cups-ddk_files += "/usr/share/man/man1/ppdmerge.1.gz"
cups-ddk_files += "/usr/share/man/man1/ppdpo.1.gz"
cups-ddk_files += "/usr/share/man/man5/ppdcfile.5.gz"

cups_files = ""
cups_files += "cups.manifest"
#Remove rpm attribut "%attr(640,root,lp)"
cups_files += "/etc/cups/cupsd.conf"
#Remove rpm attribut "%attr(640,root,lp)"
cups_files += "/etc/cups/cups-files.conf"
cups_files += "/etc/cups/cupsd.conf.default"
#Remove rpm attribut "%attr(640,root,lp)"
cups_files += "/etc/cups/snmp.conf"
#Remove rpm attribut "%attr(755,lp,lp)"
cups_files += "/etc/cups/interfaces"
cups_files += "/etc/pam.d/cups"
cups_files += "/etc/dbus-1/system.d/cups.conf"
#Remove rpm attribut "%attr(700,root,lp)"
cups_files += "/etc/cups/ssl"
#Remove rpm attribut "%attr(755,root,lp)"
cups_files += "/etc/cups/ppd"
cups_files += "/usr/bin/cupstestppd"
cups_files += "/usr/sbin/cupsaddsmb"
cups_files += "/usr/sbin/cupsctl"
cups_files += "/usr/sbin/cupsd"
cups_files += "/usr/sbin/cupsfilter"
cups_files += "/usr/lib/cups"
cups_files += "/usr/lib/cups/backend"
cups_files += "/usr/lib/cups/backend/http"
cups_files += "/usr/lib/cups/backend/https"
cups_files += "/usr/lib/cups/backend/ipp"
cups_files += "/usr/lib/cups/backend/ipps"
cups_files += "/usr/lib/cups/backend/lpd"
cups_files += "/usr/lib/cups/backend/snmp"
cups_files += "/usr/lib/cups/backend/socket"
cups_files += "/usr/lib/cups/backend/usb"
cups_files += "/usr/lib/cups/cgi-bin"
cups_files += "/usr/lib/cups/cgi-bin/admin.cgi"
cups_files += "/usr/lib/cups/cgi-bin/classes.cgi"
cups_files += "/usr/lib/cups/cgi-bin/help.cgi"
cups_files += "/usr/lib/cups/cgi-bin/jobs.cgi"
cups_files += "/usr/lib/cups/cgi-bin/printers.cgi"
cups_files += "/usr/lib/cups/daemon"
cups_files += "/usr/lib/cups/daemon/cups-deviced"
cups_files += "/usr/lib/cups/daemon/cups-driverd"
cups_files += "/usr/lib/cups/daemon/cups-exec"
cups_files += "/usr/lib/cups/daemon/cups-lpd"
cups_files += "/usr/lib/cups/driver"
cups_files += "/usr/lib/cups/filter"
cups_files += "/usr/lib/cups/filter/commandtops"
cups_files += "/usr/lib/cups/filter/gziptoany"
cups_files += "/usr/lib/cups/filter/pstops"
cups_files += "/usr/lib/cups/filter/rastertodymo"
cups_files += "/usr/lib/cups/filter/rastertoepson"
cups_files += "/usr/lib/cups/filter/rastertohp"
cups_files += "/usr/lib/cups/filter/rastertolabel"
cups_files += "/usr/lib/cups/filter/rastertopwg"
cups_files += "/usr/lib/cups/monitor"
cups_files += "/usr/lib/cups/monitor/bcp"
cups_files += "/usr/lib/cups/monitor/tbcp"
cups_files += "/usr/lib/cups/notifier"
cups_files += "/usr/lib/cups/notifier/dbus"
cups_files += "/usr/lib/cups/notifier/mailto"
cups_files += "/usr/lib/cups/notifier/rss"
#Remove rpm attribut "%attr(0775,root,ntadmin)"
cups_files += "/usr/share/cups/drivers"
cups_files += "/usr/share/applications/cups.desktop"
cups_files += "/usr/share/pixmaps/cups.png"
cups_files += "/usr/share/doc/packages/cups"
cups_files += "/usr/share/man/man1/cupstestppd.1.gz"
cups_files += "/usr/share/man/man5/classes.conf.5.gz"
cups_files += "/usr/share/man/man5/client.conf.5.gz"
cups_files += "/usr/share/man/man5/cups-files.conf.5.gz"
cups_files += "/usr/share/man/man5/cups-snmp.conf.5.gz"
cups_files += "/usr/share/man/man5/cupsd.conf.5.gz"
cups_files += "/usr/share/man/man5/mailto.conf.5.gz"
cups_files += "/usr/share/man/man5/mime.convs.5.gz"
cups_files += "/usr/share/man/man5/mime.types.5.gz"
cups_files += "/usr/share/man/man5/printers.conf.5.gz"
cups_files += "/usr/share/man/man5/subscriptions.conf.5.gz"
cups_files += "/usr/share/man/man7/backend.7.gz"
cups_files += "/usr/share/man/man7/filter.7.gz"
cups_files += "/usr/share/man/man7/notifier.7.gz"
cups_files += "/usr/share/man/man8/cups-deviced.8.gz"
cups_files += "/usr/share/man/man8/cups-driverd.8.gz"
cups_files += "/usr/share/man/man8/cups-lpd.8.gz"
cups_files += "/usr/share/man/man8/cups-snmp.8.gz"
cups_files += "/usr/share/man/man8/cupsaddsmb.8.gz"
cups_files += "/usr/share/man/man8/cupsctl.8.gz"
cups_files += "/usr/share/man/man8/cupsd.8.gz"
cups_files += "/usr/share/man/man8/cupsfilter.8.gz"
cups_files += "/usr/share/cups/"

cups-libs_files = ""
cups-libs_files += "cups.manifest"
cups-libs_files += "/etc/cups/client.conf"
#Remove rpm attribut "%attr(0710,root,lp)"
cups-libs_files += "/var/spool/cups"
#Remove rpm attribut "%attr(1770,root,lp)"
cups-libs_files += "/var/spool/cups/tmp"
#Remove rpm attribut "%attr(0755,lp,lp)"
cups-libs_files += "/var/log/cups/"
#Remove rpm attribut "%attr(0775,lp,lp)"
cups-libs_files += "/var/cache/cups"
cups-libs_files += "/usr/bin/cups-config"
cups-libs_files += "/usr/lib/libcups.so.*"
cups-libs_files += "/usr/lib/libcupscgi.so.*"
cups-libs_files += "/usr/lib/libcupsimage.so.*"
cups-libs_files += "/usr/lib/libcupsmime.so.*"
cups-libs_files += "/usr/lib/libcupsppdc.so.*"
cups-libs_files += "/usr/share/locale/*/cups_*"
cups-libs_files += "/usr/share/man/man1/cups-config.1.gz"

cups-client_files = ""
cups-client_files += "cups.manifest"
cups-client_files += "/usr/bin/cancel"
cups-client_files += "/usr/bin/cupstestdsc"
cups-client_files += "/usr/bin/ipptool"
cups-client_files += "/usr/bin/lp"
cups-client_files += "/usr/bin/lpoptions"
cups-client_files += "/usr/bin/lpq"
cups-client_files += "/usr/bin/lpr"
cups-client_files += "/usr/bin/lprm"
cups-client_files += "/usr/bin/lpstat"
cups-client_files += "/usr/sbin/accept"
cups-client_files += "/usr/sbin/cupsaccept"
cups-client_files += "/usr/sbin/cupsdisable"
cups-client_files += "/usr/sbin/cupsenable"
cups-client_files += "/usr/sbin/cupsreject"
cups-client_files += "/usr/sbin/lpadmin"
cups-client_files += "/usr/sbin/lpc"
cups-client_files += "/usr/sbin/lpinfo"
cups-client_files += "/usr/sbin/lpmove"
cups-client_files += "/usr/sbin/reject"
cups-client_files += "/usr/share/man/man1/cancel.1.gz"
cups-client_files += "/usr/share/man/man1/cupstestdsc.1.gz"
cups-client_files += "/usr/share/man/man1/ipptool.1.gz"
cups-client_files += "/usr/share/man/man1/lp.1.gz"
cups-client_files += "/usr/share/man/man1/lpoptions.1.gz"
cups-client_files += "/usr/share/man/man1/lppasswd.1.gz"
cups-client_files += "/usr/share/man/man1/lpq.1.gz"
cups-client_files += "/usr/share/man/man1/lpr.1.gz"
cups-client_files += "/usr/share/man/man1/lprm.1.gz"
cups-client_files += "/usr/share/man/man1/lpstat.1.gz"
cups-client_files += "/usr/share/man/man5/ipptoolfile.5.gz"
cups-client_files += "/usr/share/man/man8/accept.8.gz"
cups-client_files += "/usr/share/man/man8/cupsaccept.8.gz"
cups-client_files += "/usr/share/man/man8/cupsdisable.8.gz"
cups-client_files += "/usr/share/man/man8/cupsenable.8.gz"
cups-client_files += "/usr/share/man/man8/cupsreject.8.gz"
cups-client_files += "/usr/share/man/man8/lpadmin.8.gz"
cups-client_files += "/usr/share/man/man8/lpc.8.gz"
cups-client_files += "/usr/share/man/man8/lpinfo.8.gz"
cups-client_files += "/usr/share/man/man8/lpmove.8.gz"
cups-client_files += "/usr/share/man/man8/reject.8.gz"

FILES_${PN}-devel = "${cups-devel_files}"
FILES_${PN}-ddk = "${cups-ddk_files}"
FILES_${PN} = "${cups_files}"
FILES_${PN}-libs = "${cups-libs_files}"
FILES_${PN}-client = "${cups-client_files}"

PKG_cups-devel= "cups-devel"
PKG_cups-ddk= "cups-ddk"
PKG_cups= "cups"
PKG_cups-libs= "cups-libs"
PKG_cups-client= "cups-client"

require cups-extraconf.inc
