# This script segment is generated automatically by AutoPilot

# Memory (RAM/ROM)  definition:
set ID 45
set hasByteEnable 0
set MemName picnic_keygen_temp
set CoreName ap_simcore_mem
set PortList { 2 3 }
set DataWd 32
set AddrRange 8
set AddrWd 3
set impl_style block
set TrueReset 0
set HasInitializer 0
set IsROM 0
set ROMData {}
set NumOfStage 2
set MaxLatency -1
set DelayBudget 1.755
set ClkPeriod 10
set RegisteredInput 0
if {${::AESL::PGuard_simmodel_gen}} {
if {[info proc ap_gen_simcore_mem] == "ap_gen_simcore_mem"} {
    eval "ap_gen_simcore_mem { \
    id ${ID} \
    name ${MemName} \
    corename ${CoreName}  \
    op mem \
    hasByteEnable ${hasByteEnable} \
    reset_level 1 \
    sync_rst true \
    stage_num ${NumOfStage}  \
    registered_input ${RegisteredInput} \
    port_num 2 \
    port_list \{${PortList}\} \
    data_wd ${DataWd} \
    addr_wd ${AddrWd} \
    addr_range ${AddrRange} \
    style ${impl_style} \
    true_reset ${TrueReset} \
    delay_budget ${DelayBudget} \
    clk_period ${ClkPeriod} \
    HasInitializer ${HasInitializer} \
    rom_data \{${ROMData}\} \
 } "
} else {
    puts "@W \[IMPL-102\] Cannot find ap_gen_simcore_mem, check your platform lib"
}
}


if {${::AESL::PGuard_rtl_comp_handler}} {
  ::AP::rtl_comp_handler $MemName
}


set CoreName RAM
if {${::AESL::PGuard_autocg_gen} && ${::AESL::PGuard_autocg_ipmgen}} {
if {[info proc ::AESL_LIB_VIRTEX::xil_gen_RAM] == "::AESL_LIB_VIRTEX::xil_gen_RAM"} {
    eval "::AESL_LIB_VIRTEX::xil_gen_RAM { \
    id ${ID} \
    name ${MemName} \
    corename ${CoreName}  \
    op mem \
    hasByteEnable ${hasByteEnable} \
    reset_level 1 \
    sync_rst true \
    stage_num ${NumOfStage}  \
    registered_input ${RegisteredInput} \
    port_num 2 \
    port_list \{${PortList}\} \
    data_wd ${DataWd} \
    addr_wd ${AddrWd} \
    addr_range ${AddrRange} \
    style ${impl_style} \
    true_reset ${TrueReset} \
    delay_budget ${DelayBudget} \
    clk_period ${ClkPeriod} \
    HasInitializer ${HasInitializer} \
    rom_data \{${ROMData}\} \
 } "
  } else {
    puts "@W \[IMPL-104\] Cannot find ::AESL_LIB_VIRTEX::xil_gen_RAM, check your platform lib"
  }
}


# clear list
if {${::AESL::PGuard_autoexp_gen}} {
    cg_default_interface_gen_dc_begin
    cg_default_interface_gen_bundle_begin
    AESL_LIB_XILADAPTER::native_axis_begin
}

# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 47 \
    name pk_plaintext \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename pk_plaintext \
    op interface \
    ports { pk_plaintext_address0 { O 5 vector } pk_plaintext_ce0 { O 1 bit } pk_plaintext_we0 { O 1 bit } pk_plaintext_d0 { O 8 vector } pk_plaintext_q0 { I 8 vector } pk_plaintext_address1 { O 5 vector } pk_plaintext_ce1 { O 1 bit } pk_plaintext_q1 { I 8 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'pk_plaintext'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 48 \
    name pk_ciphertext \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename pk_ciphertext \
    op interface \
    ports { pk_ciphertext_address0 { O 5 vector } pk_ciphertext_ce0 { O 1 bit } pk_ciphertext_we0 { O 1 bit } pk_ciphertext_d0 { O 8 vector } pk_ciphertext_q0 { I 8 vector } pk_ciphertext_address1 { O 5 vector } pk_ciphertext_ce1 { O 1 bit } pk_ciphertext_q1 { I 8 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'pk_ciphertext'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 49 \
    name sk_data \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename sk_data \
    op interface \
    ports { sk_data_address0 { O 5 vector } sk_data_ce0 { O 1 bit } sk_data_we0 { O 1 bit } sk_data_d0 { O 8 vector } sk_data_q0 { I 8 vector } sk_data_address1 { O 5 vector } sk_data_ce1 { O 1 bit } sk_data_q1 { I 8 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'sk_data'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 50 \
    name sk_pk_plaintext \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename sk_pk_plaintext \
    op interface \
    ports { sk_pk_plaintext_address0 { O 5 vector } sk_pk_plaintext_ce0 { O 1 bit } sk_pk_plaintext_we0 { O 1 bit } sk_pk_plaintext_d0 { O 8 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'sk_pk_plaintext'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 51 \
    name sk_pk_ciphertext \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename sk_pk_ciphertext \
    op interface \
    ports { sk_pk_ciphertext_address0 { O 5 vector } sk_pk_ciphertext_ce0 { O 1 bit } sk_pk_ciphertext_we0 { O 1 bit } sk_pk_ciphertext_d0 { O 8 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'sk_pk_ciphertext'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 52 \
    name DRBG_ctx_V \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename DRBG_ctx_V \
    op interface \
    ports { DRBG_ctx_V_address0 { O 4 vector } DRBG_ctx_V_ce0 { O 1 bit } DRBG_ctx_V_we0 { O 1 bit } DRBG_ctx_V_d0 { O 8 vector } DRBG_ctx_V_q0 { I 8 vector } DRBG_ctx_V_address1 { O 4 vector } DRBG_ctx_V_ce1 { O 1 bit } DRBG_ctx_V_q1 { I 8 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'DRBG_ctx_V'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 53 \
    name DRBG_ctx_Key \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename DRBG_ctx_Key \
    op interface \
    ports { DRBG_ctx_Key_address0 { O 5 vector } DRBG_ctx_Key_ce0 { O 1 bit } DRBG_ctx_Key_we0 { O 1 bit } DRBG_ctx_Key_d0 { O 8 vector } DRBG_ctx_Key_q0 { I 8 vector } DRBG_ctx_Key_address1 { O 5 vector } DRBG_ctx_Key_ce1 { O 1 bit } DRBG_ctx_Key_q1 { I 8 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'DRBG_ctx_Key'"
}
}


# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 46 \
    name parameters \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_parameters \
    op interface \
    ports { parameters { I 4 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 54 \
    name DRBG_ctx_reseed_counter \
    type other \
    dir IO \
    reset_level 1 \
    sync_rst true \
    corename dc_DRBG_ctx_reseed_counter \
    op interface \
    ports { DRBG_ctx_reseed_counter_i { I 32 vector } DRBG_ctx_reseed_counter_o { O 32 vector } DRBG_ctx_reseed_counter_o_ap_vld { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id -1 \
    name ap_ctrl \
    type ap_ctrl \
    reset_level 1 \
    sync_rst true \
    corename ap_ctrl \
    op interface \
    ports { ap_start { I 1 bit } ap_ready { O 1 bit } ap_done { O 1 bit } ap_idle { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id -2 \
    name ap_return \
    type ap_return \
    reset_level 1 \
    sync_rst true \
    corename ap_return \
    op interface \
    ports { ap_return { O 1 vector } } \
} "
}


# Adapter definition:
set PortName ap_clk
set DataWd 1 
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc cg_default_interface_gen_clock] == "cg_default_interface_gen_clock"} {
eval "cg_default_interface_gen_clock { \
    id -3 \
    name ${PortName} \
    reset_level 1 \
    sync_rst true \
    corename apif_ap_clk \
    data_wd ${DataWd} \
    op interface \
}"
} else {
puts "@W \[IMPL-113\] Cannot find bus interface model in the library. Ignored generation of bus interface for '${PortName}'"
}
}


# Adapter definition:
set PortName ap_rst
set DataWd 1 
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc cg_default_interface_gen_reset] == "cg_default_interface_gen_reset"} {
eval "cg_default_interface_gen_reset { \
    id -4 \
    name ${PortName} \
    reset_level 1 \
    sync_rst true \
    corename apif_ap_rst \
    data_wd ${DataWd} \
    op interface \
}"
} else {
puts "@W \[IMPL-114\] Cannot find bus interface model in the library. Ignored generation of bus interface for '${PortName}'"
}
}



# merge
if {${::AESL::PGuard_autoexp_gen}} {
    cg_default_interface_gen_dc_end
    cg_default_interface_gen_bundle_end
    AESL_LIB_XILADAPTER::native_axis_end
}


