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
typedef struct l_struct_OC_paramset_t l_struct_OC_paramset_t;
typedef struct l_struct_OC__iobuf l_struct_OC__iobuf;

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

struct l_struct_OC_paramset_t {
  unsigned int field0;
  unsigned int field1;
  unsigned int field2;
  unsigned int field3;
  unsigned int field4;
  unsigned int field5;
  unsigned int field6;
  unsigned int field7;
  unsigned int field8;
  unsigned int field9;
  unsigned int field10;
  unsigned int field11;
  unsigned int field12;
  unsigned int field13;
  unsigned char field14;
};

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
void HashUpdate(l_struct_OC_Keccak_HashInstance *llvm_cbe_ctx,  char *llvm_cbe_data, signed long long llvm_cbe_byteLen);
unsigned char Keccak_HashUpdate(l_struct_OC_Keccak_HashInstance *,  char *, signed long long );
void HashUpdate_2(l_struct_OC_Keccak_HashInstance *llvm_cbe_ctx, signed int *llvm_cbe_data, signed long long llvm_cbe_byteLen);
void HashInit(l_struct_OC_Keccak_HashInstance *llvm_cbe_ctx, l_struct_OC_paramset_t *llvm_cbe_params,  char llvm_cbe_hashPrefix);
unsigned char Keccak_HashInitialize(l_struct_OC_Keccak_HashInstance *, signed int , signed int , signed int ,  char );
void HashFinal(l_struct_OC_Keccak_HashInstance *llvm_cbe_ctx);
unsigned char Keccak_HashFinal(l_struct_OC_Keccak_HashInstance *,  char *);
void HashSqueeze(l_struct_OC_Keccak_HashInstance *llvm_cbe_ctx,  char *llvm_cbe_digest, signed long long llvm_cbe_byteLen);
unsigned char Keccak_HashSqueeze(l_struct_OC_Keccak_HashInstance *,  char *, signed long long );
unsigned short toLittleEndian(signed short llvm_cbe_x);
unsigned short fromLittleEndian(signed short llvm_cbe_x);
void HashUpdateIntLE(l_struct_OC_Keccak_HashInstance *llvm_cbe_ctx, signed short llvm_cbe_x);


/* Global Variable Definitions and Initialization */
static  char aesl_internal__OC_str[43] = "%s: Keccak_HashFinal failed (returned %d)\n";
static  char aesl_internal__OC_str1[45] = "%s: Keccak_HashSqueeze failed (returned %d)\n";
static  char aesl_internal___func___OC_HashFinal[10] = "HashFinal";
static  char aesl_internal___func___OC_HashSqueeze[12] = "HashSqueeze";


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

void HashUpdate(l_struct_OC_Keccak_HashInstance *llvm_cbe_ctx,  char *llvm_cbe_data, signed long long llvm_cbe_byteLen) {
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
  unsigned long long llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
  unsigned char llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @HashUpdate\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = shl i64 %%byteLen, 3, !dbg !14 for 0x%I64xth hint within @HashUpdate  --> \n", ++aesl_llvm_cbe_7_count);
  llvm_cbe_tmp__1 = (unsigned long long )llvm_cbe_byteLen << 3ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = tail call zeroext i2 @Keccak_HashUpdate(%%struct.Keccak_HashInstance* %%ctx, i8* %%data, i64 %%1) nounwind, !dbg !14 for 0x%I64xth hint within @HashUpdate  --> \n", ++aesl_llvm_cbe_8_count);
   /*tail*/ Keccak_HashUpdate((l_struct_OC_Keccak_HashInstance *)llvm_cbe_ctx, ( char *)llvm_cbe_data, llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__1);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__2);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @HashUpdate}\n");
  return;
}


void HashUpdate_2(l_struct_OC_Keccak_HashInstance *llvm_cbe_ctx, signed int *llvm_cbe_data, signed long long llvm_cbe_byteLen) {
  static  unsigned long long aesl_llvm_cbe_temp_count = 0;
   char llvm_cbe_temp[75];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
   char *llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
   char *llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  unsigned long long llvm_cbe_tmp__5;
  unsigned long long llvm_cbe_tmp__5__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  unsigned int llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  unsigned long long llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  signed int *llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  unsigned int llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  unsigned char llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
   char *llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  unsigned int llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  unsigned char llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  unsigned int llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  unsigned long long llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
   char *llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  unsigned int llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  unsigned char llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  unsigned int llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  unsigned long long llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
   char *llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  unsigned int llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  unsigned char llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  unsigned int llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  unsigned long long llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
   char *llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  unsigned int llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  unsigned long long llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
  unsigned long long llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
  unsigned char llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @HashUpdate_2\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds [75 x i8]* %%temp, i64 0, i64 0, !dbg !15 for 0x%I64xth hint within @HashUpdate_2  --> \n", ++aesl_llvm_cbe_19_count);
  llvm_cbe_tmp__3 = ( char *)(&llvm_cbe_temp[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 75
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = call i8* @memset(i8* %%1, i32 0, i64 75 for 0x%I64xth hint within @HashUpdate_2  --> \n", ++aesl_llvm_cbe_20_count);
  ( char *)memset(( char *)llvm_cbe_tmp__3, 0u, 75ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",75ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__4);
}
  if (((llvm_cbe_byteLen&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_tmp__5__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = phi i64 [ %%27, %%.lr.ph ], [ 0, %%0  for 0x%I64xth hint within @HashUpdate_2  --> \n", ++aesl_llvm_cbe_31_count);
  llvm_cbe_tmp__5 = (unsigned long long )llvm_cbe_tmp__5__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__5);
printf("\n = 0x%I64X",llvm_cbe_tmp__28);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ %%26, %%.lr.ph ], [ 0, %%0  for 0x%I64xth hint within @HashUpdate_2  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",llvm_cbe_tmp__27);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = sdiv i32 %%storemerge1, 4, !dbg !13 for 0x%I64xth hint within @HashUpdate_2  --> \n", ++aesl_llvm_cbe_32_count);
  llvm_cbe_tmp__6 = (unsigned int )((signed int )(((signed int )llvm_cbe_storemerge1) / ((signed int )4u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__6));
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = sext i32 %%5 to i64, !dbg !13 for 0x%I64xth hint within @HashUpdate_2  --> \n", ++aesl_llvm_cbe_33_count);
  llvm_cbe_tmp__7 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__6);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__7);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds i32* %%data, i64 %%6, !dbg !13 for 0x%I64xth hint within @HashUpdate_2  --> \n", ++aesl_llvm_cbe_34_count);
  llvm_cbe_tmp__8 = (signed int *)(&llvm_cbe_data[(((signed long long )llvm_cbe_tmp__7))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__7));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load i32* %%7, align 4, !dbg !13 for 0x%I64xth hint within @HashUpdate_2  --> \n", ++aesl_llvm_cbe_35_count);
  llvm_cbe_tmp__9 = (unsigned int )*llvm_cbe_tmp__8;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__9);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = trunc i32 %%8 to i8, !dbg !15 for 0x%I64xth hint within @HashUpdate_2  --> \n", ++aesl_llvm_cbe_44_count);
  llvm_cbe_tmp__10 = (unsigned char )((unsigned char )llvm_cbe_tmp__9&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__10);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds [75 x i8]* %%temp, i64 0, i64 %%4, !dbg !15 for 0x%I64xth hint within @HashUpdate_2  --> \n", ++aesl_llvm_cbe_45_count);
  llvm_cbe_tmp__11 = ( char *)(&llvm_cbe_temp[(((signed long long )llvm_cbe_tmp__5))
#ifdef AESL_BC_SIM
 % 75
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__5));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__5) < 75 && "Write access out of array 'temp' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%9, i8* %%10, align 4, !dbg !15 for 0x%I64xth hint within @HashUpdate_2  --> \n", ++aesl_llvm_cbe_46_count);
  *llvm_cbe_tmp__11 = llvm_cbe_tmp__10;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__10);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = lshr i32 %%8, 8, !dbg !15 for 0x%I64xth hint within @HashUpdate_2  --> \n", ++aesl_llvm_cbe_47_count);
  llvm_cbe_tmp__12 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__9&4294967295ull)) >> ((unsigned int )(8u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__12&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = trunc i32 %%11 to i8, !dbg !15 for 0x%I64xth hint within @HashUpdate_2  --> \n", ++aesl_llvm_cbe_56_count);
  llvm_cbe_tmp__13 = (unsigned char )((unsigned char )llvm_cbe_tmp__12&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__13);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = or i32 %%storemerge1, 1, !dbg !15 for 0x%I64xth hint within @HashUpdate_2  --> \n", ++aesl_llvm_cbe_57_count);
  llvm_cbe_tmp__14 = (unsigned int )llvm_cbe_storemerge1 | 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__14);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = sext i32 %%13 to i64, !dbg !15 for 0x%I64xth hint within @HashUpdate_2  --> \n", ++aesl_llvm_cbe_58_count);
  llvm_cbe_tmp__15 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__14);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__15);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds [75 x i8]* %%temp, i64 0, i64 %%14, !dbg !15 for 0x%I64xth hint within @HashUpdate_2  --> \n", ++aesl_llvm_cbe_59_count);
  llvm_cbe_tmp__16 = ( char *)(&llvm_cbe_temp[(((signed long long )llvm_cbe_tmp__15))
#ifdef AESL_BC_SIM
 % 75
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__15));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__15) < 75 && "Write access out of array 'temp' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%12, i8* %%15, align 1, !dbg !15 for 0x%I64xth hint within @HashUpdate_2  --> \n", ++aesl_llvm_cbe_60_count);
  *llvm_cbe_tmp__16 = llvm_cbe_tmp__13;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__13);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = lshr i32 %%8, 16, !dbg !15 for 0x%I64xth hint within @HashUpdate_2  --> \n", ++aesl_llvm_cbe_61_count);
  llvm_cbe_tmp__17 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__9&4294967295ull)) >> ((unsigned int )(16u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__17&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = trunc i32 %%16 to i8, !dbg !15 for 0x%I64xth hint within @HashUpdate_2  --> \n", ++aesl_llvm_cbe_70_count);
  llvm_cbe_tmp__18 = (unsigned char )((unsigned char )llvm_cbe_tmp__17&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__18);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = or i32 %%storemerge1, 2, !dbg !15 for 0x%I64xth hint within @HashUpdate_2  --> \n", ++aesl_llvm_cbe_71_count);
  llvm_cbe_tmp__19 = (unsigned int )llvm_cbe_storemerge1 | 2u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__19);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = sext i32 %%18 to i64, !dbg !15 for 0x%I64xth hint within @HashUpdate_2  --> \n", ++aesl_llvm_cbe_72_count);
  llvm_cbe_tmp__20 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__19);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__20);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = getelementptr inbounds [75 x i8]* %%temp, i64 0, i64 %%19, !dbg !15 for 0x%I64xth hint within @HashUpdate_2  --> \n", ++aesl_llvm_cbe_73_count);
  llvm_cbe_tmp__21 = ( char *)(&llvm_cbe_temp[(((signed long long )llvm_cbe_tmp__20))
#ifdef AESL_BC_SIM
 % 75
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__20));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__20) < 75 && "Write access out of array 'temp' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%17, i8* %%20, align 2, !dbg !15 for 0x%I64xth hint within @HashUpdate_2  --> \n", ++aesl_llvm_cbe_74_count);
  *llvm_cbe_tmp__21 = llvm_cbe_tmp__18;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__18);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = lshr i32 %%8, 24, !dbg !16 for 0x%I64xth hint within @HashUpdate_2  --> \n", ++aesl_llvm_cbe_75_count);
  llvm_cbe_tmp__22 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__9&4294967295ull)) >> ((unsigned int )(24u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__22&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = trunc i32 %%21 to i8, !dbg !15 for 0x%I64xth hint within @HashUpdate_2  --> \n", ++aesl_llvm_cbe_84_count);
  llvm_cbe_tmp__23 = (unsigned char )((unsigned char )llvm_cbe_tmp__22&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__23);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = or i32 %%storemerge1, 3, !dbg !15 for 0x%I64xth hint within @HashUpdate_2  --> \n", ++aesl_llvm_cbe_85_count);
  llvm_cbe_tmp__24 = (unsigned int )llvm_cbe_storemerge1 | 3u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__24);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = sext i32 %%23 to i64, !dbg !15 for 0x%I64xth hint within @HashUpdate_2  --> \n", ++aesl_llvm_cbe_86_count);
  llvm_cbe_tmp__25 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__24);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__25);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = getelementptr inbounds [75 x i8]* %%temp, i64 0, i64 %%24, !dbg !15 for 0x%I64xth hint within @HashUpdate_2  --> \n", ++aesl_llvm_cbe_87_count);
  llvm_cbe_tmp__26 = ( char *)(&llvm_cbe_temp[(((signed long long )llvm_cbe_tmp__25))
#ifdef AESL_BC_SIM
 % 75
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__25));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__25) < 75 && "Write access out of array 'temp' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%22, i8* %%25, align 1, !dbg !15 for 0x%I64xth hint within @HashUpdate_2  --> \n", ++aesl_llvm_cbe_88_count);
  *llvm_cbe_tmp__26 = llvm_cbe_tmp__23;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__23);
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = add nsw i32 %%storemerge1, 4, !dbg !15 for 0x%I64xth hint within @HashUpdate_2  --> \n", ++aesl_llvm_cbe_89_count);
  llvm_cbe_tmp__27 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(4u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__27&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = sext i32 %%26 to i64, !dbg !14 for 0x%I64xth hint within @HashUpdate_2  --> \n", ++aesl_llvm_cbe_98_count);
  llvm_cbe_tmp__28 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__27);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__28);
  if ((((unsigned long long )llvm_cbe_tmp__28&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_byteLen&18446744073709551615ULL))) {
    llvm_cbe_tmp__5__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__28;   /* for PHI node */
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__27;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = shl i64 %%byteLen, 3, !dbg !13 for 0x%I64xth hint within @HashUpdate_2  --> \n", ++aesl_llvm_cbe_101_count);
  llvm_cbe_tmp__29 = (unsigned long long )llvm_cbe_byteLen << 3ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__29);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = call zeroext i2 @Keccak_HashUpdate(%%struct.Keccak_HashInstance* %%ctx, i8* %%1, i64 %%29) nounwind, !dbg !13 for 0x%I64xth hint within @HashUpdate_2  --> \n", ++aesl_llvm_cbe_102_count);
  Keccak_HashUpdate((l_struct_OC_Keccak_HashInstance *)llvm_cbe_ctx, ( char *)llvm_cbe_tmp__3, llvm_cbe_tmp__29);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__29);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__30);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @HashUpdate_2}\n");
  return;
}


void HashInit(l_struct_OC_Keccak_HashInstance *llvm_cbe_ctx, l_struct_OC_paramset_t *llvm_cbe_params,  char llvm_cbe_hashPrefix) {
  static  unsigned long long aesl_llvm_cbe_temp_count = 0;
   char llvm_cbe_temp[1];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
   char *llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
  signed int *llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
  unsigned int llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
  unsigned char llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  unsigned char llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @HashInit\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds [1 x i8]* %%temp, i64 0, i64 0, !dbg !14 for 0x%I64xth hint within @HashInit  --> \n", ++aesl_llvm_cbe_115_count);
  llvm_cbe_tmp__31 = ( char *)(&llvm_cbe_temp[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )0ull) < 1 && "Write access out of array 'temp' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%hashPrefix, i8* %%1, align 1, !dbg !14 for 0x%I64xth hint within @HashInit  --> \n", ++aesl_llvm_cbe_116_count);
  *llvm_cbe_tmp__31 = llvm_cbe_hashPrefix;
if (AESL_DEBUG_TRACE)
printf("\nhashPrefix = 0x%X\n", llvm_cbe_hashPrefix);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds %%struct.paramset_t* %%params, i64 0, i32 2, !dbg !14 for 0x%I64xth hint within @HashInit  --> \n", ++aesl_llvm_cbe_117_count);
  llvm_cbe_tmp__32 = (signed int *)(&llvm_cbe_params->field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = load i32* %%2, align 4, !dbg !14 for 0x%I64xth hint within @HashInit  --> \n", ++aesl_llvm_cbe_118_count);
  llvm_cbe_tmp__33 = (unsigned int )*llvm_cbe_tmp__32;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__33);
  if (((llvm_cbe_tmp__33&4294967295U) == (128u&4294967295U))) {
    goto llvm_cbe_tmp__36;
  } else {
    goto llvm_cbe_tmp__37;
  }

llvm_cbe_tmp__36:
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = call zeroext i2 @Keccak_HashInitialize(%%struct.Keccak_HashInstance* %%ctx, i32 1344, i32 256, i32 0, i8 zeroext 31) nounwind, !dbg !13 for 0x%I64xth hint within @HashInit  --> \n", ++aesl_llvm_cbe_121_count);
  Keccak_HashInitialize((l_struct_OC_Keccak_HashInstance *)llvm_cbe_ctx, 1344u, 256u, 0u, ((unsigned char )31));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",1344u);
printf("\nArgument  = 0x%X",256u);
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%X",((unsigned char )31));
printf("\nReturn  = 0x%X",llvm_cbe_tmp__34);
}
  goto llvm_cbe_tmp__38;

llvm_cbe_tmp__37:
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = call zeroext i2 @Keccak_HashInitialize(%%struct.Keccak_HashInstance* %%ctx, i32 1088, i32 512, i32 0, i8 zeroext 31) nounwind, !dbg !13 for 0x%I64xth hint within @HashInit  --> \n", ++aesl_llvm_cbe_123_count);
  Keccak_HashInitialize((l_struct_OC_Keccak_HashInstance *)llvm_cbe_ctx, 1088u, 512u, 0u, ((unsigned char )31));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",1088u);
printf("\nArgument  = 0x%X",512u);
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%X",((unsigned char )31));
printf("\nReturn  = 0x%X",llvm_cbe_tmp__35);
}
  goto llvm_cbe_tmp__38;

llvm_cbe_tmp__38:
  if (((llvm_cbe_hashPrefix&255U) == (((unsigned char )-1)&255U))) {
    goto llvm_cbe_tmp__39;
  } else {
    goto llvm_cbe_tmp__40;
  }

llvm_cbe_tmp__40:
if (AESL_DEBUG_TRACE)
printf("\n  call void @HashUpdate(%%struct.Keccak_HashInstance* %%ctx, i8* %%1, i64 1), !dbg !14 for 0x%I64xth hint within @HashInit  --> \n", ++aesl_llvm_cbe_127_count);
  HashUpdate((l_struct_OC_Keccak_HashInstance *)llvm_cbe_ctx, ( char *)llvm_cbe_tmp__31, 1ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",1ull);
}
  goto llvm_cbe_tmp__39;

llvm_cbe_tmp__39:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @HashInit}\n");
  return;
}


void HashFinal(l_struct_OC_Keccak_HashInstance *llvm_cbe_ctx) {
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  unsigned char llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  unsigned int llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  unsigned int llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @HashFinal\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = tail call zeroext i2 @Keccak_HashFinal(%%struct.Keccak_HashInstance* %%ctx, i8* null) nounwind, !dbg !13 for 0x%I64xth hint within @HashFinal  --> \n", ++aesl_llvm_cbe_132_count);
  llvm_cbe_tmp__41 = (unsigned char ) /*tail*/ Keccak_HashFinal((l_struct_OC_Keccak_HashInstance *)llvm_cbe_ctx, ( char *)(( char *)/*NULL*/0));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__41);
}
  if (((llvm_cbe_tmp__41&3U) == (((unsigned char )0)&3U))) {
    goto llvm_cbe_tmp__46;
  } else {
    goto llvm_cbe_tmp__47;
  }

llvm_cbe_tmp__47:
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = tail call %%struct._iobuf* @__iob_func() nounwind, !dbg !14 for 0x%I64xth hint within @HashFinal  --> \n", ++aesl_llvm_cbe_138_count);
  llvm_cbe_tmp__42 = (l_struct_OC__iobuf *) /*tail*/ __iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__42);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds %%struct._iobuf* %%4, i64 2, !dbg !14 for 0x%I64xth hint within @HashFinal  --> \n", ++aesl_llvm_cbe_139_count);
  llvm_cbe_tmp__43 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__42[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = zext i2 %%1 to i32, !dbg !14 for 0x%I64xth hint within @HashFinal  --> \n", ++aesl_llvm_cbe_140_count);
  llvm_cbe_tmp__44 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__41&3U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__44);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = tail call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%5, i8* getelementptr inbounds ([43 x i8]* @aesl_internal_.str, i64 0, i64 0), i8* getelementptr inbounds ([10 x i8]* @aesl_internal___func__.HashFinal, i64 0, i64 0), i32 %%6) nounwind, !dbg !14 for 0x%I64xth hint within @HashFinal  --> \n", ++aesl_llvm_cbe_141_count);
   /*tail*/ fprintf((l_struct_OC__iobuf *)llvm_cbe_tmp__43, ( char *)((&aesl_internal__OC_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 43
#endif
])), ( char *)((&aesl_internal___func___OC_HashFinal[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 10
#endif
])), llvm_cbe_tmp__44);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__44);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__45);
}
  goto llvm_cbe_tmp__46;

llvm_cbe_tmp__46:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @HashFinal}\n");
  return;
}


void HashSqueeze(l_struct_OC_Keccak_HashInstance *llvm_cbe_ctx,  char *llvm_cbe_digest, signed long long llvm_cbe_byteLen) {
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  unsigned long long llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;
  unsigned char llvm_cbe_tmp__49;
  static  unsigned long long aesl_llvm_cbe_152_count = 0;
  static  unsigned long long aesl_llvm_cbe_153_count = 0;
  static  unsigned long long aesl_llvm_cbe_154_count = 0;
  static  unsigned long long aesl_llvm_cbe_155_count = 0;
  static  unsigned long long aesl_llvm_cbe_156_count = 0;
  static  unsigned long long aesl_llvm_cbe_157_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__50;
  static  unsigned long long aesl_llvm_cbe_158_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__51;
  static  unsigned long long aesl_llvm_cbe_159_count = 0;
  unsigned int llvm_cbe_tmp__52;
  static  unsigned long long aesl_llvm_cbe_160_count = 0;
  unsigned int llvm_cbe_tmp__53;
  static  unsigned long long aesl_llvm_cbe_161_count = 0;
  static  unsigned long long aesl_llvm_cbe_162_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @HashSqueeze\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = shl i64 %%byteLen, 3, !dbg !14 for 0x%I64xth hint within @HashSqueeze  --> \n", ++aesl_llvm_cbe_150_count);
  llvm_cbe_tmp__48 = (unsigned long long )llvm_cbe_byteLen << 3ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__48);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = tail call zeroext i2 @Keccak_HashSqueeze(%%struct.Keccak_HashInstance* %%ctx, i8* %%digest, i64 %%1) nounwind, !dbg !14 for 0x%I64xth hint within @HashSqueeze  --> \n", ++aesl_llvm_cbe_151_count);
  llvm_cbe_tmp__49 = (unsigned char ) /*tail*/ Keccak_HashSqueeze((l_struct_OC_Keccak_HashInstance *)llvm_cbe_ctx, ( char *)llvm_cbe_digest, llvm_cbe_tmp__48);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__48);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__49);
}
  if (((llvm_cbe_tmp__49&3U) == (((unsigned char )0)&3U))) {
    goto llvm_cbe_tmp__54;
  } else {
    goto llvm_cbe_tmp__55;
  }

llvm_cbe_tmp__55:
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = tail call %%struct._iobuf* @__iob_func() nounwind, !dbg !14 for 0x%I64xth hint within @HashSqueeze  --> \n", ++aesl_llvm_cbe_157_count);
  llvm_cbe_tmp__50 = (l_struct_OC__iobuf *) /*tail*/ __iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__50);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds %%struct._iobuf* %%5, i64 2, !dbg !14 for 0x%I64xth hint within @HashSqueeze  --> \n", ++aesl_llvm_cbe_158_count);
  llvm_cbe_tmp__51 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__50[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = zext i2 %%2 to i32, !dbg !14 for 0x%I64xth hint within @HashSqueeze  --> \n", ++aesl_llvm_cbe_159_count);
  llvm_cbe_tmp__52 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__49&3U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__52);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = tail call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%6, i8* getelementptr inbounds ([45 x i8]* @aesl_internal_.str1, i64 0, i64 0), i8* getelementptr inbounds ([12 x i8]* @aesl_internal___func__.HashSqueeze, i64 0, i64 0), i32 %%7) nounwind, !dbg !14 for 0x%I64xth hint within @HashSqueeze  --> \n", ++aesl_llvm_cbe_160_count);
   /*tail*/ fprintf((l_struct_OC__iobuf *)llvm_cbe_tmp__51, ( char *)((&aesl_internal__OC_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 45
#endif
])), ( char *)((&aesl_internal___func___OC_HashSqueeze[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 12
#endif
])), llvm_cbe_tmp__52);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__52);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__53);
}
  goto llvm_cbe_tmp__54;

llvm_cbe_tmp__54:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @HashSqueeze}\n");
  return;
}


unsigned short toLittleEndian(signed short llvm_cbe_x) {
  static  unsigned long long aesl_llvm_cbe_163_count = 0;
  static  unsigned long long aesl_llvm_cbe_164_count = 0;
  static  unsigned long long aesl_llvm_cbe_165_count = 0;
const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @toLittleEndian\n");
  if (AESL_DEBUG_TRACE)
      printf("\nEND @toLittleEndian}\n");
  return llvm_cbe_x;
}


unsigned short fromLittleEndian(signed short llvm_cbe_x) {
  static  unsigned long long aesl_llvm_cbe_166_count = 0;
  static  unsigned long long aesl_llvm_cbe_167_count = 0;
  static  unsigned long long aesl_llvm_cbe_168_count = 0;
const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @fromLittleEndian\n");
  if (AESL_DEBUG_TRACE)
      printf("\nEND @fromLittleEndian}\n");
  return llvm_cbe_x;
}


void HashUpdateIntLE(l_struct_OC_Keccak_HashInstance *llvm_cbe_ctx, signed short llvm_cbe_x) {
  static  unsigned long long aesl_llvm_cbe_temp_count = 0;
   char llvm_cbe_temp[2];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_169_count = 0;
  static  unsigned long long aesl_llvm_cbe_170_count = 0;
  static  unsigned long long aesl_llvm_cbe_171_count = 0;
  static  unsigned long long aesl_llvm_cbe_172_count = 0;
  static  unsigned long long aesl_llvm_cbe_173_count = 0;
  static  unsigned long long aesl_llvm_cbe_174_count = 0;
  static  unsigned long long aesl_llvm_cbe_175_count = 0;
  unsigned char llvm_cbe_tmp__56;
  static  unsigned long long aesl_llvm_cbe_176_count = 0;
   char *llvm_cbe_tmp__57;
  static  unsigned long long aesl_llvm_cbe_177_count = 0;
  static  unsigned long long aesl_llvm_cbe_178_count = 0;
  unsigned short llvm_cbe_tmp__58;
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
  unsigned char llvm_cbe_tmp__59;
  static  unsigned long long aesl_llvm_cbe_180_count = 0;
   char *llvm_cbe_tmp__60;
  static  unsigned long long aesl_llvm_cbe_181_count = 0;
  static  unsigned long long aesl_llvm_cbe_182_count = 0;
  static  unsigned long long aesl_llvm_cbe_183_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @HashUpdateIntLE\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = trunc i16 %%x to i8, !dbg !13 for 0x%I64xth hint within @HashUpdateIntLE  --> \n", ++aesl_llvm_cbe_175_count);
  llvm_cbe_tmp__56 = (unsigned char )((unsigned char )llvm_cbe_x&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__56);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds [2 x i8]* %%temp, i64 0, i64 0, !dbg !13 for 0x%I64xth hint within @HashUpdateIntLE  --> \n", ++aesl_llvm_cbe_176_count);
  llvm_cbe_tmp__57 = ( char *)(&llvm_cbe_temp[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 2
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )0ull) < 2 && "Write access out of array 'temp' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%1, i8* %%2, align 1, !dbg !13 for 0x%I64xth hint within @HashUpdateIntLE  --> \n", ++aesl_llvm_cbe_177_count);
  *llvm_cbe_tmp__57 = llvm_cbe_tmp__56;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__56);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = lshr i16 %%x, 8, !dbg !14 for 0x%I64xth hint within @HashUpdateIntLE  --> \n", ++aesl_llvm_cbe_178_count);
  llvm_cbe_tmp__58 = (unsigned short )((unsigned short )(((unsigned short )(((unsigned short )(llvm_cbe_x&65535ull)) >> ((unsigned short )(((unsigned short )8)&65535ull))))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned short )(llvm_cbe_tmp__58&65535ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = trunc i16 %%3 to i8, !dbg !14 for 0x%I64xth hint within @HashUpdateIntLE  --> \n", ++aesl_llvm_cbe_179_count);
  llvm_cbe_tmp__59 = (unsigned char )((unsigned char )llvm_cbe_tmp__58&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__59);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds [2 x i8]* %%temp, i64 0, i64 1, !dbg !14 for 0x%I64xth hint within @HashUpdateIntLE  --> \n", ++aesl_llvm_cbe_180_count);
  llvm_cbe_tmp__60 = ( char *)(&llvm_cbe_temp[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 2
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )1ull) < 2 && "Write access out of array 'temp' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%4, i8* %%5, align 1, !dbg !14 for 0x%I64xth hint within @HashUpdateIntLE  --> \n", ++aesl_llvm_cbe_181_count);
  *llvm_cbe_tmp__60 = llvm_cbe_tmp__59;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__59);
if (AESL_DEBUG_TRACE)
printf("\n  call void @HashUpdate(%%struct.Keccak_HashInstance* %%ctx, i8* %%2, i64 2), !dbg !13 for 0x%I64xth hint within @HashUpdateIntLE  --> \n", ++aesl_llvm_cbe_182_count);
  HashUpdate((l_struct_OC_Keccak_HashInstance *)llvm_cbe_ctx, ( char *)llvm_cbe_tmp__57, 2ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",2ull);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @HashUpdateIntLE}\n");
  return;
}

