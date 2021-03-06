// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and OpenCL
// Version: 2019.2
// Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

`timescale 1 ns / 1 ps 

(* CORE_GENERATION_INFO="crypto_sign_keypair,hls_ip_2019_2,{HLS_INPUT_TYPE=c,HLS_INPUT_FLOAT=0,HLS_INPUT_FIXED=0,HLS_INPUT_PART=xc7a200t-fbg676-2,HLS_INPUT_CLOCK=10.000000,HLS_INPUT_ARCH=others,HLS_SYN_CLOCK=8.365833,HLS_SYN_LAT=69978,HLS_SYN_TPT=none,HLS_SYN_MEM=78,HLS_SYN_DSP=0,HLS_SYN_FF=2371,HLS_SYN_LUT=10288,HLS_VERSION=2019_2}" *)

module crypto_sign_keypair (
        ap_clk,
        ap_rst,
        ap_start,
        ap_done,
        ap_idle,
        ap_ready,
        pk_address0,
        pk_ce0,
        pk_we0,
        pk_d0,
        sk_address0,
        sk_ce0,
        sk_we0,
        sk_d0,
        sk_address1,
        sk_ce1,
        sk_we1,
        sk_d1,
        params,
        DRBG_ctx_V_address0,
        DRBG_ctx_V_ce0,
        DRBG_ctx_V_we0,
        DRBG_ctx_V_d0,
        DRBG_ctx_V_q0,
        DRBG_ctx_Key_address0,
        DRBG_ctx_Key_ce0,
        DRBG_ctx_Key_we0,
        DRBG_ctx_Key_d0,
        DRBG_ctx_Key_q0,
        DRBG_ctx_reseed_counter_i,
        DRBG_ctx_reseed_counter_o,
        DRBG_ctx_reseed_counter_o_ap_vld,
        ap_return
);

parameter    ap_ST_fsm_state1 = 10'd1;
parameter    ap_ST_fsm_state2 = 10'd2;
parameter    ap_ST_fsm_state3 = 10'd4;
parameter    ap_ST_fsm_state4 = 10'd8;
parameter    ap_ST_fsm_state5 = 10'd16;
parameter    ap_ST_fsm_state6 = 10'd32;
parameter    ap_ST_fsm_state7 = 10'd64;
parameter    ap_ST_fsm_state8 = 10'd128;
parameter    ap_ST_fsm_state9 = 10'd256;
parameter    ap_ST_fsm_state10 = 10'd512;

input   ap_clk;
input   ap_rst;
input   ap_start;
output   ap_done;
output   ap_idle;
output   ap_ready;
output  [5:0] pk_address0;
output   pk_ce0;
output   pk_we0;
output  [7:0] pk_d0;
output  [5:0] sk_address0;
output   sk_ce0;
output   sk_we0;
output  [7:0] sk_d0;
output  [5:0] sk_address1;
output   sk_ce1;
output   sk_we1;
output  [7:0] sk_d1;
input  [3:0] params;
output  [3:0] DRBG_ctx_V_address0;
output   DRBG_ctx_V_ce0;
output   DRBG_ctx_V_we0;
output  [7:0] DRBG_ctx_V_d0;
input  [7:0] DRBG_ctx_V_q0;
output  [4:0] DRBG_ctx_Key_address0;
output   DRBG_ctx_Key_ce0;
output   DRBG_ctx_Key_we0;
output  [7:0] DRBG_ctx_Key_d0;
input  [7:0] DRBG_ctx_Key_q0;
input  [31:0] DRBG_ctx_reseed_counter_i;
output  [31:0] DRBG_ctx_reseed_counter_o;
output   DRBG_ctx_reseed_counter_o_ap_vld;
output  [31:0] ap_return;

reg ap_done;
reg ap_idle;
reg ap_ready;
reg[5:0] pk_address0;
reg pk_ce0;
reg pk_we0;
reg[7:0] pk_d0;
reg[5:0] sk_address0;
reg sk_ce0;
reg sk_we0;
reg[7:0] sk_d0;
reg[5:0] sk_address1;
reg sk_ce1;
reg sk_we1;
reg[7:0] sk_d1;
reg[31:0] DRBG_ctx_reseed_counter_o;

(* fsm_encoding = "none" *) reg   [9:0] ap_CS_fsm;
wire    ap_CS_fsm_state1;
wire    ap_CS_fsm_state2;
wire    grp_picnic_keygen_fu_250_ap_ready;
wire    grp_picnic_keygen_fu_250_ap_done;
reg   [3:0] secret_params_reg_422;
wire   [4:0] loop_fu_315_p2;
reg   [4:0] loop_reg_433;
wire    ap_CS_fsm_state3;
wire   [0:0] icmp_ln538_fu_309_p2;
wire   [5:0] zext_ln541_fu_330_p1;
reg   [5:0] zext_ln541_reg_444;
wire    ap_CS_fsm_state5;
wire   [4:0] loop_5_fu_340_p2;
reg   [4:0] loop_5_reg_452;
wire   [0:0] icmp_ln541_fu_334_p2;
wire   [5:0] sext_ln614_i_cast_fu_372_p1;
reg   [5:0] sext_ln614_i_cast_reg_462;
wire    ap_CS_fsm_state7;
wire   [4:0] loop_6_fu_382_p2;
reg   [4:0] loop_6_reg_471;
wire   [0:0] icmp_ln614_fu_376_p2;
wire   [7:0] secret_pk_plaintext_q0;
reg   [7:0] secret_pk_plaintext_1_reg_492;
wire    ap_CS_fsm_state8;
reg   [4:0] pubkey_plaintext_address0;
reg    pubkey_plaintext_ce0;
reg    pubkey_plaintext_we0;
wire   [7:0] pubkey_plaintext_q0;
reg    pubkey_plaintext_ce1;
wire   [7:0] pubkey_plaintext_q1;
reg   [4:0] pubkey_ciphertext_address0;
reg    pubkey_ciphertext_ce0;
reg    pubkey_ciphertext_we0;
wire   [7:0] pubkey_ciphertext_q0;
reg    pubkey_ciphertext_ce1;
wire   [7:0] pubkey_ciphertext_q1;
reg   [4:0] secret_data_address0;
reg    secret_data_ce0;
reg    secret_data_we0;
wire   [7:0] secret_data_q0;
reg    secret_data_ce1;
wire   [7:0] secret_data_q1;
reg   [4:0] secret_pk_plaintext_address0;
reg    secret_pk_plaintext_ce0;
reg    secret_pk_plaintext_we0;
reg   [4:0] secret_pk_ciphertext_address0;
reg    secret_pk_ciphertext_ce0;
reg    secret_pk_ciphertext_we0;
wire   [7:0] secret_pk_ciphertext_q0;
wire    grp_picnic_keygen_fu_250_ap_start;
wire    grp_picnic_keygen_fu_250_ap_idle;
wire   [4:0] grp_picnic_keygen_fu_250_pk_plaintext_address0;
wire    grp_picnic_keygen_fu_250_pk_plaintext_ce0;
wire    grp_picnic_keygen_fu_250_pk_plaintext_we0;
wire   [7:0] grp_picnic_keygen_fu_250_pk_plaintext_d0;
wire   [4:0] grp_picnic_keygen_fu_250_pk_plaintext_address1;
wire    grp_picnic_keygen_fu_250_pk_plaintext_ce1;
wire   [4:0] grp_picnic_keygen_fu_250_pk_ciphertext_address0;
wire    grp_picnic_keygen_fu_250_pk_ciphertext_ce0;
wire    grp_picnic_keygen_fu_250_pk_ciphertext_we0;
wire   [7:0] grp_picnic_keygen_fu_250_pk_ciphertext_d0;
wire   [4:0] grp_picnic_keygen_fu_250_pk_ciphertext_address1;
wire    grp_picnic_keygen_fu_250_pk_ciphertext_ce1;
wire   [4:0] grp_picnic_keygen_fu_250_sk_data_address0;
wire    grp_picnic_keygen_fu_250_sk_data_ce0;
wire    grp_picnic_keygen_fu_250_sk_data_we0;
wire   [7:0] grp_picnic_keygen_fu_250_sk_data_d0;
wire   [4:0] grp_picnic_keygen_fu_250_sk_data_address1;
wire    grp_picnic_keygen_fu_250_sk_data_ce1;
wire   [4:0] grp_picnic_keygen_fu_250_sk_pk_plaintext_address0;
wire    grp_picnic_keygen_fu_250_sk_pk_plaintext_ce0;
wire    grp_picnic_keygen_fu_250_sk_pk_plaintext_we0;
wire   [7:0] grp_picnic_keygen_fu_250_sk_pk_plaintext_d0;
wire   [4:0] grp_picnic_keygen_fu_250_sk_pk_ciphertext_address0;
wire    grp_picnic_keygen_fu_250_sk_pk_ciphertext_ce0;
wire    grp_picnic_keygen_fu_250_sk_pk_ciphertext_we0;
wire   [7:0] grp_picnic_keygen_fu_250_sk_pk_ciphertext_d0;
wire   [3:0] grp_picnic_keygen_fu_250_DRBG_ctx_V_address0;
wire    grp_picnic_keygen_fu_250_DRBG_ctx_V_ce0;
wire    grp_picnic_keygen_fu_250_DRBG_ctx_V_we0;
wire   [7:0] grp_picnic_keygen_fu_250_DRBG_ctx_V_d0;
wire   [4:0] grp_picnic_keygen_fu_250_DRBG_ctx_Key_address0;
wire    grp_picnic_keygen_fu_250_DRBG_ctx_Key_ce0;
wire    grp_picnic_keygen_fu_250_DRBG_ctx_Key_we0;
wire   [7:0] grp_picnic_keygen_fu_250_DRBG_ctx_Key_d0;
wire   [31:0] grp_picnic_keygen_fu_250_DRBG_ctx_reseed_counter_o;
wire    grp_picnic_keygen_fu_250_DRBG_ctx_reseed_counter_o_ap_vld;
wire   [31:0] grp_picnic_keygen_fu_250_ap_return_0;
wire   [3:0] grp_picnic_keygen_fu_250_ap_return_1;
wire   [3:0] grp_picnic_keygen_fu_250_ap_return_2;
reg   [4:0] loop_0_i_reg_206;
wire   [0:0] icmp_ln66_fu_298_p2;
wire    ap_CS_fsm_state4;
reg   [4:0] loop_1_i_reg_217;
wire    ap_CS_fsm_state6;
reg   [4:0] loop_0_i2_reg_228;
wire    ap_CS_fsm_state9;
reg   [31:0] UnifiedRetVal_reg_239;
reg    grp_picnic_keygen_fu_250_ap_start_reg;
wire   [63:0] zext_ln539_fu_321_p1;
wire   [63:0] zext_ln539_1_fu_326_p1;
wire   [63:0] zext_ln542_fu_346_p1;
wire   [63:0] zext_ln542_1_fu_360_p1;
wire   [63:0] zext_ln614_fu_365_p1;
wire   [63:0] zext_ln615_fu_388_p1;
wire   [63:0] zext_ln616_fu_397_p1;
wire   [63:0] zext_ln617_fu_407_p1;
wire   [7:0] zext_ln535_fu_304_p1;
wire   [7:0] zext_ln609_fu_351_p1;
wire   [5:0] add_ln542_1_fu_355_p2;
wire   [5:0] add_ln616_fu_392_p2;
wire   [5:0] add_ln617_fu_402_p2;
wire    ap_CS_fsm_state10;
reg   [9:0] ap_NS_fsm;

// power-on initialization
initial begin
#0 ap_CS_fsm = 10'd1;
#0 grp_picnic_keygen_fu_250_ap_start_reg = 1'b0;
end

crypto_sign_keypahbi #(
    .DataWidth( 8 ),
    .AddressRange( 32 ),
    .AddressWidth( 5 ))
pubkey_plaintext_U(
    .clk(ap_clk),
    .reset(ap_rst),
    .address0(pubkey_plaintext_address0),
    .ce0(pubkey_plaintext_ce0),
    .we0(pubkey_plaintext_we0),
    .d0(grp_picnic_keygen_fu_250_pk_plaintext_d0),
    .q0(pubkey_plaintext_q0),
    .address1(grp_picnic_keygen_fu_250_pk_plaintext_address1),
    .ce1(pubkey_plaintext_ce1),
    .q1(pubkey_plaintext_q1)
);

crypto_sign_keypahbi #(
    .DataWidth( 8 ),
    .AddressRange( 32 ),
    .AddressWidth( 5 ))
pubkey_ciphertext_U(
    .clk(ap_clk),
    .reset(ap_rst),
    .address0(pubkey_ciphertext_address0),
    .ce0(pubkey_ciphertext_ce0),
    .we0(pubkey_ciphertext_we0),
    .d0(grp_picnic_keygen_fu_250_pk_ciphertext_d0),
    .q0(pubkey_ciphertext_q0),
    .address1(grp_picnic_keygen_fu_250_pk_ciphertext_address1),
    .ce1(pubkey_ciphertext_ce1),
    .q1(pubkey_ciphertext_q1)
);

crypto_sign_keypahbi #(
    .DataWidth( 8 ),
    .AddressRange( 32 ),
    .AddressWidth( 5 ))
secret_data_U(
    .clk(ap_clk),
    .reset(ap_rst),
    .address0(secret_data_address0),
    .ce0(secret_data_ce0),
    .we0(secret_data_we0),
    .d0(grp_picnic_keygen_fu_250_sk_data_d0),
    .q0(secret_data_q0),
    .address1(grp_picnic_keygen_fu_250_sk_data_address1),
    .ce1(secret_data_ce1),
    .q1(secret_data_q1)
);

crypto_sign_keypakbM #(
    .DataWidth( 8 ),
    .AddressRange( 32 ),
    .AddressWidth( 5 ))
secret_pk_plaintext_U(
    .clk(ap_clk),
    .reset(ap_rst),
    .address0(secret_pk_plaintext_address0),
    .ce0(secret_pk_plaintext_ce0),
    .we0(secret_pk_plaintext_we0),
    .d0(grp_picnic_keygen_fu_250_sk_pk_plaintext_d0),
    .q0(secret_pk_plaintext_q0)
);

crypto_sign_keypakbM #(
    .DataWidth( 8 ),
    .AddressRange( 32 ),
    .AddressWidth( 5 ))
secret_pk_ciphertext_U(
    .clk(ap_clk),
    .reset(ap_rst),
    .address0(secret_pk_ciphertext_address0),
    .ce0(secret_pk_ciphertext_ce0),
    .we0(secret_pk_ciphertext_we0),
    .d0(grp_picnic_keygen_fu_250_sk_pk_ciphertext_d0),
    .q0(secret_pk_ciphertext_q0)
);

picnic_keygen grp_picnic_keygen_fu_250(
    .ap_clk(ap_clk),
    .ap_rst(ap_rst),
    .ap_start(grp_picnic_keygen_fu_250_ap_start),
    .ap_done(grp_picnic_keygen_fu_250_ap_done),
    .ap_idle(grp_picnic_keygen_fu_250_ap_idle),
    .ap_ready(grp_picnic_keygen_fu_250_ap_ready),
    .parameters(params),
    .pk_plaintext_address0(grp_picnic_keygen_fu_250_pk_plaintext_address0),
    .pk_plaintext_ce0(grp_picnic_keygen_fu_250_pk_plaintext_ce0),
    .pk_plaintext_we0(grp_picnic_keygen_fu_250_pk_plaintext_we0),
    .pk_plaintext_d0(grp_picnic_keygen_fu_250_pk_plaintext_d0),
    .pk_plaintext_q0(pubkey_plaintext_q0),
    .pk_plaintext_address1(grp_picnic_keygen_fu_250_pk_plaintext_address1),
    .pk_plaintext_ce1(grp_picnic_keygen_fu_250_pk_plaintext_ce1),
    .pk_plaintext_q1(pubkey_plaintext_q1),
    .pk_ciphertext_address0(grp_picnic_keygen_fu_250_pk_ciphertext_address0),
    .pk_ciphertext_ce0(grp_picnic_keygen_fu_250_pk_ciphertext_ce0),
    .pk_ciphertext_we0(grp_picnic_keygen_fu_250_pk_ciphertext_we0),
    .pk_ciphertext_d0(grp_picnic_keygen_fu_250_pk_ciphertext_d0),
    .pk_ciphertext_q0(pubkey_ciphertext_q0),
    .pk_ciphertext_address1(grp_picnic_keygen_fu_250_pk_ciphertext_address1),
    .pk_ciphertext_ce1(grp_picnic_keygen_fu_250_pk_ciphertext_ce1),
    .pk_ciphertext_q1(pubkey_ciphertext_q1),
    .sk_data_address0(grp_picnic_keygen_fu_250_sk_data_address0),
    .sk_data_ce0(grp_picnic_keygen_fu_250_sk_data_ce0),
    .sk_data_we0(grp_picnic_keygen_fu_250_sk_data_we0),
    .sk_data_d0(grp_picnic_keygen_fu_250_sk_data_d0),
    .sk_data_q0(secret_data_q0),
    .sk_data_address1(grp_picnic_keygen_fu_250_sk_data_address1),
    .sk_data_ce1(grp_picnic_keygen_fu_250_sk_data_ce1),
    .sk_data_q1(secret_data_q1),
    .sk_pk_plaintext_address0(grp_picnic_keygen_fu_250_sk_pk_plaintext_address0),
    .sk_pk_plaintext_ce0(grp_picnic_keygen_fu_250_sk_pk_plaintext_ce0),
    .sk_pk_plaintext_we0(grp_picnic_keygen_fu_250_sk_pk_plaintext_we0),
    .sk_pk_plaintext_d0(grp_picnic_keygen_fu_250_sk_pk_plaintext_d0),
    .sk_pk_ciphertext_address0(grp_picnic_keygen_fu_250_sk_pk_ciphertext_address0),
    .sk_pk_ciphertext_ce0(grp_picnic_keygen_fu_250_sk_pk_ciphertext_ce0),
    .sk_pk_ciphertext_we0(grp_picnic_keygen_fu_250_sk_pk_ciphertext_we0),
    .sk_pk_ciphertext_d0(grp_picnic_keygen_fu_250_sk_pk_ciphertext_d0),
    .DRBG_ctx_V_address0(grp_picnic_keygen_fu_250_DRBG_ctx_V_address0),
    .DRBG_ctx_V_ce0(grp_picnic_keygen_fu_250_DRBG_ctx_V_ce0),
    .DRBG_ctx_V_we0(grp_picnic_keygen_fu_250_DRBG_ctx_V_we0),
    .DRBG_ctx_V_d0(grp_picnic_keygen_fu_250_DRBG_ctx_V_d0),
    .DRBG_ctx_V_q0(DRBG_ctx_V_q0),
    .DRBG_ctx_Key_address0(grp_picnic_keygen_fu_250_DRBG_ctx_Key_address0),
    .DRBG_ctx_Key_ce0(grp_picnic_keygen_fu_250_DRBG_ctx_Key_ce0),
    .DRBG_ctx_Key_we0(grp_picnic_keygen_fu_250_DRBG_ctx_Key_we0),
    .DRBG_ctx_Key_d0(grp_picnic_keygen_fu_250_DRBG_ctx_Key_d0),
    .DRBG_ctx_Key_q0(DRBG_ctx_Key_q0),
    .DRBG_ctx_reseed_counter_i(DRBG_ctx_reseed_counter_i),
    .DRBG_ctx_reseed_counter_o(grp_picnic_keygen_fu_250_DRBG_ctx_reseed_counter_o),
    .DRBG_ctx_reseed_counter_o_ap_vld(grp_picnic_keygen_fu_250_DRBG_ctx_reseed_counter_o_ap_vld),
    .ap_return_0(grp_picnic_keygen_fu_250_ap_return_0),
    .ap_return_1(grp_picnic_keygen_fu_250_ap_return_1),
    .ap_return_2(grp_picnic_keygen_fu_250_ap_return_2)
);

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_CS_fsm <= ap_ST_fsm_state1;
    end else begin
        ap_CS_fsm <= ap_NS_fsm;
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        grp_picnic_keygen_fu_250_ap_start_reg <= 1'b0;
    end else begin
        if (((1'b1 == ap_CS_fsm_state1) & (ap_start == 1'b1))) begin
            grp_picnic_keygen_fu_250_ap_start_reg <= 1'b1;
        end else if ((grp_picnic_keygen_fu_250_ap_ready == 1'b1)) begin
            grp_picnic_keygen_fu_250_ap_start_reg <= 1'b0;
        end
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_state7) & (icmp_ln614_fu_376_p2 == 1'd1))) begin
        UnifiedRetVal_reg_239 <= 32'd0;
    end else if (((icmp_ln66_fu_298_p2 == 1'd0) & (grp_picnic_keygen_fu_250_ap_done == 1'b1) & (1'b1 == ap_CS_fsm_state2))) begin
        UnifiedRetVal_reg_239 <= grp_picnic_keygen_fu_250_ap_return_0;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state9)) begin
        loop_0_i2_reg_228 <= loop_6_reg_471;
    end else if (((1'b1 == ap_CS_fsm_state5) & (icmp_ln541_fu_334_p2 == 1'd1))) begin
        loop_0_i2_reg_228 <= 5'd0;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state4)) begin
        loop_0_i_reg_206 <= loop_reg_433;
    end else if (((grp_picnic_keygen_fu_250_ap_done == 1'b1) & (icmp_ln66_fu_298_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2))) begin
        loop_0_i_reg_206 <= 5'd0;
    end
end

always @ (posedge ap_clk) begin
    if (((icmp_ln538_fu_309_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state3))) begin
        loop_1_i_reg_217 <= 5'd0;
    end else if ((1'b1 == ap_CS_fsm_state6)) begin
        loop_1_i_reg_217 <= loop_5_reg_452;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state5)) begin
        loop_5_reg_452 <= loop_5_fu_340_p2;
        zext_ln541_reg_444[4 : 0] <= zext_ln541_fu_330_p1[4 : 0];
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state7)) begin
        loop_6_reg_471 <= loop_6_fu_382_p2;
        sext_ln614_i_cast_reg_462[4 : 0] <= sext_ln614_i_cast_fu_372_p1[4 : 0];
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state3)) begin
        loop_reg_433 <= loop_fu_315_p2;
    end
end

always @ (posedge ap_clk) begin
    if (((grp_picnic_keygen_fu_250_ap_done == 1'b1) & (1'b1 == ap_CS_fsm_state2))) begin
        secret_params_reg_422 <= grp_picnic_keygen_fu_250_ap_return_2;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state8)) begin
        secret_pk_plaintext_1_reg_492 <= secret_pk_plaintext_q0;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state2) & (grp_picnic_keygen_fu_250_DRBG_ctx_reseed_counter_o_ap_vld == 1'b1))) begin
        DRBG_ctx_reseed_counter_o = grp_picnic_keygen_fu_250_DRBG_ctx_reseed_counter_o;
    end else begin
        DRBG_ctx_reseed_counter_o = DRBG_ctx_reseed_counter_i;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state10)) begin
        ap_done = 1'b1;
    end else begin
        ap_done = 1'b0;
    end
end

always @ (*) begin
    if (((ap_start == 1'b0) & (1'b1 == ap_CS_fsm_state1))) begin
        ap_idle = 1'b1;
    end else begin
        ap_idle = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state10)) begin
        ap_ready = 1'b1;
    end else begin
        ap_ready = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state6)) begin
        pk_address0 = zext_ln542_1_fu_360_p1;
    end else if ((1'b1 == ap_CS_fsm_state4)) begin
        pk_address0 = zext_ln539_1_fu_326_p1;
    end else if ((1'b1 == ap_CS_fsm_state2)) begin
        pk_address0 = 64'd0;
    end else begin
        pk_address0 = 'bx;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state6) | (1'b1 == ap_CS_fsm_state4) | ((grp_picnic_keygen_fu_250_ap_done == 1'b1) & (1'b1 == ap_CS_fsm_state2)))) begin
        pk_ce0 = 1'b1;
    end else begin
        pk_ce0 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state6)) begin
        pk_d0 = pubkey_plaintext_q0;
    end else if ((1'b1 == ap_CS_fsm_state4)) begin
        pk_d0 = pubkey_ciphertext_q0;
    end else if ((1'b1 == ap_CS_fsm_state2)) begin
        pk_d0 = zext_ln535_fu_304_p1;
    end else begin
        pk_d0 = 'bx;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state6) | (1'b1 == ap_CS_fsm_state4) | ((grp_picnic_keygen_fu_250_ap_done == 1'b1) & (icmp_ln66_fu_298_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2)))) begin
        pk_we0 = 1'b1;
    end else begin
        pk_we0 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state3)) begin
        pubkey_ciphertext_address0 = zext_ln539_fu_321_p1;
    end else if ((1'b1 == ap_CS_fsm_state2)) begin
        pubkey_ciphertext_address0 = grp_picnic_keygen_fu_250_pk_ciphertext_address0;
    end else begin
        pubkey_ciphertext_address0 = 'bx;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state3)) begin
        pubkey_ciphertext_ce0 = 1'b1;
    end else if ((1'b1 == ap_CS_fsm_state2)) begin
        pubkey_ciphertext_ce0 = grp_picnic_keygen_fu_250_pk_ciphertext_ce0;
    end else begin
        pubkey_ciphertext_ce0 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state2)) begin
        pubkey_ciphertext_ce1 = grp_picnic_keygen_fu_250_pk_ciphertext_ce1;
    end else begin
        pubkey_ciphertext_ce1 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state2)) begin
        pubkey_ciphertext_we0 = grp_picnic_keygen_fu_250_pk_ciphertext_we0;
    end else begin
        pubkey_ciphertext_we0 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state5)) begin
        pubkey_plaintext_address0 = zext_ln542_fu_346_p1;
    end else if ((1'b1 == ap_CS_fsm_state2)) begin
        pubkey_plaintext_address0 = grp_picnic_keygen_fu_250_pk_plaintext_address0;
    end else begin
        pubkey_plaintext_address0 = 'bx;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state5)) begin
        pubkey_plaintext_ce0 = 1'b1;
    end else if ((1'b1 == ap_CS_fsm_state2)) begin
        pubkey_plaintext_ce0 = grp_picnic_keygen_fu_250_pk_plaintext_ce0;
    end else begin
        pubkey_plaintext_ce0 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state2)) begin
        pubkey_plaintext_ce1 = grp_picnic_keygen_fu_250_pk_plaintext_ce1;
    end else begin
        pubkey_plaintext_ce1 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state2)) begin
        pubkey_plaintext_we0 = grp_picnic_keygen_fu_250_pk_plaintext_we0;
    end else begin
        pubkey_plaintext_we0 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state7)) begin
        secret_data_address0 = zext_ln614_fu_365_p1;
    end else if ((1'b1 == ap_CS_fsm_state2)) begin
        secret_data_address0 = grp_picnic_keygen_fu_250_sk_data_address0;
    end else begin
        secret_data_address0 = 'bx;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state7)) begin
        secret_data_ce0 = 1'b1;
    end else if ((1'b1 == ap_CS_fsm_state2)) begin
        secret_data_ce0 = grp_picnic_keygen_fu_250_sk_data_ce0;
    end else begin
        secret_data_ce0 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state2)) begin
        secret_data_ce1 = grp_picnic_keygen_fu_250_sk_data_ce1;
    end else begin
        secret_data_ce1 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state2)) begin
        secret_data_we0 = grp_picnic_keygen_fu_250_sk_data_we0;
    end else begin
        secret_data_we0 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state7)) begin
        secret_pk_ciphertext_address0 = zext_ln614_fu_365_p1;
    end else if ((1'b1 == ap_CS_fsm_state2)) begin
        secret_pk_ciphertext_address0 = grp_picnic_keygen_fu_250_sk_pk_ciphertext_address0;
    end else begin
        secret_pk_ciphertext_address0 = 'bx;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state7)) begin
        secret_pk_ciphertext_ce0 = 1'b1;
    end else if ((1'b1 == ap_CS_fsm_state2)) begin
        secret_pk_ciphertext_ce0 = grp_picnic_keygen_fu_250_sk_pk_ciphertext_ce0;
    end else begin
        secret_pk_ciphertext_ce0 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state2)) begin
        secret_pk_ciphertext_we0 = grp_picnic_keygen_fu_250_sk_pk_ciphertext_we0;
    end else begin
        secret_pk_ciphertext_we0 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state7)) begin
        secret_pk_plaintext_address0 = zext_ln614_fu_365_p1;
    end else if ((1'b1 == ap_CS_fsm_state2)) begin
        secret_pk_plaintext_address0 = grp_picnic_keygen_fu_250_sk_pk_plaintext_address0;
    end else begin
        secret_pk_plaintext_address0 = 'bx;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state7)) begin
        secret_pk_plaintext_ce0 = 1'b1;
    end else if ((1'b1 == ap_CS_fsm_state2)) begin
        secret_pk_plaintext_ce0 = grp_picnic_keygen_fu_250_sk_pk_plaintext_ce0;
    end else begin
        secret_pk_plaintext_ce0 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state2)) begin
        secret_pk_plaintext_we0 = grp_picnic_keygen_fu_250_sk_pk_plaintext_we0;
    end else begin
        secret_pk_plaintext_we0 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state8)) begin
        sk_address0 = zext_ln615_fu_388_p1;
    end else if ((1'b1 == ap_CS_fsm_state5)) begin
        sk_address0 = 64'd0;
    end else begin
        sk_address0 = 'bx;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state9)) begin
        sk_address1 = zext_ln617_fu_407_p1;
    end else if ((1'b1 == ap_CS_fsm_state8)) begin
        sk_address1 = zext_ln616_fu_397_p1;
    end else begin
        sk_address1 = 'bx;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state8) | (1'b1 == ap_CS_fsm_state5))) begin
        sk_ce0 = 1'b1;
    end else begin
        sk_ce0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state9) | (1'b1 == ap_CS_fsm_state8))) begin
        sk_ce1 = 1'b1;
    end else begin
        sk_ce1 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state8)) begin
        sk_d0 = secret_data_q0;
    end else if ((1'b1 == ap_CS_fsm_state5)) begin
        sk_d0 = zext_ln609_fu_351_p1;
    end else begin
        sk_d0 = 'bx;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state9)) begin
        sk_d1 = secret_pk_plaintext_1_reg_492;
    end else if ((1'b1 == ap_CS_fsm_state8)) begin
        sk_d1 = secret_pk_ciphertext_q0;
    end else begin
        sk_d1 = 'bx;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state8) | ((1'b1 == ap_CS_fsm_state5) & (icmp_ln541_fu_334_p2 == 1'd1)))) begin
        sk_we0 = 1'b1;
    end else begin
        sk_we0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state9) | (1'b1 == ap_CS_fsm_state8))) begin
        sk_we1 = 1'b1;
    end else begin
        sk_we1 = 1'b0;
    end
end

always @ (*) begin
    case (ap_CS_fsm)
        ap_ST_fsm_state1 : begin
            if (((1'b1 == ap_CS_fsm_state1) & (ap_start == 1'b1))) begin
                ap_NS_fsm = ap_ST_fsm_state2;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end
        end
        ap_ST_fsm_state2 : begin
            if (((grp_picnic_keygen_fu_250_ap_done == 1'b1) & (icmp_ln66_fu_298_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2))) begin
                ap_NS_fsm = ap_ST_fsm_state3;
            end else if (((icmp_ln66_fu_298_p2 == 1'd0) & (grp_picnic_keygen_fu_250_ap_done == 1'b1) & (1'b1 == ap_CS_fsm_state2))) begin
                ap_NS_fsm = ap_ST_fsm_state10;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state2;
            end
        end
        ap_ST_fsm_state3 : begin
            if (((icmp_ln538_fu_309_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state3))) begin
                ap_NS_fsm = ap_ST_fsm_state5;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state4;
            end
        end
        ap_ST_fsm_state4 : begin
            ap_NS_fsm = ap_ST_fsm_state3;
        end
        ap_ST_fsm_state5 : begin
            if (((1'b1 == ap_CS_fsm_state5) & (icmp_ln541_fu_334_p2 == 1'd1))) begin
                ap_NS_fsm = ap_ST_fsm_state7;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state6;
            end
        end
        ap_ST_fsm_state6 : begin
            ap_NS_fsm = ap_ST_fsm_state5;
        end
        ap_ST_fsm_state7 : begin
            if (((1'b1 == ap_CS_fsm_state7) & (icmp_ln614_fu_376_p2 == 1'd1))) begin
                ap_NS_fsm = ap_ST_fsm_state10;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state8;
            end
        end
        ap_ST_fsm_state8 : begin
            ap_NS_fsm = ap_ST_fsm_state9;
        end
        ap_ST_fsm_state9 : begin
            ap_NS_fsm = ap_ST_fsm_state7;
        end
        ap_ST_fsm_state10 : begin
            ap_NS_fsm = ap_ST_fsm_state1;
        end
        default : begin
            ap_NS_fsm = 'bx;
        end
    endcase
end

assign DRBG_ctx_Key_address0 = grp_picnic_keygen_fu_250_DRBG_ctx_Key_address0;

assign DRBG_ctx_Key_ce0 = grp_picnic_keygen_fu_250_DRBG_ctx_Key_ce0;

assign DRBG_ctx_Key_d0 = grp_picnic_keygen_fu_250_DRBG_ctx_Key_d0;

assign DRBG_ctx_Key_we0 = grp_picnic_keygen_fu_250_DRBG_ctx_Key_we0;

assign DRBG_ctx_V_address0 = grp_picnic_keygen_fu_250_DRBG_ctx_V_address0;

assign DRBG_ctx_V_ce0 = grp_picnic_keygen_fu_250_DRBG_ctx_V_ce0;

assign DRBG_ctx_V_d0 = grp_picnic_keygen_fu_250_DRBG_ctx_V_d0;

assign DRBG_ctx_V_we0 = grp_picnic_keygen_fu_250_DRBG_ctx_V_we0;

assign DRBG_ctx_reseed_counter_o_ap_vld = grp_picnic_keygen_fu_250_DRBG_ctx_reseed_counter_o_ap_vld;

assign add_ln542_1_fu_355_p2 = (zext_ln541_reg_444 + 6'd17);

assign add_ln616_fu_392_p2 = (sext_ln614_i_cast_reg_462 + 6'd17);

assign add_ln617_fu_402_p2 = ($signed(sext_ln614_i_cast_reg_462) + $signed(6'd33));

assign ap_CS_fsm_state1 = ap_CS_fsm[32'd0];

assign ap_CS_fsm_state10 = ap_CS_fsm[32'd9];

assign ap_CS_fsm_state2 = ap_CS_fsm[32'd1];

assign ap_CS_fsm_state3 = ap_CS_fsm[32'd2];

assign ap_CS_fsm_state4 = ap_CS_fsm[32'd3];

assign ap_CS_fsm_state5 = ap_CS_fsm[32'd4];

assign ap_CS_fsm_state6 = ap_CS_fsm[32'd5];

assign ap_CS_fsm_state7 = ap_CS_fsm[32'd6];

assign ap_CS_fsm_state8 = ap_CS_fsm[32'd7];

assign ap_CS_fsm_state9 = ap_CS_fsm[32'd8];

assign ap_return = UnifiedRetVal_reg_239;

assign grp_picnic_keygen_fu_250_ap_start = grp_picnic_keygen_fu_250_ap_start_reg;

assign icmp_ln538_fu_309_p2 = ((loop_0_i_reg_206 == 5'd16) ? 1'b1 : 1'b0);

assign icmp_ln541_fu_334_p2 = ((loop_1_i_reg_217 == 5'd16) ? 1'b1 : 1'b0);

assign icmp_ln614_fu_376_p2 = ((loop_0_i2_reg_228 == 5'd16) ? 1'b1 : 1'b0);

assign icmp_ln66_fu_298_p2 = ((grp_picnic_keygen_fu_250_ap_return_0 == 32'd0) ? 1'b1 : 1'b0);

assign loop_5_fu_340_p2 = (loop_1_i_reg_217 + 5'd1);

assign loop_6_fu_382_p2 = (loop_0_i2_reg_228 + 5'd1);

assign loop_fu_315_p2 = (loop_0_i_reg_206 + 5'd1);

assign sext_ln614_i_cast_fu_372_p1 = loop_0_i2_reg_228;

assign zext_ln535_fu_304_p1 = grp_picnic_keygen_fu_250_ap_return_1;

assign zext_ln539_1_fu_326_p1 = loop_reg_433;

assign zext_ln539_fu_321_p1 = loop_0_i_reg_206;

assign zext_ln541_fu_330_p1 = loop_1_i_reg_217;

assign zext_ln542_1_fu_360_p1 = add_ln542_1_fu_355_p2;

assign zext_ln542_fu_346_p1 = loop_1_i_reg_217;

assign zext_ln609_fu_351_p1 = secret_params_reg_422;

assign zext_ln614_fu_365_p1 = loop_0_i2_reg_228;

assign zext_ln615_fu_388_p1 = loop_6_reg_471;

assign zext_ln616_fu_397_p1 = add_ln616_fu_392_p2;

assign zext_ln617_fu_407_p1 = add_ln617_fu_402_p2;

always @ (posedge ap_clk) begin
    zext_ln541_reg_444[5] <= 1'b0;
    sext_ln614_i_cast_reg_462[5] <= 1'b0;
end

endmodule //crypto_sign_keypair
