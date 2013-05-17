/*
 * File: controller_simulink.cpp
 *
 * Code generated for Simulink model 'controller_simulink'.
 *
 * Model version                  : 1.108
 * Simulink Coder version         : 8.2 (R2012a) 29-Dec-2011
 * TLC version                    : 8.2 (Jan 25 2012)
 * C/C++ source code generated on : Thu May 16 09:56:22 2013
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "controller_simulink.h"
#include "controller_simulink_private.h"

/* Named constants for MATLAB Function: '<S19>/Delay_feedback' */
#define controller_simulink_N_delay_max (30.0)

/* Block states (auto storage) */
D_Work_controller_simulink controller_simulink_DWork;

/* External inputs (root inport signals with auto storage) */
ExternalInputs_controller_simul controller_simulink_U;

/* External outputs (root outports fed by signals with auto storage) */
ExternalOutputs_controller_simu controller_simulink_Y;

/* Real-time model */
RT_MODEL_controller_simulink controller_simulink_M_;
RT_MODEL_controller_simulink *const controller_simulink_M =
  &controller_simulink_M_;

/* Forward declaration for local functions */
static real_T controller_simulink_norm(const real_T x[2]);

/* Function for MATLAB Function: '<S3>/MATLAB Function' */
static real_T controller_simulink_norm(const real_T x[2])
{
  real_T y;
  real_T scale;
  real_T absxk;
  real_T t;
  scale = 2.2250738585072014E-308;
  absxk = fabs(x[0]);
  if (absxk > 2.2250738585072014E-308) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 2.2250738585072014E-308;
    y = t * t;
  }

  absxk = fabs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * sqrt(y);
}

/* Model step function */
void controller_simulink_step(void)
{
  real_T e_psi_corr;
  real_T x_old_ref;
  real_T y_old_ref;
  real_T tangent_not_normed[2];
  real_T norm_tan;
  real_T distance_x;
  real_T distance_y;
  real_T normal_not_normal[2];
  real_T psi_ref;
  int32_T b_k;
  real_T rtb_psi_APM;
  real_T rtb_err_e_psi;
  real_T rtb_err_psi_ref_APM;
  real_T rtb_Gain;
  real_T rtb_SliderGain_a;
  real_T rtb_SliderGain_n;
  real_T rtb_SliderGain_g;
  real_T rtb_Gain3;
  real_T rtb_Gain5_m;
  real_T rtb_Product8;
  real_T rtb_Sum2;
  real_T rtb_Gain3_i;
  real_T rtb_Sum;
  real_T rtb_Product4;
  real_T rtb_Gain9;
  real_T rtb_Sum1;
  real_T rtb_Gain3_f;
  real_T rtb_Product5;
  real_T rtb_Gain8 = 0.0;
  real_T DiscreteTransferFcn_tmp;
  real_T DiscreteTransferFcn_tmp_f;
  real_T DiscreteTransferFcn1_tmp;
  real_T DiscreteTransferFcn_tmp_l;
  real_T tmp[60];
  real_T rtb_Gain1_e_0[400];
  real_T rtb_Gain1_e_idx;
  real_T rtb_Gain1_e_idx_0;
  real_T rtb_r_s_idx;
  real_T rtb_r_s_idx_0;
  real_T distance_vector_idx;
  real_T distance_vector_idx_0;
  real_T u;
  real_T u_0;
  real_T u_1;
  real_T u_2;
  real_T u_3;
  real_T u_4;

  /* Gain: '<S3>/Gain' incorporates:
   *  Inport: '<Root>/yaw_APM'
   */
  rtb_psi_APM = controller_simulink_P.Gain_Gain * controller_simulink_U.yaw_APM;

  /* MATLAB Function: '<S3>/MATLAB Function' incorporates:
   *  Inport: '<Root>/number_path'
   *  Inport: '<Root>/psi'
   *  Inport: '<Root>/x'
   *  Inport: '<Root>/x_ref'
   *  Inport: '<Root>/y'
   *  Inport: '<Root>/y_ref'
   *  Inport: '<Root>/z_ref'
   *  UnitDelay: '<S3>/Unit Delay'
   */
  /* MATLAB Function 'controller/error_calculation/MATLAB Function': '<S48>:1' */
  /* This function calculates all the error needed by the different controllers */
  /* initialisation of output structs */
  /* '<S48>:1:9' */
  /* '<S48>:1:10' */
  /*  General  */
  /*  Waypoint handling: if a change of the path discretisation occour */
  /*  This is already done above... */
  /* err.reset_Integrator.thrust = 0; */
  /* err.reset_Integrator.ct_pos = 0;   */
  /* err.reset_Integrator.at_rate = 0;   */
  if (controller_simulink_DWork.UnitDelay_DSTATE.path_number !=
      controller_simulink_U.number_path) {
    /* '<S48>:1:19' */
    /* %% in controller !!!! prev_i_error = 0;   */
    /* '<S48>:1:20' */
    x_old_ref = controller_simulink_DWork.UnitDelay_DSTATE.x_ref;

    /* '<S48>:1:21' */
    y_old_ref = controller_simulink_DWork.UnitDelay_DSTATE.y_ref;

    /*  reset Thrust Integrator     */
    if (controller_simulink_DWork.UnitDelay_DSTATE.z_ref !=
        controller_simulink_U.z_ref) {
      /* '<S48>:1:23' */
      /* '<S48>:1:24' */
      rtb_Gain8 = 1.0;
    }

    /*  reset Along Rate Integrator */
  } else {
    /* '<S48>:1:31' */
    x_old_ref = controller_simulink_DWork.UnitDelay_DSTATE.x_old_ref;

    /* '<S48>:1:32' */
    y_old_ref = controller_simulink_DWork.UnitDelay_DSTATE.y_old_ref;
  }

  /* '<S48>:1:35' */
  /* '<S48>:1:36' */
  /* '<S48>:1:37' */
  /* '<S48>:1:38' */
  /* '<S48>:1:39' */
  /* '<S48>:1:40' */
  /* '<S48>:1:42' */
  /*  define distance (position error) (vector 1x2) */
  /* '<S48>:1:45' */
  distance_vector_idx = controller_simulink_U.x_ref - controller_simulink_U.x;
  distance_vector_idx_0 = controller_simulink_U.y_ref - controller_simulink_U.y;

  /* distance_vector=[(x_old_ref-x) (y_old_ref-y)]; */
  /* define velocity (vector 1x2) */
  /* '<S48>:1:47' */
  /* define tangent  = straight line between two consecutive node  (vector 2x1) */
  /* '<S48>:1:50' */
  tangent_not_normed[0] = controller_simulink_U.x_ref - x_old_ref;
  tangent_not_normed[1] = controller_simulink_U.y_ref - y_old_ref;

  /* '<S48>:1:51' */
  norm_tan = controller_simulink_norm(tangent_not_normed);
  if (norm_tan == 0.0) {
    /* '<S48>:1:52' */
    /* '<S48>:1:53' */
    tangent_not_normed[0] = controller_simulink_DWork.UnitDelay_DSTATE.tangent[0];
    tangent_not_normed[1] = controller_simulink_DWork.UnitDelay_DSTATE.tangent[1];
  } else {
    /* '<S48>:1:55' */
    tangent_not_normed[0] /= norm_tan;
    tangent_not_normed[1] /= norm_tan;
  }

  /* '<S48>:1:58' */
  /* define normal (vector 2x1) */
  /* '<S48>:1:61' */
  distance_x = controller_simulink_U.x_ref - x_old_ref;

  /* '<S48>:1:62' */
  distance_y = controller_simulink_U.y_ref - y_old_ref;

  /* '<S48>:1:63' */
  normal_not_normal[0] = -distance_y;
  normal_not_normal[1] = distance_x;

  /* '<S48>:1:64' */
  norm_tan = controller_simulink_norm(normal_not_normal);
  if (norm_tan == 0.0) {
    /* '<S48>:1:65' */
    /* '<S48>:1:66' */
    normal_not_normal[0] = controller_simulink_DWork.UnitDelay_DSTATE.normal[0];
    normal_not_normal[1] = controller_simulink_DWork.UnitDelay_DSTATE.normal[1];
  } else {
    /* '<S48>:1:68' */
    normal_not_normal[0] /= norm_tan;
    normal_not_normal[1] /= norm_tan;
  }

  /* '<S48>:1:71' */
  /*  reset Cross Integrator */
  /* '<S48>:1:79' */
  /* %% End global definitions %%% */
  /*  Z Error */
  /* '<S48>:1:84' */
  /* '<S48>:1:85' */
  /*  Psi Reference and error */
  if (distance_x == 0.0) {
    /* '<S48>:1:88' */
    if (distance_y == 0.0) {
      /* '<S48>:1:89' */
      /*  delta_x und delta_y = 0 */
      /* '<S48>:1:91' */
      psi_ref = controller_simulink_DWork.UnitDelay_DSTATE.psi_ref;
    } else if (distance_y > 0.0) {
      /* '<S48>:1:92' */
      /*  delta_x = 0 */
      /* '<S48>:1:94' */
      psi_ref = 1.5707963267948966;
    } else {
      /* '<S48>:1:96' */
      psi_ref = -1.5707963267948966;
    }
  } else if (distance_y == 0.0) {
    /* '<S48>:1:99' */
    /*  delta_y = 0 */
    if (distance_x > 0.0) {
      /* '<S48>:1:101' */
      /* '<S48>:1:102' */
      psi_ref = 0.0;
    } else {
      /* '<S48>:1:104' */
      psi_ref = 3.1415926535897931;
    }
  } else {
    /*  Normalfall */
    /* '<S48>:1:108' */
    psi_ref = atan(distance_y / distance_x);

    /* so we have the desired psi in radian */
    if (distance_x < 0.0) {
      /* '<S48>:1:109' */
      if (distance_y < 0.0) {
        /* '<S48>:1:110' */
        /* '<S48>:1:111' */
        psi_ref -= 3.1415926535897931;
      } else {
        /* '<S48>:1:113' */
        psi_ref += 3.1415926535897931;
      }
    }
  }

  /* '<S48>:1:118' */
  /* '<S48>:1:119' */
  rtb_err_e_psi = psi_ref - controller_simulink_U.psi;

  /*  because the APM yaw angle driftet we need to put some correction more: */
  /* '<S48>:1:122' */
  e_psi_corr = controller_simulink_U.psi - rtb_psi_APM;
  if (e_psi_corr > 3.1415926535897931) {
    /* '<S48>:1:124' */
    /* '<S48>:1:125' */
    e_psi_corr -= 6.2831853071795862;
  } else {
    if (e_psi_corr < -3.1415926535897931) {
      /* '<S48>:1:126' */
      /* '<S48>:1:127' */
      e_psi_corr += 6.2831853071795862;
    }
  }

  /*  e_psi drifted: */
  /* '<S48>:1:130' */
  rtb_err_psi_ref_APM = psi_ref - e_psi_corr;

  /* Gain: '<S11>/Gain' incorporates:
   *  Gain: '<S15>/Gain2'
   *  Inport: '<Root>/z'
   *  Inport: '<Root>/z_ref'
   *  MATLAB Function: '<S3>/MATLAB Function'
   */
  /*  Along track error */
  /* '<S48>:1:133' */
  /*  Along Track Velocity */
  /* '<S48>:1:136' */
  /* '<S48>:1:137' */
  /*  Cross Track Error */
  /* distance_vector=[(x_old_ref-x) (y_old_ref-y)]; */
  /* '<S48>:1:141' */
  /*  Cross Rate */
  /* '<S48>:1:144' */
  /* '<S48>:1:145' */
  rtb_Gain = (controller_simulink_U.z_ref - controller_simulink_U.z) *
    controller_simulink_P.Gain2_Gain * controller_simulink_P.Gain_Gain_i;

  /* Gain: '<S36>/Slider Gain' incorporates:
   *  Constant: '<S11>/c_thrust_K_I'
   */
  rtb_SliderGain_a = controller_simulink_P.SliderGain_Gain_k *
    controller_simulink_P.c_thrust_K_I_Value;

  /* Gain: '<S40>/Slider Gain' incorporates:
   *  Constant: '<S11>/c_thrust_max_P'
   */
  norm_tan = controller_simulink_P.SliderGain_Gain_m *
    controller_simulink_P.c_thrust_max_P_Value;

  /* Gain: '<S39>/Slider Gain' incorporates:
   *  Constant: '<S11>/c_thrust_max_I'
   */
  distance_x = controller_simulink_P.SliderGain_Gain_d *
    controller_simulink_P.c_thrust_max_I_Value;

  /* Gain: '<S38>/Slider Gain' incorporates:
   *  Constant: '<S11>/c_thrust_max_D'
   */
  rtb_SliderGain_n = controller_simulink_P.SliderGain_Gain_kp *
    controller_simulink_P.c_thrust_max_D_Value;

  /* Gain: '<S41>/Slider Gain' incorporates:
   *  Constant: '<S11>/c_thrust_max_PID'
   */
  rtb_SliderGain_g = controller_simulink_P.SliderGain_Gain_h *
    controller_simulink_P.c_thrust_max_PID_Value;

  /* MATLAB Function: '<S11>/PID_CTRL' incorporates:
   *  Constant: '<S11>/c_thrust_K_D'
   *  Constant: '<S11>/c_thrust_K_P'
   *  Constant: '<S11>/c_thrust_sample_time'
   *  Gain: '<S11>/Gain4'
   *  Gain: '<S11>/Gain5'
   *  Gain: '<S15>/Gain1'
   *  Gain: '<S15>/Gain10'
   *  Gain: '<S35>/Slider Gain'
   *  Gain: '<S37>/Slider Gain'
   *  Inport: '<Root>/dz'
   *  Inport: '<Root>/dz_ref'
   *  MATLAB Function: '<S3>/MATLAB Function'
   *  UnitDelay: '<S11>/Unit Delay'
   */
  distance_y = controller_simulink_DWork.UnitDelay_DSTATE_a;

  /* MATLAB Function 'controller/controller/Controller/PID_Thrust/PID_CTRL': '<S34>:1' */
  if (controller_simulink_P.Gain10_Gain * rtb_Gain8 *
      controller_simulink_P.Gain5_Gain == 1.0) {
    /* '<S34>:1:5' */
    /* '<S34>:1:6' */
    distance_y = 0.0;
  }

  /* '<S34>:1:8' */
  /* '<S34>:1:10' */
  /* '<S34>:1:11' */
  /* '<S34>:1:12' */
  /* '<S34>:1:14' */
  /* '<S34>:1:15' */
  u = controller_simulink_P.SliderGain_Gain *
    controller_simulink_P.c_thrust_K_P_Value * rtb_Gain;
  if (!((u <= norm_tan) || rtIsNaN(norm_tan))) {
    u = norm_tan;
  }

  if (!((u >= -norm_tan) || rtIsNaN(-norm_tan))) {
    u = -norm_tan;
  }

  /* '<S34>:1:16' */
  /* '<S34>:1:17' */
  u_0 = (rtb_Gain * controller_simulink_P.c_thrust_sample_time_Value +
         distance_y) * rtb_SliderGain_a;
  if (!((u_0 <= distance_x) || rtIsNaN(distance_x))) {
    u_0 = distance_x;
  }

  if (!((u_0 >= -distance_x) || rtIsNaN(-distance_x))) {
    u_0 = -distance_x;
  }

  /* '<S34>:1:18' */
  /* '<S34>:1:19' */
  u_1 = (controller_simulink_U.dz_ref - controller_simulink_U.dz) *
    controller_simulink_P.Gain1_Gain * controller_simulink_P.Gain4_Gain *
    (controller_simulink_P.SliderGain_Gain_o *
     controller_simulink_P.c_thrust_K_D_Value);
  if (!((u_1 <= rtb_SliderGain_n) || rtIsNaN(rtb_SliderGain_n))) {
    u_1 = rtb_SliderGain_n;
  }

  if (!((u_1 >= -rtb_SliderGain_n) || rtIsNaN(-rtb_SliderGain_n))) {
    u_1 = -rtb_SliderGain_n;
  }

  if (rtb_SliderGain_a == 0.0) {
    /* Update for UnitDelay: '<S11>/Unit Delay' */
    /* '<S34>:1:21' */
    /* '<S34>:1:22' */
    controller_simulink_DWork.UnitDelay_DSTATE_a = 0.0;
  } else {
    /* Update for UnitDelay: '<S11>/Unit Delay' */
    /* '<S34>:1:24' */
    controller_simulink_DWork.UnitDelay_DSTATE_a = u_0 / rtb_SliderGain_a;
  }

  /* Gain: '<S15>/Gain3' */
  /* '<S34>:1:27' */
  /* '<S34>:1:28' */
  /* '<S34>:1:29' */
  /* '<S34>:1:31' */
  /* '<S34>:1:32' */
  rtb_Gain3 = controller_simulink_P.Gain3_Gain_l * rtb_err_e_psi;

  /* Gain: '<S15>/Gain5' incorporates:
   *  MATLAB Function: '<S3>/MATLAB Function'
   */
  rtb_Gain5_m = (distance_vector_idx * normal_not_normal[0] +
                 distance_vector_idx_0 * normal_not_normal[1]) *
    controller_simulink_P.Gain5_Gain_g;

  /* Gain: '<S4>/Gain1' incorporates:
   *  Inport: '<Root>/pitch_L'
   *  Inport: '<Root>/roll_L'
   */
  rtb_Gain1_e_idx = controller_simulink_P.Gain1_Gain_d *
    controller_simulink_U.roll_L;
  rtb_Gain1_e_idx_0 = controller_simulink_P.Gain1_Gain_d *
    controller_simulink_U.pitch_L;

  /* MATLAB Function: '<S6>/MATLAB Function' */
  /* MATLAB Function 'controller/controller/Controller/CoordinateTrasform/MATLAB Function': '<S18>:1' */
  /* '<S18>:1:4' */
  distance_x = cos(rtb_Gain1_e_idx);

  /* '<S18>:1:6' */
  distance_y = asin(distance_x * sin(rtb_Gain1_e_idx_0) * sin(rtb_Gain3) + sin
                    (rtb_Gain1_e_idx) * cos(rtb_Gain3));

  /* MATLAB Function: '<S19>/Delay_feedback' incorporates:
   *  Constant: '<S19>/df_N_delay'
   *  Constant: '<S7>/df_sign_at'
   *  Constant: '<S7>/df_sign_ct'
   *  MATLAB Function: '<S6>/MATLAB Function'
   *  Product: '<S7>/Product10'
   *  Product: '<S7>/Product11'
   */
  /* '<S18>:1:7' */
  norm_tan = controller_simulink_P.df_N_delay_Value;

  /* MATLAB Function 'controller/controller/Controller/Delayed Feedback Control/Delay2/Delay_feedback': '<S20>:1' */
  if (controller_simulink_P.df_N_delay_Value > controller_simulink_N_delay_max)
  {
    /* '<S20>:1:6' */
    /* '<S20>:1:7' */
    norm_tan = controller_simulink_N_delay_max;
  }

  /* '<S20>:1:10' */
  rtb_SliderGain_n = controller_simulink_DWork.A[((int32_T)norm_tan - 1) << 1];

  /* '<S20>:1:11' */
  rtb_SliderGain_a = controller_simulink_DWork.A[(((int32_T)norm_tan - 1) << 1)
    + 1];

  /* '<S20>:1:13' */
  tmp[0] = controller_simulink_P.df_sign_ct_Value * distance_y;
  tmp[1] = acos(1.0 / cos(distance_y) * (distance_x * cos(rtb_Gain1_e_idx_0))) *
    controller_simulink_P.df_sign_at_Value;
  for (b_k = 0; b_k < 29; b_k++) {
    tmp[(b_k + 1) << 1] = controller_simulink_DWork.A[b_k << 1];
    tmp[1 + ((b_k + 1) << 1)] = controller_simulink_DWork.A[(b_k << 1) + 1];
  }

  for (b_k = 0; b_k < 30; b_k++) {
    controller_simulink_DWork.A[b_k << 1] = tmp[b_k << 1];
    controller_simulink_DWork.A[1 + (b_k << 1)] = tmp[(b_k << 1) + 1];
  }

  /* End of MATLAB Function: '<S19>/Delay_feedback' */

  /* Product: '<S7>/Product8' incorporates:
   *  Constant: '<S7>/df_G_d'
   *  Constant: '<S7>/df_l_L'
   *  Product: '<S7>/Product6'
   *  Sin: '<S7>/Sine'
   */
  rtb_Product8 = (sin(controller_simulink_P.Sine_Freq * rtb_SliderGain_n +
                      controller_simulink_P.Sine_Phase) *
                  controller_simulink_P.Sine_Amp +
                  controller_simulink_P.Sine_Bias) *
    controller_simulink_P.df_l_L_Value * controller_simulink_P.df_G_d_Value;

  /* Sum: '<S4>/Sum2' */
  rtb_Sum2 = rtb_Gain5_m + rtb_Product8;

  /* Gain: '<S47>/Slider Gain' incorporates:
   *  Constant: '<S13>/c_cross_pos_max_P'
   */
  norm_tan = controller_simulink_P.SliderGain_Gain_e *
    controller_simulink_P.c_cross_pos_max_P_Value;

  /* MATLAB Function: '<S13>/P_CTRL' incorporates:
   *  Constant: '<S13>/c_cross_pos_K_P'
   *  Gain: '<S13>/Gain'
   *  Gain: '<S46>/Slider Gain'
   */
  /* MATLAB Function 'controller/controller/Controller/P_CrossTrack/P_CTRL': '<S45>:1' */
  /* '<S45>:1:4' */
  /* '<S45>:1:6' */
  /* '<S45>:1:7' */
  /* '<S45>:1:9' */
  u_3 = controller_simulink_P.SliderGain_Gain_l *
    controller_simulink_P.c_cross_pos_K_P_Value *
    (controller_simulink_P.Gain_Gain_o * rtb_Sum2);
  if (!((u_3 <= norm_tan) || rtIsNaN(norm_tan))) {
    u_3 = norm_tan;
  }

  if (!((u_3 >= -norm_tan) || rtIsNaN(-norm_tan))) {
    u_3 = -norm_tan;
  }

  /* Gain: '<S13>/Gain3' incorporates:
   *  MATLAB Function: '<S13>/P_CTRL'
   */
  rtb_Gain3_i = controller_simulink_P.Gain3_Gain_f * u_3;

  /* Gain: '<S15>/Gain4' incorporates:
   *  MATLAB Function: '<S3>/MATLAB Function'
   */
  rtb_Gain1_e_idx = (distance_vector_idx * tangent_not_normed[0] +
                     distance_vector_idx_0 * tangent_not_normed[1]) *
    controller_simulink_P.Gain4_Gain_l;

  /* Product: '<S7>/Product9' incorporates:
   *  Constant: '<S7>/df_G_d'
   *  Constant: '<S7>/df_l_L'
   *  Product: '<S7>/Product7'
   *  Sin: '<S7>/Sine1'
   */
  rtb_Gain1_e_idx_0 = (sin(controller_simulink_P.Sine1_Freq * rtb_SliderGain_a +
    controller_simulink_P.Sine1_Phase) * controller_simulink_P.Sine1_Amp +
                       controller_simulink_P.Sine1_Bias) *
    controller_simulink_P.df_l_L_Value * controller_simulink_P.df_G_d_Value;

  /* Sum: '<S4>/Sum3' */
  distance_vector_idx = rtb_Gain1_e_idx + rtb_Gain1_e_idx_0;

  /* Gain: '<S15>/Gain7' incorporates:
   *  Inport: '<Root>/v_ref'
   *  MATLAB Function: '<S3>/MATLAB Function'
   */
  norm_tan = controller_simulink_P.Gain7_Gain * controller_simulink_U.v_ref;

  /* Gain: '<S44>/Slider Gain' incorporates:
   *  Constant: '<S12>/c_along_pos_max_P'
   */
  distance_x = controller_simulink_P.SliderGain_Gain_dz *
    controller_simulink_P.c_along_pos_max_P_Value;

  /* MATLAB Function: '<S12>/P_CTRL' incorporates:
   *  Constant: '<S12>/c_along_pos_K_P'
   *  Gain: '<S12>/Gain'
   *  Gain: '<S43>/Slider Gain'
   */
  /* MATLAB Function 'controller/controller/Controller/P_AlongTrack/P_CTRL': '<S42>:1' */
  if (norm_tan == 0.0) {
    /* '<S42>:1:4' */
    /*  no velocity -> hold position -> position control */
    /* '<S42>:1:6' */
    /* '<S42>:1:8' */
    /* '<S42>:1:9' */
    norm_tan = controller_simulink_P.SliderGain_Gain_n *
      controller_simulink_P.c_along_pos_K_P_Value *
      (controller_simulink_P.Gain_Gain_l * distance_vector_idx);
    if (!((norm_tan <= distance_x) || rtIsNaN(distance_x))) {
      norm_tan = distance_x;
    }

    if (!((norm_tan >= -distance_x) || rtIsNaN(-distance_x))) {
      norm_tan = -distance_x;
    }
  } else {
    /*  velocity given so hold this velocity */
    /* '<S42>:1:12' */
  }

  /* Gain: '<S12>/Gain3' incorporates:
   *  MATLAB Function: '<S12>/P_CTRL'
   */
  /* '<S42>:1:15' */
  distance_vector_idx_0 = controller_simulink_P.Gain3_Gain_k * norm_tan;

  /* MATLAB Function: '<S8>/input_shaper' incorporates:
   *  Constant: '<S8>/is_A'
   *  Constant: '<S8>/is_N_impulses'
   *  Constant: '<S8>/is_N_r'
   *  Constant: '<S8>/is_on'
   *  SignalConversion: '<S21>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* MATLAB Function 'controller/controller/Controller/Input Shaper/input_shaper': '<S21>:1' */
  if (controller_simulink_P.is_on_Value == 1.0) {
    /* '<S21>:1:6' */
    /* '<S21>:1:7' */
    rtb_r_s_idx = 0.0;
    rtb_r_s_idx_0 = 0.0;

    /* '<S21>:1:9' */
    for (b_k = 0; b_k <= (int32_T)controller_simulink_P.is_N_impulses_Value - 1;
         b_k++) {
      /* '<S21>:1:9' */
      if (controller_simulink_P.is_N_r_Value[((int32_T)(1.0 + (real_T)b_k) - 1) <<
          1] == 0.0) {
        /* '<S21>:1:10' */
        /* '<S21>:1:11' */
        rtb_r_s_idx = rtb_Gain3_i;
      } else {
        /* '<S21>:1:13' */
        rtb_r_s_idx += controller_simulink_DWork.r[((int32_T)
          controller_simulink_P.is_N_r_Value[((int32_T)(1.0 + (real_T)b_k) - 1) <<
          1] - 1) << 1] * controller_simulink_P.is_A_Value[((int32_T)(1.0 +
          (real_T)b_k) - 1) << 1];
      }

      if (controller_simulink_P.is_N_r_Value[(((int32_T)(1.0 + (real_T)b_k) - 1)
           << 1) + 1] == 0.0) {
        /* '<S21>:1:16' */
        /* '<S21>:1:17' */
        rtb_r_s_idx_0 = distance_vector_idx_0;
      } else {
        /* '<S21>:1:19' */
        rtb_r_s_idx_0 += controller_simulink_DWork.r[(((int32_T)
          controller_simulink_P.is_N_r_Value[(((int32_T)(1.0 + (real_T)b_k) - 1)
          << 1) + 1] - 1) << 1) + 1] * controller_simulink_P.is_A_Value
          [(((int32_T)(1.0 + (real_T)b_k) - 1) << 1) + 1];
      }

      /* '<S21>:1:9' */
    }

    /* '<S21>:1:23' */
    rtb_Gain1_e_0[0] = rtb_Gain3_i;
    rtb_Gain1_e_0[1] = distance_vector_idx_0;
    for (b_k = 0; b_k < 199; b_k++) {
      rtb_Gain1_e_0[(b_k + 1) << 1] = controller_simulink_DWork.r[b_k << 1];
      rtb_Gain1_e_0[1 + ((b_k + 1) << 1)] = controller_simulink_DWork.r[(b_k <<
        1) + 1];
    }

    for (b_k = 0; b_k < 200; b_k++) {
      controller_simulink_DWork.r[b_k << 1] = rtb_Gain1_e_0[b_k << 1];
      controller_simulink_DWork.r[1 + (b_k << 1)] = rtb_Gain1_e_0[(b_k << 1) + 1];
    }
  } else {
    /* '<S21>:1:25' */
    rtb_r_s_idx = rtb_Gain3_i;
    rtb_r_s_idx_0 = distance_vector_idx_0;
  }

  /* End of MATLAB Function: '<S8>/input_shaper' */

  /* DiscreteTransferFcn: '<S7>/Discrete Transfer Fcn' */
  DiscreteTransferFcn_tmp = (rtb_SliderGain_n -
    controller_simulink_P.DiscreteTransferFcn_DenCoef[1] *
    controller_simulink_DWork.DiscreteTransferFcn_DSTATE) /
    controller_simulink_P.DiscreteTransferFcn_DenCoef[0];

  /* Product: '<S7>/Product4' incorporates:
   *  Constant: '<S7>/df_G_d'
   *  Constant: '<S7>/df_l_L'
   *  DiscreteTransferFcn: '<S7>/Discrete Transfer Fcn'
   *  Product: '<S7>/Product'
   *  Product: '<S7>/Product2'
   *  Sin: '<S7>/Cosine'
   */
  rtb_Product4 = (sin(controller_simulink_P.Cosine_Freq * rtb_SliderGain_n +
                      controller_simulink_P.Cosine_Phase) *
                  controller_simulink_P.Cosine_Amp +
                  controller_simulink_P.Cosine_Bias) *
    (controller_simulink_P.DiscreteTransferFcn_NumCoef[0] *
     DiscreteTransferFcn_tmp +
     controller_simulink_P.DiscreteTransferFcn_NumCoef[1] *
     controller_simulink_DWork.DiscreteTransferFcn_DSTATE) *
    controller_simulink_P.df_l_L_Value * controller_simulink_P.df_G_d_Value;

  /* Sum: '<S4>/Sum' */
  rtb_Sum = rtb_r_s_idx + rtb_Product4;

  /* Gain: '<S15>/Gain9' incorporates:
   *  Inport: '<Root>/dx'
   *  Inport: '<Root>/dy'
   *  MATLAB Function: '<S3>/MATLAB Function'
   */
  rtb_Gain9 = (controller_simulink_U.dx * normal_not_normal[0] +
               controller_simulink_U.dy * normal_not_normal[1]) *
    controller_simulink_P.Gain9_Gain;

  /* DiscreteTransferFcn: '<S10>/Discrete Transfer Fcn' */
  DiscreteTransferFcn_tmp_f = (rtb_Gain9 -
    controller_simulink_P.DiscreteTransferFcn_DenCoef_i[1] *
    controller_simulink_DWork.DiscreteTransferFcn_DSTATE_m) /
    controller_simulink_P.DiscreteTransferFcn_DenCoef_i[0];

  /* Gain: '<S32>/Slider Gain' incorporates:
   *  Constant: '<S10>/c_cross_rate_max_P'
   */
  norm_tan = controller_simulink_P.SliderGain_Gain_g *
    controller_simulink_P.c_cross_rate_max_P_Value;

  /* Gain: '<S31>/Slider Gain' incorporates:
   *  Constant: '<S10>/c_cross_rate_max_D'
   */
  distance_x = controller_simulink_P.SliderGain_Gain_mf *
    controller_simulink_P.c_cross_rate_max_D_Value;

  /* Gain: '<S33>/Slider Gain' incorporates:
   *  Constant: '<S10>/c_cross_rate_max_PD'
   */
  distance_y = controller_simulink_P.SliderGain_Gain_m5 *
    controller_simulink_P.c_cross_rate_max_PD_Value;

  /* MATLAB Function: '<S10>/PD_CTRL' incorporates:
   *  Constant: '<S10>/c_cross_rate_K_D'
   *  Constant: '<S10>/c_cross_rate_K_P'
   *  DiscreteTransferFcn: '<S10>/Discrete Transfer Fcn'
   *  Gain: '<S10>/Gain'
   *  Gain: '<S10>/Gain1'
   *  Gain: '<S10>/Gain2'
   *  Gain: '<S29>/Slider Gain'
   *  Gain: '<S30>/Slider Gain'
   */
  /* MATLAB Function 'controller/controller/Controller/PD_CrossTrack/PD_CTRL': '<S28>:1' */
  /* '<S28>:1:5' */
  /* '<S28>:1:7' */
  /* '<S28>:1:8' */
  /* '<S28>:1:10' */
  /* '<S28>:1:11' */
  u_3 = (controller_simulink_P.Gain_Gain_g * rtb_Sum -
         controller_simulink_P.Gain1_Gain_f * rtb_Gain9) *
    (controller_simulink_P.SliderGain_Gain_c *
     controller_simulink_P.c_cross_rate_K_P_Value);
  if (!((u_3 <= norm_tan) || rtIsNaN(norm_tan))) {
    u_3 = norm_tan;
  }

  if (!((u_3 >= -norm_tan) || rtIsNaN(-norm_tan))) {
    u_3 = -norm_tan;
  }

  /* '<S28>:1:12' */
  /* '<S28>:1:13' */
  u_2 = (controller_simulink_P.DiscreteTransferFcn_NumCoef_g[0] *
         DiscreteTransferFcn_tmp_f +
         controller_simulink_P.DiscreteTransferFcn_NumCoef_g[1] *
         controller_simulink_DWork.DiscreteTransferFcn_DSTATE_m) *
    controller_simulink_P.Gain2_Gain_m *
    (controller_simulink_P.SliderGain_Gain_oo *
     controller_simulink_P.c_cross_rate_K_D_Value);
  if (!((u_2 <= distance_x) || rtIsNaN(distance_x))) {
    u_2 = distance_x;
  }

  if (!((u_2 >= -distance_x) || rtIsNaN(-distance_x))) {
    u_2 = -distance_x;
  }

  /* '<S28>:1:15' */
  /* '<S28>:1:16' */
  /* '<S28>:1:17' */
  u_4 = u_3 + u_2;
  if (!((u_4 <= distance_y) || rtIsNaN(distance_y))) {
    u_4 = distance_y;
  }

  if (!((u_4 >= -distance_y) || rtIsNaN(-distance_y))) {
    u_4 = -distance_y;
  }

  /* Gain: '<S10>/Gain3' incorporates:
   *  MATLAB Function: '<S10>/PD_CTRL'
   */
  rtb_Gain3_f = controller_simulink_P.Gain3_Gain_b * u_4;

  /* DiscreteTransferFcn: '<S7>/Discrete Transfer Fcn1' */
  DiscreteTransferFcn1_tmp = (rtb_SliderGain_a -
    controller_simulink_P.DiscreteTransferFcn1_DenCoef[1] *
    controller_simulink_DWork.DiscreteTransferFcn1_DSTATE) /
    controller_simulink_P.DiscreteTransferFcn1_DenCoef[0];

  /* Product: '<S7>/Product5' incorporates:
   *  Constant: '<S7>/df_G_d'
   *  Constant: '<S7>/df_l_L'
   *  DiscreteTransferFcn: '<S7>/Discrete Transfer Fcn1'
   *  Product: '<S7>/Product1'
   *  Product: '<S7>/Product3'
   *  Sin: '<S7>/Cosine1'
   */
  rtb_Product5 = (sin(controller_simulink_P.Cosine1_Freq * rtb_SliderGain_a +
                      controller_simulink_P.Cosine1_Phase) *
                  controller_simulink_P.Cosine1_Amp +
                  controller_simulink_P.Cosine1_Bias) *
    (controller_simulink_P.DiscreteTransferFcn1_NumCoef[0] *
     DiscreteTransferFcn1_tmp +
     controller_simulink_P.DiscreteTransferFcn1_NumCoef[1] *
     controller_simulink_DWork.DiscreteTransferFcn1_DSTATE) *
    controller_simulink_P.df_l_L_Value * controller_simulink_P.df_G_d_Value;

  /* Sum: '<S4>/Sum1' */
  rtb_Sum1 = rtb_r_s_idx_0 + rtb_Product5;

  /* Gain: '<S15>/Gain8' incorporates:
   *  Inport: '<Root>/dx'
   *  Inport: '<Root>/dy'
   *  MATLAB Function: '<S3>/MATLAB Function'
   */
  rtb_Gain8 = (controller_simulink_U.dx * tangent_not_normed[0] +
               controller_simulink_U.dy * tangent_not_normed[1]) *
    controller_simulink_P.Gain8_Gain;

  /* DiscreteTransferFcn: '<S9>/Discrete Transfer Fcn' */
  DiscreteTransferFcn_tmp_l = (rtb_Gain8 -
    controller_simulink_P.DiscreteTransferFcn_DenCoef_p[1] *
    controller_simulink_DWork.DiscreteTransferFcn_DSTATE_o) /
    controller_simulink_P.DiscreteTransferFcn_DenCoef_p[0];

  /* Gain: '<S26>/Slider Gain' incorporates:
   *  Constant: '<S9>/c_along_rate_max_P'
   */
  norm_tan = controller_simulink_P.SliderGain_Gain_a *
    controller_simulink_P.c_along_rate_max_P_Value;

  /* Gain: '<S25>/Slider Gain' incorporates:
   *  Constant: '<S9>/c_along_rate_max_D'
   */
  distance_x = controller_simulink_P.SliderGain_Gain_p *
    controller_simulink_P.c_along_rate_max_D_Value;

  /* Gain: '<S27>/Slider Gain' incorporates:
   *  Constant: '<S9>/c_along_rate_max_PD'
   */
  distance_y = controller_simulink_P.SliderGain_Gain_i *
    controller_simulink_P.c_along_rate_max_PD_Value;

  /* MATLAB Function: '<S9>/PD_CTRL' incorporates:
   *  Constant: '<S9>/c_along_rate_K_D'
   *  Constant: '<S9>/c_along_rate_K_P'
   *  DiscreteTransferFcn: '<S9>/Discrete Transfer Fcn'
   *  Gain: '<S23>/Slider Gain'
   *  Gain: '<S24>/Slider Gain'
   *  Gain: '<S9>/Gain'
   *  Gain: '<S9>/Gain1'
   *  Gain: '<S9>/Gain2'
   */
  /* MATLAB Function 'controller/controller/Controller/PD_AlongTrack/PD_CTRL': '<S22>:1' */
  /* '<S22>:1:5' */
  /* '<S22>:1:7' */
  /* '<S22>:1:8' */
  /* '<S22>:1:10' */
  /* '<S22>:1:11' */
  rtb_SliderGain_a = (controller_simulink_P.Gain_Gain_lx * rtb_Sum1 -
                      controller_simulink_P.Gain1_Gain_b * rtb_Gain8) *
    (controller_simulink_P.SliderGain_Gain_f *
     controller_simulink_P.c_along_rate_K_P_Value);
  if (!((rtb_SliderGain_a <= norm_tan) || rtIsNaN(norm_tan))) {
    rtb_SliderGain_a = norm_tan;
  }

  if (!((rtb_SliderGain_a >= -norm_tan) || rtIsNaN(-norm_tan))) {
    rtb_SliderGain_a = -norm_tan;
  }

  /* '<S22>:1:12' */
  /* '<S22>:1:13' */
  rtb_SliderGain_n = (controller_simulink_P.DiscreteTransferFcn_NumCoef_d[0] *
                      DiscreteTransferFcn_tmp_l +
                      controller_simulink_P.DiscreteTransferFcn_NumCoef_d[1] *
                      controller_simulink_DWork.DiscreteTransferFcn_DSTATE_o) *
    controller_simulink_P.Gain2_Gain_l *
    (controller_simulink_P.SliderGain_Gain_eb *
     controller_simulink_P.c_along_rate_K_D_Value);
  if (!((rtb_SliderGain_n <= distance_x) || rtIsNaN(distance_x))) {
    rtb_SliderGain_n = distance_x;
  }

  if (!((rtb_SliderGain_n >= -distance_x) || rtIsNaN(-distance_x))) {
    rtb_SliderGain_n = -distance_x;
  }

  /* '<S22>:1:15' */
  /* '<S22>:1:16' */
  /* '<S22>:1:17' */
  u_4 = rtb_SliderGain_a + rtb_SliderGain_n;
  if (!((u_4 <= distance_y) || rtIsNaN(distance_y))) {
    u_4 = distance_y;
  }

  if (!((u_4 >= -distance_y) || rtIsNaN(-distance_y))) {
    u_4 = -distance_y;
  }

  /* Gain: '<S9>/Gain3' incorporates:
   *  MATLAB Function: '<S9>/PD_CTRL'
   */
  distance_x = controller_simulink_P.Gain3_Gain_h * u_4;

  /* MATLAB Function: '<S5>/MATLAB Function' */
  /* MATLAB Function 'controller/controller/Controller/Coordinate Transformation/MATLAB Function': '<S17>:1' */
  /* '<S17>:1:4' */
  distance_y = cos(rtb_Gain3);

  /* '<S17>:1:5' */
  norm_tan = sin(rtb_Gain3);

  /* MATLAB Function: '<S11>/PID_CTRL' */
  /* '<S17>:1:7' */
  /* '<S17>:1:8' */
  u_4 = (u + u_0) + u_1;
  if (!((u_4 <= rtb_SliderGain_g) || rtIsNaN(rtb_SliderGain_g))) {
    u_4 = rtb_SliderGain_g;
  }

  if (!((u_4 >= -rtb_SliderGain_g) || rtIsNaN(-rtb_SliderGain_g))) {
    u_4 = -rtb_SliderGain_g;
  }

  /* Outport: '<Root>/set_thrust' incorporates:
   *  Constant: '<S11>/hover_thrust'
   *  Gain: '<S11>/Gain1'
   *  Gain: '<S11>/Gain2'
   *  Gain: '<S11>/Gain3'
   *  Gain: '<S4>/Gain3'
   *  Gain: '<S4>/Gain4'
   *  Inport: '<Root>/phi'
   *  Inport: '<Root>/theta'
   *  MATLAB Function: '<S11>/PID_CTRL'
   */
  controller_simulink_Y.set_thrust = 1.0 / (cos(controller_simulink_P.Gain3_Gain
    * controller_simulink_U.phi * controller_simulink_P.Gain1_Gain_e) * cos
    (controller_simulink_P.Gain3_Gain * controller_simulink_U.theta *
     controller_simulink_P.Gain2_Gain_a)) *
    (controller_simulink_P.hover_thrust_Value + u_4) *
    controller_simulink_P.Gain3_Gain_i * controller_simulink_P.Gain4_Gain_c;

  /* Outport: '<Root>/set_phi' incorporates:
   *  Gain: '<S4>/Gain4'
   *  Gain: '<S4>/RadToDeg'
   *  MATLAB Function: '<S5>/MATLAB Function'
   */
  controller_simulink_Y.set_phi = (norm_tan * distance_x + distance_y *
    rtb_Gain3_f) * controller_simulink_P.RadToDeg_Gain *
    controller_simulink_P.Gain4_Gain_c;

  /* Outport: '<Root>/set_theta' incorporates:
   *  Gain: '<S4>/Gain4'
   *  Gain: '<S4>/RadToDeg1'
   *  MATLAB Function: '<S5>/MATLAB Function'
   */
  controller_simulink_Y.set_theta = (distance_y * distance_x - norm_tan *
    rtb_Gain3_f) * controller_simulink_P.RadToDeg1_Gain *
    controller_simulink_P.Gain4_Gain_c;

  /* Outport: '<Root>/set_psi' incorporates:
   *  Gain: '<S15>/Gain6'
   *  Gain: '<S4>/Gain4'
   *  Gain: '<S4>/RadToDeg2'
   */
  controller_simulink_Y.set_psi = controller_simulink_P.Gain6_Gain *
    rtb_err_psi_ref_APM * controller_simulink_P.RadToDeg2_Gain *
    controller_simulink_P.Gain4_Gain_c;

  /* Outport: '<Root>/p_action_thrust' incorporates:
   *  MATLAB Function: '<S11>/PID_CTRL'
   */
  controller_simulink_Y.p_action_thrust = u;

  /* Outport: '<Root>/i_action_thrust' incorporates:
   *  MATLAB Function: '<S11>/PID_CTRL'
   */
  controller_simulink_Y.i_action_thrust = u_0;

  /* Outport: '<Root>/d_action_thrust' incorporates:
   *  MATLAB Function: '<S11>/PID_CTRL'
   */
  controller_simulink_Y.d_action_thrust = u_1;

  /* Outport: '<Root>/z_err' */
  controller_simulink_Y.z_err = rtb_Gain;

  /* Outport: '<Root>/e_ct' */
  controller_simulink_Y.e_ct = rtb_Gain5_m;

  /* Outport: '<Root>/df_delta_pos_ct' */
  controller_simulink_Y.df_delta_pos_ct = rtb_Product8;

  /* Outport: '<Root>/e_ct_feed' */
  controller_simulink_Y.e_ct_feed = rtb_Sum2;

  /* Outport: '<Root>/des_cross_rate' */
  controller_simulink_Y.des_cross_rate = rtb_Gain3_i;

  /* Outport: '<Root>/des_cross_rate_shaped' */
  controller_simulink_Y.des_cross_rate_shaped = rtb_r_s_idx;

  /* Outport: '<Root>/df_delta_vel_ct' */
  controller_simulink_Y.df_delta_vel_ct = rtb_Product4;

  /* Outport: '<Root>/des_cross_rate_feed' */
  controller_simulink_Y.des_cross_rate_feed = rtb_Sum;

  /* Outport: '<Root>/cross_rate_is' */
  controller_simulink_Y.cross_rate_is = rtb_Gain9;

  /* Outport: '<Root>/ct_p_action' incorporates:
   *  MATLAB Function: '<S10>/PD_CTRL'
   */
  controller_simulink_Y.ct_p_action = u_3;

  /* Outport: '<Root>/ct_d_action' incorporates:
   *  MATLAB Function: '<S10>/PD_CTRL'
   */
  controller_simulink_Y.ct_d_action = u_2;

  /* Outport: '<Root>/e_at' */
  controller_simulink_Y.e_at = rtb_Gain1_e_idx;

  /* Outport: '<Root>/df_delta_pos_at' */
  controller_simulink_Y.df_delta_pos_at = rtb_Gain1_e_idx_0;

  /* Outport: '<Root>/e_at_feed' */
  controller_simulink_Y.e_at_feed = distance_vector_idx;

  /* Outport: '<Root>/des_along_rate' */
  controller_simulink_Y.des_along_rate = distance_vector_idx_0;

  /* Outport: '<Root>/des_along_rate_shaped' */
  controller_simulink_Y.des_along_rate_shaped = rtb_r_s_idx_0;

  /* Outport: '<Root>/df_delta_vel_at' */
  controller_simulink_Y.df_delta_vel_at = rtb_Product5;

  /* Outport: '<Root>/des_along_rate_feed' */
  controller_simulink_Y.des_along_rate_feed = rtb_Sum1;

  /* Outport: '<Root>/along_rate_is' */
  controller_simulink_Y.along_rate_is = rtb_Gain8;

  /* Outport: '<Root>/at_p_action' incorporates:
   *  MATLAB Function: '<S9>/PD_CTRL'
   */
  controller_simulink_Y.at_p_action = rtb_SliderGain_a;

  /* Outport: '<Root>/at_d_action' incorporates:
   *  MATLAB Function: '<S9>/PD_CTRL'
   */
  controller_simulink_Y.at_d_action = rtb_SliderGain_n;

  /* Outport: '<Root>/psi_ref' incorporates:
   *  MATLAB Function: '<S3>/MATLAB Function'
   */
  controller_simulink_Y.psi_ref = psi_ref;

  /* Outport: '<Root>/psi_state' incorporates:
   *  Inport: '<Root>/psi'
   */
  controller_simulink_Y.psi_state = controller_simulink_U.psi;

  /* Outport: '<Root>/e_psi' */
  controller_simulink_Y.e_psi = rtb_err_e_psi;

  /* Outport: '<Root>/psi_APM' */
  controller_simulink_Y.psi_APM = rtb_psi_APM;

  /* Outport: '<Root>/e_psi_corr' incorporates:
   *  MATLAB Function: '<S3>/MATLAB Function'
   */
  controller_simulink_Y.e_psi_corr = e_psi_corr;

  /* Outport: '<Root>/psi_ref_APM' */
  controller_simulink_Y.psi_ref_APM = rtb_err_psi_ref_APM;

  /* Update for UnitDelay: '<S3>/Unit Delay' incorporates:
   *  Inport: '<Root>/number_path'
   *  Inport: '<Root>/v_ref'
   *  Inport: '<Root>/x_ref'
   *  Inport: '<Root>/y_ref'
   *  Inport: '<Root>/z_ref'
   *  MATLAB Function: '<S3>/MATLAB Function'
   */
  controller_simulink_DWork.UnitDelay_DSTATE.x_ref = controller_simulink_U.x_ref;
  controller_simulink_DWork.UnitDelay_DSTATE.y_ref = controller_simulink_U.y_ref;
  controller_simulink_DWork.UnitDelay_DSTATE.z_ref = controller_simulink_U.z_ref;
  controller_simulink_DWork.UnitDelay_DSTATE.v_ref = controller_simulink_U.v_ref;
  controller_simulink_DWork.UnitDelay_DSTATE.x_old_ref = x_old_ref;
  controller_simulink_DWork.UnitDelay_DSTATE.y_old_ref = y_old_ref;
  controller_simulink_DWork.UnitDelay_DSTATE.psi_ref = psi_ref;
  controller_simulink_DWork.UnitDelay_DSTATE.path_number =
    controller_simulink_U.number_path;
  controller_simulink_DWork.UnitDelay_DSTATE.tangent[0] = tangent_not_normed[0];
  controller_simulink_DWork.UnitDelay_DSTATE.tangent[1] = tangent_not_normed[1];
  controller_simulink_DWork.UnitDelay_DSTATE.normal[0] = normal_not_normal[0];
  controller_simulink_DWork.UnitDelay_DSTATE.normal[1] = normal_not_normal[1];

  /* Update for DiscreteTransferFcn: '<S7>/Discrete Transfer Fcn' */
  controller_simulink_DWork.DiscreteTransferFcn_DSTATE = DiscreteTransferFcn_tmp;

  /* Update for DiscreteTransferFcn: '<S10>/Discrete Transfer Fcn' */
  controller_simulink_DWork.DiscreteTransferFcn_DSTATE_m =
    DiscreteTransferFcn_tmp_f;

  /* Update for DiscreteTransferFcn: '<S7>/Discrete Transfer Fcn1' */
  controller_simulink_DWork.DiscreteTransferFcn1_DSTATE =
    DiscreteTransferFcn1_tmp;

  /* Update for DiscreteTransferFcn: '<S9>/Discrete Transfer Fcn' */
  controller_simulink_DWork.DiscreteTransferFcn_DSTATE_o =
    DiscreteTransferFcn_tmp_l;
}

/* Model initialize function */
void controller_simulink_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(controller_simulink_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&controller_simulink_DWork, 0,
                sizeof(D_Work_controller_simulink));

  /* external inputs */
  (void) memset((void *)&controller_simulink_U, 0,
                sizeof(ExternalInputs_controller_simul));

  /* external outputs */
  (void) memset((void *)&controller_simulink_Y, 0,
                sizeof(ExternalOutputs_controller_simu));

  /* Start for DataStoreMemory: '<S19>/Data Store Memory' */
  memcpy(&controller_simulink_DWork.A[0],
         &controller_simulink_P.DataStoreMemory_InitialValue[0], 60U * sizeof
         (real_T));

  /* Start for DataStoreMemory: '<S8>/Data Store Memory' */
  memcpy(&controller_simulink_DWork.r[0],
         &controller_simulink_P.DataStoreMemory_InitialValue_d[0], 400U * sizeof
         (real_T));

  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay' */
  controller_simulink_DWork.UnitDelay_DSTATE =
    controller_simulink_P.UnitDelay_X0;

  /* InitializeConditions for UnitDelay: '<S11>/Unit Delay' */
  controller_simulink_DWork.UnitDelay_DSTATE_a =
    controller_simulink_P.UnitDelay_X0_l;

  /* InitializeConditions for DiscreteTransferFcn: '<S7>/Discrete Transfer Fcn' */
  controller_simulink_DWork.DiscreteTransferFcn_DSTATE =
    controller_simulink_P.DiscreteTransferFcn_InitialStat;

  /* InitializeConditions for DiscreteTransferFcn: '<S10>/Discrete Transfer Fcn' */
  controller_simulink_DWork.DiscreteTransferFcn_DSTATE_m =
    controller_simulink_P.DiscreteTransferFcn_InitialSt_o;

  /* InitializeConditions for DiscreteTransferFcn: '<S7>/Discrete Transfer Fcn1' */
  controller_simulink_DWork.DiscreteTransferFcn1_DSTATE =
    controller_simulink_P.DiscreteTransferFcn1_InitialSta;

  /* InitializeConditions for DiscreteTransferFcn: '<S9>/Discrete Transfer Fcn' */
  controller_simulink_DWork.DiscreteTransferFcn_DSTATE_o =
    controller_simulink_P.DiscreteTransferFcn_InitialSt_e;
}

/* Model terminate function */
void controller_simulink_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
