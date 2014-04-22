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
  logger.debug(1, 'p.communicate returned:\nout =\n"%s"\nerr =\n"%s"' % (out, err))
 
  os.unlink(f.name)

  logger.debug(1, '*** Leave create_smackrules() ***')


def apply_smackrules(d):

  logger.debug(1, '*** Enter apply_smackrules() ***')

  D=d.expand('${T}/mountdir')
  DEPLOY_DIR_IMAGE=d.expand('${DEPLOY_DIR_IMAGE}')
  IMAGE_NAME=d.expand('${IMAGE_NAME}')
  
  logger.debug(1, 'D = %s' % D)
  logger.debug(1, 'IMAGE_NAME = %s.rootfs.ext3' % IMAGE_NAME)
  logger.debug(1, 'DEPLOY_DIR_IMAGE = %s' % DEPLOY_DIR_IMAGE)

  command="#!/bin/bash\n"
  command+="export D=%s\n" %  D
  command+="mkdir -p $D\n"
  command+="sudo mount %s/%s.rootfs.ext3 $D\n" % (DEPLOY_DIR_IMAGE, IMAGE_NAME)
  command+="chmod a+x %s/etc/smack/init_attr\n" %  D
  command+="sudo -E $D/etc/smack/init_attr\n"
  command+="sudo umount $D\n"
  command+="rm -rf $D\n"

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

  logger.debug(1, '*** Leave apply_smackrules() ***')
