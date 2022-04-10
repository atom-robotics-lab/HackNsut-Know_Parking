#! /usr/bin/env python3

import rospy
from parking_detector.msg import Booking
from std_msgs.msg import Int32

class Robot_Controller:
    #initialised values
    def __init__(self):

        rospy.init_node('barrier_controller')
        rospy.Subscriber('/parking_booking', Booking, self.open_barrier)
        down = Int32()
        down.data = 0       
    
    def open_barrier(self, data):

        self.pub = rospy.Publisher('/parking_barrier/Rev1_position_controller/command' + str(data.parking_space), Booking, queue_size=10)
        self.pub.Publish(down)
        

if __name__ == "__main__":
    Robot = Robot_Controller()
    rospy.spin()