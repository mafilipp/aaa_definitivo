#include "SimulinkModel.h"


SimulinkModel::SimulinkModel()
{
    sub_state_estimation = nh_.subscribe("/ssf_core/state_out", 1000, &SimulinkModel::state_Callback, this);
    sub_waypoint         = nh_.subscribe("/waypoint", 1000, &SimulinkModel::waypoint_Callback, this);
    
    pub_MAVLink_node     = nh_.advertise<aaa_definitivo::controller_out>("/to_MAVLink_node", 1000); 

}

SimulinkModel::~SimulinkModel()
{
}

void SimulinkModel::waypoint_Callback(const aaa_definitivo::waypoint & waypoint)

{


// set setpoint
	simulink_model_U.waypoint_x   = waypoint.waypoint_x;
	simulink_model_U.waypoint_y   = waypoint.waypoint_y;
	simulink_model_U.waypoint_z   = waypoint.waypoint_z;
	simulink_model_U.waypoint_psi = waypoint.waypoint_psi;

/**************************************************************************************************************/ //chiedere Kosta se vale la pena fare 
        aaa_definitivo::controller_out outMsg; 
//message info																	così o se posso lasciare sto pezzo via, vesto che la frequenza sarà
																					//nettamente minore...	non vorrei che si cancellassero a 
																					//vicenda..				
	ros::Time scan_time = ros::Time::now();
	outMsg.header.stamp=scan_time;
	outMsg.header.frame_id="/to_MAVLink_node";

        simulink_model_step();

//set output
        outMsg.set_thrust = simulink_model_Y.set_thrust;
        outMsg.set_phi    = simulink_model_Y.set_phi;
        outMsg.set_theta  = simulink_model_Y.set_theta;
        outMsg.set_psi    = simulink_model_Y.set_psi;

        pub_MAVLink_node.publish(outMsg);
/**************************************************************************************************************/
}  

void SimulinkModel::state_Callback(const aaa_definitivo::DoubleArrayStamped & state) 
{
   
    aaa_definitivo::controller_out outMsg; 

//message info

	ros::Time scan_time = ros::Time::now();
	outMsg.header.stamp=scan_time;
	outMsg.header.frame_id="/to_MAVLink_node";

// set position

    simulink_model_U.x = state.data[0];
    simulink_model_U.y = state.data[1];
    simulink_model_U.z = state.data[2];

// set velocities

    simulink_model_U.dx = state.data[3];
    simulink_model_U.dy = state.data[4];
    simulink_model_U.dz = state.data[5];

// set quaternion

    simulink_model_U.q0 = state.data[7];
    simulink_model_U.q1 = state.data[8];
    simulink_model_U.q2 = state.data[9];
    simulink_model_U.q3 = state.data[6];  //controlla!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


    simulink_model_step();

//set output

    outMsg.set_thrust = simulink_model_Y.set_thrust;
    outMsg.set_phi    = simulink_model_Y.set_phi;
    outMsg.set_theta  = simulink_model_Y.set_theta;
    outMsg.set_psi    = simulink_model_Y.set_psi;


   pub_MAVLink_node.publish(outMsg);
}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "simulink_model");

  ROS_INFO("Communication from Vicon-Simulink-node to ros_MAVLink node");

  simulink_model_initialize();

  SimulinkModel sim;
  
  ros::spin();

  simulink_model_terminate();

  return 0;
}
