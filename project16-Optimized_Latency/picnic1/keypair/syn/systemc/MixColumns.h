// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and OpenCL
// Version: 2019.2
// Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#ifndef _MixColumns_HH_
#define _MixColumns_HH_

#include "systemc.h"
#include "AESL_pkg.h"


namespace ap_rtl {

struct MixColumns : public sc_module {
    // Port declarations 16
    sc_in_clk ap_clk;
    sc_in< sc_logic > ap_rst;
    sc_in< sc_logic > ap_start;
    sc_out< sc_logic > ap_done;
    sc_out< sc_logic > ap_idle;
    sc_out< sc_logic > ap_ready;
    sc_out< sc_lv<4> > state_address0;
    sc_out< sc_logic > state_ce0;
    sc_out< sc_logic > state_we0;
    sc_out< sc_lv<8> > state_d0;
    sc_in< sc_lv<8> > state_q0;
    sc_out< sc_lv<4> > state_address1;
    sc_out< sc_logic > state_ce1;
    sc_out< sc_logic > state_we1;
    sc_out< sc_lv<8> > state_d1;
    sc_in< sc_lv<8> > state_q1;


    // Module declarations
    MixColumns(sc_module_name name);
    SC_HAS_PROCESS(MixColumns);

    ~MixColumns();

    sc_trace_file* mVcdFile;

    sc_signal< sc_lv<16> > ap_CS_fsm;
    sc_signal< sc_logic > ap_CS_fsm_state1;
    sc_signal< sc_lv<8> > reg_197;
    sc_signal< sc_logic > ap_CS_fsm_state2;
    sc_signal< sc_logic > ap_CS_fsm_state9;
    sc_signal< sc_lv<8> > reg_201;
    sc_signal< sc_lv<4> > state_addr_reg_928;
    sc_signal< sc_lv<4> > state_addr_12_reg_933;
    sc_signal< sc_lv<4> > state_addr_13_reg_938;
    sc_signal< sc_lv<4> > state_addr_14_reg_943;
    sc_signal< sc_lv<4> > state_addr_1_reg_948;
    sc_signal< sc_logic > ap_CS_fsm_state3;
    sc_signal< sc_lv<4> > state_addr_15_reg_953;
    sc_signal< sc_lv<8> > state_load_14_reg_958;
    sc_signal< sc_lv<8> > state_load_15_reg_966;
    sc_signal< sc_lv<4> > state_addr_16_reg_973;
    sc_signal< sc_logic > ap_CS_fsm_state4;
    sc_signal< sc_lv<4> > state_addr_17_reg_978;
    sc_signal< sc_lv<8> > state_load_16_reg_983;
    sc_signal< sc_lv<8> > state_load_1_reg_990;
    sc_signal< sc_lv<4> > state_addr_2_reg_997;
    sc_signal< sc_logic > ap_CS_fsm_state5;
    sc_signal< sc_lv<4> > state_addr_18_reg_1002;
    sc_signal< sc_lv<8> > state_load_17_reg_1007;
    sc_signal< sc_lv<8> > state_load_18_reg_1015;
    sc_signal< sc_lv<4> > state_addr_19_reg_1022;
    sc_signal< sc_logic > ap_CS_fsm_state6;
    sc_signal< sc_lv<4> > state_addr_20_reg_1027;
    sc_signal< sc_lv<8> > state_load_19_reg_1032;
    sc_signal< sc_lv<8> > state_load_2_reg_1039;
    sc_signal< sc_lv<4> > state_addr_3_reg_1046;
    sc_signal< sc_logic > ap_CS_fsm_state7;
    sc_signal< sc_lv<4> > state_addr_21_reg_1051;
    sc_signal< sc_lv<8> > state_load_20_reg_1056;
    sc_signal< sc_lv<8> > state_load_21_reg_1064;
    sc_signal< sc_lv<4> > state_addr_22_reg_1071;
    sc_signal< sc_logic > ap_CS_fsm_state8;
    sc_signal< sc_lv<4> > state_addr_23_reg_1076;
    sc_signal< sc_lv<8> > state_load_22_reg_1081;
    sc_signal< sc_lv<8> > state_load_3_reg_1088;
    sc_signal< sc_lv<8> > xor_ln321_1_fu_345_p2;
    sc_signal< sc_lv<8> > xor_ln321_1_reg_1095;
    sc_signal< sc_lv<8> > xor_ln322_fu_384_p2;
    sc_signal< sc_lv<8> > xor_ln322_reg_1100;
    sc_signal< sc_lv<8> > xor_ln321_6_fu_525_p2;
    sc_signal< sc_lv<8> > xor_ln321_6_reg_1105;
    sc_signal< sc_logic > ap_CS_fsm_state11;
    sc_signal< sc_lv<8> > xor_ln322_2_fu_563_p2;
    sc_signal< sc_lv<8> > xor_ln322_2_reg_1110;
    sc_signal< sc_lv<8> > xor_ln321_8_fu_704_p2;
    sc_signal< sc_lv<8> > xor_ln321_8_reg_1115;
    sc_signal< sc_logic > ap_CS_fsm_state13;
    sc_signal< sc_lv<8> > xor_ln322_4_fu_742_p2;
    sc_signal< sc_lv<8> > xor_ln322_4_reg_1120;
    sc_signal< sc_lv<8> > xor_ln321_10_fu_883_p2;
    sc_signal< sc_lv<8> > xor_ln321_10_reg_1125;
    sc_signal< sc_logic > ap_CS_fsm_state15;
    sc_signal< sc_lv<8> > xor_ln322_6_fu_922_p2;
    sc_signal< sc_lv<8> > xor_ln322_6_reg_1130;
    sc_signal< sc_lv<8> > xor_ln319_1_fu_255_p2;
    sc_signal< sc_lv<8> > xor_ln320_1_fu_301_p2;
    sc_signal< sc_logic > ap_CS_fsm_state10;
    sc_signal< sc_lv<8> > xor_ln319_5_fu_437_p2;
    sc_signal< sc_lv<8> > xor_ln320_6_fu_481_p2;
    sc_signal< sc_logic > ap_CS_fsm_state12;
    sc_signal< sc_lv<8> > xor_ln319_6_fu_616_p2;
    sc_signal< sc_lv<8> > xor_ln320_8_fu_660_p2;
    sc_signal< sc_logic > ap_CS_fsm_state14;
    sc_signal< sc_lv<8> > xor_ln319_7_fu_797_p2;
    sc_signal< sc_lv<8> > xor_ln320_10_fu_842_p2;
    sc_signal< sc_logic > ap_CS_fsm_state16;
    sc_signal< sc_lv<8> > grp_fu_205_p2;
    sc_signal< sc_lv<8> > xor_ln318_1_fu_211_p2;
    sc_signal< sc_lv<1> > tmp_fu_227_p3;
    sc_signal< sc_lv<8> > select_ln306_fu_235_p3;
    sc_signal< sc_lv<8> > shl_ln306_fu_221_p2;
    sc_signal< sc_lv<8> > xor_ln318_2_fu_216_p2;
    sc_signal< sc_lv<8> > xor_ln319_2_fu_249_p2;
    sc_signal< sc_lv<8> > xor_ln319_fu_243_p2;
    sc_signal< sc_lv<8> > xor_ln320_3_fu_262_p2;
    sc_signal< sc_lv<1> > tmp_21_fu_273_p3;
    sc_signal< sc_lv<8> > select_ln306_1_fu_281_p3;
    sc_signal< sc_lv<8> > shl_ln306_1_fu_267_p2;
    sc_signal< sc_lv<8> > xor_ln320_2_fu_295_p2;
    sc_signal< sc_lv<8> > xor_ln320_fu_289_p2;
    sc_signal< sc_lv<8> > xor_ln321_3_fu_308_p2;
    sc_signal< sc_lv<1> > tmp_22_fu_318_p3;
    sc_signal< sc_lv<8> > select_ln306_2_fu_326_p3;
    sc_signal< sc_lv<8> > shl_ln306_2_fu_312_p2;
    sc_signal< sc_lv<8> > xor_ln321_2_fu_339_p2;
    sc_signal< sc_lv<8> > xor_ln321_fu_334_p2;
    sc_signal< sc_lv<8> > xor_ln322_1_fu_351_p2;
    sc_signal< sc_lv<1> > tmp_23_fu_362_p3;
    sc_signal< sc_lv<8> > shl_ln306_3_fu_356_p2;
    sc_signal< sc_lv<8> > xor_ln322_3_fu_378_p2;
    sc_signal< sc_lv<8> > select_ln306_3_fu_370_p3;
    sc_signal< sc_lv<8> > xor_ln318_9_fu_390_p2;
    sc_signal< sc_lv<8> > xor_ln318_3_fu_394_p2;
    sc_signal< sc_lv<1> > tmp_24_fu_410_p3;
    sc_signal< sc_lv<8> > select_ln306_4_fu_418_p3;
    sc_signal< sc_lv<8> > shl_ln306_4_fu_404_p2;
    sc_signal< sc_lv<8> > xor_ln318_4_fu_399_p2;
    sc_signal< sc_lv<8> > xor_ln319_4_fu_431_p2;
    sc_signal< sc_lv<8> > xor_ln319_3_fu_426_p2;
    sc_signal< sc_lv<8> > xor_ln320_7_fu_444_p2;
    sc_signal< sc_lv<1> > tmp_25_fu_454_p3;
    sc_signal< sc_lv<8> > select_ln306_5_fu_462_p3;
    sc_signal< sc_lv<8> > shl_ln306_5_fu_448_p2;
    sc_signal< sc_lv<8> > xor_ln320_5_fu_475_p2;
    sc_signal< sc_lv<8> > xor_ln320_4_fu_470_p2;
    sc_signal< sc_lv<8> > xor_ln321_7_fu_488_p2;
    sc_signal< sc_lv<1> > tmp_26_fu_498_p3;
    sc_signal< sc_lv<8> > select_ln306_6_fu_506_p3;
    sc_signal< sc_lv<8> > shl_ln306_6_fu_492_p2;
    sc_signal< sc_lv<8> > xor_ln321_5_fu_519_p2;
    sc_signal< sc_lv<8> > xor_ln321_4_fu_514_p2;
    sc_signal< sc_lv<8> > xor_ln322_5_fu_531_p2;
    sc_signal< sc_lv<1> > tmp_27_fu_541_p3;
    sc_signal< sc_lv<8> > shl_ln306_7_fu_535_p2;
    sc_signal< sc_lv<8> > xor_ln322_7_fu_557_p2;
    sc_signal< sc_lv<8> > select_ln306_7_fu_549_p3;
    sc_signal< sc_lv<8> > xor_ln318_10_fu_569_p2;
    sc_signal< sc_lv<8> > xor_ln318_5_fu_573_p2;
    sc_signal< sc_lv<1> > tmp_28_fu_589_p3;
    sc_signal< sc_lv<8> > select_ln306_8_fu_597_p3;
    sc_signal< sc_lv<8> > shl_ln306_8_fu_583_p2;
    sc_signal< sc_lv<8> > xor_ln318_6_fu_578_p2;
    sc_signal< sc_lv<8> > xor_ln319_9_fu_610_p2;
    sc_signal< sc_lv<8> > xor_ln319_8_fu_605_p2;
    sc_signal< sc_lv<8> > xor_ln320_12_fu_623_p2;
    sc_signal< sc_lv<1> > tmp_29_fu_633_p3;
    sc_signal< sc_lv<8> > select_ln306_9_fu_641_p3;
    sc_signal< sc_lv<8> > shl_ln306_9_fu_627_p2;
    sc_signal< sc_lv<8> > xor_ln320_11_fu_654_p2;
    sc_signal< sc_lv<8> > xor_ln320_9_fu_649_p2;
    sc_signal< sc_lv<8> > xor_ln321_12_fu_667_p2;
    sc_signal< sc_lv<1> > tmp_30_fu_677_p3;
    sc_signal< sc_lv<8> > select_ln306_10_fu_685_p3;
    sc_signal< sc_lv<8> > shl_ln306_10_fu_671_p2;
    sc_signal< sc_lv<8> > xor_ln321_11_fu_698_p2;
    sc_signal< sc_lv<8> > xor_ln321_9_fu_693_p2;
    sc_signal< sc_lv<8> > xor_ln322_8_fu_710_p2;
    sc_signal< sc_lv<1> > tmp_31_fu_720_p3;
    sc_signal< sc_lv<8> > shl_ln306_11_fu_714_p2;
    sc_signal< sc_lv<8> > xor_ln322_9_fu_736_p2;
    sc_signal< sc_lv<8> > select_ln306_11_fu_728_p3;
    sc_signal< sc_lv<8> > xor_ln318_11_fu_748_p2;
    sc_signal< sc_lv<8> > xor_ln318_7_fu_752_p2;
    sc_signal< sc_lv<1> > tmp_32_fu_770_p3;
    sc_signal< sc_lv<8> > select_ln306_12_fu_778_p3;
    sc_signal< sc_lv<8> > shl_ln306_12_fu_764_p2;
    sc_signal< sc_lv<8> > xor_ln318_8_fu_758_p2;
    sc_signal< sc_lv<8> > xor_ln319_11_fu_791_p2;
    sc_signal< sc_lv<8> > xor_ln319_10_fu_786_p2;
    sc_signal< sc_lv<8> > xor_ln320_15_fu_804_p2;
    sc_signal< sc_lv<1> > tmp_33_fu_815_p3;
    sc_signal< sc_lv<8> > select_ln306_13_fu_823_p3;
    sc_signal< sc_lv<8> > shl_ln306_13_fu_809_p2;
    sc_signal< sc_lv<8> > xor_ln320_14_fu_836_p2;
    sc_signal< sc_lv<8> > xor_ln320_13_fu_831_p2;
    sc_signal< sc_lv<1> > tmp_34_fu_855_p3;
    sc_signal< sc_lv<8> > select_ln306_14_fu_863_p3;
    sc_signal< sc_lv<8> > shl_ln306_14_fu_849_p2;
    sc_signal< sc_lv<8> > xor_ln321_14_fu_877_p2;
    sc_signal< sc_lv<8> > xor_ln321_13_fu_871_p2;
    sc_signal< sc_lv<8> > xor_ln322_10_fu_889_p2;
    sc_signal< sc_lv<1> > tmp_35_fu_900_p3;
    sc_signal< sc_lv<8> > shl_ln306_15_fu_894_p2;
    sc_signal< sc_lv<8> > xor_ln322_11_fu_916_p2;
    sc_signal< sc_lv<8> > select_ln306_15_fu_908_p3;
    sc_signal< sc_lv<16> > ap_NS_fsm;
    static const sc_logic ap_const_logic_1;
    static const sc_logic ap_const_logic_0;
    static const sc_lv<16> ap_ST_fsm_state1;
    static const sc_lv<16> ap_ST_fsm_state2;
    static const sc_lv<16> ap_ST_fsm_state3;
    static const sc_lv<16> ap_ST_fsm_state4;
    static const sc_lv<16> ap_ST_fsm_state5;
    static const sc_lv<16> ap_ST_fsm_state6;
    static const sc_lv<16> ap_ST_fsm_state7;
    static const sc_lv<16> ap_ST_fsm_state8;
    static const sc_lv<16> ap_ST_fsm_state9;
    static const sc_lv<16> ap_ST_fsm_state10;
    static const sc_lv<16> ap_ST_fsm_state11;
    static const sc_lv<16> ap_ST_fsm_state12;
    static const sc_lv<16> ap_ST_fsm_state13;
    static const sc_lv<16> ap_ST_fsm_state14;
    static const sc_lv<16> ap_ST_fsm_state15;
    static const sc_lv<16> ap_ST_fsm_state16;
    static const sc_lv<32> ap_const_lv32_0;
    static const sc_lv<32> ap_const_lv32_1;
    static const sc_lv<32> ap_const_lv32_8;
    static const sc_lv<32> ap_const_lv32_2;
    static const sc_lv<32> ap_const_lv32_3;
    static const sc_lv<32> ap_const_lv32_4;
    static const sc_lv<32> ap_const_lv32_5;
    static const sc_lv<32> ap_const_lv32_6;
    static const sc_lv<32> ap_const_lv32_7;
    static const sc_lv<32> ap_const_lv32_A;
    static const sc_lv<32> ap_const_lv32_C;
    static const sc_lv<32> ap_const_lv32_E;
    static const sc_lv<64> ap_const_lv64_0;
    static const sc_lv<64> ap_const_lv64_1;
    static const sc_lv<64> ap_const_lv64_2;
    static const sc_lv<64> ap_const_lv64_3;
    static const sc_lv<64> ap_const_lv64_4;
    static const sc_lv<64> ap_const_lv64_5;
    static const sc_lv<64> ap_const_lv64_6;
    static const sc_lv<64> ap_const_lv64_7;
    static const sc_lv<64> ap_const_lv64_8;
    static const sc_lv<64> ap_const_lv64_9;
    static const sc_lv<64> ap_const_lv64_A;
    static const sc_lv<64> ap_const_lv64_B;
    static const sc_lv<64> ap_const_lv64_C;
    static const sc_lv<64> ap_const_lv64_D;
    static const sc_lv<64> ap_const_lv64_E;
    static const sc_lv<64> ap_const_lv64_F;
    static const sc_lv<32> ap_const_lv32_9;
    static const sc_lv<32> ap_const_lv32_B;
    static const sc_lv<32> ap_const_lv32_D;
    static const sc_lv<32> ap_const_lv32_F;
    static const sc_lv<8> ap_const_lv8_1;
    static const sc_lv<8> ap_const_lv8_1B;
    static const sc_lv<8> ap_const_lv8_0;
    static const bool ap_const_boolean_1;
    // Thread declarations
    void thread_ap_clk_no_reset_();
    void thread_ap_CS_fsm_state1();
    void thread_ap_CS_fsm_state10();
    void thread_ap_CS_fsm_state11();
    void thread_ap_CS_fsm_state12();
    void thread_ap_CS_fsm_state13();
    void thread_ap_CS_fsm_state14();
    void thread_ap_CS_fsm_state15();
    void thread_ap_CS_fsm_state16();
    void thread_ap_CS_fsm_state2();
    void thread_ap_CS_fsm_state3();
    void thread_ap_CS_fsm_state4();
    void thread_ap_CS_fsm_state5();
    void thread_ap_CS_fsm_state6();
    void thread_ap_CS_fsm_state7();
    void thread_ap_CS_fsm_state8();
    void thread_ap_CS_fsm_state9();
    void thread_ap_done();
    void thread_ap_idle();
    void thread_ap_ready();
    void thread_grp_fu_205_p2();
    void thread_select_ln306_10_fu_685_p3();
    void thread_select_ln306_11_fu_728_p3();
    void thread_select_ln306_12_fu_778_p3();
    void thread_select_ln306_13_fu_823_p3();
    void thread_select_ln306_14_fu_863_p3();
    void thread_select_ln306_15_fu_908_p3();
    void thread_select_ln306_1_fu_281_p3();
    void thread_select_ln306_2_fu_326_p3();
    void thread_select_ln306_3_fu_370_p3();
    void thread_select_ln306_4_fu_418_p3();
    void thread_select_ln306_5_fu_462_p3();
    void thread_select_ln306_6_fu_506_p3();
    void thread_select_ln306_7_fu_549_p3();
    void thread_select_ln306_8_fu_597_p3();
    void thread_select_ln306_9_fu_641_p3();
    void thread_select_ln306_fu_235_p3();
    void thread_shl_ln306_10_fu_671_p2();
    void thread_shl_ln306_11_fu_714_p2();
    void thread_shl_ln306_12_fu_764_p2();
    void thread_shl_ln306_13_fu_809_p2();
    void thread_shl_ln306_14_fu_849_p2();
    void thread_shl_ln306_15_fu_894_p2();
    void thread_shl_ln306_1_fu_267_p2();
    void thread_shl_ln306_2_fu_312_p2();
    void thread_shl_ln306_3_fu_356_p2();
    void thread_shl_ln306_4_fu_404_p2();
    void thread_shl_ln306_5_fu_448_p2();
    void thread_shl_ln306_6_fu_492_p2();
    void thread_shl_ln306_7_fu_535_p2();
    void thread_shl_ln306_8_fu_583_p2();
    void thread_shl_ln306_9_fu_627_p2();
    void thread_shl_ln306_fu_221_p2();
    void thread_state_addr_12_reg_933();
    void thread_state_addr_13_reg_938();
    void thread_state_addr_14_reg_943();
    void thread_state_addr_15_reg_953();
    void thread_state_addr_16_reg_973();
    void thread_state_addr_17_reg_978();
    void thread_state_addr_18_reg_1002();
    void thread_state_addr_19_reg_1022();
    void thread_state_addr_1_reg_948();
    void thread_state_addr_20_reg_1027();
    void thread_state_addr_21_reg_1051();
    void thread_state_addr_22_reg_1071();
    void thread_state_addr_23_reg_1076();
    void thread_state_addr_2_reg_997();
    void thread_state_addr_3_reg_1046();
    void thread_state_addr_reg_928();
    void thread_state_address0();
    void thread_state_address1();
    void thread_state_ce0();
    void thread_state_ce1();
    void thread_state_d0();
    void thread_state_d1();
    void thread_state_we0();
    void thread_state_we1();
    void thread_tmp_21_fu_273_p3();
    void thread_tmp_22_fu_318_p3();
    void thread_tmp_23_fu_362_p3();
    void thread_tmp_24_fu_410_p3();
    void thread_tmp_25_fu_454_p3();
    void thread_tmp_26_fu_498_p3();
    void thread_tmp_27_fu_541_p3();
    void thread_tmp_28_fu_589_p3();
    void thread_tmp_29_fu_633_p3();
    void thread_tmp_30_fu_677_p3();
    void thread_tmp_31_fu_720_p3();
    void thread_tmp_32_fu_770_p3();
    void thread_tmp_33_fu_815_p3();
    void thread_tmp_34_fu_855_p3();
    void thread_tmp_35_fu_900_p3();
    void thread_tmp_fu_227_p3();
    void thread_xor_ln318_10_fu_569_p2();
    void thread_xor_ln318_11_fu_748_p2();
    void thread_xor_ln318_1_fu_211_p2();
    void thread_xor_ln318_2_fu_216_p2();
    void thread_xor_ln318_3_fu_394_p2();
    void thread_xor_ln318_4_fu_399_p2();
    void thread_xor_ln318_5_fu_573_p2();
    void thread_xor_ln318_6_fu_578_p2();
    void thread_xor_ln318_7_fu_752_p2();
    void thread_xor_ln318_8_fu_758_p2();
    void thread_xor_ln318_9_fu_390_p2();
    void thread_xor_ln319_10_fu_786_p2();
    void thread_xor_ln319_11_fu_791_p2();
    void thread_xor_ln319_1_fu_255_p2();
    void thread_xor_ln319_2_fu_249_p2();
    void thread_xor_ln319_3_fu_426_p2();
    void thread_xor_ln319_4_fu_431_p2();
    void thread_xor_ln319_5_fu_437_p2();
    void thread_xor_ln319_6_fu_616_p2();
    void thread_xor_ln319_7_fu_797_p2();
    void thread_xor_ln319_8_fu_605_p2();
    void thread_xor_ln319_9_fu_610_p2();
    void thread_xor_ln319_fu_243_p2();
    void thread_xor_ln320_10_fu_842_p2();
    void thread_xor_ln320_11_fu_654_p2();
    void thread_xor_ln320_12_fu_623_p2();
    void thread_xor_ln320_13_fu_831_p2();
    void thread_xor_ln320_14_fu_836_p2();
    void thread_xor_ln320_15_fu_804_p2();
    void thread_xor_ln320_1_fu_301_p2();
    void thread_xor_ln320_2_fu_295_p2();
    void thread_xor_ln320_3_fu_262_p2();
    void thread_xor_ln320_4_fu_470_p2();
    void thread_xor_ln320_5_fu_475_p2();
    void thread_xor_ln320_6_fu_481_p2();
    void thread_xor_ln320_7_fu_444_p2();
    void thread_xor_ln320_8_fu_660_p2();
    void thread_xor_ln320_9_fu_649_p2();
    void thread_xor_ln320_fu_289_p2();
    void thread_xor_ln321_10_fu_883_p2();
    void thread_xor_ln321_11_fu_698_p2();
    void thread_xor_ln321_12_fu_667_p2();
    void thread_xor_ln321_13_fu_871_p2();
    void thread_xor_ln321_14_fu_877_p2();
    void thread_xor_ln321_1_fu_345_p2();
    void thread_xor_ln321_2_fu_339_p2();
    void thread_xor_ln321_3_fu_308_p2();
    void thread_xor_ln321_4_fu_514_p2();
    void thread_xor_ln321_5_fu_519_p2();
    void thread_xor_ln321_6_fu_525_p2();
    void thread_xor_ln321_7_fu_488_p2();
    void thread_xor_ln321_8_fu_704_p2();
    void thread_xor_ln321_9_fu_693_p2();
    void thread_xor_ln321_fu_334_p2();
    void thread_xor_ln322_10_fu_889_p2();
    void thread_xor_ln322_11_fu_916_p2();
    void thread_xor_ln322_1_fu_351_p2();
    void thread_xor_ln322_2_fu_563_p2();
    void thread_xor_ln322_3_fu_378_p2();
    void thread_xor_ln322_4_fu_742_p2();
    void thread_xor_ln322_5_fu_531_p2();
    void thread_xor_ln322_6_fu_922_p2();
    void thread_xor_ln322_7_fu_557_p2();
    void thread_xor_ln322_8_fu_710_p2();
    void thread_xor_ln322_9_fu_736_p2();
    void thread_xor_ln322_fu_384_p2();
    void thread_ap_NS_fsm();
};

}

using namespace ap_rtl;

#endif