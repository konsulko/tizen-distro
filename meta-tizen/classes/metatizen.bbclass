python () {
    if bb.data.inherits_class('rootfs_rpm', d):
        rootfsdepends = d.getVarFlag("do_rootfs", "depends", True)
        rootfsdepends = rootfsdepends.replace("rpmresolve-native:do_populate_sysroot", "")
        d.setVarFlag("do_rootfs", "depends", rootfsdepends)

    if bb.data.inherits_class('image-live', d):
        bootimgdepends = d.getVarFlag("do_bootimg", "depends", True)
        bootimgdepends = bootimgdepends.replace(d.expand("${INITRD_IMAGE}:do_rootfs"), "")
        d.setVarFlag("do_bootimg", "depends", bootimgdepends)
        d.setVar("INITRD_IMAGE", "")
        d.setVar("INITRD", "")
}

DIRFILES = "1"
RPM_EXTRA_PKGDATA = "1"

def package_rpm_extra_pkgdata(splitname, spec_file, d):
    if d.getVar('MANIFESTFILES', True):
        spec_file.append('%%manifest %s' % (d.getVar('MANIFESTFILES', True)))

python tizen_copy_manifest () {
    dest = d.getVar('S', True)
    dvar = d.getVar('PKGDEST', True)

    # Start by package population by taking a copy of the installed
    # files to operate on
    # Preserve sparse files and hard links
    cmd = 'cp %s/*.manifest %s' % (dest, dvar)
    (retval, output) = oe.utils.getstatusoutput(cmd)
    if retval:
        bb.fatal("file copy failed with exit code %s (cmd was %s)%s" % (retval, cmd, ":\n%s" % output if output else ""))
}
