#!/usr/bin/env python

import rospy
from service_file.srv import WordCount
import sys

rospy.init_node("Service_Client")

rospy.wait_for_service("Topic_name")				                              //  Wait for the service to be advertised by the server

word_counter = rospy.ServiceProxy("Topic_name", WordCount)	              //  Set up a local proxy for it

words = " ".join(sys.argv[1:])
word_count = word_counter(words)				                                  //  Topic of the service (word_count) and the type (WordCount)

print words, " -> ", word_count.count
