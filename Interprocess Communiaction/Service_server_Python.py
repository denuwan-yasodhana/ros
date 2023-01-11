#!/usr/bin/env python

import rospy
from service_file.srv import WordCount, WordCountResponse             // WordCount is service counts the number of words in a String
							                                                        // This means that the input to the service call should be a String and the output should be an Integer

def count_words(request):					                                    // Takes a single argument of type WordCountRequest and returns a single argument of type WordCountResponse
	return WordCountResponse(len(request.words.split()))	

	return [ len(request.words.split()) ]			                          // Tuple or list
	return { "count" : len(request.words.split()) }		                  // Dictionary		
	

rospy.init_node("Service_Server")				                              // Initializing the node

service = rospy.Service("Topic_name", WordCount, count_words)	

rospy.spin()						                                              // Exits when the node is ready to shutdown
