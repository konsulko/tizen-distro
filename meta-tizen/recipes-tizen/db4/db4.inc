DESCRIPTION = "Berkeley DB Database Library Version 4.8"
HOMEPAGE = "http://www.sleepycat.com"
SECTION = "System/Libraries"
LICENSE = "BSD-3-Clause"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by db4-doc 
PROVIDES += "db4-doc"
RPROVIDES_db4-doc += "db4-doc"

#PROVIDES by db4-utils 
PROVIDES += "db4-utils"
RPROVIDES_db4-utils += "db4-utils"

#PROVIDES by db4 
PROVIDES += "db4"
RPROVIDES_db4 += "db4"
# the PROVIDES rules is ignore "db = 4.8.30.NC"
PROVIDES += "db"
RPROVIDES_db4 += "db"

#PROVIDES by db4-devel 
PROVIDES += "db4-devel"
RPROVIDES_db4-devel += "db4-devel"
RPROVIDES_db4-devel += "db4-dev"

RDEPENDS = ""
#RDEPENDS of db4-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "glibc-dev"
RDEPENDS_${PN}-devel += "db4"


DEPENDS = ""
#DEPENDS of db4 
DEPENDS += "autoconf-native"
DEPENDS += "gcc-c++"
DEPENDS += "fdupes-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n db-4.8.30.NC
 cp ${S}/packaging/db4.manifest .
 
 
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
 
 cd dist
 # dist/RELEASE codes the build date into the binary.
 # Use last change of changes file instead
 LAST_MOD=`stat --format="%Y" ${S}/packaging/db4.changes`
 DIST_DATE=`date '+%B %e, %Y' --date="@$LAST_MOD"`
 sed -i -e "s/^DB_RELEASE_DATE=.*$/DB_RELEASE_DATE=\"$DIST_DATE\"/" RELEASE
 ./s_config
 CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -fno-strict-aliasing"
 CC=gcc
 export CFLAGS CXXFLAGS CC
 #
 # Build now the NPTL version
 #
 mkdir ../build_nptl
 cd ../build_nptl
 ../dist/configure --prefix=/usr \
         --libdir=/usr/lib --enable-compat185 --disable-dump185 \
         --enable-shared --disable-static --enable-cxx \
         --with-mutex="POSIX/pthreads/library" \
         x86_64-suse-linux
 # Make sure O_DIRECT is really disabled (build host could have old kernel)
 perl -pi -e 's/#define HAVE_O_DIRECT 1/#undef HAVE_O_DIRECT/' db_config.h
 # Remove libtool predep_objects and postdep_objects wonkiness
 perl -pi -e 's/^predep_objects=".*$/predep_objects=""/' libtool
 perl -pi -e 's/^postdep_objects=".*$/postdep_objects=""/' libtool
 perl -pi -e 's/-shared -nostdlib/-shared/' libtool
 
 make -j16 LIBSO_LIBS='$(LIBS)' LIBXSO_LIBS='$(LIBS)'" -L/usr/lib -lstdc++"
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 mkdir -p ${D}/usr/include/db4
 CONFIG_ARGS=$(find . -name "config.log" -exec grep "\$ \.\./dist\/configure" {} \; | sed 's/.*configure\( --.*\)/\1/g')
 if [ -z "$CONFIG_ARGS" ]
 then
   echo "could not find configure arguments ... exiting"
   exit 42
 fi
 mkdir -p ${D}/usr/lib
 cd build_nptl
 make prefix=${D}/usr libdir=${D}/usr/lib strip=true install
 cd ..
 # make ldd happy:
 chmod 755 ${D}/usr/lib/libdb*.so
 # Fix header file installation
 mv ${D}/usr/include/*.h ${D}/usr/include/db4
 echo "#include <db4/db.h>" > ${D}/usr/include/db.h
 echo "#include <db4/db_185.h>" > ${D}/usr/include/db_185.h
 echo "#include <db4/db_cxx.h>" > ${D}/usr/include/db_cxx.h
 # remove dangling tags symlink from examples.
 rm -f examples_cxx/tags
 rm -f examples_c/tags
 # Move documentation to the right directory
 mkdir -p ${D}/usr/share/doc/packages/db4
 mv ${D}/usr/docs/* ${D}//usr/share/doc/packages/db4
 cp -a examples_cxx examples_c ${D}//usr/share/doc/packages/db4
 cp -a LICENSE README ${D}//usr/share/doc/packages/db4
 #
 # Remove api documentation for C++, Java and TCL
 rm -rf ${D}//usr/share/doc/packages/db4/csharp
 rm -rf ${D}//usr/share/doc/packages/db4/java
 rm -rf ${D}//usr/share/doc/packages/db4/api_reference/CXX
 rm -rf ${D}//usr/share/doc/packages/db4/api_reference/STL
 rm -rf ${D}//usr/share/doc/packages/db4/api_reference/TCL
 rm -rf ${D}//usr/share/doc/packages/db4/gsg*/CXX
 rm -rf ${D}//usr/share/doc/packages/db4/gsg*/JAVA
 mv ${D}//usr/share/doc/packages/db4/collections/tutorial ${D}//usr/share/doc/packages/db4/
 # Remove crappy *.la files
 rm -rf ${D}/usr/lib/*.la
 rm -rf ${D}/usr/lib/tls/*.la
 
  _target=""; 
  _symlinks=0; 
   
  fdupes -q -n -r ${D}/usr/lib | 
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
 
  _target=""; 
  _symlinks=0; 
   
  fdupes -q -n -r ${D}/usr/share/doc/packages/db4 | 
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
 
 
}

PACKAGES = ""
PACKAGES += "db4-doc"
PACKAGES += "db4-utils"
PACKAGES += "db4"
PACKAGES += "db4-devel"

db4-doc_files = ""
db4-doc_files += "db4.manifest"
db4-doc_files += "/usr/share/doc/packages/db4"
db4-doc_files += "/usr/share/doc/packages/db4/LICENSE"
db4-doc_files += "/usr/share/doc/packages/db4/README"
db4-doc_files += "/usr/share/doc/packages/db4/index.html"
db4-doc_files += "/usr/share/doc/packages/db4/license"
db4-doc_files += "/usr/share/doc/packages/db4/articles"
db4-doc_files += "/usr/share/doc/packages/db4/api_reference"
db4-doc_files += "/usr/share/doc/packages/db4/examples_c"
db4-doc_files += "/usr/share/doc/packages/db4/examples_cxx"
db4-doc_files += "/usr/share/doc/packages/db4/gsg*"
db4-doc_files += "/usr/share/doc/packages/db4/porting"
db4-doc_files += "/usr/share/doc/packages/db4/programmer_reference"
db4-doc_files += "/usr/share/doc/packages/db4/tutorial"

db4-utils_files = ""
db4-utils_files += "db4.manifest"
db4-utils_files += "/usr/bin/db_archive"
db4-utils_files += "/usr/bin/db_checkpoint"
db4-utils_files += "/usr/bin/db_deadlock"
db4-utils_files += "/usr/bin/db_dump"
db4-utils_files += "/usr/bin/db_load"
db4-utils_files += "/usr/bin/db_printlog"
db4-utils_files += "/usr/bin/db_recover"
db4-utils_files += "/usr/bin/db_sql"
db4-utils_files += "/usr/bin/db_stat"
db4-utils_files += "/usr/bin/db_upgrade"
db4-utils_files += "/usr/bin/db_verify"
db4-utils_files += "/usr/bin/db_hotbackup"

db4_files = ""
db4_files += "db4.manifest"
db4_files += "/usr/lib/libdb-4.8.so"
db4_files += "/usr/lib/libdb_cxx-4.8.so"

db4-devel_files = ""
db4-devel_files += "db4.manifest"
db4-devel_files += "/usr/include/db4"
db4-devel_files += "/usr/include/db.h"
db4-devel_files += "/usr/include/db_185.h"
db4-devel_files += "/usr/include/db_cxx.h"
db4-devel_files += "/usr/include/db4/db.h"
db4-devel_files += "/usr/include/db4/db_185.h"
db4-devel_files += "/usr/include/db4/db_cxx.h"
db4-devel_files += "/usr/lib/libdb.so"
db4-devel_files += "/usr/lib/libdb-4.so"
db4-devel_files += "/usr/lib/libdb_cxx.so"
db4-devel_files += "/usr/lib/libdb_cxx-4.so"

FILES_${PN}-doc = "${db4-doc_files}"
FILES_${PN}-utils = "${db4-utils_files}"
FILES_${PN} = "${db4_files}"
FILES_${PN}-devel = "${db4-devel_files}"

PKG_db4-doc= "db4-doc"
PKG_db4-utils= "db4-utils"
PKG_db4= "db4"
PKG_db4-devel= "db4-devel"

require db4-extraconf.inc
