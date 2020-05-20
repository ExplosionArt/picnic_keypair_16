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
typedef struct l_struct_OC_shares_t l_struct_OC_shares_t;
typedef struct l_struct_OC_view_t l_struct_OC_view_t;
typedef struct l_struct_OC_paramset_t l_struct_OC_paramset_t;
typedef struct l_struct_OC_randomTape_t l_struct_OC_randomTape_t;
typedef struct l_struct_OC_proof2_t l_struct_OC_proof2_t;
typedef struct l_struct_OC_proof_t l_struct_OC_proof_t;
typedef struct l_struct_OC_signature_t l_struct_OC_signature_t;
typedef struct l_struct_OC_signature2_t l_struct_OC_signature2_t;
typedef struct l_struct_OC_seeds_t l_struct_OC_seeds_t;
typedef struct l_struct_OC_commitments_t l_struct_OC_commitments_t;
typedef struct l_struct_OC_msgs_t l_struct_OC_msgs_t;
typedef struct l_struct_OC_g_commitments_t l_struct_OC_g_commitments_t;

/* Structure contents */
struct l_struct_OC_shares_t {
  signed long long *field0;
  unsigned long long field1;
};

struct l_struct_OC_view_t {
  signed int *field0;
   char *field1;
  signed int *field2;
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

struct l_struct_OC_randomTape_t {
   char **field0;
  unsigned int field1;
  unsigned long long field2;
};

struct l_struct_OC_proof2_t {
  unsigned short field0;
   char *field1;
  unsigned long long field2;
   char *field3;
   char *field4;
   char *field5;
   char *field6;
};

struct l_struct_OC_proof_t {
   char field0[16];
   char field1[16];
  signed int field2[4];
   char field3[75];
   char field4[32];
  unsigned char field5;
};

struct l_struct_OC_signature_t {
  l_struct_OC_proof_t field0[219];
   char field1[55];
   char field2[32];
};

struct l_struct_OC_signature2_t {
   char *field0;
   char *field1;
  unsigned long long field2;
   char *field3;
  unsigned long long field4;
  signed short *field5;
  signed short *field6;
  l_struct_OC_proof2_t *field7;
};

struct l_struct_OC_seeds_t {
   char **field0;
   char *field1;
};

struct l_struct_OC_commitments_t {
   char **field0;
  unsigned long long field1;
};

struct l_struct_OC_msgs_t {
   char **field0;
  unsigned long long field1;
  unsigned int field2;
};

struct l_struct_OC_g_commitments_t {
   char *field0[3];
};


/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
l_struct_OC_shares_t *allocateShares(signed long long llvm_cbe_count);
void freeShares(l_struct_OC_shares_t *llvm_cbe_shares);
void allocateView(l_struct_OC_view_t *llvm_cbe_view, l_struct_OC_paramset_t *llvm_cbe_params);
void freeView(l_struct_OC_view_t *llvm_cbe_view);
void allocateRandomTape(l_struct_OC_randomTape_t *llvm_cbe_tape, l_struct_OC_paramset_t *llvm_cbe_params);
void freeRandomTape(l_struct_OC_randomTape_t *llvm_cbe_tape);
void allocateProof2(l_struct_OC_proof2_t *llvm_cbe_proof, l_struct_OC_paramset_t *llvm_cbe_params);
void freeProof2(l_struct_OC_proof2_t *llvm_cbe_proof);
void allocateProof(l_struct_OC_proof_t *llvm_cbe_proof, l_struct_OC_paramset_t *llvm_cbe_params);
void freeProof(l_struct_OC_proof_t *llvm_cbe_proof);
void allocateSignature(l_struct_OC_signature_t *llvm_cbe_sig, l_struct_OC_paramset_t *llvm_cbe_params);
void freeSignature(l_struct_OC_signature_t *llvm_cbe_sig, l_struct_OC_paramset_t *llvm_cbe_params);
void allocateSignature2(l_struct_OC_signature2_t *llvm_cbe_sig, l_struct_OC_paramset_t *llvm_cbe_params);
void freeSignature2(l_struct_OC_signature2_t *llvm_cbe_sig, l_struct_OC_paramset_t *llvm_cbe_params);
l_struct_OC_seeds_t *allocateSeeds(l_struct_OC_paramset_t *llvm_cbe_params);
void freeSeeds(l_struct_OC_seeds_t *llvm_cbe_seeds);
l_struct_OC_commitments_t *allocateCommitments(l_struct_OC_paramset_t *llvm_cbe_params, signed long long llvm_cbe_numCommitments);
void freeCommitments(l_struct_OC_commitments_t *llvm_cbe_commitments);
void allocateCommitments2(l_struct_OC_commitments_t *llvm_cbe_commitments, l_struct_OC_paramset_t *llvm_cbe_params, signed long long llvm_cbe_numCommitments);
void freeCommitments2(l_struct_OC_commitments_t *llvm_cbe_commitments);
 char **allocateInputs(l_struct_OC_paramset_t *llvm_cbe_params);
void freeInputs( char **llvm_cbe_inputs);
l_struct_OC_msgs_t *allocateMsgs(l_struct_OC_paramset_t *llvm_cbe_params);
void freeMsgs(l_struct_OC_msgs_t *llvm_cbe_msgs);
l_struct_OC_view_t **allocateViews(l_struct_OC_paramset_t *llvm_cbe_params);
void freeViews(l_struct_OC_view_t **llvm_cbe_views, l_struct_OC_paramset_t *llvm_cbe_params);
l_struct_OC_g_commitments_t *allocateGCommitments(l_struct_OC_paramset_t *llvm_cbe_params);
void freeGCommitments(l_struct_OC_g_commitments_t *llvm_cbe_gs);


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

l_struct_OC_shares_t *allocateShares(signed long long llvm_cbe_count) {
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
   char *llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
  l_struct_OC_shares_t *llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
   char *llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  signed long long *llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  signed long long **llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  signed long long *llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @allocateShares\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = tail call i8* @malloc(i64 16), !dbg !33 for 0x%I64xth hint within @allocateShares  --> \n", ++aesl_llvm_cbe_4_count);
  llvm_cbe_tmp__1 = ( char *) /*tail*/ ( char *)malloc(16ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",16ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__1);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = bitcast i8* %%1 to %%struct.shares_t*, !dbg !33 for 0x%I64xth hint within @allocateShares  --> \n", ++aesl_llvm_cbe_5_count);
  llvm_cbe_tmp__2 = (l_struct_OC_shares_t *)((l_struct_OC_shares_t *)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = tail call i8* @calloc(i64 %%count, i64 8) nounwind, !dbg !33 for 0x%I64xth hint within @allocateShares  --> \n", ++aesl_llvm_cbe_10_count);
  llvm_cbe_tmp__3 = ( char *) /*tail*/ ( char *)calloc(llvm_cbe_count, 8ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument count = 0x%I64X",llvm_cbe_count);
printf("\nArgument  = 0x%I64X",8ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__3);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = bitcast i8* %%3 to i64*, !dbg !33 for 0x%I64xth hint within @allocateShares  --> \n", ++aesl_llvm_cbe_11_count);
  llvm_cbe_tmp__4 = (signed long long *)((signed long long *)llvm_cbe_tmp__3);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = bitcast i8* %%1 to i64**, !dbg !33 for 0x%I64xth hint within @allocateShares  --> \n", ++aesl_llvm_cbe_12_count);
  llvm_cbe_tmp__5 = (signed long long **)((signed long long **)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE)
printf("\n  store i64* %%4, i64** %%5, align 8, !dbg !33 for 0x%I64xth hint within @allocateShares  --> \n", ++aesl_llvm_cbe_13_count);
  *llvm_cbe_tmp__5 = (signed long long *)llvm_cbe_tmp__4;
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds %%struct.shares_t* %%2, i64 0, i32 1, !dbg !33 for 0x%I64xth hint within @allocateShares  --> \n", ++aesl_llvm_cbe_14_count);
  llvm_cbe_tmp__6 = (signed long long *)(&llvm_cbe_tmp__2->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%count, i64* %%6, align 8, !dbg !33 for 0x%I64xth hint within @allocateShares  --> \n", ++aesl_llvm_cbe_15_count);
  *llvm_cbe_tmp__6 = llvm_cbe_count;
if (AESL_DEBUG_TRACE)
printf("\ncount = 0x%I64X\n", llvm_cbe_count);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @allocateShares}\n");
  return llvm_cbe_tmp__2;
}


void freeShares(l_struct_OC_shares_t *llvm_cbe_shares) {
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  signed long long **llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  signed long long *llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
   char *llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
   char *llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @freeShares\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.shares_t* %%shares, i64 0, i32 0, !dbg !33 for 0x%I64xth hint within @freeShares  --> \n", ++aesl_llvm_cbe_20_count);
  llvm_cbe_tmp__7 = (signed long long **)(&llvm_cbe_shares->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i64** %%1, align 8, !dbg !33 for 0x%I64xth hint within @freeShares  --> \n", ++aesl_llvm_cbe_21_count);
  llvm_cbe_tmp__8 = (signed long long *)*llvm_cbe_tmp__7;
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = bitcast i64* %%2 to i8*, !dbg !33 for 0x%I64xth hint within @freeShares  --> \n", ++aesl_llvm_cbe_22_count);
  llvm_cbe_tmp__9 = ( char *)(( char *)llvm_cbe_tmp__8);
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @free(i8* %%3), !dbg !33 for 0x%I64xth hint within @freeShares  --> \n", ++aesl_llvm_cbe_23_count);
   /*tail*/ free(( char *)llvm_cbe_tmp__9);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = bitcast %%struct.shares_t* %%shares to i8*, !dbg !33 for 0x%I64xth hint within @freeShares  --> \n", ++aesl_llvm_cbe_24_count);
  llvm_cbe_tmp__10 = ( char *)(( char *)llvm_cbe_shares);
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @free(i8* %%4), !dbg !33 for 0x%I64xth hint within @freeShares  --> \n", ++aesl_llvm_cbe_25_count);
   /*tail*/ free(( char *)llvm_cbe_tmp__10);
if (AESL_DEBUG_TRACE) {
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @freeShares}\n");
  return;
}


void allocateView(l_struct_OC_view_t *llvm_cbe_view, l_struct_OC_paramset_t *llvm_cbe_params) {
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  signed int *llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  unsigned int llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  unsigned long long llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
   char *llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  signed int *llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  signed int **llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  signed int *llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  unsigned int llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  unsigned long long llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
   char *llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
   char **llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  unsigned int llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  unsigned long long llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
   char *llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  signed int *llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  signed int **llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @allocateView\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.paramset_t* %%params, i64 0, i32 3, !dbg !33 for 0x%I64xth hint within @allocateView  --> \n", ++aesl_llvm_cbe_35_count);
  llvm_cbe_tmp__11 = (signed int *)(&llvm_cbe_params->field3);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i32* %%1, align 4, !dbg !33 for 0x%I64xth hint within @allocateView  --> \n", ++aesl_llvm_cbe_36_count);
  llvm_cbe_tmp__12 = (unsigned int )*llvm_cbe_tmp__11;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__12);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = zext i32 %%2 to i64, !dbg !33 for 0x%I64xth hint within @allocateView  --> \n", ++aesl_llvm_cbe_37_count);
  llvm_cbe_tmp__13 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__12&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__13);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = tail call i8* @malloc(i64 %%3), !dbg !33 for 0x%I64xth hint within @allocateView  --> \n", ++aesl_llvm_cbe_38_count);
  llvm_cbe_tmp__14 = ( char *) /*tail*/ ( char *)malloc(llvm_cbe_tmp__13);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__13);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__14);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = bitcast i8* %%4 to i32*, !dbg !33 for 0x%I64xth hint within @allocateView  --> \n", ++aesl_llvm_cbe_39_count);
  llvm_cbe_tmp__15 = (signed int *)((signed int *)llvm_cbe_tmp__14);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds %%struct.view_t* %%view, i64 0, i32 0, !dbg !33 for 0x%I64xth hint within @allocateView  --> \n", ++aesl_llvm_cbe_40_count);
  llvm_cbe_tmp__16 = (signed int **)(&llvm_cbe_view->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32* %%5, i32** %%6, align 8, !dbg !33 for 0x%I64xth hint within @allocateView  --> \n", ++aesl_llvm_cbe_41_count);
  *llvm_cbe_tmp__16 = (signed int *)llvm_cbe_tmp__15;
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds %%struct.paramset_t* %%params, i64 0, i32 5, !dbg !33 for 0x%I64xth hint within @allocateView  --> \n", ++aesl_llvm_cbe_42_count);
  llvm_cbe_tmp__17 = (signed int *)(&llvm_cbe_params->field5);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load i32* %%7, align 4, !dbg !33 for 0x%I64xth hint within @allocateView  --> \n", ++aesl_llvm_cbe_43_count);
  llvm_cbe_tmp__18 = (unsigned int )*llvm_cbe_tmp__17;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__18);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = zext i32 %%8 to i64, !dbg !33 for 0x%I64xth hint within @allocateView  --> \n", ++aesl_llvm_cbe_44_count);
  llvm_cbe_tmp__19 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__18&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__19);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = tail call i8* @malloc(i64 %%9), !dbg !33 for 0x%I64xth hint within @allocateView  --> \n", ++aesl_llvm_cbe_45_count);
  llvm_cbe_tmp__20 = ( char *) /*tail*/ ( char *)malloc(llvm_cbe_tmp__19);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__19);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__20);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds %%struct.view_t* %%view, i64 0, i32 1, !dbg !33 for 0x%I64xth hint within @allocateView  --> \n", ++aesl_llvm_cbe_46_count);
  llvm_cbe_tmp__21 = ( char **)(&llvm_cbe_view->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8* %%10, i8** %%11, align 8, !dbg !33 for 0x%I64xth hint within @allocateView  --> \n", ++aesl_llvm_cbe_47_count);
  *llvm_cbe_tmp__21 = ( char *)llvm_cbe_tmp__20;
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = load i32* %%1, align 4, !dbg !33 for 0x%I64xth hint within @allocateView  --> \n", ++aesl_llvm_cbe_48_count);
  llvm_cbe_tmp__22 = (unsigned int )*llvm_cbe_tmp__11;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__22);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = zext i32 %%12 to i64, !dbg !33 for 0x%I64xth hint within @allocateView  --> \n", ++aesl_llvm_cbe_49_count);
  llvm_cbe_tmp__23 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__22&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__23);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = tail call i8* @malloc(i64 %%13), !dbg !33 for 0x%I64xth hint within @allocateView  --> \n", ++aesl_llvm_cbe_50_count);
  llvm_cbe_tmp__24 = ( char *) /*tail*/ ( char *)malloc(llvm_cbe_tmp__23);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__23);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__24);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = bitcast i8* %%14 to i32*, !dbg !33 for 0x%I64xth hint within @allocateView  --> \n", ++aesl_llvm_cbe_51_count);
  llvm_cbe_tmp__25 = (signed int *)((signed int *)llvm_cbe_tmp__24);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds %%struct.view_t* %%view, i64 0, i32 2, !dbg !33 for 0x%I64xth hint within @allocateView  --> \n", ++aesl_llvm_cbe_52_count);
  llvm_cbe_tmp__26 = (signed int **)(&llvm_cbe_view->field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32* %%15, i32** %%16, align 8, !dbg !33 for 0x%I64xth hint within @allocateView  --> \n", ++aesl_llvm_cbe_53_count);
  *llvm_cbe_tmp__26 = (signed int *)llvm_cbe_tmp__25;
  if (AESL_DEBUG_TRACE)
      printf("\nEND @allocateView}\n");
  return;
}


void freeView(l_struct_OC_view_t *llvm_cbe_view) {
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  signed int **llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  signed int *llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
   char *llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
   char **llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
   char *llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  signed int **llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  signed int *llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
   char *llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @freeView\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.view_t* %%view, i64 0, i32 0, !dbg !33 for 0x%I64xth hint within @freeView  --> \n", ++aesl_llvm_cbe_59_count);
  llvm_cbe_tmp__27 = (signed int **)(&llvm_cbe_view->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i32** %%1, align 8, !dbg !33 for 0x%I64xth hint within @freeView  --> \n", ++aesl_llvm_cbe_60_count);
  llvm_cbe_tmp__28 = (signed int *)*llvm_cbe_tmp__27;
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = bitcast i32* %%2 to i8*, !dbg !33 for 0x%I64xth hint within @freeView  --> \n", ++aesl_llvm_cbe_61_count);
  llvm_cbe_tmp__29 = ( char *)(( char *)llvm_cbe_tmp__28);
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @free(i8* %%3), !dbg !33 for 0x%I64xth hint within @freeView  --> \n", ++aesl_llvm_cbe_62_count);
   /*tail*/ free(( char *)llvm_cbe_tmp__29);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds %%struct.view_t* %%view, i64 0, i32 1, !dbg !33 for 0x%I64xth hint within @freeView  --> \n", ++aesl_llvm_cbe_63_count);
  llvm_cbe_tmp__30 = ( char **)(&llvm_cbe_view->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load i8** %%4, align 8, !dbg !33 for 0x%I64xth hint within @freeView  --> \n", ++aesl_llvm_cbe_64_count);
  llvm_cbe_tmp__31 = ( char *)*llvm_cbe_tmp__30;
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @free(i8* %%5), !dbg !33 for 0x%I64xth hint within @freeView  --> \n", ++aesl_llvm_cbe_65_count);
   /*tail*/ free(( char *)llvm_cbe_tmp__31);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds %%struct.view_t* %%view, i64 0, i32 2, !dbg !33 for 0x%I64xth hint within @freeView  --> \n", ++aesl_llvm_cbe_66_count);
  llvm_cbe_tmp__32 = (signed int **)(&llvm_cbe_view->field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = load i32** %%6, align 8, !dbg !33 for 0x%I64xth hint within @freeView  --> \n", ++aesl_llvm_cbe_67_count);
  llvm_cbe_tmp__33 = (signed int *)*llvm_cbe_tmp__32;
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = bitcast i32* %%7 to i8*, !dbg !33 for 0x%I64xth hint within @freeView  --> \n", ++aesl_llvm_cbe_68_count);
  llvm_cbe_tmp__34 = ( char *)(( char *)llvm_cbe_tmp__33);
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @free(i8* %%8), !dbg !33 for 0x%I64xth hint within @freeView  --> \n", ++aesl_llvm_cbe_69_count);
   /*tail*/ free(( char *)llvm_cbe_tmp__34);
if (AESL_DEBUG_TRACE) {
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @freeView}\n");
  return;
}


void allocateRandomTape(l_struct_OC_randomTape_t *llvm_cbe_tape, l_struct_OC_paramset_t *llvm_cbe_params) {
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
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  signed int *llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  unsigned int llvm_cbe_tmp__36;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  unsigned long long llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  signed long long *llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  unsigned long long llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
   char *llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
   char **llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
   char ***llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  signed int *llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
  unsigned int llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  unsigned int llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  signed int *llvm_cbe_tmp__46;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  unsigned int llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  unsigned int llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;
  unsigned long long llvm_cbe_tmp__49;
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
  unsigned long long llvm_cbe_tmp__50;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
   char *llvm_cbe_tmp__51;
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  unsigned long long llvm_cbe_tmp__52;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
  unsigned long long llvm_cbe_tmp__53;
  unsigned long long llvm_cbe_tmp__53__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned char llvm_cbe_storemerge1;
  unsigned char llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_rec_count = 0;
  unsigned long long llvm_cbe__2e_rec;
  unsigned long long llvm_cbe__2e_rec__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
   char *llvm_cbe_tmp__54;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
   char **llvm_cbe_tmp__55;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
   char **llvm_cbe_tmp__56;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_rec2_count = 0;
  unsigned long long llvm_cbe__2e_rec2;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
  unsigned char llvm_cbe_tmp__57;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  unsigned long long llvm_cbe_tmp__58;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  unsigned long long llvm_cbe_tmp__59;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  signed int *llvm_cbe_tmp__60;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @allocateRandomTape\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.paramset_t* %%params, i64 0, i32 10, !dbg !33 for 0x%I64xth hint within @allocateRandomTape  --> \n", ++aesl_llvm_cbe_83_count);
  llvm_cbe_tmp__35 = (signed int *)(&llvm_cbe_params->field10);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i32* %%1, align 4, !dbg !33 for 0x%I64xth hint within @allocateRandomTape  --> \n", ++aesl_llvm_cbe_84_count);
  llvm_cbe_tmp__36 = (unsigned int )*llvm_cbe_tmp__35;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__36);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = zext i32 %%2 to i64, !dbg !33 for 0x%I64xth hint within @allocateRandomTape  --> \n", ++aesl_llvm_cbe_85_count);
  llvm_cbe_tmp__37 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__36&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__37);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds %%struct.randomTape_t* %%tape, i64 0, i32 2, !dbg !33 for 0x%I64xth hint within @allocateRandomTape  --> \n", ++aesl_llvm_cbe_86_count);
  llvm_cbe_tmp__38 = (signed long long *)(&llvm_cbe_tape->field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%3, i64* %%4, align 8, !dbg !33 for 0x%I64xth hint within @allocateRandomTape  --> \n", ++aesl_llvm_cbe_87_count);
  *llvm_cbe_tmp__38 = llvm_cbe_tmp__37;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__37);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = shl nuw nsw i64 %%3, 3, !dbg !33 for 0x%I64xth hint within @allocateRandomTape  --> \n", ++aesl_llvm_cbe_88_count);
  llvm_cbe_tmp__39 = (unsigned long long )llvm_cbe_tmp__37 << 3ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__39);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = tail call i8* @malloc(i64 %%5), !dbg !33 for 0x%I64xth hint within @allocateRandomTape  --> \n", ++aesl_llvm_cbe_89_count);
  llvm_cbe_tmp__40 = ( char *) /*tail*/ ( char *)malloc(llvm_cbe_tmp__39);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__39);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__40);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = bitcast i8* %%6 to i8**, !dbg !33 for 0x%I64xth hint within @allocateRandomTape  --> \n", ++aesl_llvm_cbe_90_count);
  llvm_cbe_tmp__41 = ( char **)(( char **)llvm_cbe_tmp__40);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds %%struct.randomTape_t* %%tape, i64 0, i32 0, !dbg !33 for 0x%I64xth hint within @allocateRandomTape  --> \n", ++aesl_llvm_cbe_91_count);
  llvm_cbe_tmp__42 = ( char ***)(&llvm_cbe_tape->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8** %%7, i8*** %%8, align 8, !dbg !33 for 0x%I64xth hint within @allocateRandomTape  --> \n", ++aesl_llvm_cbe_92_count);
  *llvm_cbe_tmp__42 = ( char **)llvm_cbe_tmp__41;
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds %%struct.paramset_t* %%params, i64 0, i32 5, !dbg !34 for 0x%I64xth hint within @allocateRandomTape  --> \n", ++aesl_llvm_cbe_93_count);
  llvm_cbe_tmp__43 = (signed int *)(&llvm_cbe_params->field5);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = load i32* %%9, align 4, !dbg !34 for 0x%I64xth hint within @allocateRandomTape  --> \n", ++aesl_llvm_cbe_94_count);
  llvm_cbe_tmp__44 = (unsigned int )*llvm_cbe_tmp__43;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__44);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = shl i32 %%10, 1, !dbg !34 for 0x%I64xth hint within @allocateRandomTape  --> \n", ++aesl_llvm_cbe_95_count);
  llvm_cbe_tmp__45 = (unsigned int )llvm_cbe_tmp__44 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__45);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds %%struct.paramset_t* %%params, i64 0, i32 3, !dbg !34 for 0x%I64xth hint within @allocateRandomTape  --> \n", ++aesl_llvm_cbe_96_count);
  llvm_cbe_tmp__46 = (signed int *)(&llvm_cbe_params->field3);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = load i32* %%12, align 4, !dbg !34 for 0x%I64xth hint within @allocateRandomTape  --> \n", ++aesl_llvm_cbe_97_count);
  llvm_cbe_tmp__47 = (unsigned int )*llvm_cbe_tmp__46;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__47);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = add i32 %%11, %%13, !dbg !34 for 0x%I64xth hint within @allocateRandomTape  --> \n", ++aesl_llvm_cbe_98_count);
  llvm_cbe_tmp__48 = (unsigned int )((unsigned int )(llvm_cbe_tmp__45&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__47&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__48&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = zext i32 %%14 to i64, !dbg !34 for 0x%I64xth hint within @allocateRandomTape  --> \n", ++aesl_llvm_cbe_99_count);
  llvm_cbe_tmp__49 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__48&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__49);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = mul i64 %%15, %%3, !dbg !33 for 0x%I64xth hint within @allocateRandomTape  --> \n", ++aesl_llvm_cbe_103_count);
  llvm_cbe_tmp__50 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__49&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__37&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__50&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = tail call i8* @calloc(i64 1, i64 %%16) nounwind, !dbg !33 for 0x%I64xth hint within @allocateRandomTape  --> \n", ++aesl_llvm_cbe_104_count);
  llvm_cbe_tmp__51 = ( char *) /*tail*/ ( char *)calloc(1ull, llvm_cbe_tmp__50);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",1ull);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__50);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__51);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = load i64* %%4, align 8, !dbg !33 for 0x%I64xth hint within @allocateRandomTape  --> \n", ++aesl_llvm_cbe_112_count);
  llvm_cbe_tmp__52 = (unsigned long long )*llvm_cbe_tmp__38;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__52);
  if (((llvm_cbe_tmp__52&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_tmp__53__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned char )((unsigned char )0);   /* for PHI node */
    llvm_cbe__2e_rec__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = phi i64 [ %%25, %%.lr.ph ], [ 0, %%0  for 0x%I64xth hint within @allocateRandomTape  --> \n", ++aesl_llvm_cbe_115_count);
  llvm_cbe_tmp__53 = (unsigned long long )llvm_cbe_tmp__53__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__53);
printf("\n = 0x%I64X",llvm_cbe_tmp__58);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i8 [ %%24, %%.lr.ph ], [ 0, %%0  for 0x%I64xth hint within @allocateRandomTape  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned char )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",llvm_cbe_tmp__57);
printf("\n = 0x%X",((unsigned char )0));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec = phi i64 [ %%.rec2, %%.lr.ph ], [ 0, %%0  for 0x%I64xth hint within @allocateRandomTape  --> \n", ++aesl_llvm_cbe__2e_rec_count);
  llvm_cbe__2e_rec = (unsigned long long )llvm_cbe__2e_rec__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.rec = 0x%I64X",llvm_cbe__2e_rec);
printf("\n.rec2 = 0x%I64X",llvm_cbe__2e_rec2);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = getelementptr i8* %%17, i64 %%.re for 0x%I64xth hint within @allocateRandomTape  --> \n", ++aesl_llvm_cbe_116_count);
  llvm_cbe_tmp__54 = ( char *)(&llvm_cbe_tmp__51[(((signed long long )llvm_cbe__2e_rec))]);
if (AESL_DEBUG_TRACE) {
printf("\n.rec = 0x%I64X",((signed long long )llvm_cbe__2e_rec));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = load i8*** %%8, align 8, !dbg !33 for 0x%I64xth hint within @allocateRandomTape  --> \n", ++aesl_llvm_cbe_117_count);
  llvm_cbe_tmp__55 = ( char **)*llvm_cbe_tmp__42;
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = getelementptr inbounds i8** %%22, i64 %%20, !dbg !33 for 0x%I64xth hint within @allocateRandomTape  --> \n", ++aesl_llvm_cbe_118_count);
  llvm_cbe_tmp__56 = ( char **)(&llvm_cbe_tmp__55[(((signed long long )llvm_cbe_tmp__53))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__53));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8* %%21, i8** %%23, align 8, !dbg !33 for 0x%I64xth hint within @allocateRandomTape  --> \n", ++aesl_llvm_cbe_119_count);
  *llvm_cbe_tmp__56 = ( char *)llvm_cbe_tmp__54;
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec2 = add i64 %%.rec, %%15, !dbg !34 for 0x%I64xth hint within @allocateRandomTape  --> \n", ++aesl_llvm_cbe__2e_rec2_count);
  llvm_cbe__2e_rec2 = (unsigned long long )((unsigned long long )(llvm_cbe__2e_rec&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__49&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.rec2 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_rec2&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = add i8 %%storemerge1, 1, !dbg !34 for 0x%I64xth hint within @allocateRandomTape  --> \n", ++aesl_llvm_cbe_120_count);
  llvm_cbe_tmp__57 = (unsigned char )((unsigned char )(((unsigned char )(llvm_cbe_storemerge1&255ull)) + ((unsigned char )(((unsigned char )1)&255ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )(llvm_cbe_tmp__57&255ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = zext i8 %%24 to i64, !dbg !33 for 0x%I64xth hint within @allocateRandomTape  --> \n", ++aesl_llvm_cbe_125_count);
  llvm_cbe_tmp__58 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_tmp__57&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__58);
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = load i64* %%4, align 8, !dbg !33 for 0x%I64xth hint within @allocateRandomTape  --> \n", ++aesl_llvm_cbe_126_count);
  llvm_cbe_tmp__59 = (unsigned long long )*llvm_cbe_tmp__38;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__59);
  if ((((unsigned long long )llvm_cbe_tmp__58&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__59&18446744073709551615ULL))) {
    llvm_cbe_tmp__53__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__58;   /* for PHI node */
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__57;   /* for PHI node */
    llvm_cbe__2e_rec__PHI_TEMPORARY = (unsigned long long )llvm_cbe__2e_rec2;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = getelementptr inbounds %%struct.randomTape_t* %%tape, i64 0, i32 1, !dbg !33 for 0x%I64xth hint within @allocateRandomTape  --> \n", ++aesl_llvm_cbe_129_count);
  llvm_cbe_tmp__60 = (signed int *)(&llvm_cbe_tape->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 0, i32* %%28, align 4, !dbg !33 for 0x%I64xth hint within @allocateRandomTape  --> \n", ++aesl_llvm_cbe_130_count);
  *llvm_cbe_tmp__60 = 0u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 0u);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @allocateRandomTape}\n");
  return;
}


void freeRandomTape(l_struct_OC_randomTape_t *llvm_cbe_tape) {
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
   char ***llvm_cbe_tmp__61;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
   char **llvm_cbe_tmp__62;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
   char *llvm_cbe_tmp__63;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
   char **llvm_cbe_tmp__64;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
   char *llvm_cbe_tmp__65;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @freeRandomTape\n");
  if (((llvm_cbe_tape) == (((l_struct_OC_randomTape_t *)/*NULL*/0)))) {
    goto llvm_cbe_tmp__66;
  } else {
    goto llvm_cbe_tmp__67;
  }

llvm_cbe_tmp__67:
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.randomTape_t* %%tape, i64 0, i32 0, !dbg !33 for 0x%I64xth hint within @freeRandomTape  --> \n", ++aesl_llvm_cbe_138_count);
  llvm_cbe_tmp__61 = ( char ***)(&llvm_cbe_tape->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i8*** %%3, align 8, !dbg !33 for 0x%I64xth hint within @freeRandomTape  --> \n", ++aesl_llvm_cbe_139_count);
  llvm_cbe_tmp__62 = ( char **)*llvm_cbe_tmp__61;
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load i8** %%4, align 8, !dbg !33 for 0x%I64xth hint within @freeRandomTape  --> \n", ++aesl_llvm_cbe_140_count);
  llvm_cbe_tmp__63 = ( char *)*llvm_cbe_tmp__62;
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @free(i8* %%5), !dbg !33 for 0x%I64xth hint within @freeRandomTape  --> \n", ++aesl_llvm_cbe_141_count);
   /*tail*/ free(( char *)llvm_cbe_tmp__63);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load i8*** %%3, align 8, !dbg !33 for 0x%I64xth hint within @freeRandomTape  --> \n", ++aesl_llvm_cbe_142_count);
  llvm_cbe_tmp__64 = ( char **)*llvm_cbe_tmp__61;
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = bitcast i8** %%6 to i8*, !dbg !33 for 0x%I64xth hint within @freeRandomTape  --> \n", ++aesl_llvm_cbe_143_count);
  llvm_cbe_tmp__65 = ( char *)(( char *)llvm_cbe_tmp__64);
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @free(i8* %%7), !dbg !33 for 0x%I64xth hint within @freeRandomTape  --> \n", ++aesl_llvm_cbe_144_count);
   /*tail*/ free(( char *)llvm_cbe_tmp__65);
if (AESL_DEBUG_TRACE) {
}
  goto llvm_cbe_tmp__66;

llvm_cbe_tmp__66:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @freeRandomTape}\n");
  return;
}


void allocateProof2(l_struct_OC_proof2_t *llvm_cbe_proof, l_struct_OC_paramset_t *llvm_cbe_params) {
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;
  static  unsigned long long aesl_llvm_cbe_152_count = 0;
  static  unsigned long long aesl_llvm_cbe_153_count = 0;
  static  unsigned long long aesl_llvm_cbe_154_count = 0;
  static  unsigned long long aesl_llvm_cbe_155_count = 0;
  static  unsigned long long aesl_llvm_cbe_156_count = 0;
  static  unsigned long long aesl_llvm_cbe_157_count = 0;
  static  unsigned long long aesl_llvm_cbe_158_count = 0;
  static  unsigned long long aesl_llvm_cbe_159_count = 0;
  static  unsigned long long aesl_llvm_cbe_160_count = 0;
  static  unsigned long long aesl_llvm_cbe_161_count = 0;
  static  unsigned long long aesl_llvm_cbe_162_count = 0;
   char *llvm_cbe_tmp__68;
  static  unsigned long long aesl_llvm_cbe_163_count = 0;
   char *llvm_cbe_tmp__69;
  static  unsigned long long aesl_llvm_cbe_164_count = 0;
  signed short *llvm_cbe_tmp__70;
  static  unsigned long long aesl_llvm_cbe_165_count = 0;
  static  unsigned long long aesl_llvm_cbe_166_count = 0;
   char **llvm_cbe_tmp__71;
  static  unsigned long long aesl_llvm_cbe_167_count = 0;
  signed int *llvm_cbe_tmp__72;
  static  unsigned long long aesl_llvm_cbe_168_count = 0;
   char *llvm_cbe_tmp__73;
  static  unsigned long long aesl_llvm_cbe_169_count = 0;
   char *llvm_cbe_tmp__74;
  static  unsigned long long aesl_llvm_cbe_170_count = 0;
  unsigned int llvm_cbe_tmp__75;
  static  unsigned long long aesl_llvm_cbe_171_count = 0;
  unsigned long long llvm_cbe_tmp__76;
  static  unsigned long long aesl_llvm_cbe_172_count = 0;
   char *llvm_cbe_tmp__77;
  static  unsigned long long aesl_llvm_cbe_173_count = 0;
   char **llvm_cbe_tmp__78;
  static  unsigned long long aesl_llvm_cbe_174_count = 0;
  static  unsigned long long aesl_llvm_cbe_175_count = 0;
  signed int *llvm_cbe_tmp__79;
  static  unsigned long long aesl_llvm_cbe_176_count = 0;
  unsigned int llvm_cbe_tmp__80;
  static  unsigned long long aesl_llvm_cbe_177_count = 0;
  unsigned long long llvm_cbe_tmp__81;
  static  unsigned long long aesl_llvm_cbe_178_count = 0;
   char *llvm_cbe_tmp__82;
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
   char **llvm_cbe_tmp__83;
  static  unsigned long long aesl_llvm_cbe_180_count = 0;
  static  unsigned long long aesl_llvm_cbe_181_count = 0;
  signed int *llvm_cbe_tmp__84;
  static  unsigned long long aesl_llvm_cbe_182_count = 0;
  unsigned int llvm_cbe_tmp__85;
  static  unsigned long long aesl_llvm_cbe_183_count = 0;
  unsigned long long llvm_cbe_tmp__86;
  static  unsigned long long aesl_llvm_cbe_184_count = 0;
   char *llvm_cbe_tmp__87;
  static  unsigned long long aesl_llvm_cbe_185_count = 0;
   char **llvm_cbe_tmp__88;
  static  unsigned long long aesl_llvm_cbe_186_count = 0;
  static  unsigned long long aesl_llvm_cbe_187_count = 0;
  unsigned int llvm_cbe_tmp__89;
  static  unsigned long long aesl_llvm_cbe_188_count = 0;
  unsigned int llvm_cbe_tmp__90;
  static  unsigned long long aesl_llvm_cbe_189_count = 0;
  unsigned int llvm_cbe_tmp__91;
  static  unsigned long long aesl_llvm_cbe_190_count = 0;
  unsigned long long llvm_cbe_tmp__92;
  static  unsigned long long aesl_llvm_cbe_191_count = 0;
   char *llvm_cbe_tmp__93;
  static  unsigned long long aesl_llvm_cbe_192_count = 0;
   char **llvm_cbe_tmp__94;
  static  unsigned long long aesl_llvm_cbe_193_count = 0;
  static  unsigned long long aesl_llvm_cbe_194_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @allocateProof2\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = bitcast %%struct.proof2_t* %%proof to i8*, !dbg !33 for 0x%I64xth hint within @allocateProof2  --> \n", ++aesl_llvm_cbe_162_count);
  llvm_cbe_tmp__68 = ( char *)(( char *)llvm_cbe_proof);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = call i8* @memset(i8* %%1, i32 0, i64 56 for 0x%I64xth hint within @allocateProof2  --> \n", ++aesl_llvm_cbe_163_count);
  ( char *)memset(( char *)llvm_cbe_tmp__68, 0u, 56ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",56ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__69);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.proof2_t* %%proof, i64 0, i32 0, !dbg !33 for 0x%I64xth hint within @allocateProof2  --> \n", ++aesl_llvm_cbe_164_count);
  llvm_cbe_tmp__70 = (signed short *)(&llvm_cbe_proof->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i16 0, i16* %%3, align 2, !dbg !33 for 0x%I64xth hint within @allocateProof2  --> \n", ++aesl_llvm_cbe_165_count);
  *llvm_cbe_tmp__70 = ((unsigned short )0);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned short )0));
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds %%struct.proof2_t* %%proof, i64 0, i32 1, !dbg !33 for 0x%I64xth hint within @allocateProof2  --> \n", ++aesl_llvm_cbe_166_count);
  llvm_cbe_tmp__71 = ( char **)(&llvm_cbe_proof->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds %%struct.paramset_t* %%params, i64 0, i32 13, !dbg !33 for 0x%I64xth hint within @allocateProof2  --> \n", ++aesl_llvm_cbe_167_count);
  llvm_cbe_tmp__72 = (signed int *)(&llvm_cbe_params->field13);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = bitcast i8** %%4 to i8*, !dbg !33 for 0x%I64xth hint within @allocateProof2  --> \n", ++aesl_llvm_cbe_168_count);
  llvm_cbe_tmp__73 = ( char *)(( char *)llvm_cbe_tmp__71);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = call i8* @memset(i8* %%6, i32 0, i64 16 for 0x%I64xth hint within @allocateProof2  --> \n", ++aesl_llvm_cbe_169_count);
  ( char *)memset(( char *)llvm_cbe_tmp__73, 0u, 16ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",16ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__74);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load i32* %%5, align 4, !dbg !33 for 0x%I64xth hint within @allocateProof2  --> \n", ++aesl_llvm_cbe_170_count);
  llvm_cbe_tmp__75 = (unsigned int )*llvm_cbe_tmp__72;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__75);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = zext i32 %%8 to i64, !dbg !33 for 0x%I64xth hint within @allocateProof2  --> \n", ++aesl_llvm_cbe_171_count);
  llvm_cbe_tmp__76 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__75&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__76);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = tail call i8* @malloc(i64 %%9), !dbg !33 for 0x%I64xth hint within @allocateProof2  --> \n", ++aesl_llvm_cbe_172_count);
  llvm_cbe_tmp__77 = ( char *) /*tail*/ ( char *)malloc(llvm_cbe_tmp__76);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__76);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__77);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds %%struct.proof2_t* %%proof, i64 0, i32 4, !dbg !33 for 0x%I64xth hint within @allocateProof2  --> \n", ++aesl_llvm_cbe_173_count);
  llvm_cbe_tmp__78 = ( char **)(&llvm_cbe_proof->field4);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8* %%10, i8** %%11, align 8, !dbg !33 for 0x%I64xth hint within @allocateProof2  --> \n", ++aesl_llvm_cbe_174_count);
  *llvm_cbe_tmp__78 = ( char *)llvm_cbe_tmp__77;
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds %%struct.paramset_t* %%params, i64 0, i32 3, !dbg !33 for 0x%I64xth hint within @allocateProof2  --> \n", ++aesl_llvm_cbe_175_count);
  llvm_cbe_tmp__79 = (signed int *)(&llvm_cbe_params->field3);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = load i32* %%12, align 4, !dbg !33 for 0x%I64xth hint within @allocateProof2  --> \n", ++aesl_llvm_cbe_176_count);
  llvm_cbe_tmp__80 = (unsigned int )*llvm_cbe_tmp__79;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__80);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = zext i32 %%13 to i64, !dbg !33 for 0x%I64xth hint within @allocateProof2  --> \n", ++aesl_llvm_cbe_177_count);
  llvm_cbe_tmp__81 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__80&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__81);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = tail call i8* @malloc(i64 %%14), !dbg !33 for 0x%I64xth hint within @allocateProof2  --> \n", ++aesl_llvm_cbe_178_count);
  llvm_cbe_tmp__82 = ( char *) /*tail*/ ( char *)malloc(llvm_cbe_tmp__81);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__81);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__82);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds %%struct.proof2_t* %%proof, i64 0, i32 5, !dbg !33 for 0x%I64xth hint within @allocateProof2  --> \n", ++aesl_llvm_cbe_179_count);
  llvm_cbe_tmp__83 = ( char **)(&llvm_cbe_proof->field5);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8* %%15, i8** %%16, align 8, !dbg !33 for 0x%I64xth hint within @allocateProof2  --> \n", ++aesl_llvm_cbe_180_count);
  *llvm_cbe_tmp__83 = ( char *)llvm_cbe_tmp__82;
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds %%struct.paramset_t* %%params, i64 0, i32 5, !dbg !33 for 0x%I64xth hint within @allocateProof2  --> \n", ++aesl_llvm_cbe_181_count);
  llvm_cbe_tmp__84 = (signed int *)(&llvm_cbe_params->field5);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = load i32* %%17, align 4, !dbg !33 for 0x%I64xth hint within @allocateProof2  --> \n", ++aesl_llvm_cbe_182_count);
  llvm_cbe_tmp__85 = (unsigned int )*llvm_cbe_tmp__84;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__85);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = zext i32 %%18 to i64, !dbg !33 for 0x%I64xth hint within @allocateProof2  --> \n", ++aesl_llvm_cbe_183_count);
  llvm_cbe_tmp__86 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__85&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__86);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = tail call i8* @malloc(i64 %%19), !dbg !33 for 0x%I64xth hint within @allocateProof2  --> \n", ++aesl_llvm_cbe_184_count);
  llvm_cbe_tmp__87 = ( char *) /*tail*/ ( char *)malloc(llvm_cbe_tmp__86);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__86);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__87);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = getelementptr inbounds %%struct.proof2_t* %%proof, i64 0, i32 3, !dbg !33 for 0x%I64xth hint within @allocateProof2  --> \n", ++aesl_llvm_cbe_185_count);
  llvm_cbe_tmp__88 = ( char **)(&llvm_cbe_proof->field3);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8* %%20, i8** %%21, align 8, !dbg !33 for 0x%I64xth hint within @allocateProof2  --> \n", ++aesl_llvm_cbe_186_count);
  *llvm_cbe_tmp__88 = ( char *)llvm_cbe_tmp__87;
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = load i32* %%17, align 4, !dbg !33 for 0x%I64xth hint within @allocateProof2  --> \n", ++aesl_llvm_cbe_187_count);
  llvm_cbe_tmp__89 = (unsigned int )*llvm_cbe_tmp__84;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__89);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = load i32* %%12, align 4, !dbg !33 for 0x%I64xth hint within @allocateProof2  --> \n", ++aesl_llvm_cbe_188_count);
  llvm_cbe_tmp__90 = (unsigned int )*llvm_cbe_tmp__79;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__90);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = add i32 %%23, %%22, !dbg !33 for 0x%I64xth hint within @allocateProof2  --> \n", ++aesl_llvm_cbe_189_count);
  llvm_cbe_tmp__91 = (unsigned int )((unsigned int )(llvm_cbe_tmp__90&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__89&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__91&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = zext i32 %%24 to i64, !dbg !33 for 0x%I64xth hint within @allocateProof2  --> \n", ++aesl_llvm_cbe_190_count);
  llvm_cbe_tmp__92 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__91&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__92);
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = tail call i8* @malloc(i64 %%25), !dbg !33 for 0x%I64xth hint within @allocateProof2  --> \n", ++aesl_llvm_cbe_191_count);
  llvm_cbe_tmp__93 = ( char *) /*tail*/ ( char *)malloc(llvm_cbe_tmp__92);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__92);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__93);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = getelementptr inbounds %%struct.proof2_t* %%proof, i64 0, i32 6, !dbg !33 for 0x%I64xth hint within @allocateProof2  --> \n", ++aesl_llvm_cbe_192_count);
  llvm_cbe_tmp__94 = ( char **)(&llvm_cbe_proof->field6);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8* %%26, i8** %%27, align 8, !dbg !33 for 0x%I64xth hint within @allocateProof2  --> \n", ++aesl_llvm_cbe_193_count);
  *llvm_cbe_tmp__94 = ( char *)llvm_cbe_tmp__93;
  if (AESL_DEBUG_TRACE)
      printf("\nEND @allocateProof2}\n");
  return;
}


void freeProof2(l_struct_OC_proof2_t *llvm_cbe_proof) {
  static  unsigned long long aesl_llvm_cbe_195_count = 0;
  static  unsigned long long aesl_llvm_cbe_196_count = 0;
  static  unsigned long long aesl_llvm_cbe_197_count = 0;
  static  unsigned long long aesl_llvm_cbe_198_count = 0;
  static  unsigned long long aesl_llvm_cbe_199_count = 0;
  static  unsigned long long aesl_llvm_cbe_200_count = 0;
  static  unsigned long long aesl_llvm_cbe_201_count = 0;
   char **llvm_cbe_tmp__95;
  static  unsigned long long aesl_llvm_cbe_202_count = 0;
   char *llvm_cbe_tmp__96;
  static  unsigned long long aesl_llvm_cbe_203_count = 0;
  static  unsigned long long aesl_llvm_cbe_204_count = 0;
   char **llvm_cbe_tmp__97;
  static  unsigned long long aesl_llvm_cbe_205_count = 0;
   char *llvm_cbe_tmp__98;
  static  unsigned long long aesl_llvm_cbe_206_count = 0;
  static  unsigned long long aesl_llvm_cbe_207_count = 0;
   char **llvm_cbe_tmp__99;
  static  unsigned long long aesl_llvm_cbe_208_count = 0;
   char *llvm_cbe_tmp__100;
  static  unsigned long long aesl_llvm_cbe_209_count = 0;
  static  unsigned long long aesl_llvm_cbe_210_count = 0;
   char **llvm_cbe_tmp__101;
  static  unsigned long long aesl_llvm_cbe_211_count = 0;
   char *llvm_cbe_tmp__102;
  static  unsigned long long aesl_llvm_cbe_212_count = 0;
  static  unsigned long long aesl_llvm_cbe_213_count = 0;
   char **llvm_cbe_tmp__103;
  static  unsigned long long aesl_llvm_cbe_214_count = 0;
   char *llvm_cbe_tmp__104;
  static  unsigned long long aesl_llvm_cbe_215_count = 0;
  static  unsigned long long aesl_llvm_cbe_216_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @freeProof2\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.proof2_t* %%proof, i64 0, i32 1, !dbg !33 for 0x%I64xth hint within @freeProof2  --> \n", ++aesl_llvm_cbe_201_count);
  llvm_cbe_tmp__95 = ( char **)(&llvm_cbe_proof->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i8** %%1, align 8, !dbg !33 for 0x%I64xth hint within @freeProof2  --> \n", ++aesl_llvm_cbe_202_count);
  llvm_cbe_tmp__96 = ( char *)*llvm_cbe_tmp__95;
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @free(i8* %%2), !dbg !33 for 0x%I64xth hint within @freeProof2  --> \n", ++aesl_llvm_cbe_203_count);
   /*tail*/ free(( char *)llvm_cbe_tmp__96);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.proof2_t* %%proof, i64 0, i32 4, !dbg !33 for 0x%I64xth hint within @freeProof2  --> \n", ++aesl_llvm_cbe_204_count);
  llvm_cbe_tmp__97 = ( char **)(&llvm_cbe_proof->field4);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i8** %%3, align 8, !dbg !33 for 0x%I64xth hint within @freeProof2  --> \n", ++aesl_llvm_cbe_205_count);
  llvm_cbe_tmp__98 = ( char *)*llvm_cbe_tmp__97;
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @free(i8* %%4), !dbg !33 for 0x%I64xth hint within @freeProof2  --> \n", ++aesl_llvm_cbe_206_count);
   /*tail*/ free(( char *)llvm_cbe_tmp__98);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds %%struct.proof2_t* %%proof, i64 0, i32 5, !dbg !33 for 0x%I64xth hint within @freeProof2  --> \n", ++aesl_llvm_cbe_207_count);
  llvm_cbe_tmp__99 = ( char **)(&llvm_cbe_proof->field5);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load i8** %%5, align 8, !dbg !33 for 0x%I64xth hint within @freeProof2  --> \n", ++aesl_llvm_cbe_208_count);
  llvm_cbe_tmp__100 = ( char *)*llvm_cbe_tmp__99;
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @free(i8* %%6), !dbg !33 for 0x%I64xth hint within @freeProof2  --> \n", ++aesl_llvm_cbe_209_count);
   /*tail*/ free(( char *)llvm_cbe_tmp__100);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds %%struct.proof2_t* %%proof, i64 0, i32 3, !dbg !33 for 0x%I64xth hint within @freeProof2  --> \n", ++aesl_llvm_cbe_210_count);
  llvm_cbe_tmp__101 = ( char **)(&llvm_cbe_proof->field3);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load i8** %%7, align 8, !dbg !33 for 0x%I64xth hint within @freeProof2  --> \n", ++aesl_llvm_cbe_211_count);
  llvm_cbe_tmp__102 = ( char *)*llvm_cbe_tmp__101;
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @free(i8* %%8), !dbg !33 for 0x%I64xth hint within @freeProof2  --> \n", ++aesl_llvm_cbe_212_count);
   /*tail*/ free(( char *)llvm_cbe_tmp__102);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds %%struct.proof2_t* %%proof, i64 0, i32 6, !dbg !33 for 0x%I64xth hint within @freeProof2  --> \n", ++aesl_llvm_cbe_213_count);
  llvm_cbe_tmp__103 = ( char **)(&llvm_cbe_proof->field6);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = load i8** %%9, align 8, !dbg !33 for 0x%I64xth hint within @freeProof2  --> \n", ++aesl_llvm_cbe_214_count);
  llvm_cbe_tmp__104 = ( char *)*llvm_cbe_tmp__103;
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @free(i8* %%10), !dbg !33 for 0x%I64xth hint within @freeProof2  --> \n", ++aesl_llvm_cbe_215_count);
   /*tail*/ free(( char *)llvm_cbe_tmp__104);
if (AESL_DEBUG_TRACE) {
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @freeProof2}\n");
  return;
}


void allocateProof(l_struct_OC_proof_t *llvm_cbe_proof, l_struct_OC_paramset_t *llvm_cbe_params) {
  static  unsigned long long aesl_llvm_cbe_217_count = 0;
  static  unsigned long long aesl_llvm_cbe_218_count = 0;
  static  unsigned long long aesl_llvm_cbe_219_count = 0;
const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @allocateProof\n");
  if (AESL_DEBUG_TRACE)
      printf("\nEND @allocateProof}\n");
  return;
}


void freeProof(l_struct_OC_proof_t *llvm_cbe_proof) {
  static  unsigned long long aesl_llvm_cbe_220_count = 0;
  static  unsigned long long aesl_llvm_cbe_221_count = 0;
const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @freeProof\n");
  if (AESL_DEBUG_TRACE)
      printf("\nEND @freeProof}\n");
  return;
}


void allocateSignature(l_struct_OC_signature_t *llvm_cbe_sig, l_struct_OC_paramset_t *llvm_cbe_params) {
  static  unsigned long long aesl_llvm_cbe_222_count = 0;
  static  unsigned long long aesl_llvm_cbe_223_count = 0;
  static  unsigned long long aesl_llvm_cbe_224_count = 0;
const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @allocateSignature\n");
  if (AESL_DEBUG_TRACE)
      printf("\nEND @allocateSignature}\n");
  return;
}


void freeSignature(l_struct_OC_signature_t *llvm_cbe_sig, l_struct_OC_paramset_t *llvm_cbe_params) {
  static  unsigned long long aesl_llvm_cbe_225_count = 0;
  static  unsigned long long aesl_llvm_cbe_226_count = 0;
  static  unsigned long long aesl_llvm_cbe_227_count = 0;
const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @freeSignature\n");
  if (AESL_DEBUG_TRACE)
      printf("\nEND @freeSignature}\n");
  return;
}


void allocateSignature2(l_struct_OC_signature2_t *llvm_cbe_sig, l_struct_OC_paramset_t *llvm_cbe_params) {
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
  static  unsigned long long aesl_llvm_cbe_239_count = 0;
  static  unsigned long long aesl_llvm_cbe_240_count = 0;
  static  unsigned long long aesl_llvm_cbe_241_count = 0;
  static  unsigned long long aesl_llvm_cbe_242_count = 0;
  signed int *llvm_cbe_tmp__105;
  static  unsigned long long aesl_llvm_cbe_243_count = 0;
  unsigned int llvm_cbe_tmp__106;
  static  unsigned long long aesl_llvm_cbe_244_count = 0;
  unsigned long long llvm_cbe_tmp__107;
  static  unsigned long long aesl_llvm_cbe_245_count = 0;
   char *llvm_cbe_tmp__108;
  static  unsigned long long aesl_llvm_cbe_246_count = 0;
   char **llvm_cbe_tmp__109;
  static  unsigned long long aesl_llvm_cbe_247_count = 0;
  static  unsigned long long aesl_llvm_cbe_248_count = 0;
   char **llvm_cbe_tmp__110;
  static  unsigned long long aesl_llvm_cbe_249_count = 0;
  signed int *llvm_cbe_tmp__111;
  static  unsigned long long aesl_llvm_cbe_250_count = 0;
   char *llvm_cbe_tmp__112;
  static  unsigned long long aesl_llvm_cbe_251_count = 0;
   char *llvm_cbe_tmp__113;
  static  unsigned long long aesl_llvm_cbe_252_count = 0;
  unsigned int llvm_cbe_tmp__114;
  static  unsigned long long aesl_llvm_cbe_253_count = 0;
  unsigned long long llvm_cbe_tmp__115;
  static  unsigned long long aesl_llvm_cbe_254_count = 0;
  unsigned long long llvm_cbe_tmp__116;
  static  unsigned long long aesl_llvm_cbe_255_count = 0;
   char *llvm_cbe_tmp__117;
  static  unsigned long long aesl_llvm_cbe_256_count = 0;
  signed short *llvm_cbe_tmp__118;
  static  unsigned long long aesl_llvm_cbe_257_count = 0;
  signed short **llvm_cbe_tmp__119;
  static  unsigned long long aesl_llvm_cbe_258_count = 0;
  static  unsigned long long aesl_llvm_cbe_259_count = 0;
  unsigned int llvm_cbe_tmp__120;
  static  unsigned long long aesl_llvm_cbe_260_count = 0;
  unsigned long long llvm_cbe_tmp__121;
  static  unsigned long long aesl_llvm_cbe_261_count = 0;
  unsigned long long llvm_cbe_tmp__122;
  static  unsigned long long aesl_llvm_cbe_262_count = 0;
   char *llvm_cbe_tmp__123;
  static  unsigned long long aesl_llvm_cbe_263_count = 0;
  signed short *llvm_cbe_tmp__124;
  static  unsigned long long aesl_llvm_cbe_264_count = 0;
  signed short **llvm_cbe_tmp__125;
  static  unsigned long long aesl_llvm_cbe_265_count = 0;
  static  unsigned long long aesl_llvm_cbe_266_count = 0;
  signed int *llvm_cbe_tmp__126;
  static  unsigned long long aesl_llvm_cbe_267_count = 0;
  unsigned int llvm_cbe_tmp__127;
  static  unsigned long long aesl_llvm_cbe_268_count = 0;
  unsigned long long llvm_cbe_tmp__128;
  static  unsigned long long aesl_llvm_cbe_269_count = 0;
   char *llvm_cbe_tmp__129;
  static  unsigned long long aesl_llvm_cbe_270_count = 0;
  l_struct_OC_proof2_t *llvm_cbe_tmp__130;
  static  unsigned long long aesl_llvm_cbe_271_count = 0;
  l_struct_OC_proof2_t **llvm_cbe_tmp__131;
  static  unsigned long long aesl_llvm_cbe_272_count = 0;
  static  unsigned long long aesl_llvm_cbe_273_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @allocateSignature2\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.paramset_t* %%params, i64 0, i32 12, !dbg !33 for 0x%I64xth hint within @allocateSignature2  --> \n", ++aesl_llvm_cbe_242_count);
  llvm_cbe_tmp__105 = (signed int *)(&llvm_cbe_params->field12);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i32* %%1, align 4, !dbg !33 for 0x%I64xth hint within @allocateSignature2  --> \n", ++aesl_llvm_cbe_243_count);
  llvm_cbe_tmp__106 = (unsigned int )*llvm_cbe_tmp__105;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__106);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = zext i32 %%2 to i64, !dbg !33 for 0x%I64xth hint within @allocateSignature2  --> \n", ++aesl_llvm_cbe_244_count);
  llvm_cbe_tmp__107 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__106&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__107);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = tail call i8* @malloc(i64 %%3), !dbg !33 for 0x%I64xth hint within @allocateSignature2  --> \n", ++aesl_llvm_cbe_245_count);
  llvm_cbe_tmp__108 = ( char *) /*tail*/ ( char *)malloc(llvm_cbe_tmp__107);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__107);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__108);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds %%struct.signature2_t* %%sig, i64 0, i32 0, !dbg !33 for 0x%I64xth hint within @allocateSignature2  --> \n", ++aesl_llvm_cbe_246_count);
  llvm_cbe_tmp__109 = ( char **)(&llvm_cbe_sig->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8* %%4, i8** %%5, align 8, !dbg !33 for 0x%I64xth hint within @allocateSignature2  --> \n", ++aesl_llvm_cbe_247_count);
  *llvm_cbe_tmp__109 = ( char *)llvm_cbe_tmp__108;
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds %%struct.signature2_t* %%sig, i64 0, i32 1, !dbg !33 for 0x%I64xth hint within @allocateSignature2  --> \n", ++aesl_llvm_cbe_248_count);
  llvm_cbe_tmp__110 = ( char **)(&llvm_cbe_sig->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds %%struct.paramset_t* %%params, i64 0, i32 9, !dbg !33 for 0x%I64xth hint within @allocateSignature2  --> \n", ++aesl_llvm_cbe_249_count);
  llvm_cbe_tmp__111 = (signed int *)(&llvm_cbe_params->field9);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = bitcast i8** %%6 to i8*, !dbg !33 for 0x%I64xth hint within @allocateSignature2  --> \n", ++aesl_llvm_cbe_250_count);
  llvm_cbe_tmp__112 = ( char *)(( char *)llvm_cbe_tmp__110);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = call i8* @memset(i8* %%8, i32 0, i64 32 for 0x%I64xth hint within @allocateSignature2  --> \n", ++aesl_llvm_cbe_251_count);
  ( char *)memset(( char *)llvm_cbe_tmp__112, 0u, 32ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",32ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__113);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = load i32* %%7, align 4, !dbg !33 for 0x%I64xth hint within @allocateSignature2  --> \n", ++aesl_llvm_cbe_252_count);
  llvm_cbe_tmp__114 = (unsigned int )*llvm_cbe_tmp__111;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__114);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = zext i32 %%10 to i64, !dbg !33 for 0x%I64xth hint within @allocateSignature2  --> \n", ++aesl_llvm_cbe_253_count);
  llvm_cbe_tmp__115 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__114&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__115);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = shl nuw nsw i64 %%11, 1, !dbg !33 for 0x%I64xth hint within @allocateSignature2  --> \n", ++aesl_llvm_cbe_254_count);
  llvm_cbe_tmp__116 = (unsigned long long )llvm_cbe_tmp__115 << 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__116);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = tail call i8* @malloc(i64 %%12), !dbg !33 for 0x%I64xth hint within @allocateSignature2  --> \n", ++aesl_llvm_cbe_255_count);
  llvm_cbe_tmp__117 = ( char *) /*tail*/ ( char *)malloc(llvm_cbe_tmp__116);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__116);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__117);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = bitcast i8* %%13 to i16*, !dbg !33 for 0x%I64xth hint within @allocateSignature2  --> \n", ++aesl_llvm_cbe_256_count);
  llvm_cbe_tmp__118 = (signed short *)((signed short *)llvm_cbe_tmp__117);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds %%struct.signature2_t* %%sig, i64 0, i32 5, !dbg !33 for 0x%I64xth hint within @allocateSignature2  --> \n", ++aesl_llvm_cbe_257_count);
  llvm_cbe_tmp__119 = (signed short **)(&llvm_cbe_sig->field5);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i16* %%14, i16** %%15, align 8, !dbg !33 for 0x%I64xth hint within @allocateSignature2  --> \n", ++aesl_llvm_cbe_258_count);
  *llvm_cbe_tmp__119 = (signed short *)llvm_cbe_tmp__118;
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = load i32* %%7, align 4, !dbg !33 for 0x%I64xth hint within @allocateSignature2  --> \n", ++aesl_llvm_cbe_259_count);
  llvm_cbe_tmp__120 = (unsigned int )*llvm_cbe_tmp__111;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__120);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = zext i32 %%16 to i64, !dbg !33 for 0x%I64xth hint within @allocateSignature2  --> \n", ++aesl_llvm_cbe_260_count);
  llvm_cbe_tmp__121 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__120&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__121);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = shl nuw nsw i64 %%17, 1, !dbg !33 for 0x%I64xth hint within @allocateSignature2  --> \n", ++aesl_llvm_cbe_261_count);
  llvm_cbe_tmp__122 = (unsigned long long )llvm_cbe_tmp__121 << 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__122);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = tail call i8* @malloc(i64 %%18), !dbg !33 for 0x%I64xth hint within @allocateSignature2  --> \n", ++aesl_llvm_cbe_262_count);
  llvm_cbe_tmp__123 = ( char *) /*tail*/ ( char *)malloc(llvm_cbe_tmp__122);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__122);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__123);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = bitcast i8* %%19 to i16*, !dbg !33 for 0x%I64xth hint within @allocateSignature2  --> \n", ++aesl_llvm_cbe_263_count);
  llvm_cbe_tmp__124 = (signed short *)((signed short *)llvm_cbe_tmp__123);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = getelementptr inbounds %%struct.signature2_t* %%sig, i64 0, i32 6, !dbg !33 for 0x%I64xth hint within @allocateSignature2  --> \n", ++aesl_llvm_cbe_264_count);
  llvm_cbe_tmp__125 = (signed short **)(&llvm_cbe_sig->field6);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i16* %%20, i16** %%21, align 8, !dbg !33 for 0x%I64xth hint within @allocateSignature2  --> \n", ++aesl_llvm_cbe_265_count);
  *llvm_cbe_tmp__125 = (signed short *)llvm_cbe_tmp__124;
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = getelementptr inbounds %%struct.paramset_t* %%params, i64 0, i32 8, !dbg !33 for 0x%I64xth hint within @allocateSignature2  --> \n", ++aesl_llvm_cbe_266_count);
  llvm_cbe_tmp__126 = (signed int *)(&llvm_cbe_params->field8);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = load i32* %%22, align 4, !dbg !33 for 0x%I64xth hint within @allocateSignature2  --> \n", ++aesl_llvm_cbe_267_count);
  llvm_cbe_tmp__127 = (unsigned int )*llvm_cbe_tmp__126;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__127);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = zext i32 %%23 to i64, !dbg !33 for 0x%I64xth hint within @allocateSignature2  --> \n", ++aesl_llvm_cbe_268_count);
  llvm_cbe_tmp__128 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__127&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__128);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = tail call i8* @calloc(i64 %%24, i64 56) nounwind, !dbg !33 for 0x%I64xth hint within @allocateSignature2  --> \n", ++aesl_llvm_cbe_269_count);
  llvm_cbe_tmp__129 = ( char *) /*tail*/ ( char *)calloc(llvm_cbe_tmp__128, 56ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__128);
printf("\nArgument  = 0x%I64X",56ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__129);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = bitcast i8* %%25 to %%struct.proof2_t*, !dbg !33 for 0x%I64xth hint within @allocateSignature2  --> \n", ++aesl_llvm_cbe_270_count);
  llvm_cbe_tmp__130 = (l_struct_OC_proof2_t *)((l_struct_OC_proof2_t *)llvm_cbe_tmp__129);
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = getelementptr inbounds %%struct.signature2_t* %%sig, i64 0, i32 7, !dbg !33 for 0x%I64xth hint within @allocateSignature2  --> \n", ++aesl_llvm_cbe_271_count);
  llvm_cbe_tmp__131 = (l_struct_OC_proof2_t **)(&llvm_cbe_sig->field7);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store %%struct.proof2_t* %%26, %%struct.proof2_t** %%27, align 8, !dbg !33 for 0x%I64xth hint within @allocateSignature2  --> \n", ++aesl_llvm_cbe_272_count);
  *llvm_cbe_tmp__131 = (l_struct_OC_proof2_t *)llvm_cbe_tmp__130;
  if (AESL_DEBUG_TRACE)
      printf("\nEND @allocateSignature2}\n");
  return;
}


void freeSignature2(l_struct_OC_signature2_t *llvm_cbe_sig, l_struct_OC_paramset_t *llvm_cbe_params) {
  static  unsigned long long aesl_llvm_cbe_274_count = 0;
  static  unsigned long long aesl_llvm_cbe_275_count = 0;
  static  unsigned long long aesl_llvm_cbe_276_count = 0;
  static  unsigned long long aesl_llvm_cbe_277_count = 0;
  static  unsigned long long aesl_llvm_cbe_278_count = 0;
  static  unsigned long long aesl_llvm_cbe_279_count = 0;
  static  unsigned long long aesl_llvm_cbe_280_count = 0;
  static  unsigned long long aesl_llvm_cbe_281_count = 0;
  static  unsigned long long aesl_llvm_cbe_282_count = 0;
  static  unsigned long long aesl_llvm_cbe_283_count = 0;
  static  unsigned long long aesl_llvm_cbe_284_count = 0;
   char **llvm_cbe_tmp__132;
  static  unsigned long long aesl_llvm_cbe_285_count = 0;
   char *llvm_cbe_tmp__133;
  static  unsigned long long aesl_llvm_cbe_286_count = 0;
  static  unsigned long long aesl_llvm_cbe_287_count = 0;
   char **llvm_cbe_tmp__134;
  static  unsigned long long aesl_llvm_cbe_288_count = 0;
   char *llvm_cbe_tmp__135;
  static  unsigned long long aesl_llvm_cbe_289_count = 0;
  static  unsigned long long aesl_llvm_cbe_290_count = 0;
   char **llvm_cbe_tmp__136;
  static  unsigned long long aesl_llvm_cbe_291_count = 0;
   char *llvm_cbe_tmp__137;
  static  unsigned long long aesl_llvm_cbe_292_count = 0;
  static  unsigned long long aesl_llvm_cbe_293_count = 0;
  signed short **llvm_cbe_tmp__138;
  static  unsigned long long aesl_llvm_cbe_294_count = 0;
  signed short *llvm_cbe_tmp__139;
  static  unsigned long long aesl_llvm_cbe_295_count = 0;
   char *llvm_cbe_tmp__140;
  static  unsigned long long aesl_llvm_cbe_296_count = 0;
  static  unsigned long long aesl_llvm_cbe_297_count = 0;
  signed short **llvm_cbe_tmp__141;
  static  unsigned long long aesl_llvm_cbe_298_count = 0;
  signed short *llvm_cbe_tmp__142;
  static  unsigned long long aesl_llvm_cbe_299_count = 0;
   char *llvm_cbe_tmp__143;
  static  unsigned long long aesl_llvm_cbe_300_count = 0;
  static  unsigned long long aesl_llvm_cbe_301_count = 0;
  static  unsigned long long aesl_llvm_cbe_302_count = 0;
  static  unsigned long long aesl_llvm_cbe_303_count = 0;
  static  unsigned long long aesl_llvm_cbe_304_count = 0;
  static  unsigned long long aesl_llvm_cbe_305_count = 0;
  signed int *llvm_cbe_tmp__144;
  static  unsigned long long aesl_llvm_cbe_306_count = 0;
  unsigned int llvm_cbe_tmp__145;
  static  unsigned long long aesl_llvm_cbe_307_count = 0;
  static  unsigned long long aesl_llvm_cbe_308_count = 0;
  static  unsigned long long aesl_llvm_cbe_309_count = 0;
  l_struct_OC_proof2_t **llvm_cbe_tmp__146;
  static  unsigned long long aesl_llvm_cbe_310_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned long long llvm_cbe_storemerge1;
  unsigned long long llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_311_count = 0;
  l_struct_OC_proof2_t *llvm_cbe_tmp__147;
  static  unsigned long long aesl_llvm_cbe_312_count = 0;
  l_struct_OC_proof2_t *llvm_cbe_tmp__148;
  static  unsigned long long aesl_llvm_cbe_313_count = 0;
  static  unsigned long long aesl_llvm_cbe_314_count = 0;
  unsigned long long llvm_cbe_tmp__149;
  static  unsigned long long aesl_llvm_cbe_315_count = 0;
  static  unsigned long long aesl_llvm_cbe_316_count = 0;
  static  unsigned long long aesl_llvm_cbe_317_count = 0;
  static  unsigned long long aesl_llvm_cbe_318_count = 0;
  static  unsigned long long aesl_llvm_cbe_319_count = 0;
  unsigned int llvm_cbe_tmp__150;
  static  unsigned long long aesl_llvm_cbe_320_count = 0;
  unsigned long long llvm_cbe_tmp__151;
  static  unsigned long long aesl_llvm_cbe_321_count = 0;
  static  unsigned long long aesl_llvm_cbe_322_count = 0;
  static  unsigned long long aesl_llvm_cbe_323_count = 0;
  l_struct_OC_proof2_t **llvm_cbe_tmp__152;
  static  unsigned long long aesl_llvm_cbe_324_count = 0;
  l_struct_OC_proof2_t *llvm_cbe_tmp__153;
  static  unsigned long long aesl_llvm_cbe_325_count = 0;
   char *llvm_cbe_tmp__154;
  static  unsigned long long aesl_llvm_cbe_326_count = 0;
  static  unsigned long long aesl_llvm_cbe_327_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @freeSignature2\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.signature2_t* %%sig, i64 0, i32 0, !dbg !33 for 0x%I64xth hint within @freeSignature2  --> \n", ++aesl_llvm_cbe_284_count);
  llvm_cbe_tmp__132 = ( char **)(&llvm_cbe_sig->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i8** %%1, align 8, !dbg !33 for 0x%I64xth hint within @freeSignature2  --> \n", ++aesl_llvm_cbe_285_count);
  llvm_cbe_tmp__133 = ( char *)*llvm_cbe_tmp__132;
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @free(i8* %%2), !dbg !33 for 0x%I64xth hint within @freeSignature2  --> \n", ++aesl_llvm_cbe_286_count);
   /*tail*/ free(( char *)llvm_cbe_tmp__133);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.signature2_t* %%sig, i64 0, i32 1, !dbg !33 for 0x%I64xth hint within @freeSignature2  --> \n", ++aesl_llvm_cbe_287_count);
  llvm_cbe_tmp__134 = ( char **)(&llvm_cbe_sig->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i8** %%3, align 8, !dbg !33 for 0x%I64xth hint within @freeSignature2  --> \n", ++aesl_llvm_cbe_288_count);
  llvm_cbe_tmp__135 = ( char *)*llvm_cbe_tmp__134;
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @free(i8* %%4), !dbg !33 for 0x%I64xth hint within @freeSignature2  --> \n", ++aesl_llvm_cbe_289_count);
   /*tail*/ free(( char *)llvm_cbe_tmp__135);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds %%struct.signature2_t* %%sig, i64 0, i32 3, !dbg !33 for 0x%I64xth hint within @freeSignature2  --> \n", ++aesl_llvm_cbe_290_count);
  llvm_cbe_tmp__136 = ( char **)(&llvm_cbe_sig->field3);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load i8** %%5, align 8, !dbg !33 for 0x%I64xth hint within @freeSignature2  --> \n", ++aesl_llvm_cbe_291_count);
  llvm_cbe_tmp__137 = ( char *)*llvm_cbe_tmp__136;
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @free(i8* %%6), !dbg !33 for 0x%I64xth hint within @freeSignature2  --> \n", ++aesl_llvm_cbe_292_count);
   /*tail*/ free(( char *)llvm_cbe_tmp__137);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds %%struct.signature2_t* %%sig, i64 0, i32 5, !dbg !33 for 0x%I64xth hint within @freeSignature2  --> \n", ++aesl_llvm_cbe_293_count);
  llvm_cbe_tmp__138 = (signed short **)(&llvm_cbe_sig->field5);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load i16** %%7, align 8, !dbg !33 for 0x%I64xth hint within @freeSignature2  --> \n", ++aesl_llvm_cbe_294_count);
  llvm_cbe_tmp__139 = (signed short *)*llvm_cbe_tmp__138;
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = bitcast i16* %%8 to i8*, !dbg !33 for 0x%I64xth hint within @freeSignature2  --> \n", ++aesl_llvm_cbe_295_count);
  llvm_cbe_tmp__140 = ( char *)(( char *)llvm_cbe_tmp__139);
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @free(i8* %%9), !dbg !33 for 0x%I64xth hint within @freeSignature2  --> \n", ++aesl_llvm_cbe_296_count);
   /*tail*/ free(( char *)llvm_cbe_tmp__140);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds %%struct.signature2_t* %%sig, i64 0, i32 6, !dbg !33 for 0x%I64xth hint within @freeSignature2  --> \n", ++aesl_llvm_cbe_297_count);
  llvm_cbe_tmp__141 = (signed short **)(&llvm_cbe_sig->field6);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = load i16** %%10, align 8, !dbg !33 for 0x%I64xth hint within @freeSignature2  --> \n", ++aesl_llvm_cbe_298_count);
  llvm_cbe_tmp__142 = (signed short *)*llvm_cbe_tmp__141;
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = bitcast i16* %%11 to i8*, !dbg !33 for 0x%I64xth hint within @freeSignature2  --> \n", ++aesl_llvm_cbe_299_count);
  llvm_cbe_tmp__143 = ( char *)(( char *)llvm_cbe_tmp__142);
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @free(i8* %%12), !dbg !33 for 0x%I64xth hint within @freeSignature2  --> \n", ++aesl_llvm_cbe_300_count);
   /*tail*/ free(( char *)llvm_cbe_tmp__143);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds %%struct.paramset_t* %%params, i64 0, i32 8, !dbg !34 for 0x%I64xth hint within @freeSignature2  --> \n", ++aesl_llvm_cbe_305_count);
  llvm_cbe_tmp__144 = (signed int *)(&llvm_cbe_params->field8);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load i32* %%13, align 4, !dbg !34 for 0x%I64xth hint within @freeSignature2  --> \n", ++aesl_llvm_cbe_306_count);
  llvm_cbe_tmp__145 = (unsigned int )*llvm_cbe_tmp__144;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__145);
  if (((llvm_cbe_tmp__145&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    goto llvm_cbe__2e_lr_2e_ph;
  }

llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds %%struct.signature2_t* %%sig, i64 0, i32 7, !dbg !33 for 0x%I64xth hint within @freeSignature2  --> \n", ++aesl_llvm_cbe_309_count);
  llvm_cbe_tmp__146 = (l_struct_OC_proof2_t **)(&llvm_cbe_sig->field7);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__155;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__155:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i64 [ 0, %%.lr.ph ], [ %%20, %%17  for 0x%I64xth hint within @freeSignature2  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned long long )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",llvm_cbe_storemerge1);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__149);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = load %%struct.proof2_t** %%16, align 8, !dbg !33 for 0x%I64xth hint within @freeSignature2  --> \n", ++aesl_llvm_cbe_311_count);
  llvm_cbe_tmp__147 = (l_struct_OC_proof2_t *)*llvm_cbe_tmp__146;
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = getelementptr inbounds %%struct.proof2_t* %%18, i64 %%storemerge1, !dbg !33 for 0x%I64xth hint within @freeSignature2  --> \n", ++aesl_llvm_cbe_312_count);
  llvm_cbe_tmp__148 = (l_struct_OC_proof2_t *)(&llvm_cbe_tmp__147[(((signed long long )llvm_cbe_storemerge1))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",((signed long long )llvm_cbe_storemerge1));
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @freeProof2(%%struct.proof2_t* %%19), !dbg !33 for 0x%I64xth hint within @freeSignature2  --> \n", ++aesl_llvm_cbe_313_count);
   /*tail*/ freeProof2((l_struct_OC_proof2_t *)llvm_cbe_tmp__148);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = add i64 %%storemerge1, 1, !dbg !34 for 0x%I64xth hint within @freeSignature2  --> \n", ++aesl_llvm_cbe_314_count);
  llvm_cbe_tmp__149 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__149&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = load i32* %%13, align 4, !dbg !34 for 0x%I64xth hint within @freeSignature2  --> \n", ++aesl_llvm_cbe_319_count);
  llvm_cbe_tmp__150 = (unsigned int )*llvm_cbe_tmp__144;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__150);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = zext i32 %%21 to i64, !dbg !34 for 0x%I64xth hint within @freeSignature2  --> \n", ++aesl_llvm_cbe_320_count);
  llvm_cbe_tmp__151 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__150&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__151);
  if ((((unsigned long long )llvm_cbe_tmp__149&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__151&18446744073709551615ULL))) {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__149;   /* for PHI node */
    goto llvm_cbe_tmp__155;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = getelementptr inbounds %%struct.signature2_t* %%sig, i64 0, i32 7, !dbg !34 for 0x%I64xth hint within @freeSignature2  --> \n", ++aesl_llvm_cbe_323_count);
  llvm_cbe_tmp__152 = (l_struct_OC_proof2_t **)(&llvm_cbe_sig->field7);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = load %%struct.proof2_t** %%24, align 8, !dbg !34 for 0x%I64xth hint within @freeSignature2  --> \n", ++aesl_llvm_cbe_324_count);
  llvm_cbe_tmp__153 = (l_struct_OC_proof2_t *)*llvm_cbe_tmp__152;
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = bitcast %%struct.proof2_t* %%25 to i8*, !dbg !34 for 0x%I64xth hint within @freeSignature2  --> \n", ++aesl_llvm_cbe_325_count);
  llvm_cbe_tmp__154 = ( char *)(( char *)llvm_cbe_tmp__153);
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @free(i8* %%26), !dbg !34 for 0x%I64xth hint within @freeSignature2  --> \n", ++aesl_llvm_cbe_326_count);
   /*tail*/ free(( char *)llvm_cbe_tmp__154);
if (AESL_DEBUG_TRACE) {
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @freeSignature2}\n");
  return;
}


l_struct_OC_seeds_t *allocateSeeds(l_struct_OC_paramset_t *llvm_cbe_params) {
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
  signed int *llvm_cbe_tmp__156;
  static  unsigned long long aesl_llvm_cbe_347_count = 0;
  unsigned int llvm_cbe_tmp__157;
  static  unsigned long long aesl_llvm_cbe_348_count = 0;
  unsigned int llvm_cbe_tmp__158;
  static  unsigned long long aesl_llvm_cbe_349_count = 0;
  unsigned long long llvm_cbe_tmp__159;
  static  unsigned long long aesl_llvm_cbe_350_count = 0;
  unsigned long long llvm_cbe_tmp__160;
  static  unsigned long long aesl_llvm_cbe_351_count = 0;
   char *llvm_cbe_tmp__161;
  static  unsigned long long aesl_llvm_cbe_352_count = 0;
  l_struct_OC_seeds_t *llvm_cbe_tmp__162;
  static  unsigned long long aesl_llvm_cbe_353_count = 0;
  static  unsigned long long aesl_llvm_cbe_354_count = 0;
  static  unsigned long long aesl_llvm_cbe_355_count = 0;
  static  unsigned long long aesl_llvm_cbe_356_count = 0;
  static  unsigned long long aesl_llvm_cbe_357_count = 0;
  static  unsigned long long aesl_llvm_cbe_358_count = 0;
  static  unsigned long long aesl_llvm_cbe_359_count = 0;
  static  unsigned long long aesl_llvm_cbe_360_count = 0;
  static  unsigned long long aesl_llvm_cbe_361_count = 0;
  signed int *llvm_cbe_tmp__163;
  static  unsigned long long aesl_llvm_cbe_362_count = 0;
  unsigned int llvm_cbe_tmp__164;
  static  unsigned long long aesl_llvm_cbe_363_count = 0;
  unsigned long long llvm_cbe_tmp__165;
  static  unsigned long long aesl_llvm_cbe_364_count = 0;
  static  unsigned long long aesl_llvm_cbe_365_count = 0;
  static  unsigned long long aesl_llvm_cbe_366_count = 0;
  static  unsigned long long aesl_llvm_cbe_367_count = 0;
  static  unsigned long long aesl_llvm_cbe_368_count = 0;
  static  unsigned long long aesl_llvm_cbe_369_count = 0;
  unsigned long long llvm_cbe_tmp__166;
  static  unsigned long long aesl_llvm_cbe_370_count = 0;
  signed int *llvm_cbe_tmp__167;
  static  unsigned long long aesl_llvm_cbe_371_count = 0;
  unsigned int llvm_cbe_tmp__168;
  static  unsigned long long aesl_llvm_cbe_372_count = 0;
  unsigned long long llvm_cbe_tmp__169;
  static  unsigned long long aesl_llvm_cbe_373_count = 0;
  unsigned long long llvm_cbe_tmp__170;
  static  unsigned long long aesl_llvm_cbe_374_count = 0;
  unsigned long long llvm_cbe_tmp__171;
  static  unsigned long long aesl_llvm_cbe_375_count = 0;
  signed int *llvm_cbe_tmp__172;
  static  unsigned long long aesl_llvm_cbe_376_count = 0;
  unsigned int llvm_cbe_tmp__173;
  static  unsigned long long aesl_llvm_cbe_377_count = 0;
  unsigned long long llvm_cbe_tmp__174;
  static  unsigned long long aesl_llvm_cbe_378_count = 0;
  unsigned long long llvm_cbe_tmp__175;
  static  unsigned long long aesl_llvm_cbe_379_count = 0;
   char *llvm_cbe_tmp__176;
  static  unsigned long long aesl_llvm_cbe_380_count = 0;
  static  unsigned long long aesl_llvm_cbe_381_count = 0;
  static  unsigned long long aesl_llvm_cbe_382_count = 0;
  static  unsigned long long aesl_llvm_cbe_383_count = 0;
  static  unsigned long long aesl_llvm_cbe_tmp_count = 0;
  unsigned long long llvm_cbe_tmp;
  static  unsigned long long aesl_llvm_cbe_tmp2_count = 0;
  unsigned long long llvm_cbe_tmp2;
  static  unsigned long long aesl_llvm_cbe_384_count = 0;
  unsigned long long llvm_cbe_tmp__177;
  static  unsigned long long aesl_llvm_cbe_385_count = 0;
   char *llvm_cbe_tmp__178;
  static  unsigned long long aesl_llvm_cbe_386_count = 0;
  static  unsigned long long aesl_llvm_cbe_387_count = 0;
  static  unsigned long long aesl_llvm_cbe_388_count = 0;
  static  unsigned long long aesl_llvm_cbe_389_count = 0;
  unsigned int llvm_cbe_tmp__179;
  static  unsigned long long aesl_llvm_cbe_390_count = 0;
  unsigned int llvm_cbe_tmp__180;
  static  unsigned long long aesl_llvm_cbe_391_count = 0;
  unsigned long long llvm_cbe_tmp__181;
  static  unsigned long long aesl_llvm_cbe_392_count = 0;
   char *llvm_cbe_tmp__182;
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
  static  unsigned long long aesl_llvm_cbe_405_count = 0;
  unsigned long long llvm_cbe_tmp__183;
  static  unsigned long long aesl_llvm_cbe_406_count = 0;
  static  unsigned long long aesl_llvm_cbe_407_count = 0;
  static  unsigned long long aesl_llvm_cbe_408_count = 0;
  unsigned int llvm_cbe_tmp__184;
  static  unsigned long long aesl_llvm_cbe_409_count = 0;
  static  unsigned long long aesl_llvm_cbe_410_count = 0;
  static  unsigned long long aesl_llvm_cbe_411_count = 0;
  static  unsigned long long aesl_llvm_cbe_412_count = 0;
  static  unsigned long long aesl_llvm_cbe_413_count = 0;
  static  unsigned long long aesl_llvm_cbe_414_count = 0;
  static  unsigned long long aesl_llvm_cbe_415_count = 0;
  unsigned int llvm_cbe_tmp__185;
  static  unsigned long long aesl_llvm_cbe_416_count = 0;
  static  unsigned long long aesl_llvm_cbe_417_count = 0;
  static  unsigned long long aesl_llvm_cbe_418_count = 0;
  unsigned long long llvm_cbe_tmp__186;
  unsigned long long llvm_cbe_tmp__186__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge13_2e_us_count = 0;
  unsigned int llvm_cbe_storemerge13_2e_us;
  unsigned int llvm_cbe_storemerge13_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_rec_count = 0;
  unsigned long long llvm_cbe__2e_rec;
  unsigned long long llvm_cbe__2e_rec__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_419_count = 0;
   char *llvm_cbe_tmp__187;
  static  unsigned long long aesl_llvm_cbe_420_count = 0;
   char **llvm_cbe_tmp__188;
  static  unsigned long long aesl_llvm_cbe_421_count = 0;
  static  unsigned long long aesl_llvm_cbe_422_count = 0;
  unsigned int llvm_cbe_tmp__189;
  static  unsigned long long aesl_llvm_cbe_423_count = 0;
  unsigned long long llvm_cbe_tmp__190;
  static  unsigned long long aesl_llvm_cbe__2e_rec15_count = 0;
  unsigned long long llvm_cbe__2e_rec15;
  static  unsigned long long aesl_llvm_cbe_424_count = 0;
   char *llvm_cbe_tmp__191;
  static  unsigned long long aesl_llvm_cbe_425_count = 0;
  static  unsigned long long aesl_llvm_cbe_426_count = 0;
  static  unsigned long long aesl_llvm_cbe_427_count = 0;
  static  unsigned long long aesl_llvm_cbe_428_count = 0;
  static  unsigned long long aesl_llvm_cbe_429_count = 0;
  unsigned int llvm_cbe_tmp__192;
  static  unsigned long long aesl_llvm_cbe_430_count = 0;
  static  unsigned long long aesl_llvm_cbe_431_count = 0;
  static  unsigned long long aesl_llvm_cbe_432_count = 0;
  static  unsigned long long aesl_llvm_cbe_433_count = 0;
  static  unsigned long long aesl_llvm_cbe_434_count = 0;
  unsigned long long llvm_cbe_tmp__193;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_435_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge7_2e_us_count = 0;
  unsigned int llvm_cbe_storemerge7_2e_us;
  unsigned int llvm_cbe_storemerge7_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_436_count = 0;
   char *llvm_cbe_tmp__194;
   char *llvm_cbe_tmp__194__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_rec18_count = 0;
  unsigned long long llvm_cbe__2e_rec18;
  unsigned long long llvm_cbe__2e_rec18__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_rec20_count = 0;
  unsigned long long llvm_cbe__2e_rec20;
  unsigned long long llvm_cbe__2e_rec20__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_437_count = 0;
   char *llvm_cbe_tmp__195;
  static  unsigned long long aesl_llvm_cbe_438_count = 0;
   char *llvm_cbe_tmp__196;
  static  unsigned long long aesl_llvm_cbe_439_count = 0;
   char **llvm_cbe_tmp__197;
  static  unsigned long long aesl_llvm_cbe_440_count = 0;
  unsigned long long llvm_cbe_tmp__198;
  static  unsigned long long aesl_llvm_cbe_441_count = 0;
   char ***llvm_cbe_tmp__199;
  static  unsigned long long aesl_llvm_cbe_442_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_rec19_count = 0;
  unsigned long long llvm_cbe__2e_rec19;
  static  unsigned long long aesl_llvm_cbe_443_count = 0;
   char **llvm_cbe_tmp__200;
  static  unsigned long long aesl_llvm_cbe_444_count = 0;
  static  unsigned long long aesl_llvm_cbe_445_count = 0;
  unsigned int llvm_cbe_tmp__201;
  static  unsigned long long aesl_llvm_cbe_446_count = 0;
  unsigned long long llvm_cbe_tmp__202;
  static  unsigned long long aesl_llvm_cbe__2e_rec21_count = 0;
  unsigned long long llvm_cbe__2e_rec21;
  static  unsigned long long aesl_llvm_cbe_447_count = 0;
  static  unsigned long long aesl_llvm_cbe_448_count = 0;
  static  unsigned long long aesl_llvm_cbe_449_count = 0;
  static  unsigned long long aesl_llvm_cbe_450_count = 0;
  static  unsigned long long aesl_llvm_cbe_451_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge7_count = 0;
  unsigned int llvm_cbe_storemerge7;
  unsigned int llvm_cbe_storemerge7__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_rec24_count = 0;
  unsigned long long llvm_cbe__2e_rec24;
  unsigned long long llvm_cbe__2e_rec24__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_rec26_count = 0;
  unsigned long long llvm_cbe__2e_rec26;
  unsigned long long llvm_cbe__2e_rec26__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_452_count = 0;
   char *llvm_cbe_tmp__203;
  static  unsigned long long aesl_llvm_cbe_453_count = 0;
   char *llvm_cbe_tmp__204;
  static  unsigned long long aesl_llvm_cbe_454_count = 0;
   char **llvm_cbe_tmp__205;
  static  unsigned long long aesl_llvm_cbe_455_count = 0;
  unsigned long long llvm_cbe_tmp__206;
  static  unsigned long long aesl_llvm_cbe_456_count = 0;
   char ***llvm_cbe_tmp__207;
  static  unsigned long long aesl_llvm_cbe_457_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_rec25_count = 0;
  unsigned long long llvm_cbe__2e_rec25;
  static  unsigned long long aesl_llvm_cbe_458_count = 0;
   char **llvm_cbe_tmp__208;
  static  unsigned long long aesl_llvm_cbe_459_count = 0;
  static  unsigned long long aesl_llvm_cbe_460_count = 0;
  unsigned int llvm_cbe_tmp__209;
  static  unsigned long long aesl_llvm_cbe_461_count = 0;
  unsigned long long llvm_cbe_tmp__210;
  static  unsigned long long aesl_llvm_cbe__2e_rec27_count = 0;
  unsigned long long llvm_cbe__2e_rec27;
  static  unsigned long long aesl_llvm_cbe_462_count = 0;
  static  unsigned long long aesl_llvm_cbe_463_count = 0;
  static  unsigned long long aesl_llvm_cbe_464_count = 0;
  static  unsigned long long aesl_llvm_cbe_465_count = 0;
  static  unsigned long long aesl_llvm_cbe_466_count = 0;
  unsigned int llvm_cbe_tmp__211;
  static  unsigned long long aesl_llvm_cbe_467_count = 0;
  static  unsigned long long aesl_llvm_cbe_468_count = 0;
  static  unsigned long long aesl_llvm_cbe_469_count = 0;
  static  unsigned long long aesl_llvm_cbe_470_count = 0;
  static  unsigned long long aesl_llvm_cbe_471_count = 0;
  static  unsigned long long aesl_llvm_cbe_472_count = 0;
  static  unsigned long long aesl_llvm_cbe_473_count = 0;
  unsigned int llvm_cbe_tmp__212;
  static  unsigned long long aesl_llvm_cbe_474_count = 0;
  static  unsigned long long aesl_llvm_cbe_475_count = 0;
  static  unsigned long long aesl_llvm_cbe_split11_count = 0;
  unsigned int llvm_cbe_split11;
  unsigned int llvm_cbe_split11__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_split12_count = 0;
   char *llvm_cbe_split12;
   char *llvm_cbe_split12__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_rec27_2e_pn_count = 0;
  unsigned long long llvm_cbe__2e_rec27_2e_pn;
  unsigned long long llvm_cbe__2e_rec27_2e_pn__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_split13_count = 0;
   char *llvm_cbe_split13;
  static  unsigned long long aesl_llvm_cbe_476_count = 0;
  static  unsigned long long aesl_llvm_cbe_477_count = 0;
  static  unsigned long long aesl_llvm_cbe_478_count = 0;
  unsigned int llvm_cbe_tmp__213;
  unsigned int llvm_cbe_tmp__213__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_lcssa5_count = 0;
   char *llvm_cbe__2e_lcssa5;
   char *llvm_cbe__2e_lcssa5__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_lcssa4_count = 0;
   char *llvm_cbe__2e_lcssa4;
   char *llvm_cbe__2e_lcssa4__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_479_count = 0;
  unsigned long long llvm_cbe_tmp__214;
  static  unsigned long long aesl_llvm_cbe_480_count = 0;
   char ***llvm_cbe_tmp__215;
  static  unsigned long long aesl_llvm_cbe_481_count = 0;
  static  unsigned long long aesl_llvm_cbe_482_count = 0;
  static  unsigned long long aesl_llvm_cbe_483_count = 0;
  static  unsigned long long aesl_llvm_cbe_484_count = 0;
   char **llvm_cbe_tmp__216;
  static  unsigned long long aesl_llvm_cbe_485_count = 0;
  static  unsigned long long aesl_llvm_cbe_486_count = 0;
  static  unsigned long long aesl_llvm_cbe_487_count = 0;
   char **llvm_cbe_tmp__217;
  static  unsigned long long aesl_llvm_cbe_488_count = 0;
  static  unsigned long long aesl_llvm_cbe_489_count = 0;
  static  unsigned long long aesl_llvm_cbe_490_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @allocateSeeds\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.paramset_t* %%params, i64 0, i32 8, !dbg !33 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_346_count);
  llvm_cbe_tmp__156 = (signed int *)(&llvm_cbe_params->field8);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i32* %%1, align 4, !dbg !33 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_347_count);
  llvm_cbe_tmp__157 = (unsigned int )*llvm_cbe_tmp__156;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__157);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = add i32 %%2, 1, !dbg !33 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_348_count);
  llvm_cbe_tmp__158 = (unsigned int )((unsigned int )(llvm_cbe_tmp__157&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__158&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = zext i32 %%3 to i64, !dbg !33 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_349_count);
  llvm_cbe_tmp__159 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__158&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__159);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = shl nuw nsw i64 %%4, 4, !dbg !33 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_350_count);
  llvm_cbe_tmp__160 = (unsigned long long )llvm_cbe_tmp__159 << 4ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__160);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = tail call i8* @malloc(i64 %%5), !dbg !33 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_351_count);
  llvm_cbe_tmp__161 = ( char *) /*tail*/ ( char *)malloc(llvm_cbe_tmp__160);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__160);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__161);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = bitcast i8* %%6 to %%struct.seeds_t*, !dbg !33 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_352_count);
  llvm_cbe_tmp__162 = (l_struct_OC_seeds_t *)((l_struct_OC_seeds_t *)llvm_cbe_tmp__161);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds %%struct.paramset_t* %%params, i64 0, i32 10, !dbg !33 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_361_count);
  llvm_cbe_tmp__163 = (signed int *)(&llvm_cbe_params->field10);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = load i32* %%8, align 4, !dbg !33 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_362_count);
  llvm_cbe_tmp__164 = (unsigned int )*llvm_cbe_tmp__163;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__164);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = zext i32 %%9 to i64, !dbg !33 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_363_count);
  llvm_cbe_tmp__165 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__164&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__165);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = zext i32 %%2 to i64, !dbg !33 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_369_count);
  llvm_cbe_tmp__166 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__157&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__166);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds %%struct.paramset_t* %%params, i64 0, i32 11, !dbg !33 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_370_count);
  llvm_cbe_tmp__167 = (signed int *)(&llvm_cbe_params->field11);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = load i32* %%12, align 4, !dbg !33 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_371_count);
  llvm_cbe_tmp__168 = (unsigned int )*llvm_cbe_tmp__167;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__168);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = zext i32 %%13 to i64, !dbg !33 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_372_count);
  llvm_cbe_tmp__169 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__168&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__169);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = mul i64 %%11, %%10, !dbg !33 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_373_count);
  llvm_cbe_tmp__170 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__166&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__165&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__170&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = mul i64 %%15, %%14, !dbg !33 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_374_count);
  llvm_cbe_tmp__171 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__170&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__169&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__171&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds %%struct.paramset_t* %%params, i64 0, i32 12, !dbg !33 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_375_count);
  llvm_cbe_tmp__172 = (signed int *)(&llvm_cbe_params->field12);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = load i32* %%17, align 4, !dbg !33 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_376_count);
  llvm_cbe_tmp__173 = (unsigned int )*llvm_cbe_tmp__172;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__173);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = zext i32 %%18 to i64, !dbg !33 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_377_count);
  llvm_cbe_tmp__174 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__173&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__174);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = add i64 %%16, %%19, !dbg !33 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_378_count);
  llvm_cbe_tmp__175 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__171&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__174&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__175&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = tail call i8* @malloc(i64 %%20), !dbg !33 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_379_count);
  llvm_cbe_tmp__176 = ( char *) /*tail*/ ( char *)malloc(llvm_cbe_tmp__175);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__175);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__176);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp = add i64 %%15, %%1 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_tmp_count);
  llvm_cbe_tmp = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__170&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__166&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp2 = shl i64 %%tmp,  for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_tmp2_count);
  llvm_cbe_tmp2 = (unsigned long long )llvm_cbe_tmp << 3ull;
if (AESL_DEBUG_TRACE)
printf("\ntmp2 = 0x%I64X\n", llvm_cbe_tmp2);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = add i64 %%tmp2, 8, !dbg !33 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_384_count);
  llvm_cbe_tmp__177 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp2&18446744073709551615ull)) + ((unsigned long long )(8ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__177&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = tail call i8* @malloc(i64 %%22), !dbg !33 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_385_count);
  llvm_cbe_tmp__178 = ( char *) /*tail*/ ( char *)malloc(llvm_cbe_tmp__177);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__177);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__178);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = mul i32 %%13, %%2, !dbg !33 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_389_count);
  llvm_cbe_tmp__179 = (unsigned int )((unsigned int )(llvm_cbe_tmp__168&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__157&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__179&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = add i32 %%24, %%18, !dbg !33 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_390_count);
  llvm_cbe_tmp__180 = (unsigned int )((unsigned int )(llvm_cbe_tmp__179&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__173&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__180&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = zext i32 %%25 to i64, !dbg !33 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_391_count);
  llvm_cbe_tmp__181 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__180&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__181);
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = tail call i8* @malloc(i64 %%26), !dbg !33 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_392_count);
  llvm_cbe_tmp__182 = ( char *) /*tail*/ ( char *)malloc(llvm_cbe_tmp__181);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__181);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__182);
}
  if (((llvm_cbe_tmp__157&4294967295U) == (0u&4294967295U))) {
    llvm_cbe_tmp__213__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    llvm_cbe__2e_lcssa5__PHI_TEMPORARY = ( char *)llvm_cbe_tmp__176;   /* for PHI node */
    llvm_cbe__2e_lcssa4__PHI_TEMPORARY = ( char *)llvm_cbe_tmp__182;   /* for PHI node */
    goto llvm_cbe_tmp__218;
  } else {
    goto llvm_cbe__2e_lr_2e_ph9;
  }

llvm_cbe__2e_lr_2e_ph9:
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = shl nuw nsw i64 %%10, 3, !dbg !35 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_405_count);
  llvm_cbe_tmp__183 = (unsigned long long )llvm_cbe_tmp__165 << 3ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__183);
  if (((llvm_cbe_tmp__164&4294967295U) == (0u&4294967295U))) {
    llvm_cbe_storemerge7__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    llvm_cbe__2e_rec24__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    llvm_cbe__2e_rec26__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe_tmp__219;
  } else {
    llvm_cbe_storemerge7_2e_us__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    llvm_cbe_tmp__194__PHI_TEMPORARY = ( char *)llvm_cbe_tmp__176;   /* for PHI node */
    llvm_cbe__2e_rec18__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    llvm_cbe__2e_rec20__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  }

  do {     /* Syntactic loop '.lr.ph.us' to make GCC happy */
llvm_cbe__2e_lr_2e_ph_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge7.us = phi i32 [ %%32, %%31 ], [ 0, %%.lr.ph9  for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_storemerge7_2e_us_count);
  llvm_cbe_storemerge7_2e_us = (unsigned int )llvm_cbe_storemerge7_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge7.us = 0x%X",llvm_cbe_storemerge7_2e_us);
printf("\n = 0x%X",llvm_cbe_tmp__184);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = phi i8* [ %%41, %%31 ], [ %%21, %%.lr.ph9  for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_436_count);
  llvm_cbe_tmp__194 = ( char *)llvm_cbe_tmp__194__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec18 = phi i64 [ %%.rec19, %%31 ], [ 0, %%.lr.ph9  for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe__2e_rec18_count);
  llvm_cbe__2e_rec18 = (unsigned long long )llvm_cbe__2e_rec18__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.rec18 = 0x%I64X",llvm_cbe__2e_rec18);
printf("\n.rec19 = 0x%I64X",llvm_cbe__2e_rec19);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec20 = phi i64 [ %%.rec21, %%31 ], [ 0, %%.lr.ph9  for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe__2e_rec20_count);
  llvm_cbe__2e_rec20 = (unsigned long long )llvm_cbe__2e_rec20__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.rec20 = 0x%I64X",llvm_cbe__2e_rec20);
printf("\n.rec21 = 0x%I64X",llvm_cbe__2e_rec21);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = getelementptr i8* %%27, i64 %%.rec2 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_437_count);
  llvm_cbe_tmp__195 = ( char *)(&llvm_cbe_tmp__182[(((signed long long )llvm_cbe__2e_rec20))]);
if (AESL_DEBUG_TRACE) {
printf("\n.rec20 = 0x%I64X",((signed long long )llvm_cbe__2e_rec20));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = getelementptr i8* %%23, i64 %%.rec1 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_438_count);
  llvm_cbe_tmp__196 = ( char *)(&llvm_cbe_tmp__178[(((signed long long )llvm_cbe__2e_rec18))]);
if (AESL_DEBUG_TRACE) {
printf("\n.rec18 = 0x%I64X",((signed long long )llvm_cbe__2e_rec18));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = bitcast i8* %%46 to i8**, !dbg !35 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_439_count);
  llvm_cbe_tmp__197 = ( char **)(( char **)llvm_cbe_tmp__196);
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = zext i32 %%storemerge7.us to i64, !dbg !35 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_440_count);
  llvm_cbe_tmp__198 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge7_2e_us&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__198);
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = getelementptr inbounds %%struct.seeds_t* %%7, i64 %%48, i32 0, !dbg !35 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_441_count);
  llvm_cbe_tmp__199 = ( char ***)(&llvm_cbe_tmp__162[(((signed long long )llvm_cbe_tmp__198))].field0);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__198));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8** %%47, i8*** %%49, align 8, !dbg !35 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_442_count);
  *llvm_cbe_tmp__199 = ( char **)llvm_cbe_tmp__197;
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec19 = add i64 %%.rec18, %%29, !dbg !35 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe__2e_rec19_count);
  llvm_cbe__2e_rec19 = (unsigned long long )((unsigned long long )(llvm_cbe__2e_rec18&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__183&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.rec19 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_rec19&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = getelementptr inbounds %%struct.seeds_t* %%7, i64 %%48, i32 1, !dbg !35 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_443_count);
  llvm_cbe_tmp__200 = ( char **)(&llvm_cbe_tmp__162[(((signed long long )llvm_cbe_tmp__198))].field1);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__198));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8* %%45, i8** %%50, align 8, !dbg !35 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_444_count);
  *llvm_cbe_tmp__200 = ( char *)llvm_cbe_tmp__195;
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = load i32* %%12, align 4, !dbg !33 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_445_count);
  llvm_cbe_tmp__201 = (unsigned int )*llvm_cbe_tmp__167;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__201);
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = zext i32 %%51 to i64, !dbg !33 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_446_count);
  llvm_cbe_tmp__202 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__201&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__202);
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec21 = add i64 %%.rec20, %%52, !dbg !33 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe__2e_rec21_count);
  llvm_cbe__2e_rec21 = (unsigned long long )((unsigned long long )(llvm_cbe__2e_rec20&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__202&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.rec21 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_rec21&18446744073709551615ull)));
  llvm_cbe_tmp__186__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  llvm_cbe_storemerge13_2e_us__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  llvm_cbe__2e_rec__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__220;

llvm_cbe_tmp__221:
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = add i32 %%storemerge7.us, 1, !dbg !36 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_408_count);
  llvm_cbe_tmp__184 = (unsigned int )((unsigned int )(llvm_cbe_storemerge7_2e_us&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__184&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = load i32* %%1, align 4, !dbg !33 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_415_count);
  llvm_cbe_tmp__185 = (unsigned int )*llvm_cbe_tmp__156;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__185);
  if ((((unsigned int )llvm_cbe_tmp__184&4294967295U) < ((unsigned int )llvm_cbe_tmp__185&4294967295U))) {
    llvm_cbe_storemerge7_2e_us__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__184;   /* for PHI node */
    llvm_cbe_tmp__194__PHI_TEMPORARY = ( char *)llvm_cbe_tmp__191;   /* for PHI node */
    llvm_cbe__2e_rec18__PHI_TEMPORARY = (unsigned long long )llvm_cbe__2e_rec19;   /* for PHI node */
    llvm_cbe__2e_rec20__PHI_TEMPORARY = (unsigned long long )llvm_cbe__2e_rec21;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  } else {
    llvm_cbe_split11__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__185;   /* for PHI node */
    llvm_cbe_split12__PHI_TEMPORARY = ( char *)llvm_cbe_tmp__191;   /* for PHI node */
    llvm_cbe__2e_rec27_2e_pn__PHI_TEMPORARY = (unsigned long long )llvm_cbe__2e_rec21;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge10;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__220:
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = phi i64 [ 0, %%.lr.ph.us ], [ %%43, %%35  for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_418_count);
  llvm_cbe_tmp__186 = (unsigned long long )llvm_cbe_tmp__186__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__186);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__193);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge13.us = phi i32 [ 0, %%.lr.ph.us ], [ %%42, %%35  for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_storemerge13_2e_us_count);
  llvm_cbe_storemerge13_2e_us = (unsigned int )llvm_cbe_storemerge13_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge13.us = 0x%X",llvm_cbe_storemerge13_2e_us);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__192);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec = phi i64 [ 0, %%.lr.ph.us ], [ %%.rec15, %%35  for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe__2e_rec_count);
  llvm_cbe__2e_rec = (unsigned long long )llvm_cbe__2e_rec__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.rec = 0x%I64X",llvm_cbe__2e_rec);
printf("\n = 0x%I64X",0ull);
printf("\n.rec15 = 0x%I64X",llvm_cbe__2e_rec15);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = getelementptr i8* %%44, i64 %%.re for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_419_count);
  llvm_cbe_tmp__187 = ( char *)(&llvm_cbe_tmp__194[(((signed long long )llvm_cbe__2e_rec))]);
if (AESL_DEBUG_TRACE) {
printf("\n.rec = 0x%I64X",((signed long long )llvm_cbe__2e_rec));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = getelementptr inbounds i8** %%47, i64 %%36, !dbg !35 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_420_count);
  llvm_cbe_tmp__188 = ( char **)(&llvm_cbe_tmp__197[(((signed long long )llvm_cbe_tmp__186))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__186));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8* %%37, i8** %%38, align 8, !dbg !35 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_421_count);
  *llvm_cbe_tmp__188 = ( char *)llvm_cbe_tmp__187;
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = load i32* %%12, align 4, !dbg !34 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_422_count);
  llvm_cbe_tmp__189 = (unsigned int )*llvm_cbe_tmp__167;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__189);
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = zext i32 %%39 to i64, !dbg !34 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_423_count);
  llvm_cbe_tmp__190 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__189&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__190);
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec15 = add i64 %%.rec, %%40, !dbg !34 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe__2e_rec15_count);
  llvm_cbe__2e_rec15 = (unsigned long long )((unsigned long long )(llvm_cbe__2e_rec&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__190&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.rec15 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_rec15&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = getelementptr inbounds i8* %%44, i64 %%.rec15, !dbg !34 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_424_count);
  llvm_cbe_tmp__191 = ( char *)(&llvm_cbe_tmp__194[(((signed long long )llvm_cbe__2e_rec15))]);
if (AESL_DEBUG_TRACE) {
printf("\n.rec15 = 0x%I64X",((signed long long )llvm_cbe__2e_rec15));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = add i32 %%storemerge13.us, 1, !dbg !36 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_429_count);
  llvm_cbe_tmp__192 = (unsigned int )((unsigned int )(llvm_cbe_storemerge13_2e_us&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__192&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = zext i32 %%42 to i64, !dbg !35 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_434_count);
  llvm_cbe_tmp__193 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__192&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__193);
  if (((llvm_cbe_tmp__192&4294967295U) == (llvm_cbe_tmp__164&4294967295U))) {
    goto llvm_cbe_tmp__221;
  } else {
    llvm_cbe_tmp__186__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__193;   /* for PHI node */
    llvm_cbe_storemerge13_2e_us__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__192;   /* for PHI node */
    llvm_cbe__2e_rec__PHI_TEMPORARY = (unsigned long long )llvm_cbe__2e_rec15;   /* for PHI node */
    goto llvm_cbe_tmp__220;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.lr.ph.us' */
  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__219:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge7 = phi i32 [ %%62, %%53 ], [ 0, %%.lr.ph9  for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_storemerge7_count);
  llvm_cbe_storemerge7 = (unsigned int )llvm_cbe_storemerge7__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge7 = 0x%X",llvm_cbe_storemerge7);
printf("\n = 0x%X",llvm_cbe_tmp__211);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec24 = phi i64 [ %%.rec25, %%53 ], [ 0, %%.lr.ph9  for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe__2e_rec24_count);
  llvm_cbe__2e_rec24 = (unsigned long long )llvm_cbe__2e_rec24__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.rec24 = 0x%I64X",llvm_cbe__2e_rec24);
printf("\n.rec25 = 0x%I64X",llvm_cbe__2e_rec25);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec26 = phi i64 [ %%.rec27, %%53 ], [ 0, %%.lr.ph9  for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe__2e_rec26_count);
  llvm_cbe__2e_rec26 = (unsigned long long )llvm_cbe__2e_rec26__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.rec26 = 0x%I64X",llvm_cbe__2e_rec26);
printf("\n.rec27 = 0x%I64X",llvm_cbe__2e_rec27);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = getelementptr i8* %%27, i64 %%.rec2 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_452_count);
  llvm_cbe_tmp__203 = ( char *)(&llvm_cbe_tmp__182[(((signed long long )llvm_cbe__2e_rec26))]);
if (AESL_DEBUG_TRACE) {
printf("\n.rec26 = 0x%I64X",((signed long long )llvm_cbe__2e_rec26));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = getelementptr i8* %%23, i64 %%.rec2 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_453_count);
  llvm_cbe_tmp__204 = ( char *)(&llvm_cbe_tmp__178[(((signed long long )llvm_cbe__2e_rec24))]);
if (AESL_DEBUG_TRACE) {
printf("\n.rec24 = 0x%I64X",((signed long long )llvm_cbe__2e_rec24));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = bitcast i8* %%55 to i8**, !dbg !35 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_454_count);
  llvm_cbe_tmp__205 = ( char **)(( char **)llvm_cbe_tmp__204);
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = zext i32 %%storemerge7 to i64, !dbg !35 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_455_count);
  llvm_cbe_tmp__206 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge7&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__206);
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = getelementptr inbounds %%struct.seeds_t* %%7, i64 %%57, i32 0, !dbg !35 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_456_count);
  llvm_cbe_tmp__207 = ( char ***)(&llvm_cbe_tmp__162[(((signed long long )llvm_cbe_tmp__206))].field0);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__206));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8** %%56, i8*** %%58, align 8, !dbg !35 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_457_count);
  *llvm_cbe_tmp__207 = ( char **)llvm_cbe_tmp__205;
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec25 = add i64 %%.rec24, %%29, !dbg !35 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe__2e_rec25_count);
  llvm_cbe__2e_rec25 = (unsigned long long )((unsigned long long )(llvm_cbe__2e_rec24&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__183&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.rec25 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_rec25&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = getelementptr inbounds %%struct.seeds_t* %%7, i64 %%57, i32 1, !dbg !35 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_458_count);
  llvm_cbe_tmp__208 = ( char **)(&llvm_cbe_tmp__162[(((signed long long )llvm_cbe_tmp__206))].field1);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__206));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8* %%54, i8** %%59, align 8, !dbg !35 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_459_count);
  *llvm_cbe_tmp__208 = ( char *)llvm_cbe_tmp__203;
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = load i32* %%12, align 4, !dbg !33 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_460_count);
  llvm_cbe_tmp__209 = (unsigned int )*llvm_cbe_tmp__167;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__209);
if (AESL_DEBUG_TRACE)
printf("\n  %%61 = zext i32 %%60 to i64, !dbg !33 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_461_count);
  llvm_cbe_tmp__210 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__209&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__210);
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec27 = add i64 %%.rec26, %%61, !dbg !33 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe__2e_rec27_count);
  llvm_cbe__2e_rec27 = (unsigned long long )((unsigned long long )(llvm_cbe__2e_rec26&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__210&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.rec27 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_rec27&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = add i32 %%storemerge7, 1, !dbg !36 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_466_count);
  llvm_cbe_tmp__211 = (unsigned int )((unsigned int )(llvm_cbe_storemerge7&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__211&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = load i32* %%1, align 4, !dbg !33 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_473_count);
  llvm_cbe_tmp__212 = (unsigned int )*llvm_cbe_tmp__156;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__212);
  if ((((unsigned int )llvm_cbe_tmp__211&4294967295U) < ((unsigned int )llvm_cbe_tmp__212&4294967295U))) {
    llvm_cbe_storemerge7__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__211;   /* for PHI node */
    llvm_cbe__2e_rec24__PHI_TEMPORARY = (unsigned long long )llvm_cbe__2e_rec25;   /* for PHI node */
    llvm_cbe__2e_rec26__PHI_TEMPORARY = (unsigned long long )llvm_cbe__2e_rec27;   /* for PHI node */
    goto llvm_cbe_tmp__219;
  } else {
    llvm_cbe_split11__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__212;   /* for PHI node */
    llvm_cbe_split12__PHI_TEMPORARY = ( char *)llvm_cbe_tmp__176;   /* for PHI node */
    llvm_cbe__2e_rec27_2e_pn__PHI_TEMPORARY = (unsigned long long )llvm_cbe__2e_rec27;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge10;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e__crit_edge10:
if (AESL_DEBUG_TRACE)
printf("\n  %%split11 = phi i32 [ %%33, %%31 ], [ %%63, %%53  for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_split11_count);
  llvm_cbe_split11 = (unsigned int )llvm_cbe_split11__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nsplit11 = 0x%X",llvm_cbe_split11);
printf("\n = 0x%X",llvm_cbe_tmp__185);
printf("\n = 0x%X",llvm_cbe_tmp__212);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%split12 = phi i8* [ %%41, %%31 ], [ %%21, %%53  for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_split12_count);
  llvm_cbe_split12 = ( char *)llvm_cbe_split12__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec27.pn = phi i64 [ %%.rec21, %%31 ], [ %%.rec27, %%53  for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe__2e_rec27_2e_pn_count);
  llvm_cbe__2e_rec27_2e_pn = (unsigned long long )llvm_cbe__2e_rec27_2e_pn__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.rec27.pn = 0x%I64X",llvm_cbe__2e_rec27_2e_pn);
printf("\n.rec21 = 0x%I64X",llvm_cbe__2e_rec21);
printf("\n.rec27 = 0x%I64X",llvm_cbe__2e_rec27);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%split13 = getelementptr inbounds i8* %%27, i64 %%.rec27.pn, !dbg !34 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_split13_count);
  llvm_cbe_split13 = ( char *)(&llvm_cbe_tmp__182[(((signed long long )llvm_cbe__2e_rec27_2e_pn))]);
if (AESL_DEBUG_TRACE) {
printf("\n.rec27.pn = 0x%I64X",((signed long long )llvm_cbe__2e_rec27_2e_pn));
}
  llvm_cbe_tmp__213__PHI_TEMPORARY = (unsigned int )llvm_cbe_split11;   /* for PHI node */
  llvm_cbe__2e_lcssa5__PHI_TEMPORARY = ( char *)llvm_cbe_split12;   /* for PHI node */
  llvm_cbe__2e_lcssa4__PHI_TEMPORARY = ( char *)llvm_cbe_split13;   /* for PHI node */
  goto llvm_cbe_tmp__218;

llvm_cbe_tmp__218:
if (AESL_DEBUG_TRACE)
printf("\n  %%66 = phi i32 [ %%split11, %%._crit_edge10 ], [ 0, %%0  for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_478_count);
  llvm_cbe_tmp__213 = (unsigned int )llvm_cbe_tmp__213__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__213);
printf("\nsplit11 = 0x%X",llvm_cbe_split11);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.lcssa5 = phi i8* [ %%split12, %%._crit_edge10 ], [ %%21, %%0  for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe__2e_lcssa5_count);
  llvm_cbe__2e_lcssa5 = ( char *)llvm_cbe__2e_lcssa5__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE)
printf("\n  %%.lcssa4 = phi i8* [ %%split13, %%._crit_edge10 ], [ %%27, %%0  for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe__2e_lcssa4_count);
  llvm_cbe__2e_lcssa4 = ( char *)llvm_cbe__2e_lcssa4__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE)
printf("\n  %%67 = zext i32 %%66 to i64, !dbg !34 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_479_count);
  llvm_cbe_tmp__214 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__213&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__214);
if (AESL_DEBUG_TRACE)
printf("\n  %%68 = getelementptr inbounds %%struct.seeds_t* %%7, i64 %%67, i32 0, !dbg !34 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_480_count);
  llvm_cbe_tmp__215 = ( char ***)(&llvm_cbe_tmp__162[(((signed long long )llvm_cbe_tmp__214))].field0);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__214));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8** null, i8*** %%68, align 8, !dbg !34 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_481_count);
  *llvm_cbe_tmp__215 = ( char **)(( char **)/*NULL*/0);
  if (((llvm_cbe_tmp__164&4294967295U) == (3u&4294967295U))) {
    goto llvm_cbe_tmp__222;
  } else {
    goto llvm_cbe_tmp__223;
  }

llvm_cbe_tmp__222:
if (AESL_DEBUG_TRACE)
printf("\n  %%71 = getelementptr inbounds %%struct.seeds_t* %%7, i64 %%67, i32 1, !dbg !34 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_484_count);
  llvm_cbe_tmp__216 = ( char **)(&llvm_cbe_tmp__162[(((signed long long )llvm_cbe_tmp__214))].field1);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__214));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8* %%.lcssa5, i8** %%71, align 8, !dbg !34 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_485_count);
  *llvm_cbe_tmp__216 = ( char *)llvm_cbe__2e_lcssa5;
  goto llvm_cbe_tmp__224;

llvm_cbe_tmp__223:
if (AESL_DEBUG_TRACE)
printf("\n  %%73 = getelementptr inbounds %%struct.seeds_t* %%7, i64 %%67, i32 1, !dbg !34 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_487_count);
  llvm_cbe_tmp__217 = ( char **)(&llvm_cbe_tmp__162[(((signed long long )llvm_cbe_tmp__214))].field1);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__214));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8* %%.lcssa4, i8** %%73, align 8, !dbg !34 for 0x%I64xth hint within @allocateSeeds  --> \n", ++aesl_llvm_cbe_488_count);
  *llvm_cbe_tmp__217 = ( char *)llvm_cbe__2e_lcssa4;
  goto llvm_cbe_tmp__224;

llvm_cbe_tmp__224:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @allocateSeeds}\n");
  return llvm_cbe_tmp__162;
}


void freeSeeds(l_struct_OC_seeds_t *llvm_cbe_seeds) {
  static  unsigned long long aesl_llvm_cbe_491_count = 0;
  static  unsigned long long aesl_llvm_cbe_492_count = 0;
  static  unsigned long long aesl_llvm_cbe_493_count = 0;
  static  unsigned long long aesl_llvm_cbe_494_count = 0;
  static  unsigned long long aesl_llvm_cbe_495_count = 0;
  static  unsigned long long aesl_llvm_cbe_496_count = 0;
   char ***llvm_cbe_tmp__225;
  static  unsigned long long aesl_llvm_cbe_497_count = 0;
   char **llvm_cbe_tmp__226;
  static  unsigned long long aesl_llvm_cbe_498_count = 0;
   char *llvm_cbe_tmp__227;
  static  unsigned long long aesl_llvm_cbe_499_count = 0;
  static  unsigned long long aesl_llvm_cbe_500_count = 0;
   char **llvm_cbe_tmp__228;
  static  unsigned long long aesl_llvm_cbe_501_count = 0;
   char *llvm_cbe_tmp__229;
  static  unsigned long long aesl_llvm_cbe_502_count = 0;
  static  unsigned long long aesl_llvm_cbe_503_count = 0;
   char **llvm_cbe_tmp__230;
  static  unsigned long long aesl_llvm_cbe_504_count = 0;
   char *llvm_cbe_tmp__231;
  static  unsigned long long aesl_llvm_cbe_505_count = 0;
  static  unsigned long long aesl_llvm_cbe_506_count = 0;
   char *llvm_cbe_tmp__232;
  static  unsigned long long aesl_llvm_cbe_507_count = 0;
  static  unsigned long long aesl_llvm_cbe_508_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @freeSeeds\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.seeds_t* %%seeds, i64 0, i32 0, !dbg !33 for 0x%I64xth hint within @freeSeeds  --> \n", ++aesl_llvm_cbe_496_count);
  llvm_cbe_tmp__225 = ( char ***)(&llvm_cbe_seeds->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i8*** %%1, align 8, !dbg !33 for 0x%I64xth hint within @freeSeeds  --> \n", ++aesl_llvm_cbe_497_count);
  llvm_cbe_tmp__226 = ( char **)*llvm_cbe_tmp__225;
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = load i8** %%2, align 8, !dbg !33 for 0x%I64xth hint within @freeSeeds  --> \n", ++aesl_llvm_cbe_498_count);
  llvm_cbe_tmp__227 = ( char *)*llvm_cbe_tmp__226;
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @free(i8* %%3), !dbg !33 for 0x%I64xth hint within @freeSeeds  --> \n", ++aesl_llvm_cbe_499_count);
   /*tail*/ free(( char *)llvm_cbe_tmp__227);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds %%struct.seeds_t* %%seeds, i64 0, i32 1, !dbg !33 for 0x%I64xth hint within @freeSeeds  --> \n", ++aesl_llvm_cbe_500_count);
  llvm_cbe_tmp__228 = ( char **)(&llvm_cbe_seeds->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load i8** %%4, align 8, !dbg !33 for 0x%I64xth hint within @freeSeeds  --> \n", ++aesl_llvm_cbe_501_count);
  llvm_cbe_tmp__229 = ( char *)*llvm_cbe_tmp__228;
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @free(i8* %%5), !dbg !33 for 0x%I64xth hint within @freeSeeds  --> \n", ++aesl_llvm_cbe_502_count);
   /*tail*/ free(( char *)llvm_cbe_tmp__229);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load i8*** %%1, align 8, !dbg !33 for 0x%I64xth hint within @freeSeeds  --> \n", ++aesl_llvm_cbe_503_count);
  llvm_cbe_tmp__230 = ( char **)*llvm_cbe_tmp__225;
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = bitcast i8** %%6 to i8*, !dbg !33 for 0x%I64xth hint within @freeSeeds  --> \n", ++aesl_llvm_cbe_504_count);
  llvm_cbe_tmp__231 = ( char *)(( char *)llvm_cbe_tmp__230);
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @free(i8* %%7), !dbg !33 for 0x%I64xth hint within @freeSeeds  --> \n", ++aesl_llvm_cbe_505_count);
   /*tail*/ free(( char *)llvm_cbe_tmp__231);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = bitcast %%struct.seeds_t* %%seeds to i8*, !dbg !33 for 0x%I64xth hint within @freeSeeds  --> \n", ++aesl_llvm_cbe_506_count);
  llvm_cbe_tmp__232 = ( char *)(( char *)llvm_cbe_seeds);
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @free(i8* %%8), !dbg !33 for 0x%I64xth hint within @freeSeeds  --> \n", ++aesl_llvm_cbe_507_count);
   /*tail*/ free(( char *)llvm_cbe_tmp__232);
if (AESL_DEBUG_TRACE) {
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @freeSeeds}\n");
  return;
}


l_struct_OC_commitments_t *allocateCommitments(l_struct_OC_paramset_t *llvm_cbe_params, signed long long llvm_cbe_numCommitments) {
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
  static  unsigned long long aesl_llvm_cbe_519_count = 0;
  signed int *llvm_cbe_tmp__233;
  static  unsigned long long aesl_llvm_cbe_520_count = 0;
  unsigned int llvm_cbe_tmp__234;
  static  unsigned long long aesl_llvm_cbe_521_count = 0;
  unsigned long long llvm_cbe_tmp__235;
  static  unsigned long long aesl_llvm_cbe_522_count = 0;
  unsigned long long llvm_cbe_tmp__236;
  static  unsigned long long aesl_llvm_cbe_523_count = 0;
   char *llvm_cbe_tmp__237;
  static  unsigned long long aesl_llvm_cbe_524_count = 0;
  l_struct_OC_commitments_t *llvm_cbe_tmp__238;
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
  signed int *llvm_cbe_tmp__239;
  static  unsigned long long aesl_llvm_cbe_537_count = 0;
  unsigned int llvm_cbe_tmp__240;
  static  unsigned long long aesl_llvm_cbe_538_count = 0;
  unsigned long long llvm_cbe_tmp__241;
  static  unsigned long long aesl_llvm_cbe_539_count = 0;
  static  unsigned long long aesl_llvm_cbe_540_count = 0;
  unsigned long long llvm_cbe_tmp__242;
  unsigned long long llvm_cbe_tmp__242__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_541_count = 0;
  signed long long *llvm_cbe_tmp__243;
  static  unsigned long long aesl_llvm_cbe_542_count = 0;
  static  unsigned long long aesl_llvm_cbe_543_count = 0;
  signed int *llvm_cbe_tmp__244;
  static  unsigned long long aesl_llvm_cbe_544_count = 0;
  unsigned int llvm_cbe_tmp__245;
  static  unsigned long long aesl_llvm_cbe_545_count = 0;
  unsigned long long llvm_cbe_tmp__246;
  static  unsigned long long aesl_llvm_cbe_tmp_count = 0;
  unsigned long long llvm_cbe_tmp;
  static  unsigned long long aesl_llvm_cbe_tmp2_count = 0;
  unsigned long long llvm_cbe_tmp2;
  static  unsigned long long aesl_llvm_cbe_546_count = 0;
  unsigned long long llvm_cbe_tmp__247;
  static  unsigned long long aesl_llvm_cbe_547_count = 0;
   char *llvm_cbe_tmp__248;
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
  unsigned long long llvm_cbe_tmp__249;
  static  unsigned long long aesl_llvm_cbe_561_count = 0;
  static  unsigned long long aesl_llvm_cbe_562_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_lcssa_2e_us_count = 0;
   char *llvm_cbe__2e_lcssa_2e_us;
  static  unsigned long long aesl_llvm_cbe_563_count = 0;
  static  unsigned long long aesl_llvm_cbe_564_count = 0;
  unsigned int llvm_cbe_tmp__250;
  static  unsigned long long aesl_llvm_cbe_565_count = 0;
  static  unsigned long long aesl_llvm_cbe_566_count = 0;
  static  unsigned long long aesl_llvm_cbe_567_count = 0;
  static  unsigned long long aesl_llvm_cbe_568_count = 0;
  static  unsigned long long aesl_llvm_cbe_569_count = 0;
  static  unsigned long long aesl_llvm_cbe_570_count = 0;
  unsigned int llvm_cbe_tmp__251;
  static  unsigned long long aesl_llvm_cbe_571_count = 0;
  static  unsigned long long aesl_llvm_cbe_572_count = 0;
  static  unsigned long long aesl_llvm_cbe_573_count = 0;
  unsigned long long llvm_cbe_tmp__252;
  unsigned long long llvm_cbe_tmp__252__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge13_2e_us_count = 0;
  unsigned int llvm_cbe_storemerge13_2e_us;
  unsigned int llvm_cbe_storemerge13_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_rec_count = 0;
  unsigned long long llvm_cbe__2e_rec;
  unsigned long long llvm_cbe__2e_rec__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_sum_count = 0;
  unsigned long long llvm_cbe__2e_sum;
  static  unsigned long long aesl_llvm_cbe_574_count = 0;
   char *llvm_cbe_tmp__253;
  static  unsigned long long aesl_llvm_cbe_575_count = 0;
   char **llvm_cbe_tmp__254;
  static  unsigned long long aesl_llvm_cbe_576_count = 0;
  static  unsigned long long aesl_llvm_cbe_577_count = 0;
  unsigned int llvm_cbe_tmp__255;
  static  unsigned long long aesl_llvm_cbe_578_count = 0;
  unsigned long long llvm_cbe_tmp__256;
  static  unsigned long long aesl_llvm_cbe__2e_rec9_count = 0;
  unsigned long long llvm_cbe__2e_rec9;
  static  unsigned long long aesl_llvm_cbe__2e_sum10_count = 0;
  unsigned long long llvm_cbe__2e_sum10;
  static  unsigned long long aesl_llvm_cbe_579_count = 0;
  unsigned int llvm_cbe_tmp__257;
  static  unsigned long long aesl_llvm_cbe_580_count = 0;
  static  unsigned long long aesl_llvm_cbe_581_count = 0;
  static  unsigned long long aesl_llvm_cbe_582_count = 0;
  static  unsigned long long aesl_llvm_cbe_583_count = 0;
  static  unsigned long long aesl_llvm_cbe_584_count = 0;
  unsigned long long llvm_cbe_tmp__258;
  static  unsigned long long aesl_llvm_cbe_585_count = 0;
  static  unsigned long long aesl_llvm_cbe_586_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge4_2e_us_count = 0;
  unsigned int llvm_cbe_storemerge4_2e_us;
  unsigned int llvm_cbe_storemerge4_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_587_count = 0;
   char *llvm_cbe_tmp__259;
   char *llvm_cbe_tmp__259__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_588_count = 0;
   char **llvm_cbe_tmp__260;
  static  unsigned long long aesl_llvm_cbe_589_count = 0;
  unsigned long long llvm_cbe_tmp__261;
  static  unsigned long long aesl_llvm_cbe_590_count = 0;
   char ***llvm_cbe_tmp__262;
  static  unsigned long long aesl_llvm_cbe_591_count = 0;
  static  unsigned long long aesl_llvm_cbe_592_count = 0;
  static  unsigned long long aesl_llvm_cbe_593_count = 0;
  static  unsigned long long aesl_llvm_cbe_594_count = 0;
  static  unsigned long long aesl_llvm_cbe_595_count = 0;
  static  unsigned long long aesl_llvm_cbe_596_count = 0;
  unsigned long long llvm_cbe_tmp__263;
  static  unsigned long long aesl_llvm_cbe_597_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge4_count = 0;
  unsigned int llvm_cbe_storemerge4;
  unsigned int llvm_cbe_storemerge4__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_598_count = 0;
   char *llvm_cbe_tmp__264;
   char *llvm_cbe_tmp__264__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_599_count = 0;
   char **llvm_cbe_tmp__265;
  static  unsigned long long aesl_llvm_cbe_600_count = 0;
  unsigned long long llvm_cbe_tmp__266;
  static  unsigned long long aesl_llvm_cbe_601_count = 0;
   char ***llvm_cbe_tmp__267;
  static  unsigned long long aesl_llvm_cbe_602_count = 0;
  static  unsigned long long aesl_llvm_cbe_603_count = 0;
   char *llvm_cbe_tmp__268;
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
  unsigned int llvm_cbe_tmp__269;
  static  unsigned long long aesl_llvm_cbe_614_count = 0;
  static  unsigned long long aesl_llvm_cbe_615_count = 0;
  static  unsigned long long aesl_llvm_cbe_616_count = 0;
  static  unsigned long long aesl_llvm_cbe_617_count = 0;
  static  unsigned long long aesl_llvm_cbe_618_count = 0;
  static  unsigned long long aesl_llvm_cbe_619_count = 0;
  unsigned int llvm_cbe_tmp__270;
  static  unsigned long long aesl_llvm_cbe_620_count = 0;
  static  unsigned long long aesl_llvm_cbe_621_count = 0;
  static  unsigned long long aesl_llvm_cbe_622_count = 0;
  static  unsigned long long aesl_llvm_cbe_623_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @allocateCommitments\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.paramset_t* %%params, i64 0, i32 8, !dbg !33 for 0x%I64xth hint within @allocateCommitments  --> \n", ++aesl_llvm_cbe_519_count);
  llvm_cbe_tmp__233 = (signed int *)(&llvm_cbe_params->field8);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i32* %%1, align 4, !dbg !33 for 0x%I64xth hint within @allocateCommitments  --> \n", ++aesl_llvm_cbe_520_count);
  llvm_cbe_tmp__234 = (unsigned int )*llvm_cbe_tmp__233;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__234);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = zext i32 %%2 to i64, !dbg !33 for 0x%I64xth hint within @allocateCommitments  --> \n", ++aesl_llvm_cbe_521_count);
  llvm_cbe_tmp__235 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__234&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__235);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = shl nuw nsw i64 %%3, 4, !dbg !33 for 0x%I64xth hint within @allocateCommitments  --> \n", ++aesl_llvm_cbe_522_count);
  llvm_cbe_tmp__236 = (unsigned long long )llvm_cbe_tmp__235 << 4ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__236);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = tail call i8* @malloc(i64 %%4), !dbg !33 for 0x%I64xth hint within @allocateCommitments  --> \n", ++aesl_llvm_cbe_523_count);
  llvm_cbe_tmp__237 = ( char *) /*tail*/ ( char *)malloc(llvm_cbe_tmp__236);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__236);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__237);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = bitcast i8* %%5 to %%struct.commitments_t*, !dbg !33 for 0x%I64xth hint within @allocateCommitments  --> \n", ++aesl_llvm_cbe_524_count);
  llvm_cbe_tmp__238 = (l_struct_OC_commitments_t *)((l_struct_OC_commitments_t *)llvm_cbe_tmp__237);
  if (((llvm_cbe_numCommitments&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__271;
  } else {
    llvm_cbe_tmp__242__PHI_TEMPORARY = (unsigned long long )llvm_cbe_numCommitments;   /* for PHI node */
    goto llvm_cbe_tmp__272;
  }

llvm_cbe_tmp__271:
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds %%struct.paramset_t* %%params, i64 0, i32 10, !dbg !33 for 0x%I64xth hint within @allocateCommitments  --> \n", ++aesl_llvm_cbe_536_count);
  llvm_cbe_tmp__239 = (signed int *)(&llvm_cbe_params->field10);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = load i32* %%9, align 4, !dbg !33 for 0x%I64xth hint within @allocateCommitments  --> \n", ++aesl_llvm_cbe_537_count);
  llvm_cbe_tmp__240 = (unsigned int )*llvm_cbe_tmp__239;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__240);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = zext i32 %%10 to i64, !dbg !33 for 0x%I64xth hint within @allocateCommitments  --> \n", ++aesl_llvm_cbe_538_count);
  llvm_cbe_tmp__241 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__240&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__241);
  llvm_cbe_tmp__242__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__241;   /* for PHI node */
  goto llvm_cbe_tmp__272;

llvm_cbe_tmp__272:
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = phi i64 [ %%11, %%8 ], [ %%numCommitments, %%0 ], !dbg !33 for 0x%I64xth hint within @allocateCommitments  --> \n", ++aesl_llvm_cbe_540_count);
  llvm_cbe_tmp__242 = (unsigned long long )llvm_cbe_tmp__242__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__242);
printf("\n = 0x%I64X",llvm_cbe_tmp__241);
printf("\nnumCommitments = 0x%I64X",llvm_cbe_numCommitments);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds %%struct.commitments_t* %%6, i64 0, i32 1, !dbg !33 for 0x%I64xth hint within @allocateCommitments  --> \n", ++aesl_llvm_cbe_541_count);
  llvm_cbe_tmp__243 = (signed long long *)(&llvm_cbe_tmp__238->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%13, i64* %%14, align 8, !dbg !33 for 0x%I64xth hint within @allocateCommitments  --> \n", ++aesl_llvm_cbe_542_count);
  *llvm_cbe_tmp__243 = llvm_cbe_tmp__242;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__242);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds %%struct.paramset_t* %%params, i64 0, i32 13, !dbg !33 for 0x%I64xth hint within @allocateCommitments  --> \n", ++aesl_llvm_cbe_543_count);
  llvm_cbe_tmp__244 = (signed int *)(&llvm_cbe_params->field13);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = load i32* %%15, align 4, !dbg !33 for 0x%I64xth hint within @allocateCommitments  --> \n", ++aesl_llvm_cbe_544_count);
  llvm_cbe_tmp__245 = (unsigned int )*llvm_cbe_tmp__244;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__245);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = zext i32 %%16 to i64, !dbg !33 for 0x%I64xth hint within @allocateCommitments  --> \n", ++aesl_llvm_cbe_545_count);
  llvm_cbe_tmp__246 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__245&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__246);
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp = add i64 %%17,  for 0x%I64xth hint within @allocateCommitments  --> \n", ++aesl_llvm_cbe_tmp_count);
  llvm_cbe_tmp = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__246&18446744073709551615ull)) + ((unsigned long long )(8ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp2 = mul i64 %%3, %%13, !dbg !33 for 0x%I64xth hint within @allocateCommitments  --> \n", ++aesl_llvm_cbe_tmp2_count);
  llvm_cbe_tmp2 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__235&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__242&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp2 = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp2&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = mul i64 %%tmp2, %%tmp, !dbg !33 for 0x%I64xth hint within @allocateCommitments  --> \n", ++aesl_llvm_cbe_546_count);
  llvm_cbe_tmp__247 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp2&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__247&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = tail call i8* @malloc(i64 %%18), !dbg !33 for 0x%I64xth hint within @allocateCommitments  --> \n", ++aesl_llvm_cbe_547_count);
  llvm_cbe_tmp__248 = ( char *) /*tail*/ ( char *)malloc(llvm_cbe_tmp__247);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__247);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__248);
}
  if (((llvm_cbe_tmp__234&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__273;
  } else {
    goto llvm_cbe__2e_lr_2e_ph6;
  }

llvm_cbe__2e_lr_2e_ph6:
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = shl i64 %%13, 3, !dbg !34 for 0x%I64xth hint within @allocateCommitments  --> \n", ++aesl_llvm_cbe_560_count);
  llvm_cbe_tmp__249 = (unsigned long long )llvm_cbe_tmp__242 << 3ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__249);
  if (((llvm_cbe_tmp__242&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    llvm_cbe_storemerge4__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    llvm_cbe_tmp__264__PHI_TEMPORARY = ( char *)llvm_cbe_tmp__248;   /* for PHI node */
    goto llvm_cbe_tmp__274;
  } else {
    llvm_cbe_storemerge4_2e_us__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    llvm_cbe_tmp__259__PHI_TEMPORARY = ( char *)llvm_cbe_tmp__248;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  }

  do {     /* Syntactic loop '.lr.ph.us' to make GCC happy */
llvm_cbe__2e_lr_2e_ph_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge4.us = phi i32 [ %%24, %%23 ], [ 0, %%.lr.ph6  for 0x%I64xth hint within @allocateCommitments  --> \n", ++aesl_llvm_cbe_storemerge4_2e_us_count);
  llvm_cbe_storemerge4_2e_us = (unsigned int )llvm_cbe_storemerge4_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge4.us = 0x%X",llvm_cbe_storemerge4_2e_us);
printf("\n = 0x%X",llvm_cbe_tmp__250);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = phi i8* [ %%.lcssa.us, %%23 ], [ %%19, %%.lr.ph6  for 0x%I64xth hint within @allocateCommitments  --> \n", ++aesl_llvm_cbe_587_count);
  llvm_cbe_tmp__259 = ( char *)llvm_cbe_tmp__259__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = bitcast i8* %%36 to i8**, !dbg !34 for 0x%I64xth hint within @allocateCommitments  --> \n", ++aesl_llvm_cbe_588_count);
  llvm_cbe_tmp__260 = ( char **)(( char **)llvm_cbe_tmp__259);
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = zext i32 %%storemerge4.us to i64, !dbg !34 for 0x%I64xth hint within @allocateCommitments  --> \n", ++aesl_llvm_cbe_589_count);
  llvm_cbe_tmp__261 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge4_2e_us&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__261);
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = getelementptr inbounds %%struct.commitments_t* %%6, i64 %%38, i32 0, !dbg !34 for 0x%I64xth hint within @allocateCommitments  --> \n", ++aesl_llvm_cbe_590_count);
  llvm_cbe_tmp__262 = ( char ***)(&llvm_cbe_tmp__238[(((signed long long )llvm_cbe_tmp__261))].field0);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__261));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8** %%37, i8*** %%39, align 8, !dbg !34 for 0x%I64xth hint within @allocateCommitments  --> \n", ++aesl_llvm_cbe_591_count);
  *llvm_cbe_tmp__262 = ( char **)llvm_cbe_tmp__260;
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = load i64* %%14, align 8, !dbg !34 for 0x%I64xth hint within @allocateCommitments  --> \n", ++aesl_llvm_cbe_596_count);
  llvm_cbe_tmp__263 = (unsigned long long )*llvm_cbe_tmp__243;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__263);
  llvm_cbe_tmp__252__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  llvm_cbe_storemerge13_2e_us__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  llvm_cbe__2e_rec__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__275;

llvm_cbe_tmp__276:
if (AESL_DEBUG_TRACE)
printf("\n  %%.lcssa.us = getelementptr inbounds i8* %%36, i64 %%.sum10, !dbg !33 for 0x%I64xth hint within @allocateCommitments  --> \n", ++aesl_llvm_cbe__2e_lcssa_2e_us_count);
  llvm_cbe__2e_lcssa_2e_us = ( char *)(&llvm_cbe_tmp__259[(((signed long long )llvm_cbe__2e_sum10))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum10 = 0x%I64X",((signed long long )llvm_cbe__2e_sum10));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = add i32 %%storemerge4.us, 1, !dbg !35 for 0x%I64xth hint within @allocateCommitments  --> \n", ++aesl_llvm_cbe_564_count);
  llvm_cbe_tmp__250 = (unsigned int )((unsigned int )(llvm_cbe_storemerge4_2e_us&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__250&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = load i32* %%1, align 4, !dbg !33 for 0x%I64xth hint within @allocateCommitments  --> \n", ++aesl_llvm_cbe_570_count);
  llvm_cbe_tmp__251 = (unsigned int )*llvm_cbe_tmp__233;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__251);
  if ((((unsigned int )llvm_cbe_tmp__250&4294967295U) < ((unsigned int )llvm_cbe_tmp__251&4294967295U))) {
    llvm_cbe_storemerge4_2e_us__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__250;   /* for PHI node */
    llvm_cbe_tmp__259__PHI_TEMPORARY = ( char *)llvm_cbe__2e_lcssa_2e_us;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  } else {
    goto llvm_cbe__2e__crit_edge7;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__275:
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = phi i64 [ 0, %%.lr.ph.us ], [ %%34, %%27  for 0x%I64xth hint within @allocateCommitments  --> \n", ++aesl_llvm_cbe_573_count);
  llvm_cbe_tmp__252 = (unsigned long long )llvm_cbe_tmp__252__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__252);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__258);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge13.us = phi i32 [ 0, %%.lr.ph.us ], [ %%33, %%27  for 0x%I64xth hint within @allocateCommitments  --> \n", ++aesl_llvm_cbe_storemerge13_2e_us_count);
  llvm_cbe_storemerge13_2e_us = (unsigned int )llvm_cbe_storemerge13_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge13.us = 0x%X",llvm_cbe_storemerge13_2e_us);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__257);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec = phi i64 [ 0, %%.lr.ph.us ], [ %%.rec9, %%27  for 0x%I64xth hint within @allocateCommitments  --> \n", ++aesl_llvm_cbe__2e_rec_count);
  llvm_cbe__2e_rec = (unsigned long long )llvm_cbe__2e_rec__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.rec = 0x%I64X",llvm_cbe__2e_rec);
printf("\n = 0x%I64X",0ull);
printf("\n.rec9 = 0x%I64X",llvm_cbe__2e_rec9);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum = add i64 %%21, %%.re for 0x%I64xth hint within @allocateCommitments  --> \n", ++aesl_llvm_cbe__2e_sum_count);
  llvm_cbe__2e_sum = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__249&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe__2e_rec&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = getelementptr i8* %%36, i64 %%.su for 0x%I64xth hint within @allocateCommitments  --> \n", ++aesl_llvm_cbe_574_count);
  llvm_cbe_tmp__253 = ( char *)(&llvm_cbe_tmp__259[(((signed long long )llvm_cbe__2e_sum))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum = 0x%I64X",((signed long long )llvm_cbe__2e_sum));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = getelementptr inbounds i8** %%37, i64 %%28, !dbg !34 for 0x%I64xth hint within @allocateCommitments  --> \n", ++aesl_llvm_cbe_575_count);
  llvm_cbe_tmp__254 = ( char **)(&llvm_cbe_tmp__260[(((signed long long )llvm_cbe_tmp__252))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__252));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8* %%29, i8** %%30, align 8, !dbg !34 for 0x%I64xth hint within @allocateCommitments  --> \n", ++aesl_llvm_cbe_576_count);
  *llvm_cbe_tmp__254 = ( char *)llvm_cbe_tmp__253;
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = load i32* %%15, align 4, !dbg !33 for 0x%I64xth hint within @allocateCommitments  --> \n", ++aesl_llvm_cbe_577_count);
  llvm_cbe_tmp__255 = (unsigned int )*llvm_cbe_tmp__244;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__255);
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = zext i32 %%31 to i64, !dbg !33 for 0x%I64xth hint within @allocateCommitments  --> \n", ++aesl_llvm_cbe_578_count);
  llvm_cbe_tmp__256 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__255&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__256);
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec9 = add i64 %%.rec, %%32, !dbg !33 for 0x%I64xth hint within @allocateCommitments  --> \n", ++aesl_llvm_cbe__2e_rec9_count);
  llvm_cbe__2e_rec9 = (unsigned long long )((unsigned long long )(llvm_cbe__2e_rec&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__256&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.rec9 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_rec9&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum10 = add i64 %%21, %%.rec9, !dbg !33 for 0x%I64xth hint within @allocateCommitments  --> \n", ++aesl_llvm_cbe__2e_sum10_count);
  llvm_cbe__2e_sum10 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__249&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe__2e_rec9&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum10 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum10&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = add i32 %%storemerge13.us, 1, !dbg !35 for 0x%I64xth hint within @allocateCommitments  --> \n", ++aesl_llvm_cbe_579_count);
  llvm_cbe_tmp__257 = (unsigned int )((unsigned int )(llvm_cbe_storemerge13_2e_us&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__257&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = zext i32 %%33 to i64, !dbg !34 for 0x%I64xth hint within @allocateCommitments  --> \n", ++aesl_llvm_cbe_584_count);
  llvm_cbe_tmp__258 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__257&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__258);
  if ((((unsigned long long )llvm_cbe_tmp__258&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__263&18446744073709551615ULL))) {
    llvm_cbe_tmp__252__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__258;   /* for PHI node */
    llvm_cbe_storemerge13_2e_us__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__257;   /* for PHI node */
    llvm_cbe__2e_rec__PHI_TEMPORARY = (unsigned long long )llvm_cbe__2e_rec9;   /* for PHI node */
    goto llvm_cbe_tmp__275;
  } else {
    goto llvm_cbe_tmp__276;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.lr.ph.us' */
  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__274:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge4 = phi i32 [ %%47, %%41 ], [ 0, %%.lr.ph6  for 0x%I64xth hint within @allocateCommitments  --> \n", ++aesl_llvm_cbe_storemerge4_count);
  llvm_cbe_storemerge4 = (unsigned int )llvm_cbe_storemerge4__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge4 = 0x%X",llvm_cbe_storemerge4);
printf("\n = 0x%X",llvm_cbe_tmp__269);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = phi i8* [ %%46, %%41 ], [ %%19, %%.lr.ph6  for 0x%I64xth hint within @allocateCommitments  --> \n", ++aesl_llvm_cbe_598_count);
  llvm_cbe_tmp__264 = ( char *)llvm_cbe_tmp__264__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = bitcast i8* %%42 to i8**, !dbg !34 for 0x%I64xth hint within @allocateCommitments  --> \n", ++aesl_llvm_cbe_599_count);
  llvm_cbe_tmp__265 = ( char **)(( char **)llvm_cbe_tmp__264);
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = zext i32 %%storemerge4 to i64, !dbg !34 for 0x%I64xth hint within @allocateCommitments  --> \n", ++aesl_llvm_cbe_600_count);
  llvm_cbe_tmp__266 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge4&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__266);
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = getelementptr inbounds %%struct.commitments_t* %%6, i64 %%44, i32 0, !dbg !34 for 0x%I64xth hint within @allocateCommitments  --> \n", ++aesl_llvm_cbe_601_count);
  llvm_cbe_tmp__267 = ( char ***)(&llvm_cbe_tmp__238[(((signed long long )llvm_cbe_tmp__266))].field0);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__266));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8** %%43, i8*** %%45, align 8, !dbg !34 for 0x%I64xth hint within @allocateCommitments  --> \n", ++aesl_llvm_cbe_602_count);
  *llvm_cbe_tmp__267 = ( char **)llvm_cbe_tmp__265;
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = getelementptr inbounds i8* %%42, i64 %%21, !dbg !34 for 0x%I64xth hint within @allocateCommitments  --> \n", ++aesl_llvm_cbe_603_count);
  llvm_cbe_tmp__268 = ( char *)(&llvm_cbe_tmp__264[(((signed long long )llvm_cbe_tmp__249))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__249));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = add i32 %%storemerge4, 1, !dbg !35 for 0x%I64xth hint within @allocateCommitments  --> \n", ++aesl_llvm_cbe_613_count);
  llvm_cbe_tmp__269 = (unsigned int )((unsigned int )(llvm_cbe_storemerge4&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__269&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = load i32* %%1, align 4, !dbg !33 for 0x%I64xth hint within @allocateCommitments  --> \n", ++aesl_llvm_cbe_619_count);
  llvm_cbe_tmp__270 = (unsigned int )*llvm_cbe_tmp__233;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__270);
  if ((((unsigned int )llvm_cbe_tmp__269&4294967295U) < ((unsigned int )llvm_cbe_tmp__270&4294967295U))) {
    llvm_cbe_storemerge4__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__269;   /* for PHI node */
    llvm_cbe_tmp__264__PHI_TEMPORARY = ( char *)llvm_cbe_tmp__268;   /* for PHI node */
    goto llvm_cbe_tmp__274;
  } else {
    goto llvm_cbe__2e__crit_edge7;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e__crit_edge7:
  goto llvm_cbe_tmp__273;

llvm_cbe_tmp__273:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @allocateCommitments}\n");
  return llvm_cbe_tmp__238;
}


void freeCommitments(l_struct_OC_commitments_t *llvm_cbe_commitments) {
  static  unsigned long long aesl_llvm_cbe_624_count = 0;
  static  unsigned long long aesl_llvm_cbe_625_count = 0;
  static  unsigned long long aesl_llvm_cbe_626_count = 0;
  static  unsigned long long aesl_llvm_cbe_627_count = 0;
   char ***llvm_cbe_tmp__277;
  static  unsigned long long aesl_llvm_cbe_628_count = 0;
   char **llvm_cbe_tmp__278;
  static  unsigned long long aesl_llvm_cbe_629_count = 0;
   char *llvm_cbe_tmp__279;
  static  unsigned long long aesl_llvm_cbe_630_count = 0;
  static  unsigned long long aesl_llvm_cbe_631_count = 0;
   char *llvm_cbe_tmp__280;
  static  unsigned long long aesl_llvm_cbe_632_count = 0;
  static  unsigned long long aesl_llvm_cbe_633_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @freeCommitments\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.commitments_t* %%commitments, i64 0, i32 0, !dbg !33 for 0x%I64xth hint within @freeCommitments  --> \n", ++aesl_llvm_cbe_627_count);
  llvm_cbe_tmp__277 = ( char ***)(&llvm_cbe_commitments->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i8*** %%1, align 8, !dbg !33 for 0x%I64xth hint within @freeCommitments  --> \n", ++aesl_llvm_cbe_628_count);
  llvm_cbe_tmp__278 = ( char **)*llvm_cbe_tmp__277;
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = bitcast i8** %%2 to i8*, !dbg !33 for 0x%I64xth hint within @freeCommitments  --> \n", ++aesl_llvm_cbe_629_count);
  llvm_cbe_tmp__279 = ( char *)(( char *)llvm_cbe_tmp__278);
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @free(i8* %%3), !dbg !33 for 0x%I64xth hint within @freeCommitments  --> \n", ++aesl_llvm_cbe_630_count);
   /*tail*/ free(( char *)llvm_cbe_tmp__279);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = bitcast %%struct.commitments_t* %%commitments to i8*, !dbg !33 for 0x%I64xth hint within @freeCommitments  --> \n", ++aesl_llvm_cbe_631_count);
  llvm_cbe_tmp__280 = ( char *)(( char *)llvm_cbe_commitments);
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @free(i8* %%4), !dbg !33 for 0x%I64xth hint within @freeCommitments  --> \n", ++aesl_llvm_cbe_632_count);
   /*tail*/ free(( char *)llvm_cbe_tmp__280);
if (AESL_DEBUG_TRACE) {
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @freeCommitments}\n");
  return;
}


void allocateCommitments2(l_struct_OC_commitments_t *llvm_cbe_commitments, l_struct_OC_paramset_t *llvm_cbe_params, signed long long llvm_cbe_numCommitments) {
  static  unsigned long long aesl_llvm_cbe_634_count = 0;
  static  unsigned long long aesl_llvm_cbe_635_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_647_count = 0;
  signed long long *llvm_cbe_tmp__281;
  static  unsigned long long aesl_llvm_cbe_648_count = 0;
  static  unsigned long long aesl_llvm_cbe_649_count = 0;
  signed int *llvm_cbe_tmp__282;
  static  unsigned long long aesl_llvm_cbe_650_count = 0;
  unsigned int llvm_cbe_tmp__283;
  static  unsigned long long aesl_llvm_cbe_651_count = 0;
  unsigned long long llvm_cbe_tmp__284;
  static  unsigned long long aesl_llvm_cbe_652_count = 0;
  unsigned long long llvm_cbe_tmp__285;
  static  unsigned long long aesl_llvm_cbe_653_count = 0;
  unsigned long long llvm_cbe_tmp__286;
  static  unsigned long long aesl_llvm_cbe_654_count = 0;
  unsigned long long llvm_cbe_tmp__287;
  static  unsigned long long aesl_llvm_cbe_655_count = 0;
   char *llvm_cbe_tmp__288;
  static  unsigned long long aesl_llvm_cbe_656_count = 0;
  static  unsigned long long aesl_llvm_cbe_657_count = 0;
  static  unsigned long long aesl_llvm_cbe_658_count = 0;
  static  unsigned long long aesl_llvm_cbe_659_count = 0;
  static  unsigned long long aesl_llvm_cbe_660_count = 0;
  static  unsigned long long aesl_llvm_cbe_661_count = 0;
   char **llvm_cbe_tmp__289;
  static  unsigned long long aesl_llvm_cbe_662_count = 0;
   char ***llvm_cbe_tmp__290;
  static  unsigned long long aesl_llvm_cbe_663_count = 0;
  static  unsigned long long aesl_llvm_cbe_664_count = 0;
  static  unsigned long long aesl_llvm_cbe_665_count = 0;
  static  unsigned long long aesl_llvm_cbe_666_count = 0;
  static  unsigned long long aesl_llvm_cbe_667_count = 0;
  static  unsigned long long aesl_llvm_cbe_668_count = 0;
  static  unsigned long long aesl_llvm_cbe_669_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned long long llvm_cbe_storemerge1;
  unsigned long long llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_rec_count = 0;
  unsigned long long llvm_cbe__2e_rec;
  unsigned long long llvm_cbe__2e_rec__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_sum_count = 0;
  unsigned long long llvm_cbe__2e_sum;
  static  unsigned long long aesl_llvm_cbe_670_count = 0;
   char *llvm_cbe_tmp__291;
  static  unsigned long long aesl_llvm_cbe_671_count = 0;
   char **llvm_cbe_tmp__292;
  static  unsigned long long aesl_llvm_cbe_672_count = 0;
   char **llvm_cbe_tmp__293;
  static  unsigned long long aesl_llvm_cbe_673_count = 0;
  static  unsigned long long aesl_llvm_cbe_674_count = 0;
  unsigned int llvm_cbe_tmp__294;
  static  unsigned long long aesl_llvm_cbe_675_count = 0;
  unsigned long long llvm_cbe_tmp__295;
  static  unsigned long long aesl_llvm_cbe__2e_rec2_count = 0;
  unsigned long long llvm_cbe__2e_rec2;
  static  unsigned long long aesl_llvm_cbe_676_count = 0;
  unsigned long long llvm_cbe_tmp__296;
  static  unsigned long long aesl_llvm_cbe_677_count = 0;
  static  unsigned long long aesl_llvm_cbe_678_count = 0;
  static  unsigned long long aesl_llvm_cbe_679_count = 0;
  static  unsigned long long aesl_llvm_cbe_680_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_681_count = 0;
  static  unsigned long long aesl_llvm_cbe_682_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @allocateCommitments2\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.commitments_t* %%commitments, i64 0, i32 1, !dbg !33 for 0x%I64xth hint within @allocateCommitments2  --> \n", ++aesl_llvm_cbe_647_count);
  llvm_cbe_tmp__281 = (signed long long *)(&llvm_cbe_commitments->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%numCommitments, i64* %%1, align 8, !dbg !33 for 0x%I64xth hint within @allocateCommitments2  --> \n", ++aesl_llvm_cbe_648_count);
  *llvm_cbe_tmp__281 = llvm_cbe_numCommitments;
if (AESL_DEBUG_TRACE)
printf("\nnumCommitments = 0x%I64X\n", llvm_cbe_numCommitments);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds %%struct.paramset_t* %%params, i64 0, i32 13, !dbg !33 for 0x%I64xth hint within @allocateCommitments2  --> \n", ++aesl_llvm_cbe_649_count);
  llvm_cbe_tmp__282 = (signed int *)(&llvm_cbe_params->field13);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = load i32* %%2, align 4, !dbg !33 for 0x%I64xth hint within @allocateCommitments2  --> \n", ++aesl_llvm_cbe_650_count);
  llvm_cbe_tmp__283 = (unsigned int )*llvm_cbe_tmp__282;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__283);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = zext i32 %%3 to i64, !dbg !33 for 0x%I64xth hint within @allocateCommitments2  --> \n", ++aesl_llvm_cbe_651_count);
  llvm_cbe_tmp__284 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__283&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__284);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = mul i64 %%4, %%numCommitments, !dbg !33 for 0x%I64xth hint within @allocateCommitments2  --> \n", ++aesl_llvm_cbe_652_count);
  llvm_cbe_tmp__285 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__284&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_numCommitments&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__285&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = shl i64 %%numCommitments, 3, !dbg !33 for 0x%I64xth hint within @allocateCommitments2  --> \n", ++aesl_llvm_cbe_653_count);
  llvm_cbe_tmp__286 = (unsigned long long )llvm_cbe_numCommitments << 3ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__286);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = add i64 %%5, %%6, !dbg !33 for 0x%I64xth hint within @allocateCommitments2  --> \n", ++aesl_llvm_cbe_654_count);
  llvm_cbe_tmp__287 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__285&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__286&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__287&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = tail call i8* @malloc(i64 %%7), !dbg !33 for 0x%I64xth hint within @allocateCommitments2  --> \n", ++aesl_llvm_cbe_655_count);
  llvm_cbe_tmp__288 = ( char *) /*tail*/ ( char *)malloc(llvm_cbe_tmp__287);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__287);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__288);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = bitcast i8* %%8 to i8**, !dbg !33 for 0x%I64xth hint within @allocateCommitments2  --> \n", ++aesl_llvm_cbe_661_count);
  llvm_cbe_tmp__289 = ( char **)(( char **)llvm_cbe_tmp__288);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds %%struct.commitments_t* %%commitments, i64 0, i32 0, !dbg !33 for 0x%I64xth hint within @allocateCommitments2  --> \n", ++aesl_llvm_cbe_662_count);
  llvm_cbe_tmp__290 = ( char ***)(&llvm_cbe_commitments->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8** %%9, i8*** %%10, align 8, !dbg !33 for 0x%I64xth hint within @allocateCommitments2  --> \n", ++aesl_llvm_cbe_663_count);
  *llvm_cbe_tmp__290 = ( char **)llvm_cbe_tmp__289;
  if (((llvm_cbe_numCommitments&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    llvm_cbe__2e_rec__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i64 [ %%17, %%.lr.ph ], [ 0, %%0  for 0x%I64xth hint within @allocateCommitments2  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned long long )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",llvm_cbe_storemerge1);
printf("\n = 0x%I64X",llvm_cbe_tmp__296);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec = phi i64 [ %%.rec2, %%.lr.ph ], [ 0, %%0  for 0x%I64xth hint within @allocateCommitments2  --> \n", ++aesl_llvm_cbe__2e_rec_count);
  llvm_cbe__2e_rec = (unsigned long long )llvm_cbe__2e_rec__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.rec = 0x%I64X",llvm_cbe__2e_rec);
printf("\n.rec2 = 0x%I64X",llvm_cbe__2e_rec2);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum = add i64 %%6, %%.re for 0x%I64xth hint within @allocateCommitments2  --> \n", ++aesl_llvm_cbe__2e_sum_count);
  llvm_cbe__2e_sum = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__286&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe__2e_rec&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr i8* %%8, i64 %%.su for 0x%I64xth hint within @allocateCommitments2  --> \n", ++aesl_llvm_cbe_670_count);
  llvm_cbe_tmp__291 = ( char *)(&llvm_cbe_tmp__288[(((signed long long )llvm_cbe__2e_sum))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum = 0x%I64X",((signed long long )llvm_cbe__2e_sum));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = load i8*** %%10, align 8, !dbg !33 for 0x%I64xth hint within @allocateCommitments2  --> \n", ++aesl_llvm_cbe_671_count);
  llvm_cbe_tmp__292 = ( char **)*llvm_cbe_tmp__290;
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds i8** %%13, i64 %%storemerge1, !dbg !33 for 0x%I64xth hint within @allocateCommitments2  --> \n", ++aesl_llvm_cbe_672_count);
  llvm_cbe_tmp__293 = ( char **)(&llvm_cbe_tmp__292[(((signed long long )llvm_cbe_storemerge1))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",((signed long long )llvm_cbe_storemerge1));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8* %%12, i8** %%14, align 8, !dbg !33 for 0x%I64xth hint within @allocateCommitments2  --> \n", ++aesl_llvm_cbe_673_count);
  *llvm_cbe_tmp__293 = ( char *)llvm_cbe_tmp__291;
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = load i32* %%2, align 4, !dbg !34 for 0x%I64xth hint within @allocateCommitments2  --> \n", ++aesl_llvm_cbe_674_count);
  llvm_cbe_tmp__294 = (unsigned int )*llvm_cbe_tmp__282;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__294);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = zext i32 %%15 to i64, !dbg !34 for 0x%I64xth hint within @allocateCommitments2  --> \n", ++aesl_llvm_cbe_675_count);
  llvm_cbe_tmp__295 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__294&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__295);
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec2 = add i64 %%.rec, %%16, !dbg !34 for 0x%I64xth hint within @allocateCommitments2  --> \n", ++aesl_llvm_cbe__2e_rec2_count);
  llvm_cbe__2e_rec2 = (unsigned long long )((unsigned long long )(llvm_cbe__2e_rec&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__295&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.rec2 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_rec2&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = add i64 %%storemerge1, 1, !dbg !34 for 0x%I64xth hint within @allocateCommitments2  --> \n", ++aesl_llvm_cbe_676_count);
  llvm_cbe_tmp__296 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__296&18446744073709551615ull)));
  if (((llvm_cbe_tmp__296&18446744073709551615ULL) == (llvm_cbe_numCommitments&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__296;   /* for PHI node */
    llvm_cbe__2e_rec__PHI_TEMPORARY = (unsigned long long )llvm_cbe__2e_rec2;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @allocateCommitments2}\n");
  return;
}


void freeCommitments2(l_struct_OC_commitments_t *llvm_cbe_commitments) {
  static  unsigned long long aesl_llvm_cbe_683_count = 0;
  static  unsigned long long aesl_llvm_cbe_684_count = 0;
  static  unsigned long long aesl_llvm_cbe_685_count = 0;
  static  unsigned long long aesl_llvm_cbe_686_count = 0;
  static  unsigned long long aesl_llvm_cbe_687_count = 0;
  static  unsigned long long aesl_llvm_cbe_688_count = 0;
   char ***llvm_cbe_tmp__297;
  static  unsigned long long aesl_llvm_cbe_689_count = 0;
   char **llvm_cbe_tmp__298;
  static  unsigned long long aesl_llvm_cbe_690_count = 0;
   char *llvm_cbe_tmp__299;
  static  unsigned long long aesl_llvm_cbe_691_count = 0;
  static  unsigned long long aesl_llvm_cbe_692_count = 0;
  static  unsigned long long aesl_llvm_cbe_693_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @freeCommitments2\n");
  if (((llvm_cbe_commitments) == (((l_struct_OC_commitments_t *)/*NULL*/0)))) {
    goto llvm_cbe_tmp__300;
  } else {
    goto llvm_cbe_tmp__301;
  }

llvm_cbe_tmp__301:
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.commitments_t* %%commitments, i64 0, i32 0, !dbg !33 for 0x%I64xth hint within @freeCommitments2  --> \n", ++aesl_llvm_cbe_688_count);
  llvm_cbe_tmp__297 = ( char ***)(&llvm_cbe_commitments->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i8*** %%3, align 8, !dbg !33 for 0x%I64xth hint within @freeCommitments2  --> \n", ++aesl_llvm_cbe_689_count);
  llvm_cbe_tmp__298 = ( char **)*llvm_cbe_tmp__297;
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = bitcast i8** %%4 to i8*, !dbg !33 for 0x%I64xth hint within @freeCommitments2  --> \n", ++aesl_llvm_cbe_690_count);
  llvm_cbe_tmp__299 = ( char *)(( char *)llvm_cbe_tmp__298);
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @free(i8* %%5), !dbg !33 for 0x%I64xth hint within @freeCommitments2  --> \n", ++aesl_llvm_cbe_691_count);
   /*tail*/ free(( char *)llvm_cbe_tmp__299);
if (AESL_DEBUG_TRACE) {
}
  goto llvm_cbe_tmp__300;

llvm_cbe_tmp__300:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @freeCommitments2}\n");
  return;
}


 char **allocateInputs(l_struct_OC_paramset_t *llvm_cbe_params) {
  static  unsigned long long aesl_llvm_cbe_694_count = 0;
  static  unsigned long long aesl_llvm_cbe_695_count = 0;
  static  unsigned long long aesl_llvm_cbe_696_count = 0;
  static  unsigned long long aesl_llvm_cbe_697_count = 0;
  static  unsigned long long aesl_llvm_cbe_698_count = 0;
  static  unsigned long long aesl_llvm_cbe_699_count = 0;
  static  unsigned long long aesl_llvm_cbe_700_count = 0;
  signed int *llvm_cbe_tmp__302;
  static  unsigned long long aesl_llvm_cbe_701_count = 0;
  unsigned int llvm_cbe_tmp__303;
  static  unsigned long long aesl_llvm_cbe_702_count = 0;
  unsigned long long llvm_cbe_tmp__304;
  static  unsigned long long aesl_llvm_cbe_703_count = 0;
  signed int *llvm_cbe_tmp__305;
  static  unsigned long long aesl_llvm_cbe_704_count = 0;
  unsigned int llvm_cbe_tmp__306;
  static  unsigned long long aesl_llvm_cbe_705_count = 0;
  unsigned long long llvm_cbe_tmp__307;
  static  unsigned long long aesl_llvm_cbe_706_count = 0;
  unsigned long long llvm_cbe_tmp__308;
  static  unsigned long long aesl_llvm_cbe_707_count = 0;
  unsigned long long llvm_cbe_tmp__309;
  static  unsigned long long aesl_llvm_cbe_708_count = 0;
   char *llvm_cbe_tmp__310;
  static  unsigned long long aesl_llvm_cbe_709_count = 0;
  static  unsigned long long aesl_llvm_cbe_710_count = 0;
  static  unsigned long long aesl_llvm_cbe_711_count = 0;
  static  unsigned long long aesl_llvm_cbe_712_count = 0;
  static  unsigned long long aesl_llvm_cbe_713_count = 0;
  static  unsigned long long aesl_llvm_cbe_714_count = 0;
   char **llvm_cbe_tmp__311;
  static  unsigned long long aesl_llvm_cbe_715_count = 0;
  static  unsigned long long aesl_llvm_cbe_716_count = 0;
  static  unsigned long long aesl_llvm_cbe_717_count = 0;
  static  unsigned long long aesl_llvm_cbe_718_count = 0;
  unsigned int llvm_cbe_tmp__312;
  static  unsigned long long aesl_llvm_cbe_719_count = 0;
  unsigned long long llvm_cbe_tmp__313;
  static  unsigned long long aesl_llvm_cbe_720_count = 0;
  unsigned long long llvm_cbe_tmp__314;
  static  unsigned long long aesl_llvm_cbe_721_count = 0;
  static  unsigned long long aesl_llvm_cbe_722_count = 0;
  static  unsigned long long aesl_llvm_cbe_723_count = 0;
  static  unsigned long long aesl_llvm_cbe_724_count = 0;
  static  unsigned long long aesl_llvm_cbe_725_count = 0;
  static  unsigned long long aesl_llvm_cbe_726_count = 0;
  static  unsigned long long aesl_llvm_cbe_727_count = 0;
  unsigned int llvm_cbe_tmp__315;
  static  unsigned long long aesl_llvm_cbe_728_count = 0;
  unsigned long long llvm_cbe_tmp__316;
  static  unsigned long long aesl_llvm_cbe_729_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_rec_count = 0;
  unsigned long long llvm_cbe__2e_rec;
  unsigned long long llvm_cbe__2e_rec__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_sum_count = 0;
  unsigned long long llvm_cbe__2e_sum;
  static  unsigned long long aesl_llvm_cbe_730_count = 0;
   char *llvm_cbe_tmp__317;
  static  unsigned long long aesl_llvm_cbe_731_count = 0;
  unsigned long long llvm_cbe_tmp__318;
  static  unsigned long long aesl_llvm_cbe_732_count = 0;
   char **llvm_cbe_tmp__319;
  static  unsigned long long aesl_llvm_cbe_733_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_rec2_count = 0;
  unsigned long long llvm_cbe__2e_rec2;
  static  unsigned long long aesl_llvm_cbe_734_count = 0;
  unsigned int llvm_cbe_tmp__320;
  static  unsigned long long aesl_llvm_cbe_735_count = 0;
  static  unsigned long long aesl_llvm_cbe_736_count = 0;
  static  unsigned long long aesl_llvm_cbe_737_count = 0;
  static  unsigned long long aesl_llvm_cbe_738_count = 0;
  static  unsigned long long aesl_llvm_cbe_739_count = 0;
  static  unsigned long long aesl_llvm_cbe_740_count = 0;
  static  unsigned long long aesl_llvm_cbe_741_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @allocateInputs\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.paramset_t* %%params, i64 0, i32 8, !dbg !33 for 0x%I64xth hint within @allocateInputs  --> \n", ++aesl_llvm_cbe_700_count);
  llvm_cbe_tmp__302 = (signed int *)(&llvm_cbe_params->field8);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i32* %%1, align 4, !dbg !33 for 0x%I64xth hint within @allocateInputs  --> \n", ++aesl_llvm_cbe_701_count);
  llvm_cbe_tmp__303 = (unsigned int )*llvm_cbe_tmp__302;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__303);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = zext i32 %%2 to i64, !dbg !33 for 0x%I64xth hint within @allocateInputs  --> \n", ++aesl_llvm_cbe_702_count);
  llvm_cbe_tmp__304 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__303&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__304);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds %%struct.paramset_t* %%params, i64 0, i32 3, !dbg !33 for 0x%I64xth hint within @allocateInputs  --> \n", ++aesl_llvm_cbe_703_count);
  llvm_cbe_tmp__305 = (signed int *)(&llvm_cbe_params->field3);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load i32* %%4, align 4, !dbg !33 for 0x%I64xth hint within @allocateInputs  --> \n", ++aesl_llvm_cbe_704_count);
  llvm_cbe_tmp__306 = (unsigned int )*llvm_cbe_tmp__305;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__306);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = zext i32 %%5 to i64, !dbg !33 for 0x%I64xth hint within @allocateInputs  --> \n", ++aesl_llvm_cbe_705_count);
  llvm_cbe_tmp__307 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__306&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__307);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = add i64 %%6, 8, !dbg !33 for 0x%I64xth hint within @allocateInputs  --> \n", ++aesl_llvm_cbe_706_count);
  llvm_cbe_tmp__308 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__307&18446744073709551615ull)) + ((unsigned long long )(8ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__308&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = mul i64 %%7, %%3, !dbg !33 for 0x%I64xth hint within @allocateInputs  --> \n", ++aesl_llvm_cbe_707_count);
  llvm_cbe_tmp__309 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__308&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__304&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__309&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = tail call i8* @calloc(i64 1, i64 %%8) nounwind, !dbg !33 for 0x%I64xth hint within @allocateInputs  --> \n", ++aesl_llvm_cbe_708_count);
  llvm_cbe_tmp__310 = ( char *) /*tail*/ ( char *)calloc(1ull, llvm_cbe_tmp__309);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",1ull);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__309);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__310);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = bitcast i8* %%9 to i8**, !dbg !33 for 0x%I64xth hint within @allocateInputs  --> \n", ++aesl_llvm_cbe_714_count);
  llvm_cbe_tmp__311 = ( char **)(( char **)llvm_cbe_tmp__310);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = load i32* %%1, align 4, !dbg !33 for 0x%I64xth hint within @allocateInputs  --> \n", ++aesl_llvm_cbe_718_count);
  llvm_cbe_tmp__312 = (unsigned int )*llvm_cbe_tmp__302;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__312);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = zext i32 %%11 to i64, !dbg !33 for 0x%I64xth hint within @allocateInputs  --> \n", ++aesl_llvm_cbe_719_count);
  llvm_cbe_tmp__313 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__312&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__313);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = shl nuw nsw i64 %%12, 3, !dbg !33 for 0x%I64xth hint within @allocateInputs  --> \n", ++aesl_llvm_cbe_720_count);
  llvm_cbe_tmp__314 = (unsigned long long )llvm_cbe_tmp__313 << 3ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__314);
  if (((llvm_cbe_tmp__312&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    goto llvm_cbe__2e_lr_2e_ph;
  }

llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = load i32* %%4, align 4, !dbg !33 for 0x%I64xth hint within @allocateInputs  --> \n", ++aesl_llvm_cbe_727_count);
  llvm_cbe_tmp__315 = (unsigned int )*llvm_cbe_tmp__305;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__315);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = zext i32 %%15 to i64, !dbg !33 for 0x%I64xth hint within @allocateInputs  --> \n", ++aesl_llvm_cbe_728_count);
  llvm_cbe_tmp__316 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__315&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__316);
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  llvm_cbe__2e_rec__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__321;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__321:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ 0, %%.lr.ph ], [ %%21, %%17  for 0x%I64xth hint within @allocateInputs  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__320);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec = phi i64 [ 0, %%.lr.ph ], [ %%.rec2, %%17  for 0x%I64xth hint within @allocateInputs  --> \n", ++aesl_llvm_cbe__2e_rec_count);
  llvm_cbe__2e_rec = (unsigned long long )llvm_cbe__2e_rec__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.rec = 0x%I64X",llvm_cbe__2e_rec);
printf("\n = 0x%I64X",0ull);
printf("\n.rec2 = 0x%I64X",llvm_cbe__2e_rec2);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum = add i64 %%13, %%.re for 0x%I64xth hint within @allocateInputs  --> \n", ++aesl_llvm_cbe__2e_sum_count);
  llvm_cbe__2e_sum = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__314&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe__2e_rec&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = getelementptr i8* %%9, i64 %%.su for 0x%I64xth hint within @allocateInputs  --> \n", ++aesl_llvm_cbe_730_count);
  llvm_cbe_tmp__317 = ( char *)(&llvm_cbe_tmp__310[(((signed long long )llvm_cbe__2e_sum))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum = 0x%I64X",((signed long long )llvm_cbe__2e_sum));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = zext i32 %%storemerge1 to i64, !dbg !34 for 0x%I64xth hint within @allocateInputs  --> \n", ++aesl_llvm_cbe_731_count);
  llvm_cbe_tmp__318 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge1&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__318);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = getelementptr inbounds i8** %%10, i64 %%19, !dbg !34 for 0x%I64xth hint within @allocateInputs  --> \n", ++aesl_llvm_cbe_732_count);
  llvm_cbe_tmp__319 = ( char **)(&llvm_cbe_tmp__311[(((signed long long )llvm_cbe_tmp__318))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__318));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8* %%18, i8** %%20, align 8, !dbg !34 for 0x%I64xth hint within @allocateInputs  --> \n", ++aesl_llvm_cbe_733_count);
  *llvm_cbe_tmp__319 = ( char *)llvm_cbe_tmp__317;
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec2 = add i64 %%.rec, %%16, !dbg !33 for 0x%I64xth hint within @allocateInputs  --> \n", ++aesl_llvm_cbe__2e_rec2_count);
  llvm_cbe__2e_rec2 = (unsigned long long )((unsigned long long )(llvm_cbe__2e_rec&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__316&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.rec2 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_rec2&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = add i32 %%storemerge1, 1, !dbg !34 for 0x%I64xth hint within @allocateInputs  --> \n", ++aesl_llvm_cbe_734_count);
  llvm_cbe_tmp__320 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__320&4294967295ull)));
  if ((((unsigned int )llvm_cbe_tmp__320&4294967295U) < ((unsigned int )llvm_cbe_tmp__312&4294967295U))) {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__320;   /* for PHI node */
    llvm_cbe__2e_rec__PHI_TEMPORARY = (unsigned long long )llvm_cbe__2e_rec2;   /* for PHI node */
    goto llvm_cbe_tmp__321;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e__crit_edge:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @allocateInputs}\n");
  return llvm_cbe_tmp__311;
}


void freeInputs( char **llvm_cbe_inputs) {
  static  unsigned long long aesl_llvm_cbe_742_count = 0;
  static  unsigned long long aesl_llvm_cbe_743_count = 0;
  static  unsigned long long aesl_llvm_cbe_744_count = 0;
   char *llvm_cbe_tmp__322;
  static  unsigned long long aesl_llvm_cbe_745_count = 0;
  static  unsigned long long aesl_llvm_cbe_746_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @freeInputs\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = bitcast i8** %%inputs to i8*, !dbg !33 for 0x%I64xth hint within @freeInputs  --> \n", ++aesl_llvm_cbe_744_count);
  llvm_cbe_tmp__322 = ( char *)(( char *)llvm_cbe_inputs);
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @free(i8* %%1), !dbg !33 for 0x%I64xth hint within @freeInputs  --> \n", ++aesl_llvm_cbe_745_count);
   /*tail*/ free(( char *)llvm_cbe_tmp__322);
if (AESL_DEBUG_TRACE) {
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @freeInputs}\n");
  return;
}


l_struct_OC_msgs_t *allocateMsgs(l_struct_OC_paramset_t *llvm_cbe_params) {
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
  static  unsigned long long aesl_llvm_cbe_759_count = 0;
  signed int *llvm_cbe_tmp__323;
  static  unsigned long long aesl_llvm_cbe_760_count = 0;
  unsigned int llvm_cbe_tmp__324;
  static  unsigned long long aesl_llvm_cbe_761_count = 0;
  unsigned long long llvm_cbe_tmp__325;
  static  unsigned long long aesl_llvm_cbe_762_count = 0;
  unsigned long long llvm_cbe_tmp__326;
  static  unsigned long long aesl_llvm_cbe_763_count = 0;
   char *llvm_cbe_tmp__327;
  static  unsigned long long aesl_llvm_cbe_764_count = 0;
  l_struct_OC_msgs_t *llvm_cbe_tmp__328;
  static  unsigned long long aesl_llvm_cbe_765_count = 0;
  static  unsigned long long aesl_llvm_cbe_766_count = 0;
  static  unsigned long long aesl_llvm_cbe_767_count = 0;
  static  unsigned long long aesl_llvm_cbe_768_count = 0;
  static  unsigned long long aesl_llvm_cbe_769_count = 0;
  static  unsigned long long aesl_llvm_cbe_770_count = 0;
  static  unsigned long long aesl_llvm_cbe_771_count = 0;
  signed int *llvm_cbe_tmp__329;
  static  unsigned long long aesl_llvm_cbe_772_count = 0;
  unsigned int llvm_cbe_tmp__330;
  static  unsigned long long aesl_llvm_cbe_773_count = 0;
  signed int *llvm_cbe_tmp__331;
  static  unsigned long long aesl_llvm_cbe_774_count = 0;
  unsigned int llvm_cbe_tmp__332;
  static  unsigned long long aesl_llvm_cbe_775_count = 0;
  signed int *llvm_cbe_tmp__333;
  static  unsigned long long aesl_llvm_cbe_776_count = 0;
  unsigned int llvm_cbe_tmp__334;
  static  unsigned long long aesl_llvm_cbe_777_count = 0;
  unsigned int llvm_cbe_tmp__335;
  static  unsigned long long aesl_llvm_cbe_778_count = 0;
  unsigned int llvm_cbe_tmp__336;
  static  unsigned long long aesl_llvm_cbe_779_count = 0;
  unsigned long long llvm_cbe_tmp__337;
  static  unsigned long long aesl_llvm_cbe_780_count = 0;
  unsigned long long llvm_cbe_tmp__338;
  static  unsigned long long aesl_llvm_cbe_781_count = 0;
  unsigned long long llvm_cbe_tmp__339;
  static  unsigned long long aesl_llvm_cbe_782_count = 0;
  unsigned long long llvm_cbe_tmp__340;
  static  unsigned long long aesl_llvm_cbe_783_count = 0;
  unsigned long long llvm_cbe_tmp__341;
  static  unsigned long long aesl_llvm_cbe_784_count = 0;
   char *llvm_cbe_tmp__342;
  static  unsigned long long aesl_llvm_cbe_785_count = 0;
  static  unsigned long long aesl_llvm_cbe_786_count = 0;
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
  unsigned int llvm_cbe_tmp__343;
  static  unsigned long long aesl_llvm_cbe_798_count = 0;
  static  unsigned long long aesl_llvm_cbe_799_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned int llvm_cbe_storemerge3;
  unsigned int llvm_cbe_storemerge3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_800_count = 0;
   char *llvm_cbe_tmp__344;
   char *llvm_cbe_tmp__344__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_801_count = 0;
  unsigned long long llvm_cbe_tmp__345;
  static  unsigned long long aesl_llvm_cbe_802_count = 0;
  signed long long *llvm_cbe_tmp__346;
  static  unsigned long long aesl_llvm_cbe_803_count = 0;
  static  unsigned long long aesl_llvm_cbe_804_count = 0;
  signed int *llvm_cbe_tmp__347;
  static  unsigned long long aesl_llvm_cbe_805_count = 0;
  static  unsigned long long aesl_llvm_cbe_806_count = 0;
   char **llvm_cbe_tmp__348;
  static  unsigned long long aesl_llvm_cbe_807_count = 0;
   char ***llvm_cbe_tmp__349;
  static  unsigned long long aesl_llvm_cbe_808_count = 0;
  static  unsigned long long aesl_llvm_cbe_809_count = 0;
  unsigned int llvm_cbe_tmp__350;
  static  unsigned long long aesl_llvm_cbe_810_count = 0;
  unsigned long long llvm_cbe_tmp__351;
  static  unsigned long long aesl_llvm_cbe_811_count = 0;
  unsigned long long llvm_cbe_tmp__352;
  static  unsigned long long aesl_llvm_cbe_812_count = 0;
  static  unsigned long long aesl_llvm_cbe_813_count = 0;
  static  unsigned long long aesl_llvm_cbe_814_count = 0;
  static  unsigned long long aesl_llvm_cbe_815_count = 0;
  static  unsigned long long aesl_llvm_cbe_816_count = 0;
  static  unsigned long long aesl_llvm_cbe_817_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_count = 0;
  unsigned int llvm_cbe_storemerge12;
  unsigned int llvm_cbe_storemerge12__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_rec_count = 0;
  unsigned long long llvm_cbe__2e_rec;
  unsigned long long llvm_cbe__2e_rec__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_sum_count = 0;
  unsigned long long llvm_cbe__2e_sum;
  static  unsigned long long aesl_llvm_cbe_818_count = 0;
   char *llvm_cbe_tmp__353;
  static  unsigned long long aesl_llvm_cbe_819_count = 0;
  unsigned long long llvm_cbe_tmp__354;
  static  unsigned long long aesl_llvm_cbe_820_count = 0;
   char **llvm_cbe_tmp__355;
  static  unsigned long long aesl_llvm_cbe_821_count = 0;
  static  unsigned long long aesl_llvm_cbe_822_count = 0;
  unsigned int llvm_cbe_tmp__356;
  static  unsigned long long aesl_llvm_cbe_823_count = 0;
  unsigned int llvm_cbe_tmp__357;
  static  unsigned long long aesl_llvm_cbe_824_count = 0;
  unsigned int llvm_cbe_tmp__358;
  static  unsigned long long aesl_llvm_cbe_825_count = 0;
  unsigned long long llvm_cbe_tmp__359;
  static  unsigned long long aesl_llvm_cbe__2e_rec8_count = 0;
  unsigned long long llvm_cbe__2e_rec8;
  static  unsigned long long aesl_llvm_cbe__2e_sum9_count = 0;
  unsigned long long llvm_cbe__2e_sum9;
  static  unsigned long long aesl_llvm_cbe_826_count = 0;
  unsigned int llvm_cbe_tmp__360;
  static  unsigned long long aesl_llvm_cbe_827_count = 0;
  static  unsigned long long aesl_llvm_cbe_828_count = 0;
  static  unsigned long long aesl_llvm_cbe_829_count = 0;
  static  unsigned long long aesl_llvm_cbe_830_count = 0;
  static  unsigned long long aesl_llvm_cbe_831_count = 0;
  unsigned int llvm_cbe_tmp__361;
  static  unsigned long long aesl_llvm_cbe_832_count = 0;
  static  unsigned long long aesl_llvm_cbe_833_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_sum9_2e_pn_count = 0;
  unsigned long long llvm_cbe__2e_sum9_2e_pn;
  unsigned long long llvm_cbe__2e_sum9_2e_pn__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_lcssa_count = 0;
   char *llvm_cbe__2e_lcssa;
  static  unsigned long long aesl_llvm_cbe_834_count = 0;
  static  unsigned long long aesl_llvm_cbe_835_count = 0;
  unsigned int llvm_cbe_tmp__362;
  static  unsigned long long aesl_llvm_cbe_836_count = 0;
  static  unsigned long long aesl_llvm_cbe_837_count = 0;
  static  unsigned long long aesl_llvm_cbe_838_count = 0;
  static  unsigned long long aesl_llvm_cbe_839_count = 0;
  static  unsigned long long aesl_llvm_cbe_840_count = 0;
  static  unsigned long long aesl_llvm_cbe_841_count = 0;
  static  unsigned long long aesl_llvm_cbe_842_count = 0;
  static  unsigned long long aesl_llvm_cbe_843_count = 0;
  unsigned int llvm_cbe_tmp__363;
  static  unsigned long long aesl_llvm_cbe_844_count = 0;
  static  unsigned long long aesl_llvm_cbe_845_count = 0;
  static  unsigned long long aesl_llvm_cbe_846_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @allocateMsgs\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.paramset_t* %%params, i64 0, i32 8, !dbg !33 for 0x%I64xth hint within @allocateMsgs  --> \n", ++aesl_llvm_cbe_759_count);
  llvm_cbe_tmp__323 = (signed int *)(&llvm_cbe_params->field8);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i32* %%1, align 4, !dbg !33 for 0x%I64xth hint within @allocateMsgs  --> \n", ++aesl_llvm_cbe_760_count);
  llvm_cbe_tmp__324 = (unsigned int )*llvm_cbe_tmp__323;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__324);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = zext i32 %%2 to i64, !dbg !33 for 0x%I64xth hint within @allocateMsgs  --> \n", ++aesl_llvm_cbe_761_count);
  llvm_cbe_tmp__325 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__324&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__325);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = mul i64 %%3, 24, !dbg !33 for 0x%I64xth hint within @allocateMsgs  --> \n", ++aesl_llvm_cbe_762_count);
  llvm_cbe_tmp__326 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__325&18446744073709551615ull)) * ((unsigned long long )(24ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__326&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = tail call i8* @malloc(i64 %%4), !dbg !33 for 0x%I64xth hint within @allocateMsgs  --> \n", ++aesl_llvm_cbe_763_count);
  llvm_cbe_tmp__327 = ( char *) /*tail*/ ( char *)malloc(llvm_cbe_tmp__326);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__326);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__327);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = bitcast i8* %%5 to %%struct.msgs_t*, !dbg !33 for 0x%I64xth hint within @allocateMsgs  --> \n", ++aesl_llvm_cbe_764_count);
  llvm_cbe_tmp__328 = (l_struct_OC_msgs_t *)((l_struct_OC_msgs_t *)llvm_cbe_tmp__327);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds %%struct.paramset_t* %%params, i64 0, i32 10, !dbg !33 for 0x%I64xth hint within @allocateMsgs  --> \n", ++aesl_llvm_cbe_771_count);
  llvm_cbe_tmp__329 = (signed int *)(&llvm_cbe_params->field10);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load i32* %%7, align 4, !dbg !33 for 0x%I64xth hint within @allocateMsgs  --> \n", ++aesl_llvm_cbe_772_count);
  llvm_cbe_tmp__330 = (unsigned int )*llvm_cbe_tmp__329;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__330);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds %%struct.paramset_t* %%params, i64 0, i32 5, !dbg !33 for 0x%I64xth hint within @allocateMsgs  --> \n", ++aesl_llvm_cbe_773_count);
  llvm_cbe_tmp__331 = (signed int *)(&llvm_cbe_params->field5);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = load i32* %%9, align 4, !dbg !33 for 0x%I64xth hint within @allocateMsgs  --> \n", ++aesl_llvm_cbe_774_count);
  llvm_cbe_tmp__332 = (unsigned int )*llvm_cbe_tmp__331;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__332);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds %%struct.paramset_t* %%params, i64 0, i32 3, !dbg !33 for 0x%I64xth hint within @allocateMsgs  --> \n", ++aesl_llvm_cbe_775_count);
  llvm_cbe_tmp__333 = (signed int *)(&llvm_cbe_params->field3);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = load i32* %%11, align 4, !dbg !33 for 0x%I64xth hint within @allocateMsgs  --> \n", ++aesl_llvm_cbe_776_count);
  llvm_cbe_tmp__334 = (unsigned int )*llvm_cbe_tmp__333;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__334);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = add i32 %%12, %%10, !dbg !33 for 0x%I64xth hint within @allocateMsgs  --> \n", ++aesl_llvm_cbe_777_count);
  llvm_cbe_tmp__335 = (unsigned int )((unsigned int )(llvm_cbe_tmp__334&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__332&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__335&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = mul i32 %%13, %%8, !dbg !33 for 0x%I64xth hint within @allocateMsgs  --> \n", ++aesl_llvm_cbe_778_count);
  llvm_cbe_tmp__336 = (unsigned int )((unsigned int )(llvm_cbe_tmp__335&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__330&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__336&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = zext i32 %%14 to i64, !dbg !33 for 0x%I64xth hint within @allocateMsgs  --> \n", ++aesl_llvm_cbe_779_count);
  llvm_cbe_tmp__337 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__336&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__337);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = zext i32 %%8 to i64, !dbg !33 for 0x%I64xth hint within @allocateMsgs  --> \n", ++aesl_llvm_cbe_780_count);
  llvm_cbe_tmp__338 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__330&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__338);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = shl nuw nsw i64 %%16, 3, !dbg !33 for 0x%I64xth hint within @allocateMsgs  --> \n", ++aesl_llvm_cbe_781_count);
  llvm_cbe_tmp__339 = (unsigned long long )llvm_cbe_tmp__338 << 3ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__339);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = add i64 %%15, %%17, !dbg !33 for 0x%I64xth hint within @allocateMsgs  --> \n", ++aesl_llvm_cbe_782_count);
  llvm_cbe_tmp__340 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__337&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__339&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__340&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = mul i64 %%18, %%3, !dbg !33 for 0x%I64xth hint within @allocateMsgs  --> \n", ++aesl_llvm_cbe_783_count);
  llvm_cbe_tmp__341 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__340&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__325&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__341&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = tail call i8* @calloc(i64 1, i64 %%19) nounwind, !dbg !33 for 0x%I64xth hint within @allocateMsgs  --> \n", ++aesl_llvm_cbe_784_count);
  llvm_cbe_tmp__342 = ( char *) /*tail*/ ( char *)calloc(1ull, llvm_cbe_tmp__341);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",1ull);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__341);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__342);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = load i32* %%1, align 4, !dbg !33 for 0x%I64xth hint within @allocateMsgs  --> \n", ++aesl_llvm_cbe_797_count);
  llvm_cbe_tmp__343 = (unsigned int )*llvm_cbe_tmp__323;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__343);
  if (((llvm_cbe_tmp__343&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe__2e__crit_edge6;
  } else {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    llvm_cbe_tmp__344__PHI_TEMPORARY = ( char *)llvm_cbe_tmp__342;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph5;
  }

  do {     /* Syntactic loop '.lr.ph5' to make GCC happy */
llvm_cbe__2e_lr_2e_ph5:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = phi i32 [ %%43, %%._crit_edge ], [ 0, %%0  for 0x%I64xth hint within @allocateMsgs  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned int )llvm_cbe_storemerge3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%X",llvm_cbe_storemerge3);
printf("\n = 0x%X",llvm_cbe_tmp__362);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = phi i8* [ %%.lcssa, %%._crit_edge ], [ %%20, %%0  for 0x%I64xth hint within @allocateMsgs  --> \n", ++aesl_llvm_cbe_800_count);
  llvm_cbe_tmp__344 = ( char *)llvm_cbe_tmp__344__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = zext i32 %%storemerge3 to i64, !dbg !34 for 0x%I64xth hint within @allocateMsgs  --> \n", ++aesl_llvm_cbe_801_count);
  llvm_cbe_tmp__345 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge3&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__345);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = getelementptr inbounds %%struct.msgs_t* %%6, i64 %%24, i32 1, !dbg !34 for 0x%I64xth hint within @allocateMsgs  --> \n", ++aesl_llvm_cbe_802_count);
  llvm_cbe_tmp__346 = (signed long long *)(&llvm_cbe_tmp__328[(((signed long long )llvm_cbe_tmp__345))].field1);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__345));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 0, i64* %%25, align 8, !dbg !34 for 0x%I64xth hint within @allocateMsgs  --> \n", ++aesl_llvm_cbe_803_count);
  *llvm_cbe_tmp__346 = 0ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 0ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = getelementptr inbounds %%struct.msgs_t* %%6, i64 %%24, i32 2, !dbg !34 for 0x%I64xth hint within @allocateMsgs  --> \n", ++aesl_llvm_cbe_804_count);
  llvm_cbe_tmp__347 = (signed int *)(&llvm_cbe_tmp__328[(((signed long long )llvm_cbe_tmp__345))].field2);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__345));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 -1, i32* %%26, align 4, !dbg !34 for 0x%I64xth hint within @allocateMsgs  --> \n", ++aesl_llvm_cbe_805_count);
  *llvm_cbe_tmp__347 = 4294967295u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 4294967295u);
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = bitcast i8* %%23 to i8**, !dbg !34 for 0x%I64xth hint within @allocateMsgs  --> \n", ++aesl_llvm_cbe_806_count);
  llvm_cbe_tmp__348 = ( char **)(( char **)llvm_cbe_tmp__344);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = getelementptr inbounds %%struct.msgs_t* %%6, i64 %%24, i32 0, !dbg !34 for 0x%I64xth hint within @allocateMsgs  --> \n", ++aesl_llvm_cbe_807_count);
  llvm_cbe_tmp__349 = ( char ***)(&llvm_cbe_tmp__328[(((signed long long )llvm_cbe_tmp__345))].field0);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__345));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8** %%27, i8*** %%28, align 8, !dbg !34 for 0x%I64xth hint within @allocateMsgs  --> \n", ++aesl_llvm_cbe_808_count);
  *llvm_cbe_tmp__349 = ( char **)llvm_cbe_tmp__348;
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = load i32* %%7, align 4, !dbg !33 for 0x%I64xth hint within @allocateMsgs  --> \n", ++aesl_llvm_cbe_809_count);
  llvm_cbe_tmp__350 = (unsigned int )*llvm_cbe_tmp__329;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__350);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = zext i32 %%29 to i64, !dbg !33 for 0x%I64xth hint within @allocateMsgs  --> \n", ++aesl_llvm_cbe_810_count);
  llvm_cbe_tmp__351 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__350&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__351);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = shl nuw nsw i64 %%30, 3, !dbg !33 for 0x%I64xth hint within @allocateMsgs  --> \n", ++aesl_llvm_cbe_811_count);
  llvm_cbe_tmp__352 = (unsigned long long )llvm_cbe_tmp__351 << 3ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__352);
  if (((llvm_cbe_tmp__350&4294967295U) == (0u&4294967295U))) {
    llvm_cbe__2e_sum9_2e_pn__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__352;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    llvm_cbe__2e_rec__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum9.pn = phi i64 [ %%31, %%.lr.ph5 ], [ %%.sum9, %%.lr.ph  for 0x%I64xth hint within @allocateMsgs  --> \n", ++aesl_llvm_cbe__2e_sum9_2e_pn_count);
  llvm_cbe__2e_sum9_2e_pn = (unsigned long long )llvm_cbe__2e_sum9_2e_pn__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.sum9.pn = 0x%I64X",llvm_cbe__2e_sum9_2e_pn);
printf("\n = 0x%I64X",llvm_cbe_tmp__352);
printf("\n.sum9 = 0x%I64X",llvm_cbe__2e_sum9);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.lcssa = getelementptr inbounds i8* %%23, i64 %%.sum9.pn, !dbg !34 for 0x%I64xth hint within @allocateMsgs  --> \n", ++aesl_llvm_cbe__2e_lcssa_count);
  llvm_cbe__2e_lcssa = ( char *)(&llvm_cbe_tmp__344[(((signed long long )llvm_cbe__2e_sum9_2e_pn))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum9.pn = 0x%I64X",((signed long long )llvm_cbe__2e_sum9_2e_pn));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = add i32 %%storemerge3, 1, !dbg !35 for 0x%I64xth hint within @allocateMsgs  --> \n", ++aesl_llvm_cbe_835_count);
  llvm_cbe_tmp__362 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__362&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = load i32* %%1, align 4, !dbg !33 for 0x%I64xth hint within @allocateMsgs  --> \n", ++aesl_llvm_cbe_843_count);
  llvm_cbe_tmp__363 = (unsigned int )*llvm_cbe_tmp__323;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__363);
  if ((((unsigned int )llvm_cbe_tmp__362&4294967295U) < ((unsigned int )llvm_cbe_tmp__363&4294967295U))) {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__362;   /* for PHI node */
    llvm_cbe_tmp__344__PHI_TEMPORARY = ( char *)llvm_cbe__2e_lcssa;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph5;
  } else {
    goto llvm_cbe__2e__crit_edge6;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12 = phi i32 [ %%40, %%.lr.ph ], [ 0, %%.lr.ph5  for 0x%I64xth hint within @allocateMsgs  --> \n", ++aesl_llvm_cbe_storemerge12_count);
  llvm_cbe_storemerge12 = (unsigned int )llvm_cbe_storemerge12__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%X",llvm_cbe_storemerge12);
printf("\n = 0x%X",llvm_cbe_tmp__360);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec = phi i64 [ %%.rec8, %%.lr.ph ], [ 0, %%.lr.ph5  for 0x%I64xth hint within @allocateMsgs  --> \n", ++aesl_llvm_cbe__2e_rec_count);
  llvm_cbe__2e_rec = (unsigned long long )llvm_cbe__2e_rec__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.rec = 0x%I64X",llvm_cbe__2e_rec);
printf("\n.rec8 = 0x%I64X",llvm_cbe__2e_rec8);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum = add i64 %%31, %%.re for 0x%I64xth hint within @allocateMsgs  --> \n", ++aesl_llvm_cbe__2e_sum_count);
  llvm_cbe__2e_sum = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__352&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe__2e_rec&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = getelementptr i8* %%23, i64 %%.su for 0x%I64xth hint within @allocateMsgs  --> \n", ++aesl_llvm_cbe_818_count);
  llvm_cbe_tmp__353 = ( char *)(&llvm_cbe_tmp__344[(((signed long long )llvm_cbe__2e_sum))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum = 0x%I64X",((signed long long )llvm_cbe__2e_sum));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = zext i32 %%storemerge12 to i64, !dbg !34 for 0x%I64xth hint within @allocateMsgs  --> \n", ++aesl_llvm_cbe_819_count);
  llvm_cbe_tmp__354 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge12&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__354);
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = getelementptr inbounds i8** %%27, i64 %%34, !dbg !34 for 0x%I64xth hint within @allocateMsgs  --> \n", ++aesl_llvm_cbe_820_count);
  llvm_cbe_tmp__355 = ( char **)(&llvm_cbe_tmp__348[(((signed long long )llvm_cbe_tmp__354))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__354));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8* %%33, i8** %%35, align 8, !dbg !34 for 0x%I64xth hint within @allocateMsgs  --> \n", ++aesl_llvm_cbe_821_count);
  *llvm_cbe_tmp__355 = ( char *)llvm_cbe_tmp__353;
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = load i32* %%9, align 4, !dbg !34 for 0x%I64xth hint within @allocateMsgs  --> \n", ++aesl_llvm_cbe_822_count);
  llvm_cbe_tmp__356 = (unsigned int )*llvm_cbe_tmp__331;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__356);
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = load i32* %%11, align 4, !dbg !34 for 0x%I64xth hint within @allocateMsgs  --> \n", ++aesl_llvm_cbe_823_count);
  llvm_cbe_tmp__357 = (unsigned int )*llvm_cbe_tmp__333;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__357);
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = add i32 %%37, %%36, !dbg !34 for 0x%I64xth hint within @allocateMsgs  --> \n", ++aesl_llvm_cbe_824_count);
  llvm_cbe_tmp__358 = (unsigned int )((unsigned int )(llvm_cbe_tmp__357&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__356&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__358&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = zext i32 %%38 to i64, !dbg !34 for 0x%I64xth hint within @allocateMsgs  --> \n", ++aesl_llvm_cbe_825_count);
  llvm_cbe_tmp__359 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__358&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__359);
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec8 = add i64 %%.rec, %%39, !dbg !34 for 0x%I64xth hint within @allocateMsgs  --> \n", ++aesl_llvm_cbe__2e_rec8_count);
  llvm_cbe__2e_rec8 = (unsigned long long )((unsigned long long )(llvm_cbe__2e_rec&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__359&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.rec8 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_rec8&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum9 = add i64 %%31, %%.rec8, !dbg !34 for 0x%I64xth hint within @allocateMsgs  --> \n", ++aesl_llvm_cbe__2e_sum9_count);
  llvm_cbe__2e_sum9 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__352&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe__2e_rec8&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum9 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum9&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = add i32 %%storemerge12, 1, !dbg !35 for 0x%I64xth hint within @allocateMsgs  --> \n", ++aesl_llvm_cbe_826_count);
  llvm_cbe_tmp__360 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__360&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = load i32* %%7, align 4, !dbg !33 for 0x%I64xth hint within @allocateMsgs  --> \n", ++aesl_llvm_cbe_831_count);
  llvm_cbe_tmp__361 = (unsigned int )*llvm_cbe_tmp__329;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__361);
  if ((((unsigned int )llvm_cbe_tmp__360&4294967295U) < ((unsigned int )llvm_cbe_tmp__361&4294967295U))) {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__360;   /* for PHI node */
    llvm_cbe__2e_rec__PHI_TEMPORARY = (unsigned long long )llvm_cbe__2e_rec8;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    llvm_cbe__2e_sum9_2e_pn__PHI_TEMPORARY = (unsigned long long )llvm_cbe__2e_sum9;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
  } while (1); /* end of syntactic loop '.lr.ph5' */
llvm_cbe__2e__crit_edge6:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @allocateMsgs}\n");
  return llvm_cbe_tmp__328;
}


void freeMsgs(l_struct_OC_msgs_t *llvm_cbe_msgs) {
  static  unsigned long long aesl_llvm_cbe_847_count = 0;
  static  unsigned long long aesl_llvm_cbe_848_count = 0;
  static  unsigned long long aesl_llvm_cbe_849_count = 0;
  static  unsigned long long aesl_llvm_cbe_850_count = 0;
   char ***llvm_cbe_tmp__364;
  static  unsigned long long aesl_llvm_cbe_851_count = 0;
   char **llvm_cbe_tmp__365;
  static  unsigned long long aesl_llvm_cbe_852_count = 0;
   char *llvm_cbe_tmp__366;
  static  unsigned long long aesl_llvm_cbe_853_count = 0;
  static  unsigned long long aesl_llvm_cbe_854_count = 0;
   char *llvm_cbe_tmp__367;
  static  unsigned long long aesl_llvm_cbe_855_count = 0;
  static  unsigned long long aesl_llvm_cbe_856_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @freeMsgs\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.msgs_t* %%msgs, i64 0, i32 0, !dbg !33 for 0x%I64xth hint within @freeMsgs  --> \n", ++aesl_llvm_cbe_850_count);
  llvm_cbe_tmp__364 = ( char ***)(&llvm_cbe_msgs->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i8*** %%1, align 8, !dbg !33 for 0x%I64xth hint within @freeMsgs  --> \n", ++aesl_llvm_cbe_851_count);
  llvm_cbe_tmp__365 = ( char **)*llvm_cbe_tmp__364;
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = bitcast i8** %%2 to i8*, !dbg !33 for 0x%I64xth hint within @freeMsgs  --> \n", ++aesl_llvm_cbe_852_count);
  llvm_cbe_tmp__366 = ( char *)(( char *)llvm_cbe_tmp__365);
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @free(i8* %%3), !dbg !33 for 0x%I64xth hint within @freeMsgs  --> \n", ++aesl_llvm_cbe_853_count);
   /*tail*/ free(( char *)llvm_cbe_tmp__366);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = bitcast %%struct.msgs_t* %%msgs to i8*, !dbg !33 for 0x%I64xth hint within @freeMsgs  --> \n", ++aesl_llvm_cbe_854_count);
  llvm_cbe_tmp__367 = ( char *)(( char *)llvm_cbe_msgs);
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @free(i8* %%4), !dbg !33 for 0x%I64xth hint within @freeMsgs  --> \n", ++aesl_llvm_cbe_855_count);
   /*tail*/ free(( char *)llvm_cbe_tmp__367);
if (AESL_DEBUG_TRACE) {
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @freeMsgs}\n");
  return;
}


l_struct_OC_view_t **allocateViews(l_struct_OC_paramset_t *llvm_cbe_params) {
  static  unsigned long long aesl_llvm_cbe_857_count = 0;
  static  unsigned long long aesl_llvm_cbe_858_count = 0;
  static  unsigned long long aesl_llvm_cbe_859_count = 0;
  static  unsigned long long aesl_llvm_cbe_860_count = 0;
  static  unsigned long long aesl_llvm_cbe_861_count = 0;
  static  unsigned long long aesl_llvm_cbe_862_count = 0;
  signed int *llvm_cbe_tmp__368;
  static  unsigned long long aesl_llvm_cbe_863_count = 0;
  unsigned int llvm_cbe_tmp__369;
  static  unsigned long long aesl_llvm_cbe_864_count = 0;
  unsigned long long llvm_cbe_tmp__370;
  static  unsigned long long aesl_llvm_cbe_865_count = 0;
  unsigned long long llvm_cbe_tmp__371;
  static  unsigned long long aesl_llvm_cbe_866_count = 0;
   char *llvm_cbe_tmp__372;
  static  unsigned long long aesl_llvm_cbe_867_count = 0;
  l_struct_OC_view_t **llvm_cbe_tmp__373;
  static  unsigned long long aesl_llvm_cbe_868_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_881_count = 0;
  signed int *llvm_cbe_tmp__374;
  static  unsigned long long aesl_llvm_cbe_882_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned long long llvm_cbe_storemerge3;
  unsigned long long llvm_cbe_storemerge3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_883_count = 0;
   char *llvm_cbe_tmp__375;
  static  unsigned long long aesl_llvm_cbe_884_count = 0;
  l_struct_OC_view_t *llvm_cbe_tmp__376;
  static  unsigned long long aesl_llvm_cbe_885_count = 0;
  l_struct_OC_view_t **llvm_cbe_tmp__377;
  static  unsigned long long aesl_llvm_cbe_886_count = 0;
  static  unsigned long long aesl_llvm_cbe_887_count = 0;
  static  unsigned long long aesl_llvm_cbe_888_count = 0;
  static  unsigned long long aesl_llvm_cbe_889_count = 0;
  static  unsigned long long aesl_llvm_cbe_890_count = 0;
  static  unsigned long long aesl_llvm_cbe_891_count = 0;
  static  unsigned long long aesl_llvm_cbe_892_count = 0;
  static  unsigned long long aesl_llvm_cbe_893_count = 0;
  unsigned int llvm_cbe_tmp__378;
  static  unsigned long long aesl_llvm_cbe_894_count = 0;
  unsigned int llvm_cbe_tmp__379;
  static  unsigned long long aesl_llvm_cbe_895_count = 0;
  unsigned long long llvm_cbe_tmp__380;
  static  unsigned long long aesl_llvm_cbe_896_count = 0;
   char **llvm_cbe_tmp__381;
  static  unsigned long long aesl_llvm_cbe_897_count = 0;
   char *llvm_cbe_tmp__382;
  static  unsigned long long aesl_llvm_cbe_898_count = 0;
   char *llvm_cbe_tmp__383;
  static  unsigned long long aesl_llvm_cbe_899_count = 0;
  static  unsigned long long aesl_llvm_cbe_900_count = 0;
  static  unsigned long long aesl_llvm_cbe_901_count = 0;
  static  unsigned long long aesl_llvm_cbe_902_count = 0;
  static  unsigned long long aesl_llvm_cbe_903_count = 0;
  static  unsigned long long aesl_llvm_cbe_904_count = 0;
  static  unsigned long long aesl_llvm_cbe_905_count = 0;
  l_struct_OC_view_t *llvm_cbe_tmp__384;
  static  unsigned long long aesl_llvm_cbe_906_count = 0;
  static  unsigned long long aesl_llvm_cbe_907_count = 0;
  unsigned int llvm_cbe_tmp__385;
  static  unsigned long long aesl_llvm_cbe_908_count = 0;
  unsigned int llvm_cbe_tmp__386;
  static  unsigned long long aesl_llvm_cbe_909_count = 0;
  unsigned long long llvm_cbe_tmp__387;
  static  unsigned long long aesl_llvm_cbe_910_count = 0;
   char **llvm_cbe_tmp__388;
  static  unsigned long long aesl_llvm_cbe_911_count = 0;
   char *llvm_cbe_tmp__389;
  static  unsigned long long aesl_llvm_cbe_912_count = 0;
   char *llvm_cbe_tmp__390;
  static  unsigned long long aesl_llvm_cbe_913_count = 0;
  static  unsigned long long aesl_llvm_cbe_914_count = 0;
  static  unsigned long long aesl_llvm_cbe_915_count = 0;
  static  unsigned long long aesl_llvm_cbe_916_count = 0;
  static  unsigned long long aesl_llvm_cbe_917_count = 0;
  static  unsigned long long aesl_llvm_cbe_918_count = 0;
  static  unsigned long long aesl_llvm_cbe_919_count = 0;
  l_struct_OC_view_t *llvm_cbe_tmp__391;
  static  unsigned long long aesl_llvm_cbe_920_count = 0;
  static  unsigned long long aesl_llvm_cbe_921_count = 0;
  unsigned int llvm_cbe_tmp__392;
  static  unsigned long long aesl_llvm_cbe_922_count = 0;
  unsigned int llvm_cbe_tmp__393;
  static  unsigned long long aesl_llvm_cbe_923_count = 0;
  unsigned long long llvm_cbe_tmp__394;
  static  unsigned long long aesl_llvm_cbe_924_count = 0;
   char **llvm_cbe_tmp__395;
  static  unsigned long long aesl_llvm_cbe_925_count = 0;
   char *llvm_cbe_tmp__396;
  static  unsigned long long aesl_llvm_cbe_926_count = 0;
   char *llvm_cbe_tmp__397;
  static  unsigned long long aesl_llvm_cbe_927_count = 0;
  static  unsigned long long aesl_llvm_cbe_928_count = 0;
  static  unsigned long long aesl_llvm_cbe_929_count = 0;
  static  unsigned long long aesl_llvm_cbe_930_count = 0;
  static  unsigned long long aesl_llvm_cbe_931_count = 0;
  static  unsigned long long aesl_llvm_cbe_932_count = 0;
  static  unsigned long long aesl_llvm_cbe_933_count = 0;
  unsigned long long llvm_cbe_tmp__398;
  static  unsigned long long aesl_llvm_cbe_934_count = 0;
  static  unsigned long long aesl_llvm_cbe_935_count = 0;
  static  unsigned long long aesl_llvm_cbe_936_count = 0;
  static  unsigned long long aesl_llvm_cbe_937_count = 0;
  static  unsigned long long aesl_llvm_cbe_938_count = 0;
  static  unsigned long long aesl_llvm_cbe_939_count = 0;
  static  unsigned long long aesl_llvm_cbe_940_count = 0;
  unsigned int llvm_cbe_tmp__399;
  static  unsigned long long aesl_llvm_cbe_941_count = 0;
  unsigned long long llvm_cbe_tmp__400;
  static  unsigned long long aesl_llvm_cbe_942_count = 0;
  static  unsigned long long aesl_llvm_cbe_943_count = 0;
  static  unsigned long long aesl_llvm_cbe_944_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @allocateViews\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.paramset_t* %%params, i64 0, i32 8, !dbg !33 for 0x%I64xth hint within @allocateViews  --> \n", ++aesl_llvm_cbe_862_count);
  llvm_cbe_tmp__368 = (signed int *)(&llvm_cbe_params->field8);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i32* %%1, align 4, !dbg !33 for 0x%I64xth hint within @allocateViews  --> \n", ++aesl_llvm_cbe_863_count);
  llvm_cbe_tmp__369 = (unsigned int )*llvm_cbe_tmp__368;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__369);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = zext i32 %%2 to i64, !dbg !33 for 0x%I64xth hint within @allocateViews  --> \n", ++aesl_llvm_cbe_864_count);
  llvm_cbe_tmp__370 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__369&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__370);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = shl nuw nsw i64 %%3, 3, !dbg !33 for 0x%I64xth hint within @allocateViews  --> \n", ++aesl_llvm_cbe_865_count);
  llvm_cbe_tmp__371 = (unsigned long long )llvm_cbe_tmp__370 << 3ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__371);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = tail call i8* @malloc(i64 %%4), !dbg !33 for 0x%I64xth hint within @allocateViews  --> \n", ++aesl_llvm_cbe_866_count);
  llvm_cbe_tmp__372 = ( char *) /*tail*/ ( char *)malloc(llvm_cbe_tmp__371);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__371);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__372);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = bitcast i8* %%5 to %%struct.view_t**, !dbg !33 for 0x%I64xth hint within @allocateViews  --> \n", ++aesl_llvm_cbe_867_count);
  llvm_cbe_tmp__373 = (l_struct_OC_view_t **)((l_struct_OC_view_t **)llvm_cbe_tmp__372);
  if (((llvm_cbe_tmp__369&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    goto llvm_cbe__2e_lr_2e_ph;
  }

llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds %%struct.paramset_t* %%params, i64 0, i32 5, !dbg !33 for 0x%I64xth hint within @allocateViews  --> \n", ++aesl_llvm_cbe_881_count);
  llvm_cbe_tmp__374 = (signed int *)(&llvm_cbe_params->field5);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__401;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__401:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = phi i64 [ 0, %%.lr.ph ], [ %%33, %%9  for 0x%I64xth hint within @allocateViews  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned long long )llvm_cbe_storemerge3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%I64X",llvm_cbe_storemerge3);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__398);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = tail call i8* @malloc(i64 72), !dbg !34 for 0x%I64xth hint within @allocateViews  --> \n", ++aesl_llvm_cbe_883_count);
  llvm_cbe_tmp__375 = ( char *) /*tail*/ ( char *)malloc(72ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",72ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__375);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = bitcast i8* %%10 to %%struct.view_t*, !dbg !34 for 0x%I64xth hint within @allocateViews  --> \n", ++aesl_llvm_cbe_884_count);
  llvm_cbe_tmp__376 = (l_struct_OC_view_t *)((l_struct_OC_view_t *)llvm_cbe_tmp__375);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds %%struct.view_t** %%6, i64 %%storemerge3, !dbg !34 for 0x%I64xth hint within @allocateViews  --> \n", ++aesl_llvm_cbe_885_count);
  llvm_cbe_tmp__377 = (l_struct_OC_view_t **)(&llvm_cbe_tmp__373[(((signed long long )llvm_cbe_storemerge3))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%I64X",((signed long long )llvm_cbe_storemerge3));
}
if (AESL_DEBUG_TRACE)
printf("\n  store %%struct.view_t* %%11, %%struct.view_t** %%12, align 8, !dbg !34 for 0x%I64xth hint within @allocateViews  --> \n", ++aesl_llvm_cbe_886_count);
  *llvm_cbe_tmp__377 = (l_struct_OC_view_t *)llvm_cbe_tmp__376;
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @allocateView(%%struct.view_t* %%11, %%struct.paramset_t* %%params), !dbg !33 for 0x%I64xth hint within @allocateViews  --> \n", ++aesl_llvm_cbe_892_count);
   /*tail*/ allocateView((l_struct_OC_view_t *)llvm_cbe_tmp__376, (l_struct_OC_paramset_t *)llvm_cbe_params);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = load i32* %%8, align 4, !dbg !33 for 0x%I64xth hint within @allocateViews  --> \n", ++aesl_llvm_cbe_893_count);
  llvm_cbe_tmp__378 = (unsigned int )*llvm_cbe_tmp__374;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__378);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = add i32 %%13, -1, !dbg !33 for 0x%I64xth hint within @allocateViews  --> \n", ++aesl_llvm_cbe_894_count);
  llvm_cbe_tmp__379 = (unsigned int )((unsigned int )(llvm_cbe_tmp__378&4294967295ull)) + ((unsigned int )(4294967295u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__379&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = zext i32 %%14 to i64, !dbg !33 for 0x%I64xth hint within @allocateViews  --> \n", ++aesl_llvm_cbe_895_count);
  llvm_cbe_tmp__380 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__379&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__380);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds %%struct.view_t* %%11, i64 0, i32 1, !dbg !33 for 0x%I64xth hint within @allocateViews  --> \n", ++aesl_llvm_cbe_896_count);
  llvm_cbe_tmp__381 = ( char **)(&llvm_cbe_tmp__376->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = load i8** %%16, align 8, !dbg !33 for 0x%I64xth hint within @allocateViews  --> \n", ++aesl_llvm_cbe_897_count);
  llvm_cbe_tmp__382 = ( char *)*llvm_cbe_tmp__381;
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = getelementptr inbounds i8* %%17, i64 %%15, !dbg !33 for 0x%I64xth hint within @allocateViews  --> \n", ++aesl_llvm_cbe_898_count);
  llvm_cbe_tmp__383 = ( char *)(&llvm_cbe_tmp__382[(((signed long long )llvm_cbe_tmp__380))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__380));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 0, i8* %%18, align 1, !dbg !33 for 0x%I64xth hint within @allocateViews  --> \n", ++aesl_llvm_cbe_899_count);
  *llvm_cbe_tmp__383 = ((unsigned char )0);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )0));
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = getelementptr inbounds %%struct.view_t* %%11, i64 1, !dbg !33 for 0x%I64xth hint within @allocateViews  --> \n", ++aesl_llvm_cbe_905_count);
  llvm_cbe_tmp__384 = (l_struct_OC_view_t *)(&llvm_cbe_tmp__376[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @allocateView(%%struct.view_t* %%19, %%struct.paramset_t* %%params), !dbg !33 for 0x%I64xth hint within @allocateViews  --> \n", ++aesl_llvm_cbe_906_count);
   /*tail*/ allocateView((l_struct_OC_view_t *)llvm_cbe_tmp__384, (l_struct_OC_paramset_t *)llvm_cbe_params);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = load i32* %%8, align 4, !dbg !33 for 0x%I64xth hint within @allocateViews  --> \n", ++aesl_llvm_cbe_907_count);
  llvm_cbe_tmp__385 = (unsigned int )*llvm_cbe_tmp__374;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__385);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = add i32 %%20, -1, !dbg !33 for 0x%I64xth hint within @allocateViews  --> \n", ++aesl_llvm_cbe_908_count);
  llvm_cbe_tmp__386 = (unsigned int )((unsigned int )(llvm_cbe_tmp__385&4294967295ull)) + ((unsigned int )(4294967295u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__386&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = zext i32 %%21 to i64, !dbg !33 for 0x%I64xth hint within @allocateViews  --> \n", ++aesl_llvm_cbe_909_count);
  llvm_cbe_tmp__387 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__386&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__387);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = getelementptr inbounds %%struct.view_t* %%11, i64 1, i32 1, !dbg !33 for 0x%I64xth hint within @allocateViews  --> \n", ++aesl_llvm_cbe_910_count);
  llvm_cbe_tmp__388 = ( char **)(&llvm_cbe_tmp__376[(((signed long long )1ull))].field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = load i8** %%23, align 8, !dbg !33 for 0x%I64xth hint within @allocateViews  --> \n", ++aesl_llvm_cbe_911_count);
  llvm_cbe_tmp__389 = ( char *)*llvm_cbe_tmp__388;
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = getelementptr inbounds i8* %%24, i64 %%22, !dbg !33 for 0x%I64xth hint within @allocateViews  --> \n", ++aesl_llvm_cbe_912_count);
  llvm_cbe_tmp__390 = ( char *)(&llvm_cbe_tmp__389[(((signed long long )llvm_cbe_tmp__387))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__387));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 0, i8* %%25, align 1, !dbg !33 for 0x%I64xth hint within @allocateViews  --> \n", ++aesl_llvm_cbe_913_count);
  *llvm_cbe_tmp__390 = ((unsigned char )0);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )0));
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = getelementptr inbounds %%struct.view_t* %%11, i64 2, !dbg !33 for 0x%I64xth hint within @allocateViews  --> \n", ++aesl_llvm_cbe_919_count);
  llvm_cbe_tmp__391 = (l_struct_OC_view_t *)(&llvm_cbe_tmp__376[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @allocateView(%%struct.view_t* %%26, %%struct.paramset_t* %%params), !dbg !33 for 0x%I64xth hint within @allocateViews  --> \n", ++aesl_llvm_cbe_920_count);
   /*tail*/ allocateView((l_struct_OC_view_t *)llvm_cbe_tmp__391, (l_struct_OC_paramset_t *)llvm_cbe_params);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = load i32* %%8, align 4, !dbg !33 for 0x%I64xth hint within @allocateViews  --> \n", ++aesl_llvm_cbe_921_count);
  llvm_cbe_tmp__392 = (unsigned int )*llvm_cbe_tmp__374;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__392);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = add i32 %%27, -1, !dbg !33 for 0x%I64xth hint within @allocateViews  --> \n", ++aesl_llvm_cbe_922_count);
  llvm_cbe_tmp__393 = (unsigned int )((unsigned int )(llvm_cbe_tmp__392&4294967295ull)) + ((unsigned int )(4294967295u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__393&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = zext i32 %%28 to i64, !dbg !33 for 0x%I64xth hint within @allocateViews  --> \n", ++aesl_llvm_cbe_923_count);
  llvm_cbe_tmp__394 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__393&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__394);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = getelementptr inbounds %%struct.view_t* %%11, i64 2, i32 1, !dbg !33 for 0x%I64xth hint within @allocateViews  --> \n", ++aesl_llvm_cbe_924_count);
  llvm_cbe_tmp__395 = ( char **)(&llvm_cbe_tmp__376[(((signed long long )2ull))].field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = load i8** %%30, align 8, !dbg !33 for 0x%I64xth hint within @allocateViews  --> \n", ++aesl_llvm_cbe_925_count);
  llvm_cbe_tmp__396 = ( char *)*llvm_cbe_tmp__395;
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = getelementptr inbounds i8* %%31, i64 %%29, !dbg !33 for 0x%I64xth hint within @allocateViews  --> \n", ++aesl_llvm_cbe_926_count);
  llvm_cbe_tmp__397 = ( char *)(&llvm_cbe_tmp__396[(((signed long long )llvm_cbe_tmp__394))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__394));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 0, i8* %%32, align 1, !dbg !33 for 0x%I64xth hint within @allocateViews  --> \n", ++aesl_llvm_cbe_927_count);
  *llvm_cbe_tmp__397 = ((unsigned char )0);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )0));
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = add i64 %%storemerge3, 1, !dbg !34 for 0x%I64xth hint within @allocateViews  --> \n", ++aesl_llvm_cbe_933_count);
  llvm_cbe_tmp__398 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge3&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__398&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = load i32* %%1, align 4, !dbg !33 for 0x%I64xth hint within @allocateViews  --> \n", ++aesl_llvm_cbe_940_count);
  llvm_cbe_tmp__399 = (unsigned int )*llvm_cbe_tmp__368;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__399);
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = zext i32 %%34 to i64, !dbg !33 for 0x%I64xth hint within @allocateViews  --> \n", ++aesl_llvm_cbe_941_count);
  llvm_cbe_tmp__400 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__399&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__400);
  if ((((unsigned long long )llvm_cbe_tmp__398&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__400&18446744073709551615ULL))) {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__398;   /* for PHI node */
    goto llvm_cbe_tmp__401;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e__crit_edge:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @allocateViews}\n");
  return llvm_cbe_tmp__373;
}


void freeViews(l_struct_OC_view_t **llvm_cbe_views, l_struct_OC_paramset_t *llvm_cbe_params) {
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
  signed int *llvm_cbe_tmp__402;
  static  unsigned long long aesl_llvm_cbe_957_count = 0;
  unsigned int llvm_cbe_tmp__403;
  static  unsigned long long aesl_llvm_cbe_958_count = 0;
  static  unsigned long long aesl_llvm_cbe_959_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned long long llvm_cbe_storemerge3;
  unsigned long long llvm_cbe_storemerge3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_960_count = 0;
  static  unsigned long long aesl_llvm_cbe_961_count = 0;
  static  unsigned long long aesl_llvm_cbe_962_count = 0;
  static  unsigned long long aesl_llvm_cbe_963_count = 0;
  l_struct_OC_view_t **llvm_cbe_tmp__404;
  static  unsigned long long aesl_llvm_cbe_964_count = 0;
  l_struct_OC_view_t *llvm_cbe_tmp__405;
  static  unsigned long long aesl_llvm_cbe_965_count = 0;
  static  unsigned long long aesl_llvm_cbe_966_count = 0;
  static  unsigned long long aesl_llvm_cbe_967_count = 0;
  static  unsigned long long aesl_llvm_cbe_968_count = 0;
  static  unsigned long long aesl_llvm_cbe_969_count = 0;
  static  unsigned long long aesl_llvm_cbe_970_count = 0;
  l_struct_OC_view_t *llvm_cbe_tmp__406;
  static  unsigned long long aesl_llvm_cbe_971_count = 0;
  l_struct_OC_view_t *llvm_cbe_tmp__407;
  static  unsigned long long aesl_llvm_cbe_972_count = 0;
  static  unsigned long long aesl_llvm_cbe_973_count = 0;
  static  unsigned long long aesl_llvm_cbe_974_count = 0;
  static  unsigned long long aesl_llvm_cbe_975_count = 0;
  static  unsigned long long aesl_llvm_cbe_976_count = 0;
  static  unsigned long long aesl_llvm_cbe_977_count = 0;
  l_struct_OC_view_t *llvm_cbe_tmp__408;
  static  unsigned long long aesl_llvm_cbe_978_count = 0;
  l_struct_OC_view_t *llvm_cbe_tmp__409;
  static  unsigned long long aesl_llvm_cbe_979_count = 0;
  static  unsigned long long aesl_llvm_cbe_980_count = 0;
  static  unsigned long long aesl_llvm_cbe_981_count = 0;
  static  unsigned long long aesl_llvm_cbe_982_count = 0;
  static  unsigned long long aesl_llvm_cbe_983_count = 0;
  static  unsigned long long aesl_llvm_cbe_984_count = 0;
  l_struct_OC_view_t *llvm_cbe_tmp__410;
  static  unsigned long long aesl_llvm_cbe_985_count = 0;
   char *llvm_cbe_tmp__411;
  static  unsigned long long aesl_llvm_cbe_986_count = 0;
  static  unsigned long long aesl_llvm_cbe_987_count = 0;
  unsigned long long llvm_cbe_tmp__412;
  static  unsigned long long aesl_llvm_cbe_988_count = 0;
  static  unsigned long long aesl_llvm_cbe_989_count = 0;
  static  unsigned long long aesl_llvm_cbe_990_count = 0;
  static  unsigned long long aesl_llvm_cbe_991_count = 0;
  static  unsigned long long aesl_llvm_cbe_992_count = 0;
  static  unsigned long long aesl_llvm_cbe_993_count = 0;
  unsigned int llvm_cbe_tmp__413;
  static  unsigned long long aesl_llvm_cbe_994_count = 0;
  unsigned long long llvm_cbe_tmp__414;
  static  unsigned long long aesl_llvm_cbe_995_count = 0;
  static  unsigned long long aesl_llvm_cbe_996_count = 0;
  static  unsigned long long aesl_llvm_cbe_997_count = 0;
   char *llvm_cbe_tmp__415;
  static  unsigned long long aesl_llvm_cbe_998_count = 0;
  static  unsigned long long aesl_llvm_cbe_999_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @freeViews\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.paramset_t* %%params, i64 0, i32 8, !dbg !34 for 0x%I64xth hint within @freeViews  --> \n", ++aesl_llvm_cbe_956_count);
  llvm_cbe_tmp__402 = (signed int *)(&llvm_cbe_params->field8);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i32* %%1, align 4, !dbg !34 for 0x%I64xth hint within @freeViews  --> \n", ++aesl_llvm_cbe_957_count);
  llvm_cbe_tmp__403 = (unsigned int )*llvm_cbe_tmp__402;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__403);
  if (((llvm_cbe_tmp__403&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = phi i64 [ %%12, %%.preheader ], [ 0, %%0  for 0x%I64xth hint within @freeViews  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned long long )llvm_cbe_storemerge3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%I64X",llvm_cbe_storemerge3);
printf("\n = 0x%I64X",llvm_cbe_tmp__412);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds %%struct.view_t** %%views, i64 %%storemerge3, !dbg !33 for 0x%I64xth hint within @freeViews  --> \n", ++aesl_llvm_cbe_963_count);
  llvm_cbe_tmp__404 = (l_struct_OC_view_t **)(&llvm_cbe_views[(((signed long long )llvm_cbe_storemerge3))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%I64X",((signed long long )llvm_cbe_storemerge3));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load %%struct.view_t** %%4, align 8, !dbg !33 for 0x%I64xth hint within @freeViews  --> \n", ++aesl_llvm_cbe_964_count);
  llvm_cbe_tmp__405 = (l_struct_OC_view_t *)*llvm_cbe_tmp__404;
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @freeView(%%struct.view_t* %%5), !dbg !33 for 0x%I64xth hint within @freeViews  --> \n", ++aesl_llvm_cbe_965_count);
   /*tail*/ freeView((l_struct_OC_view_t *)llvm_cbe_tmp__405);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load %%struct.view_t** %%4, align 8, !dbg !33 for 0x%I64xth hint within @freeViews  --> \n", ++aesl_llvm_cbe_970_count);
  llvm_cbe_tmp__406 = (l_struct_OC_view_t *)*llvm_cbe_tmp__404;
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds %%struct.view_t* %%6, i64 1, !dbg !33 for 0x%I64xth hint within @freeViews  --> \n", ++aesl_llvm_cbe_971_count);
  llvm_cbe_tmp__407 = (l_struct_OC_view_t *)(&llvm_cbe_tmp__406[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @freeView(%%struct.view_t* %%7), !dbg !33 for 0x%I64xth hint within @freeViews  --> \n", ++aesl_llvm_cbe_972_count);
   /*tail*/ freeView((l_struct_OC_view_t *)llvm_cbe_tmp__407);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load %%struct.view_t** %%4, align 8, !dbg !33 for 0x%I64xth hint within @freeViews  --> \n", ++aesl_llvm_cbe_977_count);
  llvm_cbe_tmp__408 = (l_struct_OC_view_t *)*llvm_cbe_tmp__404;
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds %%struct.view_t* %%8, i64 2, !dbg !33 for 0x%I64xth hint within @freeViews  --> \n", ++aesl_llvm_cbe_978_count);
  llvm_cbe_tmp__409 = (l_struct_OC_view_t *)(&llvm_cbe_tmp__408[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @freeView(%%struct.view_t* %%9), !dbg !33 for 0x%I64xth hint within @freeViews  --> \n", ++aesl_llvm_cbe_979_count);
   /*tail*/ freeView((l_struct_OC_view_t *)llvm_cbe_tmp__409);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = load %%struct.view_t** %%4, align 8, !dbg !33 for 0x%I64xth hint within @freeViews  --> \n", ++aesl_llvm_cbe_984_count);
  llvm_cbe_tmp__410 = (l_struct_OC_view_t *)*llvm_cbe_tmp__404;
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = bitcast %%struct.view_t* %%10 to i8*, !dbg !33 for 0x%I64xth hint within @freeViews  --> \n", ++aesl_llvm_cbe_985_count);
  llvm_cbe_tmp__411 = ( char *)(( char *)llvm_cbe_tmp__410);
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @free(i8* %%11), !dbg !33 for 0x%I64xth hint within @freeViews  --> \n", ++aesl_llvm_cbe_986_count);
   /*tail*/ free(( char *)llvm_cbe_tmp__411);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = add i64 %%storemerge3, 1, !dbg !34 for 0x%I64xth hint within @freeViews  --> \n", ++aesl_llvm_cbe_987_count);
  llvm_cbe_tmp__412 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge3&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__412&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = load i32* %%1, align 4, !dbg !34 for 0x%I64xth hint within @freeViews  --> \n", ++aesl_llvm_cbe_993_count);
  llvm_cbe_tmp__413 = (unsigned int )*llvm_cbe_tmp__402;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__413);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = zext i32 %%13 to i64, !dbg !34 for 0x%I64xth hint within @freeViews  --> \n", ++aesl_llvm_cbe_994_count);
  llvm_cbe_tmp__414 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__413&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__414);
  if ((((unsigned long long )llvm_cbe_tmp__412&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__414&18446744073709551615ULL))) {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__412;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = bitcast %%struct.view_t** %%views to i8*, !dbg !33 for 0x%I64xth hint within @freeViews  --> \n", ++aesl_llvm_cbe_997_count);
  llvm_cbe_tmp__415 = ( char *)(( char *)llvm_cbe_views);
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @free(i8* %%16), !dbg !33 for 0x%I64xth hint within @freeViews  --> \n", ++aesl_llvm_cbe_998_count);
   /*tail*/ free(( char *)llvm_cbe_tmp__415);
if (AESL_DEBUG_TRACE) {
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @freeViews}\n");
  return;
}


l_struct_OC_g_commitments_t *allocateGCommitments(l_struct_OC_paramset_t *llvm_cbe_params) {
  static  unsigned long long aesl_llvm_cbe_1000_count = 0;
  static  unsigned long long aesl_llvm_cbe_1001_count = 0;
  static  unsigned long long aesl_llvm_cbe_1002_count = 0;
  static  unsigned long long aesl_llvm_cbe_1003_count = 0;
  static  unsigned long long aesl_llvm_cbe_1004_count = 0;
  static  unsigned long long aesl_llvm_cbe_1005_count = 0;
  static  unsigned long long aesl_llvm_cbe_1006_count = 0;
  static  unsigned long long aesl_llvm_cbe_1007_count = 0;
  static  unsigned long long aesl_llvm_cbe_1008_count = 0;
  static  unsigned long long aesl_llvm_cbe_1009_count = 0;
  static  unsigned long long aesl_llvm_cbe_1010_count = 0;
   char *llvm_cbe_tmp__416;
  static  unsigned long long aesl_llvm_cbe_1011_count = 0;
  unsigned char llvm_cbe_tmp__417;
  static  unsigned long long aesl_llvm_cbe_1012_count = 0;
  static  unsigned long long aesl_llvm_cbe_1013_count = 0;
  static  unsigned long long aesl_llvm_cbe_1014_count = 0;
  signed int *llvm_cbe_tmp__418;
  static  unsigned long long aesl_llvm_cbe_1015_count = 0;
  unsigned int llvm_cbe_tmp__419;
  static  unsigned long long aesl_llvm_cbe_1016_count = 0;
  unsigned long long llvm_cbe_tmp__420;
  static  unsigned long long aesl_llvm_cbe_1017_count = 0;
  unsigned long long llvm_cbe_tmp__421;
  static  unsigned long long aesl_llvm_cbe_1018_count = 0;
   char *llvm_cbe_tmp__422;
  static  unsigned long long aesl_llvm_cbe_1019_count = 0;
  l_struct_OC_g_commitments_t *llvm_cbe_tmp__423;
  static  unsigned long long aesl_llvm_cbe_1020_count = 0;
  static  unsigned long long aesl_llvm_cbe_1021_count = 0;
  static  unsigned long long aesl_llvm_cbe_1022_count = 0;
  static  unsigned long long aesl_llvm_cbe_1023_count = 0;
  signed int *llvm_cbe_tmp__424;
  static  unsigned long long aesl_llvm_cbe_1024_count = 0;
  unsigned int llvm_cbe_tmp__425;
  static  unsigned long long aesl_llvm_cbe_1025_count = 0;
  unsigned int llvm_cbe_tmp__426;
  static  unsigned long long aesl_llvm_cbe_1026_count = 0;
  unsigned int llvm_cbe_tmp__427;
  static  unsigned long long aesl_llvm_cbe_1027_count = 0;
  unsigned long long llvm_cbe_tmp__428;
  static  unsigned long long aesl_llvm_cbe_1028_count = 0;
   char *llvm_cbe_tmp__429;
  static  unsigned long long aesl_llvm_cbe_1029_count = 0;
  static  unsigned long long aesl_llvm_cbe_1030_count = 0;
  static  unsigned long long aesl_llvm_cbe_1031_count = 0;
  static  unsigned long long aesl_llvm_cbe_1032_count = 0;
  static  unsigned long long aesl_llvm_cbe_1033_count = 0;
  static  unsigned long long aesl_llvm_cbe_1034_count = 0;
  static  unsigned long long aesl_llvm_cbe_1035_count = 0;
  static  unsigned long long aesl_llvm_cbe_1036_count = 0;
  static  unsigned long long aesl_llvm_cbe_1037_count = 0;
  static  unsigned long long aesl_llvm_cbe_1038_count = 0;
  unsigned long long llvm_cbe_tmp__430;
  static  unsigned long long aesl_llvm_cbe_1039_count = 0;
  unsigned long long llvm_cbe_tmp__431;
  static  unsigned long long aesl_llvm_cbe_1040_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned int llvm_cbe_storemerge3;
  unsigned int llvm_cbe_storemerge3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_rec_count = 0;
  unsigned long long llvm_cbe__2e_rec;
  unsigned long long llvm_cbe__2e_rec__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1041_count = 0;
   char *llvm_cbe_tmp__432;
  static  unsigned long long aesl_llvm_cbe_1042_count = 0;
  static  unsigned long long aesl_llvm_cbe_1043_count = 0;
  static  unsigned long long aesl_llvm_cbe_1044_count = 0;
  static  unsigned long long aesl_llvm_cbe_1045_count = 0;
  unsigned long long llvm_cbe_tmp__433;
  static  unsigned long long aesl_llvm_cbe_scevgep_2e_rec_count = 0;
  unsigned long long llvm_cbe_scevgep_2e_rec;
  static  unsigned long long aesl_llvm_cbe_1046_count = 0;
   char **llvm_cbe_tmp__434;
  static  unsigned long long aesl_llvm_cbe_1047_count = 0;
  static  unsigned long long aesl_llvm_cbe_1048_count = 0;
  static  unsigned long long aesl_llvm_cbe_1049_count = 0;
  static  unsigned long long aesl_llvm_cbe_1050_count = 0;
  static  unsigned long long aesl_llvm_cbe_1051_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_sum_count = 0;
  unsigned long long llvm_cbe__2e_sum;
  static  unsigned long long aesl_llvm_cbe_1052_count = 0;
   char *llvm_cbe_tmp__435;
  static  unsigned long long aesl_llvm_cbe_1053_count = 0;
   char **llvm_cbe_tmp__436;
  static  unsigned long long aesl_llvm_cbe_1054_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_rec4_2e_1_count = 0;
  unsigned long long llvm_cbe__2e_rec4_2e_1;
  static  unsigned long long aesl_llvm_cbe_1055_count = 0;
  static  unsigned long long aesl_llvm_cbe_1056_count = 0;
  static  unsigned long long aesl_llvm_cbe_1057_count = 0;
  static  unsigned long long aesl_llvm_cbe_1058_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_sum5_count = 0;
  unsigned long long llvm_cbe__2e_sum5;
  static  unsigned long long aesl_llvm_cbe_1059_count = 0;
   char *llvm_cbe_tmp__437;
  static  unsigned long long aesl_llvm_cbe_1060_count = 0;
   char **llvm_cbe_tmp__438;
  static  unsigned long long aesl_llvm_cbe_1061_count = 0;
  static  unsigned long long aesl_llvm_cbe_1062_count = 0;
  static  unsigned long long aesl_llvm_cbe_1063_count = 0;
  static  unsigned long long aesl_llvm_cbe_1064_count = 0;
  static  unsigned long long aesl_llvm_cbe_1065_count = 0;
  static  unsigned long long aesl_llvm_cbe_1066_count = 0;
  unsigned int llvm_cbe_tmp__439;
  static  unsigned long long aesl_llvm_cbe_1067_count = 0;
  static  unsigned long long aesl_llvm_cbe_1068_count = 0;
  static  unsigned long long aesl_llvm_cbe_1069_count = 0;
  static  unsigned long long aesl_llvm_cbe_1070_count = 0;
  static  unsigned long long aesl_llvm_cbe_1071_count = 0;
  static  unsigned long long aesl_llvm_cbe_1072_count = 0;
  static  unsigned long long aesl_llvm_cbe_1073_count = 0;
  static  unsigned long long aesl_llvm_cbe_1074_count = 0;
  l_struct_OC_g_commitments_t *llvm_cbe_tmp__440;
  l_struct_OC_g_commitments_t *llvm_cbe_tmp__440__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1075_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @allocateGCommitments\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.paramset_t* %%params, i64 0, i32 14, !dbg !33 for 0x%I64xth hint within @allocateGCommitments  --> \n", ++aesl_llvm_cbe_1010_count);
  llvm_cbe_tmp__416 = ( char *)(&llvm_cbe_params->field14);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i8* %%1, align 1, !dbg !33 for 0x%I64xth hint within @allocateGCommitments  --> \n", ++aesl_llvm_cbe_1011_count);
  llvm_cbe_tmp__417 = (unsigned char )*llvm_cbe_tmp__416;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__417);
  if (((llvm_cbe_tmp__417&255U) == (((unsigned char )1)&255U))) {
    goto llvm_cbe_tmp__441;
  } else {
    llvm_cbe_tmp__440__PHI_TEMPORARY = (l_struct_OC_g_commitments_t *)((l_struct_OC_g_commitments_t *)/*NULL*/0);   /* for PHI node */
    goto llvm_cbe_tmp__442;
  }

llvm_cbe_tmp__441:
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds %%struct.paramset_t* %%params, i64 0, i32 8, !dbg !33 for 0x%I64xth hint within @allocateGCommitments  --> \n", ++aesl_llvm_cbe_1014_count);
  llvm_cbe_tmp__418 = (signed int *)(&llvm_cbe_params->field8);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load i32* %%5, align 4, !dbg !33 for 0x%I64xth hint within @allocateGCommitments  --> \n", ++aesl_llvm_cbe_1015_count);
  llvm_cbe_tmp__419 = (unsigned int )*llvm_cbe_tmp__418;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__419);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = zext i32 %%6 to i64, !dbg !33 for 0x%I64xth hint within @allocateGCommitments  --> \n", ++aesl_llvm_cbe_1016_count);
  llvm_cbe_tmp__420 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__419&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__420);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = mul i64 %%7, 24, !dbg !33 for 0x%I64xth hint within @allocateGCommitments  --> \n", ++aesl_llvm_cbe_1017_count);
  llvm_cbe_tmp__421 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__420&18446744073709551615ull)) * ((unsigned long long )(24ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__421&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = tail call i8* @malloc(i64 %%8), !dbg !33 for 0x%I64xth hint within @allocateGCommitments  --> \n", ++aesl_llvm_cbe_1018_count);
  llvm_cbe_tmp__422 = ( char *) /*tail*/ ( char *)malloc(llvm_cbe_tmp__421);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__421);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__422);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = bitcast i8* %%9 to %%struct.g_commitments_t*, !dbg !33 for 0x%I64xth hint within @allocateGCommitments  --> \n", ++aesl_llvm_cbe_1019_count);
  llvm_cbe_tmp__423 = (l_struct_OC_g_commitments_t *)((l_struct_OC_g_commitments_t *)llvm_cbe_tmp__422);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds %%struct.paramset_t* %%params, i64 0, i32 7, !dbg !33 for 0x%I64xth hint within @allocateGCommitments  --> \n", ++aesl_llvm_cbe_1023_count);
  llvm_cbe_tmp__424 = (signed int *)(&llvm_cbe_params->field7);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = load i32* %%11, align 4, !dbg !33 for 0x%I64xth hint within @allocateGCommitments  --> \n", ++aesl_llvm_cbe_1024_count);
  llvm_cbe_tmp__425 = (unsigned int )*llvm_cbe_tmp__424;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__425);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = mul i32 %%12, 3, !dbg !33 for 0x%I64xth hint within @allocateGCommitments  --> \n", ++aesl_llvm_cbe_1025_count);
  llvm_cbe_tmp__426 = (unsigned int )((unsigned int )(llvm_cbe_tmp__425&4294967295ull)) * ((unsigned int )(3u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__426&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = mul i32 %%13, %%6, !dbg !33 for 0x%I64xth hint within @allocateGCommitments  --> \n", ++aesl_llvm_cbe_1026_count);
  llvm_cbe_tmp__427 = (unsigned int )((unsigned int )(llvm_cbe_tmp__426&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__419&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__427&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = zext i32 %%14 to i64, !dbg !33 for 0x%I64xth hint within @allocateGCommitments  --> \n", ++aesl_llvm_cbe_1027_count);
  llvm_cbe_tmp__428 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__427&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__428);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = tail call i8* @malloc(i64 %%15), !dbg !33 for 0x%I64xth hint within @allocateGCommitments  --> \n", ++aesl_llvm_cbe_1028_count);
  llvm_cbe_tmp__429 = ( char *) /*tail*/ ( char *)malloc(llvm_cbe_tmp__428);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__428);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__429);
}
  if (((llvm_cbe_tmp__419&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe__2e_loopexit;
  } else {
    goto llvm_cbe__2e_preheader_2e_lr_2e_ph;
  }

llvm_cbe__2e_preheader_2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = zext i32 %%12 to i64, !dbg !33 for 0x%I64xth hint within @allocateGCommitments  --> \n", ++aesl_llvm_cbe_1038_count);
  llvm_cbe_tmp__430 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__425&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__430);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = mul i64 %%18, 3, !dbg !33 for 0x%I64xth hint within @allocateGCommitments  --> \n", ++aesl_llvm_cbe_1039_count);
  llvm_cbe_tmp__431 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__430&18446744073709551615ull)) * ((unsigned long long )(3ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__431&18446744073709551615ull)));
  llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  llvm_cbe__2e_rec__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe__2e_preheader;

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = phi i32 [ 0, %%.preheader.lr.ph ], [ %%27, %%.preheader  for 0x%I64xth hint within @allocateGCommitments  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned int )llvm_cbe_storemerge3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%X",llvm_cbe_storemerge3);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__439);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec = phi i64 [ 0, %%.preheader.lr.ph ], [ %%scevgep.rec, %%.preheader  for 0x%I64xth hint within @allocateGCommitments  --> \n", ++aesl_llvm_cbe__2e_rec_count);
  llvm_cbe__2e_rec = (unsigned long long )llvm_cbe__2e_rec__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.rec = 0x%I64X",llvm_cbe__2e_rec);
printf("\n = 0x%I64X",0ull);
printf("\nscevgep.rec = 0x%I64X",llvm_cbe_scevgep_2e_rec);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = getelementptr i8* %%16, i64 %%.re for 0x%I64xth hint within @allocateGCommitments  --> \n", ++aesl_llvm_cbe_1041_count);
  llvm_cbe_tmp__432 = ( char *)(&llvm_cbe_tmp__429[(((signed long long )llvm_cbe__2e_rec))]);
if (AESL_DEBUG_TRACE) {
printf("\n.rec = 0x%I64X",((signed long long )llvm_cbe__2e_rec));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = zext i32 %%storemerge3 to i64, !dbg !34 for 0x%I64xth hint within @allocateGCommitments  --> \n", ++aesl_llvm_cbe_1045_count);
  llvm_cbe_tmp__433 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge3&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__433);
if (AESL_DEBUG_TRACE)
printf("\n  %%scevgep.rec = add i64 %%.rec, %%19, !dbg !33 for 0x%I64xth hint within @allocateGCommitments  --> \n", ++aesl_llvm_cbe_scevgep_2e_rec_count);
  llvm_cbe_scevgep_2e_rec = (unsigned long long )((unsigned long long )(llvm_cbe__2e_rec&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__431&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\nscevgep.rec = 0x%I64X\n", ((unsigned long long )(llvm_cbe_scevgep_2e_rec&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = getelementptr inbounds %%struct.g_commitments_t* %%10, i64 %%21, i32 0, i64 0, !dbg !34 for 0x%I64xth hint within @allocateGCommitments  --> \n", ++aesl_llvm_cbe_1046_count);
  llvm_cbe_tmp__434 = ( char **)(&llvm_cbe_tmp__423[(((signed long long )llvm_cbe_tmp__433))].field0[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__433));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8* %%20, i8** %%22, align 8, !dbg !34 for 0x%I64xth hint within @allocateGCommitments  --> \n", ++aesl_llvm_cbe_1047_count);
  *llvm_cbe_tmp__434 = ( char *)llvm_cbe_tmp__432;
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum = add i64 %%.rec, %%1 for 0x%I64xth hint within @allocateGCommitments  --> \n", ++aesl_llvm_cbe__2e_sum_count);
  llvm_cbe__2e_sum = (unsigned long long )((unsigned long long )(llvm_cbe__2e_rec&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__430&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = getelementptr i8* %%16, i64 %%.su for 0x%I64xth hint within @allocateGCommitments  --> \n", ++aesl_llvm_cbe_1052_count);
  llvm_cbe_tmp__435 = ( char *)(&llvm_cbe_tmp__429[(((signed long long )llvm_cbe__2e_sum))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum = 0x%I64X",((signed long long )llvm_cbe__2e_sum));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = getelementptr inbounds %%struct.g_commitments_t* %%10, i64 %%21, i32 0, i64 1, !dbg !34 for 0x%I64xth hint within @allocateGCommitments  --> \n", ++aesl_llvm_cbe_1053_count);
  llvm_cbe_tmp__436 = ( char **)(&llvm_cbe_tmp__423[(((signed long long )llvm_cbe_tmp__433))].field0[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__433));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8* %%23, i8** %%24, align 8, !dbg !34 for 0x%I64xth hint within @allocateGCommitments  --> \n", ++aesl_llvm_cbe_1054_count);
  *llvm_cbe_tmp__436 = ( char *)llvm_cbe_tmp__435;
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec4.1 = shl nuw nsw i64 %%18, 1, !dbg !33 for 0x%I64xth hint within @allocateGCommitments  --> \n", ++aesl_llvm_cbe__2e_rec4_2e_1_count);
  llvm_cbe__2e_rec4_2e_1 = (unsigned long long )llvm_cbe_tmp__430 << 1ull;
if (AESL_DEBUG_TRACE)
printf("\n.rec4.1 = 0x%I64X\n", llvm_cbe__2e_rec4_2e_1);
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum5 = add i64 %%.rec, %%.rec4. for 0x%I64xth hint within @allocateGCommitments  --> \n", ++aesl_llvm_cbe__2e_sum5_count);
  llvm_cbe__2e_sum5 = (unsigned long long )((unsigned long long )(llvm_cbe__2e_rec&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe__2e_rec4_2e_1&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum5 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum5&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = getelementptr i8* %%16, i64 %%.sum for 0x%I64xth hint within @allocateGCommitments  --> \n", ++aesl_llvm_cbe_1059_count);
  llvm_cbe_tmp__437 = ( char *)(&llvm_cbe_tmp__429[(((signed long long )llvm_cbe__2e_sum5))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum5 = 0x%I64X",((signed long long )llvm_cbe__2e_sum5));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = getelementptr inbounds %%struct.g_commitments_t* %%10, i64 %%21, i32 0, i64 2, !dbg !34 for 0x%I64xth hint within @allocateGCommitments  --> \n", ++aesl_llvm_cbe_1060_count);
  llvm_cbe_tmp__438 = ( char **)(&llvm_cbe_tmp__423[(((signed long long )llvm_cbe_tmp__433))].field0[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__433));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8* %%25, i8** %%26, align 8, !dbg !34 for 0x%I64xth hint within @allocateGCommitments  --> \n", ++aesl_llvm_cbe_1061_count);
  *llvm_cbe_tmp__438 = ( char *)llvm_cbe_tmp__437;
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = add i32 %%storemerge3, 1, !dbg !34 for 0x%I64xth hint within @allocateGCommitments  --> \n", ++aesl_llvm_cbe_1066_count);
  llvm_cbe_tmp__439 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__439&4294967295ull)));
  if ((((unsigned int )llvm_cbe_tmp__439&4294967295U) < ((unsigned int )llvm_cbe_tmp__419&4294967295U))) {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__439;   /* for PHI node */
    llvm_cbe__2e_rec__PHI_TEMPORARY = (unsigned long long )llvm_cbe_scevgep_2e_rec;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  } else {
    goto llvm_cbe__2e_loopexit;
  }

  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe__2e_loopexit:
  llvm_cbe_tmp__440__PHI_TEMPORARY = (l_struct_OC_g_commitments_t *)llvm_cbe_tmp__423;   /* for PHI node */
  goto llvm_cbe_tmp__442;

llvm_cbe_tmp__442:
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = phi %%struct.g_commitments_t* [ null, %%0 ], [ %%10, %%.loopexit  for 0x%I64xth hint within @allocateGCommitments  --> \n", ++aesl_llvm_cbe_1074_count);
  llvm_cbe_tmp__440 = (l_struct_OC_g_commitments_t *)llvm_cbe_tmp__440__PHI_TEMPORARY;
  if (AESL_DEBUG_TRACE)
      printf("\nEND @allocateGCommitments}\n");
  return llvm_cbe_tmp__440;
}


void freeGCommitments(l_struct_OC_g_commitments_t *llvm_cbe_gs) {
  static  unsigned long long aesl_llvm_cbe_1076_count = 0;
  static  unsigned long long aesl_llvm_cbe_1077_count = 0;
  static  unsigned long long aesl_llvm_cbe_1078_count = 0;
  static  unsigned long long aesl_llvm_cbe_1079_count = 0;
  static  unsigned long long aesl_llvm_cbe_1080_count = 0;
  static  unsigned long long aesl_llvm_cbe_1081_count = 0;
  static  unsigned long long aesl_llvm_cbe_1082_count = 0;
   char **llvm_cbe_tmp__443;
  static  unsigned long long aesl_llvm_cbe_1083_count = 0;
   char *llvm_cbe_tmp__444;
  static  unsigned long long aesl_llvm_cbe_1084_count = 0;
  static  unsigned long long aesl_llvm_cbe_1085_count = 0;
   char *llvm_cbe_tmp__445;
  static  unsigned long long aesl_llvm_cbe_1086_count = 0;
  static  unsigned long long aesl_llvm_cbe_1087_count = 0;
  static  unsigned long long aesl_llvm_cbe_1088_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @freeGCommitments\n");
  if (((llvm_cbe_gs) == (((l_struct_OC_g_commitments_t *)/*NULL*/0)))) {
    goto llvm_cbe_tmp__446;
  } else {
    goto llvm_cbe_tmp__447;
  }

llvm_cbe_tmp__447:
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.g_commitments_t* %%gs, i64 0, i32 0, i64 0, !dbg !33 for 0x%I64xth hint within @freeGCommitments  --> \n", ++aesl_llvm_cbe_1082_count);
  llvm_cbe_tmp__443 = ( char **)(&llvm_cbe_gs->field0[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i8** %%3, align 8, !dbg !33 for 0x%I64xth hint within @freeGCommitments  --> \n", ++aesl_llvm_cbe_1083_count);
  llvm_cbe_tmp__444 = ( char *)*llvm_cbe_tmp__443;
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @free(i8* %%4), !dbg !33 for 0x%I64xth hint within @freeGCommitments  --> \n", ++aesl_llvm_cbe_1084_count);
   /*tail*/ free(( char *)llvm_cbe_tmp__444);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = bitcast %%struct.g_commitments_t* %%gs to i8*, !dbg !33 for 0x%I64xth hint within @freeGCommitments  --> \n", ++aesl_llvm_cbe_1085_count);
  llvm_cbe_tmp__445 = ( char *)(( char *)llvm_cbe_gs);
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @free(i8* %%5), !dbg !33 for 0x%I64xth hint within @freeGCommitments  --> \n", ++aesl_llvm_cbe_1086_count);
   /*tail*/ free(( char *)llvm_cbe_tmp__445);
if (AESL_DEBUG_TRACE) {
}
  goto llvm_cbe_tmp__446;

llvm_cbe_tmp__446:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @freeGCommitments}\n");
  return;
}

