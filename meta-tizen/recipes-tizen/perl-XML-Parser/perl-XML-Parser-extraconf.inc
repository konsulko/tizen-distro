# fix up sub MakeMaker project as arguments don't get propagated though
# see https://rt.cpan.org/Public/Bug/Display.html?id=28632
do_configure_append() {
	sed 's:--sysroot=.*\(\s\|$\):--sysroot=${STAGING_DIR_TARGET} :g' -i Makefile Expat/Makefile
	sed 's:^FULL_AR = .*:FULL_AR = ${AR}:g' -i Expat/Makefile
}