DESCRIPTION = "The Low Level Virtual Machine"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Development/Toolchain"
LICENSE = "NCSA"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libllvm 
PROVIDES += "libllvm"
RPROVIDES_libllvm += "libllvm"

#PROVIDES by llvm 
PROVIDES += "llvm"
RPROVIDES_llvm += "llvm"

#PROVIDES by clang-analyzer 
PROVIDES += "clang-analyzer"
RPROVIDES_clang-analyzer += "clang-analyzer"

#PROVIDES by clang-doc 
PROVIDES += "clang-doc"
RPROVIDES_clang-doc += "clang-doc"

#PROVIDES by llvm-devel 
PROVIDES += "llvm-devel"
RPROVIDES_llvm-devel += "llvm-devel"
RPROVIDES_llvm-devel += "llvm-dev"
# the PROVIDES rules is ignore "llvm-static = 3.1-0"
PROVIDES += "llvm-static"
RPROVIDES_llvm-devel += "llvm-static"

#PROVIDES by clang-devel 
PROVIDES += "clang-devel"
RPROVIDES_clang-devel += "clang-devel"
RPROVIDES_clang-devel += "clang-dev"

#PROVIDES by clang 
PROVIDES += "clang"
RPROVIDES_clang += "clang"

RDEPENDS = ""
#RDEPENDS of llvm (${PN})
RDEPENDS_${PN} += "libllvm"

#RDEPENDS of clang-analyzer (clang-analyzer)
RDEPENDS_clang-analyzer += "python"
RDEPENDS_clang-analyzer += "clang"

#RDEPENDS of clang-doc (clang-doc)
RDEPENDS_clang-doc += "llvm"

#RDEPENDS of llvm-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "llvm"
RDEPENDS_${PN}-devel += "libffi-dev"
RDEPENDS_${PN}-devel += "update-alternatives"
RDEPENDS_${PN}-devel += "libstdc++-dev"

#RDEPENDS of clang-devel (clang-devel)
RDEPENDS_clang-devel += "clang"

#RDEPENDS of clang (clang)
RDEPENDS_clang += "gcc"
RDEPENDS_clang += "llvm"
RDEPENDS_clang += "libstdc++-dev"


DEPENDS = ""
#DEPENDS of llvm 
DEPENDS += "flex"
DEPENDS += "gcc-cross"
DEPENDS += "chrpath"
DEPENDS += "zip"
DEPENDS += "python-devel"
DEPENDS += "bison-native"
DEPENDS += "libffi"
DEPENDS += "libtool-cross"
DEPENDS += "groff"
DEPENDS += "binutils"

do_patch() {
 #extracte source 1 
 pushd ${S}
 unp ${S}/packaging/clang-3.1.src.tar.gz 
 popd 
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n llvm-3.1.src -a1
 cp ${S}/packaging/llvm.manifest .
 rm -r -f tools/clang
 mv clang-3.1.src tools/clang
 
 
 
 
 # fix ld search path
 sed -i 's|/lib /usr/lib $lt_ld_extra|/usr/lib $lt_ld_extra|' \
     ./configure
 
 
 
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
 
 # Build without -ftree-pre as a workaround for clang segfaulting on x86_64.
 # https://bugzilla.redhat.com/show_bug.cgi?id=791365
 
 # Disabling assertions now, rec. by pure and needed for OpenGTL
 
   CFLAGS="${CFLAGS:--O2 -fno-tree-pre -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CFLAGS ; 
   CXXFLAGS="${CXXFLAGS:--O2 -fno-tree-pre -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
   FFLAGS="${FFLAGS:--O2 -fno-tree-pre -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -I%_fmoddir}" ; export FFLAGS ; 
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
   --prefix=/usr \
   --libdir=/usr/lib/llvm \
   --with-binutils-include=/usr/include \
   --enable-targets=host \
   --disable-assertions \
   --enable-debug-runtime \
   --enable-jit \
   --enable-libffi \
   --enable-shared
 
 # FIXME file this
 # configure does not properly specify libdir
 sed -i 's|(PROJ_prefix)/lib|(PROJ_prefix)/lib/llvm|g' Makefile.config
 
 # FIXME upstream need to fix this
 # llvm-config.cpp hardcodes lib in it
 sed -i 's|ActiveLibDir = ActivePrefix + "/lib"|ActiveLibDir = ActivePrefix + "/lib/llvm"|g' tools/llvm-config/llvm-config.cpp
 
 make -j16 REQUIRES_RTTI=1 VERBOSE=1  OPTIMIZE_OPTION="-O2 -fno-tree-pre -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables"
 
 exit 0
 # the Koji build server does not seem to have enough RAM
 # for the default 16 threads
 
 make check LIT_ARGS="-v -j4" \
  
 
 # FIXME:
 # unexpected failures on all platforms with GCC 4.7.0.
 # capture logs
 make -C tools/clang/test TESTARGS="-v -j4" \
      | tee clang-testlog-x86_64.txt
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 make install DESTDIR=${D} \
      PROJ_docsdir=/moredocs
 
 # multilib fixes
 mv ${D}/usr/bin/llvm-config{,-64}
 
 pushd ${D}/usr/include/llvm/Config
 mv config.h config-64.h
 cp -p ${S}/packaging/llvm-Config-config.h config.h
 mv llvm-config.h llvm-config-64.h
 cp -p ${S}/packaging/llvm-Config-llvm-config.h llvm-config.h
 popd
 
 # Create ld.so.conf.d entry
 mkdir -p ${D}/etc/ld.so.conf.d
 cat >> ${D}/etc/ld.so.conf.d/llvm-x86_64.conf << EOF
 /usr/lib/llvm
 EOF
 
 # Static analyzer not installed by default:
 # http://clang-analyzer.llvm.org/installation#OtherPlatforms
 mkdir -p ${D}/usr/lib/clang-analyzer
 # create launchers
 for f in scan-{build,view}; do
   ln -s /usr/lib/clang-analyzer/$f/$f ${D}/usr/bin/$f
 done
 
 (cd tools/clang/tools && cp -pr scan-{build,view} \
  ${D}/usr/lib/clang-analyzer/)
 
 # Move documentation back to build directory
 # 
 mv ${D}/moredocs .
 rm -f moredocs/*.tar.gz
 rm -f moredocs/ocamldoc/html/*.tar.gz
 
 # and separate the apidoc
 
 # And prepare Clang documentation
 #
 mkdir clang-docs
 for f in LICENSE.TXT NOTES.txt README.txt; do # TODO.txt; do
   ln tools/clang/$f clang-docs/
 done
 rm -rf tools/clang/docs/{doxygen*,Makefile*,*.graffle,tools}
 
 
 file ${D}//usr/bin/* | awk -F: '$2~/ELF/{print $1}' | xargs -r chrpath -d
 file ${D}//usr/lib/llvm/*.so | awk -F: '$2~/ELF/{print $1}' | xargs -r chrpath -d
 #chrpath -d %{buildroot}/%{_libexecdir}/clang-cc
 
 # Get rid of erroneously installed example files.
 rm ${D}/usr/lib/llvm/*LLVMHello.*
 
 # FIXME file this bug
 sed -i 's,ABS_RUN_DIR/lib",ABS_RUN_DIR/lib/llvm",' \
   ${D}/usr/bin/llvm-config-64
 
 chmod -x ${D}/usr/lib/llvm/*.a
 
 # remove documentation makefiles:
 # they require the build directory to work
 find examples -name 'Makefile' | xargs -0r rm -f
 
 
 cd $RPM_BUILD_DIR
 
 
   rm -rf ${D}/usr/share/info 
   rm -rf ${D}/usr/share/doc/packages 
   rm -rf ${D}/usr/share/doc/llvm 
   rm -rf ${D}/usr/share/doc/llvm-3.1 
   rm -rf ${D}/usr/share/gtk-doc 
   rm -rf ${D}/usr/share/doc 
   rm -rf ${D}/usr/share/man 
   find ${D} -regex ".*/man/man./.*.[0-9]" | xargs rm -f -- 
   find ${D} -regex ".*/man/../man./.*.[0-9]" | xargs rm -f -- 
   find ${D} -regex ".*/man/man./.*.[0-9]pm" | xargs rm -f --
 
 
 
}

PACKAGES = ""
PACKAGES += "libllvm"
PACKAGES += "llvm"
PACKAGES += "clang-analyzer"
PACKAGES += "llvm-devel"
PACKAGES += "clang-devel"
PACKAGES += "clang"

libllvm_files = ""
libllvm_files += "llvm.manifest"
libllvm_files += "/etc/ld.so.conf.d/llvm-x86_64.conf"
libllvm_files += "/usr/lib/llvm"
libllvm_files += "/usr/lib/llvm/*.so"

llvm_files = ""
llvm_files += "llvm.manifest"
llvm_files += "/usr/bin/bugpoint"
llvm_files += "/usr/bin/llc"
llvm_files += "/usr/bin/lli"
llvm_files += "/usr/bin/llvm*"
llvm_files += "/usr/bin/macho-dump"
llvm_files += "/usr/bin/opt"

clang-analyzer_files = ""
clang-analyzer_files += "llvm.manifest"
clang-analyzer_files += "/usr/bin/scan-build"
clang-analyzer_files += "/usr/bin/scan-view"
clang-analyzer_files += "/usr/lib/clang-analyzer"

llvm-devel_files = ""
llvm-devel_files += "llvm.manifest"
llvm-devel_files += "/usr/bin/llvm-config-64"
llvm-devel_files += "/usr/include/llvm"
llvm-devel_files += "/usr/include/llvm-c"
llvm-devel_files += "/usr/lib/llvm/*.a"

clang-devel_files = ""
clang-devel_files += "llvm.manifest"
clang-devel_files += "/usr/include/clang"
clang-devel_files += "/usr/include/clang-c"

clang_files = ""
clang_files += "llvm.manifest"
clang_files += "/usr/bin/clang*"
clang_files += "/usr/bin/c-index-test"
clang_files += "/usr/lib/llvm/libclang.so"
clang_files += "/usr/lib/clang"

FILES_lib${PN} = "${libllvm_files}"
FILES_${PN} = "${llvm_files}"
FILES_clang-analyzer = "${clang-analyzer_files}"
FILES_${PN}-devel = "${llvm-devel_files}"
FILES_clang-devel = "${clang-devel_files}"
FILES_clang = "${clang_files}"

PKG_libllvm= "libllvm"
PKG_llvm= "llvm"
PKG_clang-analyzer= "clang-analyzer"
PKG_llvm-devel= "llvm-devel"
PKG_clang-devel= "clang-devel"
PKG_clang= "clang"

require llvm-extraconf.inc
