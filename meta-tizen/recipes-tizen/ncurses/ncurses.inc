DESCRIPTION = "New curses Libraries"
HOMEPAGE = "http://invisible-island.net/ncurses/ncurses.html"
SECTION = "Base/Libraries"
LICENSE = "MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by ncurses-utils 
PROVIDES += "ncurses-utils"
RPROVIDES_ncurses-utils += "ncurses-utils"
# the PROVIDES rules is ignore "ncurses:/usr/bin/tput  "
PROVIDES += "ncurses:/usr/bin/tput"
RPROVIDES_ncurses-utils += "ncurses:/usr/bin/tput"

#PROVIDES by terminfo-base 
PROVIDES += "terminfo-base"
RPROVIDES_terminfo-base += "terminfo-base"
# the PROVIDES rules is ignore "ncurses:/usr/share/tabset  "
PROVIDES += "ncurses:/usr/share/tabset"
RPROVIDES_terminfo-base += "ncurses:/usr/share/tabset"

#PROVIDES by ncurses-devel 
PROVIDES += "ncurses-devel"
RPROVIDES_ncurses-devel += "ncurses-devel"
RPROVIDES_ncurses-devel += "ncurses-dev"
# the PROVIDES rules is ignore "ncurses:/usr/include/ncurses.h  "
PROVIDES += "ncurses:/usr/include/ncurses.h"
RPROVIDES_ncurses-devel += "ncurses:/usr/include/ncurses.h"

#PROVIDES by ncurses 
PROVIDES += "ncurses"
RPROVIDES_ncurses += "ncurses"

#PROVIDES by ncurses-docs  
PROVIDES += "ncurses-docs "
RPROVIDES_ncurses-docs  += "ncurses-docs "

#PROVIDES by libncurses 
PROVIDES += "libncurses"
RPROVIDES_libncurses += "libncurses"
# the PROVIDES rules is ignore "ncurses = 5.9"
PROVIDES += "ncurses"
RPROVIDES_libncurses += "ncurses"

#PROVIDES by libncurses6 
PROVIDES += "libncurses6"
RPROVIDES_libncurses6 += "libncurses6"
# the PROVIDES rules is ignore "ncurses = 6.0"
PROVIDES += "ncurses"
RPROVIDES_libncurses6 += "ncurses"

#PROVIDES by terminfo 
PROVIDES += "terminfo"
RPROVIDES_terminfo += "terminfo"

RDEPENDS = ""
#RDEPENDS of ncurses-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "ncurses"
RDEPENDS_${PN}-devel += "libncurses"
RDEPENDS_${PN}-devel += "libncurses6"

#RDEPENDS of libncurses (lib${PN})
RDEPENDS_lib${PN} += "terminfo-base"

#RDEPENDS of libncurses6 (lib${PN}6)
RDEPENDS_lib${PN}6 += "terminfo-base"


DEPENDS = ""
#DEPENDS of ncurses 
DEPENDS += "gcc-cross"
DEPENDS += "pkgconfig-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n ncurses-5.9
 cp ${S}/packaging/ncurses.manifest .
 rm -vf include/ncurses_dll.h
 rm -vf mkdirs.sh
 rm -vf tar-copy.sh
 rm -vf mk-dlls.sh
 
 
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
 
     cflags ()
     {
 	local flag=$1; shift
 	local var=$1; shift
 	test -n "${flag}" -a -n "${var}" || return
 	case "${!var}" in
 	*${flag}*) return
 	esac
 	set -o noclobber
 	case "$flag" in
 	-Wl,*)
 	    if echo 'int main () { return 0; }' | \
 	       ${CC:-gcc} -Werror $flag -o /dev/null -xc - > /dev/null 2>&1 ; then
 		eval $var=\${$var:+\$$var\ }$flag
 	    fi
 	    ;;
 	*)
 	    if ${CC:-gcc} -Werror $flag -S -o /dev/null -xc /dev/null > /dev/null 2>&1 ; then
 		eval $var=\${$var:+\$$var\ }$flag
 	    fi
 	    if ${CXX:-g++} -Werror $flag -S -o /dev/null -xc++ /dev/null > /dev/null 2>&1 ; then
 		eval $var=\${$var:+\$$var\ }$flag
 	    fi
 	esac
 	set +o noclobber
     }
 
     test ! -f /.buildenv || . /.buildenv
        OPATH=$PATH
       FALLBK="xterm,linux,vt100,vt102"
 	  CC=gcc
 	 CXX=g++
     CFLAGS="${RPM_OPT_FLAGS} -pipe -D_REENTRANT"
     if [[ "$BUILD_BASENAME" = debug-* ]] ; then
 	CFLAGS="${CFLAGS} -g -DTRACE"
     fi
     cflags -Wl,-O2                  LDFLAGS
     cflags -Wl,-Bsymbolic-functions LDFLAGS
     cflags -Wl,--hash-size=8599     LDFLAGS
     cflags -Wl,--as-needed          LDFLAGS
     CXXFLAGS=$CFLAGS
     test -n "$TERM" || TERM=linux
     GZIP="-9"
     export CC CFLAGS CXX CXXFLAGS GZIP TERM LDFLAGS
     #
     # Detect 64bit architecures and be sure that
     # we use an unsigned long for chtype to be
     # backward compatible with ncurses 5.4
     #
     echo 'int main () { return !(sizeof(void*) >= 8); }' | gcc -x c -o test64 -
     if ./test64 ; then
 	WITHCHTYPE="--with-chtype=long"
     else
 	WITHCHTYPE=""
 	CFLAGS="${CFLAGS} -D_LARGEFILE64_SOURCES -D_FILE_OFFSET_BITS=64"
     fi
     rm -f ./test64
     #
     # For security of some configure and install scripts
     #
     TMPDIR=$(mktemp -d /tmp/ncurses.XXXXXXXX) || exit 1
     trap 'rm -rf ${TMPDIR}' EXIT
     export TMPDIR
     #
     # No --enable-term-driver as this had crashed last time
     # in ncurses/tinfo/lib_setup.c due to the fact that
     # _nc_globals.term_driver was a NULL function pointer
     #
     # No --enable-tcap-names because we may have to recompile
     # programs or foreign programs won't work
     #
     # No --enable-safe-sprintf because this seems to
     # crash on some architectures
     #
     # No --enable-xmc-glitch because this seems to break yast2
     # on console/konsole (no magic cookie support on those?)
     #
     # No --with-termlib=tinfo because libncurses depend on
     # libtinfo (is linked with) and therefore there is no
     # advantage about splitting of a libtinfo (IMHO).
     #
     touch --reference=README config.sub config.guess
     
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
 	--without-ada		\
 	--without-debug		\
 	--without-profile	\
 	--without-manpage-tbl	\
 	--with-shared		\
 	--with-normal		\
 	--with-manpage-format=gzip \
 	--with-manpage-renames=${PWD}/man/man_db.renames \
 	--with-manpage-aliases	\
 	--with-ospeed=speed_t	\
 	--with-gpm		\
 	--with-dlsym		\
 	--with-termlib=tinfo	\
 	--with-ticlib=tic	\
 	--with-xterm-kbs=del	\
 	--disable-root-environ	\
 	--disable-termcap	\
 	--disable-overwrite	\
 	--disable-rpath		\
 	--disable-leaks		\
 	--disable-xmc-glitch	\
 	--enable-symlinks	\
 	--enable-big-core	\
 	--enable-const		\
 	--enable-hashmap	\
 	--enable-no-padding	\
 	--enable-symlinks	\
 	--enable-sigwinch	\
     --enable-pc-files \
     --with-pkg-config-libdir=/usr/lib/pkgconfig \
     --with-pkg-config \
 	--enable-colorfgbg	\
 	--enable-sp-funcs	\
 	--without-pthread	\
 	--disable-reentrant	\
 	--disable-ext-mouse	\
 	--disable-widec		\
 	--disable-ext-colors	\
 	--enable-weak-symbols	\
 	--enable-wgetch-events	\
 	--enable-pthreads-eintr	\
 	--enable-string-hacks	\
 	--prefix=/usr	\
 	--exec-prefix=/usr\
 	--libdir=/usr/lib	\
 	--datadir=/usr/share	\
 	--mandir=/usr/share/man	\
 	--includedir=/usr/include	\
 	"${WITHCHTYPE}" 	\
 	--disable-widec		\
 	--disable-tic-depends	\
 	--with-ticlib=tic
     #--with-pkg-config-libdir=/usr/lib/pkgconfig \
     #
     #  The configure line
     #
     c=$(grep '^ *$ *\./configure' config.log)
     #
     # This is a hack to be able to boot strap
     # a libncurses with correct fallback.c.
     #
     make -j16 -C include
     make -j16 -C ncurses fallback.c FALLBACK_LIST=""
     make -j16 -C progs   termsort.c transform.h infocmp tic
     rm   -f ncurses/fallback.c
     PATH=$PWD/progs:$OPATH
     LD_LIBRARY_PATH=$PWD/lib
     export LD_LIBRARY_PATH PATH
     pushd ncurses/
 	TERMINFO=$PWD/tmp
 	export TERMINFO
 	mkdir -p $TERMINFO
 export BUILD_TIC=$PWD/../progs/tic
 	$BUILD_TIC -I -r -e $FALLBK ../misc/terminfo.src > terminfo.src
 	$BUILD_TIC -o $TERMINFO -s terminfo.src
 	sh -e ./tinfo/MKfallback.sh $TERMINFO ../misc/terminfo.src $BUILD_TIC ${FALLBK//,/ } > fallback.c
 	rm -rf $TERMINFO
 	unset  TERMINFO
 	cp -p fallback.c ../fallback.c.backup
     popd
     PATH=$OPATH
     unset LD_LIBRARY_PATH
     #
     # Refresh second install path
     #
     rm -rf /var/tmp/ncurses-5.9-store
     mkdir  /var/tmp/ncurses-5.9-store
     #
     # Now rebuild libncurses and do the rest of this job
     #
     find -name fallback.o | xargs -r rm -vf
     cp fallback.c.backup ncurses/fallback.c
     make -j16
     lib=/usr/lib
     inc=/usr/include/ncurses
     # must not use 16 here (would lead to: ln: ncurses.h already exists)
     make install DESTDIR=/var/tmp/ncurses-5.9-store includedir=${inc} libdir=${lib}
     ln -sf ${inc##*/}/{curses,ncurses,term,termcap}.h /var/tmp/ncurses-5.9-store${inc%/*}/
     sh ${S}/packaging/edit.sed --cflags "-I${inc}" --libs "-lncurses" --libs "-ltinfo" /var/tmp/ncurses-5.9-store/usr/bin/ncurses5-config
     #
     # Now use --with-pthread for reentrant pthread support (abi > 5).
     #
     eval ./${c#*./} --with-pthread --enable-reentrant --enable-ext-mouse --disable-widec --disable-ext-colors --without-progs
     find -name fallback.o | xargs -r rm -vf
     cp fallback.c.backup ncurses/fallback.c
     make -j16
     lib=/usr/lib/ncurses6
     inc=/usr/include/ncurses6/ncurses
     # must not use 16 here (would lead to: ln: ncurses.h already exists)
     make install.libs install.includes DESTDIR=/var/tmp/ncurses-5.9-store includedir=${inc} libdir=${lib}
     ln -sf ${inc##*/}/{curses,ncurses,term}.h /var/tmp/ncurses-5.9-store${inc%/*}/
     sh ${S}/packaging/edit.sed --cflags "-I${inc} -I${inc%/*}" --libs "-L${lib} -lncurses" --libs "-ltinfo" /var/tmp/ncurses-5.9-store/usr/bin/ncurses6-config
     pushd man
 	sh ../edit_man.sh normal installing /var/tmp/ncurses-5.9-store/usr/share/man . ncurses6-config.1
     popd
     #
     # Now use --enable-widec for UTF8/wide character support.
     # The libs with 16 bit wide characters are binary incompatible
     # to the normal 8bit wide character libs.
     #
     eval ./${c#*./} --disable-ext-mouse --enable-widec --disable-ext-colors --without-progs
     find -name fallback.o | xargs -r rm -vf
     cp fallback.c.backup ncurses/fallback.c
     make -j16
     lib=/usr/lib
     inc=/usr/include/ncursesw
     # must not use 16 here (would lead to: ln: ncurses.h already exists)
     make install.libs install.includes DESTDIR=/var/tmp/ncurses-5.9-store includedir=${inc} libdir=${lib}
     sh ${S}/packaging/edit.sed --cflags "-I${inc}" --libs "-lncursesw" --libs "-ltinfo" /var/tmp/ncurses-5.9-store/usr/bin/ncursesw5-config
     pushd man
 	sh ../edit_man.sh normal installing /var/tmp/ncurses-5.9-store/usr/share/man . ncursesw5-config.1
     popd
     #
     # Do both --enable-widec and --with-pthread (abi > 5).
     #
     eval ./${c#*./} --with-pthread --enable-reentrant --enable-ext-mouse --enable-widec --enable-ext-colors --without-progs
     find -name fallback.o | xargs -r rm -vf
     cp fallback.c.backup ncurses/fallback.c
     make -j16
     lib=/usr/lib/ncurses6
     inc=/usr/include/ncurses6/ncursesw
     # must not use 16 here (would lead to: ln: ncurses.h already exists)
     make install.libs install.includes DESTDIR=/var/tmp/ncurses-5.9-store includedir=${inc} libdir=${lib}
     sh ${S}/packaging/edit.sed --cflags "-I${inc} -I${inc%/*}" --libs "-L${lib} -lncursesw" --libs "-ltinfo" /var/tmp/ncurses-5.9-store/usr/bin/ncursesw6-config
     pushd man
 	sh ../edit_man.sh normal installing /var/tmp/ncurses-5.9-store/usr/share/man . ncursesw6-config.1
     popd
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
     GZIP="-9"
     export GZIP
     (cd /var/tmp/ncurses-5.9-store/; tar -cpSf - *)|tar -xpsSf - -C ${D}/
     rm -rf /var/tmp/ncurses-5.9-store
     #mkdir -p ${D}/lib
     for model in libncurses libncursest libncursesw libncursestw libtinfo
     do
 	#for lib in ${D}/usr/lib/${model}.so.* ; do
 	#    test   -e "${lib}" || continue
 	#    mv "${lib}" ${D}/lib/ || continue
 	#done
 	for lib in ${D}//usr/lib/${model}.so.5 ; do
 	    test -e "${lib}" || continue
 	    test -L "${lib}" || continue
 	    lib=${lib#${D}}
 	    lnk=${D}/usr/lib/${model}.so
 	    case "${lib##*/}" in
 	    libncurses*)
 		rm -f ${lnk}
 		echo '/* GNU ld script */'		>  ${lnk}
 		echo "INPUT(${lib} AS_NEEDED(-ltinfo))" >> ${lnk}
 		;;
 	    #*)	ln -sf ${lib} ${D}/usr/lib/${model}.so
 	    esac
 	done
     done
     chmod 0755 ${D}//usr/lib/lib*.so.*
     chmod 0755 ${D}//usr/lib/lib*.so.*
     chmod a-x  ${D}//usr/lib/lib*.a
     if test -d ${D}/usr/lib/ncurses6 ; then
 	mv ${D}/usr/lib/ncurses6/*.so.6*   ${D}/usr/lib/
 	for lib in ${D}/usr/lib/ncurses6/*.so
 	do
 	    lnk=$lib
 	    lib=//usr/lib/${lib##*/}.6
 	    case "${lib##*/}" in
 	    libncurses*)
 		rm -f "${lnk}"
 		echo '/* GNU ld script */'		>  ${lnk}
 		echo "INPUT(${lib} AS_NEEDED(-ltinfo))"	>> ${lnk} 
 		;;
 	    libtinfo*)
 		test -L "${lnk}" || continue
 		ln -sf ${lib} ${lnk}
 		;;
 	    *)
 		test -L "${lnk}" || continue
 		ln -sf ../${lib##*/} ${lnk}
 	    esac
 	done
 	for model in libncurses libncursest libncursesw libncursestw libtinfo
 	do
 	    for lib in ${D}/usr/lib/${model}.so.* ; do
 		test   -e "${lib}" || continue
 		#mv "${lib}" ${D}/lib/ || continue
 	    done
 	    for lib in ${D}//usr/lib/${model}.so.6 ; do
 		test -e "${lib}" || continue
 		test -L "${lib}" || continue
 		lib=${lib#${D}}
 		lnk=${D}/usr/lib/ncurses6/${model}.so
 		case "${lib##*/}" in
 		libncurses*)
 		    rm -f ${lnk}
 		    echo '/* GNU ld script */'		    >  ${lnk}
 		    echo 'SEARCH_DIR(/usr/lib/ncurses6)'  >> ${lnk}
 		    echo "INPUT(${lib} AS_NEEDED(-ltinfo))" >> ${lnk}
 		    ;;
 		*)  : #ln -sf ${lib} ${D}/usr/lib/ncurses6/${model}.so
 	    esac
 	    done
 	done
 	chmod 0755 ${D}//usr/lib/lib*.so.6*
 	chmod 0755 ${D}//usr/lib/lib*.so.6*
 	chmod a-x  ${D}//usr/lib/ncurses6/lib*.a
     fi
     test -n "${D}" || ldconfig -N
     mkdir -p ${D}/usr/share/doc/packages/ncurses
     bzip2 -c misc/terminfo.src > misc/terminfo.src.bz2
     install -m 644 misc/terminfo.src.bz2	${D}/usr/share/doc/packages/ncurses/
     install -m 644 doc/html/*.html		${D}/usr/share/doc/packages/ncurses/
     bzip2 doc/ncurses-intro.doc -c > doc/ncurses-intro.txt.bz2
     install -m 644 doc/ncurses-intro.txt.bz2	${D}/usr/share/doc/packages/ncurses/
     bzip2 doc/hackguide.doc -c > doc/hackguide.txt.bz2
     install -m 644 doc/hackguide.txt.bz2	${D}/usr/share/doc/packages/ncurses/
     install -m 644 README			${D}/usr/share/doc/packages/ncurses/
     install -m 644 NEWS				${D}/usr/share/doc/packages/ncurses/
     mkdir -p ${D}/etc
     mkdir -p ${D}/usr/share/misc
     LD_LIBRARY_PATH=$PWD/lib
     export LD_LIBRARY_PATH
     pushd ncurses/
 	{ echo "# See annotated version in /usr/share/doc/packages/ncurses/terminfo.src.bz2"
 	BUILD_TIC=$PWD/../progs/tic
 	$BUILD_TIC -C -r ../misc/terminfo.src | grep -E -v '^#'; } > termcap
 	# Gererate new termcap entries for various linux consoles
 	TERMCAP=termcap \
 	TERMINFO=${D}/usr/share/terminfo \
 	    bash ${S}/packaging/handle.linux
 	install -m 0644 termcap.new ${D}/usr/share/misc/termcap
     popd
     unset LD_LIBRARY_PATH
     if test `/usr/bin/id -u` = '0' ; then
 	chown root:root ${D}/usr/share/misc/termcap
 	chmod 0644      ${D}/usr/share/misc/termcap
     fi
     ln -sf /usr/share/misc/termcap ${D}/etc/termcap
     (cat > default.list) <<-EOF
 	/usr/share/tabset/std
 	/usr/share/tabset/stdcrt
 	/usr/share/tabset/vt100
 	/usr/share/tabset/vt300
 	/usr/share/terminfo/a/ansi
 	/usr/share/terminfo/d/dumb
 	/usr/share/terminfo/g/gnome
 	/usr/share/terminfo/g/gnome-rh72
 	/usr/share/terminfo/k/klone+color
 	/usr/share/terminfo/k/kvt
 	/usr/share/terminfo/l/linux
 	/usr/share/terminfo/l/linux-m
 	/usr/share/terminfo/l/linux-nic
 	/usr/share/terminfo/m/mlterm
 	/usr/share/terminfo/n/nxterm
 	/usr/share/terminfo/r/rxvt
 	/usr/share/terminfo/s/screen
 	/usr/share/terminfo/s/screen-w
 	/usr/share/terminfo/s/screen-256color
 	/usr/share/terminfo/s/sun
 	/usr/share/terminfo/u/unknown
 	/usr/share/terminfo/v/vt100
 	/usr/share/terminfo/v/vt102
 	/usr/share/terminfo/v/vt220
 	/usr/share/terminfo/v/vt220-8
 	/usr/share/terminfo/v/vt220-8bit
 	/usr/share/terminfo/v/vt320
 	/usr/share/terminfo/v/vt52
 	/usr/share/terminfo/x/xterm
 	/usr/share/terminfo/x/xterm-color
 	/usr/share/terminfo/x/xterm-256color
 	/usr/share/terminfo/x/xterm-basic
 	/usr/share/terminfo/x/xterm-nic
 	/usr/share/terminfo/x/xterm-r6
 	EOF
     find ${D}/usr/share/tabset/"" ${D}/usr/share/terminfo/"" \
 	\( -type f -or -type l \) | \
 	sed "s@^${D}@@g" | \
 	grep -v -F -x -f default.list \
 	> extension.list
     rm -f ${D}/usr/lib/terminfo
 
 
}

PACKAGES = ""
PACKAGES += "ncurses-docs"
PACKAGES += "ncurses-utils"
PACKAGES += "terminfo-base"
PACKAGES += "ncurses-devel"
PACKAGES += "ncurses"
PACKAGES += "libncurses"
PACKAGES += "libncurses6"

ncurses-docs_files = ""
ncurses-docs_files += "/usr/share/info"
ncurses-docs_files += "/usr/share/man"
ncurses-docs_files += "/usr/share/doc/packages/ncurses/"
ncurses-docs_files += "/usr/share/doc/packages/ncurses/*"

ncurses-utils_files = ""
ncurses-utils_files += "ncurses.manifest"
ncurses-utils_files += "/usr/bin/clear"
ncurses-utils_files += "/usr/bin/reset"
ncurses-utils_files += "/usr/bin/tabs"
ncurses-utils_files += "/usr/bin/toe"
ncurses-utils_files += "/usr/bin/tput"
ncurses-utils_files += "/usr/bin/tset"

terminfo-base_files = ""
terminfo-base_files += "ncurses.manifest"
terminfo-base_files += "/etc/termcap"
terminfo-base_files += "/usr/share/misc/termcap"
terminfo-base_files += "/usr/share/tabset/"
terminfo-base_files += "/usr/share/terminfo/"
terminfo-base_files += "/usr/share/terminfo/*/"

ncurses-devel_files = ""
ncurses-devel_files += "ncurses.manifest"
ncurses-devel_files += "/usr/bin/ncurses*-config"
ncurses-devel_files += "/usr/bin/captoinfo"
ncurses-devel_files += "/usr/bin/infocmp"
ncurses-devel_files += "/usr/bin/infotocap"
ncurses-devel_files += "/usr/bin/tic"
ncurses-devel_files += "/usr/include/ncurses/"
ncurses-devel_files += "/usr/include/ncursesw/"
ncurses-devel_files += "/usr/include/ncurses6/"
ncurses-devel_files += "/usr/include/ncurses6/ncurses/"
ncurses-devel_files += "/usr/include/ncurses6/ncursesw/"
ncurses-devel_files += "/usr/include/*.h"
ncurses-devel_files += "/usr/include/ncurses*/*.h"
ncurses-devel_files += "/usr/include/ncurses*/*/*.h"
ncurses-devel_files += "/usr/lib/ncurses6/"
ncurses-devel_files += "/usr/lib/lib*.a"
ncurses-devel_files += "/usr/lib/lib*.so"
ncurses-devel_files += "/usr/lib/pkgconfig/*.pc"
ncurses-devel_files += "/usr/lib/ncurses6/lib*.a"
ncurses-devel_files += "/usr/lib/ncurses6/lib*.so"

ncurses_files = ""
ncurses_files += "ncurses.manifest"

libncurses_files = ""
libncurses_files += "ncurses.manifest"
libncurses_files += "/usr/lib/lib*.so.5*"

libncurses6_files = ""
libncurses6_files += "ncurses.manifest"
libncurses6_files += "/usr/lib/lib*.so.6*"

FILES_${PN}-docs = "${ncurses-docs_files}"
FILES_${PN}-utils = "${ncurses-utils_files}"
FILES_terminfo-base = "${terminfo-base_files}"
FILES_${PN}-devel = "${ncurses-devel_files}"
FILES_${PN} = "${ncurses_files}"
FILES_lib${PN} = "${libncurses_files}"
FILES_lib${PN}6 = "${libncurses6_files}"

PKG_ncurses-docs= "ncurses-docs"
PKG_ncurses-utils= "ncurses-utils"
PKG_terminfo-base= "terminfo-base"
PKG_ncurses-devel= "ncurses-devel"
PKG_ncurses= "ncurses"
PKG_libncurses= "libncurses"
PKG_libncurses6= "libncurses6"

require ncurses-extraconf.inc
