DESCRIPTION = "Display Word Differences Between Text Files"
HOMEPAGE = "ftp://mirrors.kernel.org/gnu/wdiff/"
SECTION = "Productivity/Text/Utilities"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by wdiff 
PROVIDES += "wdiff"
RPROVIDES_wdiff += "wdiff"

#PROVIDES by wdiff-lang 
PROVIDES += "wdiff-lang"
RPROVIDES_wdiff-lang += "wdiff-lang"

RDEPENDS = ""
#RDEPENDS of wdiff-lang (${PN}-lang)
RDEPENDS_${PN}-lang += "wdiff"


DEPENDS = ""
#DEPENDS of wdiff 
DEPENDS += "ncurses"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/wdiff.manifest .
 
 
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
 
 # those autoconf tools never really work, do they?
 # error: AC_REQUIRE: circular dependency of AC_GNU_SOURCE
 # autoreconf -fi
 LIBS=-lncurses \
 CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -pipe -DPROTOTYPES" \
 GETOPT="" \
 
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
 make
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 make "DESTDIR=${D}" install
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} wdiff-gnulib
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} wdiff
 
 
}

PACKAGES = ""
PACKAGES += "wdiff"
PACKAGES += "wdiff-lang"

wdiff_files = ""
wdiff_files += "wdiff.manifest"
wdiff_files += "/usr/share/info/wdiff.info*"
wdiff_files += "/usr/bin/*"
wdiff_files += "/usr/share/man/man1/*"

wdiff-lang_files = ""
wdiff-lang_files += "wdiff.manifest"

FILES_${PN} = "${wdiff_files}"
FILES_${PN}-lang = "${wdiff-lang_files}"

PKG_wdiff= "wdiff"
PKG_wdiff-lang= "wdiff-lang"

require wdiff-extraconf.inc
