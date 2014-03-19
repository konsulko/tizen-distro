DESCRIPTION = "List packages that have no dependencies (like deborphan)"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Applications/System"
LICENSE = "GPLv2+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by rpmorphan 
PROVIDES += "rpmorphan"
RPROVIDES_rpmorphan += "rpmorphan"

RDEPENDS = ""
#RDEPENDS of rpmorphan (${PN})
RDEPENDS_${PN} += "rpm"
RDEPENDS_${PN} += "perl"


DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/rpmorphan.manifest .
 
 
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
 
 make -j16
 
 
 
 
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
PACKAGES += "rpmorphan"

rpmorphan_files = ""
rpmorphan_files += "rpmorphan.manifest"
rpmorphan_files += "COPYING"
rpmorphan_files += "/usr/bin/rpmorphan-lib.pl"
rpmorphan_files += "/usr/bin/rpmorphan-curses-lib.pl"
rpmorphan_files += "/usr/bin/rpmorphan-tk-lib.pl"
rpmorphan_files += "/usr/bin/rpmorphan.pl"
rpmorphan_files += "/usr/bin/rpmorphan"
rpmorphan_files += "/usr/bin/grpmorphan"
rpmorphan_files += "/usr/bin/rpmusage.pl"
rpmorphan_files += "/usr/bin/rpmusage"
rpmorphan_files += "/usr/bin/rpmdep.pl"
rpmorphan_files += "/usr/bin/rpmdep"
rpmorphan_files += "/usr/bin/rpmduplicates.pl"
rpmorphan_files += "/usr/bin/rpmduplicates"
rpmorphan_files += "/usr/bin/rpmextra.pl"
rpmorphan_files += "/usr/bin/rpmextra"
rpmorphan_files += "/var/lib/rpmorphan"
#Remove rpm attribut "%attr(644, root, root)"
rpmorphan_files += "/var/lib/rpmorphan/keep"
rpmorphan_files += "/usr/lib/rpmorphan"
rpmorphan_files += "/usr/lib/rpmorphan/locale"
rpmorphan_files += "/usr/lib/rpmorphan/locale/en"
rpmorphan_files += "/usr/lib/rpmorphan/locale/fr_FR"
rpmorphan_files += "/etc/logrotate.d/rpmorphan"
rpmorphan_files += "/etc/rpmorphanrc"
rpmorphan_files += "/usr/share/man/man1/rpmorphan.1*"
rpmorphan_files += "/usr/share/man/man1/rpmusage.1*"
rpmorphan_files += "/usr/share/man/man1/rpmdep.1*"
rpmorphan_files += "/usr/share/man/man1/rpmduplicates.1*"
rpmorphan_files += "/usr/share/man/man1/rpmextra.1*"

FILES_${PN} = "${rpmorphan_files}"

PKG_rpmorphan= "rpmorphan"

require rpmorphan-extraconf.inc
