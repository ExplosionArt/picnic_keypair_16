-- ==============================================================
-- RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and OpenCL
-- Version: 2019.2
-- Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
-- 
-- ===========================================================

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity SubBytes is
port (
    ap_clk : IN STD_LOGIC;
    ap_rst : IN STD_LOGIC;
    ap_start : IN STD_LOGIC;
    ap_done : OUT STD_LOGIC;
    ap_idle : OUT STD_LOGIC;
    ap_ready : OUT STD_LOGIC;
    state_address0 : OUT STD_LOGIC_VECTOR (3 downto 0);
    state_ce0 : OUT STD_LOGIC;
    state_we0 : OUT STD_LOGIC;
    state_d0 : OUT STD_LOGIC_VECTOR (7 downto 0);
    state_q0 : IN STD_LOGIC_VECTOR (7 downto 0) );
end;


architecture behav of SubBytes is 
    constant ap_const_logic_1 : STD_LOGIC := '1';
    constant ap_const_logic_0 : STD_LOGIC := '0';
    constant ap_ST_fsm_state1 : STD_LOGIC_VECTOR (4 downto 0) := "00001";
    constant ap_ST_fsm_state2 : STD_LOGIC_VECTOR (4 downto 0) := "00010";
    constant ap_ST_fsm_state3 : STD_LOGIC_VECTOR (4 downto 0) := "00100";
    constant ap_ST_fsm_state4 : STD_LOGIC_VECTOR (4 downto 0) := "01000";
    constant ap_ST_fsm_state5 : STD_LOGIC_VECTOR (4 downto 0) := "10000";
    constant ap_const_lv32_0 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000000";
    constant ap_const_lv32_1 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000001";
    constant ap_const_lv1_0 : STD_LOGIC_VECTOR (0 downto 0) := "0";
    constant ap_const_lv32_2 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000010";
    constant ap_const_lv32_3 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000011";
    constant ap_const_lv3_0 : STD_LOGIC_VECTOR (2 downto 0) := "000";
    constant ap_const_lv1_1 : STD_LOGIC_VECTOR (0 downto 0) := "1";
    constant ap_const_lv32_4 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000100";
    constant ap_const_lv3_4 : STD_LOGIC_VECTOR (2 downto 0) := "100";
    constant ap_const_lv3_1 : STD_LOGIC_VECTOR (2 downto 0) := "001";
    constant ap_const_lv2_0 : STD_LOGIC_VECTOR (1 downto 0) := "00";
    constant ap_const_boolean_1 : BOOLEAN := true;

    signal ap_CS_fsm : STD_LOGIC_VECTOR (4 downto 0) := "00001";
    attribute fsm_encoding : string;
    attribute fsm_encoding of ap_CS_fsm : signal is "none";
    signal ap_CS_fsm_state1 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state1 : signal is "none";
    signal sbox_address0 : STD_LOGIC_VECTOR (7 downto 0);
    signal sbox_ce0 : STD_LOGIC;
    signal sbox_q0 : STD_LOGIC_VECTOR (7 downto 0);
    signal i_fu_85_p2 : STD_LOGIC_VECTOR (2 downto 0);
    signal i_reg_137 : STD_LOGIC_VECTOR (2 downto 0);
    signal ap_CS_fsm_state2 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state2 : signal is "none";
    signal zext_ln262_fu_91_p1 : STD_LOGIC_VECTOR (5 downto 0);
    signal zext_ln262_reg_142 : STD_LOGIC_VECTOR (5 downto 0);
    signal icmp_ln260_fu_79_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal j_fu_101_p2 : STD_LOGIC_VECTOR (2 downto 0);
    signal j_reg_150 : STD_LOGIC_VECTOR (2 downto 0);
    signal ap_CS_fsm_state3 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state3 : signal is "none";
    signal state_addr_reg_155 : STD_LOGIC_VECTOR (3 downto 0);
    signal icmp_ln262_fu_95_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal ap_CS_fsm_state4 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state4 : signal is "none";
    signal i_0_reg_57 : STD_LOGIC_VECTOR (2 downto 0);
    signal j_0_reg_68 : STD_LOGIC_VECTOR (2 downto 0);
    signal ap_CS_fsm_state5 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state5 : signal is "none";
    signal zext_ln264_1_fu_124_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal zext_ln264_2_fu_129_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal tmp_9_fu_107_p3 : STD_LOGIC_VECTOR (4 downto 0);
    signal zext_ln264_fu_115_p1 : STD_LOGIC_VECTOR (5 downto 0);
    signal add_ln264_fu_119_p2 : STD_LOGIC_VECTOR (5 downto 0);
    signal ap_NS_fsm : STD_LOGIC_VECTOR (4 downto 0);

    component SubBytes_sbox IS
    generic (
        DataWidth : INTEGER;
        AddressRange : INTEGER;
        AddressWidth : INTEGER );
    port (
        clk : IN STD_LOGIC;
        reset : IN STD_LOGIC;
        address0 : IN STD_LOGIC_VECTOR (7 downto 0);
        ce0 : IN STD_LOGIC;
        q0 : OUT STD_LOGIC_VECTOR (7 downto 0) );
    end component;



begin
    sbox_U : component SubBytes_sbox
    generic map (
        DataWidth => 8,
        AddressRange => 256,
        AddressWidth => 8)
    port map (
        clk => ap_clk,
        reset => ap_rst,
        address0 => sbox_address0,
        ce0 => sbox_ce0,
        q0 => sbox_q0);





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


    i_0_reg_57_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((icmp_ln262_fu_95_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state3))) then 
                i_0_reg_57 <= i_reg_137;
            elsif (((ap_const_logic_1 = ap_CS_fsm_state1) and (ap_start = ap_const_logic_1))) then 
                i_0_reg_57 <= ap_const_lv3_0;
            end if; 
        end if;
    end process;

    j_0_reg_68_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state5)) then 
                j_0_reg_68 <= j_reg_150;
            elsif (((icmp_ln260_fu_79_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state2))) then 
                j_0_reg_68 <= ap_const_lv3_0;
            end if; 
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state2)) then
                i_reg_137 <= i_fu_85_p2;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state3)) then
                j_reg_150 <= j_fu_101_p2;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((icmp_ln262_fu_95_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state3))) then
                state_addr_reg_155 <= zext_ln264_1_fu_124_p1(4 - 1 downto 0);
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((icmp_ln260_fu_79_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state2))) then
                    zext_ln262_reg_142(2 downto 0) <= zext_ln262_fu_91_p1(2 downto 0);
            end if;
        end if;
    end process;
    zext_ln262_reg_142(5 downto 3) <= "000";

    ap_NS_fsm_assign_proc : process (ap_start, ap_CS_fsm, ap_CS_fsm_state1, ap_CS_fsm_state2, icmp_ln260_fu_79_p2, ap_CS_fsm_state3, icmp_ln262_fu_95_p2)
    begin
        case ap_CS_fsm is
            when ap_ST_fsm_state1 => 
                if (((ap_const_logic_1 = ap_CS_fsm_state1) and (ap_start = ap_const_logic_1))) then
                    ap_NS_fsm <= ap_ST_fsm_state2;
                else
                    ap_NS_fsm <= ap_ST_fsm_state1;
                end if;
            when ap_ST_fsm_state2 => 
                if (((icmp_ln260_fu_79_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state2))) then
                    ap_NS_fsm <= ap_ST_fsm_state1;
                else
                    ap_NS_fsm <= ap_ST_fsm_state3;
                end if;
            when ap_ST_fsm_state3 => 
                if (((icmp_ln262_fu_95_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state3))) then
                    ap_NS_fsm <= ap_ST_fsm_state2;
                else
                    ap_NS_fsm <= ap_ST_fsm_state4;
                end if;
            when ap_ST_fsm_state4 => 
                ap_NS_fsm <= ap_ST_fsm_state5;
            when ap_ST_fsm_state5 => 
                ap_NS_fsm <= ap_ST_fsm_state3;
            when others =>  
                ap_NS_fsm <= "XXXXX";
        end case;
    end process;
    add_ln264_fu_119_p2 <= std_logic_vector(unsigned(zext_ln262_reg_142) + unsigned(zext_ln264_fu_115_p1));
    ap_CS_fsm_state1 <= ap_CS_fsm(0);
    ap_CS_fsm_state2 <= ap_CS_fsm(1);
    ap_CS_fsm_state3 <= ap_CS_fsm(2);
    ap_CS_fsm_state4 <= ap_CS_fsm(3);
    ap_CS_fsm_state5 <= ap_CS_fsm(4);

    ap_done_assign_proc : process(ap_start, ap_CS_fsm_state1, ap_CS_fsm_state2, icmp_ln260_fu_79_p2)
    begin
        if ((((icmp_ln260_fu_79_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state2)) or ((ap_start = ap_const_logic_0) and (ap_const_logic_1 = ap_CS_fsm_state1)))) then 
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


    ap_ready_assign_proc : process(ap_CS_fsm_state2, icmp_ln260_fu_79_p2)
    begin
        if (((icmp_ln260_fu_79_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state2))) then 
            ap_ready <= ap_const_logic_1;
        else 
            ap_ready <= ap_const_logic_0;
        end if; 
    end process;

    i_fu_85_p2 <= std_logic_vector(unsigned(i_0_reg_57) + unsigned(ap_const_lv3_1));
    icmp_ln260_fu_79_p2 <= "1" when (i_0_reg_57 = ap_const_lv3_4) else "0";
    icmp_ln262_fu_95_p2 <= "1" when (j_0_reg_68 = ap_const_lv3_4) else "0";
    j_fu_101_p2 <= std_logic_vector(unsigned(j_0_reg_68) + unsigned(ap_const_lv3_1));
    sbox_address0 <= zext_ln264_2_fu_129_p1(8 - 1 downto 0);

    sbox_ce0_assign_proc : process(ap_CS_fsm_state4)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state4)) then 
            sbox_ce0 <= ap_const_logic_1;
        else 
            sbox_ce0 <= ap_const_logic_0;
        end if; 
    end process;


    state_address0_assign_proc : process(ap_CS_fsm_state3, state_addr_reg_155, ap_CS_fsm_state5, zext_ln264_1_fu_124_p1)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state5)) then 
            state_address0 <= state_addr_reg_155;
        elsif ((ap_const_logic_1 = ap_CS_fsm_state3)) then 
            state_address0 <= zext_ln264_1_fu_124_p1(4 - 1 downto 0);
        else 
            state_address0 <= "XXXX";
        end if; 
    end process;


    state_ce0_assign_proc : process(ap_CS_fsm_state3, ap_CS_fsm_state5)
    begin
        if (((ap_const_logic_1 = ap_CS_fsm_state5) or (ap_const_logic_1 = ap_CS_fsm_state3))) then 
            state_ce0 <= ap_const_logic_1;
        else 
            state_ce0 <= ap_const_logic_0;
        end if; 
    end process;

    state_d0 <= sbox_q0;

    state_we0_assign_proc : process(ap_CS_fsm_state5)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state5)) then 
            state_we0 <= ap_const_logic_1;
        else 
            state_we0 <= ap_const_logic_0;
        end if; 
    end process;

    tmp_9_fu_107_p3 <= (j_0_reg_68 & ap_const_lv2_0);
    zext_ln262_fu_91_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(i_0_reg_57),6));
    zext_ln264_1_fu_124_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(add_ln264_fu_119_p2),64));
    zext_ln264_2_fu_129_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(state_q0),64));
    zext_ln264_fu_115_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(tmp_9_fu_107_p3),6));
end behav;
