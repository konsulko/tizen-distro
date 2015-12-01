#!/usr/bin/python

import dbus
import dbus.service
import os

KBD_NAME = 'com.konsulko.m2p.Keypad'
states = ['Released: ', 'Pressed : ']
keys = ['Mute',
	'Back',
	'Volume Up',
	'Volume Down',
	'Map',
	'Phone',
	'Track Down',
	'Track Up']

def handle_event(*args, **kwargs):
	print states[args[1]] + keys[args[0]]

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

bus.add_signal_receiver(handle_event,
 			signal_name="Event",
			path="/",
 			dbus_interface=KBD_NAME)

import gobject

loop = gobject.MainLoop()
loop.run()
