// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and OpenCL
// Version: 2019.2
// Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

`timescale 1 ns / 1 ps 

module SubBytes (
        ap_clk,
        ap_rst,
        ap_start,
        ap_done,
        ap_idle,
        ap_ready,
        state_address0,
        state_ce0,
        state_we0,
        state_d0,
        state_q0,
        state_address1,
        state_ce1,
        state_we1,
        state_d1,
        state_q1
);

parameter    ap_ST_fsm_state1 = 5'd1;
parameter    ap_ST_fsm_state2 = 5'd2;
parameter    ap_ST_fsm_state3 = 5'd4;
parameter    ap_ST_fsm_state4 = 5'd8;
parameter    ap_ST_fsm_state5 = 5'd16;

input   ap_clk;
input   ap_rst;
input   ap_start;
output   ap_done;
output   ap_idle;
output   ap_ready;
output  [3:0] state_address0;
output   state_ce0;
output   state_we0;
output  [7:0] state_d0;
input  [7:0] state_q0;
output  [3:0] state_address1;
output   state_ce1;
output   state_we1;
output  [7:0] state_d1;
input  [7:0] state_q1;

reg ap_done;
reg ap_idle;
reg ap_ready;
reg[3:0] state_address0;
reg state_ce0;
reg state_we0;
reg[3:0] state_address1;
reg state_ce1;
reg state_we1;

(* fsm_encoding = "none" *) reg   [4:0] ap_CS_fsm;
wire    ap_CS_fsm_state1;
reg   [7:0] sbox_address0;
reg    sbox_ce0;
wire   [7:0] sbox_q0;
reg   [7:0] sbox_address1;
reg    sbox_ce1;
wire   [7:0] sbox_q1;
wire   [2:0] i_fu_126_p2;
reg   [2:0] i_reg_188;
wire    ap_CS_fsm_state2;
reg   [3:0] state_addr_reg_193;
wire   [0:0] icmp_ln263_fu_120_p2;
wire  signed [2:0] xor_ln268_fu_137_p2;
reg  signed [2:0] xor_ln268_reg_198;
reg   [3:0] state_addr_1_reg_203;
reg   [3:0] state_addr_2_reg_208;
wire    ap_CS_fsm_state3;
reg   [3:0] state_addr_3_reg_213;
wire    ap_CS_fsm_state4;
reg   [2:0] i_0_reg_108;
wire    ap_CS_fsm_state5;
wire   [63:0] zext_ln268_fu_132_p1;
wire   [63:0] zext_ln268_5_fu_143_p1;
wire   [63:0] tmp_fu_148_p3;
wire   [63:0] zext_ln268_6_fu_160_p1;
wire   [63:0] zext_ln268_1_fu_165_p1;
wire   [63:0] zext_ln268_2_fu_170_p1;
wire   [63:0] zext_ln268_3_fu_175_p1;
wire   [63:0] zext_ln268_4_fu_180_p1;
wire  signed [3:0] sext_ln268_fu_157_p1;
reg   [4:0] ap_NS_fsm;

// power-on initialization
initial begin
#0 ap_CS_fsm = 5'd1;
end

KeyExpansion_sbox #(
    .DataWidth( 8 ),
    .AddressRange( 256 ),
    .AddressWidth( 8 ))
sbox_U(
    .clk(ap_clk),
    .reset(ap_rst),
    .address0(sbox_address0),
    .ce0(sbox_ce0),
    .q0(sbox_q0),
    .address1(sbox_address1),
    .ce1(sbox_ce1),
    .q1(sbox_q1)
);

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_CS_fsm <= ap_ST_fsm_state1;
    end else begin
        ap_CS_fsm <= ap_NS_fsm;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state5)) begin
        i_0_reg_108 <= i_reg_188;
    end else if (((1'b1 == ap_CS_fsm_state1) & (ap_start == 1'b1))) begin
        i_0_reg_108 <= 3'd0;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state2)) begin
        i_reg_188 <= i_fu_126_p2;
    end
end

always @ (posedge ap_clk) begin
    if (((icmp_ln263_fu_120_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state2))) begin
        state_addr_1_reg_203[2 : 0] <= zext_ln268_5_fu_143_p1[2 : 0];
        state_addr_reg_193[2 : 0] <= zext_ln268_fu_132_p1[2 : 0];
        xor_ln268_reg_198 <= xor_ln268_fu_137_p2;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state3)) begin
        state_addr_2_reg_208[2 : 0] <= tmp_fu_148_p3[2 : 0];
        state_addr_3_reg_213 <= zext_ln268_6_fu_160_p1;
    end
end

always @ (*) begin
    if ((((icmp_ln263_fu_120_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2)) | ((ap_start == 1'b0) & (1'b1 == ap_CS_fsm_state1)))) begin
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
    if (((icmp_ln263_fu_120_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2))) begin
        ap_ready = 1'b1;
    end else begin
        ap_ready = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state4)) begin
        sbox_address0 = zext_ln268_3_fu_175_p1;
    end else if ((1'b1 == ap_CS_fsm_state3)) begin
        sbox_address0 = zext_ln268_1_fu_165_p1;
    end else begin
        sbox_address0 = 'bx;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state4)) begin
        sbox_address1 = zext_ln268_4_fu_180_p1;
    end else if ((1'b1 == ap_CS_fsm_state3)) begin
        sbox_address1 = zext_ln268_2_fu_170_p1;
    end else begin
        sbox_address1 = 'bx;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state4) | (1'b1 == ap_CS_fsm_state3))) begin
        sbox_ce0 = 1'b1;
    end else begin
        sbox_ce0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state4) | (1'b1 == ap_CS_fsm_state3))) begin
        sbox_ce1 = 1'b1;
    end else begin
        sbox_ce1 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state5)) begin
        state_address0 = state_addr_2_reg_208;
    end else if ((1'b1 == ap_CS_fsm_state4)) begin
        state_address0 = state_addr_reg_193;
    end else if ((1'b1 == ap_CS_fsm_state3)) begin
        state_address0 = tmp_fu_148_p3;
    end else if ((1'b1 == ap_CS_fsm_state2)) begin
        state_address0 = zext_ln268_fu_132_p1;
    end else begin
        state_address0 = 'bx;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state5)) begin
        state_address1 = state_addr_3_reg_213;
    end else if ((1'b1 == ap_CS_fsm_state4)) begin
        state_address1 = state_addr_1_reg_203;
    end else if ((1'b1 == ap_CS_fsm_state3)) begin
        state_address1 = zext_ln268_6_fu_160_p1;
    end else if ((1'b1 == ap_CS_fsm_state2)) begin
        state_address1 = zext_ln268_5_fu_143_p1;
    end else begin
        state_address1 = 'bx;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state5) | (1'b1 == ap_CS_fsm_state4) | (1'b1 == ap_CS_fsm_state3) | (1'b1 == ap_CS_fsm_state2))) begin
        state_ce0 = 1'b1;
    end else begin
        state_ce0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state5) | (1'b1 == ap_CS_fsm_state4) | (1'b1 == ap_CS_fsm_state3) | (1'b1 == ap_CS_fsm_state2))) begin
        state_ce1 = 1'b1;
    end else begin
        state_ce1 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state5) | (1'b1 == ap_CS_fsm_state4))) begin
        state_we0 = 1'b1;
    end else begin
        state_we0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state5) | (1'b1 == ap_CS_fsm_state4))) begin
        state_we1 = 1'b1;
    end else begin
        state_we1 = 1'b0;
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
            if (((icmp_ln263_fu_120_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2))) begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state3;
            end
        end
        ap_ST_fsm_state3 : begin
            ap_NS_fsm = ap_ST_fsm_state4;
        end
        ap_ST_fsm_state4 : begin
            ap_NS_fsm = ap_ST_fsm_state5;
        end
        ap_ST_fsm_state5 : begin
            ap_NS_fsm = ap_ST_fsm_state2;
        end
        default : begin
            ap_NS_fsm = 'bx;
        end
    endcase
end

assign ap_CS_fsm_state1 = ap_CS_fsm[32'd0];

assign ap_CS_fsm_state2 = ap_CS_fsm[32'd1];

assign ap_CS_fsm_state3 = ap_CS_fsm[32'd2];

assign ap_CS_fsm_state4 = ap_CS_fsm[32'd3];

assign ap_CS_fsm_state5 = ap_CS_fsm[32'd4];

assign i_fu_126_p2 = (i_0_reg_108 + 3'd1);

assign icmp_ln263_fu_120_p2 = ((i_0_reg_108 == 3'd4) ? 1'b1 : 1'b0);

assign sext_ln268_fu_157_p1 = xor_ln268_reg_198;

assign state_d0 = sbox_q0;

assign state_d1 = sbox_q1;

assign tmp_fu_148_p3 = {{61'd1}, {i_0_reg_108}};

assign xor_ln268_fu_137_p2 = (i_0_reg_108 ^ 3'd4);

assign zext_ln268_1_fu_165_p1 = state_q0;

assign zext_ln268_2_fu_170_p1 = state_q1;

assign zext_ln268_3_fu_175_p1 = state_q0;

assign zext_ln268_4_fu_180_p1 = state_q1;

assign zext_ln268_5_fu_143_p1 = $unsigned(xor_ln268_fu_137_p2);

assign zext_ln268_6_fu_160_p1 = $unsigned(sext_ln268_fu_157_p1);

assign zext_ln268_fu_132_p1 = i_0_reg_108;

always @ (posedge ap_clk) begin
    state_addr_reg_193[3] <= 1'b0;
    state_addr_1_reg_203[3] <= 1'b0;
    state_addr_2_reg_208[3] <= 1'b1;
end

endmodule //SubBytes