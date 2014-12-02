DESCRIPTION = "A free speech synthesis and text-to-speech system"
HOMEPAGE = "http://www.cstr.ed.ac.uk/projects/festival/"
SECTION = "System/Libraries"
LICENSE = "MIT and GPL-2.0+ and TCL"
PV = "2.1"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit manifest autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by festival


#PROVIDES by festival-dev
PROVIDES += "festival-dev"


RDEPENDS = ""
#RDEPENDS of festival-dev (${PN}-dev)
RDEPENDS_${PN}-dev += "festival"


DEPENDS = ""
#DEPENDS of festival
DEPENDS += "ncurses"
inherit pkgconfig

do_prep() {
 cd ${S}
 #extracte source 1
 CURDIR=$(pwd)
 cd ${S}/../
 tar -zxf ${S}/packaging/speech_tools-2.1-release.tar.gz
 cd ${CURDIR}
 #extracte source 2
 CURDIR=$(pwd)
 cd ${S}/../
 tar -zxf ${S}/packaging/festlex_CMU.tar.gz
 cd ${CURDIR}
 #extracte source 3
 CURDIR=$(pwd)
 cd ${S}/../
 tar -zxf ${S}/packaging/festvox_kallpc16k.tar.gz
 cd ${CURDIR}
 #extracte source 4
 CURDIR=$(pwd)
 cd ${S}/../
 tar -zxf ${S}/packaging/festlex_POSLEX.tar.gz
 cd ${CURDIR}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -b 1 -b 2 -b 3 -b 4
 mv ../festival/lib/* lib/
 cat ${S}/packaging/festival-1.95-examples.patch | patch -s  -p1 --fuzz=2
 #patch0 -p1
 cat ${S}/packaging/festival-text2wave-manpage.patch | patch -s  -p1 --fuzz=2
 #patch1 -p1
 cat ${S}/packaging/festival-1.95-libdir.patch | patch -s  -p0 --fuzz=2
 #patch2
 cat ${S}/packaging/festival-1.95-audsp.patch | patch -s  -p0 --fuzz=2
 #patch3
 cat ${S}/packaging/festival-1.96-chroot.patch | patch -s  -p0 --fuzz=2
 #patch4
 cat ${S}/packaging/festival-no-LD_LIBRARY_PATH-extension.patch | patch -s  -p1 --fuzz=2
 #patch5 -p1
 cat ${S}/packaging/festival-safe-temp-file.patch | patch -s  -p1 --fuzz=2
 #patch6 -p1
 cat ${S}/packaging/festival-use-pacat.patch | patch -s  -p1 -b --suffix .use-pacat  --fuzz=2
 #patch7 -p1 -b .use-pacat 
 cd ../speech_tools
 cat ${S}/packaging/speech_tools-undefined-operation.patch | patch -s  -p1 --fuzz=2
 #patch101 -p1
 cat ${S}/packaging/speech_tools-1.2.95-config.patch | patch -s  -p0 --fuzz=2
 #patch102
 cat ${S}/packaging/speech_tools-no-LD_LIBRARY_PATH-extension.patch | patch -s  -p1 --fuzz=2
 #patch103 -p1
 cat ${S}/packaging/speech_tools-gcc47.patch | patch -s  -p1 --fuzz=2
 #patch104 -p1
 cat ${S}/packaging/festival-1.96-speechtools-shared-build.patch | patch -s  -p2 -b --suffix .shared-build --fuzz=2
 #patch200 -p2 -b .shared-build
 cat ${S}/packaging/festival-1.96-bettersonamehack.patch | patch -s  -p2 -b --suffix .bettersoname --fuzz=2
 #patch201 -p2 -b .bettersoname
 cat ${S}/packaging/festival-1.96-main-speech_tools-shared-build.patch | patch -s  -p2 -b --suffix .shared --fuzz=2
 #patch205 -p2 -b .shared
 cd ../festival-2.1
 cat ${S}/packaging/festival-1.96-main-festival-shared-build.patch | patch -s  -p1 -b --suffix .shared --fuzz=2
 #patch206 -p1 -b .shared
 cd ../speech_tools
 cat ${S}/packaging/no-shared-data.patch | patch -s  -p1 -b --suffix .no-shared-data --fuzz=2
 #patch210 -p1 -b .no-shared-data
 cat ${S}/packaging/festival-1.96-speechtools-linklibswithotherlibs.patch | patch -s  -p1 -b --suffix .linklibswithotherlibs --fuzz=2
 #patch211 -p1 -b .linklibswithotherlibs
 
 
}
do_patch_append() {
    bb.build.exec_func('do_prep', d)
}

do_configure() {
}

do_compile() {
 cd ${S}
  LANG=C
  export LANG
  unset DISPLAY
  LD_AS_NEEDED=1; export LD_AS_NEEDED ;
  
  # festival
  
  autotools_do_configure
  
  cd ..
  export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(pwd)/speech_tools/lib
  export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(pwd)/festival-2.1/src/lib
  # speech tools
  cd speech_tools
  ./configure --host=${HOST_SYS} --prefix=${prefix}               --libdir=${prefix}/lib               --datadir=${prefix}/share/festival               --sysconfdir=${sysconfdir}
  
  oe_runmake CC="${CC} -fPIC $RPM_OPT_FLAGS" CXX="${CXX} $RPM_OPT_FLAGS -fPIC -Wno-non-template-friend -ffriend-injection -fno-strict-aliasing"
  cd ../festival-2.1
  oe_runmake CC="${CC} -fPIC $RPM_OPT_FLAGS" CXX="${CXX} $RPM_OPT_FLAGS -fPIC -Wno-non-template-friend -ffriend-injection -fno-strict-aliasing"
  oe_runmake doc
  
  
  
  
}
EXTRA_OECONF += " --prefix=${prefix} --libdir=${prefix}/lib --datadir=${prefix}/share/festival --sysconfdir=${sysconfdir}"

do_install() {
 export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D}
 mkdir -p ${D}
 
 cd ..
 export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(pwd)/speech_tools/lib
 export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(pwd)/festival-2.1/src/lib
 cd -
 #%make_install
 #make INSTALLED_BIN=%{buildroot}%{_bindir} make_installed_bin_shared
 cd ../speech_tools
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=${prefix}/bin \
   install  
   rm -f ${D}${infodir}/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 cd ../festival-2.1
 # install binarys
 install -D bin/text2wave ${D}${prefix}/bin/text2wave
 install -m 755 src/main/festival ${D}${prefix}/bin/
 install -m 755 src/main/festival_client ${D}${prefix}/bin/
 install -m 755 bin/festival_server* ${D}${prefix}/bin/
 install -m 755 examples/saytime ${D}${prefix}/bin/
 # install manpages
 install -D -m 644 doc/festival.1 ${D}${mandir}/man1/festival.1
 install -m 644 doc/festival_client.1 ${D}${mandir}/man1/
 install -m 644 doc/text2wave.1 ${D}${mandir}/man1/
 # install configs
 install -D lib/festival.scm ${D}${sysconfdir}/festival.scm
 # install dictionarys
 install -D lib/dicts/cmu/cmudict-0.4.out ${D}${prefix}/share/festival/dicts/cmu/cmudict-0.4.out
 install -m 644 lib/dicts/cmu/*.scm ${D}${prefix}/share/festival/dicts/cmu/
 install -m 644 lib/dicts/wsj.wp39.poslexR ${D}${prefix}/share/festival/dicts/
 install -m 644 lib/dicts/wsj.wp39.tri.ngrambin ${D}${prefix}/share/festival/dicts/
 # install voices
 mkdir -p ${D}${prefix}/share/festival/voices/english/kal_diphone/festvox
 mkdir -p ${D}${prefix}/share/festival/voices/english/kal_diphone/group
 cp lib/voices/english/kal_diphone/group/* ${D}${prefix}/share/festival/voices/english/kal_diphone/group/
 cp lib/voices/english/kal_diphone/festvox/*.scm ${D}${prefix}/share/festival/voices/english/kal_diphone/festvox
 # install data
 cp lib/*.scm ${D}${prefix}/share/festival/
 cp lib/*.ngrambin ${D}${prefix}/share/festival/
 cp lib/*.gram ${D}${prefix}/share/festival/
 cp lib/*.el ${D}${prefix}/share/festival/
 install -D lib/etc/unknown_Linux/audsp ${D}${prefix}/lib/festival/audsp
 # install libs
 install -D src/lib/libFestival.so  ${D}${prefix}/lib/libFestival.so
 # install includes
 mkdir -p ${D}${prefix}/include/
 install -m 644 src/include/*.h ${D}${prefix}/include/
 cd ../speech_tools
 # install includes
 mkdir -p ${D}${prefix}/include/instantiate
 mkdir -p ${D}${prefix}/include/ling_class
 mkdir -p ${D}${prefix}/include/rxp
 mkdir -p ${D}${prefix}/include/sigpr
 mkdir -p ${D}${prefix}/include/unix
 install -m 644 include/*h ${D}${prefix}/include
 install -m 644 include/instantiate/*h ${D}${prefix}/include/instantiate
 install -m 644 include/ling_class/*h ${D}${prefix}/include/ling_class
 install -m 644 include/rxp/*h ${D}${prefix}/include/rxp
 install -m 644 include/sigpr/*h ${D}${prefix}/include/sigpr
 install -m 644 include/unix/*h ${D}${prefix}/include/unix
 # make sure we have no static libs, install shared ones
 install -m 644 lib/lib*.so* ${D}${prefix}/lib
 rm -f ${D}${prefix}/lib/*.a
 
 # install init script
 # install -m 755 -D %{S:6} %{buildroot}/etc/init.d/%name
 # install -d %{buildroot}%_sbindir
 # ln -sf ../../etc/init.d/%name %{buildroot}/usr/sbin/rc%name
 # installl sysconfig file
 #install -m 644 -D %{S:5} %{buildroot}/var/adm/fillup-templates/sysconfig.%name
 
 
}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    ldconfig

}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    ldconfig

}

pkg_postrm_${PN}() {
    #!/bin/sh -e

    ldconfig

}

pkg_postrm_${PN}() {
    #!/bin/sh -e

    ldconfig

}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " festival "
PACKAGES += " festival-dev "

festival_files = ""
festival_files += "MIT COPYING"
festival_files += "README INSTALL examples/*.text examples/ex1.* examples/*.scm examples/*.dtd"
festival_files += "${sysconfdir}/festival.scm"
festival_files += "${prefix}/bin/festival"
festival_files += "${prefix}/bin/festival_client"
festival_files += "${prefix}/bin/festival_server"
festival_files += "${prefix}/bin/festival_server_control"
festival_files += "${prefix}/bin/text2wave"
festival_files += "${prefix}/bin/saytime"
festival_files += "${prefix}/lib/libe*.so.*"
festival_files += "${prefix}/lib/libFestival.so"
festival_files += "${prefix}/lib/festival"
festival_files += "${prefix}/share/festival"
festival_files += "${mandir}/man1/*"

festival-dev_files = ""
festival-dev_files += "${prefix}/include/*"
festival-dev_files += "${prefix}/lib/libe*.so"

FILES_${PN} = "${festival_files}"
FILES_${PN}-dev = "${festival-dev_files}"

PKG_festival= "festival"
PKG_festival-dev= "festival-dev"

require festival-extraconf.inc

