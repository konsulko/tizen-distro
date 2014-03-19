DESCRIPTION = "An ELF Prelinking Utility"
HOMEPAGE = "http://people.redhat.com/jakub/prelink/"
SECTION = "System/Base"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by prelink 
PROVIDES += "prelink"
RPROVIDES_prelink += "prelink"

#PROVIDES by prelink-docs  
PROVIDES += "prelink-docs "
RPROVIDES_prelink-docs  += "prelink-docs "

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of prelink 
DEPENDS += "gcc-cross"
DEPENDS += "libelf0"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n prelink
 cp ${S}/packaging/prelink.manifest .
 
 
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
 
 # This package failed when testing with -Wl,-as-needed being default.
 # So we disable it here, if you want to retest, just delete this comment and the line below.
 export LD_AS_NEEDED=0
 # Uninitialized memory in dynamic loader in ifunc3 test.
 export -n MALLOC_PERTURB_
 unset MALLOC_PERTURB_
 
 CFLAGS="$RPM_OPT_FLAGS" \
 ./configure --prefix=/usr --mandir=/usr/share/man || cat config.log
 make -j16
 
 exit 0
 make -C testsuite check-harder
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 make install DESTDIR=$RPM_BUILD_ROOT
 mkdir -p $RPM_BUILD_ROOT/etc
 sed -e "s,LIBDIR,lib," ${S}/packaging/prelink.conf > $RPM_BUILD_ROOT/etc/prelink.conf
 mkdir -p $FILLUP_DIR $RPM_BUILD_ROOT/sbin/conf.d
 install -m 0755 -d $RPM_BUILD_ROOT/var/lib/prelink
 mkdir -p $RPM_BUILD_ROOT/etc/rpm
 cat > $RPM_BUILD_ROOT/etc/rpm/macros.prelink <<EOF
 # rpm-4.1 verifies prelinked libraries using a prelink undo helper.
 #       Note: The 2nd token is used as argv[0] and "library" is a
 #       placeholder that will be deleted and replaced with the appropriate
 #       library file path.
 %__prelink_undo_cmd     /usr/sbin/prelink prelink -y library
 EOF
 
 
 
 
}

PACKAGES = ""
PACKAGES += "prelink"
PACKAGES += "prelink-docs"

prelink_files = ""
prelink_files += "prelink.manifest"
prelink_files += "/var/lib/prelink"
prelink_files += "/etc/rpm"
prelink_files += "/etc/prelink.conf"
prelink_files += "/etc/rpm/macros.prelink"
prelink_files += "/usr/sbin/prelink"
prelink_files += "/usr/bin/execstack"

prelink-docs_files = ""
prelink-docs_files += "/usr/share/info"
prelink-docs_files += "/usr/share/man"

FILES_${PN} = "${prelink_files}"
FILES_${PN}-docs = "${prelink-docs_files}"

PKG_prelink= "prelink"
PKG_prelink-docs= "prelink-docs"

require prelink-extraconf.inc
