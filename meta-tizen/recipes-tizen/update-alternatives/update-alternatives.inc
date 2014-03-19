DESCRIPTION = "Maintain symbolic links determining default commands"
HOMEPAGE = "http://ftp.de.debian.org/debian/pool/main/d/dpkg/"
SECTION = "System/Management"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by update-alternatives 
PROVIDES += "update-alternatives"
RPROVIDES_update-alternatives += "update-alternatives"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of update-alternatives 
DEPENDS += "ncurses"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n dpkg-1.16.3
 cp ${S}/packaging/update-alternatives.manifest .
 
 
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
     --with-admindir=/var/lib/rpm/ \
     --disable-compiler-warnings # disable for sles10 -Wvla
 
 make -C lib/compat -j16
 make -C utils/ -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 install -d -m 0755 ${D}//usr/sbin/
 install -d -m 0755 ${D}//usr/share/man/man8/
 install -d -m 0755 ${D}//etc/alternatives
 install -d -m 0755 ${D}//var/lib/rpm//alternatives
 install -d -m 0755 ${D}//var/log
 
 install -m 0755 utils/update-alternatives ${D}//usr/sbin
 install -m 0644 man/update-alternatives.8 ${D}//usr/share/man/man8/
 
 touch ${D}//var/log/update-alternatives.log
 
 
}

PACKAGES = ""
PACKAGES += "update-alternatives"

update-alternatives_files = ""
update-alternatives_files += "update-alternatives.manifest"
update-alternatives_files += "/etc/alternatives"
update-alternatives_files += "/var/lib/rpm/alternatives"
update-alternatives_files += "/usr/sbin/update-alternatives"
update-alternatives_files += "/usr/share/man/man8/update-alternatives.8*"

FILES_${PN} = "${update-alternatives_files}"

PKG_update-alternatives= "update-alternatives"

require update-alternatives-extraconf.inc
