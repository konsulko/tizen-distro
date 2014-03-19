DESCRIPTION = "Tools Needed to Create Documentation from Texinfo Sources"
HOMEPAGE = "http://www.texinfo.org"
SECTION = "Productivity/Publishing/Texinfo"
LICENSE = "GPL-2.0+  GPL-3.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by info 
PROVIDES += "info"
RPROVIDES_info += "info"

#PROVIDES by texinfo 
PROVIDES += "texinfo"
RPROVIDES_texinfo += "texinfo"
# the PROVIDES rules is ignore "texi2html = 1.82"
PROVIDES += "texi2html"
RPROVIDES_texinfo += "texi2html"
# the PROVIDES rules is ignore "texi2roff = 2.0"
PROVIDES += "texi2roff"
RPROVIDES_texinfo += "texi2roff"

#PROVIDES by makeinfo 
PROVIDES += "makeinfo"
RPROVIDES_makeinfo += "makeinfo"
# the PROVIDES rules is ignore "texinfo:/usr/bin/makeinfo  "
PROVIDES += "texinfo:/usr/bin/makeinfo"
RPROVIDES_makeinfo += "texinfo:/usr/bin/makeinfo"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of texinfo 
DEPENDS += "zlib-devel"
DEPENDS += "bzip2"
DEPENDS += "ncurses"
DEPENDS += "libzio"
DEPENDS += "automake-native"
DEPENDS += "perl-gettext"
DEPENDS += "help2man-native"

do_patch() {
 rm -rf texi2html-1.82 texi2roff-2.0
 #extracte source 1 
 pushd ${S}/../
 unp ${S}/packaging/texi2html-1.82.tar.bz2 
 popd 
 #extracte source 2 
 pushd ${S}/../
 unp ${S}/packaging/texi2roff-2.0.tar.bz2 
 popd 
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -b 1 -b 2 -n texinfo-4.13
 cp ${S}/packaging/texinfo.manifest .
 cat ${S}/packaging/texinfo-4.12-zlib.patch | patch -s  -p0 -b --suffix .zlib --fuzz=2
 #patch4 -p0 -b .zlib
 cat ${S}/packaging/texinfo-4.8-echo.patch | patch -s  -p0 -b --suffix .echo --fuzz=2
 #patch5 -p0 -b .echo
 cat ${S}/packaging/texinfo-4.13a-bug640417.diff | patch -s  -p1 -b --suffix .size_t --fuzz=2
 #patch7 -p1 -b .size_t
 cat ${S}/packaging/texinfo-4.13a-bug713517.diff | patch -s  -p0 -b --suffix .egrep --fuzz=2
 #patch8 -p0 -b .egrep
 cat ${S}/packaging/automake-1.12.patch | patch -s  -p1 --fuzz=2
 #patch9 -p1
 cat ${S}/packaging/texinfo-4.12.dif | patch -s  -p0 --fuzz=2
 #patch -p0
 pushd ../texi2html-1.82
 cat ${S}/packaging/texi2html-1.78.dif | patch -s  -p0 --fuzz=2
 #patch1 -p0
 popd
 pushd ../texi2roff-2.0
 bzcat ${S}/packaging/texi2roff.patch.bz2 | patch -s  -p0 -b --suffix .Bader --fuzz=2
 #patch3 -p0 -b .Bader
 cat ${S}/packaging/texi2roff-2.0.dif | patch -s  -p0 --fuzz=2
 #patch2 -p0
 cat ${S}/packaging/texi2roff-2.0-gcc4.patch | patch -s  -p1 --fuzz=2
 #patch6 -p1
 popd
 
 
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
 
     HOST=x86_64-tizen-linux
     CFLAGS="$RPM_OPT_FLAGS -pipe"
     LDFLAGS=""
     CC=gcc
     export CFLAGS LDFLAGS CC
     export LD_AS_NEEDED=0
     AUTOPOINT=true autoreconf -fi
     ./configure --build=$HOST		\
 	--prefix=/usr		\
 	--mandir=/usr/share/man		\
 	--datadir=/usr/share		\
 	--infodir=/usr/share/info		\
 	--without-included-gettext	\
 	--enable-nls
     PATH=${PWD}/makeinfo:${PWD}/util:$PATH
     export PATH
     make -j16;
 pushd ../texi2html-1.82
     ./configure --build=$HOST		\
 	--prefix=/usr		\
 	--mandir=/usr/share/man		\
 	--datadir=/usr/share		\
 	--infodir=/usr/share/info		\
 	--without-included-gettext	\
 	--enable-nls
     make -j16;
 popd
 pushd ../texi2roff-2.0
     rm -f texi2roff
     make -j16;
 popd
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
     export LD_AS_NEEDED=0
     make DESTDIR=${D} \
 	infodir=/usr/share/info	   \
 	htmldir=/usr/share/doc/packages/texi2html install
     mkdir -p ${D}/sbin
     mv ${D}/usr/bin/install-info ${D}/sbin/
     ln -sf ../../sbin/install-info ${D}/usr/bin/install-info
     mkdir -p ${D}/usr/share/info
     install -m 644 ${S}/packaging/info-dir       ${D}/usr/share/info/dir
 pushd ../texi2html-1.82
     make DESTDIR=${D} \
 	infodir=/usr/share/info	   \
 	texinfohtmldir=/usr/share/doc/packages/texi2html install
     install -m 644 README        ${D}/usr/share/doc/packages/texi2html/
     install -m 644 NEWS          ${D}/usr/share/doc/packages/texi2html/
     install -m 644 COPYING       ${D}/usr/share/doc/packages/texi2html/
 popd
 pushd ../texi2roff-2.0
     doc=/usr/share/doc/packages/texi2roff
     install -m 755 texi2roff     ${D}/usr/bin/
     install -m 755 texi2index    ${D}/usr/bin/
     install -m 644 texi2roff.1   ${D}/usr/share/man/man1/
     mkdir -p                     ${D}${doc}
     install -m 644 Readme        ${D}${doc}
     install -m 644 copyright     ${D}${doc}
 popd
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} texinfo texinfo.lang
 
 
}

PACKAGES = ""
PACKAGES += "info"
PACKAGES += "texinfo"
PACKAGES += "makeinfo"

info_files = ""
info_files += "texinfo.manifest"
info_files += "%verify(not md5 size mtime) /usr/share/info/dir"
info_files += "/sbin/install-info"
info_files += "/usr/bin/install-info"
info_files += "/usr/bin/info"
info_files += "/usr/bin/infokey"
info_files += "/usr/share/info/info.info*"
info_files += "/usr/share/info/info-stnd.info*"
info_files += "/usr/share/man/man1/info.1*"
info_files += "/usr/share/man/man1/infokey.1*"
info_files += "/usr/share/man/man1/install-info.1*"
info_files += "/usr/share/man/man5/info.5*"

texinfo_files = ""
texinfo_files += "texinfo.manifest"
texinfo_files += "/usr/share/doc/packages/texi2html"
texinfo_files += "/usr/share/doc/packages/texi2roff"
texinfo_files += "ABOUT-NLS AUTHORS COPYING INTRODUCTION NEWS README TODO"
texinfo_files += "doc/texinfo.tex doc/txi-*.tex"
texinfo_files += "/usr/share/doc/packages/texi2html/*"
texinfo_files += "/usr/share/doc/packages/texi2roff/*"
texinfo_files += "/usr/bin/pdftexi*"
texinfo_files += "/usr/bin/texi*"
texinfo_files += "/usr/share/info/texinfo*.gz"
texinfo_files += "/usr/share/info/texi2html*.gz"
texinfo_files += "/usr/share/man/man1/pdftexi2dvi.1.gz"
texinfo_files += "/usr/share/man/man1/texi*.1.gz"
texinfo_files += "/usr/share/man/man5/texinfo.5.gz"
texinfo_files += "/usr/share/texinfo"
texinfo_files += "/usr/share/texi2html"

makeinfo_files = ""
makeinfo_files += "texinfo.manifest"
makeinfo_files += "/usr/bin/makeinfo"
makeinfo_files += "/usr/share/man/man1/makeinfo.1.gz"

FILES_info = "${info_files}"
FILES_${PN} = "${texinfo_files}"
FILES_makeinfo = "${makeinfo_files}"

PKG_info= "info"
PKG_texinfo= "texinfo"
PKG_makeinfo= "makeinfo"

require texinfo-extraconf.inc
