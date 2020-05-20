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
typedef struct l_struct_OC_paramset_t l_struct_OC_paramset_t;
typedef struct l_struct_OC_picnic_publickey_t l_struct_OC_picnic_publickey_t;
typedef struct l_struct_OC_picnic_privatekey_t l_struct_OC_picnic_privatekey_t;
typedef struct l_struct_OC_signature_t l_struct_OC_signature_t;
typedef struct l_struct_OC_proof_t l_struct_OC_proof_t;
typedef struct l_struct_OC__iobuf l_struct_OC__iobuf;

/* Structure contents */
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
unsigned char get_transform( char llvm_cbe_parameters);
 char *picnic_get_param_name( char llvm_cbe_parameters);
signed int get_param_set( char llvm_cbe_picnicParams, l_struct_OC_paramset_t *llvm_cbe_paramset);
signed int numBytes(signed int );
signed int picnic_keygen( char llvm_cbe_parameters, l_struct_OC_picnic_publickey_t *llvm_cbe_pk, l_struct_OC_picnic_privatekey_t *llvm_cbe_sk);
static signed int aesl_internal_is_valid_params( char llvm_cbe_params);
signed int randombytes( char *, signed long long );
void LowMCEnc(signed int *, signed int *, signed int *, l_struct_OC_paramset_t *);
signed int is_picnic2( char llvm_cbe_params);
signed int picnic_sign(l_struct_OC_picnic_privatekey_t *llvm_cbe_sk,  char *llvm_cbe_message, signed long long llvm_cbe_message_len,  char *llvm_cbe_signature, signed long long *llvm_cbe_signature_len);
signed int sign_picnic1(signed int *, signed int *, signed int *,  char *, signed long long , l_struct_OC_signature_t *, l_struct_OC_paramset_t *);
signed int serializeSignature(l_struct_OC_signature_t *,  char *, signed long long , l_struct_OC_paramset_t *);
signed long long picnic_signature_size( char llvm_cbe_parameters);
signed int ceil_log2(signed int );
signed int picnic_verify(l_struct_OC_picnic_publickey_t *llvm_cbe_pk,  char *llvm_cbe_message, signed long long llvm_cbe_message_len,  char *llvm_cbe_signature, signed long long llvm_cbe_signature_len);
signed int deserializeSignature(l_struct_OC_signature_t *,  char *, signed long long , l_struct_OC_paramset_t *);
signed int verify(l_struct_OC_signature_t *, signed int *, signed int *,  char *, signed long long , l_struct_OC_paramset_t *);
void freeSignature(l_struct_OC_signature_t *, l_struct_OC_paramset_t *);
signed int picnic_write_public_key(l_struct_OC_picnic_publickey_t *llvm_cbe_key,  char *llvm_cbe_buf, signed long long llvm_cbe_buflen);
signed int picnic_read_public_key(l_struct_OC_picnic_publickey_t *llvm_cbe_key,  char *llvm_cbe_buf, signed long long llvm_cbe_buflen);
signed int picnic_write_private_key(l_struct_OC_picnic_privatekey_t *llvm_cbe_key,  char *llvm_cbe_buf, signed long long llvm_cbe_buflen);
signed int picnic_read_private_key(l_struct_OC_picnic_privatekey_t *llvm_cbe_key,  char *llvm_cbe_buf, signed long long llvm_cbe_buflen);
signed int picnic_validate_keypair(l_struct_OC_picnic_privatekey_t *llvm_cbe_privatekey, l_struct_OC_picnic_publickey_t *llvm_cbe_publickey);
void print_signature( char *llvm_cbe_sigBytes, signed long long llvm_cbe_sigBytesLen,  char llvm_cbe_picnic_params);
void allocateSignature(l_struct_OC_signature_t *, l_struct_OC_paramset_t *);
void printHex( char *,  char *, signed long long );
unsigned char getChallenge( char *, signed long long );


/* Global Variable Definitions and Initialization */
static  char aesl_internal__OC_str6[14] = "Picnic2_L1_FS";
static  char aesl_internal__OC_str23[11] = "transcript";
static  char aesl_internal__OC_str24[6] = "seed1";
static  char aesl_internal__OC_str25[6] = "seed2";
static  char aesl_internal_str[15] = "INVALID PARAMS";
static  char aesl_internal_str2[100] = "Printing intermediate values of signatures created with Picnic2 parameter sets is not supported yet";
static  char aesl_internal__OC_str1[13] = "Picnic_L1_UR";
static  char aesl_internal__OC_str7[14] = "Picnic2_L3_FS";
static  char aesl_internal___func___OC_picnic_write_private_key[25] = "picnic_write_private_key";
static  char aesl_internal__OC_str5[13] = "Picnic_L5_UR";
static  char aesl_internal__OC_str14[27] = "Unsupported parameter set\n";
static  char aesl_internal__OC_str26[11] = "inputShare";
static  char aesl_internal_str1[22] = "Invalid parameter set";
static  char aesl_internal__OC_str22[10] = "e_%u: %u\n";
static  char aesl_internal__OC_str[13] = "Picnic_L1_FS";
static  char aesl_internal__OC_str2[13] = "Picnic_L3_FS";
static  char aesl_internal__OC_str18[10] = "challenge";
static  char aesl_internal__OC_str8[14] = "Picnic2_L5_FS";
static  char aesl_internal__OC_str13[56] = "%s: buffer provided has %u bytes, but %u are required.\n";
static  char aesl_internal__OC_str4[13] = "Picnic_L5_FS";
static  char aesl_internal__OC_str3[13] = "Picnic_L3_UR";
static  char aesl_internal__OC_str9[22] = "Unknown parameter set";
static  char aesl_internal__OC_str21[17] = "Iteration t: %u\n";
static  char aesl_internal__OC_str19[5] = "salt";
static  char aesl_internal_str3[41] = "Invalid signature; deserialization fails";


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

unsigned char get_transform( char llvm_cbe_parameters) {
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
  unsigned int llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
  unsigned char llvm_cbe_tmp__2;
  unsigned char llvm_cbe_tmp__2__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @get_transform\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = zext i4 %%parameters to i32, !dbg !19 for 0x%I64xth hint within @get_transform  --> \n", ++aesl_llvm_cbe_3_count);
  llvm_cbe_tmp__1 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_parameters&15U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__1);
  switch (((unsigned int )(llvm_cbe_tmp__1&4294967295ull))) {
  default:
    llvm_cbe_tmp__2__PHI_TEMPORARY = (unsigned char )((unsigned char )-1);   /* for PHI node */
    goto llvm_cbe_tmp__3;
;
  case ((unsigned int )(1u&4294967295ull)):
    goto llvm_cbe_tmp__4;
    break;
  case ((unsigned int )(3u&4294967295ull)):
    goto llvm_cbe_tmp__4;
    break;
  case ((unsigned int )(5u&4294967295ull)):
    goto llvm_cbe_tmp__4;
    break;
  case ((unsigned int )(7u&4294967295ull)):
    goto llvm_cbe_tmp__4;
    break;
  case ((unsigned int )(8u&4294967295ull)):
    goto llvm_cbe_tmp__4;
    break;
  case ((unsigned int )(9u&4294967295ull)):
    goto llvm_cbe_tmp__4;
    break;
  case ((unsigned int )(2u&4294967295ull)):
    goto llvm_cbe_tmp__5;
  case ((unsigned int )(4u&4294967295ull)):
    goto llvm_cbe_tmp__5;
  case ((unsigned int )(6u&4294967295ull)):
    goto llvm_cbe_tmp__5;
  }
llvm_cbe_tmp__4:
  llvm_cbe_tmp__2__PHI_TEMPORARY = (unsigned char )((unsigned char )0);   /* for PHI node */
  goto llvm_cbe_tmp__3;

llvm_cbe_tmp__5:
  llvm_cbe_tmp__2__PHI_TEMPORARY = (unsigned char )((unsigned char )1);   /* for PHI node */
  goto llvm_cbe_tmp__3;

llvm_cbe_tmp__3:
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = phi i8 [ 1, %%3 ], [ 0, %%2 ], [ -1, %%0  for 0x%I64xth hint within @get_transform  --> \n", ++aesl_llvm_cbe_7_count);
  llvm_cbe_tmp__2 = (unsigned char )llvm_cbe_tmp__2__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__2);
printf("\n = 0x%X",((unsigned char )1));
printf("\n = 0x%X",((unsigned char )0));
printf("\n = 0x%X",((unsigned char )-1));
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @get_transform}\n");
  return llvm_cbe_tmp__2;
}


 char *picnic_get_param_name( char llvm_cbe_parameters) {
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  unsigned int llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
   char *llvm_cbe_tmp__7;
   char *llvm_cbe_tmp__7__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @picnic_get_param_name\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = zext i4 %%parameters to i32, !dbg !19 for 0x%I64xth hint within @picnic_get_param_name  --> \n", ++aesl_llvm_cbe_11_count);
  llvm_cbe_tmp__6 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_parameters&15U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__6);
  switch (((unsigned int )(llvm_cbe_tmp__6&4294967295ull))) {
  default:
    goto llvm_cbe_tmp__8;
;
  case ((unsigned int )(1u&4294967295ull)):
    llvm_cbe_tmp__7__PHI_TEMPORARY = ( char *)((&aesl_internal__OC_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 13
#endif
]));   /* for PHI node */
    goto llvm_cbe_tmp__9;
  case ((unsigned int )(2u&4294967295ull)):
    goto llvm_cbe_tmp__10;
    break;
  case ((unsigned int )(3u&4294967295ull)):
    goto llvm_cbe_tmp__11;
  case ((unsigned int )(4u&4294967295ull)):
    goto llvm_cbe_tmp__12;
  case ((unsigned int )(5u&4294967295ull)):
    goto llvm_cbe_tmp__13;
  case ((unsigned int )(6u&4294967295ull)):
    goto llvm_cbe_tmp__14;
  case ((unsigned int )(7u&4294967295ull)):
    goto llvm_cbe_tmp__15;
  case ((unsigned int )(8u&4294967295ull)):
    goto llvm_cbe_tmp__16;
  case ((unsigned int )(9u&4294967295ull)):
    goto llvm_cbe_tmp__17;
  }
llvm_cbe_tmp__10:
  llvm_cbe_tmp__7__PHI_TEMPORARY = ( char *)((&aesl_internal__OC_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 13
#endif
]));   /* for PHI node */
  goto llvm_cbe_tmp__9;

llvm_cbe_tmp__11:
  llvm_cbe_tmp__7__PHI_TEMPORARY = ( char *)((&aesl_internal__OC_str2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 13
#endif
]));   /* for PHI node */
  goto llvm_cbe_tmp__9;

llvm_cbe_tmp__12:
  llvm_cbe_tmp__7__PHI_TEMPORARY = ( char *)((&aesl_internal__OC_str3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 13
#endif
]));   /* for PHI node */
  goto llvm_cbe_tmp__9;

llvm_cbe_tmp__13:
  llvm_cbe_tmp__7__PHI_TEMPORARY = ( char *)((&aesl_internal__OC_str4[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 13
#endif
]));   /* for PHI node */
  goto llvm_cbe_tmp__9;

llvm_cbe_tmp__14:
  llvm_cbe_tmp__7__PHI_TEMPORARY = ( char *)((&aesl_internal__OC_str5[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 13
#endif
]));   /* for PHI node */
  goto llvm_cbe_tmp__9;

llvm_cbe_tmp__15:
  llvm_cbe_tmp__7__PHI_TEMPORARY = ( char *)((&aesl_internal__OC_str6[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 14
#endif
]));   /* for PHI node */
  goto llvm_cbe_tmp__9;

llvm_cbe_tmp__16:
  llvm_cbe_tmp__7__PHI_TEMPORARY = ( char *)((&aesl_internal__OC_str7[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 14
#endif
]));   /* for PHI node */
  goto llvm_cbe_tmp__9;

llvm_cbe_tmp__17:
  llvm_cbe_tmp__7__PHI_TEMPORARY = ( char *)((&aesl_internal__OC_str8[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 14
#endif
]));   /* for PHI node */
  goto llvm_cbe_tmp__9;

llvm_cbe_tmp__8:
  llvm_cbe_tmp__7__PHI_TEMPORARY = ( char *)((&aesl_internal__OC_str9[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 22
#endif
]));   /* for PHI node */
  goto llvm_cbe_tmp__9;

llvm_cbe_tmp__9:
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = phi i8* [ getelementptr inbounds ([22 x i8]* @aesl_internal_.str9, i64 0, i64 0), %%10 ], [ getelementptr inbounds ([14 x i8]* @aesl_internal_.str8, i64 0, i64 0), %%9 ], [ getelementptr inbounds ([14 x i8]* @aesl_internal_.str7, i64 0, i64 0), %%8 ], [ getelementptr inbounds ([14 x i8]* @aesl_internal_.str6, i64 0, i64 0), %%7 ], [ getelementptr inbounds ([13 x i8]* @aesl_internal_.str5, i64 0, i64 0), %%6 ], [ getelementptr inbounds ([13 x i8]* @aesl_internal_.str4, i64 0, i64 0), %%5 ], [ getelementptr inbounds ([13 x i8]* @aesl_internal_.str3, i64 0, i64 0), %%4 ], [ getelementptr inbounds ([13 x i8]* @aesl_internal_.str2, i64 0, i64 0), %%3 ], [ getelementptr inbounds ([13 x i8]* @aesl_internal_.str1, i64 0, i64 0), %%2 ], [ getelementptr inbounds ([13 x i8]* @aesl_internal_.str, i64 0, i64 0), %%0  for 0x%I64xth hint within @picnic_get_param_name  --> \n", ++aesl_llvm_cbe_22_count);
  llvm_cbe_tmp__7 = ( char *)llvm_cbe_tmp__7__PHI_TEMPORARY;
  if (AESL_DEBUG_TRACE)
      printf("\nEND @picnic_get_param_name}\n");
  return llvm_cbe_tmp__7;
}


signed int get_param_set( char llvm_cbe_picnicParams, l_struct_OC_paramset_t *llvm_cbe_paramset) {
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
   char *llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
   char *llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  signed int *llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  signed int *llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  signed int *llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  signed int *llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  signed int *llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  unsigned int llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  signed int *llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  unsigned int llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  signed int *llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  unsigned int llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  signed int *llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  unsigned int llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  unsigned int llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  signed int *llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  unsigned int llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  unsigned int llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  signed int *llvm_cbe_tmp__36;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  unsigned char llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
   char *llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  signed int *llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  unsigned int llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  unsigned int llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  signed int *llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
  unsigned int llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  signed int *llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @get_param_set\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = bitcast %%struct.paramset_t* %%paramset to i8*, !dbg !20 for 0x%I64xth hint within @get_param_set  --> \n", ++aesl_llvm_cbe_51_count);
  llvm_cbe_tmp__18 = ( char *)(( char *)llvm_cbe_paramset);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = call i8* @memset(i8* %%1, i32 0, i64 60 for 0x%I64xth hint within @get_param_set  --> \n", ++aesl_llvm_cbe_52_count);
  ( char *)memset(( char *)llvm_cbe_tmp__18, 0u, 60ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",60ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__19);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.paramset_t* %%paramset, i64 0, i32 8, !dbg !20 for 0x%I64xth hint within @get_param_set  --> \n", ++aesl_llvm_cbe_56_count);
  llvm_cbe_tmp__20 = (signed int *)(&llvm_cbe_paramset->field8);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 219, i32* %%3, align 4, !dbg !20 for 0x%I64xth hint within @get_param_set  --> \n", ++aesl_llvm_cbe_57_count);
  *llvm_cbe_tmp__20 = 219u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 219u);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds %%struct.paramset_t* %%paramset, i64 0, i32 10, !dbg !20 for 0x%I64xth hint within @get_param_set  --> \n", ++aesl_llvm_cbe_58_count);
  llvm_cbe_tmp__21 = (signed int *)(&llvm_cbe_paramset->field10);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 3, i32* %%4, align 4, !dbg !20 for 0x%I64xth hint within @get_param_set  --> \n", ++aesl_llvm_cbe_59_count);
  *llvm_cbe_tmp__21 = 3u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 3u);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds %%struct.paramset_t* %%paramset, i64 0, i32 1, !dbg !20 for 0x%I64xth hint within @get_param_set  --> \n", ++aesl_llvm_cbe_60_count);
  llvm_cbe_tmp__22 = (signed int *)(&llvm_cbe_paramset->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 10, i32* %%5, align 4, !dbg !20 for 0x%I64xth hint within @get_param_set  --> \n", ++aesl_llvm_cbe_61_count);
  *llvm_cbe_tmp__22 = 10u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 10u);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds %%struct.paramset_t* %%paramset, i64 0, i32 0, !dbg !20 for 0x%I64xth hint within @get_param_set  --> \n", ++aesl_llvm_cbe_62_count);
  llvm_cbe_tmp__23 = (signed int *)(&llvm_cbe_paramset->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 20, i32* %%6, align 4, !dbg !20 for 0x%I64xth hint within @get_param_set  --> \n", ++aesl_llvm_cbe_63_count);
  *llvm_cbe_tmp__23 = 20u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 20u);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds %%struct.paramset_t* %%paramset, i64 0, i32 13, !dbg !20 for 0x%I64xth hint within @get_param_set  --> \n", ++aesl_llvm_cbe_64_count);
  llvm_cbe_tmp__24 = (signed int *)(&llvm_cbe_paramset->field13);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 32, i32* %%7, align 4, !dbg !20 for 0x%I64xth hint within @get_param_set  --> \n", ++aesl_llvm_cbe_65_count);
  *llvm_cbe_tmp__24 = 32u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 32u);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = tail call i32 @numBytes(i32 600) nounwind, !dbg !20 for 0x%I64xth hint within @get_param_set  --> \n", ++aesl_llvm_cbe_66_count);
  llvm_cbe_tmp__25 = (unsigned int ) /*tail*/ numBytes(600u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",600u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__25);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds %%struct.paramset_t* %%paramset, i64 0, i32 5, !dbg !20 for 0x%I64xth hint within @get_param_set  --> \n", ++aesl_llvm_cbe_67_count);
  llvm_cbe_tmp__26 = (signed int *)(&llvm_cbe_paramset->field5);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%8, i32* %%9, align 4, !dbg !20 for 0x%I64xth hint within @get_param_set  --> \n", ++aesl_llvm_cbe_68_count);
  *llvm_cbe_tmp__26 = llvm_cbe_tmp__25;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__25);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = tail call i32 @numBytes(i32 128) nounwind, !dbg !20 for 0x%I64xth hint within @get_param_set  --> \n", ++aesl_llvm_cbe_69_count);
  llvm_cbe_tmp__27 = (unsigned int ) /*tail*/ numBytes(128u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",128u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__27);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds %%struct.paramset_t* %%paramset, i64 0, i32 3, !dbg !20 for 0x%I64xth hint within @get_param_set  --> \n", ++aesl_llvm_cbe_70_count);
  llvm_cbe_tmp__28 = (signed int *)(&llvm_cbe_paramset->field3);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%10, i32* %%11, align 4, !dbg !20 for 0x%I64xth hint within @get_param_set  --> \n", ++aesl_llvm_cbe_71_count);
  *llvm_cbe_tmp__28 = llvm_cbe_tmp__27;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__27);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = tail call i32 @numBytes(i32 128) nounwind, !dbg !20 for 0x%I64xth hint within @get_param_set  --> \n", ++aesl_llvm_cbe_72_count);
  llvm_cbe_tmp__29 = (unsigned int ) /*tail*/ numBytes(128u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",128u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__29);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds %%struct.paramset_t* %%paramset, i64 0, i32 11, !dbg !20 for 0x%I64xth hint within @get_param_set  --> \n", ++aesl_llvm_cbe_73_count);
  llvm_cbe_tmp__30 = (signed int *)(&llvm_cbe_paramset->field11);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%12, i32* %%13, align 4, !dbg !20 for 0x%I64xth hint within @get_param_set  --> \n", ++aesl_llvm_cbe_74_count);
  *llvm_cbe_tmp__30 = llvm_cbe_tmp__29;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__29);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load i32* %%11, align 4, !dbg !21 for 0x%I64xth hint within @get_param_set  --> \n", ++aesl_llvm_cbe_75_count);
  llvm_cbe_tmp__31 = (unsigned int )*llvm_cbe_tmp__28;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__31);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = shl i32 %%14, 3, !dbg !21 for 0x%I64xth hint within @get_param_set  --> \n", ++aesl_llvm_cbe_76_count);
  llvm_cbe_tmp__32 = (unsigned int )llvm_cbe_tmp__31 << 3u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__32);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds %%struct.paramset_t* %%paramset, i64 0, i32 2, !dbg !21 for 0x%I64xth hint within @get_param_set  --> \n", ++aesl_llvm_cbe_77_count);
  llvm_cbe_tmp__33 = (signed int *)(&llvm_cbe_paramset->field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%15, i32* %%16, align 4, !dbg !21 for 0x%I64xth hint within @get_param_set  --> \n", ++aesl_llvm_cbe_78_count);
  *llvm_cbe_tmp__33 = llvm_cbe_tmp__32;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__32);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = lshr i32 %%14, 2, !dbg !21 for 0x%I64xth hint within @get_param_set  --> \n", ++aesl_llvm_cbe_79_count);
  llvm_cbe_tmp__34 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__31&4294967295ull)) >> ((unsigned int )(2u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__34&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = and i32 %%17, 134217727, !dbg !21 for 0x%I64xth hint within @get_param_set  --> \n", ++aesl_llvm_cbe_80_count);
  llvm_cbe_tmp__35 = (unsigned int )llvm_cbe_tmp__34 & 134217727u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__35);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = getelementptr inbounds %%struct.paramset_t* %%paramset, i64 0, i32 4, !dbg !21 for 0x%I64xth hint within @get_param_set  --> \n", ++aesl_llvm_cbe_81_count);
  llvm_cbe_tmp__36 = (signed int *)(&llvm_cbe_paramset->field4);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%18, i32* %%19, align 4, !dbg !21 for 0x%I64xth hint within @get_param_set  --> \n", ++aesl_llvm_cbe_82_count);
  *llvm_cbe_tmp__36 = llvm_cbe_tmp__35;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__35);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = tail call zeroext i8 @get_transform(i4 zeroext %%picnicParams), !dbg !19 for 0x%I64xth hint within @get_param_set  --> \n", ++aesl_llvm_cbe_83_count);
  llvm_cbe_tmp__37 = (unsigned char ) /*tail*/ get_transform(llvm_cbe_picnicParams);
if (AESL_DEBUG_TRACE) {
printf("\nArgument picnicParams = 0x%X",llvm_cbe_picnicParams);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__37);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = getelementptr inbounds %%struct.paramset_t* %%paramset, i64 0, i32 14, !dbg !19 for 0x%I64xth hint within @get_param_set  --> \n", ++aesl_llvm_cbe_84_count);
  llvm_cbe_tmp__38 = ( char *)(&llvm_cbe_paramset->field14);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%20, i8* %%21, align 1, !dbg !19 for 0x%I64xth hint within @get_param_set  --> \n", ++aesl_llvm_cbe_85_count);
  *llvm_cbe_tmp__38 = llvm_cbe_tmp__37;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__37);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = getelementptr inbounds %%struct.paramset_t* %%paramset, i64 0, i32 12, !dbg !21 for 0x%I64xth hint within @get_param_set  --> \n", ++aesl_llvm_cbe_86_count);
  llvm_cbe_tmp__39 = (signed int *)(&llvm_cbe_paramset->field12);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 32, i32* %%22, align 4, !dbg !21 for 0x%I64xth hint within @get_param_set  --> \n", ++aesl_llvm_cbe_87_count);
  *llvm_cbe_tmp__39 = 32u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 32u);
  if (((llvm_cbe_tmp__37&255U) == (((unsigned char )1)&255U))) {
    goto llvm_cbe_tmp__45;
  } else {
    goto llvm_cbe_tmp__46;
  }

llvm_cbe_tmp__45:
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = load i32* %%9, align 4, !dbg !21 for 0x%I64xth hint within @get_param_set  --> \n", ++aesl_llvm_cbe_90_count);
  llvm_cbe_tmp__40 = (unsigned int )*llvm_cbe_tmp__26;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__40);
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = add i32 %%25, %%12, !dbg !21 for 0x%I64xth hint within @get_param_set  --> \n", ++aesl_llvm_cbe_91_count);
  llvm_cbe_tmp__41 = (unsigned int )((unsigned int )(llvm_cbe_tmp__40&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__29&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__41&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = getelementptr inbounds %%struct.paramset_t* %%paramset, i64 0, i32 6, !dbg !21 for 0x%I64xth hint within @get_param_set  --> \n", ++aesl_llvm_cbe_92_count);
  llvm_cbe_tmp__42 = (signed int *)(&llvm_cbe_paramset->field6);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%26, i32* %%27, align 4, !dbg !21 for 0x%I64xth hint within @get_param_set  --> \n", ++aesl_llvm_cbe_93_count);
  *llvm_cbe_tmp__42 = llvm_cbe_tmp__41;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__41);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = add i32 %%26, %%14, !dbg !21 for 0x%I64xth hint within @get_param_set  --> \n", ++aesl_llvm_cbe_94_count);
  llvm_cbe_tmp__43 = (unsigned int )((unsigned int )(llvm_cbe_tmp__41&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__31&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__43&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = getelementptr inbounds %%struct.paramset_t* %%paramset, i64 0, i32 7, !dbg !21 for 0x%I64xth hint within @get_param_set  --> \n", ++aesl_llvm_cbe_95_count);
  llvm_cbe_tmp__44 = (signed int *)(&llvm_cbe_paramset->field7);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%28, i32* %%29, align 4, !dbg !21 for 0x%I64xth hint within @get_param_set  --> \n", ++aesl_llvm_cbe_96_count);
  *llvm_cbe_tmp__44 = llvm_cbe_tmp__43;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__43);
  goto llvm_cbe_tmp__46;

llvm_cbe_tmp__46:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @get_param_set}\n");
  return 0u;
}


signed int picnic_keygen( char llvm_cbe_parameters, l_struct_OC_picnic_publickey_t *llvm_cbe_pk, l_struct_OC_picnic_privatekey_t *llvm_cbe_sk) {
  static  unsigned long long aesl_llvm_cbe_paramset_count = 0;
  l_struct_OC_paramset_t llvm_cbe_paramset;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_temp_count = 0;
  signed int llvm_cbe_temp[8];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_temp2_count = 0;
  signed int llvm_cbe_temp2[8];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_temp3_count = 0;
  signed int llvm_cbe_temp3[8];    /* Address-exposed local */
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
  unsigned int llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts_count = 0;
  unsigned int llvm_cbe_puts;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  unsigned int llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
   char *llvm_cbe_tmp__49;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
   char *llvm_cbe_tmp__50;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  signed int *llvm_cbe_tmp__51;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  unsigned int llvm_cbe_tmp__52;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  unsigned long long llvm_cbe_tmp__53;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  unsigned int llvm_cbe_tmp__54;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
   char *llvm_cbe_tmp__55;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
   char *llvm_cbe_tmp__56;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
  unsigned int llvm_cbe_tmp__57;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  unsigned long long llvm_cbe_tmp__58;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;
  unsigned int llvm_cbe_tmp__59;
  static  unsigned long long aesl_llvm_cbe_152_count = 0;
  static  unsigned long long aesl_llvm_cbe_153_count = 0;
  static  unsigned long long aesl_llvm_cbe_154_count = 0;
  static  unsigned long long aesl_llvm_cbe_155_count = 0;
   char *llvm_cbe_tmp__60;
  static  unsigned long long aesl_llvm_cbe_156_count = 0;
   char *llvm_cbe_tmp__61;
  static  unsigned long long aesl_llvm_cbe_157_count = 0;
  static  unsigned long long aesl_llvm_cbe_158_count = 0;
   char *llvm_cbe_tmp__62;
  static  unsigned long long aesl_llvm_cbe_159_count = 0;
   char *llvm_cbe_tmp__63;
  static  unsigned long long aesl_llvm_cbe_160_count = 0;
  static  unsigned long long aesl_llvm_cbe_161_count = 0;
   char *llvm_cbe_tmp__64;
  static  unsigned long long aesl_llvm_cbe_162_count = 0;
   char *llvm_cbe_tmp__65;
  static  unsigned long long aesl_llvm_cbe_163_count = 0;
  static  unsigned long long aesl_llvm_cbe_164_count = 0;
  static  unsigned long long aesl_llvm_cbe_165_count = 0;
  static  unsigned long long aesl_llvm_cbe_166_count = 0;
  static  unsigned long long aesl_llvm_cbe_167_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_191_count = 0;
  static  unsigned long long aesl_llvm_cbe_192_count = 0;
  static  unsigned long long aesl_llvm_cbe_193_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge5_count = 0;
  unsigned int llvm_cbe_storemerge5;
  unsigned int llvm_cbe_storemerge5__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_194_count = 0;
  unsigned long long llvm_cbe_tmp__66;
  static  unsigned long long aesl_llvm_cbe_195_count = 0;
   char *llvm_cbe_tmp__67;
  static  unsigned long long aesl_llvm_cbe_196_count = 0;
  unsigned char llvm_cbe_tmp__68;
  static  unsigned long long aesl_llvm_cbe_197_count = 0;
  unsigned int llvm_cbe_tmp__69;
  static  unsigned long long aesl_llvm_cbe_198_count = 0;
  unsigned int llvm_cbe_tmp__70;
  static  unsigned long long aesl_llvm_cbe_199_count = 0;
  unsigned long long llvm_cbe_tmp__71;
  static  unsigned long long aesl_llvm_cbe_200_count = 0;
   char *llvm_cbe_tmp__72;
  static  unsigned long long aesl_llvm_cbe_201_count = 0;
  unsigned char llvm_cbe_tmp__73;
  static  unsigned long long aesl_llvm_cbe_202_count = 0;
  unsigned int llvm_cbe_tmp__74;
  static  unsigned long long aesl_llvm_cbe_203_count = 0;
  unsigned int llvm_cbe_tmp__75;
  static  unsigned long long aesl_llvm_cbe_204_count = 0;
  unsigned long long llvm_cbe_tmp__76;
  static  unsigned long long aesl_llvm_cbe_205_count = 0;
   char *llvm_cbe_tmp__77;
  static  unsigned long long aesl_llvm_cbe_206_count = 0;
  unsigned char llvm_cbe_tmp__78;
  static  unsigned long long aesl_llvm_cbe_207_count = 0;
  unsigned int llvm_cbe_tmp__79;
  static  unsigned long long aesl_llvm_cbe_208_count = 0;
  unsigned int llvm_cbe_tmp__80;
  static  unsigned long long aesl_llvm_cbe_209_count = 0;
  unsigned long long llvm_cbe_tmp__81;
  static  unsigned long long aesl_llvm_cbe_210_count = 0;
   char *llvm_cbe_tmp__82;
  static  unsigned long long aesl_llvm_cbe_211_count = 0;
  unsigned char llvm_cbe_tmp__83;
  static  unsigned long long aesl_llvm_cbe_212_count = 0;
  unsigned int llvm_cbe_tmp__84;
  static  unsigned long long aesl_llvm_cbe_213_count = 0;
  unsigned int llvm_cbe_tmp__85;
  static  unsigned long long aesl_llvm_cbe_214_count = 0;
  unsigned int llvm_cbe_tmp__86;
  static  unsigned long long aesl_llvm_cbe_215_count = 0;
  unsigned int llvm_cbe_tmp__87;
  static  unsigned long long aesl_llvm_cbe_216_count = 0;
  unsigned int llvm_cbe_tmp__88;
  static  unsigned long long aesl_llvm_cbe_217_count = 0;
  unsigned int llvm_cbe_tmp__89;
  static  unsigned long long aesl_llvm_cbe_218_count = 0;
  unsigned int llvm_cbe_tmp__90;
  static  unsigned long long aesl_llvm_cbe_219_count = 0;
  unsigned int llvm_cbe_tmp__91;
  static  unsigned long long aesl_llvm_cbe_220_count = 0;
  unsigned long long llvm_cbe_tmp__92;
  static  unsigned long long aesl_llvm_cbe_221_count = 0;
  signed int *llvm_cbe_tmp__93;
  static  unsigned long long aesl_llvm_cbe_222_count = 0;
  static  unsigned long long aesl_llvm_cbe_223_count = 0;
   char *llvm_cbe_tmp__94;
  static  unsigned long long aesl_llvm_cbe_224_count = 0;
  unsigned char llvm_cbe_tmp__95;
  static  unsigned long long aesl_llvm_cbe_225_count = 0;
  unsigned int llvm_cbe_tmp__96;
  static  unsigned long long aesl_llvm_cbe_226_count = 0;
   char *llvm_cbe_tmp__97;
  static  unsigned long long aesl_llvm_cbe_227_count = 0;
  unsigned char llvm_cbe_tmp__98;
  static  unsigned long long aesl_llvm_cbe_228_count = 0;
  unsigned int llvm_cbe_tmp__99;
  static  unsigned long long aesl_llvm_cbe_229_count = 0;
   char *llvm_cbe_tmp__100;
  static  unsigned long long aesl_llvm_cbe_230_count = 0;
  unsigned char llvm_cbe_tmp__101;
  static  unsigned long long aesl_llvm_cbe_231_count = 0;
  unsigned int llvm_cbe_tmp__102;
  static  unsigned long long aesl_llvm_cbe_232_count = 0;
   char *llvm_cbe_tmp__103;
  static  unsigned long long aesl_llvm_cbe_233_count = 0;
  unsigned char llvm_cbe_tmp__104;
  static  unsigned long long aesl_llvm_cbe_234_count = 0;
  unsigned int llvm_cbe_tmp__105;
  static  unsigned long long aesl_llvm_cbe_235_count = 0;
  unsigned int llvm_cbe_tmp__106;
  static  unsigned long long aesl_llvm_cbe_236_count = 0;
  unsigned int llvm_cbe_tmp__107;
  static  unsigned long long aesl_llvm_cbe_237_count = 0;
  unsigned int llvm_cbe_tmp__108;
  static  unsigned long long aesl_llvm_cbe_238_count = 0;
  unsigned int llvm_cbe_tmp__109;
  static  unsigned long long aesl_llvm_cbe_239_count = 0;
  unsigned int llvm_cbe_tmp__110;
  static  unsigned long long aesl_llvm_cbe_240_count = 0;
  unsigned int llvm_cbe_tmp__111;
  static  unsigned long long aesl_llvm_cbe_241_count = 0;
  signed int *llvm_cbe_tmp__112;
  static  unsigned long long aesl_llvm_cbe_242_count = 0;
  static  unsigned long long aesl_llvm_cbe_243_count = 0;
   char *llvm_cbe_tmp__113;
  static  unsigned long long aesl_llvm_cbe_244_count = 0;
  unsigned char llvm_cbe_tmp__114;
  static  unsigned long long aesl_llvm_cbe_245_count = 0;
  unsigned int llvm_cbe_tmp__115;
  static  unsigned long long aesl_llvm_cbe_246_count = 0;
   char *llvm_cbe_tmp__116;
  static  unsigned long long aesl_llvm_cbe_247_count = 0;
  unsigned char llvm_cbe_tmp__117;
  static  unsigned long long aesl_llvm_cbe_248_count = 0;
  unsigned int llvm_cbe_tmp__118;
  static  unsigned long long aesl_llvm_cbe_249_count = 0;
   char *llvm_cbe_tmp__119;
  static  unsigned long long aesl_llvm_cbe_250_count = 0;
  unsigned char llvm_cbe_tmp__120;
  static  unsigned long long aesl_llvm_cbe_251_count = 0;
  unsigned int llvm_cbe_tmp__121;
  static  unsigned long long aesl_llvm_cbe_252_count = 0;
   char *llvm_cbe_tmp__122;
  static  unsigned long long aesl_llvm_cbe_253_count = 0;
  unsigned char llvm_cbe_tmp__123;
  static  unsigned long long aesl_llvm_cbe_254_count = 0;
  unsigned int llvm_cbe_tmp__124;
  static  unsigned long long aesl_llvm_cbe_255_count = 0;
  unsigned int llvm_cbe_tmp__125;
  static  unsigned long long aesl_llvm_cbe_256_count = 0;
  unsigned int llvm_cbe_tmp__126;
  static  unsigned long long aesl_llvm_cbe_257_count = 0;
  unsigned int llvm_cbe_tmp__127;
  static  unsigned long long aesl_llvm_cbe_258_count = 0;
  unsigned int llvm_cbe_tmp__128;
  static  unsigned long long aesl_llvm_cbe_259_count = 0;
  unsigned int llvm_cbe_tmp__129;
  static  unsigned long long aesl_llvm_cbe_260_count = 0;
  unsigned int llvm_cbe_tmp__130;
  static  unsigned long long aesl_llvm_cbe_261_count = 0;
  signed int *llvm_cbe_tmp__131;
  static  unsigned long long aesl_llvm_cbe_262_count = 0;
  static  unsigned long long aesl_llvm_cbe_263_count = 0;
  unsigned int llvm_cbe_tmp__132;
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
  static  unsigned long long aesl_llvm_cbe_285_count = 0;
  static  unsigned long long aesl_llvm_cbe_286_count = 0;
  static  unsigned long long aesl_llvm_cbe_287_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_299_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_312_count = 0;
  static  unsigned long long aesl_llvm_cbe_313_count = 0;
  static  unsigned long long aesl_llvm_cbe_314_count = 0;
  static  unsigned long long aesl_llvm_cbe_315_count = 0;
  static  unsigned long long aesl_llvm_cbe_316_count = 0;
  static  unsigned long long aesl_llvm_cbe_317_count = 0;
  static  unsigned long long aesl_llvm_cbe_318_count = 0;
  static  unsigned long long aesl_llvm_cbe_319_count = 0;
  static  unsigned long long aesl_llvm_cbe_320_count = 0;
  static  unsigned long long aesl_llvm_cbe_321_count = 0;
  static  unsigned long long aesl_llvm_cbe_322_count = 0;
  static  unsigned long long aesl_llvm_cbe_323_count = 0;
  static  unsigned long long aesl_llvm_cbe_324_count = 0;
  static  unsigned long long aesl_llvm_cbe_325_count = 0;
  static  unsigned long long aesl_llvm_cbe_326_count = 0;
  signed int *llvm_cbe_tmp__133;
  static  unsigned long long aesl_llvm_cbe_327_count = 0;
  signed int *llvm_cbe_tmp__134;
  static  unsigned long long aesl_llvm_cbe_328_count = 0;
  signed int *llvm_cbe_tmp__135;
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
  static  unsigned long long aesl_llvm_cbe_354_count = 0;
  static  unsigned long long aesl_llvm_cbe_355_count = 0;
  static  unsigned long long aesl_llvm_cbe_356_count = 0;
  static  unsigned long long aesl_llvm_cbe_357_count = 0;
  static  unsigned long long aesl_llvm_cbe_358_count = 0;
  static  unsigned long long aesl_llvm_cbe_359_count = 0;
  static  unsigned long long aesl_llvm_cbe_360_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge14_count = 0;
  unsigned int llvm_cbe_storemerge14;
  unsigned int llvm_cbe_storemerge14__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_361_count = 0;
  unsigned int llvm_cbe_tmp__136;
  static  unsigned long long aesl_llvm_cbe_362_count = 0;
  unsigned long long llvm_cbe_tmp__137;
  static  unsigned long long aesl_llvm_cbe_363_count = 0;
  signed int *llvm_cbe_tmp__138;
  static  unsigned long long aesl_llvm_cbe_364_count = 0;
  unsigned int llvm_cbe_tmp__139;
  static  unsigned long long aesl_llvm_cbe_365_count = 0;
  unsigned char llvm_cbe_tmp__140;
  static  unsigned long long aesl_llvm_cbe_366_count = 0;
  unsigned long long llvm_cbe_tmp__141;
  static  unsigned long long aesl_llvm_cbe_367_count = 0;
   char *llvm_cbe_tmp__142;
  static  unsigned long long aesl_llvm_cbe_368_count = 0;
  static  unsigned long long aesl_llvm_cbe_369_count = 0;
  unsigned int llvm_cbe_tmp__143;
  static  unsigned long long aesl_llvm_cbe_370_count = 0;
  static  unsigned long long aesl_llvm_cbe_371_count = 0;
  unsigned int llvm_cbe_tmp__144;
  static  unsigned long long aesl_llvm_cbe_372_count = 0;
  static  unsigned long long aesl_llvm_cbe_373_count = 0;
  static  unsigned long long aesl_llvm_cbe_374_count = 0;
  static  unsigned long long aesl_llvm_cbe_375_count = 0;
  static  unsigned long long aesl_llvm_cbe_376_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_388_count = 0;
  static  unsigned long long aesl_llvm_cbe_389_count = 0;
  static  unsigned long long aesl_llvm_cbe_390_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_exitcond6_count = 0;
  static  unsigned long long aesl_llvm_cbe_402_count = 0;
  static  unsigned long long aesl_llvm_cbe_403_count = 0;
  unsigned char llvm_cbe_tmp__145;
  static  unsigned long long aesl_llvm_cbe_404_count = 0;
   char *llvm_cbe_tmp__146;
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
  static  unsigned long long aesl_llvm_cbe_storemerge23_count = 0;
  unsigned int llvm_cbe_storemerge23;
  unsigned int llvm_cbe_storemerge23__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_437_count = 0;
  unsigned long long llvm_cbe_tmp__147;
  static  unsigned long long aesl_llvm_cbe_438_count = 0;
   char *llvm_cbe_tmp__148;
  static  unsigned long long aesl_llvm_cbe_439_count = 0;
  unsigned char llvm_cbe_tmp__149;
  static  unsigned long long aesl_llvm_cbe_440_count = 0;
   char *llvm_cbe_tmp__150;
  static  unsigned long long aesl_llvm_cbe_441_count = 0;
  static  unsigned long long aesl_llvm_cbe_442_count = 0;
   char *llvm_cbe_tmp__151;
  static  unsigned long long aesl_llvm_cbe_443_count = 0;
  unsigned char llvm_cbe_tmp__152;
  static  unsigned long long aesl_llvm_cbe_444_count = 0;
   char *llvm_cbe_tmp__153;
  static  unsigned long long aesl_llvm_cbe_445_count = 0;
  static  unsigned long long aesl_llvm_cbe_446_count = 0;
  unsigned int llvm_cbe_tmp__154;
  static  unsigned long long aesl_llvm_cbe_447_count = 0;
  static  unsigned long long aesl_llvm_cbe_448_count = 0;
  static  unsigned long long aesl_llvm_cbe_449_count = 0;
  static  unsigned long long aesl_llvm_cbe_450_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_469_count = 0;
  static  unsigned long long aesl_llvm_cbe_470_count = 0;
  static  unsigned long long aesl_llvm_cbe_471_count = 0;
  static  unsigned long long aesl_llvm_cbe_472_count = 0;
  static  unsigned long long aesl_llvm_cbe_473_count = 0;
  static  unsigned long long aesl_llvm_cbe_474_count = 0;
  static  unsigned long long aesl_llvm_cbe_475_count = 0;
  static  unsigned long long aesl_llvm_cbe_476_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_477_count = 0;
  static  unsigned long long aesl_llvm_cbe_478_count = 0;
  unsigned int llvm_cbe_tmp__155;
  unsigned int llvm_cbe_tmp__155__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_479_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @picnic_keygen\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = call fastcc i32 @aesl_internal_is_valid_params(i4 zeroext %%parameters), !dbg !19 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_129_count);
  llvm_cbe_tmp__47 = (unsigned int )aesl_internal_is_valid_params(llvm_cbe_parameters);
if (AESL_DEBUG_TRACE) {
printf("\nArgument parameters = 0x%X",llvm_cbe_parameters);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__47);
}
  if (((llvm_cbe_tmp__47&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__156;
  } else {
    goto llvm_cbe_tmp__157;
  }

llvm_cbe_tmp__156:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts = call i32 @puts(i8* getelementptr inbounds ([22 x i8]* @aesl_internal_str1, i64 0, i64 0)), !dbg !22 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_puts_count);
  puts(( char *)((&aesl_internal_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 22
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts = 0x%X",llvm_cbe_puts);
}
  llvm_cbe_tmp__155__PHI_TEMPORARY = (unsigned int )4294967295u;   /* for PHI node */
  goto llvm_cbe__2e_loopexit;

llvm_cbe_tmp__157:
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = call i32 @get_param_set(i4 zeroext %%parameters, %%struct.paramset_t* %%paramset), !dbg !19 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_134_count);
  get_param_set(llvm_cbe_parameters, (l_struct_OC_paramset_t *)(&llvm_cbe_paramset));
if (AESL_DEBUG_TRACE) {
printf("\nArgument parameters = 0x%X",llvm_cbe_parameters);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__48);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds %%struct.picnic_privatekey_t* %%sk, i64 0, i32 0, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_137_count);
  llvm_cbe_tmp__49 = ( char *)(&llvm_cbe_sk->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i4 %%parameters, i4* %%6, align 1, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_138_count);
  *llvm_cbe_tmp__49 = ((llvm_cbe_parameters) & 15ull);
if (AESL_DEBUG_TRACE)
printf("\nparameters = 0x%X\n", llvm_cbe_parameters);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds %%struct.picnic_privatekey_t* %%sk, i64 0, i32 1, i64 0, !dbg !21 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_139_count);
  llvm_cbe_tmp__50 = ( char *)(&llvm_cbe_sk->field1[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds %%struct.paramset_t* %%paramset, i64 0, i32 3, !dbg !21 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_140_count);
  llvm_cbe_tmp__51 = (signed int *)(&llvm_cbe_paramset.field3);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = load i32* %%8, align 4, !dbg !21 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_141_count);
  llvm_cbe_tmp__52 = (unsigned int )*llvm_cbe_tmp__51;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__52);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = zext i32 %%9 to i64, !dbg !21 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_142_count);
  llvm_cbe_tmp__53 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__52&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__53);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = call i32 @randombytes(i8* %%7, i64 %%10) nounwind, !dbg !21 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_143_count);
  llvm_cbe_tmp__54 = (unsigned int )randombytes(( char *)llvm_cbe_tmp__50, llvm_cbe_tmp__53);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__53);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__54);
}
  if (((llvm_cbe_tmp__54&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__158;
  } else {
    llvm_cbe_tmp__155__PHI_TEMPORARY = (unsigned int )4294967295u;   /* for PHI node */
    goto llvm_cbe__2e_loopexit;
  }

llvm_cbe_tmp__158:
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds %%struct.picnic_publickey_t* %%pk, i64 0, i32 0, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_146_count);
  llvm_cbe_tmp__55 = ( char *)(&llvm_cbe_pk->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i4 %%parameters, i4* %%14, align 1, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_147_count);
  *llvm_cbe_tmp__55 = ((llvm_cbe_parameters) & 15ull);
if (AESL_DEBUG_TRACE)
printf("\nparameters = 0x%X\n", llvm_cbe_parameters);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds %%struct.picnic_publickey_t* %%pk, i64 0, i32 1, i64 0, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_148_count);
  llvm_cbe_tmp__56 = ( char *)(&llvm_cbe_pk->field1[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = load i32* %%8, align 4, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_149_count);
  llvm_cbe_tmp__57 = (unsigned int )*llvm_cbe_tmp__51;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__57);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = zext i32 %%16 to i64, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_150_count);
  llvm_cbe_tmp__58 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__57&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__58);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = call i32 @randombytes(i8* %%15, i64 %%17) nounwind, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_151_count);
  llvm_cbe_tmp__59 = (unsigned int )randombytes(( char *)llvm_cbe_tmp__56, llvm_cbe_tmp__58);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__58);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__59);
}
  if (((llvm_cbe_tmp__59&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__159;
  } else {
    llvm_cbe_tmp__155__PHI_TEMPORARY = (unsigned int )4294967295u;   /* for PHI node */
    goto llvm_cbe__2e_loopexit;
  }

llvm_cbe_tmp__159:
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = bitcast [8 x i32]* %%temp to i8*, !dbg !23 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_155_count);
  llvm_cbe_tmp__60 = ( char *)(( char *)(&llvm_cbe_temp));
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = call i8* @memset(i8* %%21, i32 0, i64 32 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_156_count);
  ( char *)memset(( char *)llvm_cbe_tmp__60, 0u, 32ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",32ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__61);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = bitcast [8 x i32]* %%temp2 to i8*, !dbg !23 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_158_count);
  llvm_cbe_tmp__62 = ( char *)(( char *)(&llvm_cbe_temp2));
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = call i8* @memset(i8* %%23, i32 0, i64 32 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_159_count);
  ( char *)memset(( char *)llvm_cbe_tmp__62, 0u, 32ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",32ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__63);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = bitcast [8 x i32]* %%temp3 to i8*, !dbg !23 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_161_count);
  llvm_cbe_tmp__64 = ( char *)(( char *)(&llvm_cbe_temp3));
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = call i8* @memset(i8* %%25, i32 0, i64 32 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_162_count);
  ( char *)memset(( char *)llvm_cbe_tmp__64, 0u, 32ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",32ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__65);
}
  llvm_cbe_storemerge5__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__160;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__160:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge5 = phi i32 [ 0, %%20 ], [ %%94, %%27  for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_storemerge5_count);
  llvm_cbe_storemerge5 = (unsigned int )llvm_cbe_storemerge5__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge5 = 0x%X",llvm_cbe_storemerge5);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__132);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = sext i32 %%storemerge5 to i64, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_194_count);
  llvm_cbe_tmp__66 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge5);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__66);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = getelementptr inbounds %%struct.picnic_publickey_t* %%pk, i64 0, i32 2, i64 %%28, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_195_count);
  llvm_cbe_tmp__67 = ( char *)(&llvm_cbe_pk->field2[(((signed long long )llvm_cbe_tmp__66))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__66));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = load i8* %%29, align 1, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_196_count);
  llvm_cbe_tmp__68 = (unsigned char )*llvm_cbe_tmp__67;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__68);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = zext i8 %%30 to i32, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_197_count);
  llvm_cbe_tmp__69 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__68&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__69);
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = or i32 %%storemerge5, 1, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_198_count);
  llvm_cbe_tmp__70 = (unsigned int )llvm_cbe_storemerge5 | 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__70);
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = sext i32 %%32 to i64, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_199_count);
  llvm_cbe_tmp__71 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__70);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__71);
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = getelementptr inbounds %%struct.picnic_publickey_t* %%pk, i64 0, i32 2, i64 %%33, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_200_count);
  llvm_cbe_tmp__72 = ( char *)(&llvm_cbe_pk->field2[(((signed long long )llvm_cbe_tmp__71))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__71));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = load i8* %%34, align 1, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_201_count);
  llvm_cbe_tmp__73 = (unsigned char )*llvm_cbe_tmp__72;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__73);
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = zext i8 %%35 to i32, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_202_count);
  llvm_cbe_tmp__74 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__73&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__74);
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = or i32 %%storemerge5, 2, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_203_count);
  llvm_cbe_tmp__75 = (unsigned int )llvm_cbe_storemerge5 | 2u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__75);
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = sext i32 %%37 to i64, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_204_count);
  llvm_cbe_tmp__76 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__75);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__76);
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = getelementptr inbounds %%struct.picnic_publickey_t* %%pk, i64 0, i32 2, i64 %%38, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_205_count);
  llvm_cbe_tmp__77 = ( char *)(&llvm_cbe_pk->field2[(((signed long long )llvm_cbe_tmp__76))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__76));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = load i8* %%39, align 1, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_206_count);
  llvm_cbe_tmp__78 = (unsigned char )*llvm_cbe_tmp__77;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__78);
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = zext i8 %%40 to i32, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_207_count);
  llvm_cbe_tmp__79 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__78&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__79);
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = or i32 %%storemerge5, 3, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_208_count);
  llvm_cbe_tmp__80 = (unsigned int )llvm_cbe_storemerge5 | 3u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__80);
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = sext i32 %%42 to i64, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_209_count);
  llvm_cbe_tmp__81 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__80);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__81);
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = getelementptr inbounds %%struct.picnic_publickey_t* %%pk, i64 0, i32 2, i64 %%43, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_210_count);
  llvm_cbe_tmp__82 = ( char *)(&llvm_cbe_pk->field2[(((signed long long )llvm_cbe_tmp__81))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__81));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = load i8* %%44, align 1, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_211_count);
  llvm_cbe_tmp__83 = (unsigned char )*llvm_cbe_tmp__82;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__83);
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = zext i8 %%45 to i32, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_212_count);
  llvm_cbe_tmp__84 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__83&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__84);
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = shl nuw nsw i32 %%46, 8, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_213_count);
  llvm_cbe_tmp__85 = (unsigned int )llvm_cbe_tmp__84 << 8u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__85);
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = or i32 %%47, %%41, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_214_count);
  llvm_cbe_tmp__86 = (unsigned int )llvm_cbe_tmp__85 | llvm_cbe_tmp__79;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__86);
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = shl nuw nsw i32 %%48, 8, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_215_count);
  llvm_cbe_tmp__87 = (unsigned int )llvm_cbe_tmp__86 << 8u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__87);
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = or i32 %%49, %%36, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_216_count);
  llvm_cbe_tmp__88 = (unsigned int )llvm_cbe_tmp__87 | llvm_cbe_tmp__74;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__88);
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = shl nuw nsw i32 %%50, 8, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_217_count);
  llvm_cbe_tmp__89 = (unsigned int )llvm_cbe_tmp__88 << 8u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__89);
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = or i32 %%51, %%31, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_218_count);
  llvm_cbe_tmp__90 = (unsigned int )llvm_cbe_tmp__89 | llvm_cbe_tmp__69;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__90);
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = sdiv i32 %%storemerge5, 4, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_219_count);
  llvm_cbe_tmp__91 = (unsigned int )((signed int )(((signed int )llvm_cbe_storemerge5) / ((signed int )4u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__91));
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = sext i32 %%53 to i64, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_220_count);
  llvm_cbe_tmp__92 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__91);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__92);
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = getelementptr inbounds [8 x i32]* %%temp, i64 0, i64 %%54, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_221_count);
  llvm_cbe_tmp__93 = (signed int *)(&llvm_cbe_temp[(((signed long long )llvm_cbe_tmp__92))
#ifdef AESL_BC_SIM
 % 8
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__92));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__92) < 8 && "Write access out of array 'temp' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%52, i32* %%55, align 4, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_222_count);
  *llvm_cbe_tmp__93 = llvm_cbe_tmp__90;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__90);
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = getelementptr inbounds %%struct.picnic_publickey_t* %%pk, i64 0, i32 1, i64 %%28, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_223_count);
  llvm_cbe_tmp__94 = ( char *)(&llvm_cbe_pk->field1[(((signed long long )llvm_cbe_tmp__66))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__66));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = load i8* %%56, align 1, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_224_count);
  llvm_cbe_tmp__95 = (unsigned char )*llvm_cbe_tmp__94;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__95);
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = zext i8 %%57 to i32, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_225_count);
  llvm_cbe_tmp__96 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__95&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__96);
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = getelementptr inbounds %%struct.picnic_publickey_t* %%pk, i64 0, i32 1, i64 %%33, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_226_count);
  llvm_cbe_tmp__97 = ( char *)(&llvm_cbe_pk->field1[(((signed long long )llvm_cbe_tmp__71))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__71));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = load i8* %%59, align 1, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_227_count);
  llvm_cbe_tmp__98 = (unsigned char )*llvm_cbe_tmp__97;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__98);
if (AESL_DEBUG_TRACE)
printf("\n  %%61 = zext i8 %%60 to i32, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_228_count);
  llvm_cbe_tmp__99 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__98&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__99);
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = getelementptr inbounds %%struct.picnic_publickey_t* %%pk, i64 0, i32 1, i64 %%38, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_229_count);
  llvm_cbe_tmp__100 = ( char *)(&llvm_cbe_pk->field1[(((signed long long )llvm_cbe_tmp__76))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__76));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = load i8* %%62, align 1, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_230_count);
  llvm_cbe_tmp__101 = (unsigned char )*llvm_cbe_tmp__100;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__101);
if (AESL_DEBUG_TRACE)
printf("\n  %%64 = zext i8 %%63 to i32, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_231_count);
  llvm_cbe_tmp__102 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__101&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__102);
if (AESL_DEBUG_TRACE)
printf("\n  %%65 = getelementptr inbounds %%struct.picnic_publickey_t* %%pk, i64 0, i32 1, i64 %%43, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_232_count);
  llvm_cbe_tmp__103 = ( char *)(&llvm_cbe_pk->field1[(((signed long long )llvm_cbe_tmp__81))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__81));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%66 = load i8* %%65, align 1, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_233_count);
  llvm_cbe_tmp__104 = (unsigned char )*llvm_cbe_tmp__103;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__104);
if (AESL_DEBUG_TRACE)
printf("\n  %%67 = zext i8 %%66 to i32, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_234_count);
  llvm_cbe_tmp__105 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__104&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__105);
if (AESL_DEBUG_TRACE)
printf("\n  %%68 = shl nuw nsw i32 %%67, 8, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_235_count);
  llvm_cbe_tmp__106 = (unsigned int )llvm_cbe_tmp__105 << 8u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__106);
if (AESL_DEBUG_TRACE)
printf("\n  %%69 = or i32 %%68, %%64, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_236_count);
  llvm_cbe_tmp__107 = (unsigned int )llvm_cbe_tmp__106 | llvm_cbe_tmp__102;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__107);
if (AESL_DEBUG_TRACE)
printf("\n  %%70 = shl nuw nsw i32 %%69, 8, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_237_count);
  llvm_cbe_tmp__108 = (unsigned int )llvm_cbe_tmp__107 << 8u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__108);
if (AESL_DEBUG_TRACE)
printf("\n  %%71 = or i32 %%70, %%61, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_238_count);
  llvm_cbe_tmp__109 = (unsigned int )llvm_cbe_tmp__108 | llvm_cbe_tmp__99;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__109);
if (AESL_DEBUG_TRACE)
printf("\n  %%72 = shl nuw nsw i32 %%71, 8, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_239_count);
  llvm_cbe_tmp__110 = (unsigned int )llvm_cbe_tmp__109 << 8u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__110);
if (AESL_DEBUG_TRACE)
printf("\n  %%73 = or i32 %%72, %%58, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_240_count);
  llvm_cbe_tmp__111 = (unsigned int )llvm_cbe_tmp__110 | llvm_cbe_tmp__96;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__111);
if (AESL_DEBUG_TRACE)
printf("\n  %%74 = getelementptr inbounds [8 x i32]* %%temp2, i64 0, i64 %%54, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_241_count);
  llvm_cbe_tmp__112 = (signed int *)(&llvm_cbe_temp2[(((signed long long )llvm_cbe_tmp__92))
#ifdef AESL_BC_SIM
 % 8
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__92));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__92) < 8 && "Write access out of array 'temp2' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%73, i32* %%74, align 4, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_242_count);
  *llvm_cbe_tmp__112 = llvm_cbe_tmp__111;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__111);
if (AESL_DEBUG_TRACE)
printf("\n  %%75 = getelementptr inbounds %%struct.picnic_privatekey_t* %%sk, i64 0, i32 1, i64 %%28, !dbg !22 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_243_count);
  llvm_cbe_tmp__113 = ( char *)(&llvm_cbe_sk->field1[(((signed long long )llvm_cbe_tmp__66))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__66));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%76 = load i8* %%75, align 1, !dbg !22 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_244_count);
  llvm_cbe_tmp__114 = (unsigned char )*llvm_cbe_tmp__113;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__114);
if (AESL_DEBUG_TRACE)
printf("\n  %%77 = zext i8 %%76 to i32, !dbg !22 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_245_count);
  llvm_cbe_tmp__115 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__114&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__115);
if (AESL_DEBUG_TRACE)
printf("\n  %%78 = getelementptr inbounds %%struct.picnic_privatekey_t* %%sk, i64 0, i32 1, i64 %%33, !dbg !22 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_246_count);
  llvm_cbe_tmp__116 = ( char *)(&llvm_cbe_sk->field1[(((signed long long )llvm_cbe_tmp__71))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__71));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%79 = load i8* %%78, align 1, !dbg !22 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_247_count);
  llvm_cbe_tmp__117 = (unsigned char )*llvm_cbe_tmp__116;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__117);
if (AESL_DEBUG_TRACE)
printf("\n  %%80 = zext i8 %%79 to i32, !dbg !22 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_248_count);
  llvm_cbe_tmp__118 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__117&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__118);
if (AESL_DEBUG_TRACE)
printf("\n  %%81 = getelementptr inbounds %%struct.picnic_privatekey_t* %%sk, i64 0, i32 1, i64 %%38, !dbg !22 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_249_count);
  llvm_cbe_tmp__119 = ( char *)(&llvm_cbe_sk->field1[(((signed long long )llvm_cbe_tmp__76))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__76));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%82 = load i8* %%81, align 1, !dbg !22 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_250_count);
  llvm_cbe_tmp__120 = (unsigned char )*llvm_cbe_tmp__119;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__120);
if (AESL_DEBUG_TRACE)
printf("\n  %%83 = zext i8 %%82 to i32, !dbg !22 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_251_count);
  llvm_cbe_tmp__121 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__120&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__121);
if (AESL_DEBUG_TRACE)
printf("\n  %%84 = getelementptr inbounds %%struct.picnic_privatekey_t* %%sk, i64 0, i32 1, i64 %%43, !dbg !22 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_252_count);
  llvm_cbe_tmp__122 = ( char *)(&llvm_cbe_sk->field1[(((signed long long )llvm_cbe_tmp__81))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__81));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%85 = load i8* %%84, align 1, !dbg !22 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_253_count);
  llvm_cbe_tmp__123 = (unsigned char )*llvm_cbe_tmp__122;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__123);
if (AESL_DEBUG_TRACE)
printf("\n  %%86 = zext i8 %%85 to i32, !dbg !22 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_254_count);
  llvm_cbe_tmp__124 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__123&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__124);
if (AESL_DEBUG_TRACE)
printf("\n  %%87 = shl nuw nsw i32 %%86, 8, !dbg !22 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_255_count);
  llvm_cbe_tmp__125 = (unsigned int )llvm_cbe_tmp__124 << 8u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__125);
if (AESL_DEBUG_TRACE)
printf("\n  %%88 = or i32 %%87, %%83, !dbg !22 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_256_count);
  llvm_cbe_tmp__126 = (unsigned int )llvm_cbe_tmp__125 | llvm_cbe_tmp__121;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__126);
if (AESL_DEBUG_TRACE)
printf("\n  %%89 = shl nuw nsw i32 %%88, 8, !dbg !22 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_257_count);
  llvm_cbe_tmp__127 = (unsigned int )llvm_cbe_tmp__126 << 8u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__127);
if (AESL_DEBUG_TRACE)
printf("\n  %%90 = or i32 %%89, %%80, !dbg !22 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_258_count);
  llvm_cbe_tmp__128 = (unsigned int )llvm_cbe_tmp__127 | llvm_cbe_tmp__118;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__128);
if (AESL_DEBUG_TRACE)
printf("\n  %%91 = shl nuw nsw i32 %%90, 8, !dbg !22 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_259_count);
  llvm_cbe_tmp__129 = (unsigned int )llvm_cbe_tmp__128 << 8u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__129);
if (AESL_DEBUG_TRACE)
printf("\n  %%92 = or i32 %%91, %%77, !dbg !22 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_260_count);
  llvm_cbe_tmp__130 = (unsigned int )llvm_cbe_tmp__129 | llvm_cbe_tmp__115;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__130);
if (AESL_DEBUG_TRACE)
printf("\n  %%93 = getelementptr inbounds [8 x i32]* %%temp3, i64 0, i64 %%54, !dbg !22 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_261_count);
  llvm_cbe_tmp__131 = (signed int *)(&llvm_cbe_temp3[(((signed long long )llvm_cbe_tmp__92))
#ifdef AESL_BC_SIM
 % 8
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__92));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__92) < 8 && "Write access out of array 'temp3' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%92, i32* %%93, align 4, !dbg !22 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_262_count);
  *llvm_cbe_tmp__131 = llvm_cbe_tmp__130;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__130);
if (AESL_DEBUG_TRACE)
printf("\n  %%94 = add nsw i32 %%storemerge5, 4, !dbg !24 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_263_count);
  llvm_cbe_tmp__132 = (unsigned int )((unsigned int )(llvm_cbe_storemerge5&4294967295ull)) + ((unsigned int )(4u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__132&4294967295ull)));
  if ((((signed int )llvm_cbe_tmp__132) < ((signed int )32u))) {
    llvm_cbe_storemerge5__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__132;   /* for PHI node */
    goto llvm_cbe_tmp__160;
  } else {
    goto llvm_cbe_tmp__161;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__161:
if (AESL_DEBUG_TRACE)
printf("\n  %%97 = getelementptr inbounds [8 x i32]* %%temp2, i64 0, i64 0, !dbg !24 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_326_count);
  llvm_cbe_tmp__133 = (signed int *)(&llvm_cbe_temp2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%98 = getelementptr inbounds [8 x i32]* %%temp, i64 0, i64 0, !dbg !24 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_327_count);
  llvm_cbe_tmp__134 = (signed int *)(&llvm_cbe_temp[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%99 = getelementptr inbounds [8 x i32]* %%temp3, i64 0, i64 0, !dbg !24 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_328_count);
  llvm_cbe_tmp__135 = (signed int *)(&llvm_cbe_temp3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @LowMCEnc(i32* %%97, i32* %%98, i32* %%99, %%struct.paramset_t* %%paramset) nounwind, !dbg !24 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_329_count);
  LowMCEnc((signed int *)llvm_cbe_tmp__133, (signed int *)llvm_cbe_tmp__134, (signed int *)llvm_cbe_tmp__135, (l_struct_OC_paramset_t *)(&llvm_cbe_paramset));
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge14__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__162;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__162:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge14 = phi i32 [ 0, %%96 ], [ %%109, %%100  for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_storemerge14_count);
  llvm_cbe_storemerge14 = (unsigned int )llvm_cbe_storemerge14__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge14 = 0x%X",llvm_cbe_storemerge14);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__144);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%101 = sdiv i32 %%storemerge14, 4, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_361_count);
  llvm_cbe_tmp__136 = (unsigned int )((signed int )(((signed int )llvm_cbe_storemerge14) / ((signed int )4u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__136));
if (AESL_DEBUG_TRACE)
printf("\n  %%102 = sext i32 %%101 to i64, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_362_count);
  llvm_cbe_tmp__137 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__136);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__137);
if (AESL_DEBUG_TRACE)
printf("\n  %%103 = getelementptr inbounds [8 x i32]* %%temp, i64 0, i64 %%102, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_363_count);
  llvm_cbe_tmp__138 = (signed int *)(&llvm_cbe_temp[(((signed long long )llvm_cbe_tmp__137))
#ifdef AESL_BC_SIM
 % 8
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__137));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__137) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'temp' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%104 = load i32* %%103, align 4, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_364_count);
  llvm_cbe_tmp__139 = (unsigned int )*llvm_cbe_tmp__138;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__139);
if (AESL_DEBUG_TRACE)
printf("\n  %%105 = trunc i32 %%104 to i8, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_365_count);
  llvm_cbe_tmp__140 = (unsigned char )((unsigned char )llvm_cbe_tmp__139&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__140);
if (AESL_DEBUG_TRACE)
printf("\n  %%106 = sext i32 %%storemerge14 to i64, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_366_count);
  llvm_cbe_tmp__141 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge14);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__141);
if (AESL_DEBUG_TRACE)
printf("\n  %%107 = getelementptr inbounds %%struct.picnic_publickey_t* %%pk, i64 0, i32 2, i64 %%106, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_367_count);
  llvm_cbe_tmp__142 = ( char *)(&llvm_cbe_pk->field2[(((signed long long )llvm_cbe_tmp__141))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__141));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%105, i8* %%107, align 1, !dbg !20 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_368_count);
  *llvm_cbe_tmp__142 = llvm_cbe_tmp__140;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__140);
if (AESL_DEBUG_TRACE)
printf("\n  %%108 = lshr i32 %%104, 8, !dbg !24 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_369_count);
  llvm_cbe_tmp__143 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__139&4294967295ull)) >> ((unsigned int )(8u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__143&4294967295ull)));

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__137) < 8 && "Write access out of array 'temp' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%108, i32* %%103, align 4, !dbg !24 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_370_count);
  *llvm_cbe_tmp__138 = llvm_cbe_tmp__143;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__143);
if (AESL_DEBUG_TRACE)
printf("\n  %%109 = add nsw i32 %%storemerge14, 1, !dbg !24 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_371_count);
  llvm_cbe_tmp__144 = (unsigned int )((unsigned int )(llvm_cbe_storemerge14&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__144&4294967295ull)));
  if (((llvm_cbe_tmp__144&4294967295U) == (32u&4294967295U))) {
    goto llvm_cbe_tmp__163;
  } else {
    llvm_cbe_storemerge14__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__144;   /* for PHI node */
    goto llvm_cbe_tmp__162;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__163:
if (AESL_DEBUG_TRACE)
printf("\n  %%111 = load i4* %%14, align 1, !dbg !21 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_403_count);
  llvm_cbe_tmp__145 = (unsigned char )*llvm_cbe_tmp__55;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__145);
if (AESL_DEBUG_TRACE)
printf("\n  %%112 = getelementptr inbounds %%struct.picnic_privatekey_t* %%sk, i64 0, i32 2, i32 0, !dbg !21 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_404_count);
  llvm_cbe_tmp__146 = ( char *)(&llvm_cbe_sk->field2.field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i4 %%111, i4* %%112, align 1, !dbg !21 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_405_count);
  *llvm_cbe_tmp__146 = ((llvm_cbe_tmp__145) & 15ull);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__145);
  llvm_cbe_storemerge23__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__164;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__164:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge23 = phi i32 [ 0, %%110 ], [ %%121, %%113  for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_storemerge23_count);
  llvm_cbe_storemerge23 = (unsigned int )llvm_cbe_storemerge23__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge23 = 0x%X",llvm_cbe_storemerge23);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__154);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%114 = sext i32 %%storemerge23 to i64, !dbg !21 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_437_count);
  llvm_cbe_tmp__147 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge23);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__147);
if (AESL_DEBUG_TRACE)
printf("\n  %%115 = getelementptr inbounds %%struct.picnic_publickey_t* %%pk, i64 0, i32 2, i64 %%114, !dbg !21 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_438_count);
  llvm_cbe_tmp__148 = ( char *)(&llvm_cbe_pk->field2[(((signed long long )llvm_cbe_tmp__147))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__147));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%116 = load i8* %%115, align 1, !dbg !21 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_439_count);
  llvm_cbe_tmp__149 = (unsigned char )*llvm_cbe_tmp__148;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__149);
if (AESL_DEBUG_TRACE)
printf("\n  %%117 = getelementptr inbounds %%struct.picnic_privatekey_t* %%sk, i64 0, i32 2, i32 2, i64 %%114, !dbg !21 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_440_count);
  llvm_cbe_tmp__150 = ( char *)(&llvm_cbe_sk->field2.field2[(((signed long long )llvm_cbe_tmp__147))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__147));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%116, i8* %%117, align 1, !dbg !21 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_441_count);
  *llvm_cbe_tmp__150 = llvm_cbe_tmp__149;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__149);
if (AESL_DEBUG_TRACE)
printf("\n  %%118 = getelementptr inbounds %%struct.picnic_publickey_t* %%pk, i64 0, i32 1, i64 %%114, !dbg !21 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_442_count);
  llvm_cbe_tmp__151 = ( char *)(&llvm_cbe_pk->field1[(((signed long long )llvm_cbe_tmp__147))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__147));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%119 = load i8* %%118, align 1, !dbg !21 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_443_count);
  llvm_cbe_tmp__152 = (unsigned char )*llvm_cbe_tmp__151;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__152);
if (AESL_DEBUG_TRACE)
printf("\n  %%120 = getelementptr inbounds %%struct.picnic_privatekey_t* %%sk, i64 0, i32 2, i32 1, i64 %%114, !dbg !21 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_444_count);
  llvm_cbe_tmp__153 = ( char *)(&llvm_cbe_sk->field2.field1[(((signed long long )llvm_cbe_tmp__147))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__147));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%119, i8* %%120, align 1, !dbg !21 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_445_count);
  *llvm_cbe_tmp__153 = llvm_cbe_tmp__152;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__152);
if (AESL_DEBUG_TRACE)
printf("\n  %%121 = add nsw i32 %%storemerge23, 1, !dbg !24 for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_446_count);
  llvm_cbe_tmp__154 = (unsigned int )((unsigned int )(llvm_cbe_storemerge23&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__154&4294967295ull)));
  if (((llvm_cbe_tmp__154&4294967295U) == (32u&4294967295U))) {
    llvm_cbe_tmp__155__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_loopexit;
  } else {
    llvm_cbe_storemerge23__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__154;   /* for PHI node */
    goto llvm_cbe_tmp__164;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_loopexit:
if (AESL_DEBUG_TRACE)
printf("\n  %%122 = phi i32 [ -1, %%3 ], [ -1, %%4 ], [ -1, %%13 ], [ 0, %%113  for 0x%I64xth hint within @picnic_keygen  --> \n", ++aesl_llvm_cbe_478_count);
  llvm_cbe_tmp__155 = (unsigned int )llvm_cbe_tmp__155__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__155);
printf("\n = 0x%X",4294967295u);
printf("\n = 0x%X",4294967295u);
printf("\n = 0x%X",4294967295u);
printf("\n = 0x%X",0u);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @picnic_keygen}\n");
  return llvm_cbe_tmp__155;
}


static signed int aesl_internal_is_valid_params( char llvm_cbe_params) {
  static  unsigned long long aesl_llvm_cbe_480_count = 0;
  static  unsigned long long aesl_llvm_cbe_481_count = 0;
  static  unsigned long long aesl_llvm_cbe_482_count = 0;
  static  unsigned long long aesl_llvm_cbe_483_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts_count = 0;
  unsigned int llvm_cbe_puts;
  static  unsigned long long aesl_llvm_cbe_484_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge_count = 0;
  unsigned int llvm_cbe_storemerge;
  unsigned int llvm_cbe_storemerge__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_485_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @aesl_internal_is_valid_params\n");
  switch (((unsigned char )(llvm_cbe_params&15ull))) {
  default:
    llvm_cbe_storemerge__PHI_TEMPORARY = (unsigned int )1u;   /* for PHI node */
    goto llvm_cbe_tmp__165;
;
  case ((unsigned char )(((unsigned char )-1)&15ull)):
    goto llvm_cbe_tmp__166;
    break;
  case ((unsigned char )(((unsigned char )-2)&15ull)):
    goto llvm_cbe_tmp__166;
    break;
  case ((unsigned char )(((unsigned char )-3)&15ull)):
    goto llvm_cbe_tmp__166;
    break;
  case ((unsigned char )(((unsigned char )-4)&15ull)):
    goto llvm_cbe_tmp__166;
    break;
  case ((unsigned char )(((unsigned char )-5)&15ull)):
    goto llvm_cbe_tmp__166;
    break;
  case ((unsigned char )(((unsigned char )-6)&15ull)):
    goto llvm_cbe_tmp__166;
    break;
  case ((unsigned char )(((unsigned char )0)&15ull)):
    goto llvm_cbe_tmp__166;
    break;
  }
llvm_cbe_tmp__166:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts = tail call i32 @puts(i8* getelementptr inbounds ([15 x i8]* @aesl_internal_str, i64 0, i64 0)), !dbg !19 for 0x%I64xth hint within @aesl_internal_is_valid_params  --> \n", ++aesl_llvm_cbe_puts_count);
   /*tail*/ puts(( char *)((&aesl_internal_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 15
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts = 0x%X",llvm_cbe_puts);
}
  llvm_cbe_storemerge__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__165;

llvm_cbe_tmp__165:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge = phi i32 [ 0, %%1 ], [ 1, %%0  for 0x%I64xth hint within @aesl_internal_is_valid_params  --> \n", ++aesl_llvm_cbe_storemerge_count);
  llvm_cbe_storemerge = (unsigned int )llvm_cbe_storemerge__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge = 0x%X",llvm_cbe_storemerge);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",1u);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @aesl_internal_is_valid_params}\n");
  return llvm_cbe_storemerge;
}


signed int is_picnic2( char llvm_cbe_params) {
  static  unsigned long long aesl_llvm_cbe_486_count = 0;
  static  unsigned long long aesl_llvm_cbe_487_count = 0;
  static  unsigned long long aesl_llvm_cbe_488_count = 0;
  static  unsigned long long aesl_llvm_cbe_489_count = 0;
  static  unsigned long long aesl_llvm_cbe_490_count = 0;
  static  unsigned long long aesl_llvm_cbe_switch_count = 0;
  static  unsigned long long aesl_llvm_cbe_or_2e_cond_count = 0;
  bool llvm_cbe_or_2e_cond;
  static  unsigned long long aesl_llvm_cbe_storemerge_count = 0;
  unsigned int llvm_cbe_storemerge;
  static  unsigned long long aesl_llvm_cbe_491_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @is_picnic2\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%or.cond = or i1 %%1, %%switch, !dbg !19 for 0x%I64xth hint within @is_picnic2  --> \n", ++aesl_llvm_cbe_or_2e_cond_count);
  llvm_cbe_or_2e_cond = (bool )((((llvm_cbe_params&15U) == (((unsigned char )7)&15U)) | ((( char )(llvm_cbe_params & (1U << 3U )  ? llvm_cbe_params | 4294967280U : llvm_cbe_params & 15U)) < (( char )(((unsigned char )-6) & (1U << 3U )  ? ((unsigned char )-6) | 4294967280U : ((unsigned char )-6) & 15U))))&1);
if (AESL_DEBUG_TRACE)
printf("\nor.cond = 0x%X\n", llvm_cbe_or_2e_cond);
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge = zext i1 %%or.cond to i32, !dbg !19 for 0x%I64xth hint within @is_picnic2  --> \n", ++aesl_llvm_cbe_storemerge_count);
  llvm_cbe_storemerge = (unsigned int )((unsigned int )(bool )llvm_cbe_or_2e_cond&1U);
if (AESL_DEBUG_TRACE)
printf("\nstoremerge = 0x%X\n", llvm_cbe_storemerge);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @is_picnic2}\n");
  return llvm_cbe_storemerge;
}


signed int picnic_sign(l_struct_OC_picnic_privatekey_t *llvm_cbe_sk,  char *llvm_cbe_message, signed long long llvm_cbe_message_len,  char *llvm_cbe_signature, signed long long *llvm_cbe_signature_len) {
  static  unsigned long long aesl_llvm_cbe_paramset_count = 0;
  l_struct_OC_paramset_t llvm_cbe_paramset;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_sig_count = 0;
  l_struct_OC_signature_t llvm_cbe_sig[1];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_temp_count = 0;
  signed int llvm_cbe_temp[8];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_temp2_count = 0;
  signed int llvm_cbe_temp2[8];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_temp3_count = 0;
  signed int llvm_cbe_temp3[8];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_492_count = 0;
  static  unsigned long long aesl_llvm_cbe_493_count = 0;
  static  unsigned long long aesl_llvm_cbe_494_count = 0;
  static  unsigned long long aesl_llvm_cbe_495_count = 0;
  static  unsigned long long aesl_llvm_cbe_496_count = 0;
  static  unsigned long long aesl_llvm_cbe_497_count = 0;
  static  unsigned long long aesl_llvm_cbe_498_count = 0;
  static  unsigned long long aesl_llvm_cbe_499_count = 0;
  static  unsigned long long aesl_llvm_cbe_500_count = 0;
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
   char *llvm_cbe_tmp__167;
  static  unsigned long long aesl_llvm_cbe_517_count = 0;
  unsigned char llvm_cbe_tmp__168;
  static  unsigned long long aesl_llvm_cbe_518_count = 0;
  unsigned int llvm_cbe_tmp__169;
  static  unsigned long long aesl_llvm_cbe_519_count = 0;
  static  unsigned long long aesl_llvm_cbe_520_count = 0;
  static  unsigned long long aesl_llvm_cbe_521_count = 0;
  static  unsigned long long aesl_llvm_cbe_522_count = 0;
  static  unsigned long long aesl_llvm_cbe_523_count = 0;
  static  unsigned long long aesl_llvm_cbe_524_count = 0;
  static  unsigned long long aesl_llvm_cbe_525_count = 0;
  static  unsigned long long aesl_llvm_cbe_526_count = 0;
   char *llvm_cbe_tmp__170;
  static  unsigned long long aesl_llvm_cbe_527_count = 0;
   char *llvm_cbe_tmp__171;
  static  unsigned long long aesl_llvm_cbe_528_count = 0;
  static  unsigned long long aesl_llvm_cbe_529_count = 0;
   char *llvm_cbe_tmp__172;
  static  unsigned long long aesl_llvm_cbe_530_count = 0;
   char *llvm_cbe_tmp__173;
  static  unsigned long long aesl_llvm_cbe_531_count = 0;
  static  unsigned long long aesl_llvm_cbe_532_count = 0;
   char *llvm_cbe_tmp__174;
  static  unsigned long long aesl_llvm_cbe_533_count = 0;
   char *llvm_cbe_tmp__175;
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
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_553_count = 0;
  unsigned long long llvm_cbe_tmp__176;
  static  unsigned long long aesl_llvm_cbe_554_count = 0;
   char *llvm_cbe_tmp__177;
  static  unsigned long long aesl_llvm_cbe_555_count = 0;
  unsigned char llvm_cbe_tmp__178;
  static  unsigned long long aesl_llvm_cbe_556_count = 0;
  unsigned int llvm_cbe_tmp__179;
  static  unsigned long long aesl_llvm_cbe_557_count = 0;
  unsigned int llvm_cbe_tmp__180;
  static  unsigned long long aesl_llvm_cbe_558_count = 0;
  unsigned long long llvm_cbe_tmp__181;
  static  unsigned long long aesl_llvm_cbe_559_count = 0;
   char *llvm_cbe_tmp__182;
  static  unsigned long long aesl_llvm_cbe_560_count = 0;
  unsigned char llvm_cbe_tmp__183;
  static  unsigned long long aesl_llvm_cbe_561_count = 0;
  unsigned int llvm_cbe_tmp__184;
  static  unsigned long long aesl_llvm_cbe_562_count = 0;
  unsigned int llvm_cbe_tmp__185;
  static  unsigned long long aesl_llvm_cbe_563_count = 0;
  unsigned long long llvm_cbe_tmp__186;
  static  unsigned long long aesl_llvm_cbe_564_count = 0;
   char *llvm_cbe_tmp__187;
  static  unsigned long long aesl_llvm_cbe_565_count = 0;
  unsigned char llvm_cbe_tmp__188;
  static  unsigned long long aesl_llvm_cbe_566_count = 0;
  unsigned int llvm_cbe_tmp__189;
  static  unsigned long long aesl_llvm_cbe_567_count = 0;
  unsigned int llvm_cbe_tmp__190;
  static  unsigned long long aesl_llvm_cbe_568_count = 0;
  unsigned long long llvm_cbe_tmp__191;
  static  unsigned long long aesl_llvm_cbe_569_count = 0;
   char *llvm_cbe_tmp__192;
  static  unsigned long long aesl_llvm_cbe_570_count = 0;
  unsigned char llvm_cbe_tmp__193;
  static  unsigned long long aesl_llvm_cbe_571_count = 0;
  unsigned int llvm_cbe_tmp__194;
  static  unsigned long long aesl_llvm_cbe_572_count = 0;
  unsigned int llvm_cbe_tmp__195;
  static  unsigned long long aesl_llvm_cbe_573_count = 0;
  unsigned int llvm_cbe_tmp__196;
  static  unsigned long long aesl_llvm_cbe_574_count = 0;
  unsigned int llvm_cbe_tmp__197;
  static  unsigned long long aesl_llvm_cbe_575_count = 0;
  unsigned int llvm_cbe_tmp__198;
  static  unsigned long long aesl_llvm_cbe_576_count = 0;
  unsigned int llvm_cbe_tmp__199;
  static  unsigned long long aesl_llvm_cbe_577_count = 0;
  unsigned int llvm_cbe_tmp__200;
  static  unsigned long long aesl_llvm_cbe_578_count = 0;
  unsigned int llvm_cbe_tmp__201;
  static  unsigned long long aesl_llvm_cbe_579_count = 0;
  unsigned long long llvm_cbe_tmp__202;
  static  unsigned long long aesl_llvm_cbe_580_count = 0;
  signed int *llvm_cbe_tmp__203;
  static  unsigned long long aesl_llvm_cbe_581_count = 0;
  static  unsigned long long aesl_llvm_cbe_582_count = 0;
   char *llvm_cbe_tmp__204;
  static  unsigned long long aesl_llvm_cbe_583_count = 0;
  unsigned char llvm_cbe_tmp__205;
  static  unsigned long long aesl_llvm_cbe_584_count = 0;
  unsigned int llvm_cbe_tmp__206;
  static  unsigned long long aesl_llvm_cbe_585_count = 0;
   char *llvm_cbe_tmp__207;
  static  unsigned long long aesl_llvm_cbe_586_count = 0;
  unsigned char llvm_cbe_tmp__208;
  static  unsigned long long aesl_llvm_cbe_587_count = 0;
  unsigned int llvm_cbe_tmp__209;
  static  unsigned long long aesl_llvm_cbe_588_count = 0;
   char *llvm_cbe_tmp__210;
  static  unsigned long long aesl_llvm_cbe_589_count = 0;
  unsigned char llvm_cbe_tmp__211;
  static  unsigned long long aesl_llvm_cbe_590_count = 0;
  unsigned int llvm_cbe_tmp__212;
  static  unsigned long long aesl_llvm_cbe_591_count = 0;
   char *llvm_cbe_tmp__213;
  static  unsigned long long aesl_llvm_cbe_592_count = 0;
  unsigned char llvm_cbe_tmp__214;
  static  unsigned long long aesl_llvm_cbe_593_count = 0;
  unsigned int llvm_cbe_tmp__215;
  static  unsigned long long aesl_llvm_cbe_594_count = 0;
  unsigned int llvm_cbe_tmp__216;
  static  unsigned long long aesl_llvm_cbe_595_count = 0;
  unsigned int llvm_cbe_tmp__217;
  static  unsigned long long aesl_llvm_cbe_596_count = 0;
  unsigned int llvm_cbe_tmp__218;
  static  unsigned long long aesl_llvm_cbe_597_count = 0;
  unsigned int llvm_cbe_tmp__219;
  static  unsigned long long aesl_llvm_cbe_598_count = 0;
  unsigned int llvm_cbe_tmp__220;
  static  unsigned long long aesl_llvm_cbe_599_count = 0;
  unsigned int llvm_cbe_tmp__221;
  static  unsigned long long aesl_llvm_cbe_600_count = 0;
  signed int *llvm_cbe_tmp__222;
  static  unsigned long long aesl_llvm_cbe_601_count = 0;
  static  unsigned long long aesl_llvm_cbe_602_count = 0;
   char *llvm_cbe_tmp__223;
  static  unsigned long long aesl_llvm_cbe_603_count = 0;
  unsigned char llvm_cbe_tmp__224;
  static  unsigned long long aesl_llvm_cbe_604_count = 0;
  unsigned int llvm_cbe_tmp__225;
  static  unsigned long long aesl_llvm_cbe_605_count = 0;
   char *llvm_cbe_tmp__226;
  static  unsigned long long aesl_llvm_cbe_606_count = 0;
  unsigned char llvm_cbe_tmp__227;
  static  unsigned long long aesl_llvm_cbe_607_count = 0;
  unsigned int llvm_cbe_tmp__228;
  static  unsigned long long aesl_llvm_cbe_608_count = 0;
   char *llvm_cbe_tmp__229;
  static  unsigned long long aesl_llvm_cbe_609_count = 0;
  unsigned char llvm_cbe_tmp__230;
  static  unsigned long long aesl_llvm_cbe_610_count = 0;
  unsigned int llvm_cbe_tmp__231;
  static  unsigned long long aesl_llvm_cbe_611_count = 0;
   char *llvm_cbe_tmp__232;
  static  unsigned long long aesl_llvm_cbe_612_count = 0;
  unsigned char llvm_cbe_tmp__233;
  static  unsigned long long aesl_llvm_cbe_613_count = 0;
  unsigned int llvm_cbe_tmp__234;
  static  unsigned long long aesl_llvm_cbe_614_count = 0;
  unsigned int llvm_cbe_tmp__235;
  static  unsigned long long aesl_llvm_cbe_615_count = 0;
  unsigned int llvm_cbe_tmp__236;
  static  unsigned long long aesl_llvm_cbe_616_count = 0;
  unsigned int llvm_cbe_tmp__237;
  static  unsigned long long aesl_llvm_cbe_617_count = 0;
  unsigned int llvm_cbe_tmp__238;
  static  unsigned long long aesl_llvm_cbe_618_count = 0;
  unsigned int llvm_cbe_tmp__239;
  static  unsigned long long aesl_llvm_cbe_619_count = 0;
  unsigned int llvm_cbe_tmp__240;
  static  unsigned long long aesl_llvm_cbe_620_count = 0;
  signed int *llvm_cbe_tmp__241;
  static  unsigned long long aesl_llvm_cbe_621_count = 0;
  static  unsigned long long aesl_llvm_cbe_622_count = 0;
  unsigned int llvm_cbe_tmp__242;
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
  signed int *llvm_cbe_tmp__243;
  static  unsigned long long aesl_llvm_cbe_662_count = 0;
  signed int *llvm_cbe_tmp__244;
  static  unsigned long long aesl_llvm_cbe_663_count = 0;
  signed int *llvm_cbe_tmp__245;
  static  unsigned long long aesl_llvm_cbe_664_count = 0;
  l_struct_OC_signature_t *llvm_cbe_tmp__246;
  static  unsigned long long aesl_llvm_cbe_665_count = 0;
  unsigned int llvm_cbe_tmp__247;
  static  unsigned long long aesl_llvm_cbe_666_count = 0;
  static  unsigned long long aesl_llvm_cbe_667_count = 0;
  static  unsigned long long aesl_llvm_cbe_668_count = 0;
  static  unsigned long long aesl_llvm_cbe_669_count = 0;
  static  unsigned long long aesl_llvm_cbe_670_count = 0;
  static  unsigned long long aesl_llvm_cbe_671_count = 0;
  static  unsigned long long aesl_llvm_cbe_672_count = 0;
  static  unsigned long long aesl_llvm_cbe_673_count = 0;
  unsigned long long llvm_cbe_tmp__248;
  static  unsigned long long aesl_llvm_cbe_674_count = 0;
  unsigned int llvm_cbe_tmp__249;
  static  unsigned long long aesl_llvm_cbe_675_count = 0;
  static  unsigned long long aesl_llvm_cbe_676_count = 0;
  static  unsigned long long aesl_llvm_cbe_677_count = 0;
  static  unsigned long long aesl_llvm_cbe_678_count = 0;
  static  unsigned long long aesl_llvm_cbe_679_count = 0;
  static  unsigned long long aesl_llvm_cbe_680_count = 0;
  static  unsigned long long aesl_llvm_cbe_681_count = 0;
  static  unsigned long long aesl_llvm_cbe_682_count = 0;
  unsigned long long llvm_cbe_tmp__250;
  static  unsigned long long aesl_llvm_cbe_683_count = 0;
  static  unsigned long long aesl_llvm_cbe_684_count = 0;
  static  unsigned long long aesl_llvm_cbe_685_count = 0;
  unsigned int llvm_cbe_tmp__251;
  unsigned int llvm_cbe_tmp__251__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_686_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @picnic_sign\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.picnic_privatekey_t* %%sk, i64 0, i32 0, !dbg !19 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_516_count);
  llvm_cbe_tmp__167 = ( char *)(&llvm_cbe_sk->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i4* %%1, align 1, !dbg !19 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_517_count);
  llvm_cbe_tmp__168 = (unsigned char )*llvm_cbe_tmp__167;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__168);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = call i32 @get_param_set(i4 zeroext %%2, %%struct.paramset_t* %%paramset), !dbg !19 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_518_count);
  get_param_set(llvm_cbe_tmp__168, (l_struct_OC_paramset_t *)(&llvm_cbe_paramset));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__168);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__169);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = bitcast [8 x i32]* %%temp to i8*, !dbg !26 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_526_count);
  llvm_cbe_tmp__170 = ( char *)(( char *)(&llvm_cbe_temp));
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = call i8* @memset(i8* %%4, i32 0, i64 32 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_527_count);
  ( char *)memset(( char *)llvm_cbe_tmp__170, 0u, 32ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",32ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__171);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = bitcast [8 x i32]* %%temp2 to i8*, !dbg !26 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_529_count);
  llvm_cbe_tmp__172 = ( char *)(( char *)(&llvm_cbe_temp2));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = call i8* @memset(i8* %%6, i32 0, i64 32 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_530_count);
  ( char *)memset(( char *)llvm_cbe_tmp__172, 0u, 32ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",32ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__173);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = bitcast [8 x i32]* %%temp3 to i8*, !dbg !26 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_532_count);
  llvm_cbe_tmp__174 = ( char *)(( char *)(&llvm_cbe_temp3));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = call i8* @memset(i8* %%8, i32 0, i64 32 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_533_count);
  ( char *)memset(( char *)llvm_cbe_tmp__174, 0u, 32ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",32ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__175);
}
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__252;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__252:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ 0, %%0 ], [ %%77, %%10  for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__242);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = sext i32 %%storemerge1 to i64, !dbg !19 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_553_count);
  llvm_cbe_tmp__176 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__176);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds %%struct.picnic_privatekey_t* %%sk, i64 0, i32 2, i32 2, i64 %%11, !dbg !19 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_554_count);
  llvm_cbe_tmp__177 = ( char *)(&llvm_cbe_sk->field2.field2[(((signed long long )llvm_cbe_tmp__176))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__176));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = load i8* %%12, align 1, !dbg !19 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_555_count);
  llvm_cbe_tmp__178 = (unsigned char )*llvm_cbe_tmp__177;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__178);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = zext i8 %%13 to i32, !dbg !19 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_556_count);
  llvm_cbe_tmp__179 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__178&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__179);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = or i32 %%storemerge1, 1, !dbg !19 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_557_count);
  llvm_cbe_tmp__180 = (unsigned int )llvm_cbe_storemerge1 | 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__180);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = sext i32 %%15 to i64, !dbg !19 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_558_count);
  llvm_cbe_tmp__181 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__180);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__181);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds %%struct.picnic_privatekey_t* %%sk, i64 0, i32 2, i32 2, i64 %%16, !dbg !19 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_559_count);
  llvm_cbe_tmp__182 = ( char *)(&llvm_cbe_sk->field2.field2[(((signed long long )llvm_cbe_tmp__181))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__181));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = load i8* %%17, align 1, !dbg !19 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_560_count);
  llvm_cbe_tmp__183 = (unsigned char )*llvm_cbe_tmp__182;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__183);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = zext i8 %%18 to i32, !dbg !19 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_561_count);
  llvm_cbe_tmp__184 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__183&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__184);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = or i32 %%storemerge1, 2, !dbg !19 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_562_count);
  llvm_cbe_tmp__185 = (unsigned int )llvm_cbe_storemerge1 | 2u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__185);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = sext i32 %%20 to i64, !dbg !19 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_563_count);
  llvm_cbe_tmp__186 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__185);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__186);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = getelementptr inbounds %%struct.picnic_privatekey_t* %%sk, i64 0, i32 2, i32 2, i64 %%21, !dbg !19 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_564_count);
  llvm_cbe_tmp__187 = ( char *)(&llvm_cbe_sk->field2.field2[(((signed long long )llvm_cbe_tmp__186))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__186));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = load i8* %%22, align 1, !dbg !19 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_565_count);
  llvm_cbe_tmp__188 = (unsigned char )*llvm_cbe_tmp__187;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__188);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = zext i8 %%23 to i32, !dbg !19 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_566_count);
  llvm_cbe_tmp__189 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__188&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__189);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = or i32 %%storemerge1, 3, !dbg !19 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_567_count);
  llvm_cbe_tmp__190 = (unsigned int )llvm_cbe_storemerge1 | 3u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__190);
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = sext i32 %%25 to i64, !dbg !19 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_568_count);
  llvm_cbe_tmp__191 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__190);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__191);
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = getelementptr inbounds %%struct.picnic_privatekey_t* %%sk, i64 0, i32 2, i32 2, i64 %%26, !dbg !19 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_569_count);
  llvm_cbe_tmp__192 = ( char *)(&llvm_cbe_sk->field2.field2[(((signed long long )llvm_cbe_tmp__191))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__191));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = load i8* %%27, align 1, !dbg !19 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_570_count);
  llvm_cbe_tmp__193 = (unsigned char )*llvm_cbe_tmp__192;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__193);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = zext i8 %%28 to i32, !dbg !19 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_571_count);
  llvm_cbe_tmp__194 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__193&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__194);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = shl nuw nsw i32 %%29, 8, !dbg !19 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_572_count);
  llvm_cbe_tmp__195 = (unsigned int )llvm_cbe_tmp__194 << 8u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__195);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = or i32 %%30, %%24, !dbg !19 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_573_count);
  llvm_cbe_tmp__196 = (unsigned int )llvm_cbe_tmp__195 | llvm_cbe_tmp__189;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__196);
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = shl nuw nsw i32 %%31, 8, !dbg !19 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_574_count);
  llvm_cbe_tmp__197 = (unsigned int )llvm_cbe_tmp__196 << 8u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__197);
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = or i32 %%32, %%19, !dbg !19 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_575_count);
  llvm_cbe_tmp__198 = (unsigned int )llvm_cbe_tmp__197 | llvm_cbe_tmp__184;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__198);
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = shl nuw nsw i32 %%33, 8, !dbg !19 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_576_count);
  llvm_cbe_tmp__199 = (unsigned int )llvm_cbe_tmp__198 << 8u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__199);
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = or i32 %%34, %%14, !dbg !19 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_577_count);
  llvm_cbe_tmp__200 = (unsigned int )llvm_cbe_tmp__199 | llvm_cbe_tmp__179;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__200);
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = sdiv i32 %%storemerge1, 4, !dbg !19 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_578_count);
  llvm_cbe_tmp__201 = (unsigned int )((signed int )(((signed int )llvm_cbe_storemerge1) / ((signed int )4u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__201));
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = sext i32 %%36 to i64, !dbg !19 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_579_count);
  llvm_cbe_tmp__202 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__201);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__202);
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = getelementptr inbounds [8 x i32]* %%temp, i64 0, i64 %%37, !dbg !19 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_580_count);
  llvm_cbe_tmp__203 = (signed int *)(&llvm_cbe_temp[(((signed long long )llvm_cbe_tmp__202))
#ifdef AESL_BC_SIM
 % 8
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__202));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__202) < 8 && "Write access out of array 'temp' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%35, i32* %%38, align 4, !dbg !19 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_581_count);
  *llvm_cbe_tmp__203 = llvm_cbe_tmp__200;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__200);
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = getelementptr inbounds %%struct.picnic_privatekey_t* %%sk, i64 0, i32 2, i32 1, i64 %%11, !dbg !20 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_582_count);
  llvm_cbe_tmp__204 = ( char *)(&llvm_cbe_sk->field2.field1[(((signed long long )llvm_cbe_tmp__176))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__176));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = load i8* %%39, align 1, !dbg !20 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_583_count);
  llvm_cbe_tmp__205 = (unsigned char )*llvm_cbe_tmp__204;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__205);
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = zext i8 %%40 to i32, !dbg !20 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_584_count);
  llvm_cbe_tmp__206 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__205&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__206);
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = getelementptr inbounds %%struct.picnic_privatekey_t* %%sk, i64 0, i32 2, i32 1, i64 %%16, !dbg !20 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_585_count);
  llvm_cbe_tmp__207 = ( char *)(&llvm_cbe_sk->field2.field1[(((signed long long )llvm_cbe_tmp__181))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__181));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = load i8* %%42, align 1, !dbg !20 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_586_count);
  llvm_cbe_tmp__208 = (unsigned char )*llvm_cbe_tmp__207;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__208);
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = zext i8 %%43 to i32, !dbg !20 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_587_count);
  llvm_cbe_tmp__209 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__208&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__209);
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = getelementptr inbounds %%struct.picnic_privatekey_t* %%sk, i64 0, i32 2, i32 1, i64 %%21, !dbg !20 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_588_count);
  llvm_cbe_tmp__210 = ( char *)(&llvm_cbe_sk->field2.field1[(((signed long long )llvm_cbe_tmp__186))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__186));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = load i8* %%45, align 1, !dbg !20 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_589_count);
  llvm_cbe_tmp__211 = (unsigned char )*llvm_cbe_tmp__210;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__211);
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = zext i8 %%46 to i32, !dbg !20 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_590_count);
  llvm_cbe_tmp__212 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__211&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__212);
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = getelementptr inbounds %%struct.picnic_privatekey_t* %%sk, i64 0, i32 2, i32 1, i64 %%26, !dbg !20 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_591_count);
  llvm_cbe_tmp__213 = ( char *)(&llvm_cbe_sk->field2.field1[(((signed long long )llvm_cbe_tmp__191))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__191));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = load i8* %%48, align 1, !dbg !20 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_592_count);
  llvm_cbe_tmp__214 = (unsigned char )*llvm_cbe_tmp__213;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__214);
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = zext i8 %%49 to i32, !dbg !20 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_593_count);
  llvm_cbe_tmp__215 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__214&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__215);
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = shl nuw nsw i32 %%50, 8, !dbg !20 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_594_count);
  llvm_cbe_tmp__216 = (unsigned int )llvm_cbe_tmp__215 << 8u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__216);
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = or i32 %%51, %%47, !dbg !20 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_595_count);
  llvm_cbe_tmp__217 = (unsigned int )llvm_cbe_tmp__216 | llvm_cbe_tmp__212;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__217);
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = shl nuw nsw i32 %%52, 8, !dbg !20 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_596_count);
  llvm_cbe_tmp__218 = (unsigned int )llvm_cbe_tmp__217 << 8u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__218);
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = or i32 %%53, %%44, !dbg !20 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_597_count);
  llvm_cbe_tmp__219 = (unsigned int )llvm_cbe_tmp__218 | llvm_cbe_tmp__209;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__219);
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = shl nuw nsw i32 %%54, 8, !dbg !20 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_598_count);
  llvm_cbe_tmp__220 = (unsigned int )llvm_cbe_tmp__219 << 8u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__220);
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = or i32 %%55, %%41, !dbg !20 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_599_count);
  llvm_cbe_tmp__221 = (unsigned int )llvm_cbe_tmp__220 | llvm_cbe_tmp__206;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__221);
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = getelementptr inbounds [8 x i32]* %%temp2, i64 0, i64 %%37, !dbg !20 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_600_count);
  llvm_cbe_tmp__222 = (signed int *)(&llvm_cbe_temp2[(((signed long long )llvm_cbe_tmp__202))
#ifdef AESL_BC_SIM
 % 8
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__202));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__202) < 8 && "Write access out of array 'temp2' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%56, i32* %%57, align 4, !dbg !20 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_601_count);
  *llvm_cbe_tmp__222 = llvm_cbe_tmp__221;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__221);
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = getelementptr inbounds %%struct.picnic_privatekey_t* %%sk, i64 0, i32 1, i64 %%11, !dbg !20 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_602_count);
  llvm_cbe_tmp__223 = ( char *)(&llvm_cbe_sk->field1[(((signed long long )llvm_cbe_tmp__176))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__176));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = load i8* %%58, align 1, !dbg !20 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_603_count);
  llvm_cbe_tmp__224 = (unsigned char )*llvm_cbe_tmp__223;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__224);
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = zext i8 %%59 to i32, !dbg !20 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_604_count);
  llvm_cbe_tmp__225 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__224&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__225);
if (AESL_DEBUG_TRACE)
printf("\n  %%61 = getelementptr inbounds %%struct.picnic_privatekey_t* %%sk, i64 0, i32 1, i64 %%16, !dbg !20 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_605_count);
  llvm_cbe_tmp__226 = ( char *)(&llvm_cbe_sk->field1[(((signed long long )llvm_cbe_tmp__181))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__181));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = load i8* %%61, align 1, !dbg !20 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_606_count);
  llvm_cbe_tmp__227 = (unsigned char )*llvm_cbe_tmp__226;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__227);
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = zext i8 %%62 to i32, !dbg !20 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_607_count);
  llvm_cbe_tmp__228 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__227&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__228);
if (AESL_DEBUG_TRACE)
printf("\n  %%64 = getelementptr inbounds %%struct.picnic_privatekey_t* %%sk, i64 0, i32 1, i64 %%21, !dbg !20 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_608_count);
  llvm_cbe_tmp__229 = ( char *)(&llvm_cbe_sk->field1[(((signed long long )llvm_cbe_tmp__186))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__186));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%65 = load i8* %%64, align 1, !dbg !20 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_609_count);
  llvm_cbe_tmp__230 = (unsigned char )*llvm_cbe_tmp__229;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__230);
if (AESL_DEBUG_TRACE)
printf("\n  %%66 = zext i8 %%65 to i32, !dbg !20 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_610_count);
  llvm_cbe_tmp__231 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__230&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__231);
if (AESL_DEBUG_TRACE)
printf("\n  %%67 = getelementptr inbounds %%struct.picnic_privatekey_t* %%sk, i64 0, i32 1, i64 %%26, !dbg !20 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_611_count);
  llvm_cbe_tmp__232 = ( char *)(&llvm_cbe_sk->field1[(((signed long long )llvm_cbe_tmp__191))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__191));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%68 = load i8* %%67, align 1, !dbg !20 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_612_count);
  llvm_cbe_tmp__233 = (unsigned char )*llvm_cbe_tmp__232;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__233);
if (AESL_DEBUG_TRACE)
printf("\n  %%69 = zext i8 %%68 to i32, !dbg !20 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_613_count);
  llvm_cbe_tmp__234 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__233&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__234);
if (AESL_DEBUG_TRACE)
printf("\n  %%70 = shl nuw nsw i32 %%69, 8, !dbg !20 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_614_count);
  llvm_cbe_tmp__235 = (unsigned int )llvm_cbe_tmp__234 << 8u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__235);
if (AESL_DEBUG_TRACE)
printf("\n  %%71 = or i32 %%70, %%66, !dbg !20 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_615_count);
  llvm_cbe_tmp__236 = (unsigned int )llvm_cbe_tmp__235 | llvm_cbe_tmp__231;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__236);
if (AESL_DEBUG_TRACE)
printf("\n  %%72 = shl nuw nsw i32 %%71, 8, !dbg !20 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_616_count);
  llvm_cbe_tmp__237 = (unsigned int )llvm_cbe_tmp__236 << 8u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__237);
if (AESL_DEBUG_TRACE)
printf("\n  %%73 = or i32 %%72, %%63, !dbg !20 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_617_count);
  llvm_cbe_tmp__238 = (unsigned int )llvm_cbe_tmp__237 | llvm_cbe_tmp__228;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__238);
if (AESL_DEBUG_TRACE)
printf("\n  %%74 = shl nuw nsw i32 %%73, 8, !dbg !20 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_618_count);
  llvm_cbe_tmp__239 = (unsigned int )llvm_cbe_tmp__238 << 8u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__239);
if (AESL_DEBUG_TRACE)
printf("\n  %%75 = or i32 %%74, %%60, !dbg !20 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_619_count);
  llvm_cbe_tmp__240 = (unsigned int )llvm_cbe_tmp__239 | llvm_cbe_tmp__225;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__240);
if (AESL_DEBUG_TRACE)
printf("\n  %%76 = getelementptr inbounds [8 x i32]* %%temp3, i64 0, i64 %%37, !dbg !20 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_620_count);
  llvm_cbe_tmp__241 = (signed int *)(&llvm_cbe_temp3[(((signed long long )llvm_cbe_tmp__202))
#ifdef AESL_BC_SIM
 % 8
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__202));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__202) < 8 && "Write access out of array 'temp3' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%75, i32* %%76, align 4, !dbg !20 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_621_count);
  *llvm_cbe_tmp__241 = llvm_cbe_tmp__240;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__240);
if (AESL_DEBUG_TRACE)
printf("\n  %%77 = add nsw i32 %%storemerge1, 4, !dbg !26 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_622_count);
  llvm_cbe_tmp__242 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(4u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__242&4294967295ull)));
  if ((((signed int )llvm_cbe_tmp__242) < ((signed int )32u))) {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__242;   /* for PHI node */
    goto llvm_cbe_tmp__252;
  } else {
    goto llvm_cbe_tmp__253;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__253:
if (AESL_DEBUG_TRACE)
printf("\n  %%80 = getelementptr inbounds [8 x i32]* %%temp3, i64 0, i64 0, !dbg !20 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_661_count);
  llvm_cbe_tmp__243 = (signed int *)(&llvm_cbe_temp3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%81 = getelementptr inbounds [8 x i32]* %%temp, i64 0, i64 0, !dbg !20 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_662_count);
  llvm_cbe_tmp__244 = (signed int *)(&llvm_cbe_temp[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%82 = getelementptr inbounds [8 x i32]* %%temp2, i64 0, i64 0, !dbg !20 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_663_count);
  llvm_cbe_tmp__245 = (signed int *)(&llvm_cbe_temp2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%83 = getelementptr inbounds [1 x %%struct.signature_t]* %%sig, i64 0, i64 0, !dbg !20 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_664_count);
  llvm_cbe_tmp__246 = (l_struct_OC_signature_t *)(&llvm_cbe_sig[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%84 = call i32 @sign_picnic1(i32* %%80, i32* %%81, i32* %%82, i8* %%message, i64 %%message_len, %%struct.signature_t* %%83, %%struct.paramset_t* %%paramset) nounwind, !dbg !20 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_665_count);
  llvm_cbe_tmp__247 = (unsigned int )sign_picnic1((signed int *)llvm_cbe_tmp__243, (signed int *)llvm_cbe_tmp__244, (signed int *)llvm_cbe_tmp__245, ( char *)llvm_cbe_message, llvm_cbe_message_len, (l_struct_OC_signature_t *)llvm_cbe_tmp__246, (l_struct_OC_paramset_t *)(&llvm_cbe_paramset));
if (AESL_DEBUG_TRACE) {
printf("\nArgument message_len = 0x%I64X",llvm_cbe_message_len);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__247);
}
  if (((llvm_cbe_tmp__247&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__254;
  } else {
    llvm_cbe_tmp__251__PHI_TEMPORARY = (unsigned int )4294967295u;   /* for PHI node */
    goto llvm_cbe_tmp__255;
  }

llvm_cbe_tmp__254:
if (AESL_DEBUG_TRACE)
printf("\n  %%87 = load i64* %%signature_len, align 8, !dbg !21 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_673_count);
  llvm_cbe_tmp__248 = (unsigned long long )*llvm_cbe_signature_len;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__248);
if (AESL_DEBUG_TRACE)
printf("\n  %%88 = call i32 @serializeSignature(%%struct.signature_t* %%83, i8* %%signature, i64 %%87, %%struct.paramset_t* %%paramset) nounwind, !dbg !21 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_674_count);
  llvm_cbe_tmp__249 = (unsigned int )serializeSignature((l_struct_OC_signature_t *)llvm_cbe_tmp__246, ( char *)llvm_cbe_signature, llvm_cbe_tmp__248, (l_struct_OC_paramset_t *)(&llvm_cbe_paramset));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__248);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__249);
}
  if (((llvm_cbe_tmp__249&4294967295U) == (4294967295u&4294967295U))) {
    llvm_cbe_tmp__251__PHI_TEMPORARY = (unsigned int )4294967295u;   /* for PHI node */
    goto llvm_cbe_tmp__255;
  } else {
    goto llvm_cbe_tmp__256;
  }

llvm_cbe_tmp__256:
if (AESL_DEBUG_TRACE)
printf("\n  %%91 = sext i32 %%88 to i64, !dbg !21 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_682_count);
  llvm_cbe_tmp__250 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__249);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__250);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%91, i64* %%signature_len, align 8, !dbg !21 for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_683_count);
  *llvm_cbe_signature_len = llvm_cbe_tmp__250;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__250);
  llvm_cbe_tmp__251__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__255;

llvm_cbe_tmp__255:
if (AESL_DEBUG_TRACE)
printf("\n  %%93 = phi i32 [ 0, %%90 ], [ -1, %%79 ], [ -1, %%86  for 0x%I64xth hint within @picnic_sign  --> \n", ++aesl_llvm_cbe_685_count);
  llvm_cbe_tmp__251 = (unsigned int )llvm_cbe_tmp__251__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__251);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",4294967295u);
printf("\n = 0x%X",4294967295u);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @picnic_sign}\n");
  return llvm_cbe_tmp__251;
}


signed long long picnic_signature_size( char llvm_cbe_parameters) {
  static  unsigned long long aesl_llvm_cbe_paramset_count = 0;
  l_struct_OC_paramset_t llvm_cbe_paramset;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_687_count = 0;
  static  unsigned long long aesl_llvm_cbe_688_count = 0;
  static  unsigned long long aesl_llvm_cbe_689_count = 0;
  static  unsigned long long aesl_llvm_cbe_690_count = 0;
  static  unsigned long long aesl_llvm_cbe_691_count = 0;
  static  unsigned long long aesl_llvm_cbe_692_count = 0;
  static  unsigned long long aesl_llvm_cbe_693_count = 0;
  unsigned int llvm_cbe_tmp__257;
  static  unsigned long long aesl_llvm_cbe_694_count = 0;
  static  unsigned long long aesl_llvm_cbe_695_count = 0;
  static  unsigned long long aesl_llvm_cbe_parameters_2e_off_count = 0;
  unsigned char llvm_cbe_parameters_2e_off;
  static  unsigned long long aesl_llvm_cbe_switch_count = 0;
  static  unsigned long long aesl_llvm_cbe_696_count = 0;
  static  unsigned long long aesl_llvm_cbe_697_count = 0;
  signed int *llvm_cbe_tmp__258;
  static  unsigned long long aesl_llvm_cbe_698_count = 0;
  unsigned int llvm_cbe_tmp__259;
  static  unsigned long long aesl_llvm_cbe_699_count = 0;
  unsigned long long llvm_cbe_tmp__260;
  static  unsigned long long aesl_llvm_cbe_700_count = 0;
  static  unsigned long long aesl_llvm_cbe_701_count = 0;
  static  unsigned long long aesl_llvm_cbe_702_count = 0;
  static  unsigned long long aesl_llvm_cbe_703_count = 0;
  static  unsigned long long aesl_llvm_cbe_704_count = 0;
  static  unsigned long long aesl_llvm_cbe_705_count = 0;
  static  unsigned long long aesl_llvm_cbe_706_count = 0;
  static  unsigned long long aesl_llvm_cbe_707_count = 0;
  signed int *llvm_cbe_tmp__261;
  static  unsigned long long aesl_llvm_cbe_708_count = 0;
  unsigned int llvm_cbe_tmp__262;
  static  unsigned long long aesl_llvm_cbe_709_count = 0;
  unsigned long long llvm_cbe_tmp__263;
  static  unsigned long long aesl_llvm_cbe_710_count = 0;
  static  unsigned long long aesl_llvm_cbe_711_count = 0;
  static  unsigned long long aesl_llvm_cbe_712_count = 0;
  unsigned long long llvm_cbe_tmp__264;
  static  unsigned long long aesl_llvm_cbe_713_count = 0;
  unsigned long long llvm_cbe_tmp__265;
  static  unsigned long long aesl_llvm_cbe_714_count = 0;
  unsigned long long llvm_cbe_tmp__266;
  static  unsigned long long aesl_llvm_cbe_715_count = 0;
  unsigned int llvm_cbe_tmp__267;
  static  unsigned long long aesl_llvm_cbe_716_count = 0;
  unsigned int llvm_cbe_tmp__268;
  static  unsigned long long aesl_llvm_cbe_717_count = 0;
  unsigned long long llvm_cbe_tmp__269;
  static  unsigned long long aesl_llvm_cbe_718_count = 0;
  signed int *llvm_cbe_tmp__270;
  static  unsigned long long aesl_llvm_cbe_719_count = 0;
  unsigned int llvm_cbe_tmp__271;
  static  unsigned long long aesl_llvm_cbe_720_count = 0;
  signed int *llvm_cbe_tmp__272;
  static  unsigned long long aesl_llvm_cbe_721_count = 0;
  unsigned int llvm_cbe_tmp__273;
  static  unsigned long long aesl_llvm_cbe_722_count = 0;
  unsigned int llvm_cbe_tmp__274;
  static  unsigned long long aesl_llvm_cbe_723_count = 0;
  unsigned int llvm_cbe_tmp__275;
  static  unsigned long long aesl_llvm_cbe_724_count = 0;
  signed int *llvm_cbe_tmp__276;
  static  unsigned long long aesl_llvm_cbe_725_count = 0;
  unsigned int llvm_cbe_tmp__277;
  static  unsigned long long aesl_llvm_cbe_726_count = 0;
  signed int *llvm_cbe_tmp__278;
  static  unsigned long long aesl_llvm_cbe_727_count = 0;
  unsigned int llvm_cbe_tmp__279;
  static  unsigned long long aesl_llvm_cbe_728_count = 0;
  signed int *llvm_cbe_tmp__280;
  static  unsigned long long aesl_llvm_cbe_729_count = 0;
  unsigned int llvm_cbe_tmp__281;
  static  unsigned long long aesl_llvm_cbe_tmp_count = 0;
  unsigned int llvm_cbe_tmp;
  static  unsigned long long aesl_llvm_cbe_tmp5_count = 0;
  unsigned int llvm_cbe_tmp5;
  static  unsigned long long aesl_llvm_cbe_730_count = 0;
  unsigned int llvm_cbe_tmp__282;
  static  unsigned long long aesl_llvm_cbe_731_count = 0;
  unsigned int llvm_cbe_tmp__283;
  static  unsigned long long aesl_llvm_cbe_732_count = 0;
  unsigned long long llvm_cbe_tmp__284;
  static  unsigned long long aesl_llvm_cbe_733_count = 0;
  static  unsigned long long aesl_llvm_cbe_734_count = 0;
  static  unsigned long long aesl_llvm_cbe_735_count = 0;
  signed int *llvm_cbe_tmp__285;
  static  unsigned long long aesl_llvm_cbe_736_count = 0;
  unsigned int llvm_cbe_tmp__286;
  static  unsigned long long aesl_llvm_cbe_737_count = 0;
  unsigned long long llvm_cbe_tmp__287;
  static  unsigned long long aesl_llvm_cbe_738_count = 0;
  unsigned int llvm_cbe_tmp__288;
  static  unsigned long long aesl_llvm_cbe_739_count = 0;
  unsigned long long llvm_cbe_tmp__289;
  static  unsigned long long aesl_llvm_cbe_740_count = 0;
  unsigned long long llvm_cbe_tmp__290;
  static  unsigned long long aesl_llvm_cbe_factor6_count = 0;
  unsigned long long llvm_cbe_factor6;
  static  unsigned long long aesl_llvm_cbe_tmp7_count = 0;
  unsigned long long llvm_cbe_tmp7;
  static  unsigned long long aesl_llvm_cbe_tmp8_count = 0;
  unsigned long long llvm_cbe_tmp8;
  static  unsigned long long aesl_llvm_cbe_tmp9_count = 0;
  unsigned long long llvm_cbe_tmp9;
  static  unsigned long long aesl_llvm_cbe_tmp10_count = 0;
  unsigned long long llvm_cbe_tmp10;
  static  unsigned long long aesl_llvm_cbe_741_count = 0;
  unsigned long long llvm_cbe_tmp__291;
  static  unsigned long long aesl_llvm_cbe_742_count = 0;
  unsigned long long llvm_cbe_tmp__292;
  static  unsigned long long aesl_llvm_cbe_743_count = 0;
  static  unsigned long long aesl_llvm_cbe_744_count = 0;
  static  unsigned long long aesl_llvm_cbe_745_count = 0;
  static  unsigned long long aesl_llvm_cbe_746_count = 0;
   char *llvm_cbe_tmp__293;
  static  unsigned long long aesl_llvm_cbe_747_count = 0;
  unsigned char llvm_cbe_tmp__294;
  static  unsigned long long aesl_llvm_cbe_748_count = 0;
  unsigned int llvm_cbe_tmp__295;
  static  unsigned long long aesl_llvm_cbe_749_count = 0;
  static  unsigned long long aesl_llvm_cbe_750_count = 0;
  signed int *llvm_cbe_tmp__296;
  static  unsigned long long aesl_llvm_cbe_751_count = 0;
  unsigned int llvm_cbe_tmp__297;
  static  unsigned long long aesl_llvm_cbe_752_count = 0;
  signed int *llvm_cbe_tmp__298;
  static  unsigned long long aesl_llvm_cbe_753_count = 0;
  unsigned int llvm_cbe_tmp__299;
  static  unsigned long long aesl_llvm_cbe_754_count = 0;
  signed int *llvm_cbe_tmp__300;
  static  unsigned long long aesl_llvm_cbe_755_count = 0;
  unsigned int llvm_cbe_tmp__301;
  static  unsigned long long aesl_llvm_cbe_756_count = 0;
  signed int *llvm_cbe_tmp__302;
  static  unsigned long long aesl_llvm_cbe_757_count = 0;
  unsigned int llvm_cbe_tmp__303;
  static  unsigned long long aesl_llvm_cbe_758_count = 0;
  signed int *llvm_cbe_tmp__304;
  static  unsigned long long aesl_llvm_cbe_759_count = 0;
  unsigned int llvm_cbe_tmp__305;
  static  unsigned long long aesl_llvm_cbe_760_count = 0;
  unsigned int llvm_cbe_tmp__306;
  static  unsigned long long aesl_llvm_cbe_761_count = 0;
  unsigned int llvm_cbe_tmp__307;
  static  unsigned long long aesl_llvm_cbe_762_count = 0;
  unsigned int llvm_cbe_tmp__308;
  static  unsigned long long aesl_llvm_cbe_763_count = 0;
  signed int *llvm_cbe_tmp__309;
  static  unsigned long long aesl_llvm_cbe_764_count = 0;
  unsigned int llvm_cbe_tmp__310;
  static  unsigned long long aesl_llvm_cbe_765_count = 0;
  unsigned int llvm_cbe_tmp__311;
  static  unsigned long long aesl_llvm_cbe_766_count = 0;
  unsigned int llvm_cbe_tmp__312;
  static  unsigned long long aesl_llvm_cbe_767_count = 0;
  unsigned int llvm_cbe_tmp__313;
  static  unsigned long long aesl_llvm_cbe_768_count = 0;
  unsigned int llvm_cbe_tmp__314;
  static  unsigned long long aesl_llvm_cbe_769_count = 0;
  unsigned int llvm_cbe_tmp__315;
  static  unsigned long long aesl_llvm_cbe_770_count = 0;
  unsigned int llvm_cbe_tmp__316;
  static  unsigned long long aesl_llvm_cbe_771_count = 0;
  unsigned int llvm_cbe_tmp__317;
  static  unsigned long long aesl_llvm_cbe_772_count = 0;
  unsigned int llvm_cbe_tmp__318;
  static  unsigned long long aesl_llvm_cbe_773_count = 0;
  signed int *llvm_cbe_tmp__319;
  static  unsigned long long aesl_llvm_cbe_774_count = 0;
  unsigned int llvm_cbe_tmp__320;
  static  unsigned long long aesl_llvm_cbe_775_count = 0;
  unsigned int llvm_cbe_tmp__321;
  static  unsigned long long aesl_llvm_cbe_776_count = 0;
  unsigned int llvm_cbe_tmp__322;
  static  unsigned long long aesl_llvm_cbe_777_count = 0;
  unsigned long long llvm_cbe_tmp__323;
  static  unsigned long long aesl_llvm_cbe_778_count = 0;
  static  unsigned long long aesl_llvm_cbe_779_count = 0;
  signed int *llvm_cbe_tmp__324;
  static  unsigned long long aesl_llvm_cbe_780_count = 0;
  unsigned int llvm_cbe_tmp__325;
  static  unsigned long long aesl_llvm_cbe_781_count = 0;
  signed int *llvm_cbe_tmp__326;
  static  unsigned long long aesl_llvm_cbe_782_count = 0;
  unsigned int llvm_cbe_tmp__327;
  static  unsigned long long aesl_llvm_cbe_783_count = 0;
  signed int *llvm_cbe_tmp__328;
  static  unsigned long long aesl_llvm_cbe_784_count = 0;
  unsigned int llvm_cbe_tmp__329;
  static  unsigned long long aesl_llvm_cbe_785_count = 0;
  signed int *llvm_cbe_tmp__330;
  static  unsigned long long aesl_llvm_cbe_786_count = 0;
  unsigned int llvm_cbe_tmp__331;
  static  unsigned long long aesl_llvm_cbe_787_count = 0;
  signed int *llvm_cbe_tmp__332;
  static  unsigned long long aesl_llvm_cbe_788_count = 0;
  unsigned int llvm_cbe_tmp__333;
  static  unsigned long long aesl_llvm_cbe_789_count = 0;
  unsigned int llvm_cbe_tmp__334;
  static  unsigned long long aesl_llvm_cbe_790_count = 0;
  unsigned int llvm_cbe_tmp__335;
  static  unsigned long long aesl_llvm_cbe_791_count = 0;
  unsigned int llvm_cbe_tmp__336;
  static  unsigned long long aesl_llvm_cbe_792_count = 0;
  unsigned int llvm_cbe_tmp__337;
  static  unsigned long long aesl_llvm_cbe_793_count = 0;
  signed int *llvm_cbe_tmp__338;
  static  unsigned long long aesl_llvm_cbe_794_count = 0;
  unsigned int llvm_cbe_tmp__339;
  static  unsigned long long aesl_llvm_cbe_795_count = 0;
  unsigned int llvm_cbe_tmp__340;
  static  unsigned long long aesl_llvm_cbe_796_count = 0;
  unsigned int llvm_cbe_tmp__341;
  static  unsigned long long aesl_llvm_cbe_797_count = 0;
  unsigned int llvm_cbe_tmp__342;
  static  unsigned long long aesl_llvm_cbe_798_count = 0;
  unsigned int llvm_cbe_tmp__343;
  static  unsigned long long aesl_llvm_cbe_799_count = 0;
  unsigned int llvm_cbe_tmp__344;
  static  unsigned long long aesl_llvm_cbe_800_count = 0;
  unsigned int llvm_cbe_tmp__345;
  static  unsigned long long aesl_llvm_cbe_801_count = 0;
  unsigned int llvm_cbe_tmp__346;
  static  unsigned long long aesl_llvm_cbe_802_count = 0;
  unsigned int llvm_cbe_tmp__347;
  static  unsigned long long aesl_llvm_cbe_803_count = 0;
  signed int *llvm_cbe_tmp__348;
  static  unsigned long long aesl_llvm_cbe_804_count = 0;
  unsigned int llvm_cbe_tmp__349;
  static  unsigned long long aesl_llvm_cbe_805_count = 0;
  unsigned int llvm_cbe_tmp__350;
  static  unsigned long long aesl_llvm_cbe_806_count = 0;
  unsigned int llvm_cbe_tmp__351;
  static  unsigned long long aesl_llvm_cbe_807_count = 0;
  unsigned long long llvm_cbe_tmp__352;
  static  unsigned long long aesl_llvm_cbe_808_count = 0;
  static  unsigned long long aesl_llvm_cbe_809_count = 0;
  unsigned long long llvm_cbe_tmp__353;
  unsigned long long llvm_cbe_tmp__353__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_810_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @picnic_signature_size\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = call i32 @get_param_set(i4 zeroext %%parameters, %%struct.paramset_t* %%paramset), !dbg !19 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_693_count);
  get_param_set(llvm_cbe_parameters, (l_struct_OC_paramset_t *)(&llvm_cbe_paramset));
if (AESL_DEBUG_TRACE) {
printf("\nArgument parameters = 0x%X",llvm_cbe_parameters);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__257);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%parameters.off = add i4 %%parameters, -7, !dbg !19 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_parameters_2e_off_count);
  llvm_cbe_parameters_2e_off = (unsigned char )((unsigned char )(llvm_cbe_parameters&15ull)) + ((unsigned char )(((unsigned char )-7)&15ull));
if (AESL_DEBUG_TRACE)
printf("\nparameters.off = 0x%X\n", ((unsigned char )(llvm_cbe_parameters_2e_off&15ull)));
  if ((((unsigned char )llvm_cbe_parameters_2e_off&15U) < ((unsigned char )((unsigned char )3)&15U))) {
    goto llvm_cbe_tmp__354;
  } else {
    goto llvm_cbe_tmp__355;
  }

llvm_cbe_tmp__354:
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.paramset_t* %%paramset, i64 0, i32 9, !dbg !20 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_697_count);
  llvm_cbe_tmp__258 = (signed int *)(&llvm_cbe_paramset.field9);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i32* %%3, align 4, !dbg !20 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_698_count);
  llvm_cbe_tmp__259 = (unsigned int )*llvm_cbe_tmp__258;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__259);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = zext i32 %%4 to i64, !dbg !20 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_699_count);
  llvm_cbe_tmp__260 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__259&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__260);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds %%struct.paramset_t* %%paramset, i64 0, i32 8, !dbg !21 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_707_count);
  llvm_cbe_tmp__261 = (signed int *)(&llvm_cbe_paramset.field8);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = load i32* %%6, align 4, !dbg !21 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_708_count);
  llvm_cbe_tmp__262 = (unsigned int )*llvm_cbe_tmp__261;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__262);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = zext i32 %%7 to i64, !dbg !21 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_709_count);
  llvm_cbe_tmp__263 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__262&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__263);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = add i64 %%5, -1, !dbg !20 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_712_count);
  llvm_cbe_tmp__264 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__260&18446744073709551615ull)) + ((unsigned long long )(18446744073709551615ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__264&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = add i64 %%9, %%8, !dbg !20 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_713_count);
  llvm_cbe_tmp__265 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__264&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__263&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__265&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = udiv i64 %%10, %%5, !dbg !20 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_714_count);
  llvm_cbe_tmp__266 = (unsigned long long )((unsigned long long )(((unsigned long long )(llvm_cbe_tmp__265&18446744073709551615ull)) / ((unsigned long long )(llvm_cbe_tmp__260&18446744073709551615ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__266&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = trunc i64 %%11 to i32, !dbg !20 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_715_count);
  llvm_cbe_tmp__267 = (unsigned int )((unsigned int )llvm_cbe_tmp__266&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__267);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = call i32 @ceil_log2(i32 %%12) nounwind, !dbg !20 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_716_count);
  llvm_cbe_tmp__268 = (unsigned int )ceil_log2(llvm_cbe_tmp__267);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__267);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__268);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = zext i32 %%13 to i64, !dbg !20 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_717_count);
  llvm_cbe_tmp__269 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__268&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__269);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds %%struct.paramset_t* %%paramset, i64 0, i32 11, !dbg !21 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_718_count);
  llvm_cbe_tmp__270 = (signed int *)(&llvm_cbe_paramset.field11);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = load i32* %%15, align 4, !dbg !21 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_719_count);
  llvm_cbe_tmp__271 = (unsigned int )*llvm_cbe_tmp__270;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__271);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds %%struct.paramset_t* %%paramset, i64 0, i32 10, !dbg !21 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_720_count);
  llvm_cbe_tmp__272 = (signed int *)(&llvm_cbe_paramset.field10);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = load i32* %%17, align 4, !dbg !21 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_721_count);
  llvm_cbe_tmp__273 = (unsigned int )*llvm_cbe_tmp__272;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__273);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = call i32 @ceil_log2(i32 %%18) nounwind, !dbg !21 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_722_count);
  llvm_cbe_tmp__274 = (unsigned int )ceil_log2(llvm_cbe_tmp__273);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__273);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__274);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = mul i32 %%19, %%16, !dbg !21 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_723_count);
  llvm_cbe_tmp__275 = (unsigned int )((unsigned int )(llvm_cbe_tmp__274&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__271&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__275&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = getelementptr inbounds %%struct.paramset_t* %%paramset, i64 0, i32 5, !dbg !21 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_724_count);
  llvm_cbe_tmp__276 = (signed int *)(&llvm_cbe_paramset.field5);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = load i32* %%21, align 4, !dbg !21 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_725_count);
  llvm_cbe_tmp__277 = (unsigned int )*llvm_cbe_tmp__276;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__277);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = getelementptr inbounds %%struct.paramset_t* %%paramset, i64 0, i32 3, !dbg !21 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_726_count);
  llvm_cbe_tmp__278 = (signed int *)(&llvm_cbe_paramset.field3);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = load i32* %%23, align 4, !dbg !21 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_727_count);
  llvm_cbe_tmp__279 = (unsigned int )*llvm_cbe_tmp__278;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__279);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = getelementptr inbounds %%struct.paramset_t* %%paramset, i64 0, i32 13, !dbg !21 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_728_count);
  llvm_cbe_tmp__280 = (signed int *)(&llvm_cbe_paramset.field13);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = load i32* %%25, align 4, !dbg !21 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_729_count);
  llvm_cbe_tmp__281 = (unsigned int )*llvm_cbe_tmp__280;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__281);
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp = add i32 %%24, %%2 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_tmp_count);
  llvm_cbe_tmp = (unsigned int )((unsigned int )(llvm_cbe_tmp__279&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__277&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp = 0x%X\n", ((unsigned int )(llvm_cbe_tmp&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp5 = shl i32 %%tmp,  for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_tmp5_count);
  llvm_cbe_tmp5 = (unsigned int )llvm_cbe_tmp << 1u;
if (AESL_DEBUG_TRACE)
printf("\ntmp5 = 0x%X\n", llvm_cbe_tmp5);
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = add i32 %%26, %%20, !dbg !21 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_730_count);
  llvm_cbe_tmp__282 = (unsigned int )((unsigned int )(llvm_cbe_tmp__281&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__275&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__282&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = add i32 %%27, %%tmp5, !dbg !21 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_731_count);
  llvm_cbe_tmp__283 = (unsigned int )((unsigned int )(llvm_cbe_tmp__282&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp5&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__283&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = zext i32 %%28 to i64, !dbg !21 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_732_count);
  llvm_cbe_tmp__284 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__283&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__284);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = getelementptr inbounds %%struct.paramset_t* %%paramset, i64 0, i32 12, !dbg !21 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_735_count);
  llvm_cbe_tmp__285 = (signed int *)(&llvm_cbe_paramset.field12);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = load i32* %%30, align 4, !dbg !21 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_736_count);
  llvm_cbe_tmp__286 = (unsigned int )*llvm_cbe_tmp__285;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__286);
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = zext i32 %%31 to i64, !dbg !21 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_737_count);
  llvm_cbe_tmp__287 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__286&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__287);
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = load i32* %%15, align 4, !dbg !21 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_738_count);
  llvm_cbe_tmp__288 = (unsigned int )*llvm_cbe_tmp__270;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__288);
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = zext i32 %%33 to i64, !dbg !21 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_739_count);
  llvm_cbe_tmp__289 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__288&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__289);
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = zext i32 %%26 to i64, !dbg !21 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_740_count);
  llvm_cbe_tmp__290 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__281&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__290);
if (AESL_DEBUG_TRACE)
printf("\n  %%factor6 = shl nuw nsw i64 %%5,  for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_factor6_count);
  llvm_cbe_factor6 = (unsigned long long )llvm_cbe_tmp__260 << 3ull;
if (AESL_DEBUG_TRACE)
printf("\nfactor6 = 0x%I64X\n", llvm_cbe_factor6);
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp7 = add i64 %%34, %%3 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_tmp7_count);
  llvm_cbe_tmp7 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__289&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__290&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp7 = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp7&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp8 = mul i64 %%14, %%tmp for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_tmp8_count);
  llvm_cbe_tmp8 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__269&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp7&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp8 = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp8&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp9 = add i64 %%tmp8, %%2 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_tmp9_count);
  llvm_cbe_tmp9 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp8&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__284&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp9 = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp9&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp10 = mul i64 %%tmp9, %% for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_tmp10_count);
  llvm_cbe_tmp10 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp9&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__260&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp10 = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp10&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = add i64 %%factor6, %%32, !dbg !21 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_741_count);
  llvm_cbe_tmp__291 = (unsigned long long )((unsigned long long )(llvm_cbe_factor6&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__287&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__291&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = add i64 %%36, %%tmp10, !dbg !21 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_742_count);
  llvm_cbe_tmp__292 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__291&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp10&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__292&18446744073709551615ull)));
  llvm_cbe_tmp__353__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__292;   /* for PHI node */
  goto llvm_cbe_tmp__356;

llvm_cbe_tmp__355:
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = getelementptr inbounds %%struct.paramset_t* %%paramset, i64 0, i32 14, !dbg !21 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_746_count);
  llvm_cbe_tmp__293 = ( char *)(&llvm_cbe_paramset.field14);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = load i8* %%39, align 4, !dbg !21 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_747_count);
  llvm_cbe_tmp__294 = (unsigned char )*llvm_cbe_tmp__293;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__294);
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = zext i8 %%40 to i32, !dbg !21 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_748_count);
  llvm_cbe_tmp__295 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__294&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__295);
  switch (((unsigned int )(llvm_cbe_tmp__295&4294967295ull))) {
  default:
    llvm_cbe_tmp__353__PHI_TEMPORARY = (unsigned long long )209522ull;   /* for PHI node */
    goto llvm_cbe_tmp__356;
;
  case ((unsigned int )(0u&4294967295ull)):
    goto llvm_cbe_tmp__357;
    break;
  case ((unsigned int )(1u&4294967295ull)):
    goto llvm_cbe_tmp__358;
  }
llvm_cbe_tmp__357:
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = getelementptr inbounds %%struct.paramset_t* %%paramset, i64 0, i32 8, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_750_count);
  llvm_cbe_tmp__296 = (signed int *)(&llvm_cbe_paramset.field8);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = load i32* %%43, align 4, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_751_count);
  llvm_cbe_tmp__297 = (unsigned int )*llvm_cbe_tmp__296;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__297);
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = getelementptr inbounds %%struct.paramset_t* %%paramset, i64 0, i32 13, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_752_count);
  llvm_cbe_tmp__298 = (signed int *)(&llvm_cbe_paramset.field13);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = load i32* %%45, align 4, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_753_count);
  llvm_cbe_tmp__299 = (unsigned int )*llvm_cbe_tmp__298;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__299);
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = getelementptr inbounds %%struct.paramset_t* %%paramset, i64 0, i32 3, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_754_count);
  llvm_cbe_tmp__300 = (signed int *)(&llvm_cbe_paramset.field3);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = load i32* %%47, align 4, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_755_count);
  llvm_cbe_tmp__301 = (unsigned int )*llvm_cbe_tmp__300;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__301);
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = getelementptr inbounds %%struct.paramset_t* %%paramset, i64 0, i32 1, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_756_count);
  llvm_cbe_tmp__302 = (signed int *)(&llvm_cbe_paramset.field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = load i32* %%49, align 4, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_757_count);
  llvm_cbe_tmp__303 = (unsigned int )*llvm_cbe_tmp__302;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__303);
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = getelementptr inbounds %%struct.paramset_t* %%paramset, i64 0, i32 0, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_758_count);
  llvm_cbe_tmp__304 = (signed int *)(&llvm_cbe_paramset.field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = load i32* %%51, align 4, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_759_count);
  llvm_cbe_tmp__305 = (unsigned int )*llvm_cbe_tmp__304;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__305);
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = mul i32 %%50, 3, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_760_count);
  llvm_cbe_tmp__306 = (unsigned int )((unsigned int )(llvm_cbe_tmp__303&4294967295ull)) * ((unsigned int )(3u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__306&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = mul i32 %%53, %%52, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_761_count);
  llvm_cbe_tmp__307 = (unsigned int )((unsigned int )(llvm_cbe_tmp__306&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__305&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__307&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = call i32 @numBytes(i32 %%54) nounwind, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_762_count);
  llvm_cbe_tmp__308 = (unsigned int )numBytes(llvm_cbe_tmp__307);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__307);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__308);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = getelementptr inbounds %%struct.paramset_t* %%paramset, i64 0, i32 11, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_763_count);
  llvm_cbe_tmp__309 = (signed int *)(&llvm_cbe_paramset.field11);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = load i32* %%56, align 4, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_764_count);
  llvm_cbe_tmp__310 = (unsigned int )*llvm_cbe_tmp__309;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__310);
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = shl i32 %%57, 1, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_765_count);
  llvm_cbe_tmp__311 = (unsigned int )llvm_cbe_tmp__310 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__311);
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = add i32 %%48, %%46, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_766_count);
  llvm_cbe_tmp__312 = (unsigned int )((unsigned int )(llvm_cbe_tmp__301&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__299&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__312&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = add i32 %%59, %%55, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_767_count);
  llvm_cbe_tmp__313 = (unsigned int )((unsigned int )(llvm_cbe_tmp__312&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__308&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__313&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%61 = add i32 %%60, %%58, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_768_count);
  llvm_cbe_tmp__314 = (unsigned int )((unsigned int )(llvm_cbe_tmp__313&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__311&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__314&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = mul i32 %%61, %%44, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_769_count);
  llvm_cbe_tmp__315 = (unsigned int )((unsigned int )(llvm_cbe_tmp__314&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__297&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__315&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = load i32* %%43, align 4, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_770_count);
  llvm_cbe_tmp__316 = (unsigned int )*llvm_cbe_tmp__296;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__316);
if (AESL_DEBUG_TRACE)
printf("\n  %%64 = shl i32 %%63, 1, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_771_count);
  llvm_cbe_tmp__317 = (unsigned int )llvm_cbe_tmp__316 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__317);
if (AESL_DEBUG_TRACE)
printf("\n  %%65 = call i32 @numBytes(i32 %%64) nounwind, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_772_count);
  llvm_cbe_tmp__318 = (unsigned int )numBytes(llvm_cbe_tmp__317);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__317);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__318);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%66 = getelementptr inbounds %%struct.paramset_t* %%paramset, i64 0, i32 12, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_773_count);
  llvm_cbe_tmp__319 = (signed int *)(&llvm_cbe_paramset.field12);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%67 = load i32* %%66, align 4, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_774_count);
  llvm_cbe_tmp__320 = (unsigned int )*llvm_cbe_tmp__319;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__320);
if (AESL_DEBUG_TRACE)
printf("\n  %%68 = add i32 %%67, %%65, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_775_count);
  llvm_cbe_tmp__321 = (unsigned int )((unsigned int )(llvm_cbe_tmp__320&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__318&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__321&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%69 = add i32 %%68, %%62, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_776_count);
  llvm_cbe_tmp__322 = (unsigned int )((unsigned int )(llvm_cbe_tmp__321&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__315&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__322&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%70 = zext i32 %%69 to i64, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_777_count);
  llvm_cbe_tmp__323 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__322&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__323);
  llvm_cbe_tmp__353__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__323;   /* for PHI node */
  goto llvm_cbe_tmp__356;

llvm_cbe_tmp__358:
if (AESL_DEBUG_TRACE)
printf("\n  %%72 = getelementptr inbounds %%struct.paramset_t* %%paramset, i64 0, i32 8, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_779_count);
  llvm_cbe_tmp__324 = (signed int *)(&llvm_cbe_paramset.field8);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%73 = load i32* %%72, align 4, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_780_count);
  llvm_cbe_tmp__325 = (unsigned int )*llvm_cbe_tmp__324;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__325);
if (AESL_DEBUG_TRACE)
printf("\n  %%74 = getelementptr inbounds %%struct.paramset_t* %%paramset, i64 0, i32 13, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_781_count);
  llvm_cbe_tmp__326 = (signed int *)(&llvm_cbe_paramset.field13);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%75 = load i32* %%74, align 4, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_782_count);
  llvm_cbe_tmp__327 = (unsigned int )*llvm_cbe_tmp__326;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__327);
if (AESL_DEBUG_TRACE)
printf("\n  %%76 = getelementptr inbounds %%struct.paramset_t* %%paramset, i64 0, i32 3, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_783_count);
  llvm_cbe_tmp__328 = (signed int *)(&llvm_cbe_paramset.field3);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%77 = load i32* %%76, align 4, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_784_count);
  llvm_cbe_tmp__329 = (unsigned int )*llvm_cbe_tmp__328;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__329);
if (AESL_DEBUG_TRACE)
printf("\n  %%78 = getelementptr inbounds %%struct.paramset_t* %%paramset, i64 0, i32 1, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_785_count);
  llvm_cbe_tmp__330 = (signed int *)(&llvm_cbe_paramset.field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%79 = load i32* %%78, align 4, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_786_count);
  llvm_cbe_tmp__331 = (unsigned int )*llvm_cbe_tmp__330;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__331);
if (AESL_DEBUG_TRACE)
printf("\n  %%80 = getelementptr inbounds %%struct.paramset_t* %%paramset, i64 0, i32 0, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_787_count);
  llvm_cbe_tmp__332 = (signed int *)(&llvm_cbe_paramset.field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%81 = load i32* %%80, align 4, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_788_count);
  llvm_cbe_tmp__333 = (unsigned int )*llvm_cbe_tmp__332;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__333);
if (AESL_DEBUG_TRACE)
printf("\n  %%82 = mul i32 %%79, 3, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_789_count);
  llvm_cbe_tmp__334 = (unsigned int )((unsigned int )(llvm_cbe_tmp__331&4294967295ull)) * ((unsigned int )(3u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__334&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%83 = mul i32 %%82, %%81, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_790_count);
  llvm_cbe_tmp__335 = (unsigned int )((unsigned int )(llvm_cbe_tmp__334&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__333&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__335&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%84 = call i32 @numBytes(i32 %%83) nounwind, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_791_count);
  llvm_cbe_tmp__336 = (unsigned int )numBytes(llvm_cbe_tmp__335);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__335);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__336);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%85 = shl i32 %%84, 1, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_792_count);
  llvm_cbe_tmp__337 = (unsigned int )llvm_cbe_tmp__336 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__337);
if (AESL_DEBUG_TRACE)
printf("\n  %%86 = getelementptr inbounds %%struct.paramset_t* %%paramset, i64 0, i32 11, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_793_count);
  llvm_cbe_tmp__338 = (signed int *)(&llvm_cbe_paramset.field11);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%87 = load i32* %%86, align 4, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_794_count);
  llvm_cbe_tmp__339 = (unsigned int )*llvm_cbe_tmp__338;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__339);
if (AESL_DEBUG_TRACE)
printf("\n  %%88 = mul i32 %%87, 3, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_795_count);
  llvm_cbe_tmp__340 = (unsigned int )((unsigned int )(llvm_cbe_tmp__339&4294967295ull)) * ((unsigned int )(3u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__340&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%89 = add i32 %%77, %%75, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_796_count);
  llvm_cbe_tmp__341 = (unsigned int )((unsigned int )(llvm_cbe_tmp__329&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__327&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__341&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%90 = add i32 %%89, %%85, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_797_count);
  llvm_cbe_tmp__342 = (unsigned int )((unsigned int )(llvm_cbe_tmp__341&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__337&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__342&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%91 = add i32 %%90, %%88, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_798_count);
  llvm_cbe_tmp__343 = (unsigned int )((unsigned int )(llvm_cbe_tmp__342&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__340&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__343&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%92 = mul i32 %%91, %%73, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_799_count);
  llvm_cbe_tmp__344 = (unsigned int )((unsigned int )(llvm_cbe_tmp__343&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__325&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__344&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%93 = load i32* %%72, align 4, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_800_count);
  llvm_cbe_tmp__345 = (unsigned int )*llvm_cbe_tmp__324;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__345);
if (AESL_DEBUG_TRACE)
printf("\n  %%94 = shl i32 %%93, 1, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_801_count);
  llvm_cbe_tmp__346 = (unsigned int )llvm_cbe_tmp__345 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__346);
if (AESL_DEBUG_TRACE)
printf("\n  %%95 = call i32 @numBytes(i32 %%94) nounwind, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_802_count);
  llvm_cbe_tmp__347 = (unsigned int )numBytes(llvm_cbe_tmp__346);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__346);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__347);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%96 = getelementptr inbounds %%struct.paramset_t* %%paramset, i64 0, i32 12, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_803_count);
  llvm_cbe_tmp__348 = (signed int *)(&llvm_cbe_paramset.field12);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%97 = load i32* %%96, align 4, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_804_count);
  llvm_cbe_tmp__349 = (unsigned int )*llvm_cbe_tmp__348;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__349);
if (AESL_DEBUG_TRACE)
printf("\n  %%98 = add i32 %%97, %%95, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_805_count);
  llvm_cbe_tmp__350 = (unsigned int )((unsigned int )(llvm_cbe_tmp__349&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__347&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__350&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%99 = add i32 %%98, %%92, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_806_count);
  llvm_cbe_tmp__351 = (unsigned int )((unsigned int )(llvm_cbe_tmp__350&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__344&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__351&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%100 = zext i32 %%99 to i64, !dbg !22 for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_807_count);
  llvm_cbe_tmp__352 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__351&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__352);
  llvm_cbe_tmp__353__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__352;   /* for PHI node */
  goto llvm_cbe_tmp__356;

llvm_cbe_tmp__356:
if (AESL_DEBUG_TRACE)
printf("\n  %%102 = phi i64 [ %%100, %%71 ], [ %%70, %%42 ], [ %%37, %%2 ], [ 209522, %%38  for 0x%I64xth hint within @picnic_signature_size  --> \n", ++aesl_llvm_cbe_809_count);
  llvm_cbe_tmp__353 = (unsigned long long )llvm_cbe_tmp__353__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__353);
printf("\n = 0x%I64X",llvm_cbe_tmp__352);
printf("\n = 0x%I64X",llvm_cbe_tmp__323);
printf("\n = 0x%I64X",llvm_cbe_tmp__292);
printf("\n = 0x%I64X",209522ull);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @picnic_signature_size}\n");
  return llvm_cbe_tmp__353;
}


signed int picnic_verify(l_struct_OC_picnic_publickey_t *llvm_cbe_pk,  char *llvm_cbe_message, signed long long llvm_cbe_message_len,  char *llvm_cbe_signature, signed long long llvm_cbe_signature_len) {
  static  unsigned long long aesl_llvm_cbe_paramset_count = 0;
  l_struct_OC_paramset_t llvm_cbe_paramset;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_sig_count = 0;
  l_struct_OC_signature_t llvm_cbe_sig[1];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_temp_count = 0;
  signed int llvm_cbe_temp[8];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_temp2_count = 0;
  signed int llvm_cbe_temp2[8];    /* Address-exposed local */
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
   char *llvm_cbe_tmp__359;
  static  unsigned long long aesl_llvm_cbe_831_count = 0;
  unsigned char llvm_cbe_tmp__360;
  static  unsigned long long aesl_llvm_cbe_832_count = 0;
  unsigned int llvm_cbe_tmp__361;
  static  unsigned long long aesl_llvm_cbe_833_count = 0;
  static  unsigned long long aesl_llvm_cbe_834_count = 0;
  static  unsigned long long aesl_llvm_cbe_835_count = 0;
  static  unsigned long long aesl_llvm_cbe_836_count = 0;
  l_struct_OC_signature_t *llvm_cbe_tmp__362;
  static  unsigned long long aesl_llvm_cbe_837_count = 0;
  unsigned int llvm_cbe_tmp__363;
  static  unsigned long long aesl_llvm_cbe_838_count = 0;
  static  unsigned long long aesl_llvm_cbe_839_count = 0;
  static  unsigned long long aesl_llvm_cbe_840_count = 0;
  static  unsigned long long aesl_llvm_cbe_841_count = 0;
  static  unsigned long long aesl_llvm_cbe_842_count = 0;
  static  unsigned long long aesl_llvm_cbe_843_count = 0;
   char *llvm_cbe_tmp__364;
  static  unsigned long long aesl_llvm_cbe_844_count = 0;
   char *llvm_cbe_tmp__365;
  static  unsigned long long aesl_llvm_cbe_845_count = 0;
  static  unsigned long long aesl_llvm_cbe_846_count = 0;
   char *llvm_cbe_tmp__366;
  static  unsigned long long aesl_llvm_cbe_847_count = 0;
   char *llvm_cbe_tmp__367;
  static  unsigned long long aesl_llvm_cbe_848_count = 0;
  static  unsigned long long aesl_llvm_cbe_849_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_861_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_862_count = 0;
  unsigned long long llvm_cbe_tmp__368;
  static  unsigned long long aesl_llvm_cbe_863_count = 0;
   char *llvm_cbe_tmp__369;
  static  unsigned long long aesl_llvm_cbe_864_count = 0;
  unsigned char llvm_cbe_tmp__370;
  static  unsigned long long aesl_llvm_cbe_865_count = 0;
  unsigned int llvm_cbe_tmp__371;
  static  unsigned long long aesl_llvm_cbe_866_count = 0;
  unsigned int llvm_cbe_tmp__372;
  static  unsigned long long aesl_llvm_cbe_867_count = 0;
  unsigned long long llvm_cbe_tmp__373;
  static  unsigned long long aesl_llvm_cbe_868_count = 0;
   char *llvm_cbe_tmp__374;
  static  unsigned long long aesl_llvm_cbe_869_count = 0;
  unsigned char llvm_cbe_tmp__375;
  static  unsigned long long aesl_llvm_cbe_870_count = 0;
  unsigned int llvm_cbe_tmp__376;
  static  unsigned long long aesl_llvm_cbe_871_count = 0;
  unsigned int llvm_cbe_tmp__377;
  static  unsigned long long aesl_llvm_cbe_872_count = 0;
  unsigned long long llvm_cbe_tmp__378;
  static  unsigned long long aesl_llvm_cbe_873_count = 0;
   char *llvm_cbe_tmp__379;
  static  unsigned long long aesl_llvm_cbe_874_count = 0;
  unsigned char llvm_cbe_tmp__380;
  static  unsigned long long aesl_llvm_cbe_875_count = 0;
  unsigned int llvm_cbe_tmp__381;
  static  unsigned long long aesl_llvm_cbe_876_count = 0;
  unsigned int llvm_cbe_tmp__382;
  static  unsigned long long aesl_llvm_cbe_877_count = 0;
  unsigned long long llvm_cbe_tmp__383;
  static  unsigned long long aesl_llvm_cbe_878_count = 0;
   char *llvm_cbe_tmp__384;
  static  unsigned long long aesl_llvm_cbe_879_count = 0;
  unsigned char llvm_cbe_tmp__385;
  static  unsigned long long aesl_llvm_cbe_880_count = 0;
  unsigned int llvm_cbe_tmp__386;
  static  unsigned long long aesl_llvm_cbe_881_count = 0;
  unsigned int llvm_cbe_tmp__387;
  static  unsigned long long aesl_llvm_cbe_882_count = 0;
  unsigned int llvm_cbe_tmp__388;
  static  unsigned long long aesl_llvm_cbe_883_count = 0;
  unsigned int llvm_cbe_tmp__389;
  static  unsigned long long aesl_llvm_cbe_884_count = 0;
  unsigned int llvm_cbe_tmp__390;
  static  unsigned long long aesl_llvm_cbe_885_count = 0;
  unsigned int llvm_cbe_tmp__391;
  static  unsigned long long aesl_llvm_cbe_886_count = 0;
  unsigned int llvm_cbe_tmp__392;
  static  unsigned long long aesl_llvm_cbe_887_count = 0;
  unsigned int llvm_cbe_tmp__393;
  static  unsigned long long aesl_llvm_cbe_888_count = 0;
  unsigned long long llvm_cbe_tmp__394;
  static  unsigned long long aesl_llvm_cbe_889_count = 0;
  signed int *llvm_cbe_tmp__395;
  static  unsigned long long aesl_llvm_cbe_890_count = 0;
  static  unsigned long long aesl_llvm_cbe_891_count = 0;
   char *llvm_cbe_tmp__396;
  static  unsigned long long aesl_llvm_cbe_892_count = 0;
  unsigned char llvm_cbe_tmp__397;
  static  unsigned long long aesl_llvm_cbe_893_count = 0;
  unsigned int llvm_cbe_tmp__398;
  static  unsigned long long aesl_llvm_cbe_894_count = 0;
   char *llvm_cbe_tmp__399;
  static  unsigned long long aesl_llvm_cbe_895_count = 0;
  unsigned char llvm_cbe_tmp__400;
  static  unsigned long long aesl_llvm_cbe_896_count = 0;
  unsigned int llvm_cbe_tmp__401;
  static  unsigned long long aesl_llvm_cbe_897_count = 0;
   char *llvm_cbe_tmp__402;
  static  unsigned long long aesl_llvm_cbe_898_count = 0;
  unsigned char llvm_cbe_tmp__403;
  static  unsigned long long aesl_llvm_cbe_899_count = 0;
  unsigned int llvm_cbe_tmp__404;
  static  unsigned long long aesl_llvm_cbe_900_count = 0;
   char *llvm_cbe_tmp__405;
  static  unsigned long long aesl_llvm_cbe_901_count = 0;
  unsigned char llvm_cbe_tmp__406;
  static  unsigned long long aesl_llvm_cbe_902_count = 0;
  unsigned int llvm_cbe_tmp__407;
  static  unsigned long long aesl_llvm_cbe_903_count = 0;
  unsigned int llvm_cbe_tmp__408;
  static  unsigned long long aesl_llvm_cbe_904_count = 0;
  unsigned int llvm_cbe_tmp__409;
  static  unsigned long long aesl_llvm_cbe_905_count = 0;
  unsigned int llvm_cbe_tmp__410;
  static  unsigned long long aesl_llvm_cbe_906_count = 0;
  unsigned int llvm_cbe_tmp__411;
  static  unsigned long long aesl_llvm_cbe_907_count = 0;
  unsigned int llvm_cbe_tmp__412;
  static  unsigned long long aesl_llvm_cbe_908_count = 0;
  unsigned int llvm_cbe_tmp__413;
  static  unsigned long long aesl_llvm_cbe_909_count = 0;
  signed int *llvm_cbe_tmp__414;
  static  unsigned long long aesl_llvm_cbe_910_count = 0;
  static  unsigned long long aesl_llvm_cbe_911_count = 0;
  unsigned int llvm_cbe_tmp__415;
  static  unsigned long long aesl_llvm_cbe_912_count = 0;
  static  unsigned long long aesl_llvm_cbe_913_count = 0;
  static  unsigned long long aesl_llvm_cbe_914_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_926_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_938_count = 0;
  static  unsigned long long aesl_llvm_cbe_939_count = 0;
  static  unsigned long long aesl_llvm_cbe_940_count = 0;
  signed int *llvm_cbe_tmp__416;
  static  unsigned long long aesl_llvm_cbe_941_count = 0;
  signed int *llvm_cbe_tmp__417;
  static  unsigned long long aesl_llvm_cbe_942_count = 0;
  unsigned int llvm_cbe_tmp__418;
  static  unsigned long long aesl_llvm_cbe_943_count = 0;
  static  unsigned long long aesl_llvm_cbe_944_count = 0;
  static  unsigned long long aesl_llvm_cbe_945_count = 0;
  static  unsigned long long aesl_llvm_cbe_946_count = 0;
  static  unsigned long long aesl_llvm_cbe_947_count = 0;
  static  unsigned long long aesl_llvm_cbe_948_count = 0;
  static  unsigned long long aesl_llvm_cbe_949_count = 0;
  unsigned int llvm_cbe_tmp__419;
  unsigned int llvm_cbe_tmp__419__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_950_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @picnic_verify\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.picnic_publickey_t* %%pk, i64 0, i32 0, !dbg !19 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_830_count);
  llvm_cbe_tmp__359 = ( char *)(&llvm_cbe_pk->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i4* %%1, align 1, !dbg !19 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_831_count);
  llvm_cbe_tmp__360 = (unsigned char )*llvm_cbe_tmp__359;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__360);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = call i32 @get_param_set(i4 zeroext %%2, %%struct.paramset_t* %%paramset), !dbg !19 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_832_count);
  get_param_set(llvm_cbe_tmp__360, (l_struct_OC_paramset_t *)(&llvm_cbe_paramset));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__360);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__361);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds [1 x %%struct.signature_t]* %%sig, i64 0, i64 0, !dbg !21 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_836_count);
  llvm_cbe_tmp__362 = (l_struct_OC_signature_t *)(&llvm_cbe_sig[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = call i32 @deserializeSignature(%%struct.signature_t* %%4, i8* %%signature, i64 %%signature_len, %%struct.paramset_t* %%paramset) nounwind, !dbg !21 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_837_count);
  llvm_cbe_tmp__363 = (unsigned int )deserializeSignature((l_struct_OC_signature_t *)llvm_cbe_tmp__362, ( char *)llvm_cbe_signature, llvm_cbe_signature_len, (l_struct_OC_paramset_t *)(&llvm_cbe_paramset));
if (AESL_DEBUG_TRACE) {
printf("\nArgument signature_len = 0x%I64X",llvm_cbe_signature_len);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__363);
}
  if (((llvm_cbe_tmp__363&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__420;
  } else {
    llvm_cbe_tmp__419__PHI_TEMPORARY = (unsigned int )4294967295u;   /* for PHI node */
    goto llvm_cbe_tmp__421;
  }

llvm_cbe_tmp__420:
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = bitcast [8 x i32]* %%temp to i8*, !dbg !25 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_843_count);
  llvm_cbe_tmp__364 = ( char *)(( char *)(&llvm_cbe_temp));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = call i8* @memset(i8* %%8, i32 0, i64 32 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_844_count);
  ( char *)memset(( char *)llvm_cbe_tmp__364, 0u, 32ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",32ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__365);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = bitcast [8 x i32]* %%temp2 to i8*, !dbg !25 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_846_count);
  llvm_cbe_tmp__366 = ( char *)(( char *)(&llvm_cbe_temp2));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = call i8* @memset(i8* %%10, i32 0, i64 32 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_847_count);
  ( char *)memset(( char *)llvm_cbe_tmp__366, 0u, 32ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",32ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__367);
}
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__422;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__422:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ 0, %%7 ], [ %%60, %%12  for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__415);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = sext i32 %%storemerge1 to i64, !dbg !19 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_862_count);
  llvm_cbe_tmp__368 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__368);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds %%struct.picnic_publickey_t* %%pk, i64 0, i32 2, i64 %%13, !dbg !19 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_863_count);
  llvm_cbe_tmp__369 = ( char *)(&llvm_cbe_pk->field2[(((signed long long )llvm_cbe_tmp__368))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__368));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = load i8* %%14, align 1, !dbg !19 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_864_count);
  llvm_cbe_tmp__370 = (unsigned char )*llvm_cbe_tmp__369;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__370);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = zext i8 %%15 to i32, !dbg !19 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_865_count);
  llvm_cbe_tmp__371 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__370&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__371);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = or i32 %%storemerge1, 1, !dbg !19 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_866_count);
  llvm_cbe_tmp__372 = (unsigned int )llvm_cbe_storemerge1 | 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__372);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = sext i32 %%17 to i64, !dbg !19 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_867_count);
  llvm_cbe_tmp__373 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__372);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__373);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = getelementptr inbounds %%struct.picnic_publickey_t* %%pk, i64 0, i32 2, i64 %%18, !dbg !19 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_868_count);
  llvm_cbe_tmp__374 = ( char *)(&llvm_cbe_pk->field2[(((signed long long )llvm_cbe_tmp__373))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__373));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = load i8* %%19, align 1, !dbg !19 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_869_count);
  llvm_cbe_tmp__375 = (unsigned char )*llvm_cbe_tmp__374;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__375);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = zext i8 %%20 to i32, !dbg !19 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_870_count);
  llvm_cbe_tmp__376 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__375&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__376);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = or i32 %%storemerge1, 2, !dbg !19 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_871_count);
  llvm_cbe_tmp__377 = (unsigned int )llvm_cbe_storemerge1 | 2u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__377);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = sext i32 %%22 to i64, !dbg !19 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_872_count);
  llvm_cbe_tmp__378 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__377);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__378);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = getelementptr inbounds %%struct.picnic_publickey_t* %%pk, i64 0, i32 2, i64 %%23, !dbg !19 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_873_count);
  llvm_cbe_tmp__379 = ( char *)(&llvm_cbe_pk->field2[(((signed long long )llvm_cbe_tmp__378))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__378));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = load i8* %%24, align 1, !dbg !19 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_874_count);
  llvm_cbe_tmp__380 = (unsigned char )*llvm_cbe_tmp__379;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__380);
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = zext i8 %%25 to i32, !dbg !19 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_875_count);
  llvm_cbe_tmp__381 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__380&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__381);
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = or i32 %%storemerge1, 3, !dbg !19 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_876_count);
  llvm_cbe_tmp__382 = (unsigned int )llvm_cbe_storemerge1 | 3u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__382);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = sext i32 %%27 to i64, !dbg !19 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_877_count);
  llvm_cbe_tmp__383 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__382);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__383);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = getelementptr inbounds %%struct.picnic_publickey_t* %%pk, i64 0, i32 2, i64 %%28, !dbg !19 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_878_count);
  llvm_cbe_tmp__384 = ( char *)(&llvm_cbe_pk->field2[(((signed long long )llvm_cbe_tmp__383))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__383));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = load i8* %%29, align 1, !dbg !19 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_879_count);
  llvm_cbe_tmp__385 = (unsigned char )*llvm_cbe_tmp__384;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__385);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = zext i8 %%30 to i32, !dbg !19 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_880_count);
  llvm_cbe_tmp__386 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__385&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__386);
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = shl nuw nsw i32 %%31, 8, !dbg !19 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_881_count);
  llvm_cbe_tmp__387 = (unsigned int )llvm_cbe_tmp__386 << 8u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__387);
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = or i32 %%32, %%26, !dbg !19 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_882_count);
  llvm_cbe_tmp__388 = (unsigned int )llvm_cbe_tmp__387 | llvm_cbe_tmp__381;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__388);
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = shl nuw nsw i32 %%33, 8, !dbg !19 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_883_count);
  llvm_cbe_tmp__389 = (unsigned int )llvm_cbe_tmp__388 << 8u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__389);
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = or i32 %%34, %%21, !dbg !19 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_884_count);
  llvm_cbe_tmp__390 = (unsigned int )llvm_cbe_tmp__389 | llvm_cbe_tmp__376;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__390);
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = shl nuw nsw i32 %%35, 8, !dbg !19 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_885_count);
  llvm_cbe_tmp__391 = (unsigned int )llvm_cbe_tmp__390 << 8u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__391);
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = or i32 %%36, %%16, !dbg !19 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_886_count);
  llvm_cbe_tmp__392 = (unsigned int )llvm_cbe_tmp__391 | llvm_cbe_tmp__371;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__392);
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = sdiv i32 %%storemerge1, 4, !dbg !19 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_887_count);
  llvm_cbe_tmp__393 = (unsigned int )((signed int )(((signed int )llvm_cbe_storemerge1) / ((signed int )4u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__393));
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = sext i32 %%38 to i64, !dbg !19 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_888_count);
  llvm_cbe_tmp__394 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__393);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__394);
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = getelementptr inbounds [8 x i32]* %%temp, i64 0, i64 %%39, !dbg !19 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_889_count);
  llvm_cbe_tmp__395 = (signed int *)(&llvm_cbe_temp[(((signed long long )llvm_cbe_tmp__394))
#ifdef AESL_BC_SIM
 % 8
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__394));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__394) < 8 && "Write access out of array 'temp' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%37, i32* %%40, align 4, !dbg !19 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_890_count);
  *llvm_cbe_tmp__395 = llvm_cbe_tmp__392;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__392);
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = getelementptr inbounds %%struct.picnic_publickey_t* %%pk, i64 0, i32 1, i64 %%13, !dbg !20 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_891_count);
  llvm_cbe_tmp__396 = ( char *)(&llvm_cbe_pk->field1[(((signed long long )llvm_cbe_tmp__368))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__368));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = load i8* %%41, align 1, !dbg !20 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_892_count);
  llvm_cbe_tmp__397 = (unsigned char )*llvm_cbe_tmp__396;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__397);
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = zext i8 %%42 to i32, !dbg !20 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_893_count);
  llvm_cbe_tmp__398 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__397&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__398);
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = getelementptr inbounds %%struct.picnic_publickey_t* %%pk, i64 0, i32 1, i64 %%18, !dbg !20 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_894_count);
  llvm_cbe_tmp__399 = ( char *)(&llvm_cbe_pk->field1[(((signed long long )llvm_cbe_tmp__373))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__373));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = load i8* %%44, align 1, !dbg !20 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_895_count);
  llvm_cbe_tmp__400 = (unsigned char )*llvm_cbe_tmp__399;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__400);
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = zext i8 %%45 to i32, !dbg !20 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_896_count);
  llvm_cbe_tmp__401 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__400&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__401);
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = getelementptr inbounds %%struct.picnic_publickey_t* %%pk, i64 0, i32 1, i64 %%23, !dbg !20 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_897_count);
  llvm_cbe_tmp__402 = ( char *)(&llvm_cbe_pk->field1[(((signed long long )llvm_cbe_tmp__378))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__378));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = load i8* %%47, align 1, !dbg !20 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_898_count);
  llvm_cbe_tmp__403 = (unsigned char )*llvm_cbe_tmp__402;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__403);
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = zext i8 %%48 to i32, !dbg !20 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_899_count);
  llvm_cbe_tmp__404 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__403&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__404);
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = getelementptr inbounds %%struct.picnic_publickey_t* %%pk, i64 0, i32 1, i64 %%28, !dbg !20 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_900_count);
  llvm_cbe_tmp__405 = ( char *)(&llvm_cbe_pk->field1[(((signed long long )llvm_cbe_tmp__383))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__383));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = load i8* %%50, align 1, !dbg !20 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_901_count);
  llvm_cbe_tmp__406 = (unsigned char )*llvm_cbe_tmp__405;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__406);
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = zext i8 %%51 to i32, !dbg !20 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_902_count);
  llvm_cbe_tmp__407 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__406&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__407);
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = shl nuw nsw i32 %%52, 8, !dbg !20 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_903_count);
  llvm_cbe_tmp__408 = (unsigned int )llvm_cbe_tmp__407 << 8u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__408);
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = or i32 %%53, %%49, !dbg !20 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_904_count);
  llvm_cbe_tmp__409 = (unsigned int )llvm_cbe_tmp__408 | llvm_cbe_tmp__404;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__409);
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = shl nuw nsw i32 %%54, 8, !dbg !20 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_905_count);
  llvm_cbe_tmp__410 = (unsigned int )llvm_cbe_tmp__409 << 8u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__410);
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = or i32 %%55, %%46, !dbg !20 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_906_count);
  llvm_cbe_tmp__411 = (unsigned int )llvm_cbe_tmp__410 | llvm_cbe_tmp__401;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__411);
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = shl nuw nsw i32 %%56, 8, !dbg !20 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_907_count);
  llvm_cbe_tmp__412 = (unsigned int )llvm_cbe_tmp__411 << 8u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__412);
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = or i32 %%57, %%43, !dbg !20 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_908_count);
  llvm_cbe_tmp__413 = (unsigned int )llvm_cbe_tmp__412 | llvm_cbe_tmp__398;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__413);
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = getelementptr inbounds [8 x i32]* %%temp2, i64 0, i64 %%39, !dbg !20 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_909_count);
  llvm_cbe_tmp__414 = (signed int *)(&llvm_cbe_temp2[(((signed long long )llvm_cbe_tmp__394))
#ifdef AESL_BC_SIM
 % 8
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__394));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__394) < 8 && "Write access out of array 'temp2' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%58, i32* %%59, align 4, !dbg !20 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_910_count);
  *llvm_cbe_tmp__414 = llvm_cbe_tmp__413;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__413);
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = add nsw i32 %%storemerge1, 4, !dbg !26 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_911_count);
  llvm_cbe_tmp__415 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(4u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__415&4294967295ull)));
  if ((((signed int )llvm_cbe_tmp__415) < ((signed int )32u))) {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__415;   /* for PHI node */
    goto llvm_cbe_tmp__422;
  } else {
    goto llvm_cbe_tmp__423;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__423:
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = getelementptr inbounds [8 x i32]* %%temp, i64 0, i64 0, !dbg !20 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_940_count);
  llvm_cbe_tmp__416 = (signed int *)(&llvm_cbe_temp[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%64 = getelementptr inbounds [8 x i32]* %%temp2, i64 0, i64 0, !dbg !20 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_941_count);
  llvm_cbe_tmp__417 = (signed int *)(&llvm_cbe_temp2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%65 = call i32 @verify(%%struct.signature_t* %%4, i32* %%63, i32* %%64, i8* %%message, i64 %%message_len, %%struct.paramset_t* %%paramset) nounwind, !dbg !20 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_942_count);
  llvm_cbe_tmp__418 = (unsigned int )verify((l_struct_OC_signature_t *)llvm_cbe_tmp__362, (signed int *)llvm_cbe_tmp__416, (signed int *)llvm_cbe_tmp__417, ( char *)llvm_cbe_message, llvm_cbe_message_len, (l_struct_OC_paramset_t *)(&llvm_cbe_paramset));
if (AESL_DEBUG_TRACE) {
printf("\nArgument message_len = 0x%I64X",llvm_cbe_message_len);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__418);
}
  if (((llvm_cbe_tmp__418&4294967295U) == (0u&4294967295U))) {
    llvm_cbe_tmp__419__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe_tmp__421;
  } else {
    goto llvm_cbe_tmp__424;
  }

llvm_cbe_tmp__424:
if (AESL_DEBUG_TRACE)
printf("\n  call void @freeSignature(%%struct.signature_t* %%4, %%struct.paramset_t* %%paramset) nounwind, !dbg !26 for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_947_count);
  freeSignature((l_struct_OC_signature_t *)llvm_cbe_tmp__362, (l_struct_OC_paramset_t *)(&llvm_cbe_paramset));
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_tmp__419__PHI_TEMPORARY = (unsigned int )4294967295u;   /* for PHI node */
  goto llvm_cbe_tmp__421;

llvm_cbe_tmp__421:
if (AESL_DEBUG_TRACE)
printf("\n  %%69 = phi i32 [ -1, %%67 ], [ -1, %%0 ], [ 0, %%62  for 0x%I64xth hint within @picnic_verify  --> \n", ++aesl_llvm_cbe_949_count);
  llvm_cbe_tmp__419 = (unsigned int )llvm_cbe_tmp__419__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__419);
printf("\n = 0x%X",4294967295u);
printf("\n = 0x%X",4294967295u);
printf("\n = 0x%X",0u);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @picnic_verify}\n");
  return llvm_cbe_tmp__419;
}


signed int picnic_write_public_key(l_struct_OC_picnic_publickey_t *llvm_cbe_key,  char *llvm_cbe_buf, signed long long llvm_cbe_buflen) {
  static  unsigned long long aesl_llvm_cbe_paramset_count = 0;
  l_struct_OC_paramset_t llvm_cbe_paramset;    /* Address-exposed local */
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
   char *llvm_cbe_tmp__425;
  static  unsigned long long aesl_llvm_cbe_964_count = 0;
  unsigned char llvm_cbe_tmp__426;
  static  unsigned long long aesl_llvm_cbe_965_count = 0;
  unsigned int llvm_cbe_tmp__427;
  static  unsigned long long aesl_llvm_cbe_966_count = 0;
  static  unsigned long long aesl_llvm_cbe_967_count = 0;
  static  unsigned long long aesl_llvm_cbe_968_count = 0;
  signed int *llvm_cbe_tmp__428;
  static  unsigned long long aesl_llvm_cbe_969_count = 0;
  unsigned int llvm_cbe_tmp__429;
  static  unsigned long long aesl_llvm_cbe_970_count = 0;
  unsigned int llvm_cbe_tmp__430;
  static  unsigned long long aesl_llvm_cbe_971_count = 0;
  unsigned int llvm_cbe_tmp__431;
  static  unsigned long long aesl_llvm_cbe_972_count = 0;
  unsigned long long llvm_cbe_tmp__432;
  static  unsigned long long aesl_llvm_cbe_973_count = 0;
  static  unsigned long long aesl_llvm_cbe_974_count = 0;
  static  unsigned long long aesl_llvm_cbe_975_count = 0;
  static  unsigned long long aesl_llvm_cbe_976_count = 0;
  static  unsigned long long aesl_llvm_cbe_977_count = 0;
  static  unsigned long long aesl_llvm_cbe_978_count = 0;
  unsigned char llvm_cbe_tmp__433;
  static  unsigned long long aesl_llvm_cbe_979_count = 0;
  unsigned char llvm_cbe_tmp__434;
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
  static  unsigned long long aesl_llvm_cbe_991_count = 0;
  static  unsigned long long aesl_llvm_cbe_992_count = 0;
  static  unsigned long long aesl_llvm_cbe_993_count = 0;
  static  unsigned long long aesl_llvm_cbe_994_count = 0;
  static  unsigned long long aesl_llvm_cbe_995_count = 0;
  static  unsigned long long aesl_llvm_cbe_996_count = 0;
  static  unsigned long long aesl_llvm_cbe_997_count = 0;
  static  unsigned long long aesl_llvm_cbe_998_count = 0;
  static  unsigned long long aesl_llvm_cbe_999_count = 0;
  static  unsigned long long aesl_llvm_cbe_1000_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned int llvm_cbe_storemerge3;
  unsigned int llvm_cbe_storemerge3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1001_count = 0;
  unsigned long long llvm_cbe_tmp__435;
  static  unsigned long long aesl_llvm_cbe_1002_count = 0;
   char *llvm_cbe_tmp__436;
  static  unsigned long long aesl_llvm_cbe_1003_count = 0;
  unsigned char llvm_cbe_tmp__437;
  static  unsigned long long aesl_llvm_cbe_1004_count = 0;
  unsigned int llvm_cbe_tmp__438;
  static  unsigned long long aesl_llvm_cbe_1005_count = 0;
  unsigned long long llvm_cbe_tmp__439;
  static  unsigned long long aesl_llvm_cbe_1006_count = 0;
   char *llvm_cbe_tmp__440;
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
  static  unsigned long long aesl_llvm_cbe_storemerge12_count = 0;
  unsigned int llvm_cbe_storemerge12;
  unsigned int llvm_cbe_storemerge12__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1019_count = 0;
  unsigned long long llvm_cbe_tmp__441;
  static  unsigned long long aesl_llvm_cbe_1020_count = 0;
   char *llvm_cbe_tmp__442;
  static  unsigned long long aesl_llvm_cbe_1021_count = 0;
  unsigned char llvm_cbe_tmp__443;
  static  unsigned long long aesl_llvm_cbe_1022_count = 0;
  unsigned int llvm_cbe_tmp__444;
  static  unsigned long long aesl_llvm_cbe_1023_count = 0;
  unsigned int llvm_cbe_tmp__445;
  static  unsigned long long aesl_llvm_cbe_1024_count = 0;
  unsigned long long llvm_cbe_tmp__446;
  static  unsigned long long aesl_llvm_cbe_1025_count = 0;
   char *llvm_cbe_tmp__447;
  static  unsigned long long aesl_llvm_cbe_1026_count = 0;
  static  unsigned long long aesl_llvm_cbe_1027_count = 0;
  static  unsigned long long aesl_llvm_cbe_1028_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_1039_count = 0;
  unsigned int llvm_cbe_tmp__448;
  unsigned int llvm_cbe_tmp__448__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1040_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @picnic_write_public_key\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.picnic_publickey_t* %%key, i64 0, i32 0, !dbg !19 for 0x%I64xth hint within @picnic_write_public_key  --> \n", ++aesl_llvm_cbe_963_count);
  llvm_cbe_tmp__425 = ( char *)(&llvm_cbe_key->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i4* %%1, align 1, !dbg !19 for 0x%I64xth hint within @picnic_write_public_key  --> \n", ++aesl_llvm_cbe_964_count);
  llvm_cbe_tmp__426 = (unsigned char )*llvm_cbe_tmp__425;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__426);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = call i32 @get_param_set(i4 zeroext %%2, %%struct.paramset_t* %%paramset), !dbg !19 for 0x%I64xth hint within @picnic_write_public_key  --> \n", ++aesl_llvm_cbe_965_count);
  get_param_set(llvm_cbe_tmp__426, (l_struct_OC_paramset_t *)(&llvm_cbe_paramset));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__426);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__427);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds %%struct.paramset_t* %%paramset, i64 0, i32 3, !dbg !21 for 0x%I64xth hint within @picnic_write_public_key  --> \n", ++aesl_llvm_cbe_968_count);
  llvm_cbe_tmp__428 = (signed int *)(&llvm_cbe_paramset.field3);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load i32* %%4, align 4, !dbg !21 for 0x%I64xth hint within @picnic_write_public_key  --> \n", ++aesl_llvm_cbe_969_count);
  llvm_cbe_tmp__429 = (unsigned int )*llvm_cbe_tmp__428;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__429);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = shl i32 %%5, 1, !dbg !21 for 0x%I64xth hint within @picnic_write_public_key  --> \n", ++aesl_llvm_cbe_970_count);
  llvm_cbe_tmp__430 = (unsigned int )llvm_cbe_tmp__429 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__430);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = or i32 %%6, 1, !dbg !21 for 0x%I64xth hint within @picnic_write_public_key  --> \n", ++aesl_llvm_cbe_971_count);
  llvm_cbe_tmp__431 = (unsigned int )llvm_cbe_tmp__430 | 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__431);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = zext i32 %%7 to i64, !dbg !21 for 0x%I64xth hint within @picnic_write_public_key  --> \n", ++aesl_llvm_cbe_972_count);
  llvm_cbe_tmp__432 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__431&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__432);
  if ((((unsigned long long )llvm_cbe_tmp__432&18446744073709551615ULL) > ((unsigned long long )llvm_cbe_buflen&18446744073709551615ULL))) {
    llvm_cbe_tmp__448__PHI_TEMPORARY = (unsigned int )4294967295u;   /* for PHI node */
    goto llvm_cbe_tmp__449;
  } else {
    goto llvm_cbe_tmp__450;
  }

llvm_cbe_tmp__450:
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = load i4* %%1, align 1, !dbg !19 for 0x%I64xth hint within @picnic_write_public_key  --> \n", ++aesl_llvm_cbe_978_count);
  llvm_cbe_tmp__433 = (unsigned char )*llvm_cbe_tmp__425;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__433);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = zext i4 %%11 to i8, !dbg !19 for 0x%I64xth hint within @picnic_write_public_key  --> \n", ++aesl_llvm_cbe_979_count);
  llvm_cbe_tmp__434 = (unsigned char )((unsigned char )(unsigned char )llvm_cbe_tmp__433&15U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__434);
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%12, i8* %%buf, align 1, !dbg !19 for 0x%I64xth hint within @picnic_write_public_key  --> \n", ++aesl_llvm_cbe_980_count);
  *llvm_cbe_buf = llvm_cbe_tmp__434;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__434);
  if (((llvm_cbe_tmp__429&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe__2e_loopexit;
  } else {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph4;
  }

llvm_cbe__2e_preheader:
  if (((llvm_cbe_tmp__429&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe__2e_loopexit;
  } else {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '.lr.ph4' to make GCC happy */
llvm_cbe__2e_lr_2e_ph4:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = phi i32 [ %%17, %%.lr.ph4 ], [ 0, %%10  for 0x%I64xth hint within @picnic_write_public_key  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned int )llvm_cbe_storemerge3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%X",llvm_cbe_storemerge3);
printf("\n = 0x%X",llvm_cbe_tmp__438);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = sext i32 %%storemerge3 to i64, !dbg !20 for 0x%I64xth hint within @picnic_write_public_key  --> \n", ++aesl_llvm_cbe_1001_count);
  llvm_cbe_tmp__435 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge3);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__435);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds %%struct.picnic_publickey_t* %%key, i64 0, i32 2, i64 %%14, !dbg !20 for 0x%I64xth hint within @picnic_write_public_key  --> \n", ++aesl_llvm_cbe_1002_count);
  llvm_cbe_tmp__436 = ( char *)(&llvm_cbe_key->field2[(((signed long long )llvm_cbe_tmp__435))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__435));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = load i8* %%15, align 1, !dbg !20 for 0x%I64xth hint within @picnic_write_public_key  --> \n", ++aesl_llvm_cbe_1003_count);
  llvm_cbe_tmp__437 = (unsigned char )*llvm_cbe_tmp__436;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__437);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = add nsw i32 %%storemerge3, 1, !dbg !20 for 0x%I64xth hint within @picnic_write_public_key  --> \n", ++aesl_llvm_cbe_1004_count);
  llvm_cbe_tmp__438 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__438&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = sext i32 %%17 to i64, !dbg !20 for 0x%I64xth hint within @picnic_write_public_key  --> \n", ++aesl_llvm_cbe_1005_count);
  llvm_cbe_tmp__439 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__438);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__439);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = getelementptr inbounds i8* %%buf, i64 %%18, !dbg !20 for 0x%I64xth hint within @picnic_write_public_key  --> \n", ++aesl_llvm_cbe_1006_count);
  llvm_cbe_tmp__440 = ( char *)(&llvm_cbe_buf[(((signed long long )llvm_cbe_tmp__439))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__439));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%16, i8* %%19, align 1, !dbg !20 for 0x%I64xth hint within @picnic_write_public_key  --> \n", ++aesl_llvm_cbe_1007_count);
  *llvm_cbe_tmp__440 = llvm_cbe_tmp__437;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__437);
  if ((((unsigned int )llvm_cbe_tmp__438&4294967295U) < ((unsigned int )llvm_cbe_tmp__429&4294967295U))) {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__438;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph4;
  } else {
    goto llvm_cbe__2e_preheader;
  }

  } while (1); /* end of syntactic loop '.lr.ph4' */
  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12 = phi i32 [ %%24, %%.lr.ph ], [ 0, %%.preheader  for 0x%I64xth hint within @picnic_write_public_key  --> \n", ++aesl_llvm_cbe_storemerge12_count);
  llvm_cbe_storemerge12 = (unsigned int )llvm_cbe_storemerge12__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%X",llvm_cbe_storemerge12);
printf("\n = 0x%X",llvm_cbe_tmp__444);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = sext i32 %%storemerge12 to i64, !dbg !20 for 0x%I64xth hint within @picnic_write_public_key  --> \n", ++aesl_llvm_cbe_1019_count);
  llvm_cbe_tmp__441 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge12);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__441);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = getelementptr inbounds %%struct.picnic_publickey_t* %%key, i64 0, i32 1, i64 %%21, !dbg !20 for 0x%I64xth hint within @picnic_write_public_key  --> \n", ++aesl_llvm_cbe_1020_count);
  llvm_cbe_tmp__442 = ( char *)(&llvm_cbe_key->field1[(((signed long long )llvm_cbe_tmp__441))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__441));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = load i8* %%22, align 1, !dbg !20 for 0x%I64xth hint within @picnic_write_public_key  --> \n", ++aesl_llvm_cbe_1021_count);
  llvm_cbe_tmp__443 = (unsigned char )*llvm_cbe_tmp__442;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__443);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = add i32 %%storemerge12, 1, !dbg !20 for 0x%I64xth hint within @picnic_write_public_key  --> \n", ++aesl_llvm_cbe_1022_count);
  llvm_cbe_tmp__444 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__444&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = add i32 %%24, %%5, !dbg !20 for 0x%I64xth hint within @picnic_write_public_key  --> \n", ++aesl_llvm_cbe_1023_count);
  llvm_cbe_tmp__445 = (unsigned int )((unsigned int )(llvm_cbe_tmp__444&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__429&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__445&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = zext i32 %%25 to i64, !dbg !20 for 0x%I64xth hint within @picnic_write_public_key  --> \n", ++aesl_llvm_cbe_1024_count);
  llvm_cbe_tmp__446 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__445&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__446);
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = getelementptr inbounds i8* %%buf, i64 %%26, !dbg !20 for 0x%I64xth hint within @picnic_write_public_key  --> \n", ++aesl_llvm_cbe_1025_count);
  llvm_cbe_tmp__447 = ( char *)(&llvm_cbe_buf[(((signed long long )llvm_cbe_tmp__446))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__446));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%23, i8* %%27, align 1, !dbg !20 for 0x%I64xth hint within @picnic_write_public_key  --> \n", ++aesl_llvm_cbe_1026_count);
  *llvm_cbe_tmp__447 = llvm_cbe_tmp__443;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__443);
  if ((((unsigned int )llvm_cbe_tmp__444&4294967295U) < ((unsigned int )llvm_cbe_tmp__429&4294967295U))) {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__444;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e_loopexit;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e_loopexit:
  llvm_cbe_tmp__448__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__431;   /* for PHI node */
  goto llvm_cbe_tmp__449;

llvm_cbe_tmp__449:
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = phi i32 [ -1, %%0 ], [ %%7, %%.loopexit  for 0x%I64xth hint within @picnic_write_public_key  --> \n", ++aesl_llvm_cbe_1039_count);
  llvm_cbe_tmp__448 = (unsigned int )llvm_cbe_tmp__448__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__448);
printf("\n = 0x%X",4294967295u);
printf("\n = 0x%X",llvm_cbe_tmp__431);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @picnic_write_public_key}\n");
  return llvm_cbe_tmp__448;
}


signed int picnic_read_public_key(l_struct_OC_picnic_publickey_t *llvm_cbe_key,  char *llvm_cbe_buf, signed long long llvm_cbe_buflen) {
  static  unsigned long long aesl_llvm_cbe_paramset_count = 0;
  l_struct_OC_paramset_t llvm_cbe_paramset;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_1041_count = 0;
  static  unsigned long long aesl_llvm_cbe_1042_count = 0;
  static  unsigned long long aesl_llvm_cbe_1043_count = 0;
  static  unsigned long long aesl_llvm_cbe_1044_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_1056_count = 0;
  unsigned char llvm_cbe_tmp__451;
  static  unsigned long long aesl_llvm_cbe_1057_count = 0;
  unsigned char llvm_cbe_tmp__452;
  static  unsigned long long aesl_llvm_cbe_1058_count = 0;
  unsigned int llvm_cbe_tmp__453;
  static  unsigned long long aesl_llvm_cbe_1059_count = 0;
  static  unsigned long long aesl_llvm_cbe_1060_count = 0;
  static  unsigned long long aesl_llvm_cbe_1061_count = 0;
  static  unsigned long long aesl_llvm_cbe_1062_count = 0;
  unsigned char llvm_cbe_tmp__454;
  static  unsigned long long aesl_llvm_cbe_1063_count = 0;
  unsigned char llvm_cbe_tmp__455;
  static  unsigned long long aesl_llvm_cbe_1064_count = 0;
   char *llvm_cbe_tmp__456;
  static  unsigned long long aesl_llvm_cbe_1065_count = 0;
  static  unsigned long long aesl_llvm_cbe_1066_count = 0;
  static  unsigned long long aesl_llvm_cbe_1067_count = 0;
  unsigned int llvm_cbe_tmp__457;
  static  unsigned long long aesl_llvm_cbe_1068_count = 0;
  static  unsigned long long aesl_llvm_cbe_1069_count = 0;
  static  unsigned long long aesl_llvm_cbe_1070_count = 0;
  signed int *llvm_cbe_tmp__458;
  static  unsigned long long aesl_llvm_cbe_1071_count = 0;
  unsigned int llvm_cbe_tmp__459;
  static  unsigned long long aesl_llvm_cbe_1072_count = 0;
  unsigned int llvm_cbe_tmp__460;
  static  unsigned long long aesl_llvm_cbe_1073_count = 0;
  unsigned int llvm_cbe_tmp__461;
  static  unsigned long long aesl_llvm_cbe_1074_count = 0;
  unsigned long long llvm_cbe_tmp__462;
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
  static  unsigned long long aesl_llvm_cbe_1089_count = 0;
  static  unsigned long long aesl_llvm_cbe_1090_count = 0;
  static  unsigned long long aesl_llvm_cbe_1091_count = 0;
  static  unsigned long long aesl_llvm_cbe_1092_count = 0;
  static  unsigned long long aesl_llvm_cbe_1093_count = 0;
  static  unsigned long long aesl_llvm_cbe_1094_count = 0;
  static  unsigned long long aesl_llvm_cbe_1095_count = 0;
  static  unsigned long long aesl_llvm_cbe_1096_count = 0;
  static  unsigned long long aesl_llvm_cbe_1097_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge4_count = 0;
  unsigned int llvm_cbe_storemerge4;
  unsigned int llvm_cbe_storemerge4__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1098_count = 0;
  unsigned int llvm_cbe_tmp__463;
  static  unsigned long long aesl_llvm_cbe_1099_count = 0;
  unsigned long long llvm_cbe_tmp__464;
  static  unsigned long long aesl_llvm_cbe_1100_count = 0;
   char *llvm_cbe_tmp__465;
  static  unsigned long long aesl_llvm_cbe_1101_count = 0;
  unsigned char llvm_cbe_tmp__466;
  static  unsigned long long aesl_llvm_cbe_1102_count = 0;
  unsigned long long llvm_cbe_tmp__467;
  static  unsigned long long aesl_llvm_cbe_1103_count = 0;
   char *llvm_cbe_tmp__468;
  static  unsigned long long aesl_llvm_cbe_1104_count = 0;
  static  unsigned long long aesl_llvm_cbe_1105_count = 0;
  static  unsigned long long aesl_llvm_cbe_1106_count = 0;
  static  unsigned long long aesl_llvm_cbe_1107_count = 0;
  static  unsigned long long aesl_llvm_cbe_1108_count = 0;
  static  unsigned long long aesl_llvm_cbe_1109_count = 0;
  static  unsigned long long aesl_llvm_cbe_1110_count = 0;
  static  unsigned long long aesl_llvm_cbe_1111_count = 0;
  static  unsigned long long aesl_llvm_cbe_1112_count = 0;
  static  unsigned long long aesl_llvm_cbe_1113_count = 0;
  static  unsigned long long aesl_llvm_cbe_1114_count = 0;
  static  unsigned long long aesl_llvm_cbe_1115_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_count = 0;
  unsigned int llvm_cbe_storemerge12;
  unsigned int llvm_cbe_storemerge12__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1116_count = 0;
  unsigned int llvm_cbe_tmp__469;
  static  unsigned long long aesl_llvm_cbe_1117_count = 0;
  unsigned int llvm_cbe_tmp__470;
  static  unsigned long long aesl_llvm_cbe_1118_count = 0;
  unsigned long long llvm_cbe_tmp__471;
  static  unsigned long long aesl_llvm_cbe_1119_count = 0;
   char *llvm_cbe_tmp__472;
  static  unsigned long long aesl_llvm_cbe_1120_count = 0;
  unsigned char llvm_cbe_tmp__473;
  static  unsigned long long aesl_llvm_cbe_1121_count = 0;
  unsigned long long llvm_cbe_tmp__474;
  static  unsigned long long aesl_llvm_cbe_1122_count = 0;
   char *llvm_cbe_tmp__475;
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
  unsigned int llvm_cbe_tmp__476;
  unsigned int llvm_cbe_tmp__476__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1137_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @picnic_read_public_key\n");
  if (((llvm_cbe_buflen&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__477;
  } else {
    goto llvm_cbe_tmp__478;
  }

llvm_cbe_tmp__478:
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = load i8* %%buf, align 1, !dbg !20 for 0x%I64xth hint within @picnic_read_public_key  --> \n", ++aesl_llvm_cbe_1056_count);
  llvm_cbe_tmp__451 = (unsigned char )*llvm_cbe_buf;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__451);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = trunc i8 %%3 to i4, !dbg !20 for 0x%I64xth hint within @picnic_read_public_key  --> \n", ++aesl_llvm_cbe_1057_count);
  llvm_cbe_tmp__452 = (unsigned char )((unsigned char )llvm_cbe_tmp__451&15U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__452);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = call fastcc i32 @aesl_internal_is_valid_params(i4 zeroext %%4), !dbg !20 for 0x%I64xth hint within @picnic_read_public_key  --> \n", ++aesl_llvm_cbe_1058_count);
  llvm_cbe_tmp__453 = (unsigned int )aesl_internal_is_valid_params(llvm_cbe_tmp__452);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__452);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__453);
}
  if (((llvm_cbe_tmp__453&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__477;
  } else {
    goto llvm_cbe_tmp__479;
  }

llvm_cbe_tmp__477:
  llvm_cbe_tmp__476__PHI_TEMPORARY = (unsigned int )4294967295u;   /* for PHI node */
  goto llvm_cbe_tmp__480;

llvm_cbe_tmp__479:
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = load i8* %%buf, align 1, !dbg !19 for 0x%I64xth hint within @picnic_read_public_key  --> \n", ++aesl_llvm_cbe_1062_count);
  llvm_cbe_tmp__454 = (unsigned char )*llvm_cbe_buf;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__454);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = trunc i8 %%9 to i4, !dbg !19 for 0x%I64xth hint within @picnic_read_public_key  --> \n", ++aesl_llvm_cbe_1063_count);
  llvm_cbe_tmp__455 = (unsigned char )((unsigned char )llvm_cbe_tmp__454&15U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__455);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds %%struct.picnic_publickey_t* %%key, i64 0, i32 0, !dbg !19 for 0x%I64xth hint within @picnic_read_public_key  --> \n", ++aesl_llvm_cbe_1064_count);
  llvm_cbe_tmp__456 = ( char *)(&llvm_cbe_key->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i4 %%10, i4* %%11, align 1, !dbg !19 for 0x%I64xth hint within @picnic_read_public_key  --> \n", ++aesl_llvm_cbe_1065_count);
  *llvm_cbe_tmp__456 = ((llvm_cbe_tmp__455) & 15ull);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__455);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = call i32 @get_param_set(i4 zeroext %%10, %%struct.paramset_t* %%paramset), !dbg !19 for 0x%I64xth hint within @picnic_read_public_key  --> \n", ++aesl_llvm_cbe_1067_count);
  get_param_set(llvm_cbe_tmp__455, (l_struct_OC_paramset_t *)(&llvm_cbe_paramset));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__455);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__457);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds %%struct.paramset_t* %%paramset, i64 0, i32 3, !dbg !21 for 0x%I64xth hint within @picnic_read_public_key  --> \n", ++aesl_llvm_cbe_1070_count);
  llvm_cbe_tmp__458 = (signed int *)(&llvm_cbe_paramset.field3);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load i32* %%13, align 4, !dbg !21 for 0x%I64xth hint within @picnic_read_public_key  --> \n", ++aesl_llvm_cbe_1071_count);
  llvm_cbe_tmp__459 = (unsigned int )*llvm_cbe_tmp__458;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__459);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = shl i32 %%14, 1, !dbg !21 for 0x%I64xth hint within @picnic_read_public_key  --> \n", ++aesl_llvm_cbe_1072_count);
  llvm_cbe_tmp__460 = (unsigned int )llvm_cbe_tmp__459 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__460);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = or i32 %%15, 1, !dbg !21 for 0x%I64xth hint within @picnic_read_public_key  --> \n", ++aesl_llvm_cbe_1073_count);
  llvm_cbe_tmp__461 = (unsigned int )llvm_cbe_tmp__460 | 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__461);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = zext i32 %%16 to i64, !dbg !21 for 0x%I64xth hint within @picnic_read_public_key  --> \n", ++aesl_llvm_cbe_1074_count);
  llvm_cbe_tmp__462 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__461&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__462);
  if ((((unsigned long long )llvm_cbe_tmp__462&18446744073709551615ULL) > ((unsigned long long )llvm_cbe_buflen&18446744073709551615ULL))) {
    llvm_cbe_tmp__476__PHI_TEMPORARY = (unsigned int )4294967295u;   /* for PHI node */
    goto llvm_cbe_tmp__480;
  } else {
    goto llvm_cbe__2e_preheader3;
  }

llvm_cbe__2e_preheader3:
  if (((llvm_cbe_tmp__459&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe__2e_loopexit;
  } else {
    llvm_cbe_storemerge4__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph5;
  }

llvm_cbe__2e_preheader:
  if (((llvm_cbe_tmp__459&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe__2e_loopexit;
  } else {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '.lr.ph5' to make GCC happy */
llvm_cbe__2e_lr_2e_ph5:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge4 = phi i32 [ %%20, %%.lr.ph5 ], [ 0, %%.preheader3  for 0x%I64xth hint within @picnic_read_public_key  --> \n", ++aesl_llvm_cbe_storemerge4_count);
  llvm_cbe_storemerge4 = (unsigned int )llvm_cbe_storemerge4__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge4 = 0x%X",llvm_cbe_storemerge4);
printf("\n = 0x%X",llvm_cbe_tmp__463);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = add nsw i32 %%storemerge4, 1, !dbg !20 for 0x%I64xth hint within @picnic_read_public_key  --> \n", ++aesl_llvm_cbe_1098_count);
  llvm_cbe_tmp__463 = (unsigned int )((unsigned int )(llvm_cbe_storemerge4&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__463&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = sext i32 %%20 to i64, !dbg !20 for 0x%I64xth hint within @picnic_read_public_key  --> \n", ++aesl_llvm_cbe_1099_count);
  llvm_cbe_tmp__464 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__463);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__464);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = getelementptr inbounds i8* %%buf, i64 %%21, !dbg !20 for 0x%I64xth hint within @picnic_read_public_key  --> \n", ++aesl_llvm_cbe_1100_count);
  llvm_cbe_tmp__465 = ( char *)(&llvm_cbe_buf[(((signed long long )llvm_cbe_tmp__464))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__464));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = load i8* %%22, align 1, !dbg !20 for 0x%I64xth hint within @picnic_read_public_key  --> \n", ++aesl_llvm_cbe_1101_count);
  llvm_cbe_tmp__466 = (unsigned char )*llvm_cbe_tmp__465;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__466);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = sext i32 %%storemerge4 to i64, !dbg !20 for 0x%I64xth hint within @picnic_read_public_key  --> \n", ++aesl_llvm_cbe_1102_count);
  llvm_cbe_tmp__467 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge4);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__467);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = getelementptr inbounds %%struct.picnic_publickey_t* %%key, i64 0, i32 2, i64 %%24, !dbg !20 for 0x%I64xth hint within @picnic_read_public_key  --> \n", ++aesl_llvm_cbe_1103_count);
  llvm_cbe_tmp__468 = ( char *)(&llvm_cbe_key->field2[(((signed long long )llvm_cbe_tmp__467))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__467));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%23, i8* %%25, align 1, !dbg !20 for 0x%I64xth hint within @picnic_read_public_key  --> \n", ++aesl_llvm_cbe_1104_count);
  *llvm_cbe_tmp__468 = llvm_cbe_tmp__466;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__466);
  if ((((unsigned int )llvm_cbe_tmp__463&4294967295U) < ((unsigned int )llvm_cbe_tmp__459&4294967295U))) {
    llvm_cbe_storemerge4__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__463;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph5;
  } else {
    goto llvm_cbe__2e_preheader;
  }

  } while (1); /* end of syntactic loop '.lr.ph5' */
  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12 = phi i32 [ %%27, %%.lr.ph ], [ 0, %%.preheader  for 0x%I64xth hint within @picnic_read_public_key  --> \n", ++aesl_llvm_cbe_storemerge12_count);
  llvm_cbe_storemerge12 = (unsigned int )llvm_cbe_storemerge12__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%X",llvm_cbe_storemerge12);
printf("\n = 0x%X",llvm_cbe_tmp__469);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = add nsw i32 %%storemerge12, 1, !dbg !20 for 0x%I64xth hint within @picnic_read_public_key  --> \n", ++aesl_llvm_cbe_1116_count);
  llvm_cbe_tmp__469 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__469&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = add i32 %%27, %%14, !dbg !20 for 0x%I64xth hint within @picnic_read_public_key  --> \n", ++aesl_llvm_cbe_1117_count);
  llvm_cbe_tmp__470 = (unsigned int )((unsigned int )(llvm_cbe_tmp__469&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__459&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__470&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = zext i32 %%28 to i64, !dbg !20 for 0x%I64xth hint within @picnic_read_public_key  --> \n", ++aesl_llvm_cbe_1118_count);
  llvm_cbe_tmp__471 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__470&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__471);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = getelementptr inbounds i8* %%buf, i64 %%29, !dbg !20 for 0x%I64xth hint within @picnic_read_public_key  --> \n", ++aesl_llvm_cbe_1119_count);
  llvm_cbe_tmp__472 = ( char *)(&llvm_cbe_buf[(((signed long long )llvm_cbe_tmp__471))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__471));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = load i8* %%30, align 1, !dbg !20 for 0x%I64xth hint within @picnic_read_public_key  --> \n", ++aesl_llvm_cbe_1120_count);
  llvm_cbe_tmp__473 = (unsigned char )*llvm_cbe_tmp__472;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__473);
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = sext i32 %%storemerge12 to i64, !dbg !20 for 0x%I64xth hint within @picnic_read_public_key  --> \n", ++aesl_llvm_cbe_1121_count);
  llvm_cbe_tmp__474 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge12);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__474);
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = getelementptr inbounds %%struct.picnic_publickey_t* %%key, i64 0, i32 1, i64 %%32, !dbg !20 for 0x%I64xth hint within @picnic_read_public_key  --> \n", ++aesl_llvm_cbe_1122_count);
  llvm_cbe_tmp__475 = ( char *)(&llvm_cbe_key->field1[(((signed long long )llvm_cbe_tmp__474))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__474));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%31, i8* %%33, align 1, !dbg !20 for 0x%I64xth hint within @picnic_read_public_key  --> \n", ++aesl_llvm_cbe_1123_count);
  *llvm_cbe_tmp__475 = llvm_cbe_tmp__473;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__473);
  if ((((unsigned int )llvm_cbe_tmp__469&4294967295U) < ((unsigned int )llvm_cbe_tmp__459&4294967295U))) {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__469;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e_loopexit;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e_loopexit:
  llvm_cbe_tmp__476__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__480;

llvm_cbe_tmp__480:
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = phi i32 [ -1, %%7 ], [ -1, %%8 ], [ 0, %%.loopexit  for 0x%I64xth hint within @picnic_read_public_key  --> \n", ++aesl_llvm_cbe_1136_count);
  llvm_cbe_tmp__476 = (unsigned int )llvm_cbe_tmp__476__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__476);
printf("\n = 0x%X",4294967295u);
printf("\n = 0x%X",4294967295u);
printf("\n = 0x%X",0u);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @picnic_read_public_key}\n");
  return llvm_cbe_tmp__476;
}


signed int picnic_write_private_key(l_struct_OC_picnic_privatekey_t *llvm_cbe_key,  char *llvm_cbe_buf, signed long long llvm_cbe_buflen) {
  static  unsigned long long aesl_llvm_cbe_paramset_count = 0;
  l_struct_OC_paramset_t llvm_cbe_paramset;    /* Address-exposed local */
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
  static  unsigned long long aesl_llvm_cbe_1151_count = 0;
  static  unsigned long long aesl_llvm_cbe_1152_count = 0;
  static  unsigned long long aesl_llvm_cbe_1153_count = 0;
   char *llvm_cbe_tmp__481;
  static  unsigned long long aesl_llvm_cbe_1154_count = 0;
  unsigned char llvm_cbe_tmp__482;
  static  unsigned long long aesl_llvm_cbe_1155_count = 0;
  unsigned int llvm_cbe_tmp__483;
  static  unsigned long long aesl_llvm_cbe_1156_count = 0;
  static  unsigned long long aesl_llvm_cbe_1157_count = 0;
  static  unsigned long long aesl_llvm_cbe_1158_count = 0;
  signed int *llvm_cbe_tmp__484;
  static  unsigned long long aesl_llvm_cbe_1159_count = 0;
  unsigned int llvm_cbe_tmp__485;
  static  unsigned long long aesl_llvm_cbe_1160_count = 0;
  unsigned long long llvm_cbe_tmp__486;
  static  unsigned long long aesl_llvm_cbe_1161_count = 0;
  static  unsigned long long aesl_llvm_cbe_1162_count = 0;
  static  unsigned long long aesl_llvm_cbe_1163_count = 0;
  static  unsigned long long aesl_llvm_cbe_1164_count = 0;
  static  unsigned long long aesl_llvm_cbe_1165_count = 0;
  static  unsigned long long aesl_llvm_cbe_1166_count = 0;
  unsigned long long llvm_cbe_tmp__487;
  static  unsigned long long aesl_llvm_cbe_1167_count = 0;
  unsigned long long llvm_cbe_tmp__488;
  static  unsigned long long aesl_llvm_cbe_1168_count = 0;
  static  unsigned long long aesl_llvm_cbe_1169_count = 0;
  static  unsigned long long aesl_llvm_cbe_1170_count = 0;
  static  unsigned long long aesl_llvm_cbe_1171_count = 0;
  static  unsigned long long aesl_llvm_cbe_1172_count = 0;
  static  unsigned long long aesl_llvm_cbe_1173_count = 0;
  static  unsigned long long aesl_llvm_cbe_1174_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__489;
  static  unsigned long long aesl_llvm_cbe_1175_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__490;
  static  unsigned long long aesl_llvm_cbe_1176_count = 0;
  unsigned int llvm_cbe_tmp__491;
  static  unsigned long long aesl_llvm_cbe_1177_count = 0;
  unsigned int llvm_cbe_tmp__492;
  static  unsigned long long aesl_llvm_cbe_1178_count = 0;
  unsigned int llvm_cbe_tmp__493;
  static  unsigned long long aesl_llvm_cbe_1179_count = 0;
  static  unsigned long long aesl_llvm_cbe_1180_count = 0;
  unsigned char llvm_cbe_tmp__494;
  static  unsigned long long aesl_llvm_cbe_1181_count = 0;
  unsigned char llvm_cbe_tmp__495;
  static  unsigned long long aesl_llvm_cbe_1182_count = 0;
  static  unsigned long long aesl_llvm_cbe_1183_count = 0;
  static  unsigned long long aesl_llvm_cbe_1184_count = 0;
  static  unsigned long long aesl_llvm_cbe_1185_count = 0;
  static  unsigned long long aesl_llvm_cbe_1186_count = 0;
  static  unsigned long long aesl_llvm_cbe_1187_count = 0;
  static  unsigned long long aesl_llvm_cbe_1188_count = 0;
  static  unsigned long long aesl_llvm_cbe_1189_count = 0;
  static  unsigned long long aesl_llvm_cbe_1190_count = 0;
  static  unsigned long long aesl_llvm_cbe_1191_count = 0;
  static  unsigned long long aesl_llvm_cbe_1192_count = 0;
  static  unsigned long long aesl_llvm_cbe_1193_count = 0;
  static  unsigned long long aesl_llvm_cbe_1194_count = 0;
  unsigned long long llvm_cbe_tmp__496;
  static  unsigned long long aesl_llvm_cbe_1195_count = 0;
  unsigned long long llvm_cbe_tmp__497;
  static  unsigned long long aesl_llvm_cbe_1196_count = 0;
  unsigned long long llvm_cbe_tmp__498;
  static  unsigned long long aesl_llvm_cbe_1197_count = 0;
  static  unsigned long long aesl_llvm_cbe_1198_count = 0;
  unsigned long long llvm_cbe_tmp__499;
  unsigned long long llvm_cbe_tmp__499__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1199_count = 0;
   char *llvm_cbe_tmp__500;
  static  unsigned long long aesl_llvm_cbe_1200_count = 0;
  unsigned char llvm_cbe_tmp__501;
  static  unsigned long long aesl_llvm_cbe_1201_count = 0;
  unsigned int llvm_cbe_tmp__502;
  static  unsigned long long aesl_llvm_cbe_1202_count = 0;
  unsigned long long llvm_cbe_tmp__503;
  static  unsigned long long aesl_llvm_cbe_1203_count = 0;
   char *llvm_cbe_tmp__504;
  static  unsigned long long aesl_llvm_cbe_1204_count = 0;
  static  unsigned long long aesl_llvm_cbe_1205_count = 0;
   char *llvm_cbe_tmp__505;
  static  unsigned long long aesl_llvm_cbe_1206_count = 0;
  unsigned char llvm_cbe_tmp__506;
  static  unsigned long long aesl_llvm_cbe_1207_count = 0;
  unsigned long long llvm_cbe_tmp__507;
  static  unsigned long long aesl_llvm_cbe_1208_count = 0;
   char *llvm_cbe_tmp__508;
  static  unsigned long long aesl_llvm_cbe_1209_count = 0;
  static  unsigned long long aesl_llvm_cbe_1210_count = 0;
   char *llvm_cbe_tmp__509;
  static  unsigned long long aesl_llvm_cbe_1211_count = 0;
  unsigned char llvm_cbe_tmp__510;
  static  unsigned long long aesl_llvm_cbe_1212_count = 0;
  unsigned long long llvm_cbe_tmp__511;
  static  unsigned long long aesl_llvm_cbe_1213_count = 0;
   char *llvm_cbe_tmp__512;
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
  unsigned int llvm_cbe_tmp__513;
  static  unsigned long long aesl_llvm_cbe_1227_count = 0;
  static  unsigned long long aesl_llvm_cbe_1228_count = 0;
  unsigned int llvm_cbe_tmp__514;
  unsigned int llvm_cbe_tmp__514__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1229_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @picnic_write_private_key\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.picnic_privatekey_t* %%key, i64 0, i32 0, !dbg !19 for 0x%I64xth hint within @picnic_write_private_key  --> \n", ++aesl_llvm_cbe_1153_count);
  llvm_cbe_tmp__481 = ( char *)(&llvm_cbe_key->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i4* %%1, align 1, !dbg !19 for 0x%I64xth hint within @picnic_write_private_key  --> \n", ++aesl_llvm_cbe_1154_count);
  llvm_cbe_tmp__482 = (unsigned char )*llvm_cbe_tmp__481;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__482);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = call i32 @get_param_set(i4 zeroext %%2, %%struct.paramset_t* %%paramset), !dbg !19 for 0x%I64xth hint within @picnic_write_private_key  --> \n", ++aesl_llvm_cbe_1155_count);
  get_param_set(llvm_cbe_tmp__482, (l_struct_OC_paramset_t *)(&llvm_cbe_paramset));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__482);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__483);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds %%struct.paramset_t* %%paramset, i64 0, i32 3, !dbg !21 for 0x%I64xth hint within @picnic_write_private_key  --> \n", ++aesl_llvm_cbe_1158_count);
  llvm_cbe_tmp__484 = (signed int *)(&llvm_cbe_paramset.field3);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load i32* %%4, align 4, !dbg !21 for 0x%I64xth hint within @picnic_write_private_key  --> \n", ++aesl_llvm_cbe_1159_count);
  llvm_cbe_tmp__485 = (unsigned int )*llvm_cbe_tmp__484;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__485);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = zext i32 %%5 to i64, !dbg !21 for 0x%I64xth hint within @picnic_write_private_key  --> \n", ++aesl_llvm_cbe_1160_count);
  llvm_cbe_tmp__486 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__485&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__486);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = mul i64 %%6, 3, !dbg !21 for 0x%I64xth hint within @picnic_write_private_key  --> \n", ++aesl_llvm_cbe_1166_count);
  llvm_cbe_tmp__487 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__486&18446744073709551615ull)) * ((unsigned long long )(3ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__487&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = add i64 %%7, 1, !dbg !21 for 0x%I64xth hint within @picnic_write_private_key  --> \n", ++aesl_llvm_cbe_1167_count);
  llvm_cbe_tmp__488 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__487&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__488&18446744073709551615ull)));
  if ((((unsigned long long )llvm_cbe_tmp__488&18446744073709551615ULL) > ((unsigned long long )llvm_cbe_buflen&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__515;
  } else {
    goto llvm_cbe_tmp__516;
  }

llvm_cbe_tmp__515:
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = call %%struct._iobuf* @__iob_func() nounwind, !dbg !21 for 0x%I64xth hint within @picnic_write_private_key  --> \n", ++aesl_llvm_cbe_1174_count);
  llvm_cbe_tmp__489 = (l_struct_OC__iobuf *)__iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__489);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds %%struct._iobuf* %%11, i64 2, !dbg !21 for 0x%I64xth hint within @picnic_write_private_key  --> \n", ++aesl_llvm_cbe_1175_count);
  llvm_cbe_tmp__490 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__489[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = trunc i64 %%buflen to i32, !dbg !21 for 0x%I64xth hint within @picnic_write_private_key  --> \n", ++aesl_llvm_cbe_1176_count);
  llvm_cbe_tmp__491 = (unsigned int )((unsigned int )llvm_cbe_buflen&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__491);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = trunc i64 %%8 to i32, !dbg !21 for 0x%I64xth hint within @picnic_write_private_key  --> \n", ++aesl_llvm_cbe_1177_count);
  llvm_cbe_tmp__492 = (unsigned int )((unsigned int )llvm_cbe_tmp__488&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__492);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%12, i8* getelementptr inbounds ([56 x i8]* @aesl_internal_.str13, i64 0, i64 0), i8* getelementptr inbounds ([25 x i8]* @aesl_internal___func__.picnic_write_private_key, i64 0, i64 0), i32 %%13, i32 %%14) nounwind, !dbg !21 for 0x%I64xth hint within @picnic_write_private_key  --> \n", ++aesl_llvm_cbe_1178_count);
  fprintf((l_struct_OC__iobuf *)llvm_cbe_tmp__490, ( char *)((&aesl_internal__OC_str13[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 56
#endif
])), ( char *)((&aesl_internal___func___OC_picnic_write_private_key[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 25
#endif
])), llvm_cbe_tmp__491, llvm_cbe_tmp__492);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__491);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__492);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__493);
}
  llvm_cbe_tmp__514__PHI_TEMPORARY = (unsigned int )4294967295u;   /* for PHI node */
  goto llvm_cbe_tmp__517;

llvm_cbe_tmp__516:
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = load i4* %%1, align 1, !dbg !19 for 0x%I64xth hint within @picnic_write_private_key  --> \n", ++aesl_llvm_cbe_1180_count);
  llvm_cbe_tmp__494 = (unsigned char )*llvm_cbe_tmp__481;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__494);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = zext i4 %%17 to i8, !dbg !19 for 0x%I64xth hint within @picnic_write_private_key  --> \n", ++aesl_llvm_cbe_1181_count);
  llvm_cbe_tmp__495 = (unsigned char )((unsigned char )(unsigned char )llvm_cbe_tmp__494&15U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__495);
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%18, i8* %%buf, align 1, !dbg !19 for 0x%I64xth hint within @picnic_write_private_key  --> \n", ++aesl_llvm_cbe_1182_count);
  *llvm_cbe_buf = llvm_cbe_tmp__495;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__495);
  if (((llvm_cbe_tmp__485&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    goto llvm_cbe__2e_lr_2e_ph;
  }

llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = add i64 %%6, 1, !dbg !20 for 0x%I64xth hint within @picnic_write_private_key  --> \n", ++aesl_llvm_cbe_1194_count);
  llvm_cbe_tmp__496 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__486&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__496&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = shl nuw nsw i64 %%6, 1, !dbg !20 for 0x%I64xth hint within @picnic_write_private_key  --> \n", ++aesl_llvm_cbe_1195_count);
  llvm_cbe_tmp__497 = (unsigned long long )llvm_cbe_tmp__486 << 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__497);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = or i64 %%21, 1, !dbg !20 for 0x%I64xth hint within @picnic_write_private_key  --> \n", ++aesl_llvm_cbe_1196_count);
  llvm_cbe_tmp__498 = (unsigned long long )llvm_cbe_tmp__497 | 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__498);
  llvm_cbe_tmp__499__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__518;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__518:
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = phi i64 [ 0, %%.lr.ph ], [ %%28, %%23  for 0x%I64xth hint within @picnic_write_private_key  --> \n", ++aesl_llvm_cbe_1198_count);
  llvm_cbe_tmp__499 = (unsigned long long )llvm_cbe_tmp__499__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__499);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__503);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ 0, %%.lr.ph ], [ %%27, %%23  for 0x%I64xth hint within @picnic_write_private_key  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__502);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = getelementptr inbounds %%struct.picnic_privatekey_t* %%key, i64 0, i32 1, i64 %%24, !dbg !20 for 0x%I64xth hint within @picnic_write_private_key  --> \n", ++aesl_llvm_cbe_1199_count);
  llvm_cbe_tmp__500 = ( char *)(&llvm_cbe_key->field1[(((signed long long )llvm_cbe_tmp__499))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__499));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = load i8* %%25, align 1, !dbg !20 for 0x%I64xth hint within @picnic_write_private_key  --> \n", ++aesl_llvm_cbe_1200_count);
  llvm_cbe_tmp__501 = (unsigned char )*llvm_cbe_tmp__500;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__501);
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = add nsw i32 %%storemerge1, 1, !dbg !20 for 0x%I64xth hint within @picnic_write_private_key  --> \n", ++aesl_llvm_cbe_1201_count);
  llvm_cbe_tmp__502 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__502&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = sext i32 %%27 to i64, !dbg !20 for 0x%I64xth hint within @picnic_write_private_key  --> \n", ++aesl_llvm_cbe_1202_count);
  llvm_cbe_tmp__503 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__502);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__503);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = getelementptr inbounds i8* %%buf, i64 %%28, !dbg !20 for 0x%I64xth hint within @picnic_write_private_key  --> \n", ++aesl_llvm_cbe_1203_count);
  llvm_cbe_tmp__504 = ( char *)(&llvm_cbe_buf[(((signed long long )llvm_cbe_tmp__503))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__503));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%26, i8* %%29, align 1, !dbg !20 for 0x%I64xth hint within @picnic_write_private_key  --> \n", ++aesl_llvm_cbe_1204_count);
  *llvm_cbe_tmp__504 = llvm_cbe_tmp__501;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__501);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = getelementptr inbounds %%struct.picnic_privatekey_t* %%key, i64 0, i32 2, i32 2, i64 %%24, !dbg !20 for 0x%I64xth hint within @picnic_write_private_key  --> \n", ++aesl_llvm_cbe_1205_count);
  llvm_cbe_tmp__505 = ( char *)(&llvm_cbe_key->field2.field2[(((signed long long )llvm_cbe_tmp__499))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__499));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = load i8* %%30, align 1, !dbg !20 for 0x%I64xth hint within @picnic_write_private_key  --> \n", ++aesl_llvm_cbe_1206_count);
  llvm_cbe_tmp__506 = (unsigned char )*llvm_cbe_tmp__505;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__506);
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = add i64 %%20, %%24, !dbg !20 for 0x%I64xth hint within @picnic_write_private_key  --> \n", ++aesl_llvm_cbe_1207_count);
  llvm_cbe_tmp__507 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__496&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__499&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__507&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = getelementptr inbounds i8* %%buf, i64 %%32, !dbg !20 for 0x%I64xth hint within @picnic_write_private_key  --> \n", ++aesl_llvm_cbe_1208_count);
  llvm_cbe_tmp__508 = ( char *)(&llvm_cbe_buf[(((signed long long )llvm_cbe_tmp__507))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__507));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%31, i8* %%33, align 1, !dbg !20 for 0x%I64xth hint within @picnic_write_private_key  --> \n", ++aesl_llvm_cbe_1209_count);
  *llvm_cbe_tmp__508 = llvm_cbe_tmp__506;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__506);
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = getelementptr inbounds %%struct.picnic_privatekey_t* %%key, i64 0, i32 2, i32 1, i64 %%24, !dbg !20 for 0x%I64xth hint within @picnic_write_private_key  --> \n", ++aesl_llvm_cbe_1210_count);
  llvm_cbe_tmp__509 = ( char *)(&llvm_cbe_key->field2.field1[(((signed long long )llvm_cbe_tmp__499))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__499));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = load i8* %%34, align 1, !dbg !20 for 0x%I64xth hint within @picnic_write_private_key  --> \n", ++aesl_llvm_cbe_1211_count);
  llvm_cbe_tmp__510 = (unsigned char )*llvm_cbe_tmp__509;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__510);
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = add i64 %%24, %%22, !dbg !20 for 0x%I64xth hint within @picnic_write_private_key  --> \n", ++aesl_llvm_cbe_1212_count);
  llvm_cbe_tmp__511 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__499&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__498&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__511&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = getelementptr inbounds i8* %%buf, i64 %%36, !dbg !20 for 0x%I64xth hint within @picnic_write_private_key  --> \n", ++aesl_llvm_cbe_1213_count);
  llvm_cbe_tmp__512 = ( char *)(&llvm_cbe_buf[(((signed long long )llvm_cbe_tmp__511))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__511));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%35, i8* %%37, align 1, !dbg !20 for 0x%I64xth hint within @picnic_write_private_key  --> \n", ++aesl_llvm_cbe_1214_count);
  *llvm_cbe_tmp__512 = llvm_cbe_tmp__510;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__510);
  if ((((unsigned long long )llvm_cbe_tmp__503&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__486&18446744073709551615ULL))) {
    llvm_cbe_tmp__499__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__503;   /* for PHI node */
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__502;   /* for PHI node */
    goto llvm_cbe_tmp__518;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = trunc i64 %%8 to i32, !dbg !22 for 0x%I64xth hint within @picnic_write_private_key  --> \n", ++aesl_llvm_cbe_1226_count);
  llvm_cbe_tmp__513 = (unsigned int )((unsigned int )llvm_cbe_tmp__488&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__513);
  llvm_cbe_tmp__514__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__513;   /* for PHI node */
  goto llvm_cbe_tmp__517;

llvm_cbe_tmp__517:
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = phi i32 [ %%39, %%._crit_edge ], [ -1, %%10  for 0x%I64xth hint within @picnic_write_private_key  --> \n", ++aesl_llvm_cbe_1228_count);
  llvm_cbe_tmp__514 = (unsigned int )llvm_cbe_tmp__514__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__514);
printf("\n = 0x%X",llvm_cbe_tmp__513);
printf("\n = 0x%X",4294967295u);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @picnic_write_private_key}\n");
  return llvm_cbe_tmp__514;
}


signed int picnic_read_private_key(l_struct_OC_picnic_privatekey_t *llvm_cbe_key,  char *llvm_cbe_buf, signed long long llvm_cbe_buflen) {
  static  unsigned long long aesl_llvm_cbe_paramset_count = 0;
  l_struct_OC_paramset_t llvm_cbe_paramset;    /* Address-exposed local */
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
  unsigned char llvm_cbe_tmp__519;
  static  unsigned long long aesl_llvm_cbe_1259_count = 0;
  unsigned char llvm_cbe_tmp__520;
  static  unsigned long long aesl_llvm_cbe_1260_count = 0;
  unsigned int llvm_cbe_tmp__521;
  static  unsigned long long aesl_llvm_cbe_1261_count = 0;
  static  unsigned long long aesl_llvm_cbe_1262_count = 0;
  static  unsigned long long aesl_llvm_cbe_1263_count = 0;
  static  unsigned long long aesl_llvm_cbe_1264_count = 0;
  unsigned char llvm_cbe_tmp__522;
  static  unsigned long long aesl_llvm_cbe_1265_count = 0;
  unsigned char llvm_cbe_tmp__523;
  static  unsigned long long aesl_llvm_cbe_1266_count = 0;
   char *llvm_cbe_tmp__524;
  static  unsigned long long aesl_llvm_cbe_1267_count = 0;
  static  unsigned long long aesl_llvm_cbe_1268_count = 0;
  unsigned char llvm_cbe_tmp__525;
  static  unsigned long long aesl_llvm_cbe_1269_count = 0;
  unsigned char llvm_cbe_tmp__526;
  static  unsigned long long aesl_llvm_cbe_1270_count = 0;
   char *llvm_cbe_tmp__527;
  static  unsigned long long aesl_llvm_cbe_1271_count = 0;
  static  unsigned long long aesl_llvm_cbe_1272_count = 0;
  static  unsigned long long aesl_llvm_cbe_1273_count = 0;
  unsigned int llvm_cbe_tmp__528;
  static  unsigned long long aesl_llvm_cbe_1274_count = 0;
  static  unsigned long long aesl_llvm_cbe_1275_count = 0;
  static  unsigned long long aesl_llvm_cbe_1276_count = 0;
  signed int *llvm_cbe_tmp__529;
  static  unsigned long long aesl_llvm_cbe_1277_count = 0;
  unsigned int llvm_cbe_tmp__530;
  static  unsigned long long aesl_llvm_cbe_1278_count = 0;
  unsigned long long llvm_cbe_tmp__531;
  static  unsigned long long aesl_llvm_cbe_1279_count = 0;
  static  unsigned long long aesl_llvm_cbe_1280_count = 0;
  static  unsigned long long aesl_llvm_cbe_1281_count = 0;
  static  unsigned long long aesl_llvm_cbe_1282_count = 0;
  static  unsigned long long aesl_llvm_cbe_1283_count = 0;
  static  unsigned long long aesl_llvm_cbe_1284_count = 0;
  unsigned long long llvm_cbe_tmp__532;
  static  unsigned long long aesl_llvm_cbe_1285_count = 0;
  unsigned long long llvm_cbe_tmp__533;
  static  unsigned long long aesl_llvm_cbe_1286_count = 0;
  static  unsigned long long aesl_llvm_cbe_1287_count = 0;
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
  unsigned long long llvm_cbe_tmp__534;
  static  unsigned long long aesl_llvm_cbe_1301_count = 0;
  unsigned long long llvm_cbe_tmp__535;
  static  unsigned long long aesl_llvm_cbe_1302_count = 0;
  unsigned long long llvm_cbe_tmp__536;
  static  unsigned long long aesl_llvm_cbe_1303_count = 0;
  static  unsigned long long aesl_llvm_cbe_1304_count = 0;
  unsigned long long llvm_cbe_tmp__537;
  unsigned long long llvm_cbe_tmp__537__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1305_count = 0;
  unsigned int llvm_cbe_tmp__538;
  static  unsigned long long aesl_llvm_cbe_1306_count = 0;
  unsigned long long llvm_cbe_tmp__539;
  static  unsigned long long aesl_llvm_cbe_1307_count = 0;
   char *llvm_cbe_tmp__540;
  static  unsigned long long aesl_llvm_cbe_1308_count = 0;
  unsigned char llvm_cbe_tmp__541;
  static  unsigned long long aesl_llvm_cbe_1309_count = 0;
   char *llvm_cbe_tmp__542;
  static  unsigned long long aesl_llvm_cbe_1310_count = 0;
  static  unsigned long long aesl_llvm_cbe_1311_count = 0;
  unsigned long long llvm_cbe_tmp__543;
  static  unsigned long long aesl_llvm_cbe_1312_count = 0;
   char *llvm_cbe_tmp__544;
  static  unsigned long long aesl_llvm_cbe_1313_count = 0;
  unsigned char llvm_cbe_tmp__545;
  static  unsigned long long aesl_llvm_cbe_1314_count = 0;
   char *llvm_cbe_tmp__546;
  static  unsigned long long aesl_llvm_cbe_1315_count = 0;
  static  unsigned long long aesl_llvm_cbe_1316_count = 0;
  unsigned long long llvm_cbe_tmp__547;
  static  unsigned long long aesl_llvm_cbe_1317_count = 0;
   char *llvm_cbe_tmp__548;
  static  unsigned long long aesl_llvm_cbe_1318_count = 0;
  unsigned char llvm_cbe_tmp__549;
  static  unsigned long long aesl_llvm_cbe_1319_count = 0;
   char *llvm_cbe_tmp__550;
  static  unsigned long long aesl_llvm_cbe_1320_count = 0;
  static  unsigned long long aesl_llvm_cbe_1321_count = 0;
  static  unsigned long long aesl_llvm_cbe_1322_count = 0;
  static  unsigned long long aesl_llvm_cbe_1323_count = 0;
  static  unsigned long long aesl_llvm_cbe_1324_count = 0;
  static  unsigned long long aesl_llvm_cbe_1325_count = 0;
  static  unsigned long long aesl_llvm_cbe_1326_count = 0;
  static  unsigned long long aesl_llvm_cbe_1327_count = 0;
  static  unsigned long long aesl_llvm_cbe_1328_count = 0;
  static  unsigned long long aesl_llvm_cbe_1329_count = 0;
  static  unsigned long long aesl_llvm_cbe_1330_count = 0;
  static  unsigned long long aesl_llvm_cbe_1331_count = 0;
  static  unsigned long long aesl_llvm_cbe_1332_count = 0;
  static  unsigned long long aesl_llvm_cbe_1333_count = 0;
  unsigned int llvm_cbe_tmp__551;
  unsigned int llvm_cbe_tmp__551__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1334_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @picnic_read_private_key\n");
  if (((llvm_cbe_buflen&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__552;
  } else {
    goto llvm_cbe_tmp__553;
  }

llvm_cbe_tmp__553:
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = load i8* %%buf, align 1, !dbg !20 for 0x%I64xth hint within @picnic_read_private_key  --> \n", ++aesl_llvm_cbe_1258_count);
  llvm_cbe_tmp__519 = (unsigned char )*llvm_cbe_buf;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__519);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = trunc i8 %%3 to i4, !dbg !20 for 0x%I64xth hint within @picnic_read_private_key  --> \n", ++aesl_llvm_cbe_1259_count);
  llvm_cbe_tmp__520 = (unsigned char )((unsigned char )llvm_cbe_tmp__519&15U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__520);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = call fastcc i32 @aesl_internal_is_valid_params(i4 zeroext %%4), !dbg !20 for 0x%I64xth hint within @picnic_read_private_key  --> \n", ++aesl_llvm_cbe_1260_count);
  llvm_cbe_tmp__521 = (unsigned int )aesl_internal_is_valid_params(llvm_cbe_tmp__520);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__520);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__521);
}
  if (((llvm_cbe_tmp__521&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__552;
  } else {
    goto llvm_cbe_tmp__554;
  }

llvm_cbe_tmp__552:
  llvm_cbe_tmp__551__PHI_TEMPORARY = (unsigned int )4294967295u;   /* for PHI node */
  goto llvm_cbe_tmp__555;

llvm_cbe_tmp__554:
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = load i8* %%buf, align 1, !dbg !19 for 0x%I64xth hint within @picnic_read_private_key  --> \n", ++aesl_llvm_cbe_1264_count);
  llvm_cbe_tmp__522 = (unsigned char )*llvm_cbe_buf;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__522);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = trunc i8 %%9 to i4, !dbg !19 for 0x%I64xth hint within @picnic_read_private_key  --> \n", ++aesl_llvm_cbe_1265_count);
  llvm_cbe_tmp__523 = (unsigned char )((unsigned char )llvm_cbe_tmp__522&15U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__523);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds %%struct.picnic_privatekey_t* %%key, i64 0, i32 0, !dbg !19 for 0x%I64xth hint within @picnic_read_private_key  --> \n", ++aesl_llvm_cbe_1266_count);
  llvm_cbe_tmp__524 = ( char *)(&llvm_cbe_key->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i4 %%10, i4* %%11, align 1, !dbg !19 for 0x%I64xth hint within @picnic_read_private_key  --> \n", ++aesl_llvm_cbe_1267_count);
  *llvm_cbe_tmp__524 = ((llvm_cbe_tmp__523) & 15ull);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__523);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = load i8* %%buf, align 1, !dbg !19 for 0x%I64xth hint within @picnic_read_private_key  --> \n", ++aesl_llvm_cbe_1268_count);
  llvm_cbe_tmp__525 = (unsigned char )*llvm_cbe_buf;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__525);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = trunc i8 %%12 to i4, !dbg !19 for 0x%I64xth hint within @picnic_read_private_key  --> \n", ++aesl_llvm_cbe_1269_count);
  llvm_cbe_tmp__526 = (unsigned char )((unsigned char )llvm_cbe_tmp__525&15U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__526);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds %%struct.picnic_privatekey_t* %%key, i64 0, i32 2, i32 0, !dbg !19 for 0x%I64xth hint within @picnic_read_private_key  --> \n", ++aesl_llvm_cbe_1270_count);
  llvm_cbe_tmp__527 = ( char *)(&llvm_cbe_key->field2.field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i4 %%13, i4* %%14, align 1, !dbg !19 for 0x%I64xth hint within @picnic_read_private_key  --> \n", ++aesl_llvm_cbe_1271_count);
  *llvm_cbe_tmp__527 = ((llvm_cbe_tmp__526) & 15ull);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__526);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = call i32 @get_param_set(i4 zeroext %%10, %%struct.paramset_t* %%paramset), !dbg !20 for 0x%I64xth hint within @picnic_read_private_key  --> \n", ++aesl_llvm_cbe_1273_count);
  get_param_set(llvm_cbe_tmp__523, (l_struct_OC_paramset_t *)(&llvm_cbe_paramset));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__523);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__528);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds %%struct.paramset_t* %%paramset, i64 0, i32 3, !dbg !22 for 0x%I64xth hint within @picnic_read_private_key  --> \n", ++aesl_llvm_cbe_1276_count);
  llvm_cbe_tmp__529 = (signed int *)(&llvm_cbe_paramset.field3);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = load i32* %%16, align 4, !dbg !22 for 0x%I64xth hint within @picnic_read_private_key  --> \n", ++aesl_llvm_cbe_1277_count);
  llvm_cbe_tmp__530 = (unsigned int )*llvm_cbe_tmp__529;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__530);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = zext i32 %%17 to i64, !dbg !22 for 0x%I64xth hint within @picnic_read_private_key  --> \n", ++aesl_llvm_cbe_1278_count);
  llvm_cbe_tmp__531 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__530&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__531);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = mul i64 %%18, 3, !dbg !22 for 0x%I64xth hint within @picnic_read_private_key  --> \n", ++aesl_llvm_cbe_1284_count);
  llvm_cbe_tmp__532 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__531&18446744073709551615ull)) * ((unsigned long long )(3ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__532&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = add i64 %%19, 1, !dbg !22 for 0x%I64xth hint within @picnic_read_private_key  --> \n", ++aesl_llvm_cbe_1285_count);
  llvm_cbe_tmp__533 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__532&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__533&18446744073709551615ull)));
  if ((((unsigned long long )llvm_cbe_tmp__533&18446744073709551615ULL) > ((unsigned long long )llvm_cbe_buflen&18446744073709551615ULL))) {
    llvm_cbe_tmp__551__PHI_TEMPORARY = (unsigned int )4294967295u;   /* for PHI node */
    goto llvm_cbe_tmp__555;
  } else {
    goto llvm_cbe__2e_preheader;
  }

llvm_cbe__2e_preheader:
  if (((llvm_cbe_tmp__530&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe__2e_loopexit;
  } else {
    goto llvm_cbe__2e_lr_2e_ph;
  }

llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = add i64 %%18, 1, !dbg !20 for 0x%I64xth hint within @picnic_read_private_key  --> \n", ++aesl_llvm_cbe_1300_count);
  llvm_cbe_tmp__534 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__531&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__534&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = shl nuw nsw i64 %%18, 1, !dbg !20 for 0x%I64xth hint within @picnic_read_private_key  --> \n", ++aesl_llvm_cbe_1301_count);
  llvm_cbe_tmp__535 = (unsigned long long )llvm_cbe_tmp__531 << 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__535);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = or i64 %%24, 1, !dbg !20 for 0x%I64xth hint within @picnic_read_private_key  --> \n", ++aesl_llvm_cbe_1302_count);
  llvm_cbe_tmp__536 = (unsigned long long )llvm_cbe_tmp__535 | 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__536);
  llvm_cbe_tmp__537__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__556;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__556:
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = phi i64 [ 0, %%.lr.ph ], [ %%29, %%26  for 0x%I64xth hint within @picnic_read_private_key  --> \n", ++aesl_llvm_cbe_1304_count);
  llvm_cbe_tmp__537 = (unsigned long long )llvm_cbe_tmp__537__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__537);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__539);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ 0, %%.lr.ph ], [ %%28, %%26  for 0x%I64xth hint within @picnic_read_private_key  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__538);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = add nsw i32 %%storemerge1, 1, !dbg !20 for 0x%I64xth hint within @picnic_read_private_key  --> \n", ++aesl_llvm_cbe_1305_count);
  llvm_cbe_tmp__538 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__538&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = sext i32 %%28 to i64, !dbg !20 for 0x%I64xth hint within @picnic_read_private_key  --> \n", ++aesl_llvm_cbe_1306_count);
  llvm_cbe_tmp__539 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__538);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__539);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = getelementptr inbounds i8* %%buf, i64 %%29, !dbg !20 for 0x%I64xth hint within @picnic_read_private_key  --> \n", ++aesl_llvm_cbe_1307_count);
  llvm_cbe_tmp__540 = ( char *)(&llvm_cbe_buf[(((signed long long )llvm_cbe_tmp__539))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__539));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = load i8* %%30, align 1, !dbg !20 for 0x%I64xth hint within @picnic_read_private_key  --> \n", ++aesl_llvm_cbe_1308_count);
  llvm_cbe_tmp__541 = (unsigned char )*llvm_cbe_tmp__540;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__541);
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = getelementptr inbounds %%struct.picnic_privatekey_t* %%key, i64 0, i32 1, i64 %%27, !dbg !20 for 0x%I64xth hint within @picnic_read_private_key  --> \n", ++aesl_llvm_cbe_1309_count);
  llvm_cbe_tmp__542 = ( char *)(&llvm_cbe_key->field1[(((signed long long )llvm_cbe_tmp__537))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__537));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%31, i8* %%32, align 1, !dbg !20 for 0x%I64xth hint within @picnic_read_private_key  --> \n", ++aesl_llvm_cbe_1310_count);
  *llvm_cbe_tmp__542 = llvm_cbe_tmp__541;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__541);
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = add i64 %%23, %%27, !dbg !20 for 0x%I64xth hint within @picnic_read_private_key  --> \n", ++aesl_llvm_cbe_1311_count);
  llvm_cbe_tmp__543 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__534&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__537&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__543&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = getelementptr inbounds i8* %%buf, i64 %%33, !dbg !20 for 0x%I64xth hint within @picnic_read_private_key  --> \n", ++aesl_llvm_cbe_1312_count);
  llvm_cbe_tmp__544 = ( char *)(&llvm_cbe_buf[(((signed long long )llvm_cbe_tmp__543))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__543));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = load i8* %%34, align 1, !dbg !20 for 0x%I64xth hint within @picnic_read_private_key  --> \n", ++aesl_llvm_cbe_1313_count);
  llvm_cbe_tmp__545 = (unsigned char )*llvm_cbe_tmp__544;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__545);
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = getelementptr inbounds %%struct.picnic_privatekey_t* %%key, i64 0, i32 2, i32 2, i64 %%27, !dbg !20 for 0x%I64xth hint within @picnic_read_private_key  --> \n", ++aesl_llvm_cbe_1314_count);
  llvm_cbe_tmp__546 = ( char *)(&llvm_cbe_key->field2.field2[(((signed long long )llvm_cbe_tmp__537))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__537));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%35, i8* %%36, align 1, !dbg !20 for 0x%I64xth hint within @picnic_read_private_key  --> \n", ++aesl_llvm_cbe_1315_count);
  *llvm_cbe_tmp__546 = llvm_cbe_tmp__545;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__545);
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = add i64 %%27, %%25, !dbg !20 for 0x%I64xth hint within @picnic_read_private_key  --> \n", ++aesl_llvm_cbe_1316_count);
  llvm_cbe_tmp__547 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__537&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__536&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__547&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = getelementptr inbounds i8* %%buf, i64 %%37, !dbg !20 for 0x%I64xth hint within @picnic_read_private_key  --> \n", ++aesl_llvm_cbe_1317_count);
  llvm_cbe_tmp__548 = ( char *)(&llvm_cbe_buf[(((signed long long )llvm_cbe_tmp__547))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__547));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = load i8* %%38, align 1, !dbg !20 for 0x%I64xth hint within @picnic_read_private_key  --> \n", ++aesl_llvm_cbe_1318_count);
  llvm_cbe_tmp__549 = (unsigned char )*llvm_cbe_tmp__548;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__549);
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = getelementptr inbounds %%struct.picnic_privatekey_t* %%key, i64 0, i32 2, i32 1, i64 %%27, !dbg !20 for 0x%I64xth hint within @picnic_read_private_key  --> \n", ++aesl_llvm_cbe_1319_count);
  llvm_cbe_tmp__550 = ( char *)(&llvm_cbe_key->field2.field1[(((signed long long )llvm_cbe_tmp__537))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__537));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%39, i8* %%40, align 1, !dbg !20 for 0x%I64xth hint within @picnic_read_private_key  --> \n", ++aesl_llvm_cbe_1320_count);
  *llvm_cbe_tmp__550 = llvm_cbe_tmp__549;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__549);
  if ((((unsigned long long )llvm_cbe_tmp__539&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__531&18446744073709551615ULL))) {
    llvm_cbe_tmp__537__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__539;   /* for PHI node */
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__538;   /* for PHI node */
    goto llvm_cbe_tmp__556;
  } else {
    goto llvm_cbe__2e_loopexit;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_loopexit:
  llvm_cbe_tmp__551__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__555;

llvm_cbe_tmp__555:
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = phi i32 [ -1, %%7 ], [ -1, %%8 ], [ 0, %%.loopexit  for 0x%I64xth hint within @picnic_read_private_key  --> \n", ++aesl_llvm_cbe_1333_count);
  llvm_cbe_tmp__551 = (unsigned int )llvm_cbe_tmp__551__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__551);
printf("\n = 0x%X",4294967295u);
printf("\n = 0x%X",4294967295u);
printf("\n = 0x%X",0u);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @picnic_read_private_key}\n");
  return llvm_cbe_tmp__551;
}


signed int picnic_validate_keypair(l_struct_OC_picnic_privatekey_t *llvm_cbe_privatekey, l_struct_OC_picnic_publickey_t *llvm_cbe_publickey) {
  static  unsigned long long aesl_llvm_cbe_paramset_count = 0;
  l_struct_OC_paramset_t llvm_cbe_paramset;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_ciphertext_count = 0;
   char llvm_cbe_ciphertext[32];    /* Address-exposed local */
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
   char *llvm_cbe_tmp__557;
  static  unsigned long long aesl_llvm_cbe_1348_count = 0;
  unsigned char llvm_cbe_tmp__558;
  static  unsigned long long aesl_llvm_cbe_1349_count = 0;
  unsigned int llvm_cbe_tmp__559;
  static  unsigned long long aesl_llvm_cbe_1350_count = 0;
  static  unsigned long long aesl_llvm_cbe_1351_count = 0;
  static  unsigned long long aesl_llvm_cbe_1352_count = 0;
  static  unsigned long long aesl_llvm_cbe_1353_count = 0;
  static  unsigned long long aesl_llvm_cbe_1354_count = 0;
   char *llvm_cbe_tmp__560;
  static  unsigned long long aesl_llvm_cbe_1355_count = 0;
  unsigned char llvm_cbe_tmp__561;
  static  unsigned long long aesl_llvm_cbe_1356_count = 0;
  unsigned char llvm_cbe_tmp__562;
  static  unsigned long long aesl_llvm_cbe_1357_count = 0;
  static  unsigned long long aesl_llvm_cbe_1358_count = 0;
  static  unsigned long long aesl_llvm_cbe_1359_count = 0;
  unsigned int llvm_cbe_tmp__563;
  static  unsigned long long aesl_llvm_cbe_1360_count = 0;
  static  unsigned long long aesl_llvm_cbe_1361_count = 0;
  static  unsigned long long aesl_llvm_cbe_1362_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__564;
  static  unsigned long long aesl_llvm_cbe_1363_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__565;
  static  unsigned long long aesl_llvm_cbe_1364_count = 0;
  unsigned long long llvm_cbe_tmp__566;
  static  unsigned long long aesl_llvm_cbe_1365_count = 0;
  static  unsigned long long aesl_llvm_cbe_1366_count = 0;
  static  unsigned long long aesl_llvm_cbe_1367_count = 0;
   char *llvm_cbe_tmp__567;
  static  unsigned long long aesl_llvm_cbe_1368_count = 0;
   char *llvm_cbe_tmp__568;
  static  unsigned long long aesl_llvm_cbe_1369_count = 0;
   char *llvm_cbe_tmp__569;
  static  unsigned long long aesl_llvm_cbe_1370_count = 0;
  signed int *llvm_cbe_tmp__570;
  static  unsigned long long aesl_llvm_cbe_1371_count = 0;
  signed int *llvm_cbe_tmp__571;
  static  unsigned long long aesl_llvm_cbe_1372_count = 0;
   char *llvm_cbe_tmp__572;
  static  unsigned long long aesl_llvm_cbe_1373_count = 0;
  signed int *llvm_cbe_tmp__573;
  static  unsigned long long aesl_llvm_cbe_1374_count = 0;
  static  unsigned long long aesl_llvm_cbe_1375_count = 0;
   char *llvm_cbe_tmp__574;
  static  unsigned long long aesl_llvm_cbe_1376_count = 0;
  signed int *llvm_cbe_tmp__575;
  static  unsigned long long aesl_llvm_cbe_1377_count = 0;
  unsigned int llvm_cbe_tmp__576;
  static  unsigned long long aesl_llvm_cbe_1378_count = 0;
  unsigned long long llvm_cbe_tmp__577;
  static  unsigned long long aesl_llvm_cbe_1379_count = 0;
  unsigned int llvm_cbe_tmp__578;
  static  unsigned long long aesl_llvm_cbe_1380_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e__count = 0;
  unsigned int llvm_cbe__2e_;
  static  unsigned long long aesl_llvm_cbe_1381_count = 0;
  static  unsigned long long aesl_llvm_cbe_1382_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @picnic_validate_keypair\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.picnic_publickey_t* %%publickey, i64 0, i32 0, !dbg !20 for 0x%I64xth hint within @picnic_validate_keypair  --> \n", ++aesl_llvm_cbe_1347_count);
  llvm_cbe_tmp__557 = ( char *)(&llvm_cbe_publickey->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i4* %%1, align 1, !dbg !20 for 0x%I64xth hint within @picnic_validate_keypair  --> \n", ++aesl_llvm_cbe_1348_count);
  llvm_cbe_tmp__558 = (unsigned char )*llvm_cbe_tmp__557;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__558);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = call i32 @get_param_set(i4 zeroext %%2, %%struct.paramset_t* %%paramset), !dbg !20 for 0x%I64xth hint within @picnic_validate_keypair  --> \n", ++aesl_llvm_cbe_1349_count);
  get_param_set(llvm_cbe_tmp__558, (l_struct_OC_paramset_t *)(&llvm_cbe_paramset));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__558);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__559);
}
  if (((llvm_cbe_privatekey) == (((l_struct_OC_picnic_privatekey_t *)/*NULL*/0)))) {
    goto llvm_cbe_tmp__579;
  } else {
    goto llvm_cbe_tmp__580;
  }

llvm_cbe_tmp__580:
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds %%struct.picnic_privatekey_t* %%privatekey, i64 0, i32 0, !dbg !19 for 0x%I64xth hint within @picnic_validate_keypair  --> \n", ++aesl_llvm_cbe_1354_count);
  llvm_cbe_tmp__560 = ( char *)(&llvm_cbe_privatekey->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = load i4* %%6, align 1, !dbg !19 for 0x%I64xth hint within @picnic_validate_keypair  --> \n", ++aesl_llvm_cbe_1355_count);
  llvm_cbe_tmp__561 = (unsigned char )*llvm_cbe_tmp__560;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__561);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load i4* %%1, align 1, !dbg !19 for 0x%I64xth hint within @picnic_validate_keypair  --> \n", ++aesl_llvm_cbe_1356_count);
  llvm_cbe_tmp__562 = (unsigned char )*llvm_cbe_tmp__557;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__562);
  if (((llvm_cbe_tmp__561&15U) == (llvm_cbe_tmp__562&15U))) {
    goto llvm_cbe_tmp__581;
  } else {
    goto llvm_cbe_tmp__579;
  }

llvm_cbe_tmp__581:
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = call fastcc i32 @aesl_internal_is_valid_params(i4 zeroext %%7), !dbg !20 for 0x%I64xth hint within @picnic_validate_keypair  --> \n", ++aesl_llvm_cbe_1359_count);
  llvm_cbe_tmp__563 = (unsigned int )aesl_internal_is_valid_params(llvm_cbe_tmp__561);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__561);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__563);
}
  if (((llvm_cbe_tmp__563&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__582;
  } else {
    goto llvm_cbe_tmp__583;
  }

llvm_cbe_tmp__582:
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = call %%struct._iobuf* @__iob_func() nounwind, !dbg !21 for 0x%I64xth hint within @picnic_validate_keypair  --> \n", ++aesl_llvm_cbe_1362_count);
  llvm_cbe_tmp__564 = (l_struct_OC__iobuf *)__iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__564);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds %%struct._iobuf* %%14, i64 2, !dbg !21 for 0x%I64xth hint within @picnic_validate_keypair  --> \n", ++aesl_llvm_cbe_1363_count);
  llvm_cbe_tmp__565 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__564[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = call i64 @fwrite(i8* getelementptr inbounds ([27 x i8]* @aesl_internal_.str14, i64 0, i64 0), i64 26, i64 1, %%struct._iobuf* %%15), !dbg !21 for 0x%I64xth hint within @picnic_validate_keypair  --> \n", ++aesl_llvm_cbe_1364_count);
  fwrite(( char *)((&aesl_internal__OC_str14[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 27
#endif
])), 26ull, 1ull, (l_struct_OC__iobuf *)llvm_cbe_tmp__565);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",26ull);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__566);
}
  goto llvm_cbe_tmp__579;

llvm_cbe_tmp__583:
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = getelementptr inbounds [32 x i8]* %%ciphertext, i64 0, i64 0, !dbg !21 for 0x%I64xth hint within @picnic_validate_keypair  --> \n", ++aesl_llvm_cbe_1367_count);
  llvm_cbe_tmp__567 = ( char *)(&llvm_cbe_ciphertext[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 32
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = call i8* @memset(i8* %%18, i32 0, i64 32 for 0x%I64xth hint within @picnic_validate_keypair  --> \n", ++aesl_llvm_cbe_1368_count);
  ( char *)memset(( char *)llvm_cbe_tmp__567, 0u, 32ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",32ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__568);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = getelementptr inbounds %%struct.picnic_publickey_t* %%publickey, i64 0, i32 1, i64 0, !dbg !20 for 0x%I64xth hint within @picnic_validate_keypair  --> \n", ++aesl_llvm_cbe_1369_count);
  llvm_cbe_tmp__569 = ( char *)(&llvm_cbe_publickey->field1[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = bitcast i8* %%20 to i32*, !dbg !20 for 0x%I64xth hint within @picnic_validate_keypair  --> \n", ++aesl_llvm_cbe_1370_count);
  llvm_cbe_tmp__570 = (signed int *)((signed int *)llvm_cbe_tmp__569);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = bitcast [32 x i8]* %%ciphertext to i32*, !dbg !20 for 0x%I64xth hint within @picnic_validate_keypair  --> \n", ++aesl_llvm_cbe_1371_count);
  llvm_cbe_tmp__571 = (signed int *)((signed int *)(&llvm_cbe_ciphertext));
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = getelementptr inbounds %%struct.picnic_privatekey_t* %%privatekey, i64 0, i32 1, i64 0, !dbg !20 for 0x%I64xth hint within @picnic_validate_keypair  --> \n", ++aesl_llvm_cbe_1372_count);
  llvm_cbe_tmp__572 = ( char *)(&llvm_cbe_privatekey->field1[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = bitcast i8* %%23 to i32*, !dbg !20 for 0x%I64xth hint within @picnic_validate_keypair  --> \n", ++aesl_llvm_cbe_1373_count);
  llvm_cbe_tmp__573 = (signed int *)((signed int *)llvm_cbe_tmp__572);
if (AESL_DEBUG_TRACE)
printf("\n  call void @LowMCEnc(i32* %%21, i32* %%22, i32* %%24, %%struct.paramset_t* %%paramset) nounwind, !dbg !20 for 0x%I64xth hint within @picnic_validate_keypair  --> \n", ++aesl_llvm_cbe_1374_count);
  LowMCEnc((signed int *)llvm_cbe_tmp__570, (signed int *)llvm_cbe_tmp__571, (signed int *)llvm_cbe_tmp__573, (l_struct_OC_paramset_t *)(&llvm_cbe_paramset));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = getelementptr inbounds %%struct.picnic_publickey_t* %%publickey, i64 0, i32 2, i64 0, !dbg !20 for 0x%I64xth hint within @picnic_validate_keypair  --> \n", ++aesl_llvm_cbe_1375_count);
  llvm_cbe_tmp__574 = ( char *)(&llvm_cbe_publickey->field2[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = getelementptr inbounds %%struct.paramset_t* %%paramset, i64 0, i32 3, !dbg !20 for 0x%I64xth hint within @picnic_validate_keypair  --> \n", ++aesl_llvm_cbe_1376_count);
  llvm_cbe_tmp__575 = (signed int *)(&llvm_cbe_paramset.field3);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = load i32* %%26, align 4, !dbg !20 for 0x%I64xth hint within @picnic_validate_keypair  --> \n", ++aesl_llvm_cbe_1377_count);
  llvm_cbe_tmp__576 = (unsigned int )*llvm_cbe_tmp__575;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__576);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = zext i32 %%27 to i64, !dbg !20 for 0x%I64xth hint within @picnic_validate_keypair  --> \n", ++aesl_llvm_cbe_1378_count);
  llvm_cbe_tmp__577 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__576&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__577);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = call i32 @memcmp(i8* %%18, i8* %%25, i64 %%28) nounwind, !dbg !20 for 0x%I64xth hint within @picnic_validate_keypair  --> \n", ++aesl_llvm_cbe_1379_count);
  llvm_cbe_tmp__578 = (unsigned int )memcmp(( char *)llvm_cbe_tmp__567, ( char *)llvm_cbe_tmp__574, llvm_cbe_tmp__577);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__577);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__578);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%. = select i1 %%30, i32 0, i32 -1, !dbg !20 for 0x%I64xth hint within @picnic_validate_keypair  --> \n", ++aesl_llvm_cbe__2e__count);
  llvm_cbe__2e_ = (unsigned int )((((llvm_cbe_tmp__578&4294967295U) == (0u&4294967295U))) ? ((unsigned int )0u) : ((unsigned int )4294967295u));
if (AESL_DEBUG_TRACE)
printf("\n. = 0x%X\n", llvm_cbe__2e_);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @picnic_validate_keypair}\n");
  return llvm_cbe__2e_;
llvm_cbe_tmp__579:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @picnic_validate_keypair}\n");
  return 4294967295u;
}


void print_signature( char *llvm_cbe_sigBytes, signed long long llvm_cbe_sigBytesLen,  char llvm_cbe_picnic_params) {
  static  unsigned long long aesl_llvm_cbe_sig_count = 0;
  l_struct_OC_signature_t llvm_cbe_sig;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_label_count = 0;
   char llvm_cbe_label[50];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_params_count = 0;
  l_struct_OC_paramset_t llvm_cbe_params;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_1383_count = 0;
  static  unsigned long long aesl_llvm_cbe_1384_count = 0;
  static  unsigned long long aesl_llvm_cbe_1385_count = 0;
  static  unsigned long long aesl_llvm_cbe_1386_count = 0;
  static  unsigned long long aesl_llvm_cbe_1387_count = 0;
  static  unsigned long long aesl_llvm_cbe_1388_count = 0;
  static  unsigned long long aesl_llvm_cbe_1389_count = 0;
  static  unsigned long long aesl_llvm_cbe_1390_count = 0;
  static  unsigned long long aesl_llvm_cbe_1391_count = 0;
  static  unsigned long long aesl_llvm_cbe_1392_count = 0;
  static  unsigned long long aesl_llvm_cbe_1393_count = 0;
  static  unsigned long long aesl_llvm_cbe_1394_count = 0;
  static  unsigned long long aesl_llvm_cbe_1395_count = 0;
  static  unsigned long long aesl_llvm_cbe_1396_count = 0;
  static  unsigned long long aesl_llvm_cbe_1397_count = 0;
  static  unsigned long long aesl_llvm_cbe_1398_count = 0;
  static  unsigned long long aesl_llvm_cbe_1399_count = 0;
  static  unsigned long long aesl_llvm_cbe_1400_count = 0;
  static  unsigned long long aesl_llvm_cbe_1401_count = 0;
  static  unsigned long long aesl_llvm_cbe_1402_count = 0;
  static  unsigned long long aesl_llvm_cbe_1403_count = 0;
  static  unsigned long long aesl_llvm_cbe_1404_count = 0;
  static  unsigned long long aesl_llvm_cbe_1405_count = 0;
  static  unsigned long long aesl_llvm_cbe_1406_count = 0;
  static  unsigned long long aesl_llvm_cbe_1407_count = 0;
  static  unsigned long long aesl_llvm_cbe_picnic_params_2e_off_count = 0;
  unsigned char llvm_cbe_picnic_params_2e_off;
  static  unsigned long long aesl_llvm_cbe_switch_count = 0;
  static  unsigned long long aesl_llvm_cbe_1408_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts_count = 0;
  unsigned int llvm_cbe_puts;
  static  unsigned long long aesl_llvm_cbe_1409_count = 0;
  static  unsigned long long aesl_llvm_cbe_1410_count = 0;
  static  unsigned long long aesl_llvm_cbe_1411_count = 0;
  unsigned int llvm_cbe_tmp__584;
  static  unsigned long long aesl_llvm_cbe_1412_count = 0;
  static  unsigned long long aesl_llvm_cbe_1413_count = 0;
  static  unsigned long long aesl_llvm_cbe_1414_count = 0;
  static  unsigned long long aesl_llvm_cbe_1415_count = 0;
  unsigned int llvm_cbe_tmp__585;
  static  unsigned long long aesl_llvm_cbe_1416_count = 0;
  static  unsigned long long aesl_llvm_cbe_1417_count = 0;
  static  unsigned long long aesl_llvm_cbe_1418_count = 0;
  static  unsigned long long aesl_llvm_cbe_1419_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts4_count = 0;
  unsigned int llvm_cbe_puts4;
  static  unsigned long long aesl_llvm_cbe_1420_count = 0;
  static  unsigned long long aesl_llvm_cbe_1421_count = 0;
   char *llvm_cbe_tmp__586;
  static  unsigned long long aesl_llvm_cbe_1422_count = 0;
  static  unsigned long long aesl_llvm_cbe_1423_count = 0;
  static  unsigned long long aesl_llvm_cbe_1424_count = 0;
  static  unsigned long long aesl_llvm_cbe_1425_count = 0;
  static  unsigned long long aesl_llvm_cbe_1426_count = 0;
  signed int *llvm_cbe_tmp__587;
  static  unsigned long long aesl_llvm_cbe_1427_count = 0;
  unsigned int llvm_cbe_tmp__588;
  static  unsigned long long aesl_llvm_cbe_1428_count = 0;
  unsigned int llvm_cbe_tmp__589;
  static  unsigned long long aesl_llvm_cbe_1429_count = 0;
  unsigned int llvm_cbe_tmp__590;
  static  unsigned long long aesl_llvm_cbe_1430_count = 0;
  unsigned long long llvm_cbe_tmp__591;
  static  unsigned long long aesl_llvm_cbe_1431_count = 0;
   char *llvm_cbe_tmp__592;
  static  unsigned long long aesl_llvm_cbe_1432_count = 0;
  unsigned int llvm_cbe_tmp__593;
  static  unsigned long long aesl_llvm_cbe_1433_count = 0;
  unsigned int llvm_cbe_tmp__594;
  static  unsigned long long aesl_llvm_cbe_1434_count = 0;
  unsigned int llvm_cbe_tmp__595;
  static  unsigned long long aesl_llvm_cbe_1435_count = 0;
  unsigned long long llvm_cbe_tmp__596;
  static  unsigned long long aesl_llvm_cbe_1436_count = 0;
   char *llvm_cbe_tmp__597;
  static  unsigned long long aesl_llvm_cbe_1437_count = 0;
  static  unsigned long long aesl_llvm_cbe_1438_count = 0;
  static  unsigned long long aesl_llvm_cbe_1439_count = 0;
  static  unsigned long long aesl_llvm_cbe_1440_count = 0;
  static  unsigned long long aesl_llvm_cbe_1441_count = 0;
  static  unsigned long long aesl_llvm_cbe_1442_count = 0;
  static  unsigned long long aesl_llvm_cbe_1443_count = 0;
  static  unsigned long long aesl_llvm_cbe_1444_count = 0;
  static  unsigned long long aesl_llvm_cbe_1445_count = 0;
  static  unsigned long long aesl_llvm_cbe_1446_count = 0;
  static  unsigned long long aesl_llvm_cbe_1447_count = 0;
  static  unsigned long long aesl_llvm_cbe_1448_count = 0;
  static  unsigned long long aesl_llvm_cbe_1449_count = 0;
  static  unsigned long long aesl_llvm_cbe_1450_count = 0;
  static  unsigned long long aesl_llvm_cbe_1451_count = 0;
  static  unsigned long long aesl_llvm_cbe_1452_count = 0;
  static  unsigned long long aesl_llvm_cbe_1453_count = 0;
  unsigned int llvm_cbe_tmp__598;
  static  unsigned long long aesl_llvm_cbe_1454_count = 0;
  unsigned int llvm_cbe_tmp__599;
  static  unsigned long long aesl_llvm_cbe_1455_count = 0;
  unsigned int llvm_cbe_tmp__600;
  static  unsigned long long aesl_llvm_cbe_1456_count = 0;
  unsigned long long llvm_cbe_tmp__601;
  static  unsigned long long aesl_llvm_cbe_1457_count = 0;
  static  unsigned long long aesl_llvm_cbe_1458_count = 0;
   char *llvm_cbe_tmp__602;
  static  unsigned long long aesl_llvm_cbe_1459_count = 0;
  signed int *llvm_cbe_tmp__603;
  static  unsigned long long aesl_llvm_cbe_1460_count = 0;
  unsigned int llvm_cbe_tmp__604;
  static  unsigned long long aesl_llvm_cbe_1461_count = 0;
  unsigned long long llvm_cbe_tmp__605;
  static  unsigned long long aesl_llvm_cbe_1462_count = 0;
  static  unsigned long long aesl_llvm_cbe_putchar_count = 0;
  unsigned int llvm_cbe_putchar;
  static  unsigned long long aesl_llvm_cbe_1463_count = 0;
  static  unsigned long long aesl_llvm_cbe_1464_count = 0;
  static  unsigned long long aesl_llvm_cbe_1465_count = 0;
  static  unsigned long long aesl_llvm_cbe_1466_count = 0;
  static  unsigned long long aesl_llvm_cbe_1467_count = 0;
  static  unsigned long long aesl_llvm_cbe_1468_count = 0;
  static  unsigned long long aesl_llvm_cbe_1469_count = 0;
  static  unsigned long long aesl_llvm_cbe_1470_count = 0;
  static  unsigned long long aesl_llvm_cbe_1471_count = 0;
  static  unsigned long long aesl_llvm_cbe_1472_count = 0;
  static  unsigned long long aesl_llvm_cbe_1473_count = 0;
  static  unsigned long long aesl_llvm_cbe_1474_count = 0;
  static  unsigned long long aesl_llvm_cbe_1475_count = 0;
  static  unsigned long long aesl_llvm_cbe_1476_count = 0;
  static  unsigned long long aesl_llvm_cbe_1477_count = 0;
  static  unsigned long long aesl_llvm_cbe_1478_count = 0;
  static  unsigned long long aesl_llvm_cbe_1479_count = 0;
  static  unsigned long long aesl_llvm_cbe_1480_count = 0;
  static  unsigned long long aesl_llvm_cbe_1481_count = 0;
  unsigned int llvm_cbe_tmp__606;
  static  unsigned long long aesl_llvm_cbe_1482_count = 0;
  static  unsigned long long aesl_llvm_cbe_1483_count = 0;
  static  unsigned long long aesl_llvm_cbe_1484_count = 0;
  signed int *llvm_cbe_tmp__607;
  static  unsigned long long aesl_llvm_cbe_1485_count = 0;
   char *llvm_cbe_tmp__608;
  static  unsigned long long aesl_llvm_cbe_1486_count = 0;
   char *llvm_cbe_tmp__609;
  static  unsigned long long aesl_llvm_cbe_1487_count = 0;
  signed int *llvm_cbe_tmp__610;
  static  unsigned long long aesl_llvm_cbe_1488_count = 0;
  signed int *llvm_cbe_tmp__611;
  static  unsigned long long aesl_llvm_cbe_1489_count = 0;
  signed int *llvm_cbe_tmp__612;
  static  unsigned long long aesl_llvm_cbe_1490_count = 0;
  signed int *llvm_cbe_tmp__613;
  static  unsigned long long aesl_llvm_cbe_1491_count = 0;
  signed int *llvm_cbe_tmp__614;
  static  unsigned long long aesl_llvm_cbe_1492_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge10_count = 0;
  unsigned long long llvm_cbe_storemerge10;
  unsigned long long llvm_cbe_storemerge10__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1493_count = 0;
   char *llvm_cbe_tmp__615;
   char *llvm_cbe_tmp__615__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1494_count = 0;
  unsigned int llvm_cbe_tmp__616;
  static  unsigned long long aesl_llvm_cbe_1495_count = 0;
  unsigned int llvm_cbe_tmp__617;
  static  unsigned long long aesl_llvm_cbe_1496_count = 0;
  unsigned char llvm_cbe_tmp__618;
  static  unsigned long long aesl_llvm_cbe_1497_count = 0;
  static  unsigned long long aesl_llvm_cbe_1498_count = 0;
  static  unsigned long long aesl_llvm_cbe_1499_count = 0;
  static  unsigned long long aesl_llvm_cbe_1500_count = 0;
  static  unsigned long long aesl_llvm_cbe_1501_count = 0;
  static  unsigned long long aesl_llvm_cbe_1502_count = 0;
  unsigned int llvm_cbe_tmp__619;
  static  unsigned long long aesl_llvm_cbe_1503_count = 0;
  unsigned int llvm_cbe_tmp__620;
  static  unsigned long long aesl_llvm_cbe_1504_count = 0;
   char *llvm_cbe_tmp__621;
  static  unsigned long long aesl_llvm_cbe_1505_count = 0;
  unsigned int llvm_cbe_tmp__622;
  static  unsigned long long aesl_llvm_cbe_1506_count = 0;
  unsigned long long llvm_cbe_tmp__623;
  static  unsigned long long aesl_llvm_cbe_1507_count = 0;
   char *llvm_cbe_tmp__624;
  static  unsigned long long aesl_llvm_cbe_1508_count = 0;
   char *llvm_cbe_tmp__625;
  static  unsigned long long aesl_llvm_cbe_1509_count = 0;
  static  unsigned long long aesl_llvm_cbe_1510_count = 0;
  static  unsigned long long aesl_llvm_cbe_1511_count = 0;
  static  unsigned long long aesl_llvm_cbe_1512_count = 0;
  static  unsigned long long aesl_llvm_cbe_1513_count = 0;
  static  unsigned long long aesl_llvm_cbe_1514_count = 0;
  static  unsigned long long aesl_llvm_cbe_1515_count = 0;
  static  unsigned long long aesl_llvm_cbe_1516_count = 0;
  static  unsigned long long aesl_llvm_cbe_1517_count = 0;
  static  unsigned long long aesl_llvm_cbe_1518_count = 0;
  static  unsigned long long aesl_llvm_cbe_1519_count = 0;
  static  unsigned long long aesl_llvm_cbe_1520_count = 0;
  static  unsigned long long aesl_llvm_cbe_1521_count = 0;
  static  unsigned long long aesl_llvm_cbe_1522_count = 0;
  static  unsigned long long aesl_llvm_cbe_1523_count = 0;
  static  unsigned long long aesl_llvm_cbe_1524_count = 0;
  static  unsigned long long aesl_llvm_cbe_1525_count = 0;
  static  unsigned long long aesl_llvm_cbe_1526_count = 0;
  unsigned char llvm_cbe_tmp__626;
  static  unsigned long long aesl_llvm_cbe_1527_count = 0;
  static  unsigned long long aesl_llvm_cbe_1528_count = 0;
  static  unsigned long long aesl_llvm_cbe_1529_count = 0;
  static  unsigned long long aesl_llvm_cbe_1530_count = 0;
  unsigned int llvm_cbe_tmp__627;
  static  unsigned long long aesl_llvm_cbe_1531_count = 0;
  unsigned int llvm_cbe_tmp__628;
  static  unsigned long long aesl_llvm_cbe_1532_count = 0;
  unsigned int llvm_cbe_tmp__629;
  static  unsigned long long aesl_llvm_cbe_1533_count = 0;
  unsigned long long llvm_cbe_tmp__630;
  static  unsigned long long aesl_llvm_cbe_1534_count = 0;
  static  unsigned long long aesl_llvm_cbe_1535_count = 0;
  static  unsigned long long aesl_llvm_cbe_1536_count = 0;
  static  unsigned long long aesl_llvm_cbe_1537_count = 0;
  static  unsigned long long aesl_llvm_cbe_1538_count = 0;
   char *llvm_cbe_tmp__631;
  static  unsigned long long aesl_llvm_cbe_1539_count = 0;
  unsigned char llvm_cbe_tmp__632;
  static  unsigned long long aesl_llvm_cbe_1540_count = 0;
  unsigned long long llvm_cbe_tmp__633;
  static  unsigned long long aesl_llvm_cbe_1541_count = 0;
   char *llvm_cbe_tmp__634;
  static  unsigned long long aesl_llvm_cbe_1542_count = 0;
   char *llvm_cbe_tmp__635;
  static  unsigned long long aesl_llvm_cbe__2e_sum9_count = 0;
  unsigned long long llvm_cbe__2e_sum9;
  static  unsigned long long aesl_llvm_cbe_1543_count = 0;
   char *llvm_cbe_tmp__636;
  static  unsigned long long aesl_llvm_cbe_1544_count = 0;
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
  unsigned char llvm_cbe_tmp__637;
  static  unsigned long long aesl_llvm_cbe_1561_count = 0;
  unsigned long long llvm_cbe_tmp__638;
  static  unsigned long long aesl_llvm_cbe_1562_count = 0;
   char *llvm_cbe_tmp__639;
  static  unsigned long long aesl_llvm_cbe_1563_count = 0;
  static  unsigned long long aesl_llvm_cbe_1564_count = 0;
  static  unsigned long long aesl_llvm_cbe_1565_count = 0;
   char *llvm_cbe_tmp__640;
   char *llvm_cbe_tmp__640__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1566_count = 0;
   char *llvm_cbe_tmp__641;
  static  unsigned long long aesl_llvm_cbe_1567_count = 0;
  unsigned int llvm_cbe_tmp__642;
  static  unsigned long long aesl_llvm_cbe_1568_count = 0;
  unsigned long long llvm_cbe_tmp__643;
  static  unsigned long long aesl_llvm_cbe_1569_count = 0;
   char *llvm_cbe_tmp__644;
  static  unsigned long long aesl_llvm_cbe_1570_count = 0;
   char *llvm_cbe_tmp__645;
  static  unsigned long long aesl_llvm_cbe_1571_count = 0;
  static  unsigned long long aesl_llvm_cbe_1572_count = 0;
  static  unsigned long long aesl_llvm_cbe_1573_count = 0;
  static  unsigned long long aesl_llvm_cbe_1574_count = 0;
  static  unsigned long long aesl_llvm_cbe_1575_count = 0;
  static  unsigned long long aesl_llvm_cbe_1576_count = 0;
  static  unsigned long long aesl_llvm_cbe_1577_count = 0;
  static  unsigned long long aesl_llvm_cbe_1578_count = 0;
  static  unsigned long long aesl_llvm_cbe_1579_count = 0;
  static  unsigned long long aesl_llvm_cbe_1580_count = 0;
  static  unsigned long long aesl_llvm_cbe_1581_count = 0;
  static  unsigned long long aesl_llvm_cbe_1582_count = 0;
  static  unsigned long long aesl_llvm_cbe_1583_count = 0;
  static  unsigned long long aesl_llvm_cbe_1584_count = 0;
  static  unsigned long long aesl_llvm_cbe_1585_count = 0;
  static  unsigned long long aesl_llvm_cbe_1586_count = 0;
  static  unsigned long long aesl_llvm_cbe_1587_count = 0;
  static  unsigned long long aesl_llvm_cbe_1588_count = 0;
   char *llvm_cbe_tmp__646;
  static  unsigned long long aesl_llvm_cbe_1589_count = 0;
  unsigned int llvm_cbe_tmp__647;
  static  unsigned long long aesl_llvm_cbe_1590_count = 0;
  unsigned long long llvm_cbe_tmp__648;
  static  unsigned long long aesl_llvm_cbe_1591_count = 0;
   char *llvm_cbe_tmp__649;
  static  unsigned long long aesl_llvm_cbe__2e_sum_count = 0;
  unsigned long long llvm_cbe__2e_sum;
  static  unsigned long long aesl_llvm_cbe_1592_count = 0;
   char *llvm_cbe_tmp__650;
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
  static  unsigned long long aesl_llvm_cbe_1607_count = 0;
  static  unsigned long long aesl_llvm_cbe_1608_count = 0;
  static  unsigned long long aesl_llvm_cbe_1609_count = 0;
  static  unsigned long long aesl_llvm_cbe_1610_count = 0;
   char *llvm_cbe_tmp__651;
  static  unsigned long long aesl_llvm_cbe_1611_count = 0;
  unsigned int llvm_cbe_tmp__652;
  static  unsigned long long aesl_llvm_cbe_1612_count = 0;
  unsigned long long llvm_cbe_tmp__653;
  static  unsigned long long aesl_llvm_cbe_1613_count = 0;
   char *llvm_cbe_tmp__654;
  static  unsigned long long aesl_llvm_cbe__2e_sum7_count = 0;
  unsigned long long llvm_cbe__2e_sum7;
  static  unsigned long long aesl_llvm_cbe_1614_count = 0;
   char *llvm_cbe_tmp__655;
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
  static  unsigned long long aesl_llvm_cbe_1630_count = 0;
  static  unsigned long long aesl_llvm_cbe_1631_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_off_count = 0;
  unsigned char llvm_cbe__2e_off;
  static  unsigned long long aesl_llvm_cbe_switch6_count = 0;
  static  unsigned long long aesl_llvm_cbe_1632_count = 0;
  static  unsigned long long aesl_llvm_cbe_1633_count = 0;
  signed int *llvm_cbe_tmp__656;
  static  unsigned long long aesl_llvm_cbe_1634_count = 0;
   char *llvm_cbe_tmp__657;
  static  unsigned long long aesl_llvm_cbe_1635_count = 0;
  unsigned int llvm_cbe_tmp__658;
  static  unsigned long long aesl_llvm_cbe_1636_count = 0;
  unsigned long long llvm_cbe_tmp__659;
  static  unsigned long long aesl_llvm_cbe_1637_count = 0;
   char *llvm_cbe_tmp__660;
  static  unsigned long long aesl_llvm_cbe__2e_sum8_count = 0;
  unsigned long long llvm_cbe__2e_sum8;
  static  unsigned long long aesl_llvm_cbe_1638_count = 0;
   char *llvm_cbe_tmp__661;
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
  static  unsigned long long aesl_llvm_cbe_1656_count = 0;
  static  unsigned long long aesl_llvm_cbe_1657_count = 0;
   char *llvm_cbe_tmp__662;
   char *llvm_cbe_tmp__662__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_putchar5_count = 0;
  unsigned int llvm_cbe_putchar5;
  static  unsigned long long aesl_llvm_cbe_1658_count = 0;
  unsigned long long llvm_cbe_tmp__663;
  static  unsigned long long aesl_llvm_cbe_1659_count = 0;
  static  unsigned long long aesl_llvm_cbe_1660_count = 0;
  static  unsigned long long aesl_llvm_cbe_1661_count = 0;
  static  unsigned long long aesl_llvm_cbe_1662_count = 0;
  static  unsigned long long aesl_llvm_cbe_1663_count = 0;
  static  unsigned long long aesl_llvm_cbe_1664_count = 0;
  static  unsigned long long aesl_llvm_cbe_1665_count = 0;
  static  unsigned long long aesl_llvm_cbe_1666_count = 0;
  static  unsigned long long aesl_llvm_cbe_1667_count = 0;
  static  unsigned long long aesl_llvm_cbe_1668_count = 0;
  static  unsigned long long aesl_llvm_cbe_1669_count = 0;
  static  unsigned long long aesl_llvm_cbe_1670_count = 0;
  static  unsigned long long aesl_llvm_cbe_1671_count = 0;
  static  unsigned long long aesl_llvm_cbe_1672_count = 0;
  static  unsigned long long aesl_llvm_cbe_1673_count = 0;
  static  unsigned long long aesl_llvm_cbe_1674_count = 0;
  static  unsigned long long aesl_llvm_cbe_1675_count = 0;
  static  unsigned long long aesl_llvm_cbe_1676_count = 0;
  static  unsigned long long aesl_llvm_cbe_1677_count = 0;
  unsigned int llvm_cbe_tmp__664;
  static  unsigned long long aesl_llvm_cbe_1678_count = 0;
  unsigned long long llvm_cbe_tmp__665;
  static  unsigned long long aesl_llvm_cbe_1679_count = 0;
  static  unsigned long long aesl_llvm_cbe_1680_count = 0;
  static  unsigned long long aesl_llvm_cbe_1681_count = 0;
  static  unsigned long long aesl_llvm_cbe_1682_count = 0;
  static  unsigned long long aesl_llvm_cbe_1683_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @print_signature\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%picnic_params.off = add i4 %%picnic_params, -7, !dbg !22 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_picnic_params_2e_off_count);
  llvm_cbe_picnic_params_2e_off = (unsigned char )((unsigned char )(llvm_cbe_picnic_params&15ull)) + ((unsigned char )(((unsigned char )-7)&15ull));
if (AESL_DEBUG_TRACE)
printf("\npicnic_params.off = 0x%X\n", ((unsigned char )(llvm_cbe_picnic_params_2e_off&15ull)));
  if ((((unsigned char )llvm_cbe_picnic_params_2e_off&15U) < ((unsigned char )((unsigned char )3)&15U))) {
    goto llvm_cbe_tmp__666;
  } else {
    goto llvm_cbe_tmp__667;
  }

llvm_cbe_tmp__666:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts = call i32 @puts(i8* getelementptr inbounds ([100 x i8]* @aesl_internal_str2, i64 0, i64 0)), !dbg !26 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_puts_count);
  puts(( char *)((&aesl_internal_str2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 100
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts = 0x%X",llvm_cbe_puts);
}
  goto llvm_cbe_tmp__668;

llvm_cbe_tmp__667:
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = call i32 @get_param_set(i4 zeroext %%picnic_params, %%struct.paramset_t* %%params), !dbg !22 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1411_count);
  get_param_set(llvm_cbe_picnic_params, (l_struct_OC_paramset_t *)(&llvm_cbe_params));
if (AESL_DEBUG_TRACE) {
printf("\nArgument picnic_params = 0x%X",llvm_cbe_picnic_params);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__584);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @allocateSignature(%%struct.signature_t* %%sig, %%struct.paramset_t* %%params) nounwind, !dbg !26 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1414_count);
  allocateSignature((l_struct_OC_signature_t *)(&llvm_cbe_sig), (l_struct_OC_paramset_t *)(&llvm_cbe_params));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = call i32 @deserializeSignature(%%struct.signature_t* %%sig, i8* %%sigBytes, i64 %%sigBytesLen, %%struct.paramset_t* %%params) nounwind, !dbg !19 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1415_count);
  llvm_cbe_tmp__585 = (unsigned int )deserializeSignature((l_struct_OC_signature_t *)(&llvm_cbe_sig), ( char *)llvm_cbe_sigBytes, llvm_cbe_sigBytesLen, (l_struct_OC_paramset_t *)(&llvm_cbe_params));
if (AESL_DEBUG_TRACE) {
printf("\nArgument sigBytesLen = 0x%I64X",llvm_cbe_sigBytesLen);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__585);
}
  if (((llvm_cbe_tmp__585&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__669;
  } else {
    goto llvm_cbe_tmp__670;
  }

llvm_cbe_tmp__670:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts4 = call i32 @puts(i8* getelementptr inbounds ([41 x i8]* @aesl_internal_str3, i64 0, i64 0)), !dbg !27 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_puts4_count);
  puts(( char *)((&aesl_internal_str3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 41
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts4 = 0x%X",llvm_cbe_puts4);
}
  goto llvm_cbe_tmp__668;

llvm_cbe_tmp__669:
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds %%struct.signature_t* %%sig, i64 0, i32 1, i64 0, !dbg !27 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1421_count);
  llvm_cbe_tmp__586 = ( char *)(&llvm_cbe_sig.field1[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds %%struct.paramset_t* %%params, i64 0, i32 8, !dbg !27 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1426_count);
  llvm_cbe_tmp__587 = (signed int *)(&llvm_cbe_params.field8);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = load i32* %%9, align 4, !dbg !27 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1427_count);
  llvm_cbe_tmp__588 = (unsigned int )*llvm_cbe_tmp__587;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__588);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = shl i32 %%10, 1, !dbg !27 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1428_count);
  llvm_cbe_tmp__589 = (unsigned int )llvm_cbe_tmp__588 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__589);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = call i32 @numBytes(i32 %%11) nounwind, !dbg !27 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1429_count);
  llvm_cbe_tmp__590 = (unsigned int )numBytes(llvm_cbe_tmp__589);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__589);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__590);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = zext i32 %%12 to i64, !dbg !27 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1430_count);
  llvm_cbe_tmp__591 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__590&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__591);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = call i8* @memcpy(i8* %%8, i8* %%sigBytes, i64 %%13 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1431_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__586, ( char *)llvm_cbe_sigBytes, llvm_cbe_tmp__591);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__591);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__592);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = load i32* %%9, align 4, !dbg !20 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1432_count);
  llvm_cbe_tmp__593 = (unsigned int )*llvm_cbe_tmp__587;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__593);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = shl i32 %%15, 1, !dbg !20 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1433_count);
  llvm_cbe_tmp__594 = (unsigned int )llvm_cbe_tmp__593 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__594);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = call i32 @numBytes(i32 %%16) nounwind, !dbg !20 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1434_count);
  llvm_cbe_tmp__595 = (unsigned int )numBytes(llvm_cbe_tmp__594);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__594);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__595);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = zext i32 %%17 to i64, !dbg !20 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1435_count);
  llvm_cbe_tmp__596 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__595&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__596);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = getelementptr inbounds i8* %%sigBytes, i64 %%18, !dbg !20 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1436_count);
  llvm_cbe_tmp__597 = ( char *)(&llvm_cbe_sigBytes[(((signed long long )llvm_cbe_tmp__596))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__596));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = load i32* %%9, align 4, !dbg !27 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1453_count);
  llvm_cbe_tmp__598 = (unsigned int )*llvm_cbe_tmp__587;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__598);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = shl i32 %%20, 1, !dbg !27 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1454_count);
  llvm_cbe_tmp__599 = (unsigned int )llvm_cbe_tmp__598 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__599);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = call i32 @numBytes(i32 %%21) nounwind, !dbg !27 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1455_count);
  llvm_cbe_tmp__600 = (unsigned int )numBytes(llvm_cbe_tmp__599);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__599);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__600);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = zext i32 %%22 to i64, !dbg !27 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1456_count);
  llvm_cbe_tmp__601 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__600&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__601);
if (AESL_DEBUG_TRACE)
printf("\n  call void @printHex(i8* getelementptr inbounds ([10 x i8]* @aesl_internal_.str18, i64 0, i64 0), i8* %%8, i64 %%23) nounwind, !dbg !27 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1457_count);
  printHex(( char *)((&aesl_internal__OC_str18[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 10
#endif
])), ( char *)llvm_cbe_tmp__586, llvm_cbe_tmp__601);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__601);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = getelementptr inbounds %%struct.signature_t* %%sig, i64 0, i32 2, i64 0, !dbg !27 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1458_count);
  llvm_cbe_tmp__602 = ( char *)(&llvm_cbe_sig.field2[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = getelementptr inbounds %%struct.paramset_t* %%params, i64 0, i32 12, !dbg !27 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1459_count);
  llvm_cbe_tmp__603 = (signed int *)(&llvm_cbe_params.field12);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = load i32* %%25, align 4, !dbg !27 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1460_count);
  llvm_cbe_tmp__604 = (unsigned int )*llvm_cbe_tmp__603;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__604);
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = zext i32 %%26 to i64, !dbg !27 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1461_count);
  llvm_cbe_tmp__605 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__604&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__605);
if (AESL_DEBUG_TRACE)
printf("\n  call void @printHex(i8* getelementptr inbounds ([5 x i8]* @aesl_internal_.str19, i64 0, i64 0), i8* %%24, i64 %%27) nounwind, !dbg !27 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1462_count);
  printHex(( char *)((&aesl_internal__OC_str19[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 5
#endif
])), ( char *)llvm_cbe_tmp__602, llvm_cbe_tmp__605);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__605);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%putchar = call i32 @putchar(i32 10) nounwind, !dbg !28 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_putchar_count);
  putchar(10u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",10u);
printf("\nReturn putchar = 0x%X",llvm_cbe_putchar);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = load i32* %%9, align 4, !dbg !28 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1481_count);
  llvm_cbe_tmp__606 = (unsigned int )*llvm_cbe_tmp__587;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__606);
  if (((llvm_cbe_tmp__606&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    goto llvm_cbe__2e_lr_2e_ph;
  }

llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = getelementptr inbounds %%struct.paramset_t* %%params, i64 0, i32 13, !dbg !20 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1484_count);
  llvm_cbe_tmp__607 = (signed int *)(&llvm_cbe_params.field13);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = getelementptr inbounds [50 x i8]* %%label, i64 0, i64 0, !dbg !28 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1485_count);
  llvm_cbe_tmp__608 = ( char *)(&llvm_cbe_label[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 50
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = getelementptr inbounds %%struct.paramset_t* %%params, i64 0, i32 14, !dbg !29 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1486_count);
  llvm_cbe_tmp__609 = ( char *)(&llvm_cbe_params.field14);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = getelementptr inbounds %%struct.paramset_t* %%params, i64 0, i32 7, !dbg !29 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1487_count);
  llvm_cbe_tmp__610 = (signed int *)(&llvm_cbe_params.field7);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = getelementptr inbounds %%struct.paramset_t* %%params, i64 0, i32 6, !dbg !29 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1488_count);
  llvm_cbe_tmp__611 = (signed int *)(&llvm_cbe_params.field6);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = getelementptr inbounds %%struct.paramset_t* %%params, i64 0, i32 5, !dbg !20 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1489_count);
  llvm_cbe_tmp__612 = (signed int *)(&llvm_cbe_params.field5);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = getelementptr inbounds %%struct.paramset_t* %%params, i64 0, i32 11, !dbg !21 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1490_count);
  llvm_cbe_tmp__613 = (signed int *)(&llvm_cbe_params.field11);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = getelementptr inbounds %%struct.paramset_t* %%params, i64 0, i32 3, !dbg !21 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1491_count);
  llvm_cbe_tmp__614 = (signed int *)(&llvm_cbe_params.field3);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge10__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  llvm_cbe_tmp__615__PHI_TEMPORARY = ( char *)llvm_cbe_tmp__597;   /* for PHI node */
  goto llvm_cbe_tmp__671;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__671:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge10 = phi i64 [ 0, %%.lr.ph ], [ %%93, %%91  for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_storemerge10_count);
  llvm_cbe_storemerge10 = (unsigned long long )llvm_cbe_storemerge10__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge10 = 0x%I64X",llvm_cbe_storemerge10);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__663);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = phi i8* [ %%19, %%.lr.ph ], [ %%92, %%91  for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1493_count);
  llvm_cbe_tmp__615 = ( char *)llvm_cbe_tmp__615__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = trunc i64 %%storemerge10 to i32, !dbg !28 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1494_count);
  llvm_cbe_tmp__616 = (unsigned int )((unsigned int )llvm_cbe_storemerge10&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__616);
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([17 x i8]* @aesl_internal_.str21, i64 0, i64 0), i32 %%40) nounwind, !dbg !28 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1495_count);
  printf(( char *)((&aesl_internal__OC_str21[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 17
#endif
])), llvm_cbe_tmp__616);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__616);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__617);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = call zeroext i8 @getChallenge(i8* %%8, i64 %%storemerge10) nounwind, !dbg !27 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1496_count);
  llvm_cbe_tmp__618 = (unsigned char )getChallenge(( char *)llvm_cbe_tmp__586, llvm_cbe_storemerge10);
if (AESL_DEBUG_TRACE) {
printf("\nArgument storemerge10 = 0x%I64X",llvm_cbe_storemerge10);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__618);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = zext i8 %%42 to i32, !dbg !28 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1502_count);
  llvm_cbe_tmp__619 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__618&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__619);
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([10 x i8]* @aesl_internal_.str22, i64 0, i64 0), i32 %%40, i32 %%43) nounwind, !dbg !28 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1503_count);
  printf(( char *)((&aesl_internal__OC_str22[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 10
#endif
])), llvm_cbe_tmp__616, llvm_cbe_tmp__619);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__616);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__619);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__620);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = getelementptr inbounds %%struct.signature_t* %%sig, i64 0, i32 0, i64 %%storemerge10, i32 4, i64 0, !dbg !20 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1504_count);
  llvm_cbe_tmp__621 = ( char *)(&llvm_cbe_sig.field0[(((signed long long )llvm_cbe_storemerge10))].field4[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge10 = 0x%I64X",((signed long long )llvm_cbe_storemerge10));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = load i32* %%30, align 4, !dbg !20 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1505_count);
  llvm_cbe_tmp__622 = (unsigned int )*llvm_cbe_tmp__607;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__622);
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = zext i32 %%46 to i64, !dbg !20 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1506_count);
  llvm_cbe_tmp__623 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__622&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__623);
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = call i8* @memcpy(i8* %%45, i8* %%39, i64 %%47 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1507_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__621, ( char *)llvm_cbe_tmp__615, llvm_cbe_tmp__623);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__623);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__624);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = getelementptr inbounds i8* %%39, i64 %%47, !dbg !20 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1508_count);
  llvm_cbe_tmp__625 = ( char *)(&llvm_cbe_tmp__615[(((signed long long )llvm_cbe_tmp__623))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__623));
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @printHex(i8* %%31, i8* %%45, i64 %%47) nounwind, !dbg !28 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1525_count);
  printHex(( char *)llvm_cbe_tmp__608, ( char *)llvm_cbe_tmp__621, llvm_cbe_tmp__623);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__623);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = load i8* %%32, align 4, !dbg !29 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1526_count);
  llvm_cbe_tmp__626 = (unsigned char )*llvm_cbe_tmp__609;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__626);
  if (((llvm_cbe_tmp__626&255U) == (((unsigned char )1)&255U))) {
    goto llvm_cbe_tmp__672;
  } else {
    llvm_cbe_tmp__640__PHI_TEMPORARY = ( char *)llvm_cbe_tmp__625;   /* for PHI node */
    goto llvm_cbe_tmp__673;
  }

llvm_cbe_tmp__674:
if (AESL_DEBUG_TRACE)
printf("\n  %%92 = phi i8* [ %%83, %%67 ], [ %%90, %%84  for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1657_count);
  llvm_cbe_tmp__662 = ( char *)llvm_cbe_tmp__662__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE)
printf("\n  %%putchar5 = call i32 @putchar(i32 10) nounwind, !dbg !30 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_putchar5_count);
  putchar(10u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",10u);
printf("\nReturn putchar5 = 0x%X",llvm_cbe_putchar5);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%93 = add i64 %%storemerge10, 1, !dbg !29 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1658_count);
  llvm_cbe_tmp__663 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge10&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__663&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%94 = load i32* %%9, align 4, !dbg !28 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1677_count);
  llvm_cbe_tmp__664 = (unsigned int )*llvm_cbe_tmp__587;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__664);
if (AESL_DEBUG_TRACE)
printf("\n  %%95 = zext i32 %%94 to i64, !dbg !28 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1678_count);
  llvm_cbe_tmp__665 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__664&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__665);
  if ((((unsigned long long )llvm_cbe_tmp__663&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__665&18446744073709551615ULL))) {
    llvm_cbe_storemerge10__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__663;   /* for PHI node */
    llvm_cbe_tmp__615__PHI_TEMPORARY = ( char *)llvm_cbe_tmp__662;   /* for PHI node */
    goto llvm_cbe_tmp__671;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

llvm_cbe_tmp__673:
if (AESL_DEBUG_TRACE)
printf("\n  %%68 = phi i8* [ %%63, %%52 ], [ %%49, %%38 ], !dbg !20 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1565_count);
  llvm_cbe_tmp__640 = ( char *)llvm_cbe_tmp__640__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE)
printf("\n  %%69 = getelementptr inbounds %%struct.signature_t* %%sig, i64 0, i32 0, i64 %%storemerge10, i32 3, i64 0, !dbg !20 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1566_count);
  llvm_cbe_tmp__641 = ( char *)(&llvm_cbe_sig.field0[(((signed long long )llvm_cbe_storemerge10))].field3[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge10 = 0x%I64X",((signed long long )llvm_cbe_storemerge10));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%70 = load i32* %%35, align 4, !dbg !20 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1567_count);
  llvm_cbe_tmp__642 = (unsigned int )*llvm_cbe_tmp__612;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__642);
if (AESL_DEBUG_TRACE)
printf("\n  %%71 = zext i32 %%70 to i64, !dbg !20 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1568_count);
  llvm_cbe_tmp__643 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__642&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__643);
if (AESL_DEBUG_TRACE)
printf("\n  %%72 = call i8* @memcpy(i8* %%69, i8* %%68, i64 %%71 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1569_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__641, ( char *)llvm_cbe_tmp__640, llvm_cbe_tmp__643);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__643);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__644);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%73 = getelementptr inbounds i8* %%68, i64 %%71, !dbg !20 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1570_count);
  llvm_cbe_tmp__645 = ( char *)(&llvm_cbe_tmp__640[(((signed long long )llvm_cbe_tmp__643))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__643));
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @printHex(i8* getelementptr inbounds ([11 x i8]* @aesl_internal_.str23, i64 0, i64 0), i8* %%69, i64 %%71) nounwind, !dbg !28 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1587_count);
  printHex(( char *)((&aesl_internal__OC_str23[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 11
#endif
])), ( char *)llvm_cbe_tmp__641, llvm_cbe_tmp__643);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__643);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%74 = getelementptr inbounds %%struct.signature_t* %%sig, i64 0, i32 0, i64 %%storemerge10, i32 0, i64 0, !dbg !21 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1588_count);
  llvm_cbe_tmp__646 = ( char *)(&llvm_cbe_sig.field0[(((signed long long )llvm_cbe_storemerge10))].field0[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge10 = 0x%I64X",((signed long long )llvm_cbe_storemerge10));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%75 = load i32* %%36, align 4, !dbg !21 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1589_count);
  llvm_cbe_tmp__647 = (unsigned int )*llvm_cbe_tmp__613;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__647);
if (AESL_DEBUG_TRACE)
printf("\n  %%76 = zext i32 %%75 to i64, !dbg !21 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1590_count);
  llvm_cbe_tmp__648 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__647&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__648);
if (AESL_DEBUG_TRACE)
printf("\n  %%77 = call i8* @memcpy(i8* %%74, i8* %%73, i64 %%76 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1591_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__646, ( char *)llvm_cbe_tmp__645, llvm_cbe_tmp__648);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__648);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__649);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum = add i64 %%76, %%71, !dbg !21 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe__2e_sum_count);
  llvm_cbe__2e_sum = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__648&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__643&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%78 = getelementptr inbounds i8* %%68, i64 %%.sum, !dbg !21 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1592_count);
  llvm_cbe_tmp__650 = ( char *)(&llvm_cbe_tmp__640[(((signed long long )llvm_cbe__2e_sum))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum = 0x%I64X",((signed long long )llvm_cbe__2e_sum));
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @printHex(i8* getelementptr inbounds ([6 x i8]* @aesl_internal_.str24, i64 0, i64 0), i8* %%74, i64 %%76) nounwind, !dbg !28 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1609_count);
  printHex(( char *)((&aesl_internal__OC_str24[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 6
#endif
])), ( char *)llvm_cbe_tmp__646, llvm_cbe_tmp__648);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__648);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%79 = getelementptr inbounds %%struct.signature_t* %%sig, i64 0, i32 0, i64 %%storemerge10, i32 1, i64 0, !dbg !21 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1610_count);
  llvm_cbe_tmp__651 = ( char *)(&llvm_cbe_sig.field0[(((signed long long )llvm_cbe_storemerge10))].field1[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge10 = 0x%I64X",((signed long long )llvm_cbe_storemerge10));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%80 = load i32* %%36, align 4, !dbg !21 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1611_count);
  llvm_cbe_tmp__652 = (unsigned int )*llvm_cbe_tmp__613;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__652);
if (AESL_DEBUG_TRACE)
printf("\n  %%81 = zext i32 %%80 to i64, !dbg !21 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1612_count);
  llvm_cbe_tmp__653 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__652&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__653);
if (AESL_DEBUG_TRACE)
printf("\n  %%82 = call i8* @memcpy(i8* %%79, i8* %%78, i64 %%81 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1613_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__651, ( char *)llvm_cbe_tmp__650, llvm_cbe_tmp__653);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__653);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__654);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum7 = add i64 %%81, %%.sum, !dbg !21 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe__2e_sum7_count);
  llvm_cbe__2e_sum7 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__653&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe__2e_sum&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum7 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum7&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%83 = getelementptr inbounds i8* %%68, i64 %%.sum7, !dbg !21 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1614_count);
  llvm_cbe_tmp__655 = ( char *)(&llvm_cbe_tmp__640[(((signed long long )llvm_cbe__2e_sum7))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum7 = 0x%I64X",((signed long long )llvm_cbe__2e_sum7));
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @printHex(i8* getelementptr inbounds ([6 x i8]* @aesl_internal_.str25, i64 0, i64 0), i8* %%79, i64 %%81) nounwind, !dbg !29 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1631_count);
  printHex(( char *)((&aesl_internal__OC_str25[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 6
#endif
])), ( char *)llvm_cbe_tmp__651, llvm_cbe_tmp__653);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__653);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.off = add i8 %%42, -1, !dbg !29 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe__2e_off_count);
  llvm_cbe__2e_off = (unsigned char )((unsigned char )(((unsigned char )(llvm_cbe_tmp__618&255ull)) + ((unsigned char )(((unsigned char )-1)&255ull))));
if (AESL_DEBUG_TRACE)
printf("\n.off = 0x%X\n", ((unsigned char )(llvm_cbe__2e_off&255ull)));
  if ((((unsigned char )llvm_cbe__2e_off&255U) < ((unsigned char )((unsigned char )2)&255U))) {
    goto llvm_cbe_tmp__675;
  } else {
    llvm_cbe_tmp__662__PHI_TEMPORARY = ( char *)llvm_cbe_tmp__655;   /* for PHI node */
    goto llvm_cbe_tmp__674;
  }

llvm_cbe_tmp__672:
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = load i32* %%33, align 4, !dbg !29 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1530_count);
  llvm_cbe_tmp__627 = (unsigned int )*llvm_cbe_tmp__610;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__627);
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = load i32* %%34, align 4, !dbg !29 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1531_count);
  llvm_cbe_tmp__628 = (unsigned int )*llvm_cbe_tmp__611;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__628);
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = select i1 %%53, i32 %%54, i32 %%55, !dbg !29 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1532_count);
  llvm_cbe_tmp__629 = (unsigned int )((((llvm_cbe_tmp__618&255U) == (((unsigned char )0)&255U))) ? ((unsigned int )llvm_cbe_tmp__627) : ((unsigned int )llvm_cbe_tmp__628));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__629);
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = zext i32 %%56 to i64, !dbg !29 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1533_count);
  llvm_cbe_tmp__630 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__629&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__630);
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = getelementptr inbounds %%struct.signature_t* %%sig, i64 0, i32 0, i64 %%storemerge10, i32 5, !dbg !20 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1538_count);
  llvm_cbe_tmp__631 = ( char *)(&llvm_cbe_sig.field0[(((signed long long )llvm_cbe_storemerge10))].field5);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge10 = 0x%I64X",((signed long long )llvm_cbe_storemerge10));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = load i8* %%58, align 1, !dbg !20 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1539_count);
  llvm_cbe_tmp__632 = (unsigned char )*llvm_cbe_tmp__631;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__632);
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = zext i8 %%59 to i64, !dbg !20 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1540_count);
  llvm_cbe_tmp__633 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_tmp__632&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__633);
if (AESL_DEBUG_TRACE)
printf("\n  %%61 = inttoptr i64 %%60 to i8*, !dbg !20 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1541_count);
  llvm_cbe_tmp__634 = ( char *)(( char *)(unsigned long)llvm_cbe_tmp__633);
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = call i8* @memcpy(i8* %%61, i8* %%49, i64 %%57 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1542_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__634, ( char *)llvm_cbe_tmp__625, llvm_cbe_tmp__630);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__630);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__635);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum9 = add i64 %%57, %%47, !dbg !20 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe__2e_sum9_count);
  llvm_cbe__2e_sum9 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__630&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__623&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum9 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum9&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = getelementptr inbounds i8* %%39, i64 %%.sum9, !dbg !20 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1543_count);
  llvm_cbe_tmp__636 = ( char *)(&llvm_cbe_tmp__615[(((signed long long )llvm_cbe__2e_sum9))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum9 = 0x%I64X",((signed long long )llvm_cbe__2e_sum9));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%64 = load i8* %%58, align 1, !dbg !28 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1560_count);
  llvm_cbe_tmp__637 = (unsigned char )*llvm_cbe_tmp__631;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__637);
if (AESL_DEBUG_TRACE)
printf("\n  %%65 = zext i8 %%64 to i64, !dbg !28 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1561_count);
  llvm_cbe_tmp__638 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_tmp__637&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__638);
if (AESL_DEBUG_TRACE)
printf("\n  %%66 = inttoptr i64 %%65 to i8*, !dbg !28 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1562_count);
  llvm_cbe_tmp__639 = ( char *)(( char *)(unsigned long)llvm_cbe_tmp__638);
if (AESL_DEBUG_TRACE)
printf("\n  call void @printHex(i8* %%31, i8* %%66, i64 %%57) nounwind, !dbg !28 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1563_count);
  printHex(( char *)llvm_cbe_tmp__608, ( char *)llvm_cbe_tmp__639, llvm_cbe_tmp__630);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__630);
}
  llvm_cbe_tmp__640__PHI_TEMPORARY = ( char *)llvm_cbe_tmp__636;   /* for PHI node */
  goto llvm_cbe_tmp__673;

llvm_cbe_tmp__675:
if (AESL_DEBUG_TRACE)
printf("\n  %%85 = getelementptr inbounds %%struct.signature_t* %%sig, i64 0, i32 0, i64 %%storemerge10, i32 2, i64 0, !dbg !21 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1633_count);
  llvm_cbe_tmp__656 = (signed int *)(&llvm_cbe_sig.field0[(((signed long long )llvm_cbe_storemerge10))].field2[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge10 = 0x%I64X",((signed long long )llvm_cbe_storemerge10));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%86 = bitcast i32* %%85 to i8*, !dbg !21 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1634_count);
  llvm_cbe_tmp__657 = ( char *)(( char *)llvm_cbe_tmp__656);
if (AESL_DEBUG_TRACE)
printf("\n  %%87 = load i32* %%37, align 4, !dbg !21 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1635_count);
  llvm_cbe_tmp__658 = (unsigned int )*llvm_cbe_tmp__614;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__658);
if (AESL_DEBUG_TRACE)
printf("\n  %%88 = zext i32 %%87 to i64, !dbg !21 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1636_count);
  llvm_cbe_tmp__659 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__658&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__659);
if (AESL_DEBUG_TRACE)
printf("\n  %%89 = call i8* @memcpy(i8* %%86, i8* %%83, i64 %%88 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1637_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__657, ( char *)llvm_cbe_tmp__655, llvm_cbe_tmp__659);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__659);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__660);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum8 = add i64 %%88, %%.sum7, !dbg !21 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe__2e_sum8_count);
  llvm_cbe__2e_sum8 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__659&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe__2e_sum7&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum8 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum8&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%90 = getelementptr inbounds i8* %%68, i64 %%.sum8, !dbg !21 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1638_count);
  llvm_cbe_tmp__661 = ( char *)(&llvm_cbe_tmp__640[(((signed long long )llvm_cbe__2e_sum8))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum8 = 0x%I64X",((signed long long )llvm_cbe__2e_sum8));
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @printHex(i8* getelementptr inbounds ([11 x i8]* @aesl_internal_.str26, i64 0, i64 0), i8* %%86, i64 %%88) nounwind, !dbg !29 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1655_count);
  printHex(( char *)((&aesl_internal__OC_str26[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 11
#endif
])), ( char *)llvm_cbe_tmp__657, llvm_cbe_tmp__659);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__659);
}
  llvm_cbe_tmp__662__PHI_TEMPORARY = ( char *)llvm_cbe_tmp__661;   /* for PHI node */
  goto llvm_cbe_tmp__674;

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  call void @freeSignature(%%struct.signature_t* %%sig, %%struct.paramset_t* %%params) nounwind, !dbg !30 for 0x%I64xth hint within @print_signature  --> \n", ++aesl_llvm_cbe_1681_count);
  freeSignature((l_struct_OC_signature_t *)(&llvm_cbe_sig), (l_struct_OC_paramset_t *)(&llvm_cbe_params));
if (AESL_DEBUG_TRACE) {
}
  goto llvm_cbe_tmp__668;

llvm_cbe_tmp__668:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @print_signature}\n");
  return;
}

