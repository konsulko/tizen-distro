DESCRIPTION = "Netwide Assembler (An x86 Assembler)"
HOMEPAGE = "http://nasm.sourceforge.net/"
SECTION = "Development/Languages"
LICENSE = "BSD-2-Clause"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by nasm-doc 
PROVIDES += "nasm-doc"
RPROVIDES_nasm-doc += "nasm-doc"

#PROVIDES by nasm 
PROVIDES += "nasm"
RPROVIDES_nasm += "nasm"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of nasm 
DEPENDS += "makeinfo"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/nasm.manifest .
 
 
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
 
 touch -r ./ver.c ./ver.c.stamp
 TS=$(LC_ALL=C date -u -r ${S}/packaging//nasm.changes '+%b %e %Y')
 sed -i "s/__DATE__/\"$TS\"/g" ver.c
 touch -r ./ver.c.stamp ./ver.c
 
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
 make all
 
 cd doc
 make html info nasmdoc.ps nasmdoc.txt
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 install -d -m 755 ${D}/usr/bin
 install -d -m 755 ${D}//usr/share/man/man1
 install -d -m 755 ${D}//usr/share/doc/packages/nasm
 install -d -m 755 ${D}//usr/share/doc/packages/nasm/rdoff
 install -d -m 755 ${D}//usr/share/doc/packages/nasm/html
 install -d -m 755 ${D}//usr/share/info
 make INSTALLROOT=${D} install
 make INSTALLROOT=${D} rdf_install
 install -m 644 AUTHORS CHANGES ChangeLog LICENSE TODO README doc/*.txt \
 	${D}//usr/share/doc/packages/nasm
 install -m 644 rdoff/README rdoff/doc/* \
 	${D}//usr/share/doc/packages/nasm/rdoff
 install -m 644 doc/html/* ${D}/usr/share/doc/packages/nasm/html
 install -m 644 ndisasm.1 nasm.1 rdoff/*.1 ${D}/usr/share/man/man1
 install -m 644 doc/info/* ${D}/usr/share/info
 
 
}

PACKAGES = ""
PACKAGES += "nasm-doc"
PACKAGES += "nasm"

nasm-doc_files = ""
nasm-doc_files += "nasm.manifest"
nasm-doc_files += "/usr/share/doc/packages/nasm"
nasm-doc_files += "/usr/share/info/nasm*"

nasm_files = ""
nasm_files += "nasm.manifest"
nasm_files += "LGPL-2.1+ LICENSE"
nasm_files += "/usr/bin/*"
nasm_files += "/usr/share/man/man1/*.1.gz"

FILES_${PN}-doc = "${nasm-doc_files}"
FILES_${PN} = "${nasm_files}"

PKG_nasm-doc= "nasm-doc"
PKG_nasm= "nasm"

require nasm-extraconf.inc
