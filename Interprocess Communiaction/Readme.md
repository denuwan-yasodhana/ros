## Step 01 : Basic Setup

- Create `workspace` and `src` folder

		cd ~/catkin_ws/src

- Go to src and initialize workspace

		catkin_init_workspace
	
- Go back and build Catkin build system

		catkin_make
	
- Go to src and create package with dependent packages(roscpp, rospy, std_msgs, message_generation)

		catkin_create_pkg [PACKAGE_NAME] [DEPENDENT_PACKAGE_1] [DEPENDENT_PACKAGE_N]

- Go to package src, and make a `node`
	- C++
		- [Publisher Node](https://github.com/denuwan-yasodhana/ros/blob/main/Interprocess%20Communiaction/Publisher_C%2B%2B.cpp)
		- [Subscriber Node](https://github.com/denuwan-yasodhana/ros/blob/main/Interprocess%20Communiaction/Subscriber_C%2B%2B.cpp)
	- Python
		- [Publisher Node](https://github.com/denuwan-yasodhana/ros/blob/main/Interprocess%20Communiaction/Publisher_C%2B%2B.cpp)

## Step 02 : In package.xml file

After creating package then change `package.xml` file details		

        <name>, <version>, <description>, <license>, <author>, <maintainer>, <url>     # I can change it as I want.
        <buildtool_depend>    # Check build system of ROS
        <build_depend>        # Check build dependent packages
        <run_depend>          # Check runtime dependent packages

## Step 03 : In CMakeList.txt file

In `CMakeList.txt` file change, Check

        project(name)                                                     	# If you changed the project name in the `package.xml` file, change it here as well. 
	find_package()                                                    	# Check or Add has required build system and all dependencies (Action has 2 find_package() to enable)
	add_message_files() / add_action_files() / add_service_files()    	# Declaration .msg or .srv or .action file
	generate_messages()					   	    	# Enable Message dependency 
	catkin_package()		                                    	# Enable function
	include directories()						    	# Enable function

	##### If Publisher & Subscriber nodes
	
	add_executable()													# for publisher
	add_dependencies(publisher_node_name ${publisher_node_name_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})		# for publisher 
	target_link_libraries()													# for publisher

	add_executable()													# for subscriber
	add_dependencies(subscriber_node_name ${subscriber_node_name_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})		# for subscriber
	target_link_libraries()													# for subscriber
	
	##### If Client & Server nodes
	
	add_executable()													# for server
	add_dependencies(server_node_name ${server_node_name_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})			# for server 
	target_link_libraries()													# for server

	add_executable()													# for client
	add_dependencies(client_node_name ${client_node_name_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})			# for client
	target_link_libraries()													# for client
	
	##### If Action Client & Action Server nodes
	
	add_executable()													# for action server
	add_dependencies(server_node_name ${server_node_name_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})			# for action server 
	target_link_libraries()													# for action server

	add_executable()													# for action client
	add_dependencies(client_node_name ${client_node_name_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})			# for action client
	target_link_libraries()													# for action client
	
	
## Step 04 : In message / service / action file

Data types : ‘bool’, ‘int8’, ‘int16’, 'int32', 'int64', ‘float32’, 'float64', ‘string’, ‘time’, ‘duration’

##### Message.msg

	time stamp
	int32 data
	
##### Service.srv

	int64 a 			# Service request
	int64 b 
	---
	int64 result			# Service response
	
##### Action.action

	
	int32 order			# Action request
	---
	int32[] sequence		# Action response
	---
	int32[] sequence		# Action feedback
	
## Step 05 : Finally, run Nodes

- Open 	`first terminal` 
	
		source /opt/ros/noetic/setup.bash
		Go to workspace then, catkin_make

i. Check configuration output files in /build

ii. Check executable files in /devel/lib/package_name

iii. Check message header files in /devel/include/package_name

- Open `second terminal`

		roscore
		
- Open `third terminal`

		source /opt/ros/noetic/setup.bash
		Go to workspace then, source devel/setup.bash
		rosrun package_name Publisher_node_name
		
- Open `first terminal`
		
		source devel/setup.bash
		rosrun package_name Subscriber_node_name
	
	
	
