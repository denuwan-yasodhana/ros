#include "ros/ros.h"
#include "package_name/Service_file_name.h"

bool calculation(package_name::Service_file_name::Request &req, 
		package_name::Service_file_name::Response &res)
{
	res.result = req.a + req.b;

	ROS_INFO("Request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
	ROS_INFO("Sending back Response: %ld", (long int)res.result);	

	return true;
}

int main(int argc, char **argv) 
{
	ros::init(argc, argv, "service_server_node"); 
	ros::NodeHandle nh; 

	ros::ServiceServer srv_server = nh.advertiseService("service_name", calculation);

	ROS_INFO("Ready Service Server!");

	ros::spin(); 									// Wait for the service request
 	return 0;
}
