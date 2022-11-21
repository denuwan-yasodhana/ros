#include "ros/ros.h"
#include "package_name/Service_file_name.h"
#include <cstdlib>								                                      //  Library for using the "atoll" function

int main(int argc, char **argv) 
{
	ros::init(argc, argv, "service_client_node");
	
	if (argc != 3) 								                                        // input value error handling, get 2 inputs only
 	{
 		ROS_INFO("cmd : rosrun ros_tutorials_service service_client arg0 arg1");
 		ROS_INFO("Enter like arg0: double number, arg1: double number");
 		return 1;
 	}

	ros::NodeHandle nh; 
	
	ros::ServiceClient srv_client = nh.serviceClient<package_name::Service_file_name>("service_name");

	package_name::Service_file_name srv;

	srv.request.a = atoll(argv[1]);						                            // Parameters entered when the node is executed as a service request value are stored at 'a' and 'b'
 	srv.request.b = atoll(argv[2]);

	if (srv_client.call(srv))						                                  // If the request is accepted, display the response value
	{
		ROS_INFO("Send srv, srv.Request.a and b: %ld, %ld", (long int)srv.request.a, (long int)srv.request.b);
 		ROS_INFO("Receive srv, srv.Response.result: %ld", (long int)srv.response.result);
	}
	else
	{
		ROS_ERROR("Failed to call service service_name");		                // like ROS_INFO
		return 1;	
	}

	return 0;

}

