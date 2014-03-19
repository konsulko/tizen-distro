DESCRIPTION = "Print lines matching a pattern"
HOMEPAGE = "http://www.gnu.org/software/grep/"
SECTION = "Base/Utilities"
LICENSE = "GPL-3.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by grep-docs  
PROVIDES += "grep-docs "
RPROVIDES_grep-docs  += "grep-docs "

#PROVIDES by grep 
PROVIDES += "grep"
RPROVIDES_grep += "grep"
# the PROVIDES rules is ignore "base:/usr/bin/grep  "
PROVIDES += "base:/usr/bin/grep"
RPROVIDES_grep += "base:/usr/bin/grep"
# the PROVIDES rules is ignore "/bin/grep  "
PROVIDES += "/bin/grep"
RPROVIDES_grep += "/bin/grep"

#PROVIDES by grep-locale  
PROVIDES += "grep-locale "
RPROVIDES_grep-locale  += "grep-locale "
# the PROVIDES rules is ignore "grep-lang-all = 2.16"
PROVIDES += "grep-lang-all"
RPROVIDES_grep-locale  += "grep-lang-all"

RDEPENDS = ""
#RDEPENDS of grep-locale  (${PN}-locale )
RDEPENDS_${PN}-locale  += "grep"


DEPENDS = ""
#DEPENDS of grep 
DEPENDS += "pcre-devel"
DEPENDS += "automake-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/grep.manifest .
 
 
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
         --infodir=/usr/share/info --disable-silent-rules --without-included-regex
 oe_runmake -j16
 
 exit 0
 make check VERBOSE=1
 
 
 
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
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} grep
 
 
 
 
}

PACKAGES = ""
PACKAGES += "grep-locale"
PACKAGES += "grep-docs"
PACKAGES += "grep"

grep-locale_files = ""

grep-docs_files = ""
grep-docs_files += "/usr/share/info"
grep-docs_files += "/usr/share/man"

grep_files = ""
grep_files += "grep.manifest"
grep_files += "/usr/bin/*"

FILES_${PN}-locale = "${grep-locale_files}"
FILES_${PN}-docs = "${grep-docs_files}"
FILES_${PN} = "${grep_files}"

PKG_grep-locale= "grep-locale"
PKG_grep-docs= "grep-docs"
PKG_grep= "grep"

require grep-extraconf.inc
