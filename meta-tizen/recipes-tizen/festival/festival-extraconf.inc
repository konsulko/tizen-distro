do_prep_prepend() {
 pushd ${S}/../
 ln -s ${S} festival-2.1
 popd 
}

INSANE_SKIP_${PN} = "dev-deps"

do_compile() {
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 LD_AS_NEEDED=1; export LD_AS_NEEDED ;

# festival

 autotools_do_configure --prefix=${prefix} \
            --libdir=${prefix}/lib \
            --datadir=${prefix}/share/festival \
            --sysconfdir=${sysconfdir}

 cd ..
 export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(pwd)/speech_tools/lib
 export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(pwd)/festival-2.1/src/lib

 # speech tools
 cd speech_tools

 ./configure --prefix=${prefix} \
            --libdir=${prefix}/lib \
                --datadir=${prefix}/share/festival \
            --sysconfdir=${sysconfdir}

 make CC="i586-poky-linux-gcc -fPIC $RPM_OPT_FLAGS" CXX="i586-poky-linux-g++ $RPM_OPT_FLAGS -fPIC -Wno-non-template-friend -ffriend-injection -fno-strict-aliasing"
 cd ../festival-2.1
 make CC="i586-poky-linux-gcc -fPIC $RPM_OPT_FLAGS" CXX="i586-poky-linux-g++ $RPM_OPT_FLAGS -fPIC -Wno-non-template-friend -ffriend-injection -fno-strict-aliasing"
 make doc

}