DESCRIPTION = "MIT Kerberos5 Implementation--Libraries"
HOMEPAGE = "http://web.mit.edu/kerberos/www/"
SECTION = "Productivity/Networking/Security"
LICENSE = "MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by krb5 
PROVIDES += "krb5"
RPROVIDES_krb5 += "krb5"

#PROVIDES by krb5-devel 
PROVIDES += "krb5-devel"
RPROVIDES_krb5-devel += "krb5-devel"
RPROVIDES_krb5-devel += "krb5-dev"

RDEPENDS = ""
#RDEPENDS of krb5-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "krb5"
RDEPENDS_${PN}-devel += "keyutils-dev"
RDEPENDS_${PN}-devel += "libcom_err-dev"


DEPENDS = ""
#DEPENDS of krb5 
DEPENDS += "keyutils"
DEPENDS += "autoconf-native"
DEPENDS += "bison-native"
DEPENDS += "e2fsprogs"
DEPENDS += "ncurses-devel"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n krb5-1.10.2
 cp ${S}/packaging/krb5.manifest .
 
 
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
 
 # needs to be re-generated
 rm -f src/lib/krb5/krb/deltat.c
 cd src
 ./util/reconf
 CFLAGS="$RPM_OPT_FLAGS -I/usr/include/et -fno-strict-aliasing -D_GNU_SOURCE -fPIC " \
 ./configure \
 	--prefix=/usr/lib/mit \
 	--sysconfdir=/etc \
 	--mandir=/usr/share/man \
 	--infodir=/usr/share/info \
 	--libexecdir=/usr/lib/mit/sbin \
 	--libdir=/usr/lib \
 	--includedir=/usr/include \
         --localstatedir=/var/lib/kerberos \
 	--enable-shared \
 	--disable-static \
         --enable-kdc-replay-cache \
         --enable-dns-for-realm \
         --disable-rpath \
         --disable-pkinit \
         --without-pam \
         --with-system-et \
         --with-system-ss
 make -j16 
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 cd src
 make DESTDIR=${D} install 
 cd ..
 # Munge the krb5-config script to remove rpaths and CFLAGS.
 sed "s|^CC_LINK=.*|CC_LINK='\$(CC) \$(PROG_LIBPATH)'|g" src/krb5-config > $RPM_BUILD_ROOT/usr/lib/mit/bin/krb5-config
 # install autoconf macro
 mkdir -p ${D}//usr/share/aclocal
 install -m 644 src/util/ac_check_krb5.m4 ${D}/usr/share/aclocal/
 # install sample config files
 # I'll probably do something about this later on
 mkdir -p ${D}/etc ${D}/var/lib/kerberos/krb5kdc
 mkdir -p ${D}/etc
 mkdir -p ${D}/etc/profile.d/
 mkdir -p ${D}/var/log/krb5
 mkdir -p ${D}/etc/sysconfig/SuSEfirewall2.d/services/
 # create plugin directories
 mkdir -p ${D}//usr/lib/krb5/plugins/kdb
 mkdir -p ${D}//usr/lib/krb5/plugins/preauth
 mkdir -p ${D}//usr/lib/krb5/plugins/libkrb5
 # all libs must have permissions 0755 
 for lib in `find ${D}//usr/lib/ -type f -name "*.so*"`
 do 
   chmod 0755 ${lib} 
 done
 # and binaries too
 chmod 0755 ${D}/usr/lib/mit/bin/ksu
 find . -type f -name '*.ps' -exec gzip -9 {} \;
 # create rc* links 
 # create links for kinit and klist, because of the java ones
 #ln -sf ../../usr/lib/mit/bin/kinit   ${D}/usr/bin/kinit
 #ln -sf ../../usr/lib/mit/bin/klist   ${D}/usr/bin/klist
 
 
 mkdir -p ${D}/usr/bin
 ln -sf ../../usr/lib/mit/bin/krb5-config ${D}/usr/bin/krb5-config
 # install doc
 install -d -m 755 ${D}//usr/share/doc/packages/krb5
 install -m 644 ${WORKDIR}/krb5-1.10.2/README ${D}//usr/share/doc/packages/krb5/README
 # cleanup
 rm -f  ${D}/usr/share/man/man1/tmac.doc*
 rm -f  /usr/share/man/man1/tmac.doc*
 rm -rf ${D}/usr/lib/mit/share/examples
 rm -rf ${D}/usr/lib/mit/share/locale
 #####################################################
 # krb5(-mini) pre/post/postun
 #####################################################
 
 
}

PACKAGES = ""
PACKAGES += "krb5"
PACKAGES += "krb5-devel"

krb5_files = ""
krb5_files += "krb5.manifest"
krb5_files += "/usr/share/doc/packages/krb5"
krb5_files += "/usr/lib/krb5"
krb5_files += "/usr/lib/krb5/plugins"
krb5_files += "/usr/lib/krb5/plugins/kdb"
krb5_files += "/usr/lib/krb5/plugins/preauth"
krb5_files += "/usr/lib/krb5/plugins/libkrb5"
krb5_files += "/var/lib/kerberos/"
krb5_files += "/var/lib/kerberos/krb5kdc"
krb5_files += "/usr/lib/mit"
krb5_files += "/usr/lib/mit/sbin"
krb5_files += "/usr/lib/mit/bin"
krb5_files += "/usr/share/doc/packages/krb5/README"
krb5_files += "/usr/lib/libgssapi_krb5.*"
krb5_files += "/usr/lib/libgssrpc.so.*"
krb5_files += "/usr/lib/libk5crypto.so.*"
krb5_files += "/usr/lib/libkadm5clnt_mit.so.*"
krb5_files += "/usr/lib/libkadm5srv_mit.so.*"
krb5_files += "/usr/lib/libkdb5.so.*"
krb5_files += "/usr/lib/libkrb5.so.*"
krb5_files += "/usr/lib/libkrb5support.so.*"
krb5_files += "/usr/lib/libverto.so.*"
krb5_files += "/usr/lib/libverto-k5ev.so.*"
krb5_files += "/usr/lib/krb5/plugins/kdb/*"
krb5_files += "/usr/lib/mit/sbin/kadmin.local"
krb5_files += "/usr/lib/mit/sbin/kadmind"
krb5_files += "/usr/lib/mit/sbin/kpropd"
krb5_files += "/usr/lib/mit/sbin/kproplog"
krb5_files += "/usr/lib/mit/sbin/kprop"
krb5_files += "/usr/lib/mit/sbin/kdb5_util"
krb5_files += "/usr/lib/mit/sbin/krb5kdc"
krb5_files += "/usr/lib/mit/sbin/uuserver"
krb5_files += "/usr/lib/mit/sbin/sserver"
krb5_files += "/usr/lib/mit/sbin/gss-server"
krb5_files += "/usr/lib/mit/sbin/sim_server"
krb5_files += "/usr/lib/mit/bin/k5srvutil"
krb5_files += "/usr/lib/mit/bin/kvno"
krb5_files += "/usr/lib/mit/bin/kinit"
krb5_files += "/usr/lib/mit/bin/kdestroy"
krb5_files += "/usr/lib/mit/bin/kpasswd"
krb5_files += "/usr/lib/mit/bin/klist"
krb5_files += "/usr/lib/mit/bin/kadmin"
krb5_files += "/usr/lib/mit/bin/ktutil"
krb5_files += "/usr/lib/mit/bin/kswitch"
krb5_files += "/usr/lib/mit/bin/uuclient"
krb5_files += "/usr/lib/mit/bin/sclient"
krb5_files += "/usr/lib/mit/bin/gss-client"
krb5_files += "/usr/lib/mit/bin/sim_client"
krb5_files += "/usr/share/man/man1/kvno.1*"
krb5_files += "/usr/share/man/man1/kinit.1*"
krb5_files += "/usr/share/man/man1/kdestroy.1*"
krb5_files += "/usr/share/man/man1/kpasswd.1*"
krb5_files += "/usr/share/man/man1/klist.1*"
krb5_files += "/usr/share/man/man1/kerberos.1*"
krb5_files += "/usr/share/man/man1/ksu.1*"
krb5_files += "/usr/share/man/man1/sclient.1*"
krb5_files += "/usr/share/man/man1/kadmin.1*"
krb5_files += "/usr/share/man/man1/ktutil.1*"
krb5_files += "/usr/share/man/man1/k5srvutil.1*"
krb5_files += "/usr/share/man/man1/kswitch.1*"
krb5_files += "/usr/share/man/man5/*"
krb5_files += "/usr/share/man/man5/.k5login.5.gz"
krb5_files += "/usr/share/man/man5/.k5identity.5*"
krb5_files += "/usr/share/man/man8/*"

krb5-devel_files = ""
krb5-devel_files += "krb5.manifest"
krb5-devel_files += "/usr/bin/krb5-config"
krb5-devel_files += "/usr/lib/mit"
krb5-devel_files += "/usr/lib/mit/bin"
krb5-devel_files += "/usr/lib/mit/sbin"
krb5-devel_files += "/usr/lib/mit/share"
krb5-devel_files += "/usr/share/aclocal"
krb5-devel_files += "/usr/lib/libgssrpc.so"
krb5-devel_files += "/usr/lib/libk5crypto.so"
krb5-devel_files += "/usr/lib/libkadm5clnt_mit.so"
krb5-devel_files += "/usr/lib/libkadm5clnt.so"
krb5-devel_files += "/usr/lib/libkadm5srv_mit.so"
krb5-devel_files += "/usr/lib/libkadm5srv.so"
krb5-devel_files += "/usr/lib/libkdb5.so"
krb5-devel_files += "/usr/lib/libkrb5.so"
krb5-devel_files += "/usr/lib/libkrb5support.so"
krb5-devel_files += "/usr/lib/libverto.so"
krb5-devel_files += "/usr/lib/libverto-k5ev.so"
krb5-devel_files += "/usr/include/*"
krb5-devel_files += "/usr/lib/mit/bin/krb5-config"
krb5-devel_files += "/usr/lib/mit/sbin/krb5-send-pr"
krb5-devel_files += "/usr/lib/mit/share/gnats"
krb5-devel_files += "/usr/share/man/man1/krb5-send-pr.1*"
krb5-devel_files += "/usr/share/man/man1/krb5-config.1*"
krb5-devel_files += "/usr/share/aclocal/ac_check_krb5.m4"

FILES_${PN} = "${krb5_files}"
FILES_${PN}-devel = "${krb5-devel_files}"

PKG_krb5= "krb5"
PKG_krb5-devel= "krb5-devel"

require krb5-extraconf.inc
