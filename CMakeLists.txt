cmake_minimum_required(VERSION 2.4.6)
include($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)

# Set the build type.  Options are:
#  Coverage       : w/ debug symbols, w/o optimization, w/ code-coverage
#  Debug          : w/ debug symbols, w/o optimization
#  Release        : w/o debug symbols, w/ optimization
#  RelWithDebInfo : w/ debug symbols, w/ optimization
#  MinSizeRel     : w/o debug symbols, w/ optimization, stripped binaries
#set(ROS_BUILD_TYPE RelWithDebInfo)
set(ROS_BUILD_TYPE RelWithDebInfo)

#ADD_DEFINITIONS("-std=c++0x") 

rosbuild_init()

#set(MATLAB_ROOT /usr/local/MATLAB/R2012a)
set(SIMULINK_OUTPUT_DIR /home/mafilipp/fuerte_workspace/sandbox/sl_controller/include/controller_simulink_ert_rtw)

#set the default path for built executables to the "bin" directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(SimulinkModel_SOURCES src/SimulinkModel.cpp src/dynamic_reconfigure.cpp)
#set the default path for built libraries to the "lib" directory
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

include_directories(${PROJECT_SOURCE_DIR}/include
	${SIMULINK_OUTPUT_DIR})
	



link_directories (${PROJECT_BINARY_DIR}/lib
	${SIMULINK_OUTPUT_DIR}) 

#uncomment if you have defined messages
rosbuild_genmsg() #modificato
#uncomment if you have defined services
#rosbuild_gensrv()

rosbuild_add_executable(sl_controller ${SimulinkModel_SOURCES})
#rosbuild_add_executable(sl_controller src/SimulinkModel.cpp)
#target_link_libraries(sl_controller -lz_controller_const)
target_link_libraries(sl_controller -lcontroller_simulink)

#target_link_libraries(simulink_model ${PROJECT_NAME})

#add dynamic reconfigure api
rosbuild_find_ros_package(dynamic_reconfigure)
include(${dynamic_reconfigure_PACKAGE_PATH}/cmake/cfgbuild.cmake)
gencfg()
