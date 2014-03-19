DESCRIPTION = "An Interpreted Object-Oriented Scripting Language"
HOMEPAGE = "http://www.ruby-lang.org/"
SECTION = "Development/Languages/Ruby"
LICENSE = "BSD-2-Clause or Ruby"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by ruby-devel 
PROVIDES += "ruby-devel"
RPROVIDES_ruby-devel += "ruby-devel"
RPROVIDES_ruby-devel += "ruby-dev"
# the PROVIDES rules is ignore "rubygems19 = 1.3.7"
PROVIDES += "rubygems19"
RPROVIDES_ruby-devel += "rubygems19"
# the PROVIDES rules is ignore "rubygems19_with_buildroot_patch  "
PROVIDES += "rubygems19_with_buildroot_patch"
RPROVIDES_ruby-devel += "rubygems19_with_buildroot_patch"

#PROVIDES by ruby-examples 
PROVIDES += "ruby-examples"
RPROVIDES_ruby-examples += "ruby-examples"

#PROVIDES by ruby-doc-ri 
PROVIDES += "ruby-doc-ri"
RPROVIDES_ruby-doc-ri += "ruby-doc-ri"

#PROVIDES by ruby-test-suite 
PROVIDES += "ruby-test-suite"
RPROVIDES_ruby-test-suite += "ruby-test-suite"

#PROVIDES by ruby-doc-html 
PROVIDES += "ruby-doc-html"
RPROVIDES_ruby-doc-html += "ruby-doc-html"

#PROVIDES by ruby 
PROVIDES += "ruby"
RPROVIDES_ruby += "ruby"
# the PROVIDES rules is ignore "rubygem-rake = 0.9.2.2"
PROVIDES += "rubygem-rake"
RPROVIDES_ruby += "rubygem-rake"
# the PROVIDES rules is ignore "ruby(abi) = 1.9.1"
PROVIDES += "ruby(abi)"
RPROVIDES_ruby += "ruby(abi)"

RDEPENDS = ""
#RDEPENDS of ruby-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "ruby"

#RDEPENDS of ruby-examples (${PN}-examples)
RDEPENDS_${PN}-examples += "ruby"

#RDEPENDS of ruby-doc-ri (${PN}-doc-ri)
RDEPENDS_${PN}-doc-ri += "ruby"

#RDEPENDS of ruby-test-suite (${PN}-test-suite)
RDEPENDS_${PN}-test-suite += "ruby"

#RDEPENDS of ruby-doc-html (${PN}-doc-html)
RDEPENDS_${PN}-doc-html += "ruby"


DEPENDS = ""
#DEPENDS of ruby 
DEPENDS += "zlib-devel"
DEPENDS += "ncurses"
DEPENDS += "openssl"
DEPENDS += "libyaml-devel"
DEPENDS += "ca-certificates"
DEPENDS += "libffi"
DEPENDS += "gdbm"
DEPENDS += "readline"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n ruby-1.9.3-p448
 cp ${S}/packaging/ruby.manifest .
 
 find sample -type f -print0 | xargs -r0 chmod a-x
 grep -Erl '^#! */' benchmark bootstraptest ext lib sample test \
   | xargs -r perl -p -i -e 's|^#!\s*\S+(\s+.*)?$|#!/usr/bin/ruby1.9$1|'
 
 
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
   --target=x86_64-tizen-linux \
   --with-mantype=man \
   --enable-shared \
   --disable-static \
   --disable-rpath
 oe_runmake all V=1
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f -- V=1
 /bin/install -D -m 0644 ${S}/packaging/ruby.macros ${D}/etc/rpm/macros.ruby19
 /bin/install -D -m 0755 ${S}/packaging/gem_install_wrapper.sh ${D}/usr/lib/rpm/gem_install_wrapper.sh
 
 
 
}

PACKAGES = ""
PACKAGES += "ruby-doc-ri"
PACKAGES += "ruby"
PACKAGES += "ruby-devel"

ruby-doc-ri_files = ""
ruby-doc-ri_files += "ruby.manifest"
ruby-doc-ri_files += "/usr/share/ri/"
ruby-doc-ri_files += "/usr/share/ri/1.9.1/"

ruby_files = ""
ruby_files += "ruby.manifest"
ruby_files += "/etc/rpm/macros.ruby19"
ruby_files += "/usr/bin/erb"
ruby_files += "/usr/bin/gem"
ruby_files += "/usr/bin/irb"
ruby_files += "/usr/bin/rake"
ruby_files += "/usr/bin/rdoc"
ruby_files += "/usr/bin/ri"
ruby_files += "/usr/bin/ruby"
ruby_files += "/usr/bin/testrb"
ruby_files += "/usr/lib/libruby.so.1.9*"
ruby_files += "/usr/lib/ruby/"
ruby_files += "/usr/lib/rpm/gem_install_wrapper.sh"
ruby_files += "/usr/share/man/man1/ri.1*"
ruby_files += "/usr/share/man/man1/irb.1*"
ruby_files += "/usr/share/man/man1/erb.1*"
ruby_files += "/usr/share/man/man1/rake.1*"
ruby_files += "/usr/share/man/man1/ruby.1*"
ruby_files += "COPYING  COPYING.ja  GPL"

ruby-devel_files = ""
ruby-devel_files += "ruby.manifest"
ruby-devel_files += "/usr/include/ruby-1.9.1"
ruby-devel_files += "/usr/lib/libruby.so"
ruby-devel_files += "/usr/lib/pkgconfig/ruby-1.9.pc"

FILES_${PN}-doc-ri = "${ruby-doc-ri_files}"
FILES_${PN} = "${ruby_files}"
FILES_${PN}-devel = "${ruby-devel_files}"

PKG_ruby-doc-ri= "ruby-doc-ri"
PKG_ruby= "ruby"
PKG_ruby-devel= "ruby-devel"

require ruby-extraconf.inc
