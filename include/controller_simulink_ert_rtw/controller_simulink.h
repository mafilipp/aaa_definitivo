/*
 * File: controller_simulink.h
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

#ifndef RTW_HEADER_controller_simulink_h_
#define RTW_HEADER_controller_simulink_h_
#ifndef controller_simulink_COMMON_INCLUDES_
# define controller_simulink_COMMON_INCLUDES_
#include <stddef.h>
#include <math.h>
#include <string.h>
#include "rtwtypes.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#endif                                 /* controller_simulink_COMMON_INCLUDES_ */

#include "controller_simulink_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  bus_errcalc UnitDelay_DSTATE;        /* '<S3>/Unit Delay' */
  real_T UnitDelay_DSTATE_a;           /* '<S11>/Unit Delay' */
  real_T DiscreteTransferFcn_DSTATE;   /* '<S7>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_DSTATE_m; /* '<S10>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn1_DSTATE;  /* '<S7>/Discrete Transfer Fcn1' */
  real_T DiscreteTransferFcn_DSTATE_o; /* '<S9>/Discrete Transfer Fcn' */
  real_T A[60];                        /* '<S19>/Data Store Memory' */
  real_T r[400];                       /* '<S8>/Data Store Memory' */
} D_Work_controller_simulink;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T x_ref;                        /* '<Root>/x_ref' */
  real_T y_ref;                        /* '<Root>/y_ref' */
  real_T z_ref;                        /* '<Root>/z_ref' */
  real_T dz_ref;                       /* '<Root>/dz_ref' */
  real_T v_ref;                        /* '<Root>/v_ref' */
  real_T number_path;                  /* '<Root>/number_path' */
  real_T x;                            /* '<Root>/x' */
  real_T y;                            /* '<Root>/y' */
  real_T z;                            /* '<Root>/z' */
  real_T phi;                          /* '<Root>/phi' */
  real_T theta;                        /* '<Root>/theta' */
  real_T psi;                          /* '<Root>/psi' */
  real_T dx;                           /* '<Root>/dx' */
  real_T dy;                           /* '<Root>/dy' */
  real_T dz;                           /* '<Root>/dz' */
  real_T roll_L;                       /* '<Root>/roll_L' */
  real_T pitch_L;                      /* '<Root>/pitch_L' */
  real_T yaw_APM;                      /* '<Root>/yaw_APM' */
} ExternalInputs_controller_simul;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T set_thrust;                   /* '<Root>/set_thrust' */
  real_T set_phi;                      /* '<Root>/set_phi' */
  real_T set_theta;                    /* '<Root>/set_theta' */
  real_T set_psi;                      /* '<Root>/set_psi' */
  real_T p_action_thrust;              /* '<Root>/p_action_thrust' */
  real_T i_action_thrust;              /* '<Root>/i_action_thrust' */
  real_T d_action_thrust;              /* '<Root>/d_action_thrust' */
  real_T z_err;                        /* '<Root>/z_err' */
  real_T e_ct;                         /* '<Root>/e_ct' */
  real_T df_delta_pos_ct;              /* '<Root>/df_delta_pos_ct' */
  real_T e_ct_feed;                    /* '<Root>/e_ct_feed' */
  real_T des_cross_rate;               /* '<Root>/des_cross_rate' */
  real_T des_cross_rate_shaped;        /* '<Root>/des_cross_rate_shaped' */
  real_T df_delta_vel_ct;              /* '<Root>/df_delta_vel_ct' */
  real_T des_cross_rate_feed;          /* '<Root>/des_cross_rate_feed' */
  real_T cross_rate_is;                /* '<Root>/cross_rate_is' */
  real_T ct_p_action;                  /* '<Root>/ct_p_action' */
  real_T ct_d_action;                  /* '<Root>/ct_d_action' */
  real_T e_at;                         /* '<Root>/e_at' */
  real_T df_delta_pos_at;              /* '<Root>/df_delta_pos_at' */
  real_T e_at_feed;                    /* '<Root>/e_at_feed' */
  real_T des_along_rate;               /* '<Root>/des_along_rate' */
  real_T des_along_rate_shaped;        /* '<Root>/des_along_rate_shaped' */
  real_T df_delta_vel_at;              /* '<Root>/df_delta_vel_at' */
  real_T des_along_rate_feed;          /* '<Root>/des_along_rate_feed' */
  real_T along_rate_is;                /* '<Root>/along_rate_is' */
  real_T at_p_action;                  /* '<Root>/at_p_action' */
  real_T at_d_action;                  /* '<Root>/at_d_action' */
  real_T psi_ref;                      /* '<Root>/psi_ref' */
  real_T psi_state;                    /* '<Root>/psi_state' */
  real_T e_psi;                        /* '<Root>/e_psi' */
  real_T psi_APM;                      /* '<Root>/psi_APM' */
  real_T e_psi_corr;                   /* '<Root>/e_psi_corr' */
  real_T psi_ref_APM;                  /* '<Root>/psi_ref_APM' */
} ExternalOutputs_controller_simu;

/* Parameters (auto storage) */
struct Parameters_controller_simulink_ {
  bus_errcalc UnitDelay_X0;            /* Expression: bus_errcalc_init
                                        * Referenced by: '<S3>/Unit Delay'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S3>/Gain'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1
                                        * Referenced by: '<S15>/Gain2'
                                        */
  real_T Gain_Gain_i;                  /* Expression: 1
                                        * Referenced by: '<S11>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1
                                        * Referenced by: '<S15>/Gain1'
                                        */
  real_T Gain4_Gain;                   /* Expression: 1
                                        * Referenced by: '<S11>/Gain4'
                                        */
  real_T Gain3_Gain;                   /* Expression: 1
                                        * Referenced by: '<S4>/Gain3'
                                        */
  real_T Gain1_Gain_e;                 /* Expression: 1
                                        * Referenced by: '<S11>/Gain1'
                                        */
  real_T Gain2_Gain_a;                 /* Expression: 1
                                        * Referenced by: '<S11>/Gain2'
                                        */
  real_T Gain10_Gain;                  /* Expression: 1
                                        * Referenced by: '<S15>/Gain10'
                                        */
  real_T Gain5_Gain;                   /* Expression: 1
                                        * Referenced by: '<S11>/Gain5'
                                        */
  real_T hover_thrust_Value;           /* Expression: hover_thrust
                                        * Referenced by: '<S11>/hover_thrust'
                                        */
  real_T c_thrust_K_P_Value;           /* Expression: thrust_K_P
                                        * Referenced by: '<S11>/c_thrust_K_P'
                                        */
  real_T SliderGain_Gain;              /* Expression: gain
                                        * Referenced by: '<S37>/Slider Gain'
                                        */
  real_T c_thrust_K_I_Value;           /* Expression: thrust_K_I
                                        * Referenced by: '<S11>/c_thrust_K_I'
                                        */
  real_T SliderGain_Gain_k;            /* Expression: gain
                                        * Referenced by: '<S36>/Slider Gain'
                                        */
  real_T c_thrust_K_D_Value;           /* Expression: thrust_K_D
                                        * Referenced by: '<S11>/c_thrust_K_D'
                                        */
  real_T SliderGain_Gain_o;            /* Expression: gain
                                        * Referenced by: '<S35>/Slider Gain'
                                        */
  real_T c_thrust_max_P_Value;         /* Expression: thrust_max_P
                                        * Referenced by: '<S11>/c_thrust_max_P'
                                        */
  real_T SliderGain_Gain_m;            /* Expression: gain
                                        * Referenced by: '<S40>/Slider Gain'
                                        */
  real_T c_thrust_max_I_Value;         /* Expression: thrust_max_I
                                        * Referenced by: '<S11>/c_thrust_max_I'
                                        */
  real_T SliderGain_Gain_d;            /* Expression: gain
                                        * Referenced by: '<S39>/Slider Gain'
                                        */
  real_T c_thrust_max_D_Value;         /* Expression: thrust_max_D
                                        * Referenced by: '<S11>/c_thrust_max_D'
                                        */
  real_T SliderGain_Gain_kp;           /* Expression: gain
                                        * Referenced by: '<S38>/Slider Gain'
                                        */
  real_T c_thrust_max_PID_Value;       /* Expression: thrust_max_PID
                                        * Referenced by: '<S11>/c_thrust_max_PID'
                                        */
  real_T SliderGain_Gain_h;            /* Expression: gain
                                        * Referenced by: '<S41>/Slider Gain'
                                        */
  real_T c_thrust_sample_time_Value;   /* Expression: sample_time_sl
                                        * Referenced by: '<S11>/c_thrust_sample_time'
                                        */
  real_T UnitDelay_X0_l;               /* Expression: 0
                                        * Referenced by: '<S11>/Unit Delay'
                                        */
  real_T Gain3_Gain_i;                 /* Expression: 1
                                        * Referenced by: '<S11>/Gain3'
                                        */
  real_T Gain3_Gain_l;                 /* Expression: 1
                                        * Referenced by: '<S15>/Gain3'
                                        */
  real_T Gain5_Gain_g;                 /* Expression: 1
                                        * Referenced by: '<S15>/Gain5'
                                        */
  real_T df_G_d_Value;                 /* Expression: G_d
                                        * Referenced by: '<S7>/df_G_d'
                                        */
  real_T df_l_L_Value;                 /* Expression: l_L
                                        * Referenced by: '<S7>/df_l_L'
                                        */
  real_T df_sign_ct_Value;             /* Expression: df_sign_ct
                                        * Referenced by: '<S7>/df_sign_ct'
                                        */
  real_T Gain1_Gain_d;                 /* Expression: 1
                                        * Referenced by: '<S4>/Gain1'
                                        */
  real_T df_sign_at_Value;             /* Expression: df_sign_at
                                        * Referenced by: '<S7>/df_sign_at'
                                        */
  real_T df_N_delay_Value;             /* Expression: N_delay
                                        * Referenced by: '<S19>/df_N_delay'
                                        */
  real_T Sine_Amp;                     /* Expression: 1
                                        * Referenced by: '<S7>/Sine'
                                        */
  real_T Sine_Bias;                    /* Expression: 0
                                        * Referenced by: '<S7>/Sine'
                                        */
  real_T Sine_Freq;                    /* Expression: 1
                                        * Referenced by: '<S7>/Sine'
                                        */
  real_T Sine_Phase;                   /* Expression: 0
                                        * Referenced by: '<S7>/Sine'
                                        */
  real_T Gain_Gain_o;                  /* Expression: 1
                                        * Referenced by: '<S13>/Gain'
                                        */
  real_T c_cross_pos_K_P_Value;        /* Expression: cross_K_P
                                        * Referenced by: '<S13>/c_cross_pos_K_P'
                                        */
  real_T SliderGain_Gain_l;            /* Expression: gain
                                        * Referenced by: '<S46>/Slider Gain'
                                        */
  real_T c_cross_pos_max_P_Value;      /* Expression: cross_max_P
                                        * Referenced by: '<S13>/c_cross_pos_max_P'
                                        */
  real_T SliderGain_Gain_e;            /* Expression: gain
                                        * Referenced by: '<S47>/Slider Gain'
                                        */
  real_T Gain3_Gain_f;                 /* Expression: 1
                                        * Referenced by: '<S13>/Gain3'
                                        */
  real_T Gain4_Gain_l;                 /* Expression: 1
                                        * Referenced by: '<S15>/Gain4'
                                        */
  real_T Sine1_Amp;                    /* Expression: 1
                                        * Referenced by: '<S7>/Sine1'
                                        */
  real_T Sine1_Bias;                   /* Expression: 0
                                        * Referenced by: '<S7>/Sine1'
                                        */
  real_T Sine1_Freq;                   /* Expression: 1
                                        * Referenced by: '<S7>/Sine1'
                                        */
  real_T Sine1_Phase;                  /* Expression: 0
                                        * Referenced by: '<S7>/Sine1'
                                        */
  real_T Gain_Gain_l;                  /* Expression: 1
                                        * Referenced by: '<S12>/Gain'
                                        */
  real_T Gain7_Gain;                   /* Expression: 1
                                        * Referenced by: '<S15>/Gain7'
                                        */
  real_T c_along_pos_K_P_Value;        /* Expression: along_K_P
                                        * Referenced by: '<S12>/c_along_pos_K_P'
                                        */
  real_T SliderGain_Gain_n;            /* Expression: gain
                                        * Referenced by: '<S43>/Slider Gain'
                                        */
  real_T c_along_pos_max_P_Value;      /* Expression: along_max_P
                                        * Referenced by: '<S12>/c_along_pos_max_P'
                                        */
  real_T SliderGain_Gain_dz;           /* Expression: gain
                                        * Referenced by: '<S44>/Slider Gain'
                                        */
  real_T Gain3_Gain_k;                 /* Expression: 1
                                        * Referenced by: '<S12>/Gain3'
                                        */
  real_T is_on_Value;                  /* Expression: is_on
                                        * Referenced by: '<S8>/is_on'
                                        */
  real_T is_N_impulses_Value;          /* Expression: is_N_impulses
                                        * Referenced by: '<S8>/is_N_impulses'
                                        */
  real_T is_A_Value[10];               /* Expression: is_A
                                        * Referenced by: '<S8>/is_A'
                                        */
  real_T is_N_r_Value[10];             /* Expression: is_N_r
                                        * Referenced by: '<S8>/is_N_r'
                                        */
  real_T DiscreteTransferFcn_InitialStat;/* Expression: 0
                                          * Referenced by: '<S7>/Discrete Transfer Fcn'
                                          */
  real_T DiscreteTransferFcn_NumCoef[2];/* Expression: washout_der_d.num{1}
                                         * Referenced by: '<S7>/Discrete Transfer Fcn'
                                         */
  real_T DiscreteTransferFcn_DenCoef[2];/* Expression: washout_der_d.den{1}
                                         * Referenced by: '<S7>/Discrete Transfer Fcn'
                                         */
  real_T Cosine_Amp;                   /* Expression: 1
                                        * Referenced by: '<S7>/Cosine'
                                        */
  real_T Cosine_Bias;                  /* Expression: 0
                                        * Referenced by: '<S7>/Cosine'
                                        */
  real_T Cosine_Freq;                  /* Expression: 1
                                        * Referenced by: '<S7>/Cosine'
                                        */
  real_T Cosine_Phase;                 /* Expression: pi/2
                                        * Referenced by: '<S7>/Cosine'
                                        */
  real_T Gain_Gain_g;                  /* Expression: 1
                                        * Referenced by: '<S10>/Gain'
                                        */
  real_T Gain9_Gain;                   /* Expression: 1
                                        * Referenced by: '<S15>/Gain9'
                                        */
  real_T Gain1_Gain_f;                 /* Expression: 1
                                        * Referenced by: '<S10>/Gain1'
                                        */
  real_T DiscreteTransferFcn_InitialSt_o;/* Expression: 0
                                          * Referenced by: '<S10>/Discrete Transfer Fcn'
                                          */
  real_T DiscreteTransferFcn_NumCoef_g[2];/* Expression: washout_der_acc_d.num{1}
                                           * Referenced by: '<S10>/Discrete Transfer Fcn'
                                           */
  real_T DiscreteTransferFcn_DenCoef_i[2];/* Expression: washout_der_acc_d.den{1}
                                           * Referenced by: '<S10>/Discrete Transfer Fcn'
                                           */
  real_T Gain2_Gain_m;                 /* Expression: -1
                                        * Referenced by: '<S10>/Gain2'
                                        */
  real_T c_cross_rate_K_P_Value;       /* Expression: cross_rate_K_P
                                        * Referenced by: '<S10>/c_cross_rate_K_P'
                                        */
  real_T SliderGain_Gain_c;            /* Expression: gain
                                        * Referenced by: '<S30>/Slider Gain'
                                        */
  real_T c_cross_rate_K_D_Value;       /* Expression: cross_rate_K_D
                                        * Referenced by: '<S10>/c_cross_rate_K_D'
                                        */
  real_T SliderGain_Gain_oo;           /* Expression: gain
                                        * Referenced by: '<S29>/Slider Gain'
                                        */
  real_T c_cross_rate_max_P_Value;     /* Expression: cross_rate_max_P
                                        * Referenced by: '<S10>/c_cross_rate_max_P'
                                        */
  real_T SliderGain_Gain_g;            /* Expression: gain
                                        * Referenced by: '<S32>/Slider Gain'
                                        */
  real_T c_cross_rate_max_D_Value;     /* Expression: cross_rate_max_D
                                        * Referenced by: '<S10>/c_cross_rate_max_D'
                                        */
  real_T SliderGain_Gain_mf;           /* Expression: gain
                                        * Referenced by: '<S31>/Slider Gain'
                                        */
  real_T c_cross_rate_max_PD_Value;    /* Expression: cross_rate_max_PD
                                        * Referenced by: '<S10>/c_cross_rate_max_PD'
                                        */
  real_T SliderGain_Gain_m5;           /* Expression: gain
                                        * Referenced by: '<S33>/Slider Gain'
                                        */
  real_T Gain3_Gain_b;                 /* Expression: 1
                                        * Referenced by: '<S10>/Gain3'
                                        */
  real_T Cosine1_Amp;                  /* Expression: 1
                                        * Referenced by: '<S7>/Cosine1'
                                        */
  real_T Cosine1_Bias;                 /* Expression: 0
                                        * Referenced by: '<S7>/Cosine1'
                                        */
  real_T Cosine1_Freq;                 /* Expression: 1
                                        * Referenced by: '<S7>/Cosine1'
                                        */
  real_T Cosine1_Phase;                /* Expression: pi/2
                                        * Referenced by: '<S7>/Cosine1'
                                        */
  real_T DiscreteTransferFcn1_InitialSta;/* Expression: 0
                                          * Referenced by: '<S7>/Discrete Transfer Fcn1'
                                          */
  real_T DiscreteTransferFcn1_NumCoef[2];/* Expression: washout_der_d.num{1}
                                          * Referenced by: '<S7>/Discrete Transfer Fcn1'
                                          */
  real_T DiscreteTransferFcn1_DenCoef[2];/* Expression: washout_der_d.den{1}
                                          * Referenced by: '<S7>/Discrete Transfer Fcn1'
                                          */
  real_T Gain_Gain_lx;                 /* Expression: 1
                                        * Referenced by: '<S9>/Gain'
                                        */
  real_T Gain8_Gain;                   /* Expression: 1
                                        * Referenced by: '<S15>/Gain8'
                                        */
  real_T Gain1_Gain_b;                 /* Expression: 1
                                        * Referenced by: '<S9>/Gain1'
                                        */
  real_T DiscreteTransferFcn_InitialSt_e;/* Expression: 0
                                          * Referenced by: '<S9>/Discrete Transfer Fcn'
                                          */
  real_T DiscreteTransferFcn_NumCoef_d[2];/* Expression: washout_der_acc_d.num{1}
                                           * Referenced by: '<S9>/Discrete Transfer Fcn'
                                           */
  real_T DiscreteTransferFcn_DenCoef_p[2];/* Expression: washout_der_acc_d.den{1}
                                           * Referenced by: '<S9>/Discrete Transfer Fcn'
                                           */
  real_T Gain2_Gain_l;                 /* Expression: -1
                                        * Referenced by: '<S9>/Gain2'
                                        */
  real_T c_along_rate_K_P_Value;       /* Expression: along_rate_K_P
                                        * Referenced by: '<S9>/c_along_rate_K_P'
                                        */
  real_T SliderGain_Gain_f;            /* Expression: gain
                                        * Referenced by: '<S24>/Slider Gain'
                                        */
  real_T c_along_rate_K_D_Value;       /* Expression: along_rate_K_D
                                        * Referenced by: '<S9>/c_along_rate_K_D'
                                        */
  real_T SliderGain_Gain_eb;           /* Expression: gain
                                        * Referenced by: '<S23>/Slider Gain'
                                        */
  real_T c_along_rate_max_P_Value;     /* Expression: along_rate_max_P
                                        * Referenced by: '<S9>/c_along_rate_max_P'
                                        */
  real_T SliderGain_Gain_a;            /* Expression: gain
                                        * Referenced by: '<S26>/Slider Gain'
                                        */
  real_T c_along_rate_max_D_Value;     /* Expression: along_rate_max_D
                                        * Referenced by: '<S9>/c_along_rate_max_D'
                                        */
  real_T SliderGain_Gain_p;            /* Expression: gain
                                        * Referenced by: '<S25>/Slider Gain'
                                        */
  real_T c_along_rate_max_PD_Value;    /* Expression: along_rate_max_PD
                                        * Referenced by: '<S9>/c_along_rate_max_PD'
                                        */
  real_T SliderGain_Gain_i;            /* Expression: gain
                                        * Referenced by: '<S27>/Slider Gain'
                                        */
  real_T Gain3_Gain_h;                 /* Expression: 1
                                        * Referenced by: '<S9>/Gain3'
                                        */
  real_T RadToDeg_Gain;                /* Expression: -DegX100
                                        * Referenced by: '<S4>/RadToDeg'
                                        */
  real_T RadToDeg1_Gain;               /* Expression: -DegX100
                                        * Referenced by: '<S4>/RadToDeg1'
                                        */
  real_T Gain6_Gain;                   /* Expression: 1
                                        * Referenced by: '<S15>/Gain6'
                                        */
  real_T RadToDeg2_Gain;               /* Expression: -DegX100
                                        * Referenced by: '<S4>/RadToDeg2'
                                        */
  real_T Gain4_Gain_c;                 /* Expression: 1
                                        * Referenced by: '<S4>/Gain4'
                                        */
  real_T DataStoreMemory_InitialValue[60];/* Expression: zeros(2,N_delay_max)
                                           * Referenced by: '<S19>/Data Store Memory'
                                           */
  real_T DataStoreMemory_InitialValue_d[400];/* Expression: zeros(2,N_r_max)
                                              * Referenced by: '<S8>/Data Store Memory'
                                              */
};

/* Real-time Model Data Structure */
struct RT_MODEL_controller_simulink {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern Parameters_controller_simulink controller_simulink_P;

/* Block states (auto storage) */
extern D_Work_controller_simulink controller_simulink_DWork;

/* External inputs (root inport signals with auto storage) */
#ifdef __cplusplus

extern "C" {

#endif

  extern ExternalInputs_controller_simul controller_simulink_U;

#ifdef __cplusplus

}
#endif

/* External outputs (root outports fed by signals with auto storage) */
#ifdef __cplusplus

extern "C" {

#endif

  extern ExternalOutputs_controller_simu controller_simulink_Y;

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  /* Model entry point functions */
  extern void controller_simulink_initialize(void);
  extern void controller_simulink_step(void);
  extern void controller_simulink_terminate(void);

#ifdef __cplusplus

}
#endif

/* Real-time Model object */
#ifdef __cplusplus

extern "C" {

#endif

  extern struct RT_MODEL_controller_simulink *const controller_simulink_M;

#ifdef __cplusplus

}
#endif

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'controller_simulink'
 * '<S1>'   : 'controller_simulink/controller'
 * '<S2>'   : 'controller_simulink/controller/controller'
 * '<S3>'   : 'controller_simulink/controller/error_calculation'
 * '<S4>'   : 'controller_simulink/controller/controller/Controller'
 * '<S5>'   : 'controller_simulink/controller/controller/Controller/Coordinate Transformation'
 * '<S6>'   : 'controller_simulink/controller/controller/Controller/CoordinateTrasform'
 * '<S7>'   : 'controller_simulink/controller/controller/Controller/Delayed Feedback Control'
 * '<S8>'   : 'controller_simulink/controller/controller/Controller/Input Shaper'
 * '<S9>'   : 'controller_simulink/controller/controller/Controller/PD_AlongTrack'
 * '<S10>'  : 'controller_simulink/controller/controller/Controller/PD_CrossTrack'
 * '<S11>'  : 'controller_simulink/controller/controller/Controller/PID_Thrust'
 * '<S12>'  : 'controller_simulink/controller/controller/Controller/P_AlongTrack'
 * '<S13>'  : 'controller_simulink/controller/controller/Controller/P_CrossTrack'
 * '<S14>'  : 'controller_simulink/controller/controller/Controller/Scopes'
 * '<S15>'  : 'controller_simulink/controller/controller/Controller/Select'
 * '<S16>'  : 'controller_simulink/controller/controller/Controller/get_used_states'
 * '<S17>'  : 'controller_simulink/controller/controller/Controller/Coordinate Transformation/MATLAB Function'
 * '<S18>'  : 'controller_simulink/controller/controller/Controller/CoordinateTrasform/MATLAB Function'
 * '<S19>'  : 'controller_simulink/controller/controller/Controller/Delayed Feedback Control/Delay2'
 * '<S20>'  : 'controller_simulink/controller/controller/Controller/Delayed Feedback Control/Delay2/Delay_feedback'
 * '<S21>'  : 'controller_simulink/controller/controller/Controller/Input Shaper/input_shaper'
 * '<S22>'  : 'controller_simulink/controller/controller/Controller/PD_AlongTrack/PD_CTRL'
 * '<S23>'  : 'controller_simulink/controller/controller/Controller/PD_AlongTrack/along_rate_K_D'
 * '<S24>'  : 'controller_simulink/controller/controller/Controller/PD_AlongTrack/along_rate_K_P'
 * '<S25>'  : 'controller_simulink/controller/controller/Controller/PD_AlongTrack/along_rate_max_d'
 * '<S26>'  : 'controller_simulink/controller/controller/Controller/PD_AlongTrack/along_rate_max_p'
 * '<S27>'  : 'controller_simulink/controller/controller/Controller/PD_AlongTrack/along_rate_max_pd'
 * '<S28>'  : 'controller_simulink/controller/controller/Controller/PD_CrossTrack/PD_CTRL'
 * '<S29>'  : 'controller_simulink/controller/controller/Controller/PD_CrossTrack/cross_rate_K_D'
 * '<S30>'  : 'controller_simulink/controller/controller/Controller/PD_CrossTrack/cross_rate_K_P'
 * '<S31>'  : 'controller_simulink/controller/controller/Controller/PD_CrossTrack/cross_rate_max_d'
 * '<S32>'  : 'controller_simulink/controller/controller/Controller/PD_CrossTrack/cross_rate_max_p'
 * '<S33>'  : 'controller_simulink/controller/controller/Controller/PD_CrossTrack/cross_rate_max_pd'
 * '<S34>'  : 'controller_simulink/controller/controller/Controller/PID_Thrust/PID_CTRL'
 * '<S35>'  : 'controller_simulink/controller/controller/Controller/PID_Thrust/thrust_K_D'
 * '<S36>'  : 'controller_simulink/controller/controller/Controller/PID_Thrust/thrust_K_I'
 * '<S37>'  : 'controller_simulink/controller/controller/Controller/PID_Thrust/thrust_K_P'
 * '<S38>'  : 'controller_simulink/controller/controller/Controller/PID_Thrust/thrust_max_d'
 * '<S39>'  : 'controller_simulink/controller/controller/Controller/PID_Thrust/thrust_max_i'
 * '<S40>'  : 'controller_simulink/controller/controller/Controller/PID_Thrust/thrust_max_p'
 * '<S41>'  : 'controller_simulink/controller/controller/Controller/PID_Thrust/thrust_max_pid'
 * '<S42>'  : 'controller_simulink/controller/controller/Controller/P_AlongTrack/P_CTRL'
 * '<S43>'  : 'controller_simulink/controller/controller/Controller/P_AlongTrack/along_pos_K_P'
 * '<S44>'  : 'controller_simulink/controller/controller/Controller/P_AlongTrack/along_pos_max_p'
 * '<S45>'  : 'controller_simulink/controller/controller/Controller/P_CrossTrack/P_CTRL'
 * '<S46>'  : 'controller_simulink/controller/controller/Controller/P_CrossTrack/cross_pos_K_P'
 * '<S47>'  : 'controller_simulink/controller/controller/Controller/P_CrossTrack/cross_pos_max_p'
 * '<S48>'  : 'controller_simulink/controller/error_calculation/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_controller_simulink_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
