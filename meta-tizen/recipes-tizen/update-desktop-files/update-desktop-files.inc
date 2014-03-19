DESCRIPTION = "A Build Tool to Update Desktop Files"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Development/Tools/Building"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by update-desktop-files 
PROVIDES += "update-desktop-files"
RPROVIDES_update-desktop-files += "update-desktop-files"

#PROVIDES by brp-trim-desktopfiles 
PROVIDES += "brp-trim-desktopfiles"
RPROVIDES_brp-trim-desktopfiles += "brp-trim-desktopfiles"

RDEPENDS = ""
#RDEPENDS of update-desktop-files (${PN})
RDEPENDS_${PN} += "desktop-file-utils"


DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n . -D -T 0
 cp ${S}/packaging/update-desktop-files.manifest .
 mkdir update-desktop-files
 cd update-desktop-files
 
 
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
 
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 mkdir -p $RPM_BUILD_ROOT/usr/share/spec2yocto/macro
 install -m0755 ${S}/packaging/tizen_update_desktop_file.sh ${S}/packaging/map-desktop-category.sh $RPM_BUILD_ROOT/usr/share/spec2yocto/macro
 install -m0644 -D ${S}/packaging/macro $RPM_BUILD_ROOT/etc/rpm/macros.update-desktop-files
 install -m0755 -D ${S}/packaging/brp-trim-desktop.sh $RPM_BUILD_ROOT/usr/lib/rpm/brp-tizen.d/brp-70-trim-desktopfiles
 
 
}

PACKAGES = ""
PACKAGES += "brp-trim-desktopfiles"
PACKAGES += "update-desktop-files"

brp-trim-desktopfiles_files = ""
brp-trim-desktopfiles_files += "update-desktop-files.manifest"
brp-trim-desktopfiles_files += "/usr/share/spec2yocto/macro/brp-tizen.d"

update-desktop-files_files = ""
update-desktop-files_files += "update-desktop-files.manifest"
update-desktop-files_files += "/usr/share/spec2yocto/macro/*"
update-desktop-files_files += "/etc/rpm/*"

FILES_brp-trim-desktopfiles = "${brp-trim-desktopfiles_files}"
FILES_${PN} = "${update-desktop-files_files}"

PKG_brp-trim-desktopfiles= "brp-trim-desktopfiles"
PKG_update-desktop-files= "update-desktop-files"

require update-desktop-files-extraconf.inc
