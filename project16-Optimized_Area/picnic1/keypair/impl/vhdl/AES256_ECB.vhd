-- ==============================================================
-- RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and OpenCL
-- Version: 2019.2
-- Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
-- 
-- ===========================================================

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity AES256_ECB is
port (
    ap_clk : IN STD_LOGIC;
    ap_rst : IN STD_LOGIC;
    ap_start : IN STD_LOGIC;
    ap_done : OUT STD_LOGIC;
    ap_idle : OUT STD_LOGIC;
    ap_ready : OUT STD_LOGIC;
    key_address0 : OUT STD_LOGIC_VECTOR (4 downto 0);
    key_ce0 : OUT STD_LOGIC;
    key_q0 : IN STD_LOGIC_VECTOR (7 downto 0);
    ctr_address0 : OUT STD_LOGIC_VECTOR (3 downto 0);
    ctr_ce0 : OUT STD_LOGIC;
    ctr_q0 : IN STD_LOGIC_VECTOR (7 downto 0);
    buffer_r_address0 : OUT STD_LOGIC_VECTOR (5 downto 0);
    buffer_r_ce0 : OUT STD_LOGIC;
    buffer_r_we0 : OUT STD_LOGIC;
    buffer_r_d0 : OUT STD_LOGIC_VECTOR (7 downto 0);
    buffer_offset : IN STD_LOGIC_VECTOR (5 downto 0) );
end;


architecture behav of AES256_ECB is 
    constant ap_const_logic_1 : STD_LOGIC := '1';
    constant ap_const_logic_0 : STD_LOGIC := '0';
    constant ap_ST_fsm_state1 : STD_LOGIC_VECTOR (8 downto 0) := "000000001";
    constant ap_ST_fsm_state2 : STD_LOGIC_VECTOR (8 downto 0) := "000000010";
    constant ap_ST_fsm_state3 : STD_LOGIC_VECTOR (8 downto 0) := "000000100";
    constant ap_ST_fsm_state4 : STD_LOGIC_VECTOR (8 downto 0) := "000001000";
    constant ap_ST_fsm_state5 : STD_LOGIC_VECTOR (8 downto 0) := "000010000";
    constant ap_ST_fsm_state6 : STD_LOGIC_VECTOR (8 downto 0) := "000100000";
    constant ap_ST_fsm_state7 : STD_LOGIC_VECTOR (8 downto 0) := "001000000";
    constant ap_ST_fsm_state8 : STD_LOGIC_VECTOR (8 downto 0) := "010000000";
    constant ap_ST_fsm_state9 : STD_LOGIC_VECTOR (8 downto 0) := "100000000";
    constant ap_const_lv32_0 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000000";
    constant ap_const_lv32_1 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000001";
    constant ap_const_lv32_2 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000010";
    constant ap_const_lv1_0 : STD_LOGIC_VECTOR (0 downto 0) := "0";
    constant ap_const_lv32_3 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000011";
    constant ap_const_lv32_6 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000110";
    constant ap_const_lv32_7 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000111";
    constant ap_const_lv3_0 : STD_LOGIC_VECTOR (2 downto 0) := "000";
    constant ap_const_lv1_1 : STD_LOGIC_VECTOR (0 downto 0) := "1";
    constant ap_const_lv32_4 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000100";
    constant ap_const_lv32_5 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000101";
    constant ap_const_lv32_8 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000001000";
    constant ap_const_lv3_4 : STD_LOGIC_VECTOR (2 downto 0) := "100";
    constant ap_const_lv3_1 : STD_LOGIC_VECTOR (2 downto 0) := "001";
    constant ap_const_lv2_0 : STD_LOGIC_VECTOR (1 downto 0) := "00";
    constant ap_const_boolean_1 : BOOLEAN := true;

    signal ap_CS_fsm : STD_LOGIC_VECTOR (8 downto 0) := "000000001";
    attribute fsm_encoding : string;
    attribute fsm_encoding of ap_CS_fsm : signal is "none";
    signal ap_CS_fsm_state1 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state1 : signal is "none";
    signal ap_CS_fsm_state2 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state2 : signal is "none";
    signal grp_KeyExpansion_fu_143_ap_ready : STD_LOGIC;
    signal grp_KeyExpansion_fu_143_ap_done : STD_LOGIC;
    signal i_fu_169_p2 : STD_LOGIC_VECTOR (2 downto 0);
    signal i_reg_330 : STD_LOGIC_VECTOR (2 downto 0);
    signal ap_CS_fsm_state3 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state3 : signal is "none";
    signal shl_ln_fu_179_p3 : STD_LOGIC_VECTOR (3 downto 0);
    signal shl_ln_reg_335 : STD_LOGIC_VECTOR (3 downto 0);
    signal icmp_ln164_fu_163_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal zext_ln166_fu_195_p1 : STD_LOGIC_VECTOR (5 downto 0);
    signal zext_ln166_reg_340 : STD_LOGIC_VECTOR (5 downto 0);
    signal j_fu_205_p2 : STD_LOGIC_VECTOR (2 downto 0);
    signal j_reg_348 : STD_LOGIC_VECTOR (2 downto 0);
    signal ap_CS_fsm_state4 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state4 : signal is "none";
    signal icmp_ln166_fu_199_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal add_ln168_2_fu_229_p2 : STD_LOGIC_VECTOR (5 downto 0);
    signal add_ln168_2_reg_358 : STD_LOGIC_VECTOR (5 downto 0);
    signal i_11_fu_244_p2 : STD_LOGIC_VECTOR (2 downto 0);
    signal i_11_reg_366 : STD_LOGIC_VECTOR (2 downto 0);
    signal ap_CS_fsm_state7 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state7 : signal is "none";
    signal zext_ln195_fu_258_p1 : STD_LOGIC_VECTOR (5 downto 0);
    signal zext_ln195_reg_371 : STD_LOGIC_VECTOR (5 downto 0);
    signal icmp_ln191_fu_238_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal shl_ln3_fu_266_p3 : STD_LOGIC_VECTOR (3 downto 0);
    signal shl_ln3_reg_376 : STD_LOGIC_VECTOR (3 downto 0);
    signal j_9_fu_280_p2 : STD_LOGIC_VECTOR (2 downto 0);
    signal j_9_reg_384 : STD_LOGIC_VECTOR (2 downto 0);
    signal ap_CS_fsm_state8 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state8 : signal is "none";
    signal icmp_ln193_fu_274_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal add_ln195_1_fu_313_p2 : STD_LOGIC_VECTOR (5 downto 0);
    signal add_ln195_1_reg_394 : STD_LOGIC_VECTOR (5 downto 0);
    signal ctx_RoundKey_address0 : STD_LOGIC_VECTOR (7 downto 0);
    signal ctx_RoundKey_ce0 : STD_LOGIC;
    signal ctx_RoundKey_we0 : STD_LOGIC;
    signal ctx_RoundKey_q0 : STD_LOGIC_VECTOR (7 downto 0);
    signal test_address0 : STD_LOGIC_VECTOR (3 downto 0);
    signal test_ce0 : STD_LOGIC;
    signal test_we0 : STD_LOGIC;
    signal test_d0 : STD_LOGIC_VECTOR (7 downto 0);
    signal test_q0 : STD_LOGIC_VECTOR (7 downto 0);
    signal test_ce1 : STD_LOGIC;
    signal test_we1 : STD_LOGIC;
    signal test_q1 : STD_LOGIC_VECTOR (7 downto 0);
    signal grp_KeyExpansion_fu_143_ap_start : STD_LOGIC;
    signal grp_KeyExpansion_fu_143_ap_idle : STD_LOGIC;
    signal grp_KeyExpansion_fu_143_RoundKey_address0 : STD_LOGIC_VECTOR (7 downto 0);
    signal grp_KeyExpansion_fu_143_RoundKey_ce0 : STD_LOGIC;
    signal grp_KeyExpansion_fu_143_RoundKey_we0 : STD_LOGIC;
    signal grp_KeyExpansion_fu_143_RoundKey_d0 : STD_LOGIC_VECTOR (7 downto 0);
    signal grp_KeyExpansion_fu_143_Key_address0 : STD_LOGIC_VECTOR (4 downto 0);
    signal grp_KeyExpansion_fu_143_Key_ce0 : STD_LOGIC;
    signal grp_Cipher_fu_155_ap_start : STD_LOGIC;
    signal grp_Cipher_fu_155_ap_done : STD_LOGIC;
    signal grp_Cipher_fu_155_ap_idle : STD_LOGIC;
    signal grp_Cipher_fu_155_ap_ready : STD_LOGIC;
    signal grp_Cipher_fu_155_state_address0 : STD_LOGIC_VECTOR (3 downto 0);
    signal grp_Cipher_fu_155_state_ce0 : STD_LOGIC;
    signal grp_Cipher_fu_155_state_we0 : STD_LOGIC;
    signal grp_Cipher_fu_155_state_d0 : STD_LOGIC_VECTOR (7 downto 0);
    signal grp_Cipher_fu_155_state_address1 : STD_LOGIC_VECTOR (3 downto 0);
    signal grp_Cipher_fu_155_state_ce1 : STD_LOGIC;
    signal grp_Cipher_fu_155_state_we1 : STD_LOGIC;
    signal grp_Cipher_fu_155_state_d1 : STD_LOGIC_VECTOR (7 downto 0);
    signal grp_Cipher_fu_155_RoundKey_address0 : STD_LOGIC_VECTOR (7 downto 0);
    signal grp_Cipher_fu_155_RoundKey_ce0 : STD_LOGIC;
    signal i_0_reg_99 : STD_LOGIC_VECTOR (2 downto 0);
    signal j_0_reg_110 : STD_LOGIC_VECTOR (2 downto 0);
    signal ap_CS_fsm_state5 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state5 : signal is "none";
    signal i_1_reg_121 : STD_LOGIC_VECTOR (2 downto 0);
    signal ap_CS_fsm_state6 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state6 : signal is "none";
    signal j_1_reg_132 : STD_LOGIC_VECTOR (2 downto 0);
    signal ap_CS_fsm_state9 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state9 : signal is "none";
    signal grp_KeyExpansion_fu_143_ap_start_reg : STD_LOGIC := '0';
    signal grp_Cipher_fu_155_ap_start_reg : STD_LOGIC := '0';
    signal zext_ln168_4_fu_220_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal zext_ln168_6_fu_234_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal zext_ln195_8_fu_295_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal zext_ln195_6_fu_318_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal trunc_ln168_fu_175_p1 : STD_LOGIC_VECTOR (1 downto 0);
    signal tmp_s_fu_187_p3 : STD_LOGIC_VECTOR (4 downto 0);
    signal zext_ln168_fu_211_p1 : STD_LOGIC_VECTOR (3 downto 0);
    signal add_ln168_fu_215_p2 : STD_LOGIC_VECTOR (3 downto 0);
    signal zext_ln168_5_fu_225_p1 : STD_LOGIC_VECTOR (5 downto 0);
    signal tmp_4_fu_250_p3 : STD_LOGIC_VECTOR (4 downto 0);
    signal trunc_ln195_fu_262_p1 : STD_LOGIC_VECTOR (1 downto 0);
    signal zext_ln195_7_fu_286_p1 : STD_LOGIC_VECTOR (5 downto 0);
    signal add_ln195_2_fu_290_p2 : STD_LOGIC_VECTOR (5 downto 0);
    signal zext_ln195_4_fu_300_p1 : STD_LOGIC_VECTOR (3 downto 0);
    signal add_ln195_fu_304_p2 : STD_LOGIC_VECTOR (3 downto 0);
    signal zext_ln195_5_fu_309_p1 : STD_LOGIC_VECTOR (5 downto 0);
    signal ap_NS_fsm : STD_LOGIC_VECTOR (8 downto 0);

    component KeyExpansion IS
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
        Key_address0 : OUT STD_LOGIC_VECTOR (4 downto 0);
        Key_ce0 : OUT STD_LOGIC;
        Key_q0 : IN STD_LOGIC_VECTOR (7 downto 0) );
    end component;


    component Cipher IS
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
        state_q0 : IN STD_LOGIC_VECTOR (7 downto 0);
        state_address1 : OUT STD_LOGIC_VECTOR (3 downto 0);
        state_ce1 : OUT STD_LOGIC;
        state_we1 : OUT STD_LOGIC;
        state_d1 : OUT STD_LOGIC_VECTOR (7 downto 0);
        state_q1 : IN STD_LOGIC_VECTOR (7 downto 0);
        RoundKey_address0 : OUT STD_LOGIC_VECTOR (7 downto 0);
        RoundKey_ce0 : OUT STD_LOGIC;
        RoundKey_q0 : IN STD_LOGIC_VECTOR (7 downto 0) );
    end component;


    component AES256_ECB_ctx_RodEe IS
    generic (
        DataWidth : INTEGER;
        AddressRange : INTEGER;
        AddressWidth : INTEGER );
    port (
        clk : IN STD_LOGIC;
        reset : IN STD_LOGIC;
        address0 : IN STD_LOGIC_VECTOR (7 downto 0);
        ce0 : IN STD_LOGIC;
        we0 : IN STD_LOGIC;
        d0 : IN STD_LOGIC_VECTOR (7 downto 0);
        q0 : OUT STD_LOGIC_VECTOR (7 downto 0) );
    end component;


    component AES256_ECB_1_test IS
    generic (
        DataWidth : INTEGER;
        AddressRange : INTEGER;
        AddressWidth : INTEGER );
    port (
        clk : IN STD_LOGIC;
        reset : IN STD_LOGIC;
        address0 : IN STD_LOGIC_VECTOR (3 downto 0);
        ce0 : IN STD_LOGIC;
        we0 : IN STD_LOGIC;
        d0 : IN STD_LOGIC_VECTOR (7 downto 0);
        q0 : OUT STD_LOGIC_VECTOR (7 downto 0);
        address1 : IN STD_LOGIC_VECTOR (3 downto 0);
        ce1 : IN STD_LOGIC;
        we1 : IN STD_LOGIC;
        d1 : IN STD_LOGIC_VECTOR (7 downto 0);
        q1 : OUT STD_LOGIC_VECTOR (7 downto 0) );
    end component;



begin
    ctx_RoundKey_U : component AES256_ECB_ctx_RodEe
    generic map (
        DataWidth => 8,
        AddressRange => 240,
        AddressWidth => 8)
    port map (
        clk => ap_clk,
        reset => ap_rst,
        address0 => ctx_RoundKey_address0,
        ce0 => ctx_RoundKey_ce0,
        we0 => ctx_RoundKey_we0,
        d0 => grp_KeyExpansion_fu_143_RoundKey_d0,
        q0 => ctx_RoundKey_q0);

    test_U : component AES256_ECB_1_test
    generic map (
        DataWidth => 8,
        AddressRange => 16,
        AddressWidth => 4)
    port map (
        clk => ap_clk,
        reset => ap_rst,
        address0 => test_address0,
        ce0 => test_ce0,
        we0 => test_we0,
        d0 => test_d0,
        q0 => test_q0,
        address1 => grp_Cipher_fu_155_state_address1,
        ce1 => test_ce1,
        we1 => test_we1,
        d1 => grp_Cipher_fu_155_state_d1,
        q1 => test_q1);

    grp_KeyExpansion_fu_143 : component KeyExpansion
    port map (
        ap_clk => ap_clk,
        ap_rst => ap_rst,
        ap_start => grp_KeyExpansion_fu_143_ap_start,
        ap_done => grp_KeyExpansion_fu_143_ap_done,
        ap_idle => grp_KeyExpansion_fu_143_ap_idle,
        ap_ready => grp_KeyExpansion_fu_143_ap_ready,
        RoundKey_address0 => grp_KeyExpansion_fu_143_RoundKey_address0,
        RoundKey_ce0 => grp_KeyExpansion_fu_143_RoundKey_ce0,
        RoundKey_we0 => grp_KeyExpansion_fu_143_RoundKey_we0,
        RoundKey_d0 => grp_KeyExpansion_fu_143_RoundKey_d0,
        RoundKey_q0 => ctx_RoundKey_q0,
        Key_address0 => grp_KeyExpansion_fu_143_Key_address0,
        Key_ce0 => grp_KeyExpansion_fu_143_Key_ce0,
        Key_q0 => key_q0);

    grp_Cipher_fu_155 : component Cipher
    port map (
        ap_clk => ap_clk,
        ap_rst => ap_rst,
        ap_start => grp_Cipher_fu_155_ap_start,
        ap_done => grp_Cipher_fu_155_ap_done,
        ap_idle => grp_Cipher_fu_155_ap_idle,
        ap_ready => grp_Cipher_fu_155_ap_ready,
        state_address0 => grp_Cipher_fu_155_state_address0,
        state_ce0 => grp_Cipher_fu_155_state_ce0,
        state_we0 => grp_Cipher_fu_155_state_we0,
        state_d0 => grp_Cipher_fu_155_state_d0,
        state_q0 => test_q0,
        state_address1 => grp_Cipher_fu_155_state_address1,
        state_ce1 => grp_Cipher_fu_155_state_ce1,
        state_we1 => grp_Cipher_fu_155_state_we1,
        state_d1 => grp_Cipher_fu_155_state_d1,
        state_q1 => test_q1,
        RoundKey_address0 => grp_Cipher_fu_155_RoundKey_address0,
        RoundKey_ce0 => grp_Cipher_fu_155_RoundKey_ce0,
        RoundKey_q0 => ctx_RoundKey_q0);





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


    grp_Cipher_fu_155_ap_start_reg_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                grp_Cipher_fu_155_ap_start_reg <= ap_const_logic_0;
            else
                if (((icmp_ln164_fu_163_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state3))) then 
                    grp_Cipher_fu_155_ap_start_reg <= ap_const_logic_1;
                elsif ((grp_Cipher_fu_155_ap_ready = ap_const_logic_1)) then 
                    grp_Cipher_fu_155_ap_start_reg <= ap_const_logic_0;
                end if; 
            end if;
        end if;
    end process;


    grp_KeyExpansion_fu_143_ap_start_reg_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                grp_KeyExpansion_fu_143_ap_start_reg <= ap_const_logic_0;
            else
                if (((ap_const_logic_1 = ap_CS_fsm_state1) and (ap_start = ap_const_logic_1))) then 
                    grp_KeyExpansion_fu_143_ap_start_reg <= ap_const_logic_1;
                elsif ((grp_KeyExpansion_fu_143_ap_ready = ap_const_logic_1)) then 
                    grp_KeyExpansion_fu_143_ap_start_reg <= ap_const_logic_0;
                end if; 
            end if;
        end if;
    end process;


    i_0_reg_99_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((icmp_ln166_fu_199_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state4))) then 
                i_0_reg_99 <= i_reg_330;
            elsif (((grp_KeyExpansion_fu_143_ap_done = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_state2))) then 
                i_0_reg_99 <= ap_const_lv3_0;
            end if; 
        end if;
    end process;

    i_1_reg_121_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((ap_const_logic_1 = ap_CS_fsm_state8) and (icmp_ln193_fu_274_p2 = ap_const_lv1_1))) then 
                i_1_reg_121 <= i_11_reg_366;
            elsif (((ap_const_logic_1 = ap_CS_fsm_state6) and (grp_Cipher_fu_155_ap_done = ap_const_logic_1))) then 
                i_1_reg_121 <= ap_const_lv3_0;
            end if; 
        end if;
    end process;

    j_0_reg_110_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((icmp_ln164_fu_163_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state3))) then 
                j_0_reg_110 <= ap_const_lv3_0;
            elsif ((ap_const_logic_1 = ap_CS_fsm_state5)) then 
                j_0_reg_110 <= j_reg_348;
            end if; 
        end if;
    end process;

    j_1_reg_132_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((icmp_ln191_fu_238_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state7))) then 
                j_1_reg_132 <= ap_const_lv3_0;
            elsif ((ap_const_logic_1 = ap_CS_fsm_state9)) then 
                j_1_reg_132 <= j_9_reg_384;
            end if; 
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((icmp_ln166_fu_199_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state4))) then
                add_ln168_2_reg_358 <= add_ln168_2_fu_229_p2;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((icmp_ln193_fu_274_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state8))) then
                add_ln195_1_reg_394 <= add_ln195_1_fu_313_p2;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state7)) then
                i_11_reg_366 <= i_11_fu_244_p2;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state3)) then
                i_reg_330 <= i_fu_169_p2;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state8)) then
                j_9_reg_384 <= j_9_fu_280_p2;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state4)) then
                j_reg_348 <= j_fu_205_p2;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((icmp_ln191_fu_238_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state7))) then
                    shl_ln3_reg_376(3 downto 2) <= shl_ln3_fu_266_p3(3 downto 2);
                    zext_ln195_reg_371(4 downto 2) <= zext_ln195_fu_258_p1(4 downto 2);
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((icmp_ln164_fu_163_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state3))) then
                    shl_ln_reg_335(3 downto 2) <= shl_ln_fu_179_p3(3 downto 2);
                    zext_ln166_reg_340(4 downto 2) <= zext_ln166_fu_195_p1(4 downto 2);
            end if;
        end if;
    end process;
    shl_ln_reg_335(1 downto 0) <= "00";
    zext_ln166_reg_340(1 downto 0) <= "00";
    zext_ln166_reg_340(5) <= '0';
    zext_ln195_reg_371(1 downto 0) <= "00";
    zext_ln195_reg_371(5) <= '0';
    shl_ln3_reg_376(1 downto 0) <= "00";

    ap_NS_fsm_assign_proc : process (ap_start, ap_CS_fsm, ap_CS_fsm_state1, ap_CS_fsm_state2, grp_KeyExpansion_fu_143_ap_done, ap_CS_fsm_state3, icmp_ln164_fu_163_p2, ap_CS_fsm_state4, icmp_ln166_fu_199_p2, ap_CS_fsm_state7, icmp_ln191_fu_238_p2, ap_CS_fsm_state8, icmp_ln193_fu_274_p2, grp_Cipher_fu_155_ap_done, ap_CS_fsm_state6)
    begin
        case ap_CS_fsm is
            when ap_ST_fsm_state1 => 
                if (((ap_const_logic_1 = ap_CS_fsm_state1) and (ap_start = ap_const_logic_1))) then
                    ap_NS_fsm <= ap_ST_fsm_state2;
                else
                    ap_NS_fsm <= ap_ST_fsm_state1;
                end if;
            when ap_ST_fsm_state2 => 
                if (((grp_KeyExpansion_fu_143_ap_done = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_state2))) then
                    ap_NS_fsm <= ap_ST_fsm_state3;
                else
                    ap_NS_fsm <= ap_ST_fsm_state2;
                end if;
            when ap_ST_fsm_state3 => 
                if (((icmp_ln164_fu_163_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state3))) then
                    ap_NS_fsm <= ap_ST_fsm_state4;
                else
                    ap_NS_fsm <= ap_ST_fsm_state6;
                end if;
            when ap_ST_fsm_state4 => 
                if (((icmp_ln166_fu_199_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state4))) then
                    ap_NS_fsm <= ap_ST_fsm_state3;
                else
                    ap_NS_fsm <= ap_ST_fsm_state5;
                end if;
            when ap_ST_fsm_state5 => 
                ap_NS_fsm <= ap_ST_fsm_state4;
            when ap_ST_fsm_state6 => 
                if (((ap_const_logic_1 = ap_CS_fsm_state6) and (grp_Cipher_fu_155_ap_done = ap_const_logic_1))) then
                    ap_NS_fsm <= ap_ST_fsm_state7;
                else
                    ap_NS_fsm <= ap_ST_fsm_state6;
                end if;
            when ap_ST_fsm_state7 => 
                if (((icmp_ln191_fu_238_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state7))) then
                    ap_NS_fsm <= ap_ST_fsm_state1;
                else
                    ap_NS_fsm <= ap_ST_fsm_state8;
                end if;
            when ap_ST_fsm_state8 => 
                if (((ap_const_logic_1 = ap_CS_fsm_state8) and (icmp_ln193_fu_274_p2 = ap_const_lv1_1))) then
                    ap_NS_fsm <= ap_ST_fsm_state7;
                else
                    ap_NS_fsm <= ap_ST_fsm_state9;
                end if;
            when ap_ST_fsm_state9 => 
                ap_NS_fsm <= ap_ST_fsm_state8;
            when others =>  
                ap_NS_fsm <= "XXXXXXXXX";
        end case;
    end process;
    add_ln168_2_fu_229_p2 <= std_logic_vector(unsigned(zext_ln166_reg_340) + unsigned(zext_ln168_5_fu_225_p1));
    add_ln168_fu_215_p2 <= std_logic_vector(unsigned(zext_ln168_fu_211_p1) + unsigned(shl_ln_reg_335));
    add_ln195_1_fu_313_p2 <= std_logic_vector(unsigned(buffer_offset) + unsigned(zext_ln195_5_fu_309_p1));
    add_ln195_2_fu_290_p2 <= std_logic_vector(unsigned(zext_ln195_reg_371) + unsigned(zext_ln195_7_fu_286_p1));
    add_ln195_fu_304_p2 <= std_logic_vector(unsigned(zext_ln195_4_fu_300_p1) + unsigned(shl_ln3_reg_376));
    ap_CS_fsm_state1 <= ap_CS_fsm(0);
    ap_CS_fsm_state2 <= ap_CS_fsm(1);
    ap_CS_fsm_state3 <= ap_CS_fsm(2);
    ap_CS_fsm_state4 <= ap_CS_fsm(3);
    ap_CS_fsm_state5 <= ap_CS_fsm(4);
    ap_CS_fsm_state6 <= ap_CS_fsm(5);
    ap_CS_fsm_state7 <= ap_CS_fsm(6);
    ap_CS_fsm_state8 <= ap_CS_fsm(7);
    ap_CS_fsm_state9 <= ap_CS_fsm(8);

    ap_done_assign_proc : process(ap_start, ap_CS_fsm_state1, ap_CS_fsm_state7, icmp_ln191_fu_238_p2)
    begin
        if ((((icmp_ln191_fu_238_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state7)) or ((ap_start = ap_const_logic_0) and (ap_const_logic_1 = ap_CS_fsm_state1)))) then 
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


    ap_ready_assign_proc : process(ap_CS_fsm_state7, icmp_ln191_fu_238_p2)
    begin
        if (((icmp_ln191_fu_238_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state7))) then 
            ap_ready <= ap_const_logic_1;
        else 
            ap_ready <= ap_const_logic_0;
        end if; 
    end process;

    buffer_r_address0 <= zext_ln195_6_fu_318_p1(6 - 1 downto 0);

    buffer_r_ce0_assign_proc : process(ap_CS_fsm_state9)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state9)) then 
            buffer_r_ce0 <= ap_const_logic_1;
        else 
            buffer_r_ce0 <= ap_const_logic_0;
        end if; 
    end process;

    buffer_r_d0 <= test_q0;

    buffer_r_we0_assign_proc : process(ap_CS_fsm_state9)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state9)) then 
            buffer_r_we0 <= ap_const_logic_1;
        else 
            buffer_r_we0 <= ap_const_logic_0;
        end if; 
    end process;

    ctr_address0 <= zext_ln168_4_fu_220_p1(4 - 1 downto 0);

    ctr_ce0_assign_proc : process(ap_CS_fsm_state4)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state4)) then 
            ctr_ce0 <= ap_const_logic_1;
        else 
            ctr_ce0 <= ap_const_logic_0;
        end if; 
    end process;


    ctx_RoundKey_address0_assign_proc : process(ap_CS_fsm_state2, grp_KeyExpansion_fu_143_RoundKey_address0, grp_Cipher_fu_155_RoundKey_address0, ap_CS_fsm_state6)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state6)) then 
            ctx_RoundKey_address0 <= grp_Cipher_fu_155_RoundKey_address0;
        elsif ((ap_const_logic_1 = ap_CS_fsm_state2)) then 
            ctx_RoundKey_address0 <= grp_KeyExpansion_fu_143_RoundKey_address0;
        else 
            ctx_RoundKey_address0 <= "XXXXXXXX";
        end if; 
    end process;


    ctx_RoundKey_ce0_assign_proc : process(ap_CS_fsm_state2, grp_KeyExpansion_fu_143_RoundKey_ce0, grp_Cipher_fu_155_RoundKey_ce0, ap_CS_fsm_state6)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state6)) then 
            ctx_RoundKey_ce0 <= grp_Cipher_fu_155_RoundKey_ce0;
        elsif ((ap_const_logic_1 = ap_CS_fsm_state2)) then 
            ctx_RoundKey_ce0 <= grp_KeyExpansion_fu_143_RoundKey_ce0;
        else 
            ctx_RoundKey_ce0 <= ap_const_logic_0;
        end if; 
    end process;


    ctx_RoundKey_we0_assign_proc : process(ap_CS_fsm_state2, grp_KeyExpansion_fu_143_RoundKey_we0)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state2)) then 
            ctx_RoundKey_we0 <= grp_KeyExpansion_fu_143_RoundKey_we0;
        else 
            ctx_RoundKey_we0 <= ap_const_logic_0;
        end if; 
    end process;

    grp_Cipher_fu_155_ap_start <= grp_Cipher_fu_155_ap_start_reg;
    grp_KeyExpansion_fu_143_ap_start <= grp_KeyExpansion_fu_143_ap_start_reg;
    i_11_fu_244_p2 <= std_logic_vector(unsigned(i_1_reg_121) + unsigned(ap_const_lv3_1));
    i_fu_169_p2 <= std_logic_vector(unsigned(i_0_reg_99) + unsigned(ap_const_lv3_1));
    icmp_ln164_fu_163_p2 <= "1" when (i_0_reg_99 = ap_const_lv3_4) else "0";
    icmp_ln166_fu_199_p2 <= "1" when (j_0_reg_110 = ap_const_lv3_4) else "0";
    icmp_ln191_fu_238_p2 <= "1" when (i_1_reg_121 = ap_const_lv3_4) else "0";
    icmp_ln193_fu_274_p2 <= "1" when (j_1_reg_132 = ap_const_lv3_4) else "0";
    j_9_fu_280_p2 <= std_logic_vector(unsigned(j_1_reg_132) + unsigned(ap_const_lv3_1));
    j_fu_205_p2 <= std_logic_vector(unsigned(j_0_reg_110) + unsigned(ap_const_lv3_1));
    key_address0 <= grp_KeyExpansion_fu_143_Key_address0;
    key_ce0 <= grp_KeyExpansion_fu_143_Key_ce0;
    shl_ln3_fu_266_p3 <= (trunc_ln195_fu_262_p1 & ap_const_lv2_0);
    shl_ln_fu_179_p3 <= (trunc_ln168_fu_175_p1 & ap_const_lv2_0);

    test_address0_assign_proc : process(ap_CS_fsm_state8, grp_Cipher_fu_155_state_address0, ap_CS_fsm_state5, ap_CS_fsm_state6, zext_ln168_6_fu_234_p1, zext_ln195_8_fu_295_p1)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state8)) then 
            test_address0 <= zext_ln195_8_fu_295_p1(4 - 1 downto 0);
        elsif ((ap_const_logic_1 = ap_CS_fsm_state5)) then 
            test_address0 <= zext_ln168_6_fu_234_p1(4 - 1 downto 0);
        elsif ((ap_const_logic_1 = ap_CS_fsm_state6)) then 
            test_address0 <= grp_Cipher_fu_155_state_address0;
        else 
            test_address0 <= "XXXX";
        end if; 
    end process;


    test_ce0_assign_proc : process(ap_CS_fsm_state8, grp_Cipher_fu_155_state_ce0, ap_CS_fsm_state5, ap_CS_fsm_state6)
    begin
        if (((ap_const_logic_1 = ap_CS_fsm_state5) or (ap_const_logic_1 = ap_CS_fsm_state8))) then 
            test_ce0 <= ap_const_logic_1;
        elsif ((ap_const_logic_1 = ap_CS_fsm_state6)) then 
            test_ce0 <= grp_Cipher_fu_155_state_ce0;
        else 
            test_ce0 <= ap_const_logic_0;
        end if; 
    end process;


    test_ce1_assign_proc : process(grp_Cipher_fu_155_state_ce1, ap_CS_fsm_state6)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state6)) then 
            test_ce1 <= grp_Cipher_fu_155_state_ce1;
        else 
            test_ce1 <= ap_const_logic_0;
        end if; 
    end process;


    test_d0_assign_proc : process(ctr_q0, grp_Cipher_fu_155_state_d0, ap_CS_fsm_state5, ap_CS_fsm_state6)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state5)) then 
            test_d0 <= ctr_q0;
        elsif ((ap_const_logic_1 = ap_CS_fsm_state6)) then 
            test_d0 <= grp_Cipher_fu_155_state_d0;
        else 
            test_d0 <= "XXXXXXXX";
        end if; 
    end process;


    test_we0_assign_proc : process(grp_Cipher_fu_155_state_we0, ap_CS_fsm_state5, ap_CS_fsm_state6)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state5)) then 
            test_we0 <= ap_const_logic_1;
        elsif ((ap_const_logic_1 = ap_CS_fsm_state6)) then 
            test_we0 <= grp_Cipher_fu_155_state_we0;
        else 
            test_we0 <= ap_const_logic_0;
        end if; 
    end process;


    test_we1_assign_proc : process(grp_Cipher_fu_155_state_we1, ap_CS_fsm_state6)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state6)) then 
            test_we1 <= grp_Cipher_fu_155_state_we1;
        else 
            test_we1 <= ap_const_logic_0;
        end if; 
    end process;

    tmp_4_fu_250_p3 <= (i_1_reg_121 & ap_const_lv2_0);
    tmp_s_fu_187_p3 <= (i_0_reg_99 & ap_const_lv2_0);
    trunc_ln168_fu_175_p1 <= i_0_reg_99(2 - 1 downto 0);
    trunc_ln195_fu_262_p1 <= i_1_reg_121(2 - 1 downto 0);
    zext_ln166_fu_195_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(tmp_s_fu_187_p3),6));
    zext_ln168_4_fu_220_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(add_ln168_fu_215_p2),64));
    zext_ln168_5_fu_225_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(j_0_reg_110),6));
    zext_ln168_6_fu_234_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(add_ln168_2_reg_358),64));
    zext_ln168_fu_211_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(j_0_reg_110),4));
    zext_ln195_4_fu_300_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(j_1_reg_132),4));
    zext_ln195_5_fu_309_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(add_ln195_fu_304_p2),6));
    zext_ln195_6_fu_318_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(add_ln195_1_reg_394),64));
    zext_ln195_7_fu_286_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(j_1_reg_132),6));
    zext_ln195_8_fu_295_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(add_ln195_2_fu_290_p2),64));
    zext_ln195_fu_258_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(tmp_4_fu_250_p3),6));
end behav;
