// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and OpenCL
// Version: 2019.2
// Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#ifndef _LowMCEnc_HH_
#define _LowMCEnc_HH_

#include "systemc.h"
#include "AESL_pkg.h"

#include "matrix_mul.h"
#include "matrix_mul_1.h"
#include "LowMCEnc_temp_matg8j.h"
#include "LowMCEnc_roundKey.h"
#include "LowMCEnc_temp.h"

namespace ap_rtl {

struct LowMCEnc : public sc_module {
    // Port declarations 28
    sc_in_clk ap_clk;
    sc_in< sc_logic > ap_rst;
    sc_in< sc_logic > ap_start;
    sc_out< sc_logic > ap_done;
    sc_out< sc_logic > ap_idle;
    sc_out< sc_logic > ap_ready;
    sc_out< sc_lv<3> > plaintext_address0;
    sc_out< sc_logic > plaintext_ce0;
    sc_in< sc_lv<32> > plaintext_q0;
    sc_out< sc_lv<3> > plaintext_address1;
    sc_out< sc_logic > plaintext_ce1;
    sc_in< sc_lv<32> > plaintext_q1;
    sc_out< sc_lv<3> > output_r_address0;
    sc_out< sc_logic > output_r_ce0;
    sc_out< sc_logic > output_r_we0;
    sc_out< sc_lv<32> > output_r_d0;
    sc_in< sc_lv<32> > output_r_q0;
    sc_out< sc_lv<3> > output_r_address1;
    sc_out< sc_logic > output_r_ce1;
    sc_out< sc_logic > output_r_we1;
    sc_out< sc_lv<32> > output_r_d1;
    sc_in< sc_lv<32> > output_r_q1;
    sc_out< sc_lv<3> > key_address0;
    sc_out< sc_logic > key_ce0;
    sc_in< sc_lv<32> > key_q0;
    sc_out< sc_lv<3> > key_address1;
    sc_out< sc_logic > key_ce1;
    sc_in< sc_lv<32> > key_q1;


    // Module declarations
    LowMCEnc(sc_module_name name);
    SC_HAS_PROCESS(LowMCEnc);

    ~LowMCEnc();

    sc_trace_file* mVcdFile;

    LowMCEnc_temp_matg8j* temp_matrix3_U;
    LowMCEnc_roundKey* roundKey_U;
    LowMCEnc_temp* temp_U;
    matrix_mul* grp_matrix_mul_fu_428;
    matrix_mul_1* grp_matrix_mul_1_fu_437;
    sc_signal< sc_lv<24> > ap_CS_fsm;
    sc_signal< sc_logic > ap_CS_fsm_state1;
    sc_signal< sc_lv<7> > temp_matrix3_address0;
    sc_signal< sc_logic > temp_matrix3_ce0;
    sc_signal< sc_lv<32> > temp_matrix3_q0;
    sc_signal< sc_lv<7> > temp_matrix3_address1;
    sc_signal< sc_logic > temp_matrix3_ce1;
    sc_signal< sc_lv<32> > temp_matrix3_q1;
    sc_signal< sc_lv<3> > loop_0_0_reg_360;
    sc_signal< sc_lv<8> > temp_q0;
    sc_signal< sc_lv<8> > reg_462;
    sc_signal< sc_logic > ap_CS_fsm_state12;
    sc_signal< sc_logic > ap_CS_fsm_state18;
    sc_signal< sc_lv<1> > tmp_36_fu_466_p3;
    sc_signal< sc_lv<1> > tmp_36_reg_1016;
    sc_signal< sc_logic > ap_CS_fsm_pp0_stage0;
    sc_signal< bool > ap_block_state2_pp0_stage0_iter0;
    sc_signal< bool > ap_block_state3_pp0_stage0_iter1;
    sc_signal< bool > ap_block_pp0_stage0_11001;
    sc_signal< sc_lv<64> > zext_ln174_fu_478_p1;
    sc_signal< sc_lv<64> > zext_ln174_reg_1020;
    sc_signal< sc_lv<64> > zext_ln174_1_fu_489_p1;
    sc_signal< sc_lv<64> > zext_ln174_1_reg_1030;
    sc_signal< sc_lv<3> > add_ln171_fu_494_p2;
    sc_signal< sc_logic > ap_enable_reg_pp0_iter0;
    sc_signal< sc_lv<3> > output_addr_6_reg_1048;
    sc_signal< sc_logic > ap_CS_fsm_state6;
    sc_signal< sc_lv<1> > icmp_ln110_1_fu_500_p2;
    sc_signal< sc_lv<3> > output_addr_7_reg_1058;
    sc_signal< sc_lv<3> > add_ln110_1_fu_528_p2;
    sc_signal< sc_lv<3> > add_ln110_1_reg_1068;
    sc_signal< sc_lv<14> > shl_ln_fu_540_p3;
    sc_signal< sc_lv<14> > shl_ln_reg_1096;
    sc_signal< sc_logic > ap_CS_fsm_state9;
    sc_signal< sc_lv<8> > trunc_ln1_reg_1102;
    sc_signal< sc_lv<8> > trunc_ln2_reg_1107;
    sc_signal< sc_lv<7> > temp_addr_11_reg_1115;
    sc_signal< sc_logic > ap_CS_fsm_state11;
    sc_signal< sc_lv<1> > icmp_ln209_fu_585_p2;
    sc_signal< sc_lv<3> > trunc_ln209_fu_612_p1;
    sc_signal< sc_lv<3> > trunc_ln209_reg_1121;
    sc_signal< sc_lv<7> > temp_addr_12_reg_1128;
    sc_signal< sc_lv<7> > temp_addr_13_reg_1134;
    sc_signal< sc_lv<5> > add_ln209_fu_652_p2;
    sc_signal< sc_lv<5> > add_ln209_reg_1140;
    sc_signal< sc_lv<1> > a_fu_673_p1;
    sc_signal< sc_lv<1> > a_reg_1145;
    sc_signal< sc_logic > ap_CS_fsm_state13;
    sc_signal< sc_lv<8> > zext_ln55_3_fu_682_p1;
    sc_signal< sc_lv<8> > zext_ln55_3_reg_1152;
    sc_signal< sc_lv<1> > b_fu_692_p1;
    sc_signal< sc_lv<1> > b_reg_1158;
    sc_signal< sc_lv<8> > zext_ln55_5_fu_701_p1;
    sc_signal< sc_lv<8> > zext_ln55_5_reg_1164;
    sc_signal< sc_lv<1> > c_fu_711_p1;
    sc_signal< sc_lv<1> > c_reg_1170;
    sc_signal< sc_lv<1> > xor_ln223_fu_766_p2;
    sc_signal< sc_lv<1> > xor_ln223_reg_1176;
    sc_signal< sc_logic > ap_CS_fsm_state15;
    sc_signal< sc_lv<8> > temp_q1;
    sc_signal< sc_lv<8> > temp_load_1_reg_1181;
    sc_signal< sc_lv<14> > add_ln243_fu_868_p2;
    sc_signal< sc_lv<14> > add_ln243_reg_1186;
    sc_signal< sc_logic > ap_CS_fsm_state20;
    sc_signal< sc_lv<7> > add_ln244_fu_882_p2;
    sc_signal< sc_lv<7> > add_ln244_reg_1191;
    sc_signal< sc_logic > ap_CS_fsm_state21;
    sc_signal< sc_logic > grp_matrix_mul_fu_428_ap_ready;
    sc_signal< sc_logic > grp_matrix_mul_fu_428_ap_done;
    sc_signal< sc_lv<3> > output_addr_4_reg_1200;
    sc_signal< sc_logic > ap_CS_fsm_state22;
    sc_signal< sc_lv<1> > icmp_ln110_fu_888_p2;
    sc_signal< sc_lv<3> > output_addr_5_reg_1210;
    sc_signal< sc_lv<3> > add_ln110_fu_950_p2;
    sc_signal< sc_lv<3> > add_ln110_reg_1220;
    sc_signal< sc_lv<3> > output_addr_8_reg_1228;
    sc_signal< sc_logic > ap_CS_fsm_state24;
    sc_signal< sc_lv<1> > icmp_ln110_2_fu_970_p2;
    sc_signal< sc_lv<3> > output_addr_9_reg_1238;
    sc_signal< sc_lv<3> > add_ln110_2_fu_998_p2;
    sc_signal< sc_lv<3> > add_ln110_2_reg_1248;
    sc_signal< sc_lv<5> > r_fu_1004_p2;
    sc_signal< bool > ap_block_pp0_stage0_subdone;
    sc_signal< sc_logic > ap_condition_pp0_exit_iter0_state2;
    sc_signal< sc_logic > ap_enable_reg_pp0_iter1;
    sc_signal< sc_lv<4> > roundKey_address0;
    sc_signal< sc_logic > roundKey_ce0;
    sc_signal< sc_logic > roundKey_we0;
    sc_signal< sc_lv<32> > roundKey_q0;
    sc_signal< sc_lv<4> > roundKey_address1;
    sc_signal< sc_logic > roundKey_ce1;
    sc_signal< sc_logic > roundKey_we1;
    sc_signal< sc_lv<32> > roundKey_q1;
    sc_signal< sc_lv<7> > temp_address0;
    sc_signal< sc_logic > temp_ce0;
    sc_signal< sc_logic > temp_we0;
    sc_signal< sc_lv<8> > temp_d0;
    sc_signal< sc_lv<7> > temp_address1;
    sc_signal< sc_logic > temp_ce1;
    sc_signal< sc_logic > temp_we1;
    sc_signal< sc_lv<8> > temp_d1;
    sc_signal< sc_logic > grp_matrix_mul_fu_428_ap_start;
    sc_signal< sc_logic > grp_matrix_mul_fu_428_ap_idle;
    sc_signal< sc_lv<3> > grp_matrix_mul_fu_428_output_r_address0;
    sc_signal< sc_logic > grp_matrix_mul_fu_428_output_r_ce0;
    sc_signal< sc_logic > grp_matrix_mul_fu_428_output_r_we0;
    sc_signal< sc_lv<32> > grp_matrix_mul_fu_428_output_r_d0;
    sc_signal< sc_lv<3> > grp_matrix_mul_fu_428_output_r_address1;
    sc_signal< sc_logic > grp_matrix_mul_fu_428_output_r_ce1;
    sc_signal< sc_logic > grp_matrix_mul_fu_428_output_r_we1;
    sc_signal< sc_lv<32> > grp_matrix_mul_fu_428_output_r_d1;
    sc_signal< sc_logic > grp_matrix_mul_1_fu_437_ap_start;
    sc_signal< sc_logic > grp_matrix_mul_1_fu_437_ap_done;
    sc_signal< sc_logic > grp_matrix_mul_1_fu_437_ap_idle;
    sc_signal< sc_logic > grp_matrix_mul_1_fu_437_ap_ready;
    sc_signal< sc_lv<4> > grp_matrix_mul_1_fu_437_output_r_address0;
    sc_signal< sc_logic > grp_matrix_mul_1_fu_437_output_r_ce0;
    sc_signal< sc_logic > grp_matrix_mul_1_fu_437_output_r_we0;
    sc_signal< sc_lv<32> > grp_matrix_mul_1_fu_437_output_r_d0;
    sc_signal< sc_lv<4> > grp_matrix_mul_1_fu_437_output_r_address1;
    sc_signal< sc_logic > grp_matrix_mul_1_fu_437_output_r_ce1;
    sc_signal< sc_logic > grp_matrix_mul_1_fu_437_output_r_we1;
    sc_signal< sc_lv<32> > grp_matrix_mul_1_fu_437_output_r_d1;
    sc_signal< sc_lv<3> > grp_matrix_mul_1_fu_437_state_address0;
    sc_signal< sc_logic > grp_matrix_mul_1_fu_437_state_ce0;
    sc_signal< sc_lv<3> > grp_matrix_mul_1_fu_437_state_address1;
    sc_signal< sc_logic > grp_matrix_mul_1_fu_437_state_ce1;
    sc_signal< sc_lv<14> > grp_matrix_mul_1_fu_437_matrix_offset;
    sc_signal< sc_lv<3> > i_0_0_i1_reg_371;
    sc_signal< sc_logic > ap_CS_fsm_state5;
    sc_signal< sc_logic > ap_CS_fsm_state7;
    sc_signal< sc_lv<5> > r_0_reg_382;
    sc_signal< sc_lv<5> > bitNumber_assign_2_reg_394;
    sc_signal< sc_logic > ap_CS_fsm_state10;
    sc_signal< sc_logic > ap_CS_fsm_state17;
    sc_signal< sc_lv<3> > i_0_0_i_reg_406;
    sc_signal< sc_logic > ap_CS_fsm_state23;
    sc_signal< sc_lv<3> > i_0_0_i2_reg_417;
    sc_signal< sc_logic > ap_CS_fsm_state25;
    sc_signal< sc_logic > grp_matrix_mul_fu_428_ap_start_reg;
    sc_signal< sc_logic > grp_matrix_mul_1_fu_437_ap_start_reg;
    sc_signal< sc_logic > ap_CS_fsm_state4;
    sc_signal< bool > ap_block_pp0_stage0;
    sc_signal< sc_lv<64> > zext_ln114_1_fu_506_p1;
    sc_signal< sc_lv<64> > zext_ln114_3_fu_522_p1;
    sc_signal< sc_lv<64> > zext_ln55_fu_607_p1;
    sc_signal< sc_lv<64> > zext_ln55_2_fu_632_p1;
    sc_signal< sc_lv<64> > zext_ln55_4_fu_647_p1;
    sc_signal< sc_lv<64> > zext_ln114_fu_894_p1;
    sc_signal< sc_lv<64> > zext_ln114_5_fu_908_p1;
    sc_signal< sc_lv<64> > zext_ln114_2_fu_923_p1;
    sc_signal< sc_lv<64> > zext_ln114_6_fu_945_p1;
    sc_signal< sc_lv<64> > zext_ln114_7_fu_976_p1;
    sc_signal< sc_lv<64> > zext_ln114_8_fu_992_p1;
    sc_signal< sc_lv<32> > grp_fu_448_p2;
    sc_signal< sc_lv<32> > grp_fu_455_p2;
    sc_signal< sc_logic > ap_CS_fsm_state8;
    sc_signal< sc_logic > ap_CS_fsm_state19;
    sc_signal< sc_lv<32> > or_ln239_2_fu_856_p5;
    sc_signal< sc_lv<32> > xor_ln114_fu_956_p2;
    sc_signal< sc_lv<32> > xor_ln114_2_fu_963_p2;
    sc_signal< sc_lv<8> > trunc_ln194_fu_549_p1;
    sc_signal< sc_lv<8> > or_ln68_fu_755_p2;
    sc_signal< sc_logic > ap_CS_fsm_state14;
    sc_signal< sc_lv<8> > or_ln68_1_fu_802_p2;
    sc_signal< sc_logic > ap_CS_fsm_state16;
    sc_signal< sc_lv<8> > or_ln68_2_fu_849_p2;
    sc_signal< sc_lv<2> > trunc_ln171_fu_474_p1;
    sc_signal< sc_lv<2> > or_ln171_fu_483_p2;
    sc_signal< sc_lv<2> > trunc_ln110_fu_512_p1;
    sc_signal< sc_lv<2> > or_ln110_1_fu_516_p2;
    sc_signal< sc_lv<5> > add_ln218_fu_591_p2;
    sc_signal< sc_lv<2> > lshr_ln_fu_597_p4;
    sc_signal< sc_lv<5> > add_ln219_fu_616_p2;
    sc_signal< sc_lv<2> > lshr_ln55_2_fu_622_p4;
    sc_signal< sc_lv<2> > lshr_ln55_4_fu_637_p4;
    sc_signal< sc_lv<3> > sub_ln55_fu_658_p2;
    sc_signal< sc_lv<8> > zext_ln55_1_fu_663_p1;
    sc_signal< sc_lv<8> > lshr_ln55_fu_667_p2;
    sc_signal< sc_lv<3> > sub_ln55_1_fu_677_p2;
    sc_signal< sc_lv<8> > lshr_ln55_1_fu_686_p2;
    sc_signal< sc_lv<3> > xor_ln55_fu_696_p2;
    sc_signal< sc_lv<8> > lshr_ln55_3_fu_705_p2;
    sc_signal< sc_lv<1> > and_ln222_fu_715_p2;
    sc_signal< sc_lv<1> > xor_ln222_fu_721_p2;
    sc_signal< sc_lv<8> > shl_ln68_fu_731_p2;
    sc_signal< sc_lv<8> > zext_ln222_fu_727_p1;
    sc_signal< sc_lv<8> > xor_ln68_fu_737_p2;
    sc_signal< sc_lv<8> > and_ln68_fu_749_p2;
    sc_signal< sc_lv<8> > shl_ln68_3_fu_743_p2;
    sc_signal< sc_lv<1> > and_ln223_fu_762_p2;
    sc_signal< sc_lv<1> > xor_ln223_1_fu_770_p2;
    sc_signal< sc_lv<8> > shl_ln68_4_fu_780_p2;
    sc_signal< sc_lv<8> > zext_ln223_fu_776_p1;
    sc_signal< sc_lv<8> > xor_ln68_3_fu_785_p2;
    sc_signal< sc_lv<8> > and_ln68_1_fu_796_p2;
    sc_signal< sc_lv<8> > shl_ln68_5_fu_791_p2;
    sc_signal< sc_lv<1> > xor_ln224_fu_813_p2;
    sc_signal< sc_lv<1> > and_ln224_fu_809_p2;
    sc_signal< sc_lv<1> > xor_ln224_1_fu_817_p2;
    sc_signal< sc_lv<8> > shl_ln68_6_fu_827_p2;
    sc_signal< sc_lv<8> > zext_ln224_fu_823_p1;
    sc_signal< sc_lv<8> > xor_ln68_4_fu_832_p2;
    sc_signal< sc_lv<8> > and_ln68_2_fu_843_p2;
    sc_signal< sc_lv<8> > shl_ln68_7_fu_838_p2;
    sc_signal< sc_lv<7> > shl_ln1_fu_874_p3;
    sc_signal< sc_lv<7> > zext_ln114_4_fu_899_p1;
    sc_signal< sc_lv<7> > add_ln114_fu_903_p2;
    sc_signal< sc_lv<2> > trunc_ln110_1_fu_913_p1;
    sc_signal< sc_lv<2> > or_ln110_fu_917_p2;
    sc_signal< sc_lv<5> > tmp_3_fu_928_p4;
    sc_signal< sc_lv<7> > add_ln114_1_fu_937_p3;
    sc_signal< sc_lv<2> > trunc_ln110_2_fu_982_p1;
    sc_signal< sc_lv<2> > or_ln110_2_fu_986_p2;
    sc_signal< sc_lv<1> > icmp_ln188_fu_534_p2;
    sc_signal< sc_lv<24> > ap_NS_fsm;
    sc_signal< sc_logic > ap_idle_pp0;
    sc_signal< sc_logic > ap_enable_pp0;
    static const sc_logic ap_const_logic_1;
    static const sc_logic ap_const_logic_0;
    static const sc_lv<24> ap_ST_fsm_state1;
    static const sc_lv<24> ap_ST_fsm_pp0_stage0;
    static const sc_lv<24> ap_ST_fsm_state4;
    static const sc_lv<24> ap_ST_fsm_state5;
    static const sc_lv<24> ap_ST_fsm_state6;
    static const sc_lv<24> ap_ST_fsm_state7;
    static const sc_lv<24> ap_ST_fsm_state8;
    static const sc_lv<24> ap_ST_fsm_state9;
    static const sc_lv<24> ap_ST_fsm_state10;
    static const sc_lv<24> ap_ST_fsm_state11;
    static const sc_lv<24> ap_ST_fsm_state12;
    static const sc_lv<24> ap_ST_fsm_state13;
    static const sc_lv<24> ap_ST_fsm_state14;
    static const sc_lv<24> ap_ST_fsm_state15;
    static const sc_lv<24> ap_ST_fsm_state16;
    static const sc_lv<24> ap_ST_fsm_state17;
    static const sc_lv<24> ap_ST_fsm_state18;
    static const sc_lv<24> ap_ST_fsm_state19;
    static const sc_lv<24> ap_ST_fsm_state20;
    static const sc_lv<24> ap_ST_fsm_state21;
    static const sc_lv<24> ap_ST_fsm_state22;
    static const sc_lv<24> ap_ST_fsm_state23;
    static const sc_lv<24> ap_ST_fsm_state24;
    static const sc_lv<24> ap_ST_fsm_state25;
    static const bool ap_const_boolean_1;
    static const sc_lv<32> ap_const_lv32_0;
    static const sc_lv<32> ap_const_lv32_A;
    static const sc_lv<32> ap_const_lv32_10;
    static const sc_lv<32> ap_const_lv32_1;
    static const bool ap_const_boolean_0;
    static const sc_lv<1> ap_const_lv1_0;
    static const sc_lv<32> ap_const_lv32_4;
    static const sc_lv<1> ap_const_lv1_1;
    static const sc_lv<32> ap_const_lv32_7;
    static const sc_lv<32> ap_const_lv32_9;
    static const sc_lv<32> ap_const_lv32_B;
    static const sc_lv<32> ap_const_lv32_D;
    static const sc_lv<32> ap_const_lv32_12;
    static const sc_lv<32> ap_const_lv32_13;
    static const sc_lv<32> ap_const_lv32_14;
    static const sc_lv<32> ap_const_lv32_16;
    static const sc_lv<3> ap_const_lv3_0;
    static const sc_lv<32> ap_const_lv32_3;
    static const sc_lv<32> ap_const_lv32_5;
    static const sc_lv<5> ap_const_lv5_1;
    static const sc_lv<5> ap_const_lv5_0;
    static const sc_lv<32> ap_const_lv32_8;
    static const sc_lv<32> ap_const_lv32_F;
    static const sc_lv<32> ap_const_lv32_15;
    static const sc_lv<32> ap_const_lv32_17;
    static const sc_lv<32> ap_const_lv32_2;
    static const sc_lv<14> ap_const_lv14_0;
    static const sc_lv<64> ap_const_lv64_0;
    static const sc_lv<64> ap_const_lv64_1;
    static const sc_lv<64> ap_const_lv64_2;
    static const sc_lv<64> ap_const_lv64_3;
    static const sc_lv<32> ap_const_lv32_6;
    static const sc_lv<32> ap_const_lv32_11;
    static const sc_lv<32> ap_const_lv32_C;
    static const sc_lv<32> ap_const_lv32_E;
    static const sc_lv<2> ap_const_lv2_1;
    static const sc_lv<3> ap_const_lv3_2;
    static const sc_lv<3> ap_const_lv3_4;
    static const sc_lv<5> ap_const_lv5_15;
    static const sc_lv<9> ap_const_lv9_0;
    static const sc_lv<32> ap_const_lv32_18;
    static const sc_lv<32> ap_const_lv32_1F;
    static const sc_lv<5> ap_const_lv5_1E;
    static const sc_lv<5> ap_const_lv5_2;
    static const sc_lv<5> ap_const_lv5_3;
    static const sc_lv<3> ap_const_lv3_5;
    static const sc_lv<3> ap_const_lv3_6;
    static const sc_lv<3> ap_const_lv3_7;
    static const sc_lv<8> ap_const_lv8_1;
    static const sc_lv<8> ap_const_lv8_FF;
    static const sc_lv<14> ap_const_lv14_3E00;
    static const sc_lv<2> ap_const_lv2_0;
    static const sc_lv<7> ap_const_lv7_7C;
    // Thread declarations
    void thread_ap_clk_no_reset_();
    void thread_a_fu_673_p1();
    void thread_add_ln110_1_fu_528_p2();
    void thread_add_ln110_2_fu_998_p2();
    void thread_add_ln110_fu_950_p2();
    void thread_add_ln114_1_fu_937_p3();
    void thread_add_ln114_fu_903_p2();
    void thread_add_ln171_fu_494_p2();
    void thread_add_ln209_fu_652_p2();
    void thread_add_ln218_fu_591_p2();
    void thread_add_ln219_fu_616_p2();
    void thread_add_ln243_fu_868_p2();
    void thread_add_ln244_fu_882_p2();
    void thread_and_ln222_fu_715_p2();
    void thread_and_ln223_fu_762_p2();
    void thread_and_ln224_fu_809_p2();
    void thread_and_ln68_1_fu_796_p2();
    void thread_and_ln68_2_fu_843_p2();
    void thread_and_ln68_fu_749_p2();
    void thread_ap_CS_fsm_pp0_stage0();
    void thread_ap_CS_fsm_state1();
    void thread_ap_CS_fsm_state10();
    void thread_ap_CS_fsm_state11();
    void thread_ap_CS_fsm_state12();
    void thread_ap_CS_fsm_state13();
    void thread_ap_CS_fsm_state14();
    void thread_ap_CS_fsm_state15();
    void thread_ap_CS_fsm_state16();
    void thread_ap_CS_fsm_state17();
    void thread_ap_CS_fsm_state18();
    void thread_ap_CS_fsm_state19();
    void thread_ap_CS_fsm_state20();
    void thread_ap_CS_fsm_state21();
    void thread_ap_CS_fsm_state22();
    void thread_ap_CS_fsm_state23();
    void thread_ap_CS_fsm_state24();
    void thread_ap_CS_fsm_state25();
    void thread_ap_CS_fsm_state4();
    void thread_ap_CS_fsm_state5();
    void thread_ap_CS_fsm_state6();
    void thread_ap_CS_fsm_state7();
    void thread_ap_CS_fsm_state8();
    void thread_ap_CS_fsm_state9();
    void thread_ap_block_pp0_stage0();
    void thread_ap_block_pp0_stage0_11001();
    void thread_ap_block_pp0_stage0_subdone();
    void thread_ap_block_state2_pp0_stage0_iter0();
    void thread_ap_block_state3_pp0_stage0_iter1();
    void thread_ap_condition_pp0_exit_iter0_state2();
    void thread_ap_done();
    void thread_ap_enable_pp0();
    void thread_ap_idle();
    void thread_ap_idle_pp0();
    void thread_ap_ready();
    void thread_b_fu_692_p1();
    void thread_c_fu_711_p1();
    void thread_grp_fu_448_p2();
    void thread_grp_fu_455_p2();
    void thread_grp_matrix_mul_1_fu_437_ap_start();
    void thread_grp_matrix_mul_1_fu_437_matrix_offset();
    void thread_grp_matrix_mul_fu_428_ap_start();
    void thread_icmp_ln110_1_fu_500_p2();
    void thread_icmp_ln110_2_fu_970_p2();
    void thread_icmp_ln110_fu_888_p2();
    void thread_icmp_ln188_fu_534_p2();
    void thread_icmp_ln209_fu_585_p2();
    void thread_key_address0();
    void thread_key_address1();
    void thread_key_ce0();
    void thread_key_ce1();
    void thread_lshr_ln55_1_fu_686_p2();
    void thread_lshr_ln55_2_fu_622_p4();
    void thread_lshr_ln55_3_fu_705_p2();
    void thread_lshr_ln55_4_fu_637_p4();
    void thread_lshr_ln55_fu_667_p2();
    void thread_lshr_ln_fu_597_p4();
    void thread_or_ln110_1_fu_516_p2();
    void thread_or_ln110_2_fu_986_p2();
    void thread_or_ln110_fu_917_p2();
    void thread_or_ln171_fu_483_p2();
    void thread_or_ln239_2_fu_856_p5();
    void thread_or_ln68_1_fu_802_p2();
    void thread_or_ln68_2_fu_849_p2();
    void thread_or_ln68_fu_755_p2();
    void thread_output_r_address0();
    void thread_output_r_address1();
    void thread_output_r_ce0();
    void thread_output_r_ce1();
    void thread_output_r_d0();
    void thread_output_r_d1();
    void thread_output_r_we0();
    void thread_output_r_we1();
    void thread_plaintext_address0();
    void thread_plaintext_address1();
    void thread_plaintext_ce0();
    void thread_plaintext_ce1();
    void thread_r_fu_1004_p2();
    void thread_roundKey_address0();
    void thread_roundKey_address1();
    void thread_roundKey_ce0();
    void thread_roundKey_ce1();
    void thread_roundKey_we0();
    void thread_roundKey_we1();
    void thread_shl_ln1_fu_874_p3();
    void thread_shl_ln68_3_fu_743_p2();
    void thread_shl_ln68_4_fu_780_p2();
    void thread_shl_ln68_5_fu_791_p2();
    void thread_shl_ln68_6_fu_827_p2();
    void thread_shl_ln68_7_fu_838_p2();
    void thread_shl_ln68_fu_731_p2();
    void thread_shl_ln_fu_540_p3();
    void thread_sub_ln55_1_fu_677_p2();
    void thread_sub_ln55_fu_658_p2();
    void thread_temp_address0();
    void thread_temp_address1();
    void thread_temp_ce0();
    void thread_temp_ce1();
    void thread_temp_d0();
    void thread_temp_d1();
    void thread_temp_matrix3_address0();
    void thread_temp_matrix3_address1();
    void thread_temp_matrix3_ce0();
    void thread_temp_matrix3_ce1();
    void thread_temp_we0();
    void thread_temp_we1();
    void thread_tmp_36_fu_466_p3();
    void thread_tmp_3_fu_928_p4();
    void thread_trunc_ln110_1_fu_913_p1();
    void thread_trunc_ln110_2_fu_982_p1();
    void thread_trunc_ln110_fu_512_p1();
    void thread_trunc_ln171_fu_474_p1();
    void thread_trunc_ln194_fu_549_p1();
    void thread_trunc_ln209_fu_612_p1();
    void thread_xor_ln114_2_fu_963_p2();
    void thread_xor_ln114_fu_956_p2();
    void thread_xor_ln222_fu_721_p2();
    void thread_xor_ln223_1_fu_770_p2();
    void thread_xor_ln223_fu_766_p2();
    void thread_xor_ln224_1_fu_817_p2();
    void thread_xor_ln224_fu_813_p2();
    void thread_xor_ln55_fu_696_p2();
    void thread_xor_ln68_3_fu_785_p2();
    void thread_xor_ln68_4_fu_832_p2();
    void thread_xor_ln68_fu_737_p2();
    void thread_zext_ln114_1_fu_506_p1();
    void thread_zext_ln114_2_fu_923_p1();
    void thread_zext_ln114_3_fu_522_p1();
    void thread_zext_ln114_4_fu_899_p1();
    void thread_zext_ln114_5_fu_908_p1();
    void thread_zext_ln114_6_fu_945_p1();
    void thread_zext_ln114_7_fu_976_p1();
    void thread_zext_ln114_8_fu_992_p1();
    void thread_zext_ln114_fu_894_p1();
    void thread_zext_ln174_1_fu_489_p1();
    void thread_zext_ln174_fu_478_p1();
    void thread_zext_ln222_fu_727_p1();
    void thread_zext_ln223_fu_776_p1();
    void thread_zext_ln224_fu_823_p1();
    void thread_zext_ln55_1_fu_663_p1();
    void thread_zext_ln55_2_fu_632_p1();
    void thread_zext_ln55_3_fu_682_p1();
    void thread_zext_ln55_4_fu_647_p1();
    void thread_zext_ln55_5_fu_701_p1();
    void thread_zext_ln55_fu_607_p1();
    void thread_ap_NS_fsm();
};

}

using namespace ap_rtl;

#endif