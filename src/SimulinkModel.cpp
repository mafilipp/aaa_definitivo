#include "SimulinkModel.h"

SimulinkModel::SimulinkModel()
{
 // ======= Basic Callback
    sub_state_estimation = nh_.subscribe("/ssf_core/ext_state", 1000, &SimulinkModel::state_Callback, this);
    sub_waypoint         = nh_.subscribe("/waypoint", 1000, &SimulinkModel::waypoint_Callback, this);
    sub_load_angles      = nh_.subscribe("/load_angles", 1000, &SimulinkModel::load_angles_Callback, this);
    sub_hover            = nh_.subscribe("/voltage", 1000, &SimulinkModel::hover_Callback, this);
    sub_yaw_APM          = nh_.subscribe("/yaw_APM", 1000, &SimulinkModel::yaw_APM_Callback, this);

 // ======= Publisher: desired attitude for the APM
    pub_controller_out = nh_.advertise<sl_controller::control_message>("from_simulink", 1000);

    pub_output = nh_.advertise<sl_controller::output>("output", 1000);

    pub_psi_debugging = nh_.advertise<sl_controller::psi_debugging>("psi_debugging", 1000);

 // ======= Global variable

	// == frequency HLC (doesn't work at the moment)
	freq_global = 30;

	// == Battery voltage
	i=0;

	// == Load weight
	load_weight = 0;

	power_supply = 0; //Default: wire

	waypoint_z_thrust = 0;

// ======= PID load

// z PID controller
	load_thrust_K_P = 0;
	load_thrust_K_I = 0;
	load_thrust_K_D = 0;

	load_thrust_max_P = 0;
	load_thrust_max_I = 0;
	load_thrust_max_D = 0;
	load_thrust_max_PID = 0;

// Cross Position P controller
	load_cross_pos_K_P = 0;
	load_cross_pos_max_P = 0;

//Cross Rate PD controller
	load_cross_rate_K_P = 0;
	load_cross_rate_K_D = 0;

	load_cross_rate_max_P = 0;
	load_cross_rate_max_D = 0;
	load_cross_rate_max_PD = 0;

//Along Position P controller
	load_along_pos_K_P = 0;
	load_along_pos_max_P = 0;

//Along Rate PD controller
	load_along_rate_K_P = 0;
	load_along_rate_K_D = 0;
	load_along_rate_max_P = 0;
	load_along_rate_max_D = 0;
	load_along_rate_max_PD = 0;


// ======= Slung Load special tuning

// Delayed Feedback control
	df_N_Delay = 0; 
	df_G_d = 0; 
	df_l_L = 0;
	df_sign_ct = 0;
	df_sign_at = 0;
	
// Input shaper

	is_on = 0;
	is_N_impulses = 0;
	is_omega_ct = 0;
	is_omega_at = 0;
	is_zeta_ct = 0;
	is_zeta_at = 0;


// test
	//test1 = 0;
	//test2 = 0;
	//test3 = 0;



// ======= Initialization coordinate system

	x_init = 0;
	y_init = 0;
	z_init = 0;

	x_true = 0;
   	y_true = 0;
   	z_true = 0;
}






 // ======= Basic Callback definition

 // == Destructor

SimulinkModel::~SimulinkModel()
{
}

 // == Waypoint_Callback

void SimulinkModel::waypoint_Callback(const sl_controller::waypoint & waypoint)

{

// == set setpoint

	controller_simulink_U.x_ref = waypoint.x_ref;
	controller_simulink_U.y_ref = waypoint.y_ref;
	controller_simulink_U.z_ref = waypoint.z_ref;
	controller_simulink_U.dz_ref   = waypoint.dz_ref;
	controller_simulink_U.v_ref = waypoint.v_ref;
	controller_simulink_U.number_path = waypoint.number_path;

// =  Thrust with wire

	waypoint_z_thrust = waypoint.z_ref + z_init;
	
}  

 // == State_Callback

void SimulinkModel::state_Callback(const sl_controller::ext_state & state) 
{
   


// == set position
    x_true = state.pose.position.x;
	y_true = state.pose.position.y;
	z_true = state.pose.position.z;

    controller_simulink_U.x = x_true - x_init;
    controller_simulink_U.y = y_true - y_init;
    controller_simulink_U.z = z_true - z_init;


// == set velocities
    controller_simulink_U.dx = state.velocity.x;
    controller_simulink_U.dy = state.velocity.y;
    controller_simulink_U.dz = state.velocity.z;



// == set quaternion
	geometry_msgs::Quaternion temp = state.pose.orientation;

	
	tf::Quaternion quat;
	double roll, pitch, yaw;
	tf::quaternionMsgToTF(temp, quat); //new quaternion of type tf
	tf::Matrix3x3(quat).getRPY(roll, pitch, yaw); // quaternion tranformed in rotation matrix and then transformed in roll, pitch, yaw

    controller_simulink_U.phi=roll;
    controller_simulink_U.theta=pitch;
    controller_simulink_U.psi=yaw;

}

 // == load_angles_Callback

void SimulinkModel::load_angles_Callback(const sl_controller::AngleMeasStamped & AngleMeasStamped)
{

	controller_simulink_U.roll_L = AngleMeasStamped.phi;
	controller_simulink_U.pitch_L = AngleMeasStamped.theta;

}

 // == hover_Callback

void SimulinkModel::hover_Callback(const std_msgs::Float64 & voltage)
{

	if (power_supply == 0)
	{

// hover Thrust = f(z, load_weight)

		controller_simulink_P.hover_thrust_Value = -8.848 * (waypoint_z_thrust+load_weight/80-0.12) * (waypoint_z_thrust+load_weight/80-0.12) + 							    69.81 * (waypoint_z_thrust+load_weight/80-0.12) + 458.1;   
		
	}
	else
	{

//frequency of the actual_hover_thrust setting: 2 Hz	
// Function based on measurement and a linear fitting

		voltage_is[i] = voltage.data;
	
		if (i >= 199)
		{
			double mean_voltage = 0;
			double actual_hover_thrust = 0;
	
			for (int a=0; a<200; a++)
			{
			mean_voltage += voltage_is[a]/200;
			}
			// Set hover_thrust
			if (power_supply == 1)	// 2200 mAh
			{	
				if (load_weight == 0)
					{
						//With 0g load:
						actual_hover_thrust = -52.2*mean_voltage*mean_voltage + 966.7*mean_voltage - 3881;
					}
					else
					{
						//With 200g load:
						actual_hover_thrust = -34.26*mean_voltage*mean_voltage + 602.8*mean_voltage -1936;
					}
			}
			else // power_supply == 2, i.e. 2700 mAh
			{	
				if (load_weight == 0)
					{
						//With 0g load:
						actual_hover_thrust = -42.36*mean_voltage*mean_voltage + 741.3*mean_voltage - 2596;
					}
					else
					{
						//With 200g load:
						actual_hover_thrust = -58.8*mean_voltage*mean_voltage + 1073*mean_voltage - 4185;
					}

			}
		i = -1;
		controller_simulink_P.hover_thrust_Value = actual_hover_thrust;
		}
		i++;
	}
}

 // == yaw_APM Callback

void SimulinkModel::yaw_APM_Callback(const std_msgs::Float64 & yaw_APM)
{

	controller_simulink_U.yaw_APM = yaw_APM.data;

}



 // ======= step function & publish

void SimulinkModel::step () {

// == step function: controller call

    controller_simulink_step();

//set output

    sl_controller::control_message outMsg; 
	outMsg.header.stamp = ros::Time::now();
	outMsg.header.frame_id = "from_simulink";
    outMsg.set_thrust = controller_simulink_Y.set_thrust;
    outMsg.set_phi  = controller_simulink_Y.set_phi;
    outMsg.set_theta = controller_simulink_Y.set_theta;
    outMsg.set_psi = controller_simulink_Y.set_psi;

	pub_controller_out.publish(outMsg);

}

// == publish z controller data 

void SimulinkModel::publish_output () {


//set output

    sl_controller::output outMsg; 
	outMsg.header.stamp = ros::Time::now();
	outMsg.header.frame_id = "output";

	outMsg.z_err = controller_simulink_Y.z_err;
    outMsg.p_action_thrust = controller_simulink_Y.p_action_thrust;
    outMsg.i_action_thrust = controller_simulink_Y.i_action_thrust;
    outMsg.d_action_thrust = controller_simulink_Y.d_action_thrust;

	outMsg.e_ct = controller_simulink_Y.e_ct;
    outMsg.df_delta_pos_ct = controller_simulink_Y.df_delta_pos_ct;
	outMsg.e_ct_feed = controller_simulink_Y.e_ct_feed;
	outMsg.des_cross_rate = controller_simulink_Y.des_cross_rate;
	outMsg.des_cross_rate_shaped = controller_simulink_Y.des_cross_rate_shaped;
    outMsg.df_delta_vel_ct = controller_simulink_Y.df_delta_vel_ct;
    outMsg.des_cross_rate_feed = controller_simulink_Y.des_cross_rate_feed;
    outMsg.cross_rate_is = controller_simulink_Y.cross_rate_is;
    outMsg.ct_p_action = controller_simulink_Y.ct_p_action; 
    outMsg.ct_d_action = controller_simulink_Y.ct_d_action;

	outMsg.e_at = controller_simulink_Y.e_at;
    outMsg.df_delta_pos_at = controller_simulink_Y.df_delta_pos_at;
	outMsg.e_at_feed = controller_simulink_Y.e_at_feed;
	outMsg.des_along_rate = controller_simulink_Y.des_along_rate;
	outMsg.des_along_rate_shaped = controller_simulink_Y.des_along_rate_shaped;
    outMsg.df_delta_vel_at = controller_simulink_Y.df_delta_vel_at;
    outMsg.des_along_rate_feed = controller_simulink_Y.des_along_rate_feed;
    outMsg.along_rate_is = controller_simulink_Y.along_rate_is;
    outMsg.at_p_action = controller_simulink_Y.at_p_action; 
    outMsg.at_d_action = controller_simulink_Y.at_d_action;

	pub_output.publish(outMsg);

}

// == publish psi dubugging data

void SimulinkModel::publish_psi_debugging () {


//set psi_debugging

    sl_controller::psi_debugging outMsg; 
	outMsg.header.stamp = ros::Time::now();
	outMsg.header.frame_id = "output";

	outMsg.psi_ref =controller_simulink_Y.psi_ref;
    outMsg.psi_state = controller_simulink_Y.psi_state;
    outMsg.e_psi = controller_simulink_Y.e_psi;
    outMsg.psi_APM = controller_simulink_Y.psi_APM ;
    outMsg.e_psi_corr = controller_simulink_Y.e_psi_corr;
    outMsg.psi_ref_APM = controller_simulink_Y.psi_ref_APM ;

    
	pub_psi_debugging.publish(outMsg);

}


 // ======= Imput shaper function

/* int factorial(int x)
{
	if (x==0 || x ==1)
	{
		return 1;
	}
	return x*fakultat(x-1);
} */
	
int SimulinkModel::factorial(int x)
{
	int result = 1;
	
	if (x==0 || x==1)
	{
		result = 1;
	}
	else
	{
		for(int i=2; i<=x; i++)
		{
			result = result*i;
		}
	}
	return result;
}

double SimulinkModel::nchoosek(int n, int k)
{
	return (double)factorial(n)/((double)factorial(k)*factorial(n-k));
}


 // ======= Main

int main(int argc, char **argv)
{
  ros::init(argc, argv, "controller_simulink");

  ROS_INFO("Slung Load controller");

//  controller_simulink_initialize();

  SimulinkModel sim;

  dynamic_reconfigure::Server<sl_controller::reconfigureConfig> server;
  dynamic_reconfigure::Server<sl_controller::reconfigureConfig>::CallbackType f;

  f = boost::bind(&SimulinkModel::dynamic_callback, &sim, _1, _2);
  server.setCallback(f);



        ros::NodeHandle private_nh_("~");

// z PID controller
	private_nh_.param("init/thrust_K_P",controller_simulink_P.c_thrust_K_P_Value,double(100));
	private_nh_.param("init/thrust_K_I",controller_simulink_P.c_thrust_K_I_Value,double(8));
	private_nh_.param("init/thrust_K_D",controller_simulink_P.c_thrust_K_D_Value,double(50));

	private_nh_.param("init/thrust_max_P",controller_simulink_P.c_thrust_max_P_Value,double(30));
	private_nh_.param("init/thrust_max_I",controller_simulink_P.c_thrust_max_I_Value,double(30));
	private_nh_.param("init/thrust_max_D",controller_simulink_P.c_thrust_max_D_Value,double(40));
	private_nh_.param("init/thrust_max_PID",controller_simulink_P.c_thrust_max_PID_Value,double(200));

// Cross Position P controller
	private_nh_.param("init/cross_pos_K_P",controller_simulink_P.c_cross_pos_K_P_Value,double(0.6));
	private_nh_.param("init/cross_pos_max_P",controller_simulink_P.c_cross_pos_max_P_Value,double(0.8));

// Cross Rate PD controller
	private_nh_.param("init/cross_rate_K_P",controller_simulink_P.c_cross_rate_K_P_Value,double(0.35));
	private_nh_.param("init/cross_rate_K_D",controller_simulink_P.c_cross_rate_K_D_Value,double(-0.02));

	private_nh_.param("init/cross_rate_max_P",controller_simulink_P.c_cross_rate_max_P_Value,double(20));
	private_nh_.param("init/cross_rate_max_D",controller_simulink_P.c_cross_rate_max_D_Value,double(20));
	private_nh_.param("init/cross_rate_max_PD",controller_simulink_P.c_cross_rate_max_PD_Value,double(40));

// Along Position P controller
	private_nh_.param("init/along_pos_K_P",controller_simulink_P.c_along_pos_K_P_Value,double(0.6));
	private_nh_.param("init/along_pos_max_P",controller_simulink_P.c_along_pos_max_P_Value,double(0.8));


// Along Rate PD controller
	private_nh_.param("init/along_rate_K_P",controller_simulink_P.c_along_rate_K_P_Value,double(0.35));
	private_nh_.param("init/along_rate_K_D",controller_simulink_P.c_along_rate_K_D_Value,double(-0.02)); 

	private_nh_.param("init/along_rate_max_P",controller_simulink_P.c_along_rate_max_P_Value,double(20));
	private_nh_.param("init/along_rate_max_D",controller_simulink_P.c_along_rate_max_D_Value,double(20));
	private_nh_.param("init/along_rate_max_PD",controller_simulink_P.c_along_rate_max_PD_Value,double(40));


/****************************************************************************************************************************/


  ros::Rate loop_rate(sim.freq_global);

  while (ros::ok())
  {

	ros::Rate loop_rate(sim.freq_global); //hertz

	sim.step();
	sim.publish_output();
	sim.publish_psi_debugging();

    ros::spinOnce();
    loop_rate.sleep();
  }

  //ros::spin();

  controller_simulink_terminate();

  return 0;
}

