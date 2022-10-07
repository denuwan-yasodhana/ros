#include "ros/ros.h"					
#include "package_name/Msg_file_name.h"			

int main(int argc, char **argv) 
{
	ros::init(argc, argv, "publisher_node");
	ros::NodeHandle nh;										// Node handle declaration for communication with ROS system

	ros::Publisher pub = nh.advertise<package_name::Msg_file_name>("topic_name", 100);		// size of the publisher queue is set to 100
	
	ros::Rate loop_rate(10);									// main loop repeats at 0.1s(10Hz) intervals

	package_name::Msg_file_name msg; 

	int count = 0; 
	while (ros::ok())
	{
		msg.stamp = ros::Time::now();				                                 // Save current time in the stamp of 'msg'
		msg.data = count; 					                                 // Save the the 'count' value in the data of 'msg'

		ROS_INFO("Send msg = %d", msg.stamp.sec); 		                                 // Print the 'stamp.sec' message
		ROS_INFO("Send msg = %d", msg.stamp.nsec);		                                 // nsecs - Duration
		ROS_INFO("Send msg = %d", msg.data); 

		pub.publish(msg);
		loop_rate.sleep(); 

		++count;
	}	

	return 0;
}
