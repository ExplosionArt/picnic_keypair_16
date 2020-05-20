# ==============================================================
# File generated on Tue May 05 12:55:35 EDT 2020
# Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
# SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
# IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
# Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
# ==============================================================
add_files -tb ../../newtest_sign_2.c -cflags { -Wno-unknown-pragmas}
add_files tree.c
add_files NIST-KATs/rng.c
add_files picnic_types.c
add_files picnic_impl.c
add_files picnic2_impl.c
add_files picnic.c
add_files lowmc_constants.c
add_files hash.c
add_files api.c
add_files NIST-KATs/aes.c
add_files sha3/KeccakSpongeWidth1600.c
add_files sha3/KeccakP-1600-reference.c
add_files sha3/KeccakHash.c
set_part xc7a200tfbg676-2
create_clock -name default -period 10
config_interface -clock_enable=0
config_interface -expose_global=1
config_interface -m_axi_addr64=0
config_interface -m_axi_offset=off
config_interface -register_io=off
config_interface -trim_dangling_port=0
