#!/usr/bin/python

import dbus
import dbus.service
import os

KBD_NAME = 'com.konsulko.m2p.Keypad'
states = ['Released: ', 'Pressed : ']
keys = ['Mute',
	'Back',
	'VolumeUp',
	'VolumeDown',
	'Map',
	'Phone',
	'TrackDown',
	'TrackUp']

# You must initialize the gobject/dbus support for threading
# before doing anything.
import gobject
gobject.threads_init()

os.environ["DBUS_SESSION_BUS_ADDRESS"] = "tcp:host=10.0.0.1,port=12330"

from dbus import glib
glib.init_threads()

from dbus.mainloop.glib import DBusGMainLoop
DBusGMainLoop(set_as_default=True)

# Create a session bus.
bus = dbus.SessionBus()

kbd = bus.get_object(KBD_NAME, '/')

for key, name in enumerate(keys):
#	state = kbd.Get(KBD_NAME, name, dbus_interface=dbus.PROPERTIES_IFACE)
	state = kbd.Get(KBD_NAME, name)
	print states[state] + name
