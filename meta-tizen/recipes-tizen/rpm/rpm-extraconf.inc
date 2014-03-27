do_compile_prepend() {
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables" ; export CFLAGS ;
 CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ;
 FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -I%_fmoddir}" ; export FFLAGS ;
 LD_AS_NEEDED=1; export LD_AS_NEEDED ;

 ### BUILD BEGIN ###
 CPPFLAGS="$CPPFLAGS `pkg-config --cflags nss`"
 export CPPFLAGS
 export CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -ffunction-sections"
 export LDFLAGS="${LDFLAGS} -Wl,-Bsymbolic-functions -ffunction-sections"

 export CCFLAGS+=" -fPIC "
 export CXXFLAGS+=" -fPIC "
 export CFLAGS+=" -fPIC "

 cd db3
 ./configure --build=${TARGET_SYS} --host=x86_64-linux-gnu
 cd ..

 cp db3/configure  db3/configure.ac
}
do_install_append() {
 mkdir -p ${D}${prefix}/lib/rpm/bin
 ln -s ../debugedit ${D}${prefix}/lib/rpm/bin/debugedit
 ln -s ../rpmdeps ${D}${prefix}/lib/rpm/bin/rpmdeps-oecore
}

DEPENDS_native += "popt-native"
DEPENDS_native += "uthash-native"
DEPENDS_native += "smack-native"