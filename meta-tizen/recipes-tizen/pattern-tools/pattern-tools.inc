DESCRIPTION = "Pattern Tools"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Base"
LICENSE = "GPLv2"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by pattern-tools 
PROVIDES += "pattern-tools"
RPROVIDES_pattern-tools += "pattern-tools"

RDEPENDS = ""
#RDEPENDS of pattern-tools (${PN})
RDEPENDS_${PN} += "libxslt"
RDEPENDS_${PN} += "python-lxml"
RDEPENDS_${PN} += "python-yaml"


DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/pattern-tools.manifest .
 
 
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
 
 make 
 
 
 
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
 
 
 
}

PACKAGES = ""
PACKAGES += "pattern-tools"

pattern-tools_files = ""
pattern-tools_files += "pattern-tools.manifest"
pattern-tools_files += "/usr/bin/merge-patterns"
pattern-tools_files += "/usr/share/package-groups/stylesheets/*.xsl"

FILES_${PN} = "${pattern-tools_files}"

PKG_pattern-tools= "pattern-tools"

require pattern-tools-extraconf.inc
