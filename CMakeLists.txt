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

set(MATLAB_ROOT /usr/local/MATLAB/R2012a)
set(SIMULINK_OUTPUT_DIR /home/mafilipp/Dropbox/MATLAB/aaa_definitivo/simulink_model_grt_rtw)

#set the default path for built executables to the "bin" directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#set the default path for built libraries to the "lib" directory
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

include_directories(${PROJECT_SOURCE_DIR}/include
	${SIMULINK_OUTPUT_DIR}
	${MATLAB_ROOT}/simulink/include
	${MATLAB_ROOT}/extern/include
	${MATLAB_ROOT}/rtw/c/src
	${MATLAB_ROOT}/rtw/c/src/ext_mode/common)


 





link_directories (${PROJECT_BINARY_DIR}/lib
	${SIMULINK_OUTPUT_DIR}) 

#uncomment if you have defined messages
rosbuild_genmsg() #modificato
#uncomment if you have defined services
#rosbuild_gensrv()

rosbuild_add_executable(aaa_definitivo src/SimulinkModel.cpp)
target_link_libraries(aaa_definitivo -lsimulink_model)

#target_link_libraries(simulink_model ${PROJECT_NAME})


