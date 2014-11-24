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

# MANIFESTFILES_<pn> is the Tizen Smack .manifest file to be used for a binary .rpm.
# It must be part of the source tree (either at the root or in a sub-directory)
# or get created there during configure. Out-of-tree compilation is not supported.

# Enable extra code for the binary .rpm spec files which injects the %manifest
# lines for each package.
RPM_EXTRA_PKGDATA = "1"
def package_rpm_extra_pkgdata(splitname, spec_file, d):
    if d.getVar('MANIFESTFILES', True):
        # Must use .manifest files at the location where tizen_copy_manifest() put it.
        spec_file.append('%%manifest ../packages-split/%s' % (d.getVar('MANIFESTFILES', True)))
    else:
        fetch = bb.fetch2.Fetch([], d)
        for url in fetch.urls:
            local = fetch.localpath(url)
            base = os.path.basename(local)
            if base.endswith('.manifest.in'):
                manifest = base[:-3]
            else:
                manifest = base
            if manifest.endswith('.manifest'):
                 urldata = fetch.ud[url]
                 if 'pkg' in urldata.parm:
                     pkg = urldata.parm['pkg'].split(',')
                     enabled = splitname in pkg or not pkg
                 else:
                     enabled = True
                 if enabled:
                     # Optionally replace placeholders with content of the corresponding variables,
                     # otherwise just copy to a place where rpm can find it. Absolute paths
                     # refering to a file on the host do not work, because rpm interprets them
                     # relative to the build dir.
                     content = open(local).read()
                     if base != manifest:
                         import re
                         def replace(m):
                             word = m.group(1)
                             # Must be a known variable.
                             return d.getVar(word, True)
                         content = re.sub('@([a-zA-Z0-9_]+)@', replace, content)
                     # Create relative to _builddir = $S, see package_rpm.bbclass/do_package_rpm ().
                     dvar = d.getVar('S', True)
                     copy = os.path.join(dvar, manifest)
                     print '***', copy
                     if not os.path.exists(dvar):
                         os.makedirs(dvar)
                     f = open(copy, 'w')
                     f.write(content)
                     f.close()
                     spec_file.append('%%manifest %s' % manifest)
                     break

# Copies manifest files from source to packages-split. Necessary because
# source is not always available during packaging (for example, when
# using sstate), only $PKGDEST is.
PACKAGESPLITFUNCS_append = " tizen_copy_manifest"
python tizen_copy_manifest () {
    dest = d.getVar('S', True)
    dvar = d.getVar('PKGDEST', True)

    packages = d.getVar('PACKAGES', True)
    for pkg in packages.split():
        manifest_path=d.getVar('MANIFESTFILES_%s' % pkg, True)
        if manifest_path:
            manifest_dir = os.path.dirname(manifest_path)

            if manifest_dir:
                cmd = 'mkdir -p %s/%s' % (dvar,manifest_dir)
                (retval, output) = oe.utils.getstatusoutput(cmd)
                if retval:
                    bb.fatal("directory failed to be created with exit code %s (cmd was %s)%s" % (retval, cmd, ":\n%s" % output if output else ""))

            cmd = 'cp %s/%s %s/%s' % (dest, manifest_path , dvar,manifest_dir)

            (retval, output) = oe.utils.getstatusoutput(cmd)
            if retval:
                bb.fatal("file copy failed with exit code %s (cmd was %s)%s" % (retval, cmd, ":\n%s" % output if output else ""))
}
