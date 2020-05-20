// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.2 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __LowMCEnc_temp_matg8j_H__
#define __LowMCEnc_temp_matg8j_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct LowMCEnc_temp_matg8j_ram : public sc_core::sc_module {

  static const unsigned DataWidth = 32;
  static const unsigned AddressRange = 80;
  static const unsigned AddressWidth = 7;

//latency = 1
//input_reg = 1
//output_reg = 0
sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in <sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in <sc_lv<AddressWidth> > address1;
sc_core::sc_in <sc_logic> ce1;
sc_core::sc_out <sc_lv<DataWidth> > q1;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


sc_lv<DataWidth> ram[AddressRange];


   SC_CTOR(LowMCEnc_temp_matg8j_ram) {
        ram[0] = "0b10010101000011110000010001011001";
        ram[1] = "0b00000111111011110110001010101000";
        ram[2] = "0b00111011100001110111000001000000";
        ram[3] = "0b00111011011100110010001110101011";
        ram[4] = "0b01011011111000110000000100101101";
        ram[5] = "0b00001011100010110111100110100111";
        ram[6] = "0b11101110011001001001111011111100";
        ram[7] = "0b01100000101110001101000011010110";
        ram[8] = "0b10000001011111010001110110011110";
        ram[9] = "0b11000001011100010010000101100110";
        ram[10] = "0b00100110110111101001101001000110";
        ram[11] = "0b11001001000010011110110101100101";
        ram[12] = "0b00001100001010010010101111100101";
        ram[13] = "0b11010001011111110111011111010100";
        ram[14] = "0b11010111011001110111001111010101";
        ram[15] = "0b01101110011101110110010101111111";
        ram[16] = "0b10001110001110010011011011100111";
        ram[17] = "0b10101010000110011011110010011101";
        ram[18] = "0b11100111100100001110011001000011";
        ram[19] = "0b10110011100101000000011111011011";
        ram[20] = "0b01011010001010011101010011101011";
        ram[21] = "0b00000000100011001001010101000000";
        ram[22] = "0b10001110111001101001000001010111";
        ram[23] = "0b01000011001101001010011000100001";
        ram[24] = "0b11110010011011111001001010111100";
        ram[25] = "0b10110111001110001111111110010111";
        ram[26] = "0b10001011001111101010010011010110";
        ram[27] = "0b01110000111110011010010100010010";
        ram[28] = "0b00010010111100101110101010001010";
        ram[29] = "0b00010101001010000001011101110010";
        ram[30] = "0b00011101100000110111001011111101";
        ram[31] = "0b01011001100100010001100001110111";
        ram[32] = "0b01111110100101110100011001010010";
        ram[33] = "0b01001100110000110010100100111101";
        ram[34] = "0b01110011101101011110001011000010";
        ram[35] = "0b00111110100000010111001010011011";
        ram[36] = "0b00101110100001011000110000000000";
        ram[37] = "0b11000110000110110110001110010011";
        ram[38] = "0b00100110111010111100101110001000";
        ram[39] = "0b10001000111000001011010001100010";
        ram[40] = "0b11011000100001000100110000010001";
        ram[41] = "0b11001001100010001011110110001011";
        ram[42] = "0b10111111011001000011100010010000";
        ram[43] = "0b10010111101001001011010011000101";
        ram[44] = "0b01100001000110000111111010110111";
        ram[45] = "0b01101101011111011000001011111000";
        ram[46] = "0b10110011110000000010110111001000";
        ram[47] = "0b00000000001011001010011101001100";
        ram[48] = "0b01110101101110011101010100000010";
        ram[49] = "0b10110011001010000011010010111101";
        ram[50] = "0b11111111011001110101111110100001";
        ram[51] = "0b10011100100111101000111101000110";
        ram[52] = "0b01110100011100110111101001001110";
        ram[53] = "0b01101100111111100110001111001100";
        ram[54] = "0b00011111001111101111000110011001";
        ram[55] = "0b00000100000000110110110100110100";
        ram[56] = "0b11101100000011010001111110110100";
        ram[57] = "0b10100101100100000010001111100101";
        ram[58] = "0b01101100111000010000111001001001";
        ram[59] = "0b01001100110100000101001001111000";
        ram[60] = "0b00001010001011111101101000101010";
        ram[61] = "0b01110100110110001000111101110111";
        ram[62] = "0b10101010001111101110111011110110";
        ram[63] = "0b11011000010110100010011001010111";
        ram[64] = "0b10010000110111111101110100001100";
        ram[65] = "0b01100010010001110100100010010111";
        ram[66] = "0b11011000111101010111000110100011";
        ram[67] = "0b00000100000100001010001010010100";
        ram[68] = "0b00100100000100101101001000100110";
        ram[69] = "0b11001000000010101101000001101100";
        ram[70] = "0b01111001101101000001010110101010";
        ram[71] = "0b10101001011101111100001001100010";
        ram[72] = "0b11010101001100110010100100011100";
        ram[73] = "0b10111111000000000010001101011110";
        ram[74] = "0b01111101011110000001001111101000";
        ram[75] = "0b00001010110000111010000101100001";
        ram[76] = "0b01110110100001110111011101111100";
        ram[77] = "0b11010001100010011011010110111010";
        ram[78] = "0b00111011101001100111100000100110";
        ram[79] = "0b10110010001110001111010011110100";


SC_METHOD(prc_write_0);
  sensitive<<clk.pos();


SC_METHOD(prc_write_1);
  sensitive<<clk.pos();
   }


void prc_write_0()
{
    if (ce0.read() == sc_dt::Log_1) 
    {
            if(address0.read().is_01() && address0.read().to_uint()<AddressRange)
              q0 = ram[address0.read().to_uint()];
            else
              q0 = sc_lv<DataWidth>();
    }
}


void prc_write_1()
{
    if (ce1.read() == sc_dt::Log_1) 
    {
            if(address1.read().is_01() && address1.read().to_uint()<AddressRange)
              q1 = ram[address1.read().to_uint()];
            else
              q1 = sc_lv<DataWidth>();
    }
}


}; //endmodule


SC_MODULE(LowMCEnc_temp_matg8j) {


static const unsigned DataWidth = 32;
static const unsigned AddressRange = 80;
static const unsigned AddressWidth = 7;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in <sc_lv<AddressWidth> > address1;
sc_core::sc_in<sc_logic> ce1;
sc_core::sc_out <sc_lv<DataWidth> > q1;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


LowMCEnc_temp_matg8j_ram* meminst;


SC_CTOR(LowMCEnc_temp_matg8j) {
meminst = new LowMCEnc_temp_matg8j_ram("LowMCEnc_temp_matg8j_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->address1(address1);
meminst->ce1(ce1);
meminst->q1(q1);

meminst->reset(reset);
meminst->clk(clk);
}
~LowMCEnc_temp_matg8j() {
    delete meminst;
}


};//endmodule
#endif
