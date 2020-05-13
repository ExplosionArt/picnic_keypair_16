// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and OpenCL
// Version: 2019.2
// Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#ifndef _matrix_mul_HH_
#define _matrix_mul_HH_

#include "systemc.h"
#include "AESL_pkg.h"

#include "matrix_mul_temp_mfYi.h"
#include "matrix_mul_1_prod.h"
#include "matrix_mul_1_temp.h"

namespace ap_rtl {

struct matrix_mul : public sc_module {
    // Port declarations 12
    sc_in_clk ap_clk;
    sc_in< sc_logic > ap_rst;
    sc_in< sc_logic > ap_start;
    sc_out< sc_logic > ap_done;
    sc_out< sc_logic > ap_idle;
    sc_out< sc_logic > ap_ready;
    sc_out< sc_lv<3> > output_r_address0;
    sc_out< sc_logic > output_r_ce0;
    sc_out< sc_logic > output_r_we0;
    sc_out< sc_lv<32> > output_r_d0;
    sc_in< sc_lv<32> > output_r_q0;
    sc_in< sc_lv<14> > matrix_offset;


    // Module declarations
    matrix_mul(sc_module_name name);
    SC_HAS_PROCESS(matrix_mul);

    ~matrix_mul();

    sc_trace_file* mVcdFile;

    matrix_mul_temp_mfYi* temp_matrix2_U;
    matrix_mul_1_prod* prod_U;
    matrix_mul_1_temp* temp_U;
    sc_signal< sc_lv<11> > ap_CS_fsm;
    sc_signal< sc_logic > ap_CS_fsm_state1;
    sc_signal< sc_lv<14> > temp_matrix2_address0;
    sc_signal< sc_logic > temp_matrix2_ce0;
    sc_signal< sc_lv<32> > temp_matrix2_q0;
    sc_signal< sc_lv<3> > trunc_ln128_fu_258_p1;
    sc_signal< sc_lv<3> > trunc_ln128_reg_889;
    sc_signal< sc_logic > ap_CS_fsm_state2;
    sc_signal< sc_lv<8> > i_fu_268_p2;
    sc_signal< sc_lv<8> > i_reg_897;
    sc_signal< sc_lv<9> > shl_ln_fu_278_p3;
    sc_signal< sc_lv<9> > shl_ln_reg_902;
    sc_signal< sc_lv<1> > icmp_ln128_fu_262_p2;
    sc_signal< sc_lv<3> > j_fu_296_p2;
    sc_signal< sc_lv<3> > j_reg_910;
    sc_signal< sc_logic > ap_CS_fsm_state3;
    sc_signal< sc_lv<64> > zext_ln134_fu_311_p1;
    sc_signal< sc_lv<64> > zext_ln134_reg_915;
    sc_signal< sc_lv<1> > icmp_ln130_fu_290_p2;
    sc_signal< sc_lv<32> > prod_q0;
    sc_signal< sc_logic > ap_CS_fsm_state5;
    sc_signal< sc_logic > ap_CS_fsm_state6;
    sc_signal< sc_lv<1> > icmp_ln87_fu_338_p2;
    sc_signal< sc_lv<3> > i_6_fu_344_p2;
    sc_signal< sc_lv<3> > i_6_reg_943;
    sc_signal< sc_lv<2> > tmp_16_reg_948;
    sc_signal< sc_lv<6> > temp_addr_5_reg_954;
    sc_signal< sc_lv<32> > x_2_fu_375_p2;
    sc_signal< sc_logic > ap_CS_fsm_state7;
    sc_signal< sc_lv<5> > zext_ln68_cast_fu_587_p3;
    sc_signal< sc_lv<5> > zext_ln68_cast_reg_964;
    sc_signal< sc_logic > ap_CS_fsm_state8;
    sc_signal< sc_lv<6> > add_ln68_fu_602_p2;
    sc_signal< sc_lv<6> > add_ln68_reg_969;
    sc_signal< sc_lv<8> > or_ln68_fu_743_p2;
    sc_signal< sc_lv<8> > or_ln68_reg_975;
    sc_signal< sc_lv<1> > icmp_ln68_2_fu_749_p2;
    sc_signal< sc_lv<1> > icmp_ln68_2_reg_980;
    sc_signal< sc_lv<3> > loop_fu_868_p2;
    sc_signal< sc_lv<3> > loop_reg_991;
    sc_signal< sc_logic > ap_CS_fsm_state10;
    sc_signal< sc_lv<64> > zext_ln141_fu_874_p1;
    sc_signal< sc_lv<64> > zext_ln141_reg_996;
    sc_signal< sc_lv<1> > icmp_ln140_fu_862_p2;
    sc_signal< sc_lv<6> > prod_address0;
    sc_signal< sc_logic > prod_ce0;
    sc_signal< sc_logic > prod_we0;
    sc_signal< sc_lv<32> > prod_d0;
    sc_signal< sc_lv<6> > temp_address0;
    sc_signal< sc_logic > temp_ce0;
    sc_signal< sc_lv<4> > temp_we0;
    sc_signal< sc_lv<32> > temp_d0;
    sc_signal< sc_lv<32> > temp_q0;
    sc_signal< sc_lv<8> > bitNumber_assign_reg_203;
    sc_signal< sc_logic > ap_CS_fsm_state9;
    sc_signal< sc_lv<3> > j_0_reg_215;
    sc_signal< sc_logic > ap_CS_fsm_state4;
    sc_signal< sc_lv<32> > x_0_i_reg_226;
    sc_signal< sc_lv<3> > i_0_i_reg_236;
    sc_signal< sc_lv<3> > loop_0_reg_247;
    sc_signal< sc_logic > ap_CS_fsm_state11;
    sc_signal< sc_lv<64> > zext_ln134_2_fu_321_p1;
    sc_signal< sc_lv<64> > zext_ln87_fu_333_p1;
    sc_signal< sc_lv<64> > zext_ln68_15_fu_370_p1;
    sc_signal< sc_lv<4> > shl_ln68_7_fu_855_p2;
    sc_signal< sc_lv<7> > trunc_ln133_fu_274_p1;
    sc_signal< sc_lv<9> > zext_ln130_fu_286_p1;
    sc_signal< sc_lv<9> > add_ln133_fu_302_p2;
    sc_signal< sc_lv<14> > zext_ln133_fu_307_p1;
    sc_signal< sc_lv<14> > add_ln134_fu_316_p2;
    sc_signal< sc_lv<2> > tmp_17_fu_360_p4;
    sc_signal< sc_lv<31> > lshr_ln_fu_381_p4;
    sc_signal< sc_lv<32> > zext_ln96_fu_391_p1;
    sc_signal< sc_lv<32> > y_fu_421_p2;
    sc_signal< sc_lv<30> > lshr_ln5_fu_427_p4;
    sc_signal< sc_lv<24> > trunc_ln96_6_fu_411_p4;
    sc_signal< sc_lv<24> > trunc_ln96_2_fu_407_p1;
    sc_signal< sc_lv<32> > zext_ln97_fu_437_p1;
    sc_signal< sc_lv<32> > y_4_fu_465_p2;
    sc_signal< sc_lv<28> > lshr_ln6_fu_471_p4;
    sc_signal< sc_lv<24> > trunc_ln97_2_fu_455_p4;
    sc_signal< sc_lv<24> > xor_ln97_fu_449_p2;
    sc_signal< sc_lv<32> > zext_ln98_fu_481_p1;
    sc_signal< sc_lv<24> > trunc_ln98_2_fu_499_p4;
    sc_signal< sc_lv<24> > xor_ln98_fu_493_p2;
    sc_signal< sc_lv<32> > y_5_fu_509_p2;
    sc_signal< sc_lv<24> > trunc_ln_fu_521_p4;
    sc_signal< sc_lv<24> > xor_ln98_4_fu_515_p2;
    sc_signal< sc_lv<24> > y_6_fu_539_p2;
    sc_signal< sc_lv<1> > trunc_ln96_fu_395_p1;
    sc_signal< sc_lv<1> > tmp_12_fu_441_p3;
    sc_signal< sc_lv<1> > xor_ln101_fu_553_p2;
    sc_signal< sc_lv<1> > tmp_11_fu_399_p3;
    sc_signal< sc_lv<1> > tmp_14_fu_531_p3;
    sc_signal< sc_lv<1> > tmp_15_fu_545_p3;
    sc_signal< sc_lv<1> > xor_ln101_6_fu_565_p2;
    sc_signal< sc_lv<1> > tmp_13_fu_485_p3;
    sc_signal< sc_lv<1> > xor_ln101_7_fu_571_p2;
    sc_signal< sc_lv<1> > xor_ln101_5_fu_559_p2;
    sc_signal< sc_lv<1> > xor_ln101_8_fu_577_p2;
    sc_signal< sc_lv<6> > zext_ln68_fu_594_p1;
    sc_signal< sc_lv<64> > zext_ln68_14_fu_598_p1;
    sc_signal< sc_lv<64> > zext_ln68_16_fu_608_p1;
    sc_signal< sc_lv<6> > zext_ln68_17_fu_618_p1;
    sc_signal< sc_lv<1> > icmp_ln68_fu_612_p2;
    sc_signal< sc_lv<6> > sub_ln68_fu_632_p2;
    sc_signal< sc_lv<6> > sub_ln68_4_fu_644_p2;
    sc_signal< sc_lv<32> > tmp_18_fu_622_p4;
    sc_signal< sc_lv<6> > xor_ln68_4_fu_638_p2;
    sc_signal< sc_lv<6> > select_ln68_fu_650_p3;
    sc_signal< sc_lv<6> > select_ln68_8_fu_666_p3;
    sc_signal< sc_lv<6> > sub_ln68_5_fu_674_p2;
    sc_signal< sc_lv<32> > select_ln68_7_fu_658_p3;
    sc_signal< sc_lv<32> > zext_ln68_18_fu_680_p1;
    sc_signal< sc_lv<32> > zext_ln68_19_fu_684_p1;
    sc_signal< sc_lv<32> > lshr_ln68_fu_688_p2;
    sc_signal< sc_lv<32> > lshr_ln68_3_fu_694_p2;
    sc_signal< sc_lv<32> > and_ln68_4_fu_700_p2;
    sc_signal< sc_lv<3> > xor_ln68_fu_710_p2;
    sc_signal< sc_lv<8> > zext_ln68_2_fu_715_p1;
    sc_signal< sc_lv<8> > shl_ln68_fu_719_p2;
    sc_signal< sc_lv<8> > zext_ln101_fu_583_p1;
    sc_signal< sc_lv<8> > trunc_ln68_fu_706_p1;
    sc_signal< sc_lv<8> > xor_ln68_2_fu_725_p2;
    sc_signal< sc_lv<8> > and_ln68_fu_737_p2;
    sc_signal< sc_lv<8> > shl_ln68_2_fu_731_p2;
    sc_signal< sc_lv<6> > zext_ln68_20_fu_755_p1;
    sc_signal< sc_lv<6> > xor_ln68_5_fu_761_p2;
    sc_signal< sc_lv<6> > select_ln68_9_fu_767_p3;
    sc_signal< sc_lv<6> > select_ln68_11_fu_779_p3;
    sc_signal< sc_lv<6> > select_ln68_10_fu_773_p3;
    sc_signal< sc_lv<6> > sub_ln68_6_fu_786_p2;
    sc_signal< sc_lv<32> > zext_ln68_21_fu_758_p1;
    sc_signal< sc_lv<32> > zext_ln68_22_fu_792_p1;
    sc_signal< sc_lv<32> > shl_ln68_5_fu_804_p2;
    sc_signal< sc_lv<32> > tmp_19_fu_810_p4;
    sc_signal< sc_lv<32> > zext_ln68_23_fu_796_p1;
    sc_signal< sc_lv<32> > zext_ln68_24_fu_800_p1;
    sc_signal< sc_lv<32> > shl_ln68_6_fu_827_p2;
    sc_signal< sc_lv<32> > lshr_ln68_4_fu_833_p2;
    sc_signal< sc_lv<32> > select_ln68_12_fu_820_p3;
    sc_signal< sc_lv<32> > and_ln68_5_fu_839_p2;
    sc_signal< sc_lv<4> > zext_ln68_25_fu_852_p1;
    sc_signal< sc_lv<11> > ap_NS_fsm;
    static const sc_logic ap_const_logic_1;
    static const sc_logic ap_const_logic_0;
    static const sc_lv<11> ap_ST_fsm_state1;
    static const sc_lv<11> ap_ST_fsm_state2;
    static const sc_lv<11> ap_ST_fsm_state3;
    static const sc_lv<11> ap_ST_fsm_state4;
    static const sc_lv<11> ap_ST_fsm_state5;
    static const sc_lv<11> ap_ST_fsm_state6;
    static const sc_lv<11> ap_ST_fsm_state7;
    static const sc_lv<11> ap_ST_fsm_state8;
    static const sc_lv<11> ap_ST_fsm_state9;
    static const sc_lv<11> ap_ST_fsm_state10;
    static const sc_lv<11> ap_ST_fsm_state11;
    static const sc_lv<32> ap_const_lv32_0;
    static const sc_lv<32> ap_const_lv32_1;
    static const sc_lv<1> ap_const_lv1_0;
    static const sc_lv<32> ap_const_lv32_2;
    static const sc_lv<32> ap_const_lv32_4;
    static const sc_lv<32> ap_const_lv32_5;
    static const sc_lv<1> ap_const_lv1_1;
    static const sc_lv<32> ap_const_lv32_6;
    static const sc_lv<32> ap_const_lv32_7;
    static const sc_lv<32> ap_const_lv32_9;
    static const sc_lv<8> ap_const_lv8_0;
    static const sc_lv<32> ap_const_lv32_8;
    static const sc_lv<3> ap_const_lv3_0;
    static const sc_lv<32> ap_const_lv32_3;
    static const sc_lv<3> ap_const_lv3_1;
    static const sc_lv<32> ap_const_lv32_A;
    static const sc_lv<64> ap_const_lv64_0;
    static const sc_lv<4> ap_const_lv4_0;
    static const sc_lv<8> ap_const_lv8_80;
    static const sc_lv<8> ap_const_lv8_1;
    static const sc_lv<2> ap_const_lv2_0;
    static const sc_lv<3> ap_const_lv3_4;
    static const sc_lv<32> ap_const_lv32_1F;
    static const sc_lv<32> ap_const_lv32_18;
    static const sc_lv<32> ap_const_lv32_19;
    static const sc_lv<32> ap_const_lv32_1B;
    static const sc_lv<32> ap_const_lv32_10;
    static const sc_lv<6> ap_const_lv6_7;
    static const sc_lv<6> ap_const_lv6_1F;
    static const sc_lv<32> ap_const_lv32_FFFFFFFF;
    static const sc_lv<3> ap_const_lv3_7;
    static const sc_lv<8> ap_const_lv8_FF;
    static const sc_lv<4> ap_const_lv4_1;
    static const bool ap_const_boolean_1;
    // Thread declarations
    void thread_ap_clk_no_reset_();
    void thread_add_ln133_fu_302_p2();
    void thread_add_ln134_fu_316_p2();
    void thread_add_ln68_fu_602_p2();
    void thread_and_ln68_4_fu_700_p2();
    void thread_and_ln68_5_fu_839_p2();
    void thread_and_ln68_fu_737_p2();
    void thread_ap_CS_fsm_state1();
    void thread_ap_CS_fsm_state10();
    void thread_ap_CS_fsm_state11();
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
    void thread_i_6_fu_344_p2();
    void thread_i_fu_268_p2();
    void thread_icmp_ln128_fu_262_p2();
    void thread_icmp_ln130_fu_290_p2();
    void thread_icmp_ln140_fu_862_p2();
    void thread_icmp_ln68_2_fu_749_p2();
    void thread_icmp_ln68_fu_612_p2();
    void thread_icmp_ln87_fu_338_p2();
    void thread_j_fu_296_p2();
    void thread_loop_fu_868_p2();
    void thread_lshr_ln5_fu_427_p4();
    void thread_lshr_ln68_3_fu_694_p2();
    void thread_lshr_ln68_4_fu_833_p2();
    void thread_lshr_ln68_fu_688_p2();
    void thread_lshr_ln6_fu_471_p4();
    void thread_lshr_ln_fu_381_p4();
    void thread_or_ln68_fu_743_p2();
    void thread_output_r_address0();
    void thread_output_r_ce0();
    void thread_output_r_d0();
    void thread_output_r_we0();
    void thread_prod_address0();
    void thread_prod_ce0();
    void thread_prod_d0();
    void thread_prod_we0();
    void thread_select_ln68_10_fu_773_p3();
    void thread_select_ln68_11_fu_779_p3();
    void thread_select_ln68_12_fu_820_p3();
    void thread_select_ln68_7_fu_658_p3();
    void thread_select_ln68_8_fu_666_p3();
    void thread_select_ln68_9_fu_767_p3();
    void thread_select_ln68_fu_650_p3();
    void thread_shl_ln68_2_fu_731_p2();
    void thread_shl_ln68_5_fu_804_p2();
    void thread_shl_ln68_6_fu_827_p2();
    void thread_shl_ln68_7_fu_855_p2();
    void thread_shl_ln68_fu_719_p2();
    void thread_shl_ln_fu_278_p3();
    void thread_sub_ln68_4_fu_644_p2();
    void thread_sub_ln68_5_fu_674_p2();
    void thread_sub_ln68_6_fu_786_p2();
    void thread_sub_ln68_fu_632_p2();
    void thread_temp_address0();
    void thread_temp_ce0();
    void thread_temp_d0();
    void thread_temp_matrix2_address0();
    void thread_temp_matrix2_ce0();
    void thread_temp_we0();
    void thread_tmp_11_fu_399_p3();
    void thread_tmp_12_fu_441_p3();
    void thread_tmp_13_fu_485_p3();
    void thread_tmp_14_fu_531_p3();
    void thread_tmp_15_fu_545_p3();
    void thread_tmp_17_fu_360_p4();
    void thread_tmp_18_fu_622_p4();
    void thread_tmp_19_fu_810_p4();
    void thread_trunc_ln128_fu_258_p1();
    void thread_trunc_ln133_fu_274_p1();
    void thread_trunc_ln68_fu_706_p1();
    void thread_trunc_ln96_2_fu_407_p1();
    void thread_trunc_ln96_6_fu_411_p4();
    void thread_trunc_ln96_fu_395_p1();
    void thread_trunc_ln97_2_fu_455_p4();
    void thread_trunc_ln98_2_fu_499_p4();
    void thread_trunc_ln_fu_521_p4();
    void thread_x_2_fu_375_p2();
    void thread_xor_ln101_5_fu_559_p2();
    void thread_xor_ln101_6_fu_565_p2();
    void thread_xor_ln101_7_fu_571_p2();
    void thread_xor_ln101_8_fu_577_p2();
    void thread_xor_ln101_fu_553_p2();
    void thread_xor_ln68_2_fu_725_p2();
    void thread_xor_ln68_4_fu_638_p2();
    void thread_xor_ln68_5_fu_761_p2();
    void thread_xor_ln68_fu_710_p2();
    void thread_xor_ln97_fu_449_p2();
    void thread_xor_ln98_4_fu_515_p2();
    void thread_xor_ln98_fu_493_p2();
    void thread_y_4_fu_465_p2();
    void thread_y_5_fu_509_p2();
    void thread_y_6_fu_539_p2();
    void thread_y_fu_421_p2();
    void thread_zext_ln101_fu_583_p1();
    void thread_zext_ln130_fu_286_p1();
    void thread_zext_ln133_fu_307_p1();
    void thread_zext_ln134_2_fu_321_p1();
    void thread_zext_ln134_fu_311_p1();
    void thread_zext_ln141_fu_874_p1();
    void thread_zext_ln68_14_fu_598_p1();
    void thread_zext_ln68_15_fu_370_p1();
    void thread_zext_ln68_16_fu_608_p1();
    void thread_zext_ln68_17_fu_618_p1();
    void thread_zext_ln68_18_fu_680_p1();
    void thread_zext_ln68_19_fu_684_p1();
    void thread_zext_ln68_20_fu_755_p1();
    void thread_zext_ln68_21_fu_758_p1();
    void thread_zext_ln68_22_fu_792_p1();
    void thread_zext_ln68_23_fu_796_p1();
    void thread_zext_ln68_24_fu_800_p1();
    void thread_zext_ln68_25_fu_852_p1();
    void thread_zext_ln68_2_fu_715_p1();
    void thread_zext_ln68_cast_fu_587_p3();
    void thread_zext_ln68_fu_594_p1();
    void thread_zext_ln87_fu_333_p1();
    void thread_zext_ln96_fu_391_p1();
    void thread_zext_ln97_fu_437_p1();
    void thread_zext_ln98_fu_481_p1();
    void thread_ap_NS_fsm();
};

}

using namespace ap_rtl;

#endif