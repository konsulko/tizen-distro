DESCRIPTION = "Tool for Writing CDRs"
HOMEPAGE = "http://cdrkit.org/"
SECTION = "Multimedia/Media Service"
LICENSE = "GPL-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by genisoimage 
PROVIDES += "genisoimage"
RPROVIDES_genisoimage += "genisoimage"
# the PROVIDES rules is ignore "mkisofs = 1.1.11"
PROVIDES += "mkisofs"
RPROVIDES_genisoimage += "mkisofs"

#PROVIDES by cdrkit-cdrtools-compat 
PROVIDES += "cdrkit-cdrtools-compat"
RPROVIDES_cdrkit-cdrtools-compat += "cdrkit-cdrtools-compat"

#PROVIDES by cdrkit 
PROVIDES += "cdrkit"
RPROVIDES_cdrkit += "cdrkit"
# the PROVIDES rules is ignore "wodim = 1.1.11"
PROVIDES += "wodim"
RPROVIDES_cdrkit += "wodim"
# the PROVIDES rules is ignore "cdrecord = 1.1.11"
PROVIDES += "cdrecord"
RPROVIDES_cdrkit += "cdrecord"

#PROVIDES by icedax 
PROVIDES += "icedax"
RPROVIDES_icedax += "icedax"
# the PROVIDES rules is ignore "cdda2wav = 1.1.11"
PROVIDES += "cdda2wav"
RPROVIDES_icedax += "cdda2wav"

RDEPENDS = ""
#RDEPENDS of cdrkit-cdrtools-compat (${PN}-cdrtools-compat)
RDEPENDS_${PN}-cdrtools-compat += "genisoimage"
RDEPENDS_${PN}-cdrtools-compat += "wodim"
RDEPENDS_${PN}-cdrtools-compat += "icedax"

#RDEPENDS of cdrkit (${PN})
RDEPENDS_${PN} += "cdrkit-cdrtools-compat"


DEPENDS = ""
#DEPENDS of cdrkit 
DEPENDS += "zlib-devel"
DEPENDS += "file-devel"
DEPENDS += "bzip2"
DEPENDS += "cmake"
inherit perlnative
DEPENDS += "libcap-devel"
DEPENDS += "fdupes-native"
DEPENDS += "gcc-c++"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n cdrkit-1.1.11
 cp ${S}/packaging/cdrkit.manifest .
 # Fix perl path
 find . -type f -print0 | xargs -0 perl -pi -e 's#/usr/local/bin/perl#/usr/bin/perl#g'
 # Fix permissions (no executables in doc files)
 chmod 644 doc/icedax/tracknames.pl misc/burnstuff misc/rc.pp
 # Rename in order to not conflict with doc/genisoimage/README when added in genisoimage rpm doc files
 mv genisoimage/diag/README genisoimage/diag/README.diag
 
 
 
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
 
 export CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -fno-strict-aliasing -DPIC -fPIC"
 export CXXFLAGS="$CFLAGS"
 mkdir build
 cd build
 
   CFLAGS="${CFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CFLAGS ; 
   CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
   FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export FFLAGS ; 
   cmake \
         -DCMAKE_VERBOSE_MAKEFILE=ON \
         -DCMAKE_INSTALL_PREFIX:PATH=/usr \
         -DCMAKE_INSTALL_LIBDIR:PATH=/usr/lib \
         -DINCLUDE_INSTALL_DIR:PATH=/usr/include \
         -DLIB_INSTALL_DIR:PATH=/usr/lib \
         -DSYSCONF_INSTALL_DIR:PATH=/etc \
         -DSHARE_INSTALL_PREFIX:PATH=/usr/share \
         -DCMAKE_SKIP_RPATH:BOOL=ON \
         -DBUILD_SHARED_LIBS:BOOL=ON \
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake ../
 make VERBOSE=1 MANDIR=share/man -j16
 gcc -O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables ${S}/packaging/cdinfo.c -o cdinfo
 cd ..
 
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 cd build
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 cd ..
 
 # Fix perl version requirement
 perl -pi -e 's#^require v5.8.1;##g' ${D}/usr/bin/dirsplit
 
 # Install additional programs
 install -pm 0755 build/cdinfo \
                  icedax/cdda2mp3.new \
                  icedax/inf2cdtext.pl \
                  ${S}/packaging/scan_scsi.linux \
                  ${D}/usr/bin
 
 install -pm 0755 3rd-party/geteltorito/geteltorito.pl ${D}/usr/bin/geteltorito
 
 ln -sf wodim ${D}/usr/bin/cdrecord
 ln -sf wodim ${D}/usr/bin/dvdrecord
 ln -sf readom ${D}/usr/bin/readcd
 ln -sf icedax ${D}/usr/bin/cdda2wav
 ln -sf genisoimage ${D}/usr/bin/mkhybrid
 ln -sf genisoimage ${D}/usr/bin/mkisofs
 ln -sf wodim.1.gz ${D}/usr/share/man/man1/cdrecord.1.gz
 ln -sf readom.1.gz ${D}/usr/share/man/man1/readcd.1.gz
 ln -sf icedax.1.gz ${D}/usr/share/man/man1/cdda2wav.1.gz
 
 ln -sf genisoimage.1.gz ${D}/usr/share/man/man1/mkisofs.1.gz
 ln -sf cdda2ogg.1.gz ${D}/usr/share/man/man1/cdda2mp3.1.gz
 
 # Install config files
 install -dm 0755 ${D}/etc
 install -pm 0644 netscsid/netscsid.dfl ${D}/etc/netscsid.conf
 install -pm 0644 wodim/wodim.dfl ${D}/etc/wodim.conf
 
 # Missing man page. Do symlink like in Debian.
 ln -sf wodim.1.gz ${D}/usr/share/man/man1/netscsid.1.gz
 
 
  _target=""; 
  _symlinks=0; 
  _symlinks=1; 
  fdupes -q -n -r ${D} | 
   while read _file; do 
     if test -z "$_target" ; then 
       _target="$_file"; 
     else 
       if test -z "$_file" ; then 
 	_target=""; 
 	continue ; 
       fi ; 
       if test "$_symlinks" = 1; then 
         ln -sf "${_target#${D}}" "$_file"; 
       else 
         ln -f "$_target" "$_file"; 
       fi ;
     fi ; 
  done 
 
 
 
}

PACKAGES = ""
PACKAGES += "genisoimage"
PACKAGES += "cdrkit-cdrtools-compat"
PACKAGES += "cdrkit"
PACKAGES += "icedax"

genisoimage_files = ""
genisoimage_files += "cdrkit.manifest"
genisoimage_files += "/usr/bin/devdump"
genisoimage_files += "/usr/bin/dirsplit"
genisoimage_files += "/usr/bin/genisoimage"
genisoimage_files += "/usr/bin/geteltorito"
genisoimage_files += "/usr/bin/isodebug"
genisoimage_files += "/usr/bin/isodump"
genisoimage_files += "/usr/bin/isoinfo"
genisoimage_files += "/usr/bin/isovfy"
genisoimage_files += "/usr/share/man/man1/devdump.1.gz"
genisoimage_files += "/usr/share/man/man1/dirsplit.1.gz"
genisoimage_files += "/usr/share/man/man1/genisoimage.1.gz"
genisoimage_files += "/usr/share/man/man1/isodebug.1.gz"
genisoimage_files += "/usr/share/man/man1/isodump.1.gz"
genisoimage_files += "/usr/share/man/man1/isoinfo.1.gz"
genisoimage_files += "/usr/share/man/man1/isovfy.1.gz"
genisoimage_files += "/usr/share/man/man5/genisoimagerc.5.gz"

cdrkit-cdrtools-compat_files = ""
cdrkit-cdrtools-compat_files += "cdrkit.manifest"
cdrkit-cdrtools-compat_files += "/usr/bin/cdda2wav"
cdrkit-cdrtools-compat_files += "/usr/bin/cdrecord"
cdrkit-cdrtools-compat_files += "/usr/bin/dvdrecord"
cdrkit-cdrtools-compat_files += "/usr/bin/mkhybrid"
cdrkit-cdrtools-compat_files += "/usr/bin/mkisofs"
cdrkit-cdrtools-compat_files += "/usr/bin/readcd"
cdrkit-cdrtools-compat_files += "/usr/share/man/man1/cdda2wav.1.gz"
cdrkit-cdrtools-compat_files += "/usr/share/man/man1/cdrecord.1.gz"
cdrkit-cdrtools-compat_files += "/usr/share/man/man1/mkisofs.1.gz"
cdrkit-cdrtools-compat_files += "/usr/share/man/man1/readcd.1.gz"

cdrkit_files = ""
cdrkit_files += "cdrkit.manifest"
cdrkit_files += "/etc/netscsid.conf"
cdrkit_files += "/etc/wodim.conf"
cdrkit_files += "/usr/bin/cdinfo"
cdrkit_files += "/usr/bin/readom"
cdrkit_files += "/usr/share/man/man1/netscsid.1.gz"
cdrkit_files += "/usr/share/man/man1/readom.1.gz"
cdrkit_files += "/usr/share/man/man1/wodim.1.gz"

icedax_files = ""
icedax_files += "cdrkit.manifest"
icedax_files += "/usr/bin/cdda2mp3"
icedax_files += "/usr/bin/cdda2mp3.new"
icedax_files += "/usr/bin/cdda2ogg"
icedax_files += "/usr/bin/icedax"
icedax_files += "/usr/bin/inf2cdtext.pl"
icedax_files += "/usr/bin/pitchplay"
icedax_files += "/usr/bin/readmult"
icedax_files += "/usr/bin/scan_scsi.linux"
icedax_files += "/usr/share/man/man1/cdda2mp3.1.gz"
icedax_files += "/usr/share/man/man1/cdda2ogg.1.gz"
icedax_files += "/usr/share/man/man1/icedax.1.gz"
icedax_files += "/usr/share/man/man1/list_audio_tracks.1.gz"
icedax_files += "/usr/share/man/man1/pitchplay.1.gz"
icedax_files += "/usr/share/man/man1/readmult.1.gz"

FILES_genisoimage = "${genisoimage_files}"
FILES_${PN}-cdrtools-compat = "${cdrkit-cdrtools-compat_files}"
FILES_${PN} = "${cdrkit_files}"
FILES_icedax = "${icedax_files}"

PKG_genisoimage= "genisoimage"
PKG_cdrkit-cdrtools-compat= "cdrkit-cdrtools-compat"
PKG_cdrkit= "cdrkit"
PKG_icedax= "icedax"

require cdrkit-extraconf.inc
