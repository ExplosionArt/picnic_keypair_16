set moduleName AES256_ECB_1
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
set C_modelName {AES256_ECB.1}
set C_modelType { int 128 }
set C_modelArgList {
	{ key int 8 regular {array 32 { 1 1 } 1 1 }  }
	{ ctr int 8 regular {array 16 { 1 1 } 1 1 }  }
}
set C_modelArgMapList {[ 
	{ "Name" : "key", "interface" : "memory", "bitwidth" : 8, "direction" : "READONLY"} , 
 	{ "Name" : "ctr", "interface" : "memory", "bitwidth" : 8, "direction" : "READONLY"} , 
 	{ "Name" : "ap_return", "interface" : "wire", "bitwidth" : 128} ]}
# RTL Port declarations: 
set portNum 34
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ key_address0 sc_out sc_lv 5 signal 0 } 
	{ key_ce0 sc_out sc_logic 1 signal 0 } 
	{ key_q0 sc_in sc_lv 8 signal 0 } 
	{ key_address1 sc_out sc_lv 5 signal 0 } 
	{ key_ce1 sc_out sc_logic 1 signal 0 } 
	{ key_q1 sc_in sc_lv 8 signal 0 } 
	{ ctr_address0 sc_out sc_lv 4 signal 1 } 
	{ ctr_ce0 sc_out sc_logic 1 signal 1 } 
	{ ctr_q0 sc_in sc_lv 8 signal 1 } 
	{ ctr_address1 sc_out sc_lv 4 signal 1 } 
	{ ctr_ce1 sc_out sc_logic 1 signal 1 } 
	{ ctr_q1 sc_in sc_lv 8 signal 1 } 
	{ ap_return_0 sc_out sc_lv 8 signal -1 } 
	{ ap_return_1 sc_out sc_lv 8 signal -1 } 
	{ ap_return_2 sc_out sc_lv 8 signal -1 } 
	{ ap_return_3 sc_out sc_lv 8 signal -1 } 
	{ ap_return_4 sc_out sc_lv 8 signal -1 } 
	{ ap_return_5 sc_out sc_lv 8 signal -1 } 
	{ ap_return_6 sc_out sc_lv 8 signal -1 } 
	{ ap_return_7 sc_out sc_lv 8 signal -1 } 
	{ ap_return_8 sc_out sc_lv 8 signal -1 } 
	{ ap_return_9 sc_out sc_lv 8 signal -1 } 
	{ ap_return_10 sc_out sc_lv 8 signal -1 } 
	{ ap_return_11 sc_out sc_lv 8 signal -1 } 
	{ ap_return_12 sc_out sc_lv 8 signal -1 } 
	{ ap_return_13 sc_out sc_lv 8 signal -1 } 
	{ ap_return_14 sc_out sc_lv 8 signal -1 } 
	{ ap_return_15 sc_out sc_lv 8 signal -1 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "key_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "key", "role": "address0" }} , 
 	{ "name": "key_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "key", "role": "ce0" }} , 
 	{ "name": "key_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "key", "role": "q0" }} , 
 	{ "name": "key_address1", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "key", "role": "address1" }} , 
 	{ "name": "key_ce1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "key", "role": "ce1" }} , 
 	{ "name": "key_q1", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "key", "role": "q1" }} , 
 	{ "name": "ctr_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "ctr", "role": "address0" }} , 
 	{ "name": "ctr_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "ctr", "role": "ce0" }} , 
 	{ "name": "ctr_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "ctr", "role": "q0" }} , 
 	{ "name": "ctr_address1", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "ctr", "role": "address1" }} , 
 	{ "name": "ctr_ce1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "ctr", "role": "ce1" }} , 
 	{ "name": "ctr_q1", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "ctr", "role": "q1" }} , 
 	{ "name": "ap_return_0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "ap_return_0", "role": "default" }} , 
 	{ "name": "ap_return_1", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "ap_return_1", "role": "default" }} , 
 	{ "name": "ap_return_2", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "ap_return_2", "role": "default" }} , 
 	{ "name": "ap_return_3", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "ap_return_3", "role": "default" }} , 
 	{ "name": "ap_return_4", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "ap_return_4", "role": "default" }} , 
 	{ "name": "ap_return_5", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "ap_return_5", "role": "default" }} , 
 	{ "name": "ap_return_6", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "ap_return_6", "role": "default" }} , 
 	{ "name": "ap_return_7", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "ap_return_7", "role": "default" }} , 
 	{ "name": "ap_return_8", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "ap_return_8", "role": "default" }} , 
 	{ "name": "ap_return_9", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "ap_return_9", "role": "default" }} , 
 	{ "name": "ap_return_10", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "ap_return_10", "role": "default" }} , 
 	{ "name": "ap_return_11", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "ap_return_11", "role": "default" }} , 
 	{ "name": "ap_return_12", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "ap_return_12", "role": "default" }} , 
 	{ "name": "ap_return_13", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "ap_return_13", "role": "default" }} , 
 	{ "name": "ap_return_14", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "ap_return_14", "role": "default" }} , 
 	{ "name": "ap_return_15", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "ap_return_15", "role": "default" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2", "3", "5", "6", "7", "8"],
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
					{"ID" : "3", "SubInstance" : "grp_KeyExpansion_fu_380", "Port" : "Key"}]},
			{"Name" : "ctr", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "sbox", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "3", "SubInstance" : "grp_KeyExpansion_fu_380", "Port" : "sbox"},
					{"ID" : "8", "SubInstance" : "grp_SubBytes_fu_421", "Port" : "sbox"}]}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.ctx_RoundKey_U", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.test_U", "Parent" : "0"},
	{"ID" : "3", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_KeyExpansion_fu_380", "Parent" : "0", "Child" : ["4"],
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
	{"ID" : "4", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_KeyExpansion_fu_380.sbox_U", "Parent" : "3"},
	{"ID" : "5", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_MixColumns_fu_389", "Parent" : "0",
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
	{"ID" : "6", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_ShiftRows_fu_394", "Parent" : "0",
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
	{"ID" : "7", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_AddRoundKey_fu_399", "Parent" : "0",
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
	{"ID" : "8", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_SubBytes_fu_421", "Parent" : "0", "Child" : ["9"],
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
	{"ID" : "9", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_SubBytes_fu_421.sbox_U", "Parent" : "8"}]}


set ArgLastReadFirstWriteLatency {
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
	{"Name" : "Latency", "Min" : "1077", "Max" : "1077"}
	, {"Name" : "Interval", "Min" : "1077", "Max" : "1077"}
]}

set PipelineEnableSignalInfo {[
]}

set Spec2ImplPortList { 
	key { ap_memory {  { key_address0 mem_address 1 5 }  { key_ce0 mem_ce 1 1 }  { key_q0 mem_dout 0 8 }  { key_address1 MemPortADDR2 1 5 }  { key_ce1 MemPortCE2 1 1 }  { key_q1 MemPortDOUT2 0 8 } } }
	ctr { ap_memory {  { ctr_address0 mem_address 1 4 }  { ctr_ce0 mem_ce 1 1 }  { ctr_q0 mem_dout 0 8 }  { ctr_address1 MemPortADDR2 1 4 }  { ctr_ce1 MemPortCE2 1 1 }  { ctr_q1 MemPortDOUT2 0 8 } } }
}
