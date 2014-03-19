DESCRIPTION = "Epson Laser Printer Driver (ESC/Page) for Linux"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Applications/System"
LICENSE = "LGPL"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by epson-laser-printer-escpage 
PROVIDES += "epson-laser-printer-escpage"
RPROVIDES_epson-laser-printer-escpage += "epson-laser-printer-escpage"

RDEPENDS = ""
#RDEPENDS of epson-laser-printer-escpage (${PN})
RDEPENDS_${PN} += "cups"


DEPENDS = ""
#DEPENDS of epson-laser-printer-escpage 
DEPENDS += "cups"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/epson-laser-printer-escpage.manifest .
 cat ${S}/packaging/tizen_disable_unused_value.patch | patch -s  -p0 --fuzz=2
 #patch0
 cat ${S}/packaging/tizen_add_job_media_progress.patch | patch -s  -p1 --fuzz=2
 #patch1 -p1
 cat ${S}/packaging/tizen_report_page_info.patch | patch -s  -p1 --fuzz=2
 #patch2 -p1
 cat ${S}/packaging/tizen_fix_ignore_sigpipe.patch | patch -s  -p1 --fuzz=2
 #patch3 -p1
 
 
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
 	--with-cupsppddir=/opt/etc/cups/ppd/Epson
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
 cp ${WORKDIR}/git/COPYING ${D}/usr/share/license/epson-laser-printer-escpage
 
 
}

PACKAGES = ""
PACKAGES += "epson-laser-printer-escpage"

epson-laser-printer-escpage_files = ""
epson-laser-printer-escpage_files += "epson-laser-printer-escpage.manifest"
epson-laser-printer-escpage_files += "/usr/share/license/epson-laser-printer-escpage"
epson-laser-printer-escpage_files += "/usr/lib/cups/filter/*"

FILES_${PN} = "${epson-laser-printer-escpage_files}"

PKG_epson-laser-printer-escpage= "epson-laser-printer-escpage"

require epson-laser-printer-escpage-extraconf.inc
