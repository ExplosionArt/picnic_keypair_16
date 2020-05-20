############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project picnic1
set_top crypto_sign_keypair
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
add_files -tb newtest_sign_2.c -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
open_solution "keypair"
set_part {xc7a200t-fbg676-2}
create_clock -period 10 -name default
config_compile -no_signed_zeros=0 -unsafe_math_optimizations=0
config_sdx -target none
config_export -vivado_optimization_level 2 -vivado_phys_opt place -vivado_report_level 0
config_interface -clock_enable=0 -expose_global -m_axi_addr64=0 -m_axi_offset off -register_io off -trim_dangling_port=0
set_clock_uncertainty 12.5%
#source "./picnic1/keypair/directives.tcl"
csim_design -clean
csynth_design
cosim_design -O
export_design -format ip_catalog
