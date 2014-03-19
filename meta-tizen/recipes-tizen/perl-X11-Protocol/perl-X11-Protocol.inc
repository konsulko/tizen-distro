DESCRIPTION = "Perl module for the X Window System Protocol, version 11"
HOMEPAGE = "http://search.cpan.org/dist/X11-Protocol/"
SECTION = "Development/Libraries/Perl"
LICENSE = "GPL-1.0+ or Artistic-1.0"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "perl-X11-Protocol"

perl-X11-Protocol_files = ""
perl-X11-Protocol_files += "perl-X11-Protocol.manifest"

FILES_${PN} = "${perl-X11-Protocol_files}"

PKG_perl-X11-Protocol= "perl-X11-Protocol"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require perl-X11-Protocol-rdepends.inc
require perl-X11-Protocol-depends.inc
require perl-X11-Protocol-extraconf.inc
