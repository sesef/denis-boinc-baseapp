/*======================================================================
                                                                        
                      --- DENIS Project ---                             
                        -----------------                               
                                                                        
      Distributed computing                                             
      Electrophysiologycal Models                                       
      Networking colaboration                                           
      In Silico research                                                
      Sharing Knowledge                                                 
                                                                        
------------------------------------------------------------------------
                                                                        
 -- C File of the tentusscher_noble_noble_panfilov_2004_a model created for the DENIS Project -- 
                                                                        
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

namespace tentusscher_noble_noble_panfilov_2004_a{

	#define ALGEBRAIC_LENGTH 67
	#define STATE_LENGTH 17
	#define CONSTANT_LENGTH 46 

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
		VoI  = "time in component environment (millisecond)";
		states[0]  = "V in component membrane (millivolt)";
		constants[0]  = "R in component membrane (joule_per_mole_kelvin)";
		constants[1]  = "T in component membrane (kelvin)";
		constants[2]  = "F in component membrane (coulomb_per_millimole)";
		constants[3]  = "Cm in component membrane (microF)";
		constants[4]  = "V_c in component membrane (micrometre3)";
		algebraic[50]  = "i_K1 in component inward_rectifier_potassium_current (picoA_per_picoF)";
		algebraic[57]  = "i_to in component transient_outward_current (picoA_per_picoF)";
		algebraic[51]  = "i_Kr in component rapid_time_dependent_potassium_current (picoA_per_picoF)";
		algebraic[52]  = "i_Ks in component slow_time_dependent_potassium_current (picoA_per_picoF)";
		algebraic[55]  = "i_CaL in component L_type_Ca_current (picoA_per_picoF)";
		algebraic[58]  = "i_NaK in component sodium_potassium_pump_current (picoA_per_picoF)";
		algebraic[53]  = "i_Na in component fast_sodium_current (picoA_per_picoF)";
		algebraic[54]  = "i_b_Na in component sodium_background_current (picoA_per_picoF)";
		algebraic[59]  = "i_NaCa in component sodium_calcium_exchanger_current (picoA_per_picoF)";
		algebraic[56]  = "i_b_Ca in component calcium_background_current (picoA_per_picoF)";
		algebraic[61]  = "i_p_K in component potassium_pump_current (picoA_per_picoF)";
		algebraic[60]  = "i_p_Ca in component calcium_pump_current (picoA_per_picoF)";
		algebraic[0]  = "i_Stim in component membrane (picoA_per_picoF)";
		constants[5]  = "stim_start in component membrane (millisecond)";
		constants[6]  = "stim_period in component membrane (millisecond)";
		constants[7]  = "stim_duration in component membrane (millisecond)";
		constants[8]  = "stim_amplitude in component membrane (picoA_per_picoF)";
		algebraic[13]  = "E_Na in component reversal_potentials (millivolt)";
		algebraic[26]  = "E_K in component reversal_potentials (millivolt)";
		algebraic[35]  = "E_Ks in component reversal_potentials (millivolt)";
		algebraic[44]  = "E_Ca in component reversal_potentials (millivolt)";
		constants[9]  = "P_kna in component reversal_potentials (dimensionless)";
		constants[10]  = "K_o in component potassium_dynamics (millimolar)";
		constants[11]  = "Na_o in component sodium_dynamics (millimolar)";
		states[1]  = "K_i in component potassium_dynamics (millimolar)";
		states[2]  = "Na_i in component sodium_dynamics (millimolar)";
		constants[12]  = "Ca_o in component calcium_dynamics (millimolar)";
		states[3]  = "Ca_i in component calcium_dynamics (millimolar)";
		constants[13]  = "g_K1 in component inward_rectifier_potassium_current (nanoS_per_picoF)";
		algebraic[49]  = "xK1_inf in component inward_rectifier_potassium_current (dimensionless)";
		algebraic[47]  = "alpha_K1 in component inward_rectifier_potassium_current (dimensionless)";
		algebraic[48]  = "beta_K1 in component inward_rectifier_potassium_current (dimensionless)";
		constants[14]  = "g_Kr in component rapid_time_dependent_potassium_current (nanoS_per_picoF)";
		states[4]  = "Xr1 in component rapid_time_dependent_potassium_current_Xr1_gate (dimensionless)";
		states[5]  = "Xr2 in component rapid_time_dependent_potassium_current_Xr2_gate (dimensionless)";
		algebraic[1]  = "xr1_inf in component rapid_time_dependent_potassium_current_Xr1_gate (dimensionless)";
		algebraic[14]  = "alpha_xr1 in component rapid_time_dependent_potassium_current_Xr1_gate (dimensionless)";
		algebraic[27]  = "beta_xr1 in component rapid_time_dependent_potassium_current_Xr1_gate (dimensionless)";
		algebraic[36]  = "tau_xr1 in component rapid_time_dependent_potassium_current_Xr1_gate (millisecond)";
		algebraic[2]  = "xr2_inf in component rapid_time_dependent_potassium_current_Xr2_gate (dimensionless)";
		algebraic[15]  = "alpha_xr2 in component rapid_time_dependent_potassium_current_Xr2_gate (dimensionless)";
		algebraic[28]  = "beta_xr2 in component rapid_time_dependent_potassium_current_Xr2_gate (dimensionless)";
		algebraic[37]  = "tau_xr2 in component rapid_time_dependent_potassium_current_Xr2_gate (millisecond)";
		constants[15]  = "g_Ks in component slow_time_dependent_potassium_current (nanoS_per_picoF)";
		states[6]  = "Xs in component slow_time_dependent_potassium_current_Xs_gate (dimensionless)";
		algebraic[3]  = "xs_inf in component slow_time_dependent_potassium_current_Xs_gate (dimensionless)";
		algebraic[16]  = "alpha_xs in component slow_time_dependent_potassium_current_Xs_gate (dimensionless)";
		algebraic[29]  = "beta_xs in component slow_time_dependent_potassium_current_Xs_gate (dimensionless)";
		algebraic[38]  = "tau_xs in component slow_time_dependent_potassium_current_Xs_gate (millisecond)";
		constants[16]  = "g_Na in component fast_sodium_current (nanoS_per_picoF)";
		states[7]  = "m in component fast_sodium_current_m_gate (dimensionless)";
		states[8]  = "h in component fast_sodium_current_h_gate (dimensionless)";
		states[9]  = "j in component fast_sodium_current_j_gate (dimensionless)";
		algebraic[4]  = "m_inf in component fast_sodium_current_m_gate (dimensionless)";
		algebraic[17]  = "alpha_m in component fast_sodium_current_m_gate (dimensionless)";
		algebraic[30]  = "beta_m in component fast_sodium_current_m_gate (dimensionless)";
		algebraic[39]  = "tau_m in component fast_sodium_current_m_gate (millisecond)";
		algebraic[5]  = "h_inf in component fast_sodium_current_h_gate (dimensionless)";
		algebraic[18]  = "alpha_h in component fast_sodium_current_h_gate (per_millisecond)";
		algebraic[31]  = "beta_h in component fast_sodium_current_h_gate (per_millisecond)";
		algebraic[40]  = "tau_h in component fast_sodium_current_h_gate (millisecond)";
		algebraic[6]  = "j_inf in component fast_sodium_current_j_gate (dimensionless)";
		algebraic[19]  = "alpha_j in component fast_sodium_current_j_gate (per_millisecond)";
		algebraic[32]  = "beta_j in component fast_sodium_current_j_gate (per_millisecond)";
		algebraic[41]  = "tau_j in component fast_sodium_current_j_gate (millisecond)";
		constants[17]  = "g_bna in component sodium_background_current (nanoS_per_picoF)";
		constants[18]  = "g_CaL in component L_type_Ca_current (litre_per_farad_second)";
		states[10]  = "d in component L_type_Ca_current_d_gate (dimensionless)";
		states[11]  = "f in component L_type_Ca_current_f_gate (dimensionless)";
		states[12]  = "fCa in component L_type_Ca_current_fCa_gate (dimensionless)";
		algebraic[7]  = "d_inf in component L_type_Ca_current_d_gate (dimensionless)";
		algebraic[20]  = "alpha_d in component L_type_Ca_current_d_gate (dimensionless)";
		algebraic[33]  = "beta_d in component L_type_Ca_current_d_gate (dimensionless)";
		algebraic[42]  = "gamma_d in component L_type_Ca_current_d_gate (millisecond)";
		algebraic[45]  = "tau_d in component L_type_Ca_current_d_gate (millisecond)";
		algebraic[8]  = "f_inf in component L_type_Ca_current_f_gate (dimensionless)";
		algebraic[21]  = "tau_f in component L_type_Ca_current_f_gate (millisecond)";
		algebraic[9]  = "alpha_fCa in component L_type_Ca_current_fCa_gate (dimensionless)";
		algebraic[22]  = "beta_fCa in component L_type_Ca_current_fCa_gate (dimensionless)";
		algebraic[34]  = "gama_fCa in component L_type_Ca_current_fCa_gate (dimensionless)";
		algebraic[43]  = "fCa_inf in component L_type_Ca_current_fCa_gate (dimensionless)";
		constants[45]  = "tau_fCa in component L_type_Ca_current_fCa_gate (millisecond)";
		algebraic[46]  = "d_fCa in component L_type_Ca_current_fCa_gate (per_millisecond)";
		constants[19]  = "g_bca in component calcium_background_current (nanoS_per_picoF)";
		constants[20]  = "g_to in component transient_outward_current (nanoS_per_picoF)";
		states[13]  = "s in component transient_outward_current_s_gate (dimensionless)";
		states[14]  = "r in component transient_outward_current_r_gate (dimensionless)";
		algebraic[10]  = "s_inf in component transient_outward_current_s_gate (dimensionless)";
		algebraic[23]  = "tau_s in component transient_outward_current_s_gate (millisecond)";
		algebraic[11]  = "r_inf in component transient_outward_current_r_gate (dimensionless)";
		algebraic[24]  = "tau_r in component transient_outward_current_r_gate (millisecond)";
		constants[21]  = "P_NaK in component sodium_potassium_pump_current (picoA_per_picoF)";
		constants[22]  = "K_mk in component sodium_potassium_pump_current (millimolar)";
		constants[23]  = "K_mNa in component sodium_potassium_pump_current (millimolar)";
		constants[24]  = "K_NaCa in component sodium_calcium_exchanger_current (picoA_per_picoF)";
		constants[25]  = "K_sat in component sodium_calcium_exchanger_current (dimensionless)";
		constants[26]  = "alpha in component sodium_calcium_exchanger_current (dimensionless)";
		constants[27]  = "gamma in component sodium_calcium_exchanger_current (dimensionless)";
		constants[28]  = "Km_Ca in component sodium_calcium_exchanger_current (millimolar)";
		constants[29]  = "Km_Nai in component sodium_calcium_exchanger_current (millimolar)";
		constants[30]  = "g_pCa in component calcium_pump_current (picoA_per_picoF)";
		constants[31]  = "K_pCa in component calcium_pump_current (millimolar)";
		constants[32]  = "g_pK in component potassium_pump_current (nanoS_per_picoF)";
		states[15]  = "Ca_SR in component calcium_dynamics (millimolar)";
		algebraic[62]  = "i_rel in component calcium_dynamics (millimolar_per_millisecond)";
		algebraic[63]  = "i_up in component calcium_dynamics (millimolar_per_millisecond)";
		algebraic[64]  = "i_leak in component calcium_dynamics (millimolar_per_millisecond)";
		states[16]  = "g in component calcium_dynamics (dimensionless)";
		constants[33]  = "tau_g in component calcium_dynamics (millisecond)";
		algebraic[12]  = "g_inf in component calcium_dynamics (dimensionless)";
		constants[34]  = "a_rel in component calcium_dynamics (millimolar_per_millisecond)";
		constants[35]  = "b_rel in component calcium_dynamics (millimolar)";
		constants[36]  = "c_rel in component calcium_dynamics (millimolar_per_millisecond)";
		constants[37]  = "K_up in component calcium_dynamics (millimolar)";
		constants[38]  = "V_leak in component calcium_dynamics (per_millisecond)";
		constants[39]  = "Vmax_up in component calcium_dynamics (millimolar_per_millisecond)";
		algebraic[65]  = "Ca_i_bufc in component calcium_dynamics (dimensionless)";
		algebraic[66]  = "Ca_sr_bufsr in component calcium_dynamics (dimensionless)";
		constants[40]  = "Buf_c in component calcium_dynamics (millimolar)";
		constants[41]  = "K_buf_c in component calcium_dynamics (millimolar)";
		constants[42]  = "Buf_sr in component calcium_dynamics (millimolar)";
		constants[43]  = "K_buf_sr in component calcium_dynamics (millimolar)";
		constants[44]  = "V_sr in component calcium_dynamics (micrometre3)";
		algebraic[25]  = "d_g in component calcium_dynamics (per_millisecond)";
		rates[0]  = "d/dt V in component membrane (millivolt)";
		rates[4]  = "d/dt Xr1 in component rapid_time_dependent_potassium_current_Xr1_gate (dimensionless)";
		rates[5]  = "d/dt Xr2 in component rapid_time_dependent_potassium_current_Xr2_gate (dimensionless)";
		rates[6]  = "d/dt Xs in component slow_time_dependent_potassium_current_Xs_gate (dimensionless)";
		rates[7]  = "d/dt m in component fast_sodium_current_m_gate (dimensionless)";
		rates[8]  = "d/dt h in component fast_sodium_current_h_gate (dimensionless)";
		rates[9]  = "d/dt j in component fast_sodium_current_j_gate (dimensionless)";
		rates[10]  = "d/dt d in component L_type_Ca_current_d_gate (dimensionless)";
		rates[11]  = "d/dt f in component L_type_Ca_current_f_gate (dimensionless)";
		rates[12]  = "d/dt fCa in component L_type_Ca_current_fCa_gate (dimensionless)";
		rates[13]  = "d/dt s in component transient_outward_current_s_gate (dimensionless)";
		rates[14]  = "d/dt r in component transient_outward_current_r_gate (dimensionless)";
		rates[16]  = "d/dt g in component calcium_dynamics (dimensionless)";
		rates[3]  = "d/dt Ca_i in component calcium_dynamics (millimolar)";
		rates[15]  = "d/dt Ca_SR in component calcium_dynamics (millimolar)";
		rates[2]  = "d/dt Na_i in component sodium_dynamics (millimolar)";
		rates[1]  = "d/dt K_i in component potassium_dynamics (millimolar)";
	}

	void initConsts(double* constants, double* states){
		states[0] = -86.2;
		constants[0] = 8314.472;
		constants[1] = 310;
		constants[2] = 96485.3415;
		constants[3] = 0.185;
		constants[4] = 0.016404;
		constants[5] = 10;
		constants[6] = 1000;
		constants[7] = 1;
		constants[8] = 52;
		constants[9] = 0.03;
		constants[10] = 5.4;
		constants[11] = 140;
		states[1] = 138.3;
		states[2] = 11.6;
		constants[12] = 2;
		states[3] = 0.0002;
		constants[13] = 5.405;
		constants[14] = 0.096;
		states[4] = 0;
		states[5] = 1;
		constants[15] = 0.062;
		states[6] = 0;
		constants[16] = 14.838;
		states[7] = 0;
		states[8] = 0.75;
		states[9] = 0.75;
		constants[17] = 0.00029;
		constants[18] = 0.000175;
		states[10] = 0;
		states[11] = 1;
		states[12] = 1;
		constants[19] = 0.000592;
		constants[20] = 0.294;
		states[13] = 1;
		states[14] = 0;
		constants[21] = 1.362;
		constants[22] = 1;
		constants[23] = 40;
		constants[24] = 1000;
		constants[25] = 0.1;
		constants[26] = 2.5;
		constants[27] = 0.35;
		constants[28] = 1.38;
		constants[29] = 87.5;
		constants[30] = 0.825;
		constants[31] = 0.0005;
		constants[32] = 0.0146;
		states[15] = 0.2;
		states[16] = 1;
		constants[33] = 2;
		constants[34] = 0.016464;
		constants[35] = 0.25;
		constants[36] = 0.008232;
		constants[37] = 0.00025;
		constants[38] = 8e-5;
		constants[39] = 0.000425;
		constants[40] = 0.15;
		constants[41] = 0.001;
		constants[42] = 10;
		constants[43] = 0.3;
		constants[44] = 0.001094;
		constants[45] = 2.00000;
	}

	void computeRates(double VoI, double* constants, double* rates, double* states, double* algebraic){
		algebraic[8] = 1.00000/(1.00000+exp((states[0]+20.0000)/7.00000));
		algebraic[21] =  1125.00*exp(- pow(states[0]+27.0000, 2.00000)/240.000)+80.0000+165.000/(1.00000+exp((25.0000 - states[0])/10.0000));
		rates[11] = (algebraic[8] - states[11])/algebraic[21];
		algebraic[10] = 1.00000/(1.00000+exp((states[0]+20.0000)/5.00000));
		algebraic[23] =  85.0000*exp(- pow(states[0]+45.0000, 2.00000)/320.000)+5.00000/(1.00000+exp((states[0] - 20.0000)/5.00000))+3.00000;
		rates[13] = (algebraic[10] - states[13])/algebraic[23];
		algebraic[11] = 1.00000/(1.00000+exp((20.0000 - states[0])/6.00000));
		algebraic[24] =  9.50000*exp(- pow(states[0]+40.0000, 2.00000)/1800.00)+0.800000;
		rates[14] = (algebraic[11] - states[14])/algebraic[24];
		algebraic[12] = (states[3]<0.000350000 ? 1.00000/(1.00000+pow(states[3]/0.000350000, 6.00000)) : 1.00000/(1.00000+pow(states[3]/0.000350000, 16.0000)));
		algebraic[25] = (algebraic[12] - states[16])/constants[33];
		rates[16] = (algebraic[12]>states[16]&&states[0]>- 60.0000 ? 0.00000 : algebraic[25]);
		algebraic[1] = 1.00000/(1.00000+exp((- 26.0000 - states[0])/7.00000));
		algebraic[14] = 450.000/(1.00000+exp((- 45.0000 - states[0])/10.0000));
		algebraic[27] = 6.00000/(1.00000+exp((states[0]+30.0000)/11.5000));
		algebraic[36] =  1.00000*algebraic[14]*algebraic[27];
		rates[4] = (algebraic[1] - states[4])/algebraic[36];
		algebraic[2] = 1.00000/(1.00000+exp((states[0]+88.0000)/24.0000));
		algebraic[15] = 3.00000/(1.00000+exp((- 60.0000 - states[0])/20.0000));
		algebraic[28] = 1.12000/(1.00000+exp((states[0] - 60.0000)/20.0000));
		algebraic[37] =  1.00000*algebraic[15]*algebraic[28];
		rates[5] = (algebraic[2] - states[5])/algebraic[37];
		algebraic[3] = 1.00000/(1.00000+exp((- 5.00000 - states[0])/14.0000));
		algebraic[16] = 1100.00/ pow((1.00000+exp((- 10.0000 - states[0])/6.00000)), 1.0 / 2);
		algebraic[29] = 1.00000/(1.00000+exp((states[0] - 60.0000)/20.0000));
		algebraic[38] =  1.00000*algebraic[16]*algebraic[29];
		rates[6] = (algebraic[3] - states[6])/algebraic[38];
		algebraic[4] = 1.00000/pow(1.00000+exp((- 56.8600 - states[0])/9.03000), 2.00000);
		algebraic[17] = 1.00000/(1.00000+exp((- 60.0000 - states[0])/5.00000));
		algebraic[30] = 0.100000/(1.00000+exp((states[0]+35.0000)/5.00000))+0.100000/(1.00000+exp((states[0] - 50.0000)/200.000));
		algebraic[39] =  1.00000*algebraic[17]*algebraic[30];
		rates[7] = (algebraic[4] - states[7])/algebraic[39];
		algebraic[5] = 1.00000/pow(1.00000+exp((states[0]+71.5500)/7.43000), 2.00000);
		algebraic[18] = (states[0]<- 40.0000 ?  0.0570000*exp(- (states[0]+80.0000)/6.80000) : 0.00000);
		algebraic[31] = (states[0]<- 40.0000 ?  2.70000*exp( 0.0790000*states[0])+ 310000.*exp( 0.348500*states[0]) : 0.770000/( 0.130000*(1.00000+exp((states[0]+10.6600)/- 11.1000))));
		algebraic[40] = 1.00000/(algebraic[18]+algebraic[31]);
		rates[8] = (algebraic[5] - states[8])/algebraic[40];
		algebraic[6] = 1.00000/pow(1.00000+exp((states[0]+71.5500)/7.43000), 2.00000);
		algebraic[19] = (states[0]<- 40.0000 ? (( ( - 25428.0*exp( 0.244400*states[0]) -  6.94800e-06*exp( - 0.0439100*states[0]))*(states[0]+37.7800))/1.00000)/(1.00000+exp( 0.311000*(states[0]+79.2300))) : 0.00000);
		algebraic[32] = (states[0]<- 40.0000 ? ( 0.0242400*exp( - 0.0105200*states[0]))/(1.00000+exp( - 0.137800*(states[0]+40.1400))) : ( 0.600000*exp( 0.0570000*states[0]))/(1.00000+exp( - 0.100000*(states[0]+32.0000))));
		algebraic[41] = 1.00000/(algebraic[19]+algebraic[32]);
		rates[9] = (algebraic[6] - states[9])/algebraic[41];
		algebraic[7] = 1.00000/(1.00000+exp((- 5.00000 - states[0])/7.50000));
		algebraic[20] = 1.40000/(1.00000+exp((- 35.0000 - states[0])/13.0000))+0.250000;
		algebraic[33] = 1.40000/(1.00000+exp((states[0]+5.00000)/5.00000));
		algebraic[42] = 1.00000/(1.00000+exp((50.0000 - states[0])/20.0000));
		algebraic[45] =  1.00000*algebraic[20]*algebraic[33]+algebraic[42];
		rates[10] = (algebraic[7] - states[10])/algebraic[45];
		algebraic[9] = 1.00000/(1.00000+pow(states[3]/0.000325000, 8.00000));
		algebraic[22] = 0.100000/(1.00000+exp((states[3] - 0.000500000)/0.000100000));
		algebraic[34] = 0.200000/(1.00000+exp((states[3] - 0.000750000)/0.000800000));
		algebraic[43] = (algebraic[9]+algebraic[22]+algebraic[34]+0.230000)/1.46000;
		algebraic[46] = (algebraic[43] - states[12])/constants[45];
		rates[12] = (algebraic[43]>states[12]&&states[0]>- 60.0000 ? 0.00000 : algebraic[46]);
		algebraic[58] = (( (( constants[21]*constants[10])/(constants[10]+constants[22]))*states[2])/(states[2]+constants[23]))/(1.00000+ 0.124500*exp(( - 0.100000*states[0]*constants[2])/( constants[0]*constants[1]))+ 0.0353000*exp(( - states[0]*constants[2])/( constants[0]*constants[1])));
		algebraic[13] =  (( constants[0]*constants[1])/constants[2])*log(constants[11]/states[2]);
		algebraic[53] =  constants[16]*pow(states[7], 3.00000)*states[8]*states[9]*(states[0] - algebraic[13]);
		algebraic[54] =  constants[17]*(states[0] - algebraic[13]);
		algebraic[59] = ( constants[24]*( exp(( constants[27]*states[0]*constants[2])/( constants[0]*constants[1]))*pow(states[2], 3.00000)*constants[12] -  exp(( (constants[27] - 1.00000)*states[0]*constants[2])/( constants[0]*constants[1]))*pow(constants[11], 3.00000)*states[3]*constants[26]))/( (pow(constants[29], 3.00000)+pow(constants[11], 3.00000))*(constants[28]+constants[12])*(1.00000+ constants[25]*exp(( (constants[27] - 1.00000)*states[0]*constants[2])/( constants[0]*constants[1]))));
		rates[2] = ( - 1.00000*(algebraic[53]+algebraic[54]+ 3.00000*algebraic[58]+ 3.00000*algebraic[59])*constants[3])/( 1.00000*constants[4]*constants[2]);
		algebraic[26] =  (( constants[0]*constants[1])/constants[2])*log(constants[10]/states[1]);
		algebraic[47] = 0.100000/(1.00000+exp( 0.0600000*((states[0] - algebraic[26]) - 200.000)));
		algebraic[48] = ( 3.00000*exp( 0.000200000*((states[0] - algebraic[26])+100.000))+exp( 0.100000*((states[0] - algebraic[26]) - 10.0000)))/(1.00000+exp( - 0.500000*(states[0] - algebraic[26])));
		algebraic[49] = algebraic[47]/(algebraic[47]+algebraic[48]);
		algebraic[50] =  constants[13]*algebraic[49]* pow((constants[10]/5.40000), 1.0 / 2)*(states[0] - algebraic[26]);
		algebraic[57] =  constants[20]*states[14]*states[13]*(states[0] - algebraic[26]);
		algebraic[51] =  constants[14]* pow((constants[10]/5.40000), 1.0 / 2)*states[4]*states[5]*(states[0] - algebraic[26]);
		algebraic[35] =  (( constants[0]*constants[1])/constants[2])*log((constants[10]+ constants[9]*constants[11])/(states[1]+ constants[9]*states[2]));
		algebraic[52] =  constants[15]*pow(states[6], 2.00000)*(states[0] - algebraic[35]);
		algebraic[55] = ( (( constants[18]*states[10]*states[11]*states[12]*4.00000*states[0]*pow(constants[2], 2.00000))/( constants[0]*constants[1]))*( states[3]*exp(( 2.00000*states[0]*constants[2])/( constants[0]*constants[1])) -  0.341000*constants[12]))/(exp(( 2.00000*states[0]*constants[2])/( constants[0]*constants[1])) - 1.00000);
		algebraic[44] =  (( 0.500000*constants[0]*constants[1])/constants[2])*log(constants[12]/states[3]);
		algebraic[56] =  constants[19]*(states[0] - algebraic[44]);
		algebraic[61] = ( constants[32]*(states[0] - algebraic[26]))/(1.00000+exp((25.0000 - states[0])/5.98000));
		algebraic[60] = ( constants[30]*states[3])/(states[3]+constants[31]);
		algebraic[0] = (VoI -  floor(VoI/constants[6])*constants[6]>=constants[5]&&VoI -  floor(VoI/constants[6])*constants[6]<=constants[5]+constants[7] ? - constants[8] : 0.00000);
		rates[0] =  (- 1.00000/1.00000)*(algebraic[50]+algebraic[57]+algebraic[51]+algebraic[52]+algebraic[55]+algebraic[58]+algebraic[53]+algebraic[54]+algebraic[59]+algebraic[56]+algebraic[61]+algebraic[60]+algebraic[0]);
		rates[1] = ( - 1.00000*((algebraic[50]+algebraic[57]+algebraic[51]+algebraic[52]+algebraic[61]+algebraic[0]) -  2.00000*algebraic[58])*constants[3])/( 1.00000*constants[4]*constants[2]);
		algebraic[62] =  (( constants[34]*pow(states[15], 2.00000))/(pow(constants[35], 2.00000)+pow(states[15], 2.00000))+constants[36])*states[10]*states[16];
		algebraic[63] = constants[39]/(1.00000+pow(constants[37], 2.00000)/pow(states[3], 2.00000));
		algebraic[64] =  constants[38]*(states[15] - states[3]);
		algebraic[65] = 1.00000/(1.00000+( constants[40]*constants[41])/pow(states[3]+constants[41], 2.00000));
		rates[3] =  algebraic[65]*(((algebraic[64] - algebraic[63])+algebraic[62]) -  (( 1.00000*((algebraic[55]+algebraic[56]+algebraic[60]) -  2.00000*algebraic[59]))/( 2.00000*1.00000*constants[4]*constants[2]))*constants[3]);
		algebraic[66] = 1.00000/(1.00000+( constants[42]*constants[43])/pow(states[15]+constants[43], 2.00000));
		rates[15] =  (( algebraic[66]*constants[4])/constants[44])*(algebraic[63] - (algebraic[62]+algebraic[64]));
	}

	void computeVariables(double VoI, double* constants, double* rates, double* states, double* algebraic){
		algebraic[8] = 1.00000/(1.00000+exp((states[0]+20.0000)/7.00000));
		algebraic[21] =  1125.00*exp(- pow(states[0]+27.0000, 2.00000)/240.000)+80.0000+165.000/(1.00000+exp((25.0000 - states[0])/10.0000));
		algebraic[10] = 1.00000/(1.00000+exp((states[0]+20.0000)/5.00000));
		algebraic[23] =  85.0000*exp(- pow(states[0]+45.0000, 2.00000)/320.000)+5.00000/(1.00000+exp((states[0] - 20.0000)/5.00000))+3.00000;
		algebraic[11] = 1.00000/(1.00000+exp((20.0000 - states[0])/6.00000));
		algebraic[24] =  9.50000*exp(- pow(states[0]+40.0000, 2.00000)/1800.00)+0.800000;
		algebraic[12] = (states[3]<0.000350000 ? 1.00000/(1.00000+pow(states[3]/0.000350000, 6.00000)) : 1.00000/(1.00000+pow(states[3]/0.000350000, 16.0000)));
		algebraic[25] = (algebraic[12] - states[16])/constants[33];
		algebraic[1] = 1.00000/(1.00000+exp((- 26.0000 - states[0])/7.00000));
		algebraic[14] = 450.000/(1.00000+exp((- 45.0000 - states[0])/10.0000));
		algebraic[27] = 6.00000/(1.00000+exp((states[0]+30.0000)/11.5000));
		algebraic[36] =  1.00000*algebraic[14]*algebraic[27];
		algebraic[2] = 1.00000/(1.00000+exp((states[0]+88.0000)/24.0000));
		algebraic[15] = 3.00000/(1.00000+exp((- 60.0000 - states[0])/20.0000));
		algebraic[28] = 1.12000/(1.00000+exp((states[0] - 60.0000)/20.0000));
		algebraic[37] =  1.00000*algebraic[15]*algebraic[28];
		algebraic[3] = 1.00000/(1.00000+exp((- 5.00000 - states[0])/14.0000));
		algebraic[16] = 1100.00/ pow((1.00000+exp((- 10.0000 - states[0])/6.00000)), 1.0 / 2);
		algebraic[29] = 1.00000/(1.00000+exp((states[0] - 60.0000)/20.0000));
		algebraic[38] =  1.00000*algebraic[16]*algebraic[29];
		algebraic[4] = 1.00000/pow(1.00000+exp((- 56.8600 - states[0])/9.03000), 2.00000);
		algebraic[17] = 1.00000/(1.00000+exp((- 60.0000 - states[0])/5.00000));
		algebraic[30] = 0.100000/(1.00000+exp((states[0]+35.0000)/5.00000))+0.100000/(1.00000+exp((states[0] - 50.0000)/200.000));
		algebraic[39] =  1.00000*algebraic[17]*algebraic[30];
		algebraic[5] = 1.00000/pow(1.00000+exp((states[0]+71.5500)/7.43000), 2.00000);
		algebraic[18] = (states[0]<- 40.0000 ?  0.0570000*exp(- (states[0]+80.0000)/6.80000) : 0.00000);
		algebraic[31] = (states[0]<- 40.0000 ?  2.70000*exp( 0.0790000*states[0])+ 310000.*exp( 0.348500*states[0]) : 0.770000/( 0.130000*(1.00000+exp((states[0]+10.6600)/- 11.1000))));
		algebraic[40] = 1.00000/(algebraic[18]+algebraic[31]);
		algebraic[6] = 1.00000/pow(1.00000+exp((states[0]+71.5500)/7.43000), 2.00000);
		algebraic[19] = (states[0]<- 40.0000 ? (( ( - 25428.0*exp( 0.244400*states[0]) -  6.94800e-06*exp( - 0.0439100*states[0]))*(states[0]+37.7800))/1.00000)/(1.00000+exp( 0.311000*(states[0]+79.2300))) : 0.00000);
		algebraic[32] = (states[0]<- 40.0000 ? ( 0.0242400*exp( - 0.0105200*states[0]))/(1.00000+exp( - 0.137800*(states[0]+40.1400))) : ( 0.600000*exp( 0.0570000*states[0]))/(1.00000+exp( - 0.100000*(states[0]+32.0000))));
		algebraic[41] = 1.00000/(algebraic[19]+algebraic[32]);
		algebraic[7] = 1.00000/(1.00000+exp((- 5.00000 - states[0])/7.50000));
		algebraic[20] = 1.40000/(1.00000+exp((- 35.0000 - states[0])/13.0000))+0.250000;
		algebraic[33] = 1.40000/(1.00000+exp((states[0]+5.00000)/5.00000));
		algebraic[42] = 1.00000/(1.00000+exp((50.0000 - states[0])/20.0000));
		algebraic[45] =  1.00000*algebraic[20]*algebraic[33]+algebraic[42];
		algebraic[9] = 1.00000/(1.00000+pow(states[3]/0.000325000, 8.00000));
		algebraic[22] = 0.100000/(1.00000+exp((states[3] - 0.000500000)/0.000100000));
		algebraic[34] = 0.200000/(1.00000+exp((states[3] - 0.000750000)/0.000800000));
		algebraic[43] = (algebraic[9]+algebraic[22]+algebraic[34]+0.230000)/1.46000;
		algebraic[46] = (algebraic[43] - states[12])/constants[45];
		algebraic[58] = (( (( constants[21]*constants[10])/(constants[10]+constants[22]))*states[2])/(states[2]+constants[23]))/(1.00000+ 0.124500*exp(( - 0.100000*states[0]*constants[2])/( constants[0]*constants[1]))+ 0.0353000*exp(( - states[0]*constants[2])/( constants[0]*constants[1])));
		algebraic[13] =  (( constants[0]*constants[1])/constants[2])*log(constants[11]/states[2]);
		algebraic[53] =  constants[16]*pow(states[7], 3.00000)*states[8]*states[9]*(states[0] - algebraic[13]);
		algebraic[54] =  constants[17]*(states[0] - algebraic[13]);
		algebraic[59] = ( constants[24]*( exp(( constants[27]*states[0]*constants[2])/( constants[0]*constants[1]))*pow(states[2], 3.00000)*constants[12] -  exp(( (constants[27] - 1.00000)*states[0]*constants[2])/( constants[0]*constants[1]))*pow(constants[11], 3.00000)*states[3]*constants[26]))/( (pow(constants[29], 3.00000)+pow(constants[11], 3.00000))*(constants[28]+constants[12])*(1.00000+ constants[25]*exp(( (constants[27] - 1.00000)*states[0]*constants[2])/( constants[0]*constants[1]))));
		algebraic[26] =  (( constants[0]*constants[1])/constants[2])*log(constants[10]/states[1]);
		algebraic[47] = 0.100000/(1.00000+exp( 0.0600000*((states[0] - algebraic[26]) - 200.000)));
		algebraic[48] = ( 3.00000*exp( 0.000200000*((states[0] - algebraic[26])+100.000))+exp( 0.100000*((states[0] - algebraic[26]) - 10.0000)))/(1.00000+exp( - 0.500000*(states[0] - algebraic[26])));
		algebraic[49] = algebraic[47]/(algebraic[47]+algebraic[48]);
		algebraic[50] =  constants[13]*algebraic[49]* pow((constants[10]/5.40000), 1.0 / 2)*(states[0] - algebraic[26]);
		algebraic[57] =  constants[20]*states[14]*states[13]*(states[0] - algebraic[26]);
		algebraic[51] =  constants[14]* pow((constants[10]/5.40000), 1.0 / 2)*states[4]*states[5]*(states[0] - algebraic[26]);
		algebraic[35] =  (( constants[0]*constants[1])/constants[2])*log((constants[10]+ constants[9]*constants[11])/(states[1]+ constants[9]*states[2]));
		algebraic[52] =  constants[15]*pow(states[6], 2.00000)*(states[0] - algebraic[35]);
		algebraic[55] = ( (( constants[18]*states[10]*states[11]*states[12]*4.00000*states[0]*pow(constants[2], 2.00000))/( constants[0]*constants[1]))*( states[3]*exp(( 2.00000*states[0]*constants[2])/( constants[0]*constants[1])) -  0.341000*constants[12]))/(exp(( 2.00000*states[0]*constants[2])/( constants[0]*constants[1])) - 1.00000);
		algebraic[44] =  (( 0.500000*constants[0]*constants[1])/constants[2])*log(constants[12]/states[3]);
		algebraic[56] =  constants[19]*(states[0] - algebraic[44]);
		algebraic[61] = ( constants[32]*(states[0] - algebraic[26]))/(1.00000+exp((25.0000 - states[0])/5.98000));
		algebraic[60] = ( constants[30]*states[3])/(states[3]+constants[31]);
		algebraic[0] = (VoI -  floor(VoI/constants[6])*constants[6]>=constants[5]&&VoI -  floor(VoI/constants[6])*constants[6]<=constants[5]+constants[7] ? - constants[8] : 0.00000);
		algebraic[62] =  (( constants[34]*pow(states[15], 2.00000))/(pow(constants[35], 2.00000)+pow(states[15], 2.00000))+constants[36])*states[10]*states[16];
		algebraic[63] = constants[39]/(1.00000+pow(constants[37], 2.00000)/pow(states[3], 2.00000));
		algebraic[64] =  constants[38]*(states[15] - states[3]);
		algebraic[65] = 1.00000/(1.00000+( constants[40]*constants[41])/pow(states[3]+constants[41], 2.00000));
		algebraic[66] = 1.00000/(1.00000+( constants[42]*constants[43])/pow(states[15]+constants[43], 2.00000));
	}

};
