-- ==============================================================
-- Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.2 (64-bit)
-- Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
-- ==============================================================
library ieee; 
use ieee.std_logic_1164.all; 
use ieee.std_logic_unsigned.all;

entity LowMCEnc_temp_matg8j_rom is 
    generic(
             DWIDTH     : integer := 32; 
             AWIDTH     : integer := 7; 
             MEM_SIZE    : integer := 80
    ); 
    port (
          addr0      : in std_logic_vector(AWIDTH-1 downto 0); 
          ce0       : in std_logic; 
          q0         : out std_logic_vector(DWIDTH-1 downto 0);
          addr1      : in std_logic_vector(AWIDTH-1 downto 0); 
          ce1       : in std_logic; 
          q1         : out std_logic_vector(DWIDTH-1 downto 0);
          clk       : in std_logic
    ); 
end entity; 


architecture rtl of LowMCEnc_temp_matg8j_rom is 

signal addr0_tmp : std_logic_vector(AWIDTH-1 downto 0); 
signal addr1_tmp : std_logic_vector(AWIDTH-1 downto 0); 
type mem_array is array (0 to MEM_SIZE-1) of std_logic_vector (DWIDTH-1 downto 0); 
signal mem : mem_array := (
    0 => "10010101000011110000010001011001", 
    1 => "00000111111011110110001010101000", 
    2 => "00111011100001110111000001000000", 
    3 => "00111011011100110010001110101011", 
    4 => "01011011111000110000000100101101", 
    5 => "00001011100010110111100110100111", 
    6 => "11101110011001001001111011111100", 
    7 => "01100000101110001101000011010110", 
    8 => "10000001011111010001110110011110", 
    9 => "11000001011100010010000101100110", 
    10 => "00100110110111101001101001000110", 
    11 => "11001001000010011110110101100101", 
    12 => "00001100001010010010101111100101", 
    13 => "11010001011111110111011111010100", 
    14 => "11010111011001110111001111010101", 
    15 => "01101110011101110110010101111111", 
    16 => "10001110001110010011011011100111", 
    17 => "10101010000110011011110010011101", 
    18 => "11100111100100001110011001000011", 
    19 => "10110011100101000000011111011011", 
    20 => "01011010001010011101010011101011", 
    21 => "00000000100011001001010101000000", 
    22 => "10001110111001101001000001010111", 
    23 => "01000011001101001010011000100001", 
    24 => "11110010011011111001001010111100", 
    25 => "10110111001110001111111110010111", 
    26 => "10001011001111101010010011010110", 
    27 => "01110000111110011010010100010010", 
    28 => "00010010111100101110101010001010", 
    29 => "00010101001010000001011101110010", 
    30 => "00011101100000110111001011111101", 
    31 => "01011001100100010001100001110111", 
    32 => "01111110100101110100011001010010", 
    33 => "01001100110000110010100100111101", 
    34 => "01110011101101011110001011000010", 
    35 => "00111110100000010111001010011011", 
    36 => "00101110100001011000110000000000", 
    37 => "11000110000110110110001110010011", 
    38 => "00100110111010111100101110001000", 
    39 => "10001000111000001011010001100010", 
    40 => "11011000100001000100110000010001", 
    41 => "11001001100010001011110110001011", 
    42 => "10111111011001000011100010010000", 
    43 => "10010111101001001011010011000101", 
    44 => "01100001000110000111111010110111", 
    45 => "01101101011111011000001011111000", 
    46 => "10110011110000000010110111001000", 
    47 => "00000000001011001010011101001100", 
    48 => "01110101101110011101010100000010", 
    49 => "10110011001010000011010010111101", 
    50 => "11111111011001110101111110100001", 
    51 => "10011100100111101000111101000110", 
    52 => "01110100011100110111101001001110", 
    53 => "01101100111111100110001111001100", 
    54 => "00011111001111101111000110011001", 
    55 => "00000100000000110110110100110100", 
    56 => "11101100000011010001111110110100", 
    57 => "10100101100100000010001111100101", 
    58 => "01101100111000010000111001001001", 
    59 => "01001100110100000101001001111000", 
    60 => "00001010001011111101101000101010", 
    61 => "01110100110110001000111101110111", 
    62 => "10101010001111101110111011110110", 
    63 => "11011000010110100010011001010111", 
    64 => "10010000110111111101110100001100", 
    65 => "01100010010001110100100010010111", 
    66 => "11011000111101010111000110100011", 
    67 => "00000100000100001010001010010100", 
    68 => "00100100000100101101001000100110", 
    69 => "11001000000010101101000001101100", 
    70 => "01111001101101000001010110101010", 
    71 => "10101001011101111100001001100010", 
    72 => "11010101001100110010100100011100", 
    73 => "10111111000000000010001101011110", 
    74 => "01111101011110000001001111101000", 
    75 => "00001010110000111010000101100001", 
    76 => "01110110100001110111011101111100", 
    77 => "11010001100010011011010110111010", 
    78 => "00111011101001100111100000100110", 
    79 => "10110010001110001111010011110100" );


begin 


memory_access_guard_0: process (addr0) 
begin
      addr0_tmp <= addr0;
--synthesis translate_off
      if (CONV_INTEGER(addr0) > mem_size-1) then
           addr0_tmp <= (others => '0');
      else 
           addr0_tmp <= addr0;
      end if;
--synthesis translate_on
end process;

memory_access_guard_1: process (addr1) 
begin
      addr1_tmp <= addr1;
--synthesis translate_off
      if (CONV_INTEGER(addr1) > mem_size-1) then
           addr1_tmp <= (others => '0');
      else 
           addr1_tmp <= addr1;
      end if;
--synthesis translate_on
end process;

p_rom_access: process (clk)  
begin 
    if (clk'event and clk = '1') then
        if (ce0 = '1') then 
            q0 <= mem(CONV_INTEGER(addr0_tmp)); 
        end if;
        if (ce1 = '1') then 
            q1 <= mem(CONV_INTEGER(addr1_tmp)); 
        end if;
    end if;
end process;

end rtl;

Library IEEE;
use IEEE.std_logic_1164.all;

entity LowMCEnc_temp_matg8j is
    generic (
        DataWidth : INTEGER := 32;
        AddressRange : INTEGER := 80;
        AddressWidth : INTEGER := 7);
    port (
        reset : IN STD_LOGIC;
        clk : IN STD_LOGIC;
        address0 : IN STD_LOGIC_VECTOR(AddressWidth - 1 DOWNTO 0);
        ce0 : IN STD_LOGIC;
        q0 : OUT STD_LOGIC_VECTOR(DataWidth - 1 DOWNTO 0);
        address1 : IN STD_LOGIC_VECTOR(AddressWidth - 1 DOWNTO 0);
        ce1 : IN STD_LOGIC;
        q1 : OUT STD_LOGIC_VECTOR(DataWidth - 1 DOWNTO 0));
end entity;

architecture arch of LowMCEnc_temp_matg8j is
    component LowMCEnc_temp_matg8j_rom is
        port (
            clk : IN STD_LOGIC;
            addr0 : IN STD_LOGIC_VECTOR;
            ce0 : IN STD_LOGIC;
            q0 : OUT STD_LOGIC_VECTOR;
            addr1 : IN STD_LOGIC_VECTOR;
            ce1 : IN STD_LOGIC;
            q1 : OUT STD_LOGIC_VECTOR);
    end component;



begin
    LowMCEnc_temp_matg8j_rom_U :  component LowMCEnc_temp_matg8j_rom
    port map (
        clk => clk,
        addr0 => address0,
        ce0 => ce0,
        q0 => q0,
        addr1 => address1,
        ce1 => ce1,
        q1 => q1);

end architecture;


