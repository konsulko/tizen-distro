DESCRIPTION = "The GNU versions of find utilities (find and xargs)"
HOMEPAGE = "http://www.gnu.org/software/findutils/"
SECTION = "Base/Tools"
LICENSE = "GPL-3.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by findutils-docs  
PROVIDES += "findutils-docs "
RPROVIDES_findutils-docs  += "findutils-docs "

#PROVIDES by findutils-locale  
PROVIDES += "findutils-locale "
RPROVIDES_findutils-locale  += "findutils-locale "
# the PROVIDES rules is ignore "findutils-lang-all = 4.5.10"
PROVIDES += "findutils-lang-all"
RPROVIDES_findutils-locale  += "findutils-lang-all"

#PROVIDES by findutils 
PROVIDES += "findutils"
RPROVIDES_findutils += "findutils"

#PROVIDES by findutils-locate 
PROVIDES += "findutils-locate"
RPROVIDES_findutils-locate += "findutils-locate"
# the PROVIDES rules is ignore "findutils:/usr/bin/locate  "
PROVIDES += "findutils:/usr/bin/locate"
RPROVIDES_findutils-locate += "findutils:/usr/bin/locate"

RDEPENDS = ""
#RDEPENDS of findutils-locale  (${PN}-locale )
RDEPENDS_${PN}-locale  += "findutils"

#RDEPENDS of findutils-locate (${PN}-locate)
RDEPENDS_${PN}-locate += "findutils"


DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/findutils.manifest .
 
 
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
   --libexecdir=/usr/lib/find \
   --localstatedir=/var/lib \
   --without-included-regex \
   --without-fts \
   --enable-d_type-optimisation
 make -j16
 
 exit 0
 make check
 
 
 
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
 
 install -D -m 644 ${S}/packaging/sysconfig.locate $RPM_BUILD_ROOT/etc/sysconfig/locate
 rm -f $RPM_BUILD_ROOT/usr/bin/oldfind
 rm -f $RPM_BUILD_ROOT/usr/bin/ftsfind
 rm -f $RPM_BUILD_ROOT/usr/share/info/find-maint*
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} findutils
 
 
 
}

PACKAGES = ""
PACKAGES += "findutils-docs"
PACKAGES += "findutils-locate"
PACKAGES += "findutils"
PACKAGES += "findutils-locale"

findutils-docs_files = ""
findutils-docs_files += "/usr/share/info"
findutils-docs_files += "/usr/share/man"

findutils-locate_files = ""
findutils-locate_files += "findutils.manifest"
findutils-locate_files += "/usr/bin/locate"
findutils-locate_files += "/usr/bin/updatedb"
findutils-locate_files += "/usr/lib/find"
findutils-locate_files += "/etc/sysconfig/locate"

findutils_files = ""
findutils_files += "findutils.manifest"
findutils_files += "/usr/bin/find"
findutils_files += "/usr/bin/xargs"

findutils-locale_files = ""

FILES_${PN}-docs = "${findutils-docs_files}"
FILES_${PN}-locate = "${findutils-locate_files}"
FILES_${PN} = "${findutils_files}"
FILES_${PN}-locale = "${findutils-locale_files}"

PKG_findutils-docs= "findutils-docs"
PKG_findutils-locate= "findutils-locate"
PKG_findutils= "findutils"
PKG_findutils-locale= "findutils-locale"

require findutils-extraconf.inc
