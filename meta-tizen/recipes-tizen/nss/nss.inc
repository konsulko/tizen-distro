DESCRIPTION = "Network Security Services"
HOMEPAGE = "http://www.mozilla.org/projects/security/pki/nss/"
SECTION = "Security/Crypto Libraries"
LICENSE = "MPL-1.1 or GPL-2.0+ or LGPL-2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libsoftokn3 
PROVIDES += "libsoftokn3"
RPROVIDES_libsoftokn3 += "libsoftokn3"

#PROVIDES by nss-tools 
PROVIDES += "nss-tools"
RPROVIDES_nss-tools += "nss-tools"

#PROVIDES by nss-devel 
PROVIDES += "nss-devel"
RPROVIDES_nss-devel += "nss-devel"
RPROVIDES_nss-devel += "nss-dev"

#PROVIDES by libfreebl3 
PROVIDES += "libfreebl3"
RPROVIDES_libfreebl3 += "libfreebl3"

#PROVIDES by nss-certs 
PROVIDES += "nss-certs"
RPROVIDES_nss-certs += "nss-certs"

#PROVIDES by nss-sysinit 
PROVIDES += "nss-sysinit"
RPROVIDES_nss-sysinit += "nss-sysinit"

#PROVIDES by nss 
PROVIDES += "nss"
RPROVIDES_nss += "nss"

RDEPENDS = ""
#RDEPENDS of libsoftokn3 (libsoftokn3)
RDEPENDS_libsoftokn3 += "libfreebl3"

#RDEPENDS of nss-tools (${PN}-tools)
RDEPENDS_${PN}-tools += "nss"

#RDEPENDS of nss-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libsoftokn3"
RDEPENDS_${PN}-devel += "libfreebl3"
RDEPENDS_${PN}-devel += "nss"
RDEPENDS_${PN}-devel += "nspr-dev"

#RDEPENDS of nss-sysinit (${PN}-sysinit)
RDEPENDS_${PN}-sysinit += "coreutils"
RDEPENDS_${PN}-sysinit += "nss"

#RDEPENDS of nss (${PN})
RDEPENDS_${PN} += "libsoftokn3"
RDEPENDS_${PN} += "libfreebl3"
RDEPENDS_${PN} += "nss-certs"
RDEPENDS_${PN} += "nspr"


DEPENDS = ""
#DEPENDS of nss 
DEPENDS += "zlib-devel"
DEPENDS += "gcc-cross"
DEPENDS += "pkgconfig(sqlite3)"
DEPENDS += "pkgconfig-native"
DEPENDS += "nspr"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -n nss-3.15.4 -q
 cp ${S}/packaging/nss.manifest .
 
 
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
 
 #modified="$(sed -n '/^----/n;s/ - .*$//;p;q' "${S}/packaging//nss.changes")"
 #DATE="\"$(date -d "${modified}" "+%b %e %Y")\""
 #TIME="\"$(date -d "${modified}" "+%R")\""
 #find . -name '*.[ch]' -print -exec sed -i "s/__DATE__/${DATE}/g;s/__TIME__/${TIME}/g" {} +
 
 cd nss
 export FREEBL_NO_DEPEND=1
 export NSPR_INCLUDE_DIR=`nspr-config --includedir`
 export NSPR_LIB_DIR=`nspr-config --libdir`
 export OPT_FLAGS="$RPM_OPT_FLAGS -fno-strict-aliasing"
 export LIBDIR=/usr/lib
 export USE_64=1
 export NSS_USE_SYSTEM_SQLITE=1
 MAKE_FLAGS="BUILD_OPT=1 NSS_ENABLE_ECC=1"
 make nss_build_all $MAKE_FLAGS
 # run testsuite
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 mkdir -p $RPM_BUILD_ROOT/usr/lib
 mkdir -p $RPM_BUILD_ROOT/usr/libexec/nss
 mkdir -p $RPM_BUILD_ROOT/usr/include/nss3
 mkdir -p $RPM_BUILD_ROOT/usr/bin
 mkdir -p $RPM_BUILD_ROOT/usr/sbin
 mkdir -p $RPM_BUILD_ROOT/etc/pki/nssdb
 pushd dist/Linux*
 # copy headers
 cp -rL ../public/nss/*.h $RPM_BUILD_ROOT/usr/include/nss3
 # copy dynamic libs
 cp -L  lib/libnss3.so \
        lib/libnssdbm3.so \
        lib/libnssdbm3.chk \
        lib/libnssutil3.so \
        lib/libnssckbi.so \
        lib/libnsssysinit.so \
        lib/libsmime3.so \
        lib/libsoftokn3.so \
        lib/libsoftokn3.chk \
        lib/libssl3.so \
        $RPM_BUILD_ROOT/usr/lib
 cp -L  lib/libfreebl3.so \
        lib/libfreebl3.chk \
        $RPM_BUILD_ROOT//usr/lib
 # copy static libs
 cp -L  lib/libcrmf.a \
        lib/libnssb.a \
        lib/libnssckfw.a \
        $RPM_BUILD_ROOT/usr/lib
 # copy tools
 cp -L  bin/certutil \
        bin/cmsutil \
        bin/crlutil \
        bin/modutil \
        bin/pk12util \
        bin/signtool \
        bin/signver \
        bin/ssltap \
        $RPM_BUILD_ROOT/usr/bin
 # copy unsupported tools
 cp -L  bin/atob \
        bin/btoa \
        bin/derdump \
        bin/ocspclnt \
        bin/pp \
        bin/selfserv \
        bin/shlibsign \
        bin/strsclnt \
        bin/symkeyutil \
        bin/tstclnt \
        bin/vfyserv \
        bin/vfychain \
        $RPM_BUILD_ROOT/usr/libexec/nss
 # prepare pkgconfig file
 mkdir -p $RPM_BUILD_ROOT/usr/lib/pkgconfig/
 sed "s:%LIBDIR%:/usr/lib:g
 s:%VERSION%:3.15.4:g
 s:%NSPR_VERSION%:4.9.2:g" \
   ${S}/packaging/nss.pc.in > $RPM_BUILD_ROOT/usr/lib/pkgconfig/nss.pc
 # prepare nss-config file
 popd
 NSS_VMAJOR=`cat nss/lib/nss/nss.h | grep "#define.*NSS_VMAJOR" | awk '{print $3}'`
 NSS_VMINOR=`cat nss/lib/nss/nss.h | grep "#define.*NSS_VMINOR" | awk '{print $3}'`
 NSS_VPATCH=`cat nss/lib/nss/nss.h | grep "#define.*NSS_VPATCH" | awk '{print $3}'`
 cat ${S}/packaging/nss-config.in | sed -e "s,@libdir@,/usr/lib,g" \
                      -e "s,@prefix@,/usr,g" \
                      -e "s,@exec_prefix@,/usr,g" \
                      -e "s,@includedir@,/usr/include/nss3,g" \
                      -e "s,@MOD_MAJOR_VERSION@,$NSS_VMAJOR,g" \
                      -e "s,@MOD_MINOR_VERSION@,$NSS_VMINOR,g" \
                      -e "s,@MOD_PATCH_VERSION@,$NSS_VPATCH,g" \
                      > $RPM_BUILD_ROOT//usr/bin/nss-config
 chmod 755 $RPM_BUILD_ROOT//usr/bin/nss-config
 # setup-nsssysinfo.sh
 install -m 744 ${S}/packaging/setup-nsssysinit.sh $RPM_BUILD_ROOT/usr/sbin/
 # create empty NSS database
 #LD_LIBRARY_PATH=$RPM_BUILD_ROOT/lib:$RPM_BUILD_ROOT/usr/lib $RPM_BUILD_ROOT/usr/bin/modutil -force -dbdir "sql:$RPM_BUILD_ROOT/etc/pki/nssdb" -create
 #LD_LIBRARY_PATH=$RPM_BUILD_ROOT/lib:$RPM_BUILD_ROOT/usr/lib $RPM_BUILD_ROOT/usr/bin/certutil -N -d "sql:$RPM_BUILD_ROOT/etc/pki/nssdb" -f /dev/null 2>&1 > /dev/null
 #chmod 644 "$RPM_BUILD_ROOT/etc/pki/nssdb"/*
 #sed "s:${D}::g
 #s/^library=$/library=libnsssysinit.so/
 #/^NSS/s/\(Flags=internal\)\(,[^m]\)/\1,moduleDBOnly\2/" \
 #  $RPM_BUILD_ROOT/etc/pki/nssdb/pkcs11.txt > $RPM_BUILD_ROOT/etc/pki/nssdb/pkcs11.txt.sed
 #  mv $RPM_BUILD_ROOT/etc/pki/nssdb/pkcs11.txt{.sed,}
 # copy empty NSS database
 install -m 644 ${S}/packaging/cert9.db $RPM_BUILD_ROOT/etc/pki/nssdb
 install -m 644 ${S}/packaging/key4.db $RPM_BUILD_ROOT/etc/pki/nssdb
 install -m 644 ${S}/packaging/pkcs11.txt $RPM_BUILD_ROOT/etc/pki/nssdb
 # create shlib sigs after extracting debuginfo
 
 
}

PACKAGES = ""
PACKAGES += "libsoftokn3"
PACKAGES += "nss-tools"
PACKAGES += "nss-devel"
PACKAGES += "libfreebl3"
PACKAGES += "nss-certs"
PACKAGES += "nss-sysinit"
PACKAGES += "nss"

libsoftokn3_files = ""
libsoftokn3_files += "nss.manifest"
libsoftokn3_files += "/usr/lib/libsoftokn3.so"
libsoftokn3_files += "/usr/lib/libsoftokn3.chk"
libsoftokn3_files += "/usr/lib/libnssdbm3.so"
libsoftokn3_files += "/usr/lib/libnssdbm3.chk"

nss-tools_files = ""
nss-tools_files += "nss.manifest"
nss-tools_files += "/usr/bin/*"
nss-tools_files += "/usr/libexec/nss/"

nss-devel_files = ""
nss-devel_files += "nss.manifest"
nss-devel_files += "/usr/include/nss3/"
nss-devel_files += "/usr/lib/*.a"
nss-devel_files += "/usr/lib/pkgconfig/*"

libfreebl3_files = ""
libfreebl3_files += "nss.manifest"
libfreebl3_files += "/usr/lib/libfreebl3.so"
libfreebl3_files += "/usr/lib/libfreebl3.chk"

nss-certs_files = ""
nss-certs_files += "nss.manifest"
nss-certs_files += "/usr/lib/libnssckbi.so"

nss-sysinit_files = ""
nss-sysinit_files += "nss.manifest"
nss-sysinit_files += "/etc/pki"
nss-sysinit_files += "/etc/pki/nssdb"
nss-sysinit_files += "/etc/pki/nssdb/*"
nss-sysinit_files += "/usr/lib/libnsssysinit.so"
nss-sysinit_files += "/usr/sbin/setup-nsssysinit.sh"

nss_files = ""
nss_files += "nss.manifest"
nss_files += "/usr/lib/libnss3.so"
nss_files += "/usr/lib/libnssutil3.so"
nss_files += "/usr/lib/libsmime3.so"
nss_files += "/usr/lib/libssl3.so"

FILES_libsoftokn3 = "${libsoftokn3_files}"
FILES_${PN}-tools = "${nss-tools_files}"
FILES_${PN}-devel = "${nss-devel_files}"
FILES_libfreebl3 = "${libfreebl3_files}"
FILES_${PN}-certs = "${nss-certs_files}"
FILES_${PN}-sysinit = "${nss-sysinit_files}"
FILES_${PN} = "${nss_files}"

PKG_libsoftokn3= "libsoftokn3"
PKG_nss-tools= "nss-tools"
PKG_nss-devel= "nss-devel"
PKG_libfreebl3= "libfreebl3"
PKG_nss-certs= "nss-certs"
PKG_nss-sysinit= "nss-sysinit"
PKG_nss= "nss"

require nss-extraconf.inc
