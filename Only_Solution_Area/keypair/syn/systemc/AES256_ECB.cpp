// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and OpenCL
// Version: 2019.2
// Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#include "AES256_ECB.h"
#include "AESL_pkg.h"

using namespace std;

namespace ap_rtl {

const sc_logic AES256_ECB::ap_const_logic_1 = sc_dt::Log_1;
const sc_logic AES256_ECB::ap_const_logic_0 = sc_dt::Log_0;
const sc_lv<9> AES256_ECB::ap_ST_fsm_state1 = "1";
const sc_lv<9> AES256_ECB::ap_ST_fsm_state2 = "10";
const sc_lv<9> AES256_ECB::ap_ST_fsm_state3 = "100";
const sc_lv<9> AES256_ECB::ap_ST_fsm_state4 = "1000";
const sc_lv<9> AES256_ECB::ap_ST_fsm_state5 = "10000";
const sc_lv<9> AES256_ECB::ap_ST_fsm_state6 = "100000";
const sc_lv<9> AES256_ECB::ap_ST_fsm_state7 = "1000000";
const sc_lv<9> AES256_ECB::ap_ST_fsm_state8 = "10000000";
const sc_lv<9> AES256_ECB::ap_ST_fsm_state9 = "100000000";
const sc_lv<32> AES256_ECB::ap_const_lv32_0 = "00000000000000000000000000000000";
const sc_lv<32> AES256_ECB::ap_const_lv32_1 = "1";
const sc_lv<32> AES256_ECB::ap_const_lv32_2 = "10";
const sc_lv<1> AES256_ECB::ap_const_lv1_0 = "0";
const sc_lv<32> AES256_ECB::ap_const_lv32_3 = "11";
const sc_lv<32> AES256_ECB::ap_const_lv32_6 = "110";
const sc_lv<32> AES256_ECB::ap_const_lv32_7 = "111";
const sc_lv<3> AES256_ECB::ap_const_lv3_0 = "000";
const sc_lv<1> AES256_ECB::ap_const_lv1_1 = "1";
const sc_lv<32> AES256_ECB::ap_const_lv32_4 = "100";
const sc_lv<32> AES256_ECB::ap_const_lv32_5 = "101";
const sc_lv<32> AES256_ECB::ap_const_lv32_8 = "1000";
const sc_lv<3> AES256_ECB::ap_const_lv3_4 = "100";
const sc_lv<3> AES256_ECB::ap_const_lv3_1 = "1";
const sc_lv<2> AES256_ECB::ap_const_lv2_0 = "00";
const bool AES256_ECB::ap_const_boolean_1 = true;

AES256_ECB::AES256_ECB(sc_module_name name) : sc_module(name), mVcdFile(0) {
    ctx_RoundKey_U = new AES256_ECB_ctx_RodEe("ctx_RoundKey_U");
    ctx_RoundKey_U->clk(ap_clk);
    ctx_RoundKey_U->reset(ap_rst);
    ctx_RoundKey_U->address0(ctx_RoundKey_address0);
    ctx_RoundKey_U->ce0(ctx_RoundKey_ce0);
    ctx_RoundKey_U->we0(ctx_RoundKey_we0);
    ctx_RoundKey_U->d0(grp_KeyExpansion_fu_143_RoundKey_d0);
    ctx_RoundKey_U->q0(ctx_RoundKey_q0);
    test_U = new AES256_ECB_1_test("test_U");
    test_U->clk(ap_clk);
    test_U->reset(ap_rst);
    test_U->address0(test_address0);
    test_U->ce0(test_ce0);
    test_U->we0(test_we0);
    test_U->d0(test_d0);
    test_U->q0(test_q0);
    test_U->address1(grp_Cipher_fu_155_state_address1);
    test_U->ce1(test_ce1);
    test_U->we1(test_we1);
    test_U->d1(grp_Cipher_fu_155_state_d1);
    test_U->q1(test_q1);
    grp_KeyExpansion_fu_143 = new KeyExpansion("grp_KeyExpansion_fu_143");
    grp_KeyExpansion_fu_143->ap_clk(ap_clk);
    grp_KeyExpansion_fu_143->ap_rst(ap_rst);
    grp_KeyExpansion_fu_143->ap_start(grp_KeyExpansion_fu_143_ap_start);
    grp_KeyExpansion_fu_143->ap_done(grp_KeyExpansion_fu_143_ap_done);
    grp_KeyExpansion_fu_143->ap_idle(grp_KeyExpansion_fu_143_ap_idle);
    grp_KeyExpansion_fu_143->ap_ready(grp_KeyExpansion_fu_143_ap_ready);
    grp_KeyExpansion_fu_143->RoundKey_address0(grp_KeyExpansion_fu_143_RoundKey_address0);
    grp_KeyExpansion_fu_143->RoundKey_ce0(grp_KeyExpansion_fu_143_RoundKey_ce0);
    grp_KeyExpansion_fu_143->RoundKey_we0(grp_KeyExpansion_fu_143_RoundKey_we0);
    grp_KeyExpansion_fu_143->RoundKey_d0(grp_KeyExpansion_fu_143_RoundKey_d0);
    grp_KeyExpansion_fu_143->RoundKey_q0(ctx_RoundKey_q0);
    grp_KeyExpansion_fu_143->Key_address0(grp_KeyExpansion_fu_143_Key_address0);
    grp_KeyExpansion_fu_143->Key_ce0(grp_KeyExpansion_fu_143_Key_ce0);
    grp_KeyExpansion_fu_143->Key_q0(key_q0);
    grp_Cipher_fu_155 = new Cipher("grp_Cipher_fu_155");
    grp_Cipher_fu_155->ap_clk(ap_clk);
    grp_Cipher_fu_155->ap_rst(ap_rst);
    grp_Cipher_fu_155->ap_start(grp_Cipher_fu_155_ap_start);
    grp_Cipher_fu_155->ap_done(grp_Cipher_fu_155_ap_done);
    grp_Cipher_fu_155->ap_idle(grp_Cipher_fu_155_ap_idle);
    grp_Cipher_fu_155->ap_ready(grp_Cipher_fu_155_ap_ready);
    grp_Cipher_fu_155->state_address0(grp_Cipher_fu_155_state_address0);
    grp_Cipher_fu_155->state_ce0(grp_Cipher_fu_155_state_ce0);
    grp_Cipher_fu_155->state_we0(grp_Cipher_fu_155_state_we0);
    grp_Cipher_fu_155->state_d0(grp_Cipher_fu_155_state_d0);
    grp_Cipher_fu_155->state_q0(test_q0);
    grp_Cipher_fu_155->state_address1(grp_Cipher_fu_155_state_address1);
    grp_Cipher_fu_155->state_ce1(grp_Cipher_fu_155_state_ce1);
    grp_Cipher_fu_155->state_we1(grp_Cipher_fu_155_state_we1);
    grp_Cipher_fu_155->state_d1(grp_Cipher_fu_155_state_d1);
    grp_Cipher_fu_155->state_q1(test_q1);
    grp_Cipher_fu_155->RoundKey_address0(grp_Cipher_fu_155_RoundKey_address0);
    grp_Cipher_fu_155->RoundKey_ce0(grp_Cipher_fu_155_RoundKey_ce0);
    grp_Cipher_fu_155->RoundKey_q0(ctx_RoundKey_q0);

    SC_METHOD(thread_ap_clk_no_reset_);
    dont_initialize();
    sensitive << ( ap_clk.pos() );

    SC_METHOD(thread_add_ln168_2_fu_229_p2);
    sensitive << ( zext_ln166_reg_340 );
    sensitive << ( zext_ln168_5_fu_225_p1 );

    SC_METHOD(thread_add_ln168_fu_215_p2);
    sensitive << ( shl_ln_reg_335 );
    sensitive << ( zext_ln168_fu_211_p1 );

    SC_METHOD(thread_add_ln195_1_fu_313_p2);
    sensitive << ( buffer_offset );
    sensitive << ( zext_ln195_5_fu_309_p1 );

    SC_METHOD(thread_add_ln195_2_fu_290_p2);
    sensitive << ( zext_ln195_reg_371 );
    sensitive << ( zext_ln195_7_fu_286_p1 );

    SC_METHOD(thread_add_ln195_fu_304_p2);
    sensitive << ( shl_ln3_reg_376 );
    sensitive << ( zext_ln195_4_fu_300_p1 );

    SC_METHOD(thread_ap_CS_fsm_state1);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state2);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state3);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state4);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state5);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state6);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state7);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state8);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state9);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_done);
    sensitive << ( ap_start );
    sensitive << ( ap_CS_fsm_state1 );
    sensitive << ( ap_CS_fsm_state7 );
    sensitive << ( icmp_ln191_fu_238_p2 );

    SC_METHOD(thread_ap_idle);
    sensitive << ( ap_start );
    sensitive << ( ap_CS_fsm_state1 );

    SC_METHOD(thread_ap_ready);
    sensitive << ( ap_CS_fsm_state7 );
    sensitive << ( icmp_ln191_fu_238_p2 );

    SC_METHOD(thread_buffer_r_address0);
    sensitive << ( ap_CS_fsm_state9 );
    sensitive << ( zext_ln195_6_fu_318_p1 );

    SC_METHOD(thread_buffer_r_ce0);
    sensitive << ( ap_CS_fsm_state9 );

    SC_METHOD(thread_buffer_r_d0);
    sensitive << ( test_q0 );
    sensitive << ( ap_CS_fsm_state9 );

    SC_METHOD(thread_buffer_r_we0);
    sensitive << ( ap_CS_fsm_state9 );

    SC_METHOD(thread_ctr_address0);
    sensitive << ( ap_CS_fsm_state4 );
    sensitive << ( zext_ln168_4_fu_220_p1 );

    SC_METHOD(thread_ctr_ce0);
    sensitive << ( ap_CS_fsm_state4 );

    SC_METHOD(thread_ctx_RoundKey_address0);
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( grp_KeyExpansion_fu_143_RoundKey_address0 );
    sensitive << ( grp_Cipher_fu_155_RoundKey_address0 );
    sensitive << ( ap_CS_fsm_state6 );

    SC_METHOD(thread_ctx_RoundKey_ce0);
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( grp_KeyExpansion_fu_143_RoundKey_ce0 );
    sensitive << ( grp_Cipher_fu_155_RoundKey_ce0 );
    sensitive << ( ap_CS_fsm_state6 );

    SC_METHOD(thread_ctx_RoundKey_we0);
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( grp_KeyExpansion_fu_143_RoundKey_we0 );

    SC_METHOD(thread_grp_Cipher_fu_155_ap_start);
    sensitive << ( grp_Cipher_fu_155_ap_start_reg );

    SC_METHOD(thread_grp_KeyExpansion_fu_143_ap_start);
    sensitive << ( grp_KeyExpansion_fu_143_ap_start_reg );

    SC_METHOD(thread_i_11_fu_244_p2);
    sensitive << ( i_1_reg_121 );

    SC_METHOD(thread_i_fu_169_p2);
    sensitive << ( i_0_reg_99 );

    SC_METHOD(thread_icmp_ln164_fu_163_p2);
    sensitive << ( ap_CS_fsm_state3 );
    sensitive << ( i_0_reg_99 );

    SC_METHOD(thread_icmp_ln166_fu_199_p2);
    sensitive << ( ap_CS_fsm_state4 );
    sensitive << ( j_0_reg_110 );

    SC_METHOD(thread_icmp_ln191_fu_238_p2);
    sensitive << ( ap_CS_fsm_state7 );
    sensitive << ( i_1_reg_121 );

    SC_METHOD(thread_icmp_ln193_fu_274_p2);
    sensitive << ( ap_CS_fsm_state8 );
    sensitive << ( j_1_reg_132 );

    SC_METHOD(thread_j_9_fu_280_p2);
    sensitive << ( j_1_reg_132 );

    SC_METHOD(thread_j_fu_205_p2);
    sensitive << ( j_0_reg_110 );

    SC_METHOD(thread_key_address0);
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( grp_KeyExpansion_fu_143_Key_address0 );

    SC_METHOD(thread_key_ce0);
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( grp_KeyExpansion_fu_143_Key_ce0 );

    SC_METHOD(thread_shl_ln3_fu_266_p3);
    sensitive << ( trunc_ln195_fu_262_p1 );

    SC_METHOD(thread_shl_ln_fu_179_p3);
    sensitive << ( trunc_ln168_fu_175_p1 );

    SC_METHOD(thread_test_address0);
    sensitive << ( ap_CS_fsm_state8 );
    sensitive << ( grp_Cipher_fu_155_state_address0 );
    sensitive << ( ap_CS_fsm_state5 );
    sensitive << ( ap_CS_fsm_state6 );
    sensitive << ( zext_ln168_6_fu_234_p1 );
    sensitive << ( zext_ln195_8_fu_295_p1 );

    SC_METHOD(thread_test_ce0);
    sensitive << ( ap_CS_fsm_state8 );
    sensitive << ( grp_Cipher_fu_155_state_ce0 );
    sensitive << ( ap_CS_fsm_state5 );
    sensitive << ( ap_CS_fsm_state6 );

    SC_METHOD(thread_test_ce1);
    sensitive << ( grp_Cipher_fu_155_state_ce1 );
    sensitive << ( ap_CS_fsm_state6 );

    SC_METHOD(thread_test_d0);
    sensitive << ( ctr_q0 );
    sensitive << ( grp_Cipher_fu_155_state_d0 );
    sensitive << ( ap_CS_fsm_state5 );
    sensitive << ( ap_CS_fsm_state6 );

    SC_METHOD(thread_test_we0);
    sensitive << ( grp_Cipher_fu_155_state_we0 );
    sensitive << ( ap_CS_fsm_state5 );
    sensitive << ( ap_CS_fsm_state6 );

    SC_METHOD(thread_test_we1);
    sensitive << ( grp_Cipher_fu_155_state_we1 );
    sensitive << ( ap_CS_fsm_state6 );

    SC_METHOD(thread_tmp_4_fu_250_p3);
    sensitive << ( i_1_reg_121 );

    SC_METHOD(thread_tmp_s_fu_187_p3);
    sensitive << ( i_0_reg_99 );

    SC_METHOD(thread_trunc_ln168_fu_175_p1);
    sensitive << ( i_0_reg_99 );

    SC_METHOD(thread_trunc_ln195_fu_262_p1);
    sensitive << ( i_1_reg_121 );

    SC_METHOD(thread_zext_ln166_fu_195_p1);
    sensitive << ( tmp_s_fu_187_p3 );

    SC_METHOD(thread_zext_ln168_4_fu_220_p1);
    sensitive << ( add_ln168_fu_215_p2 );

    SC_METHOD(thread_zext_ln168_5_fu_225_p1);
    sensitive << ( j_0_reg_110 );

    SC_METHOD(thread_zext_ln168_6_fu_234_p1);
    sensitive << ( add_ln168_2_reg_358 );

    SC_METHOD(thread_zext_ln168_fu_211_p1);
    sensitive << ( j_0_reg_110 );

    SC_METHOD(thread_zext_ln195_4_fu_300_p1);
    sensitive << ( j_1_reg_132 );

    SC_METHOD(thread_zext_ln195_5_fu_309_p1);
    sensitive << ( add_ln195_fu_304_p2 );

    SC_METHOD(thread_zext_ln195_6_fu_318_p1);
    sensitive << ( add_ln195_1_reg_394 );

    SC_METHOD(thread_zext_ln195_7_fu_286_p1);
    sensitive << ( j_1_reg_132 );

    SC_METHOD(thread_zext_ln195_8_fu_295_p1);
    sensitive << ( add_ln195_2_fu_290_p2 );

    SC_METHOD(thread_zext_ln195_fu_258_p1);
    sensitive << ( tmp_4_fu_250_p3 );

    SC_METHOD(thread_ap_NS_fsm);
    sensitive << ( ap_start );
    sensitive << ( ap_CS_fsm );
    sensitive << ( ap_CS_fsm_state1 );
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( grp_KeyExpansion_fu_143_ap_done );
    sensitive << ( ap_CS_fsm_state3 );
    sensitive << ( icmp_ln164_fu_163_p2 );
    sensitive << ( ap_CS_fsm_state4 );
    sensitive << ( icmp_ln166_fu_199_p2 );
    sensitive << ( ap_CS_fsm_state7 );
    sensitive << ( icmp_ln191_fu_238_p2 );
    sensitive << ( ap_CS_fsm_state8 );
    sensitive << ( icmp_ln193_fu_274_p2 );
    sensitive << ( grp_Cipher_fu_155_ap_done );
    sensitive << ( ap_CS_fsm_state6 );

    ap_CS_fsm = "000000001";
    grp_KeyExpansion_fu_143_ap_start_reg = SC_LOGIC_0;
    grp_Cipher_fu_155_ap_start_reg = SC_LOGIC_0;
    static int apTFileNum = 0;
    stringstream apTFilenSS;
    apTFilenSS << "AES256_ECB_sc_trace_" << apTFileNum ++;
    string apTFn = apTFilenSS.str();
    mVcdFile = sc_create_vcd_trace_file(apTFn.c_str());
    mVcdFile->set_time_unit(1, SC_PS);
    if (1) {
#ifdef __HLS_TRACE_LEVEL_PORT_HIER__
    sc_trace(mVcdFile, ap_clk, "(port)ap_clk");
    sc_trace(mVcdFile, ap_rst, "(port)ap_rst");
    sc_trace(mVcdFile, ap_start, "(port)ap_start");
    sc_trace(mVcdFile, ap_done, "(port)ap_done");
    sc_trace(mVcdFile, ap_idle, "(port)ap_idle");
    sc_trace(mVcdFile, ap_ready, "(port)ap_ready");
    sc_trace(mVcdFile, key_address0, "(port)key_address0");
    sc_trace(mVcdFile, key_ce0, "(port)key_ce0");
    sc_trace(mVcdFile, key_q0, "(port)key_q0");
    sc_trace(mVcdFile, ctr_address0, "(port)ctr_address0");
    sc_trace(mVcdFile, ctr_ce0, "(port)ctr_ce0");
    sc_trace(mVcdFile, ctr_q0, "(port)ctr_q0");
    sc_trace(mVcdFile, buffer_r_address0, "(port)buffer_r_address0");
    sc_trace(mVcdFile, buffer_r_ce0, "(port)buffer_r_ce0");
    sc_trace(mVcdFile, buffer_r_we0, "(port)buffer_r_we0");
    sc_trace(mVcdFile, buffer_r_d0, "(port)buffer_r_d0");
    sc_trace(mVcdFile, buffer_offset, "(port)buffer_offset");
#endif
#ifdef __HLS_TRACE_LEVEL_INT__
    sc_trace(mVcdFile, ap_CS_fsm, "ap_CS_fsm");
    sc_trace(mVcdFile, ap_CS_fsm_state1, "ap_CS_fsm_state1");
    sc_trace(mVcdFile, ap_CS_fsm_state2, "ap_CS_fsm_state2");
    sc_trace(mVcdFile, grp_KeyExpansion_fu_143_ap_ready, "grp_KeyExpansion_fu_143_ap_ready");
    sc_trace(mVcdFile, grp_KeyExpansion_fu_143_ap_done, "grp_KeyExpansion_fu_143_ap_done");
    sc_trace(mVcdFile, i_fu_169_p2, "i_fu_169_p2");
    sc_trace(mVcdFile, i_reg_330, "i_reg_330");
    sc_trace(mVcdFile, ap_CS_fsm_state3, "ap_CS_fsm_state3");
    sc_trace(mVcdFile, shl_ln_fu_179_p3, "shl_ln_fu_179_p3");
    sc_trace(mVcdFile, shl_ln_reg_335, "shl_ln_reg_335");
    sc_trace(mVcdFile, icmp_ln164_fu_163_p2, "icmp_ln164_fu_163_p2");
    sc_trace(mVcdFile, zext_ln166_fu_195_p1, "zext_ln166_fu_195_p1");
    sc_trace(mVcdFile, zext_ln166_reg_340, "zext_ln166_reg_340");
    sc_trace(mVcdFile, j_fu_205_p2, "j_fu_205_p2");
    sc_trace(mVcdFile, j_reg_348, "j_reg_348");
    sc_trace(mVcdFile, ap_CS_fsm_state4, "ap_CS_fsm_state4");
    sc_trace(mVcdFile, icmp_ln166_fu_199_p2, "icmp_ln166_fu_199_p2");
    sc_trace(mVcdFile, add_ln168_2_fu_229_p2, "add_ln168_2_fu_229_p2");
    sc_trace(mVcdFile, add_ln168_2_reg_358, "add_ln168_2_reg_358");
    sc_trace(mVcdFile, i_11_fu_244_p2, "i_11_fu_244_p2");
    sc_trace(mVcdFile, i_11_reg_366, "i_11_reg_366");
    sc_trace(mVcdFile, ap_CS_fsm_state7, "ap_CS_fsm_state7");
    sc_trace(mVcdFile, zext_ln195_fu_258_p1, "zext_ln195_fu_258_p1");
    sc_trace(mVcdFile, zext_ln195_reg_371, "zext_ln195_reg_371");
    sc_trace(mVcdFile, icmp_ln191_fu_238_p2, "icmp_ln191_fu_238_p2");
    sc_trace(mVcdFile, shl_ln3_fu_266_p3, "shl_ln3_fu_266_p3");
    sc_trace(mVcdFile, shl_ln3_reg_376, "shl_ln3_reg_376");
    sc_trace(mVcdFile, j_9_fu_280_p2, "j_9_fu_280_p2");
    sc_trace(mVcdFile, j_9_reg_384, "j_9_reg_384");
    sc_trace(mVcdFile, ap_CS_fsm_state8, "ap_CS_fsm_state8");
    sc_trace(mVcdFile, icmp_ln193_fu_274_p2, "icmp_ln193_fu_274_p2");
    sc_trace(mVcdFile, add_ln195_1_fu_313_p2, "add_ln195_1_fu_313_p2");
    sc_trace(mVcdFile, add_ln195_1_reg_394, "add_ln195_1_reg_394");
    sc_trace(mVcdFile, ctx_RoundKey_address0, "ctx_RoundKey_address0");
    sc_trace(mVcdFile, ctx_RoundKey_ce0, "ctx_RoundKey_ce0");
    sc_trace(mVcdFile, ctx_RoundKey_we0, "ctx_RoundKey_we0");
    sc_trace(mVcdFile, ctx_RoundKey_q0, "ctx_RoundKey_q0");
    sc_trace(mVcdFile, test_address0, "test_address0");
    sc_trace(mVcdFile, test_ce0, "test_ce0");
    sc_trace(mVcdFile, test_we0, "test_we0");
    sc_trace(mVcdFile, test_d0, "test_d0");
    sc_trace(mVcdFile, test_q0, "test_q0");
    sc_trace(mVcdFile, test_ce1, "test_ce1");
    sc_trace(mVcdFile, test_we1, "test_we1");
    sc_trace(mVcdFile, test_q1, "test_q1");
    sc_trace(mVcdFile, grp_KeyExpansion_fu_143_ap_start, "grp_KeyExpansion_fu_143_ap_start");
    sc_trace(mVcdFile, grp_KeyExpansion_fu_143_ap_idle, "grp_KeyExpansion_fu_143_ap_idle");
    sc_trace(mVcdFile, grp_KeyExpansion_fu_143_RoundKey_address0, "grp_KeyExpansion_fu_143_RoundKey_address0");
    sc_trace(mVcdFile, grp_KeyExpansion_fu_143_RoundKey_ce0, "grp_KeyExpansion_fu_143_RoundKey_ce0");
    sc_trace(mVcdFile, grp_KeyExpansion_fu_143_RoundKey_we0, "grp_KeyExpansion_fu_143_RoundKey_we0");
    sc_trace(mVcdFile, grp_KeyExpansion_fu_143_RoundKey_d0, "grp_KeyExpansion_fu_143_RoundKey_d0");
    sc_trace(mVcdFile, grp_KeyExpansion_fu_143_Key_address0, "grp_KeyExpansion_fu_143_Key_address0");
    sc_trace(mVcdFile, grp_KeyExpansion_fu_143_Key_ce0, "grp_KeyExpansion_fu_143_Key_ce0");
    sc_trace(mVcdFile, grp_Cipher_fu_155_ap_start, "grp_Cipher_fu_155_ap_start");
    sc_trace(mVcdFile, grp_Cipher_fu_155_ap_done, "grp_Cipher_fu_155_ap_done");
    sc_trace(mVcdFile, grp_Cipher_fu_155_ap_idle, "grp_Cipher_fu_155_ap_idle");
    sc_trace(mVcdFile, grp_Cipher_fu_155_ap_ready, "grp_Cipher_fu_155_ap_ready");
    sc_trace(mVcdFile, grp_Cipher_fu_155_state_address0, "grp_Cipher_fu_155_state_address0");
    sc_trace(mVcdFile, grp_Cipher_fu_155_state_ce0, "grp_Cipher_fu_155_state_ce0");
    sc_trace(mVcdFile, grp_Cipher_fu_155_state_we0, "grp_Cipher_fu_155_state_we0");
    sc_trace(mVcdFile, grp_Cipher_fu_155_state_d0, "grp_Cipher_fu_155_state_d0");
    sc_trace(mVcdFile, grp_Cipher_fu_155_state_address1, "grp_Cipher_fu_155_state_address1");
    sc_trace(mVcdFile, grp_Cipher_fu_155_state_ce1, "grp_Cipher_fu_155_state_ce1");
    sc_trace(mVcdFile, grp_Cipher_fu_155_state_we1, "grp_Cipher_fu_155_state_we1");
    sc_trace(mVcdFile, grp_Cipher_fu_155_state_d1, "grp_Cipher_fu_155_state_d1");
    sc_trace(mVcdFile, grp_Cipher_fu_155_RoundKey_address0, "grp_Cipher_fu_155_RoundKey_address0");
    sc_trace(mVcdFile, grp_Cipher_fu_155_RoundKey_ce0, "grp_Cipher_fu_155_RoundKey_ce0");
    sc_trace(mVcdFile, i_0_reg_99, "i_0_reg_99");
    sc_trace(mVcdFile, j_0_reg_110, "j_0_reg_110");
    sc_trace(mVcdFile, ap_CS_fsm_state5, "ap_CS_fsm_state5");
    sc_trace(mVcdFile, i_1_reg_121, "i_1_reg_121");
    sc_trace(mVcdFile, ap_CS_fsm_state6, "ap_CS_fsm_state6");
    sc_trace(mVcdFile, j_1_reg_132, "j_1_reg_132");
    sc_trace(mVcdFile, ap_CS_fsm_state9, "ap_CS_fsm_state9");
    sc_trace(mVcdFile, grp_KeyExpansion_fu_143_ap_start_reg, "grp_KeyExpansion_fu_143_ap_start_reg");
    sc_trace(mVcdFile, grp_Cipher_fu_155_ap_start_reg, "grp_Cipher_fu_155_ap_start_reg");
    sc_trace(mVcdFile, zext_ln168_4_fu_220_p1, "zext_ln168_4_fu_220_p1");
    sc_trace(mVcdFile, zext_ln168_6_fu_234_p1, "zext_ln168_6_fu_234_p1");
    sc_trace(mVcdFile, zext_ln195_8_fu_295_p1, "zext_ln195_8_fu_295_p1");
    sc_trace(mVcdFile, zext_ln195_6_fu_318_p1, "zext_ln195_6_fu_318_p1");
    sc_trace(mVcdFile, trunc_ln168_fu_175_p1, "trunc_ln168_fu_175_p1");
    sc_trace(mVcdFile, tmp_s_fu_187_p3, "tmp_s_fu_187_p3");
    sc_trace(mVcdFile, zext_ln168_fu_211_p1, "zext_ln168_fu_211_p1");
    sc_trace(mVcdFile, add_ln168_fu_215_p2, "add_ln168_fu_215_p2");
    sc_trace(mVcdFile, zext_ln168_5_fu_225_p1, "zext_ln168_5_fu_225_p1");
    sc_trace(mVcdFile, tmp_4_fu_250_p3, "tmp_4_fu_250_p3");
    sc_trace(mVcdFile, trunc_ln195_fu_262_p1, "trunc_ln195_fu_262_p1");
    sc_trace(mVcdFile, zext_ln195_7_fu_286_p1, "zext_ln195_7_fu_286_p1");
    sc_trace(mVcdFile, add_ln195_2_fu_290_p2, "add_ln195_2_fu_290_p2");
    sc_trace(mVcdFile, zext_ln195_4_fu_300_p1, "zext_ln195_4_fu_300_p1");
    sc_trace(mVcdFile, add_ln195_fu_304_p2, "add_ln195_fu_304_p2");
    sc_trace(mVcdFile, zext_ln195_5_fu_309_p1, "zext_ln195_5_fu_309_p1");
    sc_trace(mVcdFile, ap_NS_fsm, "ap_NS_fsm");
#endif

    }
}

AES256_ECB::~AES256_ECB() {
    if (mVcdFile) 
        sc_close_vcd_trace_file(mVcdFile);

    delete ctx_RoundKey_U;
    delete test_U;
    delete grp_KeyExpansion_fu_143;
    delete grp_Cipher_fu_155;
}

void AES256_ECB::thread_ap_clk_no_reset_() {
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_CS_fsm = ap_ST_fsm_state1;
    } else {
        ap_CS_fsm = ap_NS_fsm.read();
    }
    if ( ap_rst.read() == ap_const_logic_1) {
        grp_Cipher_fu_155_ap_start_reg = ap_const_logic_0;
    } else {
        if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read()) && 
             esl_seteq<1,1,1>(icmp_ln164_fu_163_p2.read(), ap_const_lv1_1))) {
            grp_Cipher_fu_155_ap_start_reg = ap_const_logic_1;
        } else if (esl_seteq<1,1,1>(ap_const_logic_1, grp_Cipher_fu_155_ap_ready.read())) {
            grp_Cipher_fu_155_ap_start_reg = ap_const_logic_0;
        }
    }
    if ( ap_rst.read() == ap_const_logic_1) {
        grp_KeyExpansion_fu_143_ap_start_reg = ap_const_logic_0;
    } else {
        if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && 
             esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_1))) {
            grp_KeyExpansion_fu_143_ap_start_reg = ap_const_logic_1;
        } else if (esl_seteq<1,1,1>(ap_const_logic_1, grp_KeyExpansion_fu_143_ap_ready.read())) {
            grp_KeyExpansion_fu_143_ap_start_reg = ap_const_logic_0;
        }
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state4.read()) && 
         esl_seteq<1,1,1>(icmp_ln166_fu_199_p2.read(), ap_const_lv1_1))) {
        i_0_reg_99 = i_reg_330.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read()) && 
                esl_seteq<1,1,1>(grp_KeyExpansion_fu_143_ap_done.read(), ap_const_logic_1))) {
        i_0_reg_99 = ap_const_lv3_0;
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state8.read()) && 
         esl_seteq<1,1,1>(icmp_ln193_fu_274_p2.read(), ap_const_lv1_1))) {
        i_1_reg_121 = i_11_reg_366.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state6.read()) && 
                esl_seteq<1,1,1>(grp_Cipher_fu_155_ap_done.read(), ap_const_logic_1))) {
        i_1_reg_121 = ap_const_lv3_0;
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read()) && 
         esl_seteq<1,1,1>(icmp_ln164_fu_163_p2.read(), ap_const_lv1_0))) {
        j_0_reg_110 = ap_const_lv3_0;
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state5.read())) {
        j_0_reg_110 = j_reg_348.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state7.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, icmp_ln191_fu_238_p2.read()))) {
        j_1_reg_132 = ap_const_lv3_0;
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state9.read())) {
        j_1_reg_132 = j_9_reg_384.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state4.read()) && esl_seteq<1,1,1>(ap_const_lv1_0, icmp_ln166_fu_199_p2.read()))) {
        add_ln168_2_reg_358 = add_ln168_2_fu_229_p2.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state8.read()) && esl_seteq<1,1,1>(ap_const_lv1_0, icmp_ln193_fu_274_p2.read()))) {
        add_ln195_1_reg_394 = add_ln195_1_fu_313_p2.read();
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state7.read())) {
        i_11_reg_366 = i_11_fu_244_p2.read();
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read())) {
        i_reg_330 = i_fu_169_p2.read();
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state8.read())) {
        j_9_reg_384 = j_9_fu_280_p2.read();
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state4.read())) {
        j_reg_348 = j_fu_205_p2.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state7.read()) && esl_seteq<1,1,1>(ap_const_lv1_0, icmp_ln191_fu_238_p2.read()))) {
        shl_ln3_reg_376 = shl_ln3_fu_266_p3.read();
        zext_ln195_reg_371 = zext_ln195_fu_258_p1.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read()) && esl_seteq<1,1,1>(icmp_ln164_fu_163_p2.read(), ap_const_lv1_0))) {
        shl_ln_reg_335 = shl_ln_fu_179_p3.read();
        zext_ln166_reg_340 = zext_ln166_fu_195_p1.read();
    }
}

void AES256_ECB::thread_add_ln168_2_fu_229_p2() {
    add_ln168_2_fu_229_p2 = (!zext_ln166_reg_340.read().is_01() || !zext_ln168_5_fu_225_p1.read().is_01())? sc_lv<6>(): (sc_biguint<6>(zext_ln166_reg_340.read()) + sc_biguint<6>(zext_ln168_5_fu_225_p1.read()));
}

void AES256_ECB::thread_add_ln168_fu_215_p2() {
    add_ln168_fu_215_p2 = (!zext_ln168_fu_211_p1.read().is_01() || !shl_ln_reg_335.read().is_01())? sc_lv<4>(): (sc_biguint<4>(zext_ln168_fu_211_p1.read()) + sc_biguint<4>(shl_ln_reg_335.read()));
}

void AES256_ECB::thread_add_ln195_1_fu_313_p2() {
    add_ln195_1_fu_313_p2 = (!buffer_offset.read().is_01() || !zext_ln195_5_fu_309_p1.read().is_01())? sc_lv<6>(): (sc_biguint<6>(buffer_offset.read()) + sc_biguint<6>(zext_ln195_5_fu_309_p1.read()));
}

void AES256_ECB::thread_add_ln195_2_fu_290_p2() {
    add_ln195_2_fu_290_p2 = (!zext_ln195_reg_371.read().is_01() || !zext_ln195_7_fu_286_p1.read().is_01())? sc_lv<6>(): (sc_biguint<6>(zext_ln195_reg_371.read()) + sc_biguint<6>(zext_ln195_7_fu_286_p1.read()));
}

void AES256_ECB::thread_add_ln195_fu_304_p2() {
    add_ln195_fu_304_p2 = (!zext_ln195_4_fu_300_p1.read().is_01() || !shl_ln3_reg_376.read().is_01())? sc_lv<4>(): (sc_biguint<4>(zext_ln195_4_fu_300_p1.read()) + sc_biguint<4>(shl_ln3_reg_376.read()));
}

void AES256_ECB::thread_ap_CS_fsm_state1() {
    ap_CS_fsm_state1 = ap_CS_fsm.read()[0];
}

void AES256_ECB::thread_ap_CS_fsm_state2() {
    ap_CS_fsm_state2 = ap_CS_fsm.read()[1];
}

void AES256_ECB::thread_ap_CS_fsm_state3() {
    ap_CS_fsm_state3 = ap_CS_fsm.read()[2];
}

void AES256_ECB::thread_ap_CS_fsm_state4() {
    ap_CS_fsm_state4 = ap_CS_fsm.read()[3];
}

void AES256_ECB::thread_ap_CS_fsm_state5() {
    ap_CS_fsm_state5 = ap_CS_fsm.read()[4];
}

void AES256_ECB::thread_ap_CS_fsm_state6() {
    ap_CS_fsm_state6 = ap_CS_fsm.read()[5];
}

void AES256_ECB::thread_ap_CS_fsm_state7() {
    ap_CS_fsm_state7 = ap_CS_fsm.read()[6];
}

void AES256_ECB::thread_ap_CS_fsm_state8() {
    ap_CS_fsm_state8 = ap_CS_fsm.read()[7];
}

void AES256_ECB::thread_ap_CS_fsm_state9() {
    ap_CS_fsm_state9 = ap_CS_fsm.read()[8];
}

void AES256_ECB::thread_ap_done() {
    if (((esl_seteq<1,1,1>(ap_const_logic_0, ap_start.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state7.read()) && 
          esl_seteq<1,1,1>(icmp_ln191_fu_238_p2.read(), ap_const_lv1_1)))) {
        ap_done = ap_const_logic_1;
    } else {
        ap_done = ap_const_logic_0;
    }
}

void AES256_ECB::thread_ap_idle() {
    if ((esl_seteq<1,1,1>(ap_const_logic_0, ap_start.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()))) {
        ap_idle = ap_const_logic_1;
    } else {
        ap_idle = ap_const_logic_0;
    }
}

void AES256_ECB::thread_ap_ready() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state7.read()) && 
         esl_seteq<1,1,1>(icmp_ln191_fu_238_p2.read(), ap_const_lv1_1))) {
        ap_ready = ap_const_logic_1;
    } else {
        ap_ready = ap_const_logic_0;
    }
}

void AES256_ECB::thread_buffer_r_address0() {
    buffer_r_address0 =  (sc_lv<6>) (zext_ln195_6_fu_318_p1.read());
}

void AES256_ECB::thread_buffer_r_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state9.read())) {
        buffer_r_ce0 = ap_const_logic_1;
    } else {
        buffer_r_ce0 = ap_const_logic_0;
    }
}

void AES256_ECB::thread_buffer_r_d0() {
    buffer_r_d0 = test_q0.read();
}

void AES256_ECB::thread_buffer_r_we0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state9.read())) {
        buffer_r_we0 = ap_const_logic_1;
    } else {
        buffer_r_we0 = ap_const_logic_0;
    }
}

void AES256_ECB::thread_ctr_address0() {
    ctr_address0 =  (sc_lv<4>) (zext_ln168_4_fu_220_p1.read());
}

void AES256_ECB::thread_ctr_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state4.read())) {
        ctr_ce0 = ap_const_logic_1;
    } else {
        ctr_ce0 = ap_const_logic_0;
    }
}

void AES256_ECB::thread_ctx_RoundKey_address0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state6.read())) {
        ctx_RoundKey_address0 = grp_Cipher_fu_155_RoundKey_address0.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read())) {
        ctx_RoundKey_address0 = grp_KeyExpansion_fu_143_RoundKey_address0.read();
    } else {
        ctx_RoundKey_address0 = "XXXXXXXX";
    }
}

void AES256_ECB::thread_ctx_RoundKey_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state6.read())) {
        ctx_RoundKey_ce0 = grp_Cipher_fu_155_RoundKey_ce0.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read())) {
        ctx_RoundKey_ce0 = grp_KeyExpansion_fu_143_RoundKey_ce0.read();
    } else {
        ctx_RoundKey_ce0 = ap_const_logic_0;
    }
}

void AES256_ECB::thread_ctx_RoundKey_we0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read())) {
        ctx_RoundKey_we0 = grp_KeyExpansion_fu_143_RoundKey_we0.read();
    } else {
        ctx_RoundKey_we0 = ap_const_logic_0;
    }
}

void AES256_ECB::thread_grp_Cipher_fu_155_ap_start() {
    grp_Cipher_fu_155_ap_start = grp_Cipher_fu_155_ap_start_reg.read();
}

void AES256_ECB::thread_grp_KeyExpansion_fu_143_ap_start() {
    grp_KeyExpansion_fu_143_ap_start = grp_KeyExpansion_fu_143_ap_start_reg.read();
}

void AES256_ECB::thread_i_11_fu_244_p2() {
    i_11_fu_244_p2 = (!i_1_reg_121.read().is_01() || !ap_const_lv3_1.is_01())? sc_lv<3>(): (sc_biguint<3>(i_1_reg_121.read()) + sc_biguint<3>(ap_const_lv3_1));
}

void AES256_ECB::thread_i_fu_169_p2() {
    i_fu_169_p2 = (!i_0_reg_99.read().is_01() || !ap_const_lv3_1.is_01())? sc_lv<3>(): (sc_biguint<3>(i_0_reg_99.read()) + sc_biguint<3>(ap_const_lv3_1));
}

void AES256_ECB::thread_icmp_ln164_fu_163_p2() {
    icmp_ln164_fu_163_p2 = (!i_0_reg_99.read().is_01() || !ap_const_lv3_4.is_01())? sc_lv<1>(): sc_lv<1>(i_0_reg_99.read() == ap_const_lv3_4);
}

void AES256_ECB::thread_icmp_ln166_fu_199_p2() {
    icmp_ln166_fu_199_p2 = (!j_0_reg_110.read().is_01() || !ap_const_lv3_4.is_01())? sc_lv<1>(): sc_lv<1>(j_0_reg_110.read() == ap_const_lv3_4);
}

void AES256_ECB::thread_icmp_ln191_fu_238_p2() {
    icmp_ln191_fu_238_p2 = (!i_1_reg_121.read().is_01() || !ap_const_lv3_4.is_01())? sc_lv<1>(): sc_lv<1>(i_1_reg_121.read() == ap_const_lv3_4);
}

void AES256_ECB::thread_icmp_ln193_fu_274_p2() {
    icmp_ln193_fu_274_p2 = (!j_1_reg_132.read().is_01() || !ap_const_lv3_4.is_01())? sc_lv<1>(): sc_lv<1>(j_1_reg_132.read() == ap_const_lv3_4);
}

void AES256_ECB::thread_j_9_fu_280_p2() {
    j_9_fu_280_p2 = (!j_1_reg_132.read().is_01() || !ap_const_lv3_1.is_01())? sc_lv<3>(): (sc_biguint<3>(j_1_reg_132.read()) + sc_biguint<3>(ap_const_lv3_1));
}

void AES256_ECB::thread_j_fu_205_p2() {
    j_fu_205_p2 = (!j_0_reg_110.read().is_01() || !ap_const_lv3_1.is_01())? sc_lv<3>(): (sc_biguint<3>(j_0_reg_110.read()) + sc_biguint<3>(ap_const_lv3_1));
}

void AES256_ECB::thread_key_address0() {
    key_address0 = grp_KeyExpansion_fu_143_Key_address0.read();
}

void AES256_ECB::thread_key_ce0() {
    key_ce0 = grp_KeyExpansion_fu_143_Key_ce0.read();
}

void AES256_ECB::thread_shl_ln3_fu_266_p3() {
    shl_ln3_fu_266_p3 = esl_concat<2,2>(trunc_ln195_fu_262_p1.read(), ap_const_lv2_0);
}

void AES256_ECB::thread_shl_ln_fu_179_p3() {
    shl_ln_fu_179_p3 = esl_concat<2,2>(trunc_ln168_fu_175_p1.read(), ap_const_lv2_0);
}

void AES256_ECB::thread_test_address0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state8.read())) {
        test_address0 =  (sc_lv<4>) (zext_ln195_8_fu_295_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state5.read())) {
        test_address0 =  (sc_lv<4>) (zext_ln168_6_fu_234_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state6.read())) {
        test_address0 = grp_Cipher_fu_155_state_address0.read();
    } else {
        test_address0 =  (sc_lv<4>) ("XXXX");
    }
}

void AES256_ECB::thread_test_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state8.read()) || 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state5.read()))) {
        test_ce0 = ap_const_logic_1;
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state6.read())) {
        test_ce0 = grp_Cipher_fu_155_state_ce0.read();
    } else {
        test_ce0 = ap_const_logic_0;
    }
}

void AES256_ECB::thread_test_ce1() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state6.read())) {
        test_ce1 = grp_Cipher_fu_155_state_ce1.read();
    } else {
        test_ce1 = ap_const_logic_0;
    }
}

void AES256_ECB::thread_test_d0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state5.read())) {
        test_d0 = ctr_q0.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state6.read())) {
        test_d0 = grp_Cipher_fu_155_state_d0.read();
    } else {
        test_d0 = "XXXXXXXX";
    }
}

void AES256_ECB::thread_test_we0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state5.read())) {
        test_we0 = ap_const_logic_1;
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state6.read())) {
        test_we0 = grp_Cipher_fu_155_state_we0.read();
    } else {
        test_we0 = ap_const_logic_0;
    }
}

void AES256_ECB::thread_test_we1() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state6.read())) {
        test_we1 = grp_Cipher_fu_155_state_we1.read();
    } else {
        test_we1 = ap_const_logic_0;
    }
}

void AES256_ECB::thread_tmp_4_fu_250_p3() {
    tmp_4_fu_250_p3 = esl_concat<3,2>(i_1_reg_121.read(), ap_const_lv2_0);
}

void AES256_ECB::thread_tmp_s_fu_187_p3() {
    tmp_s_fu_187_p3 = esl_concat<3,2>(i_0_reg_99.read(), ap_const_lv2_0);
}

void AES256_ECB::thread_trunc_ln168_fu_175_p1() {
    trunc_ln168_fu_175_p1 = i_0_reg_99.read().range(2-1, 0);
}

void AES256_ECB::thread_trunc_ln195_fu_262_p1() {
    trunc_ln195_fu_262_p1 = i_1_reg_121.read().range(2-1, 0);
}

void AES256_ECB::thread_zext_ln166_fu_195_p1() {
    zext_ln166_fu_195_p1 = esl_zext<6,5>(tmp_s_fu_187_p3.read());
}

void AES256_ECB::thread_zext_ln168_4_fu_220_p1() {
    zext_ln168_4_fu_220_p1 = esl_zext<64,4>(add_ln168_fu_215_p2.read());
}

void AES256_ECB::thread_zext_ln168_5_fu_225_p1() {
    zext_ln168_5_fu_225_p1 = esl_zext<6,3>(j_0_reg_110.read());
}

void AES256_ECB::thread_zext_ln168_6_fu_234_p1() {
    zext_ln168_6_fu_234_p1 = esl_zext<64,6>(add_ln168_2_reg_358.read());
}

void AES256_ECB::thread_zext_ln168_fu_211_p1() {
    zext_ln168_fu_211_p1 = esl_zext<4,3>(j_0_reg_110.read());
}

void AES256_ECB::thread_zext_ln195_4_fu_300_p1() {
    zext_ln195_4_fu_300_p1 = esl_zext<4,3>(j_1_reg_132.read());
}

void AES256_ECB::thread_zext_ln195_5_fu_309_p1() {
    zext_ln195_5_fu_309_p1 = esl_zext<6,4>(add_ln195_fu_304_p2.read());
}

void AES256_ECB::thread_zext_ln195_6_fu_318_p1() {
    zext_ln195_6_fu_318_p1 = esl_zext<64,6>(add_ln195_1_reg_394.read());
}

void AES256_ECB::thread_zext_ln195_7_fu_286_p1() {
    zext_ln195_7_fu_286_p1 = esl_zext<6,3>(j_1_reg_132.read());
}

void AES256_ECB::thread_zext_ln195_8_fu_295_p1() {
    zext_ln195_8_fu_295_p1 = esl_zext<64,6>(add_ln195_2_fu_290_p2.read());
}

void AES256_ECB::thread_zext_ln195_fu_258_p1() {
    zext_ln195_fu_258_p1 = esl_zext<6,5>(tmp_4_fu_250_p3.read());
}

void AES256_ECB::thread_ap_NS_fsm() {
    switch (ap_CS_fsm.read().to_uint64()) {
        case 1 : 
            if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_1))) {
                ap_NS_fsm = ap_ST_fsm_state2;
            } else {
                ap_NS_fsm = ap_ST_fsm_state1;
            }
            break;
        case 2 : 
            if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read()) && esl_seteq<1,1,1>(grp_KeyExpansion_fu_143_ap_done.read(), ap_const_logic_1))) {
                ap_NS_fsm = ap_ST_fsm_state3;
            } else {
                ap_NS_fsm = ap_ST_fsm_state2;
            }
            break;
        case 4 : 
            if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read()) && esl_seteq<1,1,1>(icmp_ln164_fu_163_p2.read(), ap_const_lv1_0))) {
                ap_NS_fsm = ap_ST_fsm_state4;
            } else {
                ap_NS_fsm = ap_ST_fsm_state6;
            }
            break;
        case 8 : 
            if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state4.read()) && esl_seteq<1,1,1>(icmp_ln166_fu_199_p2.read(), ap_const_lv1_1))) {
                ap_NS_fsm = ap_ST_fsm_state3;
            } else {
                ap_NS_fsm = ap_ST_fsm_state5;
            }
            break;
        case 16 : 
            ap_NS_fsm = ap_ST_fsm_state4;
            break;
        case 32 : 
            if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state6.read()) && esl_seteq<1,1,1>(grp_Cipher_fu_155_ap_done.read(), ap_const_logic_1))) {
                ap_NS_fsm = ap_ST_fsm_state7;
            } else {
                ap_NS_fsm = ap_ST_fsm_state6;
            }
            break;
        case 64 : 
            if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state7.read()) && esl_seteq<1,1,1>(icmp_ln191_fu_238_p2.read(), ap_const_lv1_1))) {
                ap_NS_fsm = ap_ST_fsm_state1;
            } else {
                ap_NS_fsm = ap_ST_fsm_state8;
            }
            break;
        case 128 : 
            if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state8.read()) && esl_seteq<1,1,1>(icmp_ln193_fu_274_p2.read(), ap_const_lv1_1))) {
                ap_NS_fsm = ap_ST_fsm_state7;
            } else {
                ap_NS_fsm = ap_ST_fsm_state9;
            }
            break;
        case 256 : 
            ap_NS_fsm = ap_ST_fsm_state8;
            break;
        default : 
            ap_NS_fsm =  (sc_lv<9>) ("XXXXXXXXX");
            break;
    }
}

}
