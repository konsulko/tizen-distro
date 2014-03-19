DESCRIPTION = "Epson Inkjet Printer Driver (ESC/P-R) for Linux"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Applications/System"
LICENSE = "GPL"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by epson-inkjet-printer-escpr 
PROVIDES += "epson-inkjet-printer-escpr"
RPROVIDES_epson-inkjet-printer-escpr += "epson-inkjet-printer-escpr"

RDEPENDS = ""
#RDEPENDS of epson-inkjet-printer-escpr (${PN})
RDEPENDS_${PN} += "cups"


DEPENDS = ""
#DEPENDS of epson-inkjet-printer-escpr 
DEPENDS += "cups"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/epson-inkjet-printer-escpr.manifest .
 cat ${S}/packaging/tizen_bugfix.patch | patch -s  -p1 --fuzz=2
 #patch0 -p1
 cat ${S}/packaging/tizen_add_job_media_progress.patch | patch -s  -p1 --fuzz=2
 #patch1 -p1
 cat ${S}/packaging/tizen_report_page_info.patch | patch -s  -p1 --fuzz=2
 #patch2 -p1
 
 
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
 	--with-cupsfilterdir=/usr/lib/cups/filter \
 	--with-cupsppddir=/opt/etc/cups/ppd/Epson \
 	--disable-static
 make
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 rm -rf ${RPM_BUILD_ROOT}
 make install-strip DESTDIR=${RPM_BUILD_ROOT}
 
 mkdir -p ${D}/usr/share/license
 cp ${WORKDIR}/git/COPYING ${D}/usr/share/license/epson-inkjet-printer-escpr
 
 
}

PACKAGES = ""
PACKAGES += "epson-inkjet-printer-escpr"

epson-inkjet-printer-escpr_files = ""
epson-inkjet-printer-escpr_files += "epson-inkjet-printer-escpr.manifest"
epson-inkjet-printer-escpr_files += "/usr/share/license/epson-inkjet-printer-escpr"
epson-inkjet-printer-escpr_files += "/usr/lib/cups/filter/epson-escpr"
epson-inkjet-printer-escpr_files += "/usr/lib/cups/filter/epson-escpr-wrapper"

FILES_${PN} = "${epson-inkjet-printer-escpr_files}"

PKG_epson-inkjet-printer-escpr= "epson-inkjet-printer-escpr"

require epson-inkjet-printer-escpr-extraconf.inc
