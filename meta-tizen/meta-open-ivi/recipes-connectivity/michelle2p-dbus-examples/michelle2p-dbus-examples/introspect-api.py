#!/usr/bin/python

import dbus
import dbus.service
import os
import sys

# You must initialize the gobject/dbus support for threading
# before doing anything.
import gobject
gobject.threads_init()

from dbus import glib
glib.init_threads()

os.environ["DBUS_SESSION_BUS_ADDRESS"] = "tcp:host=10.0.0.1,port=12330"
service = sys.argv[1]

# Create a session bus.
bus = dbus.SessionBus()

# Create an object that will proxy for a particular remote object.
remote_object = bus.get_object(service, # Connection name
                               "/" # Object's path
                              )

# Introspection returns an XML document containing information
# about the methods supported by an interface.
print ("Introspection data for %s:\n", service)
print remote_object.Introspect()
