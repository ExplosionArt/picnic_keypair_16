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
typedef struct l_struct_OC_AES256_CTR_DRBG_struct l_struct_OC_AES256_CTR_DRBG_struct;
typedef struct l_struct_OC__iobuf l_struct_OC__iobuf;
typedef struct l_struct_OC_AES_XOF_struct l_struct_OC_AES_XOF_struct;
typedef struct l_struct_OC_AES_ctx l_struct_OC_AES_ctx;

/* Structure contents */
struct l_struct_OC_AES256_CTR_DRBG_struct {
   char field0[32];
   char field1[16];
  unsigned int field2;
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

struct l_struct_OC_AES_XOF_struct {
   char field0[16];
  unsigned int field1;
  unsigned int field2;
   char field3[32];
   char field4[16];
};

struct l_struct_OC_AES_ctx {
   char field0[240];
   char field1[16];
};


/* External Global Variable Declarations */
extern l_struct_OC_AES256_CTR_DRBG_struct DRBG_ctx;

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
void print_aes256_struct(void);
void fprint_aes256_struct(l_struct_OC__iobuf *llvm_cbe_fp);
void write_aes256_struct( char *llvm_cbe_Key1,  char *llvm_cbe_V1, signed int llvm_cbe_reseed_counter1);
signed int seedexpander_init(l_struct_OC_AES_XOF_struct *llvm_cbe_ctx,  char *llvm_cbe_seed,  char *llvm_cbe_diversifier, signed int llvm_cbe_maxlen);
signed int seedexpander(l_struct_OC_AES_XOF_struct *llvm_cbe_ctx,  char *llvm_cbe_x, signed int llvm_cbe_xlen);
static void aesl_internal_AES256_ECB( char *llvm_cbe_key,  char *llvm_cbe_ctr,  char *llvm_cbe_buffer);
void handleErrors(void);
void randombytes_init( char *llvm_cbe_entropy_input,  char *llvm_cbe_personalization_string, signed int llvm_cbe_security_strength);
void AES256_CTR_DRBG_Update( char *llvm_cbe_provided_data,  char *llvm_cbe_Key,  char *llvm_cbe_V);
signed int randombytes( char *llvm_cbe_x, signed long long llvm_cbe_xlen);
signed int randombytes_sign( char *llvm_cbe_x, signed long long llvm_cbe_xlen);
void AES_init_ctx(l_struct_OC_AES_ctx *,  char *);
void AES_ECB_encrypt(l_struct_OC_AES_ctx *,  char (*)[4][4]);


/* Global Variable Definitions and Initialization */
l_struct_OC_AES256_CTR_DRBG_struct DRBG_ctx __ATTRIBUTE_WEAK__;
static  char aesl_internal__OC_str1[15] = "V_enc[%d]=%d;\n";
static  char aesl_internal__OC_str3[24] = "reseed_counter_enc=%d;\n";
static  char aesl_internal__OC_str[17] = "Key_enc[%d]=%d;\n";
static  char aesl_internal__OC_str2[23] = "reseed_counter_enc=%d\n";


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

void print_aes256_struct(void) {
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
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned int llvm_cbe_storemerge3;
  unsigned int llvm_cbe_storemerge3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  unsigned long long llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
   char *llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  unsigned char llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  unsigned int llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  unsigned int llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  unsigned int llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond4_count = 0;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_count = 0;
  unsigned int llvm_cbe_storemerge12;
  unsigned int llvm_cbe_storemerge12__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  unsigned long long llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
   char *llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  unsigned char llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  unsigned int llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  unsigned int llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  unsigned int llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  unsigned int llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  unsigned int llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @print_aes256_struct\n");
  llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__15;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__15:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = phi i32 [ 0, %%0 ], [ %%7, %%1  for 0x%I64xth hint within @print_aes256_struct  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned int )llvm_cbe_storemerge3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%X",llvm_cbe_storemerge3);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__6);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = sext i32 %%storemerge3 to i64, !dbg !12 for 0x%I64xth hint within @print_aes256_struct  --> \n", ++aesl_llvm_cbe_11_count);
  llvm_cbe_tmp__1 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge3);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.AES256_CTR_DRBG_struct* @DRBG_ctx, i64 0, i32 0, i64 %%2, !dbg !12 for 0x%I64xth hint within @print_aes256_struct  --> \n", ++aesl_llvm_cbe_12_count);
  llvm_cbe_tmp__2 = ( char *)(&DRBG_ctx.field0[(((signed long long )llvm_cbe_tmp__1))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__1));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i8* %%3, align 1, !dbg !12 for 0x%I64xth hint within @print_aes256_struct  --> \n", ++aesl_llvm_cbe_13_count);
  llvm_cbe_tmp__3 = (unsigned char )*llvm_cbe_tmp__2;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__3);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = zext i8 %%4 to i32, !dbg !12 for 0x%I64xth hint within @print_aes256_struct  --> \n", ++aesl_llvm_cbe_14_count);
  llvm_cbe_tmp__4 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__3&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__4);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([17 x i8]* @aesl_internal_.str, i64 0, i64 0), i32 %%storemerge3, i32 %%5) nounwind, !dbg !12 for 0x%I64xth hint within @print_aes256_struct  --> \n", ++aesl_llvm_cbe_15_count);
   /*tail*/ printf(( char *)((&aesl_internal__OC_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 17
#endif
])), llvm_cbe_storemerge3, llvm_cbe_tmp__4);
if (AESL_DEBUG_TRACE) {
printf("\nArgument storemerge3 = 0x%X",llvm_cbe_storemerge3);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__4);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__5);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = add nsw i32 %%storemerge3, 1, !dbg !12 for 0x%I64xth hint within @print_aes256_struct  --> \n", ++aesl_llvm_cbe_16_count);
  llvm_cbe_tmp__6 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__6&4294967295ull)));
  if (((llvm_cbe_tmp__6&4294967295U) == (32u&4294967295U))) {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  } else {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__6;   /* for PHI node */
    goto llvm_cbe_tmp__15;
  }

  } while (1); /* end of syntactic loop '' */
  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12 = phi i32 [ %%13, %%.preheader ], [ 0, %%1  for 0x%I64xth hint within @print_aes256_struct  --> \n", ++aesl_llvm_cbe_storemerge12_count);
  llvm_cbe_storemerge12 = (unsigned int )llvm_cbe_storemerge12__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%X",llvm_cbe_storemerge12);
printf("\n = 0x%X",llvm_cbe_tmp__12);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = sext i32 %%storemerge12 to i64, !dbg !13 for 0x%I64xth hint within @print_aes256_struct  --> \n", ++aesl_llvm_cbe_27_count);
  llvm_cbe_tmp__7 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge12);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__7);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds %%struct.AES256_CTR_DRBG_struct* @DRBG_ctx, i64 0, i32 1, i64 %%8, !dbg !13 for 0x%I64xth hint within @print_aes256_struct  --> \n", ++aesl_llvm_cbe_28_count);
  llvm_cbe_tmp__8 = ( char *)(&DRBG_ctx.field1[(((signed long long )llvm_cbe_tmp__7))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__7));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = load i8* %%9, align 1, !dbg !13 for 0x%I64xth hint within @print_aes256_struct  --> \n", ++aesl_llvm_cbe_29_count);
  llvm_cbe_tmp__9 = (unsigned char )*llvm_cbe_tmp__8;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__9);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = zext i8 %%10 to i32, !dbg !13 for 0x%I64xth hint within @print_aes256_struct  --> \n", ++aesl_llvm_cbe_30_count);
  llvm_cbe_tmp__10 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__9&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__10);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([15 x i8]* @aesl_internal_.str1, i64 0, i64 0), i32 %%storemerge12, i32 %%11) nounwind, !dbg !13 for 0x%I64xth hint within @print_aes256_struct  --> \n", ++aesl_llvm_cbe_31_count);
   /*tail*/ printf(( char *)((&aesl_internal__OC_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 15
#endif
])), llvm_cbe_storemerge12, llvm_cbe_tmp__10);
if (AESL_DEBUG_TRACE) {
printf("\nArgument storemerge12 = 0x%X",llvm_cbe_storemerge12);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__10);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__11);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = add nsw i32 %%storemerge12, 1, !dbg !13 for 0x%I64xth hint within @print_aes256_struct  --> \n", ++aesl_llvm_cbe_32_count);
  llvm_cbe_tmp__12 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__12&4294967295ull)));
  if (((llvm_cbe_tmp__12&4294967295U) == (16u&4294967295U))) {
    goto llvm_cbe_tmp__16;
  } else {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__12;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe_tmp__16:
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = load i32* getelementptr inbounds (%%struct.AES256_CTR_DRBG_struct* @DRBG_ctx, i64 0, i32 2), align 4, !dbg !13 for 0x%I64xth hint within @print_aes256_struct  --> \n", ++aesl_llvm_cbe_43_count);
  llvm_cbe_tmp__13 = (unsigned int )*((&DRBG_ctx.field2));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__13);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([23 x i8]* @aesl_internal_.str2, i64 0, i64 0), i32 %%15) nounwind, !dbg !13 for 0x%I64xth hint within @print_aes256_struct  --> \n", ++aesl_llvm_cbe_44_count);
   /*tail*/ printf(( char *)((&aesl_internal__OC_str2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 23
#endif
])), llvm_cbe_tmp__13);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__13);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__14);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @print_aes256_struct}\n");
  return;
}


void fprint_aes256_struct(l_struct_OC__iobuf *llvm_cbe_fp) {
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned int llvm_cbe_storemerge3;
  unsigned int llvm_cbe_storemerge3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  unsigned long long llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
   char *llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  unsigned char llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  unsigned int llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  unsigned int llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  unsigned int llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond4_count = 0;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_count = 0;
  unsigned int llvm_cbe_storemerge12;
  unsigned int llvm_cbe_storemerge12__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  unsigned long long llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
   char *llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  unsigned char llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  unsigned int llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  unsigned int llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  unsigned int llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  unsigned int llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  unsigned int llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @fprint_aes256_struct\n");
  llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__31;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__31:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = phi i32 [ 0, %%0 ], [ %%7, %%1  for 0x%I64xth hint within @fprint_aes256_struct  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned int )llvm_cbe_storemerge3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%X",llvm_cbe_storemerge3);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__22);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = sext i32 %%storemerge3 to i64, !dbg !12 for 0x%I64xth hint within @fprint_aes256_struct  --> \n", ++aesl_llvm_cbe_60_count);
  llvm_cbe_tmp__17 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge3);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__17);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.AES256_CTR_DRBG_struct* @DRBG_ctx, i64 0, i32 0, i64 %%2, !dbg !12 for 0x%I64xth hint within @fprint_aes256_struct  --> \n", ++aesl_llvm_cbe_61_count);
  llvm_cbe_tmp__18 = ( char *)(&DRBG_ctx.field0[(((signed long long )llvm_cbe_tmp__17))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__17));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i8* %%3, align 1, !dbg !12 for 0x%I64xth hint within @fprint_aes256_struct  --> \n", ++aesl_llvm_cbe_62_count);
  llvm_cbe_tmp__19 = (unsigned char )*llvm_cbe_tmp__18;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__19);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = zext i8 %%4 to i32, !dbg !12 for 0x%I64xth hint within @fprint_aes256_struct  --> \n", ++aesl_llvm_cbe_63_count);
  llvm_cbe_tmp__20 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__19&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__20);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = tail call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%fp, i8* getelementptr inbounds ([17 x i8]* @aesl_internal_.str, i64 0, i64 0), i32 %%storemerge3, i32 %%5) nounwind, !dbg !12 for 0x%I64xth hint within @fprint_aes256_struct  --> \n", ++aesl_llvm_cbe_64_count);
   /*tail*/ fprintf((l_struct_OC__iobuf *)llvm_cbe_fp, ( char *)((&aesl_internal__OC_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 17
#endif
])), llvm_cbe_storemerge3, llvm_cbe_tmp__20);
if (AESL_DEBUG_TRACE) {
printf("\nArgument storemerge3 = 0x%X",llvm_cbe_storemerge3);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__20);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__21);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = add nsw i32 %%storemerge3, 1, !dbg !13 for 0x%I64xth hint within @fprint_aes256_struct  --> \n", ++aesl_llvm_cbe_65_count);
  llvm_cbe_tmp__22 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__22&4294967295ull)));
  if (((llvm_cbe_tmp__22&4294967295U) == (32u&4294967295U))) {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  } else {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__22;   /* for PHI node */
    goto llvm_cbe_tmp__31;
  }

  } while (1); /* end of syntactic loop '' */
  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12 = phi i32 [ %%13, %%.preheader ], [ 0, %%1  for 0x%I64xth hint within @fprint_aes256_struct  --> \n", ++aesl_llvm_cbe_storemerge12_count);
  llvm_cbe_storemerge12 = (unsigned int )llvm_cbe_storemerge12__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%X",llvm_cbe_storemerge12);
printf("\n = 0x%X",llvm_cbe_tmp__28);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = sext i32 %%storemerge12 to i64, !dbg !12 for 0x%I64xth hint within @fprint_aes256_struct  --> \n", ++aesl_llvm_cbe_76_count);
  llvm_cbe_tmp__23 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge12);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__23);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds %%struct.AES256_CTR_DRBG_struct* @DRBG_ctx, i64 0, i32 1, i64 %%8, !dbg !12 for 0x%I64xth hint within @fprint_aes256_struct  --> \n", ++aesl_llvm_cbe_77_count);
  llvm_cbe_tmp__24 = ( char *)(&DRBG_ctx.field1[(((signed long long )llvm_cbe_tmp__23))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__23));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = load i8* %%9, align 1, !dbg !12 for 0x%I64xth hint within @fprint_aes256_struct  --> \n", ++aesl_llvm_cbe_78_count);
  llvm_cbe_tmp__25 = (unsigned char )*llvm_cbe_tmp__24;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__25);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = zext i8 %%10 to i32, !dbg !12 for 0x%I64xth hint within @fprint_aes256_struct  --> \n", ++aesl_llvm_cbe_79_count);
  llvm_cbe_tmp__26 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__25&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__26);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = tail call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%fp, i8* getelementptr inbounds ([15 x i8]* @aesl_internal_.str1, i64 0, i64 0), i32 %%storemerge12, i32 %%11) nounwind, !dbg !12 for 0x%I64xth hint within @fprint_aes256_struct  --> \n", ++aesl_llvm_cbe_80_count);
   /*tail*/ fprintf((l_struct_OC__iobuf *)llvm_cbe_fp, ( char *)((&aesl_internal__OC_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 15
#endif
])), llvm_cbe_storemerge12, llvm_cbe_tmp__26);
if (AESL_DEBUG_TRACE) {
printf("\nArgument storemerge12 = 0x%X",llvm_cbe_storemerge12);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__26);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__27);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = add nsw i32 %%storemerge12, 1, !dbg !13 for 0x%I64xth hint within @fprint_aes256_struct  --> \n", ++aesl_llvm_cbe_81_count);
  llvm_cbe_tmp__28 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__28&4294967295ull)));
  if (((llvm_cbe_tmp__28&4294967295U) == (16u&4294967295U))) {
    goto llvm_cbe_tmp__32;
  } else {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__28;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe_tmp__32:
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = load i32* getelementptr inbounds (%%struct.AES256_CTR_DRBG_struct* @DRBG_ctx, i64 0, i32 2), align 4, !dbg !12 for 0x%I64xth hint within @fprint_aes256_struct  --> \n", ++aesl_llvm_cbe_92_count);
  llvm_cbe_tmp__29 = (unsigned int )*((&DRBG_ctx.field2));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__29);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = tail call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%fp, i8* getelementptr inbounds ([24 x i8]* @aesl_internal_.str3, i64 0, i64 0), i32 %%15) nounwind, !dbg !12 for 0x%I64xth hint within @fprint_aes256_struct  --> \n", ++aesl_llvm_cbe_93_count);
   /*tail*/ fprintf((l_struct_OC__iobuf *)llvm_cbe_fp, ( char *)((&aesl_internal__OC_str3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 24
#endif
])), llvm_cbe_tmp__29);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__29);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__30);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @fprint_aes256_struct}\n");
  return;
}


void write_aes256_struct( char *llvm_cbe_Key1,  char *llvm_cbe_V1, signed int llvm_cbe_reseed_counter1) {
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
  unsigned char llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
   char *llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  unsigned char llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
   char *llvm_cbe_tmp__36;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  unsigned char llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;
  static  unsigned long long aesl_llvm_cbe_152_count = 0;
  static  unsigned long long aesl_llvm_cbe_153_count = 0;
  static  unsigned long long aesl_llvm_cbe_154_count = 0;
   char *llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_155_count = 0;
  unsigned char llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_156_count = 0;
  static  unsigned long long aesl_llvm_cbe_157_count = 0;
  static  unsigned long long aesl_llvm_cbe_158_count = 0;
  static  unsigned long long aesl_llvm_cbe_159_count = 0;
  static  unsigned long long aesl_llvm_cbe_160_count = 0;
  static  unsigned long long aesl_llvm_cbe_161_count = 0;
  static  unsigned long long aesl_llvm_cbe_162_count = 0;
  static  unsigned long long aesl_llvm_cbe_163_count = 0;
  static  unsigned long long aesl_llvm_cbe_164_count = 0;
  static  unsigned long long aesl_llvm_cbe_165_count = 0;
  static  unsigned long long aesl_llvm_cbe_166_count = 0;
   char *llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_167_count = 0;
  unsigned char llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_168_count = 0;
  static  unsigned long long aesl_llvm_cbe_169_count = 0;
  static  unsigned long long aesl_llvm_cbe_170_count = 0;
  static  unsigned long long aesl_llvm_cbe_171_count = 0;
  static  unsigned long long aesl_llvm_cbe_172_count = 0;
  static  unsigned long long aesl_llvm_cbe_173_count = 0;
  static  unsigned long long aesl_llvm_cbe_174_count = 0;
  static  unsigned long long aesl_llvm_cbe_175_count = 0;
  static  unsigned long long aesl_llvm_cbe_176_count = 0;
  static  unsigned long long aesl_llvm_cbe_177_count = 0;
  static  unsigned long long aesl_llvm_cbe_178_count = 0;
   char *llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
  unsigned char llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_180_count = 0;
  static  unsigned long long aesl_llvm_cbe_181_count = 0;
  static  unsigned long long aesl_llvm_cbe_182_count = 0;
  static  unsigned long long aesl_llvm_cbe_183_count = 0;
  static  unsigned long long aesl_llvm_cbe_184_count = 0;
  static  unsigned long long aesl_llvm_cbe_185_count = 0;
  static  unsigned long long aesl_llvm_cbe_186_count = 0;
  static  unsigned long long aesl_llvm_cbe_187_count = 0;
  static  unsigned long long aesl_llvm_cbe_188_count = 0;
  static  unsigned long long aesl_llvm_cbe_189_count = 0;
  static  unsigned long long aesl_llvm_cbe_190_count = 0;
   char *llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_191_count = 0;
  unsigned char llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_192_count = 0;
  static  unsigned long long aesl_llvm_cbe_193_count = 0;
  static  unsigned long long aesl_llvm_cbe_194_count = 0;
  static  unsigned long long aesl_llvm_cbe_195_count = 0;
  static  unsigned long long aesl_llvm_cbe_196_count = 0;
  static  unsigned long long aesl_llvm_cbe_197_count = 0;
  static  unsigned long long aesl_llvm_cbe_198_count = 0;
  static  unsigned long long aesl_llvm_cbe_199_count = 0;
  static  unsigned long long aesl_llvm_cbe_200_count = 0;
  static  unsigned long long aesl_llvm_cbe_201_count = 0;
  static  unsigned long long aesl_llvm_cbe_202_count = 0;
   char *llvm_cbe_tmp__46;
  static  unsigned long long aesl_llvm_cbe_203_count = 0;
  unsigned char llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe_204_count = 0;
  static  unsigned long long aesl_llvm_cbe_205_count = 0;
  static  unsigned long long aesl_llvm_cbe_206_count = 0;
  static  unsigned long long aesl_llvm_cbe_207_count = 0;
  static  unsigned long long aesl_llvm_cbe_208_count = 0;
  static  unsigned long long aesl_llvm_cbe_209_count = 0;
  static  unsigned long long aesl_llvm_cbe_210_count = 0;
  static  unsigned long long aesl_llvm_cbe_211_count = 0;
  static  unsigned long long aesl_llvm_cbe_212_count = 0;
  static  unsigned long long aesl_llvm_cbe_213_count = 0;
  static  unsigned long long aesl_llvm_cbe_214_count = 0;
   char *llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_215_count = 0;
  unsigned char llvm_cbe_tmp__49;
  static  unsigned long long aesl_llvm_cbe_216_count = 0;
  static  unsigned long long aesl_llvm_cbe_217_count = 0;
  static  unsigned long long aesl_llvm_cbe_218_count = 0;
  static  unsigned long long aesl_llvm_cbe_219_count = 0;
  static  unsigned long long aesl_llvm_cbe_220_count = 0;
  static  unsigned long long aesl_llvm_cbe_221_count = 0;
  static  unsigned long long aesl_llvm_cbe_222_count = 0;
  static  unsigned long long aesl_llvm_cbe_223_count = 0;
  static  unsigned long long aesl_llvm_cbe_224_count = 0;
  static  unsigned long long aesl_llvm_cbe_225_count = 0;
  static  unsigned long long aesl_llvm_cbe_226_count = 0;
   char *llvm_cbe_tmp__50;
  static  unsigned long long aesl_llvm_cbe_227_count = 0;
  unsigned char llvm_cbe_tmp__51;
  static  unsigned long long aesl_llvm_cbe_228_count = 0;
  static  unsigned long long aesl_llvm_cbe_229_count = 0;
  static  unsigned long long aesl_llvm_cbe_230_count = 0;
  static  unsigned long long aesl_llvm_cbe_231_count = 0;
  static  unsigned long long aesl_llvm_cbe_232_count = 0;
  static  unsigned long long aesl_llvm_cbe_233_count = 0;
  static  unsigned long long aesl_llvm_cbe_234_count = 0;
  static  unsigned long long aesl_llvm_cbe_235_count = 0;
  static  unsigned long long aesl_llvm_cbe_236_count = 0;
  static  unsigned long long aesl_llvm_cbe_237_count = 0;
  static  unsigned long long aesl_llvm_cbe_238_count = 0;
   char *llvm_cbe_tmp__52;
  static  unsigned long long aesl_llvm_cbe_239_count = 0;
  unsigned char llvm_cbe_tmp__53;
  static  unsigned long long aesl_llvm_cbe_240_count = 0;
  static  unsigned long long aesl_llvm_cbe_241_count = 0;
  static  unsigned long long aesl_llvm_cbe_242_count = 0;
  static  unsigned long long aesl_llvm_cbe_243_count = 0;
  static  unsigned long long aesl_llvm_cbe_244_count = 0;
  static  unsigned long long aesl_llvm_cbe_245_count = 0;
  static  unsigned long long aesl_llvm_cbe_246_count = 0;
  static  unsigned long long aesl_llvm_cbe_247_count = 0;
  static  unsigned long long aesl_llvm_cbe_248_count = 0;
  static  unsigned long long aesl_llvm_cbe_249_count = 0;
  static  unsigned long long aesl_llvm_cbe_250_count = 0;
   char *llvm_cbe_tmp__54;
  static  unsigned long long aesl_llvm_cbe_251_count = 0;
  unsigned char llvm_cbe_tmp__55;
  static  unsigned long long aesl_llvm_cbe_252_count = 0;
  static  unsigned long long aesl_llvm_cbe_253_count = 0;
  static  unsigned long long aesl_llvm_cbe_254_count = 0;
  static  unsigned long long aesl_llvm_cbe_255_count = 0;
  static  unsigned long long aesl_llvm_cbe_256_count = 0;
  static  unsigned long long aesl_llvm_cbe_257_count = 0;
  static  unsigned long long aesl_llvm_cbe_258_count = 0;
  static  unsigned long long aesl_llvm_cbe_259_count = 0;
  static  unsigned long long aesl_llvm_cbe_260_count = 0;
  static  unsigned long long aesl_llvm_cbe_261_count = 0;
  static  unsigned long long aesl_llvm_cbe_262_count = 0;
   char *llvm_cbe_tmp__56;
  static  unsigned long long aesl_llvm_cbe_263_count = 0;
  unsigned char llvm_cbe_tmp__57;
  static  unsigned long long aesl_llvm_cbe_264_count = 0;
  static  unsigned long long aesl_llvm_cbe_265_count = 0;
  static  unsigned long long aesl_llvm_cbe_266_count = 0;
  static  unsigned long long aesl_llvm_cbe_267_count = 0;
  static  unsigned long long aesl_llvm_cbe_268_count = 0;
  static  unsigned long long aesl_llvm_cbe_269_count = 0;
  static  unsigned long long aesl_llvm_cbe_270_count = 0;
  static  unsigned long long aesl_llvm_cbe_271_count = 0;
  static  unsigned long long aesl_llvm_cbe_272_count = 0;
  static  unsigned long long aesl_llvm_cbe_273_count = 0;
  static  unsigned long long aesl_llvm_cbe_274_count = 0;
   char *llvm_cbe_tmp__58;
  static  unsigned long long aesl_llvm_cbe_275_count = 0;
  unsigned char llvm_cbe_tmp__59;
  static  unsigned long long aesl_llvm_cbe_276_count = 0;
  static  unsigned long long aesl_llvm_cbe_277_count = 0;
  static  unsigned long long aesl_llvm_cbe_278_count = 0;
  static  unsigned long long aesl_llvm_cbe_279_count = 0;
  static  unsigned long long aesl_llvm_cbe_280_count = 0;
  static  unsigned long long aesl_llvm_cbe_281_count = 0;
  static  unsigned long long aesl_llvm_cbe_282_count = 0;
  static  unsigned long long aesl_llvm_cbe_283_count = 0;
  static  unsigned long long aesl_llvm_cbe_284_count = 0;
  static  unsigned long long aesl_llvm_cbe_285_count = 0;
  static  unsigned long long aesl_llvm_cbe_286_count = 0;
   char *llvm_cbe_tmp__60;
  static  unsigned long long aesl_llvm_cbe_287_count = 0;
  unsigned char llvm_cbe_tmp__61;
  static  unsigned long long aesl_llvm_cbe_288_count = 0;
  static  unsigned long long aesl_llvm_cbe_289_count = 0;
  static  unsigned long long aesl_llvm_cbe_290_count = 0;
  static  unsigned long long aesl_llvm_cbe_291_count = 0;
  static  unsigned long long aesl_llvm_cbe_292_count = 0;
  static  unsigned long long aesl_llvm_cbe_293_count = 0;
  static  unsigned long long aesl_llvm_cbe_294_count = 0;
  static  unsigned long long aesl_llvm_cbe_295_count = 0;
  static  unsigned long long aesl_llvm_cbe_296_count = 0;
  static  unsigned long long aesl_llvm_cbe_297_count = 0;
  static  unsigned long long aesl_llvm_cbe_298_count = 0;
   char *llvm_cbe_tmp__62;
  static  unsigned long long aesl_llvm_cbe_299_count = 0;
  unsigned char llvm_cbe_tmp__63;
  static  unsigned long long aesl_llvm_cbe_300_count = 0;
  static  unsigned long long aesl_llvm_cbe_301_count = 0;
  static  unsigned long long aesl_llvm_cbe_302_count = 0;
  static  unsigned long long aesl_llvm_cbe_303_count = 0;
  static  unsigned long long aesl_llvm_cbe_304_count = 0;
  static  unsigned long long aesl_llvm_cbe_305_count = 0;
  static  unsigned long long aesl_llvm_cbe_306_count = 0;
  static  unsigned long long aesl_llvm_cbe_307_count = 0;
  static  unsigned long long aesl_llvm_cbe_308_count = 0;
  static  unsigned long long aesl_llvm_cbe_309_count = 0;
  static  unsigned long long aesl_llvm_cbe_310_count = 0;
  static  unsigned long long aesl_llvm_cbe_311_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned int llvm_cbe_storemerge3;
  unsigned int llvm_cbe_storemerge3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_312_count = 0;
  unsigned long long llvm_cbe_tmp__64;
  static  unsigned long long aesl_llvm_cbe_313_count = 0;
   char *llvm_cbe_tmp__65;
  static  unsigned long long aesl_llvm_cbe_314_count = 0;
  unsigned char llvm_cbe_tmp__66;
  static  unsigned long long aesl_llvm_cbe_315_count = 0;
   char *llvm_cbe_tmp__67;
  static  unsigned long long aesl_llvm_cbe_316_count = 0;
  static  unsigned long long aesl_llvm_cbe_317_count = 0;
  unsigned int llvm_cbe_tmp__68;
  static  unsigned long long aesl_llvm_cbe_318_count = 0;
  static  unsigned long long aesl_llvm_cbe_319_count = 0;
  static  unsigned long long aesl_llvm_cbe_320_count = 0;
  static  unsigned long long aesl_llvm_cbe_321_count = 0;
  static  unsigned long long aesl_llvm_cbe_322_count = 0;
  static  unsigned long long aesl_llvm_cbe_323_count = 0;
  static  unsigned long long aesl_llvm_cbe_324_count = 0;
  static  unsigned long long aesl_llvm_cbe_325_count = 0;
  static  unsigned long long aesl_llvm_cbe_326_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_327_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @write_aes256_struct\n");
  llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__69;

llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = load i8* %%V1, align 1, !dbg !12 for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_119_count);
  llvm_cbe_tmp__33 = (unsigned char )*llvm_cbe_V1;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__33);
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%1, i8* getelementptr inbounds (%%struct.AES256_CTR_DRBG_struct* @DRBG_ctx, i64 0, i32 1, i64 0), align 4, !dbg !12 for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_120_count);
  *((&DRBG_ctx.field1[(((signed long long )0ull))])) = llvm_cbe_tmp__33;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__33);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds i8* %%V1, i64 1, !dbg !12 for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_130_count);
  llvm_cbe_tmp__34 = ( char *)(&llvm_cbe_V1[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = load i8* %%2, align 1, !dbg !12 for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_131_count);
  llvm_cbe_tmp__35 = (unsigned char )*llvm_cbe_tmp__34;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__35);
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%3, i8* getelementptr inbounds (%%struct.AES256_CTR_DRBG_struct* @DRBG_ctx, i64 0, i32 1, i64 1), align 1, !dbg !12 for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_132_count);
  *((&DRBG_ctx.field1[(((signed long long )1ull))])) = llvm_cbe_tmp__35;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__35);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds i8* %%V1, i64 2, !dbg !12 for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_142_count);
  llvm_cbe_tmp__36 = ( char *)(&llvm_cbe_V1[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load i8* %%4, align 1, !dbg !12 for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_143_count);
  llvm_cbe_tmp__37 = (unsigned char )*llvm_cbe_tmp__36;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__37);
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%5, i8* getelementptr inbounds (%%struct.AES256_CTR_DRBG_struct* @DRBG_ctx, i64 0, i32 1, i64 2), align 2, !dbg !12 for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_144_count);
  *((&DRBG_ctx.field1[(((signed long long )2ull))])) = llvm_cbe_tmp__37;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__37);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds i8* %%V1, i64 3, !dbg !12 for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_154_count);
  llvm_cbe_tmp__38 = ( char *)(&llvm_cbe_V1[(((signed long long )3ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = load i8* %%6, align 1, !dbg !12 for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_155_count);
  llvm_cbe_tmp__39 = (unsigned char )*llvm_cbe_tmp__38;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__39);
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%7, i8* getelementptr inbounds (%%struct.AES256_CTR_DRBG_struct* @DRBG_ctx, i64 0, i32 1, i64 3), align 1, !dbg !12 for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_156_count);
  *((&DRBG_ctx.field1[(((signed long long )3ull))])) = llvm_cbe_tmp__39;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__39);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds i8* %%V1, i64 4, !dbg !12 for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_166_count);
  llvm_cbe_tmp__40 = ( char *)(&llvm_cbe_V1[(((signed long long )4ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = load i8* %%8, align 1, !dbg !12 for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_167_count);
  llvm_cbe_tmp__41 = (unsigned char )*llvm_cbe_tmp__40;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__41);
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%9, i8* getelementptr inbounds (%%struct.AES256_CTR_DRBG_struct* @DRBG_ctx, i64 0, i32 1, i64 4), align 4, !dbg !12 for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_168_count);
  *((&DRBG_ctx.field1[(((signed long long )4ull))])) = llvm_cbe_tmp__41;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__41);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds i8* %%V1, i64 5, !dbg !12 for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_178_count);
  llvm_cbe_tmp__42 = ( char *)(&llvm_cbe_V1[(((signed long long )5ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = load i8* %%10, align 1, !dbg !12 for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_179_count);
  llvm_cbe_tmp__43 = (unsigned char )*llvm_cbe_tmp__42;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__43);
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%11, i8* getelementptr inbounds (%%struct.AES256_CTR_DRBG_struct* @DRBG_ctx, i64 0, i32 1, i64 5), align 1, !dbg !12 for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_180_count);
  *((&DRBG_ctx.field1[(((signed long long )5ull))])) = llvm_cbe_tmp__43;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__43);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds i8* %%V1, i64 6, !dbg !12 for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_190_count);
  llvm_cbe_tmp__44 = ( char *)(&llvm_cbe_V1[(((signed long long )6ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = load i8* %%12, align 1, !dbg !12 for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_191_count);
  llvm_cbe_tmp__45 = (unsigned char )*llvm_cbe_tmp__44;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__45);
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%13, i8* getelementptr inbounds (%%struct.AES256_CTR_DRBG_struct* @DRBG_ctx, i64 0, i32 1, i64 6), align 2, !dbg !12 for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_192_count);
  *((&DRBG_ctx.field1[(((signed long long )6ull))])) = llvm_cbe_tmp__45;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__45);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds i8* %%V1, i64 7, !dbg !12 for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_202_count);
  llvm_cbe_tmp__46 = ( char *)(&llvm_cbe_V1[(((signed long long )7ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = load i8* %%14, align 1, !dbg !12 for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_203_count);
  llvm_cbe_tmp__47 = (unsigned char )*llvm_cbe_tmp__46;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__47);
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%15, i8* getelementptr inbounds (%%struct.AES256_CTR_DRBG_struct* @DRBG_ctx, i64 0, i32 1, i64 7), align 1, !dbg !12 for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_204_count);
  *((&DRBG_ctx.field1[(((signed long long )7ull))])) = llvm_cbe_tmp__47;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__47);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds i8* %%V1, i64 8, !dbg !12 for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_214_count);
  llvm_cbe_tmp__48 = ( char *)(&llvm_cbe_V1[(((signed long long )8ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = load i8* %%16, align 1, !dbg !12 for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_215_count);
  llvm_cbe_tmp__49 = (unsigned char )*llvm_cbe_tmp__48;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__49);
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%17, i8* getelementptr inbounds (%%struct.AES256_CTR_DRBG_struct* @DRBG_ctx, i64 0, i32 1, i64 8), align 4, !dbg !12 for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_216_count);
  *((&DRBG_ctx.field1[(((signed long long )8ull))])) = llvm_cbe_tmp__49;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__49);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = getelementptr inbounds i8* %%V1, i64 9, !dbg !12 for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_226_count);
  llvm_cbe_tmp__50 = ( char *)(&llvm_cbe_V1[(((signed long long )9ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = load i8* %%18, align 1, !dbg !12 for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_227_count);
  llvm_cbe_tmp__51 = (unsigned char )*llvm_cbe_tmp__50;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__51);
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%19, i8* getelementptr inbounds (%%struct.AES256_CTR_DRBG_struct* @DRBG_ctx, i64 0, i32 1, i64 9), align 1, !dbg !12 for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_228_count);
  *((&DRBG_ctx.field1[(((signed long long )9ull))])) = llvm_cbe_tmp__51;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__51);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = getelementptr inbounds i8* %%V1, i64 10, !dbg !12 for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_238_count);
  llvm_cbe_tmp__52 = ( char *)(&llvm_cbe_V1[(((signed long long )10ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = load i8* %%20, align 1, !dbg !12 for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_239_count);
  llvm_cbe_tmp__53 = (unsigned char )*llvm_cbe_tmp__52;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__53);
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%21, i8* getelementptr inbounds (%%struct.AES256_CTR_DRBG_struct* @DRBG_ctx, i64 0, i32 1, i64 10), align 2, !dbg !12 for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_240_count);
  *((&DRBG_ctx.field1[(((signed long long )10ull))])) = llvm_cbe_tmp__53;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__53);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = getelementptr inbounds i8* %%V1, i64 11, !dbg !12 for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_250_count);
  llvm_cbe_tmp__54 = ( char *)(&llvm_cbe_V1[(((signed long long )11ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = load i8* %%22, align 1, !dbg !12 for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_251_count);
  llvm_cbe_tmp__55 = (unsigned char )*llvm_cbe_tmp__54;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__55);
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%23, i8* getelementptr inbounds (%%struct.AES256_CTR_DRBG_struct* @DRBG_ctx, i64 0, i32 1, i64 11), align 1, !dbg !12 for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_252_count);
  *((&DRBG_ctx.field1[(((signed long long )11ull))])) = llvm_cbe_tmp__55;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__55);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = getelementptr inbounds i8* %%V1, i64 12, !dbg !12 for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_262_count);
  llvm_cbe_tmp__56 = ( char *)(&llvm_cbe_V1[(((signed long long )12ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = load i8* %%24, align 1, !dbg !12 for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_263_count);
  llvm_cbe_tmp__57 = (unsigned char )*llvm_cbe_tmp__56;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__57);
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%25, i8* getelementptr inbounds (%%struct.AES256_CTR_DRBG_struct* @DRBG_ctx, i64 0, i32 1, i64 12), align 4, !dbg !12 for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_264_count);
  *((&DRBG_ctx.field1[(((signed long long )12ull))])) = llvm_cbe_tmp__57;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__57);
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = getelementptr inbounds i8* %%V1, i64 13, !dbg !12 for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_274_count);
  llvm_cbe_tmp__58 = ( char *)(&llvm_cbe_V1[(((signed long long )13ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = load i8* %%26, align 1, !dbg !12 for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_275_count);
  llvm_cbe_tmp__59 = (unsigned char )*llvm_cbe_tmp__58;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__59);
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%27, i8* getelementptr inbounds (%%struct.AES256_CTR_DRBG_struct* @DRBG_ctx, i64 0, i32 1, i64 13), align 1, !dbg !12 for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_276_count);
  *((&DRBG_ctx.field1[(((signed long long )13ull))])) = llvm_cbe_tmp__59;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__59);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = getelementptr inbounds i8* %%V1, i64 14, !dbg !12 for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_286_count);
  llvm_cbe_tmp__60 = ( char *)(&llvm_cbe_V1[(((signed long long )14ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = load i8* %%28, align 1, !dbg !12 for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_287_count);
  llvm_cbe_tmp__61 = (unsigned char )*llvm_cbe_tmp__60;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__61);
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%29, i8* getelementptr inbounds (%%struct.AES256_CTR_DRBG_struct* @DRBG_ctx, i64 0, i32 1, i64 14), align 2, !dbg !12 for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_288_count);
  *((&DRBG_ctx.field1[(((signed long long )14ull))])) = llvm_cbe_tmp__61;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__61);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = getelementptr inbounds i8* %%V1, i64 15, !dbg !12 for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_298_count);
  llvm_cbe_tmp__62 = ( char *)(&llvm_cbe_V1[(((signed long long )15ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = load i8* %%30, align 1, !dbg !12 for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_299_count);
  llvm_cbe_tmp__63 = (unsigned char )*llvm_cbe_tmp__62;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__63);
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%31, i8* getelementptr inbounds (%%struct.AES256_CTR_DRBG_struct* @DRBG_ctx, i64 0, i32 1, i64 15), align 1, !dbg !12 for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_300_count);
  *((&DRBG_ctx.field1[(((signed long long )15ull))])) = llvm_cbe_tmp__63;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__63);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%reseed_counter1, i32* getelementptr inbounds (%%struct.AES256_CTR_DRBG_struct* @DRBG_ctx, i64 0, i32 2), align 4, !dbg !13 for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_310_count);
  *((&DRBG_ctx.field2)) = llvm_cbe_reseed_counter1;
if (AESL_DEBUG_TRACE)
printf("\nreseed_counter1 = 0x%X\n", llvm_cbe_reseed_counter1);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @write_aes256_struct}\n");
  return;
  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__69:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = phi i32 [ 0, %%0 ], [ %%37, %%32  for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned int )llvm_cbe_storemerge3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%X",llvm_cbe_storemerge3);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__68);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = sext i32 %%storemerge3 to i64, !dbg !12 for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_312_count);
  llvm_cbe_tmp__64 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge3);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__64);
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = getelementptr inbounds i8* %%Key1, i64 %%33, !dbg !12 for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_313_count);
  llvm_cbe_tmp__65 = ( char *)(&llvm_cbe_Key1[(((signed long long )llvm_cbe_tmp__64))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__64));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = load i8* %%34, align 1, !dbg !12 for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_314_count);
  llvm_cbe_tmp__66 = (unsigned char )*llvm_cbe_tmp__65;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__66);
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = getelementptr inbounds %%struct.AES256_CTR_DRBG_struct* @DRBG_ctx, i64 0, i32 0, i64 %%33, !dbg !12 for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_315_count);
  llvm_cbe_tmp__67 = ( char *)(&DRBG_ctx.field0[(((signed long long )llvm_cbe_tmp__64))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__64));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%35, i8* %%36, align 1, !dbg !12 for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_316_count);
  *llvm_cbe_tmp__67 = llvm_cbe_tmp__66;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__66);
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = add nsw i32 %%storemerge3, 1, !dbg !13 for 0x%I64xth hint within @write_aes256_struct  --> \n", ++aesl_llvm_cbe_317_count);
  llvm_cbe_tmp__68 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__68&4294967295ull)));
  if (((llvm_cbe_tmp__68&4294967295U) == (32u&4294967295U))) {
    goto llvm_cbe__2e_preheader;
  } else {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__68;   /* for PHI node */
    goto llvm_cbe_tmp__69;
  }

  } while (1); /* end of syntactic loop '' */
}


signed int seedexpander_init(l_struct_OC_AES_XOF_struct *llvm_cbe_ctx,  char *llvm_cbe_seed,  char *llvm_cbe_diversifier, signed int llvm_cbe_maxlen) {
  static  unsigned long long aesl_llvm_cbe_328_count = 0;
  static  unsigned long long aesl_llvm_cbe_329_count = 0;
  static  unsigned long long aesl_llvm_cbe_330_count = 0;
  static  unsigned long long aesl_llvm_cbe_331_count = 0;
  static  unsigned long long aesl_llvm_cbe_332_count = 0;
  static  unsigned long long aesl_llvm_cbe_333_count = 0;
  static  unsigned long long aesl_llvm_cbe_334_count = 0;
  static  unsigned long long aesl_llvm_cbe_335_count = 0;
  static  unsigned long long aesl_llvm_cbe_336_count = 0;
  static  unsigned long long aesl_llvm_cbe_337_count = 0;
  static  unsigned long long aesl_llvm_cbe_338_count = 0;
  static  unsigned long long aesl_llvm_cbe_339_count = 0;
  static  unsigned long long aesl_llvm_cbe_340_count = 0;
  static  unsigned long long aesl_llvm_cbe_341_count = 0;
  static  unsigned long long aesl_llvm_cbe_342_count = 0;
  static  unsigned long long aesl_llvm_cbe_343_count = 0;
  static  unsigned long long aesl_llvm_cbe_344_count = 0;
  static  unsigned long long aesl_llvm_cbe_345_count = 0;
  static  unsigned long long aesl_llvm_cbe_346_count = 0;
  static  unsigned long long aesl_llvm_cbe_347_count = 0;
  static  unsigned long long aesl_llvm_cbe_348_count = 0;
  static  unsigned long long aesl_llvm_cbe_349_count = 0;
  static  unsigned long long aesl_llvm_cbe_350_count = 0;
  static  unsigned long long aesl_llvm_cbe_351_count = 0;
  static  unsigned long long aesl_llvm_cbe_352_count = 0;
  static  unsigned long long aesl_llvm_cbe_353_count = 0;
  signed int *llvm_cbe_tmp__70;
  static  unsigned long long aesl_llvm_cbe_354_count = 0;
  static  unsigned long long aesl_llvm_cbe_355_count = 0;
   char *llvm_cbe_tmp__71;
  static  unsigned long long aesl_llvm_cbe_356_count = 0;
   char *llvm_cbe_tmp__72;
  static  unsigned long long aesl_llvm_cbe_357_count = 0;
   char *llvm_cbe_tmp__73;
  static  unsigned long long aesl_llvm_cbe_358_count = 0;
   char *llvm_cbe_tmp__74;
  static  unsigned long long aesl_llvm_cbe_359_count = 0;
  unsigned char llvm_cbe_tmp__75;
  static  unsigned long long aesl_llvm_cbe_360_count = 0;
   char *llvm_cbe_tmp__76;
  static  unsigned long long aesl_llvm_cbe_361_count = 0;
  static  unsigned long long aesl_llvm_cbe_362_count = 0;
  unsigned int llvm_cbe_tmp__77;
  static  unsigned long long aesl_llvm_cbe_363_count = 0;
  static  unsigned long long aesl_llvm_cbe_364_count = 0;
  static  unsigned long long aesl_llvm_cbe_365_count = 0;
  static  unsigned long long aesl_llvm_cbe_366_count = 0;
  static  unsigned long long aesl_llvm_cbe_367_count = 0;
  static  unsigned long long aesl_llvm_cbe_368_count = 0;
  static  unsigned long long aesl_llvm_cbe_369_count = 0;
  static  unsigned long long aesl_llvm_cbe_370_count = 0;
  static  unsigned long long aesl_llvm_cbe_371_count = 0;
  static  unsigned long long aesl_llvm_cbe_372_count = 0;
  static  unsigned long long aesl_llvm_cbe_373_count = 0;
  unsigned char llvm_cbe_tmp__78;
  static  unsigned long long aesl_llvm_cbe_374_count = 0;
   char *llvm_cbe_tmp__79;
  static  unsigned long long aesl_llvm_cbe_375_count = 0;
  static  unsigned long long aesl_llvm_cbe_376_count = 0;
  unsigned int llvm_cbe_tmp__80;
  static  unsigned long long aesl_llvm_cbe_377_count = 0;
  static  unsigned long long aesl_llvm_cbe_378_count = 0;
  static  unsigned long long aesl_llvm_cbe_379_count = 0;
  static  unsigned long long aesl_llvm_cbe_380_count = 0;
  static  unsigned long long aesl_llvm_cbe_381_count = 0;
  static  unsigned long long aesl_llvm_cbe_382_count = 0;
  static  unsigned long long aesl_llvm_cbe_383_count = 0;
  static  unsigned long long aesl_llvm_cbe_384_count = 0;
  static  unsigned long long aesl_llvm_cbe_385_count = 0;
  static  unsigned long long aesl_llvm_cbe_386_count = 0;
  static  unsigned long long aesl_llvm_cbe_387_count = 0;
  unsigned char llvm_cbe_tmp__81;
  static  unsigned long long aesl_llvm_cbe_388_count = 0;
   char *llvm_cbe_tmp__82;
  static  unsigned long long aesl_llvm_cbe_389_count = 0;
  static  unsigned long long aesl_llvm_cbe_390_count = 0;
  unsigned int llvm_cbe_tmp__83;
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
  unsigned char llvm_cbe_tmp__84;
  static  unsigned long long aesl_llvm_cbe_402_count = 0;
   char *llvm_cbe_tmp__85;
  static  unsigned long long aesl_llvm_cbe_403_count = 0;
  static  unsigned long long aesl_llvm_cbe_404_count = 0;
   char *llvm_cbe_tmp__86;
  static  unsigned long long aesl_llvm_cbe_405_count = 0;
   char *llvm_cbe_tmp__87;
  static  unsigned long long aesl_llvm_cbe_406_count = 0;
  signed int *llvm_cbe_tmp__88;
  static  unsigned long long aesl_llvm_cbe_407_count = 0;
  static  unsigned long long aesl_llvm_cbe_408_count = 0;
   char *llvm_cbe_tmp__89;
  static  unsigned long long aesl_llvm_cbe_409_count = 0;
   char *llvm_cbe_tmp__90;
  static  unsigned long long aesl_llvm_cbe_410_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @seedexpander_init\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.AES_XOF_struct* %%ctx, i64 0, i32 2, !dbg !12 for 0x%I64xth hint within @seedexpander_init  --> \n", ++aesl_llvm_cbe_353_count);
  llvm_cbe_tmp__70 = (signed int *)(&llvm_cbe_ctx->field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%maxlen, i32* %%1, align 4, !dbg !12 for 0x%I64xth hint within @seedexpander_init  --> \n", ++aesl_llvm_cbe_354_count);
  *llvm_cbe_tmp__70 = llvm_cbe_maxlen;
if (AESL_DEBUG_TRACE)
printf("\nmaxlen = 0x%X\n", llvm_cbe_maxlen);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds %%struct.AES_XOF_struct* %%ctx, i64 0, i32 3, i64 0, !dbg !12 for 0x%I64xth hint within @seedexpander_init  --> \n", ++aesl_llvm_cbe_355_count);
  llvm_cbe_tmp__71 = ( char *)(&llvm_cbe_ctx->field3[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = call i8* @memcpy(i8* %%2, i8* %%seed, i64 32 for 0x%I64xth hint within @seedexpander_init  --> \n", ++aesl_llvm_cbe_356_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__71, ( char *)llvm_cbe_seed, 32ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",32ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__72);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds %%struct.AES_XOF_struct* %%ctx, i64 0, i32 4, i64 0, !dbg !12 for 0x%I64xth hint within @seedexpander_init  --> \n", ++aesl_llvm_cbe_357_count);
  llvm_cbe_tmp__73 = ( char *)(&llvm_cbe_ctx->field4[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = call i8* @memcpy(i8* %%4, i8* %%diversifier, i64 8 for 0x%I64xth hint within @seedexpander_init  --> \n", ++aesl_llvm_cbe_358_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__73, ( char *)llvm_cbe_diversifier, 8ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",8ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__74);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = trunc i32 %%maxlen to i8, !dbg !12 for 0x%I64xth hint within @seedexpander_init  --> \n", ++aesl_llvm_cbe_359_count);
  llvm_cbe_tmp__75 = (unsigned char )((unsigned char )llvm_cbe_maxlen&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__75);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds %%struct.AES_XOF_struct* %%ctx, i64 0, i32 4, i64 11, !dbg !12 for 0x%I64xth hint within @seedexpander_init  --> \n", ++aesl_llvm_cbe_360_count);
  llvm_cbe_tmp__76 = ( char *)(&llvm_cbe_ctx->field4[(((signed long long )11ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%6, i8* %%7, align 1, !dbg !12 for 0x%I64xth hint within @seedexpander_init  --> \n", ++aesl_llvm_cbe_361_count);
  *llvm_cbe_tmp__76 = llvm_cbe_tmp__75;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__75);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = lshr i32 %%maxlen, 8, !dbg !14 for 0x%I64xth hint within @seedexpander_init  --> \n", ++aesl_llvm_cbe_362_count);
  llvm_cbe_tmp__77 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_maxlen&4294967295ull)) >> ((unsigned int )(8u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__77&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = trunc i32 %%8 to i8, !dbg !12 for 0x%I64xth hint within @seedexpander_init  --> \n", ++aesl_llvm_cbe_373_count);
  llvm_cbe_tmp__78 = (unsigned char )((unsigned char )llvm_cbe_tmp__77&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__78);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds %%struct.AES_XOF_struct* %%ctx, i64 0, i32 4, i64 10, !dbg !12 for 0x%I64xth hint within @seedexpander_init  --> \n", ++aesl_llvm_cbe_374_count);
  llvm_cbe_tmp__79 = ( char *)(&llvm_cbe_ctx->field4[(((signed long long )10ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%9, i8* %%10, align 1, !dbg !12 for 0x%I64xth hint within @seedexpander_init  --> \n", ++aesl_llvm_cbe_375_count);
  *llvm_cbe_tmp__79 = llvm_cbe_tmp__78;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__78);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = lshr i32 %%maxlen, 16, !dbg !14 for 0x%I64xth hint within @seedexpander_init  --> \n", ++aesl_llvm_cbe_376_count);
  llvm_cbe_tmp__80 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_maxlen&4294967295ull)) >> ((unsigned int )(16u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__80&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = trunc i32 %%11 to i8, !dbg !13 for 0x%I64xth hint within @seedexpander_init  --> \n", ++aesl_llvm_cbe_387_count);
  llvm_cbe_tmp__81 = (unsigned char )((unsigned char )llvm_cbe_tmp__80&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__81);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds %%struct.AES_XOF_struct* %%ctx, i64 0, i32 4, i64 9, !dbg !13 for 0x%I64xth hint within @seedexpander_init  --> \n", ++aesl_llvm_cbe_388_count);
  llvm_cbe_tmp__82 = ( char *)(&llvm_cbe_ctx->field4[(((signed long long )9ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%12, i8* %%13, align 1, !dbg !13 for 0x%I64xth hint within @seedexpander_init  --> \n", ++aesl_llvm_cbe_389_count);
  *llvm_cbe_tmp__82 = llvm_cbe_tmp__81;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__81);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = lshr i32 %%maxlen, 24, !dbg !14 for 0x%I64xth hint within @seedexpander_init  --> \n", ++aesl_llvm_cbe_390_count);
  llvm_cbe_tmp__83 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_maxlen&4294967295ull)) >> ((unsigned int )(24u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__83&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = trunc i32 %%14 to i8, !dbg !13 for 0x%I64xth hint within @seedexpander_init  --> \n", ++aesl_llvm_cbe_401_count);
  llvm_cbe_tmp__84 = (unsigned char )((unsigned char )llvm_cbe_tmp__83&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__84);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds %%struct.AES_XOF_struct* %%ctx, i64 0, i32 4, i64 8, !dbg !13 for 0x%I64xth hint within @seedexpander_init  --> \n", ++aesl_llvm_cbe_402_count);
  llvm_cbe_tmp__85 = ( char *)(&llvm_cbe_ctx->field4[(((signed long long )8ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%15, i8* %%16, align 1, !dbg !13 for 0x%I64xth hint within @seedexpander_init  --> \n", ++aesl_llvm_cbe_403_count);
  *llvm_cbe_tmp__85 = llvm_cbe_tmp__84;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__84);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds %%struct.AES_XOF_struct* %%ctx, i64 0, i32 4, i64 12, !dbg !13 for 0x%I64xth hint within @seedexpander_init  --> \n", ++aesl_llvm_cbe_404_count);
  llvm_cbe_tmp__86 = ( char *)(&llvm_cbe_ctx->field4[(((signed long long )12ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = call i8* @memset(i8* %%17, i32 0, i64 4 for 0x%I64xth hint within @seedexpander_init  --> \n", ++aesl_llvm_cbe_405_count);
  ( char *)memset(( char *)llvm_cbe_tmp__86, 0u, 4ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",4ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__87);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = getelementptr inbounds %%struct.AES_XOF_struct* %%ctx, i64 0, i32 1, !dbg !13 for 0x%I64xth hint within @seedexpander_init  --> \n", ++aesl_llvm_cbe_406_count);
  llvm_cbe_tmp__88 = (signed int *)(&llvm_cbe_ctx->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 16, i32* %%19, align 4, !dbg !13 for 0x%I64xth hint within @seedexpander_init  --> \n", ++aesl_llvm_cbe_407_count);
  *llvm_cbe_tmp__88 = 16u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 16u);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = getelementptr inbounds %%struct.AES_XOF_struct* %%ctx, i64 0, i32 0, i64 0, !dbg !13 for 0x%I64xth hint within @seedexpander_init  --> \n", ++aesl_llvm_cbe_408_count);
  llvm_cbe_tmp__89 = ( char *)(&llvm_cbe_ctx->field0[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = call i8* @memset(i8* %%20, i32 0, i64 16 for 0x%I64xth hint within @seedexpander_init  --> \n", ++aesl_llvm_cbe_409_count);
  ( char *)memset(( char *)llvm_cbe_tmp__89, 0u, 16ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",16ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__90);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @seedexpander_init}\n");
  return 0u;
}


signed int seedexpander(l_struct_OC_AES_XOF_struct *llvm_cbe_ctx,  char *llvm_cbe_x, signed int llvm_cbe_xlen) {
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
  static  unsigned long long aesl_llvm_cbe_443_count = 0;
  static  unsigned long long aesl_llvm_cbe_444_count = 0;
  signed int *llvm_cbe_tmp__91;
  static  unsigned long long aesl_llvm_cbe_445_count = 0;
  unsigned int llvm_cbe_tmp__92;
  static  unsigned long long aesl_llvm_cbe_446_count = 0;
  static  unsigned long long aesl_llvm_cbe_447_count = 0;
  static  unsigned long long aesl_llvm_cbe_448_count = 0;
  unsigned int llvm_cbe_tmp__93;
  static  unsigned long long aesl_llvm_cbe_449_count = 0;
  static  unsigned long long aesl_llvm_cbe_450_count = 0;
  static  unsigned long long aesl_llvm_cbe_451_count = 0;
  static  unsigned long long aesl_llvm_cbe_452_count = 0;
  static  unsigned long long aesl_llvm_cbe_453_count = 0;
  static  unsigned long long aesl_llvm_cbe_454_count = 0;
  signed int *llvm_cbe_tmp__94;
  static  unsigned long long aesl_llvm_cbe_455_count = 0;
   char *llvm_cbe_tmp__95;
  static  unsigned long long aesl_llvm_cbe_456_count = 0;
   char *llvm_cbe_tmp__96;
  static  unsigned long long aesl_llvm_cbe_457_count = 0;
   char *llvm_cbe_tmp__97;
  static  unsigned long long aesl_llvm_cbe_458_count = 0;
  static  unsigned long long aesl_llvm_cbe_459_count = 0;
  unsigned int llvm_cbe_tmp__98;
  unsigned int llvm_cbe_tmp__98__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_460_count = 0;
  unsigned int llvm_cbe_tmp__99;
  unsigned int llvm_cbe_tmp__99__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_461_count = 0;
  static  unsigned long long aesl_llvm_cbe_462_count = 0;
  static  unsigned long long aesl_llvm_cbe_463_count = 0;
  unsigned int llvm_cbe_tmp__100;
  static  unsigned long long aesl_llvm_cbe_464_count = 0;
  unsigned int llvm_cbe_tmp__101;
  static  unsigned long long aesl_llvm_cbe_465_count = 0;
  static  unsigned long long aesl_llvm_cbe_466_count = 0;
  static  unsigned long long aesl_llvm_cbe_467_count = 0;
  unsigned long long llvm_cbe_tmp__102;
  static  unsigned long long aesl_llvm_cbe_468_count = 0;
   char *llvm_cbe_tmp__103;
  static  unsigned long long aesl_llvm_cbe_469_count = 0;
  unsigned long long llvm_cbe_tmp__104;
  static  unsigned long long aesl_llvm_cbe_470_count = 0;
   char *llvm_cbe_tmp__105;
  static  unsigned long long aesl_llvm_cbe_471_count = 0;
  unsigned long long llvm_cbe_tmp__106;
  static  unsigned long long aesl_llvm_cbe_472_count = 0;
   char *llvm_cbe_tmp__107;
  static  unsigned long long aesl_llvm_cbe_473_count = 0;
  unsigned int llvm_cbe_tmp__108;
  static  unsigned long long aesl_llvm_cbe_474_count = 0;
  unsigned int llvm_cbe_tmp__109;
  static  unsigned long long aesl_llvm_cbe_475_count = 0;
  static  unsigned long long aesl_llvm_cbe_476_count = 0;
  static  unsigned long long aesl_llvm_cbe_477_count = 0;
  unsigned long long llvm_cbe_tmp__110;
  static  unsigned long long aesl_llvm_cbe_478_count = 0;
   char *llvm_cbe_tmp__111;
  static  unsigned long long aesl_llvm_cbe_479_count = 0;
  unsigned long long llvm_cbe_tmp__112;
  static  unsigned long long aesl_llvm_cbe_480_count = 0;
   char *llvm_cbe_tmp__113;
  static  unsigned long long aesl_llvm_cbe_481_count = 0;
  unsigned long long llvm_cbe_tmp__114;
  static  unsigned long long aesl_llvm_cbe_482_count = 0;
   char *llvm_cbe_tmp__115;
  static  unsigned long long aesl_llvm_cbe_483_count = 0;
  unsigned int llvm_cbe_tmp__116;
  static  unsigned long long aesl_llvm_cbe_484_count = 0;
  unsigned int llvm_cbe_tmp__117;
  static  unsigned long long aesl_llvm_cbe_485_count = 0;
  unsigned int llvm_cbe_tmp__118;
  static  unsigned long long aesl_llvm_cbe_486_count = 0;
  static  unsigned long long aesl_llvm_cbe_487_count = 0;
  static  unsigned long long aesl_llvm_cbe_488_count = 0;
  static  unsigned long long aesl_llvm_cbe_489_count = 0;
  static  unsigned long long aesl_llvm_cbe_490_count = 0;
  static  unsigned long long aesl_llvm_cbe_491_count = 0;
  static  unsigned long long aesl_llvm_cbe_492_count = 0;
  static  unsigned long long aesl_llvm_cbe_493_count = 0;
  static  unsigned long long aesl_llvm_cbe_494_count = 0;
  unsigned int llvm_cbe_tmp__119;
  static  unsigned long long aesl_llvm_cbe_495_count = 0;
  unsigned int llvm_cbe_tmp__120;
  static  unsigned long long aesl_llvm_cbe_496_count = 0;
  static  unsigned long long aesl_llvm_cbe_497_count = 0;
  static  unsigned long long aesl_llvm_cbe_498_count = 0;
  static  unsigned long long aesl_llvm_cbe_499_count = 0;
  static  unsigned long long aesl_llvm_cbe_500_count = 0;
  static  unsigned long long aesl_llvm_cbe_501_count = 0;
  static  unsigned long long aesl_llvm_cbe_502_count = 0;
  static  unsigned long long aesl_llvm_cbe_503_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge_count = 0;
  unsigned int llvm_cbe_storemerge;
  unsigned int llvm_cbe_storemerge__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_504_count = 0;
  static  unsigned long long aesl_llvm_cbe_505_count = 0;
  static  unsigned long long aesl_llvm_cbe_506_count = 0;
  static  unsigned long long aesl_llvm_cbe_507_count = 0;
  static  unsigned long long aesl_llvm_cbe_508_count = 0;
  static  unsigned long long aesl_llvm_cbe_509_count = 0;
  static  unsigned long long aesl_llvm_cbe_510_count = 0;
  static  unsigned long long aesl_llvm_cbe_511_count = 0;
  unsigned long long llvm_cbe_tmp__121;
  static  unsigned long long aesl_llvm_cbe_512_count = 0;
   char *llvm_cbe_tmp__122;
  static  unsigned long long aesl_llvm_cbe_513_count = 0;
  unsigned char llvm_cbe_tmp__123;
  static  unsigned long long aesl_llvm_cbe_514_count = 0;
  static  unsigned long long aesl_llvm_cbe_515_count = 0;
  static  unsigned long long aesl_llvm_cbe_516_count = 0;
  static  unsigned long long aesl_llvm_cbe_517_count = 0;
  unsigned int llvm_cbe_tmp__124;
  static  unsigned long long aesl_llvm_cbe_518_count = 0;
  static  unsigned long long aesl_llvm_cbe_519_count = 0;
  static  unsigned long long aesl_llvm_cbe_520_count = 0;
  unsigned char llvm_cbe_tmp__125;
  static  unsigned long long aesl_llvm_cbe_521_count = 0;
  static  unsigned long long aesl_llvm_cbe_522_count = 0;
  static  unsigned long long aesl_llvm_cbe_523_count = 0;
  static  unsigned long long aesl_llvm_cbe_524_count = 0;
  unsigned int llvm_cbe_tmp__126;
  unsigned int llvm_cbe_tmp__126__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_525_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @seedexpander\n");
  if (((llvm_cbe_x) == ((( char *)/*NULL*/0)))) {
    llvm_cbe_tmp__126__PHI_TEMPORARY = (unsigned int )4294967294u;   /* for PHI node */
    goto llvm_cbe__2e_loopexit2;
  } else {
    goto llvm_cbe_tmp__127;
  }

llvm_cbe_tmp__127:
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.AES_XOF_struct* %%ctx, i64 0, i32 2, !dbg !12 for 0x%I64xth hint within @seedexpander  --> \n", ++aesl_llvm_cbe_444_count);
  llvm_cbe_tmp__91 = (signed int *)(&llvm_cbe_ctx->field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i32* %%3, align 4, !dbg !12 for 0x%I64xth hint within @seedexpander  --> \n", ++aesl_llvm_cbe_445_count);
  llvm_cbe_tmp__92 = (unsigned int )*llvm_cbe_tmp__91;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__92);
  if ((((unsigned int )llvm_cbe_tmp__92&4294967295U) > ((unsigned int )llvm_cbe_xlen&4294967295U))) {
    goto llvm_cbe_tmp__128;
  } else {
    llvm_cbe_tmp__126__PHI_TEMPORARY = (unsigned int )4294967293u;   /* for PHI node */
    goto llvm_cbe__2e_loopexit2;
  }

llvm_cbe_tmp__128:
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = sub i32 %%4, %%xlen, !dbg !12 for 0x%I64xth hint within @seedexpander  --> \n", ++aesl_llvm_cbe_448_count);
  llvm_cbe_tmp__93 = (unsigned int )((unsigned int )(llvm_cbe_tmp__92&4294967295ull)) - ((unsigned int )(llvm_cbe_xlen&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__93&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%7, i32* %%3, align 4, !dbg !12 for 0x%I64xth hint within @seedexpander  --> \n", ++aesl_llvm_cbe_449_count);
  *llvm_cbe_tmp__91 = llvm_cbe_tmp__93;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__93);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds %%struct.AES_XOF_struct* %%ctx, i64 0, i32 1, !dbg !12 for 0x%I64xth hint within @seedexpander  --> \n", ++aesl_llvm_cbe_454_count);
  llvm_cbe_tmp__94 = (signed int *)(&llvm_cbe_ctx->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds %%struct.AES_XOF_struct* %%ctx, i64 0, i32 3, i64 0, !dbg !13 for 0x%I64xth hint within @seedexpander  --> \n", ++aesl_llvm_cbe_455_count);
  llvm_cbe_tmp__95 = ( char *)(&llvm_cbe_ctx->field3[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds %%struct.AES_XOF_struct* %%ctx, i64 0, i32 4, i64 0, !dbg !13 for 0x%I64xth hint within @seedexpander  --> \n", ++aesl_llvm_cbe_456_count);
  llvm_cbe_tmp__96 = ( char *)(&llvm_cbe_ctx->field4[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds %%struct.AES_XOF_struct* %%ctx, i64 0, i32 0, i64 0, !dbg !13 for 0x%I64xth hint within @seedexpander  --> \n", ++aesl_llvm_cbe_457_count);
  llvm_cbe_tmp__97 = ( char *)(&llvm_cbe_ctx->field0[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_tmp__98__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  llvm_cbe_tmp__99__PHI_TEMPORARY = (unsigned int )llvm_cbe_xlen;   /* for PHI node */
  goto llvm_cbe_tmp__129;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__129:
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = phi i32 [ %%40, %%.loopexit ], [ 0, %%6  for 0x%I64xth hint within @seedexpander  --> \n", ++aesl_llvm_cbe_459_count);
  llvm_cbe_tmp__98 = (unsigned int )llvm_cbe_tmp__98__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__98);
printf("\n = 0x%X",llvm_cbe_tmp__120);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = phi i32 [ %%38, %%.loopexit ], [ %%xlen, %%6  for 0x%I64xth hint within @seedexpander  --> \n", ++aesl_llvm_cbe_460_count);
  llvm_cbe_tmp__99 = (unsigned int )llvm_cbe_tmp__99__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__99);
printf("\n = 0x%X",llvm_cbe_tmp__118);
printf("\nxlen = 0x%X",llvm_cbe_xlen);
}
  if (((llvm_cbe_tmp__99&4294967295U) == (0u&4294967295U))) {
    llvm_cbe_tmp__126__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_loopexit2;
  } else {
    goto llvm_cbe_tmp__130;
  }

llvm_cbe__2e_loopexit:
  llvm_cbe_tmp__98__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__120;   /* for PHI node */
  llvm_cbe_tmp__99__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__118;   /* for PHI node */
  goto llvm_cbe_tmp__129;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__131:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge = phi i32 [ 15, %%29 ], [ %%49, %%48  for 0x%I64xth hint within @seedexpander  --> \n", ++aesl_llvm_cbe_storemerge_count);
  llvm_cbe_storemerge = (unsigned int )llvm_cbe_storemerge__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge = 0x%X",llvm_cbe_storemerge);
printf("\n = 0x%X",15u);
printf("\n = 0x%X",llvm_cbe_tmp__124);
}
  if ((((signed int )llvm_cbe_storemerge) > ((signed int )11u))) {
    goto llvm_cbe_tmp__132;
  } else {
    goto llvm_cbe__2e_loopexit;
  }

llvm_cbe_tmp__133:
if (AESL_DEBUG_TRACE)
printf("\n  store i8 0, i8* %%45, align 1, !dbg !14 for 0x%I64xth hint within @seedexpander  --> \n", ++aesl_llvm_cbe_516_count);
  *llvm_cbe_tmp__122 = ((unsigned char )0);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )0));
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = add nsw i32 %%storemerge, -1, !dbg !15 for 0x%I64xth hint within @seedexpander  --> \n", ++aesl_llvm_cbe_517_count);
  llvm_cbe_tmp__124 = (unsigned int )((unsigned int )(llvm_cbe_storemerge&4294967295ull)) + ((unsigned int )(4294967295u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__124&4294967295ull)));
  llvm_cbe_storemerge__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__124;   /* for PHI node */
  goto llvm_cbe_tmp__131;

llvm_cbe_tmp__132:
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = sext i32 %%storemerge to i64, !dbg !13 for 0x%I64xth hint within @seedexpander  --> \n", ++aesl_llvm_cbe_511_count);
  llvm_cbe_tmp__121 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__121);
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = getelementptr inbounds %%struct.AES_XOF_struct* %%ctx, i64 0, i32 4, i64 %%44, !dbg !13 for 0x%I64xth hint within @seedexpander  --> \n", ++aesl_llvm_cbe_512_count);
  llvm_cbe_tmp__122 = ( char *)(&llvm_cbe_ctx->field4[(((signed long long )llvm_cbe_tmp__121))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__121));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = load i8* %%45, align 1, !dbg !13 for 0x%I64xth hint within @seedexpander  --> \n", ++aesl_llvm_cbe_513_count);
  llvm_cbe_tmp__123 = (unsigned char )*llvm_cbe_tmp__122;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__123);
  if (((llvm_cbe_tmp__123&255U) == (((unsigned char )-1)&255U))) {
    goto llvm_cbe_tmp__133;
  } else {
    goto llvm_cbe_tmp__134;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__135:
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = zext i32 %%13 to i64, !dbg !13 for 0x%I64xth hint within @seedexpander  --> \n", ++aesl_llvm_cbe_477_count);
  llvm_cbe_tmp__110 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__98&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__110);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = getelementptr inbounds i8* %%x, i64 %%30, !dbg !13 for 0x%I64xth hint within @seedexpander  --> \n", ++aesl_llvm_cbe_478_count);
  llvm_cbe_tmp__111 = ( char *)(&llvm_cbe_x[(((signed long long )llvm_cbe_tmp__110))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__110));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = sext i32 %%17 to i64, !dbg !13 for 0x%I64xth hint within @seedexpander  --> \n", ++aesl_llvm_cbe_479_count);
  llvm_cbe_tmp__112 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__100);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__112);
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = getelementptr inbounds %%struct.AES_XOF_struct* %%ctx, i64 0, i32 0, i64 %%32, !dbg !13 for 0x%I64xth hint within @seedexpander  --> \n", ++aesl_llvm_cbe_480_count);
  llvm_cbe_tmp__113 = ( char *)(&llvm_cbe_ctx->field0[(((signed long long )llvm_cbe_tmp__112))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__112));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = sext i32 %%18 to i64, !dbg !13 for 0x%I64xth hint within @seedexpander  --> \n", ++aesl_llvm_cbe_481_count);
  llvm_cbe_tmp__114 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__101);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__114);
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = call i8* @memcpy(i8* %%31, i8* %%33, i64 %%34 for 0x%I64xth hint within @seedexpander  --> \n", ++aesl_llvm_cbe_482_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__111, ( char *)llvm_cbe_tmp__113, llvm_cbe_tmp__114);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__114);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__115);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = load i32* %%8, align 4, !dbg !13 for 0x%I64xth hint within @seedexpander  --> \n", ++aesl_llvm_cbe_483_count);
  llvm_cbe_tmp__116 = (unsigned int )*llvm_cbe_tmp__94;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__116);
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = add i32 %%14, -16, !dbg !13 for 0x%I64xth hint within @seedexpander  --> \n", ++aesl_llvm_cbe_484_count);
  llvm_cbe_tmp__117 = (unsigned int )((unsigned int )(llvm_cbe_tmp__99&4294967295ull)) + ((unsigned int )(4294967280u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__117&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = add i32 %%37, %%36, !dbg !13 for 0x%I64xth hint within @seedexpander  --> \n", ++aesl_llvm_cbe_485_count);
  llvm_cbe_tmp__118 = (unsigned int )((unsigned int )(llvm_cbe_tmp__117&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__116&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__118&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = add i32 %%13, 16, !dbg !13 for 0x%I64xth hint within @seedexpander  --> \n", ++aesl_llvm_cbe_494_count);
  llvm_cbe_tmp__119 = (unsigned int )((unsigned int )(llvm_cbe_tmp__98&4294967295ull)) + ((unsigned int )(16u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__119&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = sub i32 %%39, %%36, !dbg !13 for 0x%I64xth hint within @seedexpander  --> \n", ++aesl_llvm_cbe_495_count);
  llvm_cbe_tmp__120 = (unsigned int )((unsigned int )(llvm_cbe_tmp__119&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__116&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__120&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  tail call fastcc void @aesl_internal_AES256_ECB(i8* %%9, i8* %%10, i8* %%11), !dbg !13 for 0x%I64xth hint within @seedexpander  --> \n", ++aesl_llvm_cbe_500_count);
   /*tail*/ aesl_internal_AES256_ECB(( char *)llvm_cbe_tmp__95, ( char *)llvm_cbe_tmp__96, ( char *)llvm_cbe_tmp__97);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 0, i32* %%8, align 4, !dbg !13 for 0x%I64xth hint within @seedexpander  --> \n", ++aesl_llvm_cbe_501_count);
  *llvm_cbe_tmp__94 = 0u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 0u);
  llvm_cbe_storemerge__PHI_TEMPORARY = (unsigned int )15u;   /* for PHI node */
  goto llvm_cbe_tmp__131;

llvm_cbe_tmp__130:
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = load i32* %%8, align 4, !dbg !12 for 0x%I64xth hint within @seedexpander  --> \n", ++aesl_llvm_cbe_463_count);
  llvm_cbe_tmp__100 = (unsigned int )*llvm_cbe_tmp__94;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__100);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = sub nsw i32 16, %%17, !dbg !12 for 0x%I64xth hint within @seedexpander  --> \n", ++aesl_llvm_cbe_464_count);
  llvm_cbe_tmp__101 = (unsigned int )((unsigned int )(16u&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__100&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__101&4294967295ull)));
  if ((((unsigned int )llvm_cbe_tmp__99&4294967295U) > ((unsigned int )llvm_cbe_tmp__101&4294967295U))) {
    goto llvm_cbe_tmp__135;
  } else {
    goto llvm_cbe_tmp__136;
  }

llvm_cbe_tmp__134:
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = add i8 %%46, 1, !dbg !14 for 0x%I64xth hint within @seedexpander  --> \n", ++aesl_llvm_cbe_520_count);
  llvm_cbe_tmp__125 = (unsigned char )((unsigned char )(((unsigned char )(llvm_cbe_tmp__123&255ull)) + ((unsigned char )(((unsigned char )1)&255ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )(llvm_cbe_tmp__125&255ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%51, i8* %%45, align 1, !dbg !14 for 0x%I64xth hint within @seedexpander  --> \n", ++aesl_llvm_cbe_521_count);
  *llvm_cbe_tmp__122 = llvm_cbe_tmp__125;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__125);
  goto llvm_cbe__2e_loopexit;

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__136:
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = zext i32 %%13 to i64, !dbg !12 for 0x%I64xth hint within @seedexpander  --> \n", ++aesl_llvm_cbe_467_count);
  llvm_cbe_tmp__102 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__98&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__102);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = getelementptr inbounds i8* %%x, i64 %%21, !dbg !12 for 0x%I64xth hint within @seedexpander  --> \n", ++aesl_llvm_cbe_468_count);
  llvm_cbe_tmp__103 = ( char *)(&llvm_cbe_x[(((signed long long )llvm_cbe_tmp__102))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__102));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = sext i32 %%17 to i64, !dbg !12 for 0x%I64xth hint within @seedexpander  --> \n", ++aesl_llvm_cbe_469_count);
  llvm_cbe_tmp__104 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__100);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__104);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = getelementptr inbounds %%struct.AES_XOF_struct* %%ctx, i64 0, i32 0, i64 %%23, !dbg !12 for 0x%I64xth hint within @seedexpander  --> \n", ++aesl_llvm_cbe_470_count);
  llvm_cbe_tmp__105 = ( char *)(&llvm_cbe_ctx->field0[(((signed long long )llvm_cbe_tmp__104))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__104));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = zext i32 %%14 to i64, !dbg !12 for 0x%I64xth hint within @seedexpander  --> \n", ++aesl_llvm_cbe_471_count);
  llvm_cbe_tmp__106 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__99&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__106);
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = call i8* @memcpy(i8* %%22, i8* %%24, i64 %%25 for 0x%I64xth hint within @seedexpander  --> \n", ++aesl_llvm_cbe_472_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__103, ( char *)llvm_cbe_tmp__105, llvm_cbe_tmp__106);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__106);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__107);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = load i32* %%8, align 4, !dbg !13 for 0x%I64xth hint within @seedexpander  --> \n", ++aesl_llvm_cbe_473_count);
  llvm_cbe_tmp__108 = (unsigned int )*llvm_cbe_tmp__94;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__108);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = add i32 %%27, %%14, !dbg !13 for 0x%I64xth hint within @seedexpander  --> \n", ++aesl_llvm_cbe_474_count);
  llvm_cbe_tmp__109 = (unsigned int )((unsigned int )(llvm_cbe_tmp__108&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__99&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__109&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%28, i32* %%8, align 4, !dbg !13 for 0x%I64xth hint within @seedexpander  --> \n", ++aesl_llvm_cbe_475_count);
  *llvm_cbe_tmp__94 = llvm_cbe_tmp__109;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__109);
  llvm_cbe_tmp__126__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_loopexit2;

llvm_cbe__2e_loopexit2:
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = phi i32 [ 0, %%20 ], [ -2, %%0 ], [ -3, %%2 ], [ 0, %%12  for 0x%I64xth hint within @seedexpander  --> \n", ++aesl_llvm_cbe_524_count);
  llvm_cbe_tmp__126 = (unsigned int )llvm_cbe_tmp__126__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__126);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",4294967294u);
printf("\n = 0x%X",4294967293u);
printf("\n = 0x%X",0u);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @seedexpander}\n");
  return llvm_cbe_tmp__126;
}


static void aesl_internal_AES256_ECB( char *llvm_cbe_key,  char *llvm_cbe_ctr,  char *llvm_cbe_buffer) {
  static  unsigned long long aesl_llvm_cbe_ctx_count = 0;
  l_struct_OC_AES_ctx llvm_cbe_ctx;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_test_count = 0;
   char llvm_cbe_test[4][4];    /* Address-exposed local */
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
  static  unsigned long long aesl_llvm_cbe_541_count = 0;
  static  unsigned long long aesl_llvm_cbe_542_count = 0;
  static  unsigned long long aesl_llvm_cbe_543_count = 0;
  static  unsigned long long aesl_llvm_cbe_544_count = 0;
  static  unsigned long long aesl_llvm_cbe_545_count = 0;
  static  unsigned long long aesl_llvm_cbe_546_count = 0;
  static  unsigned long long aesl_llvm_cbe_547_count = 0;
  static  unsigned long long aesl_llvm_cbe_548_count = 0;
  static  unsigned long long aesl_llvm_cbe_549_count = 0;
  static  unsigned long long aesl_llvm_cbe_550_count = 0;
  static  unsigned long long aesl_llvm_cbe_551_count = 0;
  static  unsigned long long aesl_llvm_cbe_552_count = 0;
  unsigned char llvm_cbe_tmp__137;
  static  unsigned long long aesl_llvm_cbe_553_count = 0;
   char *llvm_cbe_tmp__138;
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
   char *llvm_cbe_tmp__139;
  static  unsigned long long aesl_llvm_cbe_565_count = 0;
  unsigned char llvm_cbe_tmp__140;
  static  unsigned long long aesl_llvm_cbe_566_count = 0;
   char *llvm_cbe_tmp__141;
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
   char *llvm_cbe_tmp__142;
  static  unsigned long long aesl_llvm_cbe_578_count = 0;
  unsigned char llvm_cbe_tmp__143;
  static  unsigned long long aesl_llvm_cbe_579_count = 0;
   char *llvm_cbe_tmp__144;
  static  unsigned long long aesl_llvm_cbe_580_count = 0;
  static  unsigned long long aesl_llvm_cbe_581_count = 0;
  static  unsigned long long aesl_llvm_cbe_582_count = 0;
  static  unsigned long long aesl_llvm_cbe_583_count = 0;
  static  unsigned long long aesl_llvm_cbe_584_count = 0;
  static  unsigned long long aesl_llvm_cbe_585_count = 0;
  static  unsigned long long aesl_llvm_cbe_586_count = 0;
  static  unsigned long long aesl_llvm_cbe_587_count = 0;
  static  unsigned long long aesl_llvm_cbe_588_count = 0;
  static  unsigned long long aesl_llvm_cbe_589_count = 0;
  static  unsigned long long aesl_llvm_cbe_590_count = 0;
   char *llvm_cbe_tmp__145;
  static  unsigned long long aesl_llvm_cbe_591_count = 0;
  unsigned char llvm_cbe_tmp__146;
  static  unsigned long long aesl_llvm_cbe_592_count = 0;
   char *llvm_cbe_tmp__147;
  static  unsigned long long aesl_llvm_cbe_593_count = 0;
  static  unsigned long long aesl_llvm_cbe_594_count = 0;
  static  unsigned long long aesl_llvm_cbe_595_count = 0;
  static  unsigned long long aesl_llvm_cbe_596_count = 0;
  static  unsigned long long aesl_llvm_cbe_597_count = 0;
  static  unsigned long long aesl_llvm_cbe_598_count = 0;
  static  unsigned long long aesl_llvm_cbe_599_count = 0;
  static  unsigned long long aesl_llvm_cbe_600_count = 0;
  static  unsigned long long aesl_llvm_cbe_601_count = 0;
  static  unsigned long long aesl_llvm_cbe_602_count = 0;
  static  unsigned long long aesl_llvm_cbe_603_count = 0;
  static  unsigned long long aesl_llvm_cbe_604_count = 0;
  static  unsigned long long aesl_llvm_cbe_605_count = 0;
  static  unsigned long long aesl_llvm_cbe_606_count = 0;
  static  unsigned long long aesl_llvm_cbe_607_count = 0;
  static  unsigned long long aesl_llvm_cbe_608_count = 0;
  static  unsigned long long aesl_llvm_cbe_609_count = 0;
  static  unsigned long long aesl_llvm_cbe_610_count = 0;
  static  unsigned long long aesl_llvm_cbe_611_count = 0;
  static  unsigned long long aesl_llvm_cbe_612_count = 0;
  static  unsigned long long aesl_llvm_cbe_613_count = 0;
  static  unsigned long long aesl_llvm_cbe_614_count = 0;
  static  unsigned long long aesl_llvm_cbe_615_count = 0;
  static  unsigned long long aesl_llvm_cbe_616_count = 0;
  static  unsigned long long aesl_llvm_cbe_617_count = 0;
  static  unsigned long long aesl_llvm_cbe_618_count = 0;
  static  unsigned long long aesl_llvm_cbe_619_count = 0;
  static  unsigned long long aesl_llvm_cbe_620_count = 0;
   char *llvm_cbe_tmp__148;
  static  unsigned long long aesl_llvm_cbe_621_count = 0;
  unsigned char llvm_cbe_tmp__149;
  static  unsigned long long aesl_llvm_cbe_622_count = 0;
   char *llvm_cbe_tmp__150;
  static  unsigned long long aesl_llvm_cbe_623_count = 0;
  static  unsigned long long aesl_llvm_cbe_624_count = 0;
  static  unsigned long long aesl_llvm_cbe_625_count = 0;
  static  unsigned long long aesl_llvm_cbe_626_count = 0;
  static  unsigned long long aesl_llvm_cbe_627_count = 0;
  static  unsigned long long aesl_llvm_cbe_628_count = 0;
  static  unsigned long long aesl_llvm_cbe_629_count = 0;
  static  unsigned long long aesl_llvm_cbe_630_count = 0;
  static  unsigned long long aesl_llvm_cbe_631_count = 0;
  static  unsigned long long aesl_llvm_cbe_632_count = 0;
  static  unsigned long long aesl_llvm_cbe_633_count = 0;
   char *llvm_cbe_tmp__151;
  static  unsigned long long aesl_llvm_cbe_634_count = 0;
  unsigned char llvm_cbe_tmp__152;
  static  unsigned long long aesl_llvm_cbe_635_count = 0;
   char *llvm_cbe_tmp__153;
  static  unsigned long long aesl_llvm_cbe_636_count = 0;
  static  unsigned long long aesl_llvm_cbe_637_count = 0;
  static  unsigned long long aesl_llvm_cbe_638_count = 0;
  static  unsigned long long aesl_llvm_cbe_639_count = 0;
  static  unsigned long long aesl_llvm_cbe_640_count = 0;
  static  unsigned long long aesl_llvm_cbe_641_count = 0;
  static  unsigned long long aesl_llvm_cbe_642_count = 0;
  static  unsigned long long aesl_llvm_cbe_643_count = 0;
  static  unsigned long long aesl_llvm_cbe_644_count = 0;
  static  unsigned long long aesl_llvm_cbe_645_count = 0;
  static  unsigned long long aesl_llvm_cbe_646_count = 0;
   char *llvm_cbe_tmp__154;
  static  unsigned long long aesl_llvm_cbe_647_count = 0;
  unsigned char llvm_cbe_tmp__155;
  static  unsigned long long aesl_llvm_cbe_648_count = 0;
   char *llvm_cbe_tmp__156;
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
   char *llvm_cbe_tmp__157;
  static  unsigned long long aesl_llvm_cbe_660_count = 0;
  unsigned char llvm_cbe_tmp__158;
  static  unsigned long long aesl_llvm_cbe_661_count = 0;
   char *llvm_cbe_tmp__159;
  static  unsigned long long aesl_llvm_cbe_662_count = 0;
  static  unsigned long long aesl_llvm_cbe_663_count = 0;
  static  unsigned long long aesl_llvm_cbe_664_count = 0;
  static  unsigned long long aesl_llvm_cbe_665_count = 0;
  static  unsigned long long aesl_llvm_cbe_666_count = 0;
  static  unsigned long long aesl_llvm_cbe_667_count = 0;
  static  unsigned long long aesl_llvm_cbe_668_count = 0;
  static  unsigned long long aesl_llvm_cbe_669_count = 0;
  static  unsigned long long aesl_llvm_cbe_670_count = 0;
  static  unsigned long long aesl_llvm_cbe_671_count = 0;
  static  unsigned long long aesl_llvm_cbe_672_count = 0;
  static  unsigned long long aesl_llvm_cbe_673_count = 0;
  static  unsigned long long aesl_llvm_cbe_674_count = 0;
  static  unsigned long long aesl_llvm_cbe_675_count = 0;
  static  unsigned long long aesl_llvm_cbe_676_count = 0;
  static  unsigned long long aesl_llvm_cbe_677_count = 0;
  static  unsigned long long aesl_llvm_cbe_678_count = 0;
  static  unsigned long long aesl_llvm_cbe_679_count = 0;
  static  unsigned long long aesl_llvm_cbe_680_count = 0;
  static  unsigned long long aesl_llvm_cbe_681_count = 0;
  static  unsigned long long aesl_llvm_cbe_682_count = 0;
  static  unsigned long long aesl_llvm_cbe_683_count = 0;
  static  unsigned long long aesl_llvm_cbe_684_count = 0;
  static  unsigned long long aesl_llvm_cbe_685_count = 0;
  static  unsigned long long aesl_llvm_cbe_686_count = 0;
  static  unsigned long long aesl_llvm_cbe_687_count = 0;
  static  unsigned long long aesl_llvm_cbe_688_count = 0;
  static  unsigned long long aesl_llvm_cbe_689_count = 0;
   char *llvm_cbe_tmp__160;
  static  unsigned long long aesl_llvm_cbe_690_count = 0;
  unsigned char llvm_cbe_tmp__161;
  static  unsigned long long aesl_llvm_cbe_691_count = 0;
   char *llvm_cbe_tmp__162;
  static  unsigned long long aesl_llvm_cbe_692_count = 0;
  static  unsigned long long aesl_llvm_cbe_693_count = 0;
  static  unsigned long long aesl_llvm_cbe_694_count = 0;
  static  unsigned long long aesl_llvm_cbe_695_count = 0;
  static  unsigned long long aesl_llvm_cbe_696_count = 0;
  static  unsigned long long aesl_llvm_cbe_697_count = 0;
  static  unsigned long long aesl_llvm_cbe_698_count = 0;
  static  unsigned long long aesl_llvm_cbe_699_count = 0;
  static  unsigned long long aesl_llvm_cbe_700_count = 0;
  static  unsigned long long aesl_llvm_cbe_701_count = 0;
  static  unsigned long long aesl_llvm_cbe_702_count = 0;
   char *llvm_cbe_tmp__163;
  static  unsigned long long aesl_llvm_cbe_703_count = 0;
  unsigned char llvm_cbe_tmp__164;
  static  unsigned long long aesl_llvm_cbe_704_count = 0;
   char *llvm_cbe_tmp__165;
  static  unsigned long long aesl_llvm_cbe_705_count = 0;
  static  unsigned long long aesl_llvm_cbe_706_count = 0;
  static  unsigned long long aesl_llvm_cbe_707_count = 0;
  static  unsigned long long aesl_llvm_cbe_708_count = 0;
  static  unsigned long long aesl_llvm_cbe_709_count = 0;
  static  unsigned long long aesl_llvm_cbe_710_count = 0;
  static  unsigned long long aesl_llvm_cbe_711_count = 0;
  static  unsigned long long aesl_llvm_cbe_712_count = 0;
  static  unsigned long long aesl_llvm_cbe_713_count = 0;
  static  unsigned long long aesl_llvm_cbe_714_count = 0;
  static  unsigned long long aesl_llvm_cbe_715_count = 0;
   char *llvm_cbe_tmp__166;
  static  unsigned long long aesl_llvm_cbe_716_count = 0;
  unsigned char llvm_cbe_tmp__167;
  static  unsigned long long aesl_llvm_cbe_717_count = 0;
   char *llvm_cbe_tmp__168;
  static  unsigned long long aesl_llvm_cbe_718_count = 0;
  static  unsigned long long aesl_llvm_cbe_719_count = 0;
  static  unsigned long long aesl_llvm_cbe_720_count = 0;
  static  unsigned long long aesl_llvm_cbe_721_count = 0;
  static  unsigned long long aesl_llvm_cbe_722_count = 0;
  static  unsigned long long aesl_llvm_cbe_723_count = 0;
  static  unsigned long long aesl_llvm_cbe_724_count = 0;
  static  unsigned long long aesl_llvm_cbe_725_count = 0;
  static  unsigned long long aesl_llvm_cbe_726_count = 0;
  static  unsigned long long aesl_llvm_cbe_727_count = 0;
  static  unsigned long long aesl_llvm_cbe_728_count = 0;
   char *llvm_cbe_tmp__169;
  static  unsigned long long aesl_llvm_cbe_729_count = 0;
  unsigned char llvm_cbe_tmp__170;
  static  unsigned long long aesl_llvm_cbe_730_count = 0;
   char *llvm_cbe_tmp__171;
  static  unsigned long long aesl_llvm_cbe_731_count = 0;
  static  unsigned long long aesl_llvm_cbe_732_count = 0;
  static  unsigned long long aesl_llvm_cbe_733_count = 0;
  static  unsigned long long aesl_llvm_cbe_734_count = 0;
  static  unsigned long long aesl_llvm_cbe_735_count = 0;
  static  unsigned long long aesl_llvm_cbe_736_count = 0;
  static  unsigned long long aesl_llvm_cbe_737_count = 0;
  static  unsigned long long aesl_llvm_cbe_738_count = 0;
  static  unsigned long long aesl_llvm_cbe_739_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_756_count = 0;
  static  unsigned long long aesl_llvm_cbe_757_count = 0;
  static  unsigned long long aesl_llvm_cbe_758_count = 0;
   char *llvm_cbe_tmp__172;
  static  unsigned long long aesl_llvm_cbe_759_count = 0;
  unsigned char llvm_cbe_tmp__173;
  static  unsigned long long aesl_llvm_cbe_760_count = 0;
   char *llvm_cbe_tmp__174;
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
   char *llvm_cbe_tmp__175;
  static  unsigned long long aesl_llvm_cbe_772_count = 0;
  unsigned char llvm_cbe_tmp__176;
  static  unsigned long long aesl_llvm_cbe_773_count = 0;
   char *llvm_cbe_tmp__177;
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
  static  unsigned long long aesl_llvm_cbe_784_count = 0;
   char *llvm_cbe_tmp__178;
  static  unsigned long long aesl_llvm_cbe_785_count = 0;
  unsigned char llvm_cbe_tmp__179;
  static  unsigned long long aesl_llvm_cbe_786_count = 0;
   char *llvm_cbe_tmp__180;
  static  unsigned long long aesl_llvm_cbe_787_count = 0;
  static  unsigned long long aesl_llvm_cbe_788_count = 0;
  static  unsigned long long aesl_llvm_cbe_789_count = 0;
  static  unsigned long long aesl_llvm_cbe_790_count = 0;
  static  unsigned long long aesl_llvm_cbe_791_count = 0;
  static  unsigned long long aesl_llvm_cbe_792_count = 0;
  static  unsigned long long aesl_llvm_cbe_793_count = 0;
  static  unsigned long long aesl_llvm_cbe_794_count = 0;
  static  unsigned long long aesl_llvm_cbe_795_count = 0;
  static  unsigned long long aesl_llvm_cbe_796_count = 0;
  static  unsigned long long aesl_llvm_cbe_797_count = 0;
   char *llvm_cbe_tmp__181;
  static  unsigned long long aesl_llvm_cbe_798_count = 0;
  unsigned char llvm_cbe_tmp__182;
  static  unsigned long long aesl_llvm_cbe_799_count = 0;
   char *llvm_cbe_tmp__183;
  static  unsigned long long aesl_llvm_cbe_800_count = 0;
  static  unsigned long long aesl_llvm_cbe_801_count = 0;
  static  unsigned long long aesl_llvm_cbe_802_count = 0;
  static  unsigned long long aesl_llvm_cbe_803_count = 0;
  static  unsigned long long aesl_llvm_cbe_804_count = 0;
  static  unsigned long long aesl_llvm_cbe_805_count = 0;
  static  unsigned long long aesl_llvm_cbe_806_count = 0;
  static  unsigned long long aesl_llvm_cbe_807_count = 0;
  static  unsigned long long aesl_llvm_cbe_808_count = 0;
  static  unsigned long long aesl_llvm_cbe_809_count = 0;
  static  unsigned long long aesl_llvm_cbe_810_count = 0;
  static  unsigned long long aesl_llvm_cbe_811_count = 0;
  static  unsigned long long aesl_llvm_cbe_812_count = 0;
  static  unsigned long long aesl_llvm_cbe_813_count = 0;
  static  unsigned long long aesl_llvm_cbe_814_count = 0;
  static  unsigned long long aesl_llvm_cbe_815_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_826_count = 0;
  static  unsigned long long aesl_llvm_cbe_827_count = 0;
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
  unsigned char llvm_cbe_tmp__184;
  static  unsigned long long aesl_llvm_cbe_838_count = 0;
  static  unsigned long long aesl_llvm_cbe_839_count = 0;
  static  unsigned long long aesl_llvm_cbe_840_count = 0;
  static  unsigned long long aesl_llvm_cbe_841_count = 0;
  static  unsigned long long aesl_llvm_cbe_842_count = 0;
  static  unsigned long long aesl_llvm_cbe_843_count = 0;
  static  unsigned long long aesl_llvm_cbe_844_count = 0;
  static  unsigned long long aesl_llvm_cbe_845_count = 0;
  static  unsigned long long aesl_llvm_cbe_846_count = 0;
  static  unsigned long long aesl_llvm_cbe_847_count = 0;
  static  unsigned long long aesl_llvm_cbe_848_count = 0;
  unsigned char llvm_cbe_tmp__185;
  static  unsigned long long aesl_llvm_cbe_849_count = 0;
   char *llvm_cbe_tmp__186;
  static  unsigned long long aesl_llvm_cbe_850_count = 0;
  static  unsigned long long aesl_llvm_cbe_851_count = 0;
  static  unsigned long long aesl_llvm_cbe_852_count = 0;
  static  unsigned long long aesl_llvm_cbe_853_count = 0;
  static  unsigned long long aesl_llvm_cbe_854_count = 0;
  static  unsigned long long aesl_llvm_cbe_855_count = 0;
  static  unsigned long long aesl_llvm_cbe_856_count = 0;
  static  unsigned long long aesl_llvm_cbe_857_count = 0;
  static  unsigned long long aesl_llvm_cbe_858_count = 0;
  static  unsigned long long aesl_llvm_cbe_859_count = 0;
  static  unsigned long long aesl_llvm_cbe_860_count = 0;
  unsigned char llvm_cbe_tmp__187;
  static  unsigned long long aesl_llvm_cbe_861_count = 0;
   char *llvm_cbe_tmp__188;
  static  unsigned long long aesl_llvm_cbe_862_count = 0;
  static  unsigned long long aesl_llvm_cbe_863_count = 0;
  static  unsigned long long aesl_llvm_cbe_864_count = 0;
  static  unsigned long long aesl_llvm_cbe_865_count = 0;
  static  unsigned long long aesl_llvm_cbe_866_count = 0;
  static  unsigned long long aesl_llvm_cbe_867_count = 0;
  static  unsigned long long aesl_llvm_cbe_868_count = 0;
  static  unsigned long long aesl_llvm_cbe_869_count = 0;
  static  unsigned long long aesl_llvm_cbe_870_count = 0;
  static  unsigned long long aesl_llvm_cbe_871_count = 0;
  static  unsigned long long aesl_llvm_cbe_872_count = 0;
  unsigned char llvm_cbe_tmp__189;
  static  unsigned long long aesl_llvm_cbe_873_count = 0;
   char *llvm_cbe_tmp__190;
  static  unsigned long long aesl_llvm_cbe_874_count = 0;
  static  unsigned long long aesl_llvm_cbe_875_count = 0;
  static  unsigned long long aesl_llvm_cbe_876_count = 0;
  static  unsigned long long aesl_llvm_cbe_877_count = 0;
  static  unsigned long long aesl_llvm_cbe_878_count = 0;
  static  unsigned long long aesl_llvm_cbe_879_count = 0;
  static  unsigned long long aesl_llvm_cbe_880_count = 0;
  static  unsigned long long aesl_llvm_cbe_881_count = 0;
  static  unsigned long long aesl_llvm_cbe_882_count = 0;
  static  unsigned long long aesl_llvm_cbe_883_count = 0;
  static  unsigned long long aesl_llvm_cbe_884_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_897_count = 0;
  static  unsigned long long aesl_llvm_cbe_898_count = 0;
  static  unsigned long long aesl_llvm_cbe_899_count = 0;
  static  unsigned long long aesl_llvm_cbe_900_count = 0;
  static  unsigned long long aesl_llvm_cbe_901_count = 0;
  unsigned char llvm_cbe_tmp__191;
  static  unsigned long long aesl_llvm_cbe_902_count = 0;
   char *llvm_cbe_tmp__192;
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
  static  unsigned long long aesl_llvm_cbe_913_count = 0;
  unsigned char llvm_cbe_tmp__193;
  static  unsigned long long aesl_llvm_cbe_914_count = 0;
   char *llvm_cbe_tmp__194;
  static  unsigned long long aesl_llvm_cbe_915_count = 0;
  static  unsigned long long aesl_llvm_cbe_916_count = 0;
  static  unsigned long long aesl_llvm_cbe_917_count = 0;
  static  unsigned long long aesl_llvm_cbe_918_count = 0;
  static  unsigned long long aesl_llvm_cbe_919_count = 0;
  static  unsigned long long aesl_llvm_cbe_920_count = 0;
  static  unsigned long long aesl_llvm_cbe_921_count = 0;
  static  unsigned long long aesl_llvm_cbe_922_count = 0;
  static  unsigned long long aesl_llvm_cbe_923_count = 0;
  static  unsigned long long aesl_llvm_cbe_924_count = 0;
  static  unsigned long long aesl_llvm_cbe_925_count = 0;
  unsigned char llvm_cbe_tmp__195;
  static  unsigned long long aesl_llvm_cbe_926_count = 0;
   char *llvm_cbe_tmp__196;
  static  unsigned long long aesl_llvm_cbe_927_count = 0;
  static  unsigned long long aesl_llvm_cbe_928_count = 0;
  static  unsigned long long aesl_llvm_cbe_929_count = 0;
  static  unsigned long long aesl_llvm_cbe_930_count = 0;
  static  unsigned long long aesl_llvm_cbe_931_count = 0;
  static  unsigned long long aesl_llvm_cbe_932_count = 0;
  static  unsigned long long aesl_llvm_cbe_933_count = 0;
  static  unsigned long long aesl_llvm_cbe_934_count = 0;
  static  unsigned long long aesl_llvm_cbe_935_count = 0;
  static  unsigned long long aesl_llvm_cbe_936_count = 0;
  static  unsigned long long aesl_llvm_cbe_937_count = 0;
  unsigned char llvm_cbe_tmp__197;
  static  unsigned long long aesl_llvm_cbe_938_count = 0;
   char *llvm_cbe_tmp__198;
  static  unsigned long long aesl_llvm_cbe_939_count = 0;
  static  unsigned long long aesl_llvm_cbe_940_count = 0;
  static  unsigned long long aesl_llvm_cbe_941_count = 0;
  static  unsigned long long aesl_llvm_cbe_942_count = 0;
  static  unsigned long long aesl_llvm_cbe_943_count = 0;
  static  unsigned long long aesl_llvm_cbe_944_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_955_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_966_count = 0;
  unsigned char llvm_cbe_tmp__199;
  static  unsigned long long aesl_llvm_cbe_967_count = 0;
   char *llvm_cbe_tmp__200;
  static  unsigned long long aesl_llvm_cbe_968_count = 0;
  static  unsigned long long aesl_llvm_cbe_969_count = 0;
  static  unsigned long long aesl_llvm_cbe_970_count = 0;
  static  unsigned long long aesl_llvm_cbe_971_count = 0;
  static  unsigned long long aesl_llvm_cbe_972_count = 0;
  static  unsigned long long aesl_llvm_cbe_973_count = 0;
  static  unsigned long long aesl_llvm_cbe_974_count = 0;
  static  unsigned long long aesl_llvm_cbe_975_count = 0;
  static  unsigned long long aesl_llvm_cbe_976_count = 0;
  static  unsigned long long aesl_llvm_cbe_977_count = 0;
  static  unsigned long long aesl_llvm_cbe_978_count = 0;
  unsigned char llvm_cbe_tmp__201;
  static  unsigned long long aesl_llvm_cbe_979_count = 0;
   char *llvm_cbe_tmp__202;
  static  unsigned long long aesl_llvm_cbe_980_count = 0;
  static  unsigned long long aesl_llvm_cbe_981_count = 0;
  static  unsigned long long aesl_llvm_cbe_982_count = 0;
  static  unsigned long long aesl_llvm_cbe_983_count = 0;
  static  unsigned long long aesl_llvm_cbe_984_count = 0;
  static  unsigned long long aesl_llvm_cbe_985_count = 0;
  static  unsigned long long aesl_llvm_cbe_986_count = 0;
  static  unsigned long long aesl_llvm_cbe_987_count = 0;
  static  unsigned long long aesl_llvm_cbe_988_count = 0;
  static  unsigned long long aesl_llvm_cbe_989_count = 0;
  static  unsigned long long aesl_llvm_cbe_990_count = 0;
  unsigned char llvm_cbe_tmp__203;
  static  unsigned long long aesl_llvm_cbe_991_count = 0;
   char *llvm_cbe_tmp__204;
  static  unsigned long long aesl_llvm_cbe_992_count = 0;
  static  unsigned long long aesl_llvm_cbe_993_count = 0;
  static  unsigned long long aesl_llvm_cbe_994_count = 0;
  static  unsigned long long aesl_llvm_cbe_995_count = 0;
  static  unsigned long long aesl_llvm_cbe_996_count = 0;
  static  unsigned long long aesl_llvm_cbe_997_count = 0;
  static  unsigned long long aesl_llvm_cbe_998_count = 0;
  static  unsigned long long aesl_llvm_cbe_999_count = 0;
  static  unsigned long long aesl_llvm_cbe_1000_count = 0;
  static  unsigned long long aesl_llvm_cbe_1001_count = 0;
  static  unsigned long long aesl_llvm_cbe_1002_count = 0;
  unsigned char llvm_cbe_tmp__205;
  static  unsigned long long aesl_llvm_cbe_1003_count = 0;
   char *llvm_cbe_tmp__206;
  static  unsigned long long aesl_llvm_cbe_1004_count = 0;
  static  unsigned long long aesl_llvm_cbe_1005_count = 0;
  static  unsigned long long aesl_llvm_cbe_1006_count = 0;
  static  unsigned long long aesl_llvm_cbe_1007_count = 0;
  static  unsigned long long aesl_llvm_cbe_1008_count = 0;
  static  unsigned long long aesl_llvm_cbe_1009_count = 0;
  static  unsigned long long aesl_llvm_cbe_1010_count = 0;
  static  unsigned long long aesl_llvm_cbe_1011_count = 0;
  static  unsigned long long aesl_llvm_cbe_1012_count = 0;
  static  unsigned long long aesl_llvm_cbe_1013_count = 0;
  static  unsigned long long aesl_llvm_cbe_1014_count = 0;
  static  unsigned long long aesl_llvm_cbe_1015_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_1028_count = 0;
  static  unsigned long long aesl_llvm_cbe_1029_count = 0;
  static  unsigned long long aesl_llvm_cbe_1030_count = 0;
  static  unsigned long long aesl_llvm_cbe_1031_count = 0;
  unsigned char llvm_cbe_tmp__207;
  static  unsigned long long aesl_llvm_cbe_1032_count = 0;
   char *llvm_cbe_tmp__208;
  static  unsigned long long aesl_llvm_cbe_1033_count = 0;
  static  unsigned long long aesl_llvm_cbe_1034_count = 0;
  static  unsigned long long aesl_llvm_cbe_1035_count = 0;
  static  unsigned long long aesl_llvm_cbe_1036_count = 0;
  static  unsigned long long aesl_llvm_cbe_1037_count = 0;
  static  unsigned long long aesl_llvm_cbe_1038_count = 0;
  static  unsigned long long aesl_llvm_cbe_1039_count = 0;
  static  unsigned long long aesl_llvm_cbe_1040_count = 0;
  static  unsigned long long aesl_llvm_cbe_1041_count = 0;
  static  unsigned long long aesl_llvm_cbe_1042_count = 0;
  static  unsigned long long aesl_llvm_cbe_1043_count = 0;
  unsigned char llvm_cbe_tmp__209;
  static  unsigned long long aesl_llvm_cbe_1044_count = 0;
   char *llvm_cbe_tmp__210;
  static  unsigned long long aesl_llvm_cbe_1045_count = 0;
  static  unsigned long long aesl_llvm_cbe_1046_count = 0;
  static  unsigned long long aesl_llvm_cbe_1047_count = 0;
  static  unsigned long long aesl_llvm_cbe_1048_count = 0;
  static  unsigned long long aesl_llvm_cbe_1049_count = 0;
  static  unsigned long long aesl_llvm_cbe_1050_count = 0;
  static  unsigned long long aesl_llvm_cbe_1051_count = 0;
  static  unsigned long long aesl_llvm_cbe_1052_count = 0;
  static  unsigned long long aesl_llvm_cbe_1053_count = 0;
  static  unsigned long long aesl_llvm_cbe_1054_count = 0;
  static  unsigned long long aesl_llvm_cbe_1055_count = 0;
  unsigned char llvm_cbe_tmp__211;
  static  unsigned long long aesl_llvm_cbe_1056_count = 0;
   char *llvm_cbe_tmp__212;
  static  unsigned long long aesl_llvm_cbe_1057_count = 0;
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
  unsigned char llvm_cbe_tmp__213;
  static  unsigned long long aesl_llvm_cbe_1068_count = 0;
   char *llvm_cbe_tmp__214;
  static  unsigned long long aesl_llvm_cbe_1069_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_1080_count = 0;
  static  unsigned long long aesl_llvm_cbe_1081_count = 0;
  static  unsigned long long aesl_llvm_cbe_1082_count = 0;
  static  unsigned long long aesl_llvm_cbe_1083_count = 0;
  static  unsigned long long aesl_llvm_cbe_1084_count = 0;
  static  unsigned long long aesl_llvm_cbe_1085_count = 0;
  static  unsigned long long aesl_llvm_cbe_1086_count = 0;
  static  unsigned long long aesl_llvm_cbe_1087_count = 0;
  static  unsigned long long aesl_llvm_cbe_1088_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @aesl_internal_AES256_ECB\n");
if (AESL_DEBUG_TRACE)
printf("\n  call void @AES_init_ctx(%%struct.AES_ctx* %%ctx, i8* %%key) nounwind, !dbg !15 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_533_count);
  AES_init_ctx((l_struct_OC_AES_ctx *)(&llvm_cbe_ctx), ( char *)llvm_cbe_key);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%0 = load i8* %%ctr, align 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_552_count);
  llvm_cbe_tmp__137 = (unsigned char )*llvm_cbe_ctr;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__137);
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds [4 x [4 x i8]]* %%test, i64 0, i64 0, i64 0, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_553_count);
  llvm_cbe_tmp__138 = ( char *)(&llvm_cbe_test[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )0ull) < 4 && "Write access out of array 'test' bound?");
  assert(((signed long long )0ull) < 4 && "Write access out of array 'test' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%0, i8* %%1, align 16, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_554_count);
  *llvm_cbe_tmp__138 = llvm_cbe_tmp__137;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__137);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds i8* %%ctr, i64 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_564_count);
  llvm_cbe_tmp__139 = ( char *)(&llvm_cbe_ctr[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = load i8* %%2, align 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_565_count);
  llvm_cbe_tmp__140 = (unsigned char )*llvm_cbe_tmp__139;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__140);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds [4 x [4 x i8]]* %%test, i64 0, i64 0, i64 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_566_count);
  llvm_cbe_tmp__141 = ( char *)(&llvm_cbe_test[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
][(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 4
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )0ull) < 4 && "Write access out of array 'test' bound?");
  assert(((signed long long )1ull) < 4 && "Write access out of array 'test' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%3, i8* %%4, align 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_567_count);
  *llvm_cbe_tmp__141 = llvm_cbe_tmp__140;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__140);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds i8* %%ctr, i64 2, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_577_count);
  llvm_cbe_tmp__142 = ( char *)(&llvm_cbe_ctr[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load i8* %%5, align 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_578_count);
  llvm_cbe_tmp__143 = (unsigned char )*llvm_cbe_tmp__142;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__143);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds [4 x [4 x i8]]* %%test, i64 0, i64 0, i64 2, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_579_count);
  llvm_cbe_tmp__144 = ( char *)(&llvm_cbe_test[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
][(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 4
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )0ull) < 4 && "Write access out of array 'test' bound?");
  assert(((signed long long )2ull) < 4 && "Write access out of array 'test' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%6, i8* %%7, align 2, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_580_count);
  *llvm_cbe_tmp__144 = llvm_cbe_tmp__143;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__143);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds i8* %%ctr, i64 3, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_590_count);
  llvm_cbe_tmp__145 = ( char *)(&llvm_cbe_ctr[(((signed long long )3ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = load i8* %%8, align 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_591_count);
  llvm_cbe_tmp__146 = (unsigned char )*llvm_cbe_tmp__145;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__146);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds [4 x [4 x i8]]* %%test, i64 0, i64 0, i64 3, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_592_count);
  llvm_cbe_tmp__147 = ( char *)(&llvm_cbe_test[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
][(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 4
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )0ull) < 4 && "Write access out of array 'test' bound?");
  assert(((signed long long )3ull) < 4 && "Write access out of array 'test' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%9, i8* %%10, align 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_593_count);
  *llvm_cbe_tmp__147 = llvm_cbe_tmp__146;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__146);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds i8* %%ctr, i64 4, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_620_count);
  llvm_cbe_tmp__148 = ( char *)(&llvm_cbe_ctr[(((signed long long )4ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = load i8* %%11, align 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_621_count);
  llvm_cbe_tmp__149 = (unsigned char )*llvm_cbe_tmp__148;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__149);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds [4 x [4 x i8]]* %%test, i64 0, i64 1, i64 0, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_622_count);
  llvm_cbe_tmp__150 = ( char *)(&llvm_cbe_test[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 4
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )1ull) < 4 && "Write access out of array 'test' bound?");
  assert(((signed long long )0ull) < 4 && "Write access out of array 'test' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%12, i8* %%13, align 4, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_623_count);
  *llvm_cbe_tmp__150 = llvm_cbe_tmp__149;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__149);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds i8* %%ctr, i64 5, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_633_count);
  llvm_cbe_tmp__151 = ( char *)(&llvm_cbe_ctr[(((signed long long )5ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = load i8* %%14, align 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_634_count);
  llvm_cbe_tmp__152 = (unsigned char )*llvm_cbe_tmp__151;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__152);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds [4 x [4 x i8]]* %%test, i64 0, i64 1, i64 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_635_count);
  llvm_cbe_tmp__153 = ( char *)(&llvm_cbe_test[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 4
#endif
][(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 4
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )1ull) < 4 && "Write access out of array 'test' bound?");
  assert(((signed long long )1ull) < 4 && "Write access out of array 'test' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%15, i8* %%16, align 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_636_count);
  *llvm_cbe_tmp__153 = llvm_cbe_tmp__152;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__152);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds i8* %%ctr, i64 6, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_646_count);
  llvm_cbe_tmp__154 = ( char *)(&llvm_cbe_ctr[(((signed long long )6ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = load i8* %%17, align 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_647_count);
  llvm_cbe_tmp__155 = (unsigned char )*llvm_cbe_tmp__154;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__155);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = getelementptr inbounds [4 x [4 x i8]]* %%test, i64 0, i64 1, i64 2, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_648_count);
  llvm_cbe_tmp__156 = ( char *)(&llvm_cbe_test[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 4
#endif
][(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 4
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )1ull) < 4 && "Write access out of array 'test' bound?");
  assert(((signed long long )2ull) < 4 && "Write access out of array 'test' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%18, i8* %%19, align 2, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_649_count);
  *llvm_cbe_tmp__156 = llvm_cbe_tmp__155;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__155);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = getelementptr inbounds i8* %%ctr, i64 7, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_659_count);
  llvm_cbe_tmp__157 = ( char *)(&llvm_cbe_ctr[(((signed long long )7ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = load i8* %%20, align 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_660_count);
  llvm_cbe_tmp__158 = (unsigned char )*llvm_cbe_tmp__157;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__158);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = getelementptr inbounds [4 x [4 x i8]]* %%test, i64 0, i64 1, i64 3, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_661_count);
  llvm_cbe_tmp__159 = ( char *)(&llvm_cbe_test[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 4
#endif
][(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 4
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )1ull) < 4 && "Write access out of array 'test' bound?");
  assert(((signed long long )3ull) < 4 && "Write access out of array 'test' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%21, i8* %%22, align 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_662_count);
  *llvm_cbe_tmp__159 = llvm_cbe_tmp__158;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__158);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = getelementptr inbounds i8* %%ctr, i64 8, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_689_count);
  llvm_cbe_tmp__160 = ( char *)(&llvm_cbe_ctr[(((signed long long )8ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = load i8* %%23, align 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_690_count);
  llvm_cbe_tmp__161 = (unsigned char )*llvm_cbe_tmp__160;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__161);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = getelementptr inbounds [4 x [4 x i8]]* %%test, i64 0, i64 2, i64 0, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_691_count);
  llvm_cbe_tmp__162 = ( char *)(&llvm_cbe_test[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 4
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )2ull) < 4 && "Write access out of array 'test' bound?");
  assert(((signed long long )0ull) < 4 && "Write access out of array 'test' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%24, i8* %%25, align 8, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_692_count);
  *llvm_cbe_tmp__162 = llvm_cbe_tmp__161;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__161);
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = getelementptr inbounds i8* %%ctr, i64 9, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_702_count);
  llvm_cbe_tmp__163 = ( char *)(&llvm_cbe_ctr[(((signed long long )9ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = load i8* %%26, align 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_703_count);
  llvm_cbe_tmp__164 = (unsigned char )*llvm_cbe_tmp__163;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__164);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = getelementptr inbounds [4 x [4 x i8]]* %%test, i64 0, i64 2, i64 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_704_count);
  llvm_cbe_tmp__165 = ( char *)(&llvm_cbe_test[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 4
#endif
][(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 4
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )2ull) < 4 && "Write access out of array 'test' bound?");
  assert(((signed long long )1ull) < 4 && "Write access out of array 'test' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%27, i8* %%28, align 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_705_count);
  *llvm_cbe_tmp__165 = llvm_cbe_tmp__164;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__164);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = getelementptr inbounds i8* %%ctr, i64 10, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_715_count);
  llvm_cbe_tmp__166 = ( char *)(&llvm_cbe_ctr[(((signed long long )10ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = load i8* %%29, align 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_716_count);
  llvm_cbe_tmp__167 = (unsigned char )*llvm_cbe_tmp__166;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__167);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = getelementptr inbounds [4 x [4 x i8]]* %%test, i64 0, i64 2, i64 2, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_717_count);
  llvm_cbe_tmp__168 = ( char *)(&llvm_cbe_test[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 4
#endif
][(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 4
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )2ull) < 4 && "Write access out of array 'test' bound?");
  assert(((signed long long )2ull) < 4 && "Write access out of array 'test' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%30, i8* %%31, align 2, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_718_count);
  *llvm_cbe_tmp__168 = llvm_cbe_tmp__167;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__167);
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = getelementptr inbounds i8* %%ctr, i64 11, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_728_count);
  llvm_cbe_tmp__169 = ( char *)(&llvm_cbe_ctr[(((signed long long )11ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = load i8* %%32, align 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_729_count);
  llvm_cbe_tmp__170 = (unsigned char )*llvm_cbe_tmp__169;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__170);
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = getelementptr inbounds [4 x [4 x i8]]* %%test, i64 0, i64 2, i64 3, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_730_count);
  llvm_cbe_tmp__171 = ( char *)(&llvm_cbe_test[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 4
#endif
][(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 4
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )2ull) < 4 && "Write access out of array 'test' bound?");
  assert(((signed long long )3ull) < 4 && "Write access out of array 'test' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%33, i8* %%34, align 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_731_count);
  *llvm_cbe_tmp__171 = llvm_cbe_tmp__170;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__170);
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = getelementptr inbounds i8* %%ctr, i64 12, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_758_count);
  llvm_cbe_tmp__172 = ( char *)(&llvm_cbe_ctr[(((signed long long )12ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = load i8* %%35, align 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_759_count);
  llvm_cbe_tmp__173 = (unsigned char )*llvm_cbe_tmp__172;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__173);
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = getelementptr inbounds [4 x [4 x i8]]* %%test, i64 0, i64 3, i64 0, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_760_count);
  llvm_cbe_tmp__174 = ( char *)(&llvm_cbe_test[(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 4
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )3ull) < 4 && "Write access out of array 'test' bound?");
  assert(((signed long long )0ull) < 4 && "Write access out of array 'test' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%36, i8* %%37, align 4, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_761_count);
  *llvm_cbe_tmp__174 = llvm_cbe_tmp__173;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__173);
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = getelementptr inbounds i8* %%ctr, i64 13, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_771_count);
  llvm_cbe_tmp__175 = ( char *)(&llvm_cbe_ctr[(((signed long long )13ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = load i8* %%38, align 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_772_count);
  llvm_cbe_tmp__176 = (unsigned char )*llvm_cbe_tmp__175;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__176);
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = getelementptr inbounds [4 x [4 x i8]]* %%test, i64 0, i64 3, i64 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_773_count);
  llvm_cbe_tmp__177 = ( char *)(&llvm_cbe_test[(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 4
#endif
][(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 4
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )3ull) < 4 && "Write access out of array 'test' bound?");
  assert(((signed long long )1ull) < 4 && "Write access out of array 'test' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%39, i8* %%40, align 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_774_count);
  *llvm_cbe_tmp__177 = llvm_cbe_tmp__176;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__176);
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = getelementptr inbounds i8* %%ctr, i64 14, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_784_count);
  llvm_cbe_tmp__178 = ( char *)(&llvm_cbe_ctr[(((signed long long )14ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = load i8* %%41, align 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_785_count);
  llvm_cbe_tmp__179 = (unsigned char )*llvm_cbe_tmp__178;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__179);
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = getelementptr inbounds [4 x [4 x i8]]* %%test, i64 0, i64 3, i64 2, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_786_count);
  llvm_cbe_tmp__180 = ( char *)(&llvm_cbe_test[(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 4
#endif
][(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 4
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )3ull) < 4 && "Write access out of array 'test' bound?");
  assert(((signed long long )2ull) < 4 && "Write access out of array 'test' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%42, i8* %%43, align 2, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_787_count);
  *llvm_cbe_tmp__180 = llvm_cbe_tmp__179;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__179);
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = getelementptr inbounds i8* %%ctr, i64 15, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_797_count);
  llvm_cbe_tmp__181 = ( char *)(&llvm_cbe_ctr[(((signed long long )15ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = load i8* %%44, align 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_798_count);
  llvm_cbe_tmp__182 = (unsigned char )*llvm_cbe_tmp__181;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__182);
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = getelementptr inbounds [4 x [4 x i8]]* %%test, i64 0, i64 3, i64 3, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_799_count);
  llvm_cbe_tmp__183 = ( char *)(&llvm_cbe_test[(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 4
#endif
][(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 4
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )3ull) < 4 && "Write access out of array 'test' bound?");
  assert(((signed long long )3ull) < 4 && "Write access out of array 'test' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%45, i8* %%46, align 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_800_count);
  *llvm_cbe_tmp__183 = llvm_cbe_tmp__182;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__182);
if (AESL_DEBUG_TRACE)
printf("\n  call void @AES_ECB_encrypt(%%struct.AES_ctx* %%ctx, [4 x [4 x i8]]* %%test) nounwind, !dbg !17 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_819_count);
  AES_ECB_encrypt((l_struct_OC_AES_ctx *)(&llvm_cbe_ctx), ( char (*)[4][4])(*(&llvm_cbe_test)));
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )0ull) < 4)) fprintf(stderr, "%s:%d: warning: Read access out of array 'test' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )0ull) < 4)) fprintf(stderr, "%s:%d: warning: Read access out of array 'test' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = load i8* %%1, align 16, !dbg !13 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_837_count);
  llvm_cbe_tmp__184 = (unsigned char )*llvm_cbe_tmp__138;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__184);
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%47, i8* %%buffer, align 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_838_count);
  *llvm_cbe_buffer = llvm_cbe_tmp__184;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__184);

#ifdef AESL_BC_SIM
  if (!(((signed long long )0ull) < 4)) fprintf(stderr, "%s:%d: warning: Read access out of array 'test' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )1ull) < 4)) fprintf(stderr, "%s:%d: warning: Read access out of array 'test' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = load i8* %%4, align 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_848_count);
  llvm_cbe_tmp__185 = (unsigned char )*llvm_cbe_tmp__141;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__185);
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = getelementptr inbounds i8* %%buffer, i64 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_849_count);
  llvm_cbe_tmp__186 = ( char *)(&llvm_cbe_buffer[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%48, i8* %%49, align 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_850_count);
  *llvm_cbe_tmp__186 = llvm_cbe_tmp__185;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__185);

#ifdef AESL_BC_SIM
  if (!(((signed long long )0ull) < 4)) fprintf(stderr, "%s:%d: warning: Read access out of array 'test' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )2ull) < 4)) fprintf(stderr, "%s:%d: warning: Read access out of array 'test' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = load i8* %%7, align 2, !dbg !13 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_860_count);
  llvm_cbe_tmp__187 = (unsigned char )*llvm_cbe_tmp__144;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__187);
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = getelementptr inbounds i8* %%buffer, i64 2, !dbg !13 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_861_count);
  llvm_cbe_tmp__188 = ( char *)(&llvm_cbe_buffer[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%50, i8* %%51, align 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_862_count);
  *llvm_cbe_tmp__188 = llvm_cbe_tmp__187;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__187);

#ifdef AESL_BC_SIM
  if (!(((signed long long )0ull) < 4)) fprintf(stderr, "%s:%d: warning: Read access out of array 'test' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )3ull) < 4)) fprintf(stderr, "%s:%d: warning: Read access out of array 'test' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = load i8* %%10, align 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_872_count);
  llvm_cbe_tmp__189 = (unsigned char )*llvm_cbe_tmp__147;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__189);
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = getelementptr inbounds i8* %%buffer, i64 3, !dbg !13 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_873_count);
  llvm_cbe_tmp__190 = ( char *)(&llvm_cbe_buffer[(((signed long long )3ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%52, i8* %%53, align 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_874_count);
  *llvm_cbe_tmp__190 = llvm_cbe_tmp__189;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__189);

#ifdef AESL_BC_SIM
  if (!(((signed long long )1ull) < 4)) fprintf(stderr, "%s:%d: warning: Read access out of array 'test' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )0ull) < 4)) fprintf(stderr, "%s:%d: warning: Read access out of array 'test' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = load i8* %%13, align 4, !dbg !13 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_901_count);
  llvm_cbe_tmp__191 = (unsigned char )*llvm_cbe_tmp__150;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__191);
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = getelementptr inbounds i8* %%buffer, i64 4, !dbg !13 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_902_count);
  llvm_cbe_tmp__192 = ( char *)(&llvm_cbe_buffer[(((signed long long )4ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%54, i8* %%55, align 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_903_count);
  *llvm_cbe_tmp__192 = llvm_cbe_tmp__191;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__191);

#ifdef AESL_BC_SIM
  if (!(((signed long long )1ull) < 4)) fprintf(stderr, "%s:%d: warning: Read access out of array 'test' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )1ull) < 4)) fprintf(stderr, "%s:%d: warning: Read access out of array 'test' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = load i8* %%16, align 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_913_count);
  llvm_cbe_tmp__193 = (unsigned char )*llvm_cbe_tmp__153;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__193);
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = getelementptr inbounds i8* %%buffer, i64 5, !dbg !13 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_914_count);
  llvm_cbe_tmp__194 = ( char *)(&llvm_cbe_buffer[(((signed long long )5ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%56, i8* %%57, align 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_915_count);
  *llvm_cbe_tmp__194 = llvm_cbe_tmp__193;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__193);

#ifdef AESL_BC_SIM
  if (!(((signed long long )1ull) < 4)) fprintf(stderr, "%s:%d: warning: Read access out of array 'test' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )2ull) < 4)) fprintf(stderr, "%s:%d: warning: Read access out of array 'test' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = load i8* %%19, align 2, !dbg !13 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_925_count);
  llvm_cbe_tmp__195 = (unsigned char )*llvm_cbe_tmp__156;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__195);
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = getelementptr inbounds i8* %%buffer, i64 6, !dbg !13 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_926_count);
  llvm_cbe_tmp__196 = ( char *)(&llvm_cbe_buffer[(((signed long long )6ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%58, i8* %%59, align 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_927_count);
  *llvm_cbe_tmp__196 = llvm_cbe_tmp__195;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__195);

#ifdef AESL_BC_SIM
  if (!(((signed long long )1ull) < 4)) fprintf(stderr, "%s:%d: warning: Read access out of array 'test' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )3ull) < 4)) fprintf(stderr, "%s:%d: warning: Read access out of array 'test' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = load i8* %%22, align 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_937_count);
  llvm_cbe_tmp__197 = (unsigned char )*llvm_cbe_tmp__159;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__197);
if (AESL_DEBUG_TRACE)
printf("\n  %%61 = getelementptr inbounds i8* %%buffer, i64 7, !dbg !13 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_938_count);
  llvm_cbe_tmp__198 = ( char *)(&llvm_cbe_buffer[(((signed long long )7ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%60, i8* %%61, align 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_939_count);
  *llvm_cbe_tmp__198 = llvm_cbe_tmp__197;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__197);

#ifdef AESL_BC_SIM
  if (!(((signed long long )2ull) < 4)) fprintf(stderr, "%s:%d: warning: Read access out of array 'test' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )0ull) < 4)) fprintf(stderr, "%s:%d: warning: Read access out of array 'test' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = load i8* %%25, align 8, !dbg !13 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_966_count);
  llvm_cbe_tmp__199 = (unsigned char )*llvm_cbe_tmp__162;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__199);
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = getelementptr inbounds i8* %%buffer, i64 8, !dbg !13 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_967_count);
  llvm_cbe_tmp__200 = ( char *)(&llvm_cbe_buffer[(((signed long long )8ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%62, i8* %%63, align 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_968_count);
  *llvm_cbe_tmp__200 = llvm_cbe_tmp__199;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__199);

#ifdef AESL_BC_SIM
  if (!(((signed long long )2ull) < 4)) fprintf(stderr, "%s:%d: warning: Read access out of array 'test' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )1ull) < 4)) fprintf(stderr, "%s:%d: warning: Read access out of array 'test' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%64 = load i8* %%28, align 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_978_count);
  llvm_cbe_tmp__201 = (unsigned char )*llvm_cbe_tmp__165;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__201);
if (AESL_DEBUG_TRACE)
printf("\n  %%65 = getelementptr inbounds i8* %%buffer, i64 9, !dbg !13 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_979_count);
  llvm_cbe_tmp__202 = ( char *)(&llvm_cbe_buffer[(((signed long long )9ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%64, i8* %%65, align 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_980_count);
  *llvm_cbe_tmp__202 = llvm_cbe_tmp__201;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__201);

#ifdef AESL_BC_SIM
  if (!(((signed long long )2ull) < 4)) fprintf(stderr, "%s:%d: warning: Read access out of array 'test' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )2ull) < 4)) fprintf(stderr, "%s:%d: warning: Read access out of array 'test' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%66 = load i8* %%31, align 2, !dbg !13 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_990_count);
  llvm_cbe_tmp__203 = (unsigned char )*llvm_cbe_tmp__168;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__203);
if (AESL_DEBUG_TRACE)
printf("\n  %%67 = getelementptr inbounds i8* %%buffer, i64 10, !dbg !13 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_991_count);
  llvm_cbe_tmp__204 = ( char *)(&llvm_cbe_buffer[(((signed long long )10ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%66, i8* %%67, align 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_992_count);
  *llvm_cbe_tmp__204 = llvm_cbe_tmp__203;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__203);

#ifdef AESL_BC_SIM
  if (!(((signed long long )2ull) < 4)) fprintf(stderr, "%s:%d: warning: Read access out of array 'test' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )3ull) < 4)) fprintf(stderr, "%s:%d: warning: Read access out of array 'test' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%68 = load i8* %%34, align 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_1002_count);
  llvm_cbe_tmp__205 = (unsigned char )*llvm_cbe_tmp__171;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__205);
if (AESL_DEBUG_TRACE)
printf("\n  %%69 = getelementptr inbounds i8* %%buffer, i64 11, !dbg !13 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_1003_count);
  llvm_cbe_tmp__206 = ( char *)(&llvm_cbe_buffer[(((signed long long )11ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%68, i8* %%69, align 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_1004_count);
  *llvm_cbe_tmp__206 = llvm_cbe_tmp__205;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__205);

#ifdef AESL_BC_SIM
  if (!(((signed long long )3ull) < 4)) fprintf(stderr, "%s:%d: warning: Read access out of array 'test' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )0ull) < 4)) fprintf(stderr, "%s:%d: warning: Read access out of array 'test' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%70 = load i8* %%37, align 4, !dbg !13 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_1031_count);
  llvm_cbe_tmp__207 = (unsigned char )*llvm_cbe_tmp__174;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__207);
if (AESL_DEBUG_TRACE)
printf("\n  %%71 = getelementptr inbounds i8* %%buffer, i64 12, !dbg !13 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_1032_count);
  llvm_cbe_tmp__208 = ( char *)(&llvm_cbe_buffer[(((signed long long )12ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%70, i8* %%71, align 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_1033_count);
  *llvm_cbe_tmp__208 = llvm_cbe_tmp__207;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__207);

#ifdef AESL_BC_SIM
  if (!(((signed long long )3ull) < 4)) fprintf(stderr, "%s:%d: warning: Read access out of array 'test' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )1ull) < 4)) fprintf(stderr, "%s:%d: warning: Read access out of array 'test' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%72 = load i8* %%40, align 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_1043_count);
  llvm_cbe_tmp__209 = (unsigned char )*llvm_cbe_tmp__177;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__209);
if (AESL_DEBUG_TRACE)
printf("\n  %%73 = getelementptr inbounds i8* %%buffer, i64 13, !dbg !13 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_1044_count);
  llvm_cbe_tmp__210 = ( char *)(&llvm_cbe_buffer[(((signed long long )13ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%72, i8* %%73, align 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_1045_count);
  *llvm_cbe_tmp__210 = llvm_cbe_tmp__209;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__209);

#ifdef AESL_BC_SIM
  if (!(((signed long long )3ull) < 4)) fprintf(stderr, "%s:%d: warning: Read access out of array 'test' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )2ull) < 4)) fprintf(stderr, "%s:%d: warning: Read access out of array 'test' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%74 = load i8* %%43, align 2, !dbg !13 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_1055_count);
  llvm_cbe_tmp__211 = (unsigned char )*llvm_cbe_tmp__180;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__211);
if (AESL_DEBUG_TRACE)
printf("\n  %%75 = getelementptr inbounds i8* %%buffer, i64 14, !dbg !13 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_1056_count);
  llvm_cbe_tmp__212 = ( char *)(&llvm_cbe_buffer[(((signed long long )14ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%74, i8* %%75, align 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_1057_count);
  *llvm_cbe_tmp__212 = llvm_cbe_tmp__211;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__211);

#ifdef AESL_BC_SIM
  if (!(((signed long long )3ull) < 4)) fprintf(stderr, "%s:%d: warning: Read access out of array 'test' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )3ull) < 4)) fprintf(stderr, "%s:%d: warning: Read access out of array 'test' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%76 = load i8* %%46, align 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_1067_count);
  llvm_cbe_tmp__213 = (unsigned char )*llvm_cbe_tmp__183;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__213);
if (AESL_DEBUG_TRACE)
printf("\n  %%77 = getelementptr inbounds i8* %%buffer, i64 15, !dbg !13 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_1068_count);
  llvm_cbe_tmp__214 = ( char *)(&llvm_cbe_buffer[(((signed long long )15ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%76, i8* %%77, align 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_AES256_ECB  --> \n", ++aesl_llvm_cbe_1069_count);
  *llvm_cbe_tmp__214 = llvm_cbe_tmp__213;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__213);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @aesl_internal_AES256_ECB}\n");
  return;
}


void handleErrors(void) {
  static  unsigned long long aesl_llvm_cbe_1089_count = 0;
const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @handleErrors\n");
  if (AESL_DEBUG_TRACE)
      printf("\nEND @handleErrors}\n");
  return;
}


void randombytes_init( char *llvm_cbe_entropy_input,  char *llvm_cbe_personalization_string, signed int llvm_cbe_security_strength) {
  static  unsigned long long aesl_llvm_cbe_seed_material_count = 0;
   char llvm_cbe_seed_material[48];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_1090_count = 0;
  static  unsigned long long aesl_llvm_cbe_1091_count = 0;
  static  unsigned long long aesl_llvm_cbe_1092_count = 0;
  static  unsigned long long aesl_llvm_cbe_1093_count = 0;
  static  unsigned long long aesl_llvm_cbe_1094_count = 0;
  static  unsigned long long aesl_llvm_cbe_1095_count = 0;
  static  unsigned long long aesl_llvm_cbe_1096_count = 0;
   char *llvm_cbe_tmp__215;
  static  unsigned long long aesl_llvm_cbe_1097_count = 0;
  static  unsigned long long aesl_llvm_cbe_1098_count = 0;
   char *llvm_cbe_tmp__216;
  static  unsigned long long aesl_llvm_cbe_1099_count = 0;
  static  unsigned long long aesl_llvm_cbe_1100_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1101_count = 0;
  unsigned long long llvm_cbe_tmp__217;
  static  unsigned long long aesl_llvm_cbe_1102_count = 0;
   char *llvm_cbe_tmp__218;
  static  unsigned long long aesl_llvm_cbe_1103_count = 0;
  unsigned char llvm_cbe_tmp__219;
  static  unsigned long long aesl_llvm_cbe_1104_count = 0;
   char *llvm_cbe_tmp__220;
  static  unsigned long long aesl_llvm_cbe_1105_count = 0;
  unsigned char llvm_cbe_tmp__221;
  static  unsigned long long aesl_llvm_cbe_1106_count = 0;
  unsigned char llvm_cbe_tmp__222;
  static  unsigned long long aesl_llvm_cbe_1107_count = 0;
  static  unsigned long long aesl_llvm_cbe_1108_count = 0;
  unsigned int llvm_cbe_tmp__223;
  static  unsigned long long aesl_llvm_cbe_1109_count = 0;
  static  unsigned long long aesl_llvm_cbe_1110_count = 0;
  static  unsigned long long aesl_llvm_cbe_1111_count = 0;
  static  unsigned long long aesl_llvm_cbe_1112_count = 0;
  static  unsigned long long aesl_llvm_cbe_1113_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_1114_count = 0;
  static  unsigned long long aesl_llvm_cbe_1115_count = 0;
   char *llvm_cbe_tmp__224;
  static  unsigned long long aesl_llvm_cbe_1116_count = 0;
   char *llvm_cbe_tmp__225;
  static  unsigned long long aesl_llvm_cbe_1117_count = 0;
  static  unsigned long long aesl_llvm_cbe_1118_count = 0;
  static  unsigned long long aesl_llvm_cbe_1119_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @randombytes_init\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds [48 x i8]* %%seed_material, i64 0, i64 0, !dbg !13 for 0x%I64xth hint within @randombytes_init  --> \n", ++aesl_llvm_cbe_1096_count);
  llvm_cbe_tmp__215 = ( char *)(&llvm_cbe_seed_material[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 48
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = call i8* @memcpy(i8* %%1, i8* %%entropy_input, i64 48 for 0x%I64xth hint within @randombytes_init  --> \n", ++aesl_llvm_cbe_1098_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__215, ( char *)llvm_cbe_entropy_input, 48ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",48ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__216);
}
  if (((llvm_cbe_personalization_string) == ((( char *)/*NULL*/0)))) {
    goto llvm_cbe__2e_loopexit;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ %%10, %%.preheader ], [ 0, %%0  for 0x%I64xth hint within @randombytes_init  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",llvm_cbe_tmp__223);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = sext i32 %%storemerge1 to i64, !dbg !12 for 0x%I64xth hint within @randombytes_init  --> \n", ++aesl_llvm_cbe_1101_count);
  llvm_cbe_tmp__217 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__217);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds i8* %%personalization_string, i64 %%4, !dbg !12 for 0x%I64xth hint within @randombytes_init  --> \n", ++aesl_llvm_cbe_1102_count);
  llvm_cbe_tmp__218 = ( char *)(&llvm_cbe_personalization_string[(((signed long long )llvm_cbe_tmp__217))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__217));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load i8* %%5, align 1, !dbg !12 for 0x%I64xth hint within @randombytes_init  --> \n", ++aesl_llvm_cbe_1103_count);
  llvm_cbe_tmp__219 = (unsigned char )*llvm_cbe_tmp__218;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__219);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds [48 x i8]* %%seed_material, i64 0, i64 %%4, !dbg !12 for 0x%I64xth hint within @randombytes_init  --> \n", ++aesl_llvm_cbe_1104_count);
  llvm_cbe_tmp__220 = ( char *)(&llvm_cbe_seed_material[(((signed long long )llvm_cbe_tmp__217))
#ifdef AESL_BC_SIM
 % 48
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__217));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__217) < 48)) fprintf(stderr, "%s:%d: warning: Read access out of array 'seed_material' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load i8* %%7, align 1, !dbg !12 for 0x%I64xth hint within @randombytes_init  --> \n", ++aesl_llvm_cbe_1105_count);
  llvm_cbe_tmp__221 = (unsigned char )*llvm_cbe_tmp__220;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__221);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = xor i8 %%8, %%6, !dbg !12 for 0x%I64xth hint within @randombytes_init  --> \n", ++aesl_llvm_cbe_1106_count);
  llvm_cbe_tmp__222 = (unsigned char )((unsigned char )(llvm_cbe_tmp__221 ^ llvm_cbe_tmp__219));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__222);

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__217) < 48 && "Write access out of array 'seed_material' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%9, i8* %%7, align 1, !dbg !12 for 0x%I64xth hint within @randombytes_init  --> \n", ++aesl_llvm_cbe_1107_count);
  *llvm_cbe_tmp__220 = llvm_cbe_tmp__222;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__222);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = add nsw i32 %%storemerge1, 1, !dbg !13 for 0x%I64xth hint within @randombytes_init  --> \n", ++aesl_llvm_cbe_1108_count);
  llvm_cbe_tmp__223 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__223&4294967295ull)));
  if (((llvm_cbe_tmp__223&4294967295U) == (48u&4294967295U))) {
    goto llvm_cbe__2e_loopexit;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__223;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe__2e_loopexit:
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = call i8* @memset(i8* getelementptr inbounds (%%struct.AES256_CTR_DRBG_struct* @DRBG_ctx, i64 0, i32 0, i64 0), i32 0, i64 32 for 0x%I64xth hint within @randombytes_init  --> \n", ++aesl_llvm_cbe_1115_count);
  ( char *)memset(( char *)((&DRBG_ctx.field0[(((signed long long )0ull))])), 0u, 32ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",32ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__224);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = call i8* @memset(i8* getelementptr inbounds (%%struct.AES256_CTR_DRBG_struct* @DRBG_ctx, i64 0, i32 1, i64 0), i32 0, i64 16 for 0x%I64xth hint within @randombytes_init  --> \n", ++aesl_llvm_cbe_1116_count);
  ( char *)memset(( char *)((&DRBG_ctx.field1[(((signed long long )0ull))])), 0u, 16ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",16ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__225);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @AES256_CTR_DRBG_Update(i8* %%1, i8* getelementptr inbounds (%%struct.AES256_CTR_DRBG_struct* @DRBG_ctx, i64 0, i32 0, i64 0), i8* getelementptr inbounds (%%struct.AES256_CTR_DRBG_struct* @DRBG_ctx, i64 0, i32 1, i64 0)), !dbg !14 for 0x%I64xth hint within @randombytes_init  --> \n", ++aesl_llvm_cbe_1117_count);
  AES256_CTR_DRBG_Update(( char *)llvm_cbe_tmp__215, ( char *)((&DRBG_ctx.field0[(((signed long long )0ull))])), ( char *)((&DRBG_ctx.field1[(((signed long long )0ull))])));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 1, i32* getelementptr inbounds (%%struct.AES256_CTR_DRBG_struct* @DRBG_ctx, i64 0, i32 2), align 4, !dbg !14 for 0x%I64xth hint within @randombytes_init  --> \n", ++aesl_llvm_cbe_1118_count);
  *((&DRBG_ctx.field2)) = 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 1u);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @randombytes_init}\n");
  return;
}


void AES256_CTR_DRBG_Update( char *llvm_cbe_provided_data,  char *llvm_cbe_Key,  char *llvm_cbe_V) {
  static  unsigned long long aesl_llvm_cbe_temp_count = 0;
   char llvm_cbe_temp[48];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_1120_count = 0;
  static  unsigned long long aesl_llvm_cbe_1121_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_1134_count = 0;
  static  unsigned long long aesl_llvm_cbe_1135_count = 0;
  static  unsigned long long aesl_llvm_cbe_1136_count = 0;
  static  unsigned long long aesl_llvm_cbe_1137_count = 0;
  static  unsigned long long aesl_llvm_cbe_1138_count = 0;
  static  unsigned long long aesl_llvm_cbe_1139_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_storemerge4_count = 0;
  unsigned int llvm_cbe_storemerge4;
  unsigned int llvm_cbe_storemerge4__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1151_count = 0;
  static  unsigned long long aesl_llvm_cbe_1152_count = 0;
  static  unsigned long long aesl_llvm_cbe_1153_count = 0;
  static  unsigned long long aesl_llvm_cbe_1154_count = 0;
  static  unsigned long long aesl_llvm_cbe_1155_count = 0;
  static  unsigned long long aesl_llvm_cbe_1156_count = 0;
  static  unsigned long long aesl_llvm_cbe_1157_count = 0;
  static  unsigned long long aesl_llvm_cbe_1158_count = 0;
  unsigned long long llvm_cbe_tmp__226;
  static  unsigned long long aesl_llvm_cbe_1159_count = 0;
   char *llvm_cbe_tmp__227;
  static  unsigned long long aesl_llvm_cbe_1160_count = 0;
  unsigned char llvm_cbe_tmp__228;
  static  unsigned long long aesl_llvm_cbe_1161_count = 0;
  static  unsigned long long aesl_llvm_cbe_1162_count = 0;
  static  unsigned long long aesl_llvm_cbe_1163_count = 0;
  static  unsigned long long aesl_llvm_cbe_1164_count = 0;
  unsigned int llvm_cbe_tmp__229;
  static  unsigned long long aesl_llvm_cbe_1165_count = 0;
  static  unsigned long long aesl_llvm_cbe_1166_count = 0;
  static  unsigned long long aesl_llvm_cbe_1167_count = 0;
  unsigned char llvm_cbe_tmp__230;
  static  unsigned long long aesl_llvm_cbe_1168_count = 0;
  static  unsigned long long aesl_llvm_cbe_1169_count = 0;
  static  unsigned long long aesl_llvm_cbe_1170_count = 0;
   char *llvm_cbe_tmp__231;
  static  unsigned long long aesl_llvm_cbe_1171_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_1184_count = 0;
  static  unsigned long long aesl_llvm_cbe_1185_count = 0;
  static  unsigned long long aesl_llvm_cbe_1186_count = 0;
  static  unsigned long long aesl_llvm_cbe_1187_count = 0;
  static  unsigned long long aesl_llvm_cbe_1188_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge38_count = 0;
  unsigned char llvm_cbe_storemerge38;
  unsigned char llvm_cbe_storemerge38__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1189_count = 0;
  unsigned long long llvm_cbe_tmp__232;
  static  unsigned long long aesl_llvm_cbe_1190_count = 0;
   char *llvm_cbe_tmp__233;
  static  unsigned long long aesl_llvm_cbe_1191_count = 0;
  unsigned char llvm_cbe_tmp__234;
  static  unsigned long long aesl_llvm_cbe_1192_count = 0;
   char *llvm_cbe_tmp__235;
  static  unsigned long long aesl_llvm_cbe_1193_count = 0;
  unsigned char llvm_cbe_tmp__236;
  static  unsigned long long aesl_llvm_cbe_1194_count = 0;
  unsigned char llvm_cbe_tmp__237;
  static  unsigned long long aesl_llvm_cbe_1195_count = 0;
  static  unsigned long long aesl_llvm_cbe_1196_count = 0;
  unsigned char llvm_cbe_tmp__238;
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
  static  unsigned long long aesl_llvm_cbe_exitcond14_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_storemerge16_count = 0;
  unsigned char llvm_cbe_storemerge16;
  unsigned char llvm_cbe_storemerge16__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1231_count = 0;
  unsigned long long llvm_cbe_tmp__239;
  static  unsigned long long aesl_llvm_cbe_1232_count = 0;
   char *llvm_cbe_tmp__240;
  static  unsigned long long aesl_llvm_cbe_1233_count = 0;
  unsigned char llvm_cbe_tmp__241;
  static  unsigned long long aesl_llvm_cbe_1234_count = 0;
   char *llvm_cbe_tmp__242;
  static  unsigned long long aesl_llvm_cbe_1235_count = 0;
  static  unsigned long long aesl_llvm_cbe_1236_count = 0;
  unsigned char llvm_cbe_tmp__243;
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
  static  unsigned long long aesl_llvm_cbe_exitcond13_count = 0;
  static  unsigned long long aesl_llvm_cbe_1253_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge25_count = 0;
  unsigned char llvm_cbe_storemerge25;
  unsigned char llvm_cbe_storemerge25__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1254_count = 0;
  unsigned int llvm_cbe_tmp__244;
  static  unsigned long long aesl_llvm_cbe_1255_count = 0;
  unsigned int llvm_cbe_tmp__245;
  static  unsigned long long aesl_llvm_cbe_1256_count = 0;
  unsigned long long llvm_cbe_tmp__246;
  static  unsigned long long aesl_llvm_cbe_1257_count = 0;
   char *llvm_cbe_tmp__247;
  static  unsigned long long aesl_llvm_cbe_1258_count = 0;
  unsigned char llvm_cbe_tmp__248;
  static  unsigned long long aesl_llvm_cbe_1259_count = 0;
  unsigned long long llvm_cbe_tmp__249;
  static  unsigned long long aesl_llvm_cbe_1260_count = 0;
   char *llvm_cbe_tmp__250;
  static  unsigned long long aesl_llvm_cbe_1261_count = 0;
  static  unsigned long long aesl_llvm_cbe_1262_count = 0;
  unsigned char llvm_cbe_tmp__251;
  static  unsigned long long aesl_llvm_cbe_1263_count = 0;
  static  unsigned long long aesl_llvm_cbe_1264_count = 0;
  static  unsigned long long aesl_llvm_cbe_1265_count = 0;
  static  unsigned long long aesl_llvm_cbe_1266_count = 0;
  static  unsigned long long aesl_llvm_cbe_1267_count = 0;
  static  unsigned long long aesl_llvm_cbe_1268_count = 0;
  static  unsigned long long aesl_llvm_cbe_1269_count = 0;
  static  unsigned long long aesl_llvm_cbe_1270_count = 0;
  static  unsigned long long aesl_llvm_cbe_1271_count = 0;
  static  unsigned long long aesl_llvm_cbe_1272_count = 0;
  static  unsigned long long aesl_llvm_cbe_1273_count = 0;
  static  unsigned long long aesl_llvm_cbe_1274_count = 0;
  static  unsigned long long aesl_llvm_cbe_1275_count = 0;
  static  unsigned long long aesl_llvm_cbe_1276_count = 0;
  static  unsigned long long aesl_llvm_cbe_1277_count = 0;
  static  unsigned long long aesl_llvm_cbe_1278_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_1279_count = 0;
  static  unsigned long long aesl_llvm_cbe_1280_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge4_2e_1_count = 0;
  unsigned int llvm_cbe_storemerge4_2e_1;
  unsigned int llvm_cbe_storemerge4_2e_1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1281_count = 0;
  static  unsigned long long aesl_llvm_cbe_1282_count = 0;
  static  unsigned long long aesl_llvm_cbe_1283_count = 0;
  static  unsigned long long aesl_llvm_cbe_1284_count = 0;
  static  unsigned long long aesl_llvm_cbe_1285_count = 0;
  static  unsigned long long aesl_llvm_cbe_1286_count = 0;
  static  unsigned long long aesl_llvm_cbe_1287_count = 0;
  static  unsigned long long aesl_llvm_cbe_1288_count = 0;
  unsigned long long llvm_cbe_tmp__252;
  static  unsigned long long aesl_llvm_cbe_1289_count = 0;
   char *llvm_cbe_tmp__253;
  static  unsigned long long aesl_llvm_cbe_1290_count = 0;
  unsigned char llvm_cbe_tmp__254;
  static  unsigned long long aesl_llvm_cbe_1291_count = 0;
  static  unsigned long long aesl_llvm_cbe_1292_count = 0;
  static  unsigned long long aesl_llvm_cbe_1293_count = 0;
  unsigned char llvm_cbe_tmp__255;
  static  unsigned long long aesl_llvm_cbe_1294_count = 0;
  static  unsigned long long aesl_llvm_cbe_1295_count = 0;
  static  unsigned long long aesl_llvm_cbe_1296_count = 0;
   char *llvm_cbe_tmp__256;
  static  unsigned long long aesl_llvm_cbe_1297_count = 0;
  static  unsigned long long aesl_llvm_cbe_1298_count = 0;
  static  unsigned long long aesl_llvm_cbe_1299_count = 0;
  static  unsigned long long aesl_llvm_cbe_1300_count = 0;
  static  unsigned long long aesl_llvm_cbe_1301_count = 0;
  static  unsigned long long aesl_llvm_cbe_1302_count = 0;
  static  unsigned long long aesl_llvm_cbe_1303_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_1315_count = 0;
  static  unsigned long long aesl_llvm_cbe_1316_count = 0;
  unsigned int llvm_cbe_tmp__257;
  static  unsigned long long aesl_llvm_cbe_1317_count = 0;
  static  unsigned long long aesl_llvm_cbe_1318_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge4_2e_2_count = 0;
  unsigned int llvm_cbe_storemerge4_2e_2;
  unsigned int llvm_cbe_storemerge4_2e_2__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1319_count = 0;
  static  unsigned long long aesl_llvm_cbe_1320_count = 0;
  static  unsigned long long aesl_llvm_cbe_1321_count = 0;
  static  unsigned long long aesl_llvm_cbe_1322_count = 0;
  static  unsigned long long aesl_llvm_cbe_1323_count = 0;
  static  unsigned long long aesl_llvm_cbe_1324_count = 0;
  static  unsigned long long aesl_llvm_cbe_1325_count = 0;
  static  unsigned long long aesl_llvm_cbe_1326_count = 0;
  unsigned long long llvm_cbe_tmp__258;
  static  unsigned long long aesl_llvm_cbe_1327_count = 0;
   char *llvm_cbe_tmp__259;
  static  unsigned long long aesl_llvm_cbe_1328_count = 0;
  unsigned char llvm_cbe_tmp__260;
  static  unsigned long long aesl_llvm_cbe_1329_count = 0;
  static  unsigned long long aesl_llvm_cbe_1330_count = 0;
  static  unsigned long long aesl_llvm_cbe_1331_count = 0;
  unsigned char llvm_cbe_tmp__261;
  static  unsigned long long aesl_llvm_cbe_1332_count = 0;
  static  unsigned long long aesl_llvm_cbe_1333_count = 0;
  static  unsigned long long aesl_llvm_cbe_1334_count = 0;
   char *llvm_cbe_tmp__262;
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
  static  unsigned long long aesl_llvm_cbe_1348_count = 0;
  static  unsigned long long aesl_llvm_cbe_1349_count = 0;
  static  unsigned long long aesl_llvm_cbe_1350_count = 0;
  static  unsigned long long aesl_llvm_cbe_1351_count = 0;
  static  unsigned long long aesl_llvm_cbe_1352_count = 0;
  static  unsigned long long aesl_llvm_cbe_1353_count = 0;
  static  unsigned long long aesl_llvm_cbe_1354_count = 0;
  static  unsigned long long aesl_llvm_cbe_1355_count = 0;
  unsigned int llvm_cbe_tmp__263;
  static  unsigned long long aesl_llvm_cbe_1356_count = 0;
  static  unsigned long long aesl_llvm_cbe_1357_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @AES256_CTR_DRBG_Update\n");
  llvm_cbe_storemerge4__PHI_TEMPORARY = (unsigned int )15u;   /* for PHI node */
  goto llvm_cbe_tmp__264;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__264:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge4 = phi i32 [ %%8, %%7 ], [ 15, %%.preheader9  for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_storemerge4_count);
  llvm_cbe_storemerge4 = (unsigned int )llvm_cbe_storemerge4__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge4 = 0x%X",llvm_cbe_storemerge4);
printf("\n = 0x%X",llvm_cbe_tmp__229);
printf("\n = 0x%X",15u);
}
  if ((((signed int )llvm_cbe_storemerge4) > ((signed int )4294967295u))) {
    goto llvm_cbe_tmp__265;
  } else {
    goto llvm_cbe__2e_preheader9_2e_1;
  }

llvm_cbe_tmp__266:
if (AESL_DEBUG_TRACE)
printf("\n  store i8 0, i8* %%4, align 1, !dbg !14 for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_1163_count);
  *llvm_cbe_tmp__227 = ((unsigned char )0);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )0));
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = add nsw i32 %%storemerge4, -1, !dbg !16 for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_1164_count);
  llvm_cbe_tmp__229 = (unsigned int )((unsigned int )(llvm_cbe_storemerge4&4294967295ull)) + ((unsigned int )(4294967295u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__229&4294967295ull)));
  llvm_cbe_storemerge4__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__229;   /* for PHI node */
  goto llvm_cbe_tmp__264;

llvm_cbe_tmp__265:
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = sext i32 %%storemerge4 to i64, !dbg !13 for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_1158_count);
  llvm_cbe_tmp__226 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge4);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__226);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds i8* %%V, i64 %%3, !dbg !13 for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_1159_count);
  llvm_cbe_tmp__227 = ( char *)(&llvm_cbe_V[(((signed long long )llvm_cbe_tmp__226))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__226));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load i8* %%4, align 1, !dbg !13 for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_1160_count);
  llvm_cbe_tmp__228 = (unsigned char )*llvm_cbe_tmp__227;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__228);
  if (((llvm_cbe_tmp__228&255U) == (((unsigned char )-1)&255U))) {
    goto llvm_cbe_tmp__266;
  } else {
    goto llvm_cbe_tmp__267;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__267:
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = add i8 %%5, 1, !dbg !14 for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_1167_count);
  llvm_cbe_tmp__230 = (unsigned char )((unsigned char )(((unsigned char )(llvm_cbe_tmp__228&255ull)) + ((unsigned char )(((unsigned char )1)&255ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )(llvm_cbe_tmp__230&255ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%10, i8* %%4, align 1, !dbg !14 for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_1168_count);
  *llvm_cbe_tmp__227 = llvm_cbe_tmp__230;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__230);
  goto llvm_cbe__2e_preheader9_2e_1;

llvm_cbe__2e_preheader9_2e_1:
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds [48 x i8]* %%temp, i64 0, i64 0, !dbg !13 for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_1170_count);
  llvm_cbe_tmp__231 = ( char *)(&llvm_cbe_temp[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 48
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call fastcc void @aesl_internal_AES256_ECB(i8* %%Key, i8* %%V, i8* %%11), !dbg !13 for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_1171_count);
  aesl_internal_AES256_ECB(( char *)llvm_cbe_Key, ( char *)llvm_cbe_V, ( char *)llvm_cbe_tmp__231);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge4_2e_1__PHI_TEMPORARY = (unsigned int )15u;   /* for PHI node */
  goto llvm_cbe_tmp__268;

  do {     /* Syntactic loop '.preheader7' to make GCC happy */
llvm_cbe__2e_preheader7:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge38 = phi i8 [ %%18, %%.preheader7 ], [ 0, %%.loopexit10.2  for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_storemerge38_count);
  llvm_cbe_storemerge38 = (unsigned char )llvm_cbe_storemerge38__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge38 = 0x%X",llvm_cbe_storemerge38);
printf("\n = 0x%X",llvm_cbe_tmp__238);
printf("\n = 0x%X",((unsigned char )0));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = zext i8 %%storemerge38 to i64, !dbg !12 for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_1189_count);
  llvm_cbe_tmp__232 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_storemerge38&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__232);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds i8* %%provided_data, i64 %%12, !dbg !12 for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_1190_count);
  llvm_cbe_tmp__233 = ( char *)(&llvm_cbe_provided_data[(((signed long long )llvm_cbe_tmp__232))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__232));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load i8* %%13, align 1, !dbg !12 for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_1191_count);
  llvm_cbe_tmp__234 = (unsigned char )*llvm_cbe_tmp__233;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__234);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds [48 x i8]* %%temp, i64 0, i64 %%12, !dbg !12 for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_1192_count);
  llvm_cbe_tmp__235 = ( char *)(&llvm_cbe_temp[(((signed long long )llvm_cbe_tmp__232))
#ifdef AESL_BC_SIM
 % 48
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__232));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__232) < 48)) fprintf(stderr, "%s:%d: warning: Read access out of array 'temp' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = load i8* %%15, align 1, !dbg !12 for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_1193_count);
  llvm_cbe_tmp__236 = (unsigned char )*llvm_cbe_tmp__235;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__236);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = xor i8 %%16, %%14, !dbg !12 for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_1194_count);
  llvm_cbe_tmp__237 = (unsigned char )((unsigned char )(llvm_cbe_tmp__236 ^ llvm_cbe_tmp__234));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__237);

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__232) < 48 && "Write access out of array 'temp' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%17, i8* %%15, align 1, !dbg !12 for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_1195_count);
  *llvm_cbe_tmp__235 = llvm_cbe_tmp__237;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__237);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = add i8 %%storemerge38, 1, !dbg !15 for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_1196_count);
  llvm_cbe_tmp__238 = (unsigned char )((unsigned char )(((unsigned char )(llvm_cbe_storemerge38&255ull)) + ((unsigned char )(((unsigned char )1)&255ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )(llvm_cbe_tmp__238&255ull)));
  if (((llvm_cbe_tmp__238&255U) == (((unsigned char )48)&255U))) {
    goto llvm_cbe__2e_loopexit;
  } else {
    llvm_cbe_storemerge38__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__238;   /* for PHI node */
    goto llvm_cbe__2e_preheader7;
  }

  } while (1); /* end of syntactic loop '.preheader7' */
llvm_cbe__2e_loopexit:
  llvm_cbe_storemerge16__PHI_TEMPORARY = (unsigned char )((unsigned char )0);   /* for PHI node */
  goto llvm_cbe_tmp__269;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__269:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge16 = phi i8 [ 0, %%.loopexit ], [ %%24, %%19  for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_storemerge16_count);
  llvm_cbe_storemerge16 = (unsigned char )llvm_cbe_storemerge16__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge16 = 0x%X",llvm_cbe_storemerge16);
printf("\n = 0x%X",((unsigned char )0));
printf("\n = 0x%X",llvm_cbe_tmp__243);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = zext i8 %%storemerge16 to i64, !dbg !13 for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_1231_count);
  llvm_cbe_tmp__239 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_storemerge16&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__239);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = getelementptr inbounds [48 x i8]* %%temp, i64 0, i64 %%20, !dbg !13 for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_1232_count);
  llvm_cbe_tmp__240 = ( char *)(&llvm_cbe_temp[(((signed long long )llvm_cbe_tmp__239))
#ifdef AESL_BC_SIM
 % 48
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__239));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__239) < 48)) fprintf(stderr, "%s:%d: warning: Read access out of array 'temp' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = load i8* %%21, align 1, !dbg !13 for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_1233_count);
  llvm_cbe_tmp__241 = (unsigned char )*llvm_cbe_tmp__240;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__241);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = getelementptr inbounds i8* %%Key, i64 %%20, !dbg !13 for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_1234_count);
  llvm_cbe_tmp__242 = ( char *)(&llvm_cbe_Key[(((signed long long )llvm_cbe_tmp__239))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__239));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%22, i8* %%23, align 1, !dbg !13 for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_1235_count);
  *llvm_cbe_tmp__242 = llvm_cbe_tmp__241;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__241);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = add i8 %%storemerge16, 1, !dbg !15 for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_1236_count);
  llvm_cbe_tmp__243 = (unsigned char )((unsigned char )(((unsigned char )(llvm_cbe_storemerge16&255ull)) + ((unsigned char )(((unsigned char )1)&255ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )(llvm_cbe_tmp__243&255ull)));
  if (((llvm_cbe_tmp__243&255U) == (((unsigned char )32)&255U))) {
    llvm_cbe_storemerge25__PHI_TEMPORARY = (unsigned char )((unsigned char )0);   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  } else {
    llvm_cbe_storemerge16__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__243;   /* for PHI node */
    goto llvm_cbe_tmp__269;
  }

  } while (1); /* end of syntactic loop '' */
  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge25 = phi i8 [ %%32, %%.preheader ], [ 0, %%19  for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_storemerge25_count);
  llvm_cbe_storemerge25 = (unsigned char )llvm_cbe_storemerge25__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge25 = 0x%X",llvm_cbe_storemerge25);
printf("\n = 0x%X",llvm_cbe_tmp__251);
printf("\n = 0x%X",((unsigned char )0));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = zext i8 %%storemerge25 to i32, !dbg !14 for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_1254_count);
  llvm_cbe_tmp__244 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_storemerge25&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__244);
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = add nsw i32 %%25, 32, !dbg !14 for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_1255_count);
  llvm_cbe_tmp__245 = (unsigned int )((unsigned int )(llvm_cbe_tmp__244&4294967295ull)) + ((unsigned int )(32u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__245&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = zext i32 %%26 to i64, !dbg !14 for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_1256_count);
  llvm_cbe_tmp__246 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__245&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__246);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = getelementptr inbounds [48 x i8]* %%temp, i64 0, i64 %%27, !dbg !14 for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_1257_count);
  llvm_cbe_tmp__247 = ( char *)(&llvm_cbe_temp[(((signed long long )llvm_cbe_tmp__246))
#ifdef AESL_BC_SIM
 % 48
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__246));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__246) < 48)) fprintf(stderr, "%s:%d: warning: Read access out of array 'temp' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = load i8* %%28, align 1, !dbg !14 for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_1258_count);
  llvm_cbe_tmp__248 = (unsigned char )*llvm_cbe_tmp__247;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__248);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = zext i8 %%storemerge25 to i64, !dbg !14 for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_1259_count);
  llvm_cbe_tmp__249 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_storemerge25&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__249);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = getelementptr inbounds i8* %%V, i64 %%30, !dbg !14 for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_1260_count);
  llvm_cbe_tmp__250 = ( char *)(&llvm_cbe_V[(((signed long long )llvm_cbe_tmp__249))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__249));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%29, i8* %%31, align 1, !dbg !14 for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_1261_count);
  *llvm_cbe_tmp__250 = llvm_cbe_tmp__248;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__248);
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = add i8 %%storemerge25, 1, !dbg !16 for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_1262_count);
  llvm_cbe_tmp__251 = (unsigned char )((unsigned char )(((unsigned char )(llvm_cbe_storemerge25&255ull)) + ((unsigned char )(((unsigned char )1)&255ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )(llvm_cbe_tmp__251&255ull)));
  if (((llvm_cbe_tmp__251&255U) == (((unsigned char )16)&255U))) {
    goto llvm_cbe_tmp__270;
  } else {
    llvm_cbe_storemerge25__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__251;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe_tmp__270:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @AES256_CTR_DRBG_Update}\n");
  return;
  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__268:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge4.1 = phi i32 [ %%45, %%44 ], [ 15, %%.preheader9.1  for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_storemerge4_2e_1_count);
  llvm_cbe_storemerge4_2e_1 = (unsigned int )llvm_cbe_storemerge4_2e_1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge4.1 = 0x%X",llvm_cbe_storemerge4_2e_1);
printf("\n = 0x%X",llvm_cbe_tmp__257);
printf("\n = 0x%X",15u);
}
  if ((((signed int )llvm_cbe_storemerge4_2e_1) > ((signed int )4294967295u))) {
    goto llvm_cbe_tmp__271;
  } else {
    goto llvm_cbe__2e_preheader9_2e_2;
  }

llvm_cbe_tmp__272:
if (AESL_DEBUG_TRACE)
printf("\n  store i8 0, i8* %%38, align 1, !dbg !14 for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_1315_count);
  *llvm_cbe_tmp__253 = ((unsigned char )0);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )0));
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = add nsw i32 %%storemerge4.1, -1, !dbg !16 for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_1316_count);
  llvm_cbe_tmp__257 = (unsigned int )((unsigned int )(llvm_cbe_storemerge4_2e_1&4294967295ull)) + ((unsigned int )(4294967295u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__257&4294967295ull)));
  llvm_cbe_storemerge4_2e_1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__257;   /* for PHI node */
  goto llvm_cbe_tmp__268;

llvm_cbe_tmp__271:
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = sext i32 %%storemerge4.1 to i64, !dbg !13 for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_1288_count);
  llvm_cbe_tmp__252 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge4_2e_1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__252);
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = getelementptr inbounds i8* %%V, i64 %%37, !dbg !13 for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_1289_count);
  llvm_cbe_tmp__253 = ( char *)(&llvm_cbe_V[(((signed long long )llvm_cbe_tmp__252))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__252));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = load i8* %%38, align 1, !dbg !13 for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_1290_count);
  llvm_cbe_tmp__254 = (unsigned char )*llvm_cbe_tmp__253;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__254);
  if (((llvm_cbe_tmp__254&255U) == (((unsigned char )-1)&255U))) {
    goto llvm_cbe_tmp__272;
  } else {
    goto llvm_cbe_tmp__273;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__273:
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = add i8 %%39, 1, !dbg !14 for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_1293_count);
  llvm_cbe_tmp__255 = (unsigned char )((unsigned char )(((unsigned char )(llvm_cbe_tmp__254&255ull)) + ((unsigned char )(((unsigned char )1)&255ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )(llvm_cbe_tmp__255&255ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%42, i8* %%38, align 1, !dbg !14 for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_1294_count);
  *llvm_cbe_tmp__253 = llvm_cbe_tmp__255;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__255);
  goto llvm_cbe__2e_preheader9_2e_2;

llvm_cbe__2e_preheader9_2e_2:
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = getelementptr inbounds [48 x i8]* %%temp, i64 0, i64 16, !dbg !13 for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_1296_count);
  llvm_cbe_tmp__256 = ( char *)(&llvm_cbe_temp[(((signed long long )16ull))
#ifdef AESL_BC_SIM
 % 48
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call fastcc void @aesl_internal_AES256_ECB(i8* %%Key, i8* %%V, i8* %%43), !dbg !13 for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_1297_count);
  aesl_internal_AES256_ECB(( char *)llvm_cbe_Key, ( char *)llvm_cbe_V, ( char *)llvm_cbe_tmp__256);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge4_2e_2__PHI_TEMPORARY = (unsigned int )15u;   /* for PHI node */
  goto llvm_cbe_tmp__274;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__274:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge4.2 = phi i32 [ %%58, %%57 ], [ 15, %%.preheader9.2  for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_storemerge4_2e_2_count);
  llvm_cbe_storemerge4_2e_2 = (unsigned int )llvm_cbe_storemerge4_2e_2__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge4.2 = 0x%X",llvm_cbe_storemerge4_2e_2);
printf("\n = 0x%X",llvm_cbe_tmp__263);
printf("\n = 0x%X",15u);
}
  if ((((signed int )llvm_cbe_storemerge4_2e_2) > ((signed int )4294967295u))) {
    goto llvm_cbe_tmp__275;
  } else {
    goto llvm_cbe__2e_loopexit10_2e_2;
  }

llvm_cbe_tmp__276:
if (AESL_DEBUG_TRACE)
printf("\n  store i8 0, i8* %%50, align 1, !dbg !14 for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_1354_count);
  *llvm_cbe_tmp__259 = ((unsigned char )0);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )0));
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = add nsw i32 %%storemerge4.2, -1, !dbg !16 for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_1355_count);
  llvm_cbe_tmp__263 = (unsigned int )((unsigned int )(llvm_cbe_storemerge4_2e_2&4294967295ull)) + ((unsigned int )(4294967295u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__263&4294967295ull)));
  llvm_cbe_storemerge4_2e_2__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__263;   /* for PHI node */
  goto llvm_cbe_tmp__274;

llvm_cbe_tmp__275:
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = sext i32 %%storemerge4.2 to i64, !dbg !13 for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_1326_count);
  llvm_cbe_tmp__258 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge4_2e_2);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__258);
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = getelementptr inbounds i8* %%V, i64 %%49, !dbg !13 for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_1327_count);
  llvm_cbe_tmp__259 = ( char *)(&llvm_cbe_V[(((signed long long )llvm_cbe_tmp__258))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__258));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = load i8* %%50, align 1, !dbg !13 for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_1328_count);
  llvm_cbe_tmp__260 = (unsigned char )*llvm_cbe_tmp__259;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__260);
  if (((llvm_cbe_tmp__260&255U) == (((unsigned char )-1)&255U))) {
    goto llvm_cbe_tmp__276;
  } else {
    goto llvm_cbe_tmp__277;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__277:
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = add i8 %%51, 1, !dbg !14 for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_1331_count);
  llvm_cbe_tmp__261 = (unsigned char )((unsigned char )(((unsigned char )(llvm_cbe_tmp__260&255ull)) + ((unsigned char )(((unsigned char )1)&255ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )(llvm_cbe_tmp__261&255ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%54, i8* %%50, align 1, !dbg !14 for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_1332_count);
  *llvm_cbe_tmp__259 = llvm_cbe_tmp__261;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__261);
  goto llvm_cbe__2e_loopexit10_2e_2;

llvm_cbe__2e_loopexit10_2e_2:
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = getelementptr inbounds [48 x i8]* %%temp, i64 0, i64 32, !dbg !13 for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_1334_count);
  llvm_cbe_tmp__262 = ( char *)(&llvm_cbe_temp[(((signed long long )32ull))
#ifdef AESL_BC_SIM
 % 48
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call fastcc void @aesl_internal_AES256_ECB(i8* %%Key, i8* %%V, i8* %%55), !dbg !13 for 0x%I64xth hint within @AES256_CTR_DRBG_Update  --> \n", ++aesl_llvm_cbe_1335_count);
  aesl_internal_AES256_ECB(( char *)llvm_cbe_Key, ( char *)llvm_cbe_V, ( char *)llvm_cbe_tmp__262);
if (AESL_DEBUG_TRACE) {
}
  if (((llvm_cbe_provided_data) == ((( char *)/*NULL*/0)))) {
    goto llvm_cbe__2e_loopexit;
  } else {
    llvm_cbe_storemerge38__PHI_TEMPORARY = (unsigned char )((unsigned char )0);   /* for PHI node */
    goto llvm_cbe__2e_preheader7;
  }

}


signed int randombytes( char *llvm_cbe_x, signed long long llvm_cbe_xlen) {
  static  unsigned long long aesl_llvm_cbe_block_count = 0;
   char llvm_cbe_block[16];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_temp_count = 0;
   char llvm_cbe_temp[48];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_1358_count = 0;
  static  unsigned long long aesl_llvm_cbe_1359_count = 0;
  static  unsigned long long aesl_llvm_cbe_1360_count = 0;
  static  unsigned long long aesl_llvm_cbe_1361_count = 0;
  static  unsigned long long aesl_llvm_cbe_1362_count = 0;
  static  unsigned long long aesl_llvm_cbe_1363_count = 0;
  static  unsigned long long aesl_llvm_cbe_1364_count = 0;
  static  unsigned long long aesl_llvm_cbe_1365_count = 0;
  static  unsigned long long aesl_llvm_cbe_1366_count = 0;
  static  unsigned long long aesl_llvm_cbe_1367_count = 0;
  static  unsigned long long aesl_llvm_cbe_1368_count = 0;
  static  unsigned long long aesl_llvm_cbe_1369_count = 0;
  static  unsigned long long aesl_llvm_cbe_1370_count = 0;
  static  unsigned long long aesl_llvm_cbe_1371_count = 0;
  static  unsigned long long aesl_llvm_cbe_1372_count = 0;
  static  unsigned long long aesl_llvm_cbe_1373_count = 0;
  static  unsigned long long aesl_llvm_cbe_1374_count = 0;
  static  unsigned long long aesl_llvm_cbe_1375_count = 0;
  static  unsigned long long aesl_llvm_cbe_1376_count = 0;
  static  unsigned long long aesl_llvm_cbe_1377_count = 0;
  static  unsigned long long aesl_llvm_cbe_1378_count = 0;
  static  unsigned long long aesl_llvm_cbe_1379_count = 0;
  static  unsigned long long aesl_llvm_cbe_1380_count = 0;
  static  unsigned long long aesl_llvm_cbe_1381_count = 0;
  static  unsigned long long aesl_llvm_cbe_1382_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge_count = 0;
  unsigned int llvm_cbe_storemerge;
  unsigned int llvm_cbe_storemerge__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1383_count = 0;
  static  unsigned long long aesl_llvm_cbe_1384_count = 0;
  static  unsigned long long aesl_llvm_cbe_1385_count = 0;
  static  unsigned long long aesl_llvm_cbe_1386_count = 0;
  static  unsigned long long aesl_llvm_cbe_1387_count = 0;
  static  unsigned long long aesl_llvm_cbe_1388_count = 0;
  static  unsigned long long aesl_llvm_cbe_1389_count = 0;
  static  unsigned long long aesl_llvm_cbe_1390_count = 0;
  unsigned long long llvm_cbe_tmp__278;
  static  unsigned long long aesl_llvm_cbe_1391_count = 0;
   char *llvm_cbe_tmp__279;
  static  unsigned long long aesl_llvm_cbe_1392_count = 0;
  unsigned char llvm_cbe_tmp__280;
  static  unsigned long long aesl_llvm_cbe_1393_count = 0;
  static  unsigned long long aesl_llvm_cbe_1394_count = 0;
  static  unsigned long long aesl_llvm_cbe_1395_count = 0;
  static  unsigned long long aesl_llvm_cbe_1396_count = 0;
  unsigned int llvm_cbe_tmp__281;
  static  unsigned long long aesl_llvm_cbe_1397_count = 0;
  static  unsigned long long aesl_llvm_cbe_1398_count = 0;
  static  unsigned long long aesl_llvm_cbe_1399_count = 0;
  unsigned char llvm_cbe_tmp__282;
  static  unsigned long long aesl_llvm_cbe_1400_count = 0;
  static  unsigned long long aesl_llvm_cbe_1401_count = 0;
  static  unsigned long long aesl_llvm_cbe_1402_count = 0;
   char *llvm_cbe_tmp__283;
  static  unsigned long long aesl_llvm_cbe_1403_count = 0;
  static  unsigned long long aesl_llvm_cbe_1404_count = 0;
  static  unsigned long long aesl_llvm_cbe_1405_count = 0;
  static  unsigned long long aesl_llvm_cbe_1406_count = 0;
  static  unsigned long long aesl_llvm_cbe_1407_count = 0;
  static  unsigned long long aesl_llvm_cbe_1408_count = 0;
  static  unsigned long long aesl_llvm_cbe_1409_count = 0;
  unsigned char llvm_cbe_tmp__284;
  static  unsigned long long aesl_llvm_cbe_1410_count = 0;
  static  unsigned long long aesl_llvm_cbe_1411_count = 0;
  static  unsigned long long aesl_llvm_cbe_1412_count = 0;
  static  unsigned long long aesl_llvm_cbe_1413_count = 0;
  static  unsigned long long aesl_llvm_cbe_1414_count = 0;
  static  unsigned long long aesl_llvm_cbe_1415_count = 0;
  static  unsigned long long aesl_llvm_cbe_1416_count = 0;
   char *llvm_cbe_tmp__285;
  static  unsigned long long aesl_llvm_cbe_1417_count = 0;
  unsigned char llvm_cbe_tmp__286;
  static  unsigned long long aesl_llvm_cbe_1418_count = 0;
   char *llvm_cbe_tmp__287;
  static  unsigned long long aesl_llvm_cbe_1419_count = 0;
  static  unsigned long long aesl_llvm_cbe_1420_count = 0;
  static  unsigned long long aesl_llvm_cbe_1421_count = 0;
  static  unsigned long long aesl_llvm_cbe_1422_count = 0;
  static  unsigned long long aesl_llvm_cbe_1423_count = 0;
  static  unsigned long long aesl_llvm_cbe_1424_count = 0;
  static  unsigned long long aesl_llvm_cbe_1425_count = 0;
   char *llvm_cbe_tmp__288;
  static  unsigned long long aesl_llvm_cbe_1426_count = 0;
  unsigned char llvm_cbe_tmp__289;
  static  unsigned long long aesl_llvm_cbe_1427_count = 0;
   char *llvm_cbe_tmp__290;
  static  unsigned long long aesl_llvm_cbe_1428_count = 0;
  static  unsigned long long aesl_llvm_cbe_1429_count = 0;
  static  unsigned long long aesl_llvm_cbe_1430_count = 0;
  static  unsigned long long aesl_llvm_cbe_1431_count = 0;
  static  unsigned long long aesl_llvm_cbe_1432_count = 0;
  static  unsigned long long aesl_llvm_cbe_1433_count = 0;
  static  unsigned long long aesl_llvm_cbe_1434_count = 0;
   char *llvm_cbe_tmp__291;
  static  unsigned long long aesl_llvm_cbe_1435_count = 0;
  unsigned char llvm_cbe_tmp__292;
  static  unsigned long long aesl_llvm_cbe_1436_count = 0;
   char *llvm_cbe_tmp__293;
  static  unsigned long long aesl_llvm_cbe_1437_count = 0;
  static  unsigned long long aesl_llvm_cbe_1438_count = 0;
  static  unsigned long long aesl_llvm_cbe_1439_count = 0;
  static  unsigned long long aesl_llvm_cbe_1440_count = 0;
  static  unsigned long long aesl_llvm_cbe_1441_count = 0;
  static  unsigned long long aesl_llvm_cbe_1442_count = 0;
  static  unsigned long long aesl_llvm_cbe_1443_count = 0;
   char *llvm_cbe_tmp__294;
  static  unsigned long long aesl_llvm_cbe_1444_count = 0;
  unsigned char llvm_cbe_tmp__295;
  static  unsigned long long aesl_llvm_cbe_1445_count = 0;
   char *llvm_cbe_tmp__296;
  static  unsigned long long aesl_llvm_cbe_1446_count = 0;
  static  unsigned long long aesl_llvm_cbe_1447_count = 0;
  static  unsigned long long aesl_llvm_cbe_1448_count = 0;
  static  unsigned long long aesl_llvm_cbe_1449_count = 0;
  static  unsigned long long aesl_llvm_cbe_1450_count = 0;
  static  unsigned long long aesl_llvm_cbe_1451_count = 0;
  static  unsigned long long aesl_llvm_cbe_1452_count = 0;
   char *llvm_cbe_tmp__297;
  static  unsigned long long aesl_llvm_cbe_1453_count = 0;
  unsigned char llvm_cbe_tmp__298;
  static  unsigned long long aesl_llvm_cbe_1454_count = 0;
   char *llvm_cbe_tmp__299;
  static  unsigned long long aesl_llvm_cbe_1455_count = 0;
  static  unsigned long long aesl_llvm_cbe_1456_count = 0;
  static  unsigned long long aesl_llvm_cbe_1457_count = 0;
  static  unsigned long long aesl_llvm_cbe_1458_count = 0;
  static  unsigned long long aesl_llvm_cbe_1459_count = 0;
  static  unsigned long long aesl_llvm_cbe_1460_count = 0;
  static  unsigned long long aesl_llvm_cbe_1461_count = 0;
   char *llvm_cbe_tmp__300;
  static  unsigned long long aesl_llvm_cbe_1462_count = 0;
  unsigned char llvm_cbe_tmp__301;
  static  unsigned long long aesl_llvm_cbe_1463_count = 0;
   char *llvm_cbe_tmp__302;
  static  unsigned long long aesl_llvm_cbe_1464_count = 0;
  static  unsigned long long aesl_llvm_cbe_1465_count = 0;
  static  unsigned long long aesl_llvm_cbe_1466_count = 0;
  static  unsigned long long aesl_llvm_cbe_1467_count = 0;
  static  unsigned long long aesl_llvm_cbe_1468_count = 0;
  static  unsigned long long aesl_llvm_cbe_1469_count = 0;
  static  unsigned long long aesl_llvm_cbe_1470_count = 0;
   char *llvm_cbe_tmp__303;
  static  unsigned long long aesl_llvm_cbe_1471_count = 0;
  unsigned char llvm_cbe_tmp__304;
  static  unsigned long long aesl_llvm_cbe_1472_count = 0;
   char *llvm_cbe_tmp__305;
  static  unsigned long long aesl_llvm_cbe_1473_count = 0;
  static  unsigned long long aesl_llvm_cbe_1474_count = 0;
  static  unsigned long long aesl_llvm_cbe_1475_count = 0;
  static  unsigned long long aesl_llvm_cbe_1476_count = 0;
  static  unsigned long long aesl_llvm_cbe_1477_count = 0;
  static  unsigned long long aesl_llvm_cbe_1478_count = 0;
  static  unsigned long long aesl_llvm_cbe_1479_count = 0;
   char *llvm_cbe_tmp__306;
  static  unsigned long long aesl_llvm_cbe_1480_count = 0;
  unsigned char llvm_cbe_tmp__307;
  static  unsigned long long aesl_llvm_cbe_1481_count = 0;
   char *llvm_cbe_tmp__308;
  static  unsigned long long aesl_llvm_cbe_1482_count = 0;
  static  unsigned long long aesl_llvm_cbe_1483_count = 0;
  static  unsigned long long aesl_llvm_cbe_1484_count = 0;
  static  unsigned long long aesl_llvm_cbe_1485_count = 0;
  static  unsigned long long aesl_llvm_cbe_1486_count = 0;
  static  unsigned long long aesl_llvm_cbe_1487_count = 0;
  static  unsigned long long aesl_llvm_cbe_1488_count = 0;
   char *llvm_cbe_tmp__309;
  static  unsigned long long aesl_llvm_cbe_1489_count = 0;
  unsigned char llvm_cbe_tmp__310;
  static  unsigned long long aesl_llvm_cbe_1490_count = 0;
   char *llvm_cbe_tmp__311;
  static  unsigned long long aesl_llvm_cbe_1491_count = 0;
  static  unsigned long long aesl_llvm_cbe_1492_count = 0;
  static  unsigned long long aesl_llvm_cbe_1493_count = 0;
  static  unsigned long long aesl_llvm_cbe_1494_count = 0;
  static  unsigned long long aesl_llvm_cbe_1495_count = 0;
  static  unsigned long long aesl_llvm_cbe_1496_count = 0;
  static  unsigned long long aesl_llvm_cbe_1497_count = 0;
   char *llvm_cbe_tmp__312;
  static  unsigned long long aesl_llvm_cbe_1498_count = 0;
  unsigned char llvm_cbe_tmp__313;
  static  unsigned long long aesl_llvm_cbe_1499_count = 0;
   char *llvm_cbe_tmp__314;
  static  unsigned long long aesl_llvm_cbe_1500_count = 0;
  static  unsigned long long aesl_llvm_cbe_1501_count = 0;
  static  unsigned long long aesl_llvm_cbe_1502_count = 0;
  static  unsigned long long aesl_llvm_cbe_1503_count = 0;
  static  unsigned long long aesl_llvm_cbe_1504_count = 0;
  static  unsigned long long aesl_llvm_cbe_1505_count = 0;
  static  unsigned long long aesl_llvm_cbe_1506_count = 0;
   char *llvm_cbe_tmp__315;
  static  unsigned long long aesl_llvm_cbe_1507_count = 0;
  unsigned char llvm_cbe_tmp__316;
  static  unsigned long long aesl_llvm_cbe_1508_count = 0;
   char *llvm_cbe_tmp__317;
  static  unsigned long long aesl_llvm_cbe_1509_count = 0;
  static  unsigned long long aesl_llvm_cbe_1510_count = 0;
  static  unsigned long long aesl_llvm_cbe_1511_count = 0;
  static  unsigned long long aesl_llvm_cbe_1512_count = 0;
  static  unsigned long long aesl_llvm_cbe_1513_count = 0;
  static  unsigned long long aesl_llvm_cbe_1514_count = 0;
  static  unsigned long long aesl_llvm_cbe_1515_count = 0;
   char *llvm_cbe_tmp__318;
  static  unsigned long long aesl_llvm_cbe_1516_count = 0;
  unsigned char llvm_cbe_tmp__319;
  static  unsigned long long aesl_llvm_cbe_1517_count = 0;
   char *llvm_cbe_tmp__320;
  static  unsigned long long aesl_llvm_cbe_1518_count = 0;
  static  unsigned long long aesl_llvm_cbe_1519_count = 0;
  static  unsigned long long aesl_llvm_cbe_1520_count = 0;
  static  unsigned long long aesl_llvm_cbe_1521_count = 0;
  static  unsigned long long aesl_llvm_cbe_1522_count = 0;
  static  unsigned long long aesl_llvm_cbe_1523_count = 0;
  static  unsigned long long aesl_llvm_cbe_1524_count = 0;
   char *llvm_cbe_tmp__321;
  static  unsigned long long aesl_llvm_cbe_1525_count = 0;
  unsigned char llvm_cbe_tmp__322;
  static  unsigned long long aesl_llvm_cbe_1526_count = 0;
   char *llvm_cbe_tmp__323;
  static  unsigned long long aesl_llvm_cbe_1527_count = 0;
  static  unsigned long long aesl_llvm_cbe_1528_count = 0;
  static  unsigned long long aesl_llvm_cbe_1529_count = 0;
  static  unsigned long long aesl_llvm_cbe_1530_count = 0;
  static  unsigned long long aesl_llvm_cbe_1531_count = 0;
  static  unsigned long long aesl_llvm_cbe_1532_count = 0;
  static  unsigned long long aesl_llvm_cbe_1533_count = 0;
   char *llvm_cbe_tmp__324;
  static  unsigned long long aesl_llvm_cbe_1534_count = 0;
  unsigned char llvm_cbe_tmp__325;
  static  unsigned long long aesl_llvm_cbe_1535_count = 0;
   char *llvm_cbe_tmp__326;
  static  unsigned long long aesl_llvm_cbe_1536_count = 0;
  static  unsigned long long aesl_llvm_cbe_1537_count = 0;
  static  unsigned long long aesl_llvm_cbe_1538_count = 0;
  static  unsigned long long aesl_llvm_cbe_1539_count = 0;
  static  unsigned long long aesl_llvm_cbe_1540_count = 0;
  static  unsigned long long aesl_llvm_cbe_1541_count = 0;
  static  unsigned long long aesl_llvm_cbe_1542_count = 0;
   char *llvm_cbe_tmp__327;
  static  unsigned long long aesl_llvm_cbe_1543_count = 0;
  unsigned char llvm_cbe_tmp__328;
  static  unsigned long long aesl_llvm_cbe_1544_count = 0;
   char *llvm_cbe_tmp__329;
  static  unsigned long long aesl_llvm_cbe_1545_count = 0;
  static  unsigned long long aesl_llvm_cbe_1546_count = 0;
  static  unsigned long long aesl_llvm_cbe_1547_count = 0;
  static  unsigned long long aesl_llvm_cbe_1548_count = 0;
  static  unsigned long long aesl_llvm_cbe_1549_count = 0;
  static  unsigned long long aesl_llvm_cbe_1550_count = 0;
  static  unsigned long long aesl_llvm_cbe_1551_count = 0;
  static  unsigned long long aesl_llvm_cbe_1552_count = 0;
  static  unsigned long long aesl_llvm_cbe_1553_count = 0;
  static  unsigned long long aesl_llvm_cbe_1554_count = 0;
  static  unsigned long long aesl_llvm_cbe_1555_count = 0;
  static  unsigned long long aesl_llvm_cbe_1556_count = 0;
  static  unsigned long long aesl_llvm_cbe_1557_count = 0;
  static  unsigned long long aesl_llvm_cbe_1558_count = 0;
  static  unsigned long long aesl_llvm_cbe_1559_count = 0;
  static  unsigned long long aesl_llvm_cbe_1560_count = 0;
  static  unsigned long long aesl_llvm_cbe_1561_count = 0;
  static  unsigned long long aesl_llvm_cbe_1562_count = 0;
  static  unsigned long long aesl_llvm_cbe_1563_count = 0;
  static  unsigned long long aesl_llvm_cbe_1564_count = 0;
  static  unsigned long long aesl_llvm_cbe_1565_count = 0;
  static  unsigned long long aesl_llvm_cbe_1566_count = 0;
  static  unsigned long long aesl_llvm_cbe_1567_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge6_count = 0;
  unsigned int llvm_cbe_storemerge6;
  unsigned int llvm_cbe_storemerge6__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1568_count = 0;
  static  unsigned long long aesl_llvm_cbe_1569_count = 0;
  static  unsigned long long aesl_llvm_cbe_1570_count = 0;
  static  unsigned long long aesl_llvm_cbe_1571_count = 0;
  static  unsigned long long aesl_llvm_cbe_1572_count = 0;
  static  unsigned long long aesl_llvm_cbe_1573_count = 0;
  static  unsigned long long aesl_llvm_cbe_1574_count = 0;
  static  unsigned long long aesl_llvm_cbe_1575_count = 0;
  unsigned long long llvm_cbe_tmp__330;
  static  unsigned long long aesl_llvm_cbe_1576_count = 0;
   char *llvm_cbe_tmp__331;
  static  unsigned long long aesl_llvm_cbe_1577_count = 0;
  unsigned char llvm_cbe_tmp__332;
  static  unsigned long long aesl_llvm_cbe_1578_count = 0;
  static  unsigned long long aesl_llvm_cbe_1579_count = 0;
  static  unsigned long long aesl_llvm_cbe_1580_count = 0;
  static  unsigned long long aesl_llvm_cbe_1581_count = 0;
  unsigned int llvm_cbe_tmp__333;
  static  unsigned long long aesl_llvm_cbe_1582_count = 0;
  static  unsigned long long aesl_llvm_cbe_1583_count = 0;
  static  unsigned long long aesl_llvm_cbe_1584_count = 0;
  unsigned char llvm_cbe_tmp__334;
  static  unsigned long long aesl_llvm_cbe_1585_count = 0;
  static  unsigned long long aesl_llvm_cbe_1586_count = 0;
  static  unsigned long long aesl_llvm_cbe_1587_count = 0;
   char *llvm_cbe_tmp__335;
  static  unsigned long long aesl_llvm_cbe_1588_count = 0;
  static  unsigned long long aesl_llvm_cbe_1589_count = 0;
  static  unsigned long long aesl_llvm_cbe_1590_count = 0;
  static  unsigned long long aesl_llvm_cbe_1591_count = 0;
  static  unsigned long long aesl_llvm_cbe_1592_count = 0;
  static  unsigned long long aesl_llvm_cbe_1593_count = 0;
  static  unsigned long long aesl_llvm_cbe_1594_count = 0;
  static  unsigned long long aesl_llvm_cbe_1595_count = 0;
  static  unsigned long long aesl_llvm_cbe_1596_count = 0;
  static  unsigned long long aesl_llvm_cbe_1597_count = 0;
  static  unsigned long long aesl_llvm_cbe_1598_count = 0;
  static  unsigned long long aesl_llvm_cbe_1599_count = 0;
  static  unsigned long long aesl_llvm_cbe_1600_count = 0;
  static  unsigned long long aesl_llvm_cbe_1601_count = 0;
  static  unsigned long long aesl_llvm_cbe_1602_count = 0;
  static  unsigned long long aesl_llvm_cbe_1603_count = 0;
  static  unsigned long long aesl_llvm_cbe_1604_count = 0;
  static  unsigned long long aesl_llvm_cbe_1605_count = 0;
  static  unsigned long long aesl_llvm_cbe_1606_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge39_count = 0;
  unsigned int llvm_cbe_storemerge39;
  unsigned int llvm_cbe_storemerge39__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1607_count = 0;
  unsigned long long llvm_cbe_tmp__336;
  static  unsigned long long aesl_llvm_cbe_1608_count = 0;
   char *llvm_cbe_tmp__337;
  static  unsigned long long aesl_llvm_cbe_1609_count = 0;
  unsigned char llvm_cbe_tmp__338;
  static  unsigned long long aesl_llvm_cbe_1610_count = 0;
   char *llvm_cbe_tmp__339;
  static  unsigned long long aesl_llvm_cbe_1611_count = 0;
  static  unsigned long long aesl_llvm_cbe_1612_count = 0;
  unsigned int llvm_cbe_tmp__340;
  static  unsigned long long aesl_llvm_cbe_1613_count = 0;
  static  unsigned long long aesl_llvm_cbe_1614_count = 0;
  static  unsigned long long aesl_llvm_cbe_1615_count = 0;
  static  unsigned long long aesl_llvm_cbe_1616_count = 0;
  static  unsigned long long aesl_llvm_cbe_1617_count = 0;
  static  unsigned long long aesl_llvm_cbe_1618_count = 0;
  static  unsigned long long aesl_llvm_cbe_1619_count = 0;
  static  unsigned long long aesl_llvm_cbe_1620_count = 0;
  static  unsigned long long aesl_llvm_cbe_1621_count = 0;
  static  unsigned long long aesl_llvm_cbe_1622_count = 0;
  static  unsigned long long aesl_llvm_cbe_1623_count = 0;
  static  unsigned long long aesl_llvm_cbe_1624_count = 0;
  static  unsigned long long aesl_llvm_cbe_1625_count = 0;
  static  unsigned long long aesl_llvm_cbe_1626_count = 0;
  static  unsigned long long aesl_llvm_cbe_1627_count = 0;
  static  unsigned long long aesl_llvm_cbe_1628_count = 0;
  static  unsigned long long aesl_llvm_cbe_1629_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond18_count = 0;
  static  unsigned long long aesl_llvm_cbe_1630_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge47_count = 0;
  unsigned int llvm_cbe_storemerge47;
  unsigned int llvm_cbe_storemerge47__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1631_count = 0;
  unsigned int llvm_cbe_tmp__341;
  static  unsigned long long aesl_llvm_cbe_1632_count = 0;
  unsigned long long llvm_cbe_tmp__342;
  static  unsigned long long aesl_llvm_cbe_1633_count = 0;
   char *llvm_cbe_tmp__343;
  static  unsigned long long aesl_llvm_cbe_1634_count = 0;
  unsigned char llvm_cbe_tmp__344;
  static  unsigned long long aesl_llvm_cbe_1635_count = 0;
  unsigned long long llvm_cbe_tmp__345;
  static  unsigned long long aesl_llvm_cbe_1636_count = 0;
   char *llvm_cbe_tmp__346;
  static  unsigned long long aesl_llvm_cbe_1637_count = 0;
  static  unsigned long long aesl_llvm_cbe_1638_count = 0;
  unsigned int llvm_cbe_tmp__347;
  static  unsigned long long aesl_llvm_cbe_1639_count = 0;
  static  unsigned long long aesl_llvm_cbe_1640_count = 0;
  static  unsigned long long aesl_llvm_cbe_1641_count = 0;
  static  unsigned long long aesl_llvm_cbe_1642_count = 0;
  static  unsigned long long aesl_llvm_cbe_1643_count = 0;
  static  unsigned long long aesl_llvm_cbe_1644_count = 0;
  static  unsigned long long aesl_llvm_cbe_1645_count = 0;
  static  unsigned long long aesl_llvm_cbe_1646_count = 0;
  static  unsigned long long aesl_llvm_cbe_1647_count = 0;
  static  unsigned long long aesl_llvm_cbe_1648_count = 0;
  static  unsigned long long aesl_llvm_cbe_1649_count = 0;
  static  unsigned long long aesl_llvm_cbe_1650_count = 0;
  static  unsigned long long aesl_llvm_cbe_1651_count = 0;
  static  unsigned long long aesl_llvm_cbe_1652_count = 0;
  static  unsigned long long aesl_llvm_cbe_1653_count = 0;
  static  unsigned long long aesl_llvm_cbe_1654_count = 0;
  static  unsigned long long aesl_llvm_cbe_1655_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_1656_count = 0;
  static  unsigned long long aesl_llvm_cbe_1657_count = 0;
  unsigned int llvm_cbe_tmp__348;
  static  unsigned long long aesl_llvm_cbe_1658_count = 0;
  unsigned int llvm_cbe_tmp__349;
  static  unsigned long long aesl_llvm_cbe_1659_count = 0;
  static  unsigned long long aesl_llvm_cbe_1660_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge6_2e_1_count = 0;
  unsigned int llvm_cbe_storemerge6_2e_1;
  unsigned int llvm_cbe_storemerge6_2e_1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1661_count = 0;
  static  unsigned long long aesl_llvm_cbe_1662_count = 0;
  static  unsigned long long aesl_llvm_cbe_1663_count = 0;
  static  unsigned long long aesl_llvm_cbe_1664_count = 0;
  static  unsigned long long aesl_llvm_cbe_1665_count = 0;
  static  unsigned long long aesl_llvm_cbe_1666_count = 0;
  static  unsigned long long aesl_llvm_cbe_1667_count = 0;
  static  unsigned long long aesl_llvm_cbe_1668_count = 0;
  unsigned long long llvm_cbe_tmp__350;
  static  unsigned long long aesl_llvm_cbe_1669_count = 0;
   char *llvm_cbe_tmp__351;
  static  unsigned long long aesl_llvm_cbe_1670_count = 0;
  unsigned char llvm_cbe_tmp__352;
  static  unsigned long long aesl_llvm_cbe_1671_count = 0;
  static  unsigned long long aesl_llvm_cbe_1672_count = 0;
  static  unsigned long long aesl_llvm_cbe_1673_count = 0;
  unsigned char llvm_cbe_tmp__353;
  static  unsigned long long aesl_llvm_cbe_1674_count = 0;
  static  unsigned long long aesl_llvm_cbe_1675_count = 0;
  static  unsigned long long aesl_llvm_cbe_1676_count = 0;
   char *llvm_cbe_tmp__354;
  static  unsigned long long aesl_llvm_cbe_1677_count = 0;
  static  unsigned long long aesl_llvm_cbe_1678_count = 0;
  static  unsigned long long aesl_llvm_cbe_1679_count = 0;
  static  unsigned long long aesl_llvm_cbe_1680_count = 0;
  static  unsigned long long aesl_llvm_cbe_1681_count = 0;
  static  unsigned long long aesl_llvm_cbe_1682_count = 0;
  static  unsigned long long aesl_llvm_cbe_1683_count = 0;
  static  unsigned long long aesl_llvm_cbe_1684_count = 0;
  static  unsigned long long aesl_llvm_cbe_1685_count = 0;
  static  unsigned long long aesl_llvm_cbe_1686_count = 0;
  static  unsigned long long aesl_llvm_cbe_1687_count = 0;
  static  unsigned long long aesl_llvm_cbe_1688_count = 0;
  static  unsigned long long aesl_llvm_cbe_1689_count = 0;
  static  unsigned long long aesl_llvm_cbe_1690_count = 0;
  static  unsigned long long aesl_llvm_cbe_1691_count = 0;
  static  unsigned long long aesl_llvm_cbe_1692_count = 0;
  static  unsigned long long aesl_llvm_cbe_1693_count = 0;
  static  unsigned long long aesl_llvm_cbe_1694_count = 0;
  static  unsigned long long aesl_llvm_cbe_1695_count = 0;
  static  unsigned long long aesl_llvm_cbe_1696_count = 0;
  static  unsigned long long aesl_llvm_cbe_1697_count = 0;
  unsigned int llvm_cbe_tmp__355;
  static  unsigned long long aesl_llvm_cbe_1698_count = 0;
  static  unsigned long long aesl_llvm_cbe_1699_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge6_2e_2_count = 0;
  unsigned int llvm_cbe_storemerge6_2e_2;
  unsigned int llvm_cbe_storemerge6_2e_2__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1700_count = 0;
  static  unsigned long long aesl_llvm_cbe_1701_count = 0;
  static  unsigned long long aesl_llvm_cbe_1702_count = 0;
  static  unsigned long long aesl_llvm_cbe_1703_count = 0;
  static  unsigned long long aesl_llvm_cbe_1704_count = 0;
  static  unsigned long long aesl_llvm_cbe_1705_count = 0;
  static  unsigned long long aesl_llvm_cbe_1706_count = 0;
  static  unsigned long long aesl_llvm_cbe_1707_count = 0;
  unsigned long long llvm_cbe_tmp__356;
  static  unsigned long long aesl_llvm_cbe_1708_count = 0;
   char *llvm_cbe_tmp__357;
  static  unsigned long long aesl_llvm_cbe_1709_count = 0;
  unsigned char llvm_cbe_tmp__358;
  static  unsigned long long aesl_llvm_cbe_1710_count = 0;
  static  unsigned long long aesl_llvm_cbe_1711_count = 0;
  static  unsigned long long aesl_llvm_cbe_1712_count = 0;
  unsigned char llvm_cbe_tmp__359;
  static  unsigned long long aesl_llvm_cbe_1713_count = 0;
  static  unsigned long long aesl_llvm_cbe_1714_count = 0;
  static  unsigned long long aesl_llvm_cbe_1715_count = 0;
   char *llvm_cbe_tmp__360;
  static  unsigned long long aesl_llvm_cbe_1716_count = 0;
  static  unsigned long long aesl_llvm_cbe_1717_count = 0;
  static  unsigned long long aesl_llvm_cbe_1718_count = 0;
  static  unsigned long long aesl_llvm_cbe_1719_count = 0;
  static  unsigned long long aesl_llvm_cbe_1720_count = 0;
  static  unsigned long long aesl_llvm_cbe_1721_count = 0;
  static  unsigned long long aesl_llvm_cbe_1722_count = 0;
  static  unsigned long long aesl_llvm_cbe_1723_count = 0;
  static  unsigned long long aesl_llvm_cbe_1724_count = 0;
  static  unsigned long long aesl_llvm_cbe_1725_count = 0;
  static  unsigned long long aesl_llvm_cbe_1726_count = 0;
  static  unsigned long long aesl_llvm_cbe_1727_count = 0;
  static  unsigned long long aesl_llvm_cbe_1728_count = 0;
  static  unsigned long long aesl_llvm_cbe_1729_count = 0;
  static  unsigned long long aesl_llvm_cbe_1730_count = 0;
  static  unsigned long long aesl_llvm_cbe_1731_count = 0;
  static  unsigned long long aesl_llvm_cbe_1732_count = 0;
  static  unsigned long long aesl_llvm_cbe_1733_count = 0;
  static  unsigned long long aesl_llvm_cbe_1734_count = 0;
  static  unsigned long long aesl_llvm_cbe_1735_count = 0;
  static  unsigned long long aesl_llvm_cbe_1736_count = 0;
  static  unsigned long long aesl_llvm_cbe_1737_count = 0;
  static  unsigned long long aesl_llvm_cbe_1738_count = 0;
  static  unsigned long long aesl_llvm_cbe_1739_count = 0;
  static  unsigned long long aesl_llvm_cbe_1740_count = 0;
  static  unsigned long long aesl_llvm_cbe_1741_count = 0;
  static  unsigned long long aesl_llvm_cbe_1742_count = 0;
  static  unsigned long long aesl_llvm_cbe_1743_count = 0;
  static  unsigned long long aesl_llvm_cbe_1744_count = 0;
  static  unsigned long long aesl_llvm_cbe_1745_count = 0;
  static  unsigned long long aesl_llvm_cbe_1746_count = 0;
  static  unsigned long long aesl_llvm_cbe_1747_count = 0;
  static  unsigned long long aesl_llvm_cbe_1748_count = 0;
  static  unsigned long long aesl_llvm_cbe_1749_count = 0;
  static  unsigned long long aesl_llvm_cbe_1750_count = 0;
  static  unsigned long long aesl_llvm_cbe_1751_count = 0;
  static  unsigned long long aesl_llvm_cbe_1752_count = 0;
  unsigned int llvm_cbe_tmp__361;
  static  unsigned long long aesl_llvm_cbe_1753_count = 0;
  static  unsigned long long aesl_llvm_cbe_1754_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @randombytes\n");
  llvm_cbe_storemerge__PHI_TEMPORARY = (unsigned int )15u;   /* for PHI node */
  goto llvm_cbe_tmp__362;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__362:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge = phi i32 [ 15, %%0 ], [ %%9, %%8  for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_storemerge_count);
  llvm_cbe_storemerge = (unsigned int )llvm_cbe_storemerge__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge = 0x%X",llvm_cbe_storemerge);
printf("\n = 0x%X",15u);
printf("\n = 0x%X",llvm_cbe_tmp__281);
}
  if ((((signed int )llvm_cbe_storemerge) > ((signed int )4294967295u))) {
    goto llvm_cbe_tmp__363;
  } else {
    goto llvm_cbe__2e_preheader12;
  }

llvm_cbe_tmp__364:
if (AESL_DEBUG_TRACE)
printf("\n  store i8 0, i8* %%5, align 1, !dbg !16 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1395_count);
  *llvm_cbe_tmp__279 = ((unsigned char )0);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )0));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = add nsw i32 %%storemerge, -1, !dbg !16 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1396_count);
  llvm_cbe_tmp__281 = (unsigned int )((unsigned int )(llvm_cbe_storemerge&4294967295ull)) + ((unsigned int )(4294967295u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__281&4294967295ull)));
  llvm_cbe_storemerge__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__281;   /* for PHI node */
  goto llvm_cbe_tmp__362;

llvm_cbe_tmp__363:
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = sext i32 %%storemerge to i64, !dbg !16 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1390_count);
  llvm_cbe_tmp__278 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__278);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds %%struct.AES256_CTR_DRBG_struct* @DRBG_ctx, i64 0, i32 1, i64 %%4, !dbg !16 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1391_count);
  llvm_cbe_tmp__279 = ( char *)(&DRBG_ctx.field1[(((signed long long )llvm_cbe_tmp__278))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__278));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load i8* %%5, align 1, !dbg !16 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1392_count);
  llvm_cbe_tmp__280 = (unsigned char )*llvm_cbe_tmp__279;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__280);
  if (((llvm_cbe_tmp__280&255U) == (((unsigned char )-1)&255U))) {
    goto llvm_cbe_tmp__364;
  } else {
    goto llvm_cbe_tmp__365;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__365:
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = add i8 %%6, 1, !dbg !16 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1399_count);
  llvm_cbe_tmp__282 = (unsigned char )((unsigned char )(((unsigned char )(llvm_cbe_tmp__280&255ull)) + ((unsigned char )(((unsigned char )1)&255ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )(llvm_cbe_tmp__282&255ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%11, i8* %%5, align 1, !dbg !16 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1400_count);
  *llvm_cbe_tmp__279 = llvm_cbe_tmp__282;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__282);
  goto llvm_cbe__2e_preheader12;

llvm_cbe__2e_preheader12:
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds [16 x i8]* %%block, i64 0, i64 0, !dbg !16 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1402_count);
  llvm_cbe_tmp__283 = ( char *)(&llvm_cbe_block[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call fastcc void @aesl_internal_AES256_ECB(i8* getelementptr inbounds (%%struct.AES256_CTR_DRBG_struct* @DRBG_ctx, i64 0, i32 0, i64 0), i8* getelementptr inbounds (%%struct.AES256_CTR_DRBG_struct* @DRBG_ctx, i64 0, i32 1, i64 0), i8* %%12), !dbg !16 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1403_count);
  aesl_internal_AES256_ECB(( char *)((&DRBG_ctx.field0[(((signed long long )0ull))])), ( char *)((&DRBG_ctx.field1[(((signed long long )0ull))])), ( char *)llvm_cbe_tmp__283);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )0ull) < 16)) fprintf(stderr, "%s:%d: warning: Read access out of array 'block' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = load i8* %%12, align 16, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1409_count);
  llvm_cbe_tmp__284 = (unsigned char )*llvm_cbe_tmp__283;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__284);
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%13, i8* %%x, align 1, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1410_count);
  *llvm_cbe_x = llvm_cbe_tmp__284;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__284);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds [16 x i8]* %%block, i64 0, i64 1, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1416_count);
  llvm_cbe_tmp__285 = ( char *)(&llvm_cbe_block[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )1ull) < 16)) fprintf(stderr, "%s:%d: warning: Read access out of array 'block' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = load i8* %%14, align 1, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1417_count);
  llvm_cbe_tmp__286 = (unsigned char )*llvm_cbe_tmp__285;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__286);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds i8* %%x, i64 1, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1418_count);
  llvm_cbe_tmp__287 = ( char *)(&llvm_cbe_x[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%15, i8* %%16, align 1, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1419_count);
  *llvm_cbe_tmp__287 = llvm_cbe_tmp__286;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__286);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds [16 x i8]* %%block, i64 0, i64 2, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1425_count);
  llvm_cbe_tmp__288 = ( char *)(&llvm_cbe_block[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )2ull) < 16)) fprintf(stderr, "%s:%d: warning: Read access out of array 'block' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = load i8* %%17, align 2, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1426_count);
  llvm_cbe_tmp__289 = (unsigned char )*llvm_cbe_tmp__288;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__289);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = getelementptr inbounds i8* %%x, i64 2, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1427_count);
  llvm_cbe_tmp__290 = ( char *)(&llvm_cbe_x[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%18, i8* %%19, align 1, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1428_count);
  *llvm_cbe_tmp__290 = llvm_cbe_tmp__289;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__289);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = getelementptr inbounds [16 x i8]* %%block, i64 0, i64 3, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1434_count);
  llvm_cbe_tmp__291 = ( char *)(&llvm_cbe_block[(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )3ull) < 16)) fprintf(stderr, "%s:%d: warning: Read access out of array 'block' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = load i8* %%20, align 1, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1435_count);
  llvm_cbe_tmp__292 = (unsigned char )*llvm_cbe_tmp__291;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__292);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = getelementptr inbounds i8* %%x, i64 3, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1436_count);
  llvm_cbe_tmp__293 = ( char *)(&llvm_cbe_x[(((signed long long )3ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%21, i8* %%22, align 1, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1437_count);
  *llvm_cbe_tmp__293 = llvm_cbe_tmp__292;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__292);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = getelementptr inbounds [16 x i8]* %%block, i64 0, i64 4, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1443_count);
  llvm_cbe_tmp__294 = ( char *)(&llvm_cbe_block[(((signed long long )4ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )4ull) < 16)) fprintf(stderr, "%s:%d: warning: Read access out of array 'block' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = load i8* %%23, align 4, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1444_count);
  llvm_cbe_tmp__295 = (unsigned char )*llvm_cbe_tmp__294;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__295);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = getelementptr inbounds i8* %%x, i64 4, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1445_count);
  llvm_cbe_tmp__296 = ( char *)(&llvm_cbe_x[(((signed long long )4ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%24, i8* %%25, align 1, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1446_count);
  *llvm_cbe_tmp__296 = llvm_cbe_tmp__295;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__295);
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = getelementptr inbounds [16 x i8]* %%block, i64 0, i64 5, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1452_count);
  llvm_cbe_tmp__297 = ( char *)(&llvm_cbe_block[(((signed long long )5ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )5ull) < 16)) fprintf(stderr, "%s:%d: warning: Read access out of array 'block' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = load i8* %%26, align 1, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1453_count);
  llvm_cbe_tmp__298 = (unsigned char )*llvm_cbe_tmp__297;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__298);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = getelementptr inbounds i8* %%x, i64 5, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1454_count);
  llvm_cbe_tmp__299 = ( char *)(&llvm_cbe_x[(((signed long long )5ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%27, i8* %%28, align 1, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1455_count);
  *llvm_cbe_tmp__299 = llvm_cbe_tmp__298;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__298);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = getelementptr inbounds [16 x i8]* %%block, i64 0, i64 6, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1461_count);
  llvm_cbe_tmp__300 = ( char *)(&llvm_cbe_block[(((signed long long )6ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )6ull) < 16)) fprintf(stderr, "%s:%d: warning: Read access out of array 'block' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = load i8* %%29, align 2, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1462_count);
  llvm_cbe_tmp__301 = (unsigned char )*llvm_cbe_tmp__300;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__301);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = getelementptr inbounds i8* %%x, i64 6, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1463_count);
  llvm_cbe_tmp__302 = ( char *)(&llvm_cbe_x[(((signed long long )6ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%30, i8* %%31, align 1, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1464_count);
  *llvm_cbe_tmp__302 = llvm_cbe_tmp__301;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__301);
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = getelementptr inbounds [16 x i8]* %%block, i64 0, i64 7, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1470_count);
  llvm_cbe_tmp__303 = ( char *)(&llvm_cbe_block[(((signed long long )7ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )7ull) < 16)) fprintf(stderr, "%s:%d: warning: Read access out of array 'block' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = load i8* %%32, align 1, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1471_count);
  llvm_cbe_tmp__304 = (unsigned char )*llvm_cbe_tmp__303;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__304);
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = getelementptr inbounds i8* %%x, i64 7, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1472_count);
  llvm_cbe_tmp__305 = ( char *)(&llvm_cbe_x[(((signed long long )7ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%33, i8* %%34, align 1, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1473_count);
  *llvm_cbe_tmp__305 = llvm_cbe_tmp__304;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__304);
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = getelementptr inbounds [16 x i8]* %%block, i64 0, i64 8, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1479_count);
  llvm_cbe_tmp__306 = ( char *)(&llvm_cbe_block[(((signed long long )8ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )8ull) < 16)) fprintf(stderr, "%s:%d: warning: Read access out of array 'block' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = load i8* %%35, align 8, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1480_count);
  llvm_cbe_tmp__307 = (unsigned char )*llvm_cbe_tmp__306;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__307);
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = getelementptr inbounds i8* %%x, i64 8, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1481_count);
  llvm_cbe_tmp__308 = ( char *)(&llvm_cbe_x[(((signed long long )8ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%36, i8* %%37, align 1, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1482_count);
  *llvm_cbe_tmp__308 = llvm_cbe_tmp__307;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__307);
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = getelementptr inbounds [16 x i8]* %%block, i64 0, i64 9, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1488_count);
  llvm_cbe_tmp__309 = ( char *)(&llvm_cbe_block[(((signed long long )9ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )9ull) < 16)) fprintf(stderr, "%s:%d: warning: Read access out of array 'block' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = load i8* %%38, align 1, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1489_count);
  llvm_cbe_tmp__310 = (unsigned char )*llvm_cbe_tmp__309;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__310);
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = getelementptr inbounds i8* %%x, i64 9, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1490_count);
  llvm_cbe_tmp__311 = ( char *)(&llvm_cbe_x[(((signed long long )9ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%39, i8* %%40, align 1, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1491_count);
  *llvm_cbe_tmp__311 = llvm_cbe_tmp__310;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__310);
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = getelementptr inbounds [16 x i8]* %%block, i64 0, i64 10, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1497_count);
  llvm_cbe_tmp__312 = ( char *)(&llvm_cbe_block[(((signed long long )10ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )10ull) < 16)) fprintf(stderr, "%s:%d: warning: Read access out of array 'block' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = load i8* %%41, align 2, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1498_count);
  llvm_cbe_tmp__313 = (unsigned char )*llvm_cbe_tmp__312;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__313);
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = getelementptr inbounds i8* %%x, i64 10, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1499_count);
  llvm_cbe_tmp__314 = ( char *)(&llvm_cbe_x[(((signed long long )10ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%42, i8* %%43, align 1, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1500_count);
  *llvm_cbe_tmp__314 = llvm_cbe_tmp__313;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__313);
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = getelementptr inbounds [16 x i8]* %%block, i64 0, i64 11, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1506_count);
  llvm_cbe_tmp__315 = ( char *)(&llvm_cbe_block[(((signed long long )11ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )11ull) < 16)) fprintf(stderr, "%s:%d: warning: Read access out of array 'block' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = load i8* %%44, align 1, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1507_count);
  llvm_cbe_tmp__316 = (unsigned char )*llvm_cbe_tmp__315;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__316);
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = getelementptr inbounds i8* %%x, i64 11, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1508_count);
  llvm_cbe_tmp__317 = ( char *)(&llvm_cbe_x[(((signed long long )11ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%45, i8* %%46, align 1, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1509_count);
  *llvm_cbe_tmp__317 = llvm_cbe_tmp__316;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__316);
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = getelementptr inbounds [16 x i8]* %%block, i64 0, i64 12, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1515_count);
  llvm_cbe_tmp__318 = ( char *)(&llvm_cbe_block[(((signed long long )12ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )12ull) < 16)) fprintf(stderr, "%s:%d: warning: Read access out of array 'block' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = load i8* %%47, align 4, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1516_count);
  llvm_cbe_tmp__319 = (unsigned char )*llvm_cbe_tmp__318;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__319);
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = getelementptr inbounds i8* %%x, i64 12, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1517_count);
  llvm_cbe_tmp__320 = ( char *)(&llvm_cbe_x[(((signed long long )12ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%48, i8* %%49, align 1, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1518_count);
  *llvm_cbe_tmp__320 = llvm_cbe_tmp__319;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__319);
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = getelementptr inbounds [16 x i8]* %%block, i64 0, i64 13, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1524_count);
  llvm_cbe_tmp__321 = ( char *)(&llvm_cbe_block[(((signed long long )13ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )13ull) < 16)) fprintf(stderr, "%s:%d: warning: Read access out of array 'block' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = load i8* %%50, align 1, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1525_count);
  llvm_cbe_tmp__322 = (unsigned char )*llvm_cbe_tmp__321;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__322);
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = getelementptr inbounds i8* %%x, i64 13, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1526_count);
  llvm_cbe_tmp__323 = ( char *)(&llvm_cbe_x[(((signed long long )13ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%51, i8* %%52, align 1, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1527_count);
  *llvm_cbe_tmp__323 = llvm_cbe_tmp__322;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__322);
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = getelementptr inbounds [16 x i8]* %%block, i64 0, i64 14, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1533_count);
  llvm_cbe_tmp__324 = ( char *)(&llvm_cbe_block[(((signed long long )14ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )14ull) < 16)) fprintf(stderr, "%s:%d: warning: Read access out of array 'block' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = load i8* %%53, align 2, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1534_count);
  llvm_cbe_tmp__325 = (unsigned char )*llvm_cbe_tmp__324;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__325);
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = getelementptr inbounds i8* %%x, i64 14, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1535_count);
  llvm_cbe_tmp__326 = ( char *)(&llvm_cbe_x[(((signed long long )14ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%54, i8* %%55, align 1, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1536_count);
  *llvm_cbe_tmp__326 = llvm_cbe_tmp__325;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__325);
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = getelementptr inbounds [16 x i8]* %%block, i64 0, i64 15, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1542_count);
  llvm_cbe_tmp__327 = ( char *)(&llvm_cbe_block[(((signed long long )15ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )15ull) < 16)) fprintf(stderr, "%s:%d: warning: Read access out of array 'block' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = load i8* %%56, align 1, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1543_count);
  llvm_cbe_tmp__328 = (unsigned char )*llvm_cbe_tmp__327;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__328);
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = getelementptr inbounds i8* %%x, i64 15, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1544_count);
  llvm_cbe_tmp__329 = ( char *)(&llvm_cbe_x[(((signed long long )15ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%57, i8* %%58, align 1, !dbg !13 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1545_count);
  *llvm_cbe_tmp__329 = llvm_cbe_tmp__328;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__328);
  llvm_cbe_storemerge6__PHI_TEMPORARY = (unsigned int )15u;   /* for PHI node */
  goto llvm_cbe_tmp__366;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__366:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge6 = phi i32 [ %%67, %%66 ], [ 15, %%.preheader12  for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_storemerge6_count);
  llvm_cbe_storemerge6 = (unsigned int )llvm_cbe_storemerge6__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge6 = 0x%X",llvm_cbe_storemerge6);
printf("\n = 0x%X",llvm_cbe_tmp__333);
printf("\n = 0x%X",15u);
}
  if ((((signed int )llvm_cbe_storemerge6) > ((signed int )4294967295u))) {
    goto llvm_cbe_tmp__367;
  } else {
    goto llvm_cbe__2e_preheader10_2e_1;
  }

llvm_cbe_tmp__368:
if (AESL_DEBUG_TRACE)
printf("\n  store i8 0, i8* %%63, align 1, !dbg !17 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1580_count);
  *llvm_cbe_tmp__331 = ((unsigned char )0);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )0));
if (AESL_DEBUG_TRACE)
printf("\n  %%67 = add nsw i32 %%storemerge6, -1, !dbg !18 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1581_count);
  llvm_cbe_tmp__333 = (unsigned int )((unsigned int )(llvm_cbe_storemerge6&4294967295ull)) + ((unsigned int )(4294967295u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__333&4294967295ull)));
  llvm_cbe_storemerge6__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__333;   /* for PHI node */
  goto llvm_cbe_tmp__366;

llvm_cbe_tmp__367:
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = sext i32 %%storemerge6 to i64, !dbg !17 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1575_count);
  llvm_cbe_tmp__330 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge6);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__330);
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = getelementptr inbounds %%struct.AES256_CTR_DRBG_struct* @DRBG_ctx, i64 0, i32 1, i64 %%62, !dbg !17 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1576_count);
  llvm_cbe_tmp__331 = ( char *)(&DRBG_ctx.field1[(((signed long long )llvm_cbe_tmp__330))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__330));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%64 = load i8* %%63, align 1, !dbg !17 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1577_count);
  llvm_cbe_tmp__332 = (unsigned char )*llvm_cbe_tmp__331;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__332);
  if (((llvm_cbe_tmp__332&255U) == (((unsigned char )-1)&255U))) {
    goto llvm_cbe_tmp__368;
  } else {
    goto llvm_cbe_tmp__369;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__369:
if (AESL_DEBUG_TRACE)
printf("\n  %%69 = add i8 %%64, 1, !dbg !17 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1584_count);
  llvm_cbe_tmp__334 = (unsigned char )((unsigned char )(((unsigned char )(llvm_cbe_tmp__332&255ull)) + ((unsigned char )(((unsigned char )1)&255ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )(llvm_cbe_tmp__334&255ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%69, i8* %%63, align 1, !dbg !17 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1585_count);
  *llvm_cbe_tmp__331 = llvm_cbe_tmp__334;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__334);
  goto llvm_cbe__2e_preheader10_2e_1;

llvm_cbe__2e_preheader10_2e_1:
if (AESL_DEBUG_TRACE)
printf("\n  %%70 = getelementptr inbounds [48 x i8]* %%temp, i64 0, i64 0, !dbg !14 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1587_count);
  llvm_cbe_tmp__335 = ( char *)(&llvm_cbe_temp[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 48
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call fastcc void @aesl_internal_AES256_ECB(i8* getelementptr inbounds (%%struct.AES256_CTR_DRBG_struct* @DRBG_ctx, i64 0, i32 0, i64 0), i8* getelementptr inbounds (%%struct.AES256_CTR_DRBG_struct* @DRBG_ctx, i64 0, i32 1, i64 0), i8* %%70), !dbg !14 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1588_count);
  aesl_internal_AES256_ECB(( char *)((&DRBG_ctx.field0[(((signed long long )0ull))])), ( char *)((&DRBG_ctx.field1[(((signed long long )0ull))])), ( char *)llvm_cbe_tmp__335);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge6_2e_1__PHI_TEMPORARY = (unsigned int )15u;   /* for PHI node */
  goto llvm_cbe_tmp__370;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__371:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge39 = phi i32 [ 0, %%.preheader8 ], [ %%76, %%71  for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_storemerge39_count);
  llvm_cbe_storemerge39 = (unsigned int )llvm_cbe_storemerge39__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge39 = 0x%X",llvm_cbe_storemerge39);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__340);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%72 = sext i32 %%storemerge39 to i64, !dbg !15 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1607_count);
  llvm_cbe_tmp__336 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge39);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__336);
if (AESL_DEBUG_TRACE)
printf("\n  %%73 = getelementptr inbounds [48 x i8]* %%temp, i64 0, i64 %%72, !dbg !15 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1608_count);
  llvm_cbe_tmp__337 = ( char *)(&llvm_cbe_temp[(((signed long long )llvm_cbe_tmp__336))
#ifdef AESL_BC_SIM
 % 48
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__336));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__336) < 48)) fprintf(stderr, "%s:%d: warning: Read access out of array 'temp' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%74 = load i8* %%73, align 1, !dbg !15 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1609_count);
  llvm_cbe_tmp__338 = (unsigned char )*llvm_cbe_tmp__337;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__338);
if (AESL_DEBUG_TRACE)
printf("\n  %%75 = getelementptr inbounds %%struct.AES256_CTR_DRBG_struct* @DRBG_ctx, i64 0, i32 0, i64 %%72, !dbg !15 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1610_count);
  llvm_cbe_tmp__339 = ( char *)(&DRBG_ctx.field0[(((signed long long )llvm_cbe_tmp__336))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__336));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%74, i8* %%75, align 1, !dbg !15 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1611_count);
  *llvm_cbe_tmp__339 = llvm_cbe_tmp__338;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__338);
if (AESL_DEBUG_TRACE)
printf("\n  %%76 = add nsw i32 %%storemerge39, 1, !dbg !15 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1612_count);
  llvm_cbe_tmp__340 = (unsigned int )((unsigned int )(llvm_cbe_storemerge39&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__340&4294967295ull)));
  if (((llvm_cbe_tmp__340&4294967295U) == (32u&4294967295U))) {
    llvm_cbe_storemerge47__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  } else {
    llvm_cbe_storemerge39__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__340;   /* for PHI node */
    goto llvm_cbe_tmp__371;
  }

  } while (1); /* end of syntactic loop '' */
  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge47 = phi i32 [ %%83, %%.preheader ], [ 0, %%71  for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_storemerge47_count);
  llvm_cbe_storemerge47 = (unsigned int )llvm_cbe_storemerge47__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge47 = 0x%X",llvm_cbe_storemerge47);
printf("\n = 0x%X",llvm_cbe_tmp__347);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%77 = add nsw i32 %%storemerge47, 32, !dbg !15 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1631_count);
  llvm_cbe_tmp__341 = (unsigned int )((unsigned int )(llvm_cbe_storemerge47&4294967295ull)) + ((unsigned int )(32u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__341&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%78 = sext i32 %%77 to i64, !dbg !15 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1632_count);
  llvm_cbe_tmp__342 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__341);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__342);
if (AESL_DEBUG_TRACE)
printf("\n  %%79 = getelementptr inbounds [48 x i8]* %%temp, i64 0, i64 %%78, !dbg !15 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1633_count);
  llvm_cbe_tmp__343 = ( char *)(&llvm_cbe_temp[(((signed long long )llvm_cbe_tmp__342))
#ifdef AESL_BC_SIM
 % 48
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__342));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__342) < 48)) fprintf(stderr, "%s:%d: warning: Read access out of array 'temp' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%80 = load i8* %%79, align 1, !dbg !15 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1634_count);
  llvm_cbe_tmp__344 = (unsigned char )*llvm_cbe_tmp__343;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__344);
if (AESL_DEBUG_TRACE)
printf("\n  %%81 = sext i32 %%storemerge47 to i64, !dbg !15 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1635_count);
  llvm_cbe_tmp__345 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge47);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__345);
if (AESL_DEBUG_TRACE)
printf("\n  %%82 = getelementptr inbounds %%struct.AES256_CTR_DRBG_struct* @DRBG_ctx, i64 0, i32 1, i64 %%81, !dbg !15 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1636_count);
  llvm_cbe_tmp__346 = ( char *)(&DRBG_ctx.field1[(((signed long long )llvm_cbe_tmp__345))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__345));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%80, i8* %%82, align 1, !dbg !15 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1637_count);
  *llvm_cbe_tmp__346 = llvm_cbe_tmp__344;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__344);
if (AESL_DEBUG_TRACE)
printf("\n  %%83 = add nsw i32 %%storemerge47, 1, !dbg !15 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1638_count);
  llvm_cbe_tmp__347 = (unsigned int )((unsigned int )(llvm_cbe_storemerge47&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__347&4294967295ull)));
  if (((llvm_cbe_tmp__347&4294967295U) == (16u&4294967295U))) {
    goto llvm_cbe_tmp__372;
  } else {
    llvm_cbe_storemerge47__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__347;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe_tmp__372:
if (AESL_DEBUG_TRACE)
printf("\n  %%85 = load i32* getelementptr inbounds (%%struct.AES256_CTR_DRBG_struct* @DRBG_ctx, i64 0, i32 2), align 4, !dbg !18 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1657_count);
  llvm_cbe_tmp__348 = (unsigned int )*((&DRBG_ctx.field2));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__348);
if (AESL_DEBUG_TRACE)
printf("\n  %%86 = add nsw i32 %%85, 1, !dbg !18 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1658_count);
  llvm_cbe_tmp__349 = (unsigned int )((unsigned int )(llvm_cbe_tmp__348&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__349&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%86, i32* getelementptr inbounds (%%struct.AES256_CTR_DRBG_struct* @DRBG_ctx, i64 0, i32 2), align 4, !dbg !18 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1659_count);
  *((&DRBG_ctx.field2)) = llvm_cbe_tmp__349;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__349);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @randombytes}\n");
  return 0u;
  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__370:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge6.1 = phi i32 [ %%98, %%97 ], [ 15, %%.preheader10.1  for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_storemerge6_2e_1_count);
  llvm_cbe_storemerge6_2e_1 = (unsigned int )llvm_cbe_storemerge6_2e_1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge6.1 = 0x%X",llvm_cbe_storemerge6_2e_1);
printf("\n = 0x%X",llvm_cbe_tmp__355);
printf("\n = 0x%X",15u);
}
  if ((((signed int )llvm_cbe_storemerge6_2e_1) > ((signed int )4294967295u))) {
    goto llvm_cbe_tmp__373;
  } else {
    goto llvm_cbe__2e_preheader10_2e_2;
  }

llvm_cbe_tmp__374:
if (AESL_DEBUG_TRACE)
printf("\n  store i8 0, i8* %%91, align 1, !dbg !17 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1696_count);
  *llvm_cbe_tmp__351 = ((unsigned char )0);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )0));
if (AESL_DEBUG_TRACE)
printf("\n  %%98 = add nsw i32 %%storemerge6.1, -1, !dbg !18 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1697_count);
  llvm_cbe_tmp__355 = (unsigned int )((unsigned int )(llvm_cbe_storemerge6_2e_1&4294967295ull)) + ((unsigned int )(4294967295u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__355&4294967295ull)));
  llvm_cbe_storemerge6_2e_1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__355;   /* for PHI node */
  goto llvm_cbe_tmp__370;

llvm_cbe_tmp__373:
if (AESL_DEBUG_TRACE)
printf("\n  %%90 = sext i32 %%storemerge6.1 to i64, !dbg !17 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1668_count);
  llvm_cbe_tmp__350 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge6_2e_1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__350);
if (AESL_DEBUG_TRACE)
printf("\n  %%91 = getelementptr inbounds %%struct.AES256_CTR_DRBG_struct* @DRBG_ctx, i64 0, i32 1, i64 %%90, !dbg !17 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1669_count);
  llvm_cbe_tmp__351 = ( char *)(&DRBG_ctx.field1[(((signed long long )llvm_cbe_tmp__350))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__350));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%92 = load i8* %%91, align 1, !dbg !17 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1670_count);
  llvm_cbe_tmp__352 = (unsigned char )*llvm_cbe_tmp__351;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__352);
  if (((llvm_cbe_tmp__352&255U) == (((unsigned char )-1)&255U))) {
    goto llvm_cbe_tmp__374;
  } else {
    goto llvm_cbe_tmp__375;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__375:
if (AESL_DEBUG_TRACE)
printf("\n  %%95 = add i8 %%92, 1, !dbg !17 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1673_count);
  llvm_cbe_tmp__353 = (unsigned char )((unsigned char )(((unsigned char )(llvm_cbe_tmp__352&255ull)) + ((unsigned char )(((unsigned char )1)&255ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )(llvm_cbe_tmp__353&255ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%95, i8* %%91, align 1, !dbg !17 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1674_count);
  *llvm_cbe_tmp__351 = llvm_cbe_tmp__353;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__353);
  goto llvm_cbe__2e_preheader10_2e_2;

llvm_cbe__2e_preheader10_2e_2:
if (AESL_DEBUG_TRACE)
printf("\n  %%96 = getelementptr inbounds [48 x i8]* %%temp, i64 0, i64 16, !dbg !14 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1676_count);
  llvm_cbe_tmp__354 = ( char *)(&llvm_cbe_temp[(((signed long long )16ull))
#ifdef AESL_BC_SIM
 % 48
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call fastcc void @aesl_internal_AES256_ECB(i8* getelementptr inbounds (%%struct.AES256_CTR_DRBG_struct* @DRBG_ctx, i64 0, i32 0, i64 0), i8* getelementptr inbounds (%%struct.AES256_CTR_DRBG_struct* @DRBG_ctx, i64 0, i32 1, i64 0), i8* %%96), !dbg !14 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1677_count);
  aesl_internal_AES256_ECB(( char *)((&DRBG_ctx.field0[(((signed long long )0ull))])), ( char *)((&DRBG_ctx.field1[(((signed long long )0ull))])), ( char *)llvm_cbe_tmp__354);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge6_2e_2__PHI_TEMPORARY = (unsigned int )15u;   /* for PHI node */
  goto llvm_cbe_tmp__376;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__376:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge6.2 = phi i32 [ %%110, %%109 ], [ 15, %%.preheader10.2  for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_storemerge6_2e_2_count);
  llvm_cbe_storemerge6_2e_2 = (unsigned int )llvm_cbe_storemerge6_2e_2__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge6.2 = 0x%X",llvm_cbe_storemerge6_2e_2);
printf("\n = 0x%X",llvm_cbe_tmp__361);
printf("\n = 0x%X",15u);
}
  if ((((signed int )llvm_cbe_storemerge6_2e_2) > ((signed int )4294967295u))) {
    goto llvm_cbe_tmp__377;
  } else {
    goto llvm_cbe__2e_preheader8;
  }

llvm_cbe_tmp__378:
if (AESL_DEBUG_TRACE)
printf("\n  store i8 0, i8* %%103, align 1, !dbg !17 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1751_count);
  *llvm_cbe_tmp__357 = ((unsigned char )0);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )0));
if (AESL_DEBUG_TRACE)
printf("\n  %%110 = add nsw i32 %%storemerge6.2, -1, !dbg !18 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1752_count);
  llvm_cbe_tmp__361 = (unsigned int )((unsigned int )(llvm_cbe_storemerge6_2e_2&4294967295ull)) + ((unsigned int )(4294967295u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__361&4294967295ull)));
  llvm_cbe_storemerge6_2e_2__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__361;   /* for PHI node */
  goto llvm_cbe_tmp__376;

llvm_cbe_tmp__377:
if (AESL_DEBUG_TRACE)
printf("\n  %%102 = sext i32 %%storemerge6.2 to i64, !dbg !17 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1707_count);
  llvm_cbe_tmp__356 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge6_2e_2);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__356);
if (AESL_DEBUG_TRACE)
printf("\n  %%103 = getelementptr inbounds %%struct.AES256_CTR_DRBG_struct* @DRBG_ctx, i64 0, i32 1, i64 %%102, !dbg !17 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1708_count);
  llvm_cbe_tmp__357 = ( char *)(&DRBG_ctx.field1[(((signed long long )llvm_cbe_tmp__356))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__356));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%104 = load i8* %%103, align 1, !dbg !17 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1709_count);
  llvm_cbe_tmp__358 = (unsigned char )*llvm_cbe_tmp__357;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__358);
  if (((llvm_cbe_tmp__358&255U) == (((unsigned char )-1)&255U))) {
    goto llvm_cbe_tmp__378;
  } else {
    goto llvm_cbe_tmp__379;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__379:
if (AESL_DEBUG_TRACE)
printf("\n  %%107 = add i8 %%104, 1, !dbg !17 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1712_count);
  llvm_cbe_tmp__359 = (unsigned char )((unsigned char )(((unsigned char )(llvm_cbe_tmp__358&255ull)) + ((unsigned char )(((unsigned char )1)&255ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )(llvm_cbe_tmp__359&255ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%107, i8* %%103, align 1, !dbg !17 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1713_count);
  *llvm_cbe_tmp__357 = llvm_cbe_tmp__359;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__359);
  goto llvm_cbe__2e_preheader8;

llvm_cbe__2e_preheader8:
if (AESL_DEBUG_TRACE)
printf("\n  %%108 = getelementptr inbounds [48 x i8]* %%temp, i64 0, i64 32, !dbg !14 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1715_count);
  llvm_cbe_tmp__360 = ( char *)(&llvm_cbe_temp[(((signed long long )32ull))
#ifdef AESL_BC_SIM
 % 48
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call fastcc void @aesl_internal_AES256_ECB(i8* getelementptr inbounds (%%struct.AES256_CTR_DRBG_struct* @DRBG_ctx, i64 0, i32 0, i64 0), i8* getelementptr inbounds (%%struct.AES256_CTR_DRBG_struct* @DRBG_ctx, i64 0, i32 1, i64 0), i8* %%108), !dbg !14 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_1716_count);
  aesl_internal_AES256_ECB(( char *)((&DRBG_ctx.field0[(((signed long long )0ull))])), ( char *)((&DRBG_ctx.field1[(((signed long long )0ull))])), ( char *)llvm_cbe_tmp__360);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge39__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__371;

}


signed int randombytes_sign( char *llvm_cbe_x, signed long long llvm_cbe_xlen) {
  static  unsigned long long aesl_llvm_cbe_block_count = 0;
   char llvm_cbe_block[16];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_1755_count = 0;
  static  unsigned long long aesl_llvm_cbe_1756_count = 0;
  static  unsigned long long aesl_llvm_cbe_1757_count = 0;
  static  unsigned long long aesl_llvm_cbe_1758_count = 0;
  static  unsigned long long aesl_llvm_cbe_1759_count = 0;
  static  unsigned long long aesl_llvm_cbe_1760_count = 0;
  static  unsigned long long aesl_llvm_cbe_1761_count = 0;
  static  unsigned long long aesl_llvm_cbe_1762_count = 0;
  static  unsigned long long aesl_llvm_cbe_1763_count = 0;
  static  unsigned long long aesl_llvm_cbe_1764_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge_count = 0;
  unsigned int llvm_cbe_storemerge;
  unsigned int llvm_cbe_storemerge__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1765_count = 0;
  static  unsigned long long aesl_llvm_cbe_1766_count = 0;
  static  unsigned long long aesl_llvm_cbe_1767_count = 0;
  static  unsigned long long aesl_llvm_cbe_1768_count = 0;
  static  unsigned long long aesl_llvm_cbe_1769_count = 0;
  static  unsigned long long aesl_llvm_cbe_1770_count = 0;
  static  unsigned long long aesl_llvm_cbe_1771_count = 0;
  static  unsigned long long aesl_llvm_cbe_1772_count = 0;
  unsigned long long llvm_cbe_tmp__380;
  static  unsigned long long aesl_llvm_cbe_1773_count = 0;
   char *llvm_cbe_tmp__381;
  static  unsigned long long aesl_llvm_cbe_1774_count = 0;
  unsigned char llvm_cbe_tmp__382;
  static  unsigned long long aesl_llvm_cbe_1775_count = 0;
  static  unsigned long long aesl_llvm_cbe_1776_count = 0;
  static  unsigned long long aesl_llvm_cbe_1777_count = 0;
  static  unsigned long long aesl_llvm_cbe_1778_count = 0;
  unsigned int llvm_cbe_tmp__383;
  static  unsigned long long aesl_llvm_cbe_1779_count = 0;
  static  unsigned long long aesl_llvm_cbe_1780_count = 0;
  static  unsigned long long aesl_llvm_cbe_1781_count = 0;
  unsigned char llvm_cbe_tmp__384;
  static  unsigned long long aesl_llvm_cbe_1782_count = 0;
  static  unsigned long long aesl_llvm_cbe_1783_count = 0;
  static  unsigned long long aesl_llvm_cbe_1784_count = 0;
   char *llvm_cbe_tmp__385;
  static  unsigned long long aesl_llvm_cbe_1785_count = 0;
  static  unsigned long long aesl_llvm_cbe_1786_count = 0;
  static  unsigned long long aesl_llvm_cbe_1787_count = 0;
  static  unsigned long long aesl_llvm_cbe_1788_count = 0;
  static  unsigned long long aesl_llvm_cbe_1789_count = 0;
  static  unsigned long long aesl_llvm_cbe_1790_count = 0;
  static  unsigned long long aesl_llvm_cbe_1791_count = 0;
  unsigned char llvm_cbe_tmp__386;
  static  unsigned long long aesl_llvm_cbe_1792_count = 0;
  static  unsigned long long aesl_llvm_cbe_1793_count = 0;
  static  unsigned long long aesl_llvm_cbe_1794_count = 0;
  static  unsigned long long aesl_llvm_cbe_1795_count = 0;
  static  unsigned long long aesl_llvm_cbe_1796_count = 0;
  static  unsigned long long aesl_llvm_cbe_1797_count = 0;
  static  unsigned long long aesl_llvm_cbe_1798_count = 0;
   char *llvm_cbe_tmp__387;
  static  unsigned long long aesl_llvm_cbe_1799_count = 0;
  unsigned char llvm_cbe_tmp__388;
  static  unsigned long long aesl_llvm_cbe_1800_count = 0;
   char *llvm_cbe_tmp__389;
  static  unsigned long long aesl_llvm_cbe_1801_count = 0;
  static  unsigned long long aesl_llvm_cbe_1802_count = 0;
  static  unsigned long long aesl_llvm_cbe_1803_count = 0;
  static  unsigned long long aesl_llvm_cbe_1804_count = 0;
  static  unsigned long long aesl_llvm_cbe_1805_count = 0;
  static  unsigned long long aesl_llvm_cbe_1806_count = 0;
  static  unsigned long long aesl_llvm_cbe_1807_count = 0;
   char *llvm_cbe_tmp__390;
  static  unsigned long long aesl_llvm_cbe_1808_count = 0;
  unsigned char llvm_cbe_tmp__391;
  static  unsigned long long aesl_llvm_cbe_1809_count = 0;
   char *llvm_cbe_tmp__392;
  static  unsigned long long aesl_llvm_cbe_1810_count = 0;
  static  unsigned long long aesl_llvm_cbe_1811_count = 0;
  static  unsigned long long aesl_llvm_cbe_1812_count = 0;
  static  unsigned long long aesl_llvm_cbe_1813_count = 0;
  static  unsigned long long aesl_llvm_cbe_1814_count = 0;
  static  unsigned long long aesl_llvm_cbe_1815_count = 0;
  static  unsigned long long aesl_llvm_cbe_1816_count = 0;
   char *llvm_cbe_tmp__393;
  static  unsigned long long aesl_llvm_cbe_1817_count = 0;
  unsigned char llvm_cbe_tmp__394;
  static  unsigned long long aesl_llvm_cbe_1818_count = 0;
   char *llvm_cbe_tmp__395;
  static  unsigned long long aesl_llvm_cbe_1819_count = 0;
  static  unsigned long long aesl_llvm_cbe_1820_count = 0;
  static  unsigned long long aesl_llvm_cbe_1821_count = 0;
  static  unsigned long long aesl_llvm_cbe_1822_count = 0;
  static  unsigned long long aesl_llvm_cbe_1823_count = 0;
  static  unsigned long long aesl_llvm_cbe_1824_count = 0;
  static  unsigned long long aesl_llvm_cbe_1825_count = 0;
   char *llvm_cbe_tmp__396;
  static  unsigned long long aesl_llvm_cbe_1826_count = 0;
  unsigned char llvm_cbe_tmp__397;
  static  unsigned long long aesl_llvm_cbe_1827_count = 0;
   char *llvm_cbe_tmp__398;
  static  unsigned long long aesl_llvm_cbe_1828_count = 0;
  static  unsigned long long aesl_llvm_cbe_1829_count = 0;
  static  unsigned long long aesl_llvm_cbe_1830_count = 0;
  static  unsigned long long aesl_llvm_cbe_1831_count = 0;
  static  unsigned long long aesl_llvm_cbe_1832_count = 0;
  static  unsigned long long aesl_llvm_cbe_1833_count = 0;
  static  unsigned long long aesl_llvm_cbe_1834_count = 0;
   char *llvm_cbe_tmp__399;
  static  unsigned long long aesl_llvm_cbe_1835_count = 0;
  unsigned char llvm_cbe_tmp__400;
  static  unsigned long long aesl_llvm_cbe_1836_count = 0;
   char *llvm_cbe_tmp__401;
  static  unsigned long long aesl_llvm_cbe_1837_count = 0;
  static  unsigned long long aesl_llvm_cbe_1838_count = 0;
  static  unsigned long long aesl_llvm_cbe_1839_count = 0;
  static  unsigned long long aesl_llvm_cbe_1840_count = 0;
  static  unsigned long long aesl_llvm_cbe_1841_count = 0;
  static  unsigned long long aesl_llvm_cbe_1842_count = 0;
  static  unsigned long long aesl_llvm_cbe_1843_count = 0;
   char *llvm_cbe_tmp__402;
  static  unsigned long long aesl_llvm_cbe_1844_count = 0;
  unsigned char llvm_cbe_tmp__403;
  static  unsigned long long aesl_llvm_cbe_1845_count = 0;
   char *llvm_cbe_tmp__404;
  static  unsigned long long aesl_llvm_cbe_1846_count = 0;
  static  unsigned long long aesl_llvm_cbe_1847_count = 0;
  static  unsigned long long aesl_llvm_cbe_1848_count = 0;
  static  unsigned long long aesl_llvm_cbe_1849_count = 0;
  static  unsigned long long aesl_llvm_cbe_1850_count = 0;
  static  unsigned long long aesl_llvm_cbe_1851_count = 0;
  static  unsigned long long aesl_llvm_cbe_1852_count = 0;
   char *llvm_cbe_tmp__405;
  static  unsigned long long aesl_llvm_cbe_1853_count = 0;
  unsigned char llvm_cbe_tmp__406;
  static  unsigned long long aesl_llvm_cbe_1854_count = 0;
   char *llvm_cbe_tmp__407;
  static  unsigned long long aesl_llvm_cbe_1855_count = 0;
  static  unsigned long long aesl_llvm_cbe_1856_count = 0;
  static  unsigned long long aesl_llvm_cbe_1857_count = 0;
  static  unsigned long long aesl_llvm_cbe_1858_count = 0;
  static  unsigned long long aesl_llvm_cbe_1859_count = 0;
  static  unsigned long long aesl_llvm_cbe_1860_count = 0;
  static  unsigned long long aesl_llvm_cbe_1861_count = 0;
   char *llvm_cbe_tmp__408;
  static  unsigned long long aesl_llvm_cbe_1862_count = 0;
  unsigned char llvm_cbe_tmp__409;
  static  unsigned long long aesl_llvm_cbe_1863_count = 0;
   char *llvm_cbe_tmp__410;
  static  unsigned long long aesl_llvm_cbe_1864_count = 0;
  static  unsigned long long aesl_llvm_cbe_1865_count = 0;
  static  unsigned long long aesl_llvm_cbe_1866_count = 0;
  static  unsigned long long aesl_llvm_cbe_1867_count = 0;
  static  unsigned long long aesl_llvm_cbe_1868_count = 0;
  static  unsigned long long aesl_llvm_cbe_1869_count = 0;
  static  unsigned long long aesl_llvm_cbe_1870_count = 0;
   char *llvm_cbe_tmp__411;
  static  unsigned long long aesl_llvm_cbe_1871_count = 0;
  unsigned char llvm_cbe_tmp__412;
  static  unsigned long long aesl_llvm_cbe_1872_count = 0;
   char *llvm_cbe_tmp__413;
  static  unsigned long long aesl_llvm_cbe_1873_count = 0;
  static  unsigned long long aesl_llvm_cbe_1874_count = 0;
  static  unsigned long long aesl_llvm_cbe_1875_count = 0;
  static  unsigned long long aesl_llvm_cbe_1876_count = 0;
  static  unsigned long long aesl_llvm_cbe_1877_count = 0;
  static  unsigned long long aesl_llvm_cbe_1878_count = 0;
  static  unsigned long long aesl_llvm_cbe_1879_count = 0;
   char *llvm_cbe_tmp__414;
  static  unsigned long long aesl_llvm_cbe_1880_count = 0;
  unsigned char llvm_cbe_tmp__415;
  static  unsigned long long aesl_llvm_cbe_1881_count = 0;
   char *llvm_cbe_tmp__416;
  static  unsigned long long aesl_llvm_cbe_1882_count = 0;
  static  unsigned long long aesl_llvm_cbe_1883_count = 0;
  static  unsigned long long aesl_llvm_cbe_1884_count = 0;
  static  unsigned long long aesl_llvm_cbe_1885_count = 0;
  static  unsigned long long aesl_llvm_cbe_1886_count = 0;
  static  unsigned long long aesl_llvm_cbe_1887_count = 0;
  static  unsigned long long aesl_llvm_cbe_1888_count = 0;
   char *llvm_cbe_tmp__417;
  static  unsigned long long aesl_llvm_cbe_1889_count = 0;
  unsigned char llvm_cbe_tmp__418;
  static  unsigned long long aesl_llvm_cbe_1890_count = 0;
   char *llvm_cbe_tmp__419;
  static  unsigned long long aesl_llvm_cbe_1891_count = 0;
  static  unsigned long long aesl_llvm_cbe_1892_count = 0;
  static  unsigned long long aesl_llvm_cbe_1893_count = 0;
  static  unsigned long long aesl_llvm_cbe_1894_count = 0;
  static  unsigned long long aesl_llvm_cbe_1895_count = 0;
  static  unsigned long long aesl_llvm_cbe_1896_count = 0;
  static  unsigned long long aesl_llvm_cbe_1897_count = 0;
   char *llvm_cbe_tmp__420;
  static  unsigned long long aesl_llvm_cbe_1898_count = 0;
  unsigned char llvm_cbe_tmp__421;
  static  unsigned long long aesl_llvm_cbe_1899_count = 0;
   char *llvm_cbe_tmp__422;
  static  unsigned long long aesl_llvm_cbe_1900_count = 0;
  static  unsigned long long aesl_llvm_cbe_1901_count = 0;
  static  unsigned long long aesl_llvm_cbe_1902_count = 0;
  static  unsigned long long aesl_llvm_cbe_1903_count = 0;
  static  unsigned long long aesl_llvm_cbe_1904_count = 0;
  static  unsigned long long aesl_llvm_cbe_1905_count = 0;
  static  unsigned long long aesl_llvm_cbe_1906_count = 0;
   char *llvm_cbe_tmp__423;
  static  unsigned long long aesl_llvm_cbe_1907_count = 0;
  unsigned char llvm_cbe_tmp__424;
  static  unsigned long long aesl_llvm_cbe_1908_count = 0;
   char *llvm_cbe_tmp__425;
  static  unsigned long long aesl_llvm_cbe_1909_count = 0;
  static  unsigned long long aesl_llvm_cbe_1910_count = 0;
  static  unsigned long long aesl_llvm_cbe_1911_count = 0;
  static  unsigned long long aesl_llvm_cbe_1912_count = 0;
  static  unsigned long long aesl_llvm_cbe_1913_count = 0;
  static  unsigned long long aesl_llvm_cbe_1914_count = 0;
  static  unsigned long long aesl_llvm_cbe_1915_count = 0;
   char *llvm_cbe_tmp__426;
  static  unsigned long long aesl_llvm_cbe_1916_count = 0;
  unsigned char llvm_cbe_tmp__427;
  static  unsigned long long aesl_llvm_cbe_1917_count = 0;
   char *llvm_cbe_tmp__428;
  static  unsigned long long aesl_llvm_cbe_1918_count = 0;
  static  unsigned long long aesl_llvm_cbe_1919_count = 0;
  static  unsigned long long aesl_llvm_cbe_1920_count = 0;
  static  unsigned long long aesl_llvm_cbe_1921_count = 0;
  static  unsigned long long aesl_llvm_cbe_1922_count = 0;
  static  unsigned long long aesl_llvm_cbe_1923_count = 0;
  static  unsigned long long aesl_llvm_cbe_1924_count = 0;
   char *llvm_cbe_tmp__429;
  static  unsigned long long aesl_llvm_cbe_1925_count = 0;
  unsigned char llvm_cbe_tmp__430;
  static  unsigned long long aesl_llvm_cbe_1926_count = 0;
   char *llvm_cbe_tmp__431;
  static  unsigned long long aesl_llvm_cbe_1927_count = 0;
  static  unsigned long long aesl_llvm_cbe_1928_count = 0;
  static  unsigned long long aesl_llvm_cbe_1929_count = 0;
  static  unsigned long long aesl_llvm_cbe_1930_count = 0;
  static  unsigned long long aesl_llvm_cbe_1931_count = 0;
  static  unsigned long long aesl_llvm_cbe_1932_count = 0;
  static  unsigned long long aesl_llvm_cbe_1933_count = 0;
  static  unsigned long long aesl_llvm_cbe_1934_count = 0;
  unsigned int llvm_cbe_tmp__432;
  static  unsigned long long aesl_llvm_cbe_1935_count = 0;
  unsigned int llvm_cbe_tmp__433;
  static  unsigned long long aesl_llvm_cbe_1936_count = 0;
  static  unsigned long long aesl_llvm_cbe_1937_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @randombytes_sign\n");
  llvm_cbe_storemerge__PHI_TEMPORARY = (unsigned int )15u;   /* for PHI node */
  goto llvm_cbe_tmp__434;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__434:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge = phi i32 [ 15, %%0 ], [ %%9, %%8  for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_storemerge_count);
  llvm_cbe_storemerge = (unsigned int )llvm_cbe_storemerge__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge = 0x%X",llvm_cbe_storemerge);
printf("\n = 0x%X",15u);
printf("\n = 0x%X",llvm_cbe_tmp__383);
}
  if ((((signed int )llvm_cbe_storemerge) > ((signed int )4294967295u))) {
    goto llvm_cbe_tmp__435;
  } else {
    goto llvm_cbe__2e_loopexit;
  }

llvm_cbe_tmp__436:
if (AESL_DEBUG_TRACE)
printf("\n  store i8 0, i8* %%5, align 1, !dbg !14 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1777_count);
  *llvm_cbe_tmp__381 = ((unsigned char )0);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )0));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = add nsw i32 %%storemerge, -1, !dbg !14 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1778_count);
  llvm_cbe_tmp__383 = (unsigned int )((unsigned int )(llvm_cbe_storemerge&4294967295ull)) + ((unsigned int )(4294967295u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__383&4294967295ull)));
  llvm_cbe_storemerge__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__383;   /* for PHI node */
  goto llvm_cbe_tmp__434;

llvm_cbe_tmp__435:
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = sext i32 %%storemerge to i64, !dbg !13 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1772_count);
  llvm_cbe_tmp__380 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__380);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds %%struct.AES256_CTR_DRBG_struct* @DRBG_ctx, i64 0, i32 1, i64 %%4, !dbg !13 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1773_count);
  llvm_cbe_tmp__381 = ( char *)(&DRBG_ctx.field1[(((signed long long )llvm_cbe_tmp__380))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__380));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load i8* %%5, align 1, !dbg !13 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1774_count);
  llvm_cbe_tmp__382 = (unsigned char )*llvm_cbe_tmp__381;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__382);
  if (((llvm_cbe_tmp__382&255U) == (((unsigned char )-1)&255U))) {
    goto llvm_cbe_tmp__436;
  } else {
    goto llvm_cbe_tmp__437;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__437:
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = add i8 %%6, 1, !dbg !14 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1781_count);
  llvm_cbe_tmp__384 = (unsigned char )((unsigned char )(((unsigned char )(llvm_cbe_tmp__382&255ull)) + ((unsigned char )(((unsigned char )1)&255ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )(llvm_cbe_tmp__384&255ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%11, i8* %%5, align 1, !dbg !14 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1782_count);
  *llvm_cbe_tmp__381 = llvm_cbe_tmp__384;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__384);
  goto llvm_cbe__2e_loopexit;

llvm_cbe__2e_loopexit:
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds [16 x i8]* %%block, i64 0, i64 0, !dbg !14 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1784_count);
  llvm_cbe_tmp__385 = ( char *)(&llvm_cbe_block[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call fastcc void @aesl_internal_AES256_ECB(i8* getelementptr inbounds (%%struct.AES256_CTR_DRBG_struct* @DRBG_ctx, i64 0, i32 0, i64 0), i8* getelementptr inbounds (%%struct.AES256_CTR_DRBG_struct* @DRBG_ctx, i64 0, i32 1, i64 0), i8* %%12), !dbg !14 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1785_count);
  aesl_internal_AES256_ECB(( char *)((&DRBG_ctx.field0[(((signed long long )0ull))])), ( char *)((&DRBG_ctx.field1[(((signed long long )0ull))])), ( char *)llvm_cbe_tmp__385);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )0ull) < 16)) fprintf(stderr, "%s:%d: warning: Read access out of array 'block' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = load i8* %%12, align 16, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1791_count);
  llvm_cbe_tmp__386 = (unsigned char )*llvm_cbe_tmp__385;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__386);
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%13, i8* %%x, align 1, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1792_count);
  *llvm_cbe_x = llvm_cbe_tmp__386;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__386);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds [16 x i8]* %%block, i64 0, i64 1, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1798_count);
  llvm_cbe_tmp__387 = ( char *)(&llvm_cbe_block[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )1ull) < 16)) fprintf(stderr, "%s:%d: warning: Read access out of array 'block' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = load i8* %%14, align 1, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1799_count);
  llvm_cbe_tmp__388 = (unsigned char )*llvm_cbe_tmp__387;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__388);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds i8* %%x, i64 1, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1800_count);
  llvm_cbe_tmp__389 = ( char *)(&llvm_cbe_x[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%15, i8* %%16, align 1, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1801_count);
  *llvm_cbe_tmp__389 = llvm_cbe_tmp__388;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__388);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds [16 x i8]* %%block, i64 0, i64 2, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1807_count);
  llvm_cbe_tmp__390 = ( char *)(&llvm_cbe_block[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )2ull) < 16)) fprintf(stderr, "%s:%d: warning: Read access out of array 'block' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = load i8* %%17, align 2, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1808_count);
  llvm_cbe_tmp__391 = (unsigned char )*llvm_cbe_tmp__390;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__391);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = getelementptr inbounds i8* %%x, i64 2, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1809_count);
  llvm_cbe_tmp__392 = ( char *)(&llvm_cbe_x[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%18, i8* %%19, align 1, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1810_count);
  *llvm_cbe_tmp__392 = llvm_cbe_tmp__391;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__391);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = getelementptr inbounds [16 x i8]* %%block, i64 0, i64 3, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1816_count);
  llvm_cbe_tmp__393 = ( char *)(&llvm_cbe_block[(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )3ull) < 16)) fprintf(stderr, "%s:%d: warning: Read access out of array 'block' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = load i8* %%20, align 1, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1817_count);
  llvm_cbe_tmp__394 = (unsigned char )*llvm_cbe_tmp__393;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__394);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = getelementptr inbounds i8* %%x, i64 3, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1818_count);
  llvm_cbe_tmp__395 = ( char *)(&llvm_cbe_x[(((signed long long )3ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%21, i8* %%22, align 1, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1819_count);
  *llvm_cbe_tmp__395 = llvm_cbe_tmp__394;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__394);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = getelementptr inbounds [16 x i8]* %%block, i64 0, i64 4, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1825_count);
  llvm_cbe_tmp__396 = ( char *)(&llvm_cbe_block[(((signed long long )4ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )4ull) < 16)) fprintf(stderr, "%s:%d: warning: Read access out of array 'block' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = load i8* %%23, align 4, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1826_count);
  llvm_cbe_tmp__397 = (unsigned char )*llvm_cbe_tmp__396;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__397);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = getelementptr inbounds i8* %%x, i64 4, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1827_count);
  llvm_cbe_tmp__398 = ( char *)(&llvm_cbe_x[(((signed long long )4ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%24, i8* %%25, align 1, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1828_count);
  *llvm_cbe_tmp__398 = llvm_cbe_tmp__397;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__397);
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = getelementptr inbounds [16 x i8]* %%block, i64 0, i64 5, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1834_count);
  llvm_cbe_tmp__399 = ( char *)(&llvm_cbe_block[(((signed long long )5ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )5ull) < 16)) fprintf(stderr, "%s:%d: warning: Read access out of array 'block' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = load i8* %%26, align 1, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1835_count);
  llvm_cbe_tmp__400 = (unsigned char )*llvm_cbe_tmp__399;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__400);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = getelementptr inbounds i8* %%x, i64 5, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1836_count);
  llvm_cbe_tmp__401 = ( char *)(&llvm_cbe_x[(((signed long long )5ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%27, i8* %%28, align 1, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1837_count);
  *llvm_cbe_tmp__401 = llvm_cbe_tmp__400;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__400);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = getelementptr inbounds [16 x i8]* %%block, i64 0, i64 6, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1843_count);
  llvm_cbe_tmp__402 = ( char *)(&llvm_cbe_block[(((signed long long )6ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )6ull) < 16)) fprintf(stderr, "%s:%d: warning: Read access out of array 'block' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = load i8* %%29, align 2, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1844_count);
  llvm_cbe_tmp__403 = (unsigned char )*llvm_cbe_tmp__402;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__403);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = getelementptr inbounds i8* %%x, i64 6, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1845_count);
  llvm_cbe_tmp__404 = ( char *)(&llvm_cbe_x[(((signed long long )6ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%30, i8* %%31, align 1, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1846_count);
  *llvm_cbe_tmp__404 = llvm_cbe_tmp__403;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__403);
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = getelementptr inbounds [16 x i8]* %%block, i64 0, i64 7, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1852_count);
  llvm_cbe_tmp__405 = ( char *)(&llvm_cbe_block[(((signed long long )7ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )7ull) < 16)) fprintf(stderr, "%s:%d: warning: Read access out of array 'block' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = load i8* %%32, align 1, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1853_count);
  llvm_cbe_tmp__406 = (unsigned char )*llvm_cbe_tmp__405;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__406);
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = getelementptr inbounds i8* %%x, i64 7, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1854_count);
  llvm_cbe_tmp__407 = ( char *)(&llvm_cbe_x[(((signed long long )7ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%33, i8* %%34, align 1, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1855_count);
  *llvm_cbe_tmp__407 = llvm_cbe_tmp__406;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__406);
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = getelementptr inbounds [16 x i8]* %%block, i64 0, i64 8, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1861_count);
  llvm_cbe_tmp__408 = ( char *)(&llvm_cbe_block[(((signed long long )8ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )8ull) < 16)) fprintf(stderr, "%s:%d: warning: Read access out of array 'block' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = load i8* %%35, align 8, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1862_count);
  llvm_cbe_tmp__409 = (unsigned char )*llvm_cbe_tmp__408;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__409);
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = getelementptr inbounds i8* %%x, i64 8, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1863_count);
  llvm_cbe_tmp__410 = ( char *)(&llvm_cbe_x[(((signed long long )8ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%36, i8* %%37, align 1, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1864_count);
  *llvm_cbe_tmp__410 = llvm_cbe_tmp__409;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__409);
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = getelementptr inbounds [16 x i8]* %%block, i64 0, i64 9, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1870_count);
  llvm_cbe_tmp__411 = ( char *)(&llvm_cbe_block[(((signed long long )9ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )9ull) < 16)) fprintf(stderr, "%s:%d: warning: Read access out of array 'block' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = load i8* %%38, align 1, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1871_count);
  llvm_cbe_tmp__412 = (unsigned char )*llvm_cbe_tmp__411;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__412);
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = getelementptr inbounds i8* %%x, i64 9, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1872_count);
  llvm_cbe_tmp__413 = ( char *)(&llvm_cbe_x[(((signed long long )9ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%39, i8* %%40, align 1, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1873_count);
  *llvm_cbe_tmp__413 = llvm_cbe_tmp__412;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__412);
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = getelementptr inbounds [16 x i8]* %%block, i64 0, i64 10, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1879_count);
  llvm_cbe_tmp__414 = ( char *)(&llvm_cbe_block[(((signed long long )10ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )10ull) < 16)) fprintf(stderr, "%s:%d: warning: Read access out of array 'block' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = load i8* %%41, align 2, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1880_count);
  llvm_cbe_tmp__415 = (unsigned char )*llvm_cbe_tmp__414;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__415);
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = getelementptr inbounds i8* %%x, i64 10, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1881_count);
  llvm_cbe_tmp__416 = ( char *)(&llvm_cbe_x[(((signed long long )10ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%42, i8* %%43, align 1, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1882_count);
  *llvm_cbe_tmp__416 = llvm_cbe_tmp__415;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__415);
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = getelementptr inbounds [16 x i8]* %%block, i64 0, i64 11, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1888_count);
  llvm_cbe_tmp__417 = ( char *)(&llvm_cbe_block[(((signed long long )11ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )11ull) < 16)) fprintf(stderr, "%s:%d: warning: Read access out of array 'block' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = load i8* %%44, align 1, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1889_count);
  llvm_cbe_tmp__418 = (unsigned char )*llvm_cbe_tmp__417;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__418);
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = getelementptr inbounds i8* %%x, i64 11, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1890_count);
  llvm_cbe_tmp__419 = ( char *)(&llvm_cbe_x[(((signed long long )11ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%45, i8* %%46, align 1, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1891_count);
  *llvm_cbe_tmp__419 = llvm_cbe_tmp__418;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__418);
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = getelementptr inbounds [16 x i8]* %%block, i64 0, i64 12, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1897_count);
  llvm_cbe_tmp__420 = ( char *)(&llvm_cbe_block[(((signed long long )12ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )12ull) < 16)) fprintf(stderr, "%s:%d: warning: Read access out of array 'block' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = load i8* %%47, align 4, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1898_count);
  llvm_cbe_tmp__421 = (unsigned char )*llvm_cbe_tmp__420;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__421);
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = getelementptr inbounds i8* %%x, i64 12, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1899_count);
  llvm_cbe_tmp__422 = ( char *)(&llvm_cbe_x[(((signed long long )12ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%48, i8* %%49, align 1, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1900_count);
  *llvm_cbe_tmp__422 = llvm_cbe_tmp__421;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__421);
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = getelementptr inbounds [16 x i8]* %%block, i64 0, i64 13, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1906_count);
  llvm_cbe_tmp__423 = ( char *)(&llvm_cbe_block[(((signed long long )13ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )13ull) < 16)) fprintf(stderr, "%s:%d: warning: Read access out of array 'block' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = load i8* %%50, align 1, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1907_count);
  llvm_cbe_tmp__424 = (unsigned char )*llvm_cbe_tmp__423;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__424);
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = getelementptr inbounds i8* %%x, i64 13, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1908_count);
  llvm_cbe_tmp__425 = ( char *)(&llvm_cbe_x[(((signed long long )13ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%51, i8* %%52, align 1, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1909_count);
  *llvm_cbe_tmp__425 = llvm_cbe_tmp__424;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__424);
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = getelementptr inbounds [16 x i8]* %%block, i64 0, i64 14, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1915_count);
  llvm_cbe_tmp__426 = ( char *)(&llvm_cbe_block[(((signed long long )14ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )14ull) < 16)) fprintf(stderr, "%s:%d: warning: Read access out of array 'block' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = load i8* %%53, align 2, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1916_count);
  llvm_cbe_tmp__427 = (unsigned char )*llvm_cbe_tmp__426;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__427);
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = getelementptr inbounds i8* %%x, i64 14, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1917_count);
  llvm_cbe_tmp__428 = ( char *)(&llvm_cbe_x[(((signed long long )14ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%54, i8* %%55, align 1, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1918_count);
  *llvm_cbe_tmp__428 = llvm_cbe_tmp__427;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__427);
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = getelementptr inbounds [16 x i8]* %%block, i64 0, i64 15, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1924_count);
  llvm_cbe_tmp__429 = ( char *)(&llvm_cbe_block[(((signed long long )15ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )15ull) < 16)) fprintf(stderr, "%s:%d: warning: Read access out of array 'block' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = load i8* %%56, align 1, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1925_count);
  llvm_cbe_tmp__430 = (unsigned char )*llvm_cbe_tmp__429;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__430);
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = getelementptr inbounds i8* %%x, i64 15, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1926_count);
  llvm_cbe_tmp__431 = ( char *)(&llvm_cbe_x[(((signed long long )15ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%57, i8* %%58, align 1, !dbg !12 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1927_count);
  *llvm_cbe_tmp__431 = llvm_cbe_tmp__430;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__430);
if (AESL_DEBUG_TRACE)
printf("\n  call void @AES256_CTR_DRBG_Update(i8* null, i8* getelementptr inbounds (%%struct.AES256_CTR_DRBG_struct* @DRBG_ctx, i64 0, i32 0, i64 0), i8* getelementptr inbounds (%%struct.AES256_CTR_DRBG_struct* @DRBG_ctx, i64 0, i32 1, i64 0)), !dbg !15 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1933_count);
  AES256_CTR_DRBG_Update(( char *)(( char *)/*NULL*/0), ( char *)((&DRBG_ctx.field0[(((signed long long )0ull))])), ( char *)((&DRBG_ctx.field1[(((signed long long )0ull))])));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = load i32* getelementptr inbounds (%%struct.AES256_CTR_DRBG_struct* @DRBG_ctx, i64 0, i32 2), align 4, !dbg !15 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1934_count);
  llvm_cbe_tmp__432 = (unsigned int )*((&DRBG_ctx.field2));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__432);
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = add nsw i32 %%59, 1, !dbg !15 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1935_count);
  llvm_cbe_tmp__433 = (unsigned int )((unsigned int )(llvm_cbe_tmp__432&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__433&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%60, i32* getelementptr inbounds (%%struct.AES256_CTR_DRBG_struct* @DRBG_ctx, i64 0, i32 2), align 4, !dbg !15 for 0x%I64xth hint within @randombytes_sign  --> \n", ++aesl_llvm_cbe_1936_count);
  *((&DRBG_ctx.field2)) = llvm_cbe_tmp__433;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__433);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @randombytes_sign}\n");
  return 0u;
}
