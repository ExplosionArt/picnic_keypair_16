/* Provide Declarations */
#include <stdarg.h>
#include <setjmp.h>
#include <limits.h>
#ifdef NEED_CBEAPINT
#include <autopilot_cbe.h>
#else
#define aesl_fopen fopen
#define aesl_freopen freopen
#define aesl_tmpfile tmpfile
#endif
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#ifdef __STRICT_ANSI__
#define inline __inline__
#define typeof __typeof__ 
#endif
#define __isoc99_fscanf fscanf
#define __isoc99_sscanf sscanf
#undef ferror
#undef feof
/* get a declaration for alloca */
#if defined(__CYGWIN__) || defined(__MINGW32__)
#define  alloca(x) __builtin_alloca((x))
#define _alloca(x) __builtin_alloca((x))
#elif defined(__APPLE__)
extern void *__builtin_alloca(unsigned long);
#define alloca(x) __builtin_alloca(x)
#define longjmp _longjmp
#define setjmp _setjmp
#elif defined(__sun__)
#if defined(__sparcv9)
extern void *__builtin_alloca(unsigned long);
#else
extern void *__builtin_alloca(unsigned int);
#endif
#define alloca(x) __builtin_alloca(x)
#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__arm__)
#define alloca(x) __builtin_alloca(x)
#elif defined(_MSC_VER)
#define inline _inline
#define alloca(x) _alloca(x)
#else
#include <alloca.h>
#endif

#ifndef __GNUC__  /* Can only support "linkonce" vars with GCC */
#define __attribute__(X)
#endif

#if defined(__GNUC__) && defined(__APPLE_CC__)
#define __EXTERNAL_WEAK__ __attribute__((weak_import))
#elif defined(__GNUC__)
#define __EXTERNAL_WEAK__ __attribute__((weak))
#else
#define __EXTERNAL_WEAK__
#endif

#if defined(__GNUC__) && (defined(__APPLE_CC__) || defined(__CYGWIN__) || defined(__MINGW32__))
#define __ATTRIBUTE_WEAK__
#elif defined(__GNUC__)
#define __ATTRIBUTE_WEAK__ __attribute__((weak))
#else
#define __ATTRIBUTE_WEAK__
#endif

#if defined(__GNUC__)
#define __HIDDEN__ __attribute__((visibility("hidden")))
#endif

#ifdef __GNUC__
#define LLVM_NAN(NanStr)   __builtin_nan(NanStr)   /* Double */
#define LLVM_NANF(NanStr)  __builtin_nanf(NanStr)  /* Float */
#define LLVM_NANS(NanStr)  __builtin_nans(NanStr)  /* Double */
#define LLVM_NANSF(NanStr) __builtin_nansf(NanStr) /* Float */
#define LLVM_INF           __builtin_inf()         /* Double */
#define LLVM_INFF          __builtin_inff()        /* Float */
#define LLVM_PREFETCH(addr,rw,locality) __builtin_prefetch(addr,rw,locality)
#define __ATTRIBUTE_CTOR__ __attribute__((constructor))
#define __ATTRIBUTE_DTOR__ __attribute__((destructor))
#define LLVM_ASM           __asm__
#else
#define LLVM_NAN(NanStr)   ((double)0.0)           /* Double */
#define LLVM_NANF(NanStr)  0.0F                    /* Float */
#define LLVM_NANS(NanStr)  ((double)0.0)           /* Double */
#define LLVM_NANSF(NanStr) 0.0F                    /* Float */
#define LLVM_INF           ((double)0.0)           /* Double */
#define LLVM_INFF          0.0F                    /* Float */
#define LLVM_PREFETCH(addr,rw,locality)            /* PREFETCH */
#define __ATTRIBUTE_CTOR__
#define __ATTRIBUTE_DTOR__
#define LLVM_ASM(X)
#endif

#if __GNUC__ < 4 /* Old GCC's, or compilers not GCC */ 
#define __builtin_stack_save() 0   /* not implemented */
#define __builtin_stack_restore(X) /* noop */
#endif

#if __GNUC__ && __LP64__ /* 128-bit integer types */
typedef int __attribute__((mode(TI))) llvmInt128;
typedef unsigned __attribute__((mode(TI))) llvmUInt128;
#endif

#define CODE_FOR_MAIN() /* Any target-specific code for main()*/

#ifndef __cplusplus
typedef unsigned char bool;
#endif


/* Support for floating point constants */
typedef unsigned long long ConstantDoubleTy;
typedef unsigned int        ConstantFloatTy;
typedef struct { unsigned long long f1; unsigned short f2; unsigned short pad[3]; } ConstantFP80Ty;
typedef struct { unsigned long long f1; unsigned long long f2; } ConstantFP128Ty;


/* Global Declarations */
/* Helper union for bitcasts */
typedef union {
  unsigned int Int32;
  unsigned long long Int64;
  float Float;
  double Double;
} llvmBitCastUnion;
/* Structure forward decls */
typedef struct l_struct_OC__iobuf l_struct_OC__iobuf;

/* Structure contents */
struct l_struct_OC__iobuf {
   char *field0;
  unsigned int field1;
   char *field2;
  unsigned int field3;
  unsigned int field4;
  unsigned int field5;
  unsigned int field6;
   char *field7;
};


/* External Global Variable Declarations */

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
void KeccakP1600_Initialize( char *llvm_cbe_state);
void KeccakP1600_AddByte( char *llvm_cbe_state,  char llvm_cbe_byte, signed int llvm_cbe_offset);
void KeccakP1600_AddBytes( char *llvm_cbe_state,  char *llvm_cbe_data, signed int llvm_cbe_offset, signed int llvm_cbe_length);
void KeccakP1600_OverwriteBytes( char *llvm_cbe_state,  char *llvm_cbe_data, signed int llvm_cbe_offset, signed int llvm_cbe_length);
void KeccakP1600_OverwriteWithZeroes( char *llvm_cbe_state, signed int llvm_cbe_byteCount);
void KeccakP1600_Permute_Nrounds( char *llvm_cbe_state, signed int llvm_cbe_nrounds);
void KeccakP1600OnWords(signed long long *llvm_cbe_state, signed int llvm_cbe_nrRounds);
void KeccakP1600_Permute_12rounds( char *llvm_cbe_state);
void KeccakP1600_Permute_24rounds( char *llvm_cbe_state);
static void aesl_internal_fromBytesToWords(signed long long *llvm_cbe_stateAsWords,  char *llvm_cbe_state);
static void aesl_internal_fromWordsToBytes( char *llvm_cbe_state, signed long long *llvm_cbe_stateAsWords);
void KeccakP1600Round(signed long long *llvm_cbe_state, signed int llvm_cbe_indexRound);
static void aesl_internal_theta(signed long long *llvm_cbe_A);
static void aesl_internal_rho(signed long long *llvm_cbe_A);
static void aesl_internal_pi(signed long long *llvm_cbe_A);
static void aesl_internal_chi(signed long long *llvm_cbe_A);
static void aesl_internal_iota(signed long long *llvm_cbe_A, signed int llvm_cbe_indexRound);
void KeccakP1600_ExtractBytes( char *llvm_cbe_state,  char *llvm_cbe_data, signed int llvm_cbe_offset, signed int llvm_cbe_length);
void KeccakP1600_ExtractAndAddBytes( char *llvm_cbe_state,  char *llvm_cbe_input,  char *llvm_cbe_output, signed int llvm_cbe_offset, signed int llvm_cbe_length);
void KeccakP1600_DisplayRoundConstants(l_struct_OC__iobuf *llvm_cbe_f);
void KeccakP1600_DisplayRhoOffsets(l_struct_OC__iobuf *llvm_cbe_f);


/* Global Variable Definitions and Initialization */
static  char aesl_internal__OC_str1[50] = "C:/project16-master/sha3/KeccakP-1600-reference.c";
static  char aesl_internal__OC_str[13] = "offset < 200";
static  char aesl_internal__OC_str2[21] = "offset+length <= 200";
static  char aesl_internal__OC_str3[17] = "byteCount <= 200";
static  char aesl_internal__OC_str4[18] = "RC[%02i][0][0] = ";
static  char aesl_internal__OC_str5[5] = "%08X";
static signed long long aesl_internal_KeccakRoundConstants[24] = { 1ull, 32898ull, 9223372036854808714ull, 9223372039002292224ull, 32907ull, 2147483649ull, 9223372039002292353ull, 9223372036854808585ull, 138ull, 136ull, 2147516425ull, 2147483658ull, 2147516555ull, 9223372036854775947ull, 9223372036854808713ull, 9223372036854808579ull, 9223372036854808578ull, 9223372036854775936ull, 32778ull, 9223372039002259466ull, 9223372039002292353ull, 9223372036854808704ull, 2147483649ull, 9223372039002292232ull };
static  char aesl_internal__OC_str7[21] = "RhoOffset[%i][%i] = ";
static  char aesl_internal__OC_str8[4] = "%2i";
static signed int aesl_internal_KeccakRhoOffsets[25] = { 0u, 1u, 62u, 28u, 27u, 36u, 44u, 6u, 55u, 20u, 3u, 10u, 43u, 25u, 39u, 41u, 45u, 15u, 21u, 8u, 18u, 2u, 61u, 56u, 14u };


/* Function Bodies */
static inline int llvm_fcmp_ord(double X, double Y) { return X == X && Y == Y; }
static inline int llvm_fcmp_uno(double X, double Y) { return X != X || Y != Y; }
static inline int llvm_fcmp_ueq(double X, double Y) { return X == Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_une(double X, double Y) { return X != Y; }
static inline int llvm_fcmp_ult(double X, double Y) { return X <  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ugt(double X, double Y) { return X >  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ule(double X, double Y) { return X <= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_uge(double X, double Y) { return X >= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_oeq(double X, double Y) { return X == Y ; }
static inline int llvm_fcmp_one(double X, double Y) { return X != Y && llvm_fcmp_ord(X, Y); }
static inline int llvm_fcmp_olt(double X, double Y) { return X <  Y ; }
static inline int llvm_fcmp_ogt(double X, double Y) { return X >  Y ; }
static inline int llvm_fcmp_ole(double X, double Y) { return X <= Y ; }
static inline int llvm_fcmp_oge(double X, double Y) { return X >= Y ; }

void KeccakP1600_Initialize( char *llvm_cbe_state) {
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
   char *llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @KeccakP1600_Initialize\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = call i8* @memset(i8* %%state, i32 0, i64 200 for 0x%I64xth hint within @KeccakP1600_Initialize  --> \n", ++aesl_llvm_cbe_7_count);
  ( char *)memset(( char *)llvm_cbe_state, 0u, 200ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",200ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__1);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @KeccakP1600_Initialize}\n");
  return;
}


void KeccakP1600_AddByte( char *llvm_cbe_state,  char llvm_cbe_byte, signed int llvm_cbe_offset) {
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  unsigned long long llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
   char *llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  unsigned char llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  unsigned char llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @KeccakP1600_AddByte\n");
  if ((((unsigned int )llvm_cbe_offset&4294967295U) < ((unsigned int )200u&4294967295U))) {
    goto llvm_cbe_tmp__6;
  } else {
    goto llvm_cbe_tmp__7;
  }

llvm_cbe_tmp__7:
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @_assert(i8* getelementptr inbounds ([13 x i8]* @aesl_internal_.str, i64 0, i64 0), i8* getelementptr inbounds ([50 x i8]* @aesl_internal_.str1, i64 0, i64 0), i32 148) nounwind, !dbg !16 for 0x%I64xth hint within @KeccakP1600_AddByte  --> \n", ++aesl_llvm_cbe_18_count);
   /*tail*/ _assert(( char *)((&aesl_internal__OC_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 13
#endif
])), ( char *)((&aesl_internal__OC_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 50
#endif
])), 148u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",148u);
}
  goto llvm_cbe_tmp__6;

llvm_cbe_tmp__6:
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = zext i32 %%offset to i64, !dbg !15 for 0x%I64xth hint within @KeccakP1600_AddByte  --> \n", ++aesl_llvm_cbe_20_count);
  llvm_cbe_tmp__2 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_offset&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__2);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds i8* %%state, i64 %%4, !dbg !15 for 0x%I64xth hint within @KeccakP1600_AddByte  --> \n", ++aesl_llvm_cbe_21_count);
  llvm_cbe_tmp__3 = ( char *)(&llvm_cbe_state[(((signed long long )llvm_cbe_tmp__2))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__2));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load i8* %%5, align 1, !dbg !15 for 0x%I64xth hint within @KeccakP1600_AddByte  --> \n", ++aesl_llvm_cbe_22_count);
  llvm_cbe_tmp__4 = (unsigned char )*llvm_cbe_tmp__3;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__4);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = xor i8 %%6, %%byte, !dbg !15 for 0x%I64xth hint within @KeccakP1600_AddByte  --> \n", ++aesl_llvm_cbe_23_count);
  llvm_cbe_tmp__5 = (unsigned char )((unsigned char )(llvm_cbe_tmp__4 ^ llvm_cbe_byte));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__5);
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%7, i8* %%5, align 1, !dbg !15 for 0x%I64xth hint within @KeccakP1600_AddByte  --> \n", ++aesl_llvm_cbe_24_count);
  *llvm_cbe_tmp__3 = llvm_cbe_tmp__5;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__5);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @KeccakP1600_AddByte}\n");
  return;
}


void KeccakP1600_AddBytes( char *llvm_cbe_state,  char *llvm_cbe_data, signed int llvm_cbe_offset, signed int llvm_cbe_length) {
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  unsigned long long llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
   char *llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  unsigned char llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  unsigned int llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  unsigned long long llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
   char *llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  unsigned char llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  unsigned char llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  unsigned int llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @KeccakP1600_AddBytes\n");
  if (((llvm_cbe_length&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ %%10, %%.lr.ph ], [ 0, %%0  for 0x%I64xth hint within @KeccakP1600_AddBytes  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",llvm_cbe_tmp__16);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = zext i32 %%storemerge1 to i64, !dbg !15 for 0x%I64xth hint within @KeccakP1600_AddBytes  --> \n", ++aesl_llvm_cbe_46_count);
  llvm_cbe_tmp__8 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge1&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__8);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds i8* %%data, i64 %%2, !dbg !15 for 0x%I64xth hint within @KeccakP1600_AddBytes  --> \n", ++aesl_llvm_cbe_47_count);
  llvm_cbe_tmp__9 = ( char *)(&llvm_cbe_data[(((signed long long )llvm_cbe_tmp__8))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__8));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i8* %%3, align 1, !dbg !15 for 0x%I64xth hint within @KeccakP1600_AddBytes  --> \n", ++aesl_llvm_cbe_48_count);
  llvm_cbe_tmp__10 = (unsigned char )*llvm_cbe_tmp__9;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__10);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = add i32 %%storemerge1, %%offset, !dbg !15 for 0x%I64xth hint within @KeccakP1600_AddBytes  --> \n", ++aesl_llvm_cbe_49_count);
  llvm_cbe_tmp__11 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(llvm_cbe_offset&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__11&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = zext i32 %%5 to i64, !dbg !15 for 0x%I64xth hint within @KeccakP1600_AddBytes  --> \n", ++aesl_llvm_cbe_50_count);
  llvm_cbe_tmp__12 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__11&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__12);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds i8* %%state, i64 %%6, !dbg !15 for 0x%I64xth hint within @KeccakP1600_AddBytes  --> \n", ++aesl_llvm_cbe_51_count);
  llvm_cbe_tmp__13 = ( char *)(&llvm_cbe_state[(((signed long long )llvm_cbe_tmp__12))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__12));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load i8* %%7, align 1, !dbg !15 for 0x%I64xth hint within @KeccakP1600_AddBytes  --> \n", ++aesl_llvm_cbe_52_count);
  llvm_cbe_tmp__14 = (unsigned char )*llvm_cbe_tmp__13;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__14);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = xor i8 %%8, %%4, !dbg !15 for 0x%I64xth hint within @KeccakP1600_AddBytes  --> \n", ++aesl_llvm_cbe_53_count);
  llvm_cbe_tmp__15 = (unsigned char )((unsigned char )(llvm_cbe_tmp__14 ^ llvm_cbe_tmp__10));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__15);
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%9, i8* %%7, align 1, !dbg !15 for 0x%I64xth hint within @KeccakP1600_AddBytes  --> \n", ++aesl_llvm_cbe_54_count);
  *llvm_cbe_tmp__13 = llvm_cbe_tmp__15;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__15);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = add i32 %%storemerge1, 1, !dbg !17 for 0x%I64xth hint within @KeccakP1600_AddBytes  --> \n", ++aesl_llvm_cbe_55_count);
  llvm_cbe_tmp__16 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__16&4294967295ull)));
  if (((llvm_cbe_tmp__16&4294967295U) == (llvm_cbe_length&4294967295U))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__16;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @KeccakP1600_AddBytes}\n");
  return;
}


void KeccakP1600_OverwriteBytes( char *llvm_cbe_state,  char *llvm_cbe_data, signed int llvm_cbe_offset, signed int llvm_cbe_length) {
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  unsigned int llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  unsigned long long llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
   char *llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  unsigned long long llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
   char *llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @KeccakP1600_OverwriteBytes\n");
  if ((((unsigned int )llvm_cbe_offset&4294967295U) < ((unsigned int )200u&4294967295U))) {
    goto llvm_cbe_tmp__22;
  } else {
    goto llvm_cbe_tmp__23;
  }

llvm_cbe_tmp__23:
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @_assert(i8* getelementptr inbounds ([13 x i8]* @aesl_internal_.str, i64 0, i64 0), i8* getelementptr inbounds ([50 x i8]* @aesl_internal_.str1, i64 0, i64 0), i32 168) nounwind, !dbg !16 for 0x%I64xth hint within @KeccakP1600_OverwriteBytes  --> \n", ++aesl_llvm_cbe_76_count);
   /*tail*/ _assert(( char *)((&aesl_internal__OC_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 13
#endif
])), ( char *)((&aesl_internal__OC_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 50
#endif
])), 168u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",168u);
}
  goto llvm_cbe_tmp__22;

llvm_cbe_tmp__22:
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = add i32 %%length, %%offset, !dbg !16 for 0x%I64xth hint within @KeccakP1600_OverwriteBytes  --> \n", ++aesl_llvm_cbe_78_count);
  llvm_cbe_tmp__17 = (unsigned int )((unsigned int )(llvm_cbe_length&4294967295ull)) + ((unsigned int )(llvm_cbe_offset&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__17&4294967295ull)));
  if ((((unsigned int )llvm_cbe_tmp__17&4294967295U) < ((unsigned int )201u&4294967295U))) {
    goto llvm_cbe_tmp__24;
  } else {
    goto llvm_cbe_tmp__25;
  }

llvm_cbe_tmp__25:
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @_assert(i8* getelementptr inbounds ([21 x i8]* @aesl_internal_.str2, i64 0, i64 0), i8* getelementptr inbounds ([50 x i8]* @aesl_internal_.str1, i64 0, i64 0), i32 169) nounwind, !dbg !16 for 0x%I64xth hint within @KeccakP1600_OverwriteBytes  --> \n", ++aesl_llvm_cbe_81_count);
   /*tail*/ _assert(( char *)((&aesl_internal__OC_str2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 21
#endif
])), ( char *)((&aesl_internal__OC_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 50
#endif
])), 169u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",169u);
}
  goto llvm_cbe_tmp__24;

llvm_cbe_tmp__24:
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = zext i32 %%offset to i64, !dbg !15 for 0x%I64xth hint within @KeccakP1600_OverwriteBytes  --> \n", ++aesl_llvm_cbe_83_count);
  llvm_cbe_tmp__18 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_offset&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__18);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds i8* %%state, i64 %%8, !dbg !15 for 0x%I64xth hint within @KeccakP1600_OverwriteBytes  --> \n", ++aesl_llvm_cbe_84_count);
  llvm_cbe_tmp__19 = ( char *)(&llvm_cbe_state[(((signed long long )llvm_cbe_tmp__18))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__18));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = zext i32 %%length to i64, !dbg !15 for 0x%I64xth hint within @KeccakP1600_OverwriteBytes  --> \n", ++aesl_llvm_cbe_85_count);
  llvm_cbe_tmp__20 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_length&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__20);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = call i8* @memcpy(i8* %%9, i8* %%data, i64 %%10 for 0x%I64xth hint within @KeccakP1600_OverwriteBytes  --> \n", ++aesl_llvm_cbe_86_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__19, ( char *)llvm_cbe_data, llvm_cbe_tmp__20);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__20);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__21);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @KeccakP1600_OverwriteBytes}\n");
  return;
}


void KeccakP1600_OverwriteWithZeroes( char *llvm_cbe_state, signed int llvm_cbe_byteCount) {
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  unsigned long long llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
   char *llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @KeccakP1600_OverwriteWithZeroes\n");
  if ((((unsigned int )llvm_cbe_byteCount&4294967295U) < ((unsigned int )201u&4294967295U))) {
    goto llvm_cbe_tmp__28;
  } else {
    goto llvm_cbe_tmp__29;
  }

llvm_cbe_tmp__29:
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @_assert(i8* getelementptr inbounds ([17 x i8]* @aesl_internal_.str3, i64 0, i64 0), i8* getelementptr inbounds ([50 x i8]* @aesl_internal_.str1, i64 0, i64 0), i32 177) nounwind, !dbg !16 for 0x%I64xth hint within @KeccakP1600_OverwriteWithZeroes  --> \n", ++aesl_llvm_cbe_95_count);
   /*tail*/ _assert(( char *)((&aesl_internal__OC_str3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 17
#endif
])), ( char *)((&aesl_internal__OC_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 50
#endif
])), 177u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",177u);
}
  goto llvm_cbe_tmp__28;

llvm_cbe_tmp__28:
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = zext i32 %%byteCount to i64, !dbg !15 for 0x%I64xth hint within @KeccakP1600_OverwriteWithZeroes  --> \n", ++aesl_llvm_cbe_97_count);
  llvm_cbe_tmp__26 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_byteCount&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__26);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = call i8* @memset(i8* %%state, i32 0, i64 %%4 for 0x%I64xth hint within @KeccakP1600_OverwriteWithZeroes  --> \n", ++aesl_llvm_cbe_98_count);
  ( char *)memset(( char *)llvm_cbe_state, 0u, llvm_cbe_tmp__26);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__26);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__27);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @KeccakP1600_OverwriteWithZeroes}\n");
  return;
}


void KeccakP1600_Permute_Nrounds( char *llvm_cbe_state, signed int llvm_cbe_nrounds) {
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
  signed long long *llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @KeccakP1600_Permute_Nrounds\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = bitcast i8* %%state to i64*, !dbg !16 for 0x%I64xth hint within @KeccakP1600_Permute_Nrounds  --> \n", ++aesl_llvm_cbe_103_count);
  llvm_cbe_tmp__30 = (signed long long *)((signed long long *)llvm_cbe_state);
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @KeccakP1600OnWords(i64* %%1, i32 %%nrounds), !dbg !16 for 0x%I64xth hint within @KeccakP1600_Permute_Nrounds  --> \n", ++aesl_llvm_cbe_105_count);
   /*tail*/ KeccakP1600OnWords((signed long long *)llvm_cbe_tmp__30, llvm_cbe_nrounds);
if (AESL_DEBUG_TRACE) {
printf("\nArgument nrounds = 0x%X",llvm_cbe_nrounds);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @KeccakP1600_Permute_Nrounds}\n");
  return;
}


void KeccakP1600OnWords(signed long long *llvm_cbe_state, signed int llvm_cbe_nrRounds) {
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  unsigned int llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
  unsigned int llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @KeccakP1600OnWords\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = sub i32 24, %%nrRounds, !dbg !16 for 0x%I64xth hint within @KeccakP1600OnWords  --> \n", ++aesl_llvm_cbe_111_count);
  llvm_cbe_tmp__31 = (unsigned int )((unsigned int )(24u&4294967295ull)) - ((unsigned int )(llvm_cbe_nrRounds&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__31&4294967295ull)));
  if ((((unsigned int )llvm_cbe_tmp__31&4294967295U) < ((unsigned int )24u&4294967295U))) {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__31;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ %%3, %%.lr.ph ], [ %%1, %%0  for 0x%I64xth hint within @KeccakP1600OnWords  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",llvm_cbe_tmp__32);
printf("\n = 0x%X",llvm_cbe_tmp__31);
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @KeccakP1600Round(i64* %%state, i32 %%storemerge1), !dbg !15 for 0x%I64xth hint within @KeccakP1600OnWords  --> \n", ++aesl_llvm_cbe_118_count);
   /*tail*/ KeccakP1600Round((signed long long *)llvm_cbe_state, llvm_cbe_storemerge1);
if (AESL_DEBUG_TRACE) {
printf("\nArgument storemerge1 = 0x%X",llvm_cbe_storemerge1);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = add i32 %%storemerge1, 1, !dbg !16 for 0x%I64xth hint within @KeccakP1600OnWords  --> \n", ++aesl_llvm_cbe_119_count);
  llvm_cbe_tmp__32 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__32&4294967295ull)));
  if (((llvm_cbe_tmp__32&4294967295U) == (24u&4294967295U))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__32;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @KeccakP1600OnWords}\n");
  return;
}


void KeccakP1600_Permute_12rounds( char *llvm_cbe_state) {
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  signed long long *llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @KeccakP1600_Permute_12rounds\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = bitcast i8* %%state to i64*, !dbg !15 for 0x%I64xth hint within @KeccakP1600_Permute_12rounds  --> \n", ++aesl_llvm_cbe_128_count);
  llvm_cbe_tmp__33 = (signed long long *)((signed long long *)llvm_cbe_state);
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @KeccakP1600OnWords(i64* %%1, i32 12), !dbg !15 for 0x%I64xth hint within @KeccakP1600_Permute_12rounds  --> \n", ++aesl_llvm_cbe_129_count);
   /*tail*/ KeccakP1600OnWords((signed long long *)llvm_cbe_tmp__33, 12u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",12u);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @KeccakP1600_Permute_12rounds}\n");
  return;
}


void KeccakP1600_Permute_24rounds( char *llvm_cbe_state) {
  static  unsigned long long aesl_llvm_cbe_stateAsWords_count = 0;
  signed long long llvm_cbe_stateAsWords[25];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  signed long long *llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @KeccakP1600_Permute_24rounds\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds [25 x i64]* %%stateAsWords, i64 0, i64 0, !dbg !15 for 0x%I64xth hint within @KeccakP1600_Permute_24rounds  --> \n", ++aesl_llvm_cbe_136_count);
  llvm_cbe_tmp__34 = (signed long long *)(&llvm_cbe_stateAsWords[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 25
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call fastcc void @aesl_internal_fromBytesToWords(i64* %%1, i8* %%state), !dbg !15 for 0x%I64xth hint within @KeccakP1600_Permute_24rounds  --> \n", ++aesl_llvm_cbe_137_count);
  aesl_internal_fromBytesToWords((signed long long *)llvm_cbe_tmp__34, ( char *)llvm_cbe_state);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @KeccakP1600OnWords(i64* %%1, i32 24), !dbg !16 for 0x%I64xth hint within @KeccakP1600_Permute_24rounds  --> \n", ++aesl_llvm_cbe_138_count);
  KeccakP1600OnWords((signed long long *)llvm_cbe_tmp__34, 24u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",24u);
}
if (AESL_DEBUG_TRACE)
printf("\n  call fastcc void @aesl_internal_fromWordsToBytes(i8* %%state, i64* %%1), !dbg !16 for 0x%I64xth hint within @KeccakP1600_Permute_24rounds  --> \n", ++aesl_llvm_cbe_139_count);
  aesl_internal_fromWordsToBytes(( char *)llvm_cbe_state, (signed long long *)llvm_cbe_tmp__34);
if (AESL_DEBUG_TRACE) {
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @KeccakP1600_Permute_24rounds}\n");
  return;
}


static void aesl_internal_fromBytesToWords(signed long long *llvm_cbe_stateAsWords,  char *llvm_cbe_state) {
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;
  static  unsigned long long aesl_llvm_cbe_152_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned int llvm_cbe_storemerge3;
  unsigned int llvm_cbe_storemerge3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_153_count = 0;
  unsigned long long llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_154_count = 0;
  signed long long *llvm_cbe_tmp__36;
  static  unsigned long long aesl_llvm_cbe_155_count = 0;
  static  unsigned long long aesl_llvm_cbe_156_count = 0;
  static  unsigned long long aesl_llvm_cbe_157_count = 0;
  static  unsigned long long aesl_llvm_cbe_158_count = 0;
  static  unsigned long long aesl_llvm_cbe_159_count = 0;
  static  unsigned long long aesl_llvm_cbe_160_count = 0;
  static  unsigned long long aesl_llvm_cbe_161_count = 0;
  unsigned int llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_162_count = 0;
  unsigned long long llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_163_count = 0;
   char *llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_164_count = 0;
  unsigned char llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_165_count = 0;
  unsigned long long llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_166_count = 0;
  static  unsigned long long aesl_llvm_cbe_167_count = 0;
  static  unsigned long long aesl_llvm_cbe_168_count = 0;
  static  unsigned long long aesl_llvm_cbe_169_count = 0;
  static  unsigned long long aesl_llvm_cbe_170_count = 0;
  static  unsigned long long aesl_llvm_cbe_171_count = 0;
  static  unsigned long long aesl_llvm_cbe_172_count = 0;
  unsigned int llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_173_count = 0;
  unsigned long long llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_174_count = 0;
   char *llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_175_count = 0;
  unsigned char llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_176_count = 0;
  unsigned long long llvm_cbe_tmp__46;
  static  unsigned long long aesl_llvm_cbe_177_count = 0;
  unsigned long long llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe_178_count = 0;
  unsigned long long llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
  static  unsigned long long aesl_llvm_cbe_180_count = 0;
  static  unsigned long long aesl_llvm_cbe_181_count = 0;
  static  unsigned long long aesl_llvm_cbe_182_count = 0;
  static  unsigned long long aesl_llvm_cbe_183_count = 0;
  static  unsigned long long aesl_llvm_cbe_184_count = 0;
  static  unsigned long long aesl_llvm_cbe_185_count = 0;
  unsigned int llvm_cbe_tmp__49;
  static  unsigned long long aesl_llvm_cbe_186_count = 0;
  unsigned long long llvm_cbe_tmp__50;
  static  unsigned long long aesl_llvm_cbe_187_count = 0;
   char *llvm_cbe_tmp__51;
  static  unsigned long long aesl_llvm_cbe_188_count = 0;
  unsigned char llvm_cbe_tmp__52;
  static  unsigned long long aesl_llvm_cbe_189_count = 0;
  unsigned long long llvm_cbe_tmp__53;
  static  unsigned long long aesl_llvm_cbe_190_count = 0;
  unsigned long long llvm_cbe_tmp__54;
  static  unsigned long long aesl_llvm_cbe_191_count = 0;
  unsigned long long llvm_cbe_tmp__55;
  static  unsigned long long aesl_llvm_cbe_192_count = 0;
  static  unsigned long long aesl_llvm_cbe_193_count = 0;
  static  unsigned long long aesl_llvm_cbe_194_count = 0;
  static  unsigned long long aesl_llvm_cbe_195_count = 0;
  static  unsigned long long aesl_llvm_cbe_196_count = 0;
  static  unsigned long long aesl_llvm_cbe_197_count = 0;
  static  unsigned long long aesl_llvm_cbe_198_count = 0;
  unsigned int llvm_cbe_tmp__56;
  static  unsigned long long aesl_llvm_cbe_199_count = 0;
  unsigned long long llvm_cbe_tmp__57;
  static  unsigned long long aesl_llvm_cbe_200_count = 0;
   char *llvm_cbe_tmp__58;
  static  unsigned long long aesl_llvm_cbe_201_count = 0;
  unsigned char llvm_cbe_tmp__59;
  static  unsigned long long aesl_llvm_cbe_202_count = 0;
  unsigned long long llvm_cbe_tmp__60;
  static  unsigned long long aesl_llvm_cbe_203_count = 0;
  unsigned long long llvm_cbe_tmp__61;
  static  unsigned long long aesl_llvm_cbe_204_count = 0;
  unsigned long long llvm_cbe_tmp__62;
  static  unsigned long long aesl_llvm_cbe_205_count = 0;
  static  unsigned long long aesl_llvm_cbe_206_count = 0;
  static  unsigned long long aesl_llvm_cbe_207_count = 0;
  static  unsigned long long aesl_llvm_cbe_208_count = 0;
  static  unsigned long long aesl_llvm_cbe_209_count = 0;
  static  unsigned long long aesl_llvm_cbe_210_count = 0;
  static  unsigned long long aesl_llvm_cbe_211_count = 0;
  unsigned int llvm_cbe_tmp__63;
  static  unsigned long long aesl_llvm_cbe_212_count = 0;
  unsigned long long llvm_cbe_tmp__64;
  static  unsigned long long aesl_llvm_cbe_213_count = 0;
   char *llvm_cbe_tmp__65;
  static  unsigned long long aesl_llvm_cbe_214_count = 0;
  unsigned char llvm_cbe_tmp__66;
  static  unsigned long long aesl_llvm_cbe_215_count = 0;
  unsigned long long llvm_cbe_tmp__67;
  static  unsigned long long aesl_llvm_cbe_216_count = 0;
  unsigned long long llvm_cbe_tmp__68;
  static  unsigned long long aesl_llvm_cbe_217_count = 0;
  unsigned long long llvm_cbe_tmp__69;
  static  unsigned long long aesl_llvm_cbe_218_count = 0;
  static  unsigned long long aesl_llvm_cbe_219_count = 0;
  static  unsigned long long aesl_llvm_cbe_220_count = 0;
  static  unsigned long long aesl_llvm_cbe_221_count = 0;
  static  unsigned long long aesl_llvm_cbe_222_count = 0;
  static  unsigned long long aesl_llvm_cbe_223_count = 0;
  static  unsigned long long aesl_llvm_cbe_224_count = 0;
  unsigned int llvm_cbe_tmp__70;
  static  unsigned long long aesl_llvm_cbe_225_count = 0;
  unsigned long long llvm_cbe_tmp__71;
  static  unsigned long long aesl_llvm_cbe_226_count = 0;
   char *llvm_cbe_tmp__72;
  static  unsigned long long aesl_llvm_cbe_227_count = 0;
  unsigned char llvm_cbe_tmp__73;
  static  unsigned long long aesl_llvm_cbe_228_count = 0;
  unsigned long long llvm_cbe_tmp__74;
  static  unsigned long long aesl_llvm_cbe_229_count = 0;
  unsigned long long llvm_cbe_tmp__75;
  static  unsigned long long aesl_llvm_cbe_230_count = 0;
  unsigned long long llvm_cbe_tmp__76;
  static  unsigned long long aesl_llvm_cbe_231_count = 0;
  static  unsigned long long aesl_llvm_cbe_232_count = 0;
  static  unsigned long long aesl_llvm_cbe_233_count = 0;
  static  unsigned long long aesl_llvm_cbe_234_count = 0;
  static  unsigned long long aesl_llvm_cbe_235_count = 0;
  static  unsigned long long aesl_llvm_cbe_236_count = 0;
  static  unsigned long long aesl_llvm_cbe_237_count = 0;
  unsigned int llvm_cbe_tmp__77;
  static  unsigned long long aesl_llvm_cbe_238_count = 0;
  unsigned long long llvm_cbe_tmp__78;
  static  unsigned long long aesl_llvm_cbe_239_count = 0;
   char *llvm_cbe_tmp__79;
  static  unsigned long long aesl_llvm_cbe_240_count = 0;
  unsigned char llvm_cbe_tmp__80;
  static  unsigned long long aesl_llvm_cbe_241_count = 0;
  unsigned long long llvm_cbe_tmp__81;
  static  unsigned long long aesl_llvm_cbe_242_count = 0;
  unsigned long long llvm_cbe_tmp__82;
  static  unsigned long long aesl_llvm_cbe_243_count = 0;
  unsigned long long llvm_cbe_tmp__83;
  static  unsigned long long aesl_llvm_cbe_244_count = 0;
  static  unsigned long long aesl_llvm_cbe_245_count = 0;
  static  unsigned long long aesl_llvm_cbe_246_count = 0;
  static  unsigned long long aesl_llvm_cbe_247_count = 0;
  static  unsigned long long aesl_llvm_cbe_248_count = 0;
  static  unsigned long long aesl_llvm_cbe_249_count = 0;
  static  unsigned long long aesl_llvm_cbe_250_count = 0;
  unsigned int llvm_cbe_tmp__84;
  static  unsigned long long aesl_llvm_cbe_251_count = 0;
  unsigned long long llvm_cbe_tmp__85;
  static  unsigned long long aesl_llvm_cbe_252_count = 0;
   char *llvm_cbe_tmp__86;
  static  unsigned long long aesl_llvm_cbe_253_count = 0;
  unsigned char llvm_cbe_tmp__87;
  static  unsigned long long aesl_llvm_cbe_254_count = 0;
  unsigned long long llvm_cbe_tmp__88;
  static  unsigned long long aesl_llvm_cbe_255_count = 0;
  unsigned long long llvm_cbe_tmp__89;
  static  unsigned long long aesl_llvm_cbe_256_count = 0;
  unsigned long long llvm_cbe_tmp__90;
  static  unsigned long long aesl_llvm_cbe_257_count = 0;
  static  unsigned long long aesl_llvm_cbe_258_count = 0;
  static  unsigned long long aesl_llvm_cbe_259_count = 0;
  static  unsigned long long aesl_llvm_cbe_260_count = 0;
  static  unsigned long long aesl_llvm_cbe_261_count = 0;
  static  unsigned long long aesl_llvm_cbe_262_count = 0;
  static  unsigned long long aesl_llvm_cbe_263_count = 0;
  unsigned int llvm_cbe_tmp__91;
  static  unsigned long long aesl_llvm_cbe_264_count = 0;
  static  unsigned long long aesl_llvm_cbe_265_count = 0;
  static  unsigned long long aesl_llvm_cbe_266_count = 0;
  static  unsigned long long aesl_llvm_cbe_267_count = 0;
  static  unsigned long long aesl_llvm_cbe_268_count = 0;
  static  unsigned long long aesl_llvm_cbe_269_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_270_count = 0;
  static  unsigned long long aesl_llvm_cbe_271_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @aesl_internal_fromBytesToWords\n");
  llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__92;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__92:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = phi i32 [ 0, %%0 ], [ %%58, %%1  for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned int )llvm_cbe_storemerge3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%X",llvm_cbe_storemerge3);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__91);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = zext i32 %%storemerge3 to i64, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_153_count);
  llvm_cbe_tmp__35 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge3&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__35);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds i64* %%stateAsWords, i64 %%2, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_154_count);
  llvm_cbe_tmp__36 = (signed long long *)(&llvm_cbe_stateAsWords[(((signed long long )llvm_cbe_tmp__35))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__35));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 0, i64* %%3, align 8, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_155_count);
  *llvm_cbe_tmp__36 = 0ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 0ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = shl i32 %%storemerge3, 3, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_161_count);
  llvm_cbe_tmp__37 = (unsigned int )llvm_cbe_storemerge3 << 3u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__37);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = zext i32 %%4 to i64, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_162_count);
  llvm_cbe_tmp__38 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__37&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__38);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds i8* %%state, i64 %%5, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_163_count);
  llvm_cbe_tmp__39 = ( char *)(&llvm_cbe_state[(((signed long long )llvm_cbe_tmp__38))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__38));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = load i8* %%6, align 1, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_164_count);
  llvm_cbe_tmp__40 = (unsigned char )*llvm_cbe_tmp__39;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__40);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = zext i8 %%7 to i64, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_165_count);
  llvm_cbe_tmp__41 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_tmp__40&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__41);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%8, i64* %%3, align 8, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_166_count);
  *llvm_cbe_tmp__36 = llvm_cbe_tmp__41;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__41);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = or i32 %%4, 1, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_172_count);
  llvm_cbe_tmp__42 = (unsigned int )llvm_cbe_tmp__37 | 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__42);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = zext i32 %%9 to i64, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_173_count);
  llvm_cbe_tmp__43 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__42&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__43);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds i8* %%state, i64 %%10, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_174_count);
  llvm_cbe_tmp__44 = ( char *)(&llvm_cbe_state[(((signed long long )llvm_cbe_tmp__43))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__43));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = load i8* %%11, align 1, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_175_count);
  llvm_cbe_tmp__45 = (unsigned char )*llvm_cbe_tmp__44;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__45);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = zext i8 %%12 to i64, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_176_count);
  llvm_cbe_tmp__46 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_tmp__45&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__46);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = shl nuw nsw i64 %%13, 8, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_177_count);
  llvm_cbe_tmp__47 = (unsigned long long )llvm_cbe_tmp__46 << 8ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__47);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = or i64 %%14, %%8, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_178_count);
  llvm_cbe_tmp__48 = (unsigned long long )llvm_cbe_tmp__47 | llvm_cbe_tmp__41;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__48);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%15, i64* %%3, align 8, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_179_count);
  *llvm_cbe_tmp__36 = llvm_cbe_tmp__48;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__48);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = or i32 %%4, 2, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_185_count);
  llvm_cbe_tmp__49 = (unsigned int )llvm_cbe_tmp__37 | 2u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__49);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = zext i32 %%16 to i64, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_186_count);
  llvm_cbe_tmp__50 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__49&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__50);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = getelementptr inbounds i8* %%state, i64 %%17, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_187_count);
  llvm_cbe_tmp__51 = ( char *)(&llvm_cbe_state[(((signed long long )llvm_cbe_tmp__50))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__50));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = load i8* %%18, align 1, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_188_count);
  llvm_cbe_tmp__52 = (unsigned char )*llvm_cbe_tmp__51;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__52);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = zext i8 %%19 to i64, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_189_count);
  llvm_cbe_tmp__53 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_tmp__52&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__53);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = shl nuw nsw i64 %%20, 16, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_190_count);
  llvm_cbe_tmp__54 = (unsigned long long )llvm_cbe_tmp__53 << 16ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__54);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = or i64 %%21, %%15, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_191_count);
  llvm_cbe_tmp__55 = (unsigned long long )llvm_cbe_tmp__54 | llvm_cbe_tmp__48;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__55);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%22, i64* %%3, align 8, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_192_count);
  *llvm_cbe_tmp__36 = llvm_cbe_tmp__55;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__55);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = or i32 %%4, 3, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_198_count);
  llvm_cbe_tmp__56 = (unsigned int )llvm_cbe_tmp__37 | 3u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__56);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = zext i32 %%23 to i64, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_199_count);
  llvm_cbe_tmp__57 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__56&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__57);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = getelementptr inbounds i8* %%state, i64 %%24, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_200_count);
  llvm_cbe_tmp__58 = ( char *)(&llvm_cbe_state[(((signed long long )llvm_cbe_tmp__57))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__57));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = load i8* %%25, align 1, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_201_count);
  llvm_cbe_tmp__59 = (unsigned char )*llvm_cbe_tmp__58;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__59);
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = zext i8 %%26 to i64, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_202_count);
  llvm_cbe_tmp__60 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_tmp__59&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__60);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = shl nuw nsw i64 %%27, 24, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_203_count);
  llvm_cbe_tmp__61 = (unsigned long long )llvm_cbe_tmp__60 << 24ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__61);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = or i64 %%28, %%22, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_204_count);
  llvm_cbe_tmp__62 = (unsigned long long )llvm_cbe_tmp__61 | llvm_cbe_tmp__55;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__62);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%29, i64* %%3, align 8, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_205_count);
  *llvm_cbe_tmp__36 = llvm_cbe_tmp__62;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__62);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = or i32 %%4, 4, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_211_count);
  llvm_cbe_tmp__63 = (unsigned int )llvm_cbe_tmp__37 | 4u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__63);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = zext i32 %%30 to i64, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_212_count);
  llvm_cbe_tmp__64 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__63&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__64);
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = getelementptr inbounds i8* %%state, i64 %%31, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_213_count);
  llvm_cbe_tmp__65 = ( char *)(&llvm_cbe_state[(((signed long long )llvm_cbe_tmp__64))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__64));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = load i8* %%32, align 1, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_214_count);
  llvm_cbe_tmp__66 = (unsigned char )*llvm_cbe_tmp__65;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__66);
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = zext i8 %%33 to i64, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_215_count);
  llvm_cbe_tmp__67 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_tmp__66&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__67);
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = shl nuw nsw i64 %%34, 32, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_216_count);
  llvm_cbe_tmp__68 = (unsigned long long )llvm_cbe_tmp__67 << 32ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__68);
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = or i64 %%35, %%29, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_217_count);
  llvm_cbe_tmp__69 = (unsigned long long )llvm_cbe_tmp__68 | llvm_cbe_tmp__62;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__69);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%36, i64* %%3, align 8, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_218_count);
  *llvm_cbe_tmp__36 = llvm_cbe_tmp__69;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__69);
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = or i32 %%4, 5, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_224_count);
  llvm_cbe_tmp__70 = (unsigned int )llvm_cbe_tmp__37 | 5u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__70);
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = zext i32 %%37 to i64, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_225_count);
  llvm_cbe_tmp__71 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__70&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__71);
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = getelementptr inbounds i8* %%state, i64 %%38, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_226_count);
  llvm_cbe_tmp__72 = ( char *)(&llvm_cbe_state[(((signed long long )llvm_cbe_tmp__71))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__71));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = load i8* %%39, align 1, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_227_count);
  llvm_cbe_tmp__73 = (unsigned char )*llvm_cbe_tmp__72;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__73);
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = zext i8 %%40 to i64, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_228_count);
  llvm_cbe_tmp__74 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_tmp__73&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__74);
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = shl nuw nsw i64 %%41, 40, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_229_count);
  llvm_cbe_tmp__75 = (unsigned long long )llvm_cbe_tmp__74 << 40ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__75);
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = or i64 %%42, %%36, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_230_count);
  llvm_cbe_tmp__76 = (unsigned long long )llvm_cbe_tmp__75 | llvm_cbe_tmp__69;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__76);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%43, i64* %%3, align 8, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_231_count);
  *llvm_cbe_tmp__36 = llvm_cbe_tmp__76;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__76);
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = or i32 %%4, 6, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_237_count);
  llvm_cbe_tmp__77 = (unsigned int )llvm_cbe_tmp__37 | 6u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__77);
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = zext i32 %%44 to i64, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_238_count);
  llvm_cbe_tmp__78 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__77&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__78);
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = getelementptr inbounds i8* %%state, i64 %%45, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_239_count);
  llvm_cbe_tmp__79 = ( char *)(&llvm_cbe_state[(((signed long long )llvm_cbe_tmp__78))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__78));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = load i8* %%46, align 1, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_240_count);
  llvm_cbe_tmp__80 = (unsigned char )*llvm_cbe_tmp__79;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__80);
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = zext i8 %%47 to i64, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_241_count);
  llvm_cbe_tmp__81 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_tmp__80&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__81);
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = shl nuw nsw i64 %%48, 48, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_242_count);
  llvm_cbe_tmp__82 = (unsigned long long )llvm_cbe_tmp__81 << 48ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__82);
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = or i64 %%49, %%43, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_243_count);
  llvm_cbe_tmp__83 = (unsigned long long )llvm_cbe_tmp__82 | llvm_cbe_tmp__76;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__83);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%50, i64* %%3, align 8, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_244_count);
  *llvm_cbe_tmp__36 = llvm_cbe_tmp__83;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__83);
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = or i32 %%4, 7, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_250_count);
  llvm_cbe_tmp__84 = (unsigned int )llvm_cbe_tmp__37 | 7u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__84);
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = zext i32 %%51 to i64, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_251_count);
  llvm_cbe_tmp__85 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__84&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__85);
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = getelementptr inbounds i8* %%state, i64 %%52, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_252_count);
  llvm_cbe_tmp__86 = ( char *)(&llvm_cbe_state[(((signed long long )llvm_cbe_tmp__85))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__85));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = load i8* %%53, align 1, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_253_count);
  llvm_cbe_tmp__87 = (unsigned char )*llvm_cbe_tmp__86;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__87);
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = zext i8 %%54 to i64, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_254_count);
  llvm_cbe_tmp__88 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_tmp__87&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__88);
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = shl nuw i64 %%55, 56, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_255_count);
  llvm_cbe_tmp__89 = (unsigned long long )llvm_cbe_tmp__88 << 56ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__89);
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = or i64 %%56, %%50, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_256_count);
  llvm_cbe_tmp__90 = (unsigned long long )llvm_cbe_tmp__89 | llvm_cbe_tmp__83;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__90);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%57, i64* %%3, align 8, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_257_count);
  *llvm_cbe_tmp__36 = llvm_cbe_tmp__90;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__90);
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = add i32 %%storemerge3, 1, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromBytesToWords  --> \n", ++aesl_llvm_cbe_263_count);
  llvm_cbe_tmp__91 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__91&4294967295ull)));
  if (((llvm_cbe_tmp__91&4294967295U) == (25u&4294967295U))) {
    goto llvm_cbe_tmp__93;
  } else {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__91;   /* for PHI node */
    goto llvm_cbe_tmp__92;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__93:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @aesl_internal_fromBytesToWords}\n");
  return;
}


static void aesl_internal_fromWordsToBytes( char *llvm_cbe_state, signed long long *llvm_cbe_stateAsWords) {
  static  unsigned long long aesl_llvm_cbe_272_count = 0;
  static  unsigned long long aesl_llvm_cbe_273_count = 0;
  static  unsigned long long aesl_llvm_cbe_274_count = 0;
  static  unsigned long long aesl_llvm_cbe_275_count = 0;
  static  unsigned long long aesl_llvm_cbe_276_count = 0;
  static  unsigned long long aesl_llvm_cbe_277_count = 0;
  static  unsigned long long aesl_llvm_cbe_278_count = 0;
  static  unsigned long long aesl_llvm_cbe_279_count = 0;
  static  unsigned long long aesl_llvm_cbe_280_count = 0;
  static  unsigned long long aesl_llvm_cbe_281_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned int llvm_cbe_storemerge3;
  unsigned int llvm_cbe_storemerge3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_282_count = 0;
  static  unsigned long long aesl_llvm_cbe_283_count = 0;
  static  unsigned long long aesl_llvm_cbe_284_count = 0;
  static  unsigned long long aesl_llvm_cbe_285_count = 0;
  static  unsigned long long aesl_llvm_cbe_286_count = 0;
  unsigned long long llvm_cbe_tmp__94;
  static  unsigned long long aesl_llvm_cbe_287_count = 0;
  signed long long *llvm_cbe_tmp__95;
  static  unsigned long long aesl_llvm_cbe_288_count = 0;
  unsigned int llvm_cbe_tmp__96;
  static  unsigned long long aesl_llvm_cbe_289_count = 0;
  unsigned long long llvm_cbe_tmp__97;
  static  unsigned long long aesl_llvm_cbe_290_count = 0;
  unsigned char llvm_cbe_tmp__98;
  static  unsigned long long aesl_llvm_cbe_291_count = 0;
  unsigned long long llvm_cbe_tmp__99;
  static  unsigned long long aesl_llvm_cbe_292_count = 0;
   char *llvm_cbe_tmp__100;
  static  unsigned long long aesl_llvm_cbe_293_count = 0;
  static  unsigned long long aesl_llvm_cbe_294_count = 0;
  static  unsigned long long aesl_llvm_cbe_295_count = 0;
  static  unsigned long long aesl_llvm_cbe_296_count = 0;
  static  unsigned long long aesl_llvm_cbe_297_count = 0;
  static  unsigned long long aesl_llvm_cbe_298_count = 0;
  static  unsigned long long aesl_llvm_cbe_299_count = 0;
  unsigned long long llvm_cbe_tmp__101;
  static  unsigned long long aesl_llvm_cbe_300_count = 0;
  unsigned long long llvm_cbe_tmp__102;
  static  unsigned long long aesl_llvm_cbe_301_count = 0;
  unsigned char llvm_cbe_tmp__103;
  static  unsigned long long aesl_llvm_cbe_302_count = 0;
  unsigned int llvm_cbe_tmp__104;
  static  unsigned long long aesl_llvm_cbe_303_count = 0;
  unsigned long long llvm_cbe_tmp__105;
  static  unsigned long long aesl_llvm_cbe_304_count = 0;
   char *llvm_cbe_tmp__106;
  static  unsigned long long aesl_llvm_cbe_305_count = 0;
  static  unsigned long long aesl_llvm_cbe_306_count = 0;
  static  unsigned long long aesl_llvm_cbe_307_count = 0;
  static  unsigned long long aesl_llvm_cbe_308_count = 0;
  static  unsigned long long aesl_llvm_cbe_309_count = 0;
  static  unsigned long long aesl_llvm_cbe_310_count = 0;
  static  unsigned long long aesl_llvm_cbe_311_count = 0;
  unsigned long long llvm_cbe_tmp__107;
  static  unsigned long long aesl_llvm_cbe_312_count = 0;
  unsigned long long llvm_cbe_tmp__108;
  static  unsigned long long aesl_llvm_cbe_313_count = 0;
  unsigned char llvm_cbe_tmp__109;
  static  unsigned long long aesl_llvm_cbe_314_count = 0;
  unsigned int llvm_cbe_tmp__110;
  static  unsigned long long aesl_llvm_cbe_315_count = 0;
  unsigned long long llvm_cbe_tmp__111;
  static  unsigned long long aesl_llvm_cbe_316_count = 0;
   char *llvm_cbe_tmp__112;
  static  unsigned long long aesl_llvm_cbe_317_count = 0;
  static  unsigned long long aesl_llvm_cbe_318_count = 0;
  static  unsigned long long aesl_llvm_cbe_319_count = 0;
  static  unsigned long long aesl_llvm_cbe_320_count = 0;
  static  unsigned long long aesl_llvm_cbe_321_count = 0;
  static  unsigned long long aesl_llvm_cbe_322_count = 0;
  static  unsigned long long aesl_llvm_cbe_323_count = 0;
  unsigned long long llvm_cbe_tmp__113;
  static  unsigned long long aesl_llvm_cbe_324_count = 0;
  unsigned long long llvm_cbe_tmp__114;
  static  unsigned long long aesl_llvm_cbe_325_count = 0;
  unsigned char llvm_cbe_tmp__115;
  static  unsigned long long aesl_llvm_cbe_326_count = 0;
  unsigned int llvm_cbe_tmp__116;
  static  unsigned long long aesl_llvm_cbe_327_count = 0;
  unsigned long long llvm_cbe_tmp__117;
  static  unsigned long long aesl_llvm_cbe_328_count = 0;
   char *llvm_cbe_tmp__118;
  static  unsigned long long aesl_llvm_cbe_329_count = 0;
  static  unsigned long long aesl_llvm_cbe_330_count = 0;
  static  unsigned long long aesl_llvm_cbe_331_count = 0;
  static  unsigned long long aesl_llvm_cbe_332_count = 0;
  static  unsigned long long aesl_llvm_cbe_333_count = 0;
  static  unsigned long long aesl_llvm_cbe_334_count = 0;
  static  unsigned long long aesl_llvm_cbe_335_count = 0;
  unsigned long long llvm_cbe_tmp__119;
  static  unsigned long long aesl_llvm_cbe_336_count = 0;
  unsigned long long llvm_cbe_tmp__120;
  static  unsigned long long aesl_llvm_cbe_337_count = 0;
  unsigned char llvm_cbe_tmp__121;
  static  unsigned long long aesl_llvm_cbe_338_count = 0;
  unsigned int llvm_cbe_tmp__122;
  static  unsigned long long aesl_llvm_cbe_339_count = 0;
  unsigned long long llvm_cbe_tmp__123;
  static  unsigned long long aesl_llvm_cbe_340_count = 0;
   char *llvm_cbe_tmp__124;
  static  unsigned long long aesl_llvm_cbe_341_count = 0;
  static  unsigned long long aesl_llvm_cbe_342_count = 0;
  static  unsigned long long aesl_llvm_cbe_343_count = 0;
  static  unsigned long long aesl_llvm_cbe_344_count = 0;
  static  unsigned long long aesl_llvm_cbe_345_count = 0;
  static  unsigned long long aesl_llvm_cbe_346_count = 0;
  static  unsigned long long aesl_llvm_cbe_347_count = 0;
  unsigned long long llvm_cbe_tmp__125;
  static  unsigned long long aesl_llvm_cbe_348_count = 0;
  unsigned long long llvm_cbe_tmp__126;
  static  unsigned long long aesl_llvm_cbe_349_count = 0;
  unsigned char llvm_cbe_tmp__127;
  static  unsigned long long aesl_llvm_cbe_350_count = 0;
  unsigned int llvm_cbe_tmp__128;
  static  unsigned long long aesl_llvm_cbe_351_count = 0;
  unsigned long long llvm_cbe_tmp__129;
  static  unsigned long long aesl_llvm_cbe_352_count = 0;
   char *llvm_cbe_tmp__130;
  static  unsigned long long aesl_llvm_cbe_353_count = 0;
  static  unsigned long long aesl_llvm_cbe_354_count = 0;
  static  unsigned long long aesl_llvm_cbe_355_count = 0;
  static  unsigned long long aesl_llvm_cbe_356_count = 0;
  static  unsigned long long aesl_llvm_cbe_357_count = 0;
  static  unsigned long long aesl_llvm_cbe_358_count = 0;
  static  unsigned long long aesl_llvm_cbe_359_count = 0;
  unsigned long long llvm_cbe_tmp__131;
  static  unsigned long long aesl_llvm_cbe_360_count = 0;
  unsigned long long llvm_cbe_tmp__132;
  static  unsigned long long aesl_llvm_cbe_361_count = 0;
  unsigned char llvm_cbe_tmp__133;
  static  unsigned long long aesl_llvm_cbe_362_count = 0;
  unsigned int llvm_cbe_tmp__134;
  static  unsigned long long aesl_llvm_cbe_363_count = 0;
  unsigned long long llvm_cbe_tmp__135;
  static  unsigned long long aesl_llvm_cbe_364_count = 0;
   char *llvm_cbe_tmp__136;
  static  unsigned long long aesl_llvm_cbe_365_count = 0;
  static  unsigned long long aesl_llvm_cbe_366_count = 0;
  static  unsigned long long aesl_llvm_cbe_367_count = 0;
  static  unsigned long long aesl_llvm_cbe_368_count = 0;
  static  unsigned long long aesl_llvm_cbe_369_count = 0;
  static  unsigned long long aesl_llvm_cbe_370_count = 0;
  static  unsigned long long aesl_llvm_cbe_371_count = 0;
  unsigned long long llvm_cbe_tmp__137;
  static  unsigned long long aesl_llvm_cbe_372_count = 0;
  unsigned long long llvm_cbe_tmp__138;
  static  unsigned long long aesl_llvm_cbe_373_count = 0;
  unsigned char llvm_cbe_tmp__139;
  static  unsigned long long aesl_llvm_cbe_374_count = 0;
  unsigned int llvm_cbe_tmp__140;
  static  unsigned long long aesl_llvm_cbe_375_count = 0;
  unsigned long long llvm_cbe_tmp__141;
  static  unsigned long long aesl_llvm_cbe_376_count = 0;
   char *llvm_cbe_tmp__142;
  static  unsigned long long aesl_llvm_cbe_377_count = 0;
  static  unsigned long long aesl_llvm_cbe_378_count = 0;
  static  unsigned long long aesl_llvm_cbe_379_count = 0;
  static  unsigned long long aesl_llvm_cbe_380_count = 0;
  static  unsigned long long aesl_llvm_cbe_381_count = 0;
  static  unsigned long long aesl_llvm_cbe_382_count = 0;
  static  unsigned long long aesl_llvm_cbe_383_count = 0;
  unsigned int llvm_cbe_tmp__143;
  static  unsigned long long aesl_llvm_cbe_384_count = 0;
  static  unsigned long long aesl_llvm_cbe_385_count = 0;
  static  unsigned long long aesl_llvm_cbe_386_count = 0;
  static  unsigned long long aesl_llvm_cbe_387_count = 0;
  static  unsigned long long aesl_llvm_cbe_388_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_389_count = 0;
  static  unsigned long long aesl_llvm_cbe_390_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @aesl_internal_fromWordsToBytes\n");
  llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_preheader;

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = phi i32 [ 0, %%0 ], [ %%50, %%.preheader  for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned int )llvm_cbe_storemerge3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%X",llvm_cbe_storemerge3);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__143);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = zext i32 %%storemerge3 to i64, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_286_count);
  llvm_cbe_tmp__94 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge3&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__94);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds i64* %%stateAsWords, i64 %%1, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_287_count);
  llvm_cbe_tmp__95 = (signed long long *)(&llvm_cbe_stateAsWords[(((signed long long )llvm_cbe_tmp__94))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__94));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = shl i32 %%storemerge3, 3, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_288_count);
  llvm_cbe_tmp__96 = (unsigned int )llvm_cbe_storemerge3 << 3u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__96);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i64* %%2, align 8, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_289_count);
  llvm_cbe_tmp__97 = (unsigned long long )*llvm_cbe_tmp__95;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__97);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = trunc i64 %%4 to i8, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_290_count);
  llvm_cbe_tmp__98 = (unsigned char )((unsigned char )llvm_cbe_tmp__97&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__98);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = zext i32 %%3 to i64, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_291_count);
  llvm_cbe_tmp__99 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__96&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__99);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds i8* %%state, i64 %%6, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_292_count);
  llvm_cbe_tmp__100 = ( char *)(&llvm_cbe_state[(((signed long long )llvm_cbe_tmp__99))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__99));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%5, i8* %%7, align 1, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_293_count);
  *llvm_cbe_tmp__100 = llvm_cbe_tmp__98;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__98);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load i64* %%2, align 8, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_299_count);
  llvm_cbe_tmp__101 = (unsigned long long )*llvm_cbe_tmp__95;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__101);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = lshr i64 %%8, 8, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_300_count);
  llvm_cbe_tmp__102 = (unsigned long long )((unsigned long long )(((unsigned long long )(llvm_cbe_tmp__101&18446744073709551615ull)) >> ((unsigned long long )(8ull&18446744073709551615ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__102&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = trunc i64 %%9 to i8, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_301_count);
  llvm_cbe_tmp__103 = (unsigned char )((unsigned char )llvm_cbe_tmp__102&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__103);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = or i32 %%3, 1, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_302_count);
  llvm_cbe_tmp__104 = (unsigned int )llvm_cbe_tmp__96 | 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__104);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = zext i32 %%11 to i64, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_303_count);
  llvm_cbe_tmp__105 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__104&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__105);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds i8* %%state, i64 %%12, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_304_count);
  llvm_cbe_tmp__106 = ( char *)(&llvm_cbe_state[(((signed long long )llvm_cbe_tmp__105))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__105));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%10, i8* %%13, align 1, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_305_count);
  *llvm_cbe_tmp__106 = llvm_cbe_tmp__103;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__103);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load i64* %%2, align 8, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_311_count);
  llvm_cbe_tmp__107 = (unsigned long long )*llvm_cbe_tmp__95;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__107);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = lshr i64 %%14, 16, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_312_count);
  llvm_cbe_tmp__108 = (unsigned long long )((unsigned long long )(((unsigned long long )(llvm_cbe_tmp__107&18446744073709551615ull)) >> ((unsigned long long )(16ull&18446744073709551615ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__108&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = trunc i64 %%15 to i8, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_313_count);
  llvm_cbe_tmp__109 = (unsigned char )((unsigned char )llvm_cbe_tmp__108&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__109);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = or i32 %%3, 2, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_314_count);
  llvm_cbe_tmp__110 = (unsigned int )llvm_cbe_tmp__96 | 2u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__110);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = zext i32 %%17 to i64, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_315_count);
  llvm_cbe_tmp__111 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__110&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__111);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = getelementptr inbounds i8* %%state, i64 %%18, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_316_count);
  llvm_cbe_tmp__112 = ( char *)(&llvm_cbe_state[(((signed long long )llvm_cbe_tmp__111))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__111));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%16, i8* %%19, align 1, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_317_count);
  *llvm_cbe_tmp__112 = llvm_cbe_tmp__109;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__109);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = load i64* %%2, align 8, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_323_count);
  llvm_cbe_tmp__113 = (unsigned long long )*llvm_cbe_tmp__95;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__113);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = lshr i64 %%20, 24, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_324_count);
  llvm_cbe_tmp__114 = (unsigned long long )((unsigned long long )(((unsigned long long )(llvm_cbe_tmp__113&18446744073709551615ull)) >> ((unsigned long long )(24ull&18446744073709551615ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__114&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = trunc i64 %%21 to i8, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_325_count);
  llvm_cbe_tmp__115 = (unsigned char )((unsigned char )llvm_cbe_tmp__114&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__115);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = or i32 %%3, 3, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_326_count);
  llvm_cbe_tmp__116 = (unsigned int )llvm_cbe_tmp__96 | 3u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__116);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = zext i32 %%23 to i64, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_327_count);
  llvm_cbe_tmp__117 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__116&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__117);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = getelementptr inbounds i8* %%state, i64 %%24, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_328_count);
  llvm_cbe_tmp__118 = ( char *)(&llvm_cbe_state[(((signed long long )llvm_cbe_tmp__117))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__117));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%22, i8* %%25, align 1, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_329_count);
  *llvm_cbe_tmp__118 = llvm_cbe_tmp__115;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__115);
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = load i64* %%2, align 8, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_335_count);
  llvm_cbe_tmp__119 = (unsigned long long )*llvm_cbe_tmp__95;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__119);
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = lshr i64 %%26, 32, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_336_count);
  llvm_cbe_tmp__120 = (unsigned long long )((unsigned long long )(((unsigned long long )(llvm_cbe_tmp__119&18446744073709551615ull)) >> ((unsigned long long )(32ull&18446744073709551615ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__120&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = trunc i64 %%27 to i8, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_337_count);
  llvm_cbe_tmp__121 = (unsigned char )((unsigned char )llvm_cbe_tmp__120&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__121);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = or i32 %%3, 4, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_338_count);
  llvm_cbe_tmp__122 = (unsigned int )llvm_cbe_tmp__96 | 4u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__122);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = zext i32 %%29 to i64, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_339_count);
  llvm_cbe_tmp__123 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__122&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__123);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = getelementptr inbounds i8* %%state, i64 %%30, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_340_count);
  llvm_cbe_tmp__124 = ( char *)(&llvm_cbe_state[(((signed long long )llvm_cbe_tmp__123))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__123));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%28, i8* %%31, align 1, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_341_count);
  *llvm_cbe_tmp__124 = llvm_cbe_tmp__121;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__121);
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = load i64* %%2, align 8, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_347_count);
  llvm_cbe_tmp__125 = (unsigned long long )*llvm_cbe_tmp__95;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__125);
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = lshr i64 %%32, 40, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_348_count);
  llvm_cbe_tmp__126 = (unsigned long long )((unsigned long long )(((unsigned long long )(llvm_cbe_tmp__125&18446744073709551615ull)) >> ((unsigned long long )(40ull&18446744073709551615ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__126&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = trunc i64 %%33 to i8, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_349_count);
  llvm_cbe_tmp__127 = (unsigned char )((unsigned char )llvm_cbe_tmp__126&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__127);
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = or i32 %%3, 5, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_350_count);
  llvm_cbe_tmp__128 = (unsigned int )llvm_cbe_tmp__96 | 5u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__128);
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = zext i32 %%35 to i64, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_351_count);
  llvm_cbe_tmp__129 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__128&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__129);
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = getelementptr inbounds i8* %%state, i64 %%36, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_352_count);
  llvm_cbe_tmp__130 = ( char *)(&llvm_cbe_state[(((signed long long )llvm_cbe_tmp__129))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__129));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%34, i8* %%37, align 1, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_353_count);
  *llvm_cbe_tmp__130 = llvm_cbe_tmp__127;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__127);
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = load i64* %%2, align 8, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_359_count);
  llvm_cbe_tmp__131 = (unsigned long long )*llvm_cbe_tmp__95;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__131);
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = lshr i64 %%38, 48, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_360_count);
  llvm_cbe_tmp__132 = (unsigned long long )((unsigned long long )(((unsigned long long )(llvm_cbe_tmp__131&18446744073709551615ull)) >> ((unsigned long long )(48ull&18446744073709551615ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__132&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = trunc i64 %%39 to i8, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_361_count);
  llvm_cbe_tmp__133 = (unsigned char )((unsigned char )llvm_cbe_tmp__132&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__133);
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = or i32 %%3, 6, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_362_count);
  llvm_cbe_tmp__134 = (unsigned int )llvm_cbe_tmp__96 | 6u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__134);
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = zext i32 %%41 to i64, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_363_count);
  llvm_cbe_tmp__135 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__134&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__135);
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = getelementptr inbounds i8* %%state, i64 %%42, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_364_count);
  llvm_cbe_tmp__136 = ( char *)(&llvm_cbe_state[(((signed long long )llvm_cbe_tmp__135))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__135));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%40, i8* %%43, align 1, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_365_count);
  *llvm_cbe_tmp__136 = llvm_cbe_tmp__133;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__133);
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = load i64* %%2, align 8, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_371_count);
  llvm_cbe_tmp__137 = (unsigned long long )*llvm_cbe_tmp__95;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__137);
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = lshr i64 %%44, 56, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_372_count);
  llvm_cbe_tmp__138 = (unsigned long long )((unsigned long long )(((unsigned long long )(llvm_cbe_tmp__137&18446744073709551615ull)) >> ((unsigned long long )(56ull&18446744073709551615ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__138&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = trunc i64 %%45 to i8, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_373_count);
  llvm_cbe_tmp__139 = (unsigned char )((unsigned char )llvm_cbe_tmp__138&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__139);
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = or i32 %%3, 7, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_374_count);
  llvm_cbe_tmp__140 = (unsigned int )llvm_cbe_tmp__96 | 7u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__140);
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = zext i32 %%47 to i64, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_375_count);
  llvm_cbe_tmp__141 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__140&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__141);
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = getelementptr inbounds i8* %%state, i64 %%48, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_376_count);
  llvm_cbe_tmp__142 = ( char *)(&llvm_cbe_state[(((signed long long )llvm_cbe_tmp__141))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__141));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%46, i8* %%49, align 1, !dbg !15 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_377_count);
  *llvm_cbe_tmp__142 = llvm_cbe_tmp__139;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__139);
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = add i32 %%storemerge3, 1, !dbg !16 for 0x%I64xth hint within @aesl_internal_fromWordsToBytes  --> \n", ++aesl_llvm_cbe_383_count);
  llvm_cbe_tmp__143 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__143&4294967295ull)));
  if (((llvm_cbe_tmp__143&4294967295U) == (25u&4294967295U))) {
    goto llvm_cbe_tmp__144;
  } else {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__143;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe_tmp__144:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @aesl_internal_fromWordsToBytes}\n");
  return;
}


void KeccakP1600Round(signed long long *llvm_cbe_state, signed int llvm_cbe_indexRound) {
  static  unsigned long long aesl_llvm_cbe_391_count = 0;
  static  unsigned long long aesl_llvm_cbe_392_count = 0;
  static  unsigned long long aesl_llvm_cbe_393_count = 0;
  static  unsigned long long aesl_llvm_cbe_394_count = 0;
  static  unsigned long long aesl_llvm_cbe_395_count = 0;
  static  unsigned long long aesl_llvm_cbe_396_count = 0;
  static  unsigned long long aesl_llvm_cbe_397_count = 0;
  static  unsigned long long aesl_llvm_cbe_398_count = 0;
  static  unsigned long long aesl_llvm_cbe_399_count = 0;
  static  unsigned long long aesl_llvm_cbe_400_count = 0;
  static  unsigned long long aesl_llvm_cbe_401_count = 0;
  static  unsigned long long aesl_llvm_cbe_402_count = 0;
  static  unsigned long long aesl_llvm_cbe_403_count = 0;
  static  unsigned long long aesl_llvm_cbe_404_count = 0;
const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @KeccakP1600Round\n");
if (AESL_DEBUG_TRACE)
printf("\n  tail call fastcc void @aesl_internal_theta(i64* %%state), !dbg !15 for 0x%I64xth hint within @KeccakP1600Round  --> \n", ++aesl_llvm_cbe_399_count);
   /*tail*/ aesl_internal_theta((signed long long *)llvm_cbe_state);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call fastcc void @aesl_internal_rho(i64* %%state), !dbg !16 for 0x%I64xth hint within @KeccakP1600Round  --> \n", ++aesl_llvm_cbe_400_count);
   /*tail*/ aesl_internal_rho((signed long long *)llvm_cbe_state);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call fastcc void @aesl_internal_pi(i64* %%state), !dbg !16 for 0x%I64xth hint within @KeccakP1600Round  --> \n", ++aesl_llvm_cbe_401_count);
   /*tail*/ aesl_internal_pi((signed long long *)llvm_cbe_state);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call fastcc void @aesl_internal_chi(i64* %%state), !dbg !16 for 0x%I64xth hint within @KeccakP1600Round  --> \n", ++aesl_llvm_cbe_402_count);
   /*tail*/ aesl_internal_chi((signed long long *)llvm_cbe_state);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call fastcc void @aesl_internal_iota(i64* %%state, i32 %%indexRound), !dbg !16 for 0x%I64xth hint within @KeccakP1600Round  --> \n", ++aesl_llvm_cbe_403_count);
   /*tail*/ aesl_internal_iota((signed long long *)llvm_cbe_state, llvm_cbe_indexRound);
if (AESL_DEBUG_TRACE) {
printf("\nArgument indexRound = 0x%X",llvm_cbe_indexRound);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @KeccakP1600Round}\n");
  return;
}


static void aesl_internal_theta(signed long long *llvm_cbe_A) {
  static  unsigned long long aesl_llvm_cbe_C_count = 0;
  signed long long llvm_cbe_C[5];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_D_count = 0;
  signed long long llvm_cbe_D[5];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_405_count = 0;
  static  unsigned long long aesl_llvm_cbe_406_count = 0;
  static  unsigned long long aesl_llvm_cbe_407_count = 0;
  static  unsigned long long aesl_llvm_cbe_408_count = 0;
  static  unsigned long long aesl_llvm_cbe_409_count = 0;
  static  unsigned long long aesl_llvm_cbe_410_count = 0;
  static  unsigned long long aesl_llvm_cbe_411_count = 0;
  static  unsigned long long aesl_llvm_cbe_412_count = 0;
  static  unsigned long long aesl_llvm_cbe_413_count = 0;
  static  unsigned long long aesl_llvm_cbe_414_count = 0;
  static  unsigned long long aesl_llvm_cbe_415_count = 0;
  static  unsigned long long aesl_llvm_cbe_416_count = 0;
  static  unsigned long long aesl_llvm_cbe_417_count = 0;
  static  unsigned long long aesl_llvm_cbe_418_count = 0;
  static  unsigned long long aesl_llvm_cbe_419_count = 0;
  static  unsigned long long aesl_llvm_cbe_420_count = 0;
  static  unsigned long long aesl_llvm_cbe_421_count = 0;
  static  unsigned long long aesl_llvm_cbe_422_count = 0;
  static  unsigned long long aesl_llvm_cbe_423_count = 0;
  static  unsigned long long aesl_llvm_cbe_424_count = 0;
  static  unsigned long long aesl_llvm_cbe_425_count = 0;
  static  unsigned long long aesl_llvm_cbe_426_count = 0;
  static  unsigned long long aesl_llvm_cbe_427_count = 0;
  static  unsigned long long aesl_llvm_cbe_428_count = 0;
  static  unsigned long long aesl_llvm_cbe_429_count = 0;
  static  unsigned long long aesl_llvm_cbe_430_count = 0;
  static  unsigned long long aesl_llvm_cbe_431_count = 0;
  static  unsigned long long aesl_llvm_cbe_432_count = 0;
  static  unsigned long long aesl_llvm_cbe_433_count = 0;
  static  unsigned long long aesl_llvm_cbe_434_count = 0;
  static  unsigned long long aesl_llvm_cbe_435_count = 0;
  static  unsigned long long aesl_llvm_cbe_436_count = 0;
  static  unsigned long long aesl_llvm_cbe_437_count = 0;
  static  unsigned long long aesl_llvm_cbe_438_count = 0;
  static  unsigned long long aesl_llvm_cbe_439_count = 0;
  static  unsigned long long aesl_llvm_cbe_440_count = 0;
  static  unsigned long long aesl_llvm_cbe_441_count = 0;
  static  unsigned long long aesl_llvm_cbe_442_count = 0;
  signed long long *llvm_cbe_tmp__145;
  static  unsigned long long aesl_llvm_cbe_443_count = 0;
  unsigned long long llvm_cbe_tmp__146;
  static  unsigned long long aesl_llvm_cbe_444_count = 0;
  unsigned long long llvm_cbe_tmp__147;
  static  unsigned long long aesl_llvm_cbe_445_count = 0;
  unsigned long long llvm_cbe_tmp__148;
  static  unsigned long long aesl_llvm_cbe_446_count = 0;
  unsigned long long llvm_cbe_tmp__149;
  static  unsigned long long aesl_llvm_cbe_447_count = 0;
  signed long long *llvm_cbe_tmp__150;
  static  unsigned long long aesl_llvm_cbe_448_count = 0;
  unsigned long long llvm_cbe_tmp__151;
  static  unsigned long long aesl_llvm_cbe_449_count = 0;
  unsigned long long llvm_cbe_tmp__152;
  static  unsigned long long aesl_llvm_cbe_450_count = 0;
  signed long long *llvm_cbe_tmp__153;
  static  unsigned long long aesl_llvm_cbe_451_count = 0;
  static  unsigned long long aesl_llvm_cbe_452_count = 0;
  static  unsigned long long aesl_llvm_cbe_453_count = 0;
  static  unsigned long long aesl_llvm_cbe_454_count = 0;
  static  unsigned long long aesl_llvm_cbe_455_count = 0;
  static  unsigned long long aesl_llvm_cbe_456_count = 0;
  static  unsigned long long aesl_llvm_cbe_457_count = 0;
  static  unsigned long long aesl_llvm_cbe_458_count = 0;
  static  unsigned long long aesl_llvm_cbe_459_count = 0;
  static  unsigned long long aesl_llvm_cbe_460_count = 0;
  static  unsigned long long aesl_llvm_cbe_461_count = 0;
  static  unsigned long long aesl_llvm_cbe_462_count = 0;
  static  unsigned long long aesl_llvm_cbe_463_count = 0;
  static  unsigned long long aesl_llvm_cbe_464_count = 0;
  static  unsigned long long aesl_llvm_cbe_465_count = 0;
  static  unsigned long long aesl_llvm_cbe_466_count = 0;
  static  unsigned long long aesl_llvm_cbe_467_count = 0;
  static  unsigned long long aesl_llvm_cbe_468_count = 0;
  signed long long *llvm_cbe_tmp__154;
  static  unsigned long long aesl_llvm_cbe_469_count = 0;
  unsigned long long llvm_cbe_tmp__155;
  static  unsigned long long aesl_llvm_cbe_470_count = 0;
  unsigned long long llvm_cbe_tmp__156;
  static  unsigned long long aesl_llvm_cbe_471_count = 0;
  unsigned long long llvm_cbe_tmp__157;
  static  unsigned long long aesl_llvm_cbe_472_count = 0;
  unsigned long long llvm_cbe_tmp__158;
  static  unsigned long long aesl_llvm_cbe_473_count = 0;
  signed long long *llvm_cbe_tmp__159;
  static  unsigned long long aesl_llvm_cbe_474_count = 0;
  unsigned long long llvm_cbe_tmp__160;
  static  unsigned long long aesl_llvm_cbe_475_count = 0;
  unsigned long long llvm_cbe_tmp__161;
  static  unsigned long long aesl_llvm_cbe_476_count = 0;
  signed long long *llvm_cbe_tmp__162;
  static  unsigned long long aesl_llvm_cbe_477_count = 0;
  static  unsigned long long aesl_llvm_cbe_478_count = 0;
  static  unsigned long long aesl_llvm_cbe_479_count = 0;
  static  unsigned long long aesl_llvm_cbe_480_count = 0;
  static  unsigned long long aesl_llvm_cbe_481_count = 0;
  static  unsigned long long aesl_llvm_cbe_482_count = 0;
  static  unsigned long long aesl_llvm_cbe_483_count = 0;
  static  unsigned long long aesl_llvm_cbe_484_count = 0;
  static  unsigned long long aesl_llvm_cbe_485_count = 0;
  static  unsigned long long aesl_llvm_cbe_486_count = 0;
  static  unsigned long long aesl_llvm_cbe_487_count = 0;
  static  unsigned long long aesl_llvm_cbe_488_count = 0;
  static  unsigned long long aesl_llvm_cbe_489_count = 0;
  static  unsigned long long aesl_llvm_cbe_490_count = 0;
  static  unsigned long long aesl_llvm_cbe_491_count = 0;
  static  unsigned long long aesl_llvm_cbe_492_count = 0;
  static  unsigned long long aesl_llvm_cbe_493_count = 0;
  static  unsigned long long aesl_llvm_cbe_494_count = 0;
  signed long long *llvm_cbe_tmp__163;
  static  unsigned long long aesl_llvm_cbe_495_count = 0;
  unsigned long long llvm_cbe_tmp__164;
  static  unsigned long long aesl_llvm_cbe_496_count = 0;
  unsigned long long llvm_cbe_tmp__165;
  static  unsigned long long aesl_llvm_cbe_497_count = 0;
  unsigned long long llvm_cbe_tmp__166;
  static  unsigned long long aesl_llvm_cbe_498_count = 0;
  unsigned long long llvm_cbe_tmp__167;
  static  unsigned long long aesl_llvm_cbe_499_count = 0;
  unsigned long long llvm_cbe_tmp__168;
  static  unsigned long long aesl_llvm_cbe_500_count = 0;
  signed long long *llvm_cbe_tmp__169;
  static  unsigned long long aesl_llvm_cbe_501_count = 0;
  static  unsigned long long aesl_llvm_cbe_502_count = 0;
  static  unsigned long long aesl_llvm_cbe_503_count = 0;
  static  unsigned long long aesl_llvm_cbe_504_count = 0;
  static  unsigned long long aesl_llvm_cbe_505_count = 0;
  static  unsigned long long aesl_llvm_cbe_506_count = 0;
  static  unsigned long long aesl_llvm_cbe_507_count = 0;
  static  unsigned long long aesl_llvm_cbe_508_count = 0;
  static  unsigned long long aesl_llvm_cbe_509_count = 0;
  static  unsigned long long aesl_llvm_cbe_510_count = 0;
  static  unsigned long long aesl_llvm_cbe_511_count = 0;
  static  unsigned long long aesl_llvm_cbe_512_count = 0;
  static  unsigned long long aesl_llvm_cbe_513_count = 0;
  static  unsigned long long aesl_llvm_cbe_514_count = 0;
  static  unsigned long long aesl_llvm_cbe_515_count = 0;
  static  unsigned long long aesl_llvm_cbe_516_count = 0;
  static  unsigned long long aesl_llvm_cbe_517_count = 0;
  static  unsigned long long aesl_llvm_cbe_518_count = 0;
  unsigned long long llvm_cbe_tmp__170;
  static  unsigned long long aesl_llvm_cbe_519_count = 0;
  unsigned long long llvm_cbe_tmp__171;
  static  unsigned long long aesl_llvm_cbe_520_count = 0;
  unsigned long long llvm_cbe_tmp__172;
  static  unsigned long long aesl_llvm_cbe_521_count = 0;
  unsigned long long llvm_cbe_tmp__173;
  static  unsigned long long aesl_llvm_cbe_522_count = 0;
  signed long long *llvm_cbe_tmp__174;
  static  unsigned long long aesl_llvm_cbe_523_count = 0;
  static  unsigned long long aesl_llvm_cbe_524_count = 0;
  static  unsigned long long aesl_llvm_cbe_525_count = 0;
  static  unsigned long long aesl_llvm_cbe_526_count = 0;
  static  unsigned long long aesl_llvm_cbe_527_count = 0;
  static  unsigned long long aesl_llvm_cbe_528_count = 0;
  static  unsigned long long aesl_llvm_cbe_529_count = 0;
  static  unsigned long long aesl_llvm_cbe_530_count = 0;
  static  unsigned long long aesl_llvm_cbe_531_count = 0;
  static  unsigned long long aesl_llvm_cbe_532_count = 0;
  static  unsigned long long aesl_llvm_cbe_533_count = 0;
  static  unsigned long long aesl_llvm_cbe_534_count = 0;
  static  unsigned long long aesl_llvm_cbe_535_count = 0;
  static  unsigned long long aesl_llvm_cbe_536_count = 0;
  static  unsigned long long aesl_llvm_cbe_537_count = 0;
  static  unsigned long long aesl_llvm_cbe_538_count = 0;
  static  unsigned long long aesl_llvm_cbe_539_count = 0;
  static  unsigned long long aesl_llvm_cbe_540_count = 0;
  unsigned long long llvm_cbe_tmp__175;
  static  unsigned long long aesl_llvm_cbe_541_count = 0;
  unsigned long long llvm_cbe_tmp__176;
  static  unsigned long long aesl_llvm_cbe_542_count = 0;
  unsigned long long llvm_cbe_tmp__177;
  static  unsigned long long aesl_llvm_cbe_543_count = 0;
  unsigned long long llvm_cbe_tmp__178;
  static  unsigned long long aesl_llvm_cbe_544_count = 0;
  signed long long *llvm_cbe_tmp__179;
  static  unsigned long long aesl_llvm_cbe_545_count = 0;
  static  unsigned long long aesl_llvm_cbe_546_count = 0;
  static  unsigned long long aesl_llvm_cbe_547_count = 0;
  static  unsigned long long aesl_llvm_cbe_548_count = 0;
  static  unsigned long long aesl_llvm_cbe_549_count = 0;
  static  unsigned long long aesl_llvm_cbe_550_count = 0;
  static  unsigned long long aesl_llvm_cbe_551_count = 0;
  static  unsigned long long aesl_llvm_cbe_552_count = 0;
  static  unsigned long long aesl_llvm_cbe_553_count = 0;
  static  unsigned long long aesl_llvm_cbe_554_count = 0;
  static  unsigned long long aesl_llvm_cbe_555_count = 0;
  static  unsigned long long aesl_llvm_cbe_556_count = 0;
  static  unsigned long long aesl_llvm_cbe_557_count = 0;
  static  unsigned long long aesl_llvm_cbe_558_count = 0;
  static  unsigned long long aesl_llvm_cbe_559_count = 0;
  static  unsigned long long aesl_llvm_cbe_560_count = 0;
  static  unsigned long long aesl_llvm_cbe_561_count = 0;
  static  unsigned long long aesl_llvm_cbe_562_count = 0;
  static  unsigned long long aesl_llvm_cbe_563_count = 0;
  static  unsigned long long aesl_llvm_cbe_564_count = 0;
  static  unsigned long long aesl_llvm_cbe_565_count = 0;
  static  unsigned long long aesl_llvm_cbe_566_count = 0;
  static  unsigned long long aesl_llvm_cbe_567_count = 0;
  static  unsigned long long aesl_llvm_cbe_568_count = 0;
  static  unsigned long long aesl_llvm_cbe_569_count = 0;
  static  unsigned long long aesl_llvm_cbe_570_count = 0;
  static  unsigned long long aesl_llvm_cbe_571_count = 0;
  static  unsigned long long aesl_llvm_cbe_572_count = 0;
  static  unsigned long long aesl_llvm_cbe_573_count = 0;
  static  unsigned long long aesl_llvm_cbe_574_count = 0;
  static  unsigned long long aesl_llvm_cbe_575_count = 0;
  static  unsigned long long aesl_llvm_cbe_576_count = 0;
  static  unsigned long long aesl_llvm_cbe_577_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge11_count = 0;
  unsigned int llvm_cbe_storemerge11;
  unsigned int llvm_cbe_storemerge11__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_578_count = 0;
  unsigned long long llvm_cbe_tmp__180;
  static  unsigned long long aesl_llvm_cbe_579_count = 0;
  signed long long *llvm_cbe_tmp__181;
  static  unsigned long long aesl_llvm_cbe_580_count = 0;
  static  unsigned long long aesl_llvm_cbe_581_count = 0;
  static  unsigned long long aesl_llvm_cbe_582_count = 0;
  static  unsigned long long aesl_llvm_cbe_583_count = 0;
  static  unsigned long long aesl_llvm_cbe_584_count = 0;
  static  unsigned long long aesl_llvm_cbe_585_count = 0;
  static  unsigned long long aesl_llvm_cbe_586_count = 0;
  static  unsigned long long aesl_llvm_cbe_587_count = 0;
  unsigned int llvm_cbe_tmp__182;
  static  unsigned long long aesl_llvm_cbe_588_count = 0;
  unsigned long long llvm_cbe_tmp__183;
  static  unsigned long long aesl_llvm_cbe_589_count = 0;
  signed long long *llvm_cbe_tmp__184;
  static  unsigned long long aesl_llvm_cbe_590_count = 0;
  unsigned long long llvm_cbe_tmp__185;
  static  unsigned long long aesl_llvm_cbe_591_count = 0;
  static  unsigned long long aesl_llvm_cbe_592_count = 0;
  static  unsigned long long aesl_llvm_cbe_593_count = 0;
  static  unsigned long long aesl_llvm_cbe_594_count = 0;
  static  unsigned long long aesl_llvm_cbe_595_count = 0;
  static  unsigned long long aesl_llvm_cbe_596_count = 0;
  static  unsigned long long aesl_llvm_cbe_597_count = 0;
  static  unsigned long long aesl_llvm_cbe_598_count = 0;
  unsigned int llvm_cbe_tmp__186;
  static  unsigned long long aesl_llvm_cbe_599_count = 0;
  unsigned long long llvm_cbe_tmp__187;
  static  unsigned long long aesl_llvm_cbe_600_count = 0;
  signed long long *llvm_cbe_tmp__188;
  static  unsigned long long aesl_llvm_cbe_601_count = 0;
  unsigned long long llvm_cbe_tmp__189;
  static  unsigned long long aesl_llvm_cbe_602_count = 0;
  unsigned long long llvm_cbe_tmp__190;
  static  unsigned long long aesl_llvm_cbe_603_count = 0;
  static  unsigned long long aesl_llvm_cbe_604_count = 0;
  static  unsigned long long aesl_llvm_cbe_605_count = 0;
  static  unsigned long long aesl_llvm_cbe_606_count = 0;
  static  unsigned long long aesl_llvm_cbe_607_count = 0;
  static  unsigned long long aesl_llvm_cbe_608_count = 0;
  static  unsigned long long aesl_llvm_cbe_609_count = 0;
  static  unsigned long long aesl_llvm_cbe_610_count = 0;
  unsigned int llvm_cbe_tmp__191;
  static  unsigned long long aesl_llvm_cbe_611_count = 0;
  unsigned long long llvm_cbe_tmp__192;
  static  unsigned long long aesl_llvm_cbe_612_count = 0;
  signed long long *llvm_cbe_tmp__193;
  static  unsigned long long aesl_llvm_cbe_613_count = 0;
  unsigned long long llvm_cbe_tmp__194;
  static  unsigned long long aesl_llvm_cbe_614_count = 0;
  unsigned long long llvm_cbe_tmp__195;
  static  unsigned long long aesl_llvm_cbe_615_count = 0;
  static  unsigned long long aesl_llvm_cbe_616_count = 0;
  static  unsigned long long aesl_llvm_cbe_617_count = 0;
  static  unsigned long long aesl_llvm_cbe_618_count = 0;
  static  unsigned long long aesl_llvm_cbe_619_count = 0;
  static  unsigned long long aesl_llvm_cbe_620_count = 0;
  static  unsigned long long aesl_llvm_cbe_621_count = 0;
  static  unsigned long long aesl_llvm_cbe_622_count = 0;
  unsigned int llvm_cbe_tmp__196;
  static  unsigned long long aesl_llvm_cbe_623_count = 0;
  unsigned long long llvm_cbe_tmp__197;
  static  unsigned long long aesl_llvm_cbe_624_count = 0;
  signed long long *llvm_cbe_tmp__198;
  static  unsigned long long aesl_llvm_cbe_625_count = 0;
  unsigned long long llvm_cbe_tmp__199;
  static  unsigned long long aesl_llvm_cbe_626_count = 0;
  unsigned long long llvm_cbe_tmp__200;
  static  unsigned long long aesl_llvm_cbe_627_count = 0;
  static  unsigned long long aesl_llvm_cbe_628_count = 0;
  static  unsigned long long aesl_llvm_cbe_629_count = 0;
  static  unsigned long long aesl_llvm_cbe_630_count = 0;
  static  unsigned long long aesl_llvm_cbe_631_count = 0;
  static  unsigned long long aesl_llvm_cbe_632_count = 0;
  static  unsigned long long aesl_llvm_cbe_633_count = 0;
  static  unsigned long long aesl_llvm_cbe_634_count = 0;
  unsigned int llvm_cbe_tmp__201;
  static  unsigned long long aesl_llvm_cbe_635_count = 0;
  unsigned long long llvm_cbe_tmp__202;
  static  unsigned long long aesl_llvm_cbe_636_count = 0;
  signed long long *llvm_cbe_tmp__203;
  static  unsigned long long aesl_llvm_cbe_637_count = 0;
  unsigned long long llvm_cbe_tmp__204;
  static  unsigned long long aesl_llvm_cbe_638_count = 0;
  unsigned long long llvm_cbe_tmp__205;
  static  unsigned long long aesl_llvm_cbe_639_count = 0;
  static  unsigned long long aesl_llvm_cbe_640_count = 0;
  static  unsigned long long aesl_llvm_cbe_641_count = 0;
  static  unsigned long long aesl_llvm_cbe_642_count = 0;
  static  unsigned long long aesl_llvm_cbe_643_count = 0;
  static  unsigned long long aesl_llvm_cbe_644_count = 0;
  static  unsigned long long aesl_llvm_cbe_645_count = 0;
  static  unsigned long long aesl_llvm_cbe_646_count = 0;
  static  unsigned long long aesl_llvm_cbe_647_count = 0;
  unsigned int llvm_cbe_tmp__206;
  static  unsigned long long aesl_llvm_cbe_648_count = 0;
  static  unsigned long long aesl_llvm_cbe_649_count = 0;
  static  unsigned long long aesl_llvm_cbe_650_count = 0;
  static  unsigned long long aesl_llvm_cbe_651_count = 0;
  static  unsigned long long aesl_llvm_cbe_652_count = 0;
  static  unsigned long long aesl_llvm_cbe_653_count = 0;
  static  unsigned long long aesl_llvm_cbe_654_count = 0;
  static  unsigned long long aesl_llvm_cbe_655_count = 0;
  static  unsigned long long aesl_llvm_cbe_656_count = 0;
  static  unsigned long long aesl_llvm_cbe_657_count = 0;
  static  unsigned long long aesl_llvm_cbe_658_count = 0;
  static  unsigned long long aesl_llvm_cbe_659_count = 0;
  static  unsigned long long aesl_llvm_cbe_660_count = 0;
  static  unsigned long long aesl_llvm_cbe_661_count = 0;
  static  unsigned long long aesl_llvm_cbe_662_count = 0;
  static  unsigned long long aesl_llvm_cbe_663_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond14_count = 0;
  static  unsigned long long aesl_llvm_cbe_664_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge27_count = 0;
  unsigned int llvm_cbe_storemerge27;
  unsigned int llvm_cbe_storemerge27__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_665_count = 0;
  static  unsigned long long aesl_llvm_cbe_666_count = 0;
  static  unsigned long long aesl_llvm_cbe_667_count = 0;
  static  unsigned long long aesl_llvm_cbe_668_count = 0;
  static  unsigned long long aesl_llvm_cbe_669_count = 0;
  static  unsigned long long aesl_llvm_cbe_670_count = 0;
  static  unsigned long long aesl_llvm_cbe_671_count = 0;
  unsigned long long llvm_cbe_tmp__207;
  static  unsigned long long aesl_llvm_cbe_672_count = 0;
  signed long long *llvm_cbe_tmp__208;
  static  unsigned long long aesl_llvm_cbe_673_count = 0;
  unsigned long long llvm_cbe_tmp__209;
  static  unsigned long long aesl_llvm_cbe_674_count = 0;
  unsigned int llvm_cbe_tmp__210;
  static  unsigned long long aesl_llvm_cbe_675_count = 0;
  unsigned long long llvm_cbe_tmp__211;
  static  unsigned long long aesl_llvm_cbe_676_count = 0;
  signed long long *llvm_cbe_tmp__212;
  static  unsigned long long aesl_llvm_cbe_677_count = 0;
  unsigned long long llvm_cbe_tmp__213;
  static  unsigned long long aesl_llvm_cbe_678_count = 0;
  unsigned long long llvm_cbe_tmp__214;
  static  unsigned long long aesl_llvm_cbe_679_count = 0;
  static  unsigned long long aesl_llvm_cbe_680_count = 0;
  static  unsigned long long aesl_llvm_cbe_681_count = 0;
  static  unsigned long long aesl_llvm_cbe_682_count = 0;
  static  unsigned long long aesl_llvm_cbe_683_count = 0;
  static  unsigned long long aesl_llvm_cbe_684_count = 0;
  static  unsigned long long aesl_llvm_cbe_685_count = 0;
  static  unsigned long long aesl_llvm_cbe_686_count = 0;
  static  unsigned long long aesl_llvm_cbe_687_count = 0;
  unsigned int llvm_cbe_tmp__215;
  static  unsigned long long aesl_llvm_cbe_688_count = 0;
  unsigned long long llvm_cbe_tmp__216;
  static  unsigned long long aesl_llvm_cbe_689_count = 0;
  signed long long *llvm_cbe_tmp__217;
  static  unsigned long long aesl_llvm_cbe_690_count = 0;
  unsigned long long llvm_cbe_tmp__218;
  static  unsigned long long aesl_llvm_cbe_691_count = 0;
  unsigned long long llvm_cbe_tmp__219;
  static  unsigned long long aesl_llvm_cbe_692_count = 0;
  static  unsigned long long aesl_llvm_cbe_693_count = 0;
  static  unsigned long long aesl_llvm_cbe_694_count = 0;
  static  unsigned long long aesl_llvm_cbe_695_count = 0;
  static  unsigned long long aesl_llvm_cbe_696_count = 0;
  static  unsigned long long aesl_llvm_cbe_697_count = 0;
  static  unsigned long long aesl_llvm_cbe_698_count = 0;
  static  unsigned long long aesl_llvm_cbe_699_count = 0;
  static  unsigned long long aesl_llvm_cbe_700_count = 0;
  unsigned int llvm_cbe_tmp__220;
  static  unsigned long long aesl_llvm_cbe_701_count = 0;
  unsigned long long llvm_cbe_tmp__221;
  static  unsigned long long aesl_llvm_cbe_702_count = 0;
  signed long long *llvm_cbe_tmp__222;
  static  unsigned long long aesl_llvm_cbe_703_count = 0;
  unsigned long long llvm_cbe_tmp__223;
  static  unsigned long long aesl_llvm_cbe_704_count = 0;
  unsigned long long llvm_cbe_tmp__224;
  static  unsigned long long aesl_llvm_cbe_705_count = 0;
  static  unsigned long long aesl_llvm_cbe_706_count = 0;
  static  unsigned long long aesl_llvm_cbe_707_count = 0;
  static  unsigned long long aesl_llvm_cbe_708_count = 0;
  static  unsigned long long aesl_llvm_cbe_709_count = 0;
  static  unsigned long long aesl_llvm_cbe_710_count = 0;
  static  unsigned long long aesl_llvm_cbe_711_count = 0;
  static  unsigned long long aesl_llvm_cbe_712_count = 0;
  static  unsigned long long aesl_llvm_cbe_713_count = 0;
  unsigned int llvm_cbe_tmp__225;
  static  unsigned long long aesl_llvm_cbe_714_count = 0;
  unsigned long long llvm_cbe_tmp__226;
  static  unsigned long long aesl_llvm_cbe_715_count = 0;
  signed long long *llvm_cbe_tmp__227;
  static  unsigned long long aesl_llvm_cbe_716_count = 0;
  unsigned long long llvm_cbe_tmp__228;
  static  unsigned long long aesl_llvm_cbe_717_count = 0;
  unsigned long long llvm_cbe_tmp__229;
  static  unsigned long long aesl_llvm_cbe_718_count = 0;
  static  unsigned long long aesl_llvm_cbe_719_count = 0;
  static  unsigned long long aesl_llvm_cbe_720_count = 0;
  static  unsigned long long aesl_llvm_cbe_721_count = 0;
  static  unsigned long long aesl_llvm_cbe_722_count = 0;
  static  unsigned long long aesl_llvm_cbe_723_count = 0;
  static  unsigned long long aesl_llvm_cbe_724_count = 0;
  static  unsigned long long aesl_llvm_cbe_725_count = 0;
  static  unsigned long long aesl_llvm_cbe_726_count = 0;
  unsigned int llvm_cbe_tmp__230;
  static  unsigned long long aesl_llvm_cbe_727_count = 0;
  unsigned long long llvm_cbe_tmp__231;
  static  unsigned long long aesl_llvm_cbe_728_count = 0;
  signed long long *llvm_cbe_tmp__232;
  static  unsigned long long aesl_llvm_cbe_729_count = 0;
  unsigned long long llvm_cbe_tmp__233;
  static  unsigned long long aesl_llvm_cbe_730_count = 0;
  unsigned long long llvm_cbe_tmp__234;
  static  unsigned long long aesl_llvm_cbe_731_count = 0;
  static  unsigned long long aesl_llvm_cbe_732_count = 0;
  static  unsigned long long aesl_llvm_cbe_733_count = 0;
  static  unsigned long long aesl_llvm_cbe_734_count = 0;
  static  unsigned long long aesl_llvm_cbe_735_count = 0;
  static  unsigned long long aesl_llvm_cbe_736_count = 0;
  static  unsigned long long aesl_llvm_cbe_737_count = 0;
  static  unsigned long long aesl_llvm_cbe_738_count = 0;
  static  unsigned long long aesl_llvm_cbe_739_count = 0;
  unsigned int llvm_cbe_tmp__235;
  static  unsigned long long aesl_llvm_cbe_740_count = 0;
  static  unsigned long long aesl_llvm_cbe_741_count = 0;
  static  unsigned long long aesl_llvm_cbe_742_count = 0;
  static  unsigned long long aesl_llvm_cbe_743_count = 0;
  static  unsigned long long aesl_llvm_cbe_744_count = 0;
  static  unsigned long long aesl_llvm_cbe_745_count = 0;
  static  unsigned long long aesl_llvm_cbe_746_count = 0;
  static  unsigned long long aesl_llvm_cbe_747_count = 0;
  static  unsigned long long aesl_llvm_cbe_748_count = 0;
  static  unsigned long long aesl_llvm_cbe_749_count = 0;
  static  unsigned long long aesl_llvm_cbe_750_count = 0;
  static  unsigned long long aesl_llvm_cbe_751_count = 0;
  static  unsigned long long aesl_llvm_cbe_752_count = 0;
  static  unsigned long long aesl_llvm_cbe_753_count = 0;
  static  unsigned long long aesl_llvm_cbe_754_count = 0;
  static  unsigned long long aesl_llvm_cbe_755_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_756_count = 0;
  static  unsigned long long aesl_llvm_cbe_757_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @aesl_internal_theta\n");
  llvm_cbe_storemerge11__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__236;

llvm_cbe__2e_preheader8:
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds [5 x i64]* %%C, i64 0, i64 1, !dbg !17 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_442_count);
  llvm_cbe_tmp__145 = (signed long long *)(&llvm_cbe_C[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )1ull) < 5)) fprintf(stderr, "%s:%d: warning: Read access out of array 'C' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i64* %%1, align 8, !dbg !17 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_443_count);
  llvm_cbe_tmp__146 = (unsigned long long )*llvm_cbe_tmp__145;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__146);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = shl i64 %%2, 1, !dbg !17 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_444_count);
  llvm_cbe_tmp__147 = (unsigned long long )llvm_cbe_tmp__146 << 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__147);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = lshr i64 %%2, 63, !dbg !17 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_445_count);
  llvm_cbe_tmp__148 = (unsigned long long )((unsigned long long )(((unsigned long long )(llvm_cbe_tmp__146&18446744073709551615ull)) >> ((unsigned long long )(63ull&18446744073709551615ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__148&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = or i64 %%3, %%4, !dbg !17 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_446_count);
  llvm_cbe_tmp__149 = (unsigned long long )llvm_cbe_tmp__147 | llvm_cbe_tmp__148;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__149);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds [5 x i64]* %%C, i64 0, i64 4, !dbg !17 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_447_count);
  llvm_cbe_tmp__150 = (signed long long *)(&llvm_cbe_C[(((signed long long )4ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )4ull) < 5)) fprintf(stderr, "%s:%d: warning: Read access out of array 'C' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = load i64* %%6, align 16, !dbg !17 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_448_count);
  llvm_cbe_tmp__151 = (unsigned long long )*llvm_cbe_tmp__150;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__151);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = xor i64 %%5, %%7, !dbg !17 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_449_count);
  llvm_cbe_tmp__152 = (unsigned long long )llvm_cbe_tmp__149 ^ llvm_cbe_tmp__151;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__152);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds [5 x i64]* %%D, i64 0, i64 0, !dbg !17 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_450_count);
  llvm_cbe_tmp__153 = (signed long long *)(&llvm_cbe_D[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )0ull) < 5 && "Write access out of array 'D' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%8, i64* %%9, align 16, !dbg !17 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_451_count);
  *llvm_cbe_tmp__153 = llvm_cbe_tmp__152;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__152);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds [5 x i64]* %%C, i64 0, i64 2, !dbg !17 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_468_count);
  llvm_cbe_tmp__154 = (signed long long *)(&llvm_cbe_C[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )2ull) < 5)) fprintf(stderr, "%s:%d: warning: Read access out of array 'C' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = load i64* %%10, align 16, !dbg !17 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_469_count);
  llvm_cbe_tmp__155 = (unsigned long long )*llvm_cbe_tmp__154;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__155);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = shl i64 %%11, 1, !dbg !17 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_470_count);
  llvm_cbe_tmp__156 = (unsigned long long )llvm_cbe_tmp__155 << 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__156);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = lshr i64 %%11, 63, !dbg !17 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_471_count);
  llvm_cbe_tmp__157 = (unsigned long long )((unsigned long long )(((unsigned long long )(llvm_cbe_tmp__155&18446744073709551615ull)) >> ((unsigned long long )(63ull&18446744073709551615ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__157&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = or i64 %%12, %%13, !dbg !17 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_472_count);
  llvm_cbe_tmp__158 = (unsigned long long )llvm_cbe_tmp__156 | llvm_cbe_tmp__157;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__158);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds [5 x i64]* %%C, i64 0, i64 0, !dbg !17 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_473_count);
  llvm_cbe_tmp__159 = (signed long long *)(&llvm_cbe_C[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )0ull) < 5)) fprintf(stderr, "%s:%d: warning: Read access out of array 'C' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = load i64* %%15, align 16, !dbg !17 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_474_count);
  llvm_cbe_tmp__160 = (unsigned long long )*llvm_cbe_tmp__159;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__160);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = xor i64 %%14, %%16, !dbg !17 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_475_count);
  llvm_cbe_tmp__161 = (unsigned long long )llvm_cbe_tmp__158 ^ llvm_cbe_tmp__160;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__161);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = getelementptr inbounds [5 x i64]* %%D, i64 0, i64 1, !dbg !17 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_476_count);
  llvm_cbe_tmp__162 = (signed long long *)(&llvm_cbe_D[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )1ull) < 5 && "Write access out of array 'D' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%17, i64* %%18, align 8, !dbg !17 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_477_count);
  *llvm_cbe_tmp__162 = llvm_cbe_tmp__161;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__161);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = getelementptr inbounds [5 x i64]* %%C, i64 0, i64 3, !dbg !17 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_494_count);
  llvm_cbe_tmp__163 = (signed long long *)(&llvm_cbe_C[(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )3ull) < 5)) fprintf(stderr, "%s:%d: warning: Read access out of array 'C' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = load i64* %%19, align 8, !dbg !17 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_495_count);
  llvm_cbe_tmp__164 = (unsigned long long )*llvm_cbe_tmp__163;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__164);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = shl i64 %%20, 1, !dbg !17 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_496_count);
  llvm_cbe_tmp__165 = (unsigned long long )llvm_cbe_tmp__164 << 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__165);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = lshr i64 %%20, 63, !dbg !17 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_497_count);
  llvm_cbe_tmp__166 = (unsigned long long )((unsigned long long )(((unsigned long long )(llvm_cbe_tmp__164&18446744073709551615ull)) >> ((unsigned long long )(63ull&18446744073709551615ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__166&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = or i64 %%21, %%22, !dbg !17 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_498_count);
  llvm_cbe_tmp__167 = (unsigned long long )llvm_cbe_tmp__165 | llvm_cbe_tmp__166;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__167);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = xor i64 %%23, %%2, !dbg !17 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_499_count);
  llvm_cbe_tmp__168 = (unsigned long long )llvm_cbe_tmp__167 ^ llvm_cbe_tmp__146;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__168);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = getelementptr inbounds [5 x i64]* %%D, i64 0, i64 2, !dbg !17 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_500_count);
  llvm_cbe_tmp__169 = (signed long long *)(&llvm_cbe_D[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )2ull) < 5 && "Write access out of array 'D' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%24, i64* %%25, align 16, !dbg !17 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_501_count);
  *llvm_cbe_tmp__169 = llvm_cbe_tmp__168;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__168);
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = shl i64 %%7, 1, !dbg !17 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_518_count);
  llvm_cbe_tmp__170 = (unsigned long long )llvm_cbe_tmp__151 << 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__170);
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = lshr i64 %%7, 63, !dbg !17 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_519_count);
  llvm_cbe_tmp__171 = (unsigned long long )((unsigned long long )(((unsigned long long )(llvm_cbe_tmp__151&18446744073709551615ull)) >> ((unsigned long long )(63ull&18446744073709551615ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__171&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = or i64 %%26, %%27, !dbg !17 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_520_count);
  llvm_cbe_tmp__172 = (unsigned long long )llvm_cbe_tmp__170 | llvm_cbe_tmp__171;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__172);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = xor i64 %%28, %%11, !dbg !17 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_521_count);
  llvm_cbe_tmp__173 = (unsigned long long )llvm_cbe_tmp__172 ^ llvm_cbe_tmp__155;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__173);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = getelementptr inbounds [5 x i64]* %%D, i64 0, i64 3, !dbg !17 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_522_count);
  llvm_cbe_tmp__174 = (signed long long *)(&llvm_cbe_D[(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )3ull) < 5 && "Write access out of array 'D' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%29, i64* %%30, align 8, !dbg !17 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_523_count);
  *llvm_cbe_tmp__174 = llvm_cbe_tmp__173;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__173);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = shl i64 %%16, 1, !dbg !17 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_540_count);
  llvm_cbe_tmp__175 = (unsigned long long )llvm_cbe_tmp__160 << 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__175);
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = lshr i64 %%16, 63, !dbg !17 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_541_count);
  llvm_cbe_tmp__176 = (unsigned long long )((unsigned long long )(((unsigned long long )(llvm_cbe_tmp__160&18446744073709551615ull)) >> ((unsigned long long )(63ull&18446744073709551615ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__176&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = or i64 %%31, %%32, !dbg !17 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_542_count);
  llvm_cbe_tmp__177 = (unsigned long long )llvm_cbe_tmp__175 | llvm_cbe_tmp__176;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__177);
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = xor i64 %%33, %%20, !dbg !17 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_543_count);
  llvm_cbe_tmp__178 = (unsigned long long )llvm_cbe_tmp__177 ^ llvm_cbe_tmp__164;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__178);
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = getelementptr inbounds [5 x i64]* %%D, i64 0, i64 4, !dbg !17 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_544_count);
  llvm_cbe_tmp__179 = (signed long long *)(&llvm_cbe_D[(((signed long long )4ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )4ull) < 5 && "Write access out of array 'D' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%34, i64* %%35, align 16, !dbg !17 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_545_count);
  *llvm_cbe_tmp__179 = llvm_cbe_tmp__178;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__178);
  llvm_cbe_storemerge27__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_preheader;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__236:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge11 = phi i32 [ 0, %%0 ], [ %%63, %%36  for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_storemerge11_count);
  llvm_cbe_storemerge11 = (unsigned int )llvm_cbe_storemerge11__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge11 = 0x%X",llvm_cbe_storemerge11);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__206);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = zext i32 %%storemerge11 to i64, !dbg !17 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_578_count);
  llvm_cbe_tmp__180 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge11&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__180);
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = getelementptr inbounds [5 x i64]* %%C, i64 0, i64 %%37, !dbg !17 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_579_count);
  llvm_cbe_tmp__181 = (signed long long *)(&llvm_cbe_C[(((signed long long )llvm_cbe_tmp__180))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__180));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = urem i32 %%storemerge11, 5, !dbg !15 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_587_count);
  llvm_cbe_tmp__182 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_storemerge11&4294967295ull)) % ((unsigned int )(5u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__182&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = zext i32 %%39 to i64, !dbg !15 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_588_count);
  llvm_cbe_tmp__183 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__182&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__183);
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = getelementptr inbounds i64* %%A, i64 %%40, !dbg !15 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_589_count);
  llvm_cbe_tmp__184 = (signed long long *)(&llvm_cbe_A[(((signed long long )llvm_cbe_tmp__183))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__183));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = load i64* %%41, align 8, !dbg !15 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_590_count);
  llvm_cbe_tmp__185 = (unsigned long long )*llvm_cbe_tmp__184;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__185);
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = add i32 %%39, 5, !dbg !15 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_598_count);
  llvm_cbe_tmp__186 = (unsigned int )((unsigned int )(llvm_cbe_tmp__182&4294967295ull)) + ((unsigned int )(5u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__186&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = zext i32 %%43 to i64, !dbg !15 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_599_count);
  llvm_cbe_tmp__187 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__186&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__187);
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = getelementptr inbounds i64* %%A, i64 %%44, !dbg !15 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_600_count);
  llvm_cbe_tmp__188 = (signed long long *)(&llvm_cbe_A[(((signed long long )llvm_cbe_tmp__187))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__187));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = load i64* %%45, align 8, !dbg !15 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_601_count);
  llvm_cbe_tmp__189 = (unsigned long long )*llvm_cbe_tmp__188;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__189);
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = xor i64 %%42, %%46, !dbg !15 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_602_count);
  llvm_cbe_tmp__190 = (unsigned long long )llvm_cbe_tmp__185 ^ llvm_cbe_tmp__189;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__190);
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = add i32 %%39, 10, !dbg !15 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_610_count);
  llvm_cbe_tmp__191 = (unsigned int )((unsigned int )(llvm_cbe_tmp__182&4294967295ull)) + ((unsigned int )(10u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__191&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = zext i32 %%48 to i64, !dbg !15 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_611_count);
  llvm_cbe_tmp__192 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__191&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__192);
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = getelementptr inbounds i64* %%A, i64 %%49, !dbg !15 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_612_count);
  llvm_cbe_tmp__193 = (signed long long *)(&llvm_cbe_A[(((signed long long )llvm_cbe_tmp__192))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__192));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = load i64* %%50, align 8, !dbg !15 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_613_count);
  llvm_cbe_tmp__194 = (unsigned long long )*llvm_cbe_tmp__193;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__194);
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = xor i64 %%47, %%51, !dbg !15 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_614_count);
  llvm_cbe_tmp__195 = (unsigned long long )llvm_cbe_tmp__190 ^ llvm_cbe_tmp__194;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__195);
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = add i32 %%39, 15, !dbg !15 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_622_count);
  llvm_cbe_tmp__196 = (unsigned int )((unsigned int )(llvm_cbe_tmp__182&4294967295ull)) + ((unsigned int )(15u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__196&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = zext i32 %%53 to i64, !dbg !15 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_623_count);
  llvm_cbe_tmp__197 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__196&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__197);
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = getelementptr inbounds i64* %%A, i64 %%54, !dbg !15 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_624_count);
  llvm_cbe_tmp__198 = (signed long long *)(&llvm_cbe_A[(((signed long long )llvm_cbe_tmp__197))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__197));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = load i64* %%55, align 8, !dbg !15 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_625_count);
  llvm_cbe_tmp__199 = (unsigned long long )*llvm_cbe_tmp__198;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__199);
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = xor i64 %%52, %%56, !dbg !15 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_626_count);
  llvm_cbe_tmp__200 = (unsigned long long )llvm_cbe_tmp__195 ^ llvm_cbe_tmp__199;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__200);
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = add i32 %%39, 20, !dbg !15 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_634_count);
  llvm_cbe_tmp__201 = (unsigned int )((unsigned int )(llvm_cbe_tmp__182&4294967295ull)) + ((unsigned int )(20u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__201&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = zext i32 %%58 to i64, !dbg !15 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_635_count);
  llvm_cbe_tmp__202 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__201&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__202);
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = getelementptr inbounds i64* %%A, i64 %%59, !dbg !15 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_636_count);
  llvm_cbe_tmp__203 = (signed long long *)(&llvm_cbe_A[(((signed long long )llvm_cbe_tmp__202))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__202));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%61 = load i64* %%60, align 8, !dbg !15 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_637_count);
  llvm_cbe_tmp__204 = (unsigned long long )*llvm_cbe_tmp__203;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__204);
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = xor i64 %%57, %%61, !dbg !15 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_638_count);
  llvm_cbe_tmp__205 = (unsigned long long )llvm_cbe_tmp__200 ^ llvm_cbe_tmp__204;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__205);

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__180) < 5 && "Write access out of array 'C' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%62, i64* %%38, align 8, !dbg !15 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_646_count);
  *llvm_cbe_tmp__181 = llvm_cbe_tmp__205;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__205);
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = add i32 %%storemerge11, 1, !dbg !17 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_647_count);
  llvm_cbe_tmp__206 = (unsigned int )((unsigned int )(llvm_cbe_storemerge11&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__206&4294967295ull)));
  if (((llvm_cbe_tmp__206&4294967295U) == (5u&4294967295U))) {
    goto llvm_cbe__2e_preheader8;
  } else {
    llvm_cbe_storemerge11__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__206;   /* for PHI node */
    goto llvm_cbe_tmp__236;
  }

  } while (1); /* end of syntactic loop '' */
  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge27 = phi i32 [ 0, %%.preheader8 ], [ %%92, %%.preheader  for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_storemerge27_count);
  llvm_cbe_storemerge27 = (unsigned int )llvm_cbe_storemerge27__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge27 = 0x%X",llvm_cbe_storemerge27);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__235);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%64 = zext i32 %%storemerge27 to i64, !dbg !16 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_671_count);
  llvm_cbe_tmp__207 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge27&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__207);
if (AESL_DEBUG_TRACE)
printf("\n  %%65 = getelementptr inbounds [5 x i64]* %%D, i64 0, i64 %%64, !dbg !16 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_672_count);
  llvm_cbe_tmp__208 = (signed long long *)(&llvm_cbe_D[(((signed long long )llvm_cbe_tmp__207))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__207));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__207) < 5)) fprintf(stderr, "%s:%d: warning: Read access out of array 'D' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%66 = load i64* %%65, align 8, !dbg !16 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_673_count);
  llvm_cbe_tmp__209 = (unsigned long long )*llvm_cbe_tmp__208;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__209);
if (AESL_DEBUG_TRACE)
printf("\n  %%67 = urem i32 %%storemerge27, 5, !dbg !16 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_674_count);
  llvm_cbe_tmp__210 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_storemerge27&4294967295ull)) % ((unsigned int )(5u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__210&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%68 = zext i32 %%67 to i64, !dbg !16 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_675_count);
  llvm_cbe_tmp__211 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__210&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__211);
if (AESL_DEBUG_TRACE)
printf("\n  %%69 = getelementptr inbounds i64* %%A, i64 %%68, !dbg !16 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_676_count);
  llvm_cbe_tmp__212 = (signed long long *)(&llvm_cbe_A[(((signed long long )llvm_cbe_tmp__211))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__211));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%70 = load i64* %%69, align 8, !dbg !16 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_677_count);
  llvm_cbe_tmp__213 = (unsigned long long )*llvm_cbe_tmp__212;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__213);
if (AESL_DEBUG_TRACE)
printf("\n  %%71 = xor i64 %%70, %%66, !dbg !16 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_678_count);
  llvm_cbe_tmp__214 = (unsigned long long )llvm_cbe_tmp__213 ^ llvm_cbe_tmp__209;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__214);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%71, i64* %%69, align 8, !dbg !16 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_679_count);
  *llvm_cbe_tmp__212 = llvm_cbe_tmp__214;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__214);
if (AESL_DEBUG_TRACE)
printf("\n  %%72 = add i32 %%67, 5, !dbg !16 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_687_count);
  llvm_cbe_tmp__215 = (unsigned int )((unsigned int )(llvm_cbe_tmp__210&4294967295ull)) + ((unsigned int )(5u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__215&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%73 = zext i32 %%72 to i64, !dbg !16 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_688_count);
  llvm_cbe_tmp__216 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__215&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__216);
if (AESL_DEBUG_TRACE)
printf("\n  %%74 = getelementptr inbounds i64* %%A, i64 %%73, !dbg !16 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_689_count);
  llvm_cbe_tmp__217 = (signed long long *)(&llvm_cbe_A[(((signed long long )llvm_cbe_tmp__216))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__216));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%75 = load i64* %%74, align 8, !dbg !16 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_690_count);
  llvm_cbe_tmp__218 = (unsigned long long )*llvm_cbe_tmp__217;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__218);
if (AESL_DEBUG_TRACE)
printf("\n  %%76 = xor i64 %%75, %%66, !dbg !16 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_691_count);
  llvm_cbe_tmp__219 = (unsigned long long )llvm_cbe_tmp__218 ^ llvm_cbe_tmp__209;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__219);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%76, i64* %%74, align 8, !dbg !16 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_692_count);
  *llvm_cbe_tmp__217 = llvm_cbe_tmp__219;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__219);
if (AESL_DEBUG_TRACE)
printf("\n  %%77 = add i32 %%67, 10, !dbg !16 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_700_count);
  llvm_cbe_tmp__220 = (unsigned int )((unsigned int )(llvm_cbe_tmp__210&4294967295ull)) + ((unsigned int )(10u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__220&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%78 = zext i32 %%77 to i64, !dbg !16 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_701_count);
  llvm_cbe_tmp__221 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__220&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__221);
if (AESL_DEBUG_TRACE)
printf("\n  %%79 = getelementptr inbounds i64* %%A, i64 %%78, !dbg !16 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_702_count);
  llvm_cbe_tmp__222 = (signed long long *)(&llvm_cbe_A[(((signed long long )llvm_cbe_tmp__221))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__221));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%80 = load i64* %%79, align 8, !dbg !16 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_703_count);
  llvm_cbe_tmp__223 = (unsigned long long )*llvm_cbe_tmp__222;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__223);
if (AESL_DEBUG_TRACE)
printf("\n  %%81 = xor i64 %%80, %%66, !dbg !16 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_704_count);
  llvm_cbe_tmp__224 = (unsigned long long )llvm_cbe_tmp__223 ^ llvm_cbe_tmp__209;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__224);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%81, i64* %%79, align 8, !dbg !16 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_705_count);
  *llvm_cbe_tmp__222 = llvm_cbe_tmp__224;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__224);
if (AESL_DEBUG_TRACE)
printf("\n  %%82 = add i32 %%67, 15, !dbg !16 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_713_count);
  llvm_cbe_tmp__225 = (unsigned int )((unsigned int )(llvm_cbe_tmp__210&4294967295ull)) + ((unsigned int )(15u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__225&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%83 = zext i32 %%82 to i64, !dbg !16 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_714_count);
  llvm_cbe_tmp__226 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__225&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__226);
if (AESL_DEBUG_TRACE)
printf("\n  %%84 = getelementptr inbounds i64* %%A, i64 %%83, !dbg !16 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_715_count);
  llvm_cbe_tmp__227 = (signed long long *)(&llvm_cbe_A[(((signed long long )llvm_cbe_tmp__226))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__226));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%85 = load i64* %%84, align 8, !dbg !16 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_716_count);
  llvm_cbe_tmp__228 = (unsigned long long )*llvm_cbe_tmp__227;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__228);
if (AESL_DEBUG_TRACE)
printf("\n  %%86 = xor i64 %%85, %%66, !dbg !16 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_717_count);
  llvm_cbe_tmp__229 = (unsigned long long )llvm_cbe_tmp__228 ^ llvm_cbe_tmp__209;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__229);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%86, i64* %%84, align 8, !dbg !16 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_718_count);
  *llvm_cbe_tmp__227 = llvm_cbe_tmp__229;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__229);
if (AESL_DEBUG_TRACE)
printf("\n  %%87 = add i32 %%67, 20, !dbg !16 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_726_count);
  llvm_cbe_tmp__230 = (unsigned int )((unsigned int )(llvm_cbe_tmp__210&4294967295ull)) + ((unsigned int )(20u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__230&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%88 = zext i32 %%87 to i64, !dbg !16 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_727_count);
  llvm_cbe_tmp__231 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__230&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__231);
if (AESL_DEBUG_TRACE)
printf("\n  %%89 = getelementptr inbounds i64* %%A, i64 %%88, !dbg !16 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_728_count);
  llvm_cbe_tmp__232 = (signed long long *)(&llvm_cbe_A[(((signed long long )llvm_cbe_tmp__231))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__231));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%90 = load i64* %%89, align 8, !dbg !16 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_729_count);
  llvm_cbe_tmp__233 = (unsigned long long )*llvm_cbe_tmp__232;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__233);
if (AESL_DEBUG_TRACE)
printf("\n  %%91 = xor i64 %%90, %%66, !dbg !16 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_730_count);
  llvm_cbe_tmp__234 = (unsigned long long )llvm_cbe_tmp__233 ^ llvm_cbe_tmp__209;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__234);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%91, i64* %%89, align 8, !dbg !16 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_731_count);
  *llvm_cbe_tmp__232 = llvm_cbe_tmp__234;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__234);
if (AESL_DEBUG_TRACE)
printf("\n  %%92 = add i32 %%storemerge27, 1, !dbg !18 for 0x%I64xth hint within @aesl_internal_theta  --> \n", ++aesl_llvm_cbe_739_count);
  llvm_cbe_tmp__235 = (unsigned int )((unsigned int )(llvm_cbe_storemerge27&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__235&4294967295ull)));
  if (((llvm_cbe_tmp__235&4294967295U) == (5u&4294967295U))) {
    goto llvm_cbe_tmp__237;
  } else {
    llvm_cbe_storemerge27__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__235;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe_tmp__237:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @aesl_internal_theta}\n");
  return;
}


static void aesl_internal_rho(signed long long *llvm_cbe_A) {
  static  unsigned long long aesl_llvm_cbe_758_count = 0;
  static  unsigned long long aesl_llvm_cbe_759_count = 0;
  static  unsigned long long aesl_llvm_cbe_760_count = 0;
  static  unsigned long long aesl_llvm_cbe_761_count = 0;
  static  unsigned long long aesl_llvm_cbe_762_count = 0;
  static  unsigned long long aesl_llvm_cbe_763_count = 0;
  static  unsigned long long aesl_llvm_cbe_764_count = 0;
  static  unsigned long long aesl_llvm_cbe_765_count = 0;
  static  unsigned long long aesl_llvm_cbe_766_count = 0;
  static  unsigned long long aesl_llvm_cbe_767_count = 0;
  static  unsigned long long aesl_llvm_cbe_768_count = 0;
  static  unsigned long long aesl_llvm_cbe_769_count = 0;
  static  unsigned long long aesl_llvm_cbe_770_count = 0;
  static  unsigned long long aesl_llvm_cbe_771_count = 0;
  static  unsigned long long aesl_llvm_cbe_772_count = 0;
  static  unsigned long long aesl_llvm_cbe_773_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned int llvm_cbe_storemerge3;
  unsigned int llvm_cbe_storemerge3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_774_count = 0;
  static  unsigned long long aesl_llvm_cbe_775_count = 0;
  static  unsigned long long aesl_llvm_cbe_776_count = 0;
  static  unsigned long long aesl_llvm_cbe_777_count = 0;
  static  unsigned long long aesl_llvm_cbe_778_count = 0;
  static  unsigned long long aesl_llvm_cbe_779_count = 0;
  static  unsigned long long aesl_llvm_cbe_780_count = 0;
  static  unsigned long long aesl_llvm_cbe_781_count = 0;
  static  unsigned long long aesl_llvm_cbe_782_count = 0;
  static  unsigned long long aesl_llvm_cbe_783_count = 0;
  unsigned int llvm_cbe_tmp__238;
  static  unsigned long long aesl_llvm_cbe_784_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_count = 0;
  unsigned int llvm_cbe_storemerge12;
  unsigned int llvm_cbe_storemerge12__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_785_count = 0;
  unsigned int llvm_cbe_tmp__239;
  static  unsigned long long aesl_llvm_cbe_786_count = 0;
  unsigned int llvm_cbe_tmp__240;
  static  unsigned long long aesl_llvm_cbe_787_count = 0;
  static  unsigned long long aesl_llvm_cbe_788_count = 0;
  static  unsigned long long aesl_llvm_cbe_789_count = 0;
  unsigned int llvm_cbe_tmp__241;
  static  unsigned long long aesl_llvm_cbe_790_count = 0;
  unsigned int llvm_cbe_tmp__242;
  static  unsigned long long aesl_llvm_cbe_791_count = 0;
  unsigned long long llvm_cbe_tmp__243;
  static  unsigned long long aesl_llvm_cbe_792_count = 0;
  signed long long *llvm_cbe_tmp__244;
  static  unsigned long long aesl_llvm_cbe_793_count = 0;
  unsigned long long llvm_cbe_tmp__245;
  static  unsigned long long aesl_llvm_cbe_794_count = 0;
  signed int *llvm_cbe_tmp__246;
  static  unsigned long long aesl_llvm_cbe_795_count = 0;
  unsigned int llvm_cbe_tmp__247;
  static  unsigned long long aesl_llvm_cbe_796_count = 0;
  unsigned long long llvm_cbe_tmp__248;
  static  unsigned long long aesl_llvm_cbe_797_count = 0;
  unsigned long long llvm_cbe_tmp__249;
  static  unsigned long long aesl_llvm_cbe_798_count = 0;
  unsigned int llvm_cbe_tmp__250;
  static  unsigned long long aesl_llvm_cbe_799_count = 0;
  unsigned long long llvm_cbe_tmp__251;
  static  unsigned long long aesl_llvm_cbe_800_count = 0;
  unsigned long long llvm_cbe_tmp__252;
  static  unsigned long long aesl_llvm_cbe_801_count = 0;
  unsigned long long llvm_cbe_tmp__253;
  static  unsigned long long aesl_llvm_cbe_802_count = 0;
  static  unsigned long long aesl_llvm_cbe_803_count = 0;
  unsigned int llvm_cbe_tmp__254;
  static  unsigned long long aesl_llvm_cbe_804_count = 0;
  unsigned int llvm_cbe_tmp__255;
  static  unsigned long long aesl_llvm_cbe_805_count = 0;
  unsigned long long llvm_cbe_tmp__256;
  static  unsigned long long aesl_llvm_cbe_806_count = 0;
  signed long long *llvm_cbe_tmp__257;
  static  unsigned long long aesl_llvm_cbe_807_count = 0;
  unsigned long long llvm_cbe_tmp__258;
  static  unsigned long long aesl_llvm_cbe_808_count = 0;
  static  unsigned long long aesl_llvm_cbe_809_count = 0;
  unsigned long long llvm_cbe_tmp__259;
  unsigned long long llvm_cbe_tmp__259__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_810_count = 0;
  unsigned int llvm_cbe_tmp__260;
  static  unsigned long long aesl_llvm_cbe_811_count = 0;
  unsigned int llvm_cbe_tmp__261;
  static  unsigned long long aesl_llvm_cbe_812_count = 0;
  unsigned long long llvm_cbe_tmp__262;
  static  unsigned long long aesl_llvm_cbe_813_count = 0;
  signed long long *llvm_cbe_tmp__263;
  static  unsigned long long aesl_llvm_cbe_814_count = 0;
  static  unsigned long long aesl_llvm_cbe_815_count = 0;
  unsigned int llvm_cbe_tmp__264;
  static  unsigned long long aesl_llvm_cbe_816_count = 0;
  static  unsigned long long aesl_llvm_cbe_817_count = 0;
  static  unsigned long long aesl_llvm_cbe_818_count = 0;
  static  unsigned long long aesl_llvm_cbe_819_count = 0;
  static  unsigned long long aesl_llvm_cbe_820_count = 0;
  static  unsigned long long aesl_llvm_cbe_821_count = 0;
  static  unsigned long long aesl_llvm_cbe_822_count = 0;
  static  unsigned long long aesl_llvm_cbe_823_count = 0;
  static  unsigned long long aesl_llvm_cbe_824_count = 0;
  static  unsigned long long aesl_llvm_cbe_825_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_826_count = 0;
  static  unsigned long long aesl_llvm_cbe_827_count = 0;
  unsigned int llvm_cbe_tmp__265;
  static  unsigned long long aesl_llvm_cbe_828_count = 0;
  static  unsigned long long aesl_llvm_cbe_829_count = 0;
  static  unsigned long long aesl_llvm_cbe_830_count = 0;
  static  unsigned long long aesl_llvm_cbe_831_count = 0;
  static  unsigned long long aesl_llvm_cbe_832_count = 0;
  static  unsigned long long aesl_llvm_cbe_833_count = 0;
  static  unsigned long long aesl_llvm_cbe_834_count = 0;
  static  unsigned long long aesl_llvm_cbe_835_count = 0;
  static  unsigned long long aesl_llvm_cbe_836_count = 0;
  static  unsigned long long aesl_llvm_cbe_837_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond4_count = 0;
  static  unsigned long long aesl_llvm_cbe_838_count = 0;
  static  unsigned long long aesl_llvm_cbe_839_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @aesl_internal_rho\n");
  llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_preheader;

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = phi i32 [ 0, %%0 ], [ %%34, %%33  for 0x%I64xth hint within @aesl_internal_rho  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned int )llvm_cbe_storemerge3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%X",llvm_cbe_storemerge3);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__265);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = urem i32 %%storemerge3, 5, !dbg !15 for 0x%I64xth hint within @aesl_internal_rho  --> \n", ++aesl_llvm_cbe_783_count);
  llvm_cbe_tmp__238 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_storemerge3&4294967295ull)) % ((unsigned int )(5u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__238&4294967295ull)));
  llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__266;

llvm_cbe_tmp__267:
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = add i32 %%storemerge3, 1, !dbg !16 for 0x%I64xth hint within @aesl_internal_rho  --> \n", ++aesl_llvm_cbe_827_count);
  llvm_cbe_tmp__265 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__265&4294967295ull)));
  if (((llvm_cbe_tmp__265&4294967295U) == (5u&4294967295U))) {
    goto llvm_cbe_tmp__268;
  } else {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__265;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__266:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12 = phi i32 [ 0, %%.preheader ], [ %%32, %%26  for 0x%I64xth hint within @aesl_internal_rho  --> \n", ++aesl_llvm_cbe_storemerge12_count);
  llvm_cbe_storemerge12 = (unsigned int )llvm_cbe_storemerge12__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%X",llvm_cbe_storemerge12);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__264);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = urem i32 %%storemerge12, 5, !dbg !15 for 0x%I64xth hint within @aesl_internal_rho  --> \n", ++aesl_llvm_cbe_785_count);
  llvm_cbe_tmp__239 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_storemerge12&4294967295ull)) % ((unsigned int )(5u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__239&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = mul i32 %%3, -5, !dbg !15 for 0x%I64xth hint within @aesl_internal_rho  --> \n", ++aesl_llvm_cbe_786_count);
  llvm_cbe_tmp__240 = (unsigned int )((unsigned int )(llvm_cbe_tmp__239&4294967295ull)) * ((unsigned int )(4294967291u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__240&4294967295ull)));
  if (((llvm_cbe_tmp__238&4294967295U) == (llvm_cbe_tmp__240&4294967295U))) {
    goto llvm_cbe_tmp__269;
  } else {
    goto llvm_cbe_tmp__270;
  }

llvm_cbe_tmp__271:
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = phi i64 [ %%19, %%6 ], [ %%25, %%20 ], !dbg !15 for 0x%I64xth hint within @aesl_internal_rho  --> \n", ++aesl_llvm_cbe_809_count);
  llvm_cbe_tmp__259 = (unsigned long long )llvm_cbe_tmp__259__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__259);
printf("\n = 0x%I64X",llvm_cbe_tmp__253);
printf("\n = 0x%I64X",llvm_cbe_tmp__258);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = mul i32 %%3, 5, !dbg !15 for 0x%I64xth hint within @aesl_internal_rho  --> \n", ++aesl_llvm_cbe_810_count);
  llvm_cbe_tmp__260 = (unsigned int )((unsigned int )(llvm_cbe_tmp__239&4294967295ull)) * ((unsigned int )(5u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__260&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = add i32 %%28, %%1, !dbg !15 for 0x%I64xth hint within @aesl_internal_rho  --> \n", ++aesl_llvm_cbe_811_count);
  llvm_cbe_tmp__261 = (unsigned int )((unsigned int )(llvm_cbe_tmp__260&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__238&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__261&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = zext i32 %%29 to i64, !dbg !15 for 0x%I64xth hint within @aesl_internal_rho  --> \n", ++aesl_llvm_cbe_812_count);
  llvm_cbe_tmp__262 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__261&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__262);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = getelementptr inbounds i64* %%A, i64 %%30, !dbg !15 for 0x%I64xth hint within @aesl_internal_rho  --> \n", ++aesl_llvm_cbe_813_count);
  llvm_cbe_tmp__263 = (signed long long *)(&llvm_cbe_A[(((signed long long )llvm_cbe_tmp__262))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__262));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%27, i64* %%31, align 8, !dbg !15 for 0x%I64xth hint within @aesl_internal_rho  --> \n", ++aesl_llvm_cbe_814_count);
  *llvm_cbe_tmp__263 = llvm_cbe_tmp__259;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__259);
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = add i32 %%storemerge12, 1, !dbg !16 for 0x%I64xth hint within @aesl_internal_rho  --> \n", ++aesl_llvm_cbe_815_count);
  llvm_cbe_tmp__264 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__264&4294967295ull)));
  if (((llvm_cbe_tmp__264&4294967295U) == (5u&4294967295U))) {
    goto llvm_cbe_tmp__267;
  } else {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__264;   /* for PHI node */
    goto llvm_cbe_tmp__266;
  }

llvm_cbe_tmp__270:
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = mul i32 %%3, 5, !dbg !15 for 0x%I64xth hint within @aesl_internal_rho  --> \n", ++aesl_llvm_cbe_789_count);
  llvm_cbe_tmp__241 = (unsigned int )((unsigned int )(llvm_cbe_tmp__239&4294967295ull)) * ((unsigned int )(5u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__241&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = add i32 %%7, %%1, !dbg !15 for 0x%I64xth hint within @aesl_internal_rho  --> \n", ++aesl_llvm_cbe_790_count);
  llvm_cbe_tmp__242 = (unsigned int )((unsigned int )(llvm_cbe_tmp__241&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__238&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__242&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = zext i32 %%8 to i64, !dbg !15 for 0x%I64xth hint within @aesl_internal_rho  --> \n", ++aesl_llvm_cbe_791_count);
  llvm_cbe_tmp__243 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__242&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__243);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds i64* %%A, i64 %%9, !dbg !15 for 0x%I64xth hint within @aesl_internal_rho  --> \n", ++aesl_llvm_cbe_792_count);
  llvm_cbe_tmp__244 = (signed long long *)(&llvm_cbe_A[(((signed long long )llvm_cbe_tmp__243))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__243));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = load i64* %%10, align 8, !dbg !15 for 0x%I64xth hint within @aesl_internal_rho  --> \n", ++aesl_llvm_cbe_793_count);
  llvm_cbe_tmp__245 = (unsigned long long )*llvm_cbe_tmp__244;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__245);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds [25 x i32]* @aesl_internal_KeccakRhoOffsets, i64 0, i64 %%9, !dbg !15 for 0x%I64xth hint within @aesl_internal_rho  --> \n", ++aesl_llvm_cbe_794_count);
  llvm_cbe_tmp__246 = (signed int *)(&aesl_internal_KeccakRhoOffsets[(((signed long long )llvm_cbe_tmp__243))
#ifdef AESL_BC_SIM
 % 25
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__243));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__243) < 25)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_KeccakRhoOffsets' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = load i32* %%12, align 4, !dbg !15 for 0x%I64xth hint within @aesl_internal_rho  --> \n", ++aesl_llvm_cbe_795_count);
  llvm_cbe_tmp__247 = (unsigned int )*llvm_cbe_tmp__246;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__247);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = zext i32 %%13 to i64, !dbg !15 for 0x%I64xth hint within @aesl_internal_rho  --> \n", ++aesl_llvm_cbe_796_count);
  llvm_cbe_tmp__248 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__247&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__248);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = shl i64 %%11, %%14, !dbg !15 for 0x%I64xth hint within @aesl_internal_rho  --> \n", ++aesl_llvm_cbe_797_count);
  llvm_cbe_tmp__249 = (unsigned long long )llvm_cbe_tmp__245 << llvm_cbe_tmp__248;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__249);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = sub i32 64, %%13, !dbg !15 for 0x%I64xth hint within @aesl_internal_rho  --> \n", ++aesl_llvm_cbe_798_count);
  llvm_cbe_tmp__250 = (unsigned int )((unsigned int )(64u&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__247&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__250&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = zext i32 %%16 to i64, !dbg !15 for 0x%I64xth hint within @aesl_internal_rho  --> \n", ++aesl_llvm_cbe_799_count);
  llvm_cbe_tmp__251 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__250&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__251);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = lshr i64 %%11, %%17, !dbg !15 for 0x%I64xth hint within @aesl_internal_rho  --> \n", ++aesl_llvm_cbe_800_count);
  llvm_cbe_tmp__252 = (unsigned long long )((unsigned long long )(((unsigned long long )(llvm_cbe_tmp__245&18446744073709551615ull)) >> ((unsigned long long )(llvm_cbe_tmp__251&18446744073709551615ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__252&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = xor i64 %%18, %%15, !dbg !15 for 0x%I64xth hint within @aesl_internal_rho  --> \n", ++aesl_llvm_cbe_801_count);
  llvm_cbe_tmp__253 = (unsigned long long )llvm_cbe_tmp__252 ^ llvm_cbe_tmp__249;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__253);
  llvm_cbe_tmp__259__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__253;   /* for PHI node */
  goto llvm_cbe_tmp__271;

llvm_cbe_tmp__269:
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = mul i32 %%3, 5, !dbg !15 for 0x%I64xth hint within @aesl_internal_rho  --> \n", ++aesl_llvm_cbe_803_count);
  llvm_cbe_tmp__254 = (unsigned int )((unsigned int )(llvm_cbe_tmp__239&4294967295ull)) * ((unsigned int )(5u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__254&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = add i32 %%21, %%1, !dbg !15 for 0x%I64xth hint within @aesl_internal_rho  --> \n", ++aesl_llvm_cbe_804_count);
  llvm_cbe_tmp__255 = (unsigned int )((unsigned int )(llvm_cbe_tmp__254&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__238&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__255&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = zext i32 %%22 to i64, !dbg !15 for 0x%I64xth hint within @aesl_internal_rho  --> \n", ++aesl_llvm_cbe_805_count);
  llvm_cbe_tmp__256 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__255&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__256);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = getelementptr inbounds i64* %%A, i64 %%23, !dbg !15 for 0x%I64xth hint within @aesl_internal_rho  --> \n", ++aesl_llvm_cbe_806_count);
  llvm_cbe_tmp__257 = (signed long long *)(&llvm_cbe_A[(((signed long long )llvm_cbe_tmp__256))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__256));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = load i64* %%24, align 8, !dbg !15 for 0x%I64xth hint within @aesl_internal_rho  --> \n", ++aesl_llvm_cbe_807_count);
  llvm_cbe_tmp__258 = (unsigned long long )*llvm_cbe_tmp__257;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__258);
  llvm_cbe_tmp__259__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__258;   /* for PHI node */
  goto llvm_cbe_tmp__271;

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe_tmp__268:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @aesl_internal_rho}\n");
  return;
}


static void aesl_internal_pi(signed long long *llvm_cbe_A) {
  static  unsigned long long aesl_llvm_cbe_tempA_count = 0;
  signed long long llvm_cbe_tempA[25];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_840_count = 0;
  static  unsigned long long aesl_llvm_cbe_841_count = 0;
  static  unsigned long long aesl_llvm_cbe_842_count = 0;
  static  unsigned long long aesl_llvm_cbe_843_count = 0;
  static  unsigned long long aesl_llvm_cbe_844_count = 0;
  static  unsigned long long aesl_llvm_cbe_845_count = 0;
  static  unsigned long long aesl_llvm_cbe_846_count = 0;
  static  unsigned long long aesl_llvm_cbe_847_count = 0;
  static  unsigned long long aesl_llvm_cbe_848_count = 0;
  static  unsigned long long aesl_llvm_cbe_849_count = 0;
  static  unsigned long long aesl_llvm_cbe_850_count = 0;
  static  unsigned long long aesl_llvm_cbe_851_count = 0;
  static  unsigned long long aesl_llvm_cbe_852_count = 0;
  static  unsigned long long aesl_llvm_cbe_853_count = 0;
  static  unsigned long long aesl_llvm_cbe_854_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge9_count = 0;
  unsigned int llvm_cbe_storemerge9;
  unsigned int llvm_cbe_storemerge9__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_855_count = 0;
  static  unsigned long long aesl_llvm_cbe_856_count = 0;
  static  unsigned long long aesl_llvm_cbe_857_count = 0;
  static  unsigned long long aesl_llvm_cbe_858_count = 0;
  static  unsigned long long aesl_llvm_cbe_859_count = 0;
  static  unsigned long long aesl_llvm_cbe_860_count = 0;
  static  unsigned long long aesl_llvm_cbe_861_count = 0;
  static  unsigned long long aesl_llvm_cbe_862_count = 0;
  static  unsigned long long aesl_llvm_cbe_863_count = 0;
  static  unsigned long long aesl_llvm_cbe_864_count = 0;
  unsigned int llvm_cbe_tmp__272;
  static  unsigned long long aesl_llvm_cbe_865_count = 0;
  unsigned long long llvm_cbe_tmp__273;
  static  unsigned long long aesl_llvm_cbe_866_count = 0;
  signed long long *llvm_cbe_tmp__274;
  static  unsigned long long aesl_llvm_cbe_867_count = 0;
  unsigned long long llvm_cbe_tmp__275;
  static  unsigned long long aesl_llvm_cbe_868_count = 0;
  signed long long *llvm_cbe_tmp__276;
  static  unsigned long long aesl_llvm_cbe_869_count = 0;
  static  unsigned long long aesl_llvm_cbe_870_count = 0;
  static  unsigned long long aesl_llvm_cbe_871_count = 0;
  static  unsigned long long aesl_llvm_cbe_872_count = 0;
  static  unsigned long long aesl_llvm_cbe_873_count = 0;
  static  unsigned long long aesl_llvm_cbe_874_count = 0;
  static  unsigned long long aesl_llvm_cbe_875_count = 0;
  static  unsigned long long aesl_llvm_cbe_876_count = 0;
  static  unsigned long long aesl_llvm_cbe_877_count = 0;
  static  unsigned long long aesl_llvm_cbe_878_count = 0;
  static  unsigned long long aesl_llvm_cbe_879_count = 0;
  static  unsigned long long aesl_llvm_cbe_880_count = 0;
  unsigned int llvm_cbe_tmp__277;
  static  unsigned long long aesl_llvm_cbe_881_count = 0;
  unsigned long long llvm_cbe_tmp__278;
  static  unsigned long long aesl_llvm_cbe_882_count = 0;
  signed long long *llvm_cbe_tmp__279;
  static  unsigned long long aesl_llvm_cbe_883_count = 0;
  unsigned long long llvm_cbe_tmp__280;
  static  unsigned long long aesl_llvm_cbe_884_count = 0;
  signed long long *llvm_cbe_tmp__281;
  static  unsigned long long aesl_llvm_cbe_885_count = 0;
  static  unsigned long long aesl_llvm_cbe_886_count = 0;
  static  unsigned long long aesl_llvm_cbe_887_count = 0;
  static  unsigned long long aesl_llvm_cbe_888_count = 0;
  static  unsigned long long aesl_llvm_cbe_889_count = 0;
  static  unsigned long long aesl_llvm_cbe_890_count = 0;
  static  unsigned long long aesl_llvm_cbe_891_count = 0;
  static  unsigned long long aesl_llvm_cbe_892_count = 0;
  static  unsigned long long aesl_llvm_cbe_893_count = 0;
  static  unsigned long long aesl_llvm_cbe_894_count = 0;
  static  unsigned long long aesl_llvm_cbe_895_count = 0;
  static  unsigned long long aesl_llvm_cbe_896_count = 0;
  unsigned int llvm_cbe_tmp__282;
  static  unsigned long long aesl_llvm_cbe_897_count = 0;
  unsigned long long llvm_cbe_tmp__283;
  static  unsigned long long aesl_llvm_cbe_898_count = 0;
  signed long long *llvm_cbe_tmp__284;
  static  unsigned long long aesl_llvm_cbe_899_count = 0;
  unsigned long long llvm_cbe_tmp__285;
  static  unsigned long long aesl_llvm_cbe_900_count = 0;
  signed long long *llvm_cbe_tmp__286;
  static  unsigned long long aesl_llvm_cbe_901_count = 0;
  static  unsigned long long aesl_llvm_cbe_902_count = 0;
  static  unsigned long long aesl_llvm_cbe_903_count = 0;
  static  unsigned long long aesl_llvm_cbe_904_count = 0;
  static  unsigned long long aesl_llvm_cbe_905_count = 0;
  static  unsigned long long aesl_llvm_cbe_906_count = 0;
  static  unsigned long long aesl_llvm_cbe_907_count = 0;
  static  unsigned long long aesl_llvm_cbe_908_count = 0;
  static  unsigned long long aesl_llvm_cbe_909_count = 0;
  static  unsigned long long aesl_llvm_cbe_910_count = 0;
  static  unsigned long long aesl_llvm_cbe_911_count = 0;
  static  unsigned long long aesl_llvm_cbe_912_count = 0;
  unsigned int llvm_cbe_tmp__287;
  static  unsigned long long aesl_llvm_cbe_913_count = 0;
  unsigned long long llvm_cbe_tmp__288;
  static  unsigned long long aesl_llvm_cbe_914_count = 0;
  signed long long *llvm_cbe_tmp__289;
  static  unsigned long long aesl_llvm_cbe_915_count = 0;
  unsigned long long llvm_cbe_tmp__290;
  static  unsigned long long aesl_llvm_cbe_916_count = 0;
  signed long long *llvm_cbe_tmp__291;
  static  unsigned long long aesl_llvm_cbe_917_count = 0;
  static  unsigned long long aesl_llvm_cbe_918_count = 0;
  static  unsigned long long aesl_llvm_cbe_919_count = 0;
  static  unsigned long long aesl_llvm_cbe_920_count = 0;
  static  unsigned long long aesl_llvm_cbe_921_count = 0;
  static  unsigned long long aesl_llvm_cbe_922_count = 0;
  static  unsigned long long aesl_llvm_cbe_923_count = 0;
  static  unsigned long long aesl_llvm_cbe_924_count = 0;
  static  unsigned long long aesl_llvm_cbe_925_count = 0;
  static  unsigned long long aesl_llvm_cbe_926_count = 0;
  static  unsigned long long aesl_llvm_cbe_927_count = 0;
  static  unsigned long long aesl_llvm_cbe_928_count = 0;
  unsigned int llvm_cbe_tmp__292;
  static  unsigned long long aesl_llvm_cbe_929_count = 0;
  unsigned long long llvm_cbe_tmp__293;
  static  unsigned long long aesl_llvm_cbe_930_count = 0;
  signed long long *llvm_cbe_tmp__294;
  static  unsigned long long aesl_llvm_cbe_931_count = 0;
  unsigned long long llvm_cbe_tmp__295;
  static  unsigned long long aesl_llvm_cbe_932_count = 0;
  signed long long *llvm_cbe_tmp__296;
  static  unsigned long long aesl_llvm_cbe_933_count = 0;
  static  unsigned long long aesl_llvm_cbe_934_count = 0;
  static  unsigned long long aesl_llvm_cbe_935_count = 0;
  static  unsigned long long aesl_llvm_cbe_936_count = 0;
  static  unsigned long long aesl_llvm_cbe_937_count = 0;
  static  unsigned long long aesl_llvm_cbe_938_count = 0;
  static  unsigned long long aesl_llvm_cbe_939_count = 0;
  static  unsigned long long aesl_llvm_cbe_940_count = 0;
  static  unsigned long long aesl_llvm_cbe_941_count = 0;
  static  unsigned long long aesl_llvm_cbe_942_count = 0;
  static  unsigned long long aesl_llvm_cbe_943_count = 0;
  static  unsigned long long aesl_llvm_cbe_944_count = 0;
  unsigned int llvm_cbe_tmp__297;
  static  unsigned long long aesl_llvm_cbe_945_count = 0;
  static  unsigned long long aesl_llvm_cbe_946_count = 0;
  static  unsigned long long aesl_llvm_cbe_947_count = 0;
  static  unsigned long long aesl_llvm_cbe_948_count = 0;
  static  unsigned long long aesl_llvm_cbe_949_count = 0;
  static  unsigned long long aesl_llvm_cbe_950_count = 0;
  static  unsigned long long aesl_llvm_cbe_951_count = 0;
  static  unsigned long long aesl_llvm_cbe_952_count = 0;
  static  unsigned long long aesl_llvm_cbe_953_count = 0;
  static  unsigned long long aesl_llvm_cbe_954_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond11_count = 0;
  static  unsigned long long aesl_llvm_cbe_955_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge16_count = 0;
  unsigned int llvm_cbe_storemerge16;
  unsigned int llvm_cbe_storemerge16__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_956_count = 0;
  static  unsigned long long aesl_llvm_cbe_957_count = 0;
  static  unsigned long long aesl_llvm_cbe_958_count = 0;
  static  unsigned long long aesl_llvm_cbe_959_count = 0;
  static  unsigned long long aesl_llvm_cbe_960_count = 0;
  static  unsigned long long aesl_llvm_cbe_961_count = 0;
  static  unsigned long long aesl_llvm_cbe_962_count = 0;
  static  unsigned long long aesl_llvm_cbe_963_count = 0;
  static  unsigned long long aesl_llvm_cbe_964_count = 0;
  static  unsigned long long aesl_llvm_cbe_965_count = 0;
  unsigned int llvm_cbe_tmp__298;
  static  unsigned long long aesl_llvm_cbe_966_count = 0;
  unsigned int llvm_cbe_tmp__299;
  static  unsigned long long aesl_llvm_cbe_967_count = 0;
  unsigned long long llvm_cbe_tmp__300;
  static  unsigned long long aesl_llvm_cbe_968_count = 0;
  signed long long *llvm_cbe_tmp__301;
  static  unsigned long long aesl_llvm_cbe_969_count = 0;
  unsigned long long llvm_cbe_tmp__302;
  static  unsigned long long aesl_llvm_cbe_970_count = 0;
  unsigned int llvm_cbe_tmp__303;
  static  unsigned long long aesl_llvm_cbe_971_count = 0;
  unsigned int llvm_cbe_tmp__304;
  static  unsigned long long aesl_llvm_cbe_972_count = 0;
  unsigned long long llvm_cbe_tmp__305;
  static  unsigned long long aesl_llvm_cbe_973_count = 0;
  signed long long *llvm_cbe_tmp__306;
  static  unsigned long long aesl_llvm_cbe_974_count = 0;
  static  unsigned long long aesl_llvm_cbe_975_count = 0;
  static  unsigned long long aesl_llvm_cbe_976_count = 0;
  static  unsigned long long aesl_llvm_cbe_977_count = 0;
  static  unsigned long long aesl_llvm_cbe_978_count = 0;
  static  unsigned long long aesl_llvm_cbe_979_count = 0;
  static  unsigned long long aesl_llvm_cbe_980_count = 0;
  static  unsigned long long aesl_llvm_cbe_981_count = 0;
  static  unsigned long long aesl_llvm_cbe_982_count = 0;
  static  unsigned long long aesl_llvm_cbe_983_count = 0;
  static  unsigned long long aesl_llvm_cbe_984_count = 0;
  static  unsigned long long aesl_llvm_cbe_985_count = 0;
  unsigned int llvm_cbe_tmp__307;
  static  unsigned long long aesl_llvm_cbe_986_count = 0;
  unsigned long long llvm_cbe_tmp__308;
  static  unsigned long long aesl_llvm_cbe_987_count = 0;
  signed long long *llvm_cbe_tmp__309;
  static  unsigned long long aesl_llvm_cbe_988_count = 0;
  unsigned long long llvm_cbe_tmp__310;
  static  unsigned long long aesl_llvm_cbe_989_count = 0;
  unsigned int llvm_cbe_tmp__311;
  static  unsigned long long aesl_llvm_cbe_990_count = 0;
  unsigned int llvm_cbe_tmp__312;
  static  unsigned long long aesl_llvm_cbe_991_count = 0;
  unsigned int llvm_cbe_tmp__313;
  static  unsigned long long aesl_llvm_cbe_992_count = 0;
  unsigned int llvm_cbe_tmp__314;
  static  unsigned long long aesl_llvm_cbe_993_count = 0;
  unsigned long long llvm_cbe_tmp__315;
  static  unsigned long long aesl_llvm_cbe_994_count = 0;
  signed long long *llvm_cbe_tmp__316;
  static  unsigned long long aesl_llvm_cbe_995_count = 0;
  static  unsigned long long aesl_llvm_cbe_996_count = 0;
  static  unsigned long long aesl_llvm_cbe_997_count = 0;
  static  unsigned long long aesl_llvm_cbe_998_count = 0;
  static  unsigned long long aesl_llvm_cbe_999_count = 0;
  static  unsigned long long aesl_llvm_cbe_1000_count = 0;
  static  unsigned long long aesl_llvm_cbe_1001_count = 0;
  static  unsigned long long aesl_llvm_cbe_1002_count = 0;
  static  unsigned long long aesl_llvm_cbe_1003_count = 0;
  static  unsigned long long aesl_llvm_cbe_1004_count = 0;
  static  unsigned long long aesl_llvm_cbe_1005_count = 0;
  static  unsigned long long aesl_llvm_cbe_1006_count = 0;
  unsigned int llvm_cbe_tmp__317;
  static  unsigned long long aesl_llvm_cbe_1007_count = 0;
  unsigned long long llvm_cbe_tmp__318;
  static  unsigned long long aesl_llvm_cbe_1008_count = 0;
  signed long long *llvm_cbe_tmp__319;
  static  unsigned long long aesl_llvm_cbe_1009_count = 0;
  unsigned long long llvm_cbe_tmp__320;
  static  unsigned long long aesl_llvm_cbe_1010_count = 0;
  unsigned int llvm_cbe_tmp__321;
  static  unsigned long long aesl_llvm_cbe_1011_count = 0;
  unsigned int llvm_cbe_tmp__322;
  static  unsigned long long aesl_llvm_cbe_1012_count = 0;
  unsigned int llvm_cbe_tmp__323;
  static  unsigned long long aesl_llvm_cbe_1013_count = 0;
  unsigned int llvm_cbe_tmp__324;
  static  unsigned long long aesl_llvm_cbe_1014_count = 0;
  unsigned long long llvm_cbe_tmp__325;
  static  unsigned long long aesl_llvm_cbe_1015_count = 0;
  signed long long *llvm_cbe_tmp__326;
  static  unsigned long long aesl_llvm_cbe_1016_count = 0;
  static  unsigned long long aesl_llvm_cbe_1017_count = 0;
  static  unsigned long long aesl_llvm_cbe_1018_count = 0;
  static  unsigned long long aesl_llvm_cbe_1019_count = 0;
  static  unsigned long long aesl_llvm_cbe_1020_count = 0;
  static  unsigned long long aesl_llvm_cbe_1021_count = 0;
  static  unsigned long long aesl_llvm_cbe_1022_count = 0;
  static  unsigned long long aesl_llvm_cbe_1023_count = 0;
  static  unsigned long long aesl_llvm_cbe_1024_count = 0;
  static  unsigned long long aesl_llvm_cbe_1025_count = 0;
  static  unsigned long long aesl_llvm_cbe_1026_count = 0;
  static  unsigned long long aesl_llvm_cbe_1027_count = 0;
  unsigned int llvm_cbe_tmp__327;
  static  unsigned long long aesl_llvm_cbe_1028_count = 0;
  unsigned long long llvm_cbe_tmp__328;
  static  unsigned long long aesl_llvm_cbe_1029_count = 0;
  signed long long *llvm_cbe_tmp__329;
  static  unsigned long long aesl_llvm_cbe_1030_count = 0;
  unsigned long long llvm_cbe_tmp__330;
  static  unsigned long long aesl_llvm_cbe_1031_count = 0;
  unsigned int llvm_cbe_tmp__331;
  static  unsigned long long aesl_llvm_cbe_1032_count = 0;
  unsigned int llvm_cbe_tmp__332;
  static  unsigned long long aesl_llvm_cbe_1033_count = 0;
  unsigned int llvm_cbe_tmp__333;
  static  unsigned long long aesl_llvm_cbe_1034_count = 0;
  unsigned int llvm_cbe_tmp__334;
  static  unsigned long long aesl_llvm_cbe_1035_count = 0;
  unsigned long long llvm_cbe_tmp__335;
  static  unsigned long long aesl_llvm_cbe_1036_count = 0;
  signed long long *llvm_cbe_tmp__336;
  static  unsigned long long aesl_llvm_cbe_1037_count = 0;
  static  unsigned long long aesl_llvm_cbe_1038_count = 0;
  static  unsigned long long aesl_llvm_cbe_1039_count = 0;
  static  unsigned long long aesl_llvm_cbe_1040_count = 0;
  static  unsigned long long aesl_llvm_cbe_1041_count = 0;
  static  unsigned long long aesl_llvm_cbe_1042_count = 0;
  static  unsigned long long aesl_llvm_cbe_1043_count = 0;
  static  unsigned long long aesl_llvm_cbe_1044_count = 0;
  static  unsigned long long aesl_llvm_cbe_1045_count = 0;
  static  unsigned long long aesl_llvm_cbe_1046_count = 0;
  static  unsigned long long aesl_llvm_cbe_1047_count = 0;
  static  unsigned long long aesl_llvm_cbe_1048_count = 0;
  unsigned int llvm_cbe_tmp__337;
  static  unsigned long long aesl_llvm_cbe_1049_count = 0;
  unsigned long long llvm_cbe_tmp__338;
  static  unsigned long long aesl_llvm_cbe_1050_count = 0;
  signed long long *llvm_cbe_tmp__339;
  static  unsigned long long aesl_llvm_cbe_1051_count = 0;
  unsigned long long llvm_cbe_tmp__340;
  static  unsigned long long aesl_llvm_cbe_1052_count = 0;
  unsigned int llvm_cbe_tmp__341;
  static  unsigned long long aesl_llvm_cbe_1053_count = 0;
  unsigned int llvm_cbe_tmp__342;
  static  unsigned long long aesl_llvm_cbe_1054_count = 0;
  unsigned int llvm_cbe_tmp__343;
  static  unsigned long long aesl_llvm_cbe_1055_count = 0;
  unsigned int llvm_cbe_tmp__344;
  static  unsigned long long aesl_llvm_cbe_1056_count = 0;
  unsigned long long llvm_cbe_tmp__345;
  static  unsigned long long aesl_llvm_cbe_1057_count = 0;
  signed long long *llvm_cbe_tmp__346;
  static  unsigned long long aesl_llvm_cbe_1058_count = 0;
  static  unsigned long long aesl_llvm_cbe_1059_count = 0;
  static  unsigned long long aesl_llvm_cbe_1060_count = 0;
  static  unsigned long long aesl_llvm_cbe_1061_count = 0;
  static  unsigned long long aesl_llvm_cbe_1062_count = 0;
  static  unsigned long long aesl_llvm_cbe_1063_count = 0;
  static  unsigned long long aesl_llvm_cbe_1064_count = 0;
  static  unsigned long long aesl_llvm_cbe_1065_count = 0;
  static  unsigned long long aesl_llvm_cbe_1066_count = 0;
  static  unsigned long long aesl_llvm_cbe_1067_count = 0;
  static  unsigned long long aesl_llvm_cbe_1068_count = 0;
  static  unsigned long long aesl_llvm_cbe_1069_count = 0;
  unsigned int llvm_cbe_tmp__347;
  static  unsigned long long aesl_llvm_cbe_1070_count = 0;
  static  unsigned long long aesl_llvm_cbe_1071_count = 0;
  static  unsigned long long aesl_llvm_cbe_1072_count = 0;
  static  unsigned long long aesl_llvm_cbe_1073_count = 0;
  static  unsigned long long aesl_llvm_cbe_1074_count = 0;
  static  unsigned long long aesl_llvm_cbe_1075_count = 0;
  static  unsigned long long aesl_llvm_cbe_1076_count = 0;
  static  unsigned long long aesl_llvm_cbe_1077_count = 0;
  static  unsigned long long aesl_llvm_cbe_1078_count = 0;
  static  unsigned long long aesl_llvm_cbe_1079_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_1080_count = 0;
  static  unsigned long long aesl_llvm_cbe_1081_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @aesl_internal_pi\n");
  llvm_cbe_storemerge9__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_preheader7;

  do {     /* Syntactic loop '.preheader7' to make GCC happy */
llvm_cbe__2e_preheader7:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge9 = phi i32 [ 0, %%0 ], [ %%26, %%.preheader7  for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_storemerge9_count);
  llvm_cbe_storemerge9 = (unsigned int )llvm_cbe_storemerge9__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge9 = 0x%X",llvm_cbe_storemerge9);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__297);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = urem i32 %%storemerge9, 5, !dbg !15 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_864_count);
  llvm_cbe_tmp__272 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_storemerge9&4294967295ull)) % ((unsigned int )(5u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__272&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = zext i32 %%1 to i64, !dbg !15 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_865_count);
  llvm_cbe_tmp__273 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__272&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__273);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds i64* %%A, i64 %%2, !dbg !15 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_866_count);
  llvm_cbe_tmp__274 = (signed long long *)(&llvm_cbe_A[(((signed long long )llvm_cbe_tmp__273))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__273));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i64* %%3, align 8, !dbg !15 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_867_count);
  llvm_cbe_tmp__275 = (unsigned long long )*llvm_cbe_tmp__274;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__275);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds [25 x i64]* %%tempA, i64 0, i64 %%2, !dbg !15 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_868_count);
  llvm_cbe_tmp__276 = (signed long long *)(&llvm_cbe_tempA[(((signed long long )llvm_cbe_tmp__273))
#ifdef AESL_BC_SIM
 % 25
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__273));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__273) < 25 && "Write access out of array 'tempA' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%4, i64* %%5, align 8, !dbg !15 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_869_count);
  *llvm_cbe_tmp__276 = llvm_cbe_tmp__275;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__275);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = add i32 %%1, 5, !dbg !15 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_880_count);
  llvm_cbe_tmp__277 = (unsigned int )((unsigned int )(llvm_cbe_tmp__272&4294967295ull)) + ((unsigned int )(5u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__277&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = zext i32 %%6 to i64, !dbg !15 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_881_count);
  llvm_cbe_tmp__278 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__277&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__278);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds i64* %%A, i64 %%7, !dbg !15 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_882_count);
  llvm_cbe_tmp__279 = (signed long long *)(&llvm_cbe_A[(((signed long long )llvm_cbe_tmp__278))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__278));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = load i64* %%8, align 8, !dbg !15 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_883_count);
  llvm_cbe_tmp__280 = (unsigned long long )*llvm_cbe_tmp__279;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__280);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds [25 x i64]* %%tempA, i64 0, i64 %%7, !dbg !15 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_884_count);
  llvm_cbe_tmp__281 = (signed long long *)(&llvm_cbe_tempA[(((signed long long )llvm_cbe_tmp__278))
#ifdef AESL_BC_SIM
 % 25
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__278));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__278) < 25 && "Write access out of array 'tempA' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%9, i64* %%10, align 8, !dbg !15 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_885_count);
  *llvm_cbe_tmp__281 = llvm_cbe_tmp__280;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__280);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = add i32 %%1, 10, !dbg !15 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_896_count);
  llvm_cbe_tmp__282 = (unsigned int )((unsigned int )(llvm_cbe_tmp__272&4294967295ull)) + ((unsigned int )(10u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__282&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = zext i32 %%11 to i64, !dbg !15 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_897_count);
  llvm_cbe_tmp__283 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__282&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__283);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds i64* %%A, i64 %%12, !dbg !15 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_898_count);
  llvm_cbe_tmp__284 = (signed long long *)(&llvm_cbe_A[(((signed long long )llvm_cbe_tmp__283))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__283));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load i64* %%13, align 8, !dbg !15 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_899_count);
  llvm_cbe_tmp__285 = (unsigned long long )*llvm_cbe_tmp__284;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__285);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds [25 x i64]* %%tempA, i64 0, i64 %%12, !dbg !15 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_900_count);
  llvm_cbe_tmp__286 = (signed long long *)(&llvm_cbe_tempA[(((signed long long )llvm_cbe_tmp__283))
#ifdef AESL_BC_SIM
 % 25
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__283));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__283) < 25 && "Write access out of array 'tempA' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%14, i64* %%15, align 8, !dbg !15 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_901_count);
  *llvm_cbe_tmp__286 = llvm_cbe_tmp__285;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__285);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = add i32 %%1, 15, !dbg !15 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_912_count);
  llvm_cbe_tmp__287 = (unsigned int )((unsigned int )(llvm_cbe_tmp__272&4294967295ull)) + ((unsigned int )(15u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__287&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = zext i32 %%16 to i64, !dbg !15 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_913_count);
  llvm_cbe_tmp__288 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__287&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__288);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = getelementptr inbounds i64* %%A, i64 %%17, !dbg !15 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_914_count);
  llvm_cbe_tmp__289 = (signed long long *)(&llvm_cbe_A[(((signed long long )llvm_cbe_tmp__288))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__288));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = load i64* %%18, align 8, !dbg !15 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_915_count);
  llvm_cbe_tmp__290 = (unsigned long long )*llvm_cbe_tmp__289;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__290);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = getelementptr inbounds [25 x i64]* %%tempA, i64 0, i64 %%17, !dbg !15 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_916_count);
  llvm_cbe_tmp__291 = (signed long long *)(&llvm_cbe_tempA[(((signed long long )llvm_cbe_tmp__288))
#ifdef AESL_BC_SIM
 % 25
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__288));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__288) < 25 && "Write access out of array 'tempA' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%19, i64* %%20, align 8, !dbg !15 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_917_count);
  *llvm_cbe_tmp__291 = llvm_cbe_tmp__290;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__290);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = add i32 %%1, 20, !dbg !15 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_928_count);
  llvm_cbe_tmp__292 = (unsigned int )((unsigned int )(llvm_cbe_tmp__272&4294967295ull)) + ((unsigned int )(20u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__292&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = zext i32 %%21 to i64, !dbg !15 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_929_count);
  llvm_cbe_tmp__293 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__292&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__293);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = getelementptr inbounds i64* %%A, i64 %%22, !dbg !15 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_930_count);
  llvm_cbe_tmp__294 = (signed long long *)(&llvm_cbe_A[(((signed long long )llvm_cbe_tmp__293))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__293));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = load i64* %%23, align 8, !dbg !15 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_931_count);
  llvm_cbe_tmp__295 = (unsigned long long )*llvm_cbe_tmp__294;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__295);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = getelementptr inbounds [25 x i64]* %%tempA, i64 0, i64 %%22, !dbg !15 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_932_count);
  llvm_cbe_tmp__296 = (signed long long *)(&llvm_cbe_tempA[(((signed long long )llvm_cbe_tmp__293))
#ifdef AESL_BC_SIM
 % 25
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__293));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__293) < 25 && "Write access out of array 'tempA' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%24, i64* %%25, align 8, !dbg !15 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_933_count);
  *llvm_cbe_tmp__296 = llvm_cbe_tmp__295;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__295);
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = add i32 %%storemerge9, 1, !dbg !17 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_944_count);
  llvm_cbe_tmp__297 = (unsigned int )((unsigned int )(llvm_cbe_storemerge9&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__297&4294967295ull)));
  if (((llvm_cbe_tmp__297&4294967295U) == (5u&4294967295U))) {
    llvm_cbe_storemerge16__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  } else {
    llvm_cbe_storemerge9__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__297;   /* for PHI node */
    goto llvm_cbe__2e_preheader7;
  }

  } while (1); /* end of syntactic loop '.preheader7' */
  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge16 = phi i32 [ %%76, %%.preheader ], [ 0, %%.preheader7  for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_storemerge16_count);
  llvm_cbe_storemerge16 = (unsigned int )llvm_cbe_storemerge16__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge16 = 0x%X",llvm_cbe_storemerge16);
printf("\n = 0x%X",llvm_cbe_tmp__347);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = urem i32 %%storemerge16, 5, !dbg !16 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_965_count);
  llvm_cbe_tmp__298 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_storemerge16&4294967295ull)) % ((unsigned int )(5u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__298&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = shl i32 %%storemerge16, 1, !dbg !16 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_966_count);
  llvm_cbe_tmp__299 = (unsigned int )llvm_cbe_storemerge16 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__299);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = zext i32 %%27 to i64, !dbg !16 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_967_count);
  llvm_cbe_tmp__300 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__298&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__300);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = getelementptr inbounds [25 x i64]* %%tempA, i64 0, i64 %%29, !dbg !16 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_968_count);
  llvm_cbe_tmp__301 = (signed long long *)(&llvm_cbe_tempA[(((signed long long )llvm_cbe_tmp__300))
#ifdef AESL_BC_SIM
 % 25
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__300));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__300) < 25)) fprintf(stderr, "%s:%d: warning: Read access out of array 'tempA' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = load i64* %%30, align 8, !dbg !16 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_969_count);
  llvm_cbe_tmp__302 = (unsigned long long )*llvm_cbe_tmp__301;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__302);
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = urem i32 %%28, 5, !dbg !16 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_970_count);
  llvm_cbe_tmp__303 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__299&4294967295ull)) % ((unsigned int )(5u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__303&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = mul i32 %%32, 5, !dbg !16 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_971_count);
  llvm_cbe_tmp__304 = (unsigned int )((unsigned int )(llvm_cbe_tmp__303&4294967295ull)) * ((unsigned int )(5u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__304&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = zext i32 %%33 to i64, !dbg !16 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_972_count);
  llvm_cbe_tmp__305 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__304&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__305);
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = getelementptr inbounds i64* %%A, i64 %%34, !dbg !16 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_973_count);
  llvm_cbe_tmp__306 = (signed long long *)(&llvm_cbe_A[(((signed long long )llvm_cbe_tmp__305))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__305));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%31, i64* %%35, align 8, !dbg !16 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_974_count);
  *llvm_cbe_tmp__306 = llvm_cbe_tmp__302;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__302);
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = add i32 %%27, 5, !dbg !16 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_985_count);
  llvm_cbe_tmp__307 = (unsigned int )((unsigned int )(llvm_cbe_tmp__298&4294967295ull)) + ((unsigned int )(5u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__307&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = zext i32 %%36 to i64, !dbg !16 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_986_count);
  llvm_cbe_tmp__308 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__307&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__308);
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = getelementptr inbounds [25 x i64]* %%tempA, i64 0, i64 %%37, !dbg !16 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_987_count);
  llvm_cbe_tmp__309 = (signed long long *)(&llvm_cbe_tempA[(((signed long long )llvm_cbe_tmp__308))
#ifdef AESL_BC_SIM
 % 25
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__308));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__308) < 25)) fprintf(stderr, "%s:%d: warning: Read access out of array 'tempA' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = load i64* %%38, align 8, !dbg !16 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_988_count);
  llvm_cbe_tmp__310 = (unsigned long long )*llvm_cbe_tmp__309;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__310);
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = add i32 %%28, 3, !dbg !16 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_989_count);
  llvm_cbe_tmp__311 = (unsigned int )((unsigned int )(llvm_cbe_tmp__299&4294967295ull)) + ((unsigned int )(3u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__311&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = urem i32 %%40, 5, !dbg !16 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_990_count);
  llvm_cbe_tmp__312 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__311&4294967295ull)) % ((unsigned int )(5u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__312&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = mul i32 %%41, 5, !dbg !16 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_991_count);
  llvm_cbe_tmp__313 = (unsigned int )((unsigned int )(llvm_cbe_tmp__312&4294967295ull)) * ((unsigned int )(5u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__313&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = add i32 %%42, 1, !dbg !16 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_992_count);
  llvm_cbe_tmp__314 = (unsigned int )((unsigned int )(llvm_cbe_tmp__313&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__314&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = zext i32 %%43 to i64, !dbg !16 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_993_count);
  llvm_cbe_tmp__315 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__314&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__315);
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = getelementptr inbounds i64* %%A, i64 %%44, !dbg !16 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_994_count);
  llvm_cbe_tmp__316 = (signed long long *)(&llvm_cbe_A[(((signed long long )llvm_cbe_tmp__315))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__315));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%39, i64* %%45, align 8, !dbg !16 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_995_count);
  *llvm_cbe_tmp__316 = llvm_cbe_tmp__310;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__310);
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = add i32 %%27, 10, !dbg !16 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_1006_count);
  llvm_cbe_tmp__317 = (unsigned int )((unsigned int )(llvm_cbe_tmp__298&4294967295ull)) + ((unsigned int )(10u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__317&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = zext i32 %%46 to i64, !dbg !16 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_1007_count);
  llvm_cbe_tmp__318 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__317&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__318);
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = getelementptr inbounds [25 x i64]* %%tempA, i64 0, i64 %%47, !dbg !16 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_1008_count);
  llvm_cbe_tmp__319 = (signed long long *)(&llvm_cbe_tempA[(((signed long long )llvm_cbe_tmp__318))
#ifdef AESL_BC_SIM
 % 25
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__318));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__318) < 25)) fprintf(stderr, "%s:%d: warning: Read access out of array 'tempA' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = load i64* %%48, align 8, !dbg !16 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_1009_count);
  llvm_cbe_tmp__320 = (unsigned long long )*llvm_cbe_tmp__319;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__320);
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = add i32 %%28, 6, !dbg !16 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_1010_count);
  llvm_cbe_tmp__321 = (unsigned int )((unsigned int )(llvm_cbe_tmp__299&4294967295ull)) + ((unsigned int )(6u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__321&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = urem i32 %%50, 5, !dbg !16 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_1011_count);
  llvm_cbe_tmp__322 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__321&4294967295ull)) % ((unsigned int )(5u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__322&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = mul i32 %%51, 5, !dbg !16 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_1012_count);
  llvm_cbe_tmp__323 = (unsigned int )((unsigned int )(llvm_cbe_tmp__322&4294967295ull)) * ((unsigned int )(5u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__323&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = add i32 %%52, 2, !dbg !16 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_1013_count);
  llvm_cbe_tmp__324 = (unsigned int )((unsigned int )(llvm_cbe_tmp__323&4294967295ull)) + ((unsigned int )(2u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__324&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = zext i32 %%53 to i64, !dbg !16 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_1014_count);
  llvm_cbe_tmp__325 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__324&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__325);
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = getelementptr inbounds i64* %%A, i64 %%54, !dbg !16 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_1015_count);
  llvm_cbe_tmp__326 = (signed long long *)(&llvm_cbe_A[(((signed long long )llvm_cbe_tmp__325))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__325));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%49, i64* %%55, align 8, !dbg !16 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_1016_count);
  *llvm_cbe_tmp__326 = llvm_cbe_tmp__320;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__320);
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = add i32 %%27, 15, !dbg !16 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_1027_count);
  llvm_cbe_tmp__327 = (unsigned int )((unsigned int )(llvm_cbe_tmp__298&4294967295ull)) + ((unsigned int )(15u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__327&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = zext i32 %%56 to i64, !dbg !16 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_1028_count);
  llvm_cbe_tmp__328 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__327&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__328);
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = getelementptr inbounds [25 x i64]* %%tempA, i64 0, i64 %%57, !dbg !16 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_1029_count);
  llvm_cbe_tmp__329 = (signed long long *)(&llvm_cbe_tempA[(((signed long long )llvm_cbe_tmp__328))
#ifdef AESL_BC_SIM
 % 25
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__328));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__328) < 25)) fprintf(stderr, "%s:%d: warning: Read access out of array 'tempA' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = load i64* %%58, align 8, !dbg !16 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_1030_count);
  llvm_cbe_tmp__330 = (unsigned long long )*llvm_cbe_tmp__329;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__330);
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = add i32 %%28, 9, !dbg !16 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_1031_count);
  llvm_cbe_tmp__331 = (unsigned int )((unsigned int )(llvm_cbe_tmp__299&4294967295ull)) + ((unsigned int )(9u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__331&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%61 = urem i32 %%60, 5, !dbg !16 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_1032_count);
  llvm_cbe_tmp__332 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__331&4294967295ull)) % ((unsigned int )(5u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__332&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = mul i32 %%61, 5, !dbg !16 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_1033_count);
  llvm_cbe_tmp__333 = (unsigned int )((unsigned int )(llvm_cbe_tmp__332&4294967295ull)) * ((unsigned int )(5u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__333&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = add i32 %%62, 3, !dbg !16 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_1034_count);
  llvm_cbe_tmp__334 = (unsigned int )((unsigned int )(llvm_cbe_tmp__333&4294967295ull)) + ((unsigned int )(3u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__334&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%64 = zext i32 %%63 to i64, !dbg !16 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_1035_count);
  llvm_cbe_tmp__335 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__334&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__335);
if (AESL_DEBUG_TRACE)
printf("\n  %%65 = getelementptr inbounds i64* %%A, i64 %%64, !dbg !16 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_1036_count);
  llvm_cbe_tmp__336 = (signed long long *)(&llvm_cbe_A[(((signed long long )llvm_cbe_tmp__335))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__335));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%59, i64* %%65, align 8, !dbg !16 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_1037_count);
  *llvm_cbe_tmp__336 = llvm_cbe_tmp__330;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__330);
if (AESL_DEBUG_TRACE)
printf("\n  %%66 = add i32 %%27, 20, !dbg !16 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_1048_count);
  llvm_cbe_tmp__337 = (unsigned int )((unsigned int )(llvm_cbe_tmp__298&4294967295ull)) + ((unsigned int )(20u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__337&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%67 = zext i32 %%66 to i64, !dbg !16 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_1049_count);
  llvm_cbe_tmp__338 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__337&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__338);
if (AESL_DEBUG_TRACE)
printf("\n  %%68 = getelementptr inbounds [25 x i64]* %%tempA, i64 0, i64 %%67, !dbg !16 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_1050_count);
  llvm_cbe_tmp__339 = (signed long long *)(&llvm_cbe_tempA[(((signed long long )llvm_cbe_tmp__338))
#ifdef AESL_BC_SIM
 % 25
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__338));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__338) < 25)) fprintf(stderr, "%s:%d: warning: Read access out of array 'tempA' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%69 = load i64* %%68, align 8, !dbg !16 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_1051_count);
  llvm_cbe_tmp__340 = (unsigned long long )*llvm_cbe_tmp__339;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__340);
if (AESL_DEBUG_TRACE)
printf("\n  %%70 = add i32 %%28, 12, !dbg !16 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_1052_count);
  llvm_cbe_tmp__341 = (unsigned int )((unsigned int )(llvm_cbe_tmp__299&4294967295ull)) + ((unsigned int )(12u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__341&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%71 = urem i32 %%70, 5, !dbg !16 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_1053_count);
  llvm_cbe_tmp__342 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__341&4294967295ull)) % ((unsigned int )(5u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__342&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%72 = mul i32 %%71, 5, !dbg !16 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_1054_count);
  llvm_cbe_tmp__343 = (unsigned int )((unsigned int )(llvm_cbe_tmp__342&4294967295ull)) * ((unsigned int )(5u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__343&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%73 = add i32 %%72, 4, !dbg !16 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_1055_count);
  llvm_cbe_tmp__344 = (unsigned int )((unsigned int )(llvm_cbe_tmp__343&4294967295ull)) + ((unsigned int )(4u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__344&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%74 = zext i32 %%73 to i64, !dbg !16 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_1056_count);
  llvm_cbe_tmp__345 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__344&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__345);
if (AESL_DEBUG_TRACE)
printf("\n  %%75 = getelementptr inbounds i64* %%A, i64 %%74, !dbg !16 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_1057_count);
  llvm_cbe_tmp__346 = (signed long long *)(&llvm_cbe_A[(((signed long long )llvm_cbe_tmp__345))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__345));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%69, i64* %%75, align 8, !dbg !16 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_1058_count);
  *llvm_cbe_tmp__346 = llvm_cbe_tmp__340;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__340);
if (AESL_DEBUG_TRACE)
printf("\n  %%76 = add i32 %%storemerge16, 1, !dbg !17 for 0x%I64xth hint within @aesl_internal_pi  --> \n", ++aesl_llvm_cbe_1069_count);
  llvm_cbe_tmp__347 = (unsigned int )((unsigned int )(llvm_cbe_storemerge16&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__347&4294967295ull)));
  if (((llvm_cbe_tmp__347&4294967295U) == (5u&4294967295U))) {
    goto llvm_cbe_tmp__348;
  } else {
    llvm_cbe_storemerge16__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__347;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe_tmp__348:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @aesl_internal_pi}\n");
  return;
}


static void aesl_internal_chi(signed long long *llvm_cbe_A) {
  static  unsigned long long aesl_llvm_cbe_1082_count = 0;
  static  unsigned long long aesl_llvm_cbe_1083_count = 0;
  static  unsigned long long aesl_llvm_cbe_1084_count = 0;
  static  unsigned long long aesl_llvm_cbe_1085_count = 0;
  static  unsigned long long aesl_llvm_cbe_1086_count = 0;
  static  unsigned long long aesl_llvm_cbe_1087_count = 0;
  static  unsigned long long aesl_llvm_cbe_1088_count = 0;
  static  unsigned long long aesl_llvm_cbe_1089_count = 0;
  static  unsigned long long aesl_llvm_cbe_1090_count = 0;
  static  unsigned long long aesl_llvm_cbe_1091_count = 0;
  static  unsigned long long aesl_llvm_cbe_1092_count = 0;
  static  unsigned long long aesl_llvm_cbe_1093_count = 0;
  static  unsigned long long aesl_llvm_cbe_1094_count = 0;
  static  unsigned long long aesl_llvm_cbe_1095_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge6_count = 0;
  unsigned int llvm_cbe_storemerge6;
  unsigned int llvm_cbe_storemerge6__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1096_count = 0;
  static  unsigned long long aesl_llvm_cbe_1097_count = 0;
  static  unsigned long long aesl_llvm_cbe_1098_count = 0;
  static  unsigned long long aesl_llvm_cbe_1099_count = 0;
  static  unsigned long long aesl_llvm_cbe_1100_count = 0;
  static  unsigned long long aesl_llvm_cbe_1101_count = 0;
  static  unsigned long long aesl_llvm_cbe_1102_count = 0;
  static  unsigned long long aesl_llvm_cbe_1103_count = 0;
  static  unsigned long long aesl_llvm_cbe_1104_count = 0;
  static  unsigned long long aesl_llvm_cbe_1105_count = 0;
  static  unsigned long long aesl_llvm_cbe_1106_count = 0;
  unsigned int llvm_cbe_tmp__349;
  static  unsigned long long aesl_llvm_cbe_1107_count = 0;
  unsigned int llvm_cbe_tmp__350;
  static  unsigned long long aesl_llvm_cbe_1108_count = 0;
  unsigned long long llvm_cbe_tmp__351;
  static  unsigned long long aesl_llvm_cbe_1109_count = 0;
  signed long long *llvm_cbe_tmp__352;
  static  unsigned long long aesl_llvm_cbe_1110_count = 0;
  unsigned long long llvm_cbe_tmp__353;
  static  unsigned long long aesl_llvm_cbe_1111_count = 0;
  unsigned int llvm_cbe_tmp__354;
  static  unsigned long long aesl_llvm_cbe_1112_count = 0;
  unsigned long long llvm_cbe_tmp__355;
  static  unsigned long long aesl_llvm_cbe_1113_count = 0;
  signed long long *llvm_cbe_tmp__356;
  static  unsigned long long aesl_llvm_cbe_1114_count = 0;
  unsigned long long llvm_cbe_tmp__357;
  static  unsigned long long aesl_llvm_cbe_1115_count = 0;
  unsigned long long llvm_cbe_tmp__358;
  static  unsigned long long aesl_llvm_cbe_1116_count = 0;
  unsigned int llvm_cbe_tmp__359;
  static  unsigned long long aesl_llvm_cbe_1117_count = 0;
  unsigned long long llvm_cbe_tmp__360;
  static  unsigned long long aesl_llvm_cbe_1118_count = 0;
  signed long long *llvm_cbe_tmp__361;
  static  unsigned long long aesl_llvm_cbe_1119_count = 0;
  unsigned long long llvm_cbe_tmp__362;
  static  unsigned long long aesl_llvm_cbe_1120_count = 0;
  unsigned long long llvm_cbe_tmp__363;
  static  unsigned long long aesl_llvm_cbe_1121_count = 0;
  unsigned long long llvm_cbe_tmp__364;
  static  unsigned long long aesl_llvm_cbe_1122_count = 0;
  static  unsigned long long aesl_llvm_cbe_1123_count = 0;
  static  unsigned long long aesl_llvm_cbe_1124_count = 0;
  static  unsigned long long aesl_llvm_cbe_1125_count = 0;
  static  unsigned long long aesl_llvm_cbe_1126_count = 0;
  static  unsigned long long aesl_llvm_cbe_1127_count = 0;
  static  unsigned long long aesl_llvm_cbe_1128_count = 0;
  static  unsigned long long aesl_llvm_cbe_1129_count = 0;
  static  unsigned long long aesl_llvm_cbe_1130_count = 0;
  static  unsigned long long aesl_llvm_cbe_1131_count = 0;
  static  unsigned long long aesl_llvm_cbe_1132_count = 0;
  static  unsigned long long aesl_llvm_cbe_1133_count = 0;
  unsigned long long llvm_cbe_tmp__365;
  static  unsigned long long aesl_llvm_cbe_1134_count = 0;
  unsigned int llvm_cbe_tmp__366;
  static  unsigned long long aesl_llvm_cbe_1135_count = 0;
  unsigned long long llvm_cbe_tmp__367;
  static  unsigned long long aesl_llvm_cbe_1136_count = 0;
  signed long long *llvm_cbe_tmp__368;
  static  unsigned long long aesl_llvm_cbe_1137_count = 0;
  unsigned long long llvm_cbe_tmp__369;
  static  unsigned long long aesl_llvm_cbe_1138_count = 0;
  unsigned long long llvm_cbe_tmp__370;
  static  unsigned long long aesl_llvm_cbe_1139_count = 0;
  unsigned long long llvm_cbe_tmp__371;
  static  unsigned long long aesl_llvm_cbe_1140_count = 0;
  static  unsigned long long aesl_llvm_cbe_1141_count = 0;
  static  unsigned long long aesl_llvm_cbe_1142_count = 0;
  static  unsigned long long aesl_llvm_cbe_1143_count = 0;
  static  unsigned long long aesl_llvm_cbe_1144_count = 0;
  static  unsigned long long aesl_llvm_cbe_1145_count = 0;
  static  unsigned long long aesl_llvm_cbe_1146_count = 0;
  static  unsigned long long aesl_llvm_cbe_1147_count = 0;
  static  unsigned long long aesl_llvm_cbe_1148_count = 0;
  static  unsigned long long aesl_llvm_cbe_1149_count = 0;
  static  unsigned long long aesl_llvm_cbe_1150_count = 0;
  static  unsigned long long aesl_llvm_cbe_1151_count = 0;
  unsigned long long llvm_cbe_tmp__372;
  static  unsigned long long aesl_llvm_cbe_1152_count = 0;
  unsigned int llvm_cbe_tmp__373;
  static  unsigned long long aesl_llvm_cbe_1153_count = 0;
  unsigned long long llvm_cbe_tmp__374;
  static  unsigned long long aesl_llvm_cbe_1154_count = 0;
  signed long long *llvm_cbe_tmp__375;
  static  unsigned long long aesl_llvm_cbe_1155_count = 0;
  unsigned long long llvm_cbe_tmp__376;
  static  unsigned long long aesl_llvm_cbe_1156_count = 0;
  unsigned long long llvm_cbe_tmp__377;
  static  unsigned long long aesl_llvm_cbe_1157_count = 0;
  unsigned long long llvm_cbe_tmp__378;
  static  unsigned long long aesl_llvm_cbe_1158_count = 0;
  static  unsigned long long aesl_llvm_cbe_1159_count = 0;
  static  unsigned long long aesl_llvm_cbe_1160_count = 0;
  static  unsigned long long aesl_llvm_cbe_1161_count = 0;
  static  unsigned long long aesl_llvm_cbe_1162_count = 0;
  static  unsigned long long aesl_llvm_cbe_1163_count = 0;
  static  unsigned long long aesl_llvm_cbe_1164_count = 0;
  static  unsigned long long aesl_llvm_cbe_1165_count = 0;
  static  unsigned long long aesl_llvm_cbe_1166_count = 0;
  static  unsigned long long aesl_llvm_cbe_1167_count = 0;
  static  unsigned long long aesl_llvm_cbe_1168_count = 0;
  static  unsigned long long aesl_llvm_cbe_1169_count = 0;
  unsigned long long llvm_cbe_tmp__379;
  static  unsigned long long aesl_llvm_cbe_1170_count = 0;
  unsigned long long llvm_cbe_tmp__380;
  static  unsigned long long aesl_llvm_cbe_1171_count = 0;
  unsigned long long llvm_cbe_tmp__381;
  static  unsigned long long aesl_llvm_cbe_1172_count = 0;
  static  unsigned long long aesl_llvm_cbe_1173_count = 0;
  static  unsigned long long aesl_llvm_cbe_1174_count = 0;
  static  unsigned long long aesl_llvm_cbe_1175_count = 0;
  static  unsigned long long aesl_llvm_cbe_1176_count = 0;
  static  unsigned long long aesl_llvm_cbe_1177_count = 0;
  static  unsigned long long aesl_llvm_cbe_1178_count = 0;
  static  unsigned long long aesl_llvm_cbe_1179_count = 0;
  static  unsigned long long aesl_llvm_cbe_1180_count = 0;
  static  unsigned long long aesl_llvm_cbe_1181_count = 0;
  static  unsigned long long aesl_llvm_cbe_1182_count = 0;
  static  unsigned long long aesl_llvm_cbe_1183_count = 0;
  unsigned long long llvm_cbe_tmp__382;
  static  unsigned long long aesl_llvm_cbe_1184_count = 0;
  unsigned long long llvm_cbe_tmp__383;
  static  unsigned long long aesl_llvm_cbe_1185_count = 0;
  unsigned long long llvm_cbe_tmp__384;
  static  unsigned long long aesl_llvm_cbe_1186_count = 0;
  static  unsigned long long aesl_llvm_cbe_1187_count = 0;
  static  unsigned long long aesl_llvm_cbe_1188_count = 0;
  static  unsigned long long aesl_llvm_cbe_1189_count = 0;
  static  unsigned long long aesl_llvm_cbe_1190_count = 0;
  static  unsigned long long aesl_llvm_cbe_1191_count = 0;
  static  unsigned long long aesl_llvm_cbe_1192_count = 0;
  static  unsigned long long aesl_llvm_cbe_1193_count = 0;
  static  unsigned long long aesl_llvm_cbe_1194_count = 0;
  static  unsigned long long aesl_llvm_cbe_1195_count = 0;
  static  unsigned long long aesl_llvm_cbe_1196_count = 0;
  static  unsigned long long aesl_llvm_cbe_1197_count = 0;
  static  unsigned long long aesl_llvm_cbe_1198_count = 0;
  static  unsigned long long aesl_llvm_cbe_1199_count = 0;
  static  unsigned long long aesl_llvm_cbe_1200_count = 0;
  static  unsigned long long aesl_llvm_cbe_1201_count = 0;
  static  unsigned long long aesl_llvm_cbe_1202_count = 0;
  static  unsigned long long aesl_llvm_cbe_1203_count = 0;
  static  unsigned long long aesl_llvm_cbe_1204_count = 0;
  static  unsigned long long aesl_llvm_cbe_1205_count = 0;
  static  unsigned long long aesl_llvm_cbe_1206_count = 0;
  static  unsigned long long aesl_llvm_cbe_1207_count = 0;
  static  unsigned long long aesl_llvm_cbe_1208_count = 0;
  static  unsigned long long aesl_llvm_cbe_1209_count = 0;
  static  unsigned long long aesl_llvm_cbe_1210_count = 0;
  static  unsigned long long aesl_llvm_cbe_1211_count = 0;
  static  unsigned long long aesl_llvm_cbe_1212_count = 0;
  static  unsigned long long aesl_llvm_cbe_1213_count = 0;
  static  unsigned long long aesl_llvm_cbe_1214_count = 0;
  static  unsigned long long aesl_llvm_cbe_1215_count = 0;
  static  unsigned long long aesl_llvm_cbe_1216_count = 0;
  static  unsigned long long aesl_llvm_cbe_1217_count = 0;
  static  unsigned long long aesl_llvm_cbe_1218_count = 0;
  static  unsigned long long aesl_llvm_cbe_1219_count = 0;
  static  unsigned long long aesl_llvm_cbe_1220_count = 0;
  static  unsigned long long aesl_llvm_cbe_1221_count = 0;
  static  unsigned long long aesl_llvm_cbe_1222_count = 0;
  static  unsigned long long aesl_llvm_cbe_1223_count = 0;
  static  unsigned long long aesl_llvm_cbe_1224_count = 0;
  static  unsigned long long aesl_llvm_cbe_1225_count = 0;
  static  unsigned long long aesl_llvm_cbe_1226_count = 0;
  static  unsigned long long aesl_llvm_cbe_1227_count = 0;
  static  unsigned long long aesl_llvm_cbe_1228_count = 0;
  static  unsigned long long aesl_llvm_cbe_1229_count = 0;
  static  unsigned long long aesl_llvm_cbe_1230_count = 0;
  static  unsigned long long aesl_llvm_cbe_1231_count = 0;
  static  unsigned long long aesl_llvm_cbe_1232_count = 0;
  static  unsigned long long aesl_llvm_cbe_1233_count = 0;
  static  unsigned long long aesl_llvm_cbe_1234_count = 0;
  static  unsigned long long aesl_llvm_cbe_1235_count = 0;
  static  unsigned long long aesl_llvm_cbe_1236_count = 0;
  static  unsigned long long aesl_llvm_cbe_1237_count = 0;
  static  unsigned long long aesl_llvm_cbe_1238_count = 0;
  static  unsigned long long aesl_llvm_cbe_1239_count = 0;
  static  unsigned long long aesl_llvm_cbe_1240_count = 0;
  static  unsigned long long aesl_llvm_cbe_1241_count = 0;
  static  unsigned long long aesl_llvm_cbe_1242_count = 0;
  static  unsigned long long aesl_llvm_cbe_1243_count = 0;
  static  unsigned long long aesl_llvm_cbe_1244_count = 0;
  static  unsigned long long aesl_llvm_cbe_1245_count = 0;
  static  unsigned long long aesl_llvm_cbe_1246_count = 0;
  static  unsigned long long aesl_llvm_cbe_1247_count = 0;
  static  unsigned long long aesl_llvm_cbe_1248_count = 0;
  static  unsigned long long aesl_llvm_cbe_1249_count = 0;
  static  unsigned long long aesl_llvm_cbe_1250_count = 0;
  static  unsigned long long aesl_llvm_cbe_1251_count = 0;
  static  unsigned long long aesl_llvm_cbe_1252_count = 0;
  static  unsigned long long aesl_llvm_cbe_1253_count = 0;
  static  unsigned long long aesl_llvm_cbe_1254_count = 0;
  static  unsigned long long aesl_llvm_cbe_1255_count = 0;
  static  unsigned long long aesl_llvm_cbe_1256_count = 0;
  static  unsigned long long aesl_llvm_cbe_1257_count = 0;
  static  unsigned long long aesl_llvm_cbe_1258_count = 0;
  static  unsigned long long aesl_llvm_cbe_1259_count = 0;
  static  unsigned long long aesl_llvm_cbe_1260_count = 0;
  static  unsigned long long aesl_llvm_cbe_1261_count = 0;
  static  unsigned long long aesl_llvm_cbe_1262_count = 0;
  static  unsigned long long aesl_llvm_cbe_1263_count = 0;
  static  unsigned long long aesl_llvm_cbe_1264_count = 0;
  static  unsigned long long aesl_llvm_cbe_1265_count = 0;
  static  unsigned long long aesl_llvm_cbe_1266_count = 0;
  static  unsigned long long aesl_llvm_cbe_1267_count = 0;
  unsigned int llvm_cbe_tmp__385;
  static  unsigned long long aesl_llvm_cbe_1268_count = 0;
  static  unsigned long long aesl_llvm_cbe_1269_count = 0;
  static  unsigned long long aesl_llvm_cbe_1270_count = 0;
  static  unsigned long long aesl_llvm_cbe_1271_count = 0;
  static  unsigned long long aesl_llvm_cbe_1272_count = 0;
  static  unsigned long long aesl_llvm_cbe_1273_count = 0;
  static  unsigned long long aesl_llvm_cbe_1274_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_1275_count = 0;
  static  unsigned long long aesl_llvm_cbe_1276_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @aesl_internal_chi\n");
  llvm_cbe_storemerge6__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_preheader4;

  do {     /* Syntactic loop '.preheader4' to make GCC happy */
llvm_cbe__2e_preheader4:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge6 = phi i32 [ 0, %%0 ], [ %%37, %%.preheader4  for 0x%I64xth hint within @aesl_internal_chi  --> \n", ++aesl_llvm_cbe_storemerge6_count);
  llvm_cbe_storemerge6 = (unsigned int )llvm_cbe_storemerge6__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge6 = 0x%X",llvm_cbe_storemerge6);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__385);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = urem i32 %%storemerge6, 5, !dbg !15 for 0x%I64xth hint within @aesl_internal_chi  --> \n", ++aesl_llvm_cbe_1106_count);
  llvm_cbe_tmp__349 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_storemerge6&4294967295ull)) % ((unsigned int )(5u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__349&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = mul i32 %%1, 5, !dbg !15 for 0x%I64xth hint within @aesl_internal_chi  --> \n", ++aesl_llvm_cbe_1107_count);
  llvm_cbe_tmp__350 = (unsigned int )((unsigned int )(llvm_cbe_tmp__349&4294967295ull)) * ((unsigned int )(5u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__350&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = zext i32 %%2 to i64, !dbg !15 for 0x%I64xth hint within @aesl_internal_chi  --> \n", ++aesl_llvm_cbe_1108_count);
  llvm_cbe_tmp__351 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__350&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__351);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds i64* %%A, i64 %%3, !dbg !15 for 0x%I64xth hint within @aesl_internal_chi  --> \n", ++aesl_llvm_cbe_1109_count);
  llvm_cbe_tmp__352 = (signed long long *)(&llvm_cbe_A[(((signed long long )llvm_cbe_tmp__351))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__351));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load i64* %%4, align 8, !dbg !15 for 0x%I64xth hint within @aesl_internal_chi  --> \n", ++aesl_llvm_cbe_1110_count);
  llvm_cbe_tmp__353 = (unsigned long long )*llvm_cbe_tmp__352;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__353);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = add i32 %%2, 1, !dbg !15 for 0x%I64xth hint within @aesl_internal_chi  --> \n", ++aesl_llvm_cbe_1111_count);
  llvm_cbe_tmp__354 = (unsigned int )((unsigned int )(llvm_cbe_tmp__350&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__354&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = zext i32 %%6 to i64, !dbg !15 for 0x%I64xth hint within @aesl_internal_chi  --> \n", ++aesl_llvm_cbe_1112_count);
  llvm_cbe_tmp__355 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__354&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__355);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds i64* %%A, i64 %%7, !dbg !15 for 0x%I64xth hint within @aesl_internal_chi  --> \n", ++aesl_llvm_cbe_1113_count);
  llvm_cbe_tmp__356 = (signed long long *)(&llvm_cbe_A[(((signed long long )llvm_cbe_tmp__355))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__355));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = load i64* %%8, align 8, !dbg !15 for 0x%I64xth hint within @aesl_internal_chi  --> \n", ++aesl_llvm_cbe_1114_count);
  llvm_cbe_tmp__357 = (unsigned long long )*llvm_cbe_tmp__356;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__357);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = xor i64 %%9, -1, !dbg !15 for 0x%I64xth hint within @aesl_internal_chi  --> \n", ++aesl_llvm_cbe_1115_count);
  llvm_cbe_tmp__358 = (unsigned long long )llvm_cbe_tmp__357 ^ 18446744073709551615ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__358);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = add i32 %%2, 2, !dbg !15 for 0x%I64xth hint within @aesl_internal_chi  --> \n", ++aesl_llvm_cbe_1116_count);
  llvm_cbe_tmp__359 = (unsigned int )((unsigned int )(llvm_cbe_tmp__350&4294967295ull)) + ((unsigned int )(2u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__359&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = zext i32 %%11 to i64, !dbg !15 for 0x%I64xth hint within @aesl_internal_chi  --> \n", ++aesl_llvm_cbe_1117_count);
  llvm_cbe_tmp__360 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__359&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__360);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds i64* %%A, i64 %%12, !dbg !15 for 0x%I64xth hint within @aesl_internal_chi  --> \n", ++aesl_llvm_cbe_1118_count);
  llvm_cbe_tmp__361 = (signed long long *)(&llvm_cbe_A[(((signed long long )llvm_cbe_tmp__360))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__360));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load i64* %%13, align 8, !dbg !15 for 0x%I64xth hint within @aesl_internal_chi  --> \n", ++aesl_llvm_cbe_1119_count);
  llvm_cbe_tmp__362 = (unsigned long long )*llvm_cbe_tmp__361;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__362);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = and i64 %%14, %%10, !dbg !15 for 0x%I64xth hint within @aesl_internal_chi  --> \n", ++aesl_llvm_cbe_1120_count);
  llvm_cbe_tmp__363 = (unsigned long long )llvm_cbe_tmp__362 & llvm_cbe_tmp__358;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__363);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = xor i64 %%15, %%5, !dbg !15 for 0x%I64xth hint within @aesl_internal_chi  --> \n", ++aesl_llvm_cbe_1121_count);
  llvm_cbe_tmp__364 = (unsigned long long )llvm_cbe_tmp__363 ^ llvm_cbe_tmp__353;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__364);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = xor i64 %%14, -1, !dbg !15 for 0x%I64xth hint within @aesl_internal_chi  --> \n", ++aesl_llvm_cbe_1133_count);
  llvm_cbe_tmp__365 = (unsigned long long )llvm_cbe_tmp__362 ^ 18446744073709551615ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__365);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = add i32 %%2, 3, !dbg !15 for 0x%I64xth hint within @aesl_internal_chi  --> \n", ++aesl_llvm_cbe_1134_count);
  llvm_cbe_tmp__366 = (unsigned int )((unsigned int )(llvm_cbe_tmp__350&4294967295ull)) + ((unsigned int )(3u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__366&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = zext i32 %%18 to i64, !dbg !15 for 0x%I64xth hint within @aesl_internal_chi  --> \n", ++aesl_llvm_cbe_1135_count);
  llvm_cbe_tmp__367 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__366&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__367);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = getelementptr inbounds i64* %%A, i64 %%19, !dbg !15 for 0x%I64xth hint within @aesl_internal_chi  --> \n", ++aesl_llvm_cbe_1136_count);
  llvm_cbe_tmp__368 = (signed long long *)(&llvm_cbe_A[(((signed long long )llvm_cbe_tmp__367))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__367));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = load i64* %%20, align 8, !dbg !15 for 0x%I64xth hint within @aesl_internal_chi  --> \n", ++aesl_llvm_cbe_1137_count);
  llvm_cbe_tmp__369 = (unsigned long long )*llvm_cbe_tmp__368;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__369);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = and i64 %%21, %%17, !dbg !15 for 0x%I64xth hint within @aesl_internal_chi  --> \n", ++aesl_llvm_cbe_1138_count);
  llvm_cbe_tmp__370 = (unsigned long long )llvm_cbe_tmp__369 & llvm_cbe_tmp__365;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__370);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = xor i64 %%22, %%9, !dbg !15 for 0x%I64xth hint within @aesl_internal_chi  --> \n", ++aesl_llvm_cbe_1139_count);
  llvm_cbe_tmp__371 = (unsigned long long )llvm_cbe_tmp__370 ^ llvm_cbe_tmp__357;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__371);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = xor i64 %%21, -1, !dbg !15 for 0x%I64xth hint within @aesl_internal_chi  --> \n", ++aesl_llvm_cbe_1151_count);
  llvm_cbe_tmp__372 = (unsigned long long )llvm_cbe_tmp__369 ^ 18446744073709551615ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__372);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = add i32 %%2, 4, !dbg !15 for 0x%I64xth hint within @aesl_internal_chi  --> \n", ++aesl_llvm_cbe_1152_count);
  llvm_cbe_tmp__373 = (unsigned int )((unsigned int )(llvm_cbe_tmp__350&4294967295ull)) + ((unsigned int )(4u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__373&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = zext i32 %%25 to i64, !dbg !15 for 0x%I64xth hint within @aesl_internal_chi  --> \n", ++aesl_llvm_cbe_1153_count);
  llvm_cbe_tmp__374 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__373&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__374);
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = getelementptr inbounds i64* %%A, i64 %%26, !dbg !15 for 0x%I64xth hint within @aesl_internal_chi  --> \n", ++aesl_llvm_cbe_1154_count);
  llvm_cbe_tmp__375 = (signed long long *)(&llvm_cbe_A[(((signed long long )llvm_cbe_tmp__374))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__374));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = load i64* %%27, align 8, !dbg !15 for 0x%I64xth hint within @aesl_internal_chi  --> \n", ++aesl_llvm_cbe_1155_count);
  llvm_cbe_tmp__376 = (unsigned long long )*llvm_cbe_tmp__375;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__376);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = and i64 %%28, %%24, !dbg !15 for 0x%I64xth hint within @aesl_internal_chi  --> \n", ++aesl_llvm_cbe_1156_count);
  llvm_cbe_tmp__377 = (unsigned long long )llvm_cbe_tmp__376 & llvm_cbe_tmp__372;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__377);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = xor i64 %%29, %%14, !dbg !15 for 0x%I64xth hint within @aesl_internal_chi  --> \n", ++aesl_llvm_cbe_1157_count);
  llvm_cbe_tmp__378 = (unsigned long long )llvm_cbe_tmp__377 ^ llvm_cbe_tmp__362;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__378);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = xor i64 %%28, -1, !dbg !15 for 0x%I64xth hint within @aesl_internal_chi  --> \n", ++aesl_llvm_cbe_1169_count);
  llvm_cbe_tmp__379 = (unsigned long long )llvm_cbe_tmp__376 ^ 18446744073709551615ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__379);
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = and i64 %%5, %%31, !dbg !15 for 0x%I64xth hint within @aesl_internal_chi  --> \n", ++aesl_llvm_cbe_1170_count);
  llvm_cbe_tmp__380 = (unsigned long long )llvm_cbe_tmp__353 & llvm_cbe_tmp__379;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__380);
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = xor i64 %%32, %%21, !dbg !15 for 0x%I64xth hint within @aesl_internal_chi  --> \n", ++aesl_llvm_cbe_1171_count);
  llvm_cbe_tmp__381 = (unsigned long long )llvm_cbe_tmp__380 ^ llvm_cbe_tmp__369;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__381);
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = xor i64 %%5, -1, !dbg !15 for 0x%I64xth hint within @aesl_internal_chi  --> \n", ++aesl_llvm_cbe_1183_count);
  llvm_cbe_tmp__382 = (unsigned long long )llvm_cbe_tmp__353 ^ 18446744073709551615ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__382);
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = and i64 %%9, %%34, !dbg !15 for 0x%I64xth hint within @aesl_internal_chi  --> \n", ++aesl_llvm_cbe_1184_count);
  llvm_cbe_tmp__383 = (unsigned long long )llvm_cbe_tmp__357 & llvm_cbe_tmp__382;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__383);
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = xor i64 %%35, %%28, !dbg !15 for 0x%I64xth hint within @aesl_internal_chi  --> \n", ++aesl_llvm_cbe_1185_count);
  llvm_cbe_tmp__384 = (unsigned long long )llvm_cbe_tmp__383 ^ llvm_cbe_tmp__376;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__384);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%16, i64* %%4, align 8, !dbg !16 for 0x%I64xth hint within @aesl_internal_chi  --> \n", ++aesl_llvm_cbe_1207_count);
  *llvm_cbe_tmp__352 = llvm_cbe_tmp__364;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__364);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%23, i64* %%8, align 8, !dbg !16 for 0x%I64xth hint within @aesl_internal_chi  --> \n", ++aesl_llvm_cbe_1219_count);
  *llvm_cbe_tmp__356 = llvm_cbe_tmp__371;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__371);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%30, i64* %%13, align 8, !dbg !16 for 0x%I64xth hint within @aesl_internal_chi  --> \n", ++aesl_llvm_cbe_1231_count);
  *llvm_cbe_tmp__361 = llvm_cbe_tmp__378;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__378);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%33, i64* %%20, align 8, !dbg !16 for 0x%I64xth hint within @aesl_internal_chi  --> \n", ++aesl_llvm_cbe_1243_count);
  *llvm_cbe_tmp__368 = llvm_cbe_tmp__381;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__381);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%36, i64* %%27, align 8, !dbg !16 for 0x%I64xth hint within @aesl_internal_chi  --> \n", ++aesl_llvm_cbe_1255_count);
  *llvm_cbe_tmp__375 = llvm_cbe_tmp__384;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__384);
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = add i32 %%storemerge6, 1, !dbg !17 for 0x%I64xth hint within @aesl_internal_chi  --> \n", ++aesl_llvm_cbe_1267_count);
  llvm_cbe_tmp__385 = (unsigned int )((unsigned int )(llvm_cbe_storemerge6&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__385&4294967295ull)));
  if (((llvm_cbe_tmp__385&4294967295U) == (5u&4294967295U))) {
    goto llvm_cbe_tmp__386;
  } else {
    llvm_cbe_storemerge6__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__385;   /* for PHI node */
    goto llvm_cbe__2e_preheader4;
  }

  } while (1); /* end of syntactic loop '.preheader4' */
llvm_cbe_tmp__386:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @aesl_internal_chi}\n");
  return;
}


static void aesl_internal_iota(signed long long *llvm_cbe_A, signed int llvm_cbe_indexRound) {
  static  unsigned long long aesl_llvm_cbe_1277_count = 0;
  static  unsigned long long aesl_llvm_cbe_1278_count = 0;
  static  unsigned long long aesl_llvm_cbe_1279_count = 0;
  static  unsigned long long aesl_llvm_cbe_1280_count = 0;
  unsigned long long llvm_cbe_tmp__387;
  static  unsigned long long aesl_llvm_cbe_1281_count = 0;
  signed long long *llvm_cbe_tmp__388;
  static  unsigned long long aesl_llvm_cbe_1282_count = 0;
  unsigned long long llvm_cbe_tmp__389;
  static  unsigned long long aesl_llvm_cbe_1283_count = 0;
  static  unsigned long long aesl_llvm_cbe_1284_count = 0;
  unsigned long long llvm_cbe_tmp__390;
  static  unsigned long long aesl_llvm_cbe_1285_count = 0;
  unsigned long long llvm_cbe_tmp__391;
  static  unsigned long long aesl_llvm_cbe_1286_count = 0;
  static  unsigned long long aesl_llvm_cbe_1287_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @aesl_internal_iota\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = zext i32 %%indexRound to i64, !dbg !16 for 0x%I64xth hint within @aesl_internal_iota  --> \n", ++aesl_llvm_cbe_1280_count);
  llvm_cbe_tmp__387 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_indexRound&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__387);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds [24 x i64]* @aesl_internal_KeccakRoundConstants, i64 0, i64 %%1, !dbg !16 for 0x%I64xth hint within @aesl_internal_iota  --> \n", ++aesl_llvm_cbe_1281_count);
  llvm_cbe_tmp__388 = (signed long long *)(&aesl_internal_KeccakRoundConstants[(((signed long long )llvm_cbe_tmp__387))
#ifdef AESL_BC_SIM
 % 24
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__387));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__387) < 24)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_KeccakRoundConstants' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = load i64* %%2, align 8, !dbg !16 for 0x%I64xth hint within @aesl_internal_iota  --> \n", ++aesl_llvm_cbe_1282_count);
  llvm_cbe_tmp__389 = (unsigned long long )*llvm_cbe_tmp__388;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__389);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i64* %%A, align 8, !dbg !16 for 0x%I64xth hint within @aesl_internal_iota  --> \n", ++aesl_llvm_cbe_1284_count);
  llvm_cbe_tmp__390 = (unsigned long long )*llvm_cbe_A;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__390);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = xor i64 %%4, %%3, !dbg !16 for 0x%I64xth hint within @aesl_internal_iota  --> \n", ++aesl_llvm_cbe_1285_count);
  llvm_cbe_tmp__391 = (unsigned long long )llvm_cbe_tmp__390 ^ llvm_cbe_tmp__389;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__391);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%5, i64* %%A, align 8, !dbg !16 for 0x%I64xth hint within @aesl_internal_iota  --> \n", ++aesl_llvm_cbe_1286_count);
  *llvm_cbe_A = llvm_cbe_tmp__391;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__391);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @aesl_internal_iota}\n");
  return;
}


void KeccakP1600_ExtractBytes( char *llvm_cbe_state,  char *llvm_cbe_data, signed int llvm_cbe_offset, signed int llvm_cbe_length) {
  static  unsigned long long aesl_llvm_cbe_1288_count = 0;
  static  unsigned long long aesl_llvm_cbe_1289_count = 0;
  static  unsigned long long aesl_llvm_cbe_1290_count = 0;
  static  unsigned long long aesl_llvm_cbe_1291_count = 0;
  static  unsigned long long aesl_llvm_cbe_1292_count = 0;
  static  unsigned long long aesl_llvm_cbe_1293_count = 0;
  static  unsigned long long aesl_llvm_cbe_1294_count = 0;
  static  unsigned long long aesl_llvm_cbe_1295_count = 0;
  static  unsigned long long aesl_llvm_cbe_1296_count = 0;
  static  unsigned long long aesl_llvm_cbe_1297_count = 0;
  static  unsigned long long aesl_llvm_cbe_1298_count = 0;
  static  unsigned long long aesl_llvm_cbe_1299_count = 0;
  static  unsigned long long aesl_llvm_cbe_1300_count = 0;
  static  unsigned long long aesl_llvm_cbe_1301_count = 0;
  static  unsigned long long aesl_llvm_cbe_1302_count = 0;
  static  unsigned long long aesl_llvm_cbe_1303_count = 0;
  unsigned int llvm_cbe_tmp__392;
  static  unsigned long long aesl_llvm_cbe_1304_count = 0;
  static  unsigned long long aesl_llvm_cbe_1305_count = 0;
  static  unsigned long long aesl_llvm_cbe_1306_count = 0;
  static  unsigned long long aesl_llvm_cbe_1307_count = 0;
  static  unsigned long long aesl_llvm_cbe_1308_count = 0;
  static  unsigned long long aesl_llvm_cbe_1309_count = 0;
  static  unsigned long long aesl_llvm_cbe_1310_count = 0;
  static  unsigned long long aesl_llvm_cbe_1311_count = 0;
  static  unsigned long long aesl_llvm_cbe_1312_count = 0;
  static  unsigned long long aesl_llvm_cbe_1313_count = 0;
  static  unsigned long long aesl_llvm_cbe_1314_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1315_count = 0;
  unsigned int llvm_cbe_tmp__393;
  static  unsigned long long aesl_llvm_cbe_1316_count = 0;
  unsigned long long llvm_cbe_tmp__394;
  static  unsigned long long aesl_llvm_cbe_1317_count = 0;
   char *llvm_cbe_tmp__395;
  static  unsigned long long aesl_llvm_cbe_1318_count = 0;
  unsigned char llvm_cbe_tmp__396;
  static  unsigned long long aesl_llvm_cbe_1319_count = 0;
  unsigned long long llvm_cbe_tmp__397;
  static  unsigned long long aesl_llvm_cbe_1320_count = 0;
   char *llvm_cbe_tmp__398;
  static  unsigned long long aesl_llvm_cbe_1321_count = 0;
  static  unsigned long long aesl_llvm_cbe_1322_count = 0;
  unsigned int llvm_cbe_tmp__399;
  static  unsigned long long aesl_llvm_cbe_1323_count = 0;
  static  unsigned long long aesl_llvm_cbe_1324_count = 0;
  static  unsigned long long aesl_llvm_cbe_1325_count = 0;
  static  unsigned long long aesl_llvm_cbe_1326_count = 0;
  static  unsigned long long aesl_llvm_cbe_1327_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_1328_count = 0;
  static  unsigned long long aesl_llvm_cbe_1329_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @KeccakP1600_ExtractBytes\n");
  if ((((unsigned int )llvm_cbe_offset&4294967295U) < ((unsigned int )200u&4294967295U))) {
    goto llvm_cbe_tmp__400;
  } else {
    goto llvm_cbe_tmp__401;
  }

llvm_cbe_tmp__401:
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @_assert(i8* getelementptr inbounds ([13 x i8]* @aesl_internal_.str, i64 0, i64 0), i8* getelementptr inbounds ([50 x i8]* @aesl_internal_.str1, i64 0, i64 0), i32 389) nounwind, !dbg !17 for 0x%I64xth hint within @KeccakP1600_ExtractBytes  --> \n", ++aesl_llvm_cbe_1301_count);
   /*tail*/ _assert(( char *)((&aesl_internal__OC_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 13
#endif
])), ( char *)((&aesl_internal__OC_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 50
#endif
])), 389u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",389u);
}
  goto llvm_cbe_tmp__400;

llvm_cbe_tmp__400:
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = add i32 %%length, %%offset, !dbg !16 for 0x%I64xth hint within @KeccakP1600_ExtractBytes  --> \n", ++aesl_llvm_cbe_1303_count);
  llvm_cbe_tmp__392 = (unsigned int )((unsigned int )(llvm_cbe_length&4294967295ull)) + ((unsigned int )(llvm_cbe_offset&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__392&4294967295ull)));
  if ((((unsigned int )llvm_cbe_tmp__392&4294967295U) < ((unsigned int )201u&4294967295U))) {
    goto llvm_cbe_tmp__402;
  } else {
    goto llvm_cbe_tmp__403;
  }

llvm_cbe_tmp__403:
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @_assert(i8* getelementptr inbounds ([21 x i8]* @aesl_internal_.str2, i64 0, i64 0), i8* getelementptr inbounds ([50 x i8]* @aesl_internal_.str1, i64 0, i64 0), i32 390) nounwind, !dbg !17 for 0x%I64xth hint within @KeccakP1600_ExtractBytes  --> \n", ++aesl_llvm_cbe_1306_count);
   /*tail*/ _assert(( char *)((&aesl_internal__OC_str2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 21
#endif
])), ( char *)((&aesl_internal__OC_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 50
#endif
])), 390u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",390u);
}
  goto llvm_cbe_tmp__402;

llvm_cbe_tmp__402:
  if (((llvm_cbe_length&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ %%15, %%.lr.ph ], [ 0, %%7  for 0x%I64xth hint within @KeccakP1600_ExtractBytes  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",llvm_cbe_tmp__399);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = add i32 %%storemerge1, %%offset, !dbg !15 for 0x%I64xth hint within @KeccakP1600_ExtractBytes  --> \n", ++aesl_llvm_cbe_1315_count);
  llvm_cbe_tmp__393 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(llvm_cbe_offset&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__393&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = zext i32 %%9 to i64, !dbg !15 for 0x%I64xth hint within @KeccakP1600_ExtractBytes  --> \n", ++aesl_llvm_cbe_1316_count);
  llvm_cbe_tmp__394 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__393&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__394);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds i8* %%state, i64 %%10, !dbg !15 for 0x%I64xth hint within @KeccakP1600_ExtractBytes  --> \n", ++aesl_llvm_cbe_1317_count);
  llvm_cbe_tmp__395 = ( char *)(&llvm_cbe_state[(((signed long long )llvm_cbe_tmp__394))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__394));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = load i8* %%11, align 1, !dbg !15 for 0x%I64xth hint within @KeccakP1600_ExtractBytes  --> \n", ++aesl_llvm_cbe_1318_count);
  llvm_cbe_tmp__396 = (unsigned char )*llvm_cbe_tmp__395;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__396);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = sext i32 %%storemerge1 to i64, !dbg !15 for 0x%I64xth hint within @KeccakP1600_ExtractBytes  --> \n", ++aesl_llvm_cbe_1319_count);
  llvm_cbe_tmp__397 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__397);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds i8* %%data, i64 %%13, !dbg !15 for 0x%I64xth hint within @KeccakP1600_ExtractBytes  --> \n", ++aesl_llvm_cbe_1320_count);
  llvm_cbe_tmp__398 = ( char *)(&llvm_cbe_data[(((signed long long )llvm_cbe_tmp__397))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__397));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%12, i8* %%14, align 1, !dbg !15 for 0x%I64xth hint within @KeccakP1600_ExtractBytes  --> \n", ++aesl_llvm_cbe_1321_count);
  *llvm_cbe_tmp__398 = llvm_cbe_tmp__396;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__396);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = add nsw i32 %%storemerge1, 1, !dbg !17 for 0x%I64xth hint within @KeccakP1600_ExtractBytes  --> \n", ++aesl_llvm_cbe_1322_count);
  llvm_cbe_tmp__399 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__399&4294967295ull)));
  if (((llvm_cbe_tmp__399&4294967295U) == (llvm_cbe_length&4294967295U))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__399;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @KeccakP1600_ExtractBytes}\n");
  return;
}


void KeccakP1600_ExtractAndAddBytes( char *llvm_cbe_state,  char *llvm_cbe_input,  char *llvm_cbe_output, signed int llvm_cbe_offset, signed int llvm_cbe_length) {
  static  unsigned long long aesl_llvm_cbe_1330_count = 0;
  static  unsigned long long aesl_llvm_cbe_1331_count = 0;
  static  unsigned long long aesl_llvm_cbe_1332_count = 0;
  static  unsigned long long aesl_llvm_cbe_1333_count = 0;
  static  unsigned long long aesl_llvm_cbe_1334_count = 0;
  static  unsigned long long aesl_llvm_cbe_1335_count = 0;
  static  unsigned long long aesl_llvm_cbe_1336_count = 0;
  static  unsigned long long aesl_llvm_cbe_1337_count = 0;
  static  unsigned long long aesl_llvm_cbe_1338_count = 0;
  static  unsigned long long aesl_llvm_cbe_1339_count = 0;
  static  unsigned long long aesl_llvm_cbe_1340_count = 0;
  static  unsigned long long aesl_llvm_cbe_1341_count = 0;
  static  unsigned long long aesl_llvm_cbe_1342_count = 0;
  static  unsigned long long aesl_llvm_cbe_1343_count = 0;
  static  unsigned long long aesl_llvm_cbe_1344_count = 0;
  static  unsigned long long aesl_llvm_cbe_1345_count = 0;
  static  unsigned long long aesl_llvm_cbe_1346_count = 0;
  static  unsigned long long aesl_llvm_cbe_1347_count = 0;
  unsigned int llvm_cbe_tmp__404;
  static  unsigned long long aesl_llvm_cbe_1348_count = 0;
  static  unsigned long long aesl_llvm_cbe_1349_count = 0;
  static  unsigned long long aesl_llvm_cbe_1350_count = 0;
  static  unsigned long long aesl_llvm_cbe_1351_count = 0;
  static  unsigned long long aesl_llvm_cbe_1352_count = 0;
  static  unsigned long long aesl_llvm_cbe_1353_count = 0;
  static  unsigned long long aesl_llvm_cbe_1354_count = 0;
  static  unsigned long long aesl_llvm_cbe_1355_count = 0;
  static  unsigned long long aesl_llvm_cbe_1356_count = 0;
  static  unsigned long long aesl_llvm_cbe_1357_count = 0;
  static  unsigned long long aesl_llvm_cbe_1358_count = 0;
  static  unsigned long long aesl_llvm_cbe_1359_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1360_count = 0;
  unsigned long long llvm_cbe_tmp__405;
  static  unsigned long long aesl_llvm_cbe_1361_count = 0;
   char *llvm_cbe_tmp__406;
  static  unsigned long long aesl_llvm_cbe_1362_count = 0;
  unsigned char llvm_cbe_tmp__407;
  static  unsigned long long aesl_llvm_cbe_1363_count = 0;
  unsigned int llvm_cbe_tmp__408;
  static  unsigned long long aesl_llvm_cbe_1364_count = 0;
  unsigned long long llvm_cbe_tmp__409;
  static  unsigned long long aesl_llvm_cbe_1365_count = 0;
   char *llvm_cbe_tmp__410;
  static  unsigned long long aesl_llvm_cbe_1366_count = 0;
  unsigned char llvm_cbe_tmp__411;
  static  unsigned long long aesl_llvm_cbe_1367_count = 0;
  unsigned char llvm_cbe_tmp__412;
  static  unsigned long long aesl_llvm_cbe_1368_count = 0;
   char *llvm_cbe_tmp__413;
  static  unsigned long long aesl_llvm_cbe_1369_count = 0;
  static  unsigned long long aesl_llvm_cbe_1370_count = 0;
  unsigned int llvm_cbe_tmp__414;
  static  unsigned long long aesl_llvm_cbe_1371_count = 0;
  static  unsigned long long aesl_llvm_cbe_1372_count = 0;
  static  unsigned long long aesl_llvm_cbe_1373_count = 0;
  static  unsigned long long aesl_llvm_cbe_1374_count = 0;
  static  unsigned long long aesl_llvm_cbe_1375_count = 0;
  static  unsigned long long aesl_llvm_cbe_1376_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_1377_count = 0;
  static  unsigned long long aesl_llvm_cbe_1378_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @KeccakP1600_ExtractAndAddBytes\n");
  if ((((unsigned int )llvm_cbe_offset&4294967295U) < ((unsigned int )200u&4294967295U))) {
    goto llvm_cbe_tmp__415;
  } else {
    goto llvm_cbe_tmp__416;
  }

llvm_cbe_tmp__416:
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @_assert(i8* getelementptr inbounds ([13 x i8]* @aesl_internal_.str, i64 0, i64 0), i8* getelementptr inbounds ([50 x i8]* @aesl_internal_.str1, i64 0, i64 0), i32 403) nounwind, !dbg !17 for 0x%I64xth hint within @KeccakP1600_ExtractAndAddBytes  --> \n", ++aesl_llvm_cbe_1345_count);
   /*tail*/ _assert(( char *)((&aesl_internal__OC_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 13
#endif
])), ( char *)((&aesl_internal__OC_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 50
#endif
])), 403u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",403u);
}
  goto llvm_cbe_tmp__415;

llvm_cbe_tmp__415:
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = add i32 %%length, %%offset, !dbg !16 for 0x%I64xth hint within @KeccakP1600_ExtractAndAddBytes  --> \n", ++aesl_llvm_cbe_1347_count);
  llvm_cbe_tmp__404 = (unsigned int )((unsigned int )(llvm_cbe_length&4294967295ull)) + ((unsigned int )(llvm_cbe_offset&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__404&4294967295ull)));
  if ((((unsigned int )llvm_cbe_tmp__404&4294967295U) < ((unsigned int )201u&4294967295U))) {
    goto llvm_cbe_tmp__417;
  } else {
    goto llvm_cbe_tmp__418;
  }

llvm_cbe_tmp__418:
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @_assert(i8* getelementptr inbounds ([21 x i8]* @aesl_internal_.str2, i64 0, i64 0), i8* getelementptr inbounds ([50 x i8]* @aesl_internal_.str1, i64 0, i64 0), i32 404) nounwind, !dbg !17 for 0x%I64xth hint within @KeccakP1600_ExtractAndAddBytes  --> \n", ++aesl_llvm_cbe_1350_count);
   /*tail*/ _assert(( char *)((&aesl_internal__OC_str2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 21
#endif
])), ( char *)((&aesl_internal__OC_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 50
#endif
])), 404u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",404u);
}
  goto llvm_cbe_tmp__417;

llvm_cbe_tmp__417:
  if (((llvm_cbe_length&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ %%18, %%.lr.ph ], [ 0, %%7  for 0x%I64xth hint within @KeccakP1600_ExtractAndAddBytes  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",llvm_cbe_tmp__414);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = zext i32 %%storemerge1 to i64, !dbg !15 for 0x%I64xth hint within @KeccakP1600_ExtractAndAddBytes  --> \n", ++aesl_llvm_cbe_1360_count);
  llvm_cbe_tmp__405 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge1&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__405);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds i8* %%input, i64 %%9, !dbg !15 for 0x%I64xth hint within @KeccakP1600_ExtractAndAddBytes  --> \n", ++aesl_llvm_cbe_1361_count);
  llvm_cbe_tmp__406 = ( char *)(&llvm_cbe_input[(((signed long long )llvm_cbe_tmp__405))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__405));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = load i8* %%10, align 1, !dbg !15 for 0x%I64xth hint within @KeccakP1600_ExtractAndAddBytes  --> \n", ++aesl_llvm_cbe_1362_count);
  llvm_cbe_tmp__407 = (unsigned char )*llvm_cbe_tmp__406;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__407);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = add i32 %%storemerge1, %%offset, !dbg !15 for 0x%I64xth hint within @KeccakP1600_ExtractAndAddBytes  --> \n", ++aesl_llvm_cbe_1363_count);
  llvm_cbe_tmp__408 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(llvm_cbe_offset&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__408&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = zext i32 %%12 to i64, !dbg !15 for 0x%I64xth hint within @KeccakP1600_ExtractAndAddBytes  --> \n", ++aesl_llvm_cbe_1364_count);
  llvm_cbe_tmp__409 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__408&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__409);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds i8* %%state, i64 %%13, !dbg !15 for 0x%I64xth hint within @KeccakP1600_ExtractAndAddBytes  --> \n", ++aesl_llvm_cbe_1365_count);
  llvm_cbe_tmp__410 = ( char *)(&llvm_cbe_state[(((signed long long )llvm_cbe_tmp__409))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__409));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = load i8* %%14, align 1, !dbg !15 for 0x%I64xth hint within @KeccakP1600_ExtractAndAddBytes  --> \n", ++aesl_llvm_cbe_1366_count);
  llvm_cbe_tmp__411 = (unsigned char )*llvm_cbe_tmp__410;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__411);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = xor i8 %%15, %%11, !dbg !15 for 0x%I64xth hint within @KeccakP1600_ExtractAndAddBytes  --> \n", ++aesl_llvm_cbe_1367_count);
  llvm_cbe_tmp__412 = (unsigned char )((unsigned char )(llvm_cbe_tmp__411 ^ llvm_cbe_tmp__407));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__412);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds i8* %%output, i64 %%9, !dbg !15 for 0x%I64xth hint within @KeccakP1600_ExtractAndAddBytes  --> \n", ++aesl_llvm_cbe_1368_count);
  llvm_cbe_tmp__413 = ( char *)(&llvm_cbe_output[(((signed long long )llvm_cbe_tmp__405))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__405));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%16, i8* %%17, align 1, !dbg !15 for 0x%I64xth hint within @KeccakP1600_ExtractAndAddBytes  --> \n", ++aesl_llvm_cbe_1369_count);
  *llvm_cbe_tmp__413 = llvm_cbe_tmp__412;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__412);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = add i32 %%storemerge1, 1, !dbg !17 for 0x%I64xth hint within @KeccakP1600_ExtractAndAddBytes  --> \n", ++aesl_llvm_cbe_1370_count);
  llvm_cbe_tmp__414 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__414&4294967295ull)));
  if (((llvm_cbe_tmp__414&4294967295U) == (llvm_cbe_length&4294967295U))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__414;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @KeccakP1600_ExtractAndAddBytes}\n");
  return;
}


void KeccakP1600_DisplayRoundConstants(l_struct_OC__iobuf *llvm_cbe_f) {
  static  unsigned long long aesl_llvm_cbe_1379_count = 0;
  static  unsigned long long aesl_llvm_cbe_1380_count = 0;
  static  unsigned long long aesl_llvm_cbe_1381_count = 0;
  static  unsigned long long aesl_llvm_cbe_1382_count = 0;
  static  unsigned long long aesl_llvm_cbe_1383_count = 0;
  static  unsigned long long aesl_llvm_cbe_1384_count = 0;
  static  unsigned long long aesl_llvm_cbe_1385_count = 0;
  static  unsigned long long aesl_llvm_cbe_1386_count = 0;
  static  unsigned long long aesl_llvm_cbe_1387_count = 0;
  static  unsigned long long aesl_llvm_cbe_1388_count = 0;
  static  unsigned long long aesl_llvm_cbe_1389_count = 0;
  static  unsigned long long aesl_llvm_cbe_1390_count = 0;
  static  unsigned long long aesl_llvm_cbe_1391_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge4_count = 0;
  unsigned int llvm_cbe_storemerge4;
  unsigned int llvm_cbe_storemerge4__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1392_count = 0;
  unsigned int llvm_cbe_tmp__419;
  static  unsigned long long aesl_llvm_cbe_1393_count = 0;
  unsigned long long llvm_cbe_tmp__420;
  static  unsigned long long aesl_llvm_cbe_1394_count = 0;
  signed long long *llvm_cbe_tmp__421;
  static  unsigned long long aesl_llvm_cbe_1395_count = 0;
  unsigned long long llvm_cbe_tmp__422;
  static  unsigned long long aesl_llvm_cbe_1396_count = 0;
  unsigned long long llvm_cbe_tmp__423;
  static  unsigned long long aesl_llvm_cbe_1397_count = 0;
  unsigned int llvm_cbe_tmp__424;
  static  unsigned long long aesl_llvm_cbe_1398_count = 0;
  unsigned int llvm_cbe_tmp__425;
  static  unsigned long long aesl_llvm_cbe_1399_count = 0;
  unsigned int llvm_cbe_tmp__426;
  static  unsigned long long aesl_llvm_cbe_1400_count = 0;
  unsigned int llvm_cbe_tmp__427;
  static  unsigned long long aesl_llvm_cbe_fputc_count = 0;
  unsigned int llvm_cbe_fputc;
  static  unsigned long long aesl_llvm_cbe_1401_count = 0;
  unsigned int llvm_cbe_tmp__428;
  static  unsigned long long aesl_llvm_cbe_1402_count = 0;
  static  unsigned long long aesl_llvm_cbe_1403_count = 0;
  static  unsigned long long aesl_llvm_cbe_1404_count = 0;
  static  unsigned long long aesl_llvm_cbe_1405_count = 0;
  static  unsigned long long aesl_llvm_cbe_1406_count = 0;
  static  unsigned long long aesl_llvm_cbe_1407_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_1408_count = 0;
  static  unsigned long long aesl_llvm_cbe_fputc3_count = 0;
  unsigned int llvm_cbe_fputc3;
  static  unsigned long long aesl_llvm_cbe_1409_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @KeccakP1600_DisplayRoundConstants\n");
  llvm_cbe_storemerge4__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__429;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__429:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge4 = phi i32 [ 0, %%0 ], [ %%11, %%1  for 0x%I64xth hint within @KeccakP1600_DisplayRoundConstants  --> \n", ++aesl_llvm_cbe_storemerge4_count);
  llvm_cbe_storemerge4 = (unsigned int )llvm_cbe_storemerge4__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge4 = 0x%X",llvm_cbe_storemerge4);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__428);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = tail call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%f, i8* getelementptr inbounds ([18 x i8]* @aesl_internal_.str4, i64 0, i64 0), i32 %%storemerge4) nounwind, !dbg !15 for 0x%I64xth hint within @KeccakP1600_DisplayRoundConstants  --> \n", ++aesl_llvm_cbe_1392_count);
   /*tail*/ fprintf((l_struct_OC__iobuf *)llvm_cbe_f, ( char *)((&aesl_internal__OC_str4[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 18
#endif
])), llvm_cbe_storemerge4);
if (AESL_DEBUG_TRACE) {
printf("\nArgument storemerge4 = 0x%X",llvm_cbe_storemerge4);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__419);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = zext i32 %%storemerge4 to i64, !dbg !16 for 0x%I64xth hint within @KeccakP1600_DisplayRoundConstants  --> \n", ++aesl_llvm_cbe_1393_count);
  llvm_cbe_tmp__420 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge4&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__420);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds [24 x i64]* @aesl_internal_KeccakRoundConstants, i64 0, i64 %%3, !dbg !16 for 0x%I64xth hint within @KeccakP1600_DisplayRoundConstants  --> \n", ++aesl_llvm_cbe_1394_count);
  llvm_cbe_tmp__421 = (signed long long *)(&aesl_internal_KeccakRoundConstants[(((signed long long )llvm_cbe_tmp__420))
#ifdef AESL_BC_SIM
 % 24
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__420));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__420) < 24)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_KeccakRoundConstants' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load i64* %%4, align 8, !dbg !16 for 0x%I64xth hint within @KeccakP1600_DisplayRoundConstants  --> \n", ++aesl_llvm_cbe_1395_count);
  llvm_cbe_tmp__422 = (unsigned long long )*llvm_cbe_tmp__421;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__422);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = lshr i64 %%5, 32, !dbg !16 for 0x%I64xth hint within @KeccakP1600_DisplayRoundConstants  --> \n", ++aesl_llvm_cbe_1396_count);
  llvm_cbe_tmp__423 = (unsigned long long )((unsigned long long )(((unsigned long long )(llvm_cbe_tmp__422&18446744073709551615ull)) >> ((unsigned long long )(32ull&18446744073709551615ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__423&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = trunc i64 %%6 to i32, !dbg !16 for 0x%I64xth hint within @KeccakP1600_DisplayRoundConstants  --> \n", ++aesl_llvm_cbe_1397_count);
  llvm_cbe_tmp__424 = (unsigned int )((unsigned int )llvm_cbe_tmp__423&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__424);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = tail call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%f, i8* getelementptr inbounds ([5 x i8]* @aesl_internal_.str5, i64 0, i64 0), i32 %%7) nounwind, !dbg !16 for 0x%I64xth hint within @KeccakP1600_DisplayRoundConstants  --> \n", ++aesl_llvm_cbe_1398_count);
   /*tail*/ fprintf((l_struct_OC__iobuf *)llvm_cbe_f, ( char *)((&aesl_internal__OC_str5[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 5
#endif
])), llvm_cbe_tmp__424);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__424);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__425);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = trunc i64 %%5 to i32, !dbg !16 for 0x%I64xth hint within @KeccakP1600_DisplayRoundConstants  --> \n", ++aesl_llvm_cbe_1399_count);
  llvm_cbe_tmp__426 = (unsigned int )((unsigned int )llvm_cbe_tmp__422&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__426);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = tail call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%f, i8* getelementptr inbounds ([5 x i8]* @aesl_internal_.str5, i64 0, i64 0), i32 %%9) nounwind, !dbg !16 for 0x%I64xth hint within @KeccakP1600_DisplayRoundConstants  --> \n", ++aesl_llvm_cbe_1400_count);
   /*tail*/ fprintf((l_struct_OC__iobuf *)llvm_cbe_f, ( char *)((&aesl_internal__OC_str5[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 5
#endif
])), llvm_cbe_tmp__426);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__426);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__427);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%fputc = tail call i32 @fputc(i32 10, %%struct._iobuf* %%f), !dbg !16 for 0x%I64xth hint within @KeccakP1600_DisplayRoundConstants  --> \n", ++aesl_llvm_cbe_fputc_count);
   /*tail*/ fputc(10u, (l_struct_OC__iobuf *)llvm_cbe_f);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",10u);
printf("\nReturn fputc = 0x%X",llvm_cbe_fputc);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = add i32 %%storemerge4, 1, !dbg !16 for 0x%I64xth hint within @KeccakP1600_DisplayRoundConstants  --> \n", ++aesl_llvm_cbe_1401_count);
  llvm_cbe_tmp__428 = (unsigned int )((unsigned int )(llvm_cbe_storemerge4&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__428&4294967295ull)));
  if (((llvm_cbe_tmp__428&4294967295U) == (24u&4294967295U))) {
    goto llvm_cbe_tmp__430;
  } else {
    llvm_cbe_storemerge4__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__428;   /* for PHI node */
    goto llvm_cbe_tmp__429;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__430:
if (AESL_DEBUG_TRACE)
printf("\n  %%fputc3 = tail call i32 @fputc(i32 10, %%struct._iobuf* %%f), !dbg !16 for 0x%I64xth hint within @KeccakP1600_DisplayRoundConstants  --> \n", ++aesl_llvm_cbe_fputc3_count);
   /*tail*/ fputc(10u, (l_struct_OC__iobuf *)llvm_cbe_f);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",10u);
printf("\nReturn fputc3 = 0x%X",llvm_cbe_fputc3);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @KeccakP1600_DisplayRoundConstants}\n");
  return;
}


void KeccakP1600_DisplayRhoOffsets(l_struct_OC__iobuf *llvm_cbe_f) {
  static  unsigned long long aesl_llvm_cbe_1410_count = 0;
  static  unsigned long long aesl_llvm_cbe_1411_count = 0;
  static  unsigned long long aesl_llvm_cbe_1412_count = 0;
  static  unsigned long long aesl_llvm_cbe_1413_count = 0;
  static  unsigned long long aesl_llvm_cbe_1414_count = 0;
  static  unsigned long long aesl_llvm_cbe_1415_count = 0;
  static  unsigned long long aesl_llvm_cbe_1416_count = 0;
  static  unsigned long long aesl_llvm_cbe_1417_count = 0;
  static  unsigned long long aesl_llvm_cbe_1418_count = 0;
  static  unsigned long long aesl_llvm_cbe_1419_count = 0;
  static  unsigned long long aesl_llvm_cbe_1420_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge6_count = 0;
  unsigned int llvm_cbe_storemerge6;
  unsigned int llvm_cbe_storemerge6__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1421_count = 0;
  static  unsigned long long aesl_llvm_cbe_1422_count = 0;
  static  unsigned long long aesl_llvm_cbe_1423_count = 0;
  static  unsigned long long aesl_llvm_cbe_1424_count = 0;
  static  unsigned long long aesl_llvm_cbe_1425_count = 0;
  unsigned int llvm_cbe_tmp__431;
  static  unsigned long long aesl_llvm_cbe_1426_count = 0;
  unsigned int llvm_cbe_tmp__432;
  static  unsigned long long aesl_llvm_cbe_1427_count = 0;
  unsigned int llvm_cbe_tmp__433;
  static  unsigned long long aesl_llvm_cbe_1428_count = 0;
  unsigned long long llvm_cbe_tmp__434;
  static  unsigned long long aesl_llvm_cbe_1429_count = 0;
  signed int *llvm_cbe_tmp__435;
  static  unsigned long long aesl_llvm_cbe_1430_count = 0;
  unsigned int llvm_cbe_tmp__436;
  static  unsigned long long aesl_llvm_cbe_1431_count = 0;
  unsigned int llvm_cbe_tmp__437;
  static  unsigned long long aesl_llvm_cbe_fputc_count = 0;
  unsigned int llvm_cbe_fputc;
  static  unsigned long long aesl_llvm_cbe_1432_count = 0;
  static  unsigned long long aesl_llvm_cbe_1433_count = 0;
  static  unsigned long long aesl_llvm_cbe_1434_count = 0;
  static  unsigned long long aesl_llvm_cbe_1435_count = 0;
  static  unsigned long long aesl_llvm_cbe_1436_count = 0;
  static  unsigned long long aesl_llvm_cbe_1437_count = 0;
  unsigned int llvm_cbe_tmp__438;
  static  unsigned long long aesl_llvm_cbe_1438_count = 0;
  unsigned int llvm_cbe_tmp__439;
  static  unsigned long long aesl_llvm_cbe_1439_count = 0;
  unsigned long long llvm_cbe_tmp__440;
  static  unsigned long long aesl_llvm_cbe_1440_count = 0;
  signed int *llvm_cbe_tmp__441;
  static  unsigned long long aesl_llvm_cbe_1441_count = 0;
  unsigned int llvm_cbe_tmp__442;
  static  unsigned long long aesl_llvm_cbe_1442_count = 0;
  unsigned int llvm_cbe_tmp__443;
  static  unsigned long long aesl_llvm_cbe_fputc_2e_1_count = 0;
  unsigned int llvm_cbe_fputc_2e_1;
  static  unsigned long long aesl_llvm_cbe_1443_count = 0;
  static  unsigned long long aesl_llvm_cbe_1444_count = 0;
  static  unsigned long long aesl_llvm_cbe_1445_count = 0;
  static  unsigned long long aesl_llvm_cbe_1446_count = 0;
  static  unsigned long long aesl_llvm_cbe_1447_count = 0;
  static  unsigned long long aesl_llvm_cbe_1448_count = 0;
  unsigned int llvm_cbe_tmp__444;
  static  unsigned long long aesl_llvm_cbe_1449_count = 0;
  unsigned int llvm_cbe_tmp__445;
  static  unsigned long long aesl_llvm_cbe_1450_count = 0;
  unsigned long long llvm_cbe_tmp__446;
  static  unsigned long long aesl_llvm_cbe_1451_count = 0;
  signed int *llvm_cbe_tmp__447;
  static  unsigned long long aesl_llvm_cbe_1452_count = 0;
  unsigned int llvm_cbe_tmp__448;
  static  unsigned long long aesl_llvm_cbe_1453_count = 0;
  unsigned int llvm_cbe_tmp__449;
  static  unsigned long long aesl_llvm_cbe_fputc_2e_2_count = 0;
  unsigned int llvm_cbe_fputc_2e_2;
  static  unsigned long long aesl_llvm_cbe_1454_count = 0;
  static  unsigned long long aesl_llvm_cbe_1455_count = 0;
  static  unsigned long long aesl_llvm_cbe_1456_count = 0;
  static  unsigned long long aesl_llvm_cbe_1457_count = 0;
  static  unsigned long long aesl_llvm_cbe_1458_count = 0;
  static  unsigned long long aesl_llvm_cbe_1459_count = 0;
  unsigned int llvm_cbe_tmp__450;
  static  unsigned long long aesl_llvm_cbe_1460_count = 0;
  unsigned int llvm_cbe_tmp__451;
  static  unsigned long long aesl_llvm_cbe_1461_count = 0;
  unsigned long long llvm_cbe_tmp__452;
  static  unsigned long long aesl_llvm_cbe_1462_count = 0;
  signed int *llvm_cbe_tmp__453;
  static  unsigned long long aesl_llvm_cbe_1463_count = 0;
  unsigned int llvm_cbe_tmp__454;
  static  unsigned long long aesl_llvm_cbe_1464_count = 0;
  unsigned int llvm_cbe_tmp__455;
  static  unsigned long long aesl_llvm_cbe_fputc_2e_3_count = 0;
  unsigned int llvm_cbe_fputc_2e_3;
  static  unsigned long long aesl_llvm_cbe_1465_count = 0;
  static  unsigned long long aesl_llvm_cbe_1466_count = 0;
  static  unsigned long long aesl_llvm_cbe_1467_count = 0;
  static  unsigned long long aesl_llvm_cbe_1468_count = 0;
  static  unsigned long long aesl_llvm_cbe_1469_count = 0;
  static  unsigned long long aesl_llvm_cbe_1470_count = 0;
  unsigned int llvm_cbe_tmp__456;
  static  unsigned long long aesl_llvm_cbe_1471_count = 0;
  unsigned int llvm_cbe_tmp__457;
  static  unsigned long long aesl_llvm_cbe_1472_count = 0;
  unsigned long long llvm_cbe_tmp__458;
  static  unsigned long long aesl_llvm_cbe_1473_count = 0;
  signed int *llvm_cbe_tmp__459;
  static  unsigned long long aesl_llvm_cbe_1474_count = 0;
  unsigned int llvm_cbe_tmp__460;
  static  unsigned long long aesl_llvm_cbe_1475_count = 0;
  unsigned int llvm_cbe_tmp__461;
  static  unsigned long long aesl_llvm_cbe_fputc_2e_4_count = 0;
  unsigned int llvm_cbe_fputc_2e_4;
  static  unsigned long long aesl_llvm_cbe_1476_count = 0;
  static  unsigned long long aesl_llvm_cbe_1477_count = 0;
  static  unsigned long long aesl_llvm_cbe_1478_count = 0;
  static  unsigned long long aesl_llvm_cbe_1479_count = 0;
  static  unsigned long long aesl_llvm_cbe_1480_count = 0;
  static  unsigned long long aesl_llvm_cbe_1481_count = 0;
  unsigned int llvm_cbe_tmp__462;
  static  unsigned long long aesl_llvm_cbe_1482_count = 0;
  static  unsigned long long aesl_llvm_cbe_1483_count = 0;
  static  unsigned long long aesl_llvm_cbe_1484_count = 0;
  static  unsigned long long aesl_llvm_cbe_1485_count = 0;
  static  unsigned long long aesl_llvm_cbe_1486_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_1487_count = 0;
  static  unsigned long long aesl_llvm_cbe_fputc4_count = 0;
  unsigned int llvm_cbe_fputc4;
  static  unsigned long long aesl_llvm_cbe_1488_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @KeccakP1600_DisplayRhoOffsets\n");
  llvm_cbe_storemerge6__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_preheader;

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge6 = phi i32 [ 0, %%0 ], [ %%32, %%.preheader  for 0x%I64xth hint within @KeccakP1600_DisplayRhoOffsets  --> \n", ++aesl_llvm_cbe_storemerge6_count);
  llvm_cbe_storemerge6 = (unsigned int )llvm_cbe_storemerge6__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge6 = 0x%X",llvm_cbe_storemerge6);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__462);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = urem i32 %%storemerge6, 5, !dbg !16 for 0x%I64xth hint within @KeccakP1600_DisplayRhoOffsets  --> \n", ++aesl_llvm_cbe_1425_count);
  llvm_cbe_tmp__431 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_storemerge6&4294967295ull)) % ((unsigned int )(5u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__431&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = mul i32 %%1, 5, !dbg !16 for 0x%I64xth hint within @KeccakP1600_DisplayRhoOffsets  --> \n", ++aesl_llvm_cbe_1426_count);
  llvm_cbe_tmp__432 = (unsigned int )((unsigned int )(llvm_cbe_tmp__431&4294967295ull)) * ((unsigned int )(5u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__432&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = tail call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%f, i8* getelementptr inbounds ([21 x i8]* @aesl_internal_.str7, i64 0, i64 0), i32 0, i32 %%storemerge6) nounwind, !dbg !15 for 0x%I64xth hint within @KeccakP1600_DisplayRhoOffsets  --> \n", ++aesl_llvm_cbe_1427_count);
   /*tail*/ fprintf((l_struct_OC__iobuf *)llvm_cbe_f, ( char *)((&aesl_internal__OC_str7[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 21
#endif
])), 0u, llvm_cbe_storemerge6);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument storemerge6 = 0x%X",llvm_cbe_storemerge6);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__433);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = zext i32 %%2 to i64, !dbg !16 for 0x%I64xth hint within @KeccakP1600_DisplayRhoOffsets  --> \n", ++aesl_llvm_cbe_1428_count);
  llvm_cbe_tmp__434 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__432&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__434);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds [25 x i32]* @aesl_internal_KeccakRhoOffsets, i64 0, i64 %%4, !dbg !16 for 0x%I64xth hint within @KeccakP1600_DisplayRhoOffsets  --> \n", ++aesl_llvm_cbe_1429_count);
  llvm_cbe_tmp__435 = (signed int *)(&aesl_internal_KeccakRhoOffsets[(((signed long long )llvm_cbe_tmp__434))
#ifdef AESL_BC_SIM
 % 25
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__434));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__434) < 25)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_KeccakRhoOffsets' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load i32* %%5, align 4, !dbg !16 for 0x%I64xth hint within @KeccakP1600_DisplayRhoOffsets  --> \n", ++aesl_llvm_cbe_1430_count);
  llvm_cbe_tmp__436 = (unsigned int )*llvm_cbe_tmp__435;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__436);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = tail call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%f, i8* getelementptr inbounds ([4 x i8]* @aesl_internal_.str8, i64 0, i64 0), i32 %%6) nounwind, !dbg !16 for 0x%I64xth hint within @KeccakP1600_DisplayRhoOffsets  --> \n", ++aesl_llvm_cbe_1431_count);
   /*tail*/ fprintf((l_struct_OC__iobuf *)llvm_cbe_f, ( char *)((&aesl_internal__OC_str8[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
])), llvm_cbe_tmp__436);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__436);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__437);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%fputc = tail call i32 @fputc(i32 10, %%struct._iobuf* %%f), !dbg !16 for 0x%I64xth hint within @KeccakP1600_DisplayRhoOffsets  --> \n", ++aesl_llvm_cbe_fputc_count);
   /*tail*/ fputc(10u, (l_struct_OC__iobuf *)llvm_cbe_f);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",10u);
printf("\nReturn fputc = 0x%X",llvm_cbe_fputc);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = tail call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%f, i8* getelementptr inbounds ([21 x i8]* @aesl_internal_.str7, i64 0, i64 0), i32 1, i32 %%storemerge6) nounwind, !dbg !15 for 0x%I64xth hint within @KeccakP1600_DisplayRhoOffsets  --> \n", ++aesl_llvm_cbe_1437_count);
   /*tail*/ fprintf((l_struct_OC__iobuf *)llvm_cbe_f, ( char *)((&aesl_internal__OC_str7[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 21
#endif
])), 1u, llvm_cbe_storemerge6);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",1u);
printf("\nArgument storemerge6 = 0x%X",llvm_cbe_storemerge6);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__438);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = add i32 %%2, 1, !dbg !16 for 0x%I64xth hint within @KeccakP1600_DisplayRhoOffsets  --> \n", ++aesl_llvm_cbe_1438_count);
  llvm_cbe_tmp__439 = (unsigned int )((unsigned int )(llvm_cbe_tmp__432&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__439&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = zext i32 %%9 to i64, !dbg !16 for 0x%I64xth hint within @KeccakP1600_DisplayRhoOffsets  --> \n", ++aesl_llvm_cbe_1439_count);
  llvm_cbe_tmp__440 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__439&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__440);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds [25 x i32]* @aesl_internal_KeccakRhoOffsets, i64 0, i64 %%10, !dbg !16 for 0x%I64xth hint within @KeccakP1600_DisplayRhoOffsets  --> \n", ++aesl_llvm_cbe_1440_count);
  llvm_cbe_tmp__441 = (signed int *)(&aesl_internal_KeccakRhoOffsets[(((signed long long )llvm_cbe_tmp__440))
#ifdef AESL_BC_SIM
 % 25
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__440));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__440) < 25)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_KeccakRhoOffsets' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = load i32* %%11, align 4, !dbg !16 for 0x%I64xth hint within @KeccakP1600_DisplayRhoOffsets  --> \n", ++aesl_llvm_cbe_1441_count);
  llvm_cbe_tmp__442 = (unsigned int )*llvm_cbe_tmp__441;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__442);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = tail call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%f, i8* getelementptr inbounds ([4 x i8]* @aesl_internal_.str8, i64 0, i64 0), i32 %%12) nounwind, !dbg !16 for 0x%I64xth hint within @KeccakP1600_DisplayRhoOffsets  --> \n", ++aesl_llvm_cbe_1442_count);
   /*tail*/ fprintf((l_struct_OC__iobuf *)llvm_cbe_f, ( char *)((&aesl_internal__OC_str8[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
])), llvm_cbe_tmp__442);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__442);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__443);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%fputc.1 = tail call i32 @fputc(i32 10, %%struct._iobuf* %%f), !dbg !16 for 0x%I64xth hint within @KeccakP1600_DisplayRhoOffsets  --> \n", ++aesl_llvm_cbe_fputc_2e_1_count);
   /*tail*/ fputc(10u, (l_struct_OC__iobuf *)llvm_cbe_f);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",10u);
printf("\nReturn fputc.1 = 0x%X",llvm_cbe_fputc_2e_1);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = tail call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%f, i8* getelementptr inbounds ([21 x i8]* @aesl_internal_.str7, i64 0, i64 0), i32 2, i32 %%storemerge6) nounwind, !dbg !15 for 0x%I64xth hint within @KeccakP1600_DisplayRhoOffsets  --> \n", ++aesl_llvm_cbe_1448_count);
   /*tail*/ fprintf((l_struct_OC__iobuf *)llvm_cbe_f, ( char *)((&aesl_internal__OC_str7[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 21
#endif
])), 2u, llvm_cbe_storemerge6);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",2u);
printf("\nArgument storemerge6 = 0x%X",llvm_cbe_storemerge6);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__444);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = add i32 %%2, 2, !dbg !16 for 0x%I64xth hint within @KeccakP1600_DisplayRhoOffsets  --> \n", ++aesl_llvm_cbe_1449_count);
  llvm_cbe_tmp__445 = (unsigned int )((unsigned int )(llvm_cbe_tmp__432&4294967295ull)) + ((unsigned int )(2u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__445&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = zext i32 %%15 to i64, !dbg !16 for 0x%I64xth hint within @KeccakP1600_DisplayRhoOffsets  --> \n", ++aesl_llvm_cbe_1450_count);
  llvm_cbe_tmp__446 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__445&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__446);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds [25 x i32]* @aesl_internal_KeccakRhoOffsets, i64 0, i64 %%16, !dbg !16 for 0x%I64xth hint within @KeccakP1600_DisplayRhoOffsets  --> \n", ++aesl_llvm_cbe_1451_count);
  llvm_cbe_tmp__447 = (signed int *)(&aesl_internal_KeccakRhoOffsets[(((signed long long )llvm_cbe_tmp__446))
#ifdef AESL_BC_SIM
 % 25
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__446));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__446) < 25)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_KeccakRhoOffsets' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = load i32* %%17, align 4, !dbg !16 for 0x%I64xth hint within @KeccakP1600_DisplayRhoOffsets  --> \n", ++aesl_llvm_cbe_1452_count);
  llvm_cbe_tmp__448 = (unsigned int )*llvm_cbe_tmp__447;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__448);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = tail call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%f, i8* getelementptr inbounds ([4 x i8]* @aesl_internal_.str8, i64 0, i64 0), i32 %%18) nounwind, !dbg !16 for 0x%I64xth hint within @KeccakP1600_DisplayRhoOffsets  --> \n", ++aesl_llvm_cbe_1453_count);
   /*tail*/ fprintf((l_struct_OC__iobuf *)llvm_cbe_f, ( char *)((&aesl_internal__OC_str8[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
])), llvm_cbe_tmp__448);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__448);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__449);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%fputc.2 = tail call i32 @fputc(i32 10, %%struct._iobuf* %%f), !dbg !16 for 0x%I64xth hint within @KeccakP1600_DisplayRhoOffsets  --> \n", ++aesl_llvm_cbe_fputc_2e_2_count);
   /*tail*/ fputc(10u, (l_struct_OC__iobuf *)llvm_cbe_f);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",10u);
printf("\nReturn fputc.2 = 0x%X",llvm_cbe_fputc_2e_2);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = tail call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%f, i8* getelementptr inbounds ([21 x i8]* @aesl_internal_.str7, i64 0, i64 0), i32 3, i32 %%storemerge6) nounwind, !dbg !15 for 0x%I64xth hint within @KeccakP1600_DisplayRhoOffsets  --> \n", ++aesl_llvm_cbe_1459_count);
   /*tail*/ fprintf((l_struct_OC__iobuf *)llvm_cbe_f, ( char *)((&aesl_internal__OC_str7[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 21
#endif
])), 3u, llvm_cbe_storemerge6);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",3u);
printf("\nArgument storemerge6 = 0x%X",llvm_cbe_storemerge6);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__450);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = add i32 %%2, 3, !dbg !16 for 0x%I64xth hint within @KeccakP1600_DisplayRhoOffsets  --> \n", ++aesl_llvm_cbe_1460_count);
  llvm_cbe_tmp__451 = (unsigned int )((unsigned int )(llvm_cbe_tmp__432&4294967295ull)) + ((unsigned int )(3u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__451&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = zext i32 %%21 to i64, !dbg !16 for 0x%I64xth hint within @KeccakP1600_DisplayRhoOffsets  --> \n", ++aesl_llvm_cbe_1461_count);
  llvm_cbe_tmp__452 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__451&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__452);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = getelementptr inbounds [25 x i32]* @aesl_internal_KeccakRhoOffsets, i64 0, i64 %%22, !dbg !16 for 0x%I64xth hint within @KeccakP1600_DisplayRhoOffsets  --> \n", ++aesl_llvm_cbe_1462_count);
  llvm_cbe_tmp__453 = (signed int *)(&aesl_internal_KeccakRhoOffsets[(((signed long long )llvm_cbe_tmp__452))
#ifdef AESL_BC_SIM
 % 25
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__452));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__452) < 25)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_KeccakRhoOffsets' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = load i32* %%23, align 4, !dbg !16 for 0x%I64xth hint within @KeccakP1600_DisplayRhoOffsets  --> \n", ++aesl_llvm_cbe_1463_count);
  llvm_cbe_tmp__454 = (unsigned int )*llvm_cbe_tmp__453;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__454);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = tail call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%f, i8* getelementptr inbounds ([4 x i8]* @aesl_internal_.str8, i64 0, i64 0), i32 %%24) nounwind, !dbg !16 for 0x%I64xth hint within @KeccakP1600_DisplayRhoOffsets  --> \n", ++aesl_llvm_cbe_1464_count);
   /*tail*/ fprintf((l_struct_OC__iobuf *)llvm_cbe_f, ( char *)((&aesl_internal__OC_str8[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
])), llvm_cbe_tmp__454);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__454);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__455);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%fputc.3 = tail call i32 @fputc(i32 10, %%struct._iobuf* %%f), !dbg !16 for 0x%I64xth hint within @KeccakP1600_DisplayRhoOffsets  --> \n", ++aesl_llvm_cbe_fputc_2e_3_count);
   /*tail*/ fputc(10u, (l_struct_OC__iobuf *)llvm_cbe_f);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",10u);
printf("\nReturn fputc.3 = 0x%X",llvm_cbe_fputc_2e_3);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = tail call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%f, i8* getelementptr inbounds ([21 x i8]* @aesl_internal_.str7, i64 0, i64 0), i32 4, i32 %%storemerge6) nounwind, !dbg !15 for 0x%I64xth hint within @KeccakP1600_DisplayRhoOffsets  --> \n", ++aesl_llvm_cbe_1470_count);
   /*tail*/ fprintf((l_struct_OC__iobuf *)llvm_cbe_f, ( char *)((&aesl_internal__OC_str7[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 21
#endif
])), 4u, llvm_cbe_storemerge6);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",4u);
printf("\nArgument storemerge6 = 0x%X",llvm_cbe_storemerge6);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__456);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = add i32 %%2, 4, !dbg !16 for 0x%I64xth hint within @KeccakP1600_DisplayRhoOffsets  --> \n", ++aesl_llvm_cbe_1471_count);
  llvm_cbe_tmp__457 = (unsigned int )((unsigned int )(llvm_cbe_tmp__432&4294967295ull)) + ((unsigned int )(4u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__457&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = zext i32 %%27 to i64, !dbg !16 for 0x%I64xth hint within @KeccakP1600_DisplayRhoOffsets  --> \n", ++aesl_llvm_cbe_1472_count);
  llvm_cbe_tmp__458 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__457&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__458);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = getelementptr inbounds [25 x i32]* @aesl_internal_KeccakRhoOffsets, i64 0, i64 %%28, !dbg !16 for 0x%I64xth hint within @KeccakP1600_DisplayRhoOffsets  --> \n", ++aesl_llvm_cbe_1473_count);
  llvm_cbe_tmp__459 = (signed int *)(&aesl_internal_KeccakRhoOffsets[(((signed long long )llvm_cbe_tmp__458))
#ifdef AESL_BC_SIM
 % 25
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__458));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__458) < 25)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_KeccakRhoOffsets' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = load i32* %%29, align 4, !dbg !16 for 0x%I64xth hint within @KeccakP1600_DisplayRhoOffsets  --> \n", ++aesl_llvm_cbe_1474_count);
  llvm_cbe_tmp__460 = (unsigned int )*llvm_cbe_tmp__459;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__460);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = tail call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%f, i8* getelementptr inbounds ([4 x i8]* @aesl_internal_.str8, i64 0, i64 0), i32 %%30) nounwind, !dbg !16 for 0x%I64xth hint within @KeccakP1600_DisplayRhoOffsets  --> \n", ++aesl_llvm_cbe_1475_count);
   /*tail*/ fprintf((l_struct_OC__iobuf *)llvm_cbe_f, ( char *)((&aesl_internal__OC_str8[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
])), llvm_cbe_tmp__460);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__460);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__461);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%fputc.4 = tail call i32 @fputc(i32 10, %%struct._iobuf* %%f), !dbg !16 for 0x%I64xth hint within @KeccakP1600_DisplayRhoOffsets  --> \n", ++aesl_llvm_cbe_fputc_2e_4_count);
   /*tail*/ fputc(10u, (l_struct_OC__iobuf *)llvm_cbe_f);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",10u);
printf("\nReturn fputc.4 = 0x%X",llvm_cbe_fputc_2e_4);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = add i32 %%storemerge6, 1, !dbg !16 for 0x%I64xth hint within @KeccakP1600_DisplayRhoOffsets  --> \n", ++aesl_llvm_cbe_1481_count);
  llvm_cbe_tmp__462 = (unsigned int )((unsigned int )(llvm_cbe_storemerge6&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__462&4294967295ull)));
  if (((llvm_cbe_tmp__462&4294967295U) == (5u&4294967295U))) {
    goto llvm_cbe_tmp__463;
  } else {
    llvm_cbe_storemerge6__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__462;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe_tmp__463:
if (AESL_DEBUG_TRACE)
printf("\n  %%fputc4 = tail call i32 @fputc(i32 10, %%struct._iobuf* %%f), !dbg !16 for 0x%I64xth hint within @KeccakP1600_DisplayRhoOffsets  --> \n", ++aesl_llvm_cbe_fputc4_count);
   /*tail*/ fputc(10u, (l_struct_OC__iobuf *)llvm_cbe_f);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",10u);
printf("\nReturn fputc4 = 0x%X",llvm_cbe_fputc4);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @KeccakP1600_DisplayRhoOffsets}\n");
  return;
}

