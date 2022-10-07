#!/usr/bin/env python							        // "shebang" - operating system know that this is a Python file, and that it should be passed to the Python interpreter.

import rospy
from std_msgs.msg import Int32						// std_msgs - ROS standard message package

rospy.init_node('publisher_node')

pub = rospy.Publisher('topic_name', Int32)

rate = rospy.Rate(2)							        // want to publish(Hz)

count = 0
while not rospy.is_shutdown():						// function will return True if the node is ready to be shut down
	pub.publish(count)
	count += 1
	rate.sleep()
