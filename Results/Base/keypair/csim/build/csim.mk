# ==============================================================
# Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.2 (64-bit)
# Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
# ==============================================================
CSIM_DESIGN = 1

__SIM_FPO__ = 1

__HLS_FPO_v6_1__ = 1

__SIM_MATHHLS__ = 1

__SIM_OPENCV__ = 1

__SIM_FFT__ = 1

__SIM_FIR__ = 1

__SIM_DDS__ = 1

ObjDir = obj

HLS_SOURCES = ../../../../newtest_sign_2.c ../../../../sha3/KeccakHash.c ../../../../sha3/KeccakP-1600-reference.c ../../../../sha3/KeccakSpongeWidth1600.c ../../../../NIST-KATs/aes.c ../../../../api.c ../../../../hash.c ../../../../lowmc_constants.c ../../../../picnic.c ../../../../picnic2_impl.c ../../../../picnic_impl.c ../../../../picnic_types.c ../../../../NIST-KATs/rng.c ../../../../tree.c

TARGET := csim.exe

AUTOPILOT_ROOT := D:/Xilinx_Vivado/Vivado/2019.2
AUTOPILOT_MACH := win64
ifdef AP_GCC_M32
  AUTOPILOT_MACH := Linux_x86
  IFLAG += -m32
endif
ifndef AP_GCC_PATH
  AP_GCC_PATH := D:/Xilinx_Vivado/Vivado/2019.2/tps/win64/msys64/mingw64/bin
endif
AUTOPILOT_TOOL := ${AUTOPILOT_ROOT}/${AUTOPILOT_MACH}/tools
AP_CLANG_PATH := ${AUTOPILOT_ROOT}/tps/win64/msys64/mingw64/bin
AUTOPILOT_TECH := ${AUTOPILOT_ROOT}/common/technology


IFLAG += -I "${AUTOPILOT_TOOL}/systemc/include"
IFLAG += -I "${AUTOPILOT_ROOT}/include"
IFLAG += -I "${AUTOPILOT_ROOT}/include/opencv"
IFLAG += -I "${AUTOPILOT_ROOT}/include/ap_sysc"
IFLAG += -I "${AUTOPILOT_TECH}/generic/SystemC"
IFLAG += -I "${AUTOPILOT_TECH}/generic/SystemC/AESL_FP_comp"
IFLAG += -I "${AUTOPILOT_TECH}/generic/SystemC/AESL_comp"
IFLAG += -I "${AUTOPILOT_TOOL}/auto_cc/include"
IFLAG += -D__SIM_FPO__

IFLAG += -D__HLS_FPO_v6_1__

IFLAG += -D__SIM_OPENCV__

IFLAG += -D__SIM_FFT__

IFLAG += -D__SIM_FIR__

IFLAG += -D__SIM_DDS__

IFLAG += -D__DSP48E1__
IFLAG += -Wno-unknown-pragmas 
IFLAG += -g
IFLAG += -DNT
LFLAG += -Wl,--enable-auto-import 
DFLAG += -D__xilinx_ip_top= -DAESL_TB
CCFLAG += 
TOOLCHAIN += 



include ./Makefile.rules

all: $(TARGET)



$(ObjDir)/newtest_sign_2.o: ../../../../newtest_sign_2.c $(ObjDir)/.dir
	$(Echo) "   Compiling ../../../../newtest_sign_2.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(CC) ${CCFLAG} -c -MMD -Wno-unknown-pragmas -Wno-unknown-pragmas  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/newtest_sign_2.d

$(ObjDir)/KeccakHash.o: ../../../../sha3/KeccakHash.c $(ObjDir)/.dir
	$(Echo) "   Compiling ../../../../sha3/KeccakHash.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(CC) ${CCFLAG} -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/KeccakHash.d

$(ObjDir)/KeccakP-1600-reference.o: ../../../../sha3/KeccakP-1600-reference.c $(ObjDir)/.dir
	$(Echo) "   Compiling ../../../../sha3/KeccakP-1600-reference.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(CC) ${CCFLAG} -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/KeccakP-1600-reference.d

$(ObjDir)/KeccakSpongeWidth1600.o: ../../../../sha3/KeccakSpongeWidth1600.c $(ObjDir)/.dir
	$(Echo) "   Compiling ../../../../sha3/KeccakSpongeWidth1600.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(CC) ${CCFLAG} -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/KeccakSpongeWidth1600.d

$(ObjDir)/aes.o: ../../../../NIST-KATs/aes.c $(ObjDir)/.dir
	$(Echo) "   Compiling ../../../../NIST-KATs/aes.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(CC) ${CCFLAG} -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/aes.d

$(ObjDir)/api.o: ../../../../api.c $(ObjDir)/.dir
	$(Echo) "   Compiling ../../../../api.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(CC) ${CCFLAG} -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/api.d

$(ObjDir)/hash.o: ../../../../hash.c $(ObjDir)/.dir
	$(Echo) "   Compiling ../../../../hash.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(CC) ${CCFLAG} -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/hash.d

$(ObjDir)/lowmc_constants.o: ../../../../lowmc_constants.c $(ObjDir)/.dir
	$(Echo) "   Compiling ../../../../lowmc_constants.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(CC) ${CCFLAG} -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/lowmc_constants.d

$(ObjDir)/picnic.o: ../../../../picnic.c $(ObjDir)/.dir
	$(Echo) "   Compiling ../../../../picnic.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(CC) ${CCFLAG} -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/picnic.d

$(ObjDir)/picnic2_impl.o: ../../../../picnic2_impl.c $(ObjDir)/.dir
	$(Echo) "   Compiling ../../../../picnic2_impl.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(CC) ${CCFLAG} -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/picnic2_impl.d

$(ObjDir)/picnic_impl.o: ../../../../picnic_impl.c $(ObjDir)/.dir
	$(Echo) "   Compiling ../../../../picnic_impl.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(CC) ${CCFLAG} -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/picnic_impl.d

$(ObjDir)/picnic_types.o: ../../../../picnic_types.c $(ObjDir)/.dir
	$(Echo) "   Compiling ../../../../picnic_types.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(CC) ${CCFLAG} -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/picnic_types.d

$(ObjDir)/rng.o: ../../../../NIST-KATs/rng.c $(ObjDir)/.dir
	$(Echo) "   Compiling ../../../../NIST-KATs/rng.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(CC) ${CCFLAG} -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/rng.d

$(ObjDir)/tree.o: ../../../../tree.c $(ObjDir)/.dir
	$(Echo) "   Compiling ../../../../tree.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(CC) ${CCFLAG} -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/tree.d
