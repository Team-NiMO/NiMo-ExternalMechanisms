#!/usr/bin/env python
import rospy
from std_msgs.msg import String
from act_pump.srv import service1, service1Response
import serial
ser=serial.Serial('/dev/ttyACM0',9600)

def handle_control_pumps(req):
    command=""
    if req.command == "pump1":
        # Activate pump 1
        command="pump1\n"
    elif req.command == "pump2":
        # Activate pump 2
        command="pump2\n"
    elif req.command == "pump3":
        # Activate pump 3q
        command="pump3\n"
    elif req.command == "pumpsoff":
        # Deactivate all pumps
        command="pumpsoff\n"
    else:
        return service1Response(False)
    ser.write(command.encode())
    return service1Response(True)

def pumps_server():
    rospy.init_node('pumps_control_server')
    s = rospy.Service('control_pumps', service1, handle_control_pumps)
    rospy.spin()

if __name__ == "__main__":
    pumps_server()
