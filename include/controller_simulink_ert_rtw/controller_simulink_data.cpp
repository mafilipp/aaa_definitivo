/*
 * File: controller_simulink_data.cpp
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

/* Block parameters (auto storage) */
Parameters_controller_simulink controller_simulink_P = {
  {
    0.0,                               /* x_ref */
    0.0,                               /* y_ref */
    0.0,                               /* z_ref */
    0.0,                               /* v_ref */
    0.0,                               /* x_old_ref */
    0.0,                               /* y_old_ref */
    0.0,                               /* psi_ref */
    0.0,                               /* path_number */

    {
      0.0, 0.0 }
    ,                                  /* tangent */

    {
      0.0, 0.0 }
    /* normal */
  },                                   /* Expression: bus_errcalc_init
                                        * Referenced by: '<S3>/Unit Delay'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S3>/Gain'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S15>/Gain2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S11>/Gain'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S15>/Gain1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S11>/Gain4'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S4>/Gain3'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S11>/Gain1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S11>/Gain2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S15>/Gain10'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S11>/Gain5'
                                        */
  371.03614412991516,                  /* Expression: hover_thrust
                                        * Referenced by: '<S11>/hover_thrust'
                                        */
  15.0,                                /* Expression: thrust_K_P
                                        * Referenced by: '<S11>/c_thrust_K_P'
                                        */
  1.0,                                 /* Expression: gain
                                        * Referenced by: '<S37>/Slider Gain'
                                        */
  0.0,                                 /* Expression: thrust_K_I
                                        * Referenced by: '<S11>/c_thrust_K_I'
                                        */
  1.0,                                 /* Expression: gain
                                        * Referenced by: '<S36>/Slider Gain'
                                        */
  30.0,                                /* Expression: thrust_K_D
                                        * Referenced by: '<S11>/c_thrust_K_D'
                                        */
  1.0,                                 /* Expression: gain
                                        * Referenced by: '<S35>/Slider Gain'
                                        */
  800.0,                               /* Expression: thrust_max_P
                                        * Referenced by: '<S11>/c_thrust_max_P'
                                        */
  1.0,                                 /* Expression: gain
                                        * Referenced by: '<S40>/Slider Gain'
                                        */
  800.0,                               /* Expression: thrust_max_I
                                        * Referenced by: '<S11>/c_thrust_max_I'
                                        */
  1.0,                                 /* Expression: gain
                                        * Referenced by: '<S39>/Slider Gain'
                                        */
  800.0,                               /* Expression: thrust_max_D
                                        * Referenced by: '<S11>/c_thrust_max_D'
                                        */
  1.0,                                 /* Expression: gain
                                        * Referenced by: '<S38>/Slider Gain'
                                        */
  800.0,                               /* Expression: thrust_max_PID
                                        * Referenced by: '<S11>/c_thrust_max_PID'
                                        */
  1.0,                                 /* Expression: gain
                                        * Referenced by: '<S41>/Slider Gain'
                                        */
  0.033333333333333333,                /* Expression: sample_time_sl
                                        * Referenced by: '<S11>/c_thrust_sample_time'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Unit Delay'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S11>/Gain3'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S15>/Gain3'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S15>/Gain5'
                                        */
  0.0,                                 /* Expression: G_d
                                        * Referenced by: '<S7>/df_G_d'
                                        */
  0.89999999999999991,                 /* Expression: l_L
                                        * Referenced by: '<S7>/df_l_L'
                                        */
  1.0,                                 /* Expression: df_sign_ct
                                        * Referenced by: '<S7>/df_sign_ct'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S4>/Gain1'
                                        */
  1.0,                                 /* Expression: df_sign_at
                                        * Referenced by: '<S7>/df_sign_at'
                                        */
  19.0,                                /* Expression: N_delay
                                        * Referenced by: '<S19>/df_N_delay'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S7>/Sine'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Sine'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S7>/Sine'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Sine'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S13>/Gain'
                                        */
  1.5,                                 /* Expression: cross_K_P
                                        * Referenced by: '<S13>/c_cross_pos_K_P'
                                        */
  1.0,                                 /* Expression: gain
                                        * Referenced by: '<S46>/Slider Gain'
                                        */
  1000.0,                              /* Expression: cross_max_P
                                        * Referenced by: '<S13>/c_cross_pos_max_P'
                                        */
  1.0,                                 /* Expression: gain
                                        * Referenced by: '<S47>/Slider Gain'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S13>/Gain3'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S15>/Gain4'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S7>/Sine1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Sine1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S7>/Sine1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Sine1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S12>/Gain'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S15>/Gain7'
                                        */
  1.5,                                 /* Expression: along_K_P
                                        * Referenced by: '<S12>/c_along_pos_K_P'
                                        */
  1.0,                                 /* Expression: gain
                                        * Referenced by: '<S43>/Slider Gain'
                                        */
  1000.0,                              /* Expression: along_max_P
                                        * Referenced by: '<S12>/c_along_pos_max_P'
                                        */
  1.0,                                 /* Expression: gain
                                        * Referenced by: '<S44>/Slider Gain'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S12>/Gain3'
                                        */
  1.0,                                 /* Expression: is_on
                                        * Referenced by: '<S8>/is_on'
                                        */
  2.0,                                 /* Expression: is_N_impulses
                                        * Referenced by: '<S8>/is_N_impulses'
                                        */

  /*  Expression: is_A
   * Referenced by: '<S8>/is_A'
   */
  { 0.57828618165359158, 0.57828618165359158, 0.42171381834640836,
    0.42171381834640836, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /*  Expression: is_N_r
   * Referenced by: '<S8>/is_N_r'
   */
  { 0.0, 0.0, 189.0, 189.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Discrete Transfer Fcn'
                                        */

  /*  Expression: washout_der_d.num{1}
   * Referenced by: '<S7>/Discrete Transfer Fcn'
   */
  { 5.0, -5.0 },

  /*  Expression: washout_der_d.den{1}
   * Referenced by: '<S7>/Discrete Transfer Fcn'
   */
  { 1.0, -0.951229424500714 },
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S7>/Cosine'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Cosine'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S7>/Cosine'
                                        */
  1.5707963267948966,                  /* Expression: pi/2
                                        * Referenced by: '<S7>/Cosine'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S10>/Gain'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S15>/Gain9'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S10>/Gain1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Discrete Transfer Fcn'
                                        */

  /*  Expression: washout_der_acc_d.num{1}
   * Referenced by: '<S10>/Discrete Transfer Fcn'
   */
  { 6.666666666666667, -6.666666666666667 },

  /*  Expression: washout_der_acc_d.den{1}
   * Referenced by: '<S10>/Discrete Transfer Fcn'
   */
  { 1.0, -0.93550698503161767 },
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S10>/Gain2'
                                        */
  0.2,                                 /* Expression: cross_rate_K_P
                                        * Referenced by: '<S10>/c_cross_rate_K_P'
                                        */
  1.0,                                 /* Expression: gain
                                        * Referenced by: '<S30>/Slider Gain'
                                        */
  0.0,                                 /* Expression: cross_rate_K_D
                                        * Referenced by: '<S10>/c_cross_rate_K_D'
                                        */
  1.0,                                 /* Expression: gain
                                        * Referenced by: '<S29>/Slider Gain'
                                        */
  1000.0,                              /* Expression: cross_rate_max_P
                                        * Referenced by: '<S10>/c_cross_rate_max_P'
                                        */
  1.0,                                 /* Expression: gain
                                        * Referenced by: '<S32>/Slider Gain'
                                        */
  1000.0,                              /* Expression: cross_rate_max_D
                                        * Referenced by: '<S10>/c_cross_rate_max_D'
                                        */
  1.0,                                 /* Expression: gain
                                        * Referenced by: '<S31>/Slider Gain'
                                        */
  1000.0,                              /* Expression: cross_rate_max_PD
                                        * Referenced by: '<S10>/c_cross_rate_max_PD'
                                        */
  1.0,                                 /* Expression: gain
                                        * Referenced by: '<S33>/Slider Gain'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S10>/Gain3'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S7>/Cosine1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Cosine1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S7>/Cosine1'
                                        */
  1.5707963267948966,                  /* Expression: pi/2
                                        * Referenced by: '<S7>/Cosine1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Discrete Transfer Fcn1'
                                        */

  /*  Expression: washout_der_d.num{1}
   * Referenced by: '<S7>/Discrete Transfer Fcn1'
   */
  { 5.0, -5.0 },

  /*  Expression: washout_der_d.den{1}
   * Referenced by: '<S7>/Discrete Transfer Fcn1'
   */
  { 1.0, -0.951229424500714 },
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S9>/Gain'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S15>/Gain8'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S9>/Gain1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Discrete Transfer Fcn'
                                        */

  /*  Expression: washout_der_acc_d.num{1}
   * Referenced by: '<S9>/Discrete Transfer Fcn'
   */
  { 6.666666666666667, -6.666666666666667 },

  /*  Expression: washout_der_acc_d.den{1}
   * Referenced by: '<S9>/Discrete Transfer Fcn'
   */
  { 1.0, -0.93550698503161767 },
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S9>/Gain2'
                                        */
  0.2,                                 /* Expression: along_rate_K_P
                                        * Referenced by: '<S9>/c_along_rate_K_P'
                                        */
  1.0,                                 /* Expression: gain
                                        * Referenced by: '<S24>/Slider Gain'
                                        */
  0.0,                                 /* Expression: along_rate_K_D
                                        * Referenced by: '<S9>/c_along_rate_K_D'
                                        */
  1.0,                                 /* Expression: gain
                                        * Referenced by: '<S23>/Slider Gain'
                                        */
  1000.0,                              /* Expression: along_rate_max_P
                                        * Referenced by: '<S9>/c_along_rate_max_P'
                                        */
  1.0,                                 /* Expression: gain
                                        * Referenced by: '<S26>/Slider Gain'
                                        */
  1000.0,                              /* Expression: along_rate_max_D
                                        * Referenced by: '<S9>/c_along_rate_max_D'
                                        */
  1.0,                                 /* Expression: gain
                                        * Referenced by: '<S25>/Slider Gain'
                                        */
  1000.0,                              /* Expression: along_rate_max_PD
                                        * Referenced by: '<S9>/c_along_rate_max_PD'
                                        */
  1.0,                                 /* Expression: gain
                                        * Referenced by: '<S27>/Slider Gain'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S9>/Gain3'
                                        */
  -5729.57795,                         /* Expression: -DegX100
                                        * Referenced by: '<S4>/RadToDeg'
                                        */
  -5729.57795,                         /* Expression: -DegX100
                                        * Referenced by: '<S4>/RadToDeg1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S15>/Gain6'
                                        */
  -5729.57795,                         /* Expression: -DegX100
                                        * Referenced by: '<S4>/RadToDeg2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S4>/Gain4'
                                        */

  /*  Expression: zeros(2,N_delay_max)
   * Referenced by: '<S19>/Data Store Memory'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /*  Expression: zeros(2,N_r_max)
   * Referenced by: '<S8>/Data Store Memory'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
