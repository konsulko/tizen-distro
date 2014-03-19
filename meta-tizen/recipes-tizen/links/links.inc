DESCRIPTION = "Text-Based WWW Browser"
HOMEPAGE = "http://artax.karlin.mff.cuni.cz/~mikulas/links/"
SECTION = "Productivity/Networking/Web/Browsers"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by links 
PROVIDES += "links"
RPROVIDES_links += "links"
# the PROVIDES rules is ignore "web_browser  "
PROVIDES += "web_browser"
RPROVIDES_links += "web_browser"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of links 
DEPENDS += "pkgconfig-native"
DEPENDS += "openssl-devel"
DEPENDS += "automake-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n links-2.6
 cp ${S}/packaging/links.manifest .
 
 
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
 
 autoreconf -ifv
 CFLAGS="$RPM_OPT_FLAGS -fno-strict-aliasing -pipe"
 
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
         --infodir=/usr/share/info  --with-ssl  --with-pic
 make
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 mkdir -p $RPM_BUILD_ROOT/{/usr/share/man/man1,usr/bin,/usr/share/info} 
 cp links.1 $RPM_BUILD_ROOT//usr/share/man/man1
 make install DESTDIR=$RPM_BUILD_ROOT
 make clean
 make EXTRAA="-DSHOW_COLOR=TRUE"
 install links $RPM_BUILD_ROOT/usr/bin/links
 
 
}

PACKAGES = ""
PACKAGES += "links"

links_files = ""
links_files += "links.manifest"
links_files += "/usr/bin/links"
links_files += "/usr/share/man/man1/links.1.gz"

FILES_${PN} = "${links_files}"

PKG_links= "links"

require links-extraconf.inc
