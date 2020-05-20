set moduleName randombytes
set isTopModule 0
set isTaskLevelControl 1
set isCombinational 0
set isDatapathOnly 0
set isFreeRunPipelineModule 0
set isPipelined 0
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set C_modelName {randombytes}
set C_modelType { void 0 }
set C_modelArgList {
	{ x int 8 regular {array 32 { 0 0 } 0 1 }  }
	{ DRBG_ctx_V int 8 regular {array 16 { 2 2 } 1 1 } {global 2}  }
	{ DRBG_ctx_Key int 8 regular {array 32 { 2 2 } 1 1 } {global 2}  }
	{ DRBG_ctx_reseed_counter int 32 regular {pointer 2} {global 2}  }
}
set C_modelArgMapList {[ 
	{ "Name" : "x", "interface" : "memory", "bitwidth" : 8, "direction" : "WRITEONLY"} , 
 	{ "Name" : "DRBG_ctx_V", "interface" : "memory", "bitwidth" : 8, "direction" : "READWRITE", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "DRBG_ctx.V","cData": "unsigned char","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 0,"up" : 15,"step" : 1}]}]}], "extern" : 0} , 
 	{ "Name" : "DRBG_ctx_Key", "interface" : "memory", "bitwidth" : 8, "direction" : "READWRITE", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "DRBG_ctx.Key","cData": "unsigned char","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 0,"up" : 31,"step" : 1}]}]}], "extern" : 0} , 
 	{ "Name" : "DRBG_ctx_reseed_counter", "interface" : "wire", "bitwidth" : 32, "direction" : "READWRITE", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "DRBG_ctx.reseed_counter","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}], "extern" : 0} ]}
# RTL Port declarations: 
set portNum 37
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ x_address0 sc_out sc_lv 5 signal 0 } 
	{ x_ce0 sc_out sc_logic 1 signal 0 } 
	{ x_we0 sc_out sc_logic 1 signal 0 } 
	{ x_d0 sc_out sc_lv 8 signal 0 } 
	{ x_address1 sc_out sc_lv 5 signal 0 } 
	{ x_ce1 sc_out sc_logic 1 signal 0 } 
	{ x_we1 sc_out sc_logic 1 signal 0 } 
	{ x_d1 sc_out sc_lv 8 signal 0 } 
	{ DRBG_ctx_V_address0 sc_out sc_lv 4 signal 1 } 
	{ DRBG_ctx_V_ce0 sc_out sc_logic 1 signal 1 } 
	{ DRBG_ctx_V_we0 sc_out sc_logic 1 signal 1 } 
	{ DRBG_ctx_V_d0 sc_out sc_lv 8 signal 1 } 
	{ DRBG_ctx_V_q0 sc_in sc_lv 8 signal 1 } 
	{ DRBG_ctx_V_address1 sc_out sc_lv 4 signal 1 } 
	{ DRBG_ctx_V_ce1 sc_out sc_logic 1 signal 1 } 
	{ DRBG_ctx_V_we1 sc_out sc_logic 1 signal 1 } 
	{ DRBG_ctx_V_d1 sc_out sc_lv 8 signal 1 } 
	{ DRBG_ctx_V_q1 sc_in sc_lv 8 signal 1 } 
	{ DRBG_ctx_Key_address0 sc_out sc_lv 5 signal 2 } 
	{ DRBG_ctx_Key_ce0 sc_out sc_logic 1 signal 2 } 
	{ DRBG_ctx_Key_we0 sc_out sc_logic 1 signal 2 } 
	{ DRBG_ctx_Key_d0 sc_out sc_lv 8 signal 2 } 
	{ DRBG_ctx_Key_q0 sc_in sc_lv 8 signal 2 } 
	{ DRBG_ctx_Key_address1 sc_out sc_lv 5 signal 2 } 
	{ DRBG_ctx_Key_ce1 sc_out sc_logic 1 signal 2 } 
	{ DRBG_ctx_Key_we1 sc_out sc_logic 1 signal 2 } 
	{ DRBG_ctx_Key_d1 sc_out sc_lv 8 signal 2 } 
	{ DRBG_ctx_Key_q1 sc_in sc_lv 8 signal 2 } 
	{ DRBG_ctx_reseed_counter_i sc_in sc_lv 32 signal 3 } 
	{ DRBG_ctx_reseed_counter_o sc_out sc_lv 32 signal 3 } 
	{ DRBG_ctx_reseed_counter_o_ap_vld sc_out sc_logic 1 outvld 3 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "x_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "x", "role": "address0" }} , 
 	{ "name": "x_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "x", "role": "ce0" }} , 
 	{ "name": "x_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "x", "role": "we0" }} , 
 	{ "name": "x_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "x", "role": "d0" }} , 
 	{ "name": "x_address1", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "x", "role": "address1" }} , 
 	{ "name": "x_ce1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "x", "role": "ce1" }} , 
 	{ "name": "x_we1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "x", "role": "we1" }} , 
 	{ "name": "x_d1", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "x", "role": "d1" }} , 
 	{ "name": "DRBG_ctx_V_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "DRBG_ctx_V", "role": "address0" }} , 
 	{ "name": "DRBG_ctx_V_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "DRBG_ctx_V", "role": "ce0" }} , 
 	{ "name": "DRBG_ctx_V_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "DRBG_ctx_V", "role": "we0" }} , 
 	{ "name": "DRBG_ctx_V_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "DRBG_ctx_V", "role": "d0" }} , 
 	{ "name": "DRBG_ctx_V_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "DRBG_ctx_V", "role": "q0" }} , 
 	{ "name": "DRBG_ctx_V_address1", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "DRBG_ctx_V", "role": "address1" }} , 
 	{ "name": "DRBG_ctx_V_ce1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "DRBG_ctx_V", "role": "ce1" }} , 
 	{ "name": "DRBG_ctx_V_we1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "DRBG_ctx_V", "role": "we1" }} , 
 	{ "name": "DRBG_ctx_V_d1", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "DRBG_ctx_V", "role": "d1" }} , 
 	{ "name": "DRBG_ctx_V_q1", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "DRBG_ctx_V", "role": "q1" }} , 
 	{ "name": "DRBG_ctx_Key_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "DRBG_ctx_Key", "role": "address0" }} , 
 	{ "name": "DRBG_ctx_Key_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "DRBG_ctx_Key", "role": "ce0" }} , 
 	{ "name": "DRBG_ctx_Key_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "DRBG_ctx_Key", "role": "we0" }} , 
 	{ "name": "DRBG_ctx_Key_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "DRBG_ctx_Key", "role": "d0" }} , 
 	{ "name": "DRBG_ctx_Key_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "DRBG_ctx_Key", "role": "q0" }} , 
 	{ "name": "DRBG_ctx_Key_address1", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "DRBG_ctx_Key", "role": "address1" }} , 
 	{ "name": "DRBG_ctx_Key_ce1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "DRBG_ctx_Key", "role": "ce1" }} , 
 	{ "name": "DRBG_ctx_Key_we1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "DRBG_ctx_Key", "role": "we1" }} , 
 	{ "name": "DRBG_ctx_Key_d1", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "DRBG_ctx_Key", "role": "d1" }} , 
 	{ "name": "DRBG_ctx_Key_q1", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "DRBG_ctx_Key", "role": "q1" }} , 
 	{ "name": "DRBG_ctx_reseed_counter_i", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "DRBG_ctx_reseed_counter", "role": "i" }} , 
 	{ "name": "DRBG_ctx_reseed_counter_o", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "DRBG_ctx_reseed_counter", "role": "o" }} , 
 	{ "name": "DRBG_ctx_reseed_counter_o_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "DRBG_ctx_reseed_counter", "role": "o_ap_vld" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "13"],
		"CDFG" : "randombytes",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "4359", "EstimateLatencyMax" : "4419",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"WaitState" : [
			{"State" : "ap_ST_fsm_state27", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_AES256_CTR_DRBG_Upda_fu_425"},
			{"State" : "ap_ST_fsm_state20", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_AES256_ECB_1_fu_435"}],
		"Port" : [
			{"Name" : "x", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "DRBG_ctx_V", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "13", "SubInstance" : "grp_AES256_ECB_1_fu_435", "Port" : "ctr"},
					{"ID" : "1", "SubInstance" : "grp_AES256_CTR_DRBG_Upda_fu_425", "Port" : "V"}]},
			{"Name" : "sbox", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "13", "SubInstance" : "grp_AES256_ECB_1_fu_435", "Port" : "sbox"},
					{"ID" : "1", "SubInstance" : "grp_AES256_CTR_DRBG_Upda_fu_425", "Port" : "sbox"}]},
			{"Name" : "DRBG_ctx_Key", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "13", "SubInstance" : "grp_AES256_ECB_1_fu_435", "Port" : "key"},
					{"ID" : "1", "SubInstance" : "grp_AES256_CTR_DRBG_Upda_fu_425", "Port" : "DRBG_ctx_Key"}]},
			{"Name" : "DRBG_ctx_reseed_counter", "Type" : "OVld", "Direction" : "IO"}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_AES256_CTR_DRBG_Upda_fu_425", "Parent" : "0", "Child" : ["2", "3"],
		"CDFG" : "AES256_CTR_DRBG_Upda",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "3271", "EstimateLatencyMax" : "3316",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"WaitState" : [
			{"State" : "ap_ST_fsm_state21", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_AES256_ECB_fu_923"}],
		"Port" : [
			{"Name" : "V", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "3", "SubInstance" : "grp_AES256_ECB_fu_923", "Port" : "ctr"}]},
			{"Name" : "sbox", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "3", "SubInstance" : "grp_AES256_ECB_fu_923", "Port" : "sbox"}]},
			{"Name" : "DRBG_ctx_Key", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "3", "SubInstance" : "grp_AES256_ECB_fu_923", "Port" : "key"}]}]},
	{"ID" : "2", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_AES256_CTR_DRBG_Upda_fu_425.temp_U", "Parent" : "1"},
	{"ID" : "3", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_AES256_CTR_DRBG_Upda_fu_425.grp_AES256_ECB_fu_923", "Parent" : "1", "Child" : ["4", "5", "6", "8", "9", "10", "11"],
		"CDFG" : "AES256_ECB",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "1077", "EstimateLatencyMax" : "1077",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"WaitState" : [
			{"State" : "ap_ST_fsm_state9", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_KeyExpansion_fu_559"},
			{"State" : "ap_ST_fsm_state17", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_MixColumns_fu_568"},
			{"State" : "ap_ST_fsm_state25", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_MixColumns_fu_568"},
			{"State" : "ap_ST_fsm_state33", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_MixColumns_fu_568"},
			{"State" : "ap_ST_fsm_state41", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_MixColumns_fu_568"},
			{"State" : "ap_ST_fsm_state49", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_MixColumns_fu_568"},
			{"State" : "ap_ST_fsm_state57", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_MixColumns_fu_568"},
			{"State" : "ap_ST_fsm_state65", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_MixColumns_fu_568"},
			{"State" : "ap_ST_fsm_state73", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_MixColumns_fu_568"},
			{"State" : "ap_ST_fsm_state81", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_MixColumns_fu_568"},
			{"State" : "ap_ST_fsm_state89", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_MixColumns_fu_568"},
			{"State" : "ap_ST_fsm_state97", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_MixColumns_fu_568"},
			{"State" : "ap_ST_fsm_state105", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_MixColumns_fu_568"},
			{"State" : "ap_ST_fsm_state113", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_MixColumns_fu_568"},
			{"State" : "ap_ST_fsm_state15", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_ShiftRows_fu_573"},
			{"State" : "ap_ST_fsm_state23", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_ShiftRows_fu_573"},
			{"State" : "ap_ST_fsm_state31", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_ShiftRows_fu_573"},
			{"State" : "ap_ST_fsm_state39", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_ShiftRows_fu_573"},
			{"State" : "ap_ST_fsm_state47", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_ShiftRows_fu_573"},
			{"State" : "ap_ST_fsm_state55", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_ShiftRows_fu_573"},
			{"State" : "ap_ST_fsm_state63", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_ShiftRows_fu_573"},
			{"State" : "ap_ST_fsm_state71", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_ShiftRows_fu_573"},
			{"State" : "ap_ST_fsm_state79", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_ShiftRows_fu_573"},
			{"State" : "ap_ST_fsm_state87", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_ShiftRows_fu_573"},
			{"State" : "ap_ST_fsm_state95", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_ShiftRows_fu_573"},
			{"State" : "ap_ST_fsm_state103", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_ShiftRows_fu_573"},
			{"State" : "ap_ST_fsm_state111", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_ShiftRows_fu_573"},
			{"State" : "ap_ST_fsm_state119", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_ShiftRows_fu_573"},
			{"State" : "ap_ST_fsm_state11", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_AddRoundKey_fu_578"},
			{"State" : "ap_ST_fsm_state19", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_AddRoundKey_fu_578"},
			{"State" : "ap_ST_fsm_state27", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_AddRoundKey_fu_578"},
			{"State" : "ap_ST_fsm_state35", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_AddRoundKey_fu_578"},
			{"State" : "ap_ST_fsm_state43", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_AddRoundKey_fu_578"},
			{"State" : "ap_ST_fsm_state51", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_AddRoundKey_fu_578"},
			{"State" : "ap_ST_fsm_state59", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_AddRoundKey_fu_578"},
			{"State" : "ap_ST_fsm_state67", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_AddRoundKey_fu_578"},
			{"State" : "ap_ST_fsm_state75", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_AddRoundKey_fu_578"},
			{"State" : "ap_ST_fsm_state83", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_AddRoundKey_fu_578"},
			{"State" : "ap_ST_fsm_state91", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_AddRoundKey_fu_578"},
			{"State" : "ap_ST_fsm_state99", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_AddRoundKey_fu_578"},
			{"State" : "ap_ST_fsm_state107", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_AddRoundKey_fu_578"},
			{"State" : "ap_ST_fsm_state115", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_AddRoundKey_fu_578"},
			{"State" : "ap_ST_fsm_state121", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_AddRoundKey_fu_578"},
			{"State" : "ap_ST_fsm_state13", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_SubBytes_fu_600"},
			{"State" : "ap_ST_fsm_state21", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_SubBytes_fu_600"},
			{"State" : "ap_ST_fsm_state29", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_SubBytes_fu_600"},
			{"State" : "ap_ST_fsm_state37", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_SubBytes_fu_600"},
			{"State" : "ap_ST_fsm_state45", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_SubBytes_fu_600"},
			{"State" : "ap_ST_fsm_state53", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_SubBytes_fu_600"},
			{"State" : "ap_ST_fsm_state61", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_SubBytes_fu_600"},
			{"State" : "ap_ST_fsm_state69", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_SubBytes_fu_600"},
			{"State" : "ap_ST_fsm_state77", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_SubBytes_fu_600"},
			{"State" : "ap_ST_fsm_state85", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_SubBytes_fu_600"},
			{"State" : "ap_ST_fsm_state93", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_SubBytes_fu_600"},
			{"State" : "ap_ST_fsm_state101", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_SubBytes_fu_600"},
			{"State" : "ap_ST_fsm_state109", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_SubBytes_fu_600"},
			{"State" : "ap_ST_fsm_state117", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_SubBytes_fu_600"}],
		"Port" : [
			{"Name" : "key", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "6", "SubInstance" : "grp_KeyExpansion_fu_559", "Port" : "Key"}]},
			{"Name" : "ctr", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "buffer_r", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "buffer_offset", "Type" : "None", "Direction" : "I"},
			{"Name" : "sbox", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "6", "SubInstance" : "grp_KeyExpansion_fu_559", "Port" : "sbox"},
					{"ID" : "11", "SubInstance" : "grp_SubBytes_fu_600", "Port" : "sbox"}]}]},
	{"ID" : "4", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_AES256_CTR_DRBG_Upda_fu_425.grp_AES256_ECB_fu_923.ctx_RoundKey_U", "Parent" : "3"},
	{"ID" : "5", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_AES256_CTR_DRBG_Upda_fu_425.grp_AES256_ECB_fu_923.test_U", "Parent" : "3"},
	{"ID" : "6", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_AES256_CTR_DRBG_Upda_fu_425.grp_AES256_ECB_fu_923.grp_KeyExpansion_fu_559", "Parent" : "3", "Child" : ["7"],
		"CDFG" : "KeyExpansion",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "120", "EstimateLatencyMax" : "120",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "RoundKey", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "Key", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "sbox", "Type" : "Memory", "Direction" : "I"}]},
	{"ID" : "7", "Level" : "4", "Path" : "`AUTOTB_DUT_INST.grp_AES256_CTR_DRBG_Upda_fu_425.grp_AES256_ECB_fu_923.grp_KeyExpansion_fu_559.sbox_U", "Parent" : "6"},
	{"ID" : "8", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_AES256_CTR_DRBG_Upda_fu_425.grp_AES256_ECB_fu_923.grp_MixColumns_fu_568", "Parent" : "3",
		"CDFG" : "MixColumns",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "15", "EstimateLatencyMax" : "15",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "state", "Type" : "Memory", "Direction" : "IO"}]},
	{"ID" : "9", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_AES256_CTR_DRBG_Upda_fu_425.grp_AES256_ECB_fu_923.grp_ShiftRows_fu_573", "Parent" : "3",
		"CDFG" : "ShiftRows",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "10", "EstimateLatencyMax" : "10",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "state", "Type" : "Memory", "Direction" : "IO"}]},
	{"ID" : "10", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_AES256_CTR_DRBG_Upda_fu_425.grp_AES256_ECB_fu_923.grp_AddRoundKey_fu_578", "Parent" : "3",
		"CDFG" : "AddRoundKey",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "17", "EstimateLatencyMax" : "17",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "round", "Type" : "None", "Direction" : "I"},
			{"Name" : "state", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "RoundKey", "Type" : "Memory", "Direction" : "I"}]},
	{"ID" : "11", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_AES256_CTR_DRBG_Upda_fu_425.grp_AES256_ECB_fu_923.grp_SubBytes_fu_600", "Parent" : "3", "Child" : ["12"],
		"CDFG" : "SubBytes",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "17", "EstimateLatencyMax" : "17",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "state", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "sbox", "Type" : "Memory", "Direction" : "I"}]},
	{"ID" : "12", "Level" : "4", "Path" : "`AUTOTB_DUT_INST.grp_AES256_CTR_DRBG_Upda_fu_425.grp_AES256_ECB_fu_923.grp_SubBytes_fu_600.sbox_U", "Parent" : "11"},
	{"ID" : "13", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_AES256_ECB_1_fu_435", "Parent" : "0", "Child" : ["14", "15", "16", "18", "19", "20", "21"],
		"CDFG" : "AES256_ECB_1",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "1077", "EstimateLatencyMax" : "1077",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"WaitState" : [
			{"State" : "ap_ST_fsm_state9", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_KeyExpansion_fu_380"},
			{"State" : "ap_ST_fsm_state17", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_MixColumns_fu_389"},
			{"State" : "ap_ST_fsm_state25", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_MixColumns_fu_389"},
			{"State" : "ap_ST_fsm_state33", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_MixColumns_fu_389"},
			{"State" : "ap_ST_fsm_state41", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_MixColumns_fu_389"},
			{"State" : "ap_ST_fsm_state49", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_MixColumns_fu_389"},
			{"State" : "ap_ST_fsm_state57", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_MixColumns_fu_389"},
			{"State" : "ap_ST_fsm_state65", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_MixColumns_fu_389"},
			{"State" : "ap_ST_fsm_state73", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_MixColumns_fu_389"},
			{"State" : "ap_ST_fsm_state81", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_MixColumns_fu_389"},
			{"State" : "ap_ST_fsm_state89", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_MixColumns_fu_389"},
			{"State" : "ap_ST_fsm_state97", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_MixColumns_fu_389"},
			{"State" : "ap_ST_fsm_state105", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_MixColumns_fu_389"},
			{"State" : "ap_ST_fsm_state113", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_MixColumns_fu_389"},
			{"State" : "ap_ST_fsm_state15", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_ShiftRows_fu_394"},
			{"State" : "ap_ST_fsm_state23", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_ShiftRows_fu_394"},
			{"State" : "ap_ST_fsm_state31", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_ShiftRows_fu_394"},
			{"State" : "ap_ST_fsm_state39", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_ShiftRows_fu_394"},
			{"State" : "ap_ST_fsm_state47", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_ShiftRows_fu_394"},
			{"State" : "ap_ST_fsm_state55", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_ShiftRows_fu_394"},
			{"State" : "ap_ST_fsm_state63", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_ShiftRows_fu_394"},
			{"State" : "ap_ST_fsm_state71", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_ShiftRows_fu_394"},
			{"State" : "ap_ST_fsm_state79", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_ShiftRows_fu_394"},
			{"State" : "ap_ST_fsm_state87", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_ShiftRows_fu_394"},
			{"State" : "ap_ST_fsm_state95", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_ShiftRows_fu_394"},
			{"State" : "ap_ST_fsm_state103", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_ShiftRows_fu_394"},
			{"State" : "ap_ST_fsm_state111", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_ShiftRows_fu_394"},
			{"State" : "ap_ST_fsm_state119", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_ShiftRows_fu_394"},
			{"State" : "ap_ST_fsm_state11", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_AddRoundKey_fu_399"},
			{"State" : "ap_ST_fsm_state19", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_AddRoundKey_fu_399"},
			{"State" : "ap_ST_fsm_state27", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_AddRoundKey_fu_399"},
			{"State" : "ap_ST_fsm_state35", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_AddRoundKey_fu_399"},
			{"State" : "ap_ST_fsm_state43", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_AddRoundKey_fu_399"},
			{"State" : "ap_ST_fsm_state51", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_AddRoundKey_fu_399"},
			{"State" : "ap_ST_fsm_state59", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_AddRoundKey_fu_399"},
			{"State" : "ap_ST_fsm_state67", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_AddRoundKey_fu_399"},
			{"State" : "ap_ST_fsm_state75", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_AddRoundKey_fu_399"},
			{"State" : "ap_ST_fsm_state83", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_AddRoundKey_fu_399"},
			{"State" : "ap_ST_fsm_state91", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_AddRoundKey_fu_399"},
			{"State" : "ap_ST_fsm_state99", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_AddRoundKey_fu_399"},
			{"State" : "ap_ST_fsm_state107", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_AddRoundKey_fu_399"},
			{"State" : "ap_ST_fsm_state115", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_AddRoundKey_fu_399"},
			{"State" : "ap_ST_fsm_state121", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_AddRoundKey_fu_399"},
			{"State" : "ap_ST_fsm_state13", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_SubBytes_fu_421"},
			{"State" : "ap_ST_fsm_state21", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_SubBytes_fu_421"},
			{"State" : "ap_ST_fsm_state29", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_SubBytes_fu_421"},
			{"State" : "ap_ST_fsm_state37", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_SubBytes_fu_421"},
			{"State" : "ap_ST_fsm_state45", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_SubBytes_fu_421"},
			{"State" : "ap_ST_fsm_state53", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_SubBytes_fu_421"},
			{"State" : "ap_ST_fsm_state61", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_SubBytes_fu_421"},
			{"State" : "ap_ST_fsm_state69", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_SubBytes_fu_421"},
			{"State" : "ap_ST_fsm_state77", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_SubBytes_fu_421"},
			{"State" : "ap_ST_fsm_state85", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_SubBytes_fu_421"},
			{"State" : "ap_ST_fsm_state93", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_SubBytes_fu_421"},
			{"State" : "ap_ST_fsm_state101", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_SubBytes_fu_421"},
			{"State" : "ap_ST_fsm_state109", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_SubBytes_fu_421"},
			{"State" : "ap_ST_fsm_state117", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_SubBytes_fu_421"}],
		"Port" : [
			{"Name" : "key", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "16", "SubInstance" : "grp_KeyExpansion_fu_380", "Port" : "Key"}]},
			{"Name" : "ctr", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "sbox", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "16", "SubInstance" : "grp_KeyExpansion_fu_380", "Port" : "sbox"},
					{"ID" : "21", "SubInstance" : "grp_SubBytes_fu_421", "Port" : "sbox"}]}]},
	{"ID" : "14", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_AES256_ECB_1_fu_435.ctx_RoundKey_U", "Parent" : "13"},
	{"ID" : "15", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_AES256_ECB_1_fu_435.test_U", "Parent" : "13"},
	{"ID" : "16", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_AES256_ECB_1_fu_435.grp_KeyExpansion_fu_380", "Parent" : "13", "Child" : ["17"],
		"CDFG" : "KeyExpansion",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "120", "EstimateLatencyMax" : "120",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "RoundKey", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "Key", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "sbox", "Type" : "Memory", "Direction" : "I"}]},
	{"ID" : "17", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_AES256_ECB_1_fu_435.grp_KeyExpansion_fu_380.sbox_U", "Parent" : "16"},
	{"ID" : "18", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_AES256_ECB_1_fu_435.grp_MixColumns_fu_389", "Parent" : "13",
		"CDFG" : "MixColumns",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "15", "EstimateLatencyMax" : "15",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "state", "Type" : "Memory", "Direction" : "IO"}]},
	{"ID" : "19", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_AES256_ECB_1_fu_435.grp_ShiftRows_fu_394", "Parent" : "13",
		"CDFG" : "ShiftRows",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "10", "EstimateLatencyMax" : "10",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "state", "Type" : "Memory", "Direction" : "IO"}]},
	{"ID" : "20", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_AES256_ECB_1_fu_435.grp_AddRoundKey_fu_399", "Parent" : "13",
		"CDFG" : "AddRoundKey",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "17", "EstimateLatencyMax" : "17",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "round", "Type" : "None", "Direction" : "I"},
			{"Name" : "state", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "RoundKey", "Type" : "Memory", "Direction" : "I"}]},
	{"ID" : "21", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_AES256_ECB_1_fu_435.grp_SubBytes_fu_421", "Parent" : "13", "Child" : ["22"],
		"CDFG" : "SubBytes",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "17", "EstimateLatencyMax" : "17",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "state", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "sbox", "Type" : "Memory", "Direction" : "I"}]},
	{"ID" : "22", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_AES256_ECB_1_fu_435.grp_SubBytes_fu_421.sbox_U", "Parent" : "21"}]}


set ArgLastReadFirstWriteLatency {
	randombytes {
		x {Type O LastRead -1 FirstWrite 19}
		DRBG_ctx_V {Type IO LastRead 16 FirstWrite -1}
		sbox {Type I LastRead -1 FirstWrite -1}
		DRBG_ctx_Key {Type IO LastRead 16 FirstWrite -1}
		DRBG_ctx_reseed_counter {Type IO LastRead 26 FirstWrite 26}}
	AES256_CTR_DRBG_Upda {
		V {Type IO LastRead 16 FirstWrite -1}
		sbox {Type I LastRead -1 FirstWrite -1}
		DRBG_ctx_Key {Type IO LastRead 16 FirstWrite -1}}
	AES256_ECB {
		key {Type I LastRead 16 FirstWrite -1}
		ctr {Type I LastRead 8 FirstWrite -1}
		buffer_r {Type O LastRead -1 FirstWrite 122}
		buffer_offset {Type I LastRead 122 FirstWrite -1}
		sbox {Type I LastRead -1 FirstWrite -1}}
	KeyExpansion {
		RoundKey {Type O LastRead -1 FirstWrite 1}
		Key {Type I LastRead 16 FirstWrite -1}
		sbox {Type I LastRead -1 FirstWrite -1}}
	MixColumns {
		state {Type IO LastRead 8 FirstWrite 8}}
	ShiftRows {
		state {Type IO LastRead 6 FirstWrite 1}}
	AddRoundKey {
		round {Type I LastRead 0 FirstWrite -1}
		state {Type IO LastRead 3 FirstWrite 3}
		RoundKey {Type I LastRead 3 FirstWrite -1}}
	SubBytes {
		state {Type IO LastRead 3 FirstWrite 3}
		sbox {Type I LastRead -1 FirstWrite -1}}
	AES256_ECB_1 {
		key {Type I LastRead 16 FirstWrite -1}
		ctr {Type I LastRead 8 FirstWrite -1}
		sbox {Type I LastRead -1 FirstWrite -1}}
	KeyExpansion {
		RoundKey {Type O LastRead -1 FirstWrite 1}
		Key {Type I LastRead 16 FirstWrite -1}
		sbox {Type I LastRead -1 FirstWrite -1}}
	MixColumns {
		state {Type IO LastRead 8 FirstWrite 8}}
	ShiftRows {
		state {Type IO LastRead 6 FirstWrite 1}}
	AddRoundKey {
		round {Type I LastRead 0 FirstWrite -1}
		state {Type IO LastRead 3 FirstWrite 3}
		RoundKey {Type I LastRead 3 FirstWrite -1}}
	SubBytes {
		state {Type IO LastRead 3 FirstWrite 3}
		sbox {Type I LastRead -1 FirstWrite -1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "4359", "Max" : "4419"}
	, {"Name" : "Interval", "Min" : "4359", "Max" : "4419"}
]}

set PipelineEnableSignalInfo {[
]}

set Spec2ImplPortList { 
	x { ap_memory {  { x_address0 mem_address 1 5 }  { x_ce0 mem_ce 1 1 }  { x_we0 mem_we 1 1 }  { x_d0 mem_din 1 8 }  { x_address1 MemPortADDR2 1 5 }  { x_ce1 MemPortCE2 1 1 }  { x_we1 MemPortWE2 1 1 }  { x_d1 MemPortDIN2 1 8 } } }
	DRBG_ctx_V { ap_memory {  { DRBG_ctx_V_address0 mem_address 1 4 }  { DRBG_ctx_V_ce0 mem_ce 1 1 }  { DRBG_ctx_V_we0 mem_we 1 1 }  { DRBG_ctx_V_d0 mem_din 1 8 }  { DRBG_ctx_V_q0 mem_dout 0 8 }  { DRBG_ctx_V_address1 MemPortADDR2 1 4 }  { DRBG_ctx_V_ce1 MemPortCE2 1 1 }  { DRBG_ctx_V_we1 MemPortWE2 1 1 }  { DRBG_ctx_V_d1 MemPortDIN2 1 8 }  { DRBG_ctx_V_q1 MemPortDOUT2 0 8 } } }
	DRBG_ctx_Key { ap_memory {  { DRBG_ctx_Key_address0 mem_address 1 5 }  { DRBG_ctx_Key_ce0 mem_ce 1 1 }  { DRBG_ctx_Key_we0 mem_we 1 1 }  { DRBG_ctx_Key_d0 mem_din 1 8 }  { DRBG_ctx_Key_q0 mem_dout 0 8 }  { DRBG_ctx_Key_address1 MemPortADDR2 1 5 }  { DRBG_ctx_Key_ce1 MemPortCE2 1 1 }  { DRBG_ctx_Key_we1 MemPortWE2 1 1 }  { DRBG_ctx_Key_d1 MemPortDIN2 1 8 }  { DRBG_ctx_Key_q1 MemPortDOUT2 0 8 } } }
	DRBG_ctx_reseed_counter { ap_ovld {  { DRBG_ctx_reseed_counter_i in_data 0 32 }  { DRBG_ctx_reseed_counter_o out_data 1 32 }  { DRBG_ctx_reseed_counter_o_ap_vld out_vld 1 1 } } }
}
