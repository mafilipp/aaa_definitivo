#include "SimulinkModel.h" 

// ======= Dynamic reconfigure

void SimulinkModel::dynamic_callback(sl_controller::reconfigureConfig &config, uint32_t level) {


 // == initialization	

	power_supply = config.Supply_type;	
	load_weight = config.Load_0_200;
	freq_global = config.Frequency;
	controller_simulink_P.c_thrust_sample_time_Value = 1/config.Frequency;

// z PID controller
			controller_simulink_P.c_thrust_K_P_Value = config.thrust_K_P;
			controller_simulink_P.c_thrust_K_I_Value = config.thrust_K_I;
			controller_simulink_P.c_thrust_K_D_Value = config.thrust_K_D;

			controller_simulink_P.c_thrust_max_P_Value = config.thrust_max_P;
			controller_simulink_P.c_thrust_max_I_Value = config.thrust_max_I;
			controller_simulink_P.c_thrust_max_D_Value = config.thrust_max_D;
			controller_simulink_P.c_thrust_max_PID_Value = config.thrust_max_PID;

// Cross Position P controller
			controller_simulink_P.c_cross_pos_K_P_Value = config.cross_pos_K_P;
			controller_simulink_P.c_cross_pos_max_P_Value = config.cross_pos_max_P;

//Cross Rate PD controller
			controller_simulink_P.c_cross_rate_K_P_Value = config.cross_rate_K_P;
			controller_simulink_P.c_cross_rate_K_D_Value = config.cross_rate_K_D;
			controller_simulink_P.c_cross_rate_max_P_Value = config.cross_rate_max_P;
			controller_simulink_P.c_cross_rate_max_D_Value = config.cross_rate_max_D;
			controller_simulink_P.c_cross_rate_max_PD_Value = config.cross_rate_max_PD;

//Along Position P controller
			controller_simulink_P.c_along_pos_K_P_Value = config.along_pos_K_P;
			controller_simulink_P.c_along_pos_max_P_Value = config.along_pos_max_P;

//Along Rate PD controller
			controller_simulink_P.c_along_rate_K_P_Value = config.along_rate_K_P;
			controller_simulink_P.c_along_rate_K_D_Value = config.along_rate_K_D;
			controller_simulink_P.c_along_rate_max_P_Value = config.along_rate_max_P;
			controller_simulink_P.c_along_rate_max_D_Value = config.along_rate_max_D;
			controller_simulink_P.c_along_rate_max_PD_Value = config.along_rate_max_PD;

// Delayed Feedback control
	controller_simulink_P.df_N_delay_Value = config.N_Delay; 
	controller_simulink_P.df_G_d_Value = config.G_d; 
	controller_simulink_P.df_l_L_Value = config.l_L;
	controller_simulink_P.df_sign_ct_Value = config.df_sign_ct;
	controller_simulink_P.df_sign_at_Value = config.df_sign_at;
	
// Input shaper
	double pi = 3.14159265359;
	double sample_time_sl = 1.0/freq_global;
	double zeta1 = config.is_zeta_ct;
	double zeta2 = config.is_zeta_at;
	int N_impulses = config.is_N_impulses;
	int size_A = sizeof controller_simulink_P.is_A_Value;
	int size_N_r = sizeof controller_simulink_P.is_N_r_Value;

	double K1, K2, dummy1, dummy2;
	real_T is_A[size_A];
	real_T is_N_r[size_N_r];

	K1 = exp(-zeta1*pi/sqrt(1-(zeta1*zeta1)));
	K2 = exp(-zeta2*pi/sqrt(1-(zeta2*zeta2)));
	
	for(int i = 0; i < N_impulses; i++)
	{
		dummy1 = 0;
		dummy2 = 0;
		for(int j = 0; j < N_impulses; j++)
		{
			dummy1 = dummy1 + nchoosek(N_impulses-1,j)*pow(K1,j);
			dummy2 = dummy2 + nchoosek(N_impulses-1,j)*pow(K2,j);
		}
		is_A[i<<1] = nchoosek(N_impulses-1,i-1)*pow(K1,i-1)/dummy1;
		is_A[1+(i<<1)] = nchoosek(N_impulses-1,i-1)*pow(K2,i-1)/dummy2;
		is_N_r[i<<1] = floor(( ((i-1)*pi / (config.is_omega_ct*sqrt(1-(zeta1*zeta1))) )/sample_time_sl) + 0.5);
		is_N_r[1+(i<<1)] = floor(( ((i-1)*pi / (config.is_omega_at*sqrt(1-(zeta2*zeta2))))/sample_time_sl) + 0.5);
	}

	controller_simulink_P.is_on_Value = config.is_on;
	controller_simulink_P.is_N_impulses_Value = N_impulses;
	memcpy( controller_simulink_P.is_A_Value, is_A, size_A );
	memcpy( controller_simulink_P.is_N_r_Value, is_N_r, size_N_r );

// test
	//controller_simulink_P.test1_Value = config.test1;
	//controller_simulink_P.test1_Value = config.test2;
	//controller_simulink_P.test1_Value = config.test3;

// Initialization with parameter list controller_parameter.cfg

	if (config.init_PID)
	{
		ROS_INFO("Parameter inizialized");
		config.init_PID = 0;

// z PID controller
		ros::param::get("/init/thrust_K_P", config.thrust_K_P);
		ros::param::get("/init/thrust_K_I", config.thrust_K_I);
		ros::param::get("/init/thrust_K_D", config.thrust_K_D);

		ros::param::get("/init/thrust_max_P", config.thrust_max_P);
		ros::param::get("/init/thrust_max_I", config.thrust_max_I);
		ros::param::get("/init/thrust_max_D", config.thrust_max_D);
		ros::param::get("/init/thrust_max_PID", config.thrust_max_PID);

// Cross Position P controller
		ros::param::get("/init/cross_pos_K_P", config.cross_pos_K_P);
		ros::param::get("/init/cross_pos_max_P", config.cross_pos_max_P);

//Cross Rate PD controller
		ros::param::get("/init/cross_rate_K_P", config.cross_rate_K_P);
		ros::param::get("/init/cross_rate_K_D", config.cross_rate_K_D);

		ros::param::get("/init/cross_rate_max_P", config.cross_rate_max_P);
		ros::param::get("/init/cross_rate_max_D", config.cross_rate_max_D);
		ros::param::get("/init/cross_rate_max_PD", config.cross_rate_max_PD);

//Along Position P controller
		ros::param::get("/init/along_pos_K_P", config.along_pos_K_P);
		ros::param::get("/init/along_pos_max_P", config.along_pos_max_P);

//Along Rate PD controller
		ros::param::get("/init/along_rate_K_P", config.along_rate_K_P);
		ros::param::get("/init/along_rate_K_D", config.along_rate_K_D);
		ros::param::get("/init/along_rate_max_P", config.along_rate_max_P);
		ros::param::get("/init/along_rate_max_D", config.along_rate_max_D);
		ros::param::get("/init/along_rate_max_PD", config.along_rate_max_PD);

// Update with these data

// z PID controller
			controller_simulink_P.c_thrust_K_P_Value = config.thrust_K_P;
			controller_simulink_P.c_thrust_K_I_Value = config.thrust_K_I;
			controller_simulink_P.c_thrust_K_D_Value = config.thrust_K_D;

			controller_simulink_P.c_thrust_max_P_Value = config.thrust_max_P;
			controller_simulink_P.c_thrust_max_I_Value = config.thrust_max_I;
			controller_simulink_P.c_thrust_max_D_Value = config.thrust_max_D;
			controller_simulink_P.c_thrust_max_PID_Value = config.thrust_max_PID;

// Cross Position P controller
			controller_simulink_P.c_cross_pos_K_P_Value = config.cross_pos_K_P;
			controller_simulink_P.c_cross_pos_max_P_Value = config.cross_pos_max_P;

//Cross Rate PD controller
			controller_simulink_P.c_cross_rate_K_P_Value = config.cross_rate_K_P;
			controller_simulink_P.c_cross_rate_K_D_Value = config.cross_rate_K_D;
			controller_simulink_P.c_cross_rate_max_P_Value = config.cross_rate_max_P;
			controller_simulink_P.c_cross_rate_max_D_Value = config.cross_rate_max_D;
			controller_simulink_P.c_cross_rate_max_PD_Value = config.cross_rate_max_PD;

//Along Position P controller
			controller_simulink_P.c_along_pos_K_P_Value = config.along_pos_K_P;
			controller_simulink_P.c_along_pos_max_P_Value = config.along_pos_max_P;

//Along Rate PD controller
			controller_simulink_P.c_along_rate_K_P_Value = config.along_rate_K_P;
			controller_simulink_P.c_along_rate_K_D_Value = config.along_rate_K_D;
			controller_simulink_P.c_along_rate_max_P_Value = config.along_rate_max_P;
			controller_simulink_P.c_along_rate_max_D_Value = config.along_rate_max_D;
			controller_simulink_P.c_along_rate_max_PD_Value = config.along_rate_max_PD;

	}


	if (config.load_param)
	{
		ROS_INFO("Parameter loaded");
		config.load_param = 0;

// z PID controller
		ros::param::get("/controller_simulink/thrust_K_P", config.thrust_K_P);
		ros::param::get("/controller_simulink/thrust_K_I", config.thrust_K_I);
		ros::param::get("/controller_simulink/thrust_K_D", config.thrust_K_D);

		ros::param::get("/controller_simulink/thrust_max_P", config.thrust_max_P);
		ros::param::get("/controller_simulink/thrust_max_I", config.thrust_max_I);
		ros::param::get("/controller_simulink/thrust_max_D", config.thrust_max_D);
		ros::param::get("/controller_simulink/thrust_max_PID", config.thrust_max_PID);

// Cross Position P controller
		ros::param::get("/controller_simulink/cross_pos_K_P", config.cross_pos_K_P);
		ros::param::get("/controller_simulink/cross_pos_max_P", config.cross_pos_max_P);

//Cross Rate PD controller
		ros::param::get("/controller_simulink/cross_rate_K_P", config.cross_rate_K_P);
		ros::param::get("/controller_simulink/cross_rate_K_D", config.cross_rate_K_D);

		ros::param::get("/controller_simulink/cross_rate_max_P", config.cross_rate_max_P);
		ros::param::get("/controller_simulink/cross_rate_max_D", config.cross_rate_max_D);
		ros::param::get("/controller_simulink/cross_rate_max_PD", config.cross_rate_max_PD);

//Along Position P controller
		ros::param::get("/controller_simulink/along_pos_K_P", config.along_pos_K_P);
		ros::param::get("/controller_simulink/along_pos_max_P", config.along_pos_max_P);

//Along Rate PD controller
		ros::param::get("/controller_simulink/along_rate_K_P", config.along_rate_K_P);
		ros::param::get("/controller_simulink/along_rate_K_D", config.along_rate_K_D);
		ros::param::get("/controller_simulink/along_rate_max_P", config.along_rate_max_P);
		ros::param::get("/controller_simulink/along_rate_max_D", config.along_rate_max_D);
		ros::param::get("/controller_simulink/along_rate_max_PD", config.along_rate_max_PD);


// Delayed Feedback control
		ros::param::get("/controller_simulink/N_Delay", config.N_Delay);
		ros::param::get("/controller_simulink/G_d", config.G_d);
		ros::param::get("/controller_simulink/l_L", config.l_L);
		ros::param::get("/controller_simulink/df_sign_ct", config.df_sign_ct);
		ros::param::get("/controller_simulink/df_sign_at", config.df_sign_at);


// Input shaper
		ros::param::get("/controller_simulink/is_on", config.is_on);
		ros::param::get("/controller_simulink/is_N_impulses", config.is_N_impulses);
		ros::param::get("/controller_simulink/is_omega_ct", config.is_omega_ct);
		ros::param::get("/controller_simulink/is_omega_at", config.is_omega_at);
		ros::param::get("/controller_simulink/is_zeta_ct", config.is_zeta_ct);
		ros::param::get("/controller_simulink/is_zeta_at", config.is_zeta_at);


// Test
		ros::param::get("/controller_simulink/test1", config.test1);
		ros::param::get("/controller_simulink/test2", config.test2);
		ros::param::get("/controller_simulink/test3", config.test3);



// == save the value in the memory

// z PID controller
		load_thrust_K_P = config.thrust_K_P;
		load_thrust_K_I = config.thrust_K_I;
		load_thrust_K_D = config.thrust_K_D;

		load_thrust_max_P = config.thrust_max_P;
		load_thrust_max_I = config.thrust_max_I;
		load_thrust_max_D = config.thrust_max_D;
		load_thrust_max_PID = config.thrust_max_PID;

// Cross Position P controller
		load_cross_pos_K_P = config.cross_pos_K_P;
		load_cross_pos_max_P = config.cross_pos_max_P;

//Cross Rate PD controller
		load_cross_rate_K_P = config.cross_rate_K_P;
		load_cross_rate_K_D = config.cross_rate_K_D;

		load_cross_rate_max_P = config.cross_rate_max_P;
		load_cross_rate_max_D = config.cross_rate_max_D;
		load_cross_rate_max_PD = config.cross_rate_max_PD;

//Along Position P controller
		load_along_pos_K_P = config.along_pos_K_P;
		load_along_pos_max_P = config.along_pos_max_P;

//Along Rate PD controller
		load_along_rate_K_P = config.along_rate_K_P;
		load_along_rate_K_D = config.along_rate_K_D;
		load_along_rate_max_P = config.along_rate_max_P;
		load_along_rate_max_D = config.along_rate_max_D;
		load_along_rate_max_PD = config.along_rate_max_PD;


/********************** SL Controller start ***************************/

// Delayed Feedback control
	df_N_Delay = config.N_Delay; 
	df_G_d = config.G_d; 
	df_l_L = config.l_L;
	df_sign_ct = config.df_sign_ct;
	df_sign_at = config.df_sign_at;
	
// Input shaper		
	is_on = config.is_on;
	is_N_impulses = config.is_N_impulses;
	is_omega_ct = config.is_omega_ct;
	is_omega_at = config.is_omega_at;
	is_zeta_ct = config.is_zeta_ct;
	is_zeta_at = config.is_zeta_at;



// test
	//test1_Value = config.test1;
	//test2_Value = config.test2;
	//test3_Value = config.test3;


/********************** SL Controller stop ***************************/

	}


	if (config.use_param)
	{
		ROS_INFO("Parameter loaded or saved used!");
		config.use_param = 0;

// == set the loaded parameter in the reconfigure GUI

// z PID controller
		config.thrust_K_P = load_thrust_K_P;
		config.thrust_K_I = load_thrust_K_I;
		config.thrust_K_D = load_thrust_K_D;

		config.thrust_max_P = load_thrust_max_P;
		config.thrust_max_I = load_thrust_max_I;
		config.thrust_max_D = load_thrust_max_D;
		config.thrust_max_PID = load_thrust_max_PID;

// Cross Position P controller
		config.cross_pos_K_P = load_cross_pos_K_P;
		config.cross_pos_max_P = load_cross_pos_max_P;

//Cross Rate PD controller
		config.cross_rate_K_P = load_cross_rate_K_P;
		config.cross_rate_K_D = load_cross_rate_K_D;

		config.cross_rate_max_P = load_cross_rate_max_P;
		config.cross_rate_max_D = load_cross_rate_max_D;
		config.cross_rate_max_PD = load_cross_rate_max_PD;

//Along Position P controller
		config.along_pos_K_P = load_along_pos_K_P;
		config.along_pos_max_P = load_along_pos_max_P;

//Along Rate PD controller
		config.along_rate_K_P = load_along_rate_K_P;
		config.along_rate_K_D = load_along_rate_K_D;
		config.along_rate_max_P = load_along_rate_max_P;
		config.along_rate_max_D = load_along_rate_max_D;
		config.along_rate_max_PD = load_along_rate_max_PD;


/********************** SL Controller start ***************************/

// Delayed Feedback control
	config.N_Delay = df_N_Delay; 
	config.G_d = df_G_d; 
	config.l_L = df_l_L;
	config.df_sign_ct = df_sign_ct;
	config.df_sign_at = df_sign_at;
	
// Input shaper		
	config.is_on = is_on;
	config.is_N_impulses = is_N_impulses;
	config.is_omega_ct = is_omega_ct;
	config.is_omega_at = is_omega_at;
	config.is_zeta_ct = is_zeta_ct;
	config.is_zeta_at = is_zeta_at;

// test
	//config.test1 = test1_Value;
	//config.test2 = test2_Value;
	//config.test3 = test3_Value;


/********************** SL Controller stop ***************************/

// == write the loaded parameter in the memory for the function step
/// z PID controller
			controller_simulink_P.c_thrust_K_P_Value = load_thrust_K_P;
			controller_simulink_P.c_thrust_K_I_Value = load_thrust_K_I;
			controller_simulink_P.c_thrust_K_D_Value = load_thrust_K_D;
			
			controller_simulink_P.c_thrust_max_P_Value = load_thrust_max_P;
			controller_simulink_P.c_thrust_max_I_Value = load_thrust_max_I;
			controller_simulink_P.c_thrust_max_D_Value = load_thrust_max_D;
			controller_simulink_P.c_thrust_max_PID_Value = load_thrust_max_PID;

// Cross Position P controller
			controller_simulink_P.c_cross_pos_K_P_Value = load_cross_pos_K_P;
			controller_simulink_P.c_cross_pos_max_P_Value = load_cross_pos_max_P;

//Cross Rate PD controller
			controller_simulink_P.c_cross_rate_K_P_Value = load_cross_rate_K_P;
			controller_simulink_P.c_cross_rate_K_D_Value = load_cross_rate_K_D;
			controller_simulink_P.c_cross_rate_max_P_Value = load_cross_rate_max_P;
			controller_simulink_P.c_cross_rate_max_D_Value = load_cross_rate_max_D;
			controller_simulink_P.c_cross_rate_max_PD_Value = load_cross_rate_max_PD;

//Along Position P controller
			controller_simulink_P.c_along_pos_K_P_Value = load_along_pos_K_P;
			controller_simulink_P.c_along_pos_max_P_Value = load_along_pos_max_P;

//Along Rate PD controller
			controller_simulink_P.c_along_rate_K_P_Value = load_along_rate_K_P;
			controller_simulink_P.c_along_rate_K_D_Value = load_along_rate_K_D;
	
			controller_simulink_P.c_along_rate_max_P_Value = load_along_rate_max_P;
			controller_simulink_P.c_along_rate_max_D_Value = load_along_rate_max_D;
			controller_simulink_P.c_along_rate_max_PD_Value = load_along_rate_max_PD;

/********************** SL Controller start ***************************/

// Delayed Feedback control
	controller_simulink_P.df_N_delay_Value = df_N_Delay; 
	controller_simulink_P.df_G_d_Value = df_G_d; 
	controller_simulink_P.df_l_L_Value = df_l_L;
	controller_simulink_P.df_sign_ct_Value = df_sign_ct;
	controller_simulink_P.df_sign_at_Value = df_sign_at;
	
// Delayed Feedback control
	controller_simulink_P.df_N_delay_Value = df_N_Delay; 
	controller_simulink_P.df_G_d_Value = df_G_d; 
	controller_simulink_P.df_l_L_Value = df_l_L;
	controller_simulink_P.df_sign_ct_Value = df_sign_ct;
	controller_simulink_P.df_sign_at_Value = df_sign_at;
	
// Input shaper
	double pi = 3.14159265359;
	double sample_time_sl = 1.0/freq_global;
	double zeta1 = is_zeta_ct;
	double zeta2 = is_zeta_at;
	int N_impulses = is_N_impulses;
	int size_A = sizeof controller_simulink_P.is_A_Value;
	int size_N_r = sizeof controller_simulink_P.is_N_r_Value;

	double K1, K2, dummy1, dummy2;
	real_T is_A[size_A];
	real_T is_N_r[size_N_r];

	K1 = exp(-zeta1*pi/sqrt(1-(zeta1*zeta1)));
	K2 = exp(-zeta2*pi/sqrt(1-(zeta2*zeta2)));
	
	for(int i = 0; i < N_impulses; i++)
	{
		dummy1 = 0;
		dummy2 = 0;
		for(int j = 0; j < N_impulses; j++)
		{
			dummy1 = dummy1 + nchoosek(N_impulses-1,j)*pow(K1,j);
			dummy2 = dummy2 + nchoosek(N_impulses-1,j)*pow(K2,j);
		}
		is_A[i<<1] = nchoosek(N_impulses-1,i-1)*pow(K1,i-1)/dummy1;
		is_A[1+(i<<1)] = nchoosek(N_impulses-1,i-1)*pow(K2,i-1)/dummy2;
		is_N_r[i<<1] = floor(( ((i-1)*pi / (is_omega_ct*sqrt(1-(zeta1*zeta1))) )/sample_time_sl) + 0.5);
		is_N_r[1+(i<<1)] = floor(( ((i-1)*pi / (is_omega_at*sqrt(1-(zeta2*zeta2))))/sample_time_sl) + 0.5);
	}

	controller_simulink_P.is_on_Value = is_on;
	controller_simulink_P.is_N_impulses_Value = N_impulses;
	memcpy( controller_simulink_P.is_A_Value, is_A, size_A );
	memcpy( controller_simulink_P.is_N_r_Value, is_N_r, size_N_r );

// test
	//controller_simulink_P.test1_Value = test1;
	//controller_simulink_P.test1_Value = test2;
	//controller_simulink_P.test1_Value = test3;


/********************** SL Controller stop ***************************/

	}


	if (config.init_coordinate)
	{
		ROS_INFO("Coordinate system initialized");
		config.init_coordinate = 0;
		
		x_init =   	x_true;
	    y_init =	y_true;
	    z_init =	z_true; 

		waypoint_z_thrust = z_init;

		controller_simulink_U.x_ref = -0.01;
		controller_simulink_U.y_ref = 0;
		controller_simulink_U.z_ref = 0;
		controller_simulink_U.dz_ref  = 0;
		controller_simulink_U.v_ref = 0;
		controller_simulink_U.number_path = -3;

		step();

		controller_simulink_U.x_ref = 0;
		controller_simulink_U.y_ref = 0;
		controller_simulink_U.z_ref = 0;
		controller_simulink_U.dz_ref  = 0;
		controller_simulink_U.v_ref = 0;
		controller_simulink_U.number_path = -2;

		step();		


	}

}
