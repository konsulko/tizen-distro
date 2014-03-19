DESCRIPTION = "Shared MIME Database"
HOMEPAGE = "http://freedesktop.org/wiki/Software/shared-mime-info"
SECTION = "Base/Configuration"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by shared-mime-info 
PROVIDES += "shared-mime-info"
RPROVIDES_shared-mime-info += "shared-mime-info"
# the PROVIDES rules is ignore "shared-mime-info-devel = 1.0"
PROVIDES += "shared-mime-info-devel"
RPROVIDES_shared-mime-info += "shared-mime-info-devel"
RPROVIDES_shared-mime-info += "shared-mime-info-dev"

#PROVIDES by shared-mime-info-docs  
PROVIDES += "shared-mime-info-docs "
RPROVIDES_shared-mime-info-docs  += "shared-mime-info-docs "

#PROVIDES by shared-mime-info-locale  
PROVIDES += "shared-mime-info-locale "
RPROVIDES_shared-mime-info-locale  += "shared-mime-info-locale "
# the PROVIDES rules is ignore "shared-mime-info-lang-all = 1.0"
PROVIDES += "shared-mime-info-lang-all"
RPROVIDES_shared-mime-info-locale  += "shared-mime-info-lang-all"

#PROVIDES by shared-mime-info-tools 
PROVIDES += "shared-mime-info-tools"
RPROVIDES_shared-mime-info-tools += "shared-mime-info-tools"

RDEPENDS = ""
#RDEPENDS of shared-mime-info-tools (${PN}-tools)
RDEPENDS_${PN}-tools += "shared-mime-info"

#RDEPENDS of shared-mime-info-locale  (${PN}-locale )
RDEPENDS_${PN}-locale  += "shared-mime-info"

#RDEPENDS of shared-mime-info (${PN})
RDEPENDS_${PN} += "/usr/bin/fgrep"
RDEPENDS_${PN} += "/usr/bin/rm"
RDEPENDS_${PN} += "/usr/bin/mkdir"


DEPENDS = ""
#DEPENDS of shared-mime-info 
DEPENDS += "libxml2"
DEPENDS += "intltool-native"
DEPENDS += "pkgconfig(libxml-2.0)"
DEPENDS += "pkgconfig(glib-2.0)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/shared-mime-info.manifest .
 
 
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
 
 export CFLAGS=`echo $RPM_OPT_FLAGS |sed -e 's/atom/i686/g'`
 
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
 make V=1
 
 
 
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
 install ${S}/packaging/mime-info-to-mime ${D}/usr/bin/
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} shared-mime-info --without-C
 # Install rpm macros
 install -D -m644 ${S}/packaging/macros.shared-mime-info ${D}/etc/rpm/macros.shared-mime-info
 
 
 
}

PACKAGES = ""
PACKAGES += "shared-mime-info-tools"
PACKAGES += "shared-mime-info-docs"
PACKAGES += "shared-mime-info-locale"
PACKAGES += "shared-mime-info"

shared-mime-info-tools_files = ""
shared-mime-info-tools_files += "shared-mime-info.manifest"
shared-mime-info-tools_files += "/usr/bin/mime-info-to-mime"

shared-mime-info-docs_files = ""
shared-mime-info-docs_files += "/usr/share/info"
shared-mime-info-docs_files += "/usr/share/man"

shared-mime-info-locale_files = ""

shared-mime-info_files = ""
shared-mime-info_files += "shared-mime-info.manifest"
shared-mime-info_files += "/usr/bin/update-mime-database"
shared-mime-info_files += "/usr/share/mime/packages/*.xml"
shared-mime-info_files += "/usr/share/pkgconfig/*.pc"
shared-mime-info_files += "/etc/rpm/macros.shared-mime-info"

FILES_${PN}-tools = "${shared-mime-info-tools_files}"
FILES_${PN}-docs = "${shared-mime-info-docs_files}"
FILES_${PN}-locale = "${shared-mime-info-locale_files}"
FILES_${PN} = "${shared-mime-info_files}"

PKG_shared-mime-info-tools= "shared-mime-info-tools"
PKG_shared-mime-info-docs= "shared-mime-info-docs"
PKG_shared-mime-info-locale= "shared-mime-info-locale"
PKG_shared-mime-info= "shared-mime-info"

require shared-mime-info-extraconf.inc
