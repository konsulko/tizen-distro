import shlex
import subprocess as sub
import tempfile
import stat
import os

import logging
logger = logging.getLogger('BitBake.OE.Terminal')




def create_smackrules(d):

  D=d.expand('${WORKDIR}/rootfs')
  command="#!/bin/bash\n"
  command+="export D=%s\n" %  D
  command+="chmod a+x %s/etc/smack/init_attr\n" %  D
  command+="sudo -E %s/etc/smack/init_attr\n" %  D

  f = tempfile.NamedTemporaryFile(delete=False)
  f.write(command)
  os.chmod(f.name, 0777)
  f.close()

  splitted_command = shlex.split( str( f.name ) )
  bb.note("RLM run command:%s" % splitted_command)

  p = sub.Popen(splitted_command,stdout=sub.PIPE,stderr=sub.PIPE)
  out, err = p.communicate()
  os.unlink(f.name)