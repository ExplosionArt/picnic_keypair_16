// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and OpenCL
// Version: 2019.2
// Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#ifndef _AES256_CTR_DRBG_Upda_HH_
#define _AES256_CTR_DRBG_Upda_HH_

#include "systemc.h"
#include "AESL_pkg.h"

#include "AES256_ECB.h"
#include "AES256_CTR_DRBG_UdEe.h"

namespace ap_rtl {

struct AES256_CTR_DRBG_Upda : public sc_module {
    // Port declarations 26
    sc_in_clk ap_clk;
    sc_in< sc_logic > ap_rst;
    sc_in< sc_logic > ap_start;
    sc_out< sc_logic > ap_done;
    sc_out< sc_logic > ap_idle;
    sc_out< sc_logic > ap_ready;
    sc_out< sc_lv<4> > V_address0;
    sc_out< sc_logic > V_ce0;
    sc_out< sc_logic > V_we0;
    sc_out< sc_lv<8> > V_d0;
    sc_in< sc_lv<8> > V_q0;
    sc_out< sc_lv<4> > V_address1;
    sc_out< sc_logic > V_ce1;
    sc_out< sc_logic > V_we1;
    sc_out< sc_lv<8> > V_d1;
    sc_in< sc_lv<8> > V_q1;
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


    // Module declarations
    AES256_CTR_DRBG_Upda(sc_module_name name);
    SC_HAS_PROCESS(AES256_CTR_DRBG_Upda);

    ~AES256_CTR_DRBG_Upda();

    sc_trace_file* mVcdFile;

    AES256_CTR_DRBG_UdEe* temp_U;
    AES256_ECB* grp_AES256_ECB_fu_923;
    sc_signal< sc_lv<45> > ap_CS_fsm;
    sc_signal< sc_logic > ap_CS_fsm_state1;
    sc_signal< sc_lv<2> > i_fu_947_p2;
    sc_signal< sc_lv<2> > i_reg_1078;
    sc_signal< sc_logic > ap_CS_fsm_state2;
    sc_signal< sc_lv<1> > icmp_ln322_fu_941_p2;
    sc_signal< sc_logic > ap_CS_fsm_state3;
    sc_signal< sc_logic > ap_CS_fsm_state4;
    sc_signal< sc_logic > ap_CS_fsm_state5;
    sc_signal< sc_logic > ap_CS_fsm_state6;
    sc_signal< sc_logic > ap_CS_fsm_state7;
    sc_signal< sc_logic > ap_CS_fsm_state8;
    sc_signal< sc_logic > ap_CS_fsm_state9;
    sc_signal< sc_logic > ap_CS_fsm_state10;
    sc_signal< sc_logic > ap_CS_fsm_state11;
    sc_signal< sc_logic > ap_CS_fsm_state12;
    sc_signal< sc_logic > ap_CS_fsm_state13;
    sc_signal< sc_logic > ap_CS_fsm_state14;
    sc_signal< sc_logic > ap_CS_fsm_state15;
    sc_signal< sc_logic > ap_CS_fsm_state16;
    sc_signal< sc_logic > ap_CS_fsm_state17;
    sc_signal< sc_logic > ap_CS_fsm_state18;
    sc_signal< sc_lv<6> > shl_ln_fu_971_p3;
    sc_signal< sc_lv<6> > shl_ln_reg_1221;
    sc_signal< sc_logic > ap_CS_fsm_state20;
    sc_signal< sc_logic > ap_CS_fsm_state22;
    sc_signal< sc_logic > ap_CS_fsm_state23;
    sc_signal< sc_logic > ap_CS_fsm_state24;
    sc_signal< sc_logic > ap_CS_fsm_state25;
    sc_signal< sc_logic > ap_CS_fsm_state26;
    sc_signal< sc_logic > ap_CS_fsm_state27;
    sc_signal< sc_logic > ap_CS_fsm_state28;
    sc_signal< sc_logic > ap_CS_fsm_state29;
    sc_signal< sc_logic > ap_CS_fsm_state30;
    sc_signal< sc_logic > ap_CS_fsm_state31;
    sc_signal< sc_logic > ap_CS_fsm_state32;
    sc_signal< sc_logic > ap_CS_fsm_state33;
    sc_signal< sc_logic > ap_CS_fsm_state34;
    sc_signal< sc_logic > ap_CS_fsm_state35;
    sc_signal< sc_logic > ap_CS_fsm_state36;
    sc_signal< sc_logic > ap_CS_fsm_state37;
    sc_signal< sc_logic > ap_CS_fsm_state38;
    sc_signal< sc_logic > ap_CS_fsm_state39;
    sc_signal< sc_logic > ap_CS_fsm_state40;
    sc_signal< sc_logic > ap_CS_fsm_state41;
    sc_signal< sc_logic > ap_CS_fsm_state42;
    sc_signal< sc_logic > ap_CS_fsm_state43;
    sc_signal< sc_logic > ap_CS_fsm_state44;
    sc_signal< sc_lv<6> > temp_address0;
    sc_signal< sc_logic > temp_ce0;
    sc_signal< sc_logic > temp_we0;
    sc_signal< sc_lv<8> > temp_q0;
    sc_signal< sc_lv<6> > temp_address1;
    sc_signal< sc_logic > temp_ce1;
    sc_signal< sc_logic > temp_we1;
    sc_signal< sc_lv<8> > temp_q1;
    sc_signal< sc_logic > grp_AES256_ECB_fu_923_ap_start;
    sc_signal< sc_logic > grp_AES256_ECB_fu_923_ap_done;
    sc_signal< sc_logic > grp_AES256_ECB_fu_923_ap_idle;
    sc_signal< sc_logic > grp_AES256_ECB_fu_923_ap_ready;
    sc_signal< sc_lv<5> > grp_AES256_ECB_fu_923_key_address0;
    sc_signal< sc_logic > grp_AES256_ECB_fu_923_key_ce0;
    sc_signal< sc_lv<5> > grp_AES256_ECB_fu_923_key_address1;
    sc_signal< sc_logic > grp_AES256_ECB_fu_923_key_ce1;
    sc_signal< sc_lv<4> > grp_AES256_ECB_fu_923_ctr_address0;
    sc_signal< sc_logic > grp_AES256_ECB_fu_923_ctr_ce0;
    sc_signal< sc_lv<4> > grp_AES256_ECB_fu_923_ctr_address1;
    sc_signal< sc_logic > grp_AES256_ECB_fu_923_ctr_ce1;
    sc_signal< sc_lv<6> > grp_AES256_ECB_fu_923_buffer_r_address0;
    sc_signal< sc_logic > grp_AES256_ECB_fu_923_buffer_r_ce0;
    sc_signal< sc_logic > grp_AES256_ECB_fu_923_buffer_r_we0;
    sc_signal< sc_lv<8> > grp_AES256_ECB_fu_923_buffer_r_d0;
    sc_signal< sc_lv<6> > grp_AES256_ECB_fu_923_buffer_r_address1;
    sc_signal< sc_logic > grp_AES256_ECB_fu_923_buffer_r_ce1;
    sc_signal< sc_logic > grp_AES256_ECB_fu_923_buffer_r_we1;
    sc_signal< sc_lv<8> > grp_AES256_ECB_fu_923_buffer_r_d1;
    sc_signal< sc_lv<2> > i_0_reg_805;
    sc_signal< sc_logic > ap_CS_fsm_state21;
    sc_signal< sc_lv<8> > V_load_lcssa_reg_817;
    sc_signal< sc_lv<1> > grp_fu_935_p2;
    sc_signal< sc_lv<1> > icmp_ln328_2_fu_953_p2;
    sc_signal< sc_lv<4> > V_addr4_lcssa18_reg_854;
    sc_signal< sc_logic > grp_AES256_ECB_fu_923_ap_start_reg;
    sc_signal< sc_lv<64> > zext_ln328_fu_959_p1;
    sc_signal< sc_logic > ap_CS_fsm_state19;
    sc_signal< sc_lv<8> > add_ln331_fu_964_p2;
    sc_signal< sc_logic > ap_CS_fsm_state45;
    sc_signal< sc_lv<45> > ap_NS_fsm;
    static const sc_logic ap_const_logic_1;
    static const sc_logic ap_const_logic_0;
    static const sc_lv<45> ap_ST_fsm_state1;
    static const sc_lv<45> ap_ST_fsm_state2;
    static const sc_lv<45> ap_ST_fsm_state3;
    static const sc_lv<45> ap_ST_fsm_state4;
    static const sc_lv<45> ap_ST_fsm_state5;
    static const sc_lv<45> ap_ST_fsm_state6;
    static const sc_lv<45> ap_ST_fsm_state7;
    static const sc_lv<45> ap_ST_fsm_state8;
    static const sc_lv<45> ap_ST_fsm_state9;
    static const sc_lv<45> ap_ST_fsm_state10;
    static const sc_lv<45> ap_ST_fsm_state11;
    static const sc_lv<45> ap_ST_fsm_state12;
    static const sc_lv<45> ap_ST_fsm_state13;
    static const sc_lv<45> ap_ST_fsm_state14;
    static const sc_lv<45> ap_ST_fsm_state15;
    static const sc_lv<45> ap_ST_fsm_state16;
    static const sc_lv<45> ap_ST_fsm_state17;
    static const sc_lv<45> ap_ST_fsm_state18;
    static const sc_lv<45> ap_ST_fsm_state19;
    static const sc_lv<45> ap_ST_fsm_state20;
    static const sc_lv<45> ap_ST_fsm_state21;
    static const sc_lv<45> ap_ST_fsm_state22;
    static const sc_lv<45> ap_ST_fsm_state23;
    static const sc_lv<45> ap_ST_fsm_state24;
    static const sc_lv<45> ap_ST_fsm_state25;
    static const sc_lv<45> ap_ST_fsm_state26;
    static const sc_lv<45> ap_ST_fsm_state27;
    static const sc_lv<45> ap_ST_fsm_state28;
    static const sc_lv<45> ap_ST_fsm_state29;
    static const sc_lv<45> ap_ST_fsm_state30;
    static const sc_lv<45> ap_ST_fsm_state31;
    static const sc_lv<45> ap_ST_fsm_state32;
    static const sc_lv<45> ap_ST_fsm_state33;
    static const sc_lv<45> ap_ST_fsm_state34;
    static const sc_lv<45> ap_ST_fsm_state35;
    static const sc_lv<45> ap_ST_fsm_state36;
    static const sc_lv<45> ap_ST_fsm_state37;
    static const sc_lv<45> ap_ST_fsm_state38;
    static const sc_lv<45> ap_ST_fsm_state39;
    static const sc_lv<45> ap_ST_fsm_state40;
    static const sc_lv<45> ap_ST_fsm_state41;
    static const sc_lv<45> ap_ST_fsm_state42;
    static const sc_lv<45> ap_ST_fsm_state43;
    static const sc_lv<45> ap_ST_fsm_state44;
    static const sc_lv<45> ap_ST_fsm_state45;
    static const sc_lv<32> ap_const_lv32_0;
    static const sc_lv<32> ap_const_lv32_1;
    static const sc_lv<1> ap_const_lv1_1;
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
    static const sc_lv<32> ap_const_lv32_11;
    static const sc_lv<32> ap_const_lv32_13;
    static const sc_lv<32> ap_const_lv32_15;
    static const sc_lv<32> ap_const_lv32_16;
    static const sc_lv<32> ap_const_lv32_17;
    static const sc_lv<32> ap_const_lv32_18;
    static const sc_lv<32> ap_const_lv32_19;
    static const sc_lv<32> ap_const_lv32_1A;
    static const sc_lv<32> ap_const_lv32_1B;
    static const sc_lv<32> ap_const_lv32_1C;
    static const sc_lv<32> ap_const_lv32_1D;
    static const sc_lv<32> ap_const_lv32_1E;
    static const sc_lv<32> ap_const_lv32_1F;
    static const sc_lv<32> ap_const_lv32_20;
    static const sc_lv<32> ap_const_lv32_21;
    static const sc_lv<32> ap_const_lv32_22;
    static const sc_lv<32> ap_const_lv32_23;
    static const sc_lv<32> ap_const_lv32_24;
    static const sc_lv<32> ap_const_lv32_25;
    static const sc_lv<32> ap_const_lv32_26;
    static const sc_lv<32> ap_const_lv32_27;
    static const sc_lv<32> ap_const_lv32_28;
    static const sc_lv<32> ap_const_lv32_29;
    static const sc_lv<32> ap_const_lv32_2A;
    static const sc_lv<32> ap_const_lv32_2B;
    static const sc_lv<2> ap_const_lv2_0;
    static const sc_lv<32> ap_const_lv32_14;
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
    static const sc_lv<64> ap_const_lv64_F;
    static const sc_lv<64> ap_const_lv64_E;
    static const sc_lv<64> ap_const_lv64_D;
    static const sc_lv<64> ap_const_lv64_C;
    static const sc_lv<64> ap_const_lv64_B;
    static const sc_lv<64> ap_const_lv64_A;
    static const sc_lv<64> ap_const_lv64_9;
    static const sc_lv<64> ap_const_lv64_8;
    static const sc_lv<64> ap_const_lv64_7;
    static const sc_lv<64> ap_const_lv64_6;
    static const sc_lv<64> ap_const_lv64_5;
    static const sc_lv<64> ap_const_lv64_4;
    static const sc_lv<64> ap_const_lv64_3;
    static const sc_lv<64> ap_const_lv64_2;
    static const sc_lv<64> ap_const_lv64_1;
    static const sc_lv<64> ap_const_lv64_0;
    static const sc_lv<32> ap_const_lv32_12;
    static const sc_lv<64> ap_const_lv64_10;
    static const sc_lv<64> ap_const_lv64_11;
    static const sc_lv<64> ap_const_lv64_12;
    static const sc_lv<64> ap_const_lv64_13;
    static const sc_lv<64> ap_const_lv64_14;
    static const sc_lv<64> ap_const_lv64_15;
    static const sc_lv<64> ap_const_lv64_16;
    static const sc_lv<64> ap_const_lv64_17;
    static const sc_lv<64> ap_const_lv64_18;
    static const sc_lv<64> ap_const_lv64_19;
    static const sc_lv<64> ap_const_lv64_1A;
    static const sc_lv<64> ap_const_lv64_1B;
    static const sc_lv<64> ap_const_lv64_1C;
    static const sc_lv<64> ap_const_lv64_1D;
    static const sc_lv<64> ap_const_lv64_1E;
    static const sc_lv<64> ap_const_lv64_1F;
    static const sc_lv<64> ap_const_lv64_20;
    static const sc_lv<64> ap_const_lv64_21;
    static const sc_lv<64> ap_const_lv64_22;
    static const sc_lv<64> ap_const_lv64_23;
    static const sc_lv<64> ap_const_lv64_24;
    static const sc_lv<64> ap_const_lv64_25;
    static const sc_lv<64> ap_const_lv64_26;
    static const sc_lv<64> ap_const_lv64_27;
    static const sc_lv<64> ap_const_lv64_28;
    static const sc_lv<64> ap_const_lv64_29;
    static const sc_lv<64> ap_const_lv64_2A;
    static const sc_lv<64> ap_const_lv64_2B;
    static const sc_lv<64> ap_const_lv64_2C;
    static const sc_lv<64> ap_const_lv64_2D;
    static const sc_lv<64> ap_const_lv64_2E;
    static const sc_lv<64> ap_const_lv64_2F;
    static const sc_lv<8> ap_const_lv8_0;
    static const sc_lv<32> ap_const_lv32_2C;
    static const sc_lv<5> ap_const_lv5_0;
    static const sc_lv<5> ap_const_lv5_1;
    static const sc_lv<5> ap_const_lv5_2;
    static const sc_lv<5> ap_const_lv5_3;
    static const sc_lv<5> ap_const_lv5_4;
    static const sc_lv<5> ap_const_lv5_5;
    static const sc_lv<5> ap_const_lv5_6;
    static const sc_lv<5> ap_const_lv5_7;
    static const sc_lv<5> ap_const_lv5_8;
    static const sc_lv<5> ap_const_lv5_9;
    static const sc_lv<5> ap_const_lv5_A;
    static const sc_lv<5> ap_const_lv5_B;
    static const sc_lv<5> ap_const_lv5_C;
    static const sc_lv<5> ap_const_lv5_D;
    static const sc_lv<5> ap_const_lv5_E;
    static const sc_lv<5> ap_const_lv5_F;
    static const sc_lv<5> ap_const_lv5_10;
    static const sc_lv<5> ap_const_lv5_11;
    static const sc_lv<5> ap_const_lv5_12;
    static const sc_lv<5> ap_const_lv5_13;
    static const sc_lv<5> ap_const_lv5_14;
    static const sc_lv<5> ap_const_lv5_15;
    static const sc_lv<5> ap_const_lv5_16;
    static const sc_lv<5> ap_const_lv5_17;
    static const sc_lv<5> ap_const_lv5_18;
    static const sc_lv<5> ap_const_lv5_19;
    static const sc_lv<5> ap_const_lv5_1A;
    static const sc_lv<5> ap_const_lv5_1B;
    static const sc_lv<5> ap_const_lv5_1C;
    static const sc_lv<5> ap_const_lv5_1D;
    static const sc_lv<5> ap_const_lv5_1E;
    static const sc_lv<5> ap_const_lv5_1F;
    static const sc_lv<8> ap_const_lv8_FF;
    static const sc_lv<2> ap_const_lv2_3;
    static const sc_lv<2> ap_const_lv2_1;
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
    void thread_V_address0();
    void thread_V_address1();
    void thread_V_ce0();
    void thread_V_ce1();
    void thread_V_d0();
    void thread_V_d1();
    void thread_V_we0();
    void thread_V_we1();
    void thread_add_ln331_fu_964_p2();
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
    void thread_ap_CS_fsm_state28();
    void thread_ap_CS_fsm_state29();
    void thread_ap_CS_fsm_state3();
    void thread_ap_CS_fsm_state30();
    void thread_ap_CS_fsm_state31();
    void thread_ap_CS_fsm_state32();
    void thread_ap_CS_fsm_state33();
    void thread_ap_CS_fsm_state34();
    void thread_ap_CS_fsm_state35();
    void thread_ap_CS_fsm_state36();
    void thread_ap_CS_fsm_state37();
    void thread_ap_CS_fsm_state38();
    void thread_ap_CS_fsm_state39();
    void thread_ap_CS_fsm_state4();
    void thread_ap_CS_fsm_state40();
    void thread_ap_CS_fsm_state41();
    void thread_ap_CS_fsm_state42();
    void thread_ap_CS_fsm_state43();
    void thread_ap_CS_fsm_state44();
    void thread_ap_CS_fsm_state45();
    void thread_ap_CS_fsm_state5();
    void thread_ap_CS_fsm_state6();
    void thread_ap_CS_fsm_state7();
    void thread_ap_CS_fsm_state8();
    void thread_ap_CS_fsm_state9();
    void thread_ap_done();
    void thread_ap_idle();
    void thread_ap_ready();
    void thread_grp_AES256_ECB_fu_923_ap_start();
    void thread_grp_fu_935_p2();
    void thread_i_fu_947_p2();
    void thread_icmp_ln322_fu_941_p2();
    void thread_icmp_ln328_2_fu_953_p2();
    void thread_shl_ln_fu_971_p3();
    void thread_temp_address0();
    void thread_temp_address1();
    void thread_temp_ce0();
    void thread_temp_ce1();
    void thread_temp_we0();
    void thread_temp_we1();
    void thread_zext_ln328_fu_959_p1();
    void thread_ap_NS_fsm();
};

}

using namespace ap_rtl;

#endif
