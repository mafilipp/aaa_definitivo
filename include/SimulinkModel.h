#ifndef SIMULINK_MODEL_H_		
#define SIMULINK_MODEL_H_

#include "ros/ros.h"
#include "simulink_model.h"

// message include

#include "aaa_definitivo/DoubleArrayStamped.h"
#include "aaa_definitivo/controller_out.h" 
#include "aaa_definitivo/waypoint.h" 


class SimulinkModel
{
    public:
        SimulinkModel();
        ~SimulinkModel();

    private:
        void state_Callback(const aaa_definitivo::DoubleArrayStamped & state);
        void waypoint_Callback(const aaa_definitivo::waypoint & waypoint);
 
        ros::NodeHandle nh_;
        ros::Subscriber sub_state_estimation;
	ros::Subscriber sub_waypoint;
        ros::Publisher  pub_MAVLink_node;

};

#endif /*SIMULINK_MODEL_H_*/



