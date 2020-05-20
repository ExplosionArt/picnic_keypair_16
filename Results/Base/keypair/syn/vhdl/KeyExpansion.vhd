-- ==============================================================
-- RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and OpenCL
-- Version: 2019.2
-- Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
-- 
-- ===========================================================

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity KeyExpansion is
port (
    ap_clk : IN STD_LOGIC;
    ap_rst : IN STD_LOGIC;
    ap_start : IN STD_LOGIC;
    ap_done : OUT STD_LOGIC;
    ap_idle : OUT STD_LOGIC;
    ap_ready : OUT STD_LOGIC;
    RoundKey_address0 : OUT STD_LOGIC_VECTOR (7 downto 0);
    RoundKey_ce0 : OUT STD_LOGIC;
    RoundKey_we0 : OUT STD_LOGIC;
    RoundKey_d0 : OUT STD_LOGIC_VECTOR (7 downto 0);
    RoundKey_q0 : IN STD_LOGIC_VECTOR (7 downto 0);
    RoundKey_address1 : OUT STD_LOGIC_VECTOR (7 downto 0);
    RoundKey_ce1 : OUT STD_LOGIC;
    RoundKey_we1 : OUT STD_LOGIC;
    RoundKey_d1 : OUT STD_LOGIC_VECTOR (7 downto 0);
    RoundKey_q1 : IN STD_LOGIC_VECTOR (7 downto 0);
    Key_address0 : OUT STD_LOGIC_VECTOR (4 downto 0);
    Key_ce0 : OUT STD_LOGIC;
    Key_q0 : IN STD_LOGIC_VECTOR (7 downto 0);
    Key_address1 : OUT STD_LOGIC_VECTOR (4 downto 0);
    Key_ce1 : OUT STD_LOGIC;
    Key_q1 : IN STD_LOGIC_VECTOR (7 downto 0) );
end;


architecture behav of KeyExpansion is 
    constant ap_const_logic_1 : STD_LOGIC := '1';
    constant ap_const_logic_0 : STD_LOGIC := '0';
    constant ap_ST_fsm_state1 : STD_LOGIC_VECTOR (9 downto 0) := "0000000001";
    constant ap_ST_fsm_state2 : STD_LOGIC_VECTOR (9 downto 0) := "0000000010";
    constant ap_ST_fsm_state3 : STD_LOGIC_VECTOR (9 downto 0) := "0000000100";
    constant ap_ST_fsm_state4 : STD_LOGIC_VECTOR (9 downto 0) := "0000001000";
    constant ap_ST_fsm_state5 : STD_LOGIC_VECTOR (9 downto 0) := "0000010000";
    constant ap_ST_fsm_state6 : STD_LOGIC_VECTOR (9 downto 0) := "0000100000";
    constant ap_ST_fsm_state7 : STD_LOGIC_VECTOR (9 downto 0) := "0001000000";
    constant ap_ST_fsm_state8 : STD_LOGIC_VECTOR (9 downto 0) := "0010000000";
    constant ap_ST_fsm_state9 : STD_LOGIC_VECTOR (9 downto 0) := "0100000000";
    constant ap_ST_fsm_state10 : STD_LOGIC_VECTOR (9 downto 0) := "1000000000";
    constant ap_const_lv32_0 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000000";
    constant ap_const_lv32_5 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000101";
    constant ap_const_lv32_6 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000110";
    constant ap_const_lv32_7 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000111";
    constant ap_const_lv32_1 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000001";
    constant ap_const_lv1_0 : STD_LOGIC_VECTOR (0 downto 0) := "0";
    constant ap_const_lv32_2 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000010";
    constant ap_const_lv32_4 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000100";
    constant ap_const_lv1_1 : STD_LOGIC_VECTOR (0 downto 0) := "1";
    constant ap_const_lv32_8 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000001000";
    constant ap_const_lv4_0 : STD_LOGIC_VECTOR (3 downto 0) := "0000";
    constant ap_const_lv32_3 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000011";
    constant ap_const_lv32_9 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000001001";
    constant ap_const_lv6_8 : STD_LOGIC_VECTOR (5 downto 0) := "001000";
    constant ap_const_lv4_8 : STD_LOGIC_VECTOR (3 downto 0) := "1000";
    constant ap_const_lv4_1 : STD_LOGIC_VECTOR (3 downto 0) := "0001";
    constant ap_const_lv2_0 : STD_LOGIC_VECTOR (1 downto 0) := "00";
    constant ap_const_lv5_1 : STD_LOGIC_VECTOR (4 downto 0) := "00001";
    constant ap_const_lv5_2 : STD_LOGIC_VECTOR (4 downto 0) := "00010";
    constant ap_const_lv5_3 : STD_LOGIC_VECTOR (4 downto 0) := "00011";
    constant ap_const_lv6_3C : STD_LOGIC_VECTOR (5 downto 0) := "111100";
    constant ap_const_lv8_FC : STD_LOGIC_VECTOR (7 downto 0) := "11111100";
    constant ap_const_lv8_FD : STD_LOGIC_VECTOR (7 downto 0) := "11111101";
    constant ap_const_lv3_0 : STD_LOGIC_VECTOR (2 downto 0) := "000";
    constant ap_const_lv3_4 : STD_LOGIC_VECTOR (2 downto 0) := "100";
    constant ap_const_lv6_1 : STD_LOGIC_VECTOR (5 downto 0) := "000001";
    constant ap_const_lv8_FE : STD_LOGIC_VECTOR (7 downto 0) := "11111110";
    constant ap_const_lv8_FF : STD_LOGIC_VECTOR (7 downto 0) := "11111111";
    constant ap_const_lv8_E0 : STD_LOGIC_VECTOR (7 downto 0) := "11100000";
    constant ap_const_lv8_E1 : STD_LOGIC_VECTOR (7 downto 0) := "11100001";
    constant ap_const_lv8_E2 : STD_LOGIC_VECTOR (7 downto 0) := "11100010";
    constant ap_const_lv8_E3 : STD_LOGIC_VECTOR (7 downto 0) := "11100011";
    constant ap_const_lv8_1 : STD_LOGIC_VECTOR (7 downto 0) := "00000001";
    constant ap_const_lv8_2 : STD_LOGIC_VECTOR (7 downto 0) := "00000010";
    constant ap_const_lv8_3 : STD_LOGIC_VECTOR (7 downto 0) := "00000011";
    constant ap_const_boolean_1 : BOOLEAN := true;

    signal ap_CS_fsm : STD_LOGIC_VECTOR (9 downto 0) := "0000000001";
    attribute fsm_encoding : string;
    attribute fsm_encoding of ap_CS_fsm : signal is "none";
    signal ap_CS_fsm_state1 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state1 : signal is "none";
    signal sbox_address0 : STD_LOGIC_VECTOR (7 downto 0);
    signal sbox_ce0 : STD_LOGIC;
    signal sbox_q0 : STD_LOGIC_VECTOR (7 downto 0);
    signal sbox_address1 : STD_LOGIC_VECTOR (7 downto 0);
    signal sbox_ce1 : STD_LOGIC;
    signal sbox_q1 : STD_LOGIC_VECTOR (7 downto 0);
    signal sbox_address2 : STD_LOGIC_VECTOR (7 downto 0);
    signal sbox_ce2 : STD_LOGIC;
    signal sbox_q2 : STD_LOGIC_VECTOR (7 downto 0);
    signal sbox_address3 : STD_LOGIC_VECTOR (7 downto 0);
    signal sbox_ce3 : STD_LOGIC;
    signal sbox_q3 : STD_LOGIC_VECTOR (7 downto 0);
    signal Rcon_address0 : STD_LOGIC_VECTOR (3 downto 0);
    signal Rcon_ce0 : STD_LOGIC;
    signal Rcon_q0 : STD_LOGIC_VECTOR (7 downto 0);
    signal reg_374 : STD_LOGIC_VECTOR (7 downto 0);
    signal ap_CS_fsm_state6 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state6 : signal is "none";
    signal ap_CS_fsm_state7 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state7 : signal is "none";
    signal ap_CS_fsm_state8 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state8 : signal is "none";
    signal i_fu_385_p2 : STD_LOGIC_VECTOR (3 downto 0);
    signal i_reg_729 : STD_LOGIC_VECTOR (3 downto 0);
    signal ap_CS_fsm_state2 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state2 : signal is "none";
    signal shl_ln_fu_395_p3 : STD_LOGIC_VECTOR (4 downto 0);
    signal shl_ln_reg_734 : STD_LOGIC_VECTOR (4 downto 0);
    signal icmp_ln158_fu_379_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal zext_ln160_fu_403_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal zext_ln160_reg_740 : STD_LOGIC_VECTOR (63 downto 0);
    signal zext_ln161_fu_414_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal zext_ln161_reg_750 : STD_LOGIC_VECTOR (63 downto 0);
    signal zext_ln162_fu_424_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal zext_ln162_reg_760 : STD_LOGIC_VECTOR (63 downto 0);
    signal ap_CS_fsm_state3 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state3 : signal is "none";
    signal zext_ln163_fu_434_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal zext_ln163_reg_770 : STD_LOGIC_VECTOR (63 downto 0);
    signal j_fu_445_p3 : STD_LOGIC_VECTOR (7 downto 0);
    signal j_reg_783 : STD_LOGIC_VECTOR (7 downto 0);
    signal ap_CS_fsm_state5 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state5 : signal is "none";
    signal icmp_ln167_fu_439_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal icmp_ln178_fu_479_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal icmp_ln178_reg_807 : STD_LOGIC_VECTOR (0 downto 0);
    signal lshr_ln_reg_815 : STD_LOGIC_VECTOR (2 downto 0);
    signal icmp_ln206_fu_495_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal icmp_ln206_reg_820 : STD_LOGIC_VECTOR (0 downto 0);
    signal i_7_fu_501_p2 : STD_LOGIC_VECTOR (5 downto 0);
    signal i_7_reg_828 : STD_LOGIC_VECTOR (5 downto 0);
    signal tempa_1_reg_833 : STD_LOGIC_VECTOR (7 downto 0);
    signal tempa_3_reg_858 : STD_LOGIC_VECTOR (7 downto 0);
    signal tempa_0_2_fu_557_p3 : STD_LOGIC_VECTOR (7 downto 0);
    signal tempa_0_2_reg_878 : STD_LOGIC_VECTOR (7 downto 0);
    signal tempa_3_2_fu_589_p3 : STD_LOGIC_VECTOR (7 downto 0);
    signal tempa_3_2_reg_898 : STD_LOGIC_VECTOR (7 downto 0);
    signal tempa_2_2_fu_595_p3 : STD_LOGIC_VECTOR (7 downto 0);
    signal tempa_2_2_reg_903 : STD_LOGIC_VECTOR (7 downto 0);
    signal tempa_1_2_fu_602_p3 : STD_LOGIC_VECTOR (7 downto 0);
    signal tempa_1_2_reg_908 : STD_LOGIC_VECTOR (7 downto 0);
    signal xor_ln218_fu_629_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal xor_ln218_reg_928 : STD_LOGIC_VECTOR (7 downto 0);
    signal xor_ln220_fu_694_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal xor_ln220_reg_943 : STD_LOGIC_VECTOR (7 downto 0);
    signal ap_CS_fsm_state9 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state9 : signal is "none";
    signal xor_ln221_fu_700_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal xor_ln221_reg_948 : STD_LOGIC_VECTOR (7 downto 0);
    signal i_0_reg_352 : STD_LOGIC_VECTOR (3 downto 0);
    signal ap_CS_fsm_state4 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state4 : signal is "none";
    signal i_1_reg_363 : STD_LOGIC_VECTOR (5 downto 0);
    signal ap_CS_fsm_state10 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state10 : signal is "none";
    signal zext_ln171_fu_459_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal zext_ln172_fu_470_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal zext_ln173_fu_512_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal zext_ln174_fu_522_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal zext_ln197_fu_527_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal zext_ln203_fu_532_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal zext_ln198_fu_536_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal zext_ln199_fu_541_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal zext_ln200_fu_546_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal zext_ln210_fu_564_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal zext_ln218_fu_574_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal zext_ln219_fu_584_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal zext_ln211_fu_608_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal zext_ln212_fu_613_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal zext_ln213_fu_618_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal zext_ln220_fu_640_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal zext_ln221_fu_650_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal zext_ln218_1_fu_673_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal zext_ln219_1_fu_689_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal zext_ln220_1_fu_711_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal zext_ln221_1_fu_721_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal xor_ln219_fu_677_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal trunc_ln160_fu_391_p1 : STD_LOGIC_VECTOR (2 downto 0);
    signal or_ln161_fu_408_p2 : STD_LOGIC_VECTOR (4 downto 0);
    signal or_ln162_fu_419_p2 : STD_LOGIC_VECTOR (4 downto 0);
    signal or_ln163_fu_429_p2 : STD_LOGIC_VECTOR (4 downto 0);
    signal add_ln171_fu_453_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal add_ln172_fu_464_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal trunc_ln167_fu_475_p1 : STD_LOGIC_VECTOR (2 downto 0);
    signal add_ln173_fu_507_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal add_ln174_fu_517_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal tempa_0_fu_551_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal add_ln218_fu_569_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal add_ln219_fu_579_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal tempa_0_4_fu_623_p3 : STD_LOGIC_VECTOR (7 downto 0);
    signal add_ln220_fu_635_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal add_ln221_fu_645_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal tempa_1_4_fu_667_p3 : STD_LOGIC_VECTOR (7 downto 0);
    signal or_ln219_fu_684_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal tempa_2_4_fu_661_p3 : STD_LOGIC_VECTOR (7 downto 0);
    signal tempa_3_4_fu_655_p3 : STD_LOGIC_VECTOR (7 downto 0);
    signal or_ln220_fu_706_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal or_ln221_fu_716_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal ap_NS_fsm : STD_LOGIC_VECTOR (9 downto 0);

    component KeyExpansion_sbox IS
    generic (
        DataWidth : INTEGER;
        AddressRange : INTEGER;
        AddressWidth : INTEGER );
    port (
        clk : IN STD_LOGIC;
        reset : IN STD_LOGIC;
        address0 : IN STD_LOGIC_VECTOR (7 downto 0);
        ce0 : IN STD_LOGIC;
        q0 : OUT STD_LOGIC_VECTOR (7 downto 0);
        address1 : IN STD_LOGIC_VECTOR (7 downto 0);
        ce1 : IN STD_LOGIC;
        q1 : OUT STD_LOGIC_VECTOR (7 downto 0);
        address2 : IN STD_LOGIC_VECTOR (7 downto 0);
        ce2 : IN STD_LOGIC;
        q2 : OUT STD_LOGIC_VECTOR (7 downto 0);
        address3 : IN STD_LOGIC_VECTOR (7 downto 0);
        ce3 : IN STD_LOGIC;
        q3 : OUT STD_LOGIC_VECTOR (7 downto 0) );
    end component;


    component KeyExpansion_Rcon IS
    generic (
        DataWidth : INTEGER;
        AddressRange : INTEGER;
        AddressWidth : INTEGER );
    port (
        clk : IN STD_LOGIC;
        reset : IN STD_LOGIC;
        address0 : IN STD_LOGIC_VECTOR (3 downto 0);
        ce0 : IN STD_LOGIC;
        q0 : OUT STD_LOGIC_VECTOR (7 downto 0) );
    end component;



begin
    sbox_U : component KeyExpansion_sbox
    generic map (
        DataWidth => 8,
        AddressRange => 256,
        AddressWidth => 8)
    port map (
        clk => ap_clk,
        reset => ap_rst,
        address0 => sbox_address0,
        ce0 => sbox_ce0,
        q0 => sbox_q0,
        address1 => sbox_address1,
        ce1 => sbox_ce1,
        q1 => sbox_q1,
        address2 => sbox_address2,
        ce2 => sbox_ce2,
        q2 => sbox_q2,
        address3 => sbox_address3,
        ce3 => sbox_ce3,
        q3 => sbox_q3);

    Rcon_U : component KeyExpansion_Rcon
    generic map (
        DataWidth => 8,
        AddressRange => 11,
        AddressWidth => 4)
    port map (
        clk => ap_clk,
        reset => ap_rst,
        address0 => Rcon_address0,
        ce0 => Rcon_ce0,
        q0 => Rcon_q0);





    ap_CS_fsm_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_CS_fsm <= ap_ST_fsm_state1;
            else
                ap_CS_fsm <= ap_NS_fsm;
            end if;
        end if;
    end process;


    i_0_reg_352_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state4)) then 
                i_0_reg_352 <= i_reg_729;
            elsif (((ap_const_logic_1 = ap_CS_fsm_state1) and (ap_start = ap_const_logic_1))) then 
                i_0_reg_352 <= ap_const_lv4_0;
            end if; 
        end if;
    end process;

    i_1_reg_363_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((ap_const_logic_1 = ap_CS_fsm_state2) and (icmp_ln158_fu_379_p2 = ap_const_lv1_1))) then 
                i_1_reg_363 <= ap_const_lv6_8;
            elsif ((ap_const_logic_1 = ap_CS_fsm_state10)) then 
                i_1_reg_363 <= i_7_reg_828;
            end if; 
        end if;
    end process;

    reg_374_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state8)) then 
                reg_374 <= RoundKey_q1;
            elsif (((ap_const_logic_1 = ap_CS_fsm_state7) or (ap_const_logic_1 = ap_CS_fsm_state6))) then 
                reg_374 <= RoundKey_q0;
            end if; 
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((ap_const_logic_1 = ap_CS_fsm_state5) and (icmp_ln167_fu_439_p2 = ap_const_lv1_0))) then
                i_7_reg_828 <= i_7_fu_501_p2;
                icmp_ln178_reg_807 <= icmp_ln178_fu_479_p2;
                icmp_ln206_reg_820 <= icmp_ln206_fu_495_p2;
                    j_reg_783(7 downto 2) <= j_fu_445_p3(7 downto 2);
                lshr_ln_reg_815 <= i_1_reg_363(5 downto 3);
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state2)) then
                i_reg_729 <= i_fu_385_p2;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((ap_const_logic_1 = ap_CS_fsm_state2) and (icmp_ln158_fu_379_p2 = ap_const_lv1_0))) then
                    shl_ln_reg_734(4 downto 2) <= shl_ln_fu_395_p3(4 downto 2);
                    zext_ln160_reg_740(4 downto 2) <= zext_ln160_fu_403_p1(4 downto 2);
                    zext_ln161_reg_750(4 downto 2) <= zext_ln161_fu_414_p1(4 downto 2);
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state7)) then
                tempa_0_2_reg_878 <= tempa_0_2_fu_557_p3;
                tempa_3_reg_858 <= RoundKey_q1;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state8)) then
                tempa_1_2_reg_908 <= tempa_1_2_fu_602_p3;
                tempa_2_2_reg_903 <= tempa_2_2_fu_595_p3;
                tempa_3_2_reg_898 <= tempa_3_2_fu_589_p3;
                xor_ln218_reg_928 <= xor_ln218_fu_629_p2;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state6)) then
                tempa_1_reg_833 <= RoundKey_q1;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state9)) then
                xor_ln220_reg_943 <= xor_ln220_fu_694_p2;
                xor_ln221_reg_948 <= xor_ln221_fu_700_p2;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state3)) then
                    zext_ln162_reg_760(4 downto 2) <= zext_ln162_fu_424_p1(4 downto 2);
                    zext_ln163_reg_770(4 downto 2) <= zext_ln163_fu_434_p1(4 downto 2);
            end if;
        end if;
    end process;
    shl_ln_reg_734(1 downto 0) <= "00";
    zext_ln160_reg_740(1 downto 0) <= "00";
    zext_ln160_reg_740(63 downto 5) <= "00000000000000000000000000000000000000000000000000000000000";
    zext_ln161_reg_750(1 downto 0) <= "01";
    zext_ln161_reg_750(63 downto 5) <= "00000000000000000000000000000000000000000000000000000000000";
    zext_ln162_reg_760(1 downto 0) <= "10";
    zext_ln162_reg_760(63 downto 5) <= "00000000000000000000000000000000000000000000000000000000000";
    zext_ln163_reg_770(1 downto 0) <= "11";
    zext_ln163_reg_770(63 downto 5) <= "00000000000000000000000000000000000000000000000000000000000";
    j_reg_783(1 downto 0) <= "00";

    ap_NS_fsm_assign_proc : process (ap_start, ap_CS_fsm, ap_CS_fsm_state1, ap_CS_fsm_state2, icmp_ln158_fu_379_p2, ap_CS_fsm_state5, icmp_ln167_fu_439_p2)
    begin
        case ap_CS_fsm is
            when ap_ST_fsm_state1 => 
                if (((ap_const_logic_1 = ap_CS_fsm_state1) and (ap_start = ap_const_logic_1))) then
                    ap_NS_fsm <= ap_ST_fsm_state2;
                else
                    ap_NS_fsm <= ap_ST_fsm_state1;
                end if;
            when ap_ST_fsm_state2 => 
                if (((ap_const_logic_1 = ap_CS_fsm_state2) and (icmp_ln158_fu_379_p2 = ap_const_lv1_1))) then
                    ap_NS_fsm <= ap_ST_fsm_state5;
                else
                    ap_NS_fsm <= ap_ST_fsm_state3;
                end if;
            when ap_ST_fsm_state3 => 
                ap_NS_fsm <= ap_ST_fsm_state4;
            when ap_ST_fsm_state4 => 
                ap_NS_fsm <= ap_ST_fsm_state2;
            when ap_ST_fsm_state5 => 
                if (((ap_const_logic_1 = ap_CS_fsm_state5) and (icmp_ln167_fu_439_p2 = ap_const_lv1_1))) then
                    ap_NS_fsm <= ap_ST_fsm_state1;
                else
                    ap_NS_fsm <= ap_ST_fsm_state6;
                end if;
            when ap_ST_fsm_state6 => 
                ap_NS_fsm <= ap_ST_fsm_state7;
            when ap_ST_fsm_state7 => 
                ap_NS_fsm <= ap_ST_fsm_state8;
            when ap_ST_fsm_state8 => 
                ap_NS_fsm <= ap_ST_fsm_state9;
            when ap_ST_fsm_state9 => 
                ap_NS_fsm <= ap_ST_fsm_state10;
            when ap_ST_fsm_state10 => 
                ap_NS_fsm <= ap_ST_fsm_state5;
            when others =>  
                ap_NS_fsm <= "XXXXXXXXXX";
        end case;
    end process;

    Key_address0_assign_proc : process(ap_CS_fsm_state2, zext_ln160_fu_403_p1, zext_ln162_fu_424_p1, ap_CS_fsm_state3)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state3)) then 
            Key_address0 <= zext_ln162_fu_424_p1(5 - 1 downto 0);
        elsif ((ap_const_logic_1 = ap_CS_fsm_state2)) then 
            Key_address0 <= zext_ln160_fu_403_p1(5 - 1 downto 0);
        else 
            Key_address0 <= "XXXXX";
        end if; 
    end process;


    Key_address1_assign_proc : process(ap_CS_fsm_state2, zext_ln161_fu_414_p1, ap_CS_fsm_state3, zext_ln163_fu_434_p1)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state3)) then 
            Key_address1 <= zext_ln163_fu_434_p1(5 - 1 downto 0);
        elsif ((ap_const_logic_1 = ap_CS_fsm_state2)) then 
            Key_address1 <= zext_ln161_fu_414_p1(5 - 1 downto 0);
        else 
            Key_address1 <= "XXXXX";
        end if; 
    end process;


    Key_ce0_assign_proc : process(ap_CS_fsm_state2, ap_CS_fsm_state3)
    begin
        if (((ap_const_logic_1 = ap_CS_fsm_state3) or (ap_const_logic_1 = ap_CS_fsm_state2))) then 
            Key_ce0 <= ap_const_logic_1;
        else 
            Key_ce0 <= ap_const_logic_0;
        end if; 
    end process;


    Key_ce1_assign_proc : process(ap_CS_fsm_state2, ap_CS_fsm_state3)
    begin
        if (((ap_const_logic_1 = ap_CS_fsm_state3) or (ap_const_logic_1 = ap_CS_fsm_state2))) then 
            Key_ce1 <= ap_const_logic_1;
        else 
            Key_ce1 <= ap_const_logic_0;
        end if; 
    end process;

    Rcon_address0 <= zext_ln203_fu_532_p1(4 - 1 downto 0);

    Rcon_ce0_assign_proc : process(ap_CS_fsm_state6)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state6)) then 
            Rcon_ce0 <= ap_const_logic_1;
        else 
            Rcon_ce0 <= ap_const_logic_0;
        end if; 
    end process;


    RoundKey_address0_assign_proc : process(ap_CS_fsm_state6, ap_CS_fsm_state7, ap_CS_fsm_state8, zext_ln160_reg_740, zext_ln162_reg_760, ap_CS_fsm_state3, ap_CS_fsm_state5, ap_CS_fsm_state9, ap_CS_fsm_state4, ap_CS_fsm_state10, zext_ln171_fu_459_p1, zext_ln173_fu_512_p1, zext_ln218_fu_574_p1, zext_ln220_fu_640_p1, zext_ln218_1_fu_673_p1, zext_ln220_1_fu_711_p1)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state10)) then 
            RoundKey_address0 <= zext_ln220_1_fu_711_p1(8 - 1 downto 0);
        elsif ((ap_const_logic_1 = ap_CS_fsm_state9)) then 
            RoundKey_address0 <= zext_ln218_1_fu_673_p1(8 - 1 downto 0);
        elsif ((ap_const_logic_1 = ap_CS_fsm_state8)) then 
            RoundKey_address0 <= zext_ln220_fu_640_p1(8 - 1 downto 0);
        elsif ((ap_const_logic_1 = ap_CS_fsm_state7)) then 
            RoundKey_address0 <= zext_ln218_fu_574_p1(8 - 1 downto 0);
        elsif ((ap_const_logic_1 = ap_CS_fsm_state6)) then 
            RoundKey_address0 <= zext_ln173_fu_512_p1(8 - 1 downto 0);
        elsif ((ap_const_logic_1 = ap_CS_fsm_state5)) then 
            RoundKey_address0 <= zext_ln171_fu_459_p1(8 - 1 downto 0);
        elsif ((ap_const_logic_1 = ap_CS_fsm_state4)) then 
            RoundKey_address0 <= zext_ln162_reg_760(8 - 1 downto 0);
        elsif ((ap_const_logic_1 = ap_CS_fsm_state3)) then 
            RoundKey_address0 <= zext_ln160_reg_740(8 - 1 downto 0);
        else 
            RoundKey_address0 <= "XXXXXXXX";
        end if; 
    end process;


    RoundKey_address1_assign_proc : process(ap_CS_fsm_state6, ap_CS_fsm_state7, ap_CS_fsm_state8, zext_ln161_reg_750, ap_CS_fsm_state3, zext_ln163_reg_770, ap_CS_fsm_state5, ap_CS_fsm_state9, ap_CS_fsm_state4, ap_CS_fsm_state10, zext_ln172_fu_470_p1, zext_ln174_fu_522_p1, zext_ln219_fu_584_p1, zext_ln221_fu_650_p1, zext_ln219_1_fu_689_p1, zext_ln221_1_fu_721_p1)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state10)) then 
            RoundKey_address1 <= zext_ln221_1_fu_721_p1(8 - 1 downto 0);
        elsif ((ap_const_logic_1 = ap_CS_fsm_state9)) then 
            RoundKey_address1 <= zext_ln219_1_fu_689_p1(8 - 1 downto 0);
        elsif ((ap_const_logic_1 = ap_CS_fsm_state8)) then 
            RoundKey_address1 <= zext_ln221_fu_650_p1(8 - 1 downto 0);
        elsif ((ap_const_logic_1 = ap_CS_fsm_state7)) then 
            RoundKey_address1 <= zext_ln219_fu_584_p1(8 - 1 downto 0);
        elsif ((ap_const_logic_1 = ap_CS_fsm_state6)) then 
            RoundKey_address1 <= zext_ln174_fu_522_p1(8 - 1 downto 0);
        elsif ((ap_const_logic_1 = ap_CS_fsm_state5)) then 
            RoundKey_address1 <= zext_ln172_fu_470_p1(8 - 1 downto 0);
        elsif ((ap_const_logic_1 = ap_CS_fsm_state4)) then 
            RoundKey_address1 <= zext_ln163_reg_770(8 - 1 downto 0);
        elsif ((ap_const_logic_1 = ap_CS_fsm_state3)) then 
            RoundKey_address1 <= zext_ln161_reg_750(8 - 1 downto 0);
        else 
            RoundKey_address1 <= "XXXXXXXX";
        end if; 
    end process;


    RoundKey_ce0_assign_proc : process(ap_CS_fsm_state6, ap_CS_fsm_state7, ap_CS_fsm_state8, ap_CS_fsm_state3, ap_CS_fsm_state5, ap_CS_fsm_state9, ap_CS_fsm_state4, ap_CS_fsm_state10)
    begin
        if (((ap_const_logic_1 = ap_CS_fsm_state8) or (ap_const_logic_1 = ap_CS_fsm_state7) or (ap_const_logic_1 = ap_CS_fsm_state6) or (ap_const_logic_1 = ap_CS_fsm_state10) or (ap_const_logic_1 = ap_CS_fsm_state4) or (ap_const_logic_1 = ap_CS_fsm_state9) or (ap_const_logic_1 = ap_CS_fsm_state5) or (ap_const_logic_1 = ap_CS_fsm_state3))) then 
            RoundKey_ce0 <= ap_const_logic_1;
        else 
            RoundKey_ce0 <= ap_const_logic_0;
        end if; 
    end process;


    RoundKey_ce1_assign_proc : process(ap_CS_fsm_state6, ap_CS_fsm_state7, ap_CS_fsm_state8, ap_CS_fsm_state3, ap_CS_fsm_state5, ap_CS_fsm_state9, ap_CS_fsm_state4, ap_CS_fsm_state10)
    begin
        if (((ap_const_logic_1 = ap_CS_fsm_state8) or (ap_const_logic_1 = ap_CS_fsm_state7) or (ap_const_logic_1 = ap_CS_fsm_state6) or (ap_const_logic_1 = ap_CS_fsm_state10) or (ap_const_logic_1 = ap_CS_fsm_state4) or (ap_const_logic_1 = ap_CS_fsm_state9) or (ap_const_logic_1 = ap_CS_fsm_state5) or (ap_const_logic_1 = ap_CS_fsm_state3))) then 
            RoundKey_ce1 <= ap_const_logic_1;
        else 
            RoundKey_ce1 <= ap_const_logic_0;
        end if; 
    end process;


    RoundKey_d0_assign_proc : process(Key_q0, ap_CS_fsm_state3, xor_ln218_reg_928, xor_ln220_reg_943, ap_CS_fsm_state9, ap_CS_fsm_state4, ap_CS_fsm_state10)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state10)) then 
            RoundKey_d0 <= xor_ln220_reg_943;
        elsif ((ap_const_logic_1 = ap_CS_fsm_state9)) then 
            RoundKey_d0 <= xor_ln218_reg_928;
        elsif (((ap_const_logic_1 = ap_CS_fsm_state4) or (ap_const_logic_1 = ap_CS_fsm_state3))) then 
            RoundKey_d0 <= Key_q0;
        else 
            RoundKey_d0 <= "XXXXXXXX";
        end if; 
    end process;


    RoundKey_d1_assign_proc : process(Key_q1, ap_CS_fsm_state3, ap_CS_fsm_state9, xor_ln221_reg_948, ap_CS_fsm_state4, ap_CS_fsm_state10, xor_ln219_fu_677_p2)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state10)) then 
            RoundKey_d1 <= xor_ln221_reg_948;
        elsif ((ap_const_logic_1 = ap_CS_fsm_state9)) then 
            RoundKey_d1 <= xor_ln219_fu_677_p2;
        elsif (((ap_const_logic_1 = ap_CS_fsm_state4) or (ap_const_logic_1 = ap_CS_fsm_state3))) then 
            RoundKey_d1 <= Key_q1;
        else 
            RoundKey_d1 <= "XXXXXXXX";
        end if; 
    end process;


    RoundKey_we0_assign_proc : process(ap_CS_fsm_state3, ap_CS_fsm_state9, ap_CS_fsm_state4, ap_CS_fsm_state10)
    begin
        if (((ap_const_logic_1 = ap_CS_fsm_state10) or (ap_const_logic_1 = ap_CS_fsm_state4) or (ap_const_logic_1 = ap_CS_fsm_state9) or (ap_const_logic_1 = ap_CS_fsm_state3))) then 
            RoundKey_we0 <= ap_const_logic_1;
        else 
            RoundKey_we0 <= ap_const_logic_0;
        end if; 
    end process;


    RoundKey_we1_assign_proc : process(ap_CS_fsm_state3, ap_CS_fsm_state9, ap_CS_fsm_state4, ap_CS_fsm_state10)
    begin
        if (((ap_const_logic_1 = ap_CS_fsm_state10) or (ap_const_logic_1 = ap_CS_fsm_state4) or (ap_const_logic_1 = ap_CS_fsm_state9) or (ap_const_logic_1 = ap_CS_fsm_state3))) then 
            RoundKey_we1 <= ap_const_logic_1;
        else 
            RoundKey_we1 <= ap_const_logic_0;
        end if; 
    end process;

    add_ln171_fu_453_p2 <= std_logic_vector(signed(ap_const_lv8_FC) + signed(j_fu_445_p3));
    add_ln172_fu_464_p2 <= std_logic_vector(signed(ap_const_lv8_FD) + signed(j_fu_445_p3));
    add_ln173_fu_507_p2 <= std_logic_vector(signed(ap_const_lv8_FE) + signed(j_reg_783));
    add_ln174_fu_517_p2 <= std_logic_vector(signed(ap_const_lv8_FF) + signed(j_reg_783));
    add_ln218_fu_569_p2 <= std_logic_vector(signed(ap_const_lv8_E0) + signed(j_reg_783));
    add_ln219_fu_579_p2 <= std_logic_vector(signed(ap_const_lv8_E1) + signed(j_reg_783));
    add_ln220_fu_635_p2 <= std_logic_vector(signed(ap_const_lv8_E2) + signed(j_reg_783));
    add_ln221_fu_645_p2 <= std_logic_vector(signed(ap_const_lv8_E3) + signed(j_reg_783));
    ap_CS_fsm_state1 <= ap_CS_fsm(0);
    ap_CS_fsm_state10 <= ap_CS_fsm(9);
    ap_CS_fsm_state2 <= ap_CS_fsm(1);
    ap_CS_fsm_state3 <= ap_CS_fsm(2);
    ap_CS_fsm_state4 <= ap_CS_fsm(3);
    ap_CS_fsm_state5 <= ap_CS_fsm(4);
    ap_CS_fsm_state6 <= ap_CS_fsm(5);
    ap_CS_fsm_state7 <= ap_CS_fsm(6);
    ap_CS_fsm_state8 <= ap_CS_fsm(7);
    ap_CS_fsm_state9 <= ap_CS_fsm(8);

    ap_done_assign_proc : process(ap_start, ap_CS_fsm_state1, ap_CS_fsm_state5, icmp_ln167_fu_439_p2)
    begin
        if ((((ap_start = ap_const_logic_0) and (ap_const_logic_1 = ap_CS_fsm_state1)) or ((ap_const_logic_1 = ap_CS_fsm_state5) and (icmp_ln167_fu_439_p2 = ap_const_lv1_1)))) then 
            ap_done <= ap_const_logic_1;
        else 
            ap_done <= ap_const_logic_0;
        end if; 
    end process;


    ap_idle_assign_proc : process(ap_start, ap_CS_fsm_state1)
    begin
        if (((ap_start = ap_const_logic_0) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
            ap_idle <= ap_const_logic_1;
        else 
            ap_idle <= ap_const_logic_0;
        end if; 
    end process;


    ap_ready_assign_proc : process(ap_CS_fsm_state5, icmp_ln167_fu_439_p2)
    begin
        if (((ap_const_logic_1 = ap_CS_fsm_state5) and (icmp_ln167_fu_439_p2 = ap_const_lv1_1))) then 
            ap_ready <= ap_const_logic_1;
        else 
            ap_ready <= ap_const_logic_0;
        end if; 
    end process;

    i_7_fu_501_p2 <= std_logic_vector(unsigned(ap_const_lv6_1) + unsigned(i_1_reg_363));
    i_fu_385_p2 <= std_logic_vector(unsigned(i_0_reg_352) + unsigned(ap_const_lv4_1));
    icmp_ln158_fu_379_p2 <= "1" when (i_0_reg_352 = ap_const_lv4_8) else "0";
    icmp_ln167_fu_439_p2 <= "1" when (i_1_reg_363 = ap_const_lv6_3C) else "0";
    icmp_ln178_fu_479_p2 <= "1" when (trunc_ln167_fu_475_p1 = ap_const_lv3_0) else "0";
    icmp_ln206_fu_495_p2 <= "1" when (trunc_ln167_fu_475_p1 = ap_const_lv3_4) else "0";
    j_fu_445_p3 <= (i_1_reg_363 & ap_const_lv2_0);
    or_ln161_fu_408_p2 <= (shl_ln_fu_395_p3 or ap_const_lv5_1);
    or_ln162_fu_419_p2 <= (shl_ln_reg_734 or ap_const_lv5_2);
    or_ln163_fu_429_p2 <= (shl_ln_reg_734 or ap_const_lv5_3);
    or_ln219_fu_684_p2 <= (j_reg_783 or ap_const_lv8_1);
    or_ln220_fu_706_p2 <= (j_reg_783 or ap_const_lv8_2);
    or_ln221_fu_716_p2 <= (j_reg_783 or ap_const_lv8_3);

    sbox_address0_assign_proc : process(ap_CS_fsm_state6, ap_CS_fsm_state7, ap_CS_fsm_state8, zext_ln197_fu_527_p1, zext_ln198_fu_536_p1, zext_ln211_fu_608_p1)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state8)) then 
            sbox_address0 <= zext_ln211_fu_608_p1(8 - 1 downto 0);
        elsif ((ap_const_logic_1 = ap_CS_fsm_state7)) then 
            sbox_address0 <= zext_ln198_fu_536_p1(8 - 1 downto 0);
        elsif ((ap_const_logic_1 = ap_CS_fsm_state6)) then 
            sbox_address0 <= zext_ln197_fu_527_p1(8 - 1 downto 0);
        else 
            sbox_address0 <= "XXXXXXXX";
        end if; 
    end process;


    sbox_address1_assign_proc : process(ap_CS_fsm_state7, ap_CS_fsm_state8, zext_ln199_fu_541_p1, zext_ln212_fu_613_p1)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state8)) then 
            sbox_address1 <= zext_ln212_fu_613_p1(8 - 1 downto 0);
        elsif ((ap_const_logic_1 = ap_CS_fsm_state7)) then 
            sbox_address1 <= zext_ln199_fu_541_p1(8 - 1 downto 0);
        else 
            sbox_address1 <= "XXXXXXXX";
        end if; 
    end process;


    sbox_address2_assign_proc : process(ap_CS_fsm_state7, ap_CS_fsm_state8, zext_ln200_fu_546_p1, zext_ln213_fu_618_p1)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state8)) then 
            sbox_address2 <= zext_ln213_fu_618_p1(8 - 1 downto 0);
        elsif ((ap_const_logic_1 = ap_CS_fsm_state7)) then 
            sbox_address2 <= zext_ln200_fu_546_p1(8 - 1 downto 0);
        else 
            sbox_address2 <= "XXXXXXXX";
        end if; 
    end process;

    sbox_address3 <= zext_ln210_fu_564_p1(8 - 1 downto 0);

    sbox_ce0_assign_proc : process(ap_CS_fsm_state6, ap_CS_fsm_state7, ap_CS_fsm_state8)
    begin
        if (((ap_const_logic_1 = ap_CS_fsm_state8) or (ap_const_logic_1 = ap_CS_fsm_state7) or (ap_const_logic_1 = ap_CS_fsm_state6))) then 
            sbox_ce0 <= ap_const_logic_1;
        else 
            sbox_ce0 <= ap_const_logic_0;
        end if; 
    end process;


    sbox_ce1_assign_proc : process(ap_CS_fsm_state7, ap_CS_fsm_state8)
    begin
        if (((ap_const_logic_1 = ap_CS_fsm_state8) or (ap_const_logic_1 = ap_CS_fsm_state7))) then 
            sbox_ce1 <= ap_const_logic_1;
        else 
            sbox_ce1 <= ap_const_logic_0;
        end if; 
    end process;


    sbox_ce2_assign_proc : process(ap_CS_fsm_state7, ap_CS_fsm_state8)
    begin
        if (((ap_const_logic_1 = ap_CS_fsm_state8) or (ap_const_logic_1 = ap_CS_fsm_state7))) then 
            sbox_ce2 <= ap_const_logic_1;
        else 
            sbox_ce2 <= ap_const_logic_0;
        end if; 
    end process;


    sbox_ce3_assign_proc : process(ap_CS_fsm_state7)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state7)) then 
            sbox_ce3 <= ap_const_logic_1;
        else 
            sbox_ce3 <= ap_const_logic_0;
        end if; 
    end process;

    shl_ln_fu_395_p3 <= (trunc_ln160_fu_391_p1 & ap_const_lv2_0);
    tempa_0_2_fu_557_p3 <= 
        tempa_0_fu_551_p2 when (icmp_ln178_reg_807(0) = '1') else 
        reg_374;
    tempa_0_4_fu_623_p3 <= 
        sbox_q3 when (icmp_ln206_reg_820(0) = '1') else 
        tempa_0_2_reg_878;
    tempa_0_fu_551_p2 <= (sbox_q0 xor Rcon_q0);
    tempa_1_2_fu_602_p3 <= 
        sbox_q0 when (icmp_ln178_reg_807(0) = '1') else 
        tempa_1_reg_833;
    tempa_1_4_fu_667_p3 <= 
        sbox_q0 when (icmp_ln206_reg_820(0) = '1') else 
        tempa_1_2_reg_908;
    tempa_2_2_fu_595_p3 <= 
        sbox_q1 when (icmp_ln178_reg_807(0) = '1') else 
        reg_374;
    tempa_2_4_fu_661_p3 <= 
        sbox_q1 when (icmp_ln206_reg_820(0) = '1') else 
        tempa_2_2_reg_903;
    tempa_3_2_fu_589_p3 <= 
        sbox_q2 when (icmp_ln178_reg_807(0) = '1') else 
        tempa_3_reg_858;
    tempa_3_4_fu_655_p3 <= 
        sbox_q2 when (icmp_ln206_reg_820(0) = '1') else 
        tempa_3_2_reg_898;
    trunc_ln160_fu_391_p1 <= i_0_reg_352(3 - 1 downto 0);
    trunc_ln167_fu_475_p1 <= i_1_reg_363(3 - 1 downto 0);
    xor_ln218_fu_629_p2 <= (tempa_0_4_fu_623_p3 xor RoundKey_q0);
    xor_ln219_fu_677_p2 <= (tempa_1_4_fu_667_p3 xor reg_374);
    xor_ln220_fu_694_p2 <= (tempa_2_4_fu_661_p3 xor RoundKey_q0);
    xor_ln221_fu_700_p2 <= (tempa_3_4_fu_655_p3 xor RoundKey_q1);
    zext_ln160_fu_403_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(shl_ln_fu_395_p3),64));
    zext_ln161_fu_414_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(or_ln161_fu_408_p2),64));
    zext_ln162_fu_424_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(or_ln162_fu_419_p2),64));
    zext_ln163_fu_434_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(or_ln163_fu_429_p2),64));
    zext_ln171_fu_459_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(add_ln171_fu_453_p2),64));
    zext_ln172_fu_470_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(add_ln172_fu_464_p2),64));
    zext_ln173_fu_512_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(add_ln173_fu_507_p2),64));
    zext_ln174_fu_522_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(add_ln174_fu_517_p2),64));
    zext_ln197_fu_527_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(RoundKey_q1),64));
    zext_ln198_fu_536_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(RoundKey_q0),64));
    zext_ln199_fu_541_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(RoundKey_q1),64));
    zext_ln200_fu_546_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(reg_374),64));
    zext_ln203_fu_532_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(lshr_ln_reg_815),64));
    zext_ln210_fu_564_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(tempa_0_2_fu_557_p3),64));
    zext_ln211_fu_608_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(tempa_1_2_fu_602_p3),64));
    zext_ln212_fu_613_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(tempa_2_2_fu_595_p3),64));
    zext_ln213_fu_618_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(tempa_3_2_fu_589_p3),64));
    zext_ln218_1_fu_673_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(j_reg_783),64));
    zext_ln218_fu_574_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(add_ln218_fu_569_p2),64));
    zext_ln219_1_fu_689_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(or_ln219_fu_684_p2),64));
    zext_ln219_fu_584_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(add_ln219_fu_579_p2),64));
    zext_ln220_1_fu_711_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(or_ln220_fu_706_p2),64));
    zext_ln220_fu_640_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(add_ln220_fu_635_p2),64));
    zext_ln221_1_fu_721_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(or_ln221_fu_716_p2),64));
    zext_ln221_fu_650_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(add_ln221_fu_645_p2),64));
end behav;
