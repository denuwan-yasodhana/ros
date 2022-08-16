# Step by Step

## In package.xml file

After creating package then change `package.xml` file details		

        <name>, <version>, <description>, <license>, <author>, <maintainer>, <url>     # I can change it as I want.
        <buildtool_depend>    # Check build system of ROS
        <build_depend>        # Check build dependent packages
        <run_depend>          # Check runtime dependent packages

## In CMakeList.txt file

In `CMakeList.txt` file change, Check

    - project(name)  
	- find_package()							-> add build system and dependencies 			# components of package required
	- add_message_files() / add_action_files() / add_service_files()	-> add .msg file					# Declaration
	- generate_messages()							-> enable function					# Message dependency 
	- catkin_package()							-> enable function
	- include directories()							-> enable function

	- add_executable()		# for publisher
	- add_dependencies()		# for publisher 
	- target_link_libraries()	# for publisher

	- add_executable()		# for subscriber
	- add_dependencies()		# for subscriber
	- target_link_libraries()	# for subscriber

