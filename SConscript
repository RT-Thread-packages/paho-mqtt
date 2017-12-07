Import('RTT_ROOT')
from building import *

# get current directory
cwd = GetCurrentDir()

# The set of source files associated with this SConscript file.
src = Glob('MQTTPacket/src/*.c')
src += Glob('MQTTClient-RT/*.c')

path = [cwd + '/MQTTPacket/src']
path += [cwd + '/MQTTClient-RT']

group = DefineGroup('paho-mqtt', src, depend = ['PKG_USING_PAHOMQTT'], CPPPATH = path)

Return('group')
