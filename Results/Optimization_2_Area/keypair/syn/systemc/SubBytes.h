// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and OpenCL
// Version: 2019.2
// Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#ifndef _SubBytes_HH_
#define _SubBytes_HH_

#include "systemc.h"
#include "AESL_pkg.h"

#include "KeyExpansion_sbox.h"

namespace ap_rtl {

struct SubBytes : public sc_module {
    // Port declarations 11
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


    // Module declarations
    SubBytes(sc_module_name name);
    SC_HAS_PROCESS(SubBytes);

    ~SubBytes();

    sc_trace_file* mVcdFile;

    KeyExpansion_sbox* sbox_U;
    sc_signal< sc_lv<5> > ap_CS_fsm;
    sc_signal< sc_logic > ap_CS_fsm_state1;
    sc_signal< sc_lv<8> > sbox_address0;
    sc_signal< sc_logic > sbox_ce0;
    sc_signal< sc_lv<8> > sbox_q0;
    sc_signal< sc_lv<3> > i_fu_85_p2;
    sc_signal< sc_lv<3> > i_reg_137;
    sc_signal< sc_logic > ap_CS_fsm_state2;
    sc_signal< sc_lv<6> > zext_ln277_fu_91_p1;
    sc_signal< sc_lv<6> > zext_ln277_reg_142;
    sc_signal< sc_lv<1> > icmp_ln275_fu_79_p2;
    sc_signal< sc_lv<3> > j_fu_101_p2;
    sc_signal< sc_lv<3> > j_reg_150;
    sc_signal< sc_logic > ap_CS_fsm_state3;
    sc_signal< sc_lv<4> > state_addr_reg_155;
    sc_signal< sc_lv<1> > icmp_ln277_fu_95_p2;
    sc_signal< sc_logic > ap_CS_fsm_state4;
    sc_signal< sc_lv<3> > i_0_reg_57;
    sc_signal< sc_lv<3> > j_0_reg_68;
    sc_signal< sc_logic > ap_CS_fsm_state5;
    sc_signal< sc_lv<64> > zext_ln279_1_fu_124_p1;
    sc_signal< sc_lv<64> > zext_ln279_2_fu_129_p1;
    sc_signal< sc_lv<5> > tmp_s_fu_107_p3;
    sc_signal< sc_lv<6> > zext_ln279_fu_115_p1;
    sc_signal< sc_lv<6> > add_ln279_fu_119_p2;
    sc_signal< sc_lv<5> > ap_NS_fsm;
    static const sc_logic ap_const_logic_1;
    static const sc_logic ap_const_logic_0;
    static const sc_lv<5> ap_ST_fsm_state1;
    static const sc_lv<5> ap_ST_fsm_state2;
    static const sc_lv<5> ap_ST_fsm_state3;
    static const sc_lv<5> ap_ST_fsm_state4;
    static const sc_lv<5> ap_ST_fsm_state5;
    static const sc_lv<32> ap_const_lv32_0;
    static const sc_lv<32> ap_const_lv32_1;
    static const sc_lv<1> ap_const_lv1_0;
    static const sc_lv<32> ap_const_lv32_2;
    static const sc_lv<32> ap_const_lv32_3;
    static const sc_lv<3> ap_const_lv3_0;
    static const sc_lv<1> ap_const_lv1_1;
    static const sc_lv<32> ap_const_lv32_4;
    static const sc_lv<3> ap_const_lv3_4;
    static const sc_lv<3> ap_const_lv3_1;
    static const sc_lv<2> ap_const_lv2_0;
    static const bool ap_const_boolean_1;
    // Thread declarations
    void thread_ap_clk_no_reset_();
    void thread_add_ln279_fu_119_p2();
    void thread_ap_CS_fsm_state1();
    void thread_ap_CS_fsm_state2();
    void thread_ap_CS_fsm_state3();
    void thread_ap_CS_fsm_state4();
    void thread_ap_CS_fsm_state5();
    void thread_ap_done();
    void thread_ap_idle();
    void thread_ap_ready();
    void thread_i_fu_85_p2();
    void thread_icmp_ln275_fu_79_p2();
    void thread_icmp_ln277_fu_95_p2();
    void thread_j_fu_101_p2();
    void thread_sbox_address0();
    void thread_sbox_ce0();
    void thread_state_address0();
    void thread_state_ce0();
    void thread_state_d0();
    void thread_state_we0();
    void thread_tmp_s_fu_107_p3();
    void thread_zext_ln277_fu_91_p1();
    void thread_zext_ln279_1_fu_124_p1();
    void thread_zext_ln279_2_fu_129_p1();
    void thread_zext_ln279_fu_115_p1();
    void thread_ap_NS_fsm();
};

}

using namespace ap_rtl;

#endif
