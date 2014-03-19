DESCRIPTION = "Boost C++ Libraries"
HOMEPAGE = "http://www.boost.org"
SECTION = "Base/Libraries"
LICENSE = "BSD-3-Clause"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libboost_signals 
PROVIDES += "libboost_signals"
RPROVIDES_libboost_signals += "libboost_signals"

#PROVIDES by boost-license 
PROVIDES += "boost-license"
RPROVIDES_boost-license += "boost-license"

#PROVIDES by libboost_chrono 
PROVIDES += "libboost_chrono"
RPROVIDES_libboost_chrono += "libboost_chrono"
# the PROVIDES rules is ignore "boost-chrono  "
PROVIDES += "boost-chrono"
RPROVIDES_libboost_chrono += "boost-chrono"

#PROVIDES by libboost_test 
PROVIDES += "libboost_test"
RPROVIDES_libboost_test += "libboost_test"
# the PROVIDES rules is ignore "boost-test  "
PROVIDES += "boost-test"
RPROVIDES_libboost_test += "boost-test"

#PROVIDES by libboost_graph 
PROVIDES += "libboost_graph"
RPROVIDES_libboost_graph += "libboost_graph"
# the PROVIDES rules is ignore "boost-graph  "
PROVIDES += "boost-graph"
RPROVIDES_libboost_graph += "boost-graph"

#PROVIDES by libboost_context 
PROVIDES += "libboost_context"
RPROVIDES_libboost_context += "libboost_context"

#PROVIDES by libboost_python 
PROVIDES += "libboost_python"
RPROVIDES_libboost_python += "libboost_python"
# the PROVIDES rules is ignore "boost-python  "
PROVIDES += "boost-python"
RPROVIDES_libboost_python += "boost-python"

#PROVIDES by libboost_timer 
PROVIDES += "libboost_timer"
RPROVIDES_libboost_timer += "libboost_timer"
# the PROVIDES rules is ignore "boost-timer  "
PROVIDES += "boost-timer"
RPROVIDES_libboost_timer += "boost-timer"

#PROVIDES by boost 
PROVIDES += "boost"
RPROVIDES_boost += "boost"

#PROVIDES by libboost_system 
PROVIDES += "libboost_system"
RPROVIDES_libboost_system += "libboost_system"
# the PROVIDES rules is ignore "boost-system  "
PROVIDES += "boost-system"
RPROVIDES_libboost_system += "boost-system"

#PROVIDES by libboost_thread 
PROVIDES += "libboost_thread"
RPROVIDES_libboost_thread += "libboost_thread"
# the PROVIDES rules is ignore "boost-thread  "
PROVIDES += "boost-thread"
RPROVIDES_libboost_thread += "boost-thread"

#PROVIDES by boost-devel 
PROVIDES += "boost-devel"
RPROVIDES_boost-devel += "boost-devel"
RPROVIDES_boost-devel += "boost-dev"

#PROVIDES by libboost_random 
PROVIDES += "libboost_random"
RPROVIDES_libboost_random += "libboost_random"
# the PROVIDES rules is ignore "boost-random  "
PROVIDES += "boost-random"
RPROVIDES_libboost_random += "boost-random"

#PROVIDES by libboost_filesystem 
PROVIDES += "libboost_filesystem"
RPROVIDES_libboost_filesystem += "libboost_filesystem"
# the PROVIDES rules is ignore "boost-filesystem  "
PROVIDES += "boost-filesystem"
RPROVIDES_libboost_filesystem += "boost-filesystem"

#PROVIDES by libboost_program_options 
PROVIDES += "libboost_program_options"
RPROVIDES_libboost_program_options += "libboost_program_options"
# the PROVIDES rules is ignore "boost-program-options  "
PROVIDES += "boost-program-options"
RPROVIDES_libboost_program_options += "boost-program-options"

#PROVIDES by libboost_math 
PROVIDES += "libboost_math"
RPROVIDES_libboost_math += "libboost_math"
# the PROVIDES rules is ignore "boost-math  "
PROVIDES += "boost-math"
RPROVIDES_libboost_math += "boost-math"

#PROVIDES by libboost_wave 
PROVIDES += "libboost_wave"
RPROVIDES_libboost_wave += "libboost_wave"
# the PROVIDES rules is ignore "boost-wave  "
PROVIDES += "boost-wave"
RPROVIDES_libboost_wave += "boost-wave"

#PROVIDES by libboost_locale 
PROVIDES += "libboost_locale"
RPROVIDES_libboost_locale += "libboost_locale"
# the PROVIDES rules is ignore "boost-locale  "
PROVIDES += "boost-locale"
RPROVIDES_libboost_locale += "boost-locale"

#PROVIDES by libboost_iostreams 
PROVIDES += "libboost_iostreams"
RPROVIDES_libboost_iostreams += "libboost_iostreams"
# the PROVIDES rules is ignore "boost-iostreams  "
PROVIDES += "boost-iostreams"
RPROVIDES_libboost_iostreams += "boost-iostreams"

#PROVIDES by libboost_date_time 
PROVIDES += "libboost_date_time"
RPROVIDES_libboost_date_time += "libboost_date_time"
# the PROVIDES rules is ignore "boost-datetime  "
PROVIDES += "boost-datetime"
RPROVIDES_libboost_date_time += "boost-datetime"

#PROVIDES by libboost_serialization 
PROVIDES += "libboost_serialization"
RPROVIDES_libboost_serialization += "libboost_serialization"
# the PROVIDES rules is ignore "boost-serialization  "
PROVIDES += "boost-serialization"
RPROVIDES_libboost_serialization += "boost-serialization"

#PROVIDES by libboost_regex 
PROVIDES += "libboost_regex"
RPROVIDES_libboost_regex += "libboost_regex"
# the PROVIDES rules is ignore "boost-regex  "
PROVIDES += "boost-regex"
RPROVIDES_libboost_regex += "boost-regex"

RDEPENDS = ""
#RDEPENDS of libboost_signals (lib${PN}_signals)
RDEPENDS_lib${PN}_signals += "boost-license"

#RDEPENDS of boost-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libstdc++-dev"
RDEPENDS_${PN}-devel += "libboost_thread"
RDEPENDS_${PN}-devel += "libboost_regex"
RDEPENDS_${PN}-devel += "libboost_date_time"
RDEPENDS_${PN}-devel += "libboost_random"
RDEPENDS_${PN}-devel += "libboost_graph"
RDEPENDS_${PN}-devel += "libboost_filesystem"
RDEPENDS_${PN}-devel += "libboost_program_options"
RDEPENDS_${PN}-devel += "libboost_serialization"
RDEPENDS_${PN}-devel += "libboost_math"
RDEPENDS_${PN}-devel += "libboost_locale"
RDEPENDS_${PN}-devel += "libboost_signals"
RDEPENDS_${PN}-devel += "libboost_chrono"
RDEPENDS_${PN}-devel += "libboost_python"
RDEPENDS_${PN}-devel += "libboost_wave"
RDEPENDS_${PN}-devel += "libboost_timer"
RDEPENDS_${PN}-devel += "libboost_test"
RDEPENDS_${PN}-devel += "libboost_system"
RDEPENDS_${PN}-devel += "libboost_iostreams"

#RDEPENDS of libboost_test (lib${PN}_test)
RDEPENDS_lib${PN}_test += "boost-license"

#RDEPENDS of libboost_graph (lib${PN}_graph)
RDEPENDS_lib${PN}_graph += "boost-license"

#RDEPENDS of libboost_context (lib${PN}_context)
RDEPENDS_lib${PN}_context += "boost-license"

#RDEPENDS of libboost_python (lib${PN}_python)
RDEPENDS_lib${PN}_python += "boost-license"

#RDEPENDS of libboost_timer (lib${PN}_timer)
RDEPENDS_lib${PN}_timer += "boost-license"

#RDEPENDS of libboost_system (lib${PN}_system)
RDEPENDS_lib${PN}_system += "boost-license"

#RDEPENDS of libboost_thread (lib${PN}_thread)
RDEPENDS_lib${PN}_thread += "boost-license"

#RDEPENDS of libboost_chrono (lib${PN}_chrono)
RDEPENDS_lib${PN}_chrono += "boost-license"

#RDEPENDS of libboost_random (lib${PN}_random)
RDEPENDS_lib${PN}_random += "boost-license"

#RDEPENDS of libboost_filesystem (lib${PN}_filesystem)
RDEPENDS_lib${PN}_filesystem += "boost-license"

#RDEPENDS of libboost_program_options (lib${PN}_program_options)
RDEPENDS_lib${PN}_program_options += "boost-license"

#RDEPENDS of libboost_math (lib${PN}_math)
RDEPENDS_lib${PN}_math += "boost-license"

#RDEPENDS of libboost_wave (lib${PN}_wave)
RDEPENDS_lib${PN}_wave += "boost-license"

#RDEPENDS of libboost_locale (lib${PN}_locale)
RDEPENDS_lib${PN}_locale += "boost-license"

#RDEPENDS of libboost_iostreams (lib${PN}_iostreams)
RDEPENDS_lib${PN}_iostreams += "boost-license"

#RDEPENDS of libboost_date_time (lib${PN}_date_time)
RDEPENDS_lib${PN}_date_time += "boost-license"

#RDEPENDS of libboost_serialization (lib${PN}_serialization)
RDEPENDS_lib${PN}_serialization += "boost-license"

#RDEPENDS of libboost_regex (lib${PN}_regex)
RDEPENDS_lib${PN}_regex += "boost-license"


DEPENDS = ""
#DEPENDS of boost 
DEPENDS += "zlib-devel"
DEPENDS += "python-devel"
DEPENDS += "bzip2-devel"
DEPENDS += "chrpath"
DEPENDS += "expat-devel"
DEPENDS += "xz"
DEPENDS += "libicu-devel"
DEPENDS += "dos2unix"
DEPENDS += "fdupes-native"
DEPENDS += "gcc-c++"
DEPENDS += "boost-jam"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n boost_1_51_0 
 cp ${S}/packaging/boost.manifest .
 #everything in the tarball has the executable flag set ...
 find -type f ! \( -name \*.sh -o -name \*.py -o -name \*.pl \) -exec chmod -x {} +
 
 #stupid build machinery copies .orig files
 find . -name \*.orig -exec rm {} +
 
 
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
 
 find . -type f -exec chmod u+w {} +
 
 # Now build it
 J_P=16
 J_G=$(getconf _NPROCESSORS_ONLN)
 [ $J_G -gt 64 ] && J_G=64
 
 if test -z "$JOBS"; then
   JOBS=$J_G
 else
   test 1 -gt "$JOBS" && JOBS=1
 fi
 if test "$JOBS" == "0"; then
   JOBS=1
 fi
 
 # In case you want more parallel jobs then autobuild grants you
 #if [ $J_P -gt $J_I ]; then
 #  JOBS=$J_G
 #fi
 BJAM_CONFIG="-d2 -j$JOBS -sICU_PATH=/usr"
 PYTHON_VERSION=$(python -c 'import sys; print sys.version[:3]')
 PYTHON_FLAGS="--with-python-root=/usr --with-python-version=$PYTHON_VERSION"
 REGEX_FLAGS="--with-icu"
 export EXPAT_INCLUDE=/usr/include EXPAT_LIBPATH=/usr/lib REGEX_FLAGS="--with-icu"
 export PYTHON_FLAGS
 
 cat << EOF >user-config.jam
 # Boost.Build Configuration
 
 # Compiler configuration
 using gcc ;
 
 # Python configuration
 using python : ${PYTHON_VERSION} : /usr ;
 EOF
 
 
 
 sh ./bootstrap.sh
 ./b2
 
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 # Now build it
 J_P=16
 J_G=$(getconf _NPROCESSORS_ONLN)
 [ $J_G -gt 64 ] && J_G=64
 
 if test -z "$JOBS"; then
   JOBS=$J_G
 else
   test 1 -gt "$JOBS" && JOBS=1
 fi
 if test "$JOBS" == "0"; then
   JOBS=1
 fi
 
 # In case you want more parallel jobs then autobuild grants you
 if [ $J_P -gt $J_G ]; then
   JOBS=$J_G
 fi
 
 BJAM_CONFIG="-d2 -j$JOBS -sICU_PATH=/usr"
 PYTHON_VERSION=$(python -c 'import sys; print sys.version[:3]')
 PYTHON_FLAGS="--with-python-root=/usr --with-python-version=$PYTHON_VERSION"
 REGEX_FLAGS="--with-icu"
 export EXPAT_INCLUDE=/usr/include EXPAT_LIBPATH=/usr/lib REGEX_FLAGS="--with-icu"
 export PYTHON_FLAGS
 
 # Set PATH, MANPATH and LD_LIBRARY_PATH
 
 /usr/bin/bjam ${BJAM_CONFIG} ${LONG_DOUBLE_FLAGS} --user-config=user-config.jam \
 	--prefix=${D}/usr \
 	--exec-prefix=$${D}/usr \
 	--libdir=${D}/usr/lib \
 	--includedir=${D}/usr/include \
 	install || echo "Not all Boost libraries built properly."
 
 mkdir -p ${D}/usr/share/doc/packages/boost
 
 pushd ${D}/usr/lib
 blibs=$(find . -name \*.so.1.51.0)
 echo $blibs | xargs chrpath -d 
 
 for lib in ${blibs}; do
   BASE=$(basename ${lib} .so.1.51.0)
   SONAME_MT="$BASE-mt.so"
   ln -sf ${lib} $SONAME_MT
 done
 popd
 
 #install the man pages
 rm -rf doc/man/man3/boost::units::operator
 
 for sec in 3 7 9; do
     install -d ${D}//usr/share/man/man${sec}
 done
 
 #install doc files
 dos2unix libs/ptr_container/doc/tutorial_example.html \
 	libs/parameter/doc/html/reference.html \
 	libs/parameter/doc/html/index.html \
 	libs/iostreams/doc/tree/tree.js \
 	libs/graph/doc/lengauer_tarjan_dominator.htm \
 	libs/test/test/test_files/errors_handling_test.pattern \
 	libs/test/test/test_files/result_report_test.pattern
 find . -name \*.htm\* -o -name \*.gif -o -name \*.css -o -name \*.jpg -o -name \*.png -o -name \*.ico | \
 	tar --files-from=${S}/packaging/existing_extra_docs -cf - --files-from=- | tar -C ${D}/usr/share/doc/packages/boost -xf -
 rm -rf ${D}/usr/share/doc/packages/boost/boost
 ln -s /usr/include/boost ${D}/usr/share/doc/packages/boost
 ln -s ../LICENSE_1_0.txt ${D}/usr/share/doc/packages/boost/libs
 #Copy the news file.
 #cp %{S:5} %{buildroot}%{_docdir}
 #only for documentation, doesn't need to be executable
 find ${D}/usr/share/doc/packages/boost -name \*.py -exec chmod -x {} +
 rm -f ${D}/usr/lib/*.a
 #symlink dupes
 
  _target=""; 
  _symlinks=0; 
   
  fdupes -q -n -r ${D} | 
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
 
 
   rm -rf ${D}/usr/share/info 
   rm -rf ${D}/usr/share/doc/packages 
   rm -rf ${D}/usr/share/doc/boost 
   rm -rf ${D}/usr/share/doc/boost-1.51.0 
   rm -rf ${D}/usr/share/gtk-doc 
   rm -rf ${D}/usr/share/doc 
   rm -rf ${D}/usr/share/man 
   find ${D} -regex ".*/man/man./.*.[0-9]" | xargs rm -f -- 
   find ${D} -regex ".*/man/../man./.*.[0-9]" | xargs rm -f -- 
   find ${D} -regex ".*/man/man./.*.[0-9]pm" | xargs rm -f --
 
 
 
}

PACKAGES = ""
PACKAGES += "libboost_thread"
PACKAGES += "libboost_chrono"
PACKAGES += "libboost_date_time"
PACKAGES += "libboost_random"
PACKAGES += "libboost_graph"
PACKAGES += "libboost_context"
PACKAGES += "libboost_filesystem"
PACKAGES += "libboost_program_options"
PACKAGES += "libboost_serialization"
PACKAGES += "libboost_math"
PACKAGES += "libboost_locale"
PACKAGES += "boost-license"
PACKAGES += "boost-devel"
PACKAGES += "libboost_python"
PACKAGES += "libboost_wave"
PACKAGES += "libboost_regex"
PACKAGES += "libboost_timer"
PACKAGES += "libboost_signals"
PACKAGES += "libboost_test"
PACKAGES += "libboost_system"
PACKAGES += "libboost_iostreams"

libboost_thread_files = ""
libboost_thread_files += "boost.manifest"
libboost_thread_files += "/usr/lib/libboost_thread*.so.*"

libboost_chrono_files = ""
libboost_chrono_files += "boost.manifest"
libboost_chrono_files += "/usr/lib/libboost_chrono*.so.*"

libboost_date_time_files = ""
libboost_date_time_files += "boost.manifest"
libboost_date_time_files += "/usr/lib/libboost_date_time*.so.*"

libboost_random_files = ""
libboost_random_files += "boost.manifest"
libboost_random_files += "/usr/lib/libboost_random*.so.*"

libboost_graph_files = ""
libboost_graph_files += "boost.manifest"
libboost_graph_files += "/usr/lib/libboost_graph*.so.*"

libboost_context_files = ""
libboost_context_files += "boost.manifest"
libboost_context_files += "/usr/lib/libboost_context*.so.*"

libboost_filesystem_files = ""
libboost_filesystem_files += "boost.manifest"
libboost_filesystem_files += "/usr/lib/libboost_filesystem*.so.*"

libboost_program_options_files = ""
libboost_program_options_files += "boost.manifest"
libboost_program_options_files += "/usr/lib/libboost_program_options*.so.*"

libboost_serialization_files = ""
libboost_serialization_files += "boost.manifest"
libboost_serialization_files += "/usr/lib/libboost_*serialization*.so.*"

libboost_math_files = ""
libboost_math_files += "boost.manifest"
libboost_math_files += "/usr/lib/libboost_math_*.so.*"

libboost_locale_files = ""
libboost_locale_files += "boost.manifest"
libboost_locale_files += "/usr/lib/libboost_locale*.so.*"

boost-license_files = ""
boost-license_files += "boost.manifest"

boost-devel_files = ""
boost-devel_files += "boost.manifest"
boost-devel_files += "/usr/include/boost"
boost-devel_files += "/usr/lib/*.so"

libboost_python_files = ""
libboost_python_files += "boost.manifest"
libboost_python_files += "/usr/lib/libboost_python*.so.*"

libboost_wave_files = ""
libboost_wave_files += "boost.manifest"
libboost_wave_files += "/usr/lib/libboost_wave*.so.*"

libboost_regex_files = ""
libboost_regex_files += "boost.manifest"
libboost_regex_files += "/usr/lib/libboost_regex*.so.*"

libboost_timer_files = ""
libboost_timer_files += "boost.manifest"
libboost_timer_files += "/usr/lib/libboost_timer*.so.*"

libboost_signals_files = ""
libboost_signals_files += "boost.manifest"
libboost_signals_files += "/usr/lib/libboost_signals*.so.*"

libboost_test_files = ""
libboost_test_files += "boost.manifest"
libboost_test_files += "/usr/lib/libboost_prg_exec_monitor*.so.*"
libboost_test_files += "/usr/lib/libboost_unit_test_framework*.so.*"

libboost_system_files = ""
libboost_system_files += "boost.manifest"
libboost_system_files += "/usr/lib/libboost_system*.so.*"

libboost_iostreams_files = ""
libboost_iostreams_files += "boost.manifest"
libboost_iostreams_files += "/usr/lib/libboost_iostreams*.so.*"

FILES_lib${PN}_thread = "${libboost_thread_files}"
FILES_lib${PN}_chrono = "${libboost_chrono_files}"
FILES_lib${PN}_date_time = "${libboost_date_time_files}"
FILES_lib${PN}_random = "${libboost_random_files}"
FILES_lib${PN}_graph = "${libboost_graph_files}"
FILES_lib${PN}_context = "${libboost_context_files}"
FILES_lib${PN}_filesystem = "${libboost_filesystem_files}"
FILES_lib${PN}_program_options = "${libboost_program_options_files}"
FILES_lib${PN}_serialization = "${libboost_serialization_files}"
FILES_lib${PN}_math = "${libboost_math_files}"
FILES_lib${PN}_locale = "${libboost_locale_files}"
FILES_${PN}-license = "${boost-license_files}"
FILES_${PN}-devel = "${boost-devel_files}"
FILES_lib${PN}_python = "${libboost_python_files}"
FILES_lib${PN}_wave = "${libboost_wave_files}"
FILES_lib${PN}_regex = "${libboost_regex_files}"
FILES_lib${PN}_timer = "${libboost_timer_files}"
FILES_lib${PN}_signals = "${libboost_signals_files}"
FILES_lib${PN}_test = "${libboost_test_files}"
FILES_lib${PN}_system = "${libboost_system_files}"
FILES_lib${PN}_iostreams = "${libboost_iostreams_files}"

PKG_libboost_thread= "libboost_thread"
PKG_libboost_chrono= "libboost_chrono"
PKG_libboost_date_time= "libboost_date_time"
PKG_libboost_random= "libboost_random"
PKG_libboost_graph= "libboost_graph"
PKG_libboost_context= "libboost_context"
PKG_libboost_filesystem= "libboost_filesystem"
PKG_libboost_program_options= "libboost_program_options"
PKG_libboost_serialization= "libboost_serialization"
PKG_libboost_math= "libboost_math"
PKG_libboost_locale= "libboost_locale"
PKG_boost-license= "boost-license"
PKG_boost-devel= "boost-devel"
PKG_libboost_python= "libboost_python"
PKG_libboost_wave= "libboost_wave"
PKG_libboost_regex= "libboost_regex"
PKG_libboost_timer= "libboost_timer"
PKG_libboost_signals= "libboost_signals"
PKG_libboost_test= "libboost_test"
PKG_libboost_system= "libboost_system"
PKG_libboost_iostreams= "libboost_iostreams"

require boost-extraconf.inc
