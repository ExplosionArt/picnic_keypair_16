// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and OpenCL
// Version: 2019.2
// Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#ifndef _randombytes_HH_
#define _randombytes_HH_

#include "systemc.h"
#include "AESL_pkg.h"

#include "AES256_CTR_DRBG_Upda.h"
#include "AES256_ECB_1.h"

namespace ap_rtl {

struct randombytes : public sc_module {
    // Port declarations 37
    sc_in_clk ap_clk;
    sc_in< sc_logic > ap_rst;
    sc_in< sc_logic > ap_start;
    sc_out< sc_logic > ap_done;
    sc_out< sc_logic > ap_idle;
    sc_out< sc_logic > ap_ready;
    sc_out< sc_lv<5> > x_address0;
    sc_out< sc_logic > x_ce0;
    sc_out< sc_logic > x_we0;
    sc_out< sc_lv<8> > x_d0;
    sc_out< sc_lv<5> > x_address1;
    sc_out< sc_logic > x_ce1;
    sc_out< sc_logic > x_we1;
    sc_out< sc_lv<8> > x_d1;
    sc_out< sc_lv<4> > DRBG_ctx_V_address0;
    sc_out< sc_logic > DRBG_ctx_V_ce0;
    sc_out< sc_logic > DRBG_ctx_V_we0;
    sc_out< sc_lv<8> > DRBG_ctx_V_d0;
    sc_in< sc_lv<8> > DRBG_ctx_V_q0;
    sc_out< sc_lv<4> > DRBG_ctx_V_address1;
    sc_out< sc_logic > DRBG_ctx_V_ce1;
    sc_out< sc_logic > DRBG_ctx_V_we1;
    sc_out< sc_lv<8> > DRBG_ctx_V_d1;
    sc_in< sc_lv<8> > DRBG_ctx_V_q1;
    sc_out< sc_lv<5> > DRBG_ctx_Key_address0;
    sc_out< sc_logic > DRBG_ctx_Key_ce0;
    sc_out< sc_logic > DRBG_ctx_Key_we0;
    sc_out< sc_lv<8> > DRBG_ctx_Key_d0;
    sc_in< sc_lv<8> > DRBG_ctx_Key_q0;
    sc_out< sc_lv<5> > DRBG_ctx_Key_address1;
    sc_out< sc_logic > DRBG_ctx_Key_ce1;
    sc_out< sc_logic > DRBG_ctx_Key_we1;
    sc_out< sc_lv<8> > DRBG_ctx_Key_d1;
    sc_in< sc_lv<8> > DRBG_ctx_Key_q1;
    sc_in< sc_lv<32> > DRBG_ctx_reseed_counter_i;
    sc_out< sc_lv<32> > DRBG_ctx_reseed_counter_o;
    sc_out< sc_logic > DRBG_ctx_reseed_counter_o_ap_vld;


    // Module declarations
    randombytes(sc_module_name name);
    SC_HAS_PROCESS(randombytes);

    ~randombytes();

    sc_trace_file* mVcdFile;

    AES256_CTR_DRBG_Upda* grp_AES256_CTR_DRBG_Upda_fu_425;
    AES256_ECB_1* grp_AES256_ECB_1_fu_435;
    sc_signal< sc_lv<27> > ap_CS_fsm;
    sc_signal< sc_logic > ap_CS_fsm_state1;
    sc_signal< sc_logic > ap_CS_fsm_state2;
    sc_signal< sc_lv<1> > grp_fu_445_p2;
    sc_signal< sc_lv<1> > icmp_ln228_reg_556;
    sc_signal< sc_logic > ap_CS_fsm_state3;
    sc_signal< sc_lv<1> > icmp_ln228_1_reg_565;
    sc_signal< sc_logic > ap_CS_fsm_state4;
    sc_signal< sc_lv<1> > icmp_ln228_2_fu_451_p2;
    sc_signal< sc_lv<1> > icmp_ln228_2_reg_574;
    sc_signal< sc_logic > ap_CS_fsm_state5;
    sc_signal< sc_lv<1> > icmp_ln228_3_reg_583;
    sc_signal< sc_logic > ap_CS_fsm_state6;
    sc_signal< sc_lv<1> > icmp_ln228_4_reg_592;
    sc_signal< sc_logic > ap_CS_fsm_state7;
    sc_signal< sc_lv<1> > icmp_ln228_5_reg_601;
    sc_signal< sc_logic > ap_CS_fsm_state8;
    sc_signal< sc_lv<1> > icmp_ln228_6_reg_610;
    sc_signal< sc_logic > ap_CS_fsm_state9;
    sc_signal< sc_lv<1> > icmp_ln228_7_reg_619;
    sc_signal< sc_logic > ap_CS_fsm_state10;
    sc_signal< sc_lv<1> > icmp_ln228_8_reg_628;
    sc_signal< sc_logic > ap_CS_fsm_state11;
    sc_signal< sc_lv<1> > icmp_ln228_9_reg_637;
    sc_signal< sc_logic > ap_CS_fsm_state12;
    sc_signal< sc_lv<1> > icmp_ln228_10_reg_646;
    sc_signal< sc_logic > ap_CS_fsm_state13;
    sc_signal< sc_lv<1> > icmp_ln228_11_reg_655;
    sc_signal< sc_logic > ap_CS_fsm_state14;
    sc_signal< sc_lv<1> > icmp_ln228_12_reg_664;
    sc_signal< sc_logic > ap_CS_fsm_state15;
    sc_signal< sc_lv<1> > icmp_ln228_13_reg_673;
    sc_signal< sc_logic > ap_CS_fsm_state16;
    sc_signal< sc_lv<1> > icmp_ln228_14_reg_682;
    sc_signal< sc_logic > ap_CS_fsm_state17;
    sc_signal< sc_lv<1> > icmp_ln228_15_reg_691;
    sc_signal< sc_lv<8> > block_2_reg_695;
    sc_signal< sc_logic > ap_CS_fsm_state20;
    sc_signal< sc_logic > grp_AES256_ECB_1_fu_435_ap_ready;
    sc_signal< sc_logic > grp_AES256_ECB_1_fu_435_ap_done;
    sc_signal< sc_lv<8> > block_3_reg_700;
    sc_signal< sc_lv<8> > block_4_reg_705;
    sc_signal< sc_lv<8> > block_5_reg_710;
    sc_signal< sc_lv<8> > block_6_reg_715;
    sc_signal< sc_lv<8> > block_7_reg_720;
    sc_signal< sc_lv<8> > block_8_reg_725;
    sc_signal< sc_lv<8> > block_9_reg_730;
    sc_signal< sc_lv<8> > block_s_reg_735;
    sc_signal< sc_lv<8> > block_10_reg_740;
    sc_signal< sc_lv<8> > block_11_reg_745;
    sc_signal< sc_lv<8> > block_12_reg_750;
    sc_signal< sc_lv<8> > block_13_reg_755;
    sc_signal< sc_lv<8> > block_14_reg_760;
    sc_signal< sc_logic > grp_AES256_CTR_DRBG_Upda_fu_425_ap_start;
    sc_signal< sc_logic > grp_AES256_CTR_DRBG_Upda_fu_425_ap_done;
    sc_signal< sc_logic > grp_AES256_CTR_DRBG_Upda_fu_425_ap_idle;
    sc_signal< sc_logic > grp_AES256_CTR_DRBG_Upda_fu_425_ap_ready;
    sc_signal< sc_lv<4> > grp_AES256_CTR_DRBG_Upda_fu_425_V_address0;
    sc_signal< sc_logic > grp_AES256_CTR_DRBG_Upda_fu_425_V_ce0;
    sc_signal< sc_logic > grp_AES256_CTR_DRBG_Upda_fu_425_V_we0;
    sc_signal< sc_lv<8> > grp_AES256_CTR_DRBG_Upda_fu_425_V_d0;
    sc_signal< sc_lv<4> > grp_AES256_CTR_DRBG_Upda_fu_425_V_address1;
    sc_signal< sc_logic > grp_AES256_CTR_DRBG_Upda_fu_425_V_ce1;
    sc_signal< sc_logic > grp_AES256_CTR_DRBG_Upda_fu_425_V_we1;
    sc_signal< sc_lv<8> > grp_AES256_CTR_DRBG_Upda_fu_425_V_d1;
    sc_signal< sc_lv<5> > grp_AES256_CTR_DRBG_Upda_fu_425_DRBG_ctx_Key_address0;
    sc_signal< sc_logic > grp_AES256_CTR_DRBG_Upda_fu_425_DRBG_ctx_Key_ce0;
    sc_signal< sc_logic > grp_AES256_CTR_DRBG_Upda_fu_425_DRBG_ctx_Key_we0;
    sc_signal< sc_lv<8> > grp_AES256_CTR_DRBG_Upda_fu_425_DRBG_ctx_Key_d0;
    sc_signal< sc_lv<5> > grp_AES256_CTR_DRBG_Upda_fu_425_DRBG_ctx_Key_address1;
    sc_signal< sc_logic > grp_AES256_CTR_DRBG_Upda_fu_425_DRBG_ctx_Key_ce1;
    sc_signal< sc_logic > grp_AES256_CTR_DRBG_Upda_fu_425_DRBG_ctx_Key_we1;
    sc_signal< sc_lv<8> > grp_AES256_CTR_DRBG_Upda_fu_425_DRBG_ctx_Key_d1;
    sc_signal< sc_logic > grp_AES256_ECB_1_fu_435_ap_start;
    sc_signal< sc_logic > grp_AES256_ECB_1_fu_435_ap_idle;
    sc_signal< sc_lv<5> > grp_AES256_ECB_1_fu_435_key_address0;
    sc_signal< sc_logic > grp_AES256_ECB_1_fu_435_key_ce0;
    sc_signal< sc_lv<5> > grp_AES256_ECB_1_fu_435_key_address1;
    sc_signal< sc_logic > grp_AES256_ECB_1_fu_435_key_ce1;
    sc_signal< sc_lv<4> > grp_AES256_ECB_1_fu_435_ctr_address0;
    sc_signal< sc_logic > grp_AES256_ECB_1_fu_435_ctr_ce0;
    sc_signal< sc_lv<4> > grp_AES256_ECB_1_fu_435_ctr_address1;
    sc_signal< sc_logic > grp_AES256_ECB_1_fu_435_ctr_ce1;
    sc_signal< sc_lv<8> > grp_AES256_ECB_1_fu_435_ap_return_0;
    sc_signal< sc_lv<8> > grp_AES256_ECB_1_fu_435_ap_return_1;
    sc_signal< sc_lv<8> > grp_AES256_ECB_1_fu_435_ap_return_2;
    sc_signal< sc_lv<8> > grp_AES256_ECB_1_fu_435_ap_return_3;
    sc_signal< sc_lv<8> > grp_AES256_ECB_1_fu_435_ap_return_4;
    sc_signal< sc_lv<8> > grp_AES256_ECB_1_fu_435_ap_return_5;
    sc_signal< sc_lv<8> > grp_AES256_ECB_1_fu_435_ap_return_6;
    sc_signal< sc_lv<8> > grp_AES256_ECB_1_fu_435_ap_return_7;
    sc_signal< sc_lv<8> > grp_AES256_ECB_1_fu_435_ap_return_8;
    sc_signal< sc_lv<8> > grp_AES256_ECB_1_fu_435_ap_return_9;
    sc_signal< sc_lv<8> > grp_AES256_ECB_1_fu_435_ap_return_10;
    sc_signal< sc_lv<8> > grp_AES256_ECB_1_fu_435_ap_return_11;
    sc_signal< sc_lv<8> > grp_AES256_ECB_1_fu_435_ap_return_12;
    sc_signal< sc_lv<8> > grp_AES256_ECB_1_fu_435_ap_return_13;
    sc_signal< sc_lv<8> > grp_AES256_ECB_1_fu_435_ap_return_14;
    sc_signal< sc_lv<8> > grp_AES256_ECB_1_fu_435_ap_return_15;
    sc_signal< sc_lv<8> > DRBG_ctx_V_load_lcss_reg_319;
    sc_signal< sc_lv<4> > DRBG_ctx_V_addr_lcss_reg_356;
    sc_signal< sc_logic > grp_AES256_CTR_DRBG_Upda_fu_425_ap_start_reg;
    sc_signal< sc_logic > ap_CS_fsm_state26;
    sc_signal< sc_logic > ap_CS_fsm_state27;
    sc_signal< sc_logic > grp_AES256_ECB_1_fu_435_ap_start_reg;
    sc_signal< sc_logic > ap_CS_fsm_state19;
    sc_signal< sc_lv<64> > DRBG_ctx_V_addr_lcss_1_fu_457_p1;
    sc_signal< sc_logic > ap_CS_fsm_state18;
    sc_signal< sc_logic > ap_CS_fsm_state21;
    sc_signal< sc_logic > ap_CS_fsm_state22;
    sc_signal< sc_logic > ap_CS_fsm_state23;
    sc_signal< sc_logic > ap_CS_fsm_state24;
    sc_signal< sc_logic > ap_CS_fsm_state25;
    sc_signal< sc_lv<32> > add_ln263_fu_539_p2;
    sc_signal< sc_lv<8> > add_ln232_fu_462_p2;
    sc_signal< sc_lv<27> > ap_NS_fsm;
    static const sc_logic ap_const_logic_1;
    static const sc_logic ap_const_logic_0;
    static const sc_lv<27> ap_ST_fsm_state1;
    static const sc_lv<27> ap_ST_fsm_state2;
    static const sc_lv<27> ap_ST_fsm_state3;
    static const sc_lv<27> ap_ST_fsm_state4;
    static const sc_lv<27> ap_ST_fsm_state5;
    static const sc_lv<27> ap_ST_fsm_state6;
    static const sc_lv<27> ap_ST_fsm_state7;
    static const sc_lv<27> ap_ST_fsm_state8;
    static const sc_lv<27> ap_ST_fsm_state9;
    static const sc_lv<27> ap_ST_fsm_state10;
    static const sc_lv<27> ap_ST_fsm_state11;
    static const sc_lv<27> ap_ST_fsm_state12;
    static const sc_lv<27> ap_ST_fsm_state13;
    static const sc_lv<27> ap_ST_fsm_state14;
    static const sc_lv<27> ap_ST_fsm_state15;
    static const sc_lv<27> ap_ST_fsm_state16;
    static const sc_lv<27> ap_ST_fsm_state17;
    static const sc_lv<27> ap_ST_fsm_state18;
    static const sc_lv<27> ap_ST_fsm_state19;
    static const sc_lv<27> ap_ST_fsm_state20;
    static const sc_lv<27> ap_ST_fsm_state21;
    static const sc_lv<27> ap_ST_fsm_state22;
    static const sc_lv<27> ap_ST_fsm_state23;
    static const sc_lv<27> ap_ST_fsm_state24;
    static const sc_lv<27> ap_ST_fsm_state25;
    static const sc_lv<27> ap_ST_fsm_state26;
    static const sc_lv<27> ap_ST_fsm_state27;
    static const sc_lv<32> ap_const_lv32_0;
    static const sc_lv<32> ap_const_lv32_1;
    static const sc_lv<32> ap_const_lv32_2;
    static const sc_lv<32> ap_const_lv32_3;
    static const sc_lv<32> ap_const_lv32_4;
    static const sc_lv<32> ap_const_lv32_5;
    static const sc_lv<32> ap_const_lv32_6;
    static const sc_lv<32> ap_const_lv32_7;
    static const sc_lv<32> ap_const_lv32_8;
    static const sc_lv<32> ap_const_lv32_9;
    static const sc_lv<32> ap_const_lv32_A;
    static const sc_lv<32> ap_const_lv32_B;
    static const sc_lv<32> ap_const_lv32_C;
    static const sc_lv<32> ap_const_lv32_D;
    static const sc_lv<32> ap_const_lv32_E;
    static const sc_lv<32> ap_const_lv32_F;
    static const sc_lv<32> ap_const_lv32_10;
    static const sc_lv<32> ap_const_lv32_13;
    static const sc_lv<1> ap_const_lv1_0;
    static const sc_lv<4> ap_const_lv4_F;
    static const sc_lv<4> ap_const_lv4_E;
    static const sc_lv<4> ap_const_lv4_D;
    static const sc_lv<4> ap_const_lv4_C;
    static const sc_lv<4> ap_const_lv4_B;
    static const sc_lv<4> ap_const_lv4_A;
    static const sc_lv<4> ap_const_lv4_9;
    static const sc_lv<4> ap_const_lv4_8;
    static const sc_lv<4> ap_const_lv4_7;
    static const sc_lv<4> ap_const_lv4_6;
    static const sc_lv<4> ap_const_lv4_5;
    static const sc_lv<4> ap_const_lv4_4;
    static const sc_lv<4> ap_const_lv4_3;
    static const sc_lv<4> ap_const_lv4_2;
    static const sc_lv<4> ap_const_lv4_1;
    static const sc_lv<4> ap_const_lv4_0;
    static const sc_lv<32> ap_const_lv32_19;
    static const sc_lv<32> ap_const_lv32_1A;
    static const sc_lv<32> ap_const_lv32_12;
    static const sc_lv<32> ap_const_lv32_11;
    static const sc_lv<64> ap_const_lv64_0;
    static const sc_lv<64> ap_const_lv64_1;
    static const sc_lv<64> ap_const_lv64_2;
    static const sc_lv<32> ap_const_lv32_14;
    static const sc_lv<64> ap_const_lv64_3;
    static const sc_lv<64> ap_const_lv64_4;
    static const sc_lv<32> ap_const_lv32_15;
    static const sc_lv<64> ap_const_lv64_5;
    static const sc_lv<64> ap_const_lv64_6;
    static const sc_lv<32> ap_const_lv32_16;
    static const sc_lv<64> ap_const_lv64_7;
    static const sc_lv<64> ap_const_lv64_8;
    static const sc_lv<32> ap_const_lv32_17;
    static const sc_lv<64> ap_const_lv64_9;
    static const sc_lv<64> ap_const_lv64_A;
    static const sc_lv<32> ap_const_lv32_18;
    static const sc_lv<64> ap_const_lv64_B;
    static const sc_lv<64> ap_const_lv64_C;
    static const sc_lv<64> ap_const_lv64_D;
    static const sc_lv<64> ap_const_lv64_E;
    static const sc_lv<64> ap_const_lv64_F;
    static const sc_lv<8> ap_const_lv8_0;
    static const sc_lv<1> ap_const_lv1_1;
    static const sc_lv<8> ap_const_lv8_FF;
    static const sc_lv<8> ap_const_lv8_1;
    static const bool ap_const_boolean_1;
    // Thread declarations
    void thread_ap_clk_no_reset_();
    void thread_DRBG_ctx_Key_address0();
    void thread_DRBG_ctx_Key_address1();
    void thread_DRBG_ctx_Key_ce0();
    void thread_DRBG_ctx_Key_ce1();
    void thread_DRBG_ctx_Key_d0();
    void thread_DRBG_ctx_Key_d1();
    void thread_DRBG_ctx_Key_we0();
    void thread_DRBG_ctx_Key_we1();
    void thread_DRBG_ctx_V_addr_lcss_1_fu_457_p1();
    void thread_DRBG_ctx_V_address0();
    void thread_DRBG_ctx_V_address1();
    void thread_DRBG_ctx_V_ce0();
    void thread_DRBG_ctx_V_ce1();
    void thread_DRBG_ctx_V_d0();
    void thread_DRBG_ctx_V_d1();
    void thread_DRBG_ctx_V_we0();
    void thread_DRBG_ctx_V_we1();
    void thread_DRBG_ctx_reseed_counter_o();
    void thread_DRBG_ctx_reseed_counter_o_ap_vld();
    void thread_add_ln232_fu_462_p2();
    void thread_add_ln263_fu_539_p2();
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
    void thread_ap_CS_fsm_state26();
    void thread_ap_CS_fsm_state27();
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
    void thread_grp_AES256_CTR_DRBG_Upda_fu_425_ap_start();
    void thread_grp_AES256_ECB_1_fu_435_ap_start();
    void thread_grp_fu_445_p2();
    void thread_icmp_ln228_2_fu_451_p2();
    void thread_x_address0();
    void thread_x_address1();
    void thread_x_ce0();
    void thread_x_ce1();
    void thread_x_d0();
    void thread_x_d1();
    void thread_x_we0();
    void thread_x_we1();
    void thread_ap_NS_fsm();
};

}

using namespace ap_rtl;

#endif
