#!/usr/bin/env python

import rospy
from std_msgs.msg import Int32

def callback(msg):					                                    // handles the messages as they come in	
	print msg.data					                                      // display counts

rospy.init_node('subscriber_node')

sub = rospy.Subscriber('topic_name', Int32, callback)		

rospy.spin()						                                        // this function will only return when the node is ready to shut down





