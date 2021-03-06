// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and OpenCL
// Version: 2019.2
// Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

`timescale 1 ns / 1 ps 

module matrix_mul_1 (
        ap_clk,
        ap_rst,
        ap_start,
        ap_done,
        ap_idle,
        ap_ready,
        output_r_address0,
        output_r_ce0,
        output_r_we0,
        output_r_d0,
        state_address0,
        state_ce0,
        state_q0,
        matrix_offset
);

parameter    ap_ST_fsm_state1 = 11'd1;
parameter    ap_ST_fsm_state2 = 11'd2;
parameter    ap_ST_fsm_state3 = 11'd4;
parameter    ap_ST_fsm_state4 = 11'd8;
parameter    ap_ST_fsm_state5 = 11'd16;
parameter    ap_ST_fsm_state6 = 11'd32;
parameter    ap_ST_fsm_state7 = 11'd64;
parameter    ap_ST_fsm_state8 = 11'd128;
parameter    ap_ST_fsm_state9 = 11'd256;
parameter    ap_ST_fsm_state10 = 11'd512;
parameter    ap_ST_fsm_state11 = 11'd1024;

input   ap_clk;
input   ap_rst;
input   ap_start;
output   ap_done;
output   ap_idle;
output   ap_ready;
output  [3:0] output_r_address0;
output   output_r_ce0;
output   output_r_we0;
output  [31:0] output_r_d0;
output  [2:0] state_address0;
output   state_ce0;
input  [31:0] state_q0;
input  [13:0] matrix_offset;

reg ap_done;
reg ap_idle;
reg ap_ready;
reg output_r_ce0;
reg output_r_we0;
reg state_ce0;

(* fsm_encoding = "none" *) reg   [10:0] ap_CS_fsm;
wire    ap_CS_fsm_state1;
wire   [13:0] temp_matrix_address0;
reg    temp_matrix_ce0;
wire   [31:0] temp_matrix_q0;
wire   [2:0] trunc_ln124_fu_265_p1;
reg   [2:0] trunc_ln124_reg_896;
wire    ap_CS_fsm_state2;
wire   [7:0] i_fu_275_p2;
reg   [7:0] i_reg_904;
wire   [8:0] shl_ln_fu_285_p3;
reg   [8:0] shl_ln_reg_909;
wire   [0:0] icmp_ln124_fu_269_p2;
wire   [2:0] j_fu_303_p2;
reg   [2:0] j_reg_917;
wire    ap_CS_fsm_state3;
wire   [63:0] zext_ln127_fu_318_p1;
reg   [63:0] zext_ln127_reg_922;
wire   [0:0] icmp_ln125_fu_297_p2;
wire   [31:0] prod_q0;
wire    ap_CS_fsm_state5;
wire    ap_CS_fsm_state6;
wire   [0:0] icmp_ln85_fu_345_p2;
wire   [2:0] i_2_fu_351_p2;
reg   [2:0] i_2_reg_950;
reg   [1:0] tmp_8_reg_955;
reg   [5:0] temp_addr_3_reg_961;
wire   [31:0] x_1_fu_382_p2;
wire    ap_CS_fsm_state7;
wire   [4:0] zext_ln66_cast_fu_594_p3;
reg   [4:0] zext_ln66_cast_reg_971;
wire    ap_CS_fsm_state8;
wire   [5:0] add_ln66_fu_609_p2;
reg   [5:0] add_ln66_reg_976;
wire   [7:0] or_ln66_fu_750_p2;
reg   [7:0] or_ln66_reg_982;
wire   [0:0] icmp_ln66_1_fu_756_p2;
reg   [0:0] icmp_ln66_1_reg_987;
wire   [2:0] loop_fu_875_p2;
reg   [2:0] loop_reg_998;
wire    ap_CS_fsm_state10;
wire   [63:0] zext_ln134_fu_881_p1;
reg   [63:0] zext_ln134_reg_1003;
wire   [0:0] icmp_ln133_fu_869_p2;
reg   [5:0] prod_address0;
reg    prod_ce0;
reg    prod_we0;
wire   [31:0] prod_d0;
reg   [5:0] temp_address0;
reg    temp_ce0;
reg   [3:0] temp_we0;
wire   [31:0] temp_d0;
wire   [31:0] temp_q0;
reg   [7:0] bitNumber_assign_reg_210;
wire    ap_CS_fsm_state9;
reg   [2:0] j_0_reg_222;
wire    ap_CS_fsm_state4;
reg   [31:0] x_0_i_reg_233;
reg   [2:0] i_0_i_reg_243;
reg   [2:0] loop_0_reg_254;
wire    ap_CS_fsm_state11;
wire   [63:0] zext_ln127_1_fu_328_p1;
wire   [63:0] zext_ln85_fu_340_p1;
wire   [63:0] zext_ln66_3_fu_377_p1;
wire   [3:0] shl_ln66_4_fu_862_p2;
wire   [6:0] trunc_ln126_fu_281_p1;
wire   [8:0] zext_ln125_fu_293_p1;
wire   [8:0] add_ln126_fu_309_p2;
wire   [13:0] zext_ln126_fu_314_p1;
wire   [13:0] add_ln127_fu_323_p2;
wire   [1:0] tmp_9_fu_367_p4;
wire   [30:0] lshr_ln_fu_388_p4;
wire   [31:0] zext_ln93_fu_398_p1;
wire   [31:0] y_fu_428_p2;
wire   [29:0] lshr_ln1_fu_434_p4;
wire   [23:0] trunc_ln93_3_fu_418_p4;
wire   [23:0] trunc_ln93_1_fu_414_p1;
wire   [31:0] zext_ln94_fu_444_p1;
wire   [31:0] y_1_fu_472_p2;
wire   [27:0] lshr_ln2_fu_478_p4;
wire   [23:0] trunc_ln94_1_fu_462_p4;
wire   [23:0] xor_ln94_fu_456_p2;
wire   [31:0] zext_ln95_fu_488_p1;
wire   [23:0] trunc_ln95_1_fu_506_p4;
wire   [23:0] xor_ln95_fu_500_p2;
wire   [31:0] y_2_fu_516_p2;
wire   [23:0] trunc_ln5_fu_528_p4;
wire   [23:0] xor_ln95_2_fu_522_p2;
wire   [23:0] y_3_fu_546_p2;
wire   [0:0] trunc_ln93_fu_402_p1;
wire   [0:0] tmp_4_fu_448_p3;
wire   [0:0] xor_ln98_fu_560_p2;
wire   [0:0] tmp_3_fu_406_p3;
wire   [0:0] tmp_6_fu_538_p3;
wire   [0:0] tmp_7_fu_552_p3;
wire   [0:0] xor_ln98_2_fu_572_p2;
wire   [0:0] tmp_5_fu_492_p3;
wire   [0:0] xor_ln98_3_fu_578_p2;
wire   [0:0] xor_ln98_1_fu_566_p2;
wire   [0:0] xor_ln98_4_fu_584_p2;
wire   [5:0] zext_ln66_fu_601_p1;
wire   [63:0] zext_ln66_2_fu_605_p1;
wire   [63:0] zext_ln66_4_fu_615_p1;
wire   [5:0] zext_ln66_5_fu_625_p1;
wire   [0:0] icmp_ln66_fu_619_p2;
wire   [5:0] sub_ln66_fu_639_p2;
wire   [5:0] sub_ln66_1_fu_651_p2;
reg   [31:0] tmp_10_fu_629_p4;
wire   [5:0] xor_ln66_2_fu_645_p2;
wire   [5:0] select_ln66_fu_657_p3;
wire   [5:0] select_ln66_2_fu_673_p3;
wire   [5:0] sub_ln66_2_fu_681_p2;
wire   [31:0] select_ln66_1_fu_665_p3;
wire   [31:0] zext_ln66_6_fu_687_p1;
wire   [31:0] zext_ln66_7_fu_691_p1;
wire   [31:0] lshr_ln66_fu_695_p2;
wire   [31:0] lshr_ln66_1_fu_701_p2;
wire   [31:0] and_ln66_1_fu_707_p2;
wire   [2:0] xor_ln66_fu_717_p2;
wire   [7:0] zext_ln66_1_fu_722_p1;
wire   [7:0] shl_ln66_fu_726_p2;
wire   [7:0] zext_ln98_fu_590_p1;
wire   [7:0] trunc_ln66_fu_713_p1;
wire   [7:0] xor_ln66_1_fu_732_p2;
wire   [7:0] and_ln66_fu_744_p2;
wire   [7:0] shl_ln66_1_fu_738_p2;
wire   [5:0] zext_ln66_8_fu_762_p1;
wire   [5:0] xor_ln66_3_fu_768_p2;
wire   [5:0] select_ln66_3_fu_774_p3;
wire   [5:0] select_ln66_5_fu_786_p3;
wire   [5:0] select_ln66_4_fu_780_p3;
wire   [5:0] sub_ln66_3_fu_793_p2;
wire   [31:0] zext_ln66_9_fu_765_p1;
wire   [31:0] zext_ln66_10_fu_799_p1;
wire   [31:0] shl_ln66_2_fu_811_p2;
reg   [31:0] tmp_11_fu_817_p4;
wire   [31:0] zext_ln66_11_fu_803_p1;
wire   [31:0] zext_ln66_12_fu_807_p1;
wire   [31:0] shl_ln66_3_fu_834_p2;
wire   [31:0] lshr_ln66_2_fu_840_p2;
wire   [31:0] select_ln66_6_fu_827_p3;
wire   [31:0] and_ln66_2_fu_846_p2;
wire   [3:0] zext_ln66_13_fu_859_p1;
reg   [10:0] ap_NS_fsm;

// power-on initialization
initial begin
#0 ap_CS_fsm = 11'd1;
end

matrix_mul_1_tempeOg #(
    .DataWidth( 32 ),
    .AddressRange( 10752 ),
    .AddressWidth( 14 ))
temp_matrix_U(
    .clk(ap_clk),
    .reset(ap_rst),
    .address0(temp_matrix_address0),
    .ce0(temp_matrix_ce0),
    .q0(temp_matrix_q0)
);

matrix_mul_1_prod #(
    .DataWidth( 32 ),
    .AddressRange( 64 ),
    .AddressWidth( 6 ))
prod_U(
    .clk(ap_clk),
    .reset(ap_rst),
    .address0(prod_address0),
    .ce0(prod_ce0),
    .we0(prod_we0),
    .d0(prod_d0),
    .q0(prod_q0)
);

matrix_mul_1_temp #(
    .DataWidth( 32 ),
    .AddressRange( 64 ),
    .AddressWidth( 6 ))
temp_U(
    .clk(ap_clk),
    .reset(ap_rst),
    .address0(temp_address0),
    .ce0(temp_ce0),
    .we0(temp_we0),
    .d0(temp_d0),
    .q0(temp_q0)
);

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_CS_fsm <= ap_ST_fsm_state1;
    end else begin
        ap_CS_fsm <= ap_NS_fsm;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state9)) begin
        bitNumber_assign_reg_210 <= i_reg_904;
    end else if (((1'b1 == ap_CS_fsm_state1) & (ap_start == 1'b1))) begin
        bitNumber_assign_reg_210 <= 8'd0;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state7)) begin
        i_0_i_reg_243 <= i_2_reg_950;
    end else if ((1'b1 == ap_CS_fsm_state5)) begin
        i_0_i_reg_243 <= 3'd1;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state4)) begin
        j_0_reg_222 <= j_reg_917;
    end else if (((icmp_ln124_fu_269_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state2))) begin
        j_0_reg_222 <= 3'd0;
    end
end

always @ (posedge ap_clk) begin
    if (((icmp_ln124_fu_269_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2))) begin
        loop_0_reg_254 <= 3'd0;
    end else if ((1'b1 == ap_CS_fsm_state11)) begin
        loop_0_reg_254 <= loop_reg_998;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state7)) begin
        x_0_i_reg_233 <= x_1_fu_382_p2;
    end else if ((1'b1 == ap_CS_fsm_state5)) begin
        x_0_i_reg_233 <= prod_q0;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state8)) begin
        add_ln66_reg_976[5 : 3] <= add_ln66_fu_609_p2[5 : 3];
        icmp_ln66_1_reg_987 <= icmp_ln66_1_fu_756_p2;
        or_ln66_reg_982 <= or_ln66_fu_750_p2;
        zext_ln66_cast_reg_971[4 : 3] <= zext_ln66_cast_fu_594_p3[4 : 3];
    end
end

always @ (posedge ap_clk) begin
    if (((icmp_ln85_fu_345_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state6))) begin
        i_2_reg_950 <= i_2_fu_351_p2;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state2)) begin
        i_reg_904 <= i_fu_275_p2;
        trunc_ln124_reg_896 <= trunc_ln124_fu_265_p1;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state3)) begin
        j_reg_917 <= j_fu_303_p2;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state10)) begin
        loop_reg_998 <= loop_fu_875_p2;
    end
end

always @ (posedge ap_clk) begin
    if (((icmp_ln124_fu_269_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state2))) begin
        shl_ln_reg_909[8 : 2] <= shl_ln_fu_285_p3[8 : 2];
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_state6) & (icmp_ln85_fu_345_p2 == 1'd1))) begin
        temp_addr_3_reg_961[1 : 0] <= zext_ln66_3_fu_377_p1[1 : 0];
        tmp_8_reg_955 <= {{bitNumber_assign_reg_210[4:3]}};
    end
end

always @ (posedge ap_clk) begin
    if (((icmp_ln125_fu_297_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state3))) begin
        zext_ln127_reg_922[2 : 0] <= zext_ln127_fu_318_p1[2 : 0];
    end
end

always @ (posedge ap_clk) begin
    if (((icmp_ln133_fu_869_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state10))) begin
        zext_ln134_reg_1003[2 : 0] <= zext_ln134_fu_881_p1[2 : 0];
    end
end

always @ (*) begin
    if ((((ap_start == 1'b0) & (1'b1 == ap_CS_fsm_state1)) | ((1'b1 == ap_CS_fsm_state10) & (icmp_ln133_fu_869_p2 == 1'd1)))) begin
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
    if (((1'b1 == ap_CS_fsm_state10) & (icmp_ln133_fu_869_p2 == 1'd1))) begin
        ap_ready = 1'b1;
    end else begin
        ap_ready = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state11)) begin
        output_r_ce0 = 1'b1;
    end else begin
        output_r_ce0 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state11)) begin
        output_r_we0 = 1'b1;
    end else begin
        output_r_we0 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state6)) begin
        prod_address0 = zext_ln85_fu_340_p1;
    end else if ((1'b1 == ap_CS_fsm_state4)) begin
        prod_address0 = zext_ln127_reg_922;
    end else if ((1'b1 == ap_CS_fsm_state3)) begin
        prod_address0 = 64'd0;
    end else begin
        prod_address0 = 'bx;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state3) | (1'b1 == ap_CS_fsm_state4) | (1'b1 == ap_CS_fsm_state6))) begin
        prod_ce0 = 1'b1;
    end else begin
        prod_ce0 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state4)) begin
        prod_we0 = 1'b1;
    end else begin
        prod_we0 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state3)) begin
        state_ce0 = 1'b1;
    end else begin
        state_ce0 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state10)) begin
        temp_address0 = zext_ln134_fu_881_p1;
    end else if ((1'b1 == ap_CS_fsm_state9)) begin
        temp_address0 = temp_addr_3_reg_961;
    end else if ((1'b1 == ap_CS_fsm_state6)) begin
        temp_address0 = zext_ln66_3_fu_377_p1;
    end else begin
        temp_address0 = 'bx;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state9) | (1'b1 == ap_CS_fsm_state10) | (1'b1 == ap_CS_fsm_state6))) begin
        temp_ce0 = 1'b1;
    end else begin
        temp_ce0 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state3)) begin
        temp_matrix_ce0 = 1'b1;
    end else begin
        temp_matrix_ce0 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state9)) begin
        temp_we0 = shl_ln66_4_fu_862_p2;
    end else begin
        temp_we0 = 4'd0;
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
            if (((icmp_ln124_fu_269_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2))) begin
                ap_NS_fsm = ap_ST_fsm_state10;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state3;
            end
        end
        ap_ST_fsm_state3 : begin
            if (((icmp_ln125_fu_297_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state3))) begin
                ap_NS_fsm = ap_ST_fsm_state5;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state4;
            end
        end
        ap_ST_fsm_state4 : begin
            ap_NS_fsm = ap_ST_fsm_state3;
        end
        ap_ST_fsm_state5 : begin
            ap_NS_fsm = ap_ST_fsm_state6;
        end
        ap_ST_fsm_state6 : begin
            if (((1'b1 == ap_CS_fsm_state6) & (icmp_ln85_fu_345_p2 == 1'd1))) begin
                ap_NS_fsm = ap_ST_fsm_state8;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state7;
            end
        end
        ap_ST_fsm_state7 : begin
            ap_NS_fsm = ap_ST_fsm_state6;
        end
        ap_ST_fsm_state8 : begin
            ap_NS_fsm = ap_ST_fsm_state9;
        end
        ap_ST_fsm_state9 : begin
            ap_NS_fsm = ap_ST_fsm_state2;
        end
        ap_ST_fsm_state10 : begin
            if (((1'b1 == ap_CS_fsm_state10) & (icmp_ln133_fu_869_p2 == 1'd1))) begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state11;
            end
        end
        ap_ST_fsm_state11 : begin
            ap_NS_fsm = ap_ST_fsm_state10;
        end
        default : begin
            ap_NS_fsm = 'bx;
        end
    endcase
end

assign add_ln126_fu_309_p2 = (shl_ln_reg_909 + zext_ln125_fu_293_p1);

assign add_ln127_fu_323_p2 = (zext_ln126_fu_314_p1 + matrix_offset);

assign add_ln66_fu_609_p2 = (6'd7 + zext_ln66_fu_601_p1);

assign and_ln66_1_fu_707_p2 = (lshr_ln66_fu_695_p2 & lshr_ln66_1_fu_701_p2);

assign and_ln66_2_fu_846_p2 = (shl_ln66_3_fu_834_p2 & lshr_ln66_2_fu_840_p2);

assign and_ln66_fu_744_p2 = (xor_ln66_1_fu_732_p2 & trunc_ln66_fu_713_p1);

assign ap_CS_fsm_state1 = ap_CS_fsm[32'd0];

assign ap_CS_fsm_state10 = ap_CS_fsm[32'd9];

assign ap_CS_fsm_state11 = ap_CS_fsm[32'd10];

assign ap_CS_fsm_state2 = ap_CS_fsm[32'd1];

assign ap_CS_fsm_state3 = ap_CS_fsm[32'd2];

assign ap_CS_fsm_state4 = ap_CS_fsm[32'd3];

assign ap_CS_fsm_state5 = ap_CS_fsm[32'd4];

assign ap_CS_fsm_state6 = ap_CS_fsm[32'd5];

assign ap_CS_fsm_state7 = ap_CS_fsm[32'd6];

assign ap_CS_fsm_state8 = ap_CS_fsm[32'd7];

assign ap_CS_fsm_state9 = ap_CS_fsm[32'd8];

assign i_2_fu_351_p2 = (i_0_i_reg_243 + 3'd1);

assign i_fu_275_p2 = (8'd1 + bitNumber_assign_reg_210);

assign icmp_ln124_fu_269_p2 = ((bitNumber_assign_reg_210 == 8'd128) ? 1'b1 : 1'b0);

assign icmp_ln125_fu_297_p2 = ((j_0_reg_222 == 3'd4) ? 1'b1 : 1'b0);

assign icmp_ln133_fu_869_p2 = ((loop_0_reg_254 == 3'd4) ? 1'b1 : 1'b0);

assign icmp_ln66_1_fu_756_p2 = ((zext_ln66_2_fu_605_p1 > zext_ln66_4_fu_615_p1) ? 1'b1 : 1'b0);

assign icmp_ln66_fu_619_p2 = ((zext_ln66_2_fu_605_p1 > zext_ln66_4_fu_615_p1) ? 1'b1 : 1'b0);

assign icmp_ln85_fu_345_p2 = ((i_0_i_reg_243 == 3'd4) ? 1'b1 : 1'b0);

assign j_fu_303_p2 = (j_0_reg_222 + 3'd1);

assign loop_fu_875_p2 = (loop_0_reg_254 + 3'd1);

assign lshr_ln1_fu_434_p4 = {{y_fu_428_p2[31:2]}};

assign lshr_ln2_fu_478_p4 = {{y_1_fu_472_p2[31:4]}};

assign lshr_ln66_1_fu_701_p2 = 32'd4294967295 >> zext_ln66_7_fu_691_p1;

assign lshr_ln66_2_fu_840_p2 = 32'd4294967295 >> zext_ln66_12_fu_807_p1;

assign lshr_ln66_fu_695_p2 = select_ln66_1_fu_665_p3 >> zext_ln66_6_fu_687_p1;

assign lshr_ln_fu_388_p4 = {{x_0_i_reg_233[31:1]}};

assign or_ln66_fu_750_p2 = (shl_ln66_1_fu_738_p2 | and_ln66_fu_744_p2);

assign output_r_address0 = zext_ln134_reg_1003;

assign output_r_d0 = temp_q0;

assign prod_d0 = (temp_matrix_q0 & state_q0);

assign select_ln66_1_fu_665_p3 = ((icmp_ln66_fu_619_p2[0:0] === 1'b1) ? tmp_10_fu_629_p4 : temp_q0);

assign select_ln66_2_fu_673_p3 = ((icmp_ln66_fu_619_p2[0:0] === 1'b1) ? xor_ln66_2_fu_645_p2 : zext_ln66_5_fu_625_p1);

assign select_ln66_3_fu_774_p3 = ((icmp_ln66_1_reg_987[0:0] === 1'b1) ? zext_ln66_8_fu_762_p1 : add_ln66_reg_976);

assign select_ln66_4_fu_780_p3 = ((icmp_ln66_1_reg_987[0:0] === 1'b1) ? add_ln66_reg_976 : zext_ln66_8_fu_762_p1);

assign select_ln66_5_fu_786_p3 = ((icmp_ln66_1_reg_987[0:0] === 1'b1) ? xor_ln66_3_fu_768_p2 : zext_ln66_8_fu_762_p1);

assign select_ln66_6_fu_827_p3 = ((icmp_ln66_1_reg_987[0:0] === 1'b1) ? tmp_11_fu_817_p4 : shl_ln66_2_fu_811_p2);

assign select_ln66_fu_657_p3 = ((icmp_ln66_fu_619_p2[0:0] === 1'b1) ? sub_ln66_fu_639_p2 : sub_ln66_1_fu_651_p2);

assign shl_ln66_1_fu_738_p2 = zext_ln98_fu_590_p1 << zext_ln66_1_fu_722_p1;

assign shl_ln66_2_fu_811_p2 = zext_ln66_9_fu_765_p1 << zext_ln66_10_fu_799_p1;

assign shl_ln66_3_fu_834_p2 = 32'd4294967295 << zext_ln66_11_fu_803_p1;

assign shl_ln66_4_fu_862_p2 = 4'd1 << zext_ln66_13_fu_859_p1;

assign shl_ln66_fu_726_p2 = 8'd1 << zext_ln66_1_fu_722_p1;

assign shl_ln_fu_285_p3 = {{trunc_ln126_fu_281_p1}, {2'd0}};

assign state_address0 = zext_ln127_fu_318_p1;

assign sub_ln66_1_fu_651_p2 = (add_ln66_fu_609_p2 - zext_ln66_5_fu_625_p1);

assign sub_ln66_2_fu_681_p2 = (6'd31 - select_ln66_fu_657_p3);

assign sub_ln66_3_fu_793_p2 = (6'd31 - select_ln66_3_fu_774_p3);

assign sub_ln66_fu_639_p2 = (zext_ln66_5_fu_625_p1 - add_ln66_fu_609_p2);

assign temp_d0 = (select_ln66_6_fu_827_p3 & and_ln66_2_fu_846_p2);

assign temp_matrix_address0 = zext_ln127_1_fu_328_p1;

integer ap_tvar_int_0;

always @ (temp_q0) begin
    for (ap_tvar_int_0 = 32 - 1; ap_tvar_int_0 >= 0; ap_tvar_int_0 = ap_tvar_int_0 - 1) begin
        if (ap_tvar_int_0 > 31 - 0) begin
            tmp_10_fu_629_p4[ap_tvar_int_0] = 1'b0;
        end else begin
            tmp_10_fu_629_p4[ap_tvar_int_0] = temp_q0[31 - ap_tvar_int_0];
        end
    end
end

integer ap_tvar_int_1;

always @ (shl_ln66_2_fu_811_p2) begin
    for (ap_tvar_int_1 = 32 - 1; ap_tvar_int_1 >= 0; ap_tvar_int_1 = ap_tvar_int_1 - 1) begin
        if (ap_tvar_int_1 > 31 - 0) begin
            tmp_11_fu_817_p4[ap_tvar_int_1] = 1'b0;
        end else begin
            tmp_11_fu_817_p4[ap_tvar_int_1] = shl_ln66_2_fu_811_p2[31 - ap_tvar_int_1];
        end
    end
end

assign tmp_3_fu_406_p3 = x_0_i_reg_233[32'd1];

assign tmp_4_fu_448_p3 = y_fu_428_p2[32'd2];

assign tmp_5_fu_492_p3 = y_1_fu_472_p2[32'd4];

assign tmp_6_fu_538_p3 = y_2_fu_516_p2[32'd8];

assign tmp_7_fu_552_p3 = y_3_fu_546_p2[32'd16];

assign tmp_9_fu_367_p4 = {{bitNumber_assign_reg_210[6:5]}};

assign trunc_ln124_fu_265_p1 = bitNumber_assign_reg_210[2:0];

assign trunc_ln126_fu_281_p1 = bitNumber_assign_reg_210[6:0];

assign trunc_ln5_fu_528_p4 = {{y_2_fu_516_p2[31:8]}};

assign trunc_ln66_fu_713_p1 = and_ln66_1_fu_707_p2[7:0];

assign trunc_ln93_1_fu_414_p1 = x_0_i_reg_233[23:0];

assign trunc_ln93_3_fu_418_p4 = {{x_0_i_reg_233[24:1]}};

assign trunc_ln93_fu_402_p1 = x_0_i_reg_233[0:0];

assign trunc_ln94_1_fu_462_p4 = {{y_fu_428_p2[25:2]}};

assign trunc_ln95_1_fu_506_p4 = {{y_1_fu_472_p2[27:4]}};

assign x_1_fu_382_p2 = (x_0_i_reg_233 ^ prod_q0);

assign xor_ln66_1_fu_732_p2 = (shl_ln66_fu_726_p2 ^ 8'd255);

assign xor_ln66_2_fu_645_p2 = (zext_ln66_5_fu_625_p1 ^ 6'd31);

assign xor_ln66_3_fu_768_p2 = (zext_ln66_8_fu_762_p1 ^ 6'd31);

assign xor_ln66_fu_717_p2 = (trunc_ln124_reg_896 ^ 3'd7);

assign xor_ln94_fu_456_p2 = (trunc_ln93_3_fu_418_p4 ^ trunc_ln93_1_fu_414_p1);

assign xor_ln95_2_fu_522_p2 = (xor_ln95_fu_500_p2 ^ trunc_ln95_1_fu_506_p4);

assign xor_ln95_fu_500_p2 = (xor_ln94_fu_456_p2 ^ trunc_ln94_1_fu_462_p4);

assign xor_ln98_1_fu_566_p2 = (xor_ln98_fu_560_p2 ^ tmp_3_fu_406_p3);

assign xor_ln98_2_fu_572_p2 = (tmp_7_fu_552_p3 ^ tmp_6_fu_538_p3);

assign xor_ln98_3_fu_578_p2 = (xor_ln98_2_fu_572_p2 ^ tmp_5_fu_492_p3);

assign xor_ln98_4_fu_584_p2 = (xor_ln98_3_fu_578_p2 ^ xor_ln98_1_fu_566_p2);

assign xor_ln98_fu_560_p2 = (trunc_ln93_fu_402_p1 ^ tmp_4_fu_448_p3);

assign y_1_fu_472_p2 = (zext_ln94_fu_444_p1 ^ y_fu_428_p2);

assign y_2_fu_516_p2 = (zext_ln95_fu_488_p1 ^ y_1_fu_472_p2);

assign y_3_fu_546_p2 = (xor_ln95_2_fu_522_p2 ^ trunc_ln5_fu_528_p4);

assign y_fu_428_p2 = (zext_ln93_fu_398_p1 ^ x_0_i_reg_233);

assign zext_ln125_fu_293_p1 = j_0_reg_222;

assign zext_ln126_fu_314_p1 = add_ln126_fu_309_p2;

assign zext_ln127_1_fu_328_p1 = add_ln127_fu_323_p2;

assign zext_ln127_fu_318_p1 = j_0_reg_222;

assign zext_ln134_fu_881_p1 = loop_0_reg_254;

assign zext_ln66_10_fu_799_p1 = select_ln66_5_fu_786_p3;

assign zext_ln66_11_fu_803_p1 = select_ln66_4_fu_780_p3;

assign zext_ln66_12_fu_807_p1 = sub_ln66_3_fu_793_p2;

assign zext_ln66_13_fu_859_p1 = tmp_8_reg_955;

assign zext_ln66_1_fu_722_p1 = xor_ln66_fu_717_p2;

assign zext_ln66_2_fu_605_p1 = zext_ln66_cast_fu_594_p3;

assign zext_ln66_3_fu_377_p1 = tmp_9_fu_367_p4;

assign zext_ln66_4_fu_615_p1 = add_ln66_fu_609_p2;

assign zext_ln66_5_fu_625_p1 = zext_ln66_cast_fu_594_p3;

assign zext_ln66_6_fu_687_p1 = select_ln66_2_fu_673_p3;

assign zext_ln66_7_fu_691_p1 = sub_ln66_2_fu_681_p2;

assign zext_ln66_8_fu_762_p1 = zext_ln66_cast_reg_971;

assign zext_ln66_9_fu_765_p1 = or_ln66_reg_982;

assign zext_ln66_cast_fu_594_p3 = {{tmp_8_reg_955}, {3'd0}};

assign zext_ln66_fu_601_p1 = zext_ln66_cast_fu_594_p3;

assign zext_ln85_fu_340_p1 = i_0_i_reg_243;

assign zext_ln93_fu_398_p1 = lshr_ln_fu_388_p4;

assign zext_ln94_fu_444_p1 = lshr_ln1_fu_434_p4;

assign zext_ln95_fu_488_p1 = lshr_ln2_fu_478_p4;

assign zext_ln98_fu_590_p1 = xor_ln98_4_fu_584_p2;

always @ (posedge ap_clk) begin
    shl_ln_reg_909[1:0] <= 2'b00;
    zext_ln127_reg_922[63:3] <= 61'b0000000000000000000000000000000000000000000000000000000000000;
    temp_addr_3_reg_961[5:2] <= 4'b0000;
    zext_ln66_cast_reg_971[2:0] <= 3'b000;
    add_ln66_reg_976[2:0] <= 3'b111;
    zext_ln134_reg_1003[63:3] <= 61'b0000000000000000000000000000000000000000000000000000000000000;
end

endmodule //matrix_mul_1
