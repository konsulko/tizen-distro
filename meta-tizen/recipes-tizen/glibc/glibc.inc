DESCRIPTION = "Standard Shared Libraries (from the GNU C Library)"
HOMEPAGE = "http://www.gnu.org/software/libc/libc.html"
SECTION = "Base/Libraries"
LICENSE = "LGPL-2.1+ and LGPL-2.1+-with-GCC-exception and GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by glibc-devel 
PROVIDES += "glibc-devel"
RPROVIDES_glibc-devel += "glibc-devel"
RPROVIDES_glibc-devel += "glibc-dev"

#PROVIDES by glibc-locale 
PROVIDES += "glibc-locale"
RPROVIDES_glibc-locale += "glibc-locale"

#PROVIDES by glibc-devel-static 
PROVIDES += "glibc-devel-static"
RPROVIDES_glibc-devel-static += "glibc-devel-static"
RPROVIDES_glibc-devel-static += "glibc-dev"
# the PROVIDES rules is ignore "glibc-static = 2.18"
PROVIDES += "glibc-static"
RPROVIDES_glibc-devel-static += "glibc-static"

#PROVIDES by glibc-extra 
PROVIDES += "glibc-extra"
RPROVIDES_glibc-extra += "glibc-extra"

#PROVIDES by glibc 
PROVIDES += "glibc"
RPROVIDES_glibc += "glibc"
# the PROVIDES rules is ignore "rtld(GNU_HASH)  "
PROVIDES += "rtld(GNU_HASH)"
RPROVIDES_glibc += "rtld(GNU_HASH)"

#PROVIDES by glibc-obsolete 
PROVIDES += "glibc-obsolete"
RPROVIDES_glibc-obsolete += "glibc-obsolete"

#PROVIDES by glibc-docs  
PROVIDES += "glibc-docs "
RPROVIDES_glibc-docs  += "glibc-docs "

#PROVIDES by glibc-info 
PROVIDES += "glibc-info"
RPROVIDES_glibc-info += "glibc-info"

#PROVIDES by glibc-devel-utils 
PROVIDES += "glibc-devel-utils"
RPROVIDES_glibc-devel-utils += "glibc-devel-utils"
RPROVIDES_glibc-devel-utils += "glibc-dev"

#PROVIDES by nscd 
PROVIDES += "nscd"
RPROVIDES_nscd += "nscd"
# the PROVIDES rules is ignore "glibc:/usr/sbin/nscd  "
PROVIDES += "glibc:/usr/sbin/nscd"
RPROVIDES_nscd += "glibc:/usr/sbin/nscd"

#PROVIDES by glibc-i18ndata 
PROVIDES += "glibc-i18ndata"
RPROVIDES_glibc-i18ndata += "glibc-i18ndata"

#PROVIDES by glibc-html 
PROVIDES += "glibc-html"
RPROVIDES_glibc-html += "glibc-html"

#PROVIDES by glibc-profile 
PROVIDES += "glibc-profile"
RPROVIDES_glibc-profile += "glibc-profile"

RDEPENDS = ""
#RDEPENDS of glibc-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "eglibc"

#RDEPENDS of glibc-locale (${PN}-locale)
RDEPENDS_${PN}-locale += "/usr/bin/cat"
RDEPENDS_${PN}-locale += "eglibc"

#RDEPENDS of glibc-devel-static (${PN}-devel-static)
RDEPENDS_${PN}-devel-static += "glibc-dev"

#RDEPENDS of glibc-extra (${PN}-extra)
RDEPENDS_${PN}-extra += "eglibc"

#RDEPENDS of glibc-profile (${PN}-profile)
RDEPENDS_${PN}-profile += "eglibc"

#RDEPENDS of glibc-obsolete (${PN}-obsolete)
RDEPENDS_${PN}-obsolete += "eglibc"

#RDEPENDS of glibc-devel-utils (${PN}-devel-utils)
RDEPENDS_${PN}-devel-utils += "eglibc"

#RDEPENDS of nscd (nscd)
RDEPENDS_nscd += "eglibc"

#RDEPENDS of glibc (${PN})
RDEPENDS_${PN} += "filesystem"


DEPENDS = ""
#DEPENDS of glibc 
DEPENDS += "xz"
DEPENDS += "gcc-cross"
DEPENDS += "fdupes-native"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "makeinfo"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -n glibc-2.18 -q 
 cp ${S}/packaging/glibc.manifest .
 
 
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
 
 if [ -x /bin/uname.bin ]; then
 	/bin/uname.bin -a
 else
 	uname -a
 fi
 uptime || :
 ulimit -a
 nice
 # We do not want configure to figure out the system its building one
 # to support a common ground and thus set build and host to the
 # target_cpu.
 # Don't use as-needed, it breaks glibc assumptions
 # Before enabling it, run the testsuite and verify that it
 # passes completely
 export LD_AS_NEEDED=0
 # Adjust glibc version.h
 echo "#define CONFHOST \"x86_64-tizen-linux\"" >> version.h
 echo "#define GITID \"eefa3be8e4c2\"" >> version.h
 #
 # Default CFLAGS and Compiler
 #
 BuildFlags=$(echo -O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables | sed -e "s/-Wp,-D_FORTIFY_SOURCE=2//g" | sed -e "s/-ffast-math//" | sed -e "s/atom/i686/g" | sed -e "s/-mthumb//" |   sed -e "s/-fexceptions//" )
 BuildFlags="$BuildFlags -O2 -g -U_FORTIFY_SOURCE"
 BuildFlags="$(echo $BuildFlags | sed -e 's#-fstack-protector##' -e 's#-ffortify=[0-9]*##')"
 BuildCC="${HOST_SYS}-gcc"
 BuildCCplus="${HOST_SYS}-g++"
 add_ons=",libidn"
 
 
 BuildFlags="$BuildFlags -g"
 
 configure_and_build_glibc() {
 	local dirname="$1"; shift
 	local cflags="$1"; shift
 	local addons="$1"; shift
 	mkdir "cc-$dirname"
 	cd "cc-$dirname"
 	conf_cflags="$cflags"
 
 	profile="--disable-profile"
         if [ "$dirname" = "base" ] ; then
 	    profile="--enable-profile"
 	fi
 	CFLAGS="$conf_cflags" BUILD_CFLAGS="$conf_cflags" \
         CC="$BuildCC" CXX="$BuildCCplus"  ../configure \
 		--prefix=/usr \
 		--libexecdir=/usr/libexec --infodir=/usr/share/info \
 		--enable-add-ons=nptl$addons \
 	        $profile \
 		"$@" \
 		--enable-stackguard-randomization \
 		--build=x86_64-tizen-linux --host=x86_64-tizen-linux \
 		--enable-multi-arch \
 		--enable-kernel=2.6.16 \
 		--enable-bind-now  --enable-obsolete-rpc
 	# explicitly set CFLAGS to use the full CFLAGS (not the reduced one for configure)
 	make -j16 #CFLAGS="$cflags" BUILD_CFLAGS="$cflags"
 	cd ..
 }
 
 	#
 	# Build base glibc
 	#
 	configure_and_build_glibc base "$BuildFlags" "$add_ons"
 
 #
 # Build html documentation
 #
 make -C cc-base html
 
 #
 # Build glibc_post_upgrade binary
 #
 $BuildCC -static -O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -Os $RPM_SOURCE_DIR/glibc_post_upgrade.c -o glibc_post_upgrade \
      -Lcc-base -Bcc-base/csu \
     '-DREMOVE_TLS_DIRS' '-DREMOVE_PPC_OPTIMIZE_POWER5' \
     '-DLIBDIR="/lib"' '-DGCONV_MODULES_DIR="/usr/lib/gconv"'
 
 
 #######################################################################
 ###
 ### CHECK
 ###
 #######################################################################
 
 exit 0
 # The testsuite will fail if asneeded is used
 export LD_AS_NEEDED=0
 # This has to pass on all platforms!
 # Exceptions:
 # None!
 make -j16 -C cc-base check-abi
 
 #######################################################################
 ###
 ### INSTALL
 ###
 #######################################################################
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 # We don't want to strip the .symtab from our libraries in find-debuginfo.sh,
 # certainly not from libpthread.so.* because it is used by libthread_db to find
 # some non-exported symbols in order to detect if threading support
 # should be enabled.  These symbols are _not_ exported, and we can't easily
 # export them retroactively without changing the ABI.  So we have to
 # continue to "export" them via .symtab, instead of .dynsym :-(
 # But we also want to keep .symtab and .strtab of other libraries since some
 # debugging tools currently require these sections directly inside the main
 # files - specifically valgrind and PurifyPlus.
 export STRIP_KEEP_SYMTAB=*.so*
 
 # Make sure we will create the gconv-modules.cache
 mkdir -p ${D}/usr/lib/gconv
 touch ${D}/usr/lib/gconv/gconv-modules.cache
 
 # Install base glibc
 make -j16 install_root=${D} install -C cc-base
 
 install_optimized_variant() {
 	local dirname="$1"; shift
 	local subdir="$1"; shift
 	local subdir_up="$1"; shift
 
 cd "cc-$dirname"
 destdir=$RPM_BUILD_ROOT/lib/$subdir
 mkdir -p $destdir
 # Don't run a complete make install, we know which libraries
 # we want
 for lib in libc math/libm nptl/libpthread rt/librt nptl_db/libthread_db
 do
   libbase=${lib#*/}
   libbaseso=$(basename $RPM_BUILD_ROOT/lib/${libbase}-*.so)
   # Only install if different from base lib
   if cmp -s ${lib}.so ../cc-base/${lib}.so; then
     ln -sf $subdir_up/$libbaseso $destdir/$libbaseso
   else
     cp -a ${lib}.so $destdir/$libbaseso
   fi
   # Emulate ldconfig
   ln -sf $libbaseso $destdir/$(basename $RPM_BUILD_ROOT/lib/${libbase}.so.*)
 done
 cd ..
 }
 
 
 # Install locales
 	# XXX Do not install locales in parallel!
 	cd cc-base
 	# localedef creates hardlinks to other locales if possible
 	# this will not work if we generate them in parallel.
 	# thus we need to run fdupes on  /usr/lib/locale/
 	# Still, on my system this is a speed advantage:
 	# non-parallel build for install-locales: 9:34mins
 	# parallel build with fdupes: 7:08mins
 	make -j16 install_root=${D} localedata/install-locales
 	
  _target=""; 
  _symlinks=0; 
   
  fdupes -q -n -r ${D}/usr/lib/locale | 
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
 	cd ..
 # Create file list for glibc-locale package
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} libc
 
 # Prepare obsolete/, used only on some architectures:
 export RPM_BUILD_ROOT
 
 # NPTL <bits/stdio-lock.h> is not usable outside of glibc, so include
 # the generic one (RH#162634)
 cp -av bits/stdio-lock.h ${D}/usr/include/bits/stdio-lock.h
 
 
 # Miscelanna:
 
 install -m 0700 glibc_post_upgrade ${D}/usr/sbin
 
 install -m 644 ${S}/packaging/bindresvport.blacklist ${D}/etc
 install -m 644 ${S}/packaging/nsswitch.conf ${D}/etc
 install -m 644 posix/gai.conf ${D}/etc
 
 mkdir -p ${D}/etc/default
 install -m 644 nis/nss ${D}/etc/default/
 
 mkdir -p ${D}/usr/include/resolv
 install -m 0644 resolv/mapv4v6addr.h ${D}/usr/include/resolv/
 install -m 0644 resolv/mapv4v6hostent.h ${D}/usr/include/resolv/
 
 mkdir -p ${D}/usr/share/doc/glibc
 cp -p cc-base/manual/libc/*.html ${D}/usr/share/doc/glibc
 
 
 # nscd tools:
 
 cp nscd/nscd.conf ${D}/etc
 mkdir -p ${D}/etc/init.d
 ln -sf /sbin/service ${D}/usr/sbin/rcnscd
 mkdir -p ${D}/var/run/nscd
 touch ${D}/var/run/nscd/{passwd,group,hosts}
 touch ${D}/var/run/nscd/{socket,nscd.pid}
 
 #
 # Create ld.so.conf
 #
 cat > ${D}/etc/ld.so.conf <<EOF
 /usr/local/lib64
 /usr/local/lib
 include /etc/ld.so.conf.d/*.conf
 # /lib64, /lib, /usr/lib64 and /usr/lib gets added
 # automatically by ldconfig after parsing this file.
 # So, they do not need to be listed.
 EOF
 # Add ldconfig cache directory for directory ownership
 mkdir -p ${D}/var/cache/ldconfig
 # Empty the ld.so.cache:
 rm -f ${D}/etc/ld.so.cache
 touch ${D}/etc/ld.so.cache
 
 # Don't look at ldd! We don't wish a /bin/sh requires
 chmod 644 ${D}/usr/bin/ldd
 
 # Remove timezone data, now coming in standalone package:
 for i in sbin/sln usr/bin/tzselect usr/sbin/zic usr/sbin/zdump etc/localtime; do
 	rm -f ${D}/$i
 done
 rm -rf ${D}/usr/share/zoneinfo
 
 mkdir -p ${D}/usr/lib/tmpfiles.d/
 install -m 644 ${S}/packaging/nscd.conf ${D}/usr/lib/tmpfiles.d/
 mkdir -p ${D}/usr/lib/systemd/system
 install -m 644 ${S}/packaging/nscd.service ${D}/usr/lib/systemd/system
 
 
 # Move getconf to /usr/libexec/getconf/ to avoid cross device link
 mv ${D}/usr/bin/getconf ${D}/usr/libexec/getconf/getconf
 ln -s /usr/libexec/getconf/getconf ${D}/usr/bin/getconf
 
 #######################################################################
 ###
 ### ...
 ###
 #######################################################################
 
 
}

PACKAGES = ""
PACKAGES += "glibc-devel"
PACKAGES += "glibc-locale"
PACKAGES += "glibc-devel-static"
PACKAGES += "glibc-extra"
PACKAGES += "glibc"
PACKAGES += "glibc-docs"
PACKAGES += "glibc-info"
PACKAGES += "glibc-devel-utils"
PACKAGES += "nscd"
PACKAGES += "glibc-i18ndata"
PACKAGES += "glibc-html"
PACKAGES += "glibc-profile"

glibc-devel_files = ""
glibc-devel_files += "glibc.manifest"
glibc-devel_files += "LGPL-2.0+ COPYING COPYING.LIB"
glibc-devel_files += "NEWS README BUGS CONFORMANCE"
glibc-devel_files += "/usr/bin/rpcgen"
glibc-devel_files += "/usr/include/*"
glibc-devel_files += "/usr/lib/*.o"
glibc-devel_files += "/usr/lib/*.so"
glibc-devel_files += "/usr/lib/libbsd-compat.a"
glibc-devel_files += "/usr/lib/libc_nonshared.a"
glibc-devel_files += "/usr/lib/libg.a"
glibc-devel_files += "/usr/lib/libieee.a"
glibc-devel_files += "/usr/lib/libmcheck.a"
glibc-devel_files += "/usr/lib/libpthread_nonshared.a"
glibc-devel_files += "/usr/lib/librpcsvc.a"

glibc-locale_files = ""
glibc-locale_files += "glibc.manifest"
glibc-locale_files += "/usr/share/locale/locale.alias"
glibc-locale_files += "/usr/lib/locale/*"
glibc-locale_files += "/usr/lib/gconv"

glibc-devel-static_files = ""
glibc-devel-static_files += "glibc.manifest"
glibc-devel-static_files += "/usr/lib/libBrokenLocale.a"
glibc-devel-static_files += "/usr/lib/libanl.a"
glibc-devel-static_files += "/usr/lib/libc.a"
glibc-devel-static_files += "/usr/lib/libcrypt.a"
glibc-devel-static_files += "/usr/lib/libdl.a"
glibc-devel-static_files += "/usr/lib/libm.a"
glibc-devel-static_files += "/usr/lib/libnsl.a"
glibc-devel-static_files += "/usr/lib/libpthread.a"
glibc-devel-static_files += "/usr/lib/libresolv.a"
glibc-devel-static_files += "/usr/lib/librt.a"
glibc-devel-static_files += "/usr/lib/libutil.a"

glibc-extra_files = ""
glibc-extra_files += "glibc.manifest"
glibc-extra_files += "/usr/bin/makedb"
glibc-extra_files += "/var/lib/misc/Makefile"

glibc_files = ""
glibc_files += "glibc.manifest"
glibc_files += "LGPL-2.0+ LICENSES"
glibc_files += "/etc/bindresvport.blacklist"
glibc_files += "/etc/ld.so.conf"
glibc_files += "/etc/rpc"
glibc_files += "/etc/default/nss"
glibc_files += "/lib/ld-2.18.so"
glibc_files += "/lib/ld-linux-x86-64.so.2"
glibc_files += "/lib/libanl-2.18.so"
glibc_files += "/lib/libanl.so.1"
glibc_files += "/lib/libc-2.18.so"
glibc_files += "/lib/libc.so.6*"
glibc_files += "/lib/libcidn-2.18.so"
glibc_files += "/lib/libcidn.so.1"
glibc_files += "/lib/libcrypt-2.18.so"
glibc_files += "/lib/libcrypt.so.1"
glibc_files += "/lib/libdl-2.18.so"
glibc_files += "/lib/libdl.so.2*"
glibc_files += "/lib/libm-2.18.so"
glibc_files += "/lib/libm.so.6*"
glibc_files += "/lib/libnsl-2.18.so"
glibc_files += "/lib/libnsl.so.1"
glibc_files += "/lib/libnss_compat-2.18.so"
glibc_files += "/lib/libnss_compat.so.2"
glibc_files += "/lib/libnss_db-2.18.so"
glibc_files += "/lib/libnss_db.so.2"
glibc_files += "/lib/libnss_dns-2.18.so"
glibc_files += "/lib/libnss_dns.so.2"
glibc_files += "/lib/libnss_files-2.18.so"
glibc_files += "/lib/libnss_files.so.2"
glibc_files += "/lib/libnss_hesiod-2.18.so"
glibc_files += "/lib/libnss_hesiod.so.2"
glibc_files += "/lib/libnss_nis-2.18.so"
glibc_files += "/lib/libnss_nis.so.2"
glibc_files += "/lib/libnss_nisplus-2.18.so"
glibc_files += "/lib/libnss_nisplus.so.2"
glibc_files += "/lib/libpthread-2.18.so"
glibc_files += "/lib/libpthread.so.0"
glibc_files += "/lib/libresolv-2.18.so"
glibc_files += "/lib/libresolv.so.2"
glibc_files += "/lib/librt-2.18.so"
glibc_files += "/lib/librt.so.1"
glibc_files += "/lib/libutil-2.18.so"
glibc_files += "/lib/libutil.so.1"
#Remove rpm attribut "%attr(0700,root,root)"
glibc_files += "/var/cache/ldconfig"
glibc_files += "/sbin/ldconfig"
glibc_files += "/usr/bin/gencat"
glibc_files += "/usr/bin/getconf"
glibc_files += "/usr/bin/getent"
glibc_files += "/usr/bin/iconv"
glibc_files += "/usr/bin/locale"
glibc_files += "/usr/bin/localedef"
#Remove rpm attribut "%attr(0755,root,root)"
glibc_files += "/usr/libexec/getconf"
glibc_files += "/usr/libexec/getconf/*"
glibc_files += "/usr/sbin/glibc_post_upgrade"
glibc_files += "/usr/sbin/iconvconfig"

glibc-docs_files = ""
glibc-docs_files += "/usr/share/info"
glibc-docs_files += "/usr/share/man"

glibc-info_files = ""
glibc-info_files += "glibc.manifest"
glibc-info_files += "/usr/share/info/libc.info.gz"
glibc-info_files += "/usr/share/info/libc.info-?.gz"
glibc-info_files += "/usr/share/info/libc.info-??.gz"

glibc-devel-utils_files = ""
glibc-devel-utils_files += "glibc.manifest"
glibc-devel-utils_files += "/lib/libmemusage.so"
glibc-devel-utils_files += "/lib/libpcprofile.so"
glibc-devel-utils_files += "/lib/libBrokenLocale-2.18.so"
glibc-devel-utils_files += "/lib/libBrokenLocale.so.1"
glibc-devel-utils_files += "/usr/lib/libBrokenLocale.so"
glibc-devel-utils_files += "/lib/libSegFault.so"
glibc-devel-utils_files += "/lib/libthread_db-1.0.so"
glibc-devel-utils_files += "/lib/libthread_db.so.1"
glibc-devel-utils_files += "/usr/lib/libthread_db.so"
glibc-devel-utils_files += "/usr/lib/audit"
glibc-devel-utils_files += "/usr/lib/audit/sotruss-lib.so"
glibc-devel-utils_files += "/usr/bin/mtrace"
glibc-devel-utils_files += "/usr/bin/pcprofiledump"
glibc-devel-utils_files += "/usr/bin/sotruss"
glibc-devel-utils_files += "/usr/bin/xtrace"
glibc-devel-utils_files += "/usr/bin/pldd"
glibc-devel-utils_files += "/usr/bin/catchsegv"
glibc-devel-utils_files += "/usr/bin/sprof"

nscd_files = ""
nscd_files += "glibc.manifest"
nscd_files += "/etc/nscd.conf"
nscd_files += "/usr/sbin/nscd"
nscd_files += "/usr/sbin/rcnscd"
nscd_files += "/usr/lib/systemd/system/nscd.service"
nscd_files += "/usr/lib/tmpfiles.d"
nscd_files += "/usr/lib/tmpfiles.d/nscd.conf"
#Remove rpm attribut "%attr(0755,root,root)"
nscd_files += "%ghost /var/run/nscd"

glibc-i18ndata_files = ""
glibc-i18ndata_files += "glibc.manifest"
glibc-i18ndata_files += "/usr/share/i18n"

glibc-html_files = ""
glibc-html_files += "glibc.manifest"
glibc-html_files += "/usr/share/doc/glibc"

glibc-profile_files = ""
glibc-profile_files += "glibc.manifest"
glibc-profile_files += "/usr/lib/libc_p.a"
glibc-profile_files += "/usr/lib/libBrokenLocale_p.a"
glibc-profile_files += "/usr/lib/libanl_p.a"
glibc-profile_files += "/usr/lib/libm_p.a"
glibc-profile_files += "/usr/lib/libcrypt_p.a"
glibc-profile_files += "/usr/lib/libpthread_p.a"
glibc-profile_files += "/usr/lib/libresolv_p.a"
glibc-profile_files += "/usr/lib/libnsl_p.a"
glibc-profile_files += "/usr/lib/librt_p.a"
glibc-profile_files += "/usr/lib/librpcsvc_p.a"
glibc-profile_files += "/usr/lib/libutil_p.a"
glibc-profile_files += "/usr/lib/libdl_p.a"

FILES_${PN}-devel = "${glibc-devel_files}"
FILES_${PN}-locale = "${glibc-locale_files}"
FILES_${PN}-devel-static = "${glibc-devel-static_files}"
FILES_${PN}-extra = "${glibc-extra_files}"
FILES_${PN} = "${glibc_files}"
FILES_${PN}-docs = "${glibc-docs_files}"
FILES_${PN}-info = "${glibc-info_files}"
FILES_${PN}-devel-utils = "${glibc-devel-utils_files}"
FILES_nscd = "${nscd_files}"
FILES_${PN}-i18ndata = "${glibc-i18ndata_files}"
FILES_${PN}-html = "${glibc-html_files}"
FILES_${PN}-profile = "${glibc-profile_files}"

PKG_glibc-devel= "glibc-devel"
PKG_glibc-locale= "glibc-locale"
PKG_glibc-devel-static= "glibc-devel-static"
PKG_glibc-extra= "glibc-extra"
PKG_glibc= "glibc"
PKG_glibc-docs= "glibc-docs"
PKG_glibc-info= "glibc-info"
PKG_glibc-devel-utils= "glibc-devel-utils"
PKG_nscd= "nscd"
PKG_glibc-i18ndata= "glibc-i18ndata"
PKG_glibc-html= "glibc-html"
PKG_glibc-profile= "glibc-profile"

require glibc-extraconf.inc
