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
typedef struct l_struct_OC_picnic_publickey_t l_struct_OC_picnic_publickey_t;
typedef struct l_struct_OC_picnic_privatekey_t l_struct_OC_picnic_privatekey_t;

/* Structure contents */
struct l_struct_OC_picnic_publickey_t {
  unsigned char field0;
   char field1[32];
   char field2[32];
};

struct l_struct_OC_picnic_privatekey_t {
  unsigned char field0;
   char field1[32];
  l_struct_OC_picnic_publickey_t field2;
};


/* External Global Variable Declarations */
extern unsigned char params;

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
signed int crypto_sign_keypair( char *llvm_cbe_pk,  char *llvm_cbe_sk);
signed int picnic_keygen( char , l_struct_OC_picnic_publickey_t *, l_struct_OC_picnic_privatekey_t *);
signed int picnic_write_public_key(l_struct_OC_picnic_publickey_t *,  char *, signed long long );
signed int picnic_write_private_key(l_struct_OC_picnic_privatekey_t *,  char *, signed long long );
signed int crypto_sign( char *llvm_cbe_sm, signed long long *llvm_cbe_smlen,  char *llvm_cbe_m, signed long long llvm_cbe_mlen,  char *llvm_cbe_sk);
signed int picnic_read_private_key(l_struct_OC_picnic_privatekey_t *,  char *, signed long long );
signed int picnic_sign(l_struct_OC_picnic_privatekey_t *,  char *, signed long long ,  char *, signed long long *);
static signed int aesl_internal_htole32_portable(signed int llvm_cbe_x);
signed int crypto_sign_open( char *llvm_cbe_m, signed long long *llvm_cbe_mlen,  char *llvm_cbe_sm, signed long long llvm_cbe_smlen,  char *llvm_cbe_pk);
signed int picnic_read_public_key(l_struct_OC_picnic_publickey_t *,  char *, signed long long );
static signed int aesl_internal_le32toh_portable(signed int llvm_cbe_x);
signed int picnic_verify(l_struct_OC_picnic_publickey_t *,  char *, signed long long ,  char *, signed long long );
static signed int aesl_internal_bswap32(signed int llvm_cbe_x);
static signed int aesl_internal_isBigEndianSystem(void);


/* Global Variable Definitions and Initialization */
unsigned char params = ((unsigned char )1);


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

signed int crypto_sign_keypair( char *llvm_cbe_pk,  char *llvm_cbe_sk) {
  static  unsigned long long aesl_llvm_cbe_pubkey_count = 0;
  l_struct_OC_picnic_publickey_t llvm_cbe_pubkey;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_secret_count = 0;
  l_struct_OC_picnic_privatekey_t llvm_cbe_secret;    /* Address-exposed local */
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
  unsigned char llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  unsigned int llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  unsigned int llvm_cbe_tmp__3;
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
  unsigned int llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e__count = 0;
  unsigned int llvm_cbe__2e_;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  unsigned int llvm_cbe_tmp__5;
  unsigned int llvm_cbe_tmp__5__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @crypto_sign_keypair\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = load i4* @params, align 1, !dbg !12 for 0x%I64xth hint within @crypto_sign_keypair  --> \n", ++aesl_llvm_cbe_14_count);
  llvm_cbe_tmp__1 = (unsigned char )*(&params);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = call i32 @picnic_keygen(i4 zeroext %%1, %%struct.picnic_publickey_t* %%pubkey, %%struct.picnic_privatekey_t* %%secret) nounwind, !dbg !12 for 0x%I64xth hint within @crypto_sign_keypair  --> \n", ++aesl_llvm_cbe_15_count);
  llvm_cbe_tmp__2 = (unsigned int )picnic_keygen(llvm_cbe_tmp__1, (l_struct_OC_picnic_publickey_t *)(&llvm_cbe_pubkey), (l_struct_OC_picnic_privatekey_t *)(&llvm_cbe_secret));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__1);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__2);
}
  if (((llvm_cbe_tmp__2&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__6;
  } else {
    llvm_cbe_tmp__5__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__2;   /* for PHI node */
    goto llvm_cbe_tmp__7;
  }

llvm_cbe_tmp__6:
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = call i32 @picnic_write_public_key(%%struct.picnic_publickey_t* %%pubkey, i8* %%pk, i64 33) nounwind, !dbg !8 for 0x%I64xth hint within @crypto_sign_keypair  --> \n", ++aesl_llvm_cbe_25_count);
  llvm_cbe_tmp__3 = (unsigned int )picnic_write_public_key((l_struct_OC_picnic_publickey_t *)(&llvm_cbe_pubkey), ( char *)llvm_cbe_pk, 33ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",33ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__3);
}
  if ((((signed int )llvm_cbe_tmp__3) < ((signed int )1u))) {
    llvm_cbe_tmp__5__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__3;   /* for PHI node */
    goto llvm_cbe_tmp__7;
  } else {
    goto llvm_cbe_tmp__8;
  }

llvm_cbe_tmp__8:
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = call i32 @picnic_write_private_key(%%struct.picnic_privatekey_t* %%secret, i8* %%sk, i64 49) nounwind, !dbg !9 for 0x%I64xth hint within @crypto_sign_keypair  --> \n", ++aesl_llvm_cbe_35_count);
  llvm_cbe_tmp__4 = (unsigned int )picnic_write_private_key((l_struct_OC_picnic_privatekey_t *)(&llvm_cbe_secret), ( char *)llvm_cbe_sk, 49ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",49ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__4);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%. = select i1 %%9, i32 0, i32 %%8, !dbg !12 for 0x%I64xth hint within @crypto_sign_keypair  --> \n", ++aesl_llvm_cbe__2e__count);
  llvm_cbe__2e_ = (unsigned int )(((((signed int )llvm_cbe_tmp__4) > ((signed int )0u))) ? ((unsigned int )0u) : ((unsigned int )llvm_cbe_tmp__4));
if (AESL_DEBUG_TRACE)
printf("\n. = 0x%X\n", llvm_cbe__2e_);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @crypto_sign_keypair}\n");
  return llvm_cbe__2e_;
llvm_cbe_tmp__7:
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = phi i32 [ %%2, %%0 ], [ %%5, %%4  for 0x%I64xth hint within @crypto_sign_keypair  --> \n", ++aesl_llvm_cbe_45_count);
  llvm_cbe_tmp__5 = (unsigned int )llvm_cbe_tmp__5__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__5);
printf("\n = 0x%X",llvm_cbe_tmp__2);
printf("\n = 0x%X",llvm_cbe_tmp__3);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @crypto_sign_keypair}\n");
  return llvm_cbe_tmp__5;
}


signed int crypto_sign( char *llvm_cbe_sm, signed long long *llvm_cbe_smlen,  char *llvm_cbe_m, signed long long llvm_cbe_mlen,  char *llvm_cbe_sk) {
  static  unsigned long long aesl_llvm_cbe_secret_count = 0;
  l_struct_OC_picnic_privatekey_t llvm_cbe_secret;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_signature_len_count = 0;
  signed long long llvm_cbe_signature_len;    /* Address-exposed local */
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
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  unsigned int llvm_cbe_tmp__9;
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
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_sum_count = 0;
  unsigned long long llvm_cbe__2e_sum;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
   char *llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  unsigned int llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  unsigned long long llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
  unsigned long long llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
  unsigned int llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
  unsigned int llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  unsigned long long llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
  unsigned char llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
  unsigned int llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  unsigned char llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
   char *llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  unsigned int llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  unsigned char llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
   char *llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  unsigned long long llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  unsigned char llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
   char *llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;
  static  unsigned long long aesl_llvm_cbe_152_count = 0;
  static  unsigned long long aesl_llvm_cbe_153_count = 0;
  static  unsigned long long aesl_llvm_cbe_154_count = 0;
  static  unsigned long long aesl_llvm_cbe_155_count = 0;
  unsigned long long llvm_cbe_tmp__27;
  unsigned long long llvm_cbe_tmp__27__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_156_count = 0;
   char *llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_157_count = 0;
  unsigned char llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_158_count = 0;
  unsigned int llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_159_count = 0;
  unsigned long long llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_160_count = 0;
   char *llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_161_count = 0;
  static  unsigned long long aesl_llvm_cbe_162_count = 0;
  unsigned int llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_163_count = 0;
  static  unsigned long long aesl_llvm_cbe_164_count = 0;
  static  unsigned long long aesl_llvm_cbe_165_count = 0;
  static  unsigned long long aesl_llvm_cbe_166_count = 0;
  static  unsigned long long aesl_llvm_cbe_167_count = 0;
  static  unsigned long long aesl_llvm_cbe_168_count = 0;
  unsigned long long llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_169_count = 0;
  static  unsigned long long aesl_llvm_cbe_170_count = 0;
  static  unsigned long long aesl_llvm_cbe_171_count = 0;
  static  unsigned long long aesl_llvm_cbe_172_count = 0;
  unsigned int llvm_cbe_tmp__35;
  unsigned int llvm_cbe_tmp__35__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_173_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @crypto_sign\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = call i32 @picnic_read_private_key(%%struct.picnic_privatekey_t* %%secret, i8* %%sk, i64 49) nounwind, !dbg !12 for 0x%I64xth hint within @crypto_sign  --> \n", ++aesl_llvm_cbe_67_count);
  llvm_cbe_tmp__9 = (unsigned int )picnic_read_private_key((l_struct_OC_picnic_privatekey_t *)(&llvm_cbe_secret), ( char *)llvm_cbe_sk, 49ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",49ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__9);
}
  if (((llvm_cbe_tmp__9&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__36;
  } else {
    llvm_cbe_tmp__35__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__9;   /* for PHI node */
    goto llvm_cbe_tmp__37;
  }

llvm_cbe_tmp__36:
if (AESL_DEBUG_TRACE)
printf("\n  store i64 34036, i64* %%signature_len, align 8, !dbg !13 for 0x%I64xth hint within @crypto_sign  --> \n", ++aesl_llvm_cbe_82_count);
  *(&llvm_cbe_signature_len) = 34036ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 34036ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum = add i64 %%mlen, 4, !dbg !8 for 0x%I64xth hint within @crypto_sign  --> \n", ++aesl_llvm_cbe__2e_sum_count);
  llvm_cbe__2e_sum = (unsigned long long )((unsigned long long )(llvm_cbe_mlen&18446744073709551615ull)) + ((unsigned long long )(4ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds i8* %%sm, i64 %%.sum, !dbg !8 for 0x%I64xth hint within @crypto_sign  --> \n", ++aesl_llvm_cbe_83_count);
  llvm_cbe_tmp__10 = ( char *)(&llvm_cbe_sm[(((signed long long )llvm_cbe__2e_sum))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum = 0x%I64X",((signed long long )llvm_cbe__2e_sum));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = call i32 @picnic_sign(%%struct.picnic_privatekey_t* %%secret, i8* %%m, i64 %%mlen, i8* %%4, i64* %%signature_len) nounwind, !dbg !8 for 0x%I64xth hint within @crypto_sign  --> \n", ++aesl_llvm_cbe_84_count);
  llvm_cbe_tmp__11 = (unsigned int )picnic_sign((l_struct_OC_picnic_privatekey_t *)(&llvm_cbe_secret), ( char *)llvm_cbe_m, llvm_cbe_mlen, ( char *)llvm_cbe_tmp__10, (signed long long *)(&llvm_cbe_signature_len));
if (AESL_DEBUG_TRACE) {
printf("\nArgument mlen = 0x%I64X",llvm_cbe_mlen);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__11);
}
  if (((llvm_cbe_tmp__11&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__38;
  } else {
    llvm_cbe_tmp__35__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__11;   /* for PHI node */
    goto llvm_cbe_tmp__37;
  }

llvm_cbe_tmp__38:
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load i64* %%signature_len, align 8, !dbg !13 for 0x%I64xth hint within @crypto_sign  --> \n", ++aesl_llvm_cbe_98_count);
  llvm_cbe_tmp__12 = (unsigned long long )*(&llvm_cbe_signature_len);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__12);
  if ((((unsigned long long )llvm_cbe_tmp__12&18446744073709551615ULL) > ((unsigned long long )34036ull&18446744073709551615ULL))) {
    llvm_cbe_tmp__35__PHI_TEMPORARY = (unsigned int )4294967295u;   /* for PHI node */
    goto llvm_cbe_tmp__37;
  } else {
    goto llvm_cbe_tmp__39;
  }

llvm_cbe_tmp__39:
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = add i64 %%8, %%.sum, !dbg !9 for 0x%I64xth hint within @crypto_sign  --> \n", ++aesl_llvm_cbe_102_count);
  llvm_cbe_tmp__13 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__12&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe__2e_sum&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__13&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%11, i64* %%smlen, align 8, !dbg !9 for 0x%I64xth hint within @crypto_sign  --> \n", ++aesl_llvm_cbe_103_count);
  *llvm_cbe_smlen = llvm_cbe_tmp__13;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__13);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = trunc i64 %%8 to i32, !dbg !13 for 0x%I64xth hint within @crypto_sign  --> \n", ++aesl_llvm_cbe_107_count);
  llvm_cbe_tmp__14 = (unsigned int )((unsigned int )llvm_cbe_tmp__12&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__14);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = call fastcc i32 @aesl_internal_htole32_portable(i32 %%12), !dbg !13 for 0x%I64xth hint within @crypto_sign  --> \n", ++aesl_llvm_cbe_108_count);
  llvm_cbe_tmp__15 = (unsigned int )aesl_internal_htole32_portable(llvm_cbe_tmp__14);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__14);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__15);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = zext i32 %%13 to i64, !dbg !13 for 0x%I64xth hint within @crypto_sign  --> \n", ++aesl_llvm_cbe_109_count);
  llvm_cbe_tmp__16 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__15&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__16);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = trunc i32 %%13 to i8, !dbg !8 for 0x%I64xth hint within @crypto_sign  --> \n", ++aesl_llvm_cbe_115_count);
  llvm_cbe_tmp__17 = (unsigned char )((unsigned char )llvm_cbe_tmp__15&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__17);
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%15, i8* %%sm, align 1, !dbg !8 for 0x%I64xth hint within @crypto_sign  --> \n", ++aesl_llvm_cbe_116_count);
  *llvm_cbe_sm = llvm_cbe_tmp__17;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__17);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = lshr i32 %%13, 8, !dbg !13 for 0x%I64xth hint within @crypto_sign  --> \n", ++aesl_llvm_cbe_121_count);
  llvm_cbe_tmp__18 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__15&4294967295ull)) >> ((unsigned int )(8u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__18&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = trunc i32 %%16 to i8, !dbg !9 for 0x%I64xth hint within @crypto_sign  --> \n", ++aesl_llvm_cbe_122_count);
  llvm_cbe_tmp__19 = (unsigned char )((unsigned char )llvm_cbe_tmp__18&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__19);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = getelementptr inbounds i8* %%sm, i64 1, !dbg !9 for 0x%I64xth hint within @crypto_sign  --> \n", ++aesl_llvm_cbe_123_count);
  llvm_cbe_tmp__20 = ( char *)(&llvm_cbe_sm[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%17, i8* %%18, align 1, !dbg !9 for 0x%I64xth hint within @crypto_sign  --> \n", ++aesl_llvm_cbe_124_count);
  *llvm_cbe_tmp__20 = llvm_cbe_tmp__19;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__19);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = lshr i32 %%13, 16, !dbg !14 for 0x%I64xth hint within @crypto_sign  --> \n", ++aesl_llvm_cbe_129_count);
  llvm_cbe_tmp__21 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__15&4294967295ull)) >> ((unsigned int )(16u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__21&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = trunc i32 %%19 to i8, !dbg !9 for 0x%I64xth hint within @crypto_sign  --> \n", ++aesl_llvm_cbe_130_count);
  llvm_cbe_tmp__22 = (unsigned char )((unsigned char )llvm_cbe_tmp__21&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__22);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = getelementptr inbounds i8* %%sm, i64 2, !dbg !9 for 0x%I64xth hint within @crypto_sign  --> \n", ++aesl_llvm_cbe_131_count);
  llvm_cbe_tmp__23 = ( char *)(&llvm_cbe_sm[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%20, i8* %%21, align 1, !dbg !9 for 0x%I64xth hint within @crypto_sign  --> \n", ++aesl_llvm_cbe_132_count);
  *llvm_cbe_tmp__23 = llvm_cbe_tmp__22;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__22);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = lshr i64 %%14, 24, !dbg !14 for 0x%I64xth hint within @crypto_sign  --> \n", ++aesl_llvm_cbe_136_count);
  llvm_cbe_tmp__24 = (unsigned long long )((unsigned long long )(((unsigned long long )(llvm_cbe_tmp__16&18446744073709551615ull)) >> ((unsigned long long )(24ull&18446744073709551615ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__24&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%22, i64* %%signature_len, align 8, !dbg !14 for 0x%I64xth hint within @crypto_sign  --> \n", ++aesl_llvm_cbe_143_count);
  *(&llvm_cbe_signature_len) = llvm_cbe_tmp__24;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__24);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = trunc i64 %%22 to i8, !dbg !9 for 0x%I64xth hint within @crypto_sign  --> \n", ++aesl_llvm_cbe_145_count);
  llvm_cbe_tmp__25 = (unsigned char )((unsigned char )llvm_cbe_tmp__24&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__25);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = getelementptr inbounds i8* %%sm, i64 3, !dbg !9 for 0x%I64xth hint within @crypto_sign  --> \n", ++aesl_llvm_cbe_146_count);
  llvm_cbe_tmp__26 = ( char *)(&llvm_cbe_sm[(((signed long long )3ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%23, i8* %%24, align 1, !dbg !9 for 0x%I64xth hint within @crypto_sign  --> \n", ++aesl_llvm_cbe_147_count);
  *llvm_cbe_tmp__26 = llvm_cbe_tmp__25;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__25);
  if (((llvm_cbe_mlen&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e_loopexit;
  } else {
    llvm_cbe_tmp__27__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = phi i64 [ %%33, %%.lr.ph ], [ 0, %%10  for 0x%I64xth hint within @crypto_sign  --> \n", ++aesl_llvm_cbe_155_count);
  llvm_cbe_tmp__27 = (unsigned long long )llvm_cbe_tmp__27__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__27);
printf("\n = 0x%I64X",llvm_cbe_tmp__34);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ %%32, %%.lr.ph ], [ 0, %%10  for 0x%I64xth hint within @crypto_sign  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",llvm_cbe_tmp__33);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = getelementptr inbounds i8* %%m, i64 %%26, !dbg !9 for 0x%I64xth hint within @crypto_sign  --> \n", ++aesl_llvm_cbe_156_count);
  llvm_cbe_tmp__28 = ( char *)(&llvm_cbe_m[(((signed long long )llvm_cbe_tmp__27))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__27));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = load i8* %%27, align 1, !dbg !9 for 0x%I64xth hint within @crypto_sign  --> \n", ++aesl_llvm_cbe_157_count);
  llvm_cbe_tmp__29 = (unsigned char )*llvm_cbe_tmp__28;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__29);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = add nsw i32 %%storemerge1, 4, !dbg !9 for 0x%I64xth hint within @crypto_sign  --> \n", ++aesl_llvm_cbe_158_count);
  llvm_cbe_tmp__30 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(4u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__30&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = sext i32 %%29 to i64, !dbg !9 for 0x%I64xth hint within @crypto_sign  --> \n", ++aesl_llvm_cbe_159_count);
  llvm_cbe_tmp__31 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__30);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__31);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = getelementptr inbounds i8* %%sm, i64 %%30, !dbg !9 for 0x%I64xth hint within @crypto_sign  --> \n", ++aesl_llvm_cbe_160_count);
  llvm_cbe_tmp__32 = ( char *)(&llvm_cbe_sm[(((signed long long )llvm_cbe_tmp__31))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__31));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%28, i8* %%31, align 1, !dbg !9 for 0x%I64xth hint within @crypto_sign  --> \n", ++aesl_llvm_cbe_161_count);
  *llvm_cbe_tmp__32 = llvm_cbe_tmp__29;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__29);
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = add nsw i32 %%storemerge1, 1, !dbg !14 for 0x%I64xth hint within @crypto_sign  --> \n", ++aesl_llvm_cbe_162_count);
  llvm_cbe_tmp__33 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__33&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = sext i32 %%32 to i64, !dbg !10 for 0x%I64xth hint within @crypto_sign  --> \n", ++aesl_llvm_cbe_168_count);
  llvm_cbe_tmp__34 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__33);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__34);
  if ((((unsigned long long )llvm_cbe_tmp__34&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_mlen&18446744073709551615ULL))) {
    llvm_cbe_tmp__27__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__34;   /* for PHI node */
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__33;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e_loopexit;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e_loopexit:
  llvm_cbe_tmp__35__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__37;

llvm_cbe_tmp__37:
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = phi i32 [ %%1, %%0 ], [ %%5, %%3 ], [ -1, %%7 ], [ 0, %%.loopexit  for 0x%I64xth hint within @crypto_sign  --> \n", ++aesl_llvm_cbe_172_count);
  llvm_cbe_tmp__35 = (unsigned int )llvm_cbe_tmp__35__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__35);
printf("\n = 0x%X",llvm_cbe_tmp__9);
printf("\n = 0x%X",llvm_cbe_tmp__11);
printf("\n = 0x%X",4294967295u);
printf("\n = 0x%X",0u);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @crypto_sign}\n");
  return llvm_cbe_tmp__35;
}


static signed int aesl_internal_htole32_portable(signed int llvm_cbe_x) {
  static  unsigned long long aesl_llvm_cbe_174_count = 0;
  static  unsigned long long aesl_llvm_cbe_175_count = 0;
  static  unsigned long long aesl_llvm_cbe_176_count = 0;
  static  unsigned long long aesl_llvm_cbe_177_count = 0;
  unsigned int llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_178_count = 0;
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
  static  unsigned long long aesl_llvm_cbe_180_count = 0;
  unsigned int llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_181_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge_count = 0;
  unsigned int llvm_cbe_storemerge;
  unsigned int llvm_cbe_storemerge__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_182_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @aesl_internal_htole32_portable\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = tail call fastcc i32 @aesl_internal_isBigEndianSystem(), !dbg !9 for 0x%I64xth hint within @aesl_internal_htole32_portable  --> \n", ++aesl_llvm_cbe_177_count);
  llvm_cbe_tmp__40 = (unsigned int ) /*tail*/ aesl_internal_isBigEndianSystem();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__40);
}
  if (((llvm_cbe_tmp__40&4294967295U) == (0u&4294967295U))) {
    llvm_cbe_storemerge__PHI_TEMPORARY = (unsigned int )llvm_cbe_x;   /* for PHI node */
    goto llvm_cbe_tmp__42;
  } else {
    goto llvm_cbe_tmp__43;
  }

llvm_cbe_tmp__43:
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = tail call fastcc i32 @aesl_internal_bswap32(i32 %%x), !dbg !8 for 0x%I64xth hint within @aesl_internal_htole32_portable  --> \n", ++aesl_llvm_cbe_180_count);
  llvm_cbe_tmp__41 = (unsigned int ) /*tail*/ aesl_internal_bswap32(llvm_cbe_x);
if (AESL_DEBUG_TRACE) {
printf("\nArgument x = 0x%X",llvm_cbe_x);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__41);
}
  llvm_cbe_storemerge__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__41;   /* for PHI node */
  goto llvm_cbe_tmp__42;

llvm_cbe_tmp__42:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge = phi i32 [ %%4, %%3 ], [ %%x, %%0  for 0x%I64xth hint within @aesl_internal_htole32_portable  --> \n", ++aesl_llvm_cbe_storemerge_count);
  llvm_cbe_storemerge = (unsigned int )llvm_cbe_storemerge__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge = 0x%X",llvm_cbe_storemerge);
printf("\n = 0x%X",llvm_cbe_tmp__41);
printf("\nx = 0x%X",llvm_cbe_x);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @aesl_internal_htole32_portable}\n");
  return llvm_cbe_storemerge;
}


signed int crypto_sign_open( char *llvm_cbe_m, signed long long *llvm_cbe_mlen,  char *llvm_cbe_sm, signed long long llvm_cbe_smlen,  char *llvm_cbe_pk) {
  static  unsigned long long aesl_llvm_cbe_pubkey_count = 0;
  l_struct_OC_picnic_publickey_t llvm_cbe_pubkey[1];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_183_count = 0;
  static  unsigned long long aesl_llvm_cbe_184_count = 0;
  static  unsigned long long aesl_llvm_cbe_185_count = 0;
  static  unsigned long long aesl_llvm_cbe_186_count = 0;
  static  unsigned long long aesl_llvm_cbe_187_count = 0;
  static  unsigned long long aesl_llvm_cbe_188_count = 0;
  static  unsigned long long aesl_llvm_cbe_189_count = 0;
  static  unsigned long long aesl_llvm_cbe_190_count = 0;
  static  unsigned long long aesl_llvm_cbe_191_count = 0;
  static  unsigned long long aesl_llvm_cbe_192_count = 0;
  static  unsigned long long aesl_llvm_cbe_193_count = 0;
  static  unsigned long long aesl_llvm_cbe_194_count = 0;
  static  unsigned long long aesl_llvm_cbe_195_count = 0;
  static  unsigned long long aesl_llvm_cbe_196_count = 0;
  static  unsigned long long aesl_llvm_cbe_197_count = 0;
  static  unsigned long long aesl_llvm_cbe_198_count = 0;
  static  unsigned long long aesl_llvm_cbe_199_count = 0;
  static  unsigned long long aesl_llvm_cbe_200_count = 0;
  l_struct_OC_picnic_publickey_t *llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_201_count = 0;
  static  unsigned long long aesl_llvm_cbe_202_count = 0;
  unsigned int llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_203_count = 0;
  static  unsigned long long aesl_llvm_cbe_204_count = 0;
  static  unsigned long long aesl_llvm_cbe_205_count = 0;
  static  unsigned long long aesl_llvm_cbe_206_count = 0;
  static  unsigned long long aesl_llvm_cbe_207_count = 0;
   char *llvm_cbe_tmp__46;
  static  unsigned long long aesl_llvm_cbe_208_count = 0;
  unsigned char llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe_209_count = 0;
  unsigned int llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_210_count = 0;
  unsigned int llvm_cbe_tmp__49;
  static  unsigned long long aesl_llvm_cbe_211_count = 0;
   char *llvm_cbe_tmp__50;
  static  unsigned long long aesl_llvm_cbe_212_count = 0;
  unsigned char llvm_cbe_tmp__51;
  static  unsigned long long aesl_llvm_cbe_213_count = 0;
  unsigned int llvm_cbe_tmp__52;
  static  unsigned long long aesl_llvm_cbe_214_count = 0;
  unsigned int llvm_cbe_tmp__53;
  static  unsigned long long aesl_llvm_cbe_215_count = 0;
   char *llvm_cbe_tmp__54;
  static  unsigned long long aesl_llvm_cbe_216_count = 0;
  unsigned char llvm_cbe_tmp__55;
  static  unsigned long long aesl_llvm_cbe_217_count = 0;
  unsigned int llvm_cbe_tmp__56;
  static  unsigned long long aesl_llvm_cbe_218_count = 0;
  unsigned int llvm_cbe_tmp__57;
  static  unsigned long long aesl_llvm_cbe_219_count = 0;
  unsigned char llvm_cbe_tmp__58;
  static  unsigned long long aesl_llvm_cbe_220_count = 0;
  unsigned int llvm_cbe_tmp__59;
  static  unsigned long long aesl_llvm_cbe_221_count = 0;
  unsigned int llvm_cbe_tmp__60;
  static  unsigned long long aesl_llvm_cbe_222_count = 0;
  unsigned int llvm_cbe_tmp__61;
  static  unsigned long long aesl_llvm_cbe_223_count = 0;
  unsigned int llvm_cbe_tmp__62;
  static  unsigned long long aesl_llvm_cbe_224_count = 0;
  static  unsigned long long aesl_llvm_cbe_225_count = 0;
  static  unsigned long long aesl_llvm_cbe_226_count = 0;
  static  unsigned long long aesl_llvm_cbe_227_count = 0;
  static  unsigned long long aesl_llvm_cbe_228_count = 0;
  static  unsigned long long aesl_llvm_cbe_229_count = 0;
  unsigned int llvm_cbe_tmp__63;
  static  unsigned long long aesl_llvm_cbe_230_count = 0;
  static  unsigned long long aesl_llvm_cbe_231_count = 0;
  static  unsigned long long aesl_llvm_cbe_232_count = 0;
  static  unsigned long long aesl_llvm_cbe_233_count = 0;
  static  unsigned long long aesl_llvm_cbe_234_count = 0;
  static  unsigned long long aesl_llvm_cbe_235_count = 0;
  unsigned long long llvm_cbe_tmp__64;
  static  unsigned long long aesl_llvm_cbe_236_count = 0;
  unsigned long long llvm_cbe_tmp__65;
  static  unsigned long long aesl_llvm_cbe_237_count = 0;
  static  unsigned long long aesl_llvm_cbe_238_count = 0;
  static  unsigned long long aesl_llvm_cbe_239_count = 0;
  unsigned long long llvm_cbe_tmp__66;
  static  unsigned long long aesl_llvm_cbe_240_count = 0;
  unsigned long long llvm_cbe_tmp__67;
  static  unsigned long long aesl_llvm_cbe_241_count = 0;
  static  unsigned long long aesl_llvm_cbe_242_count = 0;
  static  unsigned long long aesl_llvm_cbe_243_count = 0;
  static  unsigned long long aesl_llvm_cbe_244_count = 0;
  static  unsigned long long aesl_llvm_cbe_245_count = 0;
  static  unsigned long long aesl_llvm_cbe_246_count = 0;
   char *llvm_cbe_tmp__68;
  static  unsigned long long aesl_llvm_cbe_247_count = 0;
   char *llvm_cbe_tmp__69;
  static  unsigned long long aesl_llvm_cbe_248_count = 0;
  unsigned int llvm_cbe_tmp__70;
  static  unsigned long long aesl_llvm_cbe_249_count = 0;
  static  unsigned long long aesl_llvm_cbe_250_count = 0;
  static  unsigned long long aesl_llvm_cbe_251_count = 0;
  static  unsigned long long aesl_llvm_cbe_252_count = 0;
  static  unsigned long long aesl_llvm_cbe_253_count = 0;
  static  unsigned long long aesl_llvm_cbe_254_count = 0;
  static  unsigned long long aesl_llvm_cbe_255_count = 0;
  static  unsigned long long aesl_llvm_cbe_256_count = 0;
  static  unsigned long long aesl_llvm_cbe_257_count = 0;
  static  unsigned long long aesl_llvm_cbe_258_count = 0;
  static  unsigned long long aesl_llvm_cbe_259_count = 0;
  unsigned long long llvm_cbe_tmp__71;
  unsigned long long llvm_cbe_tmp__71__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_260_count = 0;
  unsigned int llvm_cbe_tmp__72;
  static  unsigned long long aesl_llvm_cbe_261_count = 0;
  unsigned long long llvm_cbe_tmp__73;
  static  unsigned long long aesl_llvm_cbe_262_count = 0;
   char *llvm_cbe_tmp__74;
  static  unsigned long long aesl_llvm_cbe_263_count = 0;
  unsigned char llvm_cbe_tmp__75;
  static  unsigned long long aesl_llvm_cbe_264_count = 0;
   char *llvm_cbe_tmp__76;
  static  unsigned long long aesl_llvm_cbe_265_count = 0;
  static  unsigned long long aesl_llvm_cbe_266_count = 0;
  unsigned int llvm_cbe_tmp__77;
  static  unsigned long long aesl_llvm_cbe_267_count = 0;
  static  unsigned long long aesl_llvm_cbe_268_count = 0;
  static  unsigned long long aesl_llvm_cbe_269_count = 0;
  static  unsigned long long aesl_llvm_cbe_270_count = 0;
  static  unsigned long long aesl_llvm_cbe_271_count = 0;
  static  unsigned long long aesl_llvm_cbe_272_count = 0;
  unsigned long long llvm_cbe_tmp__78;
  static  unsigned long long aesl_llvm_cbe_273_count = 0;
  static  unsigned long long aesl_llvm_cbe_274_count = 0;
  static  unsigned long long aesl_llvm_cbe_275_count = 0;
  static  unsigned long long aesl_llvm_cbe_276_count = 0;
  static  unsigned long long aesl_llvm_cbe_277_count = 0;
  unsigned int llvm_cbe_tmp__79;
  unsigned int llvm_cbe_tmp__79__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_278_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @crypto_sign_open\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds [1 x %%struct.picnic_publickey_t]* %%pubkey, i64 0, i64 0, !dbg !11 for 0x%I64xth hint within @crypto_sign_open  --> \n", ++aesl_llvm_cbe_200_count);
  llvm_cbe_tmp__44 = (l_struct_OC_picnic_publickey_t *)(&llvm_cbe_pubkey[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = call i32 @picnic_read_public_key(%%struct.picnic_publickey_t* %%1, i8* %%pk, i64 33) nounwind, !dbg !11 for 0x%I64xth hint within @crypto_sign_open  --> \n", ++aesl_llvm_cbe_202_count);
  llvm_cbe_tmp__45 = (unsigned int )picnic_read_public_key((l_struct_OC_picnic_publickey_t *)llvm_cbe_tmp__44, ( char *)llvm_cbe_pk, 33ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",33ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__45);
}
  if (((llvm_cbe_tmp__45&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__80;
  } else {
    llvm_cbe_tmp__79__PHI_TEMPORARY = (unsigned int )4294967294u;   /* for PHI node */
    goto llvm_cbe_tmp__81;
  }

llvm_cbe_tmp__80:
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds i8* %%sm, i64 3, !dbg !9 for 0x%I64xth hint within @crypto_sign_open  --> \n", ++aesl_llvm_cbe_207_count);
  llvm_cbe_tmp__46 = ( char *)(&llvm_cbe_sm[(((signed long long )3ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load i8* %%5, align 1, !dbg !9 for 0x%I64xth hint within @crypto_sign_open  --> \n", ++aesl_llvm_cbe_208_count);
  llvm_cbe_tmp__47 = (unsigned char )*llvm_cbe_tmp__46;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__47);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = zext i8 %%6 to i32, !dbg !9 for 0x%I64xth hint within @crypto_sign_open  --> \n", ++aesl_llvm_cbe_209_count);
  llvm_cbe_tmp__48 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__47&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__48);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = shl nuw i32 %%7, 24, !dbg !9 for 0x%I64xth hint within @crypto_sign_open  --> \n", ++aesl_llvm_cbe_210_count);
  llvm_cbe_tmp__49 = (unsigned int )llvm_cbe_tmp__48 << 24u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__49);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds i8* %%sm, i64 2, !dbg !9 for 0x%I64xth hint within @crypto_sign_open  --> \n", ++aesl_llvm_cbe_211_count);
  llvm_cbe_tmp__50 = ( char *)(&llvm_cbe_sm[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = load i8* %%9, align 1, !dbg !9 for 0x%I64xth hint within @crypto_sign_open  --> \n", ++aesl_llvm_cbe_212_count);
  llvm_cbe_tmp__51 = (unsigned char )*llvm_cbe_tmp__50;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__51);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = zext i8 %%10 to i32, !dbg !9 for 0x%I64xth hint within @crypto_sign_open  --> \n", ++aesl_llvm_cbe_213_count);
  llvm_cbe_tmp__52 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__51&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__52);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = shl nuw nsw i32 %%11, 16, !dbg !9 for 0x%I64xth hint within @crypto_sign_open  --> \n", ++aesl_llvm_cbe_214_count);
  llvm_cbe_tmp__53 = (unsigned int )llvm_cbe_tmp__52 << 16u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__53);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds i8* %%sm, i64 1, !dbg !9 for 0x%I64xth hint within @crypto_sign_open  --> \n", ++aesl_llvm_cbe_215_count);
  llvm_cbe_tmp__54 = ( char *)(&llvm_cbe_sm[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load i8* %%13, align 1, !dbg !9 for 0x%I64xth hint within @crypto_sign_open  --> \n", ++aesl_llvm_cbe_216_count);
  llvm_cbe_tmp__55 = (unsigned char )*llvm_cbe_tmp__54;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__55);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = zext i8 %%14 to i32, !dbg !9 for 0x%I64xth hint within @crypto_sign_open  --> \n", ++aesl_llvm_cbe_217_count);
  llvm_cbe_tmp__56 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__55&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__56);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = shl nuw nsw i32 %%15, 8, !dbg !9 for 0x%I64xth hint within @crypto_sign_open  --> \n", ++aesl_llvm_cbe_218_count);
  llvm_cbe_tmp__57 = (unsigned int )llvm_cbe_tmp__56 << 8u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__57);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = load i8* %%sm, align 1, !dbg !9 for 0x%I64xth hint within @crypto_sign_open  --> \n", ++aesl_llvm_cbe_219_count);
  llvm_cbe_tmp__58 = (unsigned char )*llvm_cbe_sm;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__58);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = zext i8 %%17 to i32, !dbg !9 for 0x%I64xth hint within @crypto_sign_open  --> \n", ++aesl_llvm_cbe_220_count);
  llvm_cbe_tmp__59 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__58&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__59);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = or i32 %%12, %%8, !dbg !9 for 0x%I64xth hint within @crypto_sign_open  --> \n", ++aesl_llvm_cbe_221_count);
  llvm_cbe_tmp__60 = (unsigned int )llvm_cbe_tmp__53 | llvm_cbe_tmp__49;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__60);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = or i32 %%19, %%18, !dbg !9 for 0x%I64xth hint within @crypto_sign_open  --> \n", ++aesl_llvm_cbe_222_count);
  llvm_cbe_tmp__61 = (unsigned int )llvm_cbe_tmp__60 | llvm_cbe_tmp__59;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__61);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = or i32 %%20, %%16, !dbg !9 for 0x%I64xth hint within @crypto_sign_open  --> \n", ++aesl_llvm_cbe_223_count);
  llvm_cbe_tmp__62 = (unsigned int )llvm_cbe_tmp__61 | llvm_cbe_tmp__57;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__62);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = call fastcc i32 @aesl_internal_le32toh_portable(i32 %%21), !dbg !12 for 0x%I64xth hint within @crypto_sign_open  --> \n", ++aesl_llvm_cbe_229_count);
  llvm_cbe_tmp__63 = (unsigned int )aesl_internal_le32toh_portable(llvm_cbe_tmp__62);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__62);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__63);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = zext i32 %%22 to i64, !dbg !9 for 0x%I64xth hint within @crypto_sign_open  --> \n", ++aesl_llvm_cbe_235_count);
  llvm_cbe_tmp__64 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__63&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__64);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = add i64 %%smlen, -5, !dbg !9 for 0x%I64xth hint within @crypto_sign_open  --> \n", ++aesl_llvm_cbe_236_count);
  llvm_cbe_tmp__65 = (unsigned long long )((unsigned long long )(llvm_cbe_smlen&18446744073709551615ull)) + ((unsigned long long )(18446744073709551611ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__65&18446744073709551615ull)));
  if ((((unsigned long long )llvm_cbe_tmp__64&18446744073709551615ULL) > ((unsigned long long )llvm_cbe_tmp__65&18446744073709551615ULL))) {
    llvm_cbe_tmp__79__PHI_TEMPORARY = (unsigned int )4294967294u;   /* for PHI node */
    goto llvm_cbe_tmp__81;
  } else {
    goto llvm_cbe_tmp__82;
  }

llvm_cbe_tmp__82:
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = sub i64 %%smlen, %%23, !dbg !10 for 0x%I64xth hint within @crypto_sign_open  --> \n", ++aesl_llvm_cbe_239_count);
  llvm_cbe_tmp__66 = (unsigned long long )((unsigned long long )(llvm_cbe_smlen&18446744073709551615ull)) - ((unsigned long long )(llvm_cbe_tmp__64&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__66&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = add i64 %%27, -4, !dbg !10 for 0x%I64xth hint within @crypto_sign_open  --> \n", ++aesl_llvm_cbe_240_count);
  llvm_cbe_tmp__67 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__66&18446744073709551615ull)) + ((unsigned long long )(18446744073709551612ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__67&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = getelementptr inbounds i8* %%sm, i64 4, !dbg !9 for 0x%I64xth hint within @crypto_sign_open  --> \n", ++aesl_llvm_cbe_246_count);
  llvm_cbe_tmp__68 = ( char *)(&llvm_cbe_sm[(((signed long long )4ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = getelementptr inbounds i8* %%sm, i64 %%27, !dbg !9 for 0x%I64xth hint within @crypto_sign_open  --> \n", ++aesl_llvm_cbe_247_count);
  llvm_cbe_tmp__69 = ( char *)(&llvm_cbe_sm[(((signed long long )llvm_cbe_tmp__66))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__66));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = call i32 @picnic_verify(%%struct.picnic_publickey_t* %%1, i8* %%29, i64 %%28, i8* %%30, i64 %%23) nounwind, !dbg !9 for 0x%I64xth hint within @crypto_sign_open  --> \n", ++aesl_llvm_cbe_248_count);
  llvm_cbe_tmp__70 = (unsigned int )picnic_verify((l_struct_OC_picnic_publickey_t *)llvm_cbe_tmp__44, ( char *)llvm_cbe_tmp__68, llvm_cbe_tmp__67, ( char *)llvm_cbe_tmp__69, llvm_cbe_tmp__64);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__67);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__64);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__70);
}
  if (((llvm_cbe_tmp__70&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe__2e_preheader;
  } else {
    llvm_cbe_tmp__79__PHI_TEMPORARY = (unsigned int )4294967295u;   /* for PHI node */
    goto llvm_cbe_tmp__81;
  }

llvm_cbe__2e_preheader:
  if (((llvm_cbe_tmp__67&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_tmp__71__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = phi i64 [ %%41, %%.lr.ph ], [ 0, %%.preheader  for 0x%I64xth hint within @crypto_sign_open  --> \n", ++aesl_llvm_cbe_259_count);
  llvm_cbe_tmp__71 = (unsigned long long )llvm_cbe_tmp__71__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__71);
printf("\n = 0x%I64X",llvm_cbe_tmp__78);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ %%40, %%.lr.ph ], [ 0, %%.preheader  for 0x%I64xth hint within @crypto_sign_open  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",llvm_cbe_tmp__77);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = add nsw i32 %%storemerge1, 4, !dbg !8 for 0x%I64xth hint within @crypto_sign_open  --> \n", ++aesl_llvm_cbe_260_count);
  llvm_cbe_tmp__72 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(4u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__72&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = sext i32 %%35 to i64, !dbg !8 for 0x%I64xth hint within @crypto_sign_open  --> \n", ++aesl_llvm_cbe_261_count);
  llvm_cbe_tmp__73 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__72);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__73);
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = getelementptr inbounds i8* %%sm, i64 %%36, !dbg !8 for 0x%I64xth hint within @crypto_sign_open  --> \n", ++aesl_llvm_cbe_262_count);
  llvm_cbe_tmp__74 = ( char *)(&llvm_cbe_sm[(((signed long long )llvm_cbe_tmp__73))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__73));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = load i8* %%37, align 1, !dbg !8 for 0x%I64xth hint within @crypto_sign_open  --> \n", ++aesl_llvm_cbe_263_count);
  llvm_cbe_tmp__75 = (unsigned char )*llvm_cbe_tmp__74;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__75);
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = getelementptr inbounds i8* %%m, i64 %%34, !dbg !8 for 0x%I64xth hint within @crypto_sign_open  --> \n", ++aesl_llvm_cbe_264_count);
  llvm_cbe_tmp__76 = ( char *)(&llvm_cbe_m[(((signed long long )llvm_cbe_tmp__71))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__71));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%38, i8* %%39, align 1, !dbg !8 for 0x%I64xth hint within @crypto_sign_open  --> \n", ++aesl_llvm_cbe_265_count);
  *llvm_cbe_tmp__76 = llvm_cbe_tmp__75;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__75);
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = add nsw i32 %%storemerge1, 1, !dbg !13 for 0x%I64xth hint within @crypto_sign_open  --> \n", ++aesl_llvm_cbe_266_count);
  llvm_cbe_tmp__77 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__77&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = sext i32 %%40 to i64, !dbg !12 for 0x%I64xth hint within @crypto_sign_open  --> \n", ++aesl_llvm_cbe_272_count);
  llvm_cbe_tmp__78 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__77);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__78);
  if ((((unsigned long long )llvm_cbe_tmp__78&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__67&18446744073709551615ULL))) {
    llvm_cbe_tmp__71__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__78;   /* for PHI node */
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__77;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%28, i64* %%mlen, align 8, !dbg !9 for 0x%I64xth hint within @crypto_sign_open  --> \n", ++aesl_llvm_cbe_275_count);
  *llvm_cbe_mlen = llvm_cbe_tmp__67;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__67);
  llvm_cbe_tmp__79__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__81;

llvm_cbe_tmp__81:
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = phi i32 [ 0, %%._crit_edge ], [ -2, %%0 ], [ -2, %%4 ], [ -1, %%26  for 0x%I64xth hint within @crypto_sign_open  --> \n", ++aesl_llvm_cbe_277_count);
  llvm_cbe_tmp__79 = (unsigned int )llvm_cbe_tmp__79__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__79);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",4294967294u);
printf("\n = 0x%X",4294967294u);
printf("\n = 0x%X",4294967295u);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @crypto_sign_open}\n");
  return llvm_cbe_tmp__79;
}


static signed int aesl_internal_le32toh_portable(signed int llvm_cbe_x) {
  static  unsigned long long aesl_llvm_cbe_279_count = 0;
  static  unsigned long long aesl_llvm_cbe_280_count = 0;
  static  unsigned long long aesl_llvm_cbe_281_count = 0;
  static  unsigned long long aesl_llvm_cbe_282_count = 0;
  unsigned int llvm_cbe_tmp__83;
  static  unsigned long long aesl_llvm_cbe_283_count = 0;
  static  unsigned long long aesl_llvm_cbe_284_count = 0;
  static  unsigned long long aesl_llvm_cbe_285_count = 0;
  unsigned int llvm_cbe_tmp__84;
  static  unsigned long long aesl_llvm_cbe_286_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge_count = 0;
  unsigned int llvm_cbe_storemerge;
  unsigned int llvm_cbe_storemerge__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_287_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @aesl_internal_le32toh_portable\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = tail call fastcc i32 @aesl_internal_isBigEndianSystem(), !dbg !9 for 0x%I64xth hint within @aesl_internal_le32toh_portable  --> \n", ++aesl_llvm_cbe_282_count);
  llvm_cbe_tmp__83 = (unsigned int ) /*tail*/ aesl_internal_isBigEndianSystem();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__83);
}
  if (((llvm_cbe_tmp__83&4294967295U) == (0u&4294967295U))) {
    llvm_cbe_storemerge__PHI_TEMPORARY = (unsigned int )llvm_cbe_x;   /* for PHI node */
    goto llvm_cbe_tmp__85;
  } else {
    goto llvm_cbe_tmp__86;
  }

llvm_cbe_tmp__86:
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = tail call fastcc i32 @aesl_internal_bswap32(i32 %%x), !dbg !8 for 0x%I64xth hint within @aesl_internal_le32toh_portable  --> \n", ++aesl_llvm_cbe_285_count);
  llvm_cbe_tmp__84 = (unsigned int ) /*tail*/ aesl_internal_bswap32(llvm_cbe_x);
if (AESL_DEBUG_TRACE) {
printf("\nArgument x = 0x%X",llvm_cbe_x);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__84);
}
  llvm_cbe_storemerge__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__84;   /* for PHI node */
  goto llvm_cbe_tmp__85;

llvm_cbe_tmp__85:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge = phi i32 [ %%4, %%3 ], [ %%x, %%0  for 0x%I64xth hint within @aesl_internal_le32toh_portable  --> \n", ++aesl_llvm_cbe_storemerge_count);
  llvm_cbe_storemerge = (unsigned int )llvm_cbe_storemerge__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge = 0x%X",llvm_cbe_storemerge);
printf("\n = 0x%X",llvm_cbe_tmp__84);
printf("\nx = 0x%X",llvm_cbe_x);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @aesl_internal_le32toh_portable}\n");
  return llvm_cbe_storemerge;
}


static signed int aesl_internal_bswap32(signed int llvm_cbe_x) {
  static  unsigned long long aesl_llvm_cbe_288_count = 0;
  static  unsigned long long aesl_llvm_cbe_289_count = 0;
  static  unsigned long long aesl_llvm_cbe_290_count = 0;
  static  unsigned long long aesl_llvm_cbe_291_count = 0;
  static  unsigned long long aesl_llvm_cbe_292_count = 0;
  static  unsigned long long aesl_llvm_cbe_bswap_2e_4_count = 0;
  unsigned int llvm_cbe_bswap_2e_4;
  static  unsigned long long aesl_llvm_cbe_bswap_2e_3_count = 0;
  unsigned int llvm_cbe_bswap_2e_3;
  static  unsigned long long aesl_llvm_cbe_bswap_2e_2_count = 0;
  unsigned int llvm_cbe_bswap_2e_2;
  static  unsigned long long aesl_llvm_cbe_bswap_2e_1_count = 0;
  unsigned int llvm_cbe_bswap_2e_1;
  static  unsigned long long aesl_llvm_cbe_bswap_2e_and3_count = 0;
  unsigned int llvm_cbe_bswap_2e_and3;
  static  unsigned long long aesl_llvm_cbe_bswap_2e_and2_count = 0;
  unsigned int llvm_cbe_bswap_2e_and2;
  static  unsigned long long aesl_llvm_cbe_bswap_2e_or1_count = 0;
  unsigned int llvm_cbe_bswap_2e_or1;
  static  unsigned long long aesl_llvm_cbe_bswap_2e_or2_count = 0;
  unsigned int llvm_cbe_bswap_2e_or2;
  static  unsigned long long aesl_llvm_cbe_bswap_2e_i32_count = 0;
  unsigned int llvm_cbe_bswap_2e_i32;
  static  unsigned long long aesl_llvm_cbe_293_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @aesl_internal_bswap32\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%bswap.4 = shl i32 %%x, 2 for 0x%I64xth hint within @aesl_internal_bswap32  --> \n", ++aesl_llvm_cbe_bswap_2e_4_count);
  llvm_cbe_bswap_2e_4 = (unsigned int )llvm_cbe_x << 24u;
if (AESL_DEBUG_TRACE)
printf("\nbswap.4 = 0x%X\n", llvm_cbe_bswap_2e_4);
if (AESL_DEBUG_TRACE)
printf("\n  %%bswap.3 = shl i32 %%x,  for 0x%I64xth hint within @aesl_internal_bswap32  --> \n", ++aesl_llvm_cbe_bswap_2e_3_count);
  llvm_cbe_bswap_2e_3 = (unsigned int )llvm_cbe_x << 8u;
if (AESL_DEBUG_TRACE)
printf("\nbswap.3 = 0x%X\n", llvm_cbe_bswap_2e_3);
if (AESL_DEBUG_TRACE)
printf("\n  %%bswap.2 = lshr i32 %%x,  for 0x%I64xth hint within @aesl_internal_bswap32  --> \n", ++aesl_llvm_cbe_bswap_2e_2_count);
  llvm_cbe_bswap_2e_2 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_x&4294967295ull)) >> ((unsigned int )(8u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\nbswap.2 = 0x%X\n", ((unsigned int )(llvm_cbe_bswap_2e_2&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%bswap.1 = lshr i32 %%x, 2 for 0x%I64xth hint within @aesl_internal_bswap32  --> \n", ++aesl_llvm_cbe_bswap_2e_1_count);
  llvm_cbe_bswap_2e_1 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_x&4294967295ull)) >> ((unsigned int )(24u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\nbswap.1 = 0x%X\n", ((unsigned int )(llvm_cbe_bswap_2e_1&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%bswap.and3 = and i32 %%bswap.3, 1671168 for 0x%I64xth hint within @aesl_internal_bswap32  --> \n", ++aesl_llvm_cbe_bswap_2e_and3_count);
  llvm_cbe_bswap_2e_and3 = (unsigned int )llvm_cbe_bswap_2e_3 & 16711680u;
if (AESL_DEBUG_TRACE)
printf("\nbswap.and3 = 0x%X\n", llvm_cbe_bswap_2e_and3);
if (AESL_DEBUG_TRACE)
printf("\n  %%bswap.and2 = and i32 %%bswap.2, 6528 for 0x%I64xth hint within @aesl_internal_bswap32  --> \n", ++aesl_llvm_cbe_bswap_2e_and2_count);
  llvm_cbe_bswap_2e_and2 = (unsigned int )llvm_cbe_bswap_2e_2 & 65280u;
if (AESL_DEBUG_TRACE)
printf("\nbswap.and2 = 0x%X\n", llvm_cbe_bswap_2e_and2);
if (AESL_DEBUG_TRACE)
printf("\n  %%bswap.or1 = or i32 %%bswap.4, %%bswap.and for 0x%I64xth hint within @aesl_internal_bswap32  --> \n", ++aesl_llvm_cbe_bswap_2e_or1_count);
  llvm_cbe_bswap_2e_or1 = (unsigned int )llvm_cbe_bswap_2e_4 | llvm_cbe_bswap_2e_and3;
if (AESL_DEBUG_TRACE)
printf("\nbswap.or1 = 0x%X\n", llvm_cbe_bswap_2e_or1);
if (AESL_DEBUG_TRACE)
printf("\n  %%bswap.or2 = or i32 %%bswap.and2, %%bswap. for 0x%I64xth hint within @aesl_internal_bswap32  --> \n", ++aesl_llvm_cbe_bswap_2e_or2_count);
  llvm_cbe_bswap_2e_or2 = (unsigned int )llvm_cbe_bswap_2e_and2 | llvm_cbe_bswap_2e_1;
if (AESL_DEBUG_TRACE)
printf("\nbswap.or2 = 0x%X\n", llvm_cbe_bswap_2e_or2);
if (AESL_DEBUG_TRACE)
printf("\n  %%bswap.i32 = or i32 %%bswap.or1, %%bswap.or for 0x%I64xth hint within @aesl_internal_bswap32  --> \n", ++aesl_llvm_cbe_bswap_2e_i32_count);
  llvm_cbe_bswap_2e_i32 = (unsigned int )llvm_cbe_bswap_2e_or1 | llvm_cbe_bswap_2e_or2;
if (AESL_DEBUG_TRACE)
printf("\nbswap.i32 = 0x%X\n", llvm_cbe_bswap_2e_i32);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @aesl_internal_bswap32}\n");
  return llvm_cbe_bswap_2e_i32;
}


static signed int aesl_internal_isBigEndianSystem(void) {
  static  unsigned long long aesl_llvm_cbe_294_count = 0;
  static  unsigned long long aesl_llvm_cbe_295_count = 0;
  static  unsigned long long aesl_llvm_cbe_296_count = 0;
  static  unsigned long long aesl_llvm_cbe_297_count = 0;
const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @aesl_internal_isBigEndianSystem\n");
  if (AESL_DEBUG_TRACE)
      printf("\nEND @aesl_internal_isBigEndianSystem}\n");
  return 0u;
}

