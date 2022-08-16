# Step by Step

## In package.xml file

After creating package then change `package.xml` file details		

        <name>, <version>, <description>, <license>, <author>, <maintainer>, <url>     # I can change it as I want.
        <buildtool_depend>    # Check build system of ROS
        <build_depend>        # Check build dependent packages
        <run_depend>          # Check runtime dependent packages

## In CMakeList.txt file

In `CMakeList.txt` file change, Check

        project(name)                                                     # If you changed the project name in the `package.xml` file, change it here as well. 
	find_package()                                                    # Check or Add has required build system and all dependencies 
	add_message_files() / add_action_files() / add_service_files()    # Declaration .msg or .srv or .action file
	generate_messages()					   	    # Enable Message dependency 
	catkin_package()		                                    # Enable function
	include directories()						    # Enable function

	##### If Publisher & Subscriber nodes
	
	
