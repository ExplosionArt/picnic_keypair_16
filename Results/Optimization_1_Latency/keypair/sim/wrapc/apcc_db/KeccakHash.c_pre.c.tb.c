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
typedef struct l_struct_OC_Keccak_HashInstance l_struct_OC_Keccak_HashInstance;
typedef struct l_struct_OC_KeccakWidth1600_SpongeInstanceStruct l_struct_OC_KeccakWidth1600_SpongeInstanceStruct;

/* Structure contents */
struct l_struct_OC_KeccakWidth1600_SpongeInstanceStruct {
   char field0[200];
  unsigned int field1;
  unsigned int field2;
  unsigned int field3;
};

struct l_struct_OC_Keccak_HashInstance {
  l_struct_OC_KeccakWidth1600_SpongeInstanceStruct field0;
  unsigned int field1;
  unsigned char field2;
};


/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
unsigned char Keccak_HashInitialize(l_struct_OC_Keccak_HashInstance *llvm_cbe_instance, signed int llvm_cbe_rate, signed int llvm_cbe_capacity, signed int llvm_cbe_hashbitlen,  char llvm_cbe_delimitedSuffix);
signed int KeccakWidth1600_SpongeInitialize(l_struct_OC_KeccakWidth1600_SpongeInstanceStruct *, signed int , signed int );
unsigned char Keccak_HashUpdate(l_struct_OC_Keccak_HashInstance *llvm_cbe_instance,  char *llvm_cbe_data, signed long long llvm_cbe_databitlen);
signed int KeccakWidth1600_SpongeAbsorb(l_struct_OC_KeccakWidth1600_SpongeInstanceStruct *,  char *, signed long long );
unsigned char Keccak_HashFinal(l_struct_OC_Keccak_HashInstance *llvm_cbe_instance,  char *llvm_cbe_hashval);
signed int KeccakWidth1600_SpongeAbsorbLastFewBits(l_struct_OC_KeccakWidth1600_SpongeInstanceStruct *,  char );
unsigned char Keccak_HashSqueeze(l_struct_OC_Keccak_HashInstance *llvm_cbe_instance,  char *llvm_cbe_data, signed long long llvm_cbe_databitlen);
signed int KeccakWidth1600_SpongeSqueeze(l_struct_OC_KeccakWidth1600_SpongeInstanceStruct *,  char *, signed long long );


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

unsigned char Keccak_HashInitialize(l_struct_OC_Keccak_HashInstance *llvm_cbe_instance, signed int llvm_cbe_rate, signed int llvm_cbe_capacity, signed int llvm_cbe_hashbitlen,  char llvm_cbe_delimitedSuffix) {
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  l_struct_OC_KeccakWidth1600_SpongeInstanceStruct *llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  unsigned int llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  unsigned char llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  signed int *llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
   char *llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  unsigned char llvm_cbe_tmp__6;
  unsigned char llvm_cbe_tmp__6__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @Keccak_HashInitialize\n");
  if (((llvm_cbe_delimitedSuffix&255U) == (((unsigned char )0)&255U))) {
    llvm_cbe_tmp__6__PHI_TEMPORARY = (unsigned char )((unsigned char )1);   /* for PHI node */
    goto llvm_cbe_tmp__7;
  } else {
    goto llvm_cbe_tmp__8;
  }

llvm_cbe_tmp__8:
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.Keccak_HashInstance* %%instance, i64 0, i32 0, !dbg !8 for 0x%I64xth hint within @Keccak_HashInitialize  --> \n", ++aesl_llvm_cbe_16_count);
  llvm_cbe_tmp__1 = (l_struct_OC_KeccakWidth1600_SpongeInstanceStruct *)(&llvm_cbe_instance->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = tail call i32 @KeccakWidth1600_SpongeInitialize(%%struct.KeccakWidth1600_SpongeInstanceStruct* %%3, i32 %%rate, i32 %%capacity) nounwind, !dbg !8 for 0x%I64xth hint within @Keccak_HashInitialize  --> \n", ++aesl_llvm_cbe_17_count);
  llvm_cbe_tmp__2 = (unsigned int ) /*tail*/ KeccakWidth1600_SpongeInitialize((l_struct_OC_KeccakWidth1600_SpongeInstanceStruct *)llvm_cbe_tmp__1, llvm_cbe_rate, llvm_cbe_capacity);
if (AESL_DEBUG_TRACE) {
printf("\nArgument rate = 0x%X",llvm_cbe_rate);
printf("\nArgument capacity = 0x%X",llvm_cbe_capacity);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__2);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = trunc i32 %%4 to i2, !dbg !8 for 0x%I64xth hint within @Keccak_HashInitialize  --> \n", ++aesl_llvm_cbe_18_count);
  llvm_cbe_tmp__3 = (unsigned char )((unsigned char )llvm_cbe_tmp__2&3U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__3);
  if (((llvm_cbe_tmp__3&3U) == (((unsigned char )0)&3U))) {
    goto llvm_cbe_tmp__9;
  } else {
    llvm_cbe_tmp__6__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__3;   /* for PHI node */
    goto llvm_cbe_tmp__7;
  }

llvm_cbe_tmp__9:
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds %%struct.Keccak_HashInstance* %%instance, i64 0, i32 1, !dbg !8 for 0x%I64xth hint within @Keccak_HashInitialize  --> \n", ++aesl_llvm_cbe_24_count);
  llvm_cbe_tmp__4 = (signed int *)(&llvm_cbe_instance->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%hashbitlen, i32* %%8, align 4, !dbg !8 for 0x%I64xth hint within @Keccak_HashInitialize  --> \n", ++aesl_llvm_cbe_25_count);
  *llvm_cbe_tmp__4 = llvm_cbe_hashbitlen;
if (AESL_DEBUG_TRACE)
printf("\nhashbitlen = 0x%X\n", llvm_cbe_hashbitlen);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds %%struct.Keccak_HashInstance* %%instance, i64 0, i32 2, !dbg !8 for 0x%I64xth hint within @Keccak_HashInitialize  --> \n", ++aesl_llvm_cbe_26_count);
  llvm_cbe_tmp__5 = ( char *)(&llvm_cbe_instance->field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%delimitedSuffix, i8* %%9, align 1, !dbg !8 for 0x%I64xth hint within @Keccak_HashInitialize  --> \n", ++aesl_llvm_cbe_27_count);
  *llvm_cbe_tmp__5 = llvm_cbe_delimitedSuffix;
if (AESL_DEBUG_TRACE)
printf("\ndelimitedSuffix = 0x%X\n", llvm_cbe_delimitedSuffix);
  llvm_cbe_tmp__6__PHI_TEMPORARY = (unsigned char )((unsigned char )0);   /* for PHI node */
  goto llvm_cbe_tmp__7;

llvm_cbe_tmp__7:
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = phi i2 [ 0, %%7 ], [ 1, %%0 ], [ %%5, %%2  for 0x%I64xth hint within @Keccak_HashInitialize  --> \n", ++aesl_llvm_cbe_29_count);
  llvm_cbe_tmp__6 = (unsigned char )llvm_cbe_tmp__6__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__6);
printf("\n = 0x%X",((unsigned char )0));
printf("\n = 0x%X",((unsigned char )1));
printf("\n = 0x%X",llvm_cbe_tmp__3);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @Keccak_HashInitialize}\n");
  return llvm_cbe_tmp__6;
}


unsigned char Keccak_HashUpdate(l_struct_OC_Keccak_HashInstance *llvm_cbe_instance,  char *llvm_cbe_data, signed long long llvm_cbe_databitlen) {
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  l_struct_OC_KeccakWidth1600_SpongeInstanceStruct *llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  unsigned long long llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  unsigned int llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  unsigned char llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @Keccak_HashUpdate\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.Keccak_HashInstance* %%instance, i64 0, i32 0, !dbg !8 for 0x%I64xth hint within @Keccak_HashUpdate  --> \n", ++aesl_llvm_cbe_35_count);
  llvm_cbe_tmp__10 = (l_struct_OC_KeccakWidth1600_SpongeInstanceStruct *)(&llvm_cbe_instance->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = lshr i64 %%databitlen, 3, !dbg !8 for 0x%I64xth hint within @Keccak_HashUpdate  --> \n", ++aesl_llvm_cbe_38_count);
  llvm_cbe_tmp__11 = (unsigned long long )((unsigned long long )(((unsigned long long )(llvm_cbe_databitlen&18446744073709551615ull)) >> ((unsigned long long )(3ull&18446744073709551615ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__11&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = tail call i32 @KeccakWidth1600_SpongeAbsorb(%%struct.KeccakWidth1600_SpongeInstanceStruct* %%1, i8* %%data, i64 %%2) nounwind, !dbg !8 for 0x%I64xth hint within @Keccak_HashUpdate  --> \n", ++aesl_llvm_cbe_39_count);
  llvm_cbe_tmp__12 = (unsigned int ) /*tail*/ KeccakWidth1600_SpongeAbsorb((l_struct_OC_KeccakWidth1600_SpongeInstanceStruct *)llvm_cbe_tmp__10, ( char *)llvm_cbe_data, llvm_cbe_tmp__11);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__11);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__12);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = trunc i32 %%3 to i2, !dbg !8 for 0x%I64xth hint within @Keccak_HashUpdate  --> \n", ++aesl_llvm_cbe_40_count);
  llvm_cbe_tmp__13 = (unsigned char )((unsigned char )llvm_cbe_tmp__12&3U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__13);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @Keccak_HashUpdate}\n");
  return llvm_cbe_tmp__13;
}


unsigned char Keccak_HashFinal(l_struct_OC_Keccak_HashInstance *llvm_cbe_instance,  char *llvm_cbe_hashval) {
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  l_struct_OC_KeccakWidth1600_SpongeInstanceStruct *llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
   char *llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  unsigned char llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  unsigned int llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @Keccak_HashFinal\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.Keccak_HashInstance* %%instance, i64 0, i32 0, !dbg !8 for 0x%I64xth hint within @Keccak_HashFinal  --> \n", ++aesl_llvm_cbe_45_count);
  llvm_cbe_tmp__14 = (l_struct_OC_KeccakWidth1600_SpongeInstanceStruct *)(&llvm_cbe_instance->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds %%struct.Keccak_HashInstance* %%instance, i64 0, i32 2, !dbg !8 for 0x%I64xth hint within @Keccak_HashFinal  --> \n", ++aesl_llvm_cbe_47_count);
  llvm_cbe_tmp__15 = ( char *)(&llvm_cbe_instance->field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = load i8* %%2, align 1, !dbg !8 for 0x%I64xth hint within @Keccak_HashFinal  --> \n", ++aesl_llvm_cbe_48_count);
  llvm_cbe_tmp__16 = (unsigned char )*llvm_cbe_tmp__15;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__16);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = tail call i32 @KeccakWidth1600_SpongeAbsorbLastFewBits(%%struct.KeccakWidth1600_SpongeInstanceStruct* %%1, i8 zeroext %%3) nounwind, !dbg !8 for 0x%I64xth hint within @Keccak_HashFinal  --> \n", ++aesl_llvm_cbe_49_count);
   /*tail*/ KeccakWidth1600_SpongeAbsorbLastFewBits((l_struct_OC_KeccakWidth1600_SpongeInstanceStruct *)llvm_cbe_tmp__14, llvm_cbe_tmp__16);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__16);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__17);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @Keccak_HashFinal}\n");
  return ((unsigned char )/*UNDEF*/0);
}


unsigned char Keccak_HashSqueeze(l_struct_OC_Keccak_HashInstance *llvm_cbe_instance,  char *llvm_cbe_data, signed long long llvm_cbe_databitlen) {
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  unsigned long long llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  l_struct_OC_KeccakWidth1600_SpongeInstanceStruct *llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  unsigned long long llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  unsigned int llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  unsigned char llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge_count = 0;
  unsigned char llvm_cbe_storemerge;
  unsigned char llvm_cbe_storemerge__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @Keccak_HashSqueeze\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = and i64 %%databitlen, 7, !dbg !8 for 0x%I64xth hint within @Keccak_HashSqueeze  --> \n", ++aesl_llvm_cbe_58_count);
  llvm_cbe_tmp__18 = (unsigned long long )llvm_cbe_databitlen & 7ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__18);
  if (((llvm_cbe_tmp__18&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__23;
  } else {
    llvm_cbe_storemerge__PHI_TEMPORARY = (unsigned char )((unsigned char )1);   /* for PHI node */
    goto llvm_cbe_tmp__24;
  }

llvm_cbe_tmp__23:
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds %%struct.Keccak_HashInstance* %%instance, i64 0, i32 0, !dbg !8 for 0x%I64xth hint within @Keccak_HashSqueeze  --> \n", ++aesl_llvm_cbe_61_count);
  llvm_cbe_tmp__19 = (l_struct_OC_KeccakWidth1600_SpongeInstanceStruct *)(&llvm_cbe_instance->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = lshr i64 %%databitlen, 3, !dbg !8 for 0x%I64xth hint within @Keccak_HashSqueeze  --> \n", ++aesl_llvm_cbe_62_count);
  llvm_cbe_tmp__20 = (unsigned long long )((unsigned long long )(((unsigned long long )(llvm_cbe_databitlen&18446744073709551615ull)) >> ((unsigned long long )(3ull&18446744073709551615ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__20&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = tail call i32 @KeccakWidth1600_SpongeSqueeze(%%struct.KeccakWidth1600_SpongeInstanceStruct* %%4, i8* %%data, i64 %%5) nounwind, !dbg !8 for 0x%I64xth hint within @Keccak_HashSqueeze  --> \n", ++aesl_llvm_cbe_63_count);
  llvm_cbe_tmp__21 = (unsigned int ) /*tail*/ KeccakWidth1600_SpongeSqueeze((l_struct_OC_KeccakWidth1600_SpongeInstanceStruct *)llvm_cbe_tmp__19, ( char *)llvm_cbe_data, llvm_cbe_tmp__20);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__20);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__21);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = trunc i32 %%6 to i2, !dbg !8 for 0x%I64xth hint within @Keccak_HashSqueeze  --> \n", ++aesl_llvm_cbe_64_count);
  llvm_cbe_tmp__22 = (unsigned char )((unsigned char )llvm_cbe_tmp__21&3U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__22);
  llvm_cbe_storemerge__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__22;   /* for PHI node */
  goto llvm_cbe_tmp__24;

llvm_cbe_tmp__24:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge = phi i2 [ %%7, %%3 ], [ 1, %%0  for 0x%I64xth hint within @Keccak_HashSqueeze  --> \n", ++aesl_llvm_cbe_storemerge_count);
  llvm_cbe_storemerge = (unsigned char )llvm_cbe_storemerge__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge = 0x%X",llvm_cbe_storemerge);
printf("\n = 0x%X",llvm_cbe_tmp__22);
printf("\n = 0x%X",((unsigned char )1));
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @Keccak_HashSqueeze}\n");
  return llvm_cbe_storemerge;
}

