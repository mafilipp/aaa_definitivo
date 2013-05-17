/*
 * File: controller_simulink_types.h
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

#ifndef RTW_HEADER_controller_simulink_types_h_
#define RTW_HEADER_controller_simulink_types_h_
#include "rtwtypes.h"
#ifndef _DEFINED_TYPEDEF_FOR_struct_5jc41sWLni661nuL4jHweG_
#define _DEFINED_TYPEDEF_FOR_struct_5jc41sWLni661nuL4jHweG_

typedef struct {
  real_T x_ref;
  real_T y_ref;
  real_T z_ref;
  real_T v_ref;
  real_T x_old_ref;
  real_T y_old_ref;
  real_T psi_ref;
  real_T path_number;
  real_T tangent[2];
  real_T normal[2];
} struct_5jc41sWLni661nuL4jHweG;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_struct_FH1iJ8dWNBTaY8ztXaMW2D_
#define _DEFINED_TYPEDEF_FOR_struct_FH1iJ8dWNBTaY8ztXaMW2D_

typedef struct {
  real_T thrust;
  real_T at_rate;
  real_T ct_pos;
} struct_FH1iJ8dWNBTaY8ztXaMW2D;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_struct_kZEP5F0i6eloNuvt9tvgkD_
#define _DEFINED_TYPEDEF_FOR_struct_kZEP5F0i6eloNuvt9tvgkD_

typedef struct {
  real_T e_z;
  real_T e_d_z;
  real_T e_psi;
  real_T e_at;
  real_T e_d_at;
  real_T e_ct;
  real_T e_d_ct;
  real_T psi_ref_APM;
  real_T at_rate_ref;
  real_T at_rate_is;
  real_T ct_rate_is;
  struct_FH1iJ8dWNBTaY8ztXaMW2D reset_Integrator;
} struct_kZEP5F0i6eloNuvt9tvgkD;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_bus_reset_integrator_
#define _DEFINED_TYPEDEF_FOR_bus_reset_integrator_

typedef struct_FH1iJ8dWNBTaY8ztXaMW2D bus_reset_integrator;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_bus_errors_
#define _DEFINED_TYPEDEF_FOR_bus_errors_

typedef struct_kZEP5F0i6eloNuvt9tvgkD bus_errors;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_bus_errcalc_
#define _DEFINED_TYPEDEF_FOR_bus_errcalc_

typedef struct_5jc41sWLni661nuL4jHweG bus_errcalc;

#endif

/* Parameters (auto storage) */
typedef struct Parameters_controller_simulink_ Parameters_controller_simulink;

/* Forward declaration for rtModel */
typedef struct RT_MODEL_controller_simulink RT_MODEL_controller_simulink;

#endif                                 /* RTW_HEADER_controller_simulink_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
