
//==============================================================================
//
//                                  DENIS Project 
//
//------------------------------------------------------------------------------
//
//  -- C File created for the DENIS Project --
//
// This file has been automatically created using the CellML API and a CellML
// file to construct a BOINC program.
//
//------------------------------------------------------------------------------
//
//                                                        San Jorge University
//                                                       School of Engineering
//
//                                                           http://eps.usj.es
//
//==============================================================================

#include "fmath.h"

// Save in the inputs the number of elements in the vectors.
void vectorsLength(int* algebraicLength, int* statesLength, int* constantsLength){
	*algebraicLength = 118;
	*statesLength = 40;
	*constantsLength = 124;
}

void names(const char* &VoI, const char** constants, const char** rates, const char** states, const char** algebraic){
	VoI = "t in component environment (millisecond)";
	states[0] = "V in component membrane (millivolt)";
	constants[0] = "R in component membrane (joule_per_kmole_kelvin)";
	constants[1] = "T in component membrane (kelvin)";
	constants[2] = "Frdy in component membrane (coulomb_per_mole)";
	constants[108] = "FoRT in component membrane (per_milliV)";
	constants[3] = "C_mem in component membrane (farad)";
	algebraic[96] = "I_Na_tot_junc in component Sodium_Concentrations (picoA_per_picoF)";
	algebraic[102] = "I_Na_tot_sl in component Sodium_Concentrations (picoA_per_picoF)";
	algebraic[57] = "I_ClCa in component Ca_Activated_Cl_Current (picoA_per_picoF)";
	algebraic[58] = "I_Cl_Bk in component Background_Cl_Current (picoA_per_picoF)";
	algebraic[111] = "I_Ca_tot_junc in component Calcium_Concentrations (picoA_per_picoF)";
	algebraic[114] = "I_Ca_tot_sl in component Calcium_Concentrations (picoA_per_picoF)";
	algebraic[108] = "I_K_tot in component Potassium_Concentrations (picoA_per_picoF)";
	algebraic[103] = "I_Na_tot in component membrane (picoA_per_picoF)";
	algebraic[59] = "I_Cl_tot in component membrane (picoA_per_picoF)";
	algebraic[116] = "I_Ca_tot in component membrane (picoA_per_picoF)";
	algebraic[117] = "I_tot in component membrane (picoA_per_picoF)";
	algebraic[10] = "I_Stim in component membrane (picoA_per_picoF)";
	constants[4] = "I_Stim_Start in component membrane (millisecond)";
	constants[5] = "I_Stim_Amplitude in component membrane (picoA_per_picoF)";
	constants[6] = "I_Stim_PulseDuration in component membrane (millisecond)";
	constants[7] = "I_Stim_CL in component membrane (millisecond)";
	constants[8] = "F_junc in component membrane (dimensionless)";
	constants[109] = "F_sl in component membrane (dimensionless)";
	constants[9] = "F_junc_Ca_L in component membrane (dimensionless)";
	constants[110] = "F_sl_Ca_L in component membrane (dimensionless)";
	constants[111] = "V_cell in component membrane (litre)";
	constants[10] = "Length_cell in component membrane (decimetre)";
	constants[11] = "Radius_cell in component membrane (decimetre)";
	constants[113] = "V_myo in component membrane (litre)";
	constants[116] = "V_sl in component membrane (litre)";
	constants[117] = "V_sr in component membrane (litre)";
	constants[118] = "V_junc in component membrane (litre)";
	constants[12] = "J_Ca_juncsl in component membrane (L_per_millis)";
	constants[13] = "J_Ca_slmyo in component membrane (L_per_millis)";
	constants[14] = "J_Na_juncsl in component membrane (L_per_millis)";
	constants[15] = "J_Na_slmyo in component membrane (L_per_millis)";
	algebraic[94] = "I_Na_junc in component Fast_Na_Current (picoA_per_picoF)";
	algebraic[98] = "I_Na_sl in component Fast_Na_Current (picoA_per_picoF)";
	algebraic[99] = "I_Na in component Fast_Na_Current (picoA_per_picoF)";
	algebraic[97] = "E_Na_sl in component Nerst_Potentials (millivolt)";
	algebraic[93] = "E_Na_junc in component Nerst_Potentials (millivolt)";
	constants[16] = "G_Na in component Fast_Na_Current (milliS_per_microF)";
	states[1] = "m in component Fast_Na_Current (dimensionless)";
	algebraic[0] = "m_ss in component Fast_Na_Current (dimensionless)";
	algebraic[12] = "tau_m in component Fast_Na_Current (millisecond)";
	algebraic[1] = "a_h in component Fast_Na_Current (dimensionless)";
	algebraic[13] = "b_h in component Fast_Na_Current (dimensionless)";
	algebraic[26] = "tau_h in component Fast_Na_Current (millisecond)";
	states[2] = "h in component Fast_Na_Current (dimensionless)";
	algebraic[33] = "h_ss in component Fast_Na_Current (dimensionless)";
	algebraic[2] = "a_j in component Fast_Na_Current (dimensionless)";
	algebraic[14] = "b_j in component Fast_Na_Current (dimensionless)";
	algebraic[27] = "tau_j in component Fast_Na_Current (millisecond)";
	states[3] = "j in component Fast_Na_Current (dimensionless)";
	algebraic[34] = "j_ss in component Fast_Na_Current (dimensionless)";
	constants[17] = "A_Na in component Fast_Na_Current (dimensionless)";
	algebraic[95] = "I_Na_Bk_junc in component Background_Na_Current (picoA_per_picoF)";
	algebraic[100] = "I_Na_Bk_sl in component Background_Na_Current (picoA_per_picoF)";
	algebraic[101] = "I_Na_Bk in component Background_Na_Current (picoA_per_picoF)";
	constants[18] = "G_Na_B in component Background_Na_Current (milliS_per_microF)";
	constants[19] = "A_Na_Bk in component Background_Na_Current (dimensionless)";
	constants[20] = "Na_o in component Sodium_Concentrations (millimolar)";
	constants[112] = "sigma in component Na_K_Pump_Current (dimensionless)";
	algebraic[24] = "f_NaK in component Na_K_Pump_Current (dimensionless)";
	algebraic[31] = "I_NaK_junc in component Na_K_Pump_Current (picoA_per_picoF)";
	algebraic[38] = "I_NaK_sl in component Na_K_Pump_Current (picoA_per_picoF)";
	algebraic[43] = "I_NaK in component Na_K_Pump_Current (picoA_per_picoF)";
	constants[21] = "Ibar_NaK in component Na_K_Pump_Current (picoA_per_picoF)";
	constants[22] = "K_o in component Potassium_Concentrations (millimolar)";
	states[4] = "Na_j in component Sodium_Concentrations (millimolar)";
	states[5] = "Na_sl in component Sodium_Concentrations (millimolar)";
	constants[23] = "Km_Ko in component Na_K_Pump_Current (millimolar)";
	constants[24] = "Km_Naip in component Na_K_Pump_Current (millimolar)";
	constants[25] = "A_NaK in component Na_K_Pump_Current (dimensionless)";
	algebraic[3] = "x_r_ss in component Rapidly_Activating_K_Current (dimensionless)";
	states[6] = "x_Kr in component Rapidly_Activating_K_Current (dimensionless)";
	algebraic[44] = "r_Kr in component Rapidly_Activating_K_Current (dimensionless)";
	constants[114] = "E_K in component Nerst_Potentials (millivolt)";
	constants[26] = "G_Kr in component Rapidly_Activating_K_Current (milliS_per_microF)";
	algebraic[15] = "tau_xr in component Rapidly_Activating_K_Current (millisecond)";
	algebraic[45] = "I_Kr in component Rapidly_Activating_K_Current (picoA_per_picoF)";
	constants[27] = "A_Kr in component Rapidly_Activating_K_Current (dimensionless)";
	algebraic[4] = "x_s_ss in component Slowly_Activating_K_Current (dimensionless)";
	algebraic[16] = "tau_xs in component Slowly_Activating_K_Current (millisecond)";
	states[7] = "x_Ks in component Slowly_Activating_K_Current (dimensionless)";
	algebraic[104] = "E_Ks in component Nerst_Potentials (millivolt)";
	constants[28] = "G_Ks_junc in component Slowly_Activating_K_Current (milliS_per_microF)";
	constants[29] = "G_Ks_sl in component Slowly_Activating_K_Current (milliS_per_microF)";
	algebraic[105] = "I_Ks_junc in component Slowly_Activating_K_Current (picoA_per_picoF)";
	algebraic[106] = "I_Ks_sl in component Slowly_Activating_K_Current (picoA_per_picoF)";
	algebraic[107] = "I_Ks in component Slowly_Activating_K_Current (picoA_per_picoF)";
	constants[30] = "A_Ks in component Slowly_Activating_K_Current (dimensionless)";
	algebraic[46] = "kp_Kp in component Plateau_K_Current (dimensionless)";
	constants[31] = "G_Kp in component Plateau_K_Current (milliS_per_microF)";
	algebraic[47] = "I_Kp in component Plateau_K_Current (picoA_per_picoF)";
	constants[32] = "A_Kp in component Plateau_K_Current (dimensionless)";
	algebraic[5] = "x_to_ss in component Transient_Outward_K_Current (dimensionless)";
	algebraic[6] = "y_to_ss in component Transient_Outward_K_Current (dimensionless)";
	algebraic[17] = "tau_x_tos in component Transient_Outward_K_Current (millisecond)";
	algebraic[18] = "tau_y_tos in component Transient_Outward_K_Current (millisecond)";
	algebraic[19] = "tau_x_tof in component Transient_Outward_K_Current (millisecond)";
	algebraic[20] = "tau_y_tof in component Transient_Outward_K_Current (millisecond)";
	states[8] = "x_to_s in component Transient_Outward_K_Current (dimensionless)";
	states[9] = "y_to_s in component Transient_Outward_K_Current (dimensionless)";
	states[10] = "x_to_f in component Transient_Outward_K_Current (dimensionless)";
	states[11] = "y_to_f in component Transient_Outward_K_Current (dimensionless)";
	constants[33] = "G_to_s in component Transient_Outward_K_Current (milliS_per_microF)";
	constants[34] = "G_to_f in component Transient_Outward_K_Current (milliS_per_microF)";
	algebraic[48] = "I_to_s in component Transient_Outward_K_Current (picoA_per_picoF)";
	algebraic[49] = "I_to_f in component Transient_Outward_K_Current (picoA_per_picoF)";
	algebraic[50] = "I_to in component Transient_Outward_K_Current (picoA_per_picoF)";
	constants[35] = "A_to in component Transient_Outward_K_Current (dimensionless)";
	algebraic[51] = "a_K1 in component Inward_Rectifier_K_Current (dimensionless)";
	algebraic[52] = "b_K1 in component Inward_Rectifier_K_Current (dimensionless)";
	algebraic[53] = "K1_ss in component Inward_Rectifier_K_Current (dimensionless)";
	algebraic[54] = "I_K1 in component Inward_Rectifier_K_Current (picoA_per_picoF)";
	constants[36] = "G_K1 in component Inward_Rectifier_K_Current (milliS_per_microF)";
	constants[37] = "A_K1 in component Inward_Rectifier_K_Current (dimensionless)";
	algebraic[55] = "I_ClCa_junc in component Ca_Activated_Cl_Current (picoA_per_picoF)";
	algebraic[56] = "I_ClCa_sl in component Ca_Activated_Cl_Current (picoA_per_picoF)";
	states[12] = "Ca_j in component Calcium_Concentrations (millimolar)";
	states[13] = "Ca_sl in component Calcium_Concentrations (millimolar)";
	constants[115] = "E_Cl in component Nerst_Potentials (millivolt)";
	constants[38] = "G_ClCa in component Ca_Activated_Cl_Current (milliS_per_microF)";
	constants[39] = "Kd_ClCa in component Ca_Activated_Cl_Current (millimolar)";
	constants[40] = "A_ClCa in component Ca_Activated_Cl_Current (dimensionless)";
	constants[41] = "G_Cl_B in component Background_Cl_Current (milliS_per_microF)";
	constants[42] = "A_Cl_B in component Background_Cl_Current (dimensionless)";
	algebraic[7] = "d_ss in component L_Type_Calcium_Current (dimensionless)";
	algebraic[21] = "alpha_d in component L_Type_Calcium_Current (millisecond)";
	algebraic[28] = "beta_d in component L_Type_Calcium_Current (dimensionless)";
	algebraic[35] = "gamma_d in component L_Type_Calcium_Current (millisecond)";
	algebraic[40] = "tau_d in component L_Type_Calcium_Current (millisecond)";
	algebraic[8] = "f_ss in component L_Type_Calcium_Current (dimensionless)";
	algebraic[22] = "alpha_f in component L_Type_Calcium_Current (millisecond)";
	algebraic[29] = "beta_f in component L_Type_Calcium_Current (millisecond)";
	algebraic[36] = "gamma_f in component L_Type_Calcium_Current (millisecond)";
	algebraic[41] = "tau_f in component L_Type_Calcium_Current (millisecond)";
	algebraic[9] = "f_2_ss in component L_Type_Calcium_Current (dimensionless)";
	algebraic[23] = "alpha_f_2 in component L_Type_Calcium_Current (millisecond)";
	algebraic[30] = "beta_f_2 in component L_Type_Calcium_Current (millisecond)";
	algebraic[37] = "gamma_f_2 in component L_Type_Calcium_Current (millisecond)";
	algebraic[42] = "tau_f_2 in component L_Type_Calcium_Current (millisecond)";
	states[14] = "d in component L_Type_Calcium_Current (dimensionless)";
	states[15] = "f in component L_Type_Calcium_Current (dimensionless)";
	states[16] = "f_2 in component L_Type_Calcium_Current (dimensionless)";
	states[17] = "f_Ca_B_j in component L_Type_Calcium_Current (dimensionless)";
	states[18] = "f_Ca_B_sl in component L_Type_Calcium_Current (dimensionless)";
	constants[43] = "K_i in component Potassium_Concentrations (millimolar)";
	constants[44] = "Ca_o in component Calcium_Concentrations (millimolar)";
	algebraic[60] = "Ibar_Ca_j in component L_Type_Calcium_Current (picoA_per_picoF)";
	algebraic[61] = "Ibar_Ca_sl in component L_Type_Calcium_Current (picoA_per_picoF)";
	algebraic[62] = "Ibar_K in component L_Type_Calcium_Current (picoA_per_picoF)";
	algebraic[63] = "Ibar_Na_j in component L_Type_Calcium_Current (picoA_per_picoF)";
	algebraic[64] = "Ibar_Na_sl in component L_Type_Calcium_Current (picoA_per_picoF)";
	constants[45] = "p_Ca in component L_Type_Calcium_Current (litre_per_farad_millisecond)";
	constants[46] = "p_Na in component L_Type_Calcium_Current (litre_per_farad_millisecond)";
	constants[47] = "p_K in component L_Type_Calcium_Current (litre_per_farad_millisecond)";
	algebraic[65] = "I_Ca_junc in component L_Type_Calcium_Current (picoA_per_picoF)";
	algebraic[66] = "I_Ca_sl in component L_Type_Calcium_Current (picoA_per_picoF)";
	algebraic[67] = "I_Ca in component L_Type_Calcium_Current (picoA_per_picoF)";
	algebraic[69] = "I_Ca_Na_junc in component L_Type_Calcium_Current (picoA_per_picoF)";
	algebraic[70] = "I_Ca_Na_sl in component L_Type_Calcium_Current (picoA_per_picoF)";
	algebraic[72] = "I_Ca_Na in component L_Type_Calcium_Current (picoA_per_picoF)";
	algebraic[68] = "I_Ca_K in component L_Type_Calcium_Current (picoA_per_picoF)";
	algebraic[74] = "I_Ca_L in component L_Type_Calcium_Current (picoA_per_picoF)";
	constants[48] = "A_CaL in component L_Type_Calcium_Current (dimensionless)";
	algebraic[71] = "Ka_junc in component Na_Ca_Exchanger_Current (dimensionless)";
	algebraic[73] = "Ka_sl in component Na_Ca_Exchanger_Current (dimensionless)";
	constants[49] = "Kd_act in component Na_Ca_Exchanger_Current (millimolar)";
	constants[50] = "Km_Ca_i in component Na_Ca_Exchanger_Current (millimolar)";
	constants[51] = "Km_Ca_o in component Na_Ca_Exchanger_Current (millimolar)";
	constants[52] = "Km_Na_i in component Na_Ca_Exchanger_Current (millimolar)";
	constants[53] = "Km_Na_o in component Na_Ca_Exchanger_Current (millimolar)";
	constants[54] = "k_sat in component Na_Ca_Exchanger_Current (dimensionless)";
	constants[55] = "nu in component Na_Ca_Exchanger_Current (dimensionless)";
	algebraic[75] = "s1_junc in component Na_Ca_Exchanger_Current (millimolar4)";
	algebraic[77] = "s2_junc in component Na_Ca_Exchanger_Current (millimolar4)";
	algebraic[79] = "s3_junc in component Na_Ca_Exchanger_Current (millimolar4)";
	algebraic[76] = "s1_sl in component Na_Ca_Exchanger_Current (millimolar4)";
	algebraic[78] = "s2_sl in component Na_Ca_Exchanger_Current (millimolar4)";
	algebraic[80] = "s3_sl in component Na_Ca_Exchanger_Current (millimolar4)";
	constants[56] = "Ibar_NCX in component Na_Ca_Exchanger_Current (picoA_per_picoF)";
	algebraic[82] = "I_ncx_sl in component Na_Ca_Exchanger_Current (picoA_per_picoF)";
	algebraic[81] = "I_ncx_junc in component Na_Ca_Exchanger_Current (picoA_per_picoF)";
	algebraic[84] = "I_ncx in component Na_Ca_Exchanger_Current (picoA_per_picoF)";
	constants[57] = "A_ncx in component Na_Ca_Exchanger_Current (dimensionless)";
	constants[58] = "Km_P_Ca in component Sarcolemmal_Ca_Pump_Current (millimolar)";
	constants[59] = "Ibar_PMCA in component Sarcolemmal_Ca_Pump_Current (picoA_per_picoF)";
	algebraic[83] = "I_pCa_junc in component Sarcolemmal_Ca_Pump_Current (picoA_per_picoF)";
	algebraic[85] = "I_pCa_sl in component Sarcolemmal_Ca_Pump_Current (picoA_per_picoF)";
	algebraic[87] = "I_pCa in component Sarcolemmal_Ca_Pump_Current (picoA_per_picoF)";
	constants[60] = "A_pCa in component Sarcolemmal_Ca_Pump_Current (dimensionless)";
	algebraic[112] = "E_Ca_sl in component Nerst_Potentials (millivolt)";
	algebraic[109] = "E_Ca_junc in component Nerst_Potentials (millivolt)";
	constants[61] = "G_Ca_B in component Background_Ca_Current (milliS_per_microF)";
	algebraic[113] = "I_Ca_Bk_sl in component Background_Ca_Current (picoA_per_picoF)";
	algebraic[110] = "I_Ca_Bk_junc in component Background_Ca_Current (picoA_per_picoF)";
	algebraic[115] = "I_Ca_Bk in component Background_Ca_Current (picoA_per_picoF)";
	constants[62] = "A_Ca_Bk in component Background_Ca_Current (dimensionless)";
	constants[63] = "Max_SR in component SR_Fluxes (dimensionless)";
	constants[64] = "Min_SR in component SR_Fluxes (dimensionless)";
	states[19] = "Ca_SR in component Calcium_Concentrations (millimolar)";
	constants[65] = "ec50_SR in component SR_Fluxes (millimolar)";
	algebraic[11] = "k_Ca_SR in component SR_Fluxes (dimensionless)";
	constants[66] = "ko_Ca in component SR_Fluxes (per_milliM2_per_millis)";
	algebraic[25] = "ko_SR_Ca in component SR_Fluxes (per_milliM2_per_millis)";
	constants[67] = "ki_Ca in component SR_Fluxes (per_milliM_per_millis)";
	algebraic[32] = "ki_SR_Ca in component SR_Fluxes (per_milliM_per_millis)";
	constants[68] = "ki_m in component SR_Fluxes (per_millis)";
	constants[69] = "ko_m in component SR_Fluxes (per_millis)";
	constants[70] = "ks in component SR_Fluxes (per_millis)";
	constants[71] = "Km_f in component SR_Fluxes (millimolar)";
	constants[72] = "Km_r in component SR_Fluxes (millimolar)";
	algebraic[86] = "J_SR_Ca_rel in component SR_Fluxes (milliM_per_millis)";
	algebraic[89] = "J_SR_leak in component SR_Fluxes (milliM_per_millis)";
	algebraic[88] = "J_ser_Ca in component SR_Fluxes (milliM_per_millis)";
	algebraic[39] = "RI in component SR_Fluxes (dimensionless)";
	states[20] = "Ry_Rr in component SR_Fluxes (dimensionless)";
	states[21] = "Ry_Ro in component SR_Fluxes (dimensionless)";
	states[22] = "Ry_Ri in component SR_Fluxes (dimensionless)";
	states[23] = "Ca_i in component Calcium_Concentrations (millimolar)";
	constants[73] = "V_max_SR_CaP in component SR_Fluxes (milliM_per_millis)";
	constants[74] = "hill_SR_CaP in component SR_Fluxes (dimensionless)";
	constants[75] = "Mg_i in component Magnesium_Concentrations (millimolar)";
	states[24] = "TnC_l in component Cytosolic_Ca_Buffers (millimolar)";
	states[25] = "TnC_h_c in component Cytosolic_Ca_Buffers (millimolar)";
	states[26] = "TnC_h_m in component Cytosolic_Ca_Buffers (millimolar)";
	states[27] = "CaM in component Cytosolic_Ca_Buffers (millimolar)";
	states[28] = "Myo_c in component Cytosolic_Ca_Buffers (millimolar)";
	states[29] = "Myo_m in component Cytosolic_Ca_Buffers (millimolar)";
	states[30] = "SRB in component Cytosolic_Ca_Buffers (millimolar)";
	constants[76] = "k_off_TnC_l in component Cytosolic_Ca_Buffers (per_millis)";
	constants[77] = "k_off_TnC_h_Ca in component Cytosolic_Ca_Buffers (per_millis)";
	constants[78] = "k_off_TnC_h_Mg in component Cytosolic_Ca_Buffers (per_millis)";
	constants[79] = "k_off_CaM in component Cytosolic_Ca_Buffers (per_millis)";
	constants[80] = "k_off_myo_Ca in component Cytosolic_Ca_Buffers (per_millis)";
	constants[81] = "k_off_myo_Mg in component Cytosolic_Ca_Buffers (per_millis)";
	constants[82] = "k_off_SR in component Cytosolic_Ca_Buffers (per_millis)";
	constants[83] = "k_on_TnC_l in component Cytosolic_Ca_Buffers (per_milliM_per_millis)";
	constants[84] = "k_on_TnC_h_Ca in component Cytosolic_Ca_Buffers (per_milliM_per_millis)";
	constants[85] = "k_on_TnC_h_Mg in component Cytosolic_Ca_Buffers (per_milliM_per_millis)";
	constants[86] = "k_on_CaM in component Cytosolic_Ca_Buffers (per_milliM_per_millis)";
	constants[87] = "k_on_myo_Ca in component Cytosolic_Ca_Buffers (per_milliM_per_millis)";
	constants[88] = "k_on_myo_Mg in component Cytosolic_Ca_Buffers (per_milliM_per_millis)";
	constants[89] = "k_on_SR in component Cytosolic_Ca_Buffers (per_milliM_per_millis)";
	constants[90] = "B_max_TnC_low in component Cytosolic_Ca_Buffers (millimolar)";
	constants[91] = "B_max_TnC_high in component Cytosolic_Ca_Buffers (millimolar)";
	constants[92] = "B_max_CaM in component Cytosolic_Ca_Buffers (millimolar)";
	constants[93] = "B_max_myosin in component Cytosolic_Ca_Buffers (millimolar)";
	constants[94] = "B_max_SR in component Cytosolic_Ca_Buffers (millimolar)";
	algebraic[92] = "J_Ca_B_cytosol in component Cytosolic_Ca_Buffers (milliM_per_millis)";
	constants[119] = "B_max_SL_low_j in component Junctional_and_SL_Ca_Buffers (millimolar)";
	constants[120] = "B_max_SL_low_sl in component Junctional_and_SL_Ca_Buffers (millimolar)";
	constants[121] = "B_max_SL_high_j in component Junctional_and_SL_Ca_Buffers (millimolar)";
	constants[122] = "B_max_SL_high_sl in component Junctional_and_SL_Ca_Buffers (millimolar)";
	constants[95] = "k_off_sl_l in component Junctional_and_SL_Ca_Buffers (per_millis)";
	constants[96] = "k_off_sl_h in component Junctional_and_SL_Ca_Buffers (per_millis)";
	constants[97] = "k_on_sl_l in component Junctional_and_SL_Ca_Buffers (per_milliM_per_millis)";
	constants[98] = "k_on_sl_h in component Junctional_and_SL_Ca_Buffers (per_milliM_per_millis)";
	states[31] = "SLL_j in component Junctional_and_SL_Ca_Buffers (millimolar)";
	states[32] = "SLL_sl in component Junctional_and_SL_Ca_Buffers (millimolar)";
	states[33] = "SLH_j in component Junctional_and_SL_Ca_Buffers (millimolar)";
	states[34] = "SLH_sl in component Junctional_and_SL_Ca_Buffers (millimolar)";
	algebraic[90] = "J_Ca_B_junction in component Junctional_and_SL_Ca_Buffers (milliM_per_millis)";
	algebraic[91] = "J_Ca_B_sl in component Junctional_and_SL_Ca_Buffers (milliM_per_millis)";
	constants[99] = "B_max_Na_j in component Sodium_Concentrations (millimolar)";
	constants[100] = "B_max_Na_sl in component Sodium_Concentrations (millimolar)";
	constants[101] = "k_off_Na in component Sodium_Concentrations (per_millis)";
	constants[102] = "k_on_Na in component Sodium_Concentrations (per_milliM_per_millis)";
	states[35] = "Na_i in component Sodium_Concentrations (millimolar)";
	states[36] = "Na_B_j in component Sodium_Concentrations (millimolar)";
	states[37] = "Na_B_sl in component Sodium_Concentrations (millimolar)";
	states[38] = "Int_I_K_tot in component Potassium_Concentrations (millis_picoA_per_picoF)";
	constants[123] = "B_max_csqn in component Calcium_Concentrations (millimolar)";
	states[39] = "Csqn_b in component Calcium_Concentrations (millimolar)";
	constants[103] = "k_off_csqn in component Calcium_Concentrations (per_millis)";
	constants[104] = "k_on_csqn in component Calcium_Concentrations (per_milliM_per_millis)";
	constants[105] = "Cl_i in component Chlorine_Concentrations (millimolar)";
	constants[106] = "Cl_o in component Chlorine_Concentrations (millimolar)";
	constants[107] = "p_Na_K in component Nerst_Potentials (dimensionless)";
	rates[0] = "d/dt V in component membrane (millivolt)";
	rates[1] = "d/dt m in component Fast_Na_Current (dimensionless)";
	rates[2] = "d/dt h in component Fast_Na_Current (dimensionless)";
	rates[3] = "d/dt j in component Fast_Na_Current (dimensionless)";
	rates[6] = "d/dt x_Kr in component Rapidly_Activating_K_Current (dimensionless)";
	rates[7] = "d/dt x_Ks in component Slowly_Activating_K_Current (dimensionless)";
	rates[8] = "d/dt x_to_s in component Transient_Outward_K_Current (dimensionless)";
	rates[9] = "d/dt y_to_s in component Transient_Outward_K_Current (dimensionless)";
	rates[10] = "d/dt x_to_f in component Transient_Outward_K_Current (dimensionless)";
	rates[11] = "d/dt y_to_f in component Transient_Outward_K_Current (dimensionless)";
	rates[14] = "d/dt d in component L_Type_Calcium_Current (dimensionless)";
	rates[15] = "d/dt f in component L_Type_Calcium_Current (dimensionless)";
	rates[16] = "d/dt f_2 in component L_Type_Calcium_Current (dimensionless)";
	rates[17] = "d/dt f_Ca_B_j in component L_Type_Calcium_Current (dimensionless)";
	rates[18] = "d/dt f_Ca_B_sl in component L_Type_Calcium_Current (dimensionless)";
	rates[20] = "d/dt Ry_Rr in component SR_Fluxes (dimensionless)";
	rates[21] = "d/dt Ry_Ro in component SR_Fluxes (dimensionless)";
	rates[22] = "d/dt Ry_Ri in component SR_Fluxes (dimensionless)";
	rates[24] = "d/dt TnC_l in component Cytosolic_Ca_Buffers (millimolar)";
	rates[25] = "d/dt TnC_h_c in component Cytosolic_Ca_Buffers (millimolar)";
	rates[26] = "d/dt TnC_h_m in component Cytosolic_Ca_Buffers (millimolar)";
	rates[27] = "d/dt CaM in component Cytosolic_Ca_Buffers (millimolar)";
	rates[28] = "d/dt Myo_c in component Cytosolic_Ca_Buffers (millimolar)";
	rates[29] = "d/dt Myo_m in component Cytosolic_Ca_Buffers (millimolar)";
	rates[30] = "d/dt SRB in component Cytosolic_Ca_Buffers (millimolar)";
	rates[31] = "d/dt SLL_j in component Junctional_and_SL_Ca_Buffers (millimolar)";
	rates[32] = "d/dt SLL_sl in component Junctional_and_SL_Ca_Buffers (millimolar)";
	rates[33] = "d/dt SLH_j in component Junctional_and_SL_Ca_Buffers (millimolar)";
	rates[34] = "d/dt SLH_sl in component Junctional_and_SL_Ca_Buffers (millimolar)";
	rates[4] = "d/dt Na_j in component Sodium_Concentrations (millimolar)";
	rates[36] = "d/dt Na_B_j in component Sodium_Concentrations (millimolar)";
	rates[5] = "d/dt Na_sl in component Sodium_Concentrations (millimolar)";
	rates[37] = "d/dt Na_B_sl in component Sodium_Concentrations (millimolar)";
	rates[35] = "d/dt Na_i in component Sodium_Concentrations (millimolar)";
	rates[38] = "d/dt Int_I_K_tot in component Potassium_Concentrations (millis_picoA_per_picoF)";
	rates[39] = "d/dt Csqn_b in component Calcium_Concentrations (millimolar)";
	rates[12] = "d/dt Ca_j in component Calcium_Concentrations (millimolar)";
	rates[13] = "d/dt Ca_sl in component Calcium_Concentrations (millimolar)";
	rates[23] = "d/dt Ca_i in component Calcium_Concentrations (millimolar)";
	rates[19] = "d/dt Ca_SR in component Calcium_Concentrations (millimolar)";
}


//
void initConsts(double* constants, double *states)
{
	states[0] = -8.413368e1;
	constants[0] = 8314;
	constants[1] = 310;
	constants[2] = 96485;
	constants[3] = 1.381e-10;
	constants[4] = 0;
	constants[5] = 40;
	constants[6] = 1;
	constants[7] = 1000;
	constants[8] = 0.11;
	constants[9] = 0.9;
	constants[10] = 100e-5;
	constants[11] = 10.25e-5;
	constants[12] = 8.2413e-13;
	constants[13] = 3.7243e-12;
	constants[14] = 1.8313e-14;
	constants[15] = 1.6386e-12;
	constants[16] = 18.86;
	states[1] = 2.163678e-3;
	states[2] = 7.13497e-1;
	states[3] = 7.128671e-1;
	constants[17] = 1;
	constants[18] = 0.597e-3;
	constants[19] = 1;
	constants[20] = 140;
	constants[21] = 0.99;
	constants[22] = 5.4;
	states[4] = 1.007931e1;
	states[5] = 1.00781e1;
	constants[23] = 1.5;
	constants[24] = 11;
	constants[25] = 1;
	states[6] = 1.516232e-2;
	constants[26] = 0.035;
	constants[27] = 1;
	states[7] = 3.549354e-3;
	constants[28] = 0.0035;
	constants[29] = 0.0035;
	constants[30] = 1;
	constants[31] = 0.002;
	constants[32] = 1;
	states[8] = 3.584727e-4;
	states[9] = 8.087629e-1;
	states[10] = 3.584625e-4;
	states[11] = 9.999976e-1;
	constants[33] = 0.0156;
	constants[34] = 0.1144;
	constants[35] = 1;
	constants[36] = 0.57153;
	constants[37] = 1;
	states[12] = 2.038197e-4;
	states[13] = 1.184305e-4;
	constants[38] = 0.054813;
	constants[39] = 100e-3;
	constants[40] = 1;
	constants[41] = 9e-3;
	constants[42] = 1;
	states[14] = 1.871177e-6;
	states[15] = 9.804391e-1;
	states[16] = 9.99401e-1;
	states[17] = 2.847118e-2;
	states[18] = 1.692189e-2;
	constants[43] = 138;
	constants[44] = 1.8;
	constants[45] = 1.9887e-4;
	constants[46] = 3.0375e-9;
	constants[47] = 5.4675e-8;
	constants[48] = 1;
	constants[49] = 0.15e-3;
	constants[50] = 3.59e-3;
	constants[51] = 1.3;
	constants[52] = 12.29;
	constants[53] = 87.5;
	constants[54] = 0.32;
	constants[55] = 0.27;
	constants[56] = 4.5;
	constants[57] = 1;
	constants[58] = 0.5e-3;
	constants[59] = 0.0673;
	constants[60] = 1;
	constants[61] = 5.513e-4;
	constants[62] = 1;
	constants[63] = 15;
	constants[64] = 1;
	states[19] = 6.093596e-1;
	constants[65] = 0.45;
	constants[66] = 10;
	constants[67] = 0.5;
	constants[68] = 0.005;
	constants[69] = 0.06;
	constants[70] = 25;
	constants[71] = 0.246e-3;
	constants[72] = 1.7;
	states[20] = 8.886338e-1;
	states[21] = 1.126209e-6;
	states[22] = 1.411382e-7;
	states[23] = 9.658067e-5;
	constants[73] = 5.3114e-3;
	constants[74] = 1.787;
	constants[75] = 1;
	states[24] = 9.757237e-3;
	states[25] = 1.225914e-1;
	states[26] = 8.12201e-3;
	states[27] = 3.267494e-4;
	states[28] = 2.520383e-3;
	states[29] = 1.369529e-1;
	states[30] = 2.373753e-3;
	constants[76] = 19.6e-3;
	constants[77] = 0.032e-3;
	constants[78] = 3.33e-3;
	constants[79] = 238e-3;
	constants[80] = 0.46e-3;
	constants[81] = 0.057e-3;
	constants[82] = 60e-3;
	constants[83] = 32.7;
	constants[84] = 2.37;
	constants[85] = 3e-3;
	constants[86] = 34;
	constants[87] = 13.8;
	constants[88] = 0.0157;
	constants[89] = 100;
	constants[90] = 70e-3;
	constants[91] = 140e-3;
	constants[92] = 24e-3;
	constants[93] = 140e-3;
	constants[94] = 17.1e-3;
	constants[95] = 1.3;
	constants[96] = 30e-3;
	constants[97] = 100;
	constants[98] = 100;
	states[31] = 8.563314e-3;
	states[32] = 1.097424e-2;
	states[33] = 8.053908e-2;
	states[34] = 1.235381e-1;
	constants[99] = 7.561;
	constants[100] = 1.65;
	constants[101] = 1e-3;
	constants[102] = 0.1e-3;
	states[35] = 1.007825e1;
	states[36] = 3.796195e0;
	states[37] = 8.283308e-1;
	states[38] = 0;
	states[39] = 1.258048e0;
	constants[103] = 65;
	constants[104] = 100;
	constants[105] = 15;
	constants[106] = 150;
	constants[107] = 0.01833;
	constants[108] = constants[2] / (constants[0] * constants[1]);
	constants[109] = 1.00000 - constants[8];
	constants[110] = 1.00000 - constants[9];
	constants[111] = 3.14159265358979*pow(constants[11], 2.00000)*constants[10];
	constants[112] = (exp(constants[20] / 67.3000) - 1.00000) / 7.00000;
	constants[113] = 0.650000*constants[111];
	constants[114] = (1.00000 / constants[108])*log(constants[22] / constants[43]);
	constants[115] = (1.00000 / constants[108])*log(constants[105] / constants[106]);
	constants[116] = 0.0200000*constants[111];
	constants[117] = 0.0350000*constants[111];
	constants[118] = 0.000539000*constants[111];
	constants[119] = (0.000460000*constants[113]) / constants[118];
	constants[120] = (0.0374000*constants[113]) / constants[116];
	constants[121] = (0.000165000*constants[113]) / constants[118];
	constants[122] = (0.0134000*constants[113]) / constants[116];
	constants[123] = (0.140000*constants[113]) / constants[117];

}

void precompute(double *constants, double *out)
{
	out[0] = (constants[15] / constants[113]);

	out[1] = -constants[3] / (constants[118] * 2.00000*constants[2]);
	out[2] = -constants[3] / (constants[116] * 2.00000*constants[2]);

	out[3] = (constants[12] / constants[118]);
	out[4] = (constants[12] / constants[116]);

	out[5] = (constants[63] - constants[64]);
	out[6] = constants[85] * constants[75];
	out[7] = constants[88] * constants[75];

	out[8] = 1.0 / constants[113];
	out[9] = (constants[13] / constants[113]);

	out[10] = pow((constants[22] / 5.40000), 1.0 / 2);
	out[11] = pow(constants[58], 1.60000);

	out[12] = (1.00000 / (2.00000*constants[108]));
	out[13] = log(constants[44]);

	out[14] = (1.00000 / constants[108]);
	out[15] = log(constants[20]);

	out[16] = log(constants[22] + constants[107] * constants[20]);

	out[18] = constants[17] * constants[8] * constants[16];
	out[19] = constants[17] * constants[109] * constants[16];

	out[20] = constants[19] * constants[8] * constants[18];
	out[21] = constants[19] * constants[109] * constants[18];

	out[22] = constants[25] * constants[8] * constants[21] * constants[22];
	out[23] = constants[25] * constants[109] * constants[21] * constants[22];

	out[24] = constants[46] * constants[2] * constants[108];
	out[25] = constants[46] * constants[2] * constants[108];

	out[26] = 0.124500;
	out[27] = 0.0365000*constants[112];

	out[28] = constants[24] * constants[24] * constants[24] * constants[24];
	out[29] = (constants[22] + constants[23]);

	out[30] = constants[55];
	out[31] = (constants[55] - 1.00000);

	out[32] = constants[44];
	out[33] = (constants[20] * constants[20] * constants[20]);

	out[34] = constants[48] * constants[9];
	out[35] = constants[48] * constants[110];

	out[36] = constants[57] * constants[8] * constants[56];
	out[37] = constants[57] * constants[109] * constants[56];

	out[38] = 1.0 / constants[52];
	out[39] = 1.0 / constants[50];

	out[40] = constants[53] * constants[53] * constants[53];
	out[41] = 0.0;

	out[42] = -1.0 / (constants[118] * constants[2]);
	out[43] = -1.0 / (constants[116] * constants[2]);

	out[44] = (constants[14] / constants[118]);
	out[45] = (constants[14] / constants[116]);

	out[46] = 0.0;
	out[47] = (constants[15] / constants[116]);

	out[48] = constants[27] * constants[26] * out[10];
	out[49] = constants[32] * constants[31];

	out[50] = constants[30] * constants[8] * constants[28];
	out[51] = constants[30] * constants[109] * constants[29];

	out[52] = constants[35] * constants[33];
	out[53] = constants[35] * constants[34];

	out[54] = constants[37] * constants[36] * out[10];
	out[55] = 0.0;

	out[56] = constants[48] * constants[47] * constants[2] * constants[108];
	out[57] = constants[48] * constants[9] * constants[45] * constants[2] * constants[108];

	out[58] = constants[22];
	out[59] = constants[44];

	out[60] = constants[60] * constants[8] * constants[59];
	out[61] = constants[60] * constants[109] * constants[59];

	out[62] = constants[62] * constants[8] * constants[61];
	out[63] = constants[62] * constants[109] * constants[61];

	out[64] = constants[48] * constants[9] * constants[45] * constants[2] * constants[108];
	out[65] = constants[48] * constants[110] * constants[45] * constants[2] * constants[108];

	out[66] = (constants[40] * constants[8] * constants[38]);
	out[67] = (constants[40] * constants[109] * constants[38]);

}

void computeRates(double VoI, double* constants, double *data, double* rates, double* states)
{
	static const __m128d sign_mask = _mm_set1_pd(-0.);

	double tmp, tmp1, tmp2, ltmp;

	__m128d l1, l2, l3, l4, l5;
	__m128d s1;
	__m128d m1;

	const __m128d ones = _mm_set1_pd(1.0);
	const __m128d state0 = _mm_set1_pd(states[0]);

	__m128d stmp, stmp1, stmp2, stmp3, stmp4, stmp5, stmp6, stmp7, stmp8, stmp9, stmp10;
	__m128d gtmp, gtmp1, gtmp2;
	__m128d log1;

	l1 = _mm_loadu_pd(&states[17]);
	l2 = _mm_loadu_pd(&states[12]);

	l3 = _mm_mul_pd(l2, _mm_set1_pd(1.70000));
	l4 = _mm_sub_pd(ones, l1);
	l5 = _mm_mul_pd(l1, _mm_set1_pd(0.0119000));

	stmp = _mm_sub_pd(_mm_mul_pd(l3, l4), l5);
	_mm_storeu_pd(&rates[17], stmp);

	//rates[17] = 1.70000*states[12] * (1.00000 - states[17]) - 0.0119000*states[17];
	//rates[18] = 1.70000*states[13] * (1.00000 - states[18]) - 0.0119000*states[18];
	
	//stmp1.m128d_f64[0] = (56.8600 + states[0]) * -0.11074197120708748615725359911406;
	//stmp1.m128d_f64[1] = (states[0] + 71.5500) * 0.13458950201884253028263795423957;

	l1 = _mm_set_pd(71.5500, 56.8600);
	l2 = _mm_set_pd(0.13458950201884253028263795423957, -0.11074197120708748615725359911406);

	stmp1 = _mm_mul_pd(l2, _mm_add_pd(l1, state0));
	stmp1 = _mm_add_pd(ones, fmath::exp_pd(stmp1));
	stmp1 = _mm_div_pd(ones, _mm_mul_pd(stmp1, stmp1));

	//double algebraic0 = stmp1.m128d_f64[0];

	l1 = _mm_set_pd(-4.82300, 45.7900);
	l2 = _mm_set_pd(0.01956181533646322378716744913928, 0.06435006435006435006435006435006);
	s1 = _mm_mul_pd(l2, _mm_add_pd(state0, l1));

	//tmp1 = (states[0] + 45.7900) * 0.06435006435006435006435006435006;
	//tmp2 = (states[0] - 4.82300) * 0.01956181533646322378716744913928;

	//stmp.m128d_f64[0] = -(tmp1*tmp1);
	//stmp.m128d_f64[1] = -(tmp2*tmp2);
	stmp = _mm_mul_pd(s1, s1);
	stmp = fmath::exp_pd(_mm_or_pd(sign_mask, stmp));

	l1 = _mm_load_sd(&states[1]);
	l2 = _mm_set_pd(0.0648700, 0.129200);

	stmp = _mm_mul_pd(stmp, l2);
	stmp = _mm_hadd_pd(stmp, stmp);

	stmp = _mm_div_sd(_mm_sub_sd(stmp1, l1), stmp);
	_mm_store_sd(&rates[1], stmp);
	//double algebraic12 = 0.129200*stmp.m128d_f64[0] + 0.0648700*stmp.m128d_f64[1];
	//rates[1] = (algebraic0 - states[1]) / algebraic12;

	__m128d wtmp1, wtmp2, wtmp3, wtmp4, wtmp5;

	wtmp1.m128d_f64[0] = -(states[0] + 80.0000) * 0.14705882352941176470588235294118;
	wtmp1.m128d_f64[1] = -(states[0] + 10.6600) * 0.09009009009009009009009009009009;
	wtmp1 = fmath::exp_pd(wtmp1);

	//wtmp2.m128d_f64[0] = 0.0790000*states[0];
	//wtmp2.m128d_f64[1] = 0.348500*states[0];

	l1 = _mm_set_pd(0.348500, 0.0790000);
	l2 = _mm_set_pd(310000.0, 2.70000);

	wtmp2 = _mm_mul_pd(state0, l1);
	wtmp2 = fmath::exp_pd(wtmp2);
	wtmp2 = _mm_mul_pd(wtmp2, l2);
	wtmp2 = _mm_hadd_pd(wtmp2, wtmp2);

	m1 = _mm_cmpge_pd(state0, _mm_set1_pd(-40.0000));
	
	double algebraic1 = (states[0] >= -40.0000 ? 0.00000 : 0.0570000*wtmp1.m128d_f64[0]);
	//double algebraic13 = (states[0] >= -40.0000 ? 5.92310 / (1.00000 + wtmp1.m128d_f64[1]) : 2.70000*wtmp2.m128d_f64[0] + 310000.*wtmp2.m128d_f64[1]);
	
	double algebraic13 = (states[0] >= -40.0000 ? 5.92310 / (1.00000 + wtmp1.m128d_f64[1]) : wtmp2.m128d_f64[0]);
	
	double algebraic26 = 1.00000 / (algebraic1 + algebraic13);
	double algebraic33 = stmp1.m128d_f64[1];
	rates[2] = (algebraic33 - states[2]) / algebraic26;

	//wtmp1.m128d_f64[0] = 0.244400*states[0];
	//wtmp1.m128d_f64[1] = -0.0439100*states[0];
	wtmp5 = _mm_mul_pd(state0, _mm_set_pd(-0.0439100, 0.244400));
	wtmp5 = fmath::exp_pd(wtmp5);
	wtmp5 = _mm_mul_pd(wtmp5, _mm_set_pd(-6.94800e-06, -25428.0));
	wtmp5 = _mm_hadd_pd(wtmp5, wtmp5);

	wtmp2.m128d_f64[0] = 0.311000*(states[0] + 79.2300);
	wtmp2.m128d_f64[1] = 0.0570000*states[0];
	wtmp2 = fmath::exp_pd(wtmp2);

	wtmp3.m128d_f64[0] = -0.100000*(states[0] + 32.0000);
	wtmp3.m128d_f64[1] = -0.0105200*states[0];
	wtmp3 = fmath::exp_pd(wtmp3);

	wtmp4.m128d_f64[0] = -0.137800*(states[0] + 40.1400);
	wtmp4 = fmath::exp_pd(wtmp4);

	//double algebraic2 = (states[0] >= -40.0000 ? 0.00000 : ((-25428.0*wtmp5.m128d_f64[0] - 6.94800e-06*wtmp1.m128d_f64[1])*(states[0] + 37.7800)) / (1.00000 + wtmp2.m128d_f64[0]));

	double algebraic2 = (states[0] >= -40.0000 ? 0.00000 : ((wtmp5.m128d_f64[0])*(states[0] + 37.7800)) / (1.00000 + wtmp2.m128d_f64[0]));

	double algebraic14 = (states[0] >= -40.0000 ? (0.600000*wtmp2.m128d_f64[1]) / (1.00000 + wtmp3.m128d_f64[0]) : (0.0242400*wtmp3.m128d_f64[1]) / (1.00000 + wtmp4.m128d_f64[0]));
	double algebraic27 = 1.00000 / (algebraic2 + algebraic14);
	rates[3] = (algebraic33 - states[3]) / algebraic27;

	l1 = _mm_set_pd(3.80000, 10.0000);
	l2 = _mm_set_pd(-0.07017543859649122807017543859649, -0.20000);

	stmp1 = _mm_add_pd(l1, state0);
	stmp1 = _mm_mul_pd(stmp1, l2);

	//stmp1.m128d_f64[0] = -(states[0] + 10.0000) * 0.20000;
	//stmp1.m128d_f64[1] = -(states[0] + 3.80000) * 0.07017543859649122807017543859649;
	stmp1 = _mm_add_pd(ones, fmath::exp_pd(stmp1));
	stmp1 = _mm_div_pd(ones, stmp1);

	l1 = _mm_set_pd(40.0000, -22.0000);
	l2 = _mm_set_pd(0.050, 0.11111111111111111111111111111111);

	stmp2 = _mm_addsub_pd(l1, state0);
	stmp2 = _mm_mul_pd(l2, stmp2);

	//stmp2.m128d_f64[0] = (-22.0000 - states[0]) * 0.11111111111111111111111111111111;
	//stmp2.m128d_f64[1] = (40.0000  + states[0]) * 0.050;
	stmp2 = fmath::exp_pd(stmp2);
	stmp2 = _mm_add_pd(ones, stmp2);

	l1 = _mm_set_pd(2.43600, 11.0000);
	l2 = _mm_set_pd(-0.07082152974504249291784702549575, 0.11111111111111111111111111111111);

	stmp3 = _mm_add_pd(state0, l1);
	stmp3 = _mm_mul_pd(stmp3, l2);

	//stmp3.m128d_f64[0] = (states[0] + 11.0000) * 0.11111111111111111111111111111111;
	//stmp3.m128d_f64[1] = (states[0] + 2.43600) * -0.07082152974504249291784702549575;
	stmp3 = fmath::exp_pd(stmp3);
	stmp3 = _mm_add_pd(ones, stmp3);

	l1 = _mm_set_pd(230.000, 3300.00);
	l2 = _mm_set_pd(990.100, 0.0);

	stmp2 = _mm_mul_sd(stmp2, stmp3);
	stmp2 = _mm_div_pd(l1, stmp2);
	stmp3 = _mm_div_pd(l2, stmp3);

	stmp2 = _mm_hadd_pd(stmp2, stmp3);

	l1 = _mm_loadu_pd(&states[6]);
	stmp1 = _mm_sub_pd(stmp1, l1);
	stmp1 = _mm_div_pd(stmp1, stmp2);
	_mm_storeu_pd(&rates[6], stmp1);

	//double algebraic3 = stmp1.m128d_f64[0];
	//double algebraic15 = 3300.00 / (stmp2.m128d_f64[0] * stmp3.m128d_f64[0]) + 230.000 / stmp2.m128d_f64[1];
	//rates[6] = (algebraic3 - states[6]) / algebraic15;
	//double algebraic4 = stmp1.m128d_f64[1];
	//double algebraic16 = 990.100 / stmp3.m128d_f64[1];
	//rates[7] = (algebraic4 - states[7]) / algebraic16;

	l1 = _mm_set_pd(19.5000, 19.0000);
	l2 = _mm_set_pd(0.20, -0.07692307692307692307692307692308);
	
	stmp1 = _mm_addsub_pd(state0, l1);
	stmp1 = _mm_mul_pd(stmp1, l2);

	//stmp1.m128d_f64[0] = -(states[0] - 19.0000) * 0.07692307692307692307692307692308;
	//stmp1.m128d_f64[1] = (states[0] + 19.5000) * 0.20;
	stmp1 = _mm_add_pd(ones, fmath::exp_pd(stmp1));
	stmp1 = _mm_div_pd(ones, stmp1); 

	l1 = _mm_set_pd(60.0000, 3.00000);
	l2 = _mm_set_pd(0.10, 0.06666666666666666666666666666667);

	stmp = _mm_add_pd(state0, l1);
	stmp = _mm_mul_pd(stmp, l2);

	//stmp.m128d_f64[0] = (states[0] + 3.00000) * 0.06666666666666666666666666666667;
	//stmp.m128d_f64[1] = (states[0] + 60.0000) * 0.10;
	stmp = fmath::exp_pd(stmp);
	stmp = _mm_add_pd(ones, stmp);

	l1 = _mm_set_pd(800.000, 9.00000);
	l2 = _mm_set_pd(30.0000, 0.500000);

	stmp = _mm_div_pd(l1, stmp);
	stmp = _mm_add_pd(stmp, l2);

	stmp2 = _mm_sub_pd(stmp1, _mm_loadu_pd(&states[8]));
	stmp2 = _mm_div_pd(stmp2, stmp);
	_mm_storeu_pd(&rates[8], stmp2);

	//double algebraic5 = stmp1.m128d_f64[0];
	//double algebraic17 = 9.00000 / stmp.m128d_f64[0] + 0.500000;
	//rates[8] = (algebraic5 - states[8]) / algebraic17;
	//double algebraic6 = stmp1.m128d_f64[1];
	//double algebraic18 = 800.000 / stmp.m128d_f64[1] + 30.0000;
	//rates[9] = (algebraic6 - states[9]) / algebraic18;

	//tmp = (states[0] + 45.0000);
	//double ltmp = states[0] + 40.0000;

	l1 = _mm_set_pd(40.0000, 45.0000);
	l2 = _mm_set_pd(-0.00454545454545454545454545454545, -0.0004);

	stmp = _mm_add_pd(state0, l1);
	stmp = _mm_mul_pd(stmp, stmp);
	stmp = _mm_mul_pd(stmp, l2);

	//stmp.m128d_f64[0] = -(tmp*tmp) * 0.0004;
	//stmp.m128d_f64[1] = -(ltmp*ltmp) * 0.00454545454545454545454545454545;
	stmp = fmath::exp_pd(stmp);

	l1 = _mm_set_pd(85.0000, 8.50000);
	l2 = _mm_set_pd(7.00000, 0.500000);

	stmp = _mm_mul_pd(stmp, l1);
	stmp = _mm_add_pd(stmp, l2);

	stmp2 = _mm_sub_pd(stmp1, _mm_loadu_pd(&states[10]));
	stmp2 = _mm_div_pd(stmp2, stmp);
	_mm_storeu_pd(&rates[10], stmp2);

	//double algebraic19 = 8.50000*stmp.m128d_f64[0] + 0.500000;
	//rates[10] = (algebraic5 - states[10]) / algebraic19;	
	//double algebraic20 = 85.0000*stmp.m128d_f64[1] + 7.00000;
	//rates[11] = (algebraic6 - states[11]) / algebraic20;

	double algebraic11 = constants[63] - data[5] / (1.00000 + pow(constants[65] / states[19], 2.50000));
	double algebraic25 = constants[66] / algebraic11;
	double algebraic32 = constants[67] * algebraic11;
	tmp1 = states[12] * states[12];
	rates[21] = (algebraic25 * tmp1 * states[20] - constants[69] * states[21]) - (algebraic32 * states[12] * states[21] - constants[68] * states[22]);
	double algebraic39 = ((1.00000 - states[20]) - states[21]) - states[22];
	rates[20] = (constants[68] * algebraic39 - algebraic32*states[12] * states[20]) - (algebraic25*tmp1*states[20] - constants[69] * states[21]);
	rates[22] = (algebraic32*states[12] * states[21] - constants[68] * states[22]) - (constants[69] * states[22] - algebraic25*tmp1*algebraic39);

	l1 = _mm_set_pd(5.00000, 50.0000);
	l2 = _mm_set_pd(-0.16666666666666666666666666666667, 0.05);

	stmp1 = _mm_addsub_pd(l1, state0);
	stmp1 = _mm_mul_pd(stmp1, l2);

	//stmp1.m128d_f64[0] = (50.0000 - states[0]) * 0.05;
	//stmp1.m128d_f64[1] = (states[0] + 5.00000) * -0.16666666666666666666666666666667;
	stmp1 = _mm_add_pd(ones, fmath::exp_pd(stmp1));
	stmp1 = _mm_div_pd(ones, stmp1);

	l1 = _mm_set_pd(5.00000, -35.0000);
	l2 = _mm_set_pd(0.2, 0.07692307692307692307692307692308);

	stmp2 = _mm_addsub_pd(l1, state0);
	stmp2 = _mm_mul_pd(stmp2, l2);

	//stmp2.m128d_f64[0] = (-35.0000 - states[0]) * 0.07692307692307692307692307692308;
	//stmp2.m128d_f64[1] = (states[0] + 5.00000) * 0.2;
	stmp2 = _mm_add_pd(ones, fmath::exp_pd(stmp2));
	stmp2 = _mm_div_pd(_mm_set1_pd(1.40000), stmp2);

	double algebraic7 = stmp1.m128d_f64[1];
	double algebraic21 = stmp2.m128d_f64[0] + 0.250000;
	double algebraic28 = stmp2.m128d_f64[1];
	double algebraic35 = stmp1.m128d_f64[0];
	double algebraic40 = algebraic21 * algebraic28 + algebraic35;
	rates[14] = (algebraic7 - states[14]) / algebraic40;

	//stmp1.m128d_f64[0] = (states[0] + 20.0000) * 0.14285714285714285714285714285714;
	//stmp1.m128d_f64[1] = (states[0] + 30.0000) * 0.1;

	l1 = _mm_set_pd(30.0000, 20.0000);
	l2 = _mm_set_pd(0.1, 0.14285714285714285714285714285714);

	stmp1 = _mm_add_pd(state0, l1);
	stmp1 = _mm_mul_pd(stmp1, l2);
	stmp1 = _mm_add_pd(ones, fmath::exp_pd(stmp1));
	stmp1 = _mm_div_pd(ones, stmp1);

	//stmp.m128d_f64[0] = (13.0000 - states[0]) * 0.1;
	//stmp.m128d_f64[1] = (states[0] + 35.0000) * 0.14285714285714285714285714285714;

	l1 = _mm_set_pd(35.0000, 13.0000);
	l2 = _mm_set_pd(0.14285714285714285714285714285714, 0.1);

	stmp = _mm_addsub_pd(l1, state0);
	stmp = _mm_mul_pd(stmp, l2);
	stmp = fmath::exp_pd(stmp);
	stmp = _mm_add_pd(ones, stmp);
	
	l1 = _mm_set_pd(25.0000, 27.0000);
	l2 = _mm_set_pd(-0.00588235294117647058823529411765, -0.00444444444444444444444444444444);

	//tmp = (states[0] + 27.0000);
	//ltmp = states[0] + 25.0000;
	//stmp3.m128d_f64[0] = (tmp*tmp) * -0.00444444444444444444444444444444;
	//stmp3.m128d_f64[1] = (ltmp*ltmp) * -0.00588235294117647058823529411765;

	stmp3 = _mm_add_pd(state0, l1);
	stmp3 = _mm_mul_pd(stmp3, stmp3);
	stmp3 = _mm_mul_pd(stmp3, l2);
	stmp3 = fmath::exp_pd(stmp3);

	double algebraic8 = stmp1.m128d_f64[0];
	double algebraic22 = 1102.50*stmp3.m128d_f64[0];
	double algebraic29 = 200.000 / stmp.m128d_f64[0];
	double etmp1 = stmp1.m128d_f64[1];
	double algebraic36 = 180.000 * etmp1 + 20.0000;
	double algebraic41 = algebraic22 + algebraic29 + algebraic36;
	rates[15] = (algebraic8 - states[15]) / algebraic41;

	double algebraic9 = 0.670000 / stmp.m128d_f64[1] + 0.330000;
	double algebraic23 = 300.000*stmp3.m128d_f64[1];

	stmp3.m128d_f64[0] = (25.0000 - states[0]) * 0.1;
	stmp3.m128d_f64[1] = states[0] * constants[108];
	stmp3 = fmath::exp_pd(stmp3);

	stmp5 = _mm_loaddup_pd(&stmp3.m128d_f64[1]);

	double algebraic30 = 31.0000 / (1.00000 + stmp3.m128d_f64[0]);
	double etmpx = stmp3.m128d_f64[1];
	double algebraic37 = 16.0000 * etmp1;
	double algebraic42 = algebraic23 + algebraic30 + algebraic37;
	rates[16] = (algebraic9 - states[16]) / algebraic42;

	rates[39] = constants[104] * states[19] * (constants[123] - states[39]) - constants[103] * states[39];

	double algebraic86 = constants[70] * states[21] * (states[19] - states[12]);
	double algebraic89 = 5.34800e-06*(states[19] - states[12]);

	__m128d ptmp1;
	ptmp1.m128d_f64[0] = states[23] / constants[71];
	ptmp1.m128d_f64[1] = states[19] / constants[72];
	ptmp1 = fmath::gmx_mm_pow_pd(ptmp1, _mm_set1_pd(constants[74]));

	double algebraic88 = (constants[73] * (ptmp1.m128d_f64[0] - ptmp1.m128d_f64[1])) / (1.00000 + ptmp1.m128d_f64[0] + ptmp1.m128d_f64[1]);
	rates[19] = (algebraic88 - ((algebraic89*constants[113]) / constants[117] + algebraic86)) - rates[39];

	rates[24] = constants[83] * states[23] * (constants[90] - states[24]) - constants[76] * states[24];
	rates[25] = constants[84] * states[23] * ((constants[91] - states[25]) - states[26]) - constants[77] * states[25];
	rates[26] = data[6] * ((constants[91] - states[25]) - states[26]) - constants[78] * states[26];
	rates[27] = constants[86] * states[23] * (constants[92] - states[27]) - constants[79] * states[27];	
	rates[28] = constants[87] * states[23] * ((constants[93] - states[28]) - states[29]) - constants[80] * states[28];
	rates[29] = data[7] * ((constants[93] - states[28]) - states[29]) - constants[81] * states[29];
	rates[30] = constants[89] * states[23] * (constants[94] - states[30]) - constants[82] * states[30];
	rates[31] = constants[97] * states[12] * (constants[119] - states[31]) - constants[95] * states[31];
	rates[32] = constants[97] * states[13] * (constants[120] - states[32]) - constants[95] * states[32];
	rates[33] = constants[98] * states[12] * (constants[121] - states[33]) - constants[96] * states[33];
	rates[34] = constants[98] * states[13] * (constants[122] - states[34]) - constants[96] * states[34];
	rates[35] = data[0] * (states[5] - states[35]); //z dupy taki
	rates[36] = constants[102] * states[4] * (constants[99] - states[36]) - constants[101] * states[36];
	rates[37] = constants[102] * states[5] * (constants[100] - states[37]) - constants[101] * states[37];
	double algebraic92 = rates[24] + rates[25] + rates[26] + rates[27] + rates[28] + rates[29] + rates[30];
	rates[23] = ((-algebraic88*constants[117])*data[8] - algebraic92) + data[9] * (states[13] - states[23]);

	l1 = _mm_loaddup_pd(&data[14]);
	l2 = _mm_loaddup_pd(&data[15]);
	log1 = fmath::gmx_mm_log_pd(_mm_loadu_pd(&states[4]));

	stmp3 = _mm_sub_pd(l2, log1);
	stmp3 = _mm_mul_pd(l1, stmp3);
	stmp3 = _mm_sub_pd(state0, stmp3);

	//double algebraic93 = data[14] * (data[15] - log1.m128d_f64[0]);
	//double algebraic94 = data[18] * (states[1] * states[1] * states[1])*states[2] * states[3] * (states[0] - algebraic93);
	//double algebraic95 = data[20] * (states[0] - algebraic93);

	__m128d t1, t2, t3, a1;
	t1 = _mm_loaddup_pd(&states[1]);
	t2 = _mm_loaddup_pd(&states[2]);
	t3 = _mm_loaddup_pd(&states[3]);

	l1 = _mm_loadu_pd(&data[18]);
	l2 = _mm_loadu_pd(&data[20]);

	t2 = _mm_mul_pd(t2, t3);
	a1 = _mm_mul_pd(t1, t1);
	a1 = _mm_mul_pd(a1, t1);
	a1 = _mm_mul_pd(a1, t2);

	a1 = _mm_mul_pd(a1, stmp3);
	a1 = _mm_mul_pd(a1, l1);

	t2 = _mm_mul_pd(l2, stmp3);
	stmp3 = _mm_add_pd(t2, a1);

	//double etmp2 = 1.0 / (etmpx - 1.00000);

	l1 = _mm_set_pd(-1.0, -0.100000);
	l2 = _mm_loaddup_pd(&constants[108]);

	stmp = _mm_mul_pd(state0, l2);
	stmp4 = stmp;
	stmp = _mm_mul_pd(stmp, l1);

	//stmp.m128d_f64[0] = -0.100000*states[0] * constants[108];
	//stmp.m128d_f64[1] = -states[0] * constants[108];
	stmp = fmath::exp_pd(stmp);
	stmp = _mm_mul_pd(stmp, _mm_loadu_pd(&data[26]));
	stmp = _mm_hadd_pd(stmp, stmp);
	stmp = _mm_add_pd(stmp, ones);

	l1 = _mm_loadu_pd(&states[4]);
	stmp2 = _mm_mul_pd(l1, l1);
	stmp2 = _mm_mul_pd(stmp2, l1);

	//stmp4.m128d_f64[0] = constants[55] * states[0] * constants[108];
	//stmp4.m128d_f64[1] = (constants[55] - 1.00000)*states[0] * constants[108];
	//stmp4 = _mm_exp_pd(stmp4);
	stmp4 = _mm_mul_pd(stmp4, _mm_loadu_pd(&data[30]));
	stmp4 = fmath::exp_pd(stmp4);

	l2 = _mm_mul_pd(stmp2, l1);
	l2 = _mm_div_pd(_mm_loaddup_pd(&data[28]), l2);
	l2 = _mm_add_pd(ones, l2);
	l2 = _mm_mul_pd(_mm_loaddup_pd(&data[29]), l2);
	stmp1 = _mm_mul_pd(stmp, l2);
	stmp1 = _mm_div_pd(_mm_loadu_pd(&data[22]), stmp1);

	stmp6 = _mm_mul_pd(l1, stmp5);
	stmp6 = _mm_sub_pd(stmp6, _mm_loaddup_pd(&constants[20]));
	stmp6 = _mm_mul_pd(stmp6, state0);
	stmp6 = _mm_mul_pd(stmp6, _mm_loadu_pd(&data[24]));
	stmp6 = _mm_div_pd(stmp6, _mm_sub_pd(stmp5, ones));
	
	//tmp1 = states[4] * states[4] * states[4];
	//tmp = data[28] / (tmp1 * states[4]);
	//double algebraic24 = 1.00000 / stmp.m128d_f64[0];
	//double algebraic31 = (data[22] * algebraic24) / ((1.00000 + tmp)*data[29]);
	//double algebraic63 = (data[24] * states[0] * (states[4] * etmpx - constants[20])) * etmp2;
	//double algebraic69 = data[34] * algebraic63 * states[14] * states[15] * states[16] * (1.00000 - states[17]);

	gtmp1 = _mm_mul_pd(_mm_loaddup_pd(&states[15]), _mm_loaddup_pd(&states[14]));
	gtmp1 = _mm_mul_pd(gtmp1, _mm_loaddup_pd(&states[16]));
	stmp6 = _mm_mul_pd(stmp6, gtmp1);
	stmp6 = _mm_mul_pd(stmp6, _mm_sub_pd(ones, _mm_loadu_pd(&states[17])));
	stmp6 = _mm_mul_pd(stmp6, _mm_loadu_pd(&data[34]));
	stmp3 = _mm_add_pd(stmp3, stmp6);

	l2 = _mm_loaddup_pd(&stmp4.m128d_f64[1]);
	l5 = _mm_loadu_pd(&states[12]);

	stmp7 = _mm_div_pd(_mm_loaddup_pd(&constants[49]), l5);
	stmp7 = _mm_mul_pd(stmp7, stmp7);
	stmp7 = _mm_add_pd(stmp7, ones);

	//tmp = constants[49] / states[12];
	//double algebraic71 = 1.00000 / (1.00000 + (tmp*tmp));

	///double tmp4a = stmp4.m128d_f64[1];
	stmp4 = _mm_mul_pd(stmp4, _mm_loadu_pd(&data[32]));

	stmp8 = _mm_loaddup_pd(&stmp4.m128d_f64[0]);
	stmp8 = _mm_mul_pd(stmp8, stmp2);
	stmp8 = _mm_sub_pd(stmp8, _mm_mul_pd(_mm_loaddup_pd(&stmp4.m128d_f64[1]), l5));
	stmp8 = _mm_mul_pd(stmp8, _mm_loadu_pd(&data[36]));

	//double ctmp = stmp4.m128d_f64[0] * constants[44];
	//double algebraic75 = ctmp * tmp1;
	//tmp2 = (constants[20] * constants[20] * constants[20]);
	l3 = _mm_loaddup_pd(&data[33]);
	//double tmp4a = stmp4.m128d_f64[1];
	//double tmp5 = tmp4a*tmp2;
	//double tmp5 = stmp4.m128d_f64[1];;
	//double algebraic77 = tmp5*states[12];

	l4 = _mm_mul_pd(l1, _mm_loaddup_pd(&data[38]));
	stmp9 = _mm_mul_pd(l4, l4);
	stmp9 = _mm_mul_pd(stmp9, l4);
	stmp9 = _mm_add_pd(stmp9, ones);
	stmp9 = _mm_mul_pd(stmp9, l3);
	stmp9 = _mm_mul_pd(stmp9, _mm_loaddup_pd(&constants[50]));

	stmp10 = _mm_mul_pd(l5, _mm_loaddup_pd(&data[39]));
	stmp10 = _mm_add_pd(stmp10, ones);
	stmp10 = _mm_mul_pd(stmp10, _mm_mul_pd(l5, _mm_loaddup_pd(&data[40])));
	stmp9 = _mm_add_pd(stmp9, stmp10);

	stmp10 = _mm_mul_pd(stmp2, _mm_loaddup_pd(&constants[51]));
	stmp10 = _mm_add_pd(stmp10, _mm_mul_pd(stmp2, _mm_loaddup_pd(&constants[44])));
	stmp9 = _mm_add_pd(stmp9, stmp10);

	stmp10 = _mm_mul_pd(l3, l5);
	stmp9 = _mm_add_pd(stmp10, stmp9);
	stmp7 = _mm_mul_pd(stmp7, stmp9);

	stmp10 = _mm_mul_pd(l2, _mm_loaddup_pd(&constants[54]));
	stmp10 = _mm_add_pd(stmp10, ones);
	stmp7 = _mm_mul_pd(stmp7, stmp10);
	stmp8 = _mm_div_pd(stmp8, stmp7);
	stmp3 = _mm_add_pd(stmp3, _mm_mul_pd(_mm_set1_pd(3.0), _mm_add_pd(stmp1, stmp8)));
	gtmp2 = stmp3;

	//tmp = states[4] / constants[52];
	//double tmp3 = constants[53] * constants[53] * constants[53];
	//double algebraic79 = constants[50] * tmp2*(1.00000 + (tmp*tmp*tmp)) + tmp3*states[12] * (1.00000 + states[12] / constants[50]) + constants[51] * tmp1 + tmp1*constants[44] + tmp2*states[12];
	//double algebraic81 = (data[36] * algebraic71 * (algebraic75 - algebraic77)) / (algebraic79 * (1.00000 + constants[54] * tmp4a));
	//double algebraic96 = algebraic94 + algebraic95 + 3.00000*algebraic81 + 3.00000*algebraic31 + algebraic69;
	//double algebraic96 = stmp3.m128d_f64[0];
	//rates[4] = ((-algebraic96*constants[3]) / (constants[118] * constants[2]) + (constants[14] / constants[118])*(states[5] - states[4])) - rates[36];
	
	stmp10 = _mm_mul_pd(stmp3, _mm_loaddup_pd(&constants[3]));
	stmp10 = _mm_mul_pd(stmp10, _mm_loadu_pd(&data[42]));

	l2 = _mm_shuffle_pd(l1, l1, 0x01);
	stmp9 = _mm_sub_pd(l2, l1);
	stmp9 = _mm_mul_pd(stmp9, _mm_loadu_pd(&data[44]));

	stmp10 = _mm_add_pd(stmp10, stmp9);

	stmp9 = _mm_sub_pd(_mm_loaddup_pd(&states[35]), l1);
	stmp9 = _mm_mul_pd(stmp9, _mm_loadu_pd(&data[46]));
	stmp10 = _mm_add_pd(stmp10, stmp9);

	stmp10 = _mm_sub_pd(stmp10, _mm_loadu_pd(&rates[36]));
	_mm_storeu_pd(&rates[4], stmp10);

	//rates[4] = (stmp10.m128d_f64[0]) - rates[36];
	
	//double algebraic97 = data[14] * (data[15] - log1.m128d_f64[1]);
	//tmp = states[1] * states[1] * states[1];
	//double algebraic98 = data[19] * tmp*states[2] * states[3] * (states[0] - algebraic97);
	//double algebraic100 = data[21] * (states[0] - algebraic97);

	//tmp1 = states[5] * states[5] * states[5];
	//tmp = data[28] / (tmp1 * states[5]);
	//double algebraic38 = (data[23] * algebraic24) / ((1.00000 + tmp)*data[29]);
	//double algebraic64 = (data[25] * states[0] * (states[5] * etmpx - constants[20])) * etmp2;
	//double algebraic70 = data[35] * algebraic64 * states[14] * states[15] * states[16] * (1.00000 - states[18]);
	//tmp = constants[49] / states[13];
	//double algebraic73 = 1.00000 / (1.00000 + (tmp*tmp));
	//double algebraic76 = ctmp*tmp1; 
	//double algebraic78 = tmp5*states[13];
	//tmp = states[5] / constants[52];
	//double algebraic80 = constants[50] * tmp2*(1.00000 + (tmp*tmp*tmp)) + tmp3*states[13] * (1.00000 + states[13] / constants[50]) + constants[51] * tmp1 + tmp1*constants[44] + tmp2*states[13];
	//double algebraic82 = (data[37] * algebraic73 * (algebraic76 - algebraic78)) / (algebraic80 * (1.00000 + constants[54] * tmp4a));
	//double algebraic102 = algebraic98 + algebraic100 + 3.00000*algebraic82 + 3.00000*algebraic38 + algebraic70;
	//double algebraic102 = stmp3.m128d_f64[1];
	//rates[5] = ((-algebraic102*constants[3]) / (constants[116] * constants[2]) + (constants[14] / constants[116])*(states[4] - states[5]) + (constants[15] / constants[116])*(states[35] - states[5])) - rates[37];
	//rates[5] = (stmp10.m128d_f64[1] + (constants[15] / constants[116])*(states[35] - states[5])) - rates[37];
	
	double algebraic10 = (VoI - floor(VoI / constants[7])*constants[7] >= constants[4] && (VoI - floor(VoI / constants[7])*constants[7]) - constants[4] <= constants[6] ? constants[5] : 0.00000);
	//double algebraic43 = algebraic31 + algebraic38;

	gtmp = _mm_add_pd(stmp1, stmp1);
	//double algebraic43 = stmp1.m128d_f64[0] + stmp1.m128d_f64[1];

	//stmp2.m128d_f64[0] = 7.48800 - states[0] * 0.16722408026755852842809364548495;
	//stmp2.m128d_f64[1] = (states[0] + 74.0000) * 0.04166666666666666666666666666667;

	//stmp2.m128d_f64[0] = 7.48800 - states[0] * 0.16722408026755852842809364548495;
	//stmp2.m128d_f64[1] = 3.0833333333333333333333333333336 + states[0] * 0.04166666666666666666666666666667;

	stmp2 = _mm_mul_pd(state0, _mm_set_pd(0.04166666666666666666666666666667, 0.16722408026755852842809364548495));
	stmp2 = _mm_addsub_pd(_mm_set_pd(3.0833333333333333333333333333336, 7.48800), stmp2);
	stmp2 = _mm_shuffle_pd(stmp2, stmp2, 0x01);
	stmp2 = _mm_add_pd(ones, fmath::exp_pd(stmp2));

	stmp10 = _mm_sub_pd(state0, _mm_loaddup_pd(&constants[114]));
	stmp2 = _mm_div_pd(stmp10, stmp2);
	stmp2 = _mm_mul_pd(stmp2, _mm_loadu_pd(&data[48]));
	stmp2 = _mm_mul_sd(stmp2, _mm_load_sd(&states[6]));

	//double algebraic44 = stmp2.m128d_f64[0];
	double ptmp = data[10];
	//double algebraic45 = constants[27] * constants[26] * ptmp *states[6] * algebraic44 * (states[0] - constants[114]);
	//double algebraic45 = stmp2.m128d_f64[0];

	stmp9 = _mm_loaddup_pd(&states[35]);
	stmp9 = _mm_mul_pd(stmp9, _mm_loaddup_pd(&constants[107]));
	stmp9 = _mm_add_pd(stmp9, _mm_loaddup_pd(&constants[43]));
	stmp9 = fmath::gmx_mm_log_pd(stmp9);
	stmp9 = _mm_sub_pd(_mm_loaddup_pd(&data[16]), stmp9);
	stmp9 = _mm_mul_pd(stmp9, _mm_loaddup_pd(&data[14]));
	stmp9 = _mm_sub_pd(state0, stmp9);

	l1 = _mm_loaddup_pd(&states[7]);
	l1 = _mm_mul_pd(l1, l1);

	stmp9 = _mm_mul_pd(stmp9, l1);
	stmp9 = _mm_mul_pd(stmp9, _mm_loadu_pd(&data[50]));

	l1 = _mm_loadu_pd(&states[8]);
	l2 = _mm_loadu_pd(&states[10]);

	l3 = _mm_shuffle_pd(l1, l2, 0x00);
	l4 = _mm_shuffle_pd(l1, l2, 0x03);

	l1 = _mm_sub_pd(state0, _mm_loaddup_pd(&constants[114]));
	stmp10 = _mm_mul_pd(l1, l3);
	stmp10 = _mm_mul_pd(stmp10, l4);
	stmp10 = _mm_mul_pd(stmp10, _mm_loadu_pd(&data[52]));

	stmp10 = _mm_add_pd(stmp9, stmp10);
	stmp10 = _mm_add_pd(stmp10, stmp2);
	stmp10 = _mm_sub_pd(stmp10, gtmp);

	//double algebraic104 = data[14]*(data[16] - log((constants[43] + constants[107] * states[35])));
	//tmp = states[7] * states[7];
	//double algebraic105 = data[50] * tmp*(states[0] - algebraic104);
	//double algebraic106 = data[51] * tmp*(states[0] - algebraic104);
	//double algebraic107 = algebraic105 + algebraic106;
	//double algebraic107 = stmp10.m128d_f64[0];
	//double algebraic46 = stmp2.m128d_f64[1];
	//double algebraic47 = constants[32] * constants[31] * algebraic46 * (states[0] - constants[114]);
	//double algebraic47 = stmp2.m128d_f64[1];
	//double algebraic48 = data[52] * states[8] * states[9] * (states[0] - constants[114]);
	//double algebraic49 = data[53] * states[10] * states[11] * (states[0] - constants[114]);
	//double algebraic50 = algebraic48 + algebraic49;
	//double algebraic50 = stmp10.m128d_f64[1];

	l2 = _mm_addsub_pd(l1, _mm_set_pd(14.2067, 49.9344));
	stmp = _mm_mul_pd(l2, _mm_set_pd(-0.162850, 0.121650));

	//stmp.m128d_f64[0] = 0.121650*((states[0] - constants[114]) - 49.9344);
	//stmp.m128d_f64[1] = -0.162850*((states[0] - constants[114]) + 14.2067);
	stmp = fmath::exp_pd(stmp);
	stmp = _mm_add_pd(ones, stmp);

	l2 = _mm_sub_pd(l1, _mm_set_pd(594.310, 3.25710));
	stmp1 = _mm_mul_pd(l2, _mm_set_pd(0.0617500, 0.0673900));
	//stmp1.m128d_f64[0] = 0.0673900*((states[0] - constants[114]) - 3.25710);
	//stmp1.m128d_f64[1] = 0.0617500*((states[0] - constants[114]) - 594.310);
	stmp1 = fmath::exp_pd(stmp1);
	stmp1 = _mm_mul_pd(stmp1, _mm_set_sd(15.7197));

	stmp1 = _mm_hadd_pd(_mm_set_sd(4.09380), stmp1);
	stmp1 = _mm_div_pd(stmp1, stmp);

	//double algebraic51 = 4.09380 / stmp.m128d_f64[0];
	//double algebraic52 = (15.7197*stmp1.m128d_f64[0] + stmp1.m128d_f64[1]) / stmp.m128d_f64[1];

	//double algebraic51 = stmp1.m128d_f64[0];
	//double algebraic52 = stmp1.m128d_f64[1];

	l2 = _mm_hadd_pd(stmp1, stmp1);
	l2 = _mm_div_sd(stmp1, l2);
	l2 = _mm_mul_sd(l2, l1);
	l2 = _mm_mul_sd(l2, _mm_load_sd(&data[54]));
	stmp10 = _mm_add_sd(stmp10, l2);

	stmp5 = _mm_loaddup_pd(&etmpx);
	stmp3 = _mm_mul_pd(stmp5, stmp5);

	stmp6 = _mm_load_sd(&constants[43]);

	stmp6 = _mm_mul_pd(stmp6, stmp5);
	stmp6 = _mm_sub_pd(stmp6, _mm_loadu_pd(&data[58]));

	stmp6 = _mm_mul_pd(stmp6, state0);
	stmp6 = _mm_mul_pd(stmp6, _mm_loadu_pd(&data[56]));

	stmp5 = _mm_sub_pd(stmp5, ones);
	stmp6 = _mm_div_sd(stmp6, stmp5);
	stmp6 = _mm_mul_pd(stmp6, gtmp1);

	stmp5 = _mm_sub_pd(ones, _mm_loaddup_pd(&states[17]));
	stmp5 = _mm_mul_sd(stmp5, _mm_load1_pd(&constants[9]));

	stmp7 = _mm_sub_pd(ones, _mm_loaddup_pd(&states[18]));
	stmp7 = _mm_mul_sd(stmp7, _mm_load1_pd(&constants[110]));
	stmp5 = _mm_add_sd(stmp5, stmp7);

	stmp6 = _mm_mul_pd(stmp6, stmp5);
	stmp10 = _mm_add_sd(stmp10, stmp6);

	//double algebraic53 = algebraic51 / (algebraic51 + algebraic52);
	//double algebraic54 = data[54] *algebraic53 * (states[0] - constants[114]);
	//double algebraic62 = (data[56] * states[0] * (constants[43] * etmpx - constants[22])) / (etmpx - 1.00000);
	//double algebraic68 = algebraic62 * states[14] * states[15] * states[16] * (constants[9] * (1.00000 - states[17]) + constants[110] * (1.00000 - states[18]));
	//double algebraic108 = (((algebraic50 + algebraic45 + algebraic107 + algebraic54) - 2.00000*algebraic43) + algebraic68 + algebraic47) - algebraic10;
	double algebraic108 = (stmp10.m128d_f64[0] + stmp10.m128d_f64[1]) - algebraic10;
	rates[38] = algebraic108;

	l1 = _mm_loadu_pd(&states[12]);

	stmp5 = _mm_mul_pd(stmp3, l1);
	stmp5 = _mm_sub_pd(stmp5, _mm_loaddup_pd(&constants[44]));
	stmp5 = _mm_div_pd(stmp5, _mm_sub_pd(stmp3, ones));
	stmp5 = _mm_mul_pd(stmp5, state0);
	stmp5 = _mm_mul_pd(stmp5, _mm_loadu_pd(&data[64]));
	stmp5 = _mm_mul_pd(stmp5, gtmp1);
	stmp5 = _mm_mul_pd(stmp5, _mm_sub_pd(ones, _mm_loadu_pd(&states[17])));

	//double etmpx2 = etmpx*etmpx;
	//double algebraic60 = (data[64] * states[0] * (states[12] * etmpx2 - constants[44])) / (etmpx2 - 1.00000);
	//double algebraic65 = algebraic60 * states[14] * states[15] * states[16] * (1.00000 - states[17]);
	//double algebraic65 = stmp6.m128d_f64[1];
	//double ptmp2 = data[11];

	//ptmp1.m128d_f64[0] = states[12];
	//ptmp1.m128d_f64[1] = states[13];

	ptmp1 = fmath::gmx_mm_pow_pd(l1, _mm_set1_pd(1.60000));
	log1 = fmath::gmx_mm_log_pd(l1);

	//ptmp = ptmp1.m128d_f64[0];
	
	l3 = _mm_mul_pd(ptmp1, _mm_loadu_pd(&data[60]));
	l2 = _mm_add_pd(ptmp1, _mm_loaddup_pd(&data[11]));
	stmp1 = _mm_div_pd(l3, l2);
	
	stmp2 = _mm_sub_pd(_mm_loaddup_pd(&data[13]), log1);
	stmp2 = _mm_mul_pd(stmp2, _mm_loaddup_pd(&data[12]));
	stmp2 = _mm_sub_pd(state0, stmp2);
	stmp2 = _mm_mul_pd(stmp2, _mm_loadu_pd(&data[62]));
	stmp2 = _mm_add_pd(stmp2, stmp1);

	stmp8 = _mm_add_pd(stmp8, stmp8);
	stmp1 = _mm_sub_pd(stmp2, stmp8);
	stmp1 = _mm_add_pd(stmp1, stmp5);
	
	stmp2 = _mm_add_pd(stmp1, gtmp2);
	stmp1 = _mm_mul_pd(stmp1, _mm_loadu_pd(&data[1]));

	l2 = _mm_shuffle_pd(l1, l1, 0x01);
	stmp3 = _mm_sub_pd(l2, l1);
	stmp3 = _mm_mul_pd(stmp3, _mm_loadu_pd(&data[3]));
	stmp1 = _mm_add_pd(stmp1, stmp3);

	stmp3 = _mm_add_pd(_mm_loadu_pd(&rates[31]), _mm_loadu_pd(&rates[33]));
	stmp1 = _mm_sub_pd(stmp1, stmp3);

	//double algebraic83 = (constants[60] * constants[8] * constants[59] * ptmp) / (ptmp2 + ptmp);
	//double algebraic109 = data[12] * (data[13] - log1.m128d_f64[0]);
	//double algebraic110 = constants[62] * constants[8] * constants[61] * (states[0] - algebraic109);
	//double algebraic111 = (algebraic65 + algebraic110 + algebraic83) - (algebraic81+algebraic81);
	//double algebraic90 = rates[31] + rates[33];
	//rates[12] = ((algebraic111*data[1] + data[3] * (states[13] - states[12])) - algebraic90) + (algebraic86*constants[117]) / constants[118] + (algebraic89*constants[113]) / constants[118];
	rates[12] = stmp1.m128d_f64[0] + (algebraic86*constants[117]) / constants[118] + (algebraic89*constants[113]) / constants[118];
	
	//double algebraic61 = (data[65] * states[0] * (states[13] * etmpx2 - constants[44])) / (etmpx2 - 1.00000);
	//double algebraic66 = algebraic61 * states[14] * states[15] * states[16] * (1.00000 - states[18]);
	//ptmp = ptmp1.m128d_f64[1];

	//double algebraic85 = (constants[60] * constants[109] * constants[59] * ptmp) / (ptmp2 + ptmp);
	//double algebraic112 = data[12] * (data[13] - log1.m128d_f64[1]);
	//double algebraic113 = constants[62] * constants[109] * constants[61] * (states[0] - algebraic112);
	//double algebraic114 = (algebraic66 + algebraic113 + algebraic85) - (algebraic82+algebraic82);
	//double algebraic91 = rates[32] + rates[34];
	//rates[13] = (algebraic114*data[2] + data[4] * (states[12] - states[13]) + (constants[13] / constants[116])*(states[23] - states[13])) - algebraic91;
	rates[13] = (stmp1.m128d_f64[1] + (constants[13] / constants[116])*(states[23] - states[13]));

	stmp3 = _mm_sub_pd(state0, _mm_loaddup_pd(&constants[115]));

	stmp4 = _mm_div_pd(_mm_loaddup_pd(&constants[39]), l1);
	stmp4 = _mm_add_pd(stmp4, ones);
	stmp4 = _mm_div_pd(_mm_loadu_pd(&data[66]), stmp4);
	stmp4 = _mm_mul_pd(stmp4, stmp3);
	stmp2 = _mm_add_pd(stmp2, stmp4);

	stmp2 = _mm_hadd_pd(stmp2, stmp2);

	//double algebraic103 = algebraic96 + algebraic102;
	tmp = (states[0] - constants[115]);
	//double algebraic55 = ((constants[40] * constants[8] * constants[38]) / (1.00000 + constants[39] / states[12]))*tmp;
	//double algebraic56 = ((constants[40] * constants[109] * constants[38]) / (1.00000 + constants[39] / states[13]))*tmp;
	//double algebraic57 = algebraic55 + algebraic56;
	double algebraic58 = constants[42] * constants[41] * tmp;
	//double algebraic59 = algebraic57 + algebraic58;
	double algebraic59 = algebraic58;
	//double algebraic116 = algebraic111 + algebraic114;
	double algebraic116 = stmp2.m128d_f64[0];
	double algebraic117 = algebraic59 + algebraic116 + algebraic108;
	//double algebraic117 = algebraic103 + algebraic59 + algebraic116 + algebraic108;
	rates[0] = -algebraic117;

}

//==========================================================

