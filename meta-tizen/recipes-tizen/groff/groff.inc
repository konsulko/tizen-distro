DESCRIPTION = "A document formatting system"
HOMEPAGE = "http://groff.ffii.org"
SECTION = "Base/Utilities"
LICENSE = "BSD-3-Clause and GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by groff-perl 
PROVIDES += "groff-perl"
RPROVIDES_groff-perl += "groff-perl"

#PROVIDES by groff 
PROVIDES += "groff"
RPROVIDES_groff += "groff"

RDEPENDS = ""
#RDEPENDS of groff (${PN})
RDEPENDS_${PN} += "/usr/bin/mktemp"


DEPENDS = ""
#DEPENDS of groff 
DEPENDS += "zlib-devel"
DEPENDS += "bison-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/groff.manifest .
 
 
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
         --infodir=/usr/share/info --enable-multibyte
 make
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 mkdir -p ${D}/usr ${D}/usr/share/info
 make install manroot=${D}/usr/share/man \
 			bindir=${D}/usr/bin \
 			mandir=${D}/usr/share/man \
 			prefix=${D}/usr \
 			exec_prefix=${D}/usr \
 			sbindir=${D}/usr/sbin \
 			sysconfdir=${D}/etc \
 			datadir=${D}/usr/share \
 			infodir=${D}//usr/info \
 			sysconfdir=${D}/etc \
 			includedir=${D}/usr/include \
 			libdir=${D}//usr/lib \
 			libexecdir=${D}/usr/libexec \
 			localstatedir=${D}/var \
 			sharedstatedir=${D}/usr/com \
 			infodir=${D}/usr/share/info
 
 #install -m 644 doc/groff.info* ${D}//usr/share/info
 ln -s s.tmac ${D}/usr/share/groff/1.21/tmac/gs.tmac
 ln -s mse.tmac ${D}/usr/share/groff/1.21/tmac/gmse.tmac
 ln -s m.tmac ${D}/usr/share/groff/1.21/tmac/gm.tmac
 ln -s troff	${D}/usr/bin/gtroff
 ln -s tbl ${D}/usr/bin/gtbl
 ln -s pic ${D}/usr/bin/gpic
 ln -s eqn ${D}/usr/bin/geqn
 ln -s neqn ${D}/usr/bin/gneqn
 ln -s refer ${D}/usr/bin/grefer
 ln -s lookbib ${D}/usr/bin/glookbib
 ln -s indxbib ${D}/usr/bin/gindxbib
 ln -s soelim ${D}/usr/bin/gsoelim
 ln -s soelim ${D}/usr/bin/zsoelim
 ln -s nroff	${D}/usr/bin/gnroff
 
 
 find ${D}/usr/bin -type f -o -type l | \
 	grep -v afmtodit | grep -v grog | grep -v mdoc.samples |\
 	grep -v mmroff |\
 	grep -v gxditview |\
 	sed "s|${D}||g" | sed "s|\.[0-9]|\.*|g" > groff-files
 
 ln -sf doc.tmac ${D}/usr/share/groff/1.21/tmac/docj.tmac
 # installed, but not packaged in rpm
 mkdir -p ${D}/usr/share/groff/1.21/groffer/
 chmod 755 ${D}/usr/lib/groff/groffer/version.sh
 mv ${D}/usr/lib/groff/groffer/* ${D}//usr/share/groff/1.21/groffer/
 
 
 
   rm -rf ${D}/usr/share/info 
   rm -rf ${D}/usr/share/doc/packages 
   rm -rf ${D}/usr/share/doc/groff 
   rm -rf ${D}/usr/share/doc/groff-1.21 
   rm -rf ${D}/usr/share/gtk-doc 
   rm -rf ${D}/usr/share/doc 
   rm -rf ${D}/usr/share/man 
   find ${D} -regex ".*/man/man./.*.[0-9]" | xargs rm -f -- 
   find ${D} -regex ".*/man/../man./.*.[0-9]" | xargs rm -f -- 
   find ${D} -regex ".*/man/man./.*.[0-9]pm" | xargs rm -f --
 
 
}

PACKAGES = ""
PACKAGES += "groff-perl"
PACKAGES += "groff"

groff-perl_files = ""
groff-perl_files += "groff.manifest"
groff-perl_files += "/usr/bin/grog"
groff-perl_files += "/usr/bin/mmroff"
groff-perl_files += "/usr/bin/afmtodit"

groff_files = ""
groff_files += "groff.manifest"
groff_files += "/usr/share/groff"

FILES_${PN}-perl = "${groff-perl_files}"
FILES_${PN} = "${groff_files}"

PKG_groff-perl= "groff-perl"
PKG_groff= "groff"

require groff-extraconf.inc
