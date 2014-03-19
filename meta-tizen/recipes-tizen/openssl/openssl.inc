DESCRIPTION = "Secure Sockets and Transport Layer Security"
HOMEPAGE = "http://www.openssl.org/"
SECTION = "Security/Crypto Libraries"
LICENSE = "OpenSSL"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by openssl-doc 
PROVIDES += "openssl-doc"
RPROVIDES_openssl-doc += "openssl-doc"

#PROVIDES by openssl-misc 
PROVIDES += "openssl-misc"
RPROVIDES_openssl-misc += "openssl-misc"

#PROVIDES by libopenssl-devel 
PROVIDES += "libopenssl-devel"
RPROVIDES_libopenssl-devel += "libopenssl-devel"
RPROVIDES_libopenssl-devel += "libopenssl-dev"
# the PROVIDES rules is ignore "openssl-devel = 1.0.1e"
PROVIDES += "openssl-devel"
RPROVIDES_libopenssl-devel += "openssl-devel"
RPROVIDES_libopenssl-devel += "openssl-dev"

#PROVIDES by openssl 
PROVIDES += "openssl"
RPROVIDES_openssl += "openssl"
# the PROVIDES rules is ignore "ssl  "
PROVIDES += "ssl"
RPROVIDES_openssl += "ssl"

#PROVIDES by libopenssl 
PROVIDES += "libopenssl"
RPROVIDES_libopenssl += "libopenssl"

RDEPENDS = ""
#RDEPENDS of libopenssl-devel (lib${PN}-devel)
RDEPENDS_lib${PN}-devel += "zlib-dev"
RDEPENDS_lib${PN}-devel += "openssl"
RDEPENDS_lib${PN}-devel += "libopenssl"


DEPENDS = ""
#DEPENDS of openssl 
DEPENDS += "zlib-devel"
DEPENDS += "ed"
DEPENDS += "pkgconfig-native"
DEPENDS += "bc"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q 
 cp ${S}/packaging/openssl.manifest .
 
 echo "adding/overwriting some entries in the 'table' hash in Configure"
 # $dso_scheme:$shared_target:$shared_cflag:$shared_ldflag:$shared_extension:$ranlib:$arflags
 export DSO_SCHEME='dlfcn:linux-shared:-fPIC::.so.\$(SHLIB_MAJOR).\$(SHLIB_MINOR)::'
 cat <<EOF_ED | ed -s Configure 
 /^);
 -
 i
 #
 # local configuration added from specfile
 # ... MOST of those are now correct in openssl's Configure already, 
 # so only add them for new ports!
 #
 #config-string,  $cc:$cflags:$unistd:$thread_cflag:$sys_id:$lflags:$bn_ops:$cpuid_obj:$bn_obj:$des_obj:$aes_obj:$bf_obj:$md5_obj:$sha1_obj:$cast_obj:$rc4_obj:$rmd160_obj:$rc5_obj:$wp_obj:$cmll_obj:$dso_scheme:$shared_target:$shared_cflag:$shared_ldflag:$shared_extension:$ranlib:$arflags:$multilib
 #"linux-elf",    "gcc:-DL_ENDIAN			::-D_REENTRANT::-ldl:BN_LLONG \${x86_gcc_des} \${x86_gcc_opts}:\${x86_elf_asm}:$DSO_SCHEME:",
 #"linux-ia64",   "gcc:-DL_ENDIAN	-DMD32_REG_T=int::-D_REENTRANT::-ldl:SIXTY_FOUR_BIT_LONG RC4_CHUNK RC4_CHAR:\${ia64_asm}:		$DSO_SCHEME:",
 #"linux-ppc",    "gcc:-DB_ENDIAN			::-D_REENTRANT::-ldl:BN_LLONG RC4_CHAR RC4_CHUNK DES_RISC1 DES_UNROLL:\${no_asm}:		$DSO_SCHEME:",
 #"linux-ppc64",  "gcc:-DB_ENDIAN -DMD32_REG_T=int::-D_REENTRANT::-ldl:RC4_CHAR RC4_CHUNK DES_RISC1 DES_UNROLL SIXTY_FOUR_BIT_LONG:\${no_asm}:	$DSO_SCHEME:64",
 "linux-elf-arm","gcc:-DL_ENDIAN			::-D_REENTRANT::-ldl:BN_LLONG:\${no_asm}:							$DSO_SCHEME:",
 "linux-mips",   "gcc:-DB_ENDIAN			::-D_REENTRANT::-ldl:BN_LLONG RC4_CHAR RC4_CHUNK DES_RISC1 DES_UNROLL:\${no_asm}:		$DSO_SCHEME:",
 "linux-sparcv7","gcc:-DB_ENDIAN			::-D_REENTRANT::-ldl:BN_LLONG RC4_CHAR RC4_CHUNK DES_UNROLL BF_PTR:\${no_asm}:			$DSO_SCHEME:",
 #"linux-sparcv8","gcc:-DB_ENDIAN -DBN_DIV2W -mv8	::-D_REENTRANT::-ldl:BN_LLONG RC4_CHAR RC4_CHUNK DES_UNROLL BF_PTR::asm/sparcv8.o:::::::::::::	$DSO_SCHEME:",
 #"linux-x86_64", "gcc:-DL_ENDIAN -DNO_ASM -DMD32_REG_T=int::-D_REENTRANT::-ldl:SIXTY_FOUR_BIT_LONG:\${no_asm}:						$DSO_SCHEME:64",
 #"linux-s390",   "gcc:-DB_ENDIAN			::(unknown):   :-ldl:BN_LLONG:\${no_asm}:							$DSO_SCHEME:",
 #"linux-s390x",  "gcc:-DB_ENDIAN -DNO_ASM -DMD32_REG_T=int::-D_REENTRANT::-ldl:SIXTY_FOUR_BIT_LONG:\${no_asm}:					$DSO_SCHEME:64",
 "linux-parisc",	"gcc:-DB_ENDIAN 		::-D_REENTRANT::-ldl:BN_LLONG RC4_CHAR DES_PTR DES_UNROLL DES_RISC1:\${no_asm}:			$DSO_SCHEME:",
 .
 wq
 EOF_ED
 # fix ENGINESDIR path
 sed -i 's,/lib/engines,/lib/engines,' Configure
 # Record mtime of changes file instead of build time
 CHANGES=`stat --format="%y" ${S}/packaging/openssl.changes`
 sed -i -e "s|#define DATE \(.*\).LC_ALL.*date.|#define DATE \1$CHANGES|" crypto/Makefile
 
 
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
 
 RPM_OPT_FLAGS=$(echo $RPM_OPT_FLAGS | sed -s "s/--param=ssp-buffer-size=32//g")
 export RPM_OPT_FLAGS
 
 ./config --test-sanity 
 #
 config_flags="threads shared no-rc5 no-idea \
 enable-camellia enable-md2 \
 zlib \
 --prefix=/usr \
 --libdir=lib \
 --openssldir=/etc/ssl \
 $RPM_OPT_FLAGS -std=gnu99 \
 -Wa,--noexecstack \
 -fomit-frame-pointer \
 -DTERMIO \
 -DPURIFY \
 -DSSL_FORBID_ENULL \
 -D_GNU_SOURCE \
 $(getconf LFS_CFLAGS) \
 -Wall \
 -fstack-protector "
 #
 #
 #%if 0
 #	# generate feedback
 #	./config $config_flags
 #	make depend CC="gcc -fprofile-generate"
 #	make CC="gcc -fprofile-generate"
 #	LD_LIBRARY_PATH=`pwd` make rehash CC="gcc -fprofile-generate"
 #	LD_LIBRARY_PATH=`pwd` make test CC="gcc -fprofile-generate"
 #	LD_LIBRARY_PATH=`pwd` apps/openssl speed
 #	make clean
 #	# compile with feedback
 #	# but not if it makes a cipher slower:
 #	#find crypto/aes -name '*.da' | xargs -r rm
 #	./config $config_flags -fprofile-use
 #	make depend
 #	make
 #	LD_LIBRARY_PATH=`pwd` make rehash
 #	LD_LIBRARY_PATH=`pwd` make test
 #%else
 # OpenSSL relies on uname -m (not good). Thus that little sparc line.
 	./config \
 		$config_flags
 	make depend
 	make
 	LD_LIBRARY_PATH=`pwd` make rehash
 	#LD_LIBRARY_PATH=`pwd` make test
 #%endif
 # show settings
 make TABLE
 echo $RPM_OPT_FLAGS
 eval $(egrep PLATFORM='[[:alnum:]]' Makefile)
 grep -B1 -A22 "^\*\*\* $PLATFORM$" TABLE 
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 rm -rf $RPM_BUILD_ROOT
 make MANDIR=/usr/share/man INSTALL_PREFIX=$RPM_BUILD_ROOT install
 install -d -m755 $RPM_BUILD_ROOT/etc/ssl/certs
 ln -sf ./openssl $RPM_BUILD_ROOT//usr/include/ssl
 mkdir $RPM_BUILD_ROOT//usr/share/ssl
 mv $RPM_BUILD_ROOT//etc/ssl/misc $RPM_BUILD_ROOT//usr/share/ssl/
 # ln -s /etc/ssl/certs 	$RPM_BUILD_ROOT//usr/share/ssl/certs
 # ln -s /etc/ssl/private 	$RPM_BUILD_ROOT//usr/share/ssl/private
 # ln -s /etc/ssl/openssl.cnf 	$RPM_BUILD_ROOT//usr/share/ssl/openssl.cnf
 #
 
 # avoid file conflicts with man pages from other packages
 #
 pushd $RPM_BUILD_ROOT//usr/share/man
 # some man pages now contain spaces. This makes several scripts go havoc, among them /usr/sbin/Check.
 # replace spaces by underscores
 #for i in man?/*\ *; do mv -v "$i" "${i// /_}"; done
 which readlink &>/dev/null || function readlink { ( set +x; target=$(file $1 2>/dev/null); target=${target//* }; test -f $target && echo $target; ) }
 for i in man?/*; do 
 	if test -L $i ; then
 	    LDEST=`readlink $i`
 	    rm -f $i ${i}ssl
 	    ln -sf ${LDEST}ssl ${i}ssl
 	else
 	    mv $i ${i}ssl
         fi
 	case `basename ${i%.*}` in 
 	    asn1parse|ca|config|crl|crl2pkcs7|crypto|dgst|dhparam|dsa|dsaparam|enc|gendsa|genrsa|nseq|openssl|passwd|pkcs12|pkcs7|pkcs8|rand|req|rsa|rsautl|s_client|s_server|smime|spkac|ssl|verify|version|x509)
 		# these are the pages mentioned in openssl(1). They go into the main package.
 		echo %doc /usr/share/man/${i}ssl.gz >> $OLDPWD/filelist.doc;;
 	    *)	
 		# the rest goes into the openssl-doc package.
 		echo %doc /usr/share/man/${i}ssl.gz >> $OLDPWD/filelist.doc;;
 	esac
 done
 popd
 #
 # check wether some shared library has been installed
 #
 ls -l $RPM_BUILD_ROOT/usr/lib
 test -f $RPM_BUILD_ROOT/usr/lib/libssl.so.1.0.0
 test -f $RPM_BUILD_ROOT/usr/lib/libcrypto.so.1.0.0
 test -L $RPM_BUILD_ROOT/usr/lib/libssl.so
 test -L $RPM_BUILD_ROOT/usr/lib/libcrypto.so
 #
 # see what we've got
 #
 cat > showciphers.c <<EOF
 #include <openssl/err.h>
 #include <openssl/ssl.h>
 int main(){
 unsigned int i;
 SSL_CTX *ctx;
 SSL *ssl;
 SSL_METHOD *meth;
   meth = SSLv23_client_method();
   SSLeay_add_ssl_algorithms();
   ctx = SSL_CTX_new(meth);
   if (ctx == NULL) return 0;
   ssl = SSL_new(ctx);
   if (!ssl) return 0;
   for (i=0; ; i++) {
     int j, k;
     SSL_CIPHER *sc;
     sc = (meth->get_cipher)(i);
     if (!sc) break;
     k = SSL_CIPHER_get_bits(sc, &j);
     printf("%s\n", sc->name);
   }
   return 0;
 };
 EOF
 gcc $RPM_OPT_FLAGS -I${RPM_BUILD_ROOT}/usr/include -c showciphers.c
 gcc -o showciphers showciphers.o -L${RPM_BUILD_ROOT}/usr/lib -lssl -lcrypto
 LD_LIBRARY_PATH=${RPM_BUILD_ROOT}/usr/lib ./showciphers > AVAILABLE_CIPHERS || true
 cat AVAILABLE_CIPHERS
 # Do not install demo scripts executable under /usr/share/doc
 find demos -type f -perm /111 -exec chmod 644 {} \;
 
 #process openssllib
 mkdir $RPM_BUILD_ROOT/lib
 mv $RPM_BUILD_ROOT/usr/lib/libssl.so.1.0.0 $RPM_BUILD_ROOT/lib/
 mv $RPM_BUILD_ROOT/usr/lib/libcrypto.so.1.0.0 $RPM_BUILD_ROOT/lib/
 mv $RPM_BUILD_ROOT/usr/lib/engines $RPM_BUILD_ROOT/lib/
 cd $RPM_BUILD_ROOT/usr/lib/
 ln -sf /lib/libssl.so.1.0.0 ./libssl.so
 ln -sf /lib/libcrypto.so.1.0.0 ./libcrypto.so
 
 cd $RPM_BUILD_DIR
 
 
 
}

PACKAGES = ""
PACKAGES += "openssl-doc"
PACKAGES += "openssl-misc"
PACKAGES += "libopenssl-devel"
PACKAGES += "openssl"
PACKAGES += "libopenssl"

openssl-doc_files = ""
openssl-doc_files += "openssl.manifest"
openssl-doc_files += "doc/* demos"
openssl-doc_files += "showciphers.c"

openssl-misc_files = ""
openssl-misc_files += "openssl.manifest"
openssl-misc_files += "/usr/share/ssl/misc"
openssl-misc_files += "/usr/bin/c_rehash"

libopenssl-devel_files = ""
libopenssl-devel_files += "openssl.manifest"
libopenssl-devel_files += "/usr/include/openssl/"
libopenssl-devel_files += "/usr/include/ssl"
libopenssl-devel_files += "/usr/lib/libssl.so"
libopenssl-devel_files += "/usr/lib/libcrypto.so"
libopenssl-devel_files += "/usr/lib/pkgconfig/libcrypto.pc"
libopenssl-devel_files += "/usr/lib/pkgconfig/libssl.pc"
libopenssl-devel_files += "/usr/lib/pkgconfig/openssl.pc"

openssl_files = ""
openssl_files += "openssl.manifest"
openssl_files += "/etc/ssl"
openssl_files += "/etc/ssl/certs"
openssl_files += "(noreplace) /etc/ssl/openssl.cnf"
openssl_files += "/usr/share/ssl"
openssl_files += "/usr/bin/openssl"

libopenssl_files = ""
libopenssl_files += "openssl.manifest"
libopenssl_files += "/lib/libssl.so.1.0.0"
libopenssl_files += "/lib/libcrypto.so.1.0.0"
libopenssl_files += "/lib/engines"

FILES_${PN}-doc = "${openssl-doc_files}"
FILES_${PN}-misc = "${openssl-misc_files}"
FILES_lib${PN}-devel = "${libopenssl-devel_files}"
FILES_${PN} = "${openssl_files}"
FILES_lib${PN} = "${libopenssl_files}"

PKG_openssl-doc= "openssl-doc"
PKG_openssl-misc= "openssl-misc"
PKG_libopenssl-devel= "libopenssl-devel"
PKG_openssl= "openssl"
PKG_libopenssl= "libopenssl"

require openssl-extraconf.inc
