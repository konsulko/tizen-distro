DESCRIPTION = "Removes ifdefs from C files"
HOMEPAGE = "http://dotat.at/prog/unifdef/"
SECTION = "Development/Tools"
LICENSE = "BSD"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by unifdef 
PROVIDES += "unifdef"
RPROVIDES_unifdef += "unifdef"

RDEPENDS = ""

DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/unifdef.manifest .
 
 
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
 
 make -j16 CC=gcc CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables"
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 make install DESTDIR=${D} prefix=/usr
 
 
}

PACKAGES = ""
PACKAGES += "unifdef"

unifdef_files = ""
unifdef_files += "unifdef.manifest"
unifdef_files += "/usr/bin/unifdef"
unifdef_files += "/usr/bin/unifdefall"
unifdef_files += "/usr/share/man/man1/unifdef.1*"
unifdef_files += "/usr/share/man/man1/unifdefall.1*"

FILES_${PN} = "${unifdef_files}"

PKG_unifdef= "unifdef"

require unifdef-extraconf.inc
