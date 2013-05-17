#ifndef SIMULINK_MODEL_H_		
#define SIMULINK_MODEL_H_


#include <math.h>

 // ======= general include
#include "ros/ros.h"
#include "controller_simulink.h"
#include "tf/transform_datatypes.h"
#include "LinearMath/btMatrix3x3.h"

 // ======= dynamic reconfigure
#include <dynamic_reconfigure/server.h>
#include <sl_controller/reconfigureConfig.h>


 // ======= Include Messages


 // == State
#include "sl_controller/AngleMeasStamped.h"
#include "sl_controller/ext_state.h"
#include "sl_controller/waypoint.h" 
#include "std_msgs/Float64.h"

 // == Publish
#include "sl_controller/control_message.h" 
#include "sl_controller/output.h" 
#include "sl_controller/psi_debugging.h" 




class SimulinkModel
{
    public:
        SimulinkModel();
        ~SimulinkModel();

// == Dynamic reconfigure Callback
	void dynamic_callback(sl_controller::reconfigureConfig &config, uint32_t level);

// == Step
	void step();

// == Debugging
	void publish_output(); 
	void publish_psi_debugging(); 


 // ======= Global variable

	// == frequency HLC (doesn't work at the moment)
	int freq_global;

	// == Battery voltage
	double voltage_is[250];
	int i;

	// == Battery type
	double battery_mAh;

	// == Load weight
	double load_weight;

	double waypoint_z_thrust;

	int power_supply;

// ======= PID load

// z PID controller
	double load_thrust_K_P;
	double load_thrust_K_I;
	double load_thrust_K_D;

	double load_thrust_max_P;
	double load_thrust_max_I;
	double load_thrust_max_D;
	double load_thrust_max_PID;

// Cross Position P controller
	double load_cross_pos_K_P;
	double load_cross_pos_max_P;

//Cross Rate PD controller
	double load_cross_rate_K_P;
	double load_cross_rate_K_D;

	double load_cross_rate_max_P;
	double load_cross_rate_max_D;
	double load_cross_rate_max_PD;

//Along Position P controller
	double load_along_pos_K_P;
	double load_along_pos_max_P;

//Along Rate PD controller
	double load_along_rate_K_P;
	double load_along_rate_K_D;
	double load_along_rate_max_P;
	double load_along_rate_max_D;
	double load_along_rate_max_PD;

// ======= Slung Load special tuning

// Delayed Feedback control
	double df_N_Delay; 
	double df_G_d; 
	double df_l_L;
	double df_sign_ct;
	double df_sign_at;
	
// Input shaper
	
	double is_on;
	double is_N_impulses;
	double is_omega_ct;
	double is_omega_at;
	double is_zeta_ct;
	double is_zeta_at;


// test
	//double test1;
	//double test2;
	//double test3;



// ======= Initialization coordinate system

	double x_init;
	double y_init;
	double z_init;

	double x_true;
	double y_true;
	double z_true;

    private:

 // ======= Basic Callback
        void state_Callback(const sl_controller::ext_state & state);
        void waypoint_Callback(const sl_controller::waypoint & waypoint);
	void load_angles_Callback(const sl_controller::AngleMeasStamped & AngleMeasStamped);
	void hover_Callback(const std_msgs::Float64 & voltage);
	void yaw_APM_Callback(const std_msgs::Float64 & yaw_APM);

	int factorial(int x);
	double nchoosek(int n, int k);


 // ======= ROS Node
        ros::NodeHandle nh_;

 // ======= Subscriber

 // == State
        ros::Subscriber sub_state_estimation;
	ros::Subscriber sub_waypoint;
	ros::Subscriber sub_load_angles;
 // == Hover thrust
	ros::Subscriber sub_hover;
// == Yaw correction (drifting from APM)
	ros::Subscriber sub_yaw_APM;


 // ======= Pubisher
        ros::Publisher  pub_controller_out;
        ros::Publisher  pub_output;
        ros::Publisher  pub_psi_debugging;
};

#endif /*SIMULINK_MODEL_H_*/



