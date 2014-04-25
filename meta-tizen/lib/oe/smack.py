import shlex
import subprocess as sub
import tempfile
import stat
import os
import sys

import logging
logger = logging.getLogger('BitBake.OE.Terminal')


def create_smackrules(d):

  logger.debug(1, '*** Enter create_smackrules() ***')

  D=d.expand('${WORKDIR}/rootfs')
  logger.debug(1, 'D = %s' % D)

  command="#!/bin/bash\n"
  command+="export D=%s\n" %  D
  command+="cd $D\n"
  command+="find . | xargs getfattr -h -n 'security.SMACK64' > $D/etc/smack/init_attr\n"

  f = tempfile.NamedTemporaryFile(delete=False)
  f.write(command)
  os.chmod(f.name, 0777)
  f.close()

  splitted_command = shlex.split( str( f.name ) )
  bb.note("RLM run command:%s" % splitted_command)

  p = sub.Popen(splitted_command,stdout=sub.PIPE,stderr=sub.PIPE)
  out, err = p.communicate()
  logger.debug(1, 'p.communicate returned:\nout =\n"%s"\nerr =\n"%s"' % (out, err))
 
  os.unlink(f.name)

  logger.debug(1, '*** Leave create_smackrules() ***')


def apply_smackrules(d):

  logger.debug(1, '*** Enter apply_smackrules() ***')

  # Neither mke2fs nor tar seem to be working with the xattrs
  #
  # Restore the smack xattrs using:
  #   setfattr -h --restore=./etc/smack/init_attr

  logger.debug(1, '*** Leave apply_smackrules() ***')
