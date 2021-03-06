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
    // Port declarations 17
    sc_in_clk ap_clk;
    sc_in< sc_logic > ap_rst;
    sc_in< sc_logic > ap_start;
    sc_out< sc_logic > ap_done;
    sc_out< sc_logic > ap_idle;
    sc_out< sc_logic > ap_ready;
    sc_out< sc_lv<3> > plaintext_address0;
    sc_out< sc_logic > plaintext_ce0;
    sc_in< sc_lv<32> > plaintext_q0;
    sc_out< sc_lv<3> > output_r_address0;
    sc_out< sc_logic > output_r_ce0;
    sc_out< sc_logic > output_r_we0;
    sc_out< sc_lv<32> > output_r_d0;
    sc_in< sc_lv<32> > output_r_q0;
    sc_out< sc_lv<3> > key_address0;
    sc_out< sc_logic > key_ce0;
    sc_in< sc_lv<32> > key_q0;


    // Module declarations
    LowMCEnc(sc_module_name name);
    SC_HAS_PROCESS(LowMCEnc);

    ~LowMCEnc();

    sc_trace_file* mVcdFile;

    LowMCEnc_temp_matg8j* temp_matrix3_U;
    LowMCEnc_roundKey* roundKey_U;
    LowMCEnc_temp* temp_U;
    matrix_mul* grp_matrix_mul_fu_336;
    matrix_mul_1* grp_matrix_mul_1_fu_345;
    sc_signal< sc_lv<25> > ap_CS_fsm;
    sc_signal< sc_logic > ap_CS_fsm_state1;
    sc_signal< sc_lv<7> > temp_matrix3_address0;
    sc_signal< sc_logic > temp_matrix3_ce0;
    sc_signal< sc_lv<32> > temp_matrix3_q0;
    sc_signal< sc_lv<8> > temp_q0;
    sc_signal< sc_lv<8> > reg_363;
    sc_signal< sc_logic > ap_CS_fsm_state12;
    sc_signal< sc_logic > ap_CS_fsm_state18;
    sc_signal< sc_lv<3> > loop_fu_373_p2;
    sc_signal< sc_lv<3> > loop_reg_827;
    sc_signal< sc_logic > ap_CS_fsm_state2;
    sc_signal< sc_lv<64> > zext_ln170_fu_379_p1;
    sc_signal< sc_lv<64> > zext_ln170_reg_832;
    sc_signal< sc_lv<1> > icmp_ln169_fu_367_p2;
    sc_signal< sc_lv<3> > i_7_fu_390_p2;
    sc_signal< sc_lv<3> > i_7_reg_845;
    sc_signal< sc_logic > ap_CS_fsm_state5;
    sc_signal< sc_lv<3> > output_addr_2_reg_850;
    sc_signal< sc_lv<1> > icmp_ln111_fu_384_p2;
    sc_signal< sc_lv<14> > shl_ln_fu_408_p3;
    sc_signal< sc_lv<14> > shl_ln_reg_883;
    sc_signal< sc_logic > ap_CS_fsm_state7;
    sc_signal< sc_lv<1> > icmp_ln184_fu_402_p2;
    sc_signal< sc_lv<3> > loop_7_fu_423_p2;
    sc_signal< sc_lv<3> > loop_7_reg_892;
    sc_signal< sc_logic > ap_CS_fsm_state9;
    sc_signal< sc_lv<7> > temp_addr_8_reg_900;
    sc_signal< sc_logic > ap_CS_fsm_state11;
    sc_signal< sc_lv<1> > icmp_ln194_fu_454_p2;
    sc_signal< sc_lv<3> > trunc_ln194_fu_481_p1;
    sc_signal< sc_lv<3> > trunc_ln194_reg_906;
    sc_signal< sc_lv<7> > temp_addr_9_reg_913;
    sc_signal< sc_lv<7> > temp_addr_10_reg_919;
    sc_signal< sc_lv<5> > add_ln194_fu_521_p2;
    sc_signal< sc_lv<5> > add_ln194_reg_925;
    sc_signal< sc_lv<1> > a_fu_542_p1;
    sc_signal< sc_lv<1> > a_reg_930;
    sc_signal< sc_logic > ap_CS_fsm_state13;
    sc_signal< sc_lv<8> > zext_ln55_3_fu_551_p1;
    sc_signal< sc_lv<8> > zext_ln55_3_reg_937;
    sc_signal< sc_lv<1> > b_fu_561_p1;
    sc_signal< sc_lv<1> > b_reg_943;
    sc_signal< sc_lv<8> > zext_ln55_5_fu_570_p1;
    sc_signal< sc_lv<8> > zext_ln55_5_reg_949;
    sc_signal< sc_lv<1> > c_fu_580_p1;
    sc_signal< sc_lv<1> > c_reg_955;
    sc_signal< sc_lv<1> > xor_ln205_fu_635_p2;
    sc_signal< sc_lv<1> > xor_ln205_reg_961;
    sc_signal< sc_logic > ap_CS_fsm_state15;
    sc_signal< sc_lv<8> > temp_q1;
    sc_signal< sc_lv<8> > temp_load_2_reg_966;
    sc_signal< sc_lv<14> > add_ln225_fu_737_p2;
    sc_signal< sc_lv<14> > add_ln225_reg_971;
    sc_signal< sc_logic > ap_CS_fsm_state20;
    sc_signal< sc_lv<7> > add_ln226_fu_751_p2;
    sc_signal< sc_lv<7> > add_ln226_reg_976;
    sc_signal< sc_logic > ap_CS_fsm_state21;
    sc_signal< sc_logic > grp_matrix_mul_fu_336_ap_ready;
    sc_signal< sc_logic > grp_matrix_mul_fu_336_ap_done;
    sc_signal< sc_lv<3> > i_fu_763_p2;
    sc_signal< sc_lv<3> > i_reg_984;
    sc_signal< sc_logic > ap_CS_fsm_state22;
    sc_signal< sc_lv<3> > output_addr_3_reg_989;
    sc_signal< sc_lv<1> > icmp_ln111_1_fu_757_p2;
    sc_signal< sc_lv<3> > i_8_fu_801_p2;
    sc_signal< sc_lv<3> > i_8_reg_1002;
    sc_signal< sc_logic > ap_CS_fsm_state24;
    sc_signal< sc_lv<3> > output_addr_4_reg_1007;
    sc_signal< sc_lv<1> > icmp_ln111_2_fu_795_p2;
    sc_signal< sc_lv<5> > r_fu_813_p2;
    sc_signal< sc_lv<4> > roundKey_address0;
    sc_signal< sc_logic > roundKey_ce0;
    sc_signal< sc_logic > roundKey_we0;
    sc_signal< sc_lv<32> > roundKey_q0;
    sc_signal< sc_lv<7> > temp_address0;
    sc_signal< sc_logic > temp_ce0;
    sc_signal< sc_logic > temp_we0;
    sc_signal< sc_lv<8> > temp_d0;
    sc_signal< sc_lv<7> > temp_address1;
    sc_signal< sc_logic > temp_ce1;
    sc_signal< sc_logic > temp_we1;
    sc_signal< sc_lv<8> > temp_d1;
    sc_signal< sc_logic > grp_matrix_mul_fu_336_ap_start;
    sc_signal< sc_logic > grp_matrix_mul_fu_336_ap_idle;
    sc_signal< sc_lv<3> > grp_matrix_mul_fu_336_output_r_address0;
    sc_signal< sc_logic > grp_matrix_mul_fu_336_output_r_ce0;
    sc_signal< sc_logic > grp_matrix_mul_fu_336_output_r_we0;
    sc_signal< sc_lv<32> > grp_matrix_mul_fu_336_output_r_d0;
    sc_signal< sc_logic > grp_matrix_mul_1_fu_345_ap_start;
    sc_signal< sc_logic > grp_matrix_mul_1_fu_345_ap_done;
    sc_signal< sc_logic > grp_matrix_mul_1_fu_345_ap_idle;
    sc_signal< sc_logic > grp_matrix_mul_1_fu_345_ap_ready;
    sc_signal< sc_lv<4> > grp_matrix_mul_1_fu_345_output_r_address0;
    sc_signal< sc_logic > grp_matrix_mul_1_fu_345_output_r_ce0;
    sc_signal< sc_logic > grp_matrix_mul_1_fu_345_output_r_we0;
    sc_signal< sc_lv<32> > grp_matrix_mul_1_fu_345_output_r_d0;
    sc_signal< sc_lv<3> > grp_matrix_mul_1_fu_345_state_address0;
    sc_signal< sc_logic > grp_matrix_mul_1_fu_345_state_ce0;
    sc_signal< sc_lv<14> > grp_matrix_mul_1_fu_345_matrix_offset;
    sc_signal< sc_lv<3> > loop_0_reg_256;
    sc_signal< sc_logic > ap_CS_fsm_state3;
    sc_signal< sc_lv<3> > i_0_i_reg_267;
    sc_signal< sc_logic > ap_CS_fsm_state4;
    sc_signal< sc_logic > ap_CS_fsm_state6;
    sc_signal< sc_lv<5> > r_0_reg_278;
    sc_signal< sc_lv<3> > loop_1_reg_290;
    sc_signal< sc_logic > ap_CS_fsm_state8;
    sc_signal< sc_logic > ap_CS_fsm_state10;
    sc_signal< sc_lv<5> > bitNumber_assign_2_reg_302;
    sc_signal< sc_logic > ap_CS_fsm_state17;
    sc_signal< sc_lv<1> > icmp_ln189_fu_417_p2;
    sc_signal< sc_lv<3> > i_0_i49_reg_314;
    sc_signal< sc_logic > ap_CS_fsm_state23;
    sc_signal< sc_lv<3> > i_0_i56_reg_325;
    sc_signal< sc_logic > ap_CS_fsm_state25;
    sc_signal< sc_logic > grp_matrix_mul_fu_336_ap_start_reg;
    sc_signal< sc_logic > grp_matrix_mul_1_fu_345_ap_start_reg;
    sc_signal< sc_lv<64> > zext_ln112_fu_396_p1;
    sc_signal< sc_lv<64> > zext_ln191_fu_434_p1;
    sc_signal< sc_lv<64> > zext_ln55_fu_476_p1;
    sc_signal< sc_lv<64> > zext_ln55_2_fu_501_p1;
    sc_signal< sc_lv<64> > zext_ln55_4_fu_516_p1;
    sc_signal< sc_lv<64> > zext_ln112_1_fu_769_p1;
    sc_signal< sc_lv<64> > zext_ln112_4_fu_783_p1;
    sc_signal< sc_lv<64> > zext_ln112_2_fu_807_p1;
    sc_signal< sc_lv<32> > grp_fu_356_p2;
    sc_signal< sc_lv<32> > zext_ln192_fu_449_p1;
    sc_signal< sc_logic > ap_CS_fsm_state19;
    sc_signal< sc_lv<32> > or_ln220_2_fu_725_p5;
    sc_signal< sc_lv<32> > xor_ln112_1_fu_788_p2;
    sc_signal< sc_lv<8> > trunc_ln191_fu_429_p1;
    sc_signal< sc_logic > ap_CS_fsm_state14;
    sc_signal< sc_lv<8> > or_ln68_1_fu_671_p2;
    sc_signal< sc_logic > ap_CS_fsm_state16;
    sc_signal< sc_lv<8> > or_ln68_2_fu_718_p2;
    sc_signal< sc_lv<24> > lshr_ln_fu_439_p4;
    sc_signal< sc_lv<5> > add_ln200_fu_460_p2;
    sc_signal< sc_lv<2> > lshr_ln8_fu_466_p4;
    sc_signal< sc_lv<5> > add_ln201_fu_485_p2;
    sc_signal< sc_lv<2> > lshr_ln55_2_fu_491_p4;
    sc_signal< sc_lv<2> > lshr_ln55_4_fu_506_p4;
    sc_signal< sc_lv<3> > sub_ln55_fu_527_p2;
    sc_signal< sc_lv<8> > zext_ln55_1_fu_532_p1;
    sc_signal< sc_lv<8> > lshr_ln55_fu_536_p2;
    sc_signal< sc_lv<3> > sub_ln55_1_fu_546_p2;
    sc_signal< sc_lv<8> > lshr_ln55_1_fu_555_p2;
    sc_signal< sc_lv<3> > xor_ln55_fu_565_p2;
    sc_signal< sc_lv<8> > lshr_ln55_3_fu_574_p2;
    sc_signal< sc_lv<1> > and_ln204_fu_584_p2;
    sc_signal< sc_lv<1> > xor_ln204_fu_590_p2;
    sc_signal< sc_lv<8> > shl_ln68_fu_600_p2;
    sc_signal< sc_lv<8> > zext_ln204_fu_596_p1;
    sc_signal< sc_lv<8> > xor_ln68_fu_606_p2;
    sc_signal< sc_lv<8> > and_ln68_fu_618_p2;
    sc_signal< sc_lv<8> > shl_ln68_3_fu_612_p2;
    sc_signal< sc_lv<1> > and_ln205_fu_631_p2;
    sc_signal< sc_lv<1> > xor_ln205_1_fu_639_p2;
    sc_signal< sc_lv<8> > shl_ln68_4_fu_649_p2;
    sc_signal< sc_lv<8> > zext_ln205_fu_645_p1;
    sc_signal< sc_lv<8> > xor_ln68_3_fu_654_p2;
    sc_signal< sc_lv<8> > and_ln68_1_fu_665_p2;
    sc_signal< sc_lv<8> > shl_ln68_5_fu_660_p2;
    sc_signal< sc_lv<1> > xor_ln206_fu_682_p2;
    sc_signal< sc_lv<1> > and_ln206_fu_678_p2;
    sc_signal< sc_lv<1> > xor_ln206_1_fu_686_p2;
    sc_signal< sc_lv<8> > shl_ln68_6_fu_696_p2;
    sc_signal< sc_lv<8> > zext_ln206_fu_692_p1;
    sc_signal< sc_lv<8> > xor_ln68_4_fu_701_p2;
    sc_signal< sc_lv<8> > and_ln68_2_fu_712_p2;
    sc_signal< sc_lv<8> > shl_ln68_7_fu_707_p2;
    sc_signal< sc_lv<7> > shl_ln1_fu_743_p3;
    sc_signal< sc_lv<7> > zext_ln112_3_fu_774_p1;
    sc_signal< sc_lv<7> > add_ln112_fu_778_p2;
    sc_signal< sc_lv<25> > ap_NS_fsm;
    static const sc_logic ap_const_logic_1;
    static const sc_logic ap_const_logic_0;
    static const sc_lv<25> ap_ST_fsm_state1;
    static const sc_lv<25> ap_ST_fsm_state2;
    static const sc_lv<25> ap_ST_fsm_state3;
    static const sc_lv<25> ap_ST_fsm_state4;
    static const sc_lv<25> ap_ST_fsm_state5;
    static const sc_lv<25> ap_ST_fsm_state6;
    static const sc_lv<25> ap_ST_fsm_state7;
    static const sc_lv<25> ap_ST_fsm_state8;
    static const sc_lv<25> ap_ST_fsm_state9;
    static const sc_lv<25> ap_ST_fsm_state10;
    static const sc_lv<25> ap_ST_fsm_state11;
    static const sc_lv<25> ap_ST_fsm_state12;
    static const sc_lv<25> ap_ST_fsm_state13;
    static const sc_lv<25> ap_ST_fsm_state14;
    static const sc_lv<25> ap_ST_fsm_state15;
    static const sc_lv<25> ap_ST_fsm_state16;
    static const sc_lv<25> ap_ST_fsm_state17;
    static const sc_lv<25> ap_ST_fsm_state18;
    static const sc_lv<25> ap_ST_fsm_state19;
    static const sc_lv<25> ap_ST_fsm_state20;
    static const sc_lv<25> ap_ST_fsm_state21;
    static const sc_lv<25> ap_ST_fsm_state22;
    static const sc_lv<25> ap_ST_fsm_state23;
    static const sc_lv<25> ap_ST_fsm_state24;
    static const sc_lv<25> ap_ST_fsm_state25;
    static const sc_lv<32> ap_const_lv32_0;
    static const sc_lv<32> ap_const_lv32_B;
    static const sc_lv<32> ap_const_lv32_11;
    static const sc_lv<32> ap_const_lv32_1;
    static const sc_lv<1> ap_const_lv1_0;
    static const sc_lv<32> ap_const_lv32_4;
    static const sc_lv<1> ap_const_lv1_1;
    static const sc_lv<32> ap_const_lv32_6;
    static const sc_lv<32> ap_const_lv32_8;
    static const sc_lv<32> ap_const_lv32_A;
    static const sc_lv<32> ap_const_lv32_C;
    static const sc_lv<32> ap_const_lv32_E;
    static const sc_lv<32> ap_const_lv32_13;
    static const sc_lv<32> ap_const_lv32_14;
    static const sc_lv<32> ap_const_lv32_15;
    static const sc_lv<32> ap_const_lv32_17;
    static const sc_lv<32> ap_const_lv32_2;
    static const sc_lv<3> ap_const_lv3_0;
    static const sc_lv<32> ap_const_lv32_3;
    static const sc_lv<32> ap_const_lv32_5;
    static const sc_lv<5> ap_const_lv5_1;
    static const sc_lv<32> ap_const_lv32_7;
    static const sc_lv<32> ap_const_lv32_9;
    static const sc_lv<32> ap_const_lv32_10;
    static const sc_lv<5> ap_const_lv5_0;
    static const sc_lv<32> ap_const_lv32_16;
    static const sc_lv<32> ap_const_lv32_18;
    static const sc_lv<14> ap_const_lv14_0;
    static const sc_lv<64> ap_const_lv64_0;
    static const sc_lv<64> ap_const_lv64_1;
    static const sc_lv<64> ap_const_lv64_2;
    static const sc_lv<64> ap_const_lv64_3;
    static const sc_lv<32> ap_const_lv32_12;
    static const sc_lv<32> ap_const_lv32_D;
    static const sc_lv<32> ap_const_lv32_F;
    static const sc_lv<3> ap_const_lv3_4;
    static const sc_lv<3> ap_const_lv3_1;
    static const sc_lv<5> ap_const_lv5_15;
    static const sc_lv<9> ap_const_lv9_0;
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
    static const bool ap_const_boolean_1;
    // Thread declarations
    void thread_ap_clk_no_reset_();
    void thread_a_fu_542_p1();
    void thread_add_ln112_fu_778_p2();
    void thread_add_ln194_fu_521_p2();
    void thread_add_ln200_fu_460_p2();
    void thread_add_ln201_fu_485_p2();
    void thread_add_ln225_fu_737_p2();
    void thread_add_ln226_fu_751_p2();
    void thread_and_ln204_fu_584_p2();
    void thread_and_ln205_fu_631_p2();
    void thread_and_ln206_fu_678_p2();
    void thread_and_ln68_1_fu_665_p2();
    void thread_and_ln68_2_fu_712_p2();
    void thread_and_ln68_fu_618_p2();
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
    void thread_ap_CS_fsm_state2();
    void thread_ap_CS_fsm_state20();
    void thread_ap_CS_fsm_state21();
    void thread_ap_CS_fsm_state22();
    void thread_ap_CS_fsm_state23();
    void thread_ap_CS_fsm_state24();
    void thread_ap_CS_fsm_state25();
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
    void thread_b_fu_561_p1();
    void thread_c_fu_580_p1();
    void thread_grp_fu_356_p2();
    void thread_grp_matrix_mul_1_fu_345_ap_start();
    void thread_grp_matrix_mul_1_fu_345_matrix_offset();
    void thread_grp_matrix_mul_fu_336_ap_start();
    void thread_i_7_fu_390_p2();
    void thread_i_8_fu_801_p2();
    void thread_i_fu_763_p2();
    void thread_icmp_ln111_1_fu_757_p2();
    void thread_icmp_ln111_2_fu_795_p2();
    void thread_icmp_ln111_fu_384_p2();
    void thread_icmp_ln169_fu_367_p2();
    void thread_icmp_ln184_fu_402_p2();
    void thread_icmp_ln189_fu_417_p2();
    void thread_icmp_ln194_fu_454_p2();
    void thread_key_address0();
    void thread_key_ce0();
    void thread_loop_7_fu_423_p2();
    void thread_loop_fu_373_p2();
    void thread_lshr_ln55_1_fu_555_p2();
    void thread_lshr_ln55_2_fu_491_p4();
    void thread_lshr_ln55_3_fu_574_p2();
    void thread_lshr_ln55_4_fu_506_p4();
    void thread_lshr_ln55_fu_536_p2();
    void thread_lshr_ln8_fu_466_p4();
    void thread_lshr_ln_fu_439_p4();
    void thread_or_ln220_2_fu_725_p5();
    void thread_or_ln68_1_fu_671_p2();
    void thread_or_ln68_2_fu_718_p2();
    void thread_output_r_address0();
    void thread_output_r_ce0();
    void thread_output_r_d0();
    void thread_output_r_we0();
    void thread_plaintext_address0();
    void thread_plaintext_ce0();
    void thread_r_fu_813_p2();
    void thread_roundKey_address0();
    void thread_roundKey_ce0();
    void thread_roundKey_we0();
    void thread_shl_ln1_fu_743_p3();
    void thread_shl_ln68_3_fu_612_p2();
    void thread_shl_ln68_4_fu_649_p2();
    void thread_shl_ln68_5_fu_660_p2();
    void thread_shl_ln68_6_fu_696_p2();
    void thread_shl_ln68_7_fu_707_p2();
    void thread_shl_ln68_fu_600_p2();
    void thread_shl_ln_fu_408_p3();
    void thread_sub_ln55_1_fu_546_p2();
    void thread_sub_ln55_fu_527_p2();
    void thread_temp_address0();
    void thread_temp_address1();
    void thread_temp_ce0();
    void thread_temp_ce1();
    void thread_temp_d0();
    void thread_temp_d1();
    void thread_temp_matrix3_address0();
    void thread_temp_matrix3_ce0();
    void thread_temp_we0();
    void thread_temp_we1();
    void thread_trunc_ln191_fu_429_p1();
    void thread_trunc_ln194_fu_481_p1();
    void thread_xor_ln112_1_fu_788_p2();
    void thread_xor_ln204_fu_590_p2();
    void thread_xor_ln205_1_fu_639_p2();
    void thread_xor_ln205_fu_635_p2();
    void thread_xor_ln206_1_fu_686_p2();
    void thread_xor_ln206_fu_682_p2();
    void thread_xor_ln55_fu_565_p2();
    void thread_xor_ln68_3_fu_654_p2();
    void thread_xor_ln68_4_fu_701_p2();
    void thread_xor_ln68_fu_606_p2();
    void thread_zext_ln112_1_fu_769_p1();
    void thread_zext_ln112_2_fu_807_p1();
    void thread_zext_ln112_3_fu_774_p1();
    void thread_zext_ln112_4_fu_783_p1();
    void thread_zext_ln112_fu_396_p1();
    void thread_zext_ln170_fu_379_p1();
    void thread_zext_ln191_fu_434_p1();
    void thread_zext_ln192_fu_449_p1();
    void thread_zext_ln204_fu_596_p1();
    void thread_zext_ln205_fu_645_p1();
    void thread_zext_ln206_fu_692_p1();
    void thread_zext_ln55_1_fu_532_p1();
    void thread_zext_ln55_2_fu_501_p1();
    void thread_zext_ln55_3_fu_551_p1();
    void thread_zext_ln55_4_fu_516_p1();
    void thread_zext_ln55_5_fu_570_p1();
    void thread_zext_ln55_fu_476_p1();
    void thread_ap_NS_fsm();
};

}

using namespace ap_rtl;

#endif
