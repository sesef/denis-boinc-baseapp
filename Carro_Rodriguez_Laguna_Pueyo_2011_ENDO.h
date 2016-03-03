/*======================================================================
                                                                        
                      --- DENIS Project ---                             
                        -----------------                               
                                                                        
      Distributed computing                                             
      Electrophysiologycal Models                                       
      Networking colaboration                                           
      In Silico research                                                
      Sharing Knowledge                                                 
                                                                        
------------------------------------------------------------------------
                                                                        
 -- C File of the Carro_Rodriguez_Laguna_Pueyo_2011_ENDO model created for the DENIS Project -- 
                                                                        
 This file has been automatically created using the CellML API.         
                                                                        
------------------------------------------------------------------------
                                                                        
 DENIS-CellML2C Copyright 2015 J. Carro; J. Castro                      
                                                                        
 Licensed under the Apache License, Version 2.0 (the "License");      
 you may not use this file except in compliance with the License.       
 You may obtain a copy of the License at                                
                                                                        
 http://www.apache.org/licenses/LICENSE-2.0                             
                                                                        
 Unless required by applicable law or agreed to in writing, software    
 distributed under the License is distributed on an "AS IS" BASIS,    
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        
 implied. See the License for the specific language governing           
 permissions and limitations under the License.                         
                                                                        
------------------------------------------------------------------------
                                                                        
                                                  San Jorge University  
                                                 School of Engineering  
                                                                        
                                                     http://eps.usj.es  
                                                                        
======================================================================*/

using namespace std;

namespace Carro_Rodriguez_Laguna_Pueyo_2011_ENDO{

	#define ALGEBRAIC_LENGTH 118
	#define STATE_LENGTH 39
	#define CONSTANT_LENGTH 111 

	double* getNewConstantsArray(){return new double[CONSTANT_LENGTH];}
	double* getNewRatesArray(){return new double[STATE_LENGTH];}
	double* getNewStatesArray(){return new double[STATE_LENGTH];}
	double* getNewAlgebraicArray(){return new double[ALGEBRAIC_LENGTH];}
	
	void getNewArrays(double **constants, double **rates, double **states, double **algebraic){
		*constants = getNewConstantsArray();
		*rates     = getNewRatesArray();
		*states    = getNewStatesArray();
		*algebraic = getNewAlgebraicArray();
	}
	
	void getVectorsLength(int* algebraicLength, int* statesLength, int* constantsLength){
		*algebraicLength = ALGEBRAIC_LENGTH;
		*statesLength = STATE_LENGTH;
		*constantsLength = CONSTANT_LENGTH;
	}
	
	int getNameId(const char* variable, const char* component, const char** names, int namesLength){
		int index = -1;
		int counter = 0;
		string completName(variable);
		completName += " in component ";
		completName += component;
		for(int i=0; i < namesLength; i++){
			if(strncmp(completName.c_str(), names[i], (long)completName.length())==0){
				index = i;
				counter++;
			}
		}
		
		switch(counter){
			case 1:
				return index;
			case 0:
				return -1;
			default:
				return -counter;
		}
	}
		
	void names(const char* &VoI, const char** constants, const char** rates, const char** states, const char** algebraic){
		VoI  = "t in component environment (millisecond)";
		states[0]  = "V in component membrane (millivolt)";
		constants[0]  = "R in component membrane (joule_per_kmole_kelvin)";
		constants[1]  = "T in component membrane (kelvin)";
		constants[2]  = "Frdy in component membrane (coulomb_per_mole)";
		constants[95]  = "FoRT in component membrane (per_milliV)";
		constants[3]  = "C_mem in component membrane (farad)";
		algebraic[96]  = "I_Na_tot_junc in component Sodium_Concentrations (picoA_per_picoF)";
		algebraic[102]  = "I_Na_tot_sl in component Sodium_Concentrations (picoA_per_picoF)";
		algebraic[57]  = "I_ClCa in component Ca_Activated_Cl_Current (picoA_per_picoF)";
		algebraic[58]  = "I_Cl_Bk in component Background_Cl_Current (picoA_per_picoF)";
		algebraic[111]  = "I_Ca_tot_junc in component Calcium_Concentrations (picoA_per_picoF)";
		algebraic[114]  = "I_Ca_tot_sl in component Calcium_Concentrations (picoA_per_picoF)";
		algebraic[108]  = "I_K_tot in component Potassium_Concentrations (picoA_per_picoF)";
		algebraic[103]  = "I_Na_tot in component membrane (picoA_per_picoF)";
		algebraic[59]  = "I_Cl_tot in component membrane (picoA_per_picoF)";
		algebraic[116]  = "I_Ca_tot in component membrane (picoA_per_picoF)";
		algebraic[117]  = "I_tot in component membrane (picoA_per_picoF)";
		algebraic[10]  = "I_Stim in component membrane (picoA_per_picoF)";
		constants[4]  = "I_Stim_Start in component membrane (millisecond)";
		constants[5]  = "I_Stim_End in component membrane (millisecond)";
		constants[6]  = "I_Stim_Amplitude in component membrane (picoA_per_picoF)";
		constants[7]  = "I_Stim_Period in component membrane (millisecond)";
		constants[8]  = "I_Stim_PulseDuration in component membrane (millisecond)";
		constants[9]  = "F_junc in component membrane (dimensionless)";
		constants[96]  = "F_sl in component membrane (dimensionless)";
		constants[10]  = "F_junc_Ca_L in component membrane (dimensionless)";
		constants[97]  = "F_sl_Ca_L in component membrane (dimensionless)";
		constants[98]  = "V_cell in component membrane (litre)";
		constants[11]  = "Length_cell in component membrane (decimetre)";
		constants[12]  = "Radius_cell in component membrane (decimetre)";
		constants[100]  = "V_myo in component membrane (litre)";
		constants[103]  = "V_sl in component membrane (litre)";
		constants[104]  = "V_sr in component membrane (litre)";
		constants[105]  = "V_junc in component membrane (litre)";
		constants[13]  = "J_Ca_juncsl in component membrane (L_per_millis)";
		constants[14]  = "J_Ca_slmyo in component membrane (L_per_millis)";
		constants[15]  = "J_Na_juncsl in component membrane (L_per_millis)";
		constants[16]  = "J_Na_slmyo in component membrane (L_per_millis)";
		algebraic[94]  = "I_Na_junc in component Fast_Na_Current (picoA_per_picoF)";
		algebraic[98]  = "I_Na_sl in component Fast_Na_Current (picoA_per_picoF)";
		algebraic[99]  = "I_Na in component Fast_Na_Current (picoA_per_picoF)";
		algebraic[97]  = "E_Na_sl in component Nerst_Potentials (millivolt)";
		algebraic[93]  = "E_Na_junc in component Nerst_Potentials (millivolt)";
		constants[17]  = "G_Na in component Fast_Na_Current (milliS_per_microF)";
		states[1]  = "m in component Fast_Na_Current (dimensionless)";
		algebraic[0]  = "m_ss in component Fast_Na_Current (dimensionless)";
		algebraic[12]  = "tau_m in component Fast_Na_Current (millisecond)";
		algebraic[1]  = "a_h in component Fast_Na_Current (dimensionless)";
		algebraic[13]  = "b_h in component Fast_Na_Current (dimensionless)";
		algebraic[26]  = "tau_h in component Fast_Na_Current (millisecond)";
		states[2]  = "h in component Fast_Na_Current (dimensionless)";
		algebraic[33]  = "h_ss in component Fast_Na_Current (dimensionless)";
		algebraic[2]  = "a_j in component Fast_Na_Current (dimensionless)";
		algebraic[14]  = "b_j in component Fast_Na_Current (dimensionless)";
		algebraic[27]  = "tau_j in component Fast_Na_Current (millisecond)";
		states[3]  = "j in component Fast_Na_Current (dimensionless)";
		algebraic[34]  = "j_ss in component Fast_Na_Current (dimensionless)";
		algebraic[95]  = "I_Na_Bk_junc in component Background_Na_Current (picoA_per_picoF)";
		algebraic[100]  = "I_Na_Bk_sl in component Background_Na_Current (picoA_per_picoF)";
		algebraic[101]  = "I_Na_Bk in component Background_Na_Current (picoA_per_picoF)";
		constants[18]  = "G_Na_B in component Background_Na_Current (milliS_per_microF)";
		constants[19]  = "Na_o in component Sodium_Concentrations (millimolar)";
		constants[99]  = "sigma in component Na_K_Pump_Current (dimensionless)";
		algebraic[24]  = "f_NaK in component Na_K_Pump_Current (dimensionless)";
		algebraic[31]  = "I_NaK_junc in component Na_K_Pump_Current (picoA_per_picoF)";
		algebraic[38]  = "I_NaK_sl in component Na_K_Pump_Current (picoA_per_picoF)";
		algebraic[43]  = "I_NaK in component Na_K_Pump_Current (picoA_per_picoF)";
		constants[20]  = "Ibar_NaK in component Na_K_Pump_Current (picoA_per_picoF)";
		constants[21]  = "K_o in component Potassium_Concentrations (millimolar)";
		states[4]  = "Na_j in component Sodium_Concentrations (millimolar)";
		states[5]  = "Na_sl in component Sodium_Concentrations (millimolar)";
		constants[22]  = "Km_Ko in component Na_K_Pump_Current (millimolar)";
		constants[23]  = "Km_Naip in component Na_K_Pump_Current (millimolar)";
		algebraic[3]  = "x_r_ss in component Rapidly_Activating_K_Current (dimensionless)";
		states[6]  = "x_Kr in component Rapidly_Activating_K_Current (dimensionless)";
		algebraic[44]  = "r_Kr in component Rapidly_Activating_K_Current (dimensionless)";
		constants[101]  = "E_K in component Nerst_Potentials (millivolt)";
		constants[24]  = "G_Kr in component Rapidly_Activating_K_Current (milliS_per_microF)";
		algebraic[15]  = "tau_xr in component Rapidly_Activating_K_Current (millisecond)";
		algebraic[45]  = "I_Kr in component Rapidly_Activating_K_Current (picoA_per_picoF)";
		algebraic[4]  = "x_s_ss in component Slowly_Activating_K_Current (dimensionless)";
		algebraic[16]  = "tau_xs in component Slowly_Activating_K_Current (millisecond)";
		states[7]  = "x_Ks in component Slowly_Activating_K_Current (dimensionless)";
		algebraic[104]  = "E_Ks in component Nerst_Potentials (millivolt)";
		constants[25]  = "G_Ks_junc in component Slowly_Activating_K_Current (milliS_per_microF)";
		constants[26]  = "G_Ks_sl in component Slowly_Activating_K_Current (milliS_per_microF)";
		algebraic[105]  = "I_Ks_junc in component Slowly_Activating_K_Current (picoA_per_picoF)";
		algebraic[106]  = "I_Ks_sl in component Slowly_Activating_K_Current (picoA_per_picoF)";
		algebraic[107]  = "I_Ks in component Slowly_Activating_K_Current (picoA_per_picoF)";
		algebraic[46]  = "kp_Kp in component Plateau_K_Current (dimensionless)";
		constants[27]  = "G_Kp in component Plateau_K_Current (milliS_per_microF)";
		algebraic[47]  = "I_Kp in component Plateau_K_Current (picoA_per_picoF)";
		algebraic[5]  = "x_to_ss in component Transient_Outward_K_Current (dimensionless)";
		algebraic[6]  = "y_to_ss in component Transient_Outward_K_Current (dimensionless)";
		algebraic[17]  = "tau_x_tos in component Transient_Outward_K_Current (millisecond)";
		algebraic[18]  = "tau_y_tos in component Transient_Outward_K_Current (millisecond)";
		algebraic[19]  = "tau_x_tof in component Transient_Outward_K_Current (millisecond)";
		algebraic[20]  = "tau_y_tof in component Transient_Outward_K_Current (millisecond)";
		states[8]  = "x_to_s in component Transient_Outward_K_Current (dimensionless)";
		states[9]  = "y_to_s in component Transient_Outward_K_Current (dimensionless)";
		states[10]  = "x_to_f in component Transient_Outward_K_Current (dimensionless)";
		states[11]  = "y_to_f in component Transient_Outward_K_Current (dimensionless)";
		constants[28]  = "G_to_s in component Transient_Outward_K_Current (milliS_per_microF)";
		constants[29]  = "G_to_f in component Transient_Outward_K_Current (milliS_per_microF)";
		algebraic[48]  = "I_to_s in component Transient_Outward_K_Current (picoA_per_picoF)";
		algebraic[49]  = "I_to_f in component Transient_Outward_K_Current (picoA_per_picoF)";
		algebraic[50]  = "I_to in component Transient_Outward_K_Current (picoA_per_picoF)";
		algebraic[51]  = "a_K1 in component Inward_Rectifier_K_Current (dimensionless)";
		algebraic[52]  = "b_K1 in component Inward_Rectifier_K_Current (dimensionless)";
		algebraic[53]  = "K1_ss in component Inward_Rectifier_K_Current (dimensionless)";
		algebraic[54]  = "I_K1 in component Inward_Rectifier_K_Current (picoA_per_picoF)";
		constants[30]  = "G_K1 in component Inward_Rectifier_K_Current (milliS_per_microF)";
		algebraic[55]  = "I_ClCa_junc in component Ca_Activated_Cl_Current (picoA_per_picoF)";
		algebraic[56]  = "I_ClCa_sl in component Ca_Activated_Cl_Current (picoA_per_picoF)";
		states[12]  = "Ca_j in component Calcium_Concentrations (millimolar)";
		states[13]  = "Ca_sl in component Calcium_Concentrations (millimolar)";
		constants[102]  = "E_Cl in component Nerst_Potentials (millivolt)";
		constants[31]  = "G_ClCa in component Ca_Activated_Cl_Current (milliS_per_microF)";
		constants[32]  = "Kd_ClCa in component Ca_Activated_Cl_Current (millimolar)";
		constants[33]  = "G_Cl_B in component Background_Cl_Current (milliS_per_microF)";
		algebraic[7]  = "d_ss in component L_Type_Calcium_Current (dimensionless)";
		algebraic[21]  = "alpha_d in component L_Type_Calcium_Current (millisecond)";
		algebraic[28]  = "beta_d in component L_Type_Calcium_Current (dimensionless)";
		algebraic[35]  = "gamma_d in component L_Type_Calcium_Current (millisecond)";
		algebraic[40]  = "tau_d in component L_Type_Calcium_Current (millisecond)";
		algebraic[8]  = "f_ss in component L_Type_Calcium_Current (dimensionless)";
		algebraic[22]  = "alpha_f in component L_Type_Calcium_Current (millisecond)";
		algebraic[29]  = "beta_f in component L_Type_Calcium_Current (millisecond)";
		algebraic[36]  = "gamma_f in component L_Type_Calcium_Current (millisecond)";
		algebraic[41]  = "tau_f in component L_Type_Calcium_Current (millisecond)";
		algebraic[9]  = "f_2_ss in component L_Type_Calcium_Current (dimensionless)";
		algebraic[23]  = "alpha_f_2 in component L_Type_Calcium_Current (millisecond)";
		algebraic[30]  = "beta_f_2 in component L_Type_Calcium_Current (millisecond)";
		algebraic[37]  = "gamma_f_2 in component L_Type_Calcium_Current (millisecond)";
		algebraic[42]  = "tau_f_2 in component L_Type_Calcium_Current (millisecond)";
		states[14]  = "d in component L_Type_Calcium_Current (dimensionless)";
		states[15]  = "f in component L_Type_Calcium_Current (dimensionless)";
		states[16]  = "f_2 in component L_Type_Calcium_Current (dimensionless)";
		states[17]  = "f_Ca_B_j in component L_Type_Calcium_Current (dimensionless)";
		states[18]  = "f_Ca_B_sl in component L_Type_Calcium_Current (dimensionless)";
		constants[34]  = "K_i in component Potassium_Concentrations (millimolar)";
		constants[35]  = "Ca_o in component Calcium_Concentrations (millimolar)";
		algebraic[60]  = "Ibar_Ca_j in component L_Type_Calcium_Current (picoA_per_picoF)";
		algebraic[61]  = "Ibar_Ca_sl in component L_Type_Calcium_Current (picoA_per_picoF)";
		algebraic[62]  = "Ibar_K in component L_Type_Calcium_Current (picoA_per_picoF)";
		algebraic[63]  = "Ibar_Na_j in component L_Type_Calcium_Current (picoA_per_picoF)";
		algebraic[64]  = "Ibar_Na_sl in component L_Type_Calcium_Current (picoA_per_picoF)";
		constants[36]  = "p_Ca in component L_Type_Calcium_Current (litre_per_farad_millisecond)";
		constants[37]  = "p_Na in component L_Type_Calcium_Current (litre_per_farad_millisecond)";
		constants[38]  = "p_K in component L_Type_Calcium_Current (litre_per_farad_millisecond)";
		algebraic[65]  = "I_Ca_junc in component L_Type_Calcium_Current (picoA_per_picoF)";
		algebraic[66]  = "I_Ca_sl in component L_Type_Calcium_Current (picoA_per_picoF)";
		algebraic[67]  = "I_Ca in component L_Type_Calcium_Current (picoA_per_picoF)";
		algebraic[69]  = "I_Ca_Na_junc in component L_Type_Calcium_Current (picoA_per_picoF)";
		algebraic[70]  = "I_Ca_Na_sl in component L_Type_Calcium_Current (picoA_per_picoF)";
		algebraic[72]  = "I_Ca_Na in component L_Type_Calcium_Current (picoA_per_picoF)";
		algebraic[68]  = "I_Ca_K in component L_Type_Calcium_Current (picoA_per_picoF)";
		algebraic[74]  = "I_Ca_L in component L_Type_Calcium_Current (picoA_per_picoF)";
		algebraic[71]  = "Ka_junc in component Na_Ca_Exchanger_Current (dimensionless)";
		algebraic[73]  = "Ka_sl in component Na_Ca_Exchanger_Current (dimensionless)";
		constants[39]  = "Kd_act in component Na_Ca_Exchanger_Current (millimolar)";
		constants[40]  = "Km_Ca_i in component Na_Ca_Exchanger_Current (millimolar)";
		constants[41]  = "Km_Ca_o in component Na_Ca_Exchanger_Current (millimolar)";
		constants[42]  = "Km_Na_i in component Na_Ca_Exchanger_Current (millimolar)";
		constants[43]  = "Km_Na_o in component Na_Ca_Exchanger_Current (millimolar)";
		constants[44]  = "k_sat in component Na_Ca_Exchanger_Current (dimensionless)";
		constants[45]  = "nu in component Na_Ca_Exchanger_Current (dimensionless)";
		algebraic[75]  = "s1_junc in component Na_Ca_Exchanger_Current (millimolar4)";
		algebraic[77]  = "s2_junc in component Na_Ca_Exchanger_Current (millimolar4)";
		algebraic[79]  = "s3_junc in component Na_Ca_Exchanger_Current (millimolar4)";
		algebraic[76]  = "s1_sl in component Na_Ca_Exchanger_Current (millimolar4)";
		algebraic[78]  = "s2_sl in component Na_Ca_Exchanger_Current (millimolar4)";
		algebraic[80]  = "s3_sl in component Na_Ca_Exchanger_Current (millimolar4)";
		constants[46]  = "Ibar_NCX in component Na_Ca_Exchanger_Current (picoA_per_picoF)";
		algebraic[82]  = "I_ncx_sl in component Na_Ca_Exchanger_Current (picoA_per_picoF)";
		algebraic[81]  = "I_ncx_junc in component Na_Ca_Exchanger_Current (picoA_per_picoF)";
		algebraic[84]  = "I_ncx in component Na_Ca_Exchanger_Current (picoA_per_picoF)";
		constants[47]  = "Km_P_Ca in component Sarcolemmal_Ca_Pump_Current (millimolar)";
		constants[48]  = "Ibar_PMCA in component Sarcolemmal_Ca_Pump_Current (picoA_per_picoF)";
		algebraic[83]  = "I_pCa_junc in component Sarcolemmal_Ca_Pump_Current (picoA_per_picoF)";
		algebraic[85]  = "I_pCa_sl in component Sarcolemmal_Ca_Pump_Current (picoA_per_picoF)";
		algebraic[87]  = "I_pCa in component Sarcolemmal_Ca_Pump_Current (picoA_per_picoF)";
		algebraic[112]  = "E_Ca_sl in component Nerst_Potentials (millivolt)";
		algebraic[109]  = "E_Ca_junc in component Nerst_Potentials (millivolt)";
		constants[49]  = "G_Ca_B in component Background_Ca_Current (milliS_per_microF)";
		algebraic[113]  = "I_Ca_Bk_sl in component Background_Ca_Current (picoA_per_picoF)";
		algebraic[110]  = "I_Ca_Bk_junc in component Background_Ca_Current (picoA_per_picoF)";
		algebraic[115]  = "I_Ca_Bk in component Background_Ca_Current (picoA_per_picoF)";
		constants[50]  = "Max_SR in component SR_Fluxes (dimensionless)";
		constants[51]  = "Min_SR in component SR_Fluxes (dimensionless)";
		states[19]  = "Ca_SR in component Calcium_Concentrations (millimolar)";
		constants[52]  = "ec50_SR in component SR_Fluxes (millimolar)";
		algebraic[11]  = "k_Ca_SR in component SR_Fluxes (dimensionless)";
		constants[53]  = "ko_Ca in component SR_Fluxes (per_milliM2_per_millis)";
		algebraic[25]  = "ko_SR_Ca in component SR_Fluxes (per_milliM2_per_millis)";
		constants[54]  = "ki_Ca in component SR_Fluxes (per_milliM_per_millis)";
		algebraic[32]  = "ki_SR_Ca in component SR_Fluxes (per_milliM_per_millis)";
		constants[55]  = "ki_m in component SR_Fluxes (per_millis)";
		constants[56]  = "ko_m in component SR_Fluxes (per_millis)";
		constants[57]  = "ks in component SR_Fluxes (per_millis)";
		constants[58]  = "Km_f in component SR_Fluxes (millimolar)";
		constants[59]  = "Km_r in component SR_Fluxes (millimolar)";
		algebraic[86]  = "J_SR_Ca_rel in component SR_Fluxes (milliM_per_millis)";
		algebraic[89]  = "J_SR_leak in component SR_Fluxes (milliM_per_millis)";
		algebraic[88]  = "J_ser_Ca in component SR_Fluxes (milliM_per_millis)";
		algebraic[39]  = "RI in component SR_Fluxes (dimensionless)";
		states[20]  = "Ry_Rr in component SR_Fluxes (dimensionless)";
		states[21]  = "Ry_Ro in component SR_Fluxes (dimensionless)";
		states[22]  = "Ry_Ri in component SR_Fluxes (dimensionless)";
		states[23]  = "Ca_i in component Calcium_Concentrations (millimolar)";
		constants[60]  = "V_max_SR_CaP in component SR_Fluxes (milliM_per_millis)";
		constants[61]  = "hill_SR_CaP in component SR_Fluxes (dimensionless)";
		constants[62]  = "Mg_i in component Magnesium_Concentrations (millimolar)";
		states[24]  = "TnC_l in component Cytosolic_Ca_Buffers (millimolar)";
		states[25]  = "TnC_h_c in component Cytosolic_Ca_Buffers (millimolar)";
		states[26]  = "TnC_h_m in component Cytosolic_Ca_Buffers (millimolar)";
		states[27]  = "CaM in component Cytosolic_Ca_Buffers (millimolar)";
		states[28]  = "Myo_c in component Cytosolic_Ca_Buffers (millimolar)";
		states[29]  = "Myo_m in component Cytosolic_Ca_Buffers (millimolar)";
		states[30]  = "SRB in component Cytosolic_Ca_Buffers (millimolar)";
		constants[63]  = "k_off_TnC_l in component Cytosolic_Ca_Buffers (per_millis)";
		constants[64]  = "k_off_TnC_h_Ca in component Cytosolic_Ca_Buffers (per_millis)";
		constants[65]  = "k_off_TnC_h_Mg in component Cytosolic_Ca_Buffers (per_millis)";
		constants[66]  = "k_off_CaM in component Cytosolic_Ca_Buffers (per_millis)";
		constants[67]  = "k_off_myo_Ca in component Cytosolic_Ca_Buffers (per_millis)";
		constants[68]  = "k_off_myo_Mg in component Cytosolic_Ca_Buffers (per_millis)";
		constants[69]  = "k_off_SR in component Cytosolic_Ca_Buffers (per_millis)";
		constants[70]  = "k_on_TnC_l in component Cytosolic_Ca_Buffers (per_milliM_per_millis)";
		constants[71]  = "k_on_TnC_h_Ca in component Cytosolic_Ca_Buffers (per_milliM_per_millis)";
		constants[72]  = "k_on_TnC_h_Mg in component Cytosolic_Ca_Buffers (per_milliM_per_millis)";
		constants[73]  = "k_on_CaM in component Cytosolic_Ca_Buffers (per_milliM_per_millis)";
		constants[74]  = "k_on_myo_Ca in component Cytosolic_Ca_Buffers (per_milliM_per_millis)";
		constants[75]  = "k_on_myo_Mg in component Cytosolic_Ca_Buffers (per_milliM_per_millis)";
		constants[76]  = "k_on_SR in component Cytosolic_Ca_Buffers (per_milliM_per_millis)";
		constants[77]  = "B_max_TnC_low in component Cytosolic_Ca_Buffers (millimolar)";
		constants[78]  = "B_max_TnC_high in component Cytosolic_Ca_Buffers (millimolar)";
		constants[79]  = "B_max_CaM in component Cytosolic_Ca_Buffers (millimolar)";
		constants[80]  = "B_max_myosin in component Cytosolic_Ca_Buffers (millimolar)";
		constants[81]  = "B_max_SR in component Cytosolic_Ca_Buffers (millimolar)";
		algebraic[92]  = "J_Ca_B_cytosol in component Cytosolic_Ca_Buffers (milliM_per_millis)";
		constants[106]  = "B_max_SL_low_j in component Junctional_and_SL_Ca_Buffers (millimolar)";
		constants[107]  = "B_max_SL_low_sl in component Junctional_and_SL_Ca_Buffers (millimolar)";
		constants[108]  = "B_max_SL_high_j in component Junctional_and_SL_Ca_Buffers (millimolar)";
		constants[109]  = "B_max_SL_high_sl in component Junctional_and_SL_Ca_Buffers (millimolar)";
		constants[82]  = "k_off_sl_l in component Junctional_and_SL_Ca_Buffers (per_millis)";
		constants[83]  = "k_off_sl_h in component Junctional_and_SL_Ca_Buffers (per_millis)";
		constants[84]  = "k_on_sl_l in component Junctional_and_SL_Ca_Buffers (per_milliM_per_millis)";
		constants[85]  = "k_on_sl_h in component Junctional_and_SL_Ca_Buffers (per_milliM_per_millis)";
		states[31]  = "SLL_j in component Junctional_and_SL_Ca_Buffers (millimolar)";
		states[32]  = "SLL_sl in component Junctional_and_SL_Ca_Buffers (millimolar)";
		states[33]  = "SLH_j in component Junctional_and_SL_Ca_Buffers (millimolar)";
		states[34]  = "SLH_sl in component Junctional_and_SL_Ca_Buffers (millimolar)";
		algebraic[90]  = "J_Ca_B_junction in component Junctional_and_SL_Ca_Buffers (milliM_per_millis)";
		algebraic[91]  = "J_Ca_B_sl in component Junctional_and_SL_Ca_Buffers (milliM_per_millis)";
		constants[86]  = "B_max_Na_j in component Sodium_Concentrations (millimolar)";
		constants[87]  = "B_max_Na_sl in component Sodium_Concentrations (millimolar)";
		constants[88]  = "k_off_Na in component Sodium_Concentrations (per_millis)";
		constants[89]  = "k_on_Na in component Sodium_Concentrations (per_milliM_per_millis)";
		states[35]  = "Na_i in component Sodium_Concentrations (millimolar)";
		states[36]  = "Na_B_j in component Sodium_Concentrations (millimolar)";
		states[37]  = "Na_B_sl in component Sodium_Concentrations (millimolar)";
		constants[110]  = "B_max_csqn in component Calcium_Concentrations (millimolar)";
		states[38]  = "Csqn_b in component Calcium_Concentrations (millimolar)";
		constants[90]  = "k_off_csqn in component Calcium_Concentrations (per_millis)";
		constants[91]  = "k_on_csqn in component Calcium_Concentrations (per_milliM_per_millis)";
		constants[92]  = "Cl_i in component Chlorine_Concentrations (millimolar)";
		constants[93]  = "Cl_o in component Chlorine_Concentrations (millimolar)";
		constants[94]  = "p_Na_K in component Nerst_Potentials (dimensionless)";
		rates[0]  = "d/dt V in component membrane (millivolt)";
		rates[1]  = "d/dt m in component Fast_Na_Current (dimensionless)";
		rates[2]  = "d/dt h in component Fast_Na_Current (dimensionless)";
		rates[3]  = "d/dt j in component Fast_Na_Current (dimensionless)";
		rates[6]  = "d/dt x_Kr in component Rapidly_Activating_K_Current (dimensionless)";
		rates[7]  = "d/dt x_Ks in component Slowly_Activating_K_Current (dimensionless)";
		rates[8]  = "d/dt x_to_s in component Transient_Outward_K_Current (dimensionless)";
		rates[9]  = "d/dt y_to_s in component Transient_Outward_K_Current (dimensionless)";
		rates[10]  = "d/dt x_to_f in component Transient_Outward_K_Current (dimensionless)";
		rates[11]  = "d/dt y_to_f in component Transient_Outward_K_Current (dimensionless)";
		rates[14]  = "d/dt d in component L_Type_Calcium_Current (dimensionless)";
		rates[15]  = "d/dt f in component L_Type_Calcium_Current (dimensionless)";
		rates[16]  = "d/dt f_2 in component L_Type_Calcium_Current (dimensionless)";
		rates[17]  = "d/dt f_Ca_B_j in component L_Type_Calcium_Current (dimensionless)";
		rates[18]  = "d/dt f_Ca_B_sl in component L_Type_Calcium_Current (dimensionless)";
		rates[20]  = "d/dt Ry_Rr in component SR_Fluxes (dimensionless)";
		rates[21]  = "d/dt Ry_Ro in component SR_Fluxes (dimensionless)";
		rates[22]  = "d/dt Ry_Ri in component SR_Fluxes (dimensionless)";
		rates[24]  = "d/dt TnC_l in component Cytosolic_Ca_Buffers (millimolar)";
		rates[25]  = "d/dt TnC_h_c in component Cytosolic_Ca_Buffers (millimolar)";
		rates[26]  = "d/dt TnC_h_m in component Cytosolic_Ca_Buffers (millimolar)";
		rates[27]  = "d/dt CaM in component Cytosolic_Ca_Buffers (millimolar)";
		rates[28]  = "d/dt Myo_c in component Cytosolic_Ca_Buffers (millimolar)";
		rates[29]  = "d/dt Myo_m in component Cytosolic_Ca_Buffers (millimolar)";
		rates[30]  = "d/dt SRB in component Cytosolic_Ca_Buffers (millimolar)";
		rates[31]  = "d/dt SLL_j in component Junctional_and_SL_Ca_Buffers (millimolar)";
		rates[32]  = "d/dt SLL_sl in component Junctional_and_SL_Ca_Buffers (millimolar)";
		rates[33]  = "d/dt SLH_j in component Junctional_and_SL_Ca_Buffers (millimolar)";
		rates[34]  = "d/dt SLH_sl in component Junctional_and_SL_Ca_Buffers (millimolar)";
		rates[4]  = "d/dt Na_j in component Sodium_Concentrations (millimolar)";
		rates[36]  = "d/dt Na_B_j in component Sodium_Concentrations (millimolar)";
		rates[5]  = "d/dt Na_sl in component Sodium_Concentrations (millimolar)";
		rates[37]  = "d/dt Na_B_sl in component Sodium_Concentrations (millimolar)";
		rates[35]  = "d/dt Na_i in component Sodium_Concentrations (millimolar)";
		rates[38]  = "d/dt Csqn_b in component Calcium_Concentrations (millimolar)";
		rates[12]  = "d/dt Ca_j in component Calcium_Concentrations (millimolar)";
		rates[13]  = "d/dt Ca_sl in component Calcium_Concentrations (millimolar)";
		rates[23]  = "d/dt Ca_i in component Calcium_Concentrations (millimolar)";
		rates[19]  = "d/dt Ca_SR in component Calcium_Concentrations (millimolar)";
	}

	void initConsts(double* constants, double* states){
		states[0] = -8.410546e1;
		constants[0] = 8314;
		constants[1] = 310;
		constants[2] = 96485;
		constants[3] = 1.381e-10;
		constants[4] = 0;
		constants[5] = 100000;
		constants[6] = 40;
		constants[7] = 1000;
		constants[8] = 1;
		constants[9] = 0.11;
		constants[10] = 0.9;
		constants[11] = 100e-5;
		constants[12] = 10.25e-5;
		constants[13] = 8.2413e-13;
		constants[14] = 3.7243e-12;
		constants[15] = 1.8313e-14;
		constants[16] = 1.6386e-12;
		constants[17] = 18.86;
		states[1] = 2.176608e-3;
		states[2] = 7.126555e-1;
		states[3] = 7.119893e-1;
		constants[18] = 0.597e-3;
		constants[19] = 140;
		constants[20] = 0.99;
		constants[21] = 5.4;
		states[4] = 1.00211e1;
		states[5] = 1.001974e1;
		constants[22] = 1.5;
		constants[23] = 11;
		states[6] = 1.896559e-2;
		constants[24] = 0.035;
		states[7] = 3.55636e-3;
		constants[25] = 0.0035;
		constants[26] = 0.0035;
		constants[27] = 0.002;
		states[8] = 3.592503e-4;
		states[9] = 8.161309e-1;
		states[10] = 3.592405e-4;
		states[11] = 9.999976e-1;
		constants[28] = 3.7596e-2;
		constants[29] = 1.404e-3;
		constants[30] = 0.57153;
		states[12] = 2.048633e-4;
		states[13] = 1.188246e-4;
		constants[31] = 0.054813;
		constants[32] = 100e-3;
		constants[33] = 9e-3;
		states[14] = 1.879996e-6;
		states[15] = 9.789409e-1;
		states[16] = 9.993986e-1;
		states[17] = 2.861794e-2;
		states[18] = 1.69833e-2;
		constants[34] = 138;
		constants[35] = 1.8;
		constants[36] = 1.9887e-4;
		constants[37] = 3.0375e-9;
		constants[38] = 5.4675e-8;
		constants[39] = 0.15e-3;
		constants[40] = 3.59e-3;
		constants[41] = 1.3;
		constants[42] = 12.29;
		constants[43] = 87.5;
		constants[44] = 0.32;
		constants[45] = 0.27;
		constants[46] = 4.5;
		constants[47] = 0.5e-3;
		constants[48] = 0.0673;
		constants[49] = 5.513e-4;
		constants[50] = 15;
		constants[51] = 1;
		states[19] = 6.138856e-1;
		constants[52] = 0.45;
		constants[53] = 10;
		constants[54] = 0.5;
		constants[55] = 0.005;
		constants[56] = 0.06;
		constants[57] = 25;
		constants[58] = 0.246e-3;
		constants[59] = 1.7;
		states[20] = 8.888214e-1;
		states[21] = 1.149876e-6;
		states[22] = 1.43831e-7;
		states[23] = 9.719632e-5;
		constants[60] = 5.3114e-3;
		constants[61] = 1.787;
		constants[62] = 1;
		states[24] = 9.811535e-3;
		states[25] = 1.225802e-1;
		states[26] = 8.128604e-3;
		states[27] = 3.288063e-4;
		states[28] = 2.522168e-3;
		states[29] = 1.369514e-1;
		states[30] = 2.38683e-3;
		constants[63] = 19.6e-3;
		constants[64] = 0.032e-3;
		constants[65] = 3.33e-3;
		constants[66] = 238e-3;
		constants[67] = 0.46e-3;
		constants[68] = 0.057e-3;
		constants[69] = 60e-3;
		constants[70] = 32.7;
		constants[71] = 2.37;
		constants[72] = 3e-3;
		constants[73] = 34;
		constants[74] = 13.8;
		constants[75] = 0.0157;
		constants[76] = 100;
		constants[77] = 70e-3;
		constants[78] = 140e-3;
		constants[79] = 24e-3;
		constants[80] = 140e-3;
		constants[81] = 17.1e-3;
		constants[82] = 1.3;
		constants[83] = 30e-3;
		constants[84] = 100;
		constants[85] = 100;
		states[31] = 8.606485e-3;
		states[32] = 1.101044e-2;
		states[33] = 8.078504e-2;
		states[34] = 1.238366e-1;
		constants[86] = 7.561;
		constants[87] = 1.65;
		constants[88] = 1e-3;
		constants[89] = 0.1e-3;
		states[35] = 1.001989e1;
		states[36] = 3.785209e0;
		states[37] = 8.259271e-1;
		states[38] = 1.262853;
		constants[90] = 65;
		constants[91] = 100;
		constants[92] = 15;
		constants[93] = 150;
		constants[94] = 0.01833;
		constants[95] = constants[2]/( constants[0]*constants[1]);
		constants[96] = 1.00000 - constants[9];
		constants[97] = 1.00000 - constants[10];
		constants[98] =   3.14159265358979*pow(constants[12], 2.00000)*constants[11];
		constants[99] = (exp(constants[19]/67.3000) - 1.00000)/7.00000;
		constants[100] =  0.650000*constants[98];
		constants[101] =  (1.00000/constants[95])*log(constants[21]/constants[34]);
		constants[102] =  (1.00000/constants[95])*log(constants[92]/constants[93]);
		constants[103] =  0.0200000*constants[98];
		constants[104] =  0.0350000*constants[98];
		constants[105] =  0.000539000*constants[98];
		constants[106] = ( 0.000460000*constants[100])/constants[105];
		constants[107] = ( 0.0374000*constants[100])/constants[103];
		constants[108] = ( 0.000165000*constants[100])/constants[105];
		constants[109] = ( 0.0134000*constants[100])/constants[103];
		constants[110] = ( 0.140000*constants[100])/constants[104];
	}

	void computeRates(double VoI, double* constants, double* rates, double* states, double* algebraic){
		rates[17] =  1.70000*states[12]*(1.00000 - states[17]) -  0.0119000*states[17];
		rates[18] =  1.70000*states[13]*(1.00000 - states[18]) -  0.0119000*states[18];
		rates[35] =  (constants[16]/constants[100])*(states[5] - states[35]);
		algebraic[0] = 1.00000/pow(1.00000+exp(- (56.8600+states[0])/9.03000), 2.00000);
		algebraic[12] =  0.129200*exp(- pow((states[0]+45.7900)/15.5400, 2.00000))+ 0.0648700*exp(- pow((states[0] - 4.82300)/51.1200, 2.00000));
		rates[1] = (algebraic[0] - states[1])/algebraic[12];
		algebraic[3] = 1.00000/(1.00000+exp(- (states[0]+10.0000)/5.00000));
		algebraic[15] = 3300.00/( (1.00000+exp((- 22.0000 - states[0])/9.00000))*(1.00000+exp((states[0]+11.0000)/9.00000)))+230.000/(1.00000+exp((states[0]+40.0000)/20.0000));
		rates[6] = (algebraic[3] - states[6])/algebraic[15];
		algebraic[4] = 1.00000/(1.00000+exp(- (states[0]+3.80000)/14.2500));
		algebraic[16] = 990.100/(1.00000+exp(- (states[0]+2.43600)/14.1200));
		rates[7] = (algebraic[4] - states[7])/algebraic[16];
		algebraic[5] = 1.00000/(1.00000+exp(- (states[0] - 19.0000)/13.0000));
		algebraic[17] = 9.00000/(1.00000+exp((states[0]+3.00000)/15.0000))+0.500000;
		rates[8] = (algebraic[5] - states[8])/algebraic[17];
		algebraic[6] = 1.00000/(1.00000+exp((states[0]+19.5000)/5.00000));
		algebraic[18] = 800.000/(1.00000+exp((states[0]+60.0000)/10.0000))+30.0000;
		rates[9] = (algebraic[6] - states[9])/algebraic[18];
		algebraic[19] =  8.50000*exp(- pow((states[0]+45.0000)/50.0000, 2.00000))+0.500000;
		rates[10] = (algebraic[5] - states[10])/algebraic[19];
		algebraic[20] =  85.0000*exp(- pow(states[0]+40.0000, 2.00000)/220.000)+7.00000;
		rates[11] = (algebraic[6] - states[11])/algebraic[20];
		algebraic[11] = constants[50] - (constants[50] - constants[51])/(1.00000+pow(constants[52]/states[19], 2.50000));
		algebraic[25] = constants[53]/algebraic[11];
		algebraic[32] =  constants[54]*algebraic[11];
		rates[21] = ( algebraic[25]*pow(states[12], 2.00000)*states[20] -  constants[56]*states[21]) - ( algebraic[32]*states[12]*states[21] -  constants[55]*states[22]);
		algebraic[1] = (states[0]>=- 40.0000 ? 0.00000 :  0.0570000*exp(- (states[0]+80.0000)/6.80000));
		algebraic[13] = (states[0]>=- 40.0000 ? 5.92310/(1.00000+exp(- (states[0]+10.6600)/11.1000)) :  2.70000*exp( 0.0790000*states[0])+ 310000.*exp( 0.348500*states[0]));
		algebraic[26] = 1.00000/(algebraic[1]+algebraic[13]);
		algebraic[33] = 1.00000/pow(1.00000+exp((states[0]+71.5500)/7.43000), 2.00000);
		rates[2] = (algebraic[33] - states[2])/algebraic[26];
		algebraic[2] = (states[0]>=- 40.0000 ? 0.00000 : ( ( - 25428.0*exp( 0.244400*states[0]) -  6.94800e-06*exp( - 0.0439100*states[0]))*(states[0]+37.7800))/(1.00000+exp( 0.311000*(states[0]+79.2300))));
		algebraic[14] = (states[0]>=- 40.0000 ? ( 0.600000*exp( 0.0570000*states[0]))/(1.00000+exp( - 0.100000*(states[0]+32.0000))) : ( 0.0242400*exp( - 0.0105200*states[0]))/(1.00000+exp( - 0.137800*(states[0]+40.1400))));
		algebraic[27] = 1.00000/(algebraic[2]+algebraic[14]);
		algebraic[34] = 1.00000/pow(1.00000+exp((states[0]+71.5500)/7.43000), 2.00000);
		rates[3] = (algebraic[34] - states[3])/algebraic[27];
		algebraic[39] = ((1.00000 - states[20]) - states[21]) - states[22];
		rates[20] = ( constants[55]*algebraic[39] -  algebraic[32]*states[12]*states[20]) - ( algebraic[25]*pow(states[12], 2.00000)*states[20] -  constants[56]*states[21]);
		rates[22] = ( algebraic[32]*states[12]*states[21] -  constants[55]*states[22]) - ( constants[56]*states[22] -  algebraic[25]*pow(states[12], 2.00000)*algebraic[39]);
		algebraic[7] = 1.00000/(1.00000+exp(- (states[0]+5.00000)/6.00000));
		algebraic[21] = 1.40000/(1.00000+exp((- 35.0000 - states[0])/13.0000))+0.250000;
		algebraic[28] = 1.40000/(1.00000+exp((states[0]+5.00000)/5.00000));
		algebraic[35] = 1.00000/(1.00000+exp((50.0000 - states[0])/20.0000));
		algebraic[40] =  algebraic[21]*algebraic[28]+algebraic[35];
		rates[14] = (algebraic[7] - states[14])/algebraic[40];
		algebraic[8] = 1.00000/(1.00000+exp((states[0]+20.0000)/7.00000));
		algebraic[22] =  1102.50*exp(- pow((states[0]+27.0000)/15.0000, 2.00000));
		algebraic[29] = 200.000/(1.00000+exp((13.0000 - states[0])/10.0000));
		algebraic[36] = 180.000/(1.00000+exp((states[0]+30.0000)/10.0000))+20.0000;
		algebraic[41] = algebraic[22]+algebraic[29]+algebraic[36];
		rates[15] = (algebraic[8] - states[15])/algebraic[41];
		algebraic[9] = 0.670000/(1.00000+exp((states[0]+35.0000)/7.00000))+0.330000;
		algebraic[23] =  300.000*exp(- pow(states[0]+25.0000, 2.00000)/170.000);
		algebraic[30] = 31.0000/(1.00000+exp((25.0000 - states[0])/10.0000));
		algebraic[37] = 16.0000/(1.00000+exp((states[0]+30.0000)/10.0000));
		algebraic[42] = algebraic[23]+algebraic[30]+algebraic[37];
		rates[16] = (algebraic[9] - states[16])/algebraic[42];
		rates[24] =  constants[70]*states[23]*(constants[77] - states[24]) -  constants[63]*states[24];
		rates[31] =  constants[84]*states[12]*(constants[106] - states[31]) -  constants[82]*states[31];
		rates[25] =  constants[71]*states[23]*((constants[78] - states[25]) - states[26]) -  constants[64]*states[25];
		rates[38] =  constants[91]*states[19]*(constants[110] - states[38]) -  constants[90]*states[38];
		rates[32] =  constants[84]*states[13]*(constants[107] - states[32]) -  constants[82]*states[32];
		rates[26] =  constants[72]*constants[62]*((constants[78] - states[25]) - states[26]) -  constants[65]*states[26];
		algebraic[86] =  constants[57]*states[21]*(states[19] - states[12]);
		algebraic[89] =  5.34800e-06*(states[19] - states[12]);
		algebraic[88] = ( constants[60]*(pow(states[23]/constants[58], constants[61]) - pow(states[19]/constants[59], constants[61])))/(1.00000+pow(states[23]/constants[58], constants[61])+pow(states[19]/constants[59], constants[61]));
		rates[19] = (algebraic[88] - (( algebraic[89]*constants[100])/constants[104]+algebraic[86])) - rates[38];
		rates[33] =  constants[85]*states[12]*(constants[108] - states[33]) -  constants[83]*states[33];
		rates[27] =  constants[73]*states[23]*(constants[79] - states[27]) -  constants[66]*states[27];
		rates[34] =  constants[85]*states[13]*(constants[109] - states[34]) -  constants[83]*states[34];
		rates[28] =  constants[74]*states[23]*((constants[80] - states[28]) - states[29]) -  constants[67]*states[28];
		rates[29] =  constants[75]*constants[62]*((constants[80] - states[28]) - states[29]) -  constants[68]*states[29];
		rates[30] =  constants[76]*states[23]*(constants[81] - states[30]) -  constants[69]*states[30];
		rates[36] =  constants[89]*states[4]*(constants[86] - states[36]) -  constants[88]*states[36];
		rates[37] =  constants[89]*states[5]*(constants[87] - states[37]) -  constants[88]*states[37];
		algebraic[92] = rates[24]+rates[25]+rates[26]+rates[27]+rates[28]+rates[29]+rates[30];
		rates[23] = (( - algebraic[88]*constants[104])/constants[100] - algebraic[92])+ (constants[14]/constants[100])*(states[13] - states[23]);
		algebraic[93] =  (1.00000/constants[95])*log(constants[19]/states[4]);
		algebraic[94] =  constants[9]*constants[17]*pow(states[1], 3.00000)*states[2]*states[3]*(states[0] - algebraic[93]);
		algebraic[95] =  constants[9]*constants[18]*(states[0] - algebraic[93]);
		algebraic[24] = 1.00000/(1.00000+ 0.124500*exp( - 0.100000*states[0]*constants[95])+ 0.0365000*constants[99]*exp( - states[0]*constants[95]));
		algebraic[31] = ( constants[9]*constants[20]*algebraic[24]*constants[21])/( (1.00000+pow(constants[23]/states[4], 4.00000))*(constants[21]+constants[22]));
		algebraic[63] = ( constants[37]*states[0]*constants[2]*constants[95]*( states[4]*exp( states[0]*constants[95]) - constants[19]))/(exp( states[0]*constants[95]) - 1.00000);
		algebraic[69] =  constants[10]*algebraic[63]*states[14]*states[15]*states[16]*(1.00000 - states[17]);
		algebraic[71] = 1.00000/(1.00000+pow(constants[39]/states[12], 2.00000));
		algebraic[75] =  exp( constants[45]*states[0]*constants[95])*pow(states[4], 3.00000)*constants[35];
		algebraic[77] =  exp( (constants[45] - 1.00000)*states[0]*constants[95])*pow(constants[19], 3.00000)*states[12];
		algebraic[79] =  constants[40]*pow(constants[19], 3.00000)*(1.00000+pow(states[4]/constants[42], 3.00000))+ pow(constants[43], 3.00000)*states[12]*(1.00000+states[12]/constants[40])+ constants[41]*pow(states[4], 3.00000)+ pow(states[4], 3.00000)*constants[35]+ pow(constants[19], 3.00000)*states[12];
		algebraic[81] = ( constants[9]*constants[46]*algebraic[71]*(algebraic[75] - algebraic[77]))/( algebraic[79]*(1.00000+ constants[44]*exp( (constants[45] - 1.00000)*states[0]*constants[95])));
		algebraic[96] = algebraic[94]+algebraic[95]+ 3.00000*algebraic[81]+ 3.00000*algebraic[31]+algebraic[69];
		rates[4] = (( - algebraic[96]*constants[3])/( constants[105]*constants[2])+ (constants[15]/constants[105])*(states[5] - states[4])) - rates[36];
		algebraic[97] =  (1.00000/constants[95])*log(constants[19]/states[5]);
		algebraic[98] =  constants[96]*constants[17]*pow(states[1], 3.00000)*states[2]*states[3]*(states[0] - algebraic[97]);
		algebraic[100] =  constants[96]*constants[18]*(states[0] - algebraic[97]);
		algebraic[38] = ( constants[96]*constants[20]*algebraic[24]*constants[21])/( (1.00000+pow(constants[23]/states[5], 4.00000))*(constants[21]+constants[22]));
		algebraic[64] = ( constants[37]*states[0]*constants[2]*constants[95]*( states[5]*exp( states[0]*constants[95]) - constants[19]))/(exp( states[0]*constants[95]) - 1.00000);
		algebraic[70] =  constants[97]*algebraic[64]*states[14]*states[15]*states[16]*(1.00000 - states[18]);
		algebraic[73] = 1.00000/(1.00000+pow(constants[39]/states[13], 2.00000));
		algebraic[76] =  exp( constants[45]*states[0]*constants[95])*pow(states[5], 3.00000)*constants[35];
		algebraic[78] =  exp( (constants[45] - 1.00000)*states[0]*constants[95])*pow(constants[19], 3.00000)*states[13];
		algebraic[80] =  constants[40]*pow(constants[19], 3.00000)*(1.00000+pow(states[5]/constants[42], 3.00000))+ pow(constants[43], 3.00000)*states[13]*(1.00000+states[13]/constants[40])+ constants[41]*pow(states[5], 3.00000)+ pow(states[5], 3.00000)*constants[35]+ pow(constants[19], 3.00000)*states[13];
		algebraic[82] = ( constants[96]*constants[46]*algebraic[73]*(algebraic[76] - algebraic[78]))/( algebraic[80]*(1.00000+ constants[44]*exp( (constants[45] - 1.00000)*states[0]*constants[95])));
		algebraic[102] = algebraic[98]+algebraic[100]+ 3.00000*algebraic[82]+ 3.00000*algebraic[38]+algebraic[70];
		rates[5] = (( - algebraic[102]*constants[3])/( constants[103]*constants[2])+ (constants[15]/constants[103])*(states[4] - states[5])+ (constants[16]/constants[103])*(states[35] - states[5])) - rates[37];
		algebraic[60] = ( constants[36]*states[0]*constants[2]*constants[95]*( states[12]*exp( 2.00000*states[0]*constants[95]) - constants[35]))/(exp( 2.00000*states[0]*constants[95]) - 1.00000);
		algebraic[65] =  constants[10]*algebraic[60]*states[14]*states[15]*states[16]*(1.00000 - states[17]);
		algebraic[83] = ( constants[9]*constants[48]*pow(states[12], 1.60000))/(pow(constants[47], 1.60000)+pow(states[12], 1.60000));
		algebraic[109] =  (1.00000/( 2.00000*constants[95]))*log(constants[35]/states[12]);
		algebraic[110] =  constants[9]*constants[49]*(states[0] - algebraic[109]);
		algebraic[111] = (algebraic[65]+algebraic[110]+algebraic[83]) -  2.00000*algebraic[81];
		algebraic[90] = rates[31]+rates[33];
		rates[12] = ((( - algebraic[111]*constants[3])/( constants[105]*2.00000*constants[2])+ (constants[13]/constants[105])*(states[13] - states[12])) - algebraic[90])+( algebraic[86]*constants[104])/constants[105]+( algebraic[89]*constants[100])/constants[105];
		algebraic[61] = ( constants[36]*states[0]*constants[2]*constants[95]*( states[13]*exp( 2.00000*states[0]*constants[95]) - constants[35]))/(exp( 2.00000*states[0]*constants[95]) - 1.00000);
		algebraic[66] =  constants[97]*algebraic[61]*states[14]*states[15]*states[16]*(1.00000 - states[18]);
		algebraic[85] = ( constants[96]*constants[48]*pow(states[13], 1.60000))/(pow(constants[47], 1.60000)+pow(states[13], 1.60000));
		algebraic[112] =  (1.00000/( 2.00000*constants[95]))*log(constants[35]/states[13]);
		algebraic[113] =  constants[96]*constants[49]*(states[0] - algebraic[112]);
		algebraic[114] = (algebraic[66]+algebraic[113]+algebraic[85]) -  2.00000*algebraic[82];
		algebraic[91] = rates[32]+rates[34];
		rates[13] = (( - algebraic[114]*constants[3])/( constants[103]*2.00000*constants[2])+ (constants[13]/constants[103])*(states[12] - states[13])+ (constants[14]/constants[103])*(states[23] - states[13])) - algebraic[91];
		algebraic[43] = algebraic[31]+algebraic[38];
		algebraic[44] = 1.00000/(1.00000+exp((states[0]+74.0000)/24.0000));
		algebraic[45] =  constants[24]* pow((constants[21]/5.40000), 1.0 / 2)*states[6]*algebraic[44]*(states[0] - constants[101]);
		algebraic[104] =  (1.00000/constants[95])*log((constants[21]+ constants[94]*constants[19])/(constants[34]+ constants[94]*states[35]));
		algebraic[105] =  constants[9]*constants[25]*pow(states[7], 2.00000)*(states[0] - algebraic[104]);
		algebraic[106] =  constants[96]*constants[26]*pow(states[7], 2.00000)*(states[0] - algebraic[104]);
		algebraic[107] = algebraic[105]+algebraic[106];
		algebraic[46] = 1.00000/(1.00000+exp(7.48800 - states[0]/5.98000));
		algebraic[47] =  constants[27]*algebraic[46]*(states[0] - constants[101]);
		algebraic[48] =  constants[28]*states[8]*states[9]*(states[0] - constants[101]);
		algebraic[49] =  constants[29]*states[10]*states[11]*(states[0] - constants[101]);
		algebraic[50] = algebraic[48]+algebraic[49];
		algebraic[51] = 4.09380/(1.00000+exp( 0.121650*((states[0] - constants[101]) - 49.9344)));
		algebraic[52] = ( 15.7197*exp( 0.0673900*((states[0] - constants[101]) - 3.25710))+exp( 0.0617500*((states[0] - constants[101]) - 594.310)))/(1.00000+exp( - 0.162850*((states[0] - constants[101])+14.2067)));
		algebraic[53] = algebraic[51]/(algebraic[51]+algebraic[52]);
		algebraic[54] =  constants[30]* pow((constants[21]/5.40000), 1.0 / 2)*algebraic[53]*(states[0] - constants[101]);
		algebraic[62] = ( constants[38]*states[0]*constants[2]*constants[95]*( constants[34]*exp( states[0]*constants[95]) - constants[21]))/(exp( states[0]*constants[95]) - 1.00000);
		algebraic[68] =  algebraic[62]*states[14]*states[15]*states[16]*( constants[10]*(1.00000 - states[17])+ constants[97]*(1.00000 - states[18]));
		algebraic[108] = ((algebraic[50]+algebraic[45]+algebraic[107]+algebraic[54]) -  2.00000*algebraic[43])+algebraic[68]+algebraic[47];
		algebraic[103] = algebraic[96]+algebraic[102];
		algebraic[55] =  (( constants[9]*constants[31])/(1.00000+constants[32]/states[12]))*(states[0] - constants[102]);
		algebraic[56] =  (( constants[96]*constants[31])/(1.00000+constants[32]/states[13]))*(states[0] - constants[102]);
		algebraic[57] = algebraic[55]+algebraic[56];
		algebraic[58] =  constants[33]*(states[0] - constants[102]);
		algebraic[59] = algebraic[57]+algebraic[58];
		algebraic[116] = algebraic[111]+algebraic[114];
		algebraic[117] = algebraic[103]+algebraic[59]+algebraic[116]+algebraic[108];
		algebraic[10] = (VoI>=constants[4]&&VoI<=constants[5]&&(VoI - constants[4]) -  floor((VoI - constants[4])/constants[7])*constants[7]<=constants[8] ? constants[6] : 0.00000);
		rates[0] = - (algebraic[117] - algebraic[10]);
	}

	void computeVariables(double VoI, double* constants, double* rates, double* states, double* algebraic){
		algebraic[0] = 1.00000/pow(1.00000+exp(- (56.8600+states[0])/9.03000), 2.00000);
		algebraic[12] =  0.129200*exp(- pow((states[0]+45.7900)/15.5400, 2.00000))+ 0.0648700*exp(- pow((states[0] - 4.82300)/51.1200, 2.00000));
		algebraic[3] = 1.00000/(1.00000+exp(- (states[0]+10.0000)/5.00000));
		algebraic[15] = 3300.00/( (1.00000+exp((- 22.0000 - states[0])/9.00000))*(1.00000+exp((states[0]+11.0000)/9.00000)))+230.000/(1.00000+exp((states[0]+40.0000)/20.0000));
		algebraic[4] = 1.00000/(1.00000+exp(- (states[0]+3.80000)/14.2500));
		algebraic[16] = 990.100/(1.00000+exp(- (states[0]+2.43600)/14.1200));
		algebraic[5] = 1.00000/(1.00000+exp(- (states[0] - 19.0000)/13.0000));
		algebraic[17] = 9.00000/(1.00000+exp((states[0]+3.00000)/15.0000))+0.500000;
		algebraic[6] = 1.00000/(1.00000+exp((states[0]+19.5000)/5.00000));
		algebraic[18] = 800.000/(1.00000+exp((states[0]+60.0000)/10.0000))+30.0000;
		algebraic[19] =  8.50000*exp(- pow((states[0]+45.0000)/50.0000, 2.00000))+0.500000;
		algebraic[20] =  85.0000*exp(- pow(states[0]+40.0000, 2.00000)/220.000)+7.00000;
		algebraic[11] = constants[50] - (constants[50] - constants[51])/(1.00000+pow(constants[52]/states[19], 2.50000));
		algebraic[25] = constants[53]/algebraic[11];
		algebraic[32] =  constants[54]*algebraic[11];
		algebraic[1] = (states[0]>=- 40.0000 ? 0.00000 :  0.0570000*exp(- (states[0]+80.0000)/6.80000));
		algebraic[13] = (states[0]>=- 40.0000 ? 5.92310/(1.00000+exp(- (states[0]+10.6600)/11.1000)) :  2.70000*exp( 0.0790000*states[0])+ 310000.*exp( 0.348500*states[0]));
		algebraic[26] = 1.00000/(algebraic[1]+algebraic[13]);
		algebraic[33] = 1.00000/pow(1.00000+exp((states[0]+71.5500)/7.43000), 2.00000);
		algebraic[2] = (states[0]>=- 40.0000 ? 0.00000 : ( ( - 25428.0*exp( 0.244400*states[0]) -  6.94800e-06*exp( - 0.0439100*states[0]))*(states[0]+37.7800))/(1.00000+exp( 0.311000*(states[0]+79.2300))));
		algebraic[14] = (states[0]>=- 40.0000 ? ( 0.600000*exp( 0.0570000*states[0]))/(1.00000+exp( - 0.100000*(states[0]+32.0000))) : ( 0.0242400*exp( - 0.0105200*states[0]))/(1.00000+exp( - 0.137800*(states[0]+40.1400))));
		algebraic[27] = 1.00000/(algebraic[2]+algebraic[14]);
		algebraic[34] = 1.00000/pow(1.00000+exp((states[0]+71.5500)/7.43000), 2.00000);
		algebraic[39] = ((1.00000 - states[20]) - states[21]) - states[22];
		algebraic[7] = 1.00000/(1.00000+exp(- (states[0]+5.00000)/6.00000));
		algebraic[21] = 1.40000/(1.00000+exp((- 35.0000 - states[0])/13.0000))+0.250000;
		algebraic[28] = 1.40000/(1.00000+exp((states[0]+5.00000)/5.00000));
		algebraic[35] = 1.00000/(1.00000+exp((50.0000 - states[0])/20.0000));
		algebraic[40] =  algebraic[21]*algebraic[28]+algebraic[35];
		algebraic[8] = 1.00000/(1.00000+exp((states[0]+20.0000)/7.00000));
		algebraic[22] =  1102.50*exp(- pow((states[0]+27.0000)/15.0000, 2.00000));
		algebraic[29] = 200.000/(1.00000+exp((13.0000 - states[0])/10.0000));
		algebraic[36] = 180.000/(1.00000+exp((states[0]+30.0000)/10.0000))+20.0000;
		algebraic[41] = algebraic[22]+algebraic[29]+algebraic[36];
		algebraic[9] = 0.670000/(1.00000+exp((states[0]+35.0000)/7.00000))+0.330000;
		algebraic[23] =  300.000*exp(- pow(states[0]+25.0000, 2.00000)/170.000);
		algebraic[30] = 31.0000/(1.00000+exp((25.0000 - states[0])/10.0000));
		algebraic[37] = 16.0000/(1.00000+exp((states[0]+30.0000)/10.0000));
		algebraic[42] = algebraic[23]+algebraic[30]+algebraic[37];
		algebraic[86] =  constants[57]*states[21]*(states[19] - states[12]);
		algebraic[89] =  5.34800e-06*(states[19] - states[12]);
		algebraic[88] = ( constants[60]*(pow(states[23]/constants[58], constants[61]) - pow(states[19]/constants[59], constants[61])))/(1.00000+pow(states[23]/constants[58], constants[61])+pow(states[19]/constants[59], constants[61]));
		algebraic[92] = rates[24]+rates[25]+rates[26]+rates[27]+rates[28]+rates[29]+rates[30];
		algebraic[93] =  (1.00000/constants[95])*log(constants[19]/states[4]);
		algebraic[94] =  constants[9]*constants[17]*pow(states[1], 3.00000)*states[2]*states[3]*(states[0] - algebraic[93]);
		algebraic[95] =  constants[9]*constants[18]*(states[0] - algebraic[93]);
		algebraic[24] = 1.00000/(1.00000+ 0.124500*exp( - 0.100000*states[0]*constants[95])+ 0.0365000*constants[99]*exp( - states[0]*constants[95]));
		algebraic[31] = ( constants[9]*constants[20]*algebraic[24]*constants[21])/( (1.00000+pow(constants[23]/states[4], 4.00000))*(constants[21]+constants[22]));
		algebraic[63] = ( constants[37]*states[0]*constants[2]*constants[95]*( states[4]*exp( states[0]*constants[95]) - constants[19]))/(exp( states[0]*constants[95]) - 1.00000);
		algebraic[69] =  constants[10]*algebraic[63]*states[14]*states[15]*states[16]*(1.00000 - states[17]);
		algebraic[71] = 1.00000/(1.00000+pow(constants[39]/states[12], 2.00000));
		algebraic[75] =  exp( constants[45]*states[0]*constants[95])*pow(states[4], 3.00000)*constants[35];
		algebraic[77] =  exp( (constants[45] - 1.00000)*states[0]*constants[95])*pow(constants[19], 3.00000)*states[12];
		algebraic[79] =  constants[40]*pow(constants[19], 3.00000)*(1.00000+pow(states[4]/constants[42], 3.00000))+ pow(constants[43], 3.00000)*states[12]*(1.00000+states[12]/constants[40])+ constants[41]*pow(states[4], 3.00000)+ pow(states[4], 3.00000)*constants[35]+ pow(constants[19], 3.00000)*states[12];
		algebraic[81] = ( constants[9]*constants[46]*algebraic[71]*(algebraic[75] - algebraic[77]))/( algebraic[79]*(1.00000+ constants[44]*exp( (constants[45] - 1.00000)*states[0]*constants[95])));
		algebraic[96] = algebraic[94]+algebraic[95]+ 3.00000*algebraic[81]+ 3.00000*algebraic[31]+algebraic[69];
		algebraic[97] =  (1.00000/constants[95])*log(constants[19]/states[5]);
		algebraic[98] =  constants[96]*constants[17]*pow(states[1], 3.00000)*states[2]*states[3]*(states[0] - algebraic[97]);
		algebraic[100] =  constants[96]*constants[18]*(states[0] - algebraic[97]);
		algebraic[38] = ( constants[96]*constants[20]*algebraic[24]*constants[21])/( (1.00000+pow(constants[23]/states[5], 4.00000))*(constants[21]+constants[22]));
		algebraic[64] = ( constants[37]*states[0]*constants[2]*constants[95]*( states[5]*exp( states[0]*constants[95]) - constants[19]))/(exp( states[0]*constants[95]) - 1.00000);
		algebraic[70] =  constants[97]*algebraic[64]*states[14]*states[15]*states[16]*(1.00000 - states[18]);
		algebraic[73] = 1.00000/(1.00000+pow(constants[39]/states[13], 2.00000));
		algebraic[76] =  exp( constants[45]*states[0]*constants[95])*pow(states[5], 3.00000)*constants[35];
		algebraic[78] =  exp( (constants[45] - 1.00000)*states[0]*constants[95])*pow(constants[19], 3.00000)*states[13];
		algebraic[80] =  constants[40]*pow(constants[19], 3.00000)*(1.00000+pow(states[5]/constants[42], 3.00000))+ pow(constants[43], 3.00000)*states[13]*(1.00000+states[13]/constants[40])+ constants[41]*pow(states[5], 3.00000)+ pow(states[5], 3.00000)*constants[35]+ pow(constants[19], 3.00000)*states[13];
		algebraic[82] = ( constants[96]*constants[46]*algebraic[73]*(algebraic[76] - algebraic[78]))/( algebraic[80]*(1.00000+ constants[44]*exp( (constants[45] - 1.00000)*states[0]*constants[95])));
		algebraic[102] = algebraic[98]+algebraic[100]+ 3.00000*algebraic[82]+ 3.00000*algebraic[38]+algebraic[70];
		algebraic[60] = ( constants[36]*states[0]*constants[2]*constants[95]*( states[12]*exp( 2.00000*states[0]*constants[95]) - constants[35]))/(exp( 2.00000*states[0]*constants[95]) - 1.00000);
		algebraic[65] =  constants[10]*algebraic[60]*states[14]*states[15]*states[16]*(1.00000 - states[17]);
		algebraic[83] = ( constants[9]*constants[48]*pow(states[12], 1.60000))/(pow(constants[47], 1.60000)+pow(states[12], 1.60000));
		algebraic[109] =  (1.00000/( 2.00000*constants[95]))*log(constants[35]/states[12]);
		algebraic[110] =  constants[9]*constants[49]*(states[0] - algebraic[109]);
		algebraic[111] = (algebraic[65]+algebraic[110]+algebraic[83]) -  2.00000*algebraic[81];
		algebraic[90] = rates[31]+rates[33];
		algebraic[61] = ( constants[36]*states[0]*constants[2]*constants[95]*( states[13]*exp( 2.00000*states[0]*constants[95]) - constants[35]))/(exp( 2.00000*states[0]*constants[95]) - 1.00000);
		algebraic[66] =  constants[97]*algebraic[61]*states[14]*states[15]*states[16]*(1.00000 - states[18]);
		algebraic[85] = ( constants[96]*constants[48]*pow(states[13], 1.60000))/(pow(constants[47], 1.60000)+pow(states[13], 1.60000));
		algebraic[112] =  (1.00000/( 2.00000*constants[95]))*log(constants[35]/states[13]);
		algebraic[113] =  constants[96]*constants[49]*(states[0] - algebraic[112]);
		algebraic[114] = (algebraic[66]+algebraic[113]+algebraic[85]) -  2.00000*algebraic[82];
		algebraic[91] = rates[32]+rates[34];
		algebraic[43] = algebraic[31]+algebraic[38];
		algebraic[44] = 1.00000/(1.00000+exp((states[0]+74.0000)/24.0000));
		algebraic[45] =  constants[24]* pow((constants[21]/5.40000), 1.0 / 2)*states[6]*algebraic[44]*(states[0] - constants[101]);
		algebraic[104] =  (1.00000/constants[95])*log((constants[21]+ constants[94]*constants[19])/(constants[34]+ constants[94]*states[35]));
		algebraic[105] =  constants[9]*constants[25]*pow(states[7], 2.00000)*(states[0] - algebraic[104]);
		algebraic[106] =  constants[96]*constants[26]*pow(states[7], 2.00000)*(states[0] - algebraic[104]);
		algebraic[107] = algebraic[105]+algebraic[106];
		algebraic[46] = 1.00000/(1.00000+exp(7.48800 - states[0]/5.98000));
		algebraic[47] =  constants[27]*algebraic[46]*(states[0] - constants[101]);
		algebraic[48] =  constants[28]*states[8]*states[9]*(states[0] - constants[101]);
		algebraic[49] =  constants[29]*states[10]*states[11]*(states[0] - constants[101]);
		algebraic[50] = algebraic[48]+algebraic[49];
		algebraic[51] = 4.09380/(1.00000+exp( 0.121650*((states[0] - constants[101]) - 49.9344)));
		algebraic[52] = ( 15.7197*exp( 0.0673900*((states[0] - constants[101]) - 3.25710))+exp( 0.0617500*((states[0] - constants[101]) - 594.310)))/(1.00000+exp( - 0.162850*((states[0] - constants[101])+14.2067)));
		algebraic[53] = algebraic[51]/(algebraic[51]+algebraic[52]);
		algebraic[54] =  constants[30]* pow((constants[21]/5.40000), 1.0 / 2)*algebraic[53]*(states[0] - constants[101]);
		algebraic[62] = ( constants[38]*states[0]*constants[2]*constants[95]*( constants[34]*exp( states[0]*constants[95]) - constants[21]))/(exp( states[0]*constants[95]) - 1.00000);
		algebraic[68] =  algebraic[62]*states[14]*states[15]*states[16]*( constants[10]*(1.00000 - states[17])+ constants[97]*(1.00000 - states[18]));
		algebraic[108] = ((algebraic[50]+algebraic[45]+algebraic[107]+algebraic[54]) -  2.00000*algebraic[43])+algebraic[68]+algebraic[47];
		algebraic[103] = algebraic[96]+algebraic[102];
		algebraic[55] =  (( constants[9]*constants[31])/(1.00000+constants[32]/states[12]))*(states[0] - constants[102]);
		algebraic[56] =  (( constants[96]*constants[31])/(1.00000+constants[32]/states[13]))*(states[0] - constants[102]);
		algebraic[57] = algebraic[55]+algebraic[56];
		algebraic[58] =  constants[33]*(states[0] - constants[102]);
		algebraic[59] = algebraic[57]+algebraic[58];
		algebraic[116] = algebraic[111]+algebraic[114];
		algebraic[117] = algebraic[103]+algebraic[59]+algebraic[116]+algebraic[108];
		algebraic[10] = (VoI>=constants[4]&&VoI<=constants[5]&&(VoI - constants[4]) -  floor((VoI - constants[4])/constants[7])*constants[7]<=constants[8] ? constants[6] : 0.00000);
		algebraic[67] = algebraic[65]+algebraic[66];
		algebraic[72] = algebraic[69]+algebraic[70];
		algebraic[74] = algebraic[67]+algebraic[68]+algebraic[72];
		algebraic[84] = algebraic[81]+algebraic[82];
		algebraic[87] = algebraic[83]+algebraic[85];
		algebraic[99] = algebraic[94]+algebraic[98];
		algebraic[101] = algebraic[95]+algebraic[100];
		algebraic[115] = algebraic[110]+algebraic[113];
	}

};
