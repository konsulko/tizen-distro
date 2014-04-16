SRC_URI += "file://pythondeps.sh \
            file://fix-python-rpm-conf.patch \
            file://rpmmodule.c.patch \
           "

BBCLASSEXTEND_append = " nativesdk "

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n rpm-4.11.0.1
 ### PREP BEGIN ###
 cp ${S}/packaging/rpm.manifest .
 rm -rf sqlite
 tar xjf ${S}/packaging/db-4.8.30.tar.bz2
 ln -s db-4.8.30 db
 chmod -R u+w db/*
 # will get linked from db3
 rm -f rpmdb/db.h
 patch -p0 < ${S}/packaging/db-4.8.30-integration.dif

 if [ -s /etc/rpm/tizen_macros ]; then
     cp -a /etc/rpm/tizen_macros ${S}/packaging/rpm-tizen_macros
 fi
 cp -a ${S}/packaging/rpm-tizen_macros tizen_macros
 rm -f m4/libtool.m4
 rm -f m4/lt*.m4
 ### PREP END ###


}

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
 CPPFLAGS="$CPPFLAGS `pkg-config --cflags nss` "
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

do_compile() {
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables" ; export CFLAGS ;
 CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ;
 FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -I%_fmoddir}" ; export FFLAGS ;
 LD_AS_NEEDED=1; export LD_AS_NEEDED ;

 ### BUILD BEGIN ###
 CPPFLAGS="$CPPFLAGS `pkg-config --cflags nss` "
 CPPFLAGS="$CPPFLAGS `pkg-config --cflags python`"
 export CPPFLAGS
 export CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -ffunction-sections"
 export LDFLAGS="${LDFLAGS} -Wl,-Bsymbolic-functions -ffunction-sections"

 BUILDTARGET="--build=x86_64-tizen-linux --host=x86_64-linux-gnu "

 autoreconf -i -f
 export CFLAGS+=" -DRPM_VENDOR_OE "
 ./configure \
     --sysconfdir=${sysconfdir} \
     --prefix=${prefix} \
     --mandir=${prefix}/share/man \
     --infodir=${prefix}/share/info \
     --libdir=${prefix}/lib \
     --sysconfdir=/${sysconfdir} \
     --localstatedir=/${localstatedir} \
     --disable-dependency-tracking \
     --with-lua \
     --with-acl \
     --with-cap \
     --enable-shared \
     --enable-python \
     --with-python-inc-dir=${STAGING_INCDIR}/python${PYTHON_BASEVERSION} \
     --with-python-lib-dir=${libdir}/python${PYTHON_BASEVERSION}/site-packages \
     --with-msm \
     $BUILDTARGET

 make -j16
 ### BUILD END ###

}

FILES_${PN}-dbg += "\
    ${libdir}/python2.7/site-packages/rpm/.debug/* \
    "





