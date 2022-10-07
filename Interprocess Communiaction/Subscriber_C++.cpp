#include "ros/ros.h"
#include "package_name/Msg_file_name.h"

void msgCallback(const package_name::Msg_file_name::ConstPtr& msg)		              // This is a function is called when a topic message named 'topic_name' is received.
{										                                                                // ConstPtr - Shared pointer to a constant message, & - pass by reference
	ROS_INFO("Recieve msg = %d", msg->stamp.sec);
	ROS_INFO("Recieve msg = %d", msg->stamp.nsec);
	ROS_INFO("Recieve msg = %d", msg->data); 
}


int main(int argc, char **argv) 
{
	ros::init(argc, argv, "subscriber_node"); 
	ros::NodeHandle nh;

	ros::Subscriber sub = nh.subscribe("topic_name", 100, msgCallback);	              // size of the publisher queue is set to 100,  calling a callback function

	ros::spin(); 								                                                      // waiting for a message to be received, and executing a callback function when it is received 

	return 0;

}
