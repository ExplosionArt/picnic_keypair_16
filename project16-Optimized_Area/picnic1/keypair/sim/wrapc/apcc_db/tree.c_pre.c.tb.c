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
typedef struct l_struct_OC_tree_t l_struct_OC_tree_t;
typedef struct l_struct_OC_paramset_t l_struct_OC_paramset_t;
typedef struct l_struct_OC_Keccak_HashInstance l_struct_OC_Keccak_HashInstance;
typedef struct l_struct_OC_KeccakWidth1600_SpongeInstanceStruct l_struct_OC_KeccakWidth1600_SpongeInstanceStruct;

/* Structure contents */
struct l_struct_OC_tree_t {
  unsigned long long field0;
   char **field1;
  unsigned long long field2;
   char *field3;
   char *field4;
  unsigned long long field5;
  unsigned long long field6;
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


/* External Global Variable Declarations */

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
signed int exists(l_struct_OC_tree_t *llvm_cbe_tree, signed long long llvm_cbe_i);
l_struct_OC_tree_t *createTree(signed long long llvm_cbe_numLeaves, signed long long llvm_cbe_dataSize);
signed int ceil_log2(signed int );
void freeTree(l_struct_OC_tree_t *llvm_cbe_tree);
signed int isLeftChild(signed long long llvm_cbe_node);
signed int hasRightChild(l_struct_OC_tree_t *llvm_cbe_tree, signed long long llvm_cbe_node);
signed int hasLeftChild(l_struct_OC_tree_t *llvm_cbe_tree, signed long long llvm_cbe_node);
signed long long getParent(signed long long llvm_cbe_node);
 char **getLeaves(l_struct_OC_tree_t *llvm_cbe_tree);
 char *getLeaf(l_struct_OC_tree_t *llvm_cbe_tree, signed long long llvm_cbe_leafIndex);
void hashSeed( char *llvm_cbe_digest,  char *llvm_cbe_inputSeed,  char *llvm_cbe_salt,  char llvm_cbe_hashPrefix, signed long long llvm_cbe_repIndex, signed long long llvm_cbe_nodeIndex, l_struct_OC_paramset_t *llvm_cbe_params);
void HashInit(l_struct_OC_Keccak_HashInstance *, l_struct_OC_paramset_t *,  char );
void HashUpdate(l_struct_OC_Keccak_HashInstance *,  char *, signed long long );
void HashUpdateIntLE(l_struct_OC_Keccak_HashInstance *, signed short );
void HashFinal(l_struct_OC_Keccak_HashInstance *);
void HashSqueeze(l_struct_OC_Keccak_HashInstance *,  char *, signed long long );
void expandSeeds(l_struct_OC_tree_t *llvm_cbe_tree,  char *llvm_cbe_salt, signed long long llvm_cbe_repIndex, l_struct_OC_paramset_t *llvm_cbe_params);
l_struct_OC_tree_t *generateSeeds(signed long long llvm_cbe_nSeeds,  char *llvm_cbe_rootSeed,  char *llvm_cbe_salt, signed long long llvm_cbe_repIndex, l_struct_OC_paramset_t *llvm_cbe_params);
signed int isLeafNode(l_struct_OC_tree_t *llvm_cbe_tree, signed long long llvm_cbe_node);
signed int hasSibling(l_struct_OC_tree_t *llvm_cbe_tree, signed long long llvm_cbe_node);
signed long long getSibling(l_struct_OC_tree_t *llvm_cbe_tree, signed long long llvm_cbe_node);
void printSeeds( char *llvm_cbe_seedsBuf, signed long long llvm_cbe_seedLen, signed long long llvm_cbe_numSeeds);
void printHex( char *,  char *, signed long long );
void printLeaves(l_struct_OC_tree_t *llvm_cbe_tree);
signed long long revealSeedsSize(signed long long llvm_cbe_numNodes, signed short *llvm_cbe_hideList, signed long long llvm_cbe_hideListSize, l_struct_OC_paramset_t *llvm_cbe_params);
static signed long long *aesl_internal_getRevealedNodes(l_struct_OC_tree_t *llvm_cbe_tree, signed short *llvm_cbe_hideList, signed long long llvm_cbe_hideListSize, signed long long *llvm_cbe_outputSize);
signed long long revealSeeds(l_struct_OC_tree_t *llvm_cbe_tree, signed short *llvm_cbe_hideList, signed long long llvm_cbe_hideListSize,  char *llvm_cbe_output, signed long long llvm_cbe_outputSize, l_struct_OC_paramset_t *llvm_cbe_params);
signed int reconstructSeeds(l_struct_OC_tree_t *llvm_cbe_tree, signed short *llvm_cbe_hideList, signed long long llvm_cbe_hideListSize,  char *llvm_cbe_input, signed long long llvm_cbe_inputLen,  char *llvm_cbe_salt, signed long long llvm_cbe_repIndex, l_struct_OC_paramset_t *llvm_cbe_params);
void buildMerkleTree(l_struct_OC_tree_t *llvm_cbe_tree,  char **llvm_cbe_leafData,  char *llvm_cbe_salt, l_struct_OC_paramset_t *llvm_cbe_params);
static void aesl_internal_computeParentHash(l_struct_OC_tree_t *llvm_cbe_tree, signed long long llvm_cbe_child,  char *llvm_cbe_salt, l_struct_OC_paramset_t *llvm_cbe_params);
signed long long openMerkleTreeSize(signed long long llvm_cbe_numNodes, signed short *llvm_cbe_missingLeaves, signed long long llvm_cbe_missingLeavesSize, l_struct_OC_paramset_t *llvm_cbe_params);
static signed long long *aesl_internal_getRevealedMerkleNodes(l_struct_OC_tree_t *llvm_cbe_tree, signed short *llvm_cbe_missingLeaves, signed long long llvm_cbe_missingLeavesSize, signed long long *llvm_cbe_outputSize);
 char *openMerkleTree(l_struct_OC_tree_t *llvm_cbe_tree, signed short *llvm_cbe_missingLeaves, signed long long llvm_cbe_missingLeavesSize, signed long long *llvm_cbe_outputSizeBytes);
signed int addMerkleNodes(l_struct_OC_tree_t *llvm_cbe_tree, signed short *llvm_cbe_missingLeaves, signed long long llvm_cbe_missingLeavesSize,  char *llvm_cbe_input, signed long long llvm_cbe_inputSize);
static signed int aesl_internal_contains(signed long long *llvm_cbe_list, signed long long llvm_cbe_len, signed long long llvm_cbe_value);
signed int verifyMerkleTree(l_struct_OC_tree_t *llvm_cbe_tree,  char **llvm_cbe_leafData,  char *llvm_cbe_salt, l_struct_OC_paramset_t *llvm_cbe_params);


/* Global Variable Definitions and Initialization */
static  char aesl_internal__OC_str[10] = "node != 0";
static  char aesl_internal__OC_str10[37] = "!contains(revealed, revealedSize, 0)";
static  char aesl_internal__OC_str3[22] = "node < tree->numNodes";
static  char aesl_internal__OC_str8[53] = "!\"Insufficient sized buffer provided to revealSeeds\"";
static  char aesl_internal__OC_str5[49] = "!\"getSibling: request for node with not sibling\"";
static  char aesl_internal__OC_str6[9] = "seed %lu";
static  char aesl_internal__OC_str7[1];
static  char aesl_internal__OC_str2[28] = "leafIndex < tree->numLeaves";
static  char aesl_internal__OC_str1[60] = "C:/picnic_keypair_16-master/project16-Optimized_Area/tree.c";
static  char aesl_internal__OC_str4[23] = "hasSibling(tree, node)";
static  char aesl_internal__OC_str9[36] = "missingLeavesSize < tree->numLeaves";


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

signed int exists(l_struct_OC_tree_t *llvm_cbe_tree, signed long long llvm_cbe_i) {
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
  signed long long *llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
  unsigned long long llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
   char **llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
   char *llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
   char *llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  unsigned char llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e__count = 0;
  unsigned int llvm_cbe__2e_;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @exists\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.tree_t* %%tree, i64 0, i32 5, !dbg !24 for 0x%I64xth hint within @exists  --> \n", ++aesl_llvm_cbe_7_count);
  llvm_cbe_tmp__1 = (signed long long *)(&llvm_cbe_tree->field5);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i64* %%1, align 8, !dbg !24 for 0x%I64xth hint within @exists  --> \n", ++aesl_llvm_cbe_8_count);
  llvm_cbe_tmp__2 = (unsigned long long )*llvm_cbe_tmp__1;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__2);
  if ((((unsigned long long )llvm_cbe_tmp__2&18446744073709551615ULL) > ((unsigned long long )llvm_cbe_i&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__7;
  } else {
    goto llvm_cbe_tmp__8;
  }

llvm_cbe_tmp__7:
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds %%struct.tree_t* %%tree, i64 0, i32 4, !dbg !24 for 0x%I64xth hint within @exists  --> \n", ++aesl_llvm_cbe_11_count);
  llvm_cbe_tmp__3 = ( char **)(&llvm_cbe_tree->field4);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load i8** %%5, align 8, !dbg !24 for 0x%I64xth hint within @exists  --> \n", ++aesl_llvm_cbe_12_count);
  llvm_cbe_tmp__4 = ( char *)*llvm_cbe_tmp__3;
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds i8* %%6, i64 %%i, !dbg !24 for 0x%I64xth hint within @exists  --> \n", ++aesl_llvm_cbe_13_count);
  llvm_cbe_tmp__5 = ( char *)(&llvm_cbe_tmp__4[(((signed long long )llvm_cbe_i))]);
if (AESL_DEBUG_TRACE) {
printf("\ni = 0x%I64X",((signed long long )llvm_cbe_i));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load i8* %%7, align 1, !dbg !24 for 0x%I64xth hint within @exists  --> \n", ++aesl_llvm_cbe_14_count);
  llvm_cbe_tmp__6 = (unsigned char )*llvm_cbe_tmp__5;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__6);
if (AESL_DEBUG_TRACE)
printf("\n  %%. = select i1 %%9, i32 0, i32 1, !dbg !24 for 0x%I64xth hint within @exists  --> \n", ++aesl_llvm_cbe__2e__count);
  llvm_cbe__2e_ = (unsigned int )((((llvm_cbe_tmp__6&255U) == (((unsigned char )0)&255U))) ? ((unsigned int )0u) : ((unsigned int )1u));
if (AESL_DEBUG_TRACE)
printf("\n. = 0x%X\n", llvm_cbe__2e_);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @exists}\n");
  return llvm_cbe__2e_;
llvm_cbe_tmp__8:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @exists}\n");
  return 0u;
}


l_struct_OC_tree_t *createTree(signed long long llvm_cbe_numLeaves, signed long long llvm_cbe_dataSize) {
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
   char *llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  l_struct_OC_tree_t *llvm_cbe_tmp__10;
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
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  unsigned int llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  unsigned int llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  unsigned int llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  unsigned long long llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  signed long long *llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  unsigned int llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  unsigned int llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  unsigned long long llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  unsigned int llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  unsigned long long llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  unsigned long long llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  unsigned long long llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  signed long long *llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  signed long long *llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  signed long long *llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  unsigned long long llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
   char *llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
   char **llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
   char ***llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
   char *llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
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
  unsigned long long llvm_cbe_tmp__31;
  unsigned long long llvm_cbe_tmp__31__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned int llvm_cbe_storemerge3;
  unsigned int llvm_cbe_storemerge3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_rec_count = 0;
  unsigned long long llvm_cbe__2e_rec;
  unsigned long long llvm_cbe__2e_rec__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
   char *llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
   char **llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
   char **llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_rec8_count = 0;
  unsigned long long llvm_cbe__2e_rec8;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;
  unsigned int llvm_cbe_tmp__35;
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
  unsigned long long llvm_cbe_tmp__36;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  unsigned long long llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  unsigned long long llvm_cbe_tmp__38;
  unsigned long long llvm_cbe_tmp__38__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
   char *llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
   char **llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
   char *llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
   char **llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
  unsigned long long llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe__2e_sum_count = 0;
  unsigned long long llvm_cbe__2e_sum;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
   char *llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
   char *llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  unsigned int llvm_cbe_tmp__46;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_count = 0;
  unsigned int llvm_cbe_storemerge12;
  unsigned int llvm_cbe_storemerge12__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  unsigned int llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  unsigned int llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  unsigned long long llvm_cbe_tmp__49;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  unsigned int llvm_cbe_tmp__50;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  unsigned int llvm_cbe_tmp__51;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  unsigned long long llvm_cbe_tmp__52;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  unsigned int llvm_cbe_tmp__53;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  unsigned long long llvm_cbe_tmp__54;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
   char *llvm_cbe_tmp__55;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
   char *llvm_cbe_tmp__56;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;
  unsigned int llvm_cbe_tmp__57;
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
  static  unsigned long long aesl_llvm_cbe_163_count = 0;
   char *llvm_cbe_tmp__58;
  static  unsigned long long aesl_llvm_cbe_164_count = 0;
  static  unsigned long long aesl_llvm_cbe_165_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @createTree\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = tail call i8* @malloc(i64 56), !dbg !25 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_26_count);
  llvm_cbe_tmp__9 = ( char *) /*tail*/ ( char *)malloc(56ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",56ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__9);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = bitcast i8* %%1 to %%struct.tree_t*, !dbg !25 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_27_count);
  llvm_cbe_tmp__10 = (l_struct_OC_tree_t *)((l_struct_OC_tree_t *)llvm_cbe_tmp__9);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = trunc i64 %%numLeaves to i32, !dbg !24 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_55_count);
  llvm_cbe_tmp__11 = (unsigned int )((unsigned int )llvm_cbe_numLeaves&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__11);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = tail call i32 @ceil_log2(i32 %%3) nounwind, !dbg !24 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_56_count);
  llvm_cbe_tmp__12 = (unsigned int ) /*tail*/ ceil_log2(llvm_cbe_tmp__11);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__11);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__12);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = add i32 %%4, 1, !dbg !24 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_57_count);
  llvm_cbe_tmp__13 = (unsigned int )((unsigned int )(llvm_cbe_tmp__12&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__13&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = zext i32 %%5 to i64, !dbg !24 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_58_count);
  llvm_cbe_tmp__14 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__13&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__14);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = bitcast i8* %%1 to i64*, !dbg !24 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_59_count);
  llvm_cbe_tmp__15 = (signed long long *)((signed long long *)llvm_cbe_tmp__9);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%6, i64* %%7, align 8, !dbg !24 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_60_count);
  *llvm_cbe_tmp__15 = llvm_cbe_tmp__14;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__14);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = shl i32 1, %%5, !dbg !24 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_61_count);
  llvm_cbe_tmp__16 = (unsigned int )1u << llvm_cbe_tmp__13;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__16);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = add nsw i32 %%8, -1, !dbg !24 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_62_count);
  llvm_cbe_tmp__17 = (unsigned int )((unsigned int )(llvm_cbe_tmp__16&4294967295ull)) + ((unsigned int )(4294967295u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__17&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = sext i32 %%9 to i64, !dbg !24 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_63_count);
  llvm_cbe_tmp__18 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__17);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__18);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = shl i32 1, %%4, !dbg !24 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_64_count);
  llvm_cbe_tmp__19 = (unsigned int )1u << llvm_cbe_tmp__12;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__19);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = sext i32 %%11 to i64, !dbg !24 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_65_count);
  llvm_cbe_tmp__20 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__19);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__20);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = sub i64 %%numLeaves, %%12, !dbg !24 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_66_count);
  llvm_cbe_tmp__21 = (unsigned long long )((unsigned long long )(llvm_cbe_numLeaves&18446744073709551615ull)) - ((unsigned long long )(llvm_cbe_tmp__20&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__21&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = add i64 %%13, %%10, !dbg !24 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_67_count);
  llvm_cbe_tmp__22 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__21&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__18&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__22&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds %%struct.tree_t* %%2, i64 0, i32 5, !dbg !24 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_68_count);
  llvm_cbe_tmp__23 = (signed long long *)(&llvm_cbe_tmp__10->field5);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%14, i64* %%15, align 8, !dbg !24 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_69_count);
  *llvm_cbe_tmp__23 = llvm_cbe_tmp__22;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__22);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds %%struct.tree_t* %%2, i64 0, i32 6, !dbg !24 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_70_count);
  llvm_cbe_tmp__24 = (signed long long *)(&llvm_cbe_tmp__10->field6);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%numLeaves, i64* %%16, align 8, !dbg !24 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_71_count);
  *llvm_cbe_tmp__24 = llvm_cbe_numLeaves;
if (AESL_DEBUG_TRACE)
printf("\nnumLeaves = 0x%I64X\n", llvm_cbe_numLeaves);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds %%struct.tree_t* %%2, i64 0, i32 2, !dbg !25 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_72_count);
  llvm_cbe_tmp__25 = (signed long long *)(&llvm_cbe_tmp__10->field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%dataSize, i64* %%17, align 8, !dbg !25 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_73_count);
  *llvm_cbe_tmp__25 = llvm_cbe_dataSize;
if (AESL_DEBUG_TRACE)
printf("\ndataSize = 0x%I64X\n", llvm_cbe_dataSize);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = shl i64 %%14, 3, !dbg !25 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_74_count);
  llvm_cbe_tmp__26 = (unsigned long long )llvm_cbe_tmp__22 << 3ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__26);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = tail call i8* @malloc(i64 %%18), !dbg !25 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_75_count);
  llvm_cbe_tmp__27 = ( char *) /*tail*/ ( char *)malloc(llvm_cbe_tmp__26);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__26);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__27);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = bitcast i8* %%19 to i8**, !dbg !25 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_76_count);
  llvm_cbe_tmp__28 = ( char **)(( char **)llvm_cbe_tmp__27);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = getelementptr inbounds %%struct.tree_t* %%2, i64 0, i32 1, !dbg !25 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_77_count);
  llvm_cbe_tmp__29 = ( char ***)(&llvm_cbe_tmp__10->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8** %%20, i8*** %%21, align 8, !dbg !25 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_78_count);
  *llvm_cbe_tmp__29 = ( char **)llvm_cbe_tmp__28;
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = tail call i8* @calloc(i64 %%14, i64 %%dataSize) nounwind, !dbg !25 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_79_count);
  llvm_cbe_tmp__30 = ( char *) /*tail*/ ( char *)calloc(llvm_cbe_tmp__22, llvm_cbe_dataSize);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__22);
printf("\nArgument dataSize = 0x%I64X",llvm_cbe_dataSize);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__30);
}
  if (((llvm_cbe_tmp__22&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    llvm_cbe_tmp__38__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge6;
  } else {
    llvm_cbe_tmp__31__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    llvm_cbe__2e_rec__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph5;
  }

  do {     /* Syntactic loop '.lr.ph5' to make GCC happy */
llvm_cbe__2e_lr_2e_ph5:
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = phi i64 [ %%29, %%.lr.ph5 ], [ 0, %%0  for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_94_count);
  llvm_cbe_tmp__31 = (unsigned long long )llvm_cbe_tmp__31__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__31);
printf("\n = 0x%I64X",llvm_cbe_tmp__36);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = phi i32 [ %%28, %%.lr.ph5 ], [ 0, %%0  for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned int )llvm_cbe_storemerge3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%X",llvm_cbe_storemerge3);
printf("\n = 0x%X",llvm_cbe_tmp__35);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec = phi i64 [ %%.rec8, %%.lr.ph5 ], [ 0, %%0  for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe__2e_rec_count);
  llvm_cbe__2e_rec = (unsigned long long )llvm_cbe__2e_rec__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.rec = 0x%I64X",llvm_cbe__2e_rec);
printf("\n.rec8 = 0x%I64X",llvm_cbe__2e_rec8);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = getelementptr i8* %%22, i64 %%.re for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_95_count);
  llvm_cbe_tmp__32 = ( char *)(&llvm_cbe_tmp__30[(((signed long long )llvm_cbe__2e_rec))]);
if (AESL_DEBUG_TRACE) {
printf("\n.rec = 0x%I64X",((signed long long )llvm_cbe__2e_rec));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = load i8*** %%21, align 8, !dbg !25 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_96_count);
  llvm_cbe_tmp__33 = ( char **)*llvm_cbe_tmp__29;
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = getelementptr inbounds i8** %%26, i64 %%24, !dbg !25 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_97_count);
  llvm_cbe_tmp__34 = ( char **)(&llvm_cbe_tmp__33[(((signed long long )llvm_cbe_tmp__31))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__31));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8* %%25, i8** %%27, align 8, !dbg !25 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_98_count);
  *llvm_cbe_tmp__34 = ( char *)llvm_cbe_tmp__32;
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec8 = add i64 %%.rec, %%dataSize, !dbg !25 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe__2e_rec8_count);
  llvm_cbe__2e_rec8 = (unsigned long long )((unsigned long long )(llvm_cbe__2e_rec&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_dataSize&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.rec8 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_rec8&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = add nsw i32 %%storemerge3, 1, !dbg !27 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_99_count);
  llvm_cbe_tmp__35 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__35&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = sext i32 %%28 to i64, !dbg !25 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_109_count);
  llvm_cbe_tmp__36 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__35);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__36);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = load i64* %%15, align 8, !dbg !25 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_110_count);
  llvm_cbe_tmp__37 = (unsigned long long )*llvm_cbe_tmp__23;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__37);
  if ((((unsigned long long )llvm_cbe_tmp__36&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__37&18446744073709551615ULL))) {
    llvm_cbe_tmp__31__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__36;   /* for PHI node */
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__35;   /* for PHI node */
    llvm_cbe__2e_rec__PHI_TEMPORARY = (unsigned long long )llvm_cbe__2e_rec8;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph5;
  } else {
    llvm_cbe_tmp__38__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__37;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge6;
  }

  } while (1); /* end of syntactic loop '.lr.ph5' */
llvm_cbe__2e__crit_edge6:
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = phi i64 [ 0, %%0 ], [ %%30, %%.lr.ph5  for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_113_count);
  llvm_cbe_tmp__38 = (unsigned long long )llvm_cbe_tmp__38__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__38);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__37);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = tail call i8* @calloc(i64 %%32, i64 1) nounwind, !dbg !26 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_114_count);
  llvm_cbe_tmp__39 = ( char *) /*tail*/ ( char *)calloc(llvm_cbe_tmp__38, 1ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__38);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__39);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = getelementptr inbounds %%struct.tree_t* %%2, i64 0, i32 3, !dbg !26 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_115_count);
  llvm_cbe_tmp__40 = ( char **)(&llvm_cbe_tmp__10->field3);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8* %%33, i8** %%34, align 8, !dbg !26 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_116_count);
  *llvm_cbe_tmp__40 = ( char *)llvm_cbe_tmp__39;
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = tail call i8* @calloc(i64 %%32, i64 1) nounwind, !dbg !26 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_117_count);
  llvm_cbe_tmp__41 = ( char *) /*tail*/ ( char *)calloc(llvm_cbe_tmp__38, 1ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__38);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__41);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = getelementptr inbounds %%struct.tree_t* %%2, i64 0, i32 4, !dbg !26 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_118_count);
  llvm_cbe_tmp__42 = ( char **)(&llvm_cbe_tmp__10->field4);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8* %%35, i8** %%36, align 8, !dbg !26 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_119_count);
  *llvm_cbe_tmp__42 = ( char *)llvm_cbe_tmp__41;
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = load i64* %%16, align 8, !dbg !26 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_120_count);
  llvm_cbe_tmp__43 = (unsigned long long )*llvm_cbe_tmp__24;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__43);
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum = sub i64 %%32, %%37, !dbg !26 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe__2e_sum_count);
  llvm_cbe__2e_sum = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__38&18446744073709551615ull)) - ((unsigned long long )(llvm_cbe_tmp__43&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = getelementptr inbounds i8* %%35, i64 %%.sum, !dbg !26 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_121_count);
  llvm_cbe_tmp__44 = ( char *)(&llvm_cbe_tmp__41[(((signed long long )llvm_cbe__2e_sum))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum = 0x%I64X",((signed long long )llvm_cbe__2e_sum));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = call i8* @memset(i8* %%38, i32 1, i64 %%37 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_122_count);
  ( char *)memset(( char *)llvm_cbe_tmp__44, 1u, llvm_cbe_tmp__43);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",1u);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__43);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__45);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = trunc i64 %%.sum to i32, !dbg !26 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_123_count);
  llvm_cbe_tmp__46 = (unsigned int )((unsigned int )llvm_cbe__2e_sum&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__46);
  if ((((signed int )llvm_cbe_tmp__46) > ((signed int )0u))) {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__46;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12 = phi i32 [ %%57, %%56 ], [ %%40, %%._crit_edge6  for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_storemerge12_count);
  llvm_cbe_storemerge12 = (unsigned int )llvm_cbe_storemerge12__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%X",llvm_cbe_storemerge12);
printf("\n = 0x%X",llvm_cbe_tmp__57);
printf("\n = 0x%X",llvm_cbe_tmp__46);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = shl nsw i32 %%storemerge12, 1, !dbg !26 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_135_count);
  llvm_cbe_tmp__47 = (unsigned int )llvm_cbe_storemerge12 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__47);
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = or i32 %%42, 1, !dbg !26 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_136_count);
  llvm_cbe_tmp__48 = (unsigned int )llvm_cbe_tmp__47 | 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__48);
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = sext i32 %%43 to i64, !dbg !26 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_137_count);
  llvm_cbe_tmp__49 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__48);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__49);
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = tail call i32 @exists(%%struct.tree_t* %%2, i64 %%44), !dbg !26 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_138_count);
  llvm_cbe_tmp__50 = (unsigned int ) /*tail*/ exists((l_struct_OC_tree_t *)llvm_cbe_tmp__10, llvm_cbe_tmp__49);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__49);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__50);
}
  if (((llvm_cbe_tmp__50&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__59;
  } else {
    goto llvm_cbe_tmp__60;
  }

llvm_cbe_tmp__61:
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = add nsw i32 %%storemerge12, -1, !dbg !27 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_151_count);
  llvm_cbe_tmp__57 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12&4294967295ull)) + ((unsigned int )(4294967295u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__57&4294967295ull)));
  if ((((signed int )llvm_cbe_tmp__57) > ((signed int )0u))) {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__57;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

llvm_cbe_tmp__59:
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = add nsw i32 %%42, 2, !dbg !26 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_141_count);
  llvm_cbe_tmp__51 = (unsigned int )((unsigned int )(llvm_cbe_tmp__47&4294967295ull)) + ((unsigned int )(2u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__51&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = sext i32 %%48 to i64, !dbg !26 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_142_count);
  llvm_cbe_tmp__52 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__51);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__52);
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = tail call i32 @exists(%%struct.tree_t* %%2, i64 %%49), !dbg !26 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_143_count);
  llvm_cbe_tmp__53 = (unsigned int ) /*tail*/ exists((l_struct_OC_tree_t *)llvm_cbe_tmp__10, llvm_cbe_tmp__52);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__52);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__53);
}
  if (((llvm_cbe_tmp__53&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__61;
  } else {
    goto llvm_cbe_tmp__60;
  }

llvm_cbe_tmp__60:
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = sext i32 %%storemerge12 to i64, !dbg !26 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_146_count);
  llvm_cbe_tmp__54 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge12);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__54);
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = load i8** %%36, align 8, !dbg !26 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_147_count);
  llvm_cbe_tmp__55 = ( char *)*llvm_cbe_tmp__42;
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = getelementptr inbounds i8* %%54, i64 %%53, !dbg !26 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_148_count);
  llvm_cbe_tmp__56 = ( char *)(&llvm_cbe_tmp__55[(((signed long long )llvm_cbe_tmp__54))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__54));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 1, i8* %%55, align 1, !dbg !26 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_149_count);
  *llvm_cbe_tmp__56 = ((unsigned char )1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )1));
  goto llvm_cbe_tmp__61;

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = load i8** %%36, align 8, !dbg !27 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_163_count);
  llvm_cbe_tmp__58 = ( char *)*llvm_cbe_tmp__42;
if (AESL_DEBUG_TRACE)
printf("\n  store i8 1, i8* %%59, align 1, !dbg !27 for 0x%I64xth hint within @createTree  --> \n", ++aesl_llvm_cbe_164_count);
  *llvm_cbe_tmp__58 = ((unsigned char )1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )1));
  if (AESL_DEBUG_TRACE)
      printf("\nEND @createTree}\n");
  return llvm_cbe_tmp__10;
}


void freeTree(l_struct_OC_tree_t *llvm_cbe_tree) {
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
   char ***llvm_cbe_tmp__62;
  static  unsigned long long aesl_llvm_cbe_176_count = 0;
   char **llvm_cbe_tmp__63;
  static  unsigned long long aesl_llvm_cbe_177_count = 0;
   char *llvm_cbe_tmp__64;
  static  unsigned long long aesl_llvm_cbe_178_count = 0;
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
   char **llvm_cbe_tmp__65;
  static  unsigned long long aesl_llvm_cbe_180_count = 0;
   char *llvm_cbe_tmp__66;
  static  unsigned long long aesl_llvm_cbe_181_count = 0;
  static  unsigned long long aesl_llvm_cbe_182_count = 0;
   char **llvm_cbe_tmp__67;
  static  unsigned long long aesl_llvm_cbe_183_count = 0;
   char *llvm_cbe_tmp__68;
  static  unsigned long long aesl_llvm_cbe_184_count = 0;
  static  unsigned long long aesl_llvm_cbe_185_count = 0;
   char **llvm_cbe_tmp__69;
  static  unsigned long long aesl_llvm_cbe_186_count = 0;
   char *llvm_cbe_tmp__70;
  static  unsigned long long aesl_llvm_cbe_187_count = 0;
  static  unsigned long long aesl_llvm_cbe_188_count = 0;
   char *llvm_cbe_tmp__71;
  static  unsigned long long aesl_llvm_cbe_189_count = 0;
  static  unsigned long long aesl_llvm_cbe_190_count = 0;
  static  unsigned long long aesl_llvm_cbe_191_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @freeTree\n");
  if (((llvm_cbe_tree) == (((l_struct_OC_tree_t *)/*NULL*/0)))) {
    goto llvm_cbe_tmp__72;
  } else {
    goto llvm_cbe_tmp__73;
  }

llvm_cbe_tmp__73:
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.tree_t* %%tree, i64 0, i32 1, !dbg !24 for 0x%I64xth hint within @freeTree  --> \n", ++aesl_llvm_cbe_175_count);
  llvm_cbe_tmp__62 = ( char ***)(&llvm_cbe_tree->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i8*** %%3, align 8, !dbg !24 for 0x%I64xth hint within @freeTree  --> \n", ++aesl_llvm_cbe_176_count);
  llvm_cbe_tmp__63 = ( char **)*llvm_cbe_tmp__62;
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load i8** %%4, align 8, !dbg !24 for 0x%I64xth hint within @freeTree  --> \n", ++aesl_llvm_cbe_177_count);
  llvm_cbe_tmp__64 = ( char *)*llvm_cbe_tmp__63;
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @free(i8* %%5), !dbg !24 for 0x%I64xth hint within @freeTree  --> \n", ++aesl_llvm_cbe_178_count);
   /*tail*/ free(( char *)llvm_cbe_tmp__64);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load i8*** %%3, align 8, !dbg !24 for 0x%I64xth hint within @freeTree  --> \n", ++aesl_llvm_cbe_179_count);
  llvm_cbe_tmp__65 = ( char **)*llvm_cbe_tmp__62;
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = bitcast i8** %%6 to i8*, !dbg !24 for 0x%I64xth hint within @freeTree  --> \n", ++aesl_llvm_cbe_180_count);
  llvm_cbe_tmp__66 = ( char *)(( char *)llvm_cbe_tmp__65);
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @free(i8* %%7), !dbg !24 for 0x%I64xth hint within @freeTree  --> \n", ++aesl_llvm_cbe_181_count);
   /*tail*/ free(( char *)llvm_cbe_tmp__66);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds %%struct.tree_t* %%tree, i64 0, i32 3, !dbg !24 for 0x%I64xth hint within @freeTree  --> \n", ++aesl_llvm_cbe_182_count);
  llvm_cbe_tmp__67 = ( char **)(&llvm_cbe_tree->field3);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = load i8** %%8, align 8, !dbg !24 for 0x%I64xth hint within @freeTree  --> \n", ++aesl_llvm_cbe_183_count);
  llvm_cbe_tmp__68 = ( char *)*llvm_cbe_tmp__67;
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @free(i8* %%9), !dbg !24 for 0x%I64xth hint within @freeTree  --> \n", ++aesl_llvm_cbe_184_count);
   /*tail*/ free(( char *)llvm_cbe_tmp__68);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds %%struct.tree_t* %%tree, i64 0, i32 4, !dbg !25 for 0x%I64xth hint within @freeTree  --> \n", ++aesl_llvm_cbe_185_count);
  llvm_cbe_tmp__69 = ( char **)(&llvm_cbe_tree->field4);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = load i8** %%10, align 8, !dbg !25 for 0x%I64xth hint within @freeTree  --> \n", ++aesl_llvm_cbe_186_count);
  llvm_cbe_tmp__70 = ( char *)*llvm_cbe_tmp__69;
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @free(i8* %%11), !dbg !25 for 0x%I64xth hint within @freeTree  --> \n", ++aesl_llvm_cbe_187_count);
   /*tail*/ free(( char *)llvm_cbe_tmp__70);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = bitcast %%struct.tree_t* %%tree to i8*, !dbg !25 for 0x%I64xth hint within @freeTree  --> \n", ++aesl_llvm_cbe_188_count);
  llvm_cbe_tmp__71 = ( char *)(( char *)llvm_cbe_tree);
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @free(i8* %%12), !dbg !25 for 0x%I64xth hint within @freeTree  --> \n", ++aesl_llvm_cbe_189_count);
   /*tail*/ free(( char *)llvm_cbe_tmp__71);
if (AESL_DEBUG_TRACE) {
}
  goto llvm_cbe_tmp__72;

llvm_cbe_tmp__72:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @freeTree}\n");
  return;
}


signed int isLeftChild(signed long long llvm_cbe_node) {
  static  unsigned long long aesl_llvm_cbe_192_count = 0;
  static  unsigned long long aesl_llvm_cbe_193_count = 0;
  static  unsigned long long aesl_llvm_cbe_194_count = 0;
  static  unsigned long long aesl_llvm_cbe_195_count = 0;
  static  unsigned long long aesl_llvm_cbe_196_count = 0;
  static  unsigned long long aesl_llvm_cbe_197_count = 0;
  static  unsigned long long aesl_llvm_cbe_198_count = 0;
  static  unsigned long long aesl_llvm_cbe_199_count = 0;
  unsigned int llvm_cbe_tmp__74;
  static  unsigned long long aesl_llvm_cbe_200_count = 0;
  unsigned int llvm_cbe_tmp__75;
  static  unsigned long long aesl_llvm_cbe_201_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @isLeftChild\n");
  if (((llvm_cbe_node&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__76;
  } else {
    goto llvm_cbe_tmp__77;
  }

llvm_cbe_tmp__76:
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @_assert(i8* getelementptr inbounds ([10 x i8]* @aesl_internal_.str, i64 0, i64 0), i8* getelementptr inbounds ([60 x i8]* @aesl_internal_.str1, i64 0, i64 0), i32 90) nounwind, !dbg !24 for 0x%I64xth hint within @isLeftChild  --> \n", ++aesl_llvm_cbe_197_count);
   /*tail*/ _assert(( char *)((&aesl_internal__OC_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 10
#endif
])), ( char *)((&aesl_internal__OC_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 60
#endif
])), 90u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",90u);
}
  goto llvm_cbe_tmp__77;

llvm_cbe_tmp__77:
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = trunc i64 %%node to i32, !dbg !24 for 0x%I64xth hint within @isLeftChild  --> \n", ++aesl_llvm_cbe_199_count);
  llvm_cbe_tmp__74 = (unsigned int )((unsigned int )llvm_cbe_node&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__74);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = and i32 %%4, 1, !dbg !24 for 0x%I64xth hint within @isLeftChild  --> \n", ++aesl_llvm_cbe_200_count);
  llvm_cbe_tmp__75 = (unsigned int )llvm_cbe_tmp__74 & 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__75);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @isLeftChild}\n");
  return llvm_cbe_tmp__75;
}


signed int hasRightChild(l_struct_OC_tree_t *llvm_cbe_tree, signed long long llvm_cbe_node) {
  static  unsigned long long aesl_llvm_cbe_202_count = 0;
  static  unsigned long long aesl_llvm_cbe_203_count = 0;
  static  unsigned long long aesl_llvm_cbe_204_count = 0;
  static  unsigned long long aesl_llvm_cbe_205_count = 0;
  static  unsigned long long aesl_llvm_cbe_206_count = 0;
  static  unsigned long long aesl_llvm_cbe_207_count = 0;
  static  unsigned long long aesl_llvm_cbe_208_count = 0;
  unsigned long long llvm_cbe_tmp__78;
  static  unsigned long long aesl_llvm_cbe_209_count = 0;
  unsigned long long llvm_cbe_tmp__79;
  static  unsigned long long aesl_llvm_cbe_210_count = 0;
  signed long long *llvm_cbe_tmp__80;
  static  unsigned long long aesl_llvm_cbe_211_count = 0;
  unsigned long long llvm_cbe_tmp__81;
  static  unsigned long long aesl_llvm_cbe_212_count = 0;
  static  unsigned long long aesl_llvm_cbe_213_count = 0;
  static  unsigned long long aesl_llvm_cbe_214_count = 0;
  unsigned int llvm_cbe_tmp__82;
  static  unsigned long long aesl_llvm_cbe_215_count = 0;
  static  unsigned long long aesl_llvm_cbe_216_count = 0;
  static  unsigned long long aesl_llvm_cbe_217_count = 0;
  bool llvm_cbe_tmp__83;
  bool llvm_cbe_tmp__83__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_218_count = 0;
  unsigned int llvm_cbe_tmp__84;
  static  unsigned long long aesl_llvm_cbe_219_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @hasRightChild\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = shl i64 %%node, 1, !dbg !24 for 0x%I64xth hint within @hasRightChild  --> \n", ++aesl_llvm_cbe_208_count);
  llvm_cbe_tmp__78 = (unsigned long long )llvm_cbe_node << 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__78);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = add i64 %%1, 2, !dbg !24 for 0x%I64xth hint within @hasRightChild  --> \n", ++aesl_llvm_cbe_209_count);
  llvm_cbe_tmp__79 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__78&18446744073709551615ull)) + ((unsigned long long )(2ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__79&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.tree_t* %%tree, i64 0, i32 5, !dbg !24 for 0x%I64xth hint within @hasRightChild  --> \n", ++aesl_llvm_cbe_210_count);
  llvm_cbe_tmp__80 = (signed long long *)(&llvm_cbe_tree->field5);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i64* %%3, align 8, !dbg !24 for 0x%I64xth hint within @hasRightChild  --> \n", ++aesl_llvm_cbe_211_count);
  llvm_cbe_tmp__81 = (unsigned long long )*llvm_cbe_tmp__80;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__81);
  if ((((unsigned long long )llvm_cbe_tmp__79&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__81&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__85;
  } else {
    llvm_cbe_tmp__83__PHI_TEMPORARY = (bool )0;   /* for PHI node */
    goto llvm_cbe_tmp__86;
  }

llvm_cbe_tmp__85:
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = tail call i32 @exists(%%struct.tree_t* %%tree, i64 %%node), !dbg !24 for 0x%I64xth hint within @hasRightChild  --> \n", ++aesl_llvm_cbe_214_count);
  llvm_cbe_tmp__82 = (unsigned int ) /*tail*/ exists((l_struct_OC_tree_t *)llvm_cbe_tree, llvm_cbe_node);
if (AESL_DEBUG_TRACE) {
printf("\nArgument node = 0x%I64X",llvm_cbe_node);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__82);
}
  llvm_cbe_tmp__83__PHI_TEMPORARY = (bool )((llvm_cbe_tmp__82&4294967295U) != (0u&4294967295U));   /* for PHI node */
  goto llvm_cbe_tmp__86;

llvm_cbe_tmp__86:
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = phi i1 [ false, %%0 ], [ %%8, %%6  for 0x%I64xth hint within @hasRightChild  --> \n", ++aesl_llvm_cbe_217_count);
  llvm_cbe_tmp__83 = (bool )((llvm_cbe_tmp__83__PHI_TEMPORARY)&1);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__83);
printf("\n = 0x%X",0);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = zext i1 %%10 to i3 for 0x%I64xth hint within @hasRightChild  --> \n", ++aesl_llvm_cbe_218_count);
  llvm_cbe_tmp__84 = (unsigned int )((unsigned int )(bool )llvm_cbe_tmp__83&1U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__84);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @hasRightChild}\n");
  return llvm_cbe_tmp__84;
}


signed int hasLeftChild(l_struct_OC_tree_t *llvm_cbe_tree, signed long long llvm_cbe_node) {
  static  unsigned long long aesl_llvm_cbe_220_count = 0;
  static  unsigned long long aesl_llvm_cbe_221_count = 0;
  static  unsigned long long aesl_llvm_cbe_222_count = 0;
  static  unsigned long long aesl_llvm_cbe_223_count = 0;
  unsigned long long llvm_cbe_tmp__87;
  static  unsigned long long aesl_llvm_cbe_224_count = 0;
  unsigned long long llvm_cbe_tmp__88;
  static  unsigned long long aesl_llvm_cbe_225_count = 0;
  static  unsigned long long aesl_llvm_cbe_226_count = 0;
  signed long long *llvm_cbe_tmp__89;
  static  unsigned long long aesl_llvm_cbe_227_count = 0;
  unsigned long long llvm_cbe_tmp__90;
  static  unsigned long long aesl_llvm_cbe_228_count = 0;
  static  unsigned long long aesl_llvm_cbe_229_count = 0;
  unsigned int llvm_cbe_tmp__91;
  static  unsigned long long aesl_llvm_cbe_230_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @hasLeftChild\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = shl i64 %%node, 1, !dbg !24 for 0x%I64xth hint within @hasLeftChild  --> \n", ++aesl_llvm_cbe_223_count);
  llvm_cbe_tmp__87 = (unsigned long long )llvm_cbe_node << 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__87);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = or i64 %%1, 1, !dbg !24 for 0x%I64xth hint within @hasLeftChild  --> \n", ++aesl_llvm_cbe_224_count);
  llvm_cbe_tmp__88 = (unsigned long long )llvm_cbe_tmp__87 | 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__88);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.tree_t* %%tree, i64 0, i32 5, !dbg !24 for 0x%I64xth hint within @hasLeftChild  --> \n", ++aesl_llvm_cbe_226_count);
  llvm_cbe_tmp__89 = (signed long long *)(&llvm_cbe_tree->field5);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i64* %%3, align 8, !dbg !24 for 0x%I64xth hint within @hasLeftChild  --> \n", ++aesl_llvm_cbe_227_count);
  llvm_cbe_tmp__90 = (unsigned long long )*llvm_cbe_tmp__89;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__90);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = zext i1 %%5 to i32, !dbg !24 for 0x%I64xth hint within @hasLeftChild  --> \n", ++aesl_llvm_cbe_229_count);
  llvm_cbe_tmp__91 = (unsigned int )((unsigned int )(bool )(((unsigned long long )llvm_cbe_tmp__88&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__90&18446744073709551615ULL))&1U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__91);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @hasLeftChild}\n");
  return llvm_cbe_tmp__91;
}


signed long long getParent(signed long long llvm_cbe_node) {
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
  unsigned int llvm_cbe_tmp__92;
  static  unsigned long long aesl_llvm_cbe_241_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge_2e_in_2e_v_count = 0;
  unsigned long long llvm_cbe_storemerge_2e_in_2e_v;
  static  unsigned long long aesl_llvm_cbe_storemerge_2e_in_count = 0;
  unsigned long long llvm_cbe_storemerge_2e_in;
  static  unsigned long long aesl_llvm_cbe_storemerge_count = 0;
  unsigned long long llvm_cbe_storemerge;
  static  unsigned long long aesl_llvm_cbe_242_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @getParent\n");
  if (((llvm_cbe_node&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__93;
  } else {
    goto llvm_cbe_tmp__94;
  }

llvm_cbe_tmp__93:
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @_assert(i8* getelementptr inbounds ([10 x i8]* @aesl_internal_.str, i64 0, i64 0), i8* getelementptr inbounds ([60 x i8]* @aesl_internal_.str1, i64 0, i64 0), i32 104) nounwind, !dbg !25 for 0x%I64xth hint within @getParent  --> \n", ++aesl_llvm_cbe_238_count);
   /*tail*/ _assert(( char *)((&aesl_internal__OC_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 10
#endif
])), ( char *)((&aesl_internal__OC_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 60
#endif
])), 104u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",104u);
}
  goto llvm_cbe_tmp__94;

llvm_cbe_tmp__94:
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = tail call i32 @isLeftChild(i64 %%node), !dbg !24 for 0x%I64xth hint within @getParent  --> \n", ++aesl_llvm_cbe_240_count);
  llvm_cbe_tmp__92 = (unsigned int ) /*tail*/ isLeftChild(llvm_cbe_node);
if (AESL_DEBUG_TRACE) {
printf("\nArgument node = 0x%I64X",llvm_cbe_node);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__92);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge.in.v = select i1 %%5, i64 -2, i64 -1, !dbg !24 for 0x%I64xth hint within @getParent  --> \n", ++aesl_llvm_cbe_storemerge_2e_in_2e_v_count);
  llvm_cbe_storemerge_2e_in_2e_v = (unsigned long long )((((llvm_cbe_tmp__92&4294967295U) == (0u&4294967295U))) ? ((unsigned long long )18446744073709551614ull) : ((unsigned long long )18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\nstoremerge.in.v = 0x%I64X\n", llvm_cbe_storemerge_2e_in_2e_v);
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge.in = add i64 %%storemerge.in.v, %%node, !dbg !24 for 0x%I64xth hint within @getParent  --> \n", ++aesl_llvm_cbe_storemerge_2e_in_count);
  llvm_cbe_storemerge_2e_in = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge_2e_in_2e_v&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_node&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\nstoremerge.in = 0x%I64X\n", ((unsigned long long )(llvm_cbe_storemerge_2e_in&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge = lshr i64 %%storemerge.in, 1, !dbg !24 for 0x%I64xth hint within @getParent  --> \n", ++aesl_llvm_cbe_storemerge_count);
  llvm_cbe_storemerge = (unsigned long long )((unsigned long long )(((unsigned long long )(llvm_cbe_storemerge_2e_in&18446744073709551615ull)) >> ((unsigned long long )(1ull&18446744073709551615ull))));
if (AESL_DEBUG_TRACE)
printf("\nstoremerge = 0x%I64X\n", ((unsigned long long )(llvm_cbe_storemerge&18446744073709551615ull)));
  if (AESL_DEBUG_TRACE)
      printf("\nEND @getParent}\n");
  return llvm_cbe_storemerge;
}


 char **getLeaves(l_struct_OC_tree_t *llvm_cbe_tree) {
  static  unsigned long long aesl_llvm_cbe_243_count = 0;
  static  unsigned long long aesl_llvm_cbe_244_count = 0;
  static  unsigned long long aesl_llvm_cbe_245_count = 0;
  signed long long *llvm_cbe_tmp__95;
  static  unsigned long long aesl_llvm_cbe_246_count = 0;
  unsigned long long llvm_cbe_tmp__96;
  static  unsigned long long aesl_llvm_cbe_247_count = 0;
  static  unsigned long long aesl_llvm_cbe_248_count = 0;
  signed long long *llvm_cbe_tmp__97;
  static  unsigned long long aesl_llvm_cbe_249_count = 0;
  unsigned long long llvm_cbe_tmp__98;
  static  unsigned long long aesl_llvm_cbe_250_count = 0;
  unsigned long long llvm_cbe_tmp__99;
  static  unsigned long long aesl_llvm_cbe_251_count = 0;
  static  unsigned long long aesl_llvm_cbe_252_count = 0;
   char ***llvm_cbe_tmp__100;
  static  unsigned long long aesl_llvm_cbe_253_count = 0;
   char **llvm_cbe_tmp__101;
  static  unsigned long long aesl_llvm_cbe_254_count = 0;
   char **llvm_cbe_tmp__102;
  static  unsigned long long aesl_llvm_cbe_255_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @getLeaves\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.tree_t* %%tree, i64 0, i32 5, !dbg !24 for 0x%I64xth hint within @getLeaves  --> \n", ++aesl_llvm_cbe_245_count);
  llvm_cbe_tmp__95 = (signed long long *)(&llvm_cbe_tree->field5);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i64* %%1, align 8, !dbg !24 for 0x%I64xth hint within @getLeaves  --> \n", ++aesl_llvm_cbe_246_count);
  llvm_cbe_tmp__96 = (unsigned long long )*llvm_cbe_tmp__95;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__96);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.tree_t* %%tree, i64 0, i32 6, !dbg !24 for 0x%I64xth hint within @getLeaves  --> \n", ++aesl_llvm_cbe_248_count);
  llvm_cbe_tmp__97 = (signed long long *)(&llvm_cbe_tree->field6);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i64* %%3, align 8, !dbg !24 for 0x%I64xth hint within @getLeaves  --> \n", ++aesl_llvm_cbe_249_count);
  llvm_cbe_tmp__98 = (unsigned long long )*llvm_cbe_tmp__97;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__98);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = sub i64 %%2, %%4, !dbg !24 for 0x%I64xth hint within @getLeaves  --> \n", ++aesl_llvm_cbe_250_count);
  llvm_cbe_tmp__99 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__96&18446744073709551615ull)) - ((unsigned long long )(llvm_cbe_tmp__98&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__99&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds %%struct.tree_t* %%tree, i64 0, i32 1, !dbg !24 for 0x%I64xth hint within @getLeaves  --> \n", ++aesl_llvm_cbe_252_count);
  llvm_cbe_tmp__100 = ( char ***)(&llvm_cbe_tree->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = load i8*** %%6, align 8, !dbg !24 for 0x%I64xth hint within @getLeaves  --> \n", ++aesl_llvm_cbe_253_count);
  llvm_cbe_tmp__101 = ( char **)*llvm_cbe_tmp__100;
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds i8** %%7, i64 %%5, !dbg !24 for 0x%I64xth hint within @getLeaves  --> \n", ++aesl_llvm_cbe_254_count);
  llvm_cbe_tmp__102 = ( char **)(&llvm_cbe_tmp__101[(((signed long long )llvm_cbe_tmp__99))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__99));
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @getLeaves}\n");
  return llvm_cbe_tmp__102;
}


 char *getLeaf(l_struct_OC_tree_t *llvm_cbe_tree, signed long long llvm_cbe_leafIndex) {
  static  unsigned long long aesl_llvm_cbe_256_count = 0;
  static  unsigned long long aesl_llvm_cbe_257_count = 0;
  static  unsigned long long aesl_llvm_cbe_258_count = 0;
  static  unsigned long long aesl_llvm_cbe_259_count = 0;
  static  unsigned long long aesl_llvm_cbe_260_count = 0;
  static  unsigned long long aesl_llvm_cbe_261_count = 0;
  static  unsigned long long aesl_llvm_cbe_262_count = 0;
  static  unsigned long long aesl_llvm_cbe_263_count = 0;
  static  unsigned long long aesl_llvm_cbe_264_count = 0;
  signed long long *llvm_cbe_tmp__103;
  static  unsigned long long aesl_llvm_cbe_265_count = 0;
  unsigned long long llvm_cbe_tmp__104;
  static  unsigned long long aesl_llvm_cbe_266_count = 0;
  static  unsigned long long aesl_llvm_cbe_267_count = 0;
  static  unsigned long long aesl_llvm_cbe_268_count = 0;
  static  unsigned long long aesl_llvm_cbe_269_count = 0;
  static  unsigned long long aesl_llvm_cbe_270_count = 0;
  signed long long *llvm_cbe_tmp__105;
  static  unsigned long long aesl_llvm_cbe_271_count = 0;
  unsigned long long llvm_cbe_tmp__106;
  static  unsigned long long aesl_llvm_cbe_272_count = 0;
  unsigned long long llvm_cbe_tmp__107;
  static  unsigned long long aesl_llvm_cbe_273_count = 0;
  static  unsigned long long aesl_llvm_cbe_274_count = 0;
  unsigned long long llvm_cbe_tmp__108;
  static  unsigned long long aesl_llvm_cbe_275_count = 0;
  unsigned long long llvm_cbe_tmp__109;
  static  unsigned long long aesl_llvm_cbe_276_count = 0;
   char ***llvm_cbe_tmp__110;
  static  unsigned long long aesl_llvm_cbe_277_count = 0;
   char **llvm_cbe_tmp__111;
  static  unsigned long long aesl_llvm_cbe_278_count = 0;
   char **llvm_cbe_tmp__112;
  static  unsigned long long aesl_llvm_cbe_279_count = 0;
   char *llvm_cbe_tmp__113;
  static  unsigned long long aesl_llvm_cbe_280_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @getLeaf\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.tree_t* %%tree, i64 0, i32 6, !dbg !24 for 0x%I64xth hint within @getLeaf  --> \n", ++aesl_llvm_cbe_264_count);
  llvm_cbe_tmp__103 = (signed long long *)(&llvm_cbe_tree->field6);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i64* %%1, align 8, !dbg !24 for 0x%I64xth hint within @getLeaf  --> \n", ++aesl_llvm_cbe_265_count);
  llvm_cbe_tmp__104 = (unsigned long long )*llvm_cbe_tmp__103;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__104);
  if ((((unsigned long long )llvm_cbe_tmp__104&18446744073709551615ULL) > ((unsigned long long )llvm_cbe_leafIndex&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__114;
  } else {
    goto llvm_cbe_tmp__115;
  }

llvm_cbe_tmp__115:
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @_assert(i8* getelementptr inbounds ([28 x i8]* @aesl_internal_.str2, i64 0, i64 0), i8* getelementptr inbounds ([60 x i8]* @aesl_internal_.str1, i64 0, i64 0), i32 119) nounwind, !dbg !25 for 0x%I64xth hint within @getLeaf  --> \n", ++aesl_llvm_cbe_268_count);
   /*tail*/ _assert(( char *)((&aesl_internal__OC_str2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 28
#endif
])), ( char *)((&aesl_internal__OC_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 60
#endif
])), 119u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",119u);
}
  goto llvm_cbe_tmp__114;

llvm_cbe_tmp__114:
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds %%struct.tree_t* %%tree, i64 0, i32 5, !dbg !24 for 0x%I64xth hint within @getLeaf  --> \n", ++aesl_llvm_cbe_270_count);
  llvm_cbe_tmp__105 = (signed long long *)(&llvm_cbe_tree->field5);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = load i64* %%6, align 8, !dbg !24 for 0x%I64xth hint within @getLeaf  --> \n", ++aesl_llvm_cbe_271_count);
  llvm_cbe_tmp__106 = (unsigned long long )*llvm_cbe_tmp__105;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__106);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load i64* %%1, align 8, !dbg !24 for 0x%I64xth hint within @getLeaf  --> \n", ++aesl_llvm_cbe_272_count);
  llvm_cbe_tmp__107 = (unsigned long long )*llvm_cbe_tmp__103;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__107);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = add i64 %%7, %%leafIndex, !dbg !24 for 0x%I64xth hint within @getLeaf  --> \n", ++aesl_llvm_cbe_274_count);
  llvm_cbe_tmp__108 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__106&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_leafIndex&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__108&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = sub i64 %%9, %%8, !dbg !24 for 0x%I64xth hint within @getLeaf  --> \n", ++aesl_llvm_cbe_275_count);
  llvm_cbe_tmp__109 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__108&18446744073709551615ull)) - ((unsigned long long )(llvm_cbe_tmp__107&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__109&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds %%struct.tree_t* %%tree, i64 0, i32 1, !dbg !24 for 0x%I64xth hint within @getLeaf  --> \n", ++aesl_llvm_cbe_276_count);
  llvm_cbe_tmp__110 = ( char ***)(&llvm_cbe_tree->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = load i8*** %%11, align 8, !dbg !24 for 0x%I64xth hint within @getLeaf  --> \n", ++aesl_llvm_cbe_277_count);
  llvm_cbe_tmp__111 = ( char **)*llvm_cbe_tmp__110;
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds i8** %%12, i64 %%10, !dbg !24 for 0x%I64xth hint within @getLeaf  --> \n", ++aesl_llvm_cbe_278_count);
  llvm_cbe_tmp__112 = ( char **)(&llvm_cbe_tmp__111[(((signed long long )llvm_cbe_tmp__109))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__109));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load i8** %%13, align 8, !dbg !24 for 0x%I64xth hint within @getLeaf  --> \n", ++aesl_llvm_cbe_279_count);
  llvm_cbe_tmp__113 = ( char *)*llvm_cbe_tmp__112;
  if (AESL_DEBUG_TRACE)
      printf("\nEND @getLeaf}\n");
  return llvm_cbe_tmp__113;
}


void hashSeed( char *llvm_cbe_digest,  char *llvm_cbe_inputSeed,  char *llvm_cbe_salt,  char llvm_cbe_hashPrefix, signed long long llvm_cbe_repIndex, signed long long llvm_cbe_nodeIndex, l_struct_OC_paramset_t *llvm_cbe_params) {
  static  unsigned long long aesl_llvm_cbe_ctx_count = 0;
  l_struct_OC_Keccak_HashInstance llvm_cbe_ctx;    /* Address-exposed local */
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
  signed int *llvm_cbe_tmp__116;
  static  unsigned long long aesl_llvm_cbe_301_count = 0;
  unsigned int llvm_cbe_tmp__117;
  static  unsigned long long aesl_llvm_cbe_302_count = 0;
  unsigned long long llvm_cbe_tmp__118;
  static  unsigned long long aesl_llvm_cbe_303_count = 0;
  static  unsigned long long aesl_llvm_cbe_304_count = 0;
  signed int *llvm_cbe_tmp__119;
  static  unsigned long long aesl_llvm_cbe_305_count = 0;
  unsigned int llvm_cbe_tmp__120;
  static  unsigned long long aesl_llvm_cbe_306_count = 0;
  unsigned long long llvm_cbe_tmp__121;
  static  unsigned long long aesl_llvm_cbe_307_count = 0;
  static  unsigned long long aesl_llvm_cbe_308_count = 0;
  unsigned short llvm_cbe_tmp__122;
  static  unsigned long long aesl_llvm_cbe_309_count = 0;
  static  unsigned long long aesl_llvm_cbe_310_count = 0;
  unsigned short llvm_cbe_tmp__123;
  static  unsigned long long aesl_llvm_cbe_311_count = 0;
  static  unsigned long long aesl_llvm_cbe_312_count = 0;
  static  unsigned long long aesl_llvm_cbe_313_count = 0;
  unsigned int llvm_cbe_tmp__124;
  static  unsigned long long aesl_llvm_cbe_314_count = 0;
  unsigned int llvm_cbe_tmp__125;
  static  unsigned long long aesl_llvm_cbe_315_count = 0;
  unsigned long long llvm_cbe_tmp__126;
  static  unsigned long long aesl_llvm_cbe_316_count = 0;
  static  unsigned long long aesl_llvm_cbe_317_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @hashSeed\n");
if (AESL_DEBUG_TRACE)
printf("\n  call void @HashInit(%%struct.Keccak_HashInstance* %%ctx, %%struct.paramset_t* %%params, i8 zeroext %%hashPrefix) nounwind, !dbg !26 for 0x%I64xth hint within @hashSeed  --> \n", ++aesl_llvm_cbe_299_count);
  HashInit((l_struct_OC_Keccak_HashInstance *)(&llvm_cbe_ctx), (l_struct_OC_paramset_t *)llvm_cbe_params, llvm_cbe_hashPrefix);
if (AESL_DEBUG_TRACE) {
printf("\nArgument hashPrefix = 0x%X",llvm_cbe_hashPrefix);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.paramset_t* %%params, i64 0, i32 11, !dbg !24 for 0x%I64xth hint within @hashSeed  --> \n", ++aesl_llvm_cbe_300_count);
  llvm_cbe_tmp__116 = (signed int *)(&llvm_cbe_params->field11);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i32* %%1, align 4, !dbg !24 for 0x%I64xth hint within @hashSeed  --> \n", ++aesl_llvm_cbe_301_count);
  llvm_cbe_tmp__117 = (unsigned int )*llvm_cbe_tmp__116;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__117);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = zext i32 %%2 to i64, !dbg !24 for 0x%I64xth hint within @hashSeed  --> \n", ++aesl_llvm_cbe_302_count);
  llvm_cbe_tmp__118 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__117&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__118);
if (AESL_DEBUG_TRACE)
printf("\n  call void @HashUpdate(%%struct.Keccak_HashInstance* %%ctx, i8* %%inputSeed, i64 %%3) nounwind, !dbg !24 for 0x%I64xth hint within @hashSeed  --> \n", ++aesl_llvm_cbe_303_count);
  HashUpdate((l_struct_OC_Keccak_HashInstance *)(&llvm_cbe_ctx), ( char *)llvm_cbe_inputSeed, llvm_cbe_tmp__118);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__118);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds %%struct.paramset_t* %%params, i64 0, i32 12, !dbg !25 for 0x%I64xth hint within @hashSeed  --> \n", ++aesl_llvm_cbe_304_count);
  llvm_cbe_tmp__119 = (signed int *)(&llvm_cbe_params->field12);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load i32* %%4, align 4, !dbg !25 for 0x%I64xth hint within @hashSeed  --> \n", ++aesl_llvm_cbe_305_count);
  llvm_cbe_tmp__120 = (unsigned int )*llvm_cbe_tmp__119;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__120);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = zext i32 %%5 to i64, !dbg !25 for 0x%I64xth hint within @hashSeed  --> \n", ++aesl_llvm_cbe_306_count);
  llvm_cbe_tmp__121 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__120&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__121);
if (AESL_DEBUG_TRACE)
printf("\n  call void @HashUpdate(%%struct.Keccak_HashInstance* %%ctx, i8* %%salt, i64 %%6) nounwind, !dbg !25 for 0x%I64xth hint within @hashSeed  --> \n", ++aesl_llvm_cbe_307_count);
  HashUpdate((l_struct_OC_Keccak_HashInstance *)(&llvm_cbe_ctx), ( char *)llvm_cbe_salt, llvm_cbe_tmp__121);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__121);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = trunc i64 %%repIndex to i16, !dbg !25 for 0x%I64xth hint within @hashSeed  --> \n", ++aesl_llvm_cbe_308_count);
  llvm_cbe_tmp__122 = (unsigned short )((unsigned short )llvm_cbe_repIndex&65535U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__122);
if (AESL_DEBUG_TRACE)
printf("\n  call void @HashUpdateIntLE(%%struct.Keccak_HashInstance* %%ctx, i16 zeroext %%7) nounwind, !dbg !25 for 0x%I64xth hint within @hashSeed  --> \n", ++aesl_llvm_cbe_309_count);
  HashUpdateIntLE((l_struct_OC_Keccak_HashInstance *)(&llvm_cbe_ctx), llvm_cbe_tmp__122);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__122);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = trunc i64 %%nodeIndex to i16, !dbg !25 for 0x%I64xth hint within @hashSeed  --> \n", ++aesl_llvm_cbe_310_count);
  llvm_cbe_tmp__123 = (unsigned short )((unsigned short )llvm_cbe_nodeIndex&65535U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__123);
if (AESL_DEBUG_TRACE)
printf("\n  call void @HashUpdateIntLE(%%struct.Keccak_HashInstance* %%ctx, i16 zeroext %%8) nounwind, !dbg !25 for 0x%I64xth hint within @hashSeed  --> \n", ++aesl_llvm_cbe_311_count);
  HashUpdateIntLE((l_struct_OC_Keccak_HashInstance *)(&llvm_cbe_ctx), llvm_cbe_tmp__123);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__123);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @HashFinal(%%struct.Keccak_HashInstance* %%ctx) nounwind, !dbg !28 for 0x%I64xth hint within @hashSeed  --> \n", ++aesl_llvm_cbe_312_count);
  HashFinal((l_struct_OC_Keccak_HashInstance *)(&llvm_cbe_ctx));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = load i32* %%1, align 4, !dbg !24 for 0x%I64xth hint within @hashSeed  --> \n", ++aesl_llvm_cbe_313_count);
  llvm_cbe_tmp__124 = (unsigned int )*llvm_cbe_tmp__116;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__124);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = shl i32 %%9, 1, !dbg !24 for 0x%I64xth hint within @hashSeed  --> \n", ++aesl_llvm_cbe_314_count);
  llvm_cbe_tmp__125 = (unsigned int )llvm_cbe_tmp__124 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__125);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = zext i32 %%10 to i64, !dbg !24 for 0x%I64xth hint within @hashSeed  --> \n", ++aesl_llvm_cbe_315_count);
  llvm_cbe_tmp__126 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__125&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__126);
if (AESL_DEBUG_TRACE)
printf("\n  call void @HashSqueeze(%%struct.Keccak_HashInstance* %%ctx, i8* %%digest, i64 %%11) nounwind, !dbg !24 for 0x%I64xth hint within @hashSeed  --> \n", ++aesl_llvm_cbe_316_count);
  HashSqueeze((l_struct_OC_Keccak_HashInstance *)(&llvm_cbe_ctx), ( char *)llvm_cbe_digest, llvm_cbe_tmp__126);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__126);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @hashSeed}\n");
  return;
}


void expandSeeds(l_struct_OC_tree_t *llvm_cbe_tree,  char *llvm_cbe_salt, signed long long llvm_cbe_repIndex, l_struct_OC_paramset_t *llvm_cbe_params) {
  static  unsigned long long aesl_llvm_cbe_tmp_count = 0;
   char llvm_cbe_tmp[64];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_318_count = 0;
  static  unsigned long long aesl_llvm_cbe_319_count = 0;
  static  unsigned long long aesl_llvm_cbe_320_count = 0;
  static  unsigned long long aesl_llvm_cbe_321_count = 0;
  static  unsigned long long aesl_llvm_cbe_322_count = 0;
  static  unsigned long long aesl_llvm_cbe_323_count = 0;
  static  unsigned long long aesl_llvm_cbe_324_count = 0;
  static  unsigned long long aesl_llvm_cbe_325_count = 0;
  static  unsigned long long aesl_llvm_cbe_326_count = 0;
  static  unsigned long long aesl_llvm_cbe_327_count = 0;
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
  signed long long *llvm_cbe_tmp__127;
  static  unsigned long long aesl_llvm_cbe_340_count = 0;
  unsigned long long llvm_cbe_tmp__128;
  static  unsigned long long aesl_llvm_cbe_341_count = 0;
  unsigned long long llvm_cbe_tmp__129;
  static  unsigned long long aesl_llvm_cbe_342_count = 0;
  unsigned long long llvm_cbe_tmp__130;
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
   char **llvm_cbe_tmp__131;
  static  unsigned long long aesl_llvm_cbe_359_count = 0;
   char *llvm_cbe_tmp__132;
  static  unsigned long long aesl_llvm_cbe_360_count = 0;
   char ***llvm_cbe_tmp__133;
  static  unsigned long long aesl_llvm_cbe_361_count = 0;
  signed int *llvm_cbe_tmp__134;
  static  unsigned long long aesl_llvm_cbe_362_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned long long llvm_cbe_storemerge1;
  unsigned long long llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_363_count = 0;
   char *llvm_cbe_tmp__135;
  static  unsigned long long aesl_llvm_cbe_364_count = 0;
   char *llvm_cbe_tmp__136;
  static  unsigned long long aesl_llvm_cbe_365_count = 0;
  unsigned char llvm_cbe_tmp__137;
  static  unsigned long long aesl_llvm_cbe_366_count = 0;
  static  unsigned long long aesl_llvm_cbe_367_count = 0;
  static  unsigned long long aesl_llvm_cbe_368_count = 0;
   char **llvm_cbe_tmp__138;
  static  unsigned long long aesl_llvm_cbe_369_count = 0;
   char **llvm_cbe_tmp__139;
  static  unsigned long long aesl_llvm_cbe_370_count = 0;
   char *llvm_cbe_tmp__140;
  static  unsigned long long aesl_llvm_cbe_371_count = 0;
  static  unsigned long long aesl_llvm_cbe_372_count = 0;
  unsigned long long llvm_cbe_tmp__141;
  static  unsigned long long aesl_llvm_cbe_373_count = 0;
  unsigned long long llvm_cbe_tmp__142;
  static  unsigned long long aesl_llvm_cbe_374_count = 0;
   char *llvm_cbe_tmp__143;
  static  unsigned long long aesl_llvm_cbe_375_count = 0;
   char *llvm_cbe_tmp__144;
  static  unsigned long long aesl_llvm_cbe_376_count = 0;
  unsigned char llvm_cbe_tmp__145;
  static  unsigned long long aesl_llvm_cbe_377_count = 0;
  static  unsigned long long aesl_llvm_cbe_378_count = 0;
  static  unsigned long long aesl_llvm_cbe_379_count = 0;
   char **llvm_cbe_tmp__146;
  static  unsigned long long aesl_llvm_cbe_380_count = 0;
   char **llvm_cbe_tmp__147;
  static  unsigned long long aesl_llvm_cbe_381_count = 0;
   char *llvm_cbe_tmp__148;
  static  unsigned long long aesl_llvm_cbe_382_count = 0;
  unsigned int llvm_cbe_tmp__149;
  static  unsigned long long aesl_llvm_cbe_383_count = 0;
  unsigned long long llvm_cbe_tmp__150;
  static  unsigned long long aesl_llvm_cbe_384_count = 0;
   char *llvm_cbe_tmp__151;
  static  unsigned long long aesl_llvm_cbe_385_count = 0;
   char *llvm_cbe_tmp__152;
  static  unsigned long long aesl_llvm_cbe_386_count = 0;
   char *llvm_cbe_tmp__153;
  static  unsigned long long aesl_llvm_cbe_387_count = 0;
  static  unsigned long long aesl_llvm_cbe_388_count = 0;
  static  unsigned long long aesl_llvm_cbe_389_count = 0;
  unsigned long long llvm_cbe_tmp__154;
  static  unsigned long long aesl_llvm_cbe_390_count = 0;
  unsigned int llvm_cbe_tmp__155;
  static  unsigned long long aesl_llvm_cbe_391_count = 0;
  static  unsigned long long aesl_llvm_cbe_392_count = 0;
  static  unsigned long long aesl_llvm_cbe_393_count = 0;
   char *llvm_cbe_tmp__156;
  static  unsigned long long aesl_llvm_cbe_394_count = 0;
   char *llvm_cbe_tmp__157;
  static  unsigned long long aesl_llvm_cbe_395_count = 0;
  unsigned char llvm_cbe_tmp__158;
  static  unsigned long long aesl_llvm_cbe_396_count = 0;
  static  unsigned long long aesl_llvm_cbe_397_count = 0;
  static  unsigned long long aesl_llvm_cbe_398_count = 0;
   char **llvm_cbe_tmp__159;
  static  unsigned long long aesl_llvm_cbe_399_count = 0;
   char **llvm_cbe_tmp__160;
  static  unsigned long long aesl_llvm_cbe_400_count = 0;
   char *llvm_cbe_tmp__161;
  static  unsigned long long aesl_llvm_cbe_401_count = 0;
  unsigned int llvm_cbe_tmp__162;
  static  unsigned long long aesl_llvm_cbe_402_count = 0;
  unsigned long long llvm_cbe_tmp__163;
  static  unsigned long long aesl_llvm_cbe_403_count = 0;
   char *llvm_cbe_tmp__164;
  static  unsigned long long aesl_llvm_cbe_404_count = 0;
   char *llvm_cbe_tmp__165;
  static  unsigned long long aesl_llvm_cbe_405_count = 0;
   char *llvm_cbe_tmp__166;
  static  unsigned long long aesl_llvm_cbe_406_count = 0;
   char *llvm_cbe_tmp__167;
  static  unsigned long long aesl_llvm_cbe_407_count = 0;
  static  unsigned long long aesl_llvm_cbe_408_count = 0;
  static  unsigned long long aesl_llvm_cbe_409_count = 0;
  static  unsigned long long aesl_llvm_cbe_410_count = 0;
  unsigned long long llvm_cbe_tmp__168;
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

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @expandSeeds\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.tree_t* %%tree, i64 0, i32 5, !dbg !24 for 0x%I64xth hint within @expandSeeds  --> \n", ++aesl_llvm_cbe_339_count);
  llvm_cbe_tmp__127 = (signed long long *)(&llvm_cbe_tree->field5);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i64* %%1, align 8, !dbg !24 for 0x%I64xth hint within @expandSeeds  --> \n", ++aesl_llvm_cbe_340_count);
  llvm_cbe_tmp__128 = (unsigned long long )*llvm_cbe_tmp__127;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__128);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = add i64 %%2, -1, !dbg !24 for 0x%I64xth hint within @expandSeeds  --> \n", ++aesl_llvm_cbe_341_count);
  llvm_cbe_tmp__129 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__128&18446744073709551615ull)) + ((unsigned long long )(18446744073709551615ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__129&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = call i64 @getParent(i64 %%3), !dbg !24 for 0x%I64xth hint within @expandSeeds  --> \n", ++aesl_llvm_cbe_342_count);
  llvm_cbe_tmp__130 = (unsigned long long )getParent(llvm_cbe_tmp__129);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__129);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__130);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds %%struct.tree_t* %%tree, i64 0, i32 3, !dbg !24 for 0x%I64xth hint within @expandSeeds  --> \n", ++aesl_llvm_cbe_358_count);
  llvm_cbe_tmp__131 = ( char **)(&llvm_cbe_tree->field3);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds [64 x i8]* %%tmp, i64 0, i64 0, !dbg !24 for 0x%I64xth hint within @expandSeeds  --> \n", ++aesl_llvm_cbe_359_count);
  llvm_cbe_tmp__132 = ( char *)(&llvm_cbe_tmp[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 64
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds %%struct.tree_t* %%tree, i64 0, i32 1, !dbg !24 for 0x%I64xth hint within @expandSeeds  --> \n", ++aesl_llvm_cbe_360_count);
  llvm_cbe_tmp__133 = ( char ***)(&llvm_cbe_tree->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds %%struct.paramset_t* %%params, i64 0, i32 11, !dbg !25 for 0x%I64xth hint within @expandSeeds  --> \n", ++aesl_llvm_cbe_361_count);
  llvm_cbe_tmp__134 = (signed int *)(&llvm_cbe_params->field11);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__169;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__169:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i64 [ 0, %%0 ], [ %%54, %%53  for 0x%I64xth hint within @expandSeeds  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned long long )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",llvm_cbe_storemerge1);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__168);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = load i8** %%5, align 8, !dbg !24 for 0x%I64xth hint within @expandSeeds  --> \n", ++aesl_llvm_cbe_363_count);
  llvm_cbe_tmp__135 = ( char *)*llvm_cbe_tmp__131;
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds i8* %%10, i64 %%storemerge1, !dbg !24 for 0x%I64xth hint within @expandSeeds  --> \n", ++aesl_llvm_cbe_364_count);
  llvm_cbe_tmp__136 = ( char *)(&llvm_cbe_tmp__135[(((signed long long )llvm_cbe_storemerge1))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",((signed long long )llvm_cbe_storemerge1));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = load i8* %%11, align 1, !dbg !24 for 0x%I64xth hint within @expandSeeds  --> \n", ++aesl_llvm_cbe_365_count);
  llvm_cbe_tmp__137 = (unsigned char )*llvm_cbe_tmp__136;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__137);
  if (((llvm_cbe_tmp__137&255U) == (((unsigned char )0)&255U))) {
    goto llvm_cbe_tmp__170;
  } else {
    goto llvm_cbe_tmp__171;
  }

llvm_cbe_tmp__170:
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = add i64 %%storemerge1, 1, !dbg !27 for 0x%I64xth hint within @expandSeeds  --> \n", ++aesl_llvm_cbe_410_count);
  llvm_cbe_tmp__168 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__168&18446744073709551615ull)));
  if ((((unsigned long long )llvm_cbe_tmp__168&18446744073709551615ULL) > ((unsigned long long )llvm_cbe_tmp__130&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__172;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__168;   /* for PHI node */
    goto llvm_cbe_tmp__169;
  }

llvm_cbe_tmp__173:
  goto llvm_cbe_tmp__170;

llvm_cbe_tmp__174:
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = add i64 %%18, 2, !dbg !25 for 0x%I64xth hint within @expandSeeds  --> \n", ++aesl_llvm_cbe_389_count);
  llvm_cbe_tmp__154 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__141&18446744073709551615ull)) + ((unsigned long long )(2ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__154&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = call i32 @exists(%%struct.tree_t* %%tree, i64 %%34), !dbg !25 for 0x%I64xth hint within @expandSeeds  --> \n", ++aesl_llvm_cbe_390_count);
  llvm_cbe_tmp__155 = (unsigned int )exists((l_struct_OC_tree_t *)llvm_cbe_tree, llvm_cbe_tmp__154);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__154);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__155);
}
  if (((llvm_cbe_tmp__155&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__173;
  } else {
    goto llvm_cbe_tmp__175;
  }

llvm_cbe_tmp__171:
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = load i8*** %%7, align 8, !dbg !24 for 0x%I64xth hint within @expandSeeds  --> \n", ++aesl_llvm_cbe_368_count);
  llvm_cbe_tmp__138 = ( char **)*llvm_cbe_tmp__133;
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds i8** %%15, i64 %%storemerge1, !dbg !24 for 0x%I64xth hint within @expandSeeds  --> \n", ++aesl_llvm_cbe_369_count);
  llvm_cbe_tmp__139 = ( char **)(&llvm_cbe_tmp__138[(((signed long long )llvm_cbe_storemerge1))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",((signed long long )llvm_cbe_storemerge1));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = load i8** %%16, align 8, !dbg !24 for 0x%I64xth hint within @expandSeeds  --> \n", ++aesl_llvm_cbe_370_count);
  llvm_cbe_tmp__140 = ( char *)*llvm_cbe_tmp__139;
if (AESL_DEBUG_TRACE)
printf("\n  call void @hashSeed(i8* %%6, i8* %%17, i8* %%salt, i8 zeroext 1, i64 %%repIndex, i64 %%storemerge1, %%struct.paramset_t* %%params), !dbg !24 for 0x%I64xth hint within @expandSeeds  --> \n", ++aesl_llvm_cbe_371_count);
  hashSeed(( char *)llvm_cbe_tmp__132, ( char *)llvm_cbe_tmp__140, ( char *)llvm_cbe_salt, ((unsigned char )1), llvm_cbe_repIndex, llvm_cbe_storemerge1, (l_struct_OC_paramset_t *)llvm_cbe_params);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",((unsigned char )1));
printf("\nArgument repIndex = 0x%I64X",llvm_cbe_repIndex);
printf("\nArgument storemerge1 = 0x%I64X",llvm_cbe_storemerge1);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = shl i64 %%storemerge1, 1, !dbg !25 for 0x%I64xth hint within @expandSeeds  --> \n", ++aesl_llvm_cbe_372_count);
  llvm_cbe_tmp__141 = (unsigned long long )llvm_cbe_storemerge1 << 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__141);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = or i64 %%18, 1, !dbg !25 for 0x%I64xth hint within @expandSeeds  --> \n", ++aesl_llvm_cbe_373_count);
  llvm_cbe_tmp__142 = (unsigned long long )llvm_cbe_tmp__141 | 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__142);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = load i8** %%5, align 8, !dbg !25 for 0x%I64xth hint within @expandSeeds  --> \n", ++aesl_llvm_cbe_374_count);
  llvm_cbe_tmp__143 = ( char *)*llvm_cbe_tmp__131;
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = getelementptr inbounds i8* %%20, i64 %%19, !dbg !25 for 0x%I64xth hint within @expandSeeds  --> \n", ++aesl_llvm_cbe_375_count);
  llvm_cbe_tmp__144 = ( char *)(&llvm_cbe_tmp__143[(((signed long long )llvm_cbe_tmp__142))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__142));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = load i8* %%21, align 1, !dbg !25 for 0x%I64xth hint within @expandSeeds  --> \n", ++aesl_llvm_cbe_376_count);
  llvm_cbe_tmp__145 = (unsigned char )*llvm_cbe_tmp__144;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__145);
  if (((llvm_cbe_tmp__145&255U) == (((unsigned char )0)&255U))) {
    goto llvm_cbe_tmp__176;
  } else {
    goto llvm_cbe_tmp__174;
  }

llvm_cbe_tmp__176:
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = load i8*** %%7, align 8, !dbg !25 for 0x%I64xth hint within @expandSeeds  --> \n", ++aesl_llvm_cbe_379_count);
  llvm_cbe_tmp__146 = ( char **)*llvm_cbe_tmp__133;
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = getelementptr inbounds i8** %%25, i64 %%19, !dbg !25 for 0x%I64xth hint within @expandSeeds  --> \n", ++aesl_llvm_cbe_380_count);
  llvm_cbe_tmp__147 = ( char **)(&llvm_cbe_tmp__146[(((signed long long )llvm_cbe_tmp__142))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__142));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = load i8** %%26, align 8, !dbg !25 for 0x%I64xth hint within @expandSeeds  --> \n", ++aesl_llvm_cbe_381_count);
  llvm_cbe_tmp__148 = ( char *)*llvm_cbe_tmp__147;
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = load i32* %%8, align 4, !dbg !25 for 0x%I64xth hint within @expandSeeds  --> \n", ++aesl_llvm_cbe_382_count);
  llvm_cbe_tmp__149 = (unsigned int )*llvm_cbe_tmp__134;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__149);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = zext i32 %%28 to i64, !dbg !25 for 0x%I64xth hint within @expandSeeds  --> \n", ++aesl_llvm_cbe_383_count);
  llvm_cbe_tmp__150 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__149&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__150);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = call i8* @memcpy(i8* %%27, i8* %%6, i64 %%29 for 0x%I64xth hint within @expandSeeds  --> \n", ++aesl_llvm_cbe_384_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__148, ( char *)llvm_cbe_tmp__132, llvm_cbe_tmp__150);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__150);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__151);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = load i8** %%5, align 8, !dbg !25 for 0x%I64xth hint within @expandSeeds  --> \n", ++aesl_llvm_cbe_385_count);
  llvm_cbe_tmp__152 = ( char *)*llvm_cbe_tmp__131;
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = getelementptr inbounds i8* %%31, i64 %%19, !dbg !25 for 0x%I64xth hint within @expandSeeds  --> \n", ++aesl_llvm_cbe_386_count);
  llvm_cbe_tmp__153 = ( char *)(&llvm_cbe_tmp__152[(((signed long long )llvm_cbe_tmp__142))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__142));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 1, i8* %%32, align 1, !dbg !25 for 0x%I64xth hint within @expandSeeds  --> \n", ++aesl_llvm_cbe_387_count);
  *llvm_cbe_tmp__153 = ((unsigned char )1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )1));
  goto llvm_cbe_tmp__174;

llvm_cbe_tmp__175:
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = load i8** %%5, align 8, !dbg !25 for 0x%I64xth hint within @expandSeeds  --> \n", ++aesl_llvm_cbe_393_count);
  llvm_cbe_tmp__156 = ( char *)*llvm_cbe_tmp__131;
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = getelementptr inbounds i8* %%38, i64 %%34, !dbg !25 for 0x%I64xth hint within @expandSeeds  --> \n", ++aesl_llvm_cbe_394_count);
  llvm_cbe_tmp__157 = ( char *)(&llvm_cbe_tmp__156[(((signed long long )llvm_cbe_tmp__154))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__154));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = load i8* %%39, align 1, !dbg !25 for 0x%I64xth hint within @expandSeeds  --> \n", ++aesl_llvm_cbe_395_count);
  llvm_cbe_tmp__158 = (unsigned char )*llvm_cbe_tmp__157;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__158);
  if (((llvm_cbe_tmp__158&255U) == (((unsigned char )0)&255U))) {
    goto llvm_cbe_tmp__177;
  } else {
    goto llvm_cbe_tmp__173;
  }

llvm_cbe_tmp__177:
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = load i8*** %%7, align 8, !dbg !25 for 0x%I64xth hint within @expandSeeds  --> \n", ++aesl_llvm_cbe_398_count);
  llvm_cbe_tmp__159 = ( char **)*llvm_cbe_tmp__133;
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = getelementptr inbounds i8** %%43, i64 %%34, !dbg !25 for 0x%I64xth hint within @expandSeeds  --> \n", ++aesl_llvm_cbe_399_count);
  llvm_cbe_tmp__160 = ( char **)(&llvm_cbe_tmp__159[(((signed long long )llvm_cbe_tmp__154))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__154));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = load i8** %%44, align 8, !dbg !25 for 0x%I64xth hint within @expandSeeds  --> \n", ++aesl_llvm_cbe_400_count);
  llvm_cbe_tmp__161 = ( char *)*llvm_cbe_tmp__160;
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = load i32* %%8, align 4, !dbg !25 for 0x%I64xth hint within @expandSeeds  --> \n", ++aesl_llvm_cbe_401_count);
  llvm_cbe_tmp__162 = (unsigned int )*llvm_cbe_tmp__134;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__162);
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = zext i32 %%46 to i64, !dbg !25 for 0x%I64xth hint within @expandSeeds  --> \n", ++aesl_llvm_cbe_402_count);
  llvm_cbe_tmp__163 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__162&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__163);
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = getelementptr inbounds [64 x i8]* %%tmp, i64 0, i64 %%47, !dbg !25 for 0x%I64xth hint within @expandSeeds  --> \n", ++aesl_llvm_cbe_403_count);
  llvm_cbe_tmp__164 = ( char *)(&llvm_cbe_tmp[(((signed long long )llvm_cbe_tmp__163))
#ifdef AESL_BC_SIM
 % 64
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__163));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = call i8* @memcpy(i8* %%45, i8* %%48, i64 %%47 for 0x%I64xth hint within @expandSeeds  --> \n", ++aesl_llvm_cbe_404_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__161, ( char *)llvm_cbe_tmp__164, llvm_cbe_tmp__163);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__163);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__165);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = load i8** %%5, align 8, !dbg !25 for 0x%I64xth hint within @expandSeeds  --> \n", ++aesl_llvm_cbe_405_count);
  llvm_cbe_tmp__166 = ( char *)*llvm_cbe_tmp__131;
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = getelementptr inbounds i8* %%50, i64 %%34, !dbg !25 for 0x%I64xth hint within @expandSeeds  --> \n", ++aesl_llvm_cbe_406_count);
  llvm_cbe_tmp__167 = ( char *)(&llvm_cbe_tmp__166[(((signed long long )llvm_cbe_tmp__154))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__154));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 1, i8* %%51, align 1, !dbg !25 for 0x%I64xth hint within @expandSeeds  --> \n", ++aesl_llvm_cbe_407_count);
  *llvm_cbe_tmp__167 = ((unsigned char )1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )1));
  goto llvm_cbe_tmp__173;

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__172:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @expandSeeds}\n");
  return;
}


l_struct_OC_tree_t *generateSeeds(signed long long llvm_cbe_nSeeds,  char *llvm_cbe_rootSeed,  char *llvm_cbe_salt, signed long long llvm_cbe_repIndex, l_struct_OC_paramset_t *llvm_cbe_params) {
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
  signed int *llvm_cbe_tmp__178;
  static  unsigned long long aesl_llvm_cbe_440_count = 0;
  unsigned int llvm_cbe_tmp__179;
  static  unsigned long long aesl_llvm_cbe_441_count = 0;
  unsigned long long llvm_cbe_tmp__180;
  static  unsigned long long aesl_llvm_cbe_442_count = 0;
  l_struct_OC_tree_t *llvm_cbe_tmp__181;
  static  unsigned long long aesl_llvm_cbe_443_count = 0;
  static  unsigned long long aesl_llvm_cbe_444_count = 0;
  static  unsigned long long aesl_llvm_cbe_445_count = 0;
  static  unsigned long long aesl_llvm_cbe_446_count = 0;
  static  unsigned long long aesl_llvm_cbe_447_count = 0;
  static  unsigned long long aesl_llvm_cbe_448_count = 0;
   char ***llvm_cbe_tmp__182;
  static  unsigned long long aesl_llvm_cbe_449_count = 0;
   char **llvm_cbe_tmp__183;
  static  unsigned long long aesl_llvm_cbe_450_count = 0;
   char *llvm_cbe_tmp__184;
  static  unsigned long long aesl_llvm_cbe_451_count = 0;
  unsigned int llvm_cbe_tmp__185;
  static  unsigned long long aesl_llvm_cbe_452_count = 0;
  unsigned long long llvm_cbe_tmp__186;
  static  unsigned long long aesl_llvm_cbe_453_count = 0;
   char *llvm_cbe_tmp__187;
  static  unsigned long long aesl_llvm_cbe_454_count = 0;
   char **llvm_cbe_tmp__188;
  static  unsigned long long aesl_llvm_cbe_455_count = 0;
   char *llvm_cbe_tmp__189;
  static  unsigned long long aesl_llvm_cbe_456_count = 0;
  static  unsigned long long aesl_llvm_cbe_457_count = 0;
  static  unsigned long long aesl_llvm_cbe_458_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @generateSeeds\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.paramset_t* %%params, i64 0, i32 11, !dbg !25 for 0x%I64xth hint within @generateSeeds  --> \n", ++aesl_llvm_cbe_439_count);
  llvm_cbe_tmp__178 = (signed int *)(&llvm_cbe_params->field11);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i32* %%1, align 4, !dbg !25 for 0x%I64xth hint within @generateSeeds  --> \n", ++aesl_llvm_cbe_440_count);
  llvm_cbe_tmp__179 = (unsigned int )*llvm_cbe_tmp__178;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__179);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = zext i32 %%2 to i64, !dbg !25 for 0x%I64xth hint within @generateSeeds  --> \n", ++aesl_llvm_cbe_441_count);
  llvm_cbe_tmp__180 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__179&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__180);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = tail call %%struct.tree_t* @createTree(i64 %%nSeeds, i64 %%3), !dbg !25 for 0x%I64xth hint within @generateSeeds  --> \n", ++aesl_llvm_cbe_442_count);
  llvm_cbe_tmp__181 = (l_struct_OC_tree_t *) /*tail*/ createTree(llvm_cbe_nSeeds, llvm_cbe_tmp__180);
if (AESL_DEBUG_TRACE) {
printf("\nArgument nSeeds = 0x%I64X",llvm_cbe_nSeeds);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__180);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__181);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds %%struct.tree_t* %%4, i64 0, i32 1, !dbg !24 for 0x%I64xth hint within @generateSeeds  --> \n", ++aesl_llvm_cbe_448_count);
  llvm_cbe_tmp__182 = ( char ***)(&llvm_cbe_tmp__181->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load i8*** %%5, align 8, !dbg !24 for 0x%I64xth hint within @generateSeeds  --> \n", ++aesl_llvm_cbe_449_count);
  llvm_cbe_tmp__183 = ( char **)*llvm_cbe_tmp__182;
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = load i8** %%6, align 8, !dbg !24 for 0x%I64xth hint within @generateSeeds  --> \n", ++aesl_llvm_cbe_450_count);
  llvm_cbe_tmp__184 = ( char *)*llvm_cbe_tmp__183;
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load i32* %%1, align 4, !dbg !24 for 0x%I64xth hint within @generateSeeds  --> \n", ++aesl_llvm_cbe_451_count);
  llvm_cbe_tmp__185 = (unsigned int )*llvm_cbe_tmp__178;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__185);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = zext i32 %%8 to i64, !dbg !24 for 0x%I64xth hint within @generateSeeds  --> \n", ++aesl_llvm_cbe_452_count);
  llvm_cbe_tmp__186 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__185&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__186);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = call i8* @memcpy(i8* %%7, i8* %%rootSeed, i64 %%9 for 0x%I64xth hint within @generateSeeds  --> \n", ++aesl_llvm_cbe_453_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__184, ( char *)llvm_cbe_rootSeed, llvm_cbe_tmp__186);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__186);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__187);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds %%struct.tree_t* %%4, i64 0, i32 3, !dbg !25 for 0x%I64xth hint within @generateSeeds  --> \n", ++aesl_llvm_cbe_454_count);
  llvm_cbe_tmp__188 = ( char **)(&llvm_cbe_tmp__181->field3);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = load i8** %%11, align 8, !dbg !25 for 0x%I64xth hint within @generateSeeds  --> \n", ++aesl_llvm_cbe_455_count);
  llvm_cbe_tmp__189 = ( char *)*llvm_cbe_tmp__188;
if (AESL_DEBUG_TRACE)
printf("\n  store i8 1, i8* %%12, align 1, !dbg !25 for 0x%I64xth hint within @generateSeeds  --> \n", ++aesl_llvm_cbe_456_count);
  *llvm_cbe_tmp__189 = ((unsigned char )1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )1));
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @expandSeeds(%%struct.tree_t* %%4, i8* %%salt, i64 %%repIndex, %%struct.paramset_t* %%params), !dbg !25 for 0x%I64xth hint within @generateSeeds  --> \n", ++aesl_llvm_cbe_457_count);
   /*tail*/ expandSeeds((l_struct_OC_tree_t *)llvm_cbe_tmp__181, ( char *)llvm_cbe_salt, llvm_cbe_repIndex, (l_struct_OC_paramset_t *)llvm_cbe_params);
if (AESL_DEBUG_TRACE) {
printf("\nArgument repIndex = 0x%I64X",llvm_cbe_repIndex);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @generateSeeds}\n");
  return llvm_cbe_tmp__181;
}


signed int isLeafNode(l_struct_OC_tree_t *llvm_cbe_tree, signed long long llvm_cbe_node) {
  static  unsigned long long aesl_llvm_cbe_459_count = 0;
  static  unsigned long long aesl_llvm_cbe_460_count = 0;
  static  unsigned long long aesl_llvm_cbe_461_count = 0;
  static  unsigned long long aesl_llvm_cbe_462_count = 0;
  unsigned long long llvm_cbe_tmp__190;
  static  unsigned long long aesl_llvm_cbe_463_count = 0;
  unsigned long long llvm_cbe_tmp__191;
  static  unsigned long long aesl_llvm_cbe_464_count = 0;
  static  unsigned long long aesl_llvm_cbe_465_count = 0;
  signed long long *llvm_cbe_tmp__192;
  static  unsigned long long aesl_llvm_cbe_466_count = 0;
  unsigned long long llvm_cbe_tmp__193;
  static  unsigned long long aesl_llvm_cbe_467_count = 0;
  static  unsigned long long aesl_llvm_cbe_468_count = 0;
  unsigned int llvm_cbe_tmp__194;
  static  unsigned long long aesl_llvm_cbe_469_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @isLeafNode\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = shl i64 %%node, 1, !dbg !24 for 0x%I64xth hint within @isLeafNode  --> \n", ++aesl_llvm_cbe_462_count);
  llvm_cbe_tmp__190 = (unsigned long long )llvm_cbe_node << 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__190);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = or i64 %%1, 1, !dbg !24 for 0x%I64xth hint within @isLeafNode  --> \n", ++aesl_llvm_cbe_463_count);
  llvm_cbe_tmp__191 = (unsigned long long )llvm_cbe_tmp__190 | 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__191);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.tree_t* %%tree, i64 0, i32 5, !dbg !24 for 0x%I64xth hint within @isLeafNode  --> \n", ++aesl_llvm_cbe_465_count);
  llvm_cbe_tmp__192 = (signed long long *)(&llvm_cbe_tree->field5);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i64* %%3, align 8, !dbg !24 for 0x%I64xth hint within @isLeafNode  --> \n", ++aesl_llvm_cbe_466_count);
  llvm_cbe_tmp__193 = (unsigned long long )*llvm_cbe_tmp__192;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__193);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = zext i1 %%5 to i32, !dbg !24 for 0x%I64xth hint within @isLeafNode  --> \n", ++aesl_llvm_cbe_468_count);
  llvm_cbe_tmp__194 = (unsigned int )((unsigned int )(bool )(((unsigned long long )llvm_cbe_tmp__191&18446744073709551615ULL) >= ((unsigned long long )llvm_cbe_tmp__193&18446744073709551615ULL))&1U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__194);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @isLeafNode}\n");
  return llvm_cbe_tmp__194;
}


signed int hasSibling(l_struct_OC_tree_t *llvm_cbe_tree, signed long long llvm_cbe_node) {
  static  unsigned long long aesl_llvm_cbe_470_count = 0;
  static  unsigned long long aesl_llvm_cbe_471_count = 0;
  static  unsigned long long aesl_llvm_cbe_472_count = 0;
  static  unsigned long long aesl_llvm_cbe_473_count = 0;
  static  unsigned long long aesl_llvm_cbe_474_count = 0;
  static  unsigned long long aesl_llvm_cbe_475_count = 0;
  static  unsigned long long aesl_llvm_cbe_476_count = 0;
  static  unsigned long long aesl_llvm_cbe_477_count = 0;
  unsigned int llvm_cbe_tmp__195;
  static  unsigned long long aesl_llvm_cbe_478_count = 0;
  static  unsigned long long aesl_llvm_cbe_479_count = 0;
  static  unsigned long long aesl_llvm_cbe_480_count = 0;
  unsigned int llvm_cbe_tmp__196;
  static  unsigned long long aesl_llvm_cbe_481_count = 0;
  static  unsigned long long aesl_llvm_cbe_482_count = 0;
  static  unsigned long long aesl_llvm_cbe_483_count = 0;
  unsigned long long llvm_cbe_tmp__197;
  static  unsigned long long aesl_llvm_cbe_484_count = 0;
  unsigned int llvm_cbe_tmp__198;
  static  unsigned long long aesl_llvm_cbe_485_count = 0;
  static  unsigned long long aesl_llvm_cbe_486_count = 0;
  static  unsigned long long aesl_llvm_cbe_487_count = 0;
  static  unsigned long long aesl_llvm_cbe_488_count = 0;
  unsigned int llvm_cbe_tmp__199;
  unsigned int llvm_cbe_tmp__199__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_489_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @hasSibling\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = tail call i32 @exists(%%struct.tree_t* %%tree, i64 %%node), !dbg !24 for 0x%I64xth hint within @hasSibling  --> \n", ++aesl_llvm_cbe_477_count);
  llvm_cbe_tmp__195 = (unsigned int ) /*tail*/ exists((l_struct_OC_tree_t *)llvm_cbe_tree, llvm_cbe_node);
if (AESL_DEBUG_TRACE) {
printf("\nArgument node = 0x%I64X",llvm_cbe_node);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__195);
}
  if (((llvm_cbe_tmp__195&4294967295U) == (0u&4294967295U))) {
    llvm_cbe_tmp__199__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe_tmp__200;
  } else {
    goto llvm_cbe_tmp__201;
  }

llvm_cbe_tmp__201:
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = tail call i32 @isLeftChild(i64 %%node), !dbg !24 for 0x%I64xth hint within @hasSibling  --> \n", ++aesl_llvm_cbe_480_count);
  llvm_cbe_tmp__196 = (unsigned int ) /*tail*/ isLeftChild(llvm_cbe_node);
if (AESL_DEBUG_TRACE) {
printf("\nArgument node = 0x%I64X",llvm_cbe_node);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__196);
}
  if (((llvm_cbe_tmp__196&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__202;
  } else {
    goto llvm_cbe_tmp__203;
  }

llvm_cbe_tmp__203:
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = add i64 %%node, 1, !dbg !24 for 0x%I64xth hint within @hasSibling  --> \n", ++aesl_llvm_cbe_483_count);
  llvm_cbe_tmp__197 = (unsigned long long )((unsigned long long )(llvm_cbe_node&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__197&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = tail call i32 @exists(%%struct.tree_t* %%tree, i64 %%7), !dbg !24 for 0x%I64xth hint within @hasSibling  --> \n", ++aesl_llvm_cbe_484_count);
  llvm_cbe_tmp__198 = (unsigned int ) /*tail*/ exists((l_struct_OC_tree_t *)llvm_cbe_tree, llvm_cbe_tmp__197);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__197);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__198);
}
  if (((llvm_cbe_tmp__198&4294967295U) == (0u&4294967295U))) {
    llvm_cbe_tmp__199__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe_tmp__200;
  } else {
    goto llvm_cbe_tmp__202;
  }

llvm_cbe_tmp__202:
  llvm_cbe_tmp__199__PHI_TEMPORARY = (unsigned int )1u;   /* for PHI node */
  goto llvm_cbe_tmp__200;

llvm_cbe_tmp__200:
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = phi i32 [ 1, %%10 ], [ 0, %%0 ], [ 0, %%6  for 0x%I64xth hint within @hasSibling  --> \n", ++aesl_llvm_cbe_488_count);
  llvm_cbe_tmp__199 = (unsigned int )llvm_cbe_tmp__199__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__199);
printf("\n = 0x%X",1u);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",0u);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @hasSibling}\n");
  return llvm_cbe_tmp__199;
}


signed long long getSibling(l_struct_OC_tree_t *llvm_cbe_tree, signed long long llvm_cbe_node) {
  static  unsigned long long aesl_llvm_cbe_490_count = 0;
  static  unsigned long long aesl_llvm_cbe_491_count = 0;
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
  signed long long *llvm_cbe_tmp__204;
  static  unsigned long long aesl_llvm_cbe_503_count = 0;
  unsigned long long llvm_cbe_tmp__205;
  static  unsigned long long aesl_llvm_cbe_504_count = 0;
  static  unsigned long long aesl_llvm_cbe_505_count = 0;
  static  unsigned long long aesl_llvm_cbe_506_count = 0;
  static  unsigned long long aesl_llvm_cbe_507_count = 0;
  static  unsigned long long aesl_llvm_cbe_508_count = 0;
  static  unsigned long long aesl_llvm_cbe_509_count = 0;
  static  unsigned long long aesl_llvm_cbe_510_count = 0;
  static  unsigned long long aesl_llvm_cbe_511_count = 0;
  static  unsigned long long aesl_llvm_cbe_512_count = 0;
  unsigned int llvm_cbe_tmp__206;
  static  unsigned long long aesl_llvm_cbe_513_count = 0;
  static  unsigned long long aesl_llvm_cbe_514_count = 0;
  static  unsigned long long aesl_llvm_cbe_515_count = 0;
  static  unsigned long long aesl_llvm_cbe_516_count = 0;
  static  unsigned long long aesl_llvm_cbe_517_count = 0;
  unsigned int llvm_cbe_tmp__207;
  static  unsigned long long aesl_llvm_cbe_518_count = 0;
  static  unsigned long long aesl_llvm_cbe_519_count = 0;
  static  unsigned long long aesl_llvm_cbe_520_count = 0;
  unsigned long long llvm_cbe_tmp__208;
  static  unsigned long long aesl_llvm_cbe_521_count = 0;
  unsigned long long llvm_cbe_tmp__209;
  static  unsigned long long aesl_llvm_cbe_522_count = 0;
  static  unsigned long long aesl_llvm_cbe_523_count = 0;
  static  unsigned long long aesl_llvm_cbe_524_count = 0;
  static  unsigned long long aesl_llvm_cbe_525_count = 0;
  static  unsigned long long aesl_llvm_cbe_526_count = 0;
  unsigned long long llvm_cbe_tmp__210;
  static  unsigned long long aesl_llvm_cbe_527_count = 0;
  static  unsigned long long aesl_llvm_cbe_528_count = 0;
  unsigned long long llvm_cbe_tmp__211;
  unsigned long long llvm_cbe_tmp__211__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_529_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @getSibling\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.tree_t* %%tree, i64 0, i32 5, !dbg !24 for 0x%I64xth hint within @getSibling  --> \n", ++aesl_llvm_cbe_502_count);
  llvm_cbe_tmp__204 = (signed long long *)(&llvm_cbe_tree->field5);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i64* %%1, align 8, !dbg !24 for 0x%I64xth hint within @getSibling  --> \n", ++aesl_llvm_cbe_503_count);
  llvm_cbe_tmp__205 = (unsigned long long )*llvm_cbe_tmp__204;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__205);
  if ((((unsigned long long )llvm_cbe_tmp__205&18446744073709551615ULL) > ((unsigned long long )llvm_cbe_node&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__212;
  } else {
    goto llvm_cbe_tmp__213;
  }

llvm_cbe_tmp__213:
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @_assert(i8* getelementptr inbounds ([22 x i8]* @aesl_internal_.str3, i64 0, i64 0), i8* getelementptr inbounds ([60 x i8]* @aesl_internal_.str1, i64 0, i64 0), i32 200) nounwind, !dbg !25 for 0x%I64xth hint within @getSibling  --> \n", ++aesl_llvm_cbe_506_count);
   /*tail*/ _assert(( char *)((&aesl_internal__OC_str3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 22
#endif
])), ( char *)((&aesl_internal__OC_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 60
#endif
])), 200u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",200u);
}
  goto llvm_cbe_tmp__212;

llvm_cbe_tmp__212:
  if (((llvm_cbe_node&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__214;
  } else {
    goto llvm_cbe_tmp__215;
  }

llvm_cbe_tmp__214:
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @_assert(i8* getelementptr inbounds ([10 x i8]* @aesl_internal_.str, i64 0, i64 0), i8* getelementptr inbounds ([60 x i8]* @aesl_internal_.str1, i64 0, i64 0), i32 201) nounwind, !dbg !25 for 0x%I64xth hint within @getSibling  --> \n", ++aesl_llvm_cbe_510_count);
   /*tail*/ _assert(( char *)((&aesl_internal__OC_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 10
#endif
])), ( char *)((&aesl_internal__OC_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 60
#endif
])), 201u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",201u);
}
  goto llvm_cbe_tmp__215;

llvm_cbe_tmp__215:
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = tail call i32 @hasSibling(%%struct.tree_t* %%tree, i64 %%node), !dbg !24 for 0x%I64xth hint within @getSibling  --> \n", ++aesl_llvm_cbe_512_count);
  llvm_cbe_tmp__206 = (unsigned int ) /*tail*/ hasSibling((l_struct_OC_tree_t *)llvm_cbe_tree, llvm_cbe_node);
if (AESL_DEBUG_TRACE) {
printf("\nArgument node = 0x%I64X",llvm_cbe_node);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__206);
}
  if (((llvm_cbe_tmp__206&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__216;
  } else {
    goto llvm_cbe_tmp__217;
  }

llvm_cbe_tmp__216:
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @_assert(i8* getelementptr inbounds ([23 x i8]* @aesl_internal_.str4, i64 0, i64 0), i8* getelementptr inbounds ([60 x i8]* @aesl_internal_.str1, i64 0, i64 0), i32 202) nounwind, !dbg !25 for 0x%I64xth hint within @getSibling  --> \n", ++aesl_llvm_cbe_515_count);
   /*tail*/ _assert(( char *)((&aesl_internal__OC_str4[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 23
#endif
])), ( char *)((&aesl_internal__OC_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 60
#endif
])), 202u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",202u);
}
  goto llvm_cbe_tmp__217;

llvm_cbe_tmp__217:
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = tail call i32 @isLeftChild(i64 %%node), !dbg !25 for 0x%I64xth hint within @getSibling  --> \n", ++aesl_llvm_cbe_517_count);
  llvm_cbe_tmp__207 = (unsigned int ) /*tail*/ isLeftChild(llvm_cbe_node);
if (AESL_DEBUG_TRACE) {
printf("\nArgument node = 0x%I64X",llvm_cbe_node);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__207);
}
  if (((llvm_cbe_tmp__207&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__218;
  } else {
    goto llvm_cbe_tmp__219;
  }

llvm_cbe_tmp__219:
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = add i64 %%node, 1, !dbg !24 for 0x%I64xth hint within @getSibling  --> \n", ++aesl_llvm_cbe_520_count);
  llvm_cbe_tmp__208 = (unsigned long long )((unsigned long long )(llvm_cbe_node&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__208&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = load i64* %%1, align 8, !dbg !24 for 0x%I64xth hint within @getSibling  --> \n", ++aesl_llvm_cbe_521_count);
  llvm_cbe_tmp__209 = (unsigned long long )*llvm_cbe_tmp__204;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__209);
  if ((((unsigned long long )llvm_cbe_tmp__208&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__209&18446744073709551615ULL))) {
    llvm_cbe_tmp__211__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__208;   /* for PHI node */
    goto llvm_cbe_tmp__220;
  } else {
    goto llvm_cbe_tmp__221;
  }

llvm_cbe_tmp__221:
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @_assert(i8* getelementptr inbounds ([49 x i8]* @aesl_internal_.str5, i64 0, i64 0), i8* getelementptr inbounds ([60 x i8]* @aesl_internal_.str1, i64 0, i64 0), i32 209) nounwind, !dbg !26 for 0x%I64xth hint within @getSibling  --> \n", ++aesl_llvm_cbe_524_count);
   /*tail*/ _assert(( char *)((&aesl_internal__OC_str5[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 49
#endif
])), ( char *)((&aesl_internal__OC_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 60
#endif
])), 209u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",209u);
}
  llvm_cbe_tmp__211__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__220;

llvm_cbe_tmp__218:
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = add i64 %%node, -1, !dbg !25 for 0x%I64xth hint within @getSibling  --> \n", ++aesl_llvm_cbe_526_count);
  llvm_cbe_tmp__210 = (unsigned long long )((unsigned long long )(llvm_cbe_node&18446744073709551615ull)) + ((unsigned long long )(18446744073709551615ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__210&18446744073709551615ull)));
  llvm_cbe_tmp__211__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__210;   /* for PHI node */
  goto llvm_cbe_tmp__220;

llvm_cbe_tmp__220:
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = phi i64 [ %%21, %%20 ], [ 0, %%19 ], [ %%16, %%15  for 0x%I64xth hint within @getSibling  --> \n", ++aesl_llvm_cbe_528_count);
  llvm_cbe_tmp__211 = (unsigned long long )llvm_cbe_tmp__211__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__211);
printf("\n = 0x%I64X",llvm_cbe_tmp__210);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__208);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @getSibling}\n");
  return llvm_cbe_tmp__211;
}


void printSeeds( char *llvm_cbe_seedsBuf, signed long long llvm_cbe_seedLen, signed long long llvm_cbe_numSeeds) {
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
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned long long llvm_cbe_storemerge1;
  unsigned long long llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_rec_count = 0;
  unsigned long long llvm_cbe__2e_rec;
  unsigned long long llvm_cbe__2e_rec__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_544_count = 0;
   char *llvm_cbe_tmp__222;
  static  unsigned long long aesl_llvm_cbe_545_count = 0;
  unsigned int llvm_cbe_tmp__223;
  static  unsigned long long aesl_llvm_cbe_546_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_rec2_count = 0;
  unsigned long long llvm_cbe__2e_rec2;
  static  unsigned long long aesl_llvm_cbe_547_count = 0;
  unsigned long long llvm_cbe_tmp__224;
  static  unsigned long long aesl_llvm_cbe_548_count = 0;
  static  unsigned long long aesl_llvm_cbe_549_count = 0;
  static  unsigned long long aesl_llvm_cbe_550_count = 0;
  static  unsigned long long aesl_llvm_cbe_551_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_552_count = 0;
  static  unsigned long long aesl_llvm_cbe_553_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @printSeeds\n");
  if (((llvm_cbe_numSeeds&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    llvm_cbe__2e_rec__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i64 [ %%4, %%.lr.ph ], [ 0, %%0  for 0x%I64xth hint within @printSeeds  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned long long )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",llvm_cbe_storemerge1);
printf("\n = 0x%I64X",llvm_cbe_tmp__224);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec = phi i64 [ %%.rec2, %%.lr.ph ], [ 0, %%0  for 0x%I64xth hint within @printSeeds  --> \n", ++aesl_llvm_cbe__2e_rec_count);
  llvm_cbe__2e_rec = (unsigned long long )llvm_cbe__2e_rec__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.rec = 0x%I64X",llvm_cbe__2e_rec);
printf("\n.rec2 = 0x%I64X",llvm_cbe__2e_rec2);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr i8* %%seedsBuf, i64 %%.re for 0x%I64xth hint within @printSeeds  --> \n", ++aesl_llvm_cbe_544_count);
  llvm_cbe_tmp__222 = ( char *)(&llvm_cbe_seedsBuf[(((signed long long )llvm_cbe__2e_rec))]);
if (AESL_DEBUG_TRACE) {
printf("\n.rec = 0x%I64X",((signed long long )llvm_cbe__2e_rec));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([9 x i8]* @aesl_internal_.str6, i64 0, i64 0), i64 %%storemerge1) nounwind, !dbg !25 for 0x%I64xth hint within @printSeeds  --> \n", ++aesl_llvm_cbe_545_count);
   /*tail*/ printf(( char *)((&aesl_internal__OC_str6[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 9
#endif
])), llvm_cbe_storemerge1);
if (AESL_DEBUG_TRACE) {
printf("\nArgument storemerge1 = 0x%I64X",llvm_cbe_storemerge1);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__223);
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @printHex(i8* getelementptr inbounds ([1 x i8]* @aesl_internal_.str7, i64 0, i64 0), i8* %%2, i64 %%seedLen) nounwind, !dbg !24 for 0x%I64xth hint within @printSeeds  --> \n", ++aesl_llvm_cbe_546_count);
   /*tail*/ printHex(( char *)((&aesl_internal__OC_str7[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
])), ( char *)llvm_cbe_tmp__222, llvm_cbe_seedLen);
if (AESL_DEBUG_TRACE) {
printf("\nArgument seedLen = 0x%I64X",llvm_cbe_seedLen);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec2 = add i64 %%.rec, %%seedLen, !dbg !24 for 0x%I64xth hint within @printSeeds  --> \n", ++aesl_llvm_cbe__2e_rec2_count);
  llvm_cbe__2e_rec2 = (unsigned long long )((unsigned long long )(llvm_cbe__2e_rec&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_seedLen&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.rec2 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_rec2&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = add i64 %%storemerge1, 1, !dbg !25 for 0x%I64xth hint within @printSeeds  --> \n", ++aesl_llvm_cbe_547_count);
  llvm_cbe_tmp__224 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__224&18446744073709551615ull)));
  if (((llvm_cbe_tmp__224&18446744073709551615ULL) == (llvm_cbe_numSeeds&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__224;   /* for PHI node */
    llvm_cbe__2e_rec__PHI_TEMPORARY = (unsigned long long )llvm_cbe__2e_rec2;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @printSeeds}\n");
  return;
}


void printLeaves(l_struct_OC_tree_t *llvm_cbe_tree) {
  static  unsigned long long aesl_llvm_cbe_554_count = 0;
  static  unsigned long long aesl_llvm_cbe_555_count = 0;
  static  unsigned long long aesl_llvm_cbe_556_count = 0;
  static  unsigned long long aesl_llvm_cbe_557_count = 0;
  static  unsigned long long aesl_llvm_cbe_558_count = 0;
  static  unsigned long long aesl_llvm_cbe_559_count = 0;
  static  unsigned long long aesl_llvm_cbe_560_count = 0;
  signed long long *llvm_cbe_tmp__225;
  static  unsigned long long aesl_llvm_cbe_561_count = 0;
  unsigned long long llvm_cbe_tmp__226;
  static  unsigned long long aesl_llvm_cbe_562_count = 0;
  signed long long *llvm_cbe_tmp__227;
  static  unsigned long long aesl_llvm_cbe_563_count = 0;
  unsigned long long llvm_cbe_tmp__228;
  static  unsigned long long aesl_llvm_cbe_564_count = 0;
  unsigned long long llvm_cbe_tmp__229;
  static  unsigned long long aesl_llvm_cbe_565_count = 0;
  static  unsigned long long aesl_llvm_cbe_566_count = 0;
  static  unsigned long long aesl_llvm_cbe_567_count = 0;
   char ***llvm_cbe_tmp__230;
  static  unsigned long long aesl_llvm_cbe_568_count = 0;
   char **llvm_cbe_tmp__231;
  static  unsigned long long aesl_llvm_cbe_569_count = 0;
   char **llvm_cbe_tmp__232;
  static  unsigned long long aesl_llvm_cbe_570_count = 0;
   char *llvm_cbe_tmp__233;
  static  unsigned long long aesl_llvm_cbe_571_count = 0;
  signed long long *llvm_cbe_tmp__234;
  static  unsigned long long aesl_llvm_cbe_572_count = 0;
  unsigned long long llvm_cbe_tmp__235;
  static  unsigned long long aesl_llvm_cbe_573_count = 0;
  static  unsigned long long aesl_llvm_cbe_574_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @printLeaves\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.tree_t* %%tree, i64 0, i32 5, !dbg !24 for 0x%I64xth hint within @printLeaves  --> \n", ++aesl_llvm_cbe_560_count);
  llvm_cbe_tmp__225 = (signed long long *)(&llvm_cbe_tree->field5);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i64* %%1, align 8, !dbg !24 for 0x%I64xth hint within @printLeaves  --> \n", ++aesl_llvm_cbe_561_count);
  llvm_cbe_tmp__226 = (unsigned long long )*llvm_cbe_tmp__225;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__226);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.tree_t* %%tree, i64 0, i32 6, !dbg !24 for 0x%I64xth hint within @printLeaves  --> \n", ++aesl_llvm_cbe_562_count);
  llvm_cbe_tmp__227 = (signed long long *)(&llvm_cbe_tree->field6);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i64* %%3, align 8, !dbg !24 for 0x%I64xth hint within @printLeaves  --> \n", ++aesl_llvm_cbe_563_count);
  llvm_cbe_tmp__228 = (unsigned long long )*llvm_cbe_tmp__227;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__228);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = sub i64 %%2, %%4, !dbg !24 for 0x%I64xth hint within @printLeaves  --> \n", ++aesl_llvm_cbe_564_count);
  llvm_cbe_tmp__229 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__226&18446744073709551615ull)) - ((unsigned long long )(llvm_cbe_tmp__228&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__229&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds %%struct.tree_t* %%tree, i64 0, i32 1, !dbg !24 for 0x%I64xth hint within @printLeaves  --> \n", ++aesl_llvm_cbe_567_count);
  llvm_cbe_tmp__230 = ( char ***)(&llvm_cbe_tree->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = load i8*** %%6, align 8, !dbg !24 for 0x%I64xth hint within @printLeaves  --> \n", ++aesl_llvm_cbe_568_count);
  llvm_cbe_tmp__231 = ( char **)*llvm_cbe_tmp__230;
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds i8** %%7, i64 %%5, !dbg !24 for 0x%I64xth hint within @printLeaves  --> \n", ++aesl_llvm_cbe_569_count);
  llvm_cbe_tmp__232 = ( char **)(&llvm_cbe_tmp__231[(((signed long long )llvm_cbe_tmp__229))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__229));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = load i8** %%8, align 8, !dbg !24 for 0x%I64xth hint within @printLeaves  --> \n", ++aesl_llvm_cbe_570_count);
  llvm_cbe_tmp__233 = ( char *)*llvm_cbe_tmp__232;
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds %%struct.tree_t* %%tree, i64 0, i32 2, !dbg !24 for 0x%I64xth hint within @printLeaves  --> \n", ++aesl_llvm_cbe_571_count);
  llvm_cbe_tmp__234 = (signed long long *)(&llvm_cbe_tree->field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = load i64* %%10, align 8, !dbg !24 for 0x%I64xth hint within @printLeaves  --> \n", ++aesl_llvm_cbe_572_count);
  llvm_cbe_tmp__235 = (unsigned long long )*llvm_cbe_tmp__234;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__235);
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @printSeeds(i8* %%9, i64 %%11, i64 %%4), !dbg !24 for 0x%I64xth hint within @printLeaves  --> \n", ++aesl_llvm_cbe_573_count);
   /*tail*/ printSeeds(( char *)llvm_cbe_tmp__233, llvm_cbe_tmp__235, llvm_cbe_tmp__228);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__235);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__228);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @printLeaves}\n");
  return;
}


signed long long revealSeedsSize(signed long long llvm_cbe_numNodes, signed short *llvm_cbe_hideList, signed long long llvm_cbe_hideListSize, l_struct_OC_paramset_t *llvm_cbe_params) {
  static  unsigned long long aesl_llvm_cbe_numNodesRevealed_count = 0;
  signed long long llvm_cbe_numNodesRevealed;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_575_count = 0;
  static  unsigned long long aesl_llvm_cbe_576_count = 0;
  static  unsigned long long aesl_llvm_cbe_577_count = 0;
  static  unsigned long long aesl_llvm_cbe_578_count = 0;
  static  unsigned long long aesl_llvm_cbe_579_count = 0;
  static  unsigned long long aesl_llvm_cbe_580_count = 0;
  static  unsigned long long aesl_llvm_cbe_581_count = 0;
  static  unsigned long long aesl_llvm_cbe_582_count = 0;
  static  unsigned long long aesl_llvm_cbe_583_count = 0;
  static  unsigned long long aesl_llvm_cbe_584_count = 0;
  signed int *llvm_cbe_tmp__236;
  static  unsigned long long aesl_llvm_cbe_585_count = 0;
  unsigned int llvm_cbe_tmp__237;
  static  unsigned long long aesl_llvm_cbe_586_count = 0;
  unsigned long long llvm_cbe_tmp__238;
  static  unsigned long long aesl_llvm_cbe_587_count = 0;
  l_struct_OC_tree_t *llvm_cbe_tmp__239;
  static  unsigned long long aesl_llvm_cbe_588_count = 0;
  static  unsigned long long aesl_llvm_cbe_589_count = 0;
  static  unsigned long long aesl_llvm_cbe_590_count = 0;
  static  unsigned long long aesl_llvm_cbe_591_count = 0;
  static  unsigned long long aesl_llvm_cbe_592_count = 0;
  static  unsigned long long aesl_llvm_cbe_593_count = 0;
  static  unsigned long long aesl_llvm_cbe_594_count = 0;
  static  unsigned long long aesl_llvm_cbe_595_count = 0;
  static  unsigned long long aesl_llvm_cbe_596_count = 0;
  static  unsigned long long aesl_llvm_cbe_597_count = 0;
  static  unsigned long long aesl_llvm_cbe_598_count = 0;
  static  unsigned long long aesl_llvm_cbe_599_count = 0;
  signed long long *llvm_cbe_tmp__240;
  static  unsigned long long aesl_llvm_cbe_600_count = 0;
  static  unsigned long long aesl_llvm_cbe_601_count = 0;
  static  unsigned long long aesl_llvm_cbe_602_count = 0;
  static  unsigned long long aesl_llvm_cbe_603_count = 0;
   char *llvm_cbe_tmp__241;
  static  unsigned long long aesl_llvm_cbe_604_count = 0;
  static  unsigned long long aesl_llvm_cbe_605_count = 0;
  static  unsigned long long aesl_llvm_cbe_606_count = 0;
  static  unsigned long long aesl_llvm_cbe_607_count = 0;
  static  unsigned long long aesl_llvm_cbe_608_count = 0;
  static  unsigned long long aesl_llvm_cbe_609_count = 0;
  static  unsigned long long aesl_llvm_cbe_610_count = 0;
  static  unsigned long long aesl_llvm_cbe_611_count = 0;
  unsigned long long llvm_cbe_tmp__242;
  static  unsigned long long aesl_llvm_cbe_612_count = 0;
  unsigned int llvm_cbe_tmp__243;
  static  unsigned long long aesl_llvm_cbe_613_count = 0;
  unsigned long long llvm_cbe_tmp__244;
  static  unsigned long long aesl_llvm_cbe_614_count = 0;
  unsigned long long llvm_cbe_tmp__245;
  static  unsigned long long aesl_llvm_cbe_615_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @revealSeedsSize\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.paramset_t* %%params, i64 0, i32 11, !dbg !25 for 0x%I64xth hint within @revealSeedsSize  --> \n", ++aesl_llvm_cbe_584_count);
  llvm_cbe_tmp__236 = (signed int *)(&llvm_cbe_params->field11);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i32* %%1, align 4, !dbg !25 for 0x%I64xth hint within @revealSeedsSize  --> \n", ++aesl_llvm_cbe_585_count);
  llvm_cbe_tmp__237 = (unsigned int )*llvm_cbe_tmp__236;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__237);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = zext i32 %%2 to i64, !dbg !25 for 0x%I64xth hint within @revealSeedsSize  --> \n", ++aesl_llvm_cbe_586_count);
  llvm_cbe_tmp__238 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__237&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__238);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = call %%struct.tree_t* @createTree(i64 %%numNodes, i64 %%3), !dbg !25 for 0x%I64xth hint within @revealSeedsSize  --> \n", ++aesl_llvm_cbe_587_count);
  llvm_cbe_tmp__239 = (l_struct_OC_tree_t *)createTree(llvm_cbe_numNodes, llvm_cbe_tmp__238);
if (AESL_DEBUG_TRACE) {
printf("\nArgument numNodes = 0x%I64X",llvm_cbe_numNodes);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__238);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__239);
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 0, i64* %%numNodesRevealed, align 8, !dbg !26 for 0x%I64xth hint within @revealSeedsSize  --> \n", ++aesl_llvm_cbe_598_count);
  *(&llvm_cbe_numNodesRevealed) = 0ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 0ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = call fastcc i64* @aesl_internal_getRevealedNodes(%%struct.tree_t* %%4, i16* %%hideList, i64 %%hideListSize, i64* %%numNodesRevealed), !dbg !24 for 0x%I64xth hint within @revealSeedsSize  --> \n", ++aesl_llvm_cbe_599_count);
  llvm_cbe_tmp__240 = (signed long long *)aesl_internal_getRevealedNodes((l_struct_OC_tree_t *)llvm_cbe_tmp__239, (signed short *)llvm_cbe_hideList, llvm_cbe_hideListSize, (signed long long *)(&llvm_cbe_numNodesRevealed));
if (AESL_DEBUG_TRACE) {
printf("\nArgument hideListSize = 0x%I64X",llvm_cbe_hideListSize);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__240);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @freeTree(%%struct.tree_t* %%4), !dbg !25 for 0x%I64xth hint within @revealSeedsSize  --> \n", ++aesl_llvm_cbe_602_count);
  freeTree((l_struct_OC_tree_t *)llvm_cbe_tmp__239);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = bitcast i64* %%5 to i8*, !dbg !26 for 0x%I64xth hint within @revealSeedsSize  --> \n", ++aesl_llvm_cbe_603_count);
  llvm_cbe_tmp__241 = ( char *)(( char *)llvm_cbe_tmp__240);
if (AESL_DEBUG_TRACE)
printf("\n  call void @free(i8* %%6), !dbg !26 for 0x%I64xth hint within @revealSeedsSize  --> \n", ++aesl_llvm_cbe_604_count);
  free(( char *)llvm_cbe_tmp__241);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = load i64* %%numNodesRevealed, align 8, !dbg !25 for 0x%I64xth hint within @revealSeedsSize  --> \n", ++aesl_llvm_cbe_611_count);
  llvm_cbe_tmp__242 = (unsigned long long )*(&llvm_cbe_numNodesRevealed);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__242);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load i32* %%1, align 4, !dbg !25 for 0x%I64xth hint within @revealSeedsSize  --> \n", ++aesl_llvm_cbe_612_count);
  llvm_cbe_tmp__243 = (unsigned int )*llvm_cbe_tmp__236;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__243);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = zext i32 %%8 to i64, !dbg !25 for 0x%I64xth hint within @revealSeedsSize  --> \n", ++aesl_llvm_cbe_613_count);
  llvm_cbe_tmp__244 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__243&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__244);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = mul i64 %%9, %%7, !dbg !25 for 0x%I64xth hint within @revealSeedsSize  --> \n", ++aesl_llvm_cbe_614_count);
  llvm_cbe_tmp__245 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__244&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__242&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__245&18446744073709551615ull)));
  if (AESL_DEBUG_TRACE)
      printf("\nEND @revealSeedsSize}\n");
  return llvm_cbe_tmp__245;
}


static signed long long *aesl_internal_getRevealedNodes(l_struct_OC_tree_t *llvm_cbe_tree, signed short *llvm_cbe_hideList, signed long long llvm_cbe_hideListSize, signed long long *llvm_cbe_outputSize) {
  static  unsigned long long aesl_llvm_cbe_616_count = 0;
  static  unsigned long long aesl_llvm_cbe_617_count = 0;
  static  unsigned long long aesl_llvm_cbe_618_count = 0;
  static  unsigned long long aesl_llvm_cbe_619_count = 0;
  static  unsigned long long aesl_llvm_cbe_620_count = 0;
  static  unsigned long long aesl_llvm_cbe_621_count = 0;
  static  unsigned long long aesl_llvm_cbe_622_count = 0;
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
  signed long long *llvm_cbe_tmp__246;
  static  unsigned long long aesl_llvm_cbe_636_count = 0;
  unsigned long long llvm_cbe_tmp__247;
  static  unsigned long long aesl_llvm_cbe_637_count = 0;
  unsigned long long llvm_cbe_tmp__248;
  static  unsigned long long aesl_llvm_cbe_638_count = 0;
  static  unsigned long long aesl_llvm_cbe_639_count = 0;
  static  unsigned long long aesl_llvm_cbe_640_count = 0;
  static  unsigned long long aesl_llvm_cbe_641_count = 0;
  static  unsigned long long aesl_llvm_cbe_642_count = 0;
  static  unsigned long long aesl_llvm_cbe_643_count = 0;
  unsigned long long llvm_cbe_tmp__249;
  static  unsigned long long aesl_llvm_cbe_644_count = 0;
   char *llvm_cbe_tmp__250;
  static  unsigned long long aesl_llvm_cbe_645_count = 0;
  signed long long **llvm_cbe_tmp__251;
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
  unsigned long long llvm_cbe_tmp__252;
  static  unsigned long long aesl_llvm_cbe_656_count = 0;
  unsigned long long llvm_cbe_tmp__253;
  static  unsigned long long aesl_llvm_cbe_657_count = 0;
   char *llvm_cbe_tmp__254;
  static  unsigned long long aesl_llvm_cbe_658_count = 0;
  signed long long *llvm_cbe_tmp__255;
  static  unsigned long long aesl_llvm_cbe_659_count = 0;
  static  unsigned long long aesl_llvm_cbe_660_count = 0;
  static  unsigned long long aesl_llvm_cbe_661_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_690_count = 0;
  static  unsigned long long aesl_llvm_cbe_691_count = 0;
  signed long long *llvm_cbe_tmp__256;
  static  unsigned long long aesl_llvm_cbe_692_count = 0;
  signed long long *llvm_cbe_tmp__257;
  static  unsigned long long aesl_llvm_cbe_693_count = 0;
  signed long long *llvm_cbe_tmp__258;
  static  unsigned long long aesl_llvm_cbe_694_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge20_count = 0;
  unsigned long long llvm_cbe_storemerge20;
  unsigned long long llvm_cbe_storemerge20__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_rec_count = 0;
  unsigned long long llvm_cbe__2e_rec;
  unsigned long long llvm_cbe__2e_rec__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_695_count = 0;
  signed long long *llvm_cbe_tmp__259;
  static  unsigned long long aesl_llvm_cbe_696_count = 0;
  signed long long **llvm_cbe_tmp__260;
  static  unsigned long long aesl_llvm_cbe_697_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_rec27_count = 0;
  unsigned long long llvm_cbe__2e_rec27;
  static  unsigned long long aesl_llvm_cbe_698_count = 0;
  unsigned long long llvm_cbe_tmp__261;
  static  unsigned long long aesl_llvm_cbe_699_count = 0;
  static  unsigned long long aesl_llvm_cbe_700_count = 0;
  static  unsigned long long aesl_llvm_cbe_701_count = 0;
  static  unsigned long long aesl_llvm_cbe_702_count = 0;
  static  unsigned long long aesl_llvm_cbe_703_count = 0;
  static  unsigned long long aesl_llvm_cbe_704_count = 0;
  static  unsigned long long aesl_llvm_cbe_705_count = 0;
  static  unsigned long long aesl_llvm_cbe_706_count = 0;
  static  unsigned long long aesl_llvm_cbe_707_count = 0;
  static  unsigned long long aesl_llvm_cbe_708_count = 0;
  static  unsigned long long aesl_llvm_cbe_709_count = 0;
  static  unsigned long long aesl_llvm_cbe_710_count = 0;
  static  unsigned long long aesl_llvm_cbe_711_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond28_count = 0;
  static  unsigned long long aesl_llvm_cbe_712_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge117_count = 0;
  unsigned long long llvm_cbe_storemerge117;
  unsigned long long llvm_cbe_storemerge117__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_713_count = 0;
  static  unsigned long long aesl_llvm_cbe_714_count = 0;
  static  unsigned long long aesl_llvm_cbe_715_count = 0;
  static  unsigned long long aesl_llvm_cbe_716_count = 0;
  static  unsigned long long aesl_llvm_cbe_717_count = 0;
  static  unsigned long long aesl_llvm_cbe_718_count = 0;
  signed short *llvm_cbe_tmp__262;
  static  unsigned long long aesl_llvm_cbe_719_count = 0;
  unsigned short llvm_cbe_tmp__263;
  static  unsigned long long aesl_llvm_cbe_720_count = 0;
  unsigned long long llvm_cbe_tmp__264;
  static  unsigned long long aesl_llvm_cbe_721_count = 0;
  unsigned long long llvm_cbe_tmp__265;
  static  unsigned long long aesl_llvm_cbe_722_count = 0;
  unsigned long long llvm_cbe_tmp__266;
  static  unsigned long long aesl_llvm_cbe_723_count = 0;
  unsigned long long llvm_cbe_tmp__267;
  static  unsigned long long aesl_llvm_cbe_724_count = 0;
  unsigned long long llvm_cbe_tmp__268;
  static  unsigned long long aesl_llvm_cbe_725_count = 0;
  static  unsigned long long aesl_llvm_cbe_726_count = 0;
  static  unsigned long long aesl_llvm_cbe_727_count = 0;
  static  unsigned long long aesl_llvm_cbe_728_count = 0;
  static  unsigned long long aesl_llvm_cbe_729_count = 0;
  signed long long *llvm_cbe_tmp__269;
  static  unsigned long long aesl_llvm_cbe_730_count = 0;
  static  unsigned long long aesl_llvm_cbe_731_count = 0;
  static  unsigned long long aesl_llvm_cbe_732_count = 0;
  static  unsigned long long aesl_llvm_cbe_733_count = 0;
  static  unsigned long long aesl_llvm_cbe_734_count = 0;
  static  unsigned long long aesl_llvm_cbe_735_count = 0;
  static  unsigned long long aesl_llvm_cbe_736_count = 0;
  unsigned long long llvm_cbe_tmp__270;
  static  unsigned long long aesl_llvm_cbe_737_count = 0;
  static  unsigned long long aesl_llvm_cbe_738_count = 0;
  static  unsigned long long aesl_llvm_cbe_739_count = 0;
  static  unsigned long long aesl_llvm_cbe_740_count = 0;
  static  unsigned long long aesl_llvm_cbe_741_count = 0;
  static  unsigned long long aesl_llvm_cbe_742_count = 0;
  static  unsigned long long aesl_llvm_cbe_743_count = 0;
  unsigned long long llvm_cbe_tmp__271;
  unsigned long long llvm_cbe_tmp__271__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge4_2e_in12_count = 0;
  unsigned long long llvm_cbe_storemerge4_2e_in12;
  unsigned long long llvm_cbe_storemerge4_2e_in12__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_744_count = 0;
  signed long long **llvm_cbe_tmp__272;
  static  unsigned long long aesl_llvm_cbe_745_count = 0;
  signed long long *llvm_cbe_tmp__273;
  static  unsigned long long aesl_llvm_cbe_746_count = 0;
  signed long long *llvm_cbe_tmp__274;
  static  unsigned long long aesl_llvm_cbe_747_count = 0;
  static  unsigned long long aesl_llvm_cbe_phitmp_count = 0;
  unsigned long long llvm_cbe_phitmp;
  static  unsigned long long aesl_llvm_cbe_748_count = 0;
  static  unsigned long long aesl_llvm_cbe_749_count = 0;
  static  unsigned long long aesl_llvm_cbe_750_count = 0;
  static  unsigned long long aesl_llvm_cbe_751_count = 0;
  static  unsigned long long aesl_llvm_cbe_752_count = 0;
  static  unsigned long long aesl_llvm_cbe_753_count = 0;
  unsigned long long llvm_cbe_tmp__275;
  static  unsigned long long aesl_llvm_cbe_754_count = 0;
  static  unsigned long long aesl_llvm_cbe_755_count = 0;
  static  unsigned long long aesl_llvm_cbe_756_count = 0;
  static  unsigned long long aesl_llvm_cbe_757_count = 0;
  static  unsigned long long aesl_llvm_cbe_758_count = 0;
  static  unsigned long long aesl_llvm_cbe_759_count = 0;
  static  unsigned long long aesl_llvm_cbe_760_count = 0;
  unsigned long long llvm_cbe_tmp__276;
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
  static  unsigned long long aesl_llvm_cbe_exitcond26_count = 0;
  static  unsigned long long aesl_llvm_cbe_774_count = 0;
  static  unsigned long long aesl_llvm_cbe_775_count = 0;
  signed long long *llvm_cbe_tmp__277;
  static  unsigned long long aesl_llvm_cbe_776_count = 0;
  unsigned long long llvm_cbe_tmp__278;
  static  unsigned long long aesl_llvm_cbe_777_count = 0;
  unsigned long long llvm_cbe_tmp__279;
  static  unsigned long long aesl_llvm_cbe_778_count = 0;
   char *llvm_cbe_tmp__280;
  static  unsigned long long aesl_llvm_cbe_779_count = 0;
  signed long long *llvm_cbe_tmp__281;
  static  unsigned long long aesl_llvm_cbe_780_count = 0;
  static  unsigned long long aesl_llvm_cbe_781_count = 0;
  static  unsigned long long aesl_llvm_cbe_782_count = 0;
  static  unsigned long long aesl_llvm_cbe_783_count = 0;
  static  unsigned long long aesl_llvm_cbe_784_count = 0;
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
  unsigned long long llvm_cbe_tmp__282;
  static  unsigned long long aesl_llvm_cbe_798_count = 0;
  static  unsigned long long aesl_llvm_cbe_799_count = 0;
  static  unsigned long long aesl_llvm_cbe_800_count = 0;
  static  unsigned long long aesl_llvm_cbe_801_count = 0;
  static  unsigned long long aesl_llvm_cbe_802_count = 0;
  static  unsigned long long aesl_llvm_cbe_803_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond24_count = 0;
  static  unsigned long long aesl_llvm_cbe_804_count = 0;
  static  unsigned long long aesl_llvm_cbe_805_count = 0;
  unsigned long long llvm_cbe_tmp__283;
  unsigned long long llvm_cbe_tmp__283__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_806_count = 0;
  unsigned long long llvm_cbe_tmp__284;
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
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_820_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge37_2e_us_count = 0;
  unsigned long long llvm_cbe_storemerge37_2e_us;
  unsigned long long llvm_cbe_storemerge37_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_821_count = 0;
  unsigned long long llvm_cbe_tmp__285;
  unsigned long long llvm_cbe_tmp__285__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_822_count = 0;
  signed long long *llvm_cbe_tmp__286;
  static  unsigned long long aesl_llvm_cbe_823_count = 0;
  unsigned long long llvm_cbe_tmp__287;
  static  unsigned long long aesl_llvm_cbe_824_count = 0;
  unsigned int llvm_cbe_tmp__288;
  static  unsigned long long aesl_llvm_cbe_825_count = 0;
  static  unsigned long long aesl_llvm_cbe_826_count = 0;
  static  unsigned long long aesl_llvm_cbe_827_count = 0;
  signed long long *llvm_cbe_tmp__289;
  static  unsigned long long aesl_llvm_cbe_828_count = 0;
  static  unsigned long long aesl_llvm_cbe_829_count = 0;
  unsigned long long llvm_cbe_tmp__290;
  static  unsigned long long aesl_llvm_cbe_830_count = 0;
  static  unsigned long long aesl_llvm_cbe_831_count = 0;
  static  unsigned long long aesl_llvm_cbe_832_count = 0;
  static  unsigned long long aesl_llvm_cbe_833_count = 0;
  static  unsigned long long aesl_llvm_cbe_834_count = 0;
  static  unsigned long long aesl_llvm_cbe_835_count = 0;
  static  unsigned long long aesl_llvm_cbe_836_count = 0;
  unsigned int llvm_cbe_tmp__291;
  static  unsigned long long aesl_llvm_cbe_837_count = 0;
  static  unsigned long long aesl_llvm_cbe_838_count = 0;
  static  unsigned long long aesl_llvm_cbe_839_count = 0;
  unsigned int llvm_cbe_tmp__292;
  static  unsigned long long aesl_llvm_cbe_840_count = 0;
  static  unsigned long long aesl_llvm_cbe_841_count = 0;
  static  unsigned long long aesl_llvm_cbe_842_count = 0;
  unsigned long long llvm_cbe_tmp__293;
  unsigned long long llvm_cbe_tmp__293__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_843_count = 0;
  unsigned int llvm_cbe_tmp__294;
  static  unsigned long long aesl_llvm_cbe_844_count = 0;
  static  unsigned long long aesl_llvm_cbe_845_count = 0;
  static  unsigned long long aesl_llvm_cbe_846_count = 0;
  unsigned long long llvm_cbe_tmp__295;
  static  unsigned long long aesl_llvm_cbe_847_count = 0;
  unsigned long long llvm_cbe_tmp__296;
  static  unsigned long long aesl_llvm_cbe_848_count = 0;
  static  unsigned long long aesl_llvm_cbe_849_count = 0;
  static  unsigned long long aesl_llvm_cbe_850_count = 0;
  static  unsigned long long aesl_llvm_cbe_851_count = 0;
  static  unsigned long long aesl_llvm_cbe_852_count = 0;
  static  unsigned long long aesl_llvm_cbe_853_count = 0;
  static  unsigned long long aesl_llvm_cbe_854_count = 0;
  static  unsigned long long aesl_llvm_cbe_855_count = 0;
  static  unsigned long long aesl_llvm_cbe_856_count = 0;
  unsigned long long llvm_cbe_tmp__297;
  static  unsigned long long aesl_llvm_cbe_857_count = 0;
  unsigned long long llvm_cbe_tmp__298;
  static  unsigned long long aesl_llvm_cbe_858_count = 0;
  static  unsigned long long aesl_llvm_cbe_859_count = 0;
  static  unsigned long long aesl_llvm_cbe_860_count = 0;
  static  unsigned long long aesl_llvm_cbe_861_count = 0;
  static  unsigned long long aesl_llvm_cbe_862_count = 0;
  static  unsigned long long aesl_llvm_cbe_863_count = 0;
  static  unsigned long long aesl_llvm_cbe_864_count = 0;
  static  unsigned long long aesl_llvm_cbe_865_count = 0;
  unsigned int llvm_cbe_tmp__299;
  static  unsigned long long aesl_llvm_cbe_866_count = 0;
  static  unsigned long long aesl_llvm_cbe_867_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge29_2e_us_count = 0;
  unsigned long long llvm_cbe_storemerge29_2e_us;
  unsigned long long llvm_cbe_storemerge29_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_868_count = 0;
  unsigned long long llvm_cbe_tmp__300;
  unsigned long long llvm_cbe_tmp__300__PHI_TEMPORARY;
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
  signed long long **llvm_cbe_tmp__301;
  static  unsigned long long aesl_llvm_cbe_882_count = 0;
  signed long long *llvm_cbe_tmp__302;
  static  unsigned long long aesl_llvm_cbe_883_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge29_count = 0;
  unsigned long long llvm_cbe_storemerge29;
  unsigned long long llvm_cbe_storemerge29__PHI_TEMPORARY;
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
  unsigned long long llvm_cbe_tmp__303;
  static  unsigned long long aesl_llvm_cbe_897_count = 0;
  static  unsigned long long aesl_llvm_cbe_898_count = 0;
  static  unsigned long long aesl_llvm_cbe_899_count = 0;
  static  unsigned long long aesl_llvm_cbe_900_count = 0;
  static  unsigned long long aesl_llvm_cbe_901_count = 0;
  static  unsigned long long aesl_llvm_cbe_902_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond25_count = 0;
  static  unsigned long long aesl_llvm_cbe_903_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_lcssa8_count = 0;
  unsigned long long llvm_cbe__2e_lcssa8;
  unsigned long long llvm_cbe__2e_lcssa8__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_904_count = 0;
  signed long long *llvm_cbe_tmp__304;
  static  unsigned long long aesl_llvm_cbe_905_count = 0;
   char *llvm_cbe_tmp__305;
  static  unsigned long long aesl_llvm_cbe_906_count = 0;
  static  unsigned long long aesl_llvm_cbe_907_count = 0;
  static  unsigned long long aesl_llvm_cbe_908_count = 0;
  static  unsigned long long aesl_llvm_cbe_909_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @aesl_internal_getRevealedNodes\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.tree_t* %%tree, i64 0, i32 0, !dbg !24 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_635_count);
  llvm_cbe_tmp__246 = (signed long long *)(&llvm_cbe_tree->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i64* %%1, align 8, !dbg !24 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_636_count);
  llvm_cbe_tmp__247 = (unsigned long long )*llvm_cbe_tmp__246;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__247);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = add i64 %%2, -1, !dbg !24 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_637_count);
  llvm_cbe_tmp__248 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__247&18446744073709551615ull)) + ((unsigned long long )(18446744073709551615ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__248&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = shl i64 %%3, 3, !dbg !27 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_643_count);
  llvm_cbe_tmp__249 = (unsigned long long )llvm_cbe_tmp__248 << 3ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__249);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = tail call i8* @malloc(i64 %%4), !dbg !27 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_644_count);
  llvm_cbe_tmp__250 = ( char *) /*tail*/ ( char *)malloc(llvm_cbe_tmp__249);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__249);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__250);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = bitcast i8* %%5 to i64**, !dbg !27 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_645_count);
  llvm_cbe_tmp__251 = (signed long long **)((signed long long **)llvm_cbe_tmp__250);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = shl i64 %%hideListSize, 3, !dbg !26 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_655_count);
  llvm_cbe_tmp__252 = (unsigned long long )llvm_cbe_hideListSize << 3ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__252);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = mul i64 %%7, %%3, !dbg !26 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_656_count);
  llvm_cbe_tmp__253 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__252&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__248&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__253&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = tail call i8* @malloc(i64 %%8), !dbg !26 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_657_count);
  llvm_cbe_tmp__254 = ( char *) /*tail*/ ( char *)malloc(llvm_cbe_tmp__253);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__253);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__254);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = bitcast i8* %%9 to i64*, !dbg !26 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_658_count);
  llvm_cbe_tmp__255 = (signed long long *)((signed long long *)llvm_cbe_tmp__254);
  if (((llvm_cbe_tmp__248&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e_preheader16;
  } else {
    llvm_cbe_storemerge20__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    llvm_cbe__2e_rec__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph22;
  }

llvm_cbe__2e_preheader16:
  if (((llvm_cbe_hideListSize&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge19;
  } else {
    goto llvm_cbe__2e_lr_2e_ph18;
  }

llvm_cbe__2e_lr_2e_ph18:
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds %%struct.tree_t* %%tree, i64 0, i32 5, !dbg !24 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_691_count);
  llvm_cbe_tmp__256 = (signed long long *)(&llvm_cbe_tree->field5);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds %%struct.tree_t* %%tree, i64 0, i32 6, !dbg !24 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_692_count);
  llvm_cbe_tmp__257 = (signed long long *)(&llvm_cbe_tree->field6);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = load i64** %%6, align 8, !dbg !28 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_693_count);
  llvm_cbe_tmp__258 = (signed long long *)*llvm_cbe_tmp__251;
  llvm_cbe_storemerge117__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__306;

  do {     /* Syntactic loop '.lr.ph22' to make GCC happy */
llvm_cbe__2e_lr_2e_ph22:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge20 = phi i64 [ %%18, %%.lr.ph22 ], [ 0, %%0  for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_storemerge20_count);
  llvm_cbe_storemerge20 = (unsigned long long )llvm_cbe_storemerge20__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge20 = 0x%I64X",llvm_cbe_storemerge20);
printf("\n = 0x%I64X",llvm_cbe_tmp__261);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec = phi i64 [ %%.rec27, %%.lr.ph22 ], [ 0, %%0  for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe__2e_rec_count);
  llvm_cbe__2e_rec = (unsigned long long )llvm_cbe__2e_rec__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.rec = 0x%I64X",llvm_cbe__2e_rec);
printf("\n.rec27 = 0x%I64X",llvm_cbe__2e_rec27);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr i64* %%10, i64 %%.re for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_695_count);
  llvm_cbe_tmp__259 = (signed long long *)(&llvm_cbe_tmp__255[(((signed long long )llvm_cbe__2e_rec))]);
if (AESL_DEBUG_TRACE) {
printf("\n.rec = 0x%I64X",((signed long long )llvm_cbe__2e_rec));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds i64** %%6, i64 %%storemerge20, !dbg !27 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_696_count);
  llvm_cbe_tmp__260 = (signed long long **)(&llvm_cbe_tmp__251[(((signed long long )llvm_cbe_storemerge20))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge20 = 0x%I64X",((signed long long )llvm_cbe_storemerge20));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64* %%16, i64** %%17, align 8, !dbg !27 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_697_count);
  *llvm_cbe_tmp__260 = (signed long long *)llvm_cbe_tmp__259;
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec27 = add i64 %%.rec, %%hideListSize, !dbg !26 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe__2e_rec27_count);
  llvm_cbe__2e_rec27 = (unsigned long long )((unsigned long long )(llvm_cbe__2e_rec&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_hideListSize&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.rec27 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_rec27&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = add i64 %%storemerge20, 1, !dbg !28 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_698_count);
  llvm_cbe_tmp__261 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge20&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__261&18446744073709551615ull)));
  if (((llvm_cbe_tmp__261&18446744073709551615ULL) == (llvm_cbe_tmp__248&18446744073709551615ULL))) {
    goto llvm_cbe__2e_preheader16;
  } else {
    llvm_cbe_storemerge20__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__261;   /* for PHI node */
    llvm_cbe__2e_rec__PHI_TEMPORARY = (unsigned long long )llvm_cbe__2e_rec27;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph22;
  }

  } while (1); /* end of syntactic loop '.lr.ph22' */
  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__306:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge117 = phi i64 [ 0, %%.lr.ph18 ], [ %%36, %%._crit_edge15  for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_storemerge117_count);
  llvm_cbe_storemerge117 = (unsigned long long )llvm_cbe_storemerge117__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge117 = 0x%I64X",llvm_cbe_storemerge117);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__276);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = getelementptr inbounds i16* %%hideList, i64 %%storemerge117, !dbg !24 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_718_count);
  llvm_cbe_tmp__262 = (signed short *)(&llvm_cbe_hideList[(((signed long long )llvm_cbe_storemerge117))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge117 = 0x%I64X",((signed long long )llvm_cbe_storemerge117));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = load i16* %%20, align 2, !dbg !24 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_719_count);
  llvm_cbe_tmp__263 = (unsigned short )*llvm_cbe_tmp__262;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__263);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = zext i16 %%21 to i64, !dbg !24 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_720_count);
  llvm_cbe_tmp__264 = (unsigned long long )((unsigned long long )(unsigned short )llvm_cbe_tmp__263&65535U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__264);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = load i64* %%13, align 8, !dbg !24 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_721_count);
  llvm_cbe_tmp__265 = (unsigned long long )*llvm_cbe_tmp__256;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__265);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = load i64* %%14, align 8, !dbg !24 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_722_count);
  llvm_cbe_tmp__266 = (unsigned long long )*llvm_cbe_tmp__257;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__266);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = sub i64 %%23, %%24, !dbg !24 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_723_count);
  llvm_cbe_tmp__267 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__265&18446744073709551615ull)) - ((unsigned long long )(llvm_cbe_tmp__266&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__267&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = add i64 %%25, %%22, !dbg !24 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_724_count);
  llvm_cbe_tmp__268 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__267&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__264&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__268&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = getelementptr inbounds i64* %%15, i64 %%storemerge117, !dbg !28 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_729_count);
  llvm_cbe_tmp__269 = (signed long long *)(&llvm_cbe_tmp__258[(((signed long long )llvm_cbe_storemerge117))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge117 = 0x%I64X",((signed long long )llvm_cbe_storemerge117));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%26, i64* %%27, align 8, !dbg !28 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_730_count);
  *llvm_cbe_tmp__269 = llvm_cbe_tmp__268;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__268);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = tail call i64 @getParent(i64 %%26), !dbg !29 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_736_count);
  llvm_cbe_tmp__270 = (unsigned long long ) /*tail*/ getParent(llvm_cbe_tmp__268);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__268);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__270);
}
  if (((llvm_cbe_tmp__270&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge15;
  } else {
    llvm_cbe_tmp__271__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__270;   /* for PHI node */
    llvm_cbe_storemerge4_2e_in12__PHI_TEMPORARY = (unsigned long long )1ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph14;
  }

llvm_cbe__2e__crit_edge15:
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = add i64 %%storemerge117, 1, !dbg !28 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_760_count);
  llvm_cbe_tmp__276 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge117&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__276&18446744073709551615ull)));
  if (((llvm_cbe_tmp__276&18446744073709551615ULL) == (llvm_cbe_hideListSize&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge19;
  } else {
    llvm_cbe_storemerge117__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__276;   /* for PHI node */
    goto llvm_cbe_tmp__306;
  }

  do {     /* Syntactic loop '.lr.ph14' to make GCC happy */
llvm_cbe__2e_lr_2e_ph14:
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = phi i64 [ %%34, %%.lr.ph14 ], [ %%28, %%19  for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_743_count);
  llvm_cbe_tmp__271 = (unsigned long long )llvm_cbe_tmp__271__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__271);
printf("\n = 0x%I64X",llvm_cbe_tmp__275);
printf("\n = 0x%I64X",llvm_cbe_tmp__270);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge4.in12 = phi i64 [ %%phitmp, %%.lr.ph14 ], [ 1, %%19  for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_storemerge4_2e_in12_count);
  llvm_cbe_storemerge4_2e_in12 = (unsigned long long )llvm_cbe_storemerge4_2e_in12__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge4.in12 = 0x%I64X",llvm_cbe_storemerge4_2e_in12);
printf("\nphitmp = 0x%I64X",llvm_cbe_phitmp);
printf("\n = 0x%I64X",1ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = getelementptr inbounds i64** %%6, i64 %%storemerge4.in12, !dbg !28 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_744_count);
  llvm_cbe_tmp__272 = (signed long long **)(&llvm_cbe_tmp__251[(((signed long long )llvm_cbe_storemerge4_2e_in12))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge4.in12 = 0x%I64X",((signed long long )llvm_cbe_storemerge4_2e_in12));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = load i64** %%31, align 8, !dbg !28 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_745_count);
  llvm_cbe_tmp__273 = (signed long long *)*llvm_cbe_tmp__272;
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = getelementptr inbounds i64* %%32, i64 %%storemerge117, !dbg !28 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_746_count);
  llvm_cbe_tmp__274 = (signed long long *)(&llvm_cbe_tmp__273[(((signed long long )llvm_cbe_storemerge117))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge117 = 0x%I64X",((signed long long )llvm_cbe_storemerge117));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%30, i64* %%33, align 8, !dbg !28 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_747_count);
  *llvm_cbe_tmp__274 = llvm_cbe_tmp__271;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__271);
if (AESL_DEBUG_TRACE)
printf("\n  %%phitmp = add i64 %%storemerge4.in12, 1, !dbg !29 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_phitmp_count);
  llvm_cbe_phitmp = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge4_2e_in12&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\nphitmp = 0x%I64X\n", ((unsigned long long )(llvm_cbe_phitmp&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = tail call i64 @getParent(i64 %%30), !dbg !29 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_753_count);
  llvm_cbe_tmp__275 = (unsigned long long ) /*tail*/ getParent(llvm_cbe_tmp__271);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__271);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__275);
}
  if (((llvm_cbe_tmp__275&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge15;
  } else {
    llvm_cbe_tmp__271__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__275;   /* for PHI node */
    llvm_cbe_storemerge4_2e_in12__PHI_TEMPORARY = (unsigned long long )llvm_cbe_phitmp;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph14;
  }

  } while (1); /* end of syntactic loop '.lr.ph14' */
  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e__crit_edge19:
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = getelementptr inbounds %%struct.tree_t* %%tree, i64 0, i32 6, !dbg !24 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_775_count);
  llvm_cbe_tmp__277 = (signed long long *)(&llvm_cbe_tree->field6);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = load i64* %%37, align 8, !dbg !24 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_776_count);
  llvm_cbe_tmp__278 = (unsigned long long )*llvm_cbe_tmp__277;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__278);
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = shl i64 %%38, 3, !dbg !24 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_777_count);
  llvm_cbe_tmp__279 = (unsigned long long )llvm_cbe_tmp__278 << 3ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__279);
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = tail call i8* @malloc(i64 %%39), !dbg !24 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_778_count);
  llvm_cbe_tmp__280 = ( char *) /*tail*/ ( char *)malloc(llvm_cbe_tmp__279);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__279);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__280);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = bitcast i8* %%40 to i64*, !dbg !24 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_779_count);
  llvm_cbe_tmp__281 = (signed long long *)((signed long long *)llvm_cbe_tmp__280);
  if (((llvm_cbe_tmp__248&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    llvm_cbe__2e_lcssa8__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge10;
  } else {
    goto llvm_cbe__2e_preheader5_2e_lr_2e_ph;
  }

llvm_cbe__2e_preheader5_2e_lr_2e_ph:
  if (((llvm_cbe_hideListSize&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    llvm_cbe_storemerge29__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe_tmp__307;
  } else {
    llvm_cbe_storemerge29_2e_us__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    llvm_cbe_tmp__300__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  }

  do {     /* Syntactic loop '.lr.ph.us' to make GCC happy */
llvm_cbe__2e_lr_2e_ph_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge29.us = phi i64 [ %%43, %%42 ], [ 0, %%.preheader5.lr.ph  for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_storemerge29_2e_us_count);
  llvm_cbe_storemerge29_2e_us = (unsigned long long )llvm_cbe_storemerge29_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge29.us = 0x%I64X",llvm_cbe_storemerge29_2e_us);
printf("\n = 0x%I64X",llvm_cbe_tmp__282);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%72 = phi i64 [ %%45, %%42 ], [ 0, %%.preheader5.lr.ph  for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_868_count);
  llvm_cbe_tmp__300 = (unsigned long long )llvm_cbe_tmp__300__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__300);
printf("\n = 0x%I64X",llvm_cbe_tmp__283);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%73 = getelementptr inbounds i64** %%6, i64 %%storemerge29.us, !dbg !25 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_881_count);
  llvm_cbe_tmp__301 = (signed long long **)(&llvm_cbe_tmp__251[(((signed long long )llvm_cbe_storemerge29_2e_us))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge29.us = 0x%I64X",((signed long long )llvm_cbe_storemerge29_2e_us));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%74 = load i64** %%73, align 8, !dbg !25 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_882_count);
  llvm_cbe_tmp__302 = (signed long long *)*llvm_cbe_tmp__301;
  llvm_cbe_storemerge37_2e_us__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  llvm_cbe_tmp__285__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__300;   /* for PHI node */
  goto llvm_cbe_tmp__308;

llvm_cbe_tmp__309:
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = add i64 %%storemerge29.us, 1, !dbg !30 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_797_count);
  llvm_cbe_tmp__282 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge29_2e_us&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__282&18446744073709551615ull)));
  if (((llvm_cbe_tmp__282&18446744073709551615ULL) == (llvm_cbe_tmp__248&18446744073709551615ULL))) {
    llvm_cbe__2e_lcssa8__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__283;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge10;
  } else {
    llvm_cbe_storemerge29_2e_us__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__282;   /* for PHI node */
    llvm_cbe_tmp__300__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__283;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__308:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge37.us = phi i64 [ 0, %%.lr.ph.us ], [ %%46, %%44  for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_storemerge37_2e_us_count);
  llvm_cbe_storemerge37_2e_us = (unsigned long long )llvm_cbe_storemerge37_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge37.us = 0x%I64X",llvm_cbe_storemerge37_2e_us);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__284);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = phi i64 [ %%72, %%.lr.ph.us ], [ %%45, %%44  for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_821_count);
  llvm_cbe_tmp__285 = (unsigned long long )llvm_cbe_tmp__285__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__285);
printf("\n = 0x%I64X",llvm_cbe_tmp__300);
printf("\n = 0x%I64X",llvm_cbe_tmp__283);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = getelementptr inbounds i64* %%74, i64 %%storemerge37.us, !dbg !25 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_822_count);
  llvm_cbe_tmp__286 = (signed long long *)(&llvm_cbe_tmp__302[(((signed long long )llvm_cbe_storemerge37_2e_us))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge37.us = 0x%I64X",((signed long long )llvm_cbe_storemerge37_2e_us));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = load i64* %%49, align 8, !dbg !25 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_823_count);
  llvm_cbe_tmp__287 = (unsigned long long )*llvm_cbe_tmp__286;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__287);
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = tail call i32 @hasSibling(%%struct.tree_t* %%tree, i64 %%50), !dbg !25 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_824_count);
  llvm_cbe_tmp__288 = (unsigned int ) /*tail*/ hasSibling((l_struct_OC_tree_t *)llvm_cbe_tree, llvm_cbe_tmp__287);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__287);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__288);
}
  if (((llvm_cbe_tmp__288&4294967295U) == (0u&4294967295U))) {
    llvm_cbe_tmp__283__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__285;   /* for PHI node */
    goto llvm_cbe_tmp__310;
  } else {
    goto llvm_cbe_tmp__311;
  }

llvm_cbe_tmp__310:
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = phi i64 [ %%48, %%47 ], [ %%48, %%67 ], [ %%48, %%.critedge.us ], [ %%55, %%53  for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_805_count);
  llvm_cbe_tmp__283 = (unsigned long long )llvm_cbe_tmp__283__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__283);
printf("\n = 0x%I64X",llvm_cbe_tmp__285);
printf("\n = 0x%I64X",llvm_cbe_tmp__285);
printf("\n = 0x%I64X",llvm_cbe_tmp__285);
printf("\n = 0x%I64X",llvm_cbe_tmp__290);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = add i64 %%storemerge37.us, 1, !dbg !29 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_806_count);
  llvm_cbe_tmp__284 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge37_2e_us&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__284&18446744073709551615ull)));
  if (((llvm_cbe_tmp__284&18446744073709551615ULL) == (llvm_cbe_hideListSize&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__309;
  } else {
    llvm_cbe_storemerge37_2e_us__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__284;   /* for PHI node */
    llvm_cbe_tmp__285__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__283;   /* for PHI node */
    goto llvm_cbe_tmp__308;
  }

llvm_cbe_tmp__312:
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = getelementptr inbounds i64* %%41, i64 %%48, !dbg !30 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_827_count);
  llvm_cbe_tmp__289 = (signed long long *)(&llvm_cbe_tmp__281[(((signed long long )llvm_cbe_tmp__285))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__285));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%61, i64* %%54, align 8, !dbg !30 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_828_count);
  *llvm_cbe_tmp__289 = llvm_cbe_tmp__293;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__293);
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = add i64 %%48, 1, !dbg !30 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_829_count);
  llvm_cbe_tmp__290 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__285&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__290&18446744073709551615ull)));
  llvm_cbe_tmp__283__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__290;   /* for PHI node */
  goto llvm_cbe_tmp__310;

llvm_cbe__2e_critedge_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = tail call fastcc i32 @aesl_internal_contains(i64* %%41, i64 %%48, i64 %%61), !dbg !30 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_836_count);
  llvm_cbe_tmp__291 = (unsigned int ) /*tail*/ aesl_internal_contains((signed long long *)llvm_cbe_tmp__281, llvm_cbe_tmp__285, llvm_cbe_tmp__293);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__285);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__293);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__291);
}
  if (((llvm_cbe_tmp__291&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__312;
  } else {
    llvm_cbe_tmp__283__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__285;   /* for PHI node */
    goto llvm_cbe_tmp__310;
  }

  do {     /* Syntactic loop '.preheader.us' to make GCC happy */
llvm_cbe__2e_preheader_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%61 = phi i64 [ %%66, %%64 ], [ %%69, %%67  for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_842_count);
  llvm_cbe_tmp__293 = (unsigned long long )llvm_cbe_tmp__293__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__293);
printf("\n = 0x%I64X",llvm_cbe_tmp__296);
printf("\n = 0x%I64X",llvm_cbe_tmp__298);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = tail call i32 @hasRightChild(%%struct.tree_t* %%tree, i64 %%61), !dbg !25 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_843_count);
  llvm_cbe_tmp__294 = (unsigned int ) /*tail*/ hasRightChild((l_struct_OC_tree_t *)llvm_cbe_tree, llvm_cbe_tmp__293);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__293);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__294);
}
  if (((llvm_cbe_tmp__294&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__313;
  } else {
    goto llvm_cbe__2e_critedge_2e_us;
  }

llvm_cbe_tmp__314:
if (AESL_DEBUG_TRACE)
printf("\n  %%65 = shl i64 %%61, 1, !dbg !31 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_846_count);
  llvm_cbe_tmp__295 = (unsigned long long )llvm_cbe_tmp__293 << 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__295);
if (AESL_DEBUG_TRACE)
printf("\n  %%66 = or i64 %%65, 1, !dbg !31 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_847_count);
  llvm_cbe_tmp__296 = (unsigned long long )llvm_cbe_tmp__295 | 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__296);
  llvm_cbe_tmp__293__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__296;   /* for PHI node */
  goto llvm_cbe__2e_preheader_2e_us;

llvm_cbe_tmp__313:
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = tail call i32 @isLeafNode(%%struct.tree_t* %%tree, i64 %%61), !dbg !25 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_839_count);
  llvm_cbe_tmp__292 = (unsigned int ) /*tail*/ isLeafNode((l_struct_OC_tree_t *)llvm_cbe_tree, llvm_cbe_tmp__293);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__293);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__292);
}
  if (((llvm_cbe_tmp__292&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__314;
  } else {
    goto llvm_cbe__2e_critedge_2e_us;
  }

  } while (1); /* end of syntactic loop '.preheader.us' */
llvm_cbe_tmp__311:
if (AESL_DEBUG_TRACE)
printf("\n  %%68 = load i64* %%49, align 8, !dbg !25 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_856_count);
  llvm_cbe_tmp__297 = (unsigned long long )*llvm_cbe_tmp__286;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__297);
if (AESL_DEBUG_TRACE)
printf("\n  %%69 = tail call i64 @getSibling(%%struct.tree_t* %%tree, i64 %%68), !dbg !25 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_857_count);
  llvm_cbe_tmp__298 = (unsigned long long ) /*tail*/ getSibling((l_struct_OC_tree_t *)llvm_cbe_tree, llvm_cbe_tmp__297);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__297);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__298);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%70 = tail call fastcc i32 @aesl_internal_contains(i64* %%74, i64 %%hideListSize, i64 %%69), !dbg !26 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_865_count);
  llvm_cbe_tmp__299 = (unsigned int ) /*tail*/ aesl_internal_contains((signed long long *)llvm_cbe_tmp__302, llvm_cbe_hideListSize, llvm_cbe_tmp__298);
if (AESL_DEBUG_TRACE) {
printf("\nArgument hideListSize = 0x%I64X",llvm_cbe_hideListSize);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__298);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__299);
}
  if (((llvm_cbe_tmp__299&4294967295U) == (0u&4294967295U))) {
    llvm_cbe_tmp__293__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__298;   /* for PHI node */
    goto llvm_cbe__2e_preheader_2e_us;
  } else {
    llvm_cbe_tmp__283__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__285;   /* for PHI node */
    goto llvm_cbe_tmp__310;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.lr.ph.us' */
  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__307:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge29 = phi i64 [ %%76, %%75 ], [ 0, %%.preheader5.lr.ph  for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_storemerge29_count);
  llvm_cbe_storemerge29 = (unsigned long long )llvm_cbe_storemerge29__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge29 = 0x%I64X",llvm_cbe_storemerge29);
printf("\n = 0x%I64X",llvm_cbe_tmp__303);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%76 = add i64 %%storemerge29, 1, !dbg !30 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_896_count);
  llvm_cbe_tmp__303 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge29&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__303&18446744073709551615ull)));
  if (((llvm_cbe_tmp__303&18446744073709551615ULL) == (llvm_cbe_tmp__248&18446744073709551615ULL))) {
    llvm_cbe__2e_lcssa8__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge10;
  } else {
    llvm_cbe_storemerge29__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__303;   /* for PHI node */
    goto llvm_cbe_tmp__307;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e__crit_edge10:
if (AESL_DEBUG_TRACE)
printf("\n  %%.lcssa8 = phi i64 [ 0, %%._crit_edge19 ], [ %%45, %%42 ], [ 0, %%75  for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe__2e_lcssa8_count);
  llvm_cbe__2e_lcssa8 = (unsigned long long )llvm_cbe__2e_lcssa8__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.lcssa8 = 0x%I64X",llvm_cbe__2e_lcssa8);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__283);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%77 = load i64** %%6, align 8, !dbg !28 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_904_count);
  llvm_cbe_tmp__304 = (signed long long *)*llvm_cbe_tmp__251;
if (AESL_DEBUG_TRACE)
printf("\n  %%78 = bitcast i64* %%77 to i8*, !dbg !28 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_905_count);
  llvm_cbe_tmp__305 = ( char *)(( char *)llvm_cbe_tmp__304);
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @free(i8* %%78), !dbg !28 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_906_count);
   /*tail*/ free(( char *)llvm_cbe_tmp__305);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @free(i8* %%5), !dbg !28 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_907_count);
   /*tail*/ free(( char *)llvm_cbe_tmp__250);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%.lcssa8, i64* %%outputSize, align 8, !dbg !27 for 0x%I64xth hint within @aesl_internal_getRevealedNodes  --> \n", ++aesl_llvm_cbe_908_count);
  *llvm_cbe_outputSize = llvm_cbe__2e_lcssa8;
if (AESL_DEBUG_TRACE)
printf("\n.lcssa8 = 0x%I64X\n", llvm_cbe__2e_lcssa8);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @aesl_internal_getRevealedNodes}\n");
  return llvm_cbe_tmp__281;
}


signed long long revealSeeds(l_struct_OC_tree_t *llvm_cbe_tree, signed short *llvm_cbe_hideList, signed long long llvm_cbe_hideListSize,  char *llvm_cbe_output, signed long long llvm_cbe_outputSize, l_struct_OC_paramset_t *llvm_cbe_params) {
  static  unsigned long long aesl_llvm_cbe_revealedSize_count = 0;
  signed long long llvm_cbe_revealedSize;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_910_count = 0;
  static  unsigned long long aesl_llvm_cbe_911_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_941_count = 0;
  unsigned int llvm_cbe_tmp__315;
  static  unsigned long long aesl_llvm_cbe_942_count = 0;
  static  unsigned long long aesl_llvm_cbe_943_count = 0;
  static  unsigned long long aesl_llvm_cbe_944_count = 0;
  static  unsigned long long aesl_llvm_cbe_945_count = 0;
  signed long long *llvm_cbe_tmp__316;
  static  unsigned long long aesl_llvm_cbe_946_count = 0;
  static  unsigned long long aesl_llvm_cbe_947_count = 0;
  static  unsigned long long aesl_llvm_cbe_948_count = 0;
  static  unsigned long long aesl_llvm_cbe_949_count = 0;
  static  unsigned long long aesl_llvm_cbe_950_count = 0;
  static  unsigned long long aesl_llvm_cbe_951_count = 0;
  signed int *llvm_cbe_tmp__317;
  static  unsigned long long aesl_llvm_cbe_952_count = 0;
   char ***llvm_cbe_tmp__318;
  static  unsigned long long aesl_llvm_cbe_953_count = 0;
  static  unsigned long long aesl_llvm_cbe_954_count = 0;
  unsigned int llvm_cbe_tmp__319;
  unsigned int llvm_cbe_tmp__319__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_rec_count = 0;
  unsigned long long llvm_cbe__2e_rec;
  unsigned long long llvm_cbe__2e_rec__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge_count = 0;
  unsigned long long llvm_cbe_storemerge;
  unsigned long long llvm_cbe_storemerge__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_955_count = 0;
   char *llvm_cbe_tmp__320;
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
  unsigned long long llvm_cbe_tmp__321;
  static  unsigned long long aesl_llvm_cbe_966_count = 0;
  static  unsigned long long aesl_llvm_cbe_967_count = 0;
  static  unsigned long long aesl_llvm_cbe_968_count = 0;
  unsigned int llvm_cbe_tmp__322;
  static  unsigned long long aesl_llvm_cbe_969_count = 0;
  unsigned int llvm_cbe_tmp__323;
  static  unsigned long long aesl_llvm_cbe_970_count = 0;
  static  unsigned long long aesl_llvm_cbe_971_count = 0;
  static  unsigned long long aesl_llvm_cbe_972_count = 0;
  static  unsigned long long aesl_llvm_cbe_973_count = 0;
  static  unsigned long long aesl_llvm_cbe_974_count = 0;
  static  unsigned long long aesl_llvm_cbe_975_count = 0;
  static  unsigned long long aesl_llvm_cbe_976_count = 0;
   char *llvm_cbe_tmp__324;
  static  unsigned long long aesl_llvm_cbe_977_count = 0;
  static  unsigned long long aesl_llvm_cbe_978_count = 0;
  static  unsigned long long aesl_llvm_cbe_979_count = 0;
  signed long long *llvm_cbe_tmp__325;
  static  unsigned long long aesl_llvm_cbe_980_count = 0;
  unsigned long long llvm_cbe_tmp__326;
  static  unsigned long long aesl_llvm_cbe_981_count = 0;
   char **llvm_cbe_tmp__327;
  static  unsigned long long aesl_llvm_cbe_982_count = 0;
   char **llvm_cbe_tmp__328;
  static  unsigned long long aesl_llvm_cbe_983_count = 0;
   char *llvm_cbe_tmp__329;
  static  unsigned long long aesl_llvm_cbe_984_count = 0;
  unsigned long long llvm_cbe_tmp__330;
  static  unsigned long long aesl_llvm_cbe_985_count = 0;
   char *llvm_cbe_tmp__331;
  static  unsigned long long aesl_llvm_cbe_986_count = 0;
  unsigned int llvm_cbe_tmp__332;
  static  unsigned long long aesl_llvm_cbe_987_count = 0;
  unsigned long long llvm_cbe_tmp__333;
  static  unsigned long long aesl_llvm_cbe__2e_rec3_count = 0;
  unsigned long long llvm_cbe__2e_rec3;
  static  unsigned long long aesl_llvm_cbe_988_count = 0;
  unsigned long long llvm_cbe_tmp__334;
  static  unsigned long long aesl_llvm_cbe_989_count = 0;
  static  unsigned long long aesl_llvm_cbe_990_count = 0;
  static  unsigned long long aesl_llvm_cbe_991_count = 0;
   char *llvm_cbe_tmp__335;
  static  unsigned long long aesl_llvm_cbe_992_count = 0;
  static  unsigned long long aesl_llvm_cbe_993_count = 0;
  static  unsigned long long aesl_llvm_cbe_994_count = 0;
  unsigned long long llvm_cbe_tmp__336;
  unsigned long long llvm_cbe_tmp__336__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_995_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @revealSeeds\n");
if (AESL_DEBUG_TRACE)
printf("\n  store i64 0, i64* %%revealedSize, align 8, !dbg !26 for 0x%I64xth hint within @revealSeeds  --> \n", ++aesl_llvm_cbe_938_count);
  *(&llvm_cbe_revealedSize) = 0ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 0ull);
  if ((((unsigned long long )llvm_cbe_outputSize&18446744073709551615ULL) > ((unsigned long long )2147483647ull&18446744073709551615ULL))) {
    llvm_cbe_tmp__336__PHI_TEMPORARY = (unsigned long long )18446744073709551615ull;   /* for PHI node */
    goto llvm_cbe_tmp__337;
  } else {
    goto llvm_cbe_tmp__338;
  }

llvm_cbe_tmp__338:
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = trunc i64 %%outputSize to i32, !dbg !26 for 0x%I64xth hint within @revealSeeds  --> \n", ++aesl_llvm_cbe_941_count);
  llvm_cbe_tmp__315 = (unsigned int )((unsigned int )llvm_cbe_outputSize&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__315);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = call fastcc i64* @aesl_internal_getRevealedNodes(%%struct.tree_t* %%tree, i16* %%hideList, i64 %%hideListSize, i64* %%revealedSize), !dbg !24 for 0x%I64xth hint within @revealSeeds  --> \n", ++aesl_llvm_cbe_945_count);
  llvm_cbe_tmp__316 = (signed long long *)aesl_internal_getRevealedNodes((l_struct_OC_tree_t *)llvm_cbe_tree, (signed short *)llvm_cbe_hideList, llvm_cbe_hideListSize, (signed long long *)(&llvm_cbe_revealedSize));
if (AESL_DEBUG_TRACE) {
printf("\nArgument hideListSize = 0x%I64X",llvm_cbe_hideListSize);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__316);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds %%struct.paramset_t* %%params, i64 0, i32 11, !dbg !26 for 0x%I64xth hint within @revealSeeds  --> \n", ++aesl_llvm_cbe_951_count);
  llvm_cbe_tmp__317 = (signed int *)(&llvm_cbe_params->field11);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds %%struct.tree_t* %%tree, i64 0, i32 1, !dbg !24 for 0x%I64xth hint within @revealSeeds  --> \n", ++aesl_llvm_cbe_952_count);
  llvm_cbe_tmp__318 = ( char ***)(&llvm_cbe_tree->field1);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_tmp__319__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__315;   /* for PHI node */
  llvm_cbe__2e_rec__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  llvm_cbe_storemerge__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__339;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__339:
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = phi i32 [ %%3, %%2 ], [ %%14, %%18  for 0x%I64xth hint within @revealSeeds  --> \n", ++aesl_llvm_cbe_954_count);
  llvm_cbe_tmp__319 = (unsigned int )llvm_cbe_tmp__319__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__319);
printf("\n = 0x%X",llvm_cbe_tmp__315);
printf("\n = 0x%X",llvm_cbe_tmp__323);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec = phi i64 [ 0, %%2 ], [ %%.rec3, %%18  for 0x%I64xth hint within @revealSeeds  --> \n", ++aesl_llvm_cbe__2e_rec_count);
  llvm_cbe__2e_rec = (unsigned long long )llvm_cbe__2e_rec__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.rec = 0x%I64X",llvm_cbe__2e_rec);
printf("\n = 0x%I64X",0ull);
printf("\n.rec3 = 0x%I64X",llvm_cbe__2e_rec3);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge = phi i64 [ 0, %%2 ], [ %%28, %%18  for 0x%I64xth hint within @revealSeeds  --> \n", ++aesl_llvm_cbe_storemerge_count);
  llvm_cbe_storemerge = (unsigned long long )llvm_cbe_storemerge__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge = 0x%I64X",llvm_cbe_storemerge);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__334);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr i8* %%output, i64 %%.re for 0x%I64xth hint within @revealSeeds  --> \n", ++aesl_llvm_cbe_955_count);
  llvm_cbe_tmp__320 = ( char *)(&llvm_cbe_output[(((signed long long )llvm_cbe__2e_rec))]);
if (AESL_DEBUG_TRACE) {
printf("\n.rec = 0x%I64X",((signed long long )llvm_cbe__2e_rec));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = load i64* %%revealedSize, align 8, !dbg !27 for 0x%I64xth hint within @revealSeeds  --> \n", ++aesl_llvm_cbe_965_count);
  llvm_cbe_tmp__321 = (unsigned long long )*(&llvm_cbe_revealedSize);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__321);
  if ((((unsigned long long )llvm_cbe_storemerge&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__321&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__340;
  } else {
    goto llvm_cbe_tmp__341;
  }

llvm_cbe_tmp__342:
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = getelementptr inbounds i64* %%4, i64 %%storemerge, !dbg !24 for 0x%I64xth hint within @revealSeeds  --> \n", ++aesl_llvm_cbe_979_count);
  llvm_cbe_tmp__325 = (signed long long *)(&llvm_cbe_tmp__316[(((signed long long )llvm_cbe_storemerge))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge = 0x%I64X",((signed long long )llvm_cbe_storemerge));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = load i64* %%19, align 8, !dbg !24 for 0x%I64xth hint within @revealSeeds  --> \n", ++aesl_llvm_cbe_980_count);
  llvm_cbe_tmp__326 = (unsigned long long )*llvm_cbe_tmp__325;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__326);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = load i8*** %%6, align 8, !dbg !24 for 0x%I64xth hint within @revealSeeds  --> \n", ++aesl_llvm_cbe_981_count);
  llvm_cbe_tmp__327 = ( char **)*llvm_cbe_tmp__318;
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = getelementptr inbounds i8** %%21, i64 %%20, !dbg !24 for 0x%I64xth hint within @revealSeeds  --> \n", ++aesl_llvm_cbe_982_count);
  llvm_cbe_tmp__328 = ( char **)(&llvm_cbe_tmp__327[(((signed long long )llvm_cbe_tmp__326))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__326));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = load i8** %%22, align 8, !dbg !24 for 0x%I64xth hint within @revealSeeds  --> \n", ++aesl_llvm_cbe_983_count);
  llvm_cbe_tmp__329 = ( char *)*llvm_cbe_tmp__328;
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = zext i32 %%13 to i64, !dbg !24 for 0x%I64xth hint within @revealSeeds  --> \n", ++aesl_llvm_cbe_984_count);
  llvm_cbe_tmp__330 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__322&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__330);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = call i8* @memcpy(i8* %%9, i8* %%23, i64 %%24 for 0x%I64xth hint within @revealSeeds  --> \n", ++aesl_llvm_cbe_985_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__320, ( char *)llvm_cbe_tmp__329, llvm_cbe_tmp__330);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__330);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__331);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = load i32* %%5, align 4, !dbg !25 for 0x%I64xth hint within @revealSeeds  --> \n", ++aesl_llvm_cbe_986_count);
  llvm_cbe_tmp__332 = (unsigned int )*llvm_cbe_tmp__317;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__332);
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = zext i32 %%26 to i64, !dbg !25 for 0x%I64xth hint within @revealSeeds  --> \n", ++aesl_llvm_cbe_987_count);
  llvm_cbe_tmp__333 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__332&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__333);
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec3 = add i64 %%.rec, %%27, !dbg !25 for 0x%I64xth hint within @revealSeeds  --> \n", ++aesl_llvm_cbe__2e_rec3_count);
  llvm_cbe__2e_rec3 = (unsigned long long )((unsigned long long )(llvm_cbe__2e_rec&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__333&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.rec3 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_rec3&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = add i64 %%storemerge, 1, !dbg !27 for 0x%I64xth hint within @revealSeeds  --> \n", ++aesl_llvm_cbe_988_count);
  llvm_cbe_tmp__334 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__334&18446744073709551615ull)));
  llvm_cbe_tmp__319__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__323;   /* for PHI node */
  llvm_cbe__2e_rec__PHI_TEMPORARY = (unsigned long long )llvm_cbe__2e_rec3;   /* for PHI node */
  llvm_cbe_storemerge__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__334;   /* for PHI node */
  goto llvm_cbe_tmp__339;

llvm_cbe_tmp__340:
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = load i32* %%5, align 4, !dbg !26 for 0x%I64xth hint within @revealSeeds  --> \n", ++aesl_llvm_cbe_968_count);
  llvm_cbe_tmp__322 = (unsigned int )*llvm_cbe_tmp__317;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__322);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = sub i32 %%8, %%13, !dbg !26 for 0x%I64xth hint within @revealSeeds  --> \n", ++aesl_llvm_cbe_969_count);
  llvm_cbe_tmp__323 = (unsigned int )((unsigned int )(llvm_cbe_tmp__319&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__322&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__323&4294967295ull)));
  if ((((signed int )llvm_cbe_tmp__323) < ((signed int )0u))) {
    goto llvm_cbe_tmp__343;
  } else {
    goto llvm_cbe_tmp__342;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__343:
if (AESL_DEBUG_TRACE)
printf("\n  call void @_assert(i8* getelementptr inbounds ([53 x i8]* @aesl_internal_.str8, i64 0, i64 0), i8* getelementptr inbounds ([60 x i8]* @aesl_internal_.str1, i64 0, i64 0), i32 321) nounwind, !dbg !27 for 0x%I64xth hint within @revealSeeds  --> \n", ++aesl_llvm_cbe_975_count);
  _assert(( char *)((&aesl_internal__OC_str8[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 53
#endif
])), ( char *)((&aesl_internal__OC_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 60
#endif
])), 321u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",321u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = bitcast i64* %%4 to i8*, !dbg !27 for 0x%I64xth hint within @revealSeeds  --> \n", ++aesl_llvm_cbe_976_count);
  llvm_cbe_tmp__324 = ( char *)(( char *)llvm_cbe_tmp__316);
if (AESL_DEBUG_TRACE)
printf("\n  call void @free(i8* %%17), !dbg !27 for 0x%I64xth hint within @revealSeeds  --> \n", ++aesl_llvm_cbe_977_count);
  free(( char *)llvm_cbe_tmp__324);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_tmp__336__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__337;

llvm_cbe_tmp__341:
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = bitcast i64* %%4 to i8*, !dbg !27 for 0x%I64xth hint within @revealSeeds  --> \n", ++aesl_llvm_cbe_991_count);
  llvm_cbe_tmp__335 = ( char *)(( char *)llvm_cbe_tmp__316);
if (AESL_DEBUG_TRACE)
printf("\n  call void @free(i8* %%30), !dbg !27 for 0x%I64xth hint within @revealSeeds  --> \n", ++aesl_llvm_cbe_992_count);
  free(( char *)llvm_cbe_tmp__335);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_tmp__336__PHI_TEMPORARY = (unsigned long long )llvm_cbe__2e_rec;   /* for PHI node */
  goto llvm_cbe_tmp__337;

llvm_cbe_tmp__337:
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = phi i64 [ %%.rec, %%29 ], [ 0, %%16 ], [ -1, %%0  for 0x%I64xth hint within @revealSeeds  --> \n", ++aesl_llvm_cbe_994_count);
  llvm_cbe_tmp__336 = (unsigned long long )llvm_cbe_tmp__336__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__336);
printf("\n.rec = 0x%I64X",llvm_cbe__2e_rec);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",18446744073709551615ull);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @revealSeeds}\n");
  return llvm_cbe_tmp__336;
}


signed int reconstructSeeds(l_struct_OC_tree_t *llvm_cbe_tree, signed short *llvm_cbe_hideList, signed long long llvm_cbe_hideListSize,  char *llvm_cbe_input, signed long long llvm_cbe_inputLen,  char *llvm_cbe_salt, signed long long llvm_cbe_repIndex, l_struct_OC_paramset_t *llvm_cbe_params) {
  static  unsigned long long aesl_llvm_cbe_revealedSize_count = 0;
  signed long long llvm_cbe_revealedSize;    /* Address-exposed local */
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
  unsigned int llvm_cbe_tmp__344;
  static  unsigned long long aesl_llvm_cbe_1025_count = 0;
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
  signed long long *llvm_cbe_tmp__345;
  static  unsigned long long aesl_llvm_cbe_1037_count = 0;
  static  unsigned long long aesl_llvm_cbe_1038_count = 0;
  static  unsigned long long aesl_llvm_cbe_1039_count = 0;
  static  unsigned long long aesl_llvm_cbe_1040_count = 0;
  static  unsigned long long aesl_llvm_cbe_1041_count = 0;
  static  unsigned long long aesl_llvm_cbe_1042_count = 0;
  signed int *llvm_cbe_tmp__346;
  static  unsigned long long aesl_llvm_cbe_1043_count = 0;
   char ***llvm_cbe_tmp__347;
  static  unsigned long long aesl_llvm_cbe_1044_count = 0;
   char **llvm_cbe_tmp__348;
  static  unsigned long long aesl_llvm_cbe_1045_count = 0;
  static  unsigned long long aesl_llvm_cbe_1046_count = 0;
  unsigned int llvm_cbe_tmp__349;
  unsigned int llvm_cbe_tmp__349__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_rec_count = 0;
  unsigned long long llvm_cbe__2e_rec;
  unsigned long long llvm_cbe__2e_rec__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge_count = 0;
  unsigned long long llvm_cbe_storemerge;
  unsigned long long llvm_cbe_storemerge__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1047_count = 0;
   char *llvm_cbe_tmp__350;
  static  unsigned long long aesl_llvm_cbe_1048_count = 0;
  static  unsigned long long aesl_llvm_cbe_1049_count = 0;
  static  unsigned long long aesl_llvm_cbe_1050_count = 0;
  static  unsigned long long aesl_llvm_cbe_1051_count = 0;
  static  unsigned long long aesl_llvm_cbe_1052_count = 0;
  static  unsigned long long aesl_llvm_cbe_1053_count = 0;
  static  unsigned long long aesl_llvm_cbe_1054_count = 0;
  static  unsigned long long aesl_llvm_cbe_1055_count = 0;
  static  unsigned long long aesl_llvm_cbe_1056_count = 0;
  static  unsigned long long aesl_llvm_cbe_1057_count = 0;
  static  unsigned long long aesl_llvm_cbe_1058_count = 0;
  unsigned long long llvm_cbe_tmp__351;
  static  unsigned long long aesl_llvm_cbe_1059_count = 0;
  static  unsigned long long aesl_llvm_cbe_1060_count = 0;
  static  unsigned long long aesl_llvm_cbe_1061_count = 0;
  unsigned int llvm_cbe_tmp__352;
  static  unsigned long long aesl_llvm_cbe_1062_count = 0;
  unsigned int llvm_cbe_tmp__353;
  static  unsigned long long aesl_llvm_cbe_1063_count = 0;
  static  unsigned long long aesl_llvm_cbe_1064_count = 0;
  static  unsigned long long aesl_llvm_cbe_1065_count = 0;
  static  unsigned long long aesl_llvm_cbe_1066_count = 0;
  static  unsigned long long aesl_llvm_cbe_1067_count = 0;
  static  unsigned long long aesl_llvm_cbe_1068_count = 0;
  signed long long *llvm_cbe_tmp__354;
  static  unsigned long long aesl_llvm_cbe_1069_count = 0;
  unsigned long long llvm_cbe_tmp__355;
  static  unsigned long long aesl_llvm_cbe_1070_count = 0;
   char **llvm_cbe_tmp__356;
  static  unsigned long long aesl_llvm_cbe_1071_count = 0;
   char **llvm_cbe_tmp__357;
  static  unsigned long long aesl_llvm_cbe_1072_count = 0;
   char *llvm_cbe_tmp__358;
  static  unsigned long long aesl_llvm_cbe_1073_count = 0;
  unsigned long long llvm_cbe_tmp__359;
  static  unsigned long long aesl_llvm_cbe_1074_count = 0;
   char *llvm_cbe_tmp__360;
  static  unsigned long long aesl_llvm_cbe_1075_count = 0;
  unsigned long long llvm_cbe_tmp__361;
  static  unsigned long long aesl_llvm_cbe_1076_count = 0;
   char *llvm_cbe_tmp__362;
  static  unsigned long long aesl_llvm_cbe_1077_count = 0;
   char *llvm_cbe_tmp__363;
  static  unsigned long long aesl_llvm_cbe_1078_count = 0;
  static  unsigned long long aesl_llvm_cbe_1079_count = 0;
  unsigned int llvm_cbe_tmp__364;
  static  unsigned long long aesl_llvm_cbe_1080_count = 0;
  unsigned long long llvm_cbe_tmp__365;
  static  unsigned long long aesl_llvm_cbe__2e_rec2_count = 0;
  unsigned long long llvm_cbe__2e_rec2;
  static  unsigned long long aesl_llvm_cbe_1081_count = 0;
  unsigned long long llvm_cbe_tmp__366;
  static  unsigned long long aesl_llvm_cbe_1082_count = 0;
  static  unsigned long long aesl_llvm_cbe_1083_count = 0;
  static  unsigned long long aesl_llvm_cbe_1084_count = 0;
  static  unsigned long long aesl_llvm_cbe_1085_count = 0;
  static  unsigned long long aesl_llvm_cbe_1086_count = 0;
  unsigned int llvm_cbe_tmp__367;
  unsigned int llvm_cbe_tmp__367__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1087_count = 0;
   char *llvm_cbe_tmp__368;
  static  unsigned long long aesl_llvm_cbe_1088_count = 0;
  static  unsigned long long aesl_llvm_cbe_1089_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1090_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @reconstructSeeds\n");
  if ((((unsigned long long )llvm_cbe_inputLen&18446744073709551615ULL) > ((unsigned long long )2147483647ull&18446744073709551615ULL))) {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )4294967295u;   /* for PHI node */
    goto llvm_cbe_tmp__369;
  } else {
    goto llvm_cbe_tmp__370;
  }

llvm_cbe_tmp__370:
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = trunc i64 %%inputLen to i32, !dbg !26 for 0x%I64xth hint within @reconstructSeeds  --> \n", ++aesl_llvm_cbe_1024_count);
  llvm_cbe_tmp__344 = (unsigned int )((unsigned int )llvm_cbe_inputLen&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__344);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 0, i64* %%revealedSize, align 8, !dbg !27 for 0x%I64xth hint within @reconstructSeeds  --> \n", ++aesl_llvm_cbe_1035_count);
  *(&llvm_cbe_revealedSize) = 0ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 0ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = call fastcc i64* @aesl_internal_getRevealedNodes(%%struct.tree_t* %%tree, i16* %%hideList, i64 %%hideListSize, i64* %%revealedSize), !dbg !24 for 0x%I64xth hint within @reconstructSeeds  --> \n", ++aesl_llvm_cbe_1036_count);
  llvm_cbe_tmp__345 = (signed long long *)aesl_internal_getRevealedNodes((l_struct_OC_tree_t *)llvm_cbe_tree, (signed short *)llvm_cbe_hideList, llvm_cbe_hideListSize, (signed long long *)(&llvm_cbe_revealedSize));
if (AESL_DEBUG_TRACE) {
printf("\nArgument hideListSize = 0x%I64X",llvm_cbe_hideListSize);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__345);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds %%struct.paramset_t* %%params, i64 0, i32 11, !dbg !26 for 0x%I64xth hint within @reconstructSeeds  --> \n", ++aesl_llvm_cbe_1042_count);
  llvm_cbe_tmp__346 = (signed int *)(&llvm_cbe_params->field11);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds %%struct.tree_t* %%tree, i64 0, i32 1, !dbg !24 for 0x%I64xth hint within @reconstructSeeds  --> \n", ++aesl_llvm_cbe_1043_count);
  llvm_cbe_tmp__347 = ( char ***)(&llvm_cbe_tree->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds %%struct.tree_t* %%tree, i64 0, i32 3, !dbg !24 for 0x%I64xth hint within @reconstructSeeds  --> \n", ++aesl_llvm_cbe_1044_count);
  llvm_cbe_tmp__348 = ( char **)(&llvm_cbe_tree->field3);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_tmp__349__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__344;   /* for PHI node */
  llvm_cbe__2e_rec__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  llvm_cbe_storemerge__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__371;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__371:
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = phi i32 [ %%3, %%2 ], [ %%15, %%17  for 0x%I64xth hint within @reconstructSeeds  --> \n", ++aesl_llvm_cbe_1046_count);
  llvm_cbe_tmp__349 = (unsigned int )llvm_cbe_tmp__349__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__349);
printf("\n = 0x%X",llvm_cbe_tmp__344);
printf("\n = 0x%X",llvm_cbe_tmp__353);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec = phi i64 [ 0, %%2 ], [ %%.rec2, %%17  for 0x%I64xth hint within @reconstructSeeds  --> \n", ++aesl_llvm_cbe__2e_rec_count);
  llvm_cbe__2e_rec = (unsigned long long )llvm_cbe__2e_rec__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.rec = 0x%I64X",llvm_cbe__2e_rec);
printf("\n = 0x%I64X",0ull);
printf("\n.rec2 = 0x%I64X",llvm_cbe__2e_rec2);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge = phi i64 [ 0, %%2 ], [ %%30, %%17  for 0x%I64xth hint within @reconstructSeeds  --> \n", ++aesl_llvm_cbe_storemerge_count);
  llvm_cbe_storemerge = (unsigned long long )llvm_cbe_storemerge__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge = 0x%I64X",llvm_cbe_storemerge);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__366);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr i8* %%input, i64 %%.re for 0x%I64xth hint within @reconstructSeeds  --> \n", ++aesl_llvm_cbe_1047_count);
  llvm_cbe_tmp__350 = ( char *)(&llvm_cbe_input[(((signed long long )llvm_cbe__2e_rec))]);
if (AESL_DEBUG_TRACE) {
printf("\n.rec = 0x%I64X",((signed long long )llvm_cbe__2e_rec));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = load i64* %%revealedSize, align 8, !dbg !28 for 0x%I64xth hint within @reconstructSeeds  --> \n", ++aesl_llvm_cbe_1058_count);
  llvm_cbe_tmp__351 = (unsigned long long )*(&llvm_cbe_revealedSize);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__351);
  if ((((unsigned long long )llvm_cbe_storemerge&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__351&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__372;
  } else {
    goto llvm_cbe_tmp__373;
  }

llvm_cbe_tmp__374:
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = getelementptr inbounds i64* %%4, i64 %%storemerge, !dbg !24 for 0x%I64xth hint within @reconstructSeeds  --> \n", ++aesl_llvm_cbe_1068_count);
  llvm_cbe_tmp__354 = (signed long long *)(&llvm_cbe_tmp__345[(((signed long long )llvm_cbe_storemerge))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge = 0x%I64X",((signed long long )llvm_cbe_storemerge));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = load i64* %%18, align 8, !dbg !24 for 0x%I64xth hint within @reconstructSeeds  --> \n", ++aesl_llvm_cbe_1069_count);
  llvm_cbe_tmp__355 = (unsigned long long )*llvm_cbe_tmp__354;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__355);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = load i8*** %%6, align 8, !dbg !24 for 0x%I64xth hint within @reconstructSeeds  --> \n", ++aesl_llvm_cbe_1070_count);
  llvm_cbe_tmp__356 = ( char **)*llvm_cbe_tmp__347;
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = getelementptr inbounds i8** %%20, i64 %%19, !dbg !24 for 0x%I64xth hint within @reconstructSeeds  --> \n", ++aesl_llvm_cbe_1071_count);
  llvm_cbe_tmp__357 = ( char **)(&llvm_cbe_tmp__356[(((signed long long )llvm_cbe_tmp__355))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__355));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = load i8** %%21, align 8, !dbg !24 for 0x%I64xth hint within @reconstructSeeds  --> \n", ++aesl_llvm_cbe_1072_count);
  llvm_cbe_tmp__358 = ( char *)*llvm_cbe_tmp__357;
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = zext i32 %%14 to i64, !dbg !24 for 0x%I64xth hint within @reconstructSeeds  --> \n", ++aesl_llvm_cbe_1073_count);
  llvm_cbe_tmp__359 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__352&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__359);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = call i8* @memcpy(i8* %%22, i8* %%10, i64 %%23 for 0x%I64xth hint within @reconstructSeeds  --> \n", ++aesl_llvm_cbe_1074_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__358, ( char *)llvm_cbe_tmp__350, llvm_cbe_tmp__359);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__359);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__360);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = load i64* %%18, align 8, !dbg !24 for 0x%I64xth hint within @reconstructSeeds  --> \n", ++aesl_llvm_cbe_1075_count);
  llvm_cbe_tmp__361 = (unsigned long long )*llvm_cbe_tmp__354;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__361);
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = load i8** %%7, align 8, !dbg !24 for 0x%I64xth hint within @reconstructSeeds  --> \n", ++aesl_llvm_cbe_1076_count);
  llvm_cbe_tmp__362 = ( char *)*llvm_cbe_tmp__348;
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = getelementptr inbounds i8* %%26, i64 %%25, !dbg !24 for 0x%I64xth hint within @reconstructSeeds  --> \n", ++aesl_llvm_cbe_1077_count);
  llvm_cbe_tmp__363 = ( char *)(&llvm_cbe_tmp__362[(((signed long long )llvm_cbe_tmp__361))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__361));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 1, i8* %%27, align 1, !dbg !24 for 0x%I64xth hint within @reconstructSeeds  --> \n", ++aesl_llvm_cbe_1078_count);
  *llvm_cbe_tmp__363 = ((unsigned char )1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )1));
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = load i32* %%5, align 4, !dbg !25 for 0x%I64xth hint within @reconstructSeeds  --> \n", ++aesl_llvm_cbe_1079_count);
  llvm_cbe_tmp__364 = (unsigned int )*llvm_cbe_tmp__346;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__364);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = zext i32 %%28 to i64, !dbg !25 for 0x%I64xth hint within @reconstructSeeds  --> \n", ++aesl_llvm_cbe_1080_count);
  llvm_cbe_tmp__365 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__364&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__365);
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec2 = add i64 %%.rec, %%29, !dbg !25 for 0x%I64xth hint within @reconstructSeeds  --> \n", ++aesl_llvm_cbe__2e_rec2_count);
  llvm_cbe__2e_rec2 = (unsigned long long )((unsigned long long )(llvm_cbe__2e_rec&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__365&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.rec2 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_rec2&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = add i64 %%storemerge, 1, !dbg !28 for 0x%I64xth hint within @reconstructSeeds  --> \n", ++aesl_llvm_cbe_1081_count);
  llvm_cbe_tmp__366 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__366&18446744073709551615ull)));
  llvm_cbe_tmp__349__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__353;   /* for PHI node */
  llvm_cbe__2e_rec__PHI_TEMPORARY = (unsigned long long )llvm_cbe__2e_rec2;   /* for PHI node */
  llvm_cbe_storemerge__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__366;   /* for PHI node */
  goto llvm_cbe_tmp__371;

llvm_cbe_tmp__372:
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load i32* %%5, align 4, !dbg !26 for 0x%I64xth hint within @reconstructSeeds  --> \n", ++aesl_llvm_cbe_1061_count);
  llvm_cbe_tmp__352 = (unsigned int )*llvm_cbe_tmp__346;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__352);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = sub i32 %%9, %%14, !dbg !26 for 0x%I64xth hint within @reconstructSeeds  --> \n", ++aesl_llvm_cbe_1062_count);
  llvm_cbe_tmp__353 = (unsigned int )((unsigned int )(llvm_cbe_tmp__349&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__352&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__353&4294967295ull)));
  if ((((signed int )llvm_cbe_tmp__353) < ((signed int )0u))) {
    llvm_cbe_tmp__367__PHI_TEMPORARY = (unsigned int )4294967295u;   /* for PHI node */
    goto llvm_cbe__2e_loopexit;
  } else {
    goto llvm_cbe_tmp__374;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__373:
if (AESL_DEBUG_TRACE)
printf("\n  call void @expandSeeds(%%struct.tree_t* %%tree, i8* %%salt, i64 %%repIndex, %%struct.paramset_t* %%params), !dbg !25 for 0x%I64xth hint within @reconstructSeeds  --> \n", ++aesl_llvm_cbe_1084_count);
  expandSeeds((l_struct_OC_tree_t *)llvm_cbe_tree, ( char *)llvm_cbe_salt, llvm_cbe_repIndex, (l_struct_OC_paramset_t *)llvm_cbe_params);
if (AESL_DEBUG_TRACE) {
printf("\nArgument repIndex = 0x%I64X",llvm_cbe_repIndex);
}
  llvm_cbe_tmp__367__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_loopexit;

llvm_cbe__2e_loopexit:
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = phi i32 [ 0, %%31 ], [ -1, %%13  for 0x%I64xth hint within @reconstructSeeds  --> \n", ++aesl_llvm_cbe_1086_count);
  llvm_cbe_tmp__367 = (unsigned int )llvm_cbe_tmp__367__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__367);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",4294967295u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = bitcast i64* %%4 to i8*, !dbg !27 for 0x%I64xth hint within @reconstructSeeds  --> \n", ++aesl_llvm_cbe_1087_count);
  llvm_cbe_tmp__368 = ( char *)(( char *)llvm_cbe_tmp__345);
if (AESL_DEBUG_TRACE)
printf("\n  call void @free(i8* %%33), !dbg !27 for 0x%I64xth hint within @reconstructSeeds  --> \n", ++aesl_llvm_cbe_1088_count);
  free(( char *)llvm_cbe_tmp__368);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__367;   /* for PHI node */
  goto llvm_cbe_tmp__369;

llvm_cbe_tmp__369:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ %%32, %%.loopexit ], [ -1, %%0  for 0x%I64xth hint within @reconstructSeeds  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",llvm_cbe_tmp__367);
printf("\n = 0x%X",4294967295u);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @reconstructSeeds}\n");
  return llvm_cbe_storemerge1;
}


void buildMerkleTree(l_struct_OC_tree_t *llvm_cbe_tree,  char **llvm_cbe_leafData,  char *llvm_cbe_salt, l_struct_OC_paramset_t *llvm_cbe_params) {
  static  unsigned long long aesl_llvm_cbe_1091_count = 0;
  static  unsigned long long aesl_llvm_cbe_1092_count = 0;
  static  unsigned long long aesl_llvm_cbe_1093_count = 0;
  static  unsigned long long aesl_llvm_cbe_1094_count = 0;
  static  unsigned long long aesl_llvm_cbe_1095_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_1107_count = 0;
  signed long long *llvm_cbe_tmp__375;
  static  unsigned long long aesl_llvm_cbe_1108_count = 0;
  unsigned long long llvm_cbe_tmp__376;
  static  unsigned long long aesl_llvm_cbe_1109_count = 0;
  signed long long *llvm_cbe_tmp__377;
  static  unsigned long long aesl_llvm_cbe_1110_count = 0;
  unsigned long long llvm_cbe_tmp__378;
  static  unsigned long long aesl_llvm_cbe_1111_count = 0;
  unsigned long long llvm_cbe_tmp__379;
  static  unsigned long long aesl_llvm_cbe_1112_count = 0;
  static  unsigned long long aesl_llvm_cbe_1113_count = 0;
  static  unsigned long long aesl_llvm_cbe_1114_count = 0;
  static  unsigned long long aesl_llvm_cbe_1115_count = 0;
  static  unsigned long long aesl_llvm_cbe_1116_count = 0;
  static  unsigned long long aesl_llvm_cbe_1117_count = 0;
  static  unsigned long long aesl_llvm_cbe_1118_count = 0;
  static  unsigned long long aesl_llvm_cbe_1119_count = 0;
  static  unsigned long long aesl_llvm_cbe_1120_count = 0;
  static  unsigned long long aesl_llvm_cbe_1121_count = 0;
  static  unsigned long long aesl_llvm_cbe_1122_count = 0;
  static  unsigned long long aesl_llvm_cbe_1123_count = 0;
  static  unsigned long long aesl_llvm_cbe_1124_count = 0;
  static  unsigned long long aesl_llvm_cbe_1125_count = 0;
  static  unsigned long long aesl_llvm_cbe_1126_count = 0;
  static  unsigned long long aesl_llvm_cbe_1127_count = 0;
   char ***llvm_cbe_tmp__380;
  static  unsigned long long aesl_llvm_cbe_1128_count = 0;
  signed long long *llvm_cbe_tmp__381;
  static  unsigned long long aesl_llvm_cbe_1129_count = 0;
   char **llvm_cbe_tmp__382;
  static  unsigned long long aesl_llvm_cbe_1130_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned long long llvm_cbe_storemerge3;
  unsigned long long llvm_cbe_storemerge3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1131_count = 0;
   char **llvm_cbe_tmp__383;
  static  unsigned long long aesl_llvm_cbe_1132_count = 0;
   char *llvm_cbe_tmp__384;
  static  unsigned long long aesl_llvm_cbe_1133_count = 0;
  static  unsigned long long aesl_llvm_cbe_1134_count = 0;
  static  unsigned long long aesl_llvm_cbe_1135_count = 0;
  unsigned long long llvm_cbe_tmp__385;
  static  unsigned long long aesl_llvm_cbe_1136_count = 0;
   char **llvm_cbe_tmp__386;
  static  unsigned long long aesl_llvm_cbe_1137_count = 0;
   char **llvm_cbe_tmp__387;
  static  unsigned long long aesl_llvm_cbe_1138_count = 0;
   char *llvm_cbe_tmp__388;
  static  unsigned long long aesl_llvm_cbe_1139_count = 0;
  unsigned long long llvm_cbe_tmp__389;
  static  unsigned long long aesl_llvm_cbe_1140_count = 0;
   char *llvm_cbe_tmp__390;
  static  unsigned long long aesl_llvm_cbe_1141_count = 0;
   char *llvm_cbe_tmp__391;
  static  unsigned long long aesl_llvm_cbe_1142_count = 0;
   char *llvm_cbe_tmp__392;
  static  unsigned long long aesl_llvm_cbe_1143_count = 0;
  static  unsigned long long aesl_llvm_cbe_1144_count = 0;
  static  unsigned long long aesl_llvm_cbe_1145_count = 0;
  unsigned long long llvm_cbe_tmp__393;
  static  unsigned long long aesl_llvm_cbe_1146_count = 0;
  static  unsigned long long aesl_llvm_cbe_1147_count = 0;
  static  unsigned long long aesl_llvm_cbe_1148_count = 0;
  static  unsigned long long aesl_llvm_cbe_1149_count = 0;
  static  unsigned long long aesl_llvm_cbe_1150_count = 0;
  static  unsigned long long aesl_llvm_cbe_1151_count = 0;
  static  unsigned long long aesl_llvm_cbe_1152_count = 0;
  static  unsigned long long aesl_llvm_cbe_1153_count = 0;
  static  unsigned long long aesl_llvm_cbe_1154_count = 0;
  static  unsigned long long aesl_llvm_cbe_1155_count = 0;
  static  unsigned long long aesl_llvm_cbe_1156_count = 0;
  unsigned long long llvm_cbe_tmp__394;
  static  unsigned long long aesl_llvm_cbe_1157_count = 0;
  static  unsigned long long aesl_llvm_cbe_1158_count = 0;
  static  unsigned long long aesl_llvm_cbe_1159_count = 0;
  unsigned long long llvm_cbe_tmp__395;
  static  unsigned long long aesl_llvm_cbe_1160_count = 0;
  unsigned int llvm_cbe_tmp__396;
  static  unsigned long long aesl_llvm_cbe_1161_count = 0;
  unsigned long long llvm_cbe_tmp__397;
  static  unsigned long long aesl_llvm_cbe_1162_count = 0;
  static  unsigned long long aesl_llvm_cbe_1163_count = 0;
  static  unsigned long long aesl_llvm_cbe_1164_count = 0;
  static  unsigned long long aesl_llvm_cbe_1165_count = 0;
  static  unsigned long long aesl_llvm_cbe_1166_count = 0;
  static  unsigned long long aesl_llvm_cbe_1167_count = 0;
  static  unsigned long long aesl_llvm_cbe_1168_count = 0;
  static  unsigned long long aesl_llvm_cbe_1169_count = 0;
  static  unsigned long long aesl_llvm_cbe_1170_count = 0;
  static  unsigned long long aesl_llvm_cbe_1171_count = 0;
  static  unsigned long long aesl_llvm_cbe_1172_count = 0;
  static  unsigned long long aesl_llvm_cbe_1173_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_count = 0;
  unsigned long long llvm_cbe_storemerge12;
  unsigned long long llvm_cbe_storemerge12__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1174_count = 0;
  static  unsigned long long aesl_llvm_cbe_1175_count = 0;
  unsigned long long llvm_cbe_tmp__398;
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

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @buildMerkleTree\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.tree_t* %%tree, i64 0, i32 5, !dbg !24 for 0x%I64xth hint within @buildMerkleTree  --> \n", ++aesl_llvm_cbe_1107_count);
  llvm_cbe_tmp__375 = (signed long long *)(&llvm_cbe_tree->field5);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i64* %%1, align 8, !dbg !24 for 0x%I64xth hint within @buildMerkleTree  --> \n", ++aesl_llvm_cbe_1108_count);
  llvm_cbe_tmp__376 = (unsigned long long )*llvm_cbe_tmp__375;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__376);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.tree_t* %%tree, i64 0, i32 6, !dbg !24 for 0x%I64xth hint within @buildMerkleTree  --> \n", ++aesl_llvm_cbe_1109_count);
  llvm_cbe_tmp__377 = (signed long long *)(&llvm_cbe_tree->field6);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i64* %%3, align 8, !dbg !24 for 0x%I64xth hint within @buildMerkleTree  --> \n", ++aesl_llvm_cbe_1110_count);
  llvm_cbe_tmp__378 = (unsigned long long )*llvm_cbe_tmp__377;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__378);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = sub i64 %%2, %%4, !dbg !24 for 0x%I64xth hint within @buildMerkleTree  --> \n", ++aesl_llvm_cbe_1111_count);
  llvm_cbe_tmp__379 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__376&18446744073709551615ull)) - ((unsigned long long )(llvm_cbe_tmp__378&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__379&18446744073709551615ull)));
  if (((llvm_cbe_tmp__378&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge6;
  } else {
    goto llvm_cbe__2e_lr_2e_ph5;
  }

llvm_cbe__2e_lr_2e_ph5:
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds %%struct.tree_t* %%tree, i64 0, i32 1, !dbg !24 for 0x%I64xth hint within @buildMerkleTree  --> \n", ++aesl_llvm_cbe_1127_count);
  llvm_cbe_tmp__380 = ( char ***)(&llvm_cbe_tree->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds %%struct.tree_t* %%tree, i64 0, i32 2, !dbg !24 for 0x%I64xth hint within @buildMerkleTree  --> \n", ++aesl_llvm_cbe_1128_count);
  llvm_cbe_tmp__381 = (signed long long *)(&llvm_cbe_tree->field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds %%struct.tree_t* %%tree, i64 0, i32 3, !dbg !25 for 0x%I64xth hint within @buildMerkleTree  --> \n", ++aesl_llvm_cbe_1129_count);
  llvm_cbe_tmp__382 = ( char **)(&llvm_cbe_tree->field3);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__399;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__399:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = phi i64 [ 0, %%.lr.ph5 ], [ %%24, %%23  for 0x%I64xth hint within @buildMerkleTree  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned long long )llvm_cbe_storemerge3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%I64X",llvm_cbe_storemerge3);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__393);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds i8** %%leafData, i64 %%storemerge3, !dbg !25 for 0x%I64xth hint within @buildMerkleTree  --> \n", ++aesl_llvm_cbe_1131_count);
  llvm_cbe_tmp__383 = ( char **)(&llvm_cbe_leafData[(((signed long long )llvm_cbe_storemerge3))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%I64X",((signed long long )llvm_cbe_storemerge3));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = load i8** %%11, align 8, !dbg !25 for 0x%I64xth hint within @buildMerkleTree  --> \n", ++aesl_llvm_cbe_1132_count);
  llvm_cbe_tmp__384 = ( char *)*llvm_cbe_tmp__383;
  if (((llvm_cbe_tmp__384) == ((( char *)/*NULL*/0)))) {
    goto llvm_cbe_tmp__400;
  } else {
    goto llvm_cbe_tmp__401;
  }

llvm_cbe_tmp__400:
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = add i64 %%storemerge3, 1, !dbg !26 for 0x%I64xth hint within @buildMerkleTree  --> \n", ++aesl_llvm_cbe_1145_count);
  llvm_cbe_tmp__393 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge3&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__393&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = load i64* %%3, align 8, !dbg !24 for 0x%I64xth hint within @buildMerkleTree  --> \n", ++aesl_llvm_cbe_1156_count);
  llvm_cbe_tmp__394 = (unsigned long long )*llvm_cbe_tmp__377;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__394);
  if ((((unsigned long long )llvm_cbe_tmp__393&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__394&18446744073709551615ULL))) {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__393;   /* for PHI node */
    goto llvm_cbe_tmp__399;
  } else {
    goto llvm_cbe__2e__crit_edge6;
  }

llvm_cbe_tmp__401:
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = add i64 %%storemerge3, %%5, !dbg !24 for 0x%I64xth hint within @buildMerkleTree  --> \n", ++aesl_llvm_cbe_1135_count);
  llvm_cbe_tmp__385 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge3&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__379&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__385&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = load i8*** %%7, align 8, !dbg !24 for 0x%I64xth hint within @buildMerkleTree  --> \n", ++aesl_llvm_cbe_1136_count);
  llvm_cbe_tmp__386 = ( char **)*llvm_cbe_tmp__380;
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds i8** %%16, i64 %%15, !dbg !24 for 0x%I64xth hint within @buildMerkleTree  --> \n", ++aesl_llvm_cbe_1137_count);
  llvm_cbe_tmp__387 = ( char **)(&llvm_cbe_tmp__386[(((signed long long )llvm_cbe_tmp__385))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__385));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = load i8** %%17, align 8, !dbg !24 for 0x%I64xth hint within @buildMerkleTree  --> \n", ++aesl_llvm_cbe_1138_count);
  llvm_cbe_tmp__388 = ( char *)*llvm_cbe_tmp__387;
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = load i64* %%8, align 8, !dbg !24 for 0x%I64xth hint within @buildMerkleTree  --> \n", ++aesl_llvm_cbe_1139_count);
  llvm_cbe_tmp__389 = (unsigned long long )*llvm_cbe_tmp__381;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__389);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = call i8* @memcpy(i8* %%18, i8* %%12, i64 %%19 for 0x%I64xth hint within @buildMerkleTree  --> \n", ++aesl_llvm_cbe_1140_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__388, ( char *)llvm_cbe_tmp__384, llvm_cbe_tmp__389);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__389);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__390);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = load i8** %%9, align 8, !dbg !25 for 0x%I64xth hint within @buildMerkleTree  --> \n", ++aesl_llvm_cbe_1141_count);
  llvm_cbe_tmp__391 = ( char *)*llvm_cbe_tmp__382;
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = getelementptr inbounds i8* %%21, i64 %%15, !dbg !25 for 0x%I64xth hint within @buildMerkleTree  --> \n", ++aesl_llvm_cbe_1142_count);
  llvm_cbe_tmp__392 = ( char *)(&llvm_cbe_tmp__391[(((signed long long )llvm_cbe_tmp__385))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__385));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 1, i8* %%22, align 1, !dbg !25 for 0x%I64xth hint within @buildMerkleTree  --> \n", ++aesl_llvm_cbe_1143_count);
  *llvm_cbe_tmp__392 = ((unsigned char )1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )1));
  goto llvm_cbe_tmp__400;

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e__crit_edge6:
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = load i64* %%1, align 8, !dbg !25 for 0x%I64xth hint within @buildMerkleTree  --> \n", ++aesl_llvm_cbe_1159_count);
  llvm_cbe_tmp__395 = (unsigned long long )*llvm_cbe_tmp__375;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__395);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = trunc i64 %%27 to i32, !dbg !25 for 0x%I64xth hint within @buildMerkleTree  --> \n", ++aesl_llvm_cbe_1160_count);
  llvm_cbe_tmp__396 = (unsigned int )((unsigned int )llvm_cbe_tmp__395&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__396);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = sext i32 %%28 to i64, !dbg !25 for 0x%I64xth hint within @buildMerkleTree  --> \n", ++aesl_llvm_cbe_1161_count);
  llvm_cbe_tmp__397 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__396);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__397);
  if (((llvm_cbe_tmp__396&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__397;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12 = phi i64 [ %%31, %%.lr.ph ], [ %%29, %%._crit_edge6  for 0x%I64xth hint within @buildMerkleTree  --> \n", ++aesl_llvm_cbe_storemerge12_count);
  llvm_cbe_storemerge12 = (unsigned long long )llvm_cbe_storemerge12__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%I64X",llvm_cbe_storemerge12);
printf("\n = 0x%I64X",llvm_cbe_tmp__398);
printf("\n = 0x%I64X",llvm_cbe_tmp__397);
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call fastcc void @aesl_internal_computeParentHash(%%struct.tree_t* %%tree, i64 %%storemerge12, i8* %%salt, %%struct.paramset_t* %%params), !dbg !25 for 0x%I64xth hint within @buildMerkleTree  --> \n", ++aesl_llvm_cbe_1174_count);
   /*tail*/ aesl_internal_computeParentHash((l_struct_OC_tree_t *)llvm_cbe_tree, llvm_cbe_storemerge12, ( char *)llvm_cbe_salt, (l_struct_OC_paramset_t *)llvm_cbe_params);
if (AESL_DEBUG_TRACE) {
printf("\nArgument storemerge12 = 0x%I64X",llvm_cbe_storemerge12);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = add i64 %%storemerge12, -1, !dbg !26 for 0x%I64xth hint within @buildMerkleTree  --> \n", ++aesl_llvm_cbe_1175_count);
  llvm_cbe_tmp__398 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge12&18446744073709551615ull)) + ((unsigned long long )(18446744073709551615ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__398&18446744073709551615ull)));
  if (((llvm_cbe_tmp__398&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__398;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @buildMerkleTree}\n");
  return;
}


static void aesl_internal_computeParentHash(l_struct_OC_tree_t *llvm_cbe_tree, signed long long llvm_cbe_child,  char *llvm_cbe_salt, l_struct_OC_paramset_t *llvm_cbe_params) {
  static  unsigned long long aesl_llvm_cbe_ctx_count = 0;
  l_struct_OC_Keccak_HashInstance llvm_cbe_ctx;    /* Address-exposed local */
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
  unsigned int llvm_cbe_tmp__402;
  static  unsigned long long aesl_llvm_cbe_1212_count = 0;
  static  unsigned long long aesl_llvm_cbe_1213_count = 0;
  static  unsigned long long aesl_llvm_cbe_1214_count = 0;
  unsigned long long llvm_cbe_tmp__403;
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
   char **llvm_cbe_tmp__404;
  static  unsigned long long aesl_llvm_cbe_1227_count = 0;
   char *llvm_cbe_tmp__405;
  static  unsigned long long aesl_llvm_cbe_1228_count = 0;
   char *llvm_cbe_tmp__406;
  static  unsigned long long aesl_llvm_cbe_1229_count = 0;
  unsigned char llvm_cbe_tmp__407;
  static  unsigned long long aesl_llvm_cbe_1230_count = 0;
  static  unsigned long long aesl_llvm_cbe_1231_count = 0;
  static  unsigned long long aesl_llvm_cbe_1232_count = 0;
  unsigned long long llvm_cbe_tmp__408;
  static  unsigned long long aesl_llvm_cbe_1233_count = 0;
  unsigned long long llvm_cbe_tmp__409;
  static  unsigned long long aesl_llvm_cbe_1234_count = 0;
   char *llvm_cbe_tmp__410;
  static  unsigned long long aesl_llvm_cbe_1235_count = 0;
  unsigned char llvm_cbe_tmp__411;
  static  unsigned long long aesl_llvm_cbe_1236_count = 0;
  static  unsigned long long aesl_llvm_cbe_1237_count = 0;
  static  unsigned long long aesl_llvm_cbe_1238_count = 0;
  unsigned long long llvm_cbe_tmp__412;
  static  unsigned long long aesl_llvm_cbe_1239_count = 0;
  unsigned int llvm_cbe_tmp__413;
  static  unsigned long long aesl_llvm_cbe_1240_count = 0;
  static  unsigned long long aesl_llvm_cbe_1241_count = 0;
  static  unsigned long long aesl_llvm_cbe_1242_count = 0;
   char *llvm_cbe_tmp__414;
  static  unsigned long long aesl_llvm_cbe_1243_count = 0;
  unsigned char llvm_cbe_tmp__415;
  static  unsigned long long aesl_llvm_cbe_1244_count = 0;
  static  unsigned long long aesl_llvm_cbe_1245_count = 0;
  static  unsigned long long aesl_llvm_cbe_1246_count = 0;
  static  unsigned long long aesl_llvm_cbe_1247_count = 0;
  static  unsigned long long aesl_llvm_cbe_1248_count = 0;
   char ***llvm_cbe_tmp__416;
  static  unsigned long long aesl_llvm_cbe_1249_count = 0;
   char **llvm_cbe_tmp__417;
  static  unsigned long long aesl_llvm_cbe_1250_count = 0;
   char **llvm_cbe_tmp__418;
  static  unsigned long long aesl_llvm_cbe_1251_count = 0;
   char *llvm_cbe_tmp__419;
  static  unsigned long long aesl_llvm_cbe_1252_count = 0;
  signed int *llvm_cbe_tmp__420;
  static  unsigned long long aesl_llvm_cbe_1253_count = 0;
  unsigned int llvm_cbe_tmp__421;
  static  unsigned long long aesl_llvm_cbe_1254_count = 0;
  unsigned long long llvm_cbe_tmp__422;
  static  unsigned long long aesl_llvm_cbe_1255_count = 0;
  static  unsigned long long aesl_llvm_cbe_1256_count = 0;
  unsigned int llvm_cbe_tmp__423;
  static  unsigned long long aesl_llvm_cbe_1257_count = 0;
  static  unsigned long long aesl_llvm_cbe_1258_count = 0;
  static  unsigned long long aesl_llvm_cbe_1259_count = 0;
   char **llvm_cbe_tmp__424;
  static  unsigned long long aesl_llvm_cbe_1260_count = 0;
   char **llvm_cbe_tmp__425;
  static  unsigned long long aesl_llvm_cbe_1261_count = 0;
   char *llvm_cbe_tmp__426;
  static  unsigned long long aesl_llvm_cbe_1262_count = 0;
  unsigned int llvm_cbe_tmp__427;
  static  unsigned long long aesl_llvm_cbe_1263_count = 0;
  unsigned long long llvm_cbe_tmp__428;
  static  unsigned long long aesl_llvm_cbe_1264_count = 0;
  static  unsigned long long aesl_llvm_cbe_1265_count = 0;
  static  unsigned long long aesl_llvm_cbe_1266_count = 0;
  signed int *llvm_cbe_tmp__429;
  static  unsigned long long aesl_llvm_cbe_1267_count = 0;
  unsigned int llvm_cbe_tmp__430;
  static  unsigned long long aesl_llvm_cbe_1268_count = 0;
  unsigned long long llvm_cbe_tmp__431;
  static  unsigned long long aesl_llvm_cbe_1269_count = 0;
  static  unsigned long long aesl_llvm_cbe_1270_count = 0;
  unsigned short llvm_cbe_tmp__432;
  static  unsigned long long aesl_llvm_cbe_1271_count = 0;
  static  unsigned long long aesl_llvm_cbe_1272_count = 0;
  static  unsigned long long aesl_llvm_cbe_1273_count = 0;
   char **llvm_cbe_tmp__433;
  static  unsigned long long aesl_llvm_cbe_1274_count = 0;
   char **llvm_cbe_tmp__434;
  static  unsigned long long aesl_llvm_cbe_1275_count = 0;
   char *llvm_cbe_tmp__435;
  static  unsigned long long aesl_llvm_cbe_1276_count = 0;
  unsigned int llvm_cbe_tmp__436;
  static  unsigned long long aesl_llvm_cbe_1277_count = 0;
  unsigned long long llvm_cbe_tmp__437;
  static  unsigned long long aesl_llvm_cbe_1278_count = 0;
  static  unsigned long long aesl_llvm_cbe_1279_count = 0;
   char *llvm_cbe_tmp__438;
  static  unsigned long long aesl_llvm_cbe_1280_count = 0;
   char *llvm_cbe_tmp__439;
  static  unsigned long long aesl_llvm_cbe_1281_count = 0;
  static  unsigned long long aesl_llvm_cbe_1282_count = 0;
  static  unsigned long long aesl_llvm_cbe_1283_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @aesl_internal_computeParentHash\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = call i32 @exists(%%struct.tree_t* %%tree, i64 %%child), !dbg !24 for 0x%I64xth hint within @aesl_internal_computeParentHash  --> \n", ++aesl_llvm_cbe_1211_count);
  llvm_cbe_tmp__402 = (unsigned int )exists((l_struct_OC_tree_t *)llvm_cbe_tree, llvm_cbe_child);
if (AESL_DEBUG_TRACE) {
printf("\nArgument child = 0x%I64X",llvm_cbe_child);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__402);
}
  if (((llvm_cbe_tmp__402&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__440;
  } else {
    goto llvm_cbe_tmp__441;
  }

llvm_cbe_tmp__441:
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = call i64 @getParent(i64 %%child), !dbg !25 for 0x%I64xth hint within @aesl_internal_computeParentHash  --> \n", ++aesl_llvm_cbe_1214_count);
  llvm_cbe_tmp__403 = (unsigned long long )getParent(llvm_cbe_child);
if (AESL_DEBUG_TRACE) {
printf("\nArgument child = 0x%I64X",llvm_cbe_child);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__403);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds %%struct.tree_t* %%tree, i64 0, i32 3, !dbg !24 for 0x%I64xth hint within @aesl_internal_computeParentHash  --> \n", ++aesl_llvm_cbe_1226_count);
  llvm_cbe_tmp__404 = ( char **)(&llvm_cbe_tree->field3);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load i8** %%5, align 8, !dbg !24 for 0x%I64xth hint within @aesl_internal_computeParentHash  --> \n", ++aesl_llvm_cbe_1227_count);
  llvm_cbe_tmp__405 = ( char *)*llvm_cbe_tmp__404;
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds i8* %%6, i64 %%4, !dbg !24 for 0x%I64xth hint within @aesl_internal_computeParentHash  --> \n", ++aesl_llvm_cbe_1228_count);
  llvm_cbe_tmp__406 = ( char *)(&llvm_cbe_tmp__405[(((signed long long )llvm_cbe_tmp__403))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__403));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load i8* %%7, align 1, !dbg !24 for 0x%I64xth hint within @aesl_internal_computeParentHash  --> \n", ++aesl_llvm_cbe_1229_count);
  llvm_cbe_tmp__407 = (unsigned char )*llvm_cbe_tmp__406;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__407);
  if (((llvm_cbe_tmp__407&255U) == (((unsigned char )0)&255U))) {
    goto llvm_cbe_tmp__442;
  } else {
    goto llvm_cbe_tmp__440;
  }

llvm_cbe_tmp__442:
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = shl i64 %%4, 1, !dbg !24 for 0x%I64xth hint within @aesl_internal_computeParentHash  --> \n", ++aesl_llvm_cbe_1232_count);
  llvm_cbe_tmp__408 = (unsigned long long )llvm_cbe_tmp__403 << 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__408);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = or i64 %%11, 1, !dbg !24 for 0x%I64xth hint within @aesl_internal_computeParentHash  --> \n", ++aesl_llvm_cbe_1233_count);
  llvm_cbe_tmp__409 = (unsigned long long )llvm_cbe_tmp__408 | 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__409);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds i8* %%6, i64 %%12, !dbg !24 for 0x%I64xth hint within @aesl_internal_computeParentHash  --> \n", ++aesl_llvm_cbe_1234_count);
  llvm_cbe_tmp__410 = ( char *)(&llvm_cbe_tmp__405[(((signed long long )llvm_cbe_tmp__409))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__409));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load i8* %%13, align 1, !dbg !24 for 0x%I64xth hint within @aesl_internal_computeParentHash  --> \n", ++aesl_llvm_cbe_1235_count);
  llvm_cbe_tmp__411 = (unsigned char )*llvm_cbe_tmp__410;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__411);
  if (((llvm_cbe_tmp__411&255U) == (((unsigned char )0)&255U))) {
    goto llvm_cbe_tmp__440;
  } else {
    goto llvm_cbe_tmp__443;
  }

llvm_cbe_tmp__443:
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = add i64 %%11, 2, !dbg !24 for 0x%I64xth hint within @aesl_internal_computeParentHash  --> \n", ++aesl_llvm_cbe_1238_count);
  llvm_cbe_tmp__412 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__408&18446744073709551615ull)) + ((unsigned long long )(2ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__412&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = call i32 @exists(%%struct.tree_t* %%tree, i64 %%17), !dbg !24 for 0x%I64xth hint within @aesl_internal_computeParentHash  --> \n", ++aesl_llvm_cbe_1239_count);
  llvm_cbe_tmp__413 = (unsigned int )exists((l_struct_OC_tree_t *)llvm_cbe_tree, llvm_cbe_tmp__412);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__412);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__413);
}
  if (((llvm_cbe_tmp__413&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__444;
  } else {
    goto llvm_cbe_tmp__445;
  }

llvm_cbe_tmp__445:
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = getelementptr inbounds i8* %%6, i64 %%17, !dbg !24 for 0x%I64xth hint within @aesl_internal_computeParentHash  --> \n", ++aesl_llvm_cbe_1242_count);
  llvm_cbe_tmp__414 = ( char *)(&llvm_cbe_tmp__405[(((signed long long )llvm_cbe_tmp__412))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__412));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = load i8* %%21, align 1, !dbg !24 for 0x%I64xth hint within @aesl_internal_computeParentHash  --> \n", ++aesl_llvm_cbe_1243_count);
  llvm_cbe_tmp__415 = (unsigned char )*llvm_cbe_tmp__414;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__415);
  if (((llvm_cbe_tmp__415&255U) == (((unsigned char )0)&255U))) {
    goto llvm_cbe_tmp__440;
  } else {
    goto llvm_cbe_tmp__444;
  }

llvm_cbe_tmp__444:
if (AESL_DEBUG_TRACE)
printf("\n  call void @HashInit(%%struct.Keccak_HashInstance* %%ctx, %%struct.paramset_t* %%params, i8 zeroext 3) nounwind, !dbg !26 for 0x%I64xth hint within @aesl_internal_computeParentHash  --> \n", ++aesl_llvm_cbe_1247_count);
  HashInit((l_struct_OC_Keccak_HashInstance *)(&llvm_cbe_ctx), (l_struct_OC_paramset_t *)llvm_cbe_params, ((unsigned char )3));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",((unsigned char )3));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = getelementptr inbounds %%struct.tree_t* %%tree, i64 0, i32 1, !dbg !24 for 0x%I64xth hint within @aesl_internal_computeParentHash  --> \n", ++aesl_llvm_cbe_1248_count);
  llvm_cbe_tmp__416 = ( char ***)(&llvm_cbe_tree->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = load i8*** %%25, align 8, !dbg !24 for 0x%I64xth hint within @aesl_internal_computeParentHash  --> \n", ++aesl_llvm_cbe_1249_count);
  llvm_cbe_tmp__417 = ( char **)*llvm_cbe_tmp__416;
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = getelementptr inbounds i8** %%26, i64 %%12, !dbg !24 for 0x%I64xth hint within @aesl_internal_computeParentHash  --> \n", ++aesl_llvm_cbe_1250_count);
  llvm_cbe_tmp__418 = ( char **)(&llvm_cbe_tmp__417[(((signed long long )llvm_cbe_tmp__409))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__409));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = load i8** %%27, align 8, !dbg !24 for 0x%I64xth hint within @aesl_internal_computeParentHash  --> \n", ++aesl_llvm_cbe_1251_count);
  llvm_cbe_tmp__419 = ( char *)*llvm_cbe_tmp__418;
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = getelementptr inbounds %%struct.paramset_t* %%params, i64 0, i32 13, !dbg !24 for 0x%I64xth hint within @aesl_internal_computeParentHash  --> \n", ++aesl_llvm_cbe_1252_count);
  llvm_cbe_tmp__420 = (signed int *)(&llvm_cbe_params->field13);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = load i32* %%29, align 4, !dbg !24 for 0x%I64xth hint within @aesl_internal_computeParentHash  --> \n", ++aesl_llvm_cbe_1253_count);
  llvm_cbe_tmp__421 = (unsigned int )*llvm_cbe_tmp__420;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__421);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = zext i32 %%30 to i64, !dbg !24 for 0x%I64xth hint within @aesl_internal_computeParentHash  --> \n", ++aesl_llvm_cbe_1254_count);
  llvm_cbe_tmp__422 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__421&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__422);
if (AESL_DEBUG_TRACE)
printf("\n  call void @HashUpdate(%%struct.Keccak_HashInstance* %%ctx, i8* %%28, i64 %%31) nounwind, !dbg !24 for 0x%I64xth hint within @aesl_internal_computeParentHash  --> \n", ++aesl_llvm_cbe_1255_count);
  HashUpdate((l_struct_OC_Keccak_HashInstance *)(&llvm_cbe_ctx), ( char *)llvm_cbe_tmp__419, llvm_cbe_tmp__422);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__422);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = call i32 @hasRightChild(%%struct.tree_t* %%tree, i64 %%4), !dbg !25 for 0x%I64xth hint within @aesl_internal_computeParentHash  --> \n", ++aesl_llvm_cbe_1256_count);
  llvm_cbe_tmp__423 = (unsigned int )hasRightChild((l_struct_OC_tree_t *)llvm_cbe_tree, llvm_cbe_tmp__403);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__403);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__423);
}
  if (((llvm_cbe_tmp__423&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__446;
  } else {
    goto llvm_cbe_tmp__447;
  }

llvm_cbe_tmp__447:
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = load i8*** %%25, align 8, !dbg !25 for 0x%I64xth hint within @aesl_internal_computeParentHash  --> \n", ++aesl_llvm_cbe_1259_count);
  llvm_cbe_tmp__424 = ( char **)*llvm_cbe_tmp__416;
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = getelementptr inbounds i8** %%35, i64 %%17, !dbg !25 for 0x%I64xth hint within @aesl_internal_computeParentHash  --> \n", ++aesl_llvm_cbe_1260_count);
  llvm_cbe_tmp__425 = ( char **)(&llvm_cbe_tmp__424[(((signed long long )llvm_cbe_tmp__412))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__412));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = load i8** %%36, align 8, !dbg !25 for 0x%I64xth hint within @aesl_internal_computeParentHash  --> \n", ++aesl_llvm_cbe_1261_count);
  llvm_cbe_tmp__426 = ( char *)*llvm_cbe_tmp__425;
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = load i32* %%29, align 4, !dbg !25 for 0x%I64xth hint within @aesl_internal_computeParentHash  --> \n", ++aesl_llvm_cbe_1262_count);
  llvm_cbe_tmp__427 = (unsigned int )*llvm_cbe_tmp__420;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__427);
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = zext i32 %%38 to i64, !dbg !25 for 0x%I64xth hint within @aesl_internal_computeParentHash  --> \n", ++aesl_llvm_cbe_1263_count);
  llvm_cbe_tmp__428 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__427&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__428);
if (AESL_DEBUG_TRACE)
printf("\n  call void @HashUpdate(%%struct.Keccak_HashInstance* %%ctx, i8* %%37, i64 %%39) nounwind, !dbg !25 for 0x%I64xth hint within @aesl_internal_computeParentHash  --> \n", ++aesl_llvm_cbe_1264_count);
  HashUpdate((l_struct_OC_Keccak_HashInstance *)(&llvm_cbe_ctx), ( char *)llvm_cbe_tmp__426, llvm_cbe_tmp__428);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__428);
}
  goto llvm_cbe_tmp__446;

llvm_cbe_tmp__446:
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = getelementptr inbounds %%struct.paramset_t* %%params, i64 0, i32 12, !dbg !26 for 0x%I64xth hint within @aesl_internal_computeParentHash  --> \n", ++aesl_llvm_cbe_1266_count);
  llvm_cbe_tmp__429 = (signed int *)(&llvm_cbe_params->field12);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = load i32* %%41, align 4, !dbg !26 for 0x%I64xth hint within @aesl_internal_computeParentHash  --> \n", ++aesl_llvm_cbe_1267_count);
  llvm_cbe_tmp__430 = (unsigned int )*llvm_cbe_tmp__429;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__430);
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = zext i32 %%42 to i64, !dbg !26 for 0x%I64xth hint within @aesl_internal_computeParentHash  --> \n", ++aesl_llvm_cbe_1268_count);
  llvm_cbe_tmp__431 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__430&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__431);
if (AESL_DEBUG_TRACE)
printf("\n  call void @HashUpdate(%%struct.Keccak_HashInstance* %%ctx, i8* %%salt, i64 %%43) nounwind, !dbg !26 for 0x%I64xth hint within @aesl_internal_computeParentHash  --> \n", ++aesl_llvm_cbe_1269_count);
  HashUpdate((l_struct_OC_Keccak_HashInstance *)(&llvm_cbe_ctx), ( char *)llvm_cbe_salt, llvm_cbe_tmp__431);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__431);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = trunc i64 %%4 to i16, !dbg !26 for 0x%I64xth hint within @aesl_internal_computeParentHash  --> \n", ++aesl_llvm_cbe_1270_count);
  llvm_cbe_tmp__432 = (unsigned short )((unsigned short )llvm_cbe_tmp__403&65535U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__432);
if (AESL_DEBUG_TRACE)
printf("\n  call void @HashUpdateIntLE(%%struct.Keccak_HashInstance* %%ctx, i16 zeroext %%44) nounwind, !dbg !26 for 0x%I64xth hint within @aesl_internal_computeParentHash  --> \n", ++aesl_llvm_cbe_1271_count);
  HashUpdateIntLE((l_struct_OC_Keccak_HashInstance *)(&llvm_cbe_ctx), llvm_cbe_tmp__432);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__432);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @HashFinal(%%struct.Keccak_HashInstance* %%ctx) nounwind, !dbg !28 for 0x%I64xth hint within @aesl_internal_computeParentHash  --> \n", ++aesl_llvm_cbe_1272_count);
  HashFinal((l_struct_OC_Keccak_HashInstance *)(&llvm_cbe_ctx));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = load i8*** %%25, align 8, !dbg !25 for 0x%I64xth hint within @aesl_internal_computeParentHash  --> \n", ++aesl_llvm_cbe_1273_count);
  llvm_cbe_tmp__433 = ( char **)*llvm_cbe_tmp__416;
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = getelementptr inbounds i8** %%45, i64 %%4, !dbg !25 for 0x%I64xth hint within @aesl_internal_computeParentHash  --> \n", ++aesl_llvm_cbe_1274_count);
  llvm_cbe_tmp__434 = ( char **)(&llvm_cbe_tmp__433[(((signed long long )llvm_cbe_tmp__403))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__403));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = load i8** %%46, align 8, !dbg !25 for 0x%I64xth hint within @aesl_internal_computeParentHash  --> \n", ++aesl_llvm_cbe_1275_count);
  llvm_cbe_tmp__435 = ( char *)*llvm_cbe_tmp__434;
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = load i32* %%29, align 4, !dbg !25 for 0x%I64xth hint within @aesl_internal_computeParentHash  --> \n", ++aesl_llvm_cbe_1276_count);
  llvm_cbe_tmp__436 = (unsigned int )*llvm_cbe_tmp__420;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__436);
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = zext i32 %%48 to i64, !dbg !25 for 0x%I64xth hint within @aesl_internal_computeParentHash  --> \n", ++aesl_llvm_cbe_1277_count);
  llvm_cbe_tmp__437 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__436&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__437);
if (AESL_DEBUG_TRACE)
printf("\n  call void @HashSqueeze(%%struct.Keccak_HashInstance* %%ctx, i8* %%47, i64 %%49) nounwind, !dbg !25 for 0x%I64xth hint within @aesl_internal_computeParentHash  --> \n", ++aesl_llvm_cbe_1278_count);
  HashSqueeze((l_struct_OC_Keccak_HashInstance *)(&llvm_cbe_ctx), ( char *)llvm_cbe_tmp__435, llvm_cbe_tmp__437);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__437);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = load i8** %%5, align 8, !dbg !25 for 0x%I64xth hint within @aesl_internal_computeParentHash  --> \n", ++aesl_llvm_cbe_1279_count);
  llvm_cbe_tmp__438 = ( char *)*llvm_cbe_tmp__404;
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = getelementptr inbounds i8* %%50, i64 %%4, !dbg !25 for 0x%I64xth hint within @aesl_internal_computeParentHash  --> \n", ++aesl_llvm_cbe_1280_count);
  llvm_cbe_tmp__439 = ( char *)(&llvm_cbe_tmp__438[(((signed long long )llvm_cbe_tmp__403))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__403));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 1, i8* %%51, align 1, !dbg !25 for 0x%I64xth hint within @aesl_internal_computeParentHash  --> \n", ++aesl_llvm_cbe_1281_count);
  *llvm_cbe_tmp__439 = ((unsigned char )1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )1));
  goto llvm_cbe_tmp__440;

llvm_cbe_tmp__440:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @aesl_internal_computeParentHash}\n");
  return;
}


signed long long openMerkleTreeSize(signed long long llvm_cbe_numNodes, signed short *llvm_cbe_missingLeaves, signed long long llvm_cbe_missingLeavesSize, l_struct_OC_paramset_t *llvm_cbe_params) {
  static  unsigned long long aesl_llvm_cbe_revealedSize_count = 0;
  signed long long llvm_cbe_revealedSize;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_1284_count = 0;
  static  unsigned long long aesl_llvm_cbe_1285_count = 0;
  static  unsigned long long aesl_llvm_cbe_1286_count = 0;
  static  unsigned long long aesl_llvm_cbe_1287_count = 0;
  static  unsigned long long aesl_llvm_cbe_1288_count = 0;
  static  unsigned long long aesl_llvm_cbe_1289_count = 0;
  static  unsigned long long aesl_llvm_cbe_1290_count = 0;
  static  unsigned long long aesl_llvm_cbe_1291_count = 0;
  static  unsigned long long aesl_llvm_cbe_1292_count = 0;
  static  unsigned long long aesl_llvm_cbe_1293_count = 0;
  signed int *llvm_cbe_tmp__448;
  static  unsigned long long aesl_llvm_cbe_1294_count = 0;
  unsigned int llvm_cbe_tmp__449;
  static  unsigned long long aesl_llvm_cbe_1295_count = 0;
  unsigned long long llvm_cbe_tmp__450;
  static  unsigned long long aesl_llvm_cbe_1296_count = 0;
  l_struct_OC_tree_t *llvm_cbe_tmp__451;
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
  signed long long *llvm_cbe_tmp__452;
  static  unsigned long long aesl_llvm_cbe_1309_count = 0;
  static  unsigned long long aesl_llvm_cbe_1310_count = 0;
  static  unsigned long long aesl_llvm_cbe_1311_count = 0;
  static  unsigned long long aesl_llvm_cbe_1312_count = 0;
   char *llvm_cbe_tmp__453;
  static  unsigned long long aesl_llvm_cbe_1313_count = 0;
  static  unsigned long long aesl_llvm_cbe_1314_count = 0;
  static  unsigned long long aesl_llvm_cbe_1315_count = 0;
  static  unsigned long long aesl_llvm_cbe_1316_count = 0;
  static  unsigned long long aesl_llvm_cbe_1317_count = 0;
  static  unsigned long long aesl_llvm_cbe_1318_count = 0;
  static  unsigned long long aesl_llvm_cbe_1319_count = 0;
  static  unsigned long long aesl_llvm_cbe_1320_count = 0;
  unsigned long long llvm_cbe_tmp__454;
  static  unsigned long long aesl_llvm_cbe_1321_count = 0;
  unsigned int llvm_cbe_tmp__455;
  static  unsigned long long aesl_llvm_cbe_1322_count = 0;
  unsigned long long llvm_cbe_tmp__456;
  static  unsigned long long aesl_llvm_cbe_1323_count = 0;
  unsigned long long llvm_cbe_tmp__457;
  static  unsigned long long aesl_llvm_cbe_1324_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @openMerkleTreeSize\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.paramset_t* %%params, i64 0, i32 13, !dbg !25 for 0x%I64xth hint within @openMerkleTreeSize  --> \n", ++aesl_llvm_cbe_1293_count);
  llvm_cbe_tmp__448 = (signed int *)(&llvm_cbe_params->field13);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i32* %%1, align 4, !dbg !25 for 0x%I64xth hint within @openMerkleTreeSize  --> \n", ++aesl_llvm_cbe_1294_count);
  llvm_cbe_tmp__449 = (unsigned int )*llvm_cbe_tmp__448;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__449);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = zext i32 %%2 to i64, !dbg !25 for 0x%I64xth hint within @openMerkleTreeSize  --> \n", ++aesl_llvm_cbe_1295_count);
  llvm_cbe_tmp__450 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__449&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__450);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = call %%struct.tree_t* @createTree(i64 %%numNodes, i64 %%3), !dbg !25 for 0x%I64xth hint within @openMerkleTreeSize  --> \n", ++aesl_llvm_cbe_1296_count);
  llvm_cbe_tmp__451 = (l_struct_OC_tree_t *)createTree(llvm_cbe_numNodes, llvm_cbe_tmp__450);
if (AESL_DEBUG_TRACE) {
printf("\nArgument numNodes = 0x%I64X",llvm_cbe_numNodes);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__450);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__451);
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 0, i64* %%revealedSize, align 8, !dbg !26 for 0x%I64xth hint within @openMerkleTreeSize  --> \n", ++aesl_llvm_cbe_1307_count);
  *(&llvm_cbe_revealedSize) = 0ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 0ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = call fastcc i64* @aesl_internal_getRevealedMerkleNodes(%%struct.tree_t* %%4, i16* %%missingLeaves, i64 %%missingLeavesSize, i64* %%revealedSize), !dbg !24 for 0x%I64xth hint within @openMerkleTreeSize  --> \n", ++aesl_llvm_cbe_1308_count);
  llvm_cbe_tmp__452 = (signed long long *)aesl_internal_getRevealedMerkleNodes((l_struct_OC_tree_t *)llvm_cbe_tmp__451, (signed short *)llvm_cbe_missingLeaves, llvm_cbe_missingLeavesSize, (signed long long *)(&llvm_cbe_revealedSize));
if (AESL_DEBUG_TRACE) {
printf("\nArgument missingLeavesSize = 0x%I64X",llvm_cbe_missingLeavesSize);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__452);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @freeTree(%%struct.tree_t* %%4), !dbg !25 for 0x%I64xth hint within @openMerkleTreeSize  --> \n", ++aesl_llvm_cbe_1311_count);
  freeTree((l_struct_OC_tree_t *)llvm_cbe_tmp__451);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = bitcast i64* %%5 to i8*, !dbg !26 for 0x%I64xth hint within @openMerkleTreeSize  --> \n", ++aesl_llvm_cbe_1312_count);
  llvm_cbe_tmp__453 = ( char *)(( char *)llvm_cbe_tmp__452);
if (AESL_DEBUG_TRACE)
printf("\n  call void @free(i8* %%6), !dbg !26 for 0x%I64xth hint within @openMerkleTreeSize  --> \n", ++aesl_llvm_cbe_1313_count);
  free(( char *)llvm_cbe_tmp__453);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = load i64* %%revealedSize, align 8, !dbg !25 for 0x%I64xth hint within @openMerkleTreeSize  --> \n", ++aesl_llvm_cbe_1320_count);
  llvm_cbe_tmp__454 = (unsigned long long )*(&llvm_cbe_revealedSize);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__454);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load i32* %%1, align 4, !dbg !25 for 0x%I64xth hint within @openMerkleTreeSize  --> \n", ++aesl_llvm_cbe_1321_count);
  llvm_cbe_tmp__455 = (unsigned int )*llvm_cbe_tmp__448;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__455);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = zext i32 %%8 to i64, !dbg !25 for 0x%I64xth hint within @openMerkleTreeSize  --> \n", ++aesl_llvm_cbe_1322_count);
  llvm_cbe_tmp__456 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__455&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__456);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = mul i64 %%9, %%7, !dbg !25 for 0x%I64xth hint within @openMerkleTreeSize  --> \n", ++aesl_llvm_cbe_1323_count);
  llvm_cbe_tmp__457 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__456&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__454&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__457&18446744073709551615ull)));
  if (AESL_DEBUG_TRACE)
      printf("\nEND @openMerkleTreeSize}\n");
  return llvm_cbe_tmp__457;
}


static signed long long *aesl_internal_getRevealedMerkleNodes(l_struct_OC_tree_t *llvm_cbe_tree, signed short *llvm_cbe_missingLeaves, signed long long llvm_cbe_missingLeavesSize, signed long long *llvm_cbe_outputSize) {
  static  unsigned long long aesl_llvm_cbe_1325_count = 0;
  static  unsigned long long aesl_llvm_cbe_1326_count = 0;
  static  unsigned long long aesl_llvm_cbe_1327_count = 0;
  static  unsigned long long aesl_llvm_cbe_1328_count = 0;
  static  unsigned long long aesl_llvm_cbe_1329_count = 0;
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
  signed long long *llvm_cbe_tmp__458;
  static  unsigned long long aesl_llvm_cbe_1342_count = 0;
  unsigned long long llvm_cbe_tmp__459;
  static  unsigned long long aesl_llvm_cbe_1343_count = 0;
  signed long long *llvm_cbe_tmp__460;
  static  unsigned long long aesl_llvm_cbe_1344_count = 0;
  unsigned long long llvm_cbe_tmp__461;
  static  unsigned long long aesl_llvm_cbe_1345_count = 0;
  unsigned long long llvm_cbe_tmp__462;
  static  unsigned long long aesl_llvm_cbe_1346_count = 0;
  static  unsigned long long aesl_llvm_cbe_1347_count = 0;
  static  unsigned long long aesl_llvm_cbe_1348_count = 0;
  static  unsigned long long aesl_llvm_cbe_1349_count = 0;
   char *llvm_cbe_tmp__463;
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
  static  unsigned long long aesl_llvm_cbe_storemerge10_count = 0;
  unsigned long long llvm_cbe_storemerge10;
  unsigned long long llvm_cbe_storemerge10__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1377_count = 0;
  signed short *llvm_cbe_tmp__464;
  static  unsigned long long aesl_llvm_cbe_1378_count = 0;
  unsigned short llvm_cbe_tmp__465;
  static  unsigned long long aesl_llvm_cbe_1379_count = 0;
  unsigned long long llvm_cbe_tmp__466;
  static  unsigned long long aesl_llvm_cbe_1380_count = 0;
  unsigned long long llvm_cbe_tmp__467;
  static  unsigned long long aesl_llvm_cbe_1381_count = 0;
   char *llvm_cbe_tmp__468;
  static  unsigned long long aesl_llvm_cbe_1382_count = 0;
  static  unsigned long long aesl_llvm_cbe_1383_count = 0;
  unsigned long long llvm_cbe_tmp__469;
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
  static  unsigned long long aesl_llvm_cbe_exitcond16_count = 0;
  static  unsigned long long aesl_llvm_cbe_1400_count = 0;
  static  unsigned long long aesl_llvm_cbe_1401_count = 0;
  unsigned long long llvm_cbe_tmp__470;
  static  unsigned long long aesl_llvm_cbe_1402_count = 0;
  unsigned long long llvm_cbe_tmp__471;
  static  unsigned long long aesl_llvm_cbe_1403_count = 0;
  unsigned long long llvm_cbe_tmp__472;
  static  unsigned long long aesl_llvm_cbe_1404_count = 0;
  unsigned int llvm_cbe_tmp__473;
  static  unsigned long long aesl_llvm_cbe_1405_count = 0;
  static  unsigned long long aesl_llvm_cbe_1406_count = 0;
  static  unsigned long long aesl_llvm_cbe_1407_count = 0;
  unsigned long long llvm_cbe_tmp__474;
  static  unsigned long long aesl_llvm_cbe_1408_count = 0;
  static  unsigned long long aesl_llvm_cbe_1409_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_1421_count = 0;
  static  unsigned long long aesl_llvm_cbe_1422_count = 0;
  static  unsigned long long aesl_llvm_cbe_1423_count = 0;
  static  unsigned long long aesl_llvm_cbe_1424_count = 0;
  static  unsigned long long aesl_llvm_cbe_1425_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge16_count = 0;
  unsigned long long llvm_cbe_storemerge16;
  unsigned long long llvm_cbe_storemerge16__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1426_count = 0;
  unsigned int llvm_cbe_tmp__475;
  static  unsigned long long aesl_llvm_cbe_1427_count = 0;
  static  unsigned long long aesl_llvm_cbe_1428_count = 0;
  static  unsigned long long aesl_llvm_cbe_1429_count = 0;
  unsigned long long llvm_cbe_tmp__476;
  static  unsigned long long aesl_llvm_cbe_1430_count = 0;
  unsigned long long llvm_cbe_tmp__477;
  static  unsigned long long aesl_llvm_cbe_1431_count = 0;
  unsigned int llvm_cbe_tmp__478;
  static  unsigned long long aesl_llvm_cbe_1432_count = 0;
  static  unsigned long long aesl_llvm_cbe_1433_count = 0;
  static  unsigned long long aesl_llvm_cbe_1434_count = 0;
  unsigned long long llvm_cbe_tmp__479;
  static  unsigned long long aesl_llvm_cbe_1435_count = 0;
   char *llvm_cbe_tmp__480;
  static  unsigned long long aesl_llvm_cbe_1436_count = 0;
  unsigned char llvm_cbe_tmp__481;
  static  unsigned long long aesl_llvm_cbe_1437_count = 0;
  static  unsigned long long aesl_llvm_cbe_1438_count = 0;
  static  unsigned long long aesl_llvm_cbe_1439_count = 0;
   char *llvm_cbe_tmp__482;
  static  unsigned long long aesl_llvm_cbe_1440_count = 0;
  unsigned char llvm_cbe_tmp__483;
  static  unsigned long long aesl_llvm_cbe_1441_count = 0;
  static  unsigned long long aesl_llvm_cbe_1442_count = 0;
  static  unsigned long long aesl_llvm_cbe_1443_count = 0;
   char *llvm_cbe_tmp__484;
  static  unsigned long long aesl_llvm_cbe_1444_count = 0;
  static  unsigned long long aesl_llvm_cbe_1445_count = 0;
  static  unsigned long long aesl_llvm_cbe_1446_count = 0;
  static  unsigned long long aesl_llvm_cbe_1447_count = 0;
  unsigned long long llvm_cbe_tmp__485;
  static  unsigned long long aesl_llvm_cbe_1448_count = 0;
   char *llvm_cbe_tmp__486;
  static  unsigned long long aesl_llvm_cbe_1449_count = 0;
  unsigned char llvm_cbe_tmp__487;
  static  unsigned long long aesl_llvm_cbe_1450_count = 0;
  static  unsigned long long aesl_llvm_cbe_1451_count = 0;
  static  unsigned long long aesl_llvm_cbe_1452_count = 0;
   char *llvm_cbe_tmp__488;
  static  unsigned long long aesl_llvm_cbe_1453_count = 0;
  static  unsigned long long aesl_llvm_cbe_1454_count = 0;
  static  unsigned long long aesl_llvm_cbe_1455_count = 0;
  static  unsigned long long aesl_llvm_cbe_1456_count = 0;
  static  unsigned long long aesl_llvm_cbe_1457_count = 0;
  unsigned long long llvm_cbe_tmp__489;
  static  unsigned long long aesl_llvm_cbe_1458_count = 0;
  static  unsigned long long aesl_llvm_cbe_1459_count = 0;
  static  unsigned long long aesl_llvm_cbe_1460_count = 0;
  static  unsigned long long aesl_llvm_cbe_1461_count = 0;
  static  unsigned long long aesl_llvm_cbe_1462_count = 0;
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
  unsigned long long llvm_cbe_tmp__490;
  static  unsigned long long aesl_llvm_cbe_1477_count = 0;
  unsigned long long llvm_cbe_tmp__491;
  static  unsigned long long aesl_llvm_cbe_1478_count = 0;
   char *llvm_cbe_tmp__492;
  static  unsigned long long aesl_llvm_cbe_1479_count = 0;
  signed long long *llvm_cbe_tmp__493;
  static  unsigned long long aesl_llvm_cbe_1480_count = 0;
  static  unsigned long long aesl_llvm_cbe_1481_count = 0;
  static  unsigned long long aesl_llvm_cbe_1482_count = 0;
  static  unsigned long long aesl_llvm_cbe_1483_count = 0;
  static  unsigned long long aesl_llvm_cbe_1484_count = 0;
  static  unsigned long long aesl_llvm_cbe_1485_count = 0;
  static  unsigned long long aesl_llvm_cbe_1486_count = 0;
  static  unsigned long long aesl_llvm_cbe_1487_count = 0;
  static  unsigned long long aesl_llvm_cbe_1488_count = 0;
  static  unsigned long long aesl_llvm_cbe_1489_count = 0;
  static  unsigned long long aesl_llvm_cbe_1490_count = 0;
  static  unsigned long long aesl_llvm_cbe_1491_count = 0;
  static  unsigned long long aesl_llvm_cbe_1492_count = 0;
  static  unsigned long long aesl_llvm_cbe_1493_count = 0;
  static  unsigned long long aesl_llvm_cbe_1494_count = 0;
  static  unsigned long long aesl_llvm_cbe_1495_count = 0;
  static  unsigned long long aesl_llvm_cbe_1496_count = 0;
  static  unsigned long long aesl_llvm_cbe_1497_count = 0;
  static  unsigned long long aesl_llvm_cbe_1498_count = 0;
  static  unsigned long long aesl_llvm_cbe_1499_count = 0;
  static  unsigned long long aesl_llvm_cbe_1500_count = 0;
  static  unsigned long long aesl_llvm_cbe_1501_count = 0;
  static  unsigned long long aesl_llvm_cbe_1502_count = 0;
  static  unsigned long long aesl_llvm_cbe_1503_count = 0;
  static  unsigned long long aesl_llvm_cbe_1504_count = 0;
  static  unsigned long long aesl_llvm_cbe_1505_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge25_count = 0;
  unsigned long long llvm_cbe_storemerge25;
  unsigned long long llvm_cbe_storemerge25__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1506_count = 0;
  unsigned long long llvm_cbe_tmp__494;
  unsigned long long llvm_cbe_tmp__494__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1507_count = 0;
  signed short *llvm_cbe_tmp__495;
  static  unsigned long long aesl_llvm_cbe_1508_count = 0;
  unsigned short llvm_cbe_tmp__496;
  static  unsigned long long aesl_llvm_cbe_1509_count = 0;
  unsigned long long llvm_cbe_tmp__497;
  static  unsigned long long aesl_llvm_cbe_1510_count = 0;
  unsigned long long llvm_cbe_tmp__498;
  static  unsigned long long aesl_llvm_cbe_1511_count = 0;
  static  unsigned long long aesl_llvm_cbe_1512_count = 0;
  static  unsigned long long aesl_llvm_cbe_1513_count = 0;
  static  unsigned long long aesl_llvm_cbe_1514_count = 0;
  static  unsigned long long aesl_llvm_cbe_1515_count = 0;
  static  unsigned long long aesl_llvm_cbe_1516_count = 0;
  static  unsigned long long aesl_llvm_cbe_1517_count = 0;
  unsigned long long llvm_cbe_tmp__499;
  unsigned long long llvm_cbe_tmp__499__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1518_count = 0;
  unsigned long long llvm_cbe_tmp__500;
  static  unsigned long long aesl_llvm_cbe_1519_count = 0;
   char *llvm_cbe_tmp__501;
  static  unsigned long long aesl_llvm_cbe_1520_count = 0;
  unsigned char llvm_cbe_tmp__502;
  static  unsigned long long aesl_llvm_cbe_1521_count = 0;
  static  unsigned long long aesl_llvm_cbe_1522_count = 0;
  static  unsigned long long aesl_llvm_cbe_1523_count = 0;
  unsigned int llvm_cbe_tmp__503;
  static  unsigned long long aesl_llvm_cbe_1524_count = 0;
  static  unsigned long long aesl_llvm_cbe_1525_count = 0;
  static  unsigned long long aesl_llvm_cbe_1526_count = 0;
  signed long long *llvm_cbe_tmp__504;
  static  unsigned long long aesl_llvm_cbe_1527_count = 0;
  static  unsigned long long aesl_llvm_cbe_1528_count = 0;
  unsigned long long llvm_cbe_tmp__505;
  static  unsigned long long aesl_llvm_cbe_1529_count = 0;
  static  unsigned long long aesl_llvm_cbe_1530_count = 0;
  static  unsigned long long aesl_llvm_cbe_1531_count = 0;
  static  unsigned long long aesl_llvm_cbe_1532_count = 0;
  static  unsigned long long aesl_llvm_cbe_1533_count = 0;
  static  unsigned long long aesl_llvm_cbe_1534_count = 0;
  static  unsigned long long aesl_llvm_cbe_1535_count = 0;
  unsigned long long llvm_cbe_tmp__506;
  static  unsigned long long aesl_llvm_cbe_1536_count = 0;
  static  unsigned long long aesl_llvm_cbe_1537_count = 0;
  static  unsigned long long aesl_llvm_cbe_1538_count = 0;
  static  unsigned long long aesl_llvm_cbe_1539_count = 0;
  static  unsigned long long aesl_llvm_cbe_1540_count = 0;
  static  unsigned long long aesl_llvm_cbe_1541_count = 0;
  static  unsigned long long aesl_llvm_cbe_1542_count = 0;
  static  unsigned long long aesl_llvm_cbe_1543_count = 0;
  unsigned long long llvm_cbe_tmp__507;
  unsigned long long llvm_cbe_tmp__507__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1544_count = 0;
  unsigned long long llvm_cbe_tmp__508;
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
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_1561_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_lcssa4_count = 0;
  unsigned long long llvm_cbe__2e_lcssa4;
  unsigned long long llvm_cbe__2e_lcssa4__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1562_count = 0;
  static  unsigned long long aesl_llvm_cbe_1563_count = 0;
  static  unsigned long long aesl_llvm_cbe_1564_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @aesl_internal_getRevealedMerkleNodes\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.tree_t* %%tree, i64 0, i32 5, !dbg !24 for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1341_count);
  llvm_cbe_tmp__458 = (signed long long *)(&llvm_cbe_tree->field5);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i64* %%1, align 8, !dbg !24 for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1342_count);
  llvm_cbe_tmp__459 = (unsigned long long )*llvm_cbe_tmp__458;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__459);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.tree_t* %%tree, i64 0, i32 6, !dbg !24 for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1343_count);
  llvm_cbe_tmp__460 = (signed long long *)(&llvm_cbe_tree->field6);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i64* %%3, align 8, !dbg !24 for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1344_count);
  llvm_cbe_tmp__461 = (unsigned long long )*llvm_cbe_tmp__460;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__461);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = sub i64 %%2, %%4, !dbg !24 for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1345_count);
  llvm_cbe_tmp__462 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__459&18446744073709551615ull)) - ((unsigned long long )(llvm_cbe_tmp__461&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__462&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = tail call i8* @calloc(i64 %%2, i64 1) nounwind, !dbg !24 for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1349_count);
  llvm_cbe_tmp__463 = ( char *) /*tail*/ ( char *)calloc(llvm_cbe_tmp__459, 1ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__459);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__463);
}
  if (((llvm_cbe_missingLeavesSize&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge13;
  } else {
    llvm_cbe_storemerge10__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph12;
  }

  do {     /* Syntactic loop '.lr.ph12' to make GCC happy */
llvm_cbe__2e_lr_2e_ph12:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge10 = phi i64 [ %%13, %%.lr.ph12 ], [ 0, %%0  for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_storemerge10_count);
  llvm_cbe_storemerge10 = (unsigned long long )llvm_cbe_storemerge10__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge10 = 0x%I64X",llvm_cbe_storemerge10);
printf("\n = 0x%I64X",llvm_cbe_tmp__469);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds i16* %%missingLeaves, i64 %%storemerge10, !dbg !25 for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1377_count);
  llvm_cbe_tmp__464 = (signed short *)(&llvm_cbe_missingLeaves[(((signed long long )llvm_cbe_storemerge10))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge10 = 0x%I64X",((signed long long )llvm_cbe_storemerge10));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = load i16* %%8, align 2, !dbg !25 for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1378_count);
  llvm_cbe_tmp__465 = (unsigned short )*llvm_cbe_tmp__464;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__465);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = zext i16 %%9 to i64, !dbg !25 for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1379_count);
  llvm_cbe_tmp__466 = (unsigned long long )((unsigned long long )(unsigned short )llvm_cbe_tmp__465&65535U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__466);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = add i64 %%10, %%5, !dbg !25 for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1380_count);
  llvm_cbe_tmp__467 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__466&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__462&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__467&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds i8* %%6, i64 %%11, !dbg !25 for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1381_count);
  llvm_cbe_tmp__468 = ( char *)(&llvm_cbe_tmp__463[(((signed long long )llvm_cbe_tmp__467))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__467));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 1, i8* %%12, align 1, !dbg !25 for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1382_count);
  *llvm_cbe_tmp__468 = ((unsigned char )1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )1));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = add i64 %%storemerge10, 1, !dbg !28 for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1383_count);
  llvm_cbe_tmp__469 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge10&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__469&18446744073709551615ull)));
  if (((llvm_cbe_tmp__469&18446744073709551615ULL) == (llvm_cbe_missingLeavesSize&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge13;
  } else {
    llvm_cbe_storemerge10__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__469;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph12;
  }

  } while (1); /* end of syntactic loop '.lr.ph12' */
llvm_cbe__2e__crit_edge13:
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load i64* %%1, align 8, !dbg !24 for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1401_count);
  llvm_cbe_tmp__470 = (unsigned long long )*llvm_cbe_tmp__458;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__470);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = add i64 %%14, -1, !dbg !24 for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1402_count);
  llvm_cbe_tmp__471 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__470&18446744073709551615ull)) + ((unsigned long long )(18446744073709551615ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__471&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = tail call i64 @getParent(i64 %%15), !dbg !24 for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1403_count);
  llvm_cbe_tmp__472 = (unsigned long long ) /*tail*/ getParent(llvm_cbe_tmp__471);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__471);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__472);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = trunc i64 %%16 to i32, !dbg !24 for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1404_count);
  llvm_cbe_tmp__473 = (unsigned int )((unsigned int )llvm_cbe_tmp__472&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__473);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = sext i32 %%17 to i64, !dbg !28 for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1407_count);
  llvm_cbe_tmp__474 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__473);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__474);
  if (((llvm_cbe_tmp__473&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe__2e__crit_edge9;
  } else {
    llvm_cbe_storemerge16__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__474;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph8;
  }

  do {     /* Syntactic loop '.lr.ph8' to make GCC happy */
llvm_cbe__2e_lr_2e_ph8:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge16 = phi i64 [ %%49, %%48 ], [ %%18, %%._crit_edge13  for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_storemerge16_count);
  llvm_cbe_storemerge16 = (unsigned long long )llvm_cbe_storemerge16__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge16 = 0x%I64X",llvm_cbe_storemerge16);
printf("\n = 0x%I64X",llvm_cbe_tmp__489);
printf("\n = 0x%I64X",llvm_cbe_tmp__474);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = tail call i32 @exists(%%struct.tree_t* %%tree, i64 %%storemerge16), !dbg !24 for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1426_count);
  llvm_cbe_tmp__475 = (unsigned int ) /*tail*/ exists((l_struct_OC_tree_t *)llvm_cbe_tree, llvm_cbe_storemerge16);
if (AESL_DEBUG_TRACE) {
printf("\nArgument storemerge16 = 0x%I64X",llvm_cbe_storemerge16);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__475);
}
  if (((llvm_cbe_tmp__475&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__509;
  } else {
    goto llvm_cbe_tmp__510;
  }

llvm_cbe_tmp__509:
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = add i64 %%storemerge16, -1, !dbg !28 for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1457_count);
  llvm_cbe_tmp__489 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge16&18446744073709551615ull)) + ((unsigned long long )(18446744073709551615ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__489&18446744073709551615ull)));
  if (((llvm_cbe_tmp__489&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge9;
  } else {
    llvm_cbe_storemerge16__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__489;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph8;
  }

llvm_cbe_tmp__511:
  goto llvm_cbe_tmp__509;

llvm_cbe_tmp__512:
  goto llvm_cbe_tmp__511;

llvm_cbe_tmp__513:
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = or i64 %%23, 1, !dbg !27 for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1434_count);
  llvm_cbe_tmp__479 = (unsigned long long )llvm_cbe_tmp__476 | 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__479);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = getelementptr inbounds i8* %%6, i64 %%28, !dbg !27 for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1435_count);
  llvm_cbe_tmp__480 = ( char *)(&llvm_cbe_tmp__463[(((signed long long )llvm_cbe_tmp__479))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__479));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = load i8* %%29, align 1, !dbg !27 for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1436_count);
  llvm_cbe_tmp__481 = (unsigned char )*llvm_cbe_tmp__480;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__481);
  if (((llvm_cbe_tmp__481&255U) == (((unsigned char )0)&255U))) {
    goto llvm_cbe_tmp__512;
  } else {
    goto llvm_cbe_tmp__514;
  }

llvm_cbe_tmp__510:
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = shl i64 %%storemerge16, 1, !dbg !25 for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1429_count);
  llvm_cbe_tmp__476 = (unsigned long long )llvm_cbe_storemerge16 << 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__476);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = add i64 %%23, 2, !dbg !25 for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1430_count);
  llvm_cbe_tmp__477 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__476&18446744073709551615ull)) + ((unsigned long long )(2ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__477&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = tail call i32 @exists(%%struct.tree_t* %%tree, i64 %%24), !dbg !25 for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1431_count);
  llvm_cbe_tmp__478 = (unsigned int ) /*tail*/ exists((l_struct_OC_tree_t *)llvm_cbe_tree, llvm_cbe_tmp__477);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__477);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__478);
}
  if (((llvm_cbe_tmp__478&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__515;
  } else {
    goto llvm_cbe_tmp__513;
  }

llvm_cbe_tmp__514:
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = getelementptr inbounds i8* %%6, i64 %%24, !dbg !27 for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1439_count);
  llvm_cbe_tmp__482 = ( char *)(&llvm_cbe_tmp__463[(((signed long long )llvm_cbe_tmp__477))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__477));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = load i8* %%33, align 1, !dbg !27 for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1440_count);
  llvm_cbe_tmp__483 = (unsigned char )*llvm_cbe_tmp__482;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__483);
  if (((llvm_cbe_tmp__483&255U) == (((unsigned char )0)&255U))) {
    goto llvm_cbe_tmp__512;
  } else {
    goto llvm_cbe_tmp__516;
  }

llvm_cbe_tmp__516:
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = getelementptr inbounds i8* %%6, i64 %%storemerge16, !dbg !27 for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1443_count);
  llvm_cbe_tmp__484 = ( char *)(&llvm_cbe_tmp__463[(((signed long long )llvm_cbe_storemerge16))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge16 = 0x%I64X",((signed long long )llvm_cbe_storemerge16));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 1, i8* %%37, align 1, !dbg !27 for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1444_count);
  *llvm_cbe_tmp__484 = ((unsigned char )1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )1));
  goto llvm_cbe_tmp__512;

llvm_cbe_tmp__517:
  goto llvm_cbe_tmp__511;

llvm_cbe_tmp__515:
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = or i64 %%23, 1, !dbg !27 for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1447_count);
  llvm_cbe_tmp__485 = (unsigned long long )llvm_cbe_tmp__476 | 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__485);
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = getelementptr inbounds i8* %%6, i64 %%40, !dbg !27 for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1448_count);
  llvm_cbe_tmp__486 = ( char *)(&llvm_cbe_tmp__463[(((signed long long )llvm_cbe_tmp__485))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__485));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = load i8* %%41, align 1, !dbg !27 for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1449_count);
  llvm_cbe_tmp__487 = (unsigned char )*llvm_cbe_tmp__486;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__487);
  if (((llvm_cbe_tmp__487&255U) == (((unsigned char )0)&255U))) {
    goto llvm_cbe_tmp__517;
  } else {
    goto llvm_cbe_tmp__518;
  }

llvm_cbe_tmp__518:
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = getelementptr inbounds i8* %%6, i64 %%storemerge16, !dbg !27 for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1452_count);
  llvm_cbe_tmp__488 = ( char *)(&llvm_cbe_tmp__463[(((signed long long )llvm_cbe_storemerge16))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge16 = 0x%I64X",((signed long long )llvm_cbe_storemerge16));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 1, i8* %%45, align 1, !dbg !27 for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1453_count);
  *llvm_cbe_tmp__488 = ((unsigned char )1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )1));
  goto llvm_cbe_tmp__517;

  } while (1); /* end of syntactic loop '.lr.ph8' */
llvm_cbe__2e__crit_edge9:
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = load i64* %%3, align 8, !dbg !25 for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1476_count);
  llvm_cbe_tmp__490 = (unsigned long long )*llvm_cbe_tmp__460;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__490);
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = shl i64 %%51, 3, !dbg !25 for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1477_count);
  llvm_cbe_tmp__491 = (unsigned long long )llvm_cbe_tmp__490 << 3ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__491);
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = tail call i8* @malloc(i64 %%52), !dbg !25 for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1478_count);
  llvm_cbe_tmp__492 = ( char *) /*tail*/ ( char *)malloc(llvm_cbe_tmp__491);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__491);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__492);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = bitcast i8* %%53 to i64*, !dbg !25 for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1479_count);
  llvm_cbe_tmp__493 = (signed long long *)((signed long long *)llvm_cbe_tmp__492);
  if (((llvm_cbe_missingLeavesSize&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    llvm_cbe__2e_lcssa4__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge25__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    llvm_cbe_tmp__494__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge25 = phi i64 [ %%76, %%.loopexit ], [ 0, %%._crit_edge9  for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_storemerge25_count);
  llvm_cbe_storemerge25 = (unsigned long long )llvm_cbe_storemerge25__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge25 = 0x%I64X",llvm_cbe_storemerge25);
printf("\n = 0x%I64X",llvm_cbe_tmp__508);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = phi i64 [ %%75, %%.loopexit ], [ 0, %%._crit_edge9  for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1506_count);
  llvm_cbe_tmp__494 = (unsigned long long )llvm_cbe_tmp__494__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__494);
printf("\n = 0x%I64X",llvm_cbe_tmp__507);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = getelementptr inbounds i16* %%missingLeaves, i64 %%storemerge25, !dbg !25 for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1507_count);
  llvm_cbe_tmp__495 = (signed short *)(&llvm_cbe_missingLeaves[(((signed long long )llvm_cbe_storemerge25))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge25 = 0x%I64X",((signed long long )llvm_cbe_storemerge25));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = load i16* %%56, align 2, !dbg !25 for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1508_count);
  llvm_cbe_tmp__496 = (unsigned short )*llvm_cbe_tmp__495;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__496);
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = zext i16 %%57 to i64, !dbg !25 for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1509_count);
  llvm_cbe_tmp__497 = (unsigned long long )((unsigned long long )(unsigned short )llvm_cbe_tmp__496&65535U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__497);
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = add i64 %%58, %%5, !dbg !25 for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1510_count);
  llvm_cbe_tmp__498 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__497&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__462&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__498&18446744073709551615ull)));
  llvm_cbe_tmp__499__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__498;   /* for PHI node */
  goto llvm_cbe_tmp__519;

llvm_cbe__2e_loopexit:
if (AESL_DEBUG_TRACE)
printf("\n  %%75 = phi i64 [ %%55, %%66 ], [ %%71, %%69 ], [ %%55, %%72  for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1543_count);
  llvm_cbe_tmp__507 = (unsigned long long )llvm_cbe_tmp__507__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__507);
printf("\n = 0x%I64X",llvm_cbe_tmp__494);
printf("\n = 0x%I64X",llvm_cbe_tmp__505);
printf("\n = 0x%I64X",llvm_cbe_tmp__494);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%76 = add i64 %%storemerge25, 1, !dbg !28 for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1544_count);
  llvm_cbe_tmp__508 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge25&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__508&18446744073709551615ull)));
  if (((llvm_cbe_tmp__508&18446744073709551615ULL) == (llvm_cbe_missingLeavesSize&18446744073709551615ULL))) {
    llvm_cbe__2e_lcssa4__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__507;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge25__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__508;   /* for PHI node */
    llvm_cbe_tmp__494__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__507;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

llvm_cbe_tmp__520:
if (AESL_DEBUG_TRACE)
printf("\n  %%67 = tail call fastcc i32 @aesl_internal_contains(i64* %%54, i64 %%55, i64 %%61), !dbg !29 for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1523_count);
  llvm_cbe_tmp__503 = (unsigned int ) /*tail*/ aesl_internal_contains((signed long long *)llvm_cbe_tmp__493, llvm_cbe_tmp__494, llvm_cbe_tmp__499);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__494);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__499);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__503);
}
  if (((llvm_cbe_tmp__503&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__521;
  } else {
    llvm_cbe_tmp__507__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__494;   /* for PHI node */
    goto llvm_cbe__2e_loopexit;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__519:
if (AESL_DEBUG_TRACE)
printf("\n  %%61 = phi i64 [ %%73, %%72 ], [ %%59, %%.lr.ph  for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1517_count);
  llvm_cbe_tmp__499 = (unsigned long long )llvm_cbe_tmp__499__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__499);
printf("\n = 0x%I64X",llvm_cbe_tmp__506);
printf("\n = 0x%I64X",llvm_cbe_tmp__498);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = tail call i64 @getParent(i64 %%61), !dbg !27 for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1518_count);
  llvm_cbe_tmp__500 = (unsigned long long ) /*tail*/ getParent(llvm_cbe_tmp__499);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__499);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__500);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = getelementptr inbounds i8* %%6, i64 %%62, !dbg !27 for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1519_count);
  llvm_cbe_tmp__501 = ( char *)(&llvm_cbe_tmp__463[(((signed long long )llvm_cbe_tmp__500))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__500));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%64 = load i8* %%63, align 1, !dbg !27 for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1520_count);
  llvm_cbe_tmp__502 = (unsigned char )*llvm_cbe_tmp__501;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__502);
  if (((llvm_cbe_tmp__502&255U) == (((unsigned char )0)&255U))) {
    goto llvm_cbe_tmp__520;
  } else {
    goto llvm_cbe_tmp__522;
  }

llvm_cbe_tmp__522:
if (AESL_DEBUG_TRACE)
printf("\n  %%73 = tail call i64 @getParent(i64 %%61), !dbg !30 for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1535_count);
  llvm_cbe_tmp__506 = (unsigned long long ) /*tail*/ getParent(llvm_cbe_tmp__499);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__499);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__506);
}
  if (((llvm_cbe_tmp__506&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    llvm_cbe_tmp__507__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__494;   /* for PHI node */
    goto llvm_cbe__2e_loopexit;
  } else {
    llvm_cbe_tmp__499__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__506;   /* for PHI node */
    goto llvm_cbe_tmp__519;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__521:
if (AESL_DEBUG_TRACE)
printf("\n  %%70 = getelementptr inbounds i64* %%54, i64 %%55, !dbg !29 for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1526_count);
  llvm_cbe_tmp__504 = (signed long long *)(&llvm_cbe_tmp__493[(((signed long long )llvm_cbe_tmp__494))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__494));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%61, i64* %%70, align 8, !dbg !29 for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1527_count);
  *llvm_cbe_tmp__504 = llvm_cbe_tmp__499;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__499);
if (AESL_DEBUG_TRACE)
printf("\n  %%71 = add i64 %%55, 1, !dbg !30 for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1528_count);
  llvm_cbe_tmp__505 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__494&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__505&18446744073709551615ull)));
  llvm_cbe_tmp__507__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__505;   /* for PHI node */
  goto llvm_cbe__2e_loopexit;

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%.lcssa4 = phi i64 [ 0, %%._crit_edge9 ], [ %%75, %%.loopexit  for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe__2e_lcssa4_count);
  llvm_cbe__2e_lcssa4 = (unsigned long long )llvm_cbe__2e_lcssa4__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.lcssa4 = 0x%I64X",llvm_cbe__2e_lcssa4);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__507);
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @free(i8* %%6), !dbg !28 for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1562_count);
   /*tail*/ free(( char *)llvm_cbe_tmp__463);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%.lcssa4, i64* %%outputSize, align 8, !dbg !26 for 0x%I64xth hint within @aesl_internal_getRevealedMerkleNodes  --> \n", ++aesl_llvm_cbe_1563_count);
  *llvm_cbe_outputSize = llvm_cbe__2e_lcssa4;
if (AESL_DEBUG_TRACE)
printf("\n.lcssa4 = 0x%I64X\n", llvm_cbe__2e_lcssa4);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @aesl_internal_getRevealedMerkleNodes}\n");
  return llvm_cbe_tmp__493;
}


 char *openMerkleTree(l_struct_OC_tree_t *llvm_cbe_tree, signed short *llvm_cbe_missingLeaves, signed long long llvm_cbe_missingLeavesSize, signed long long *llvm_cbe_outputSizeBytes) {
  static  unsigned long long aesl_llvm_cbe_revealedSize_count = 0;
  signed long long llvm_cbe_revealedSize;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_1565_count = 0;
  static  unsigned long long aesl_llvm_cbe_1566_count = 0;
  static  unsigned long long aesl_llvm_cbe_1567_count = 0;
  static  unsigned long long aesl_llvm_cbe_1568_count = 0;
  static  unsigned long long aesl_llvm_cbe_1569_count = 0;
  static  unsigned long long aesl_llvm_cbe_1570_count = 0;
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
  signed long long *llvm_cbe_tmp__523;
  static  unsigned long long aesl_llvm_cbe_1587_count = 0;
  static  unsigned long long aesl_llvm_cbe_1588_count = 0;
  static  unsigned long long aesl_llvm_cbe_1589_count = 0;
  static  unsigned long long aesl_llvm_cbe_1590_count = 0;
  static  unsigned long long aesl_llvm_cbe_1591_count = 0;
  static  unsigned long long aesl_llvm_cbe_1592_count = 0;
  static  unsigned long long aesl_llvm_cbe_1593_count = 0;
  static  unsigned long long aesl_llvm_cbe_1594_count = 0;
  static  unsigned long long aesl_llvm_cbe_1595_count = 0;
  static  unsigned long long aesl_llvm_cbe_1596_count = 0;
  unsigned long long llvm_cbe_tmp__524;
  static  unsigned long long aesl_llvm_cbe_1597_count = 0;
  signed long long *llvm_cbe_tmp__525;
  static  unsigned long long aesl_llvm_cbe_1598_count = 0;
  unsigned long long llvm_cbe_tmp__526;
  static  unsigned long long aesl_llvm_cbe_1599_count = 0;
  unsigned long long llvm_cbe_tmp__527;
  static  unsigned long long aesl_llvm_cbe_1600_count = 0;
  static  unsigned long long aesl_llvm_cbe_1601_count = 0;
   char *llvm_cbe_tmp__528;
  static  unsigned long long aesl_llvm_cbe_1602_count = 0;
  static  unsigned long long aesl_llvm_cbe_1603_count = 0;
  static  unsigned long long aesl_llvm_cbe_1604_count = 0;
  static  unsigned long long aesl_llvm_cbe_1605_count = 0;
  static  unsigned long long aesl_llvm_cbe_1606_count = 0;
  static  unsigned long long aesl_llvm_cbe_1607_count = 0;
  static  unsigned long long aesl_llvm_cbe_1608_count = 0;
  static  unsigned long long aesl_llvm_cbe_1609_count = 0;
  static  unsigned long long aesl_llvm_cbe_1610_count = 0;
  static  unsigned long long aesl_llvm_cbe_1611_count = 0;
  static  unsigned long long aesl_llvm_cbe_1612_count = 0;
  static  unsigned long long aesl_llvm_cbe_1613_count = 0;
  static  unsigned long long aesl_llvm_cbe_1614_count = 0;
  static  unsigned long long aesl_llvm_cbe_1615_count = 0;
   char ***llvm_cbe_tmp__529;
  static  unsigned long long aesl_llvm_cbe_1616_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned long long llvm_cbe_storemerge1;
  unsigned long long llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_rec_count = 0;
  unsigned long long llvm_cbe__2e_rec;
  unsigned long long llvm_cbe__2e_rec__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1617_count = 0;
   char *llvm_cbe_tmp__530;
  static  unsigned long long aesl_llvm_cbe_1618_count = 0;
  signed long long *llvm_cbe_tmp__531;
  static  unsigned long long aesl_llvm_cbe_1619_count = 0;
  unsigned long long llvm_cbe_tmp__532;
  static  unsigned long long aesl_llvm_cbe_1620_count = 0;
   char **llvm_cbe_tmp__533;
  static  unsigned long long aesl_llvm_cbe_1621_count = 0;
   char **llvm_cbe_tmp__534;
  static  unsigned long long aesl_llvm_cbe_1622_count = 0;
   char *llvm_cbe_tmp__535;
  static  unsigned long long aesl_llvm_cbe_1623_count = 0;
  unsigned long long llvm_cbe_tmp__536;
  static  unsigned long long aesl_llvm_cbe_1624_count = 0;
   char *llvm_cbe_tmp__537;
  static  unsigned long long aesl_llvm_cbe__2e_rec2_count = 0;
  unsigned long long llvm_cbe__2e_rec2;
  static  unsigned long long aesl_llvm_cbe_1625_count = 0;
  unsigned long long llvm_cbe_tmp__538;
  static  unsigned long long aesl_llvm_cbe_1626_count = 0;
  static  unsigned long long aesl_llvm_cbe_1627_count = 0;
  static  unsigned long long aesl_llvm_cbe_1628_count = 0;
  static  unsigned long long aesl_llvm_cbe_1629_count = 0;
  static  unsigned long long aesl_llvm_cbe_1630_count = 0;
  static  unsigned long long aesl_llvm_cbe_1631_count = 0;
  static  unsigned long long aesl_llvm_cbe_1632_count = 0;
  static  unsigned long long aesl_llvm_cbe_1633_count = 0;
  static  unsigned long long aesl_llvm_cbe_1634_count = 0;
  static  unsigned long long aesl_llvm_cbe_1635_count = 0;
  static  unsigned long long aesl_llvm_cbe_1636_count = 0;
  unsigned long long llvm_cbe_tmp__539;
  static  unsigned long long aesl_llvm_cbe_1637_count = 0;
  static  unsigned long long aesl_llvm_cbe_1638_count = 0;
  static  unsigned long long aesl_llvm_cbe_1639_count = 0;
   char *llvm_cbe_tmp__540;
  static  unsigned long long aesl_llvm_cbe_1640_count = 0;
  static  unsigned long long aesl_llvm_cbe_1641_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @openMerkleTree\n");
if (AESL_DEBUG_TRACE)
printf("\n  store i64 0, i64* %%revealedSize, align 8, !dbg !26 for 0x%I64xth hint within @openMerkleTree  --> \n", ++aesl_llvm_cbe_1583_count);
  *(&llvm_cbe_revealedSize) = 0ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 0ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = call fastcc i64* @aesl_internal_getRevealedMerkleNodes(%%struct.tree_t* %%tree, i16* %%missingLeaves, i64 %%missingLeavesSize, i64* %%revealedSize), !dbg !24 for 0x%I64xth hint within @openMerkleTree  --> \n", ++aesl_llvm_cbe_1586_count);
  llvm_cbe_tmp__523 = (signed long long *)aesl_internal_getRevealedMerkleNodes((l_struct_OC_tree_t *)llvm_cbe_tree, (signed short *)llvm_cbe_missingLeaves, llvm_cbe_missingLeavesSize, (signed long long *)(&llvm_cbe_revealedSize));
if (AESL_DEBUG_TRACE) {
printf("\nArgument missingLeavesSize = 0x%I64X",llvm_cbe_missingLeavesSize);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__523);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i64* %%revealedSize, align 8, !dbg !24 for 0x%I64xth hint within @openMerkleTree  --> \n", ++aesl_llvm_cbe_1596_count);
  llvm_cbe_tmp__524 = (unsigned long long )*(&llvm_cbe_revealedSize);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__524);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.tree_t* %%tree, i64 0, i32 2, !dbg !24 for 0x%I64xth hint within @openMerkleTree  --> \n", ++aesl_llvm_cbe_1597_count);
  llvm_cbe_tmp__525 = (signed long long *)(&llvm_cbe_tree->field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i64* %%3, align 8, !dbg !24 for 0x%I64xth hint within @openMerkleTree  --> \n", ++aesl_llvm_cbe_1598_count);
  llvm_cbe_tmp__526 = (unsigned long long )*llvm_cbe_tmp__525;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__526);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = mul i64 %%4, %%2, !dbg !24 for 0x%I64xth hint within @openMerkleTree  --> \n", ++aesl_llvm_cbe_1599_count);
  llvm_cbe_tmp__527 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__526&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__524&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__527&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%5, i64* %%outputSizeBytes, align 8, !dbg !24 for 0x%I64xth hint within @openMerkleTree  --> \n", ++aesl_llvm_cbe_1600_count);
  *llvm_cbe_outputSizeBytes = llvm_cbe_tmp__527;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__527);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = call i8* @malloc(i64 %%5), !dbg !25 for 0x%I64xth hint within @openMerkleTree  --> \n", ++aesl_llvm_cbe_1601_count);
  llvm_cbe_tmp__528 = ( char *)( char *)malloc(llvm_cbe_tmp__527);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__527);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__528);
}
  if (((llvm_cbe_tmp__524&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    goto llvm_cbe__2e_lr_2e_ph;
  }

llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds %%struct.tree_t* %%tree, i64 0, i32 1, !dbg !24 for 0x%I64xth hint within @openMerkleTree  --> \n", ++aesl_llvm_cbe_1615_count);
  llvm_cbe_tmp__529 = ( char ***)(&llvm_cbe_tree->field1);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  llvm_cbe__2e_rec__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__541;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__541:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i64 [ 0, %%.lr.ph ], [ %%18, %%9  for 0x%I64xth hint within @openMerkleTree  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned long long )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",llvm_cbe_storemerge1);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__538);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec = phi i64 [ 0, %%.lr.ph ], [ %%.rec2, %%9  for 0x%I64xth hint within @openMerkleTree  --> \n", ++aesl_llvm_cbe__2e_rec_count);
  llvm_cbe__2e_rec = (unsigned long long )llvm_cbe__2e_rec__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.rec = 0x%I64X",llvm_cbe__2e_rec);
printf("\n = 0x%I64X",0ull);
printf("\n.rec2 = 0x%I64X",llvm_cbe__2e_rec2);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr i8* %%6, i64 %%.re for 0x%I64xth hint within @openMerkleTree  --> \n", ++aesl_llvm_cbe_1617_count);
  llvm_cbe_tmp__530 = ( char *)(&llvm_cbe_tmp__528[(((signed long long )llvm_cbe__2e_rec))]);
if (AESL_DEBUG_TRACE) {
printf("\n.rec = 0x%I64X",((signed long long )llvm_cbe__2e_rec));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds i64* %%1, i64 %%storemerge1, !dbg !24 for 0x%I64xth hint within @openMerkleTree  --> \n", ++aesl_llvm_cbe_1618_count);
  llvm_cbe_tmp__531 = (signed long long *)(&llvm_cbe_tmp__523[(((signed long long )llvm_cbe_storemerge1))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",((signed long long )llvm_cbe_storemerge1));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = load i64* %%11, align 8, !dbg !24 for 0x%I64xth hint within @openMerkleTree  --> \n", ++aesl_llvm_cbe_1619_count);
  llvm_cbe_tmp__532 = (unsigned long long )*llvm_cbe_tmp__531;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__532);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = load i8*** %%8, align 8, !dbg !24 for 0x%I64xth hint within @openMerkleTree  --> \n", ++aesl_llvm_cbe_1620_count);
  llvm_cbe_tmp__533 = ( char **)*llvm_cbe_tmp__529;
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds i8** %%13, i64 %%12, !dbg !24 for 0x%I64xth hint within @openMerkleTree  --> \n", ++aesl_llvm_cbe_1621_count);
  llvm_cbe_tmp__534 = ( char **)(&llvm_cbe_tmp__533[(((signed long long )llvm_cbe_tmp__532))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__532));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = load i8** %%14, align 8, !dbg !24 for 0x%I64xth hint within @openMerkleTree  --> \n", ++aesl_llvm_cbe_1622_count);
  llvm_cbe_tmp__535 = ( char *)*llvm_cbe_tmp__534;
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = load i64* %%3, align 8, !dbg !24 for 0x%I64xth hint within @openMerkleTree  --> \n", ++aesl_llvm_cbe_1623_count);
  llvm_cbe_tmp__536 = (unsigned long long )*llvm_cbe_tmp__525;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__536);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = call i8* @memcpy(i8* %%10, i8* %%15, i64 %%16 for 0x%I64xth hint within @openMerkleTree  --> \n", ++aesl_llvm_cbe_1624_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__530, ( char *)llvm_cbe_tmp__535, llvm_cbe_tmp__536);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__536);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__537);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec2 = add i64 %%.rec, %%16, !dbg !25 for 0x%I64xth hint within @openMerkleTree  --> \n", ++aesl_llvm_cbe__2e_rec2_count);
  llvm_cbe__2e_rec2 = (unsigned long long )((unsigned long long )(llvm_cbe__2e_rec&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__536&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.rec2 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_rec2&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = add i64 %%storemerge1, 1, !dbg !27 for 0x%I64xth hint within @openMerkleTree  --> \n", ++aesl_llvm_cbe_1625_count);
  llvm_cbe_tmp__538 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__538&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = load i64* %%revealedSize, align 8, !dbg !27 for 0x%I64xth hint within @openMerkleTree  --> \n", ++aesl_llvm_cbe_1636_count);
  llvm_cbe_tmp__539 = (unsigned long long )*(&llvm_cbe_revealedSize);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__539);
  if ((((unsigned long long )llvm_cbe_tmp__538&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__539&18446744073709551615ULL))) {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__538;   /* for PHI node */
    llvm_cbe__2e_rec__PHI_TEMPORARY = (unsigned long long )llvm_cbe__2e_rec2;   /* for PHI node */
    goto llvm_cbe_tmp__541;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = bitcast i64* %%1 to i8*, !dbg !26 for 0x%I64xth hint within @openMerkleTree  --> \n", ++aesl_llvm_cbe_1639_count);
  llvm_cbe_tmp__540 = ( char *)(( char *)llvm_cbe_tmp__523);
if (AESL_DEBUG_TRACE)
printf("\n  call void @free(i8* %%21), !dbg !26 for 0x%I64xth hint within @openMerkleTree  --> \n", ++aesl_llvm_cbe_1640_count);
  free(( char *)llvm_cbe_tmp__540);
if (AESL_DEBUG_TRACE) {
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @openMerkleTree}\n");
  return llvm_cbe_tmp__528;
}


signed int addMerkleNodes(l_struct_OC_tree_t *llvm_cbe_tree, signed short *llvm_cbe_missingLeaves, signed long long llvm_cbe_missingLeavesSize,  char *llvm_cbe_input, signed long long llvm_cbe_inputSize) {
  static  unsigned long long aesl_llvm_cbe_revealedSize_count = 0;
  signed long long llvm_cbe_revealedSize;    /* Address-exposed local */
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
  static  unsigned long long aesl_llvm_cbe_1658_count = 0;
  static  unsigned long long aesl_llvm_cbe_1659_count = 0;
  static  unsigned long long aesl_llvm_cbe_1660_count = 0;
  static  unsigned long long aesl_llvm_cbe_1661_count = 0;
  static  unsigned long long aesl_llvm_cbe_1662_count = 0;
  static  unsigned long long aesl_llvm_cbe_1663_count = 0;
  signed long long *llvm_cbe_tmp__542;
  static  unsigned long long aesl_llvm_cbe_1664_count = 0;
  unsigned long long llvm_cbe_tmp__543;
  static  unsigned long long aesl_llvm_cbe_1665_count = 0;
  static  unsigned long long aesl_llvm_cbe_1666_count = 0;
  static  unsigned long long aesl_llvm_cbe_1667_count = 0;
  static  unsigned long long aesl_llvm_cbe_1668_count = 0;
  static  unsigned long long aesl_llvm_cbe_1669_count = 0;
  static  unsigned long long aesl_llvm_cbe_1670_count = 0;
  static  unsigned long long aesl_llvm_cbe_1671_count = 0;
  unsigned int llvm_cbe_tmp__544;
  static  unsigned long long aesl_llvm_cbe_1672_count = 0;
  static  unsigned long long aesl_llvm_cbe_1673_count = 0;
  static  unsigned long long aesl_llvm_cbe_1674_count = 0;
  static  unsigned long long aesl_llvm_cbe_1675_count = 0;
  static  unsigned long long aesl_llvm_cbe_1676_count = 0;
  static  unsigned long long aesl_llvm_cbe_1677_count = 0;
  static  unsigned long long aesl_llvm_cbe_1678_count = 0;
  static  unsigned long long aesl_llvm_cbe_1679_count = 0;
  static  unsigned long long aesl_llvm_cbe_1680_count = 0;
  static  unsigned long long aesl_llvm_cbe_1681_count = 0;
  static  unsigned long long aesl_llvm_cbe_1682_count = 0;
  static  unsigned long long aesl_llvm_cbe_1683_count = 0;
  static  unsigned long long aesl_llvm_cbe_1684_count = 0;
  signed long long *llvm_cbe_tmp__545;
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
  unsigned long long llvm_cbe_tmp__546;
  static  unsigned long long aesl_llvm_cbe_1697_count = 0;
  unsigned int llvm_cbe_tmp__547;
  static  unsigned long long aesl_llvm_cbe_1698_count = 0;
  static  unsigned long long aesl_llvm_cbe_1699_count = 0;
  static  unsigned long long aesl_llvm_cbe_1700_count = 0;
  static  unsigned long long aesl_llvm_cbe_1701_count = 0;
  static  unsigned long long aesl_llvm_cbe_1702_count = 0;
  static  unsigned long long aesl_llvm_cbe_1703_count = 0;
  signed long long *llvm_cbe_tmp__548;
  static  unsigned long long aesl_llvm_cbe_1704_count = 0;
   char ***llvm_cbe_tmp__549;
  static  unsigned long long aesl_llvm_cbe_1705_count = 0;
   char **llvm_cbe_tmp__550;
  static  unsigned long long aesl_llvm_cbe_1706_count = 0;
  static  unsigned long long aesl_llvm_cbe_1707_count = 0;
  unsigned int llvm_cbe_tmp__551;
  unsigned int llvm_cbe_tmp__551__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_rec_count = 0;
  unsigned long long llvm_cbe__2e_rec;
  unsigned long long llvm_cbe__2e_rec__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge_count = 0;
  unsigned long long llvm_cbe_storemerge;
  unsigned long long llvm_cbe_storemerge__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1708_count = 0;
   char *llvm_cbe_tmp__552;
  static  unsigned long long aesl_llvm_cbe_1709_count = 0;
  static  unsigned long long aesl_llvm_cbe_1710_count = 0;
  static  unsigned long long aesl_llvm_cbe_1711_count = 0;
  static  unsigned long long aesl_llvm_cbe_1712_count = 0;
  static  unsigned long long aesl_llvm_cbe_1713_count = 0;
  static  unsigned long long aesl_llvm_cbe_1714_count = 0;
  static  unsigned long long aesl_llvm_cbe_1715_count = 0;
  static  unsigned long long aesl_llvm_cbe_1716_count = 0;
  static  unsigned long long aesl_llvm_cbe_1717_count = 0;
  static  unsigned long long aesl_llvm_cbe_1718_count = 0;
  static  unsigned long long aesl_llvm_cbe_1719_count = 0;
  unsigned long long llvm_cbe_tmp__553;
  static  unsigned long long aesl_llvm_cbe_1720_count = 0;
  static  unsigned long long aesl_llvm_cbe_1721_count = 0;
  static  unsigned long long aesl_llvm_cbe_1722_count = 0;
  unsigned long long llvm_cbe_tmp__554;
  static  unsigned long long aesl_llvm_cbe_1723_count = 0;
  unsigned int llvm_cbe_tmp__555;
  static  unsigned long long aesl_llvm_cbe_1724_count = 0;
  unsigned int llvm_cbe_tmp__556;
  static  unsigned long long aesl_llvm_cbe_1725_count = 0;
  static  unsigned long long aesl_llvm_cbe_1726_count = 0;
  static  unsigned long long aesl_llvm_cbe_1727_count = 0;
  static  unsigned long long aesl_llvm_cbe_1728_count = 0;
  static  unsigned long long aesl_llvm_cbe_1729_count = 0;
  static  unsigned long long aesl_llvm_cbe_1730_count = 0;
  static  unsigned long long aesl_llvm_cbe_1731_count = 0;
  signed long long *llvm_cbe_tmp__557;
  static  unsigned long long aesl_llvm_cbe_1732_count = 0;
  unsigned long long llvm_cbe_tmp__558;
  static  unsigned long long aesl_llvm_cbe_1733_count = 0;
   char **llvm_cbe_tmp__559;
  static  unsigned long long aesl_llvm_cbe_1734_count = 0;
   char **llvm_cbe_tmp__560;
  static  unsigned long long aesl_llvm_cbe_1735_count = 0;
   char *llvm_cbe_tmp__561;
  static  unsigned long long aesl_llvm_cbe_1736_count = 0;
   char *llvm_cbe_tmp__562;
  static  unsigned long long aesl_llvm_cbe_1737_count = 0;
  unsigned long long llvm_cbe_tmp__563;
  static  unsigned long long aesl_llvm_cbe__2e_rec4_count = 0;
  unsigned long long llvm_cbe__2e_rec4;
  static  unsigned long long aesl_llvm_cbe_1738_count = 0;
  unsigned long long llvm_cbe_tmp__564;
  static  unsigned long long aesl_llvm_cbe_1739_count = 0;
   char *llvm_cbe_tmp__565;
  static  unsigned long long aesl_llvm_cbe_1740_count = 0;
   char *llvm_cbe_tmp__566;
  static  unsigned long long aesl_llvm_cbe_1741_count = 0;
  static  unsigned long long aesl_llvm_cbe_1742_count = 0;
  unsigned long long llvm_cbe_tmp__567;
  static  unsigned long long aesl_llvm_cbe_1743_count = 0;
  static  unsigned long long aesl_llvm_cbe_1744_count = 0;
  static  unsigned long long aesl_llvm_cbe_1745_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e__count = 0;
  unsigned int llvm_cbe__2e_;
  static  unsigned long long aesl_llvm_cbe_1746_count = 0;
  static  unsigned long long aesl_llvm_cbe_1747_count = 0;
  unsigned int llvm_cbe_tmp__568;
  unsigned int llvm_cbe_tmp__568__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1748_count = 0;
   char *llvm_cbe_tmp__569;
  static  unsigned long long aesl_llvm_cbe_1749_count = 0;
  static  unsigned long long aesl_llvm_cbe_1750_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1751_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @addMerkleNodes\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.tree_t* %%tree, i64 0, i32 6, !dbg !24 for 0x%I64xth hint within @addMerkleNodes  --> \n", ++aesl_llvm_cbe_1663_count);
  llvm_cbe_tmp__542 = (signed long long *)(&llvm_cbe_tree->field6);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i64* %%1, align 8, !dbg !24 for 0x%I64xth hint within @addMerkleNodes  --> \n", ++aesl_llvm_cbe_1664_count);
  llvm_cbe_tmp__543 = (unsigned long long )*llvm_cbe_tmp__542;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__543);
  if ((((unsigned long long )llvm_cbe_tmp__543&18446744073709551615ULL) > ((unsigned long long )llvm_cbe_missingLeavesSize&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__570;
  } else {
    goto llvm_cbe_tmp__571;
  }

llvm_cbe_tmp__571:
if (AESL_DEBUG_TRACE)
printf("\n  call void @_assert(i8* getelementptr inbounds ([36 x i8]* @aesl_internal_.str9, i64 0, i64 0), i8* getelementptr inbounds ([60 x i8]* @aesl_internal_.str1, i64 0, i64 0), i32 517) nounwind, !dbg !26 for 0x%I64xth hint within @addMerkleNodes  --> \n", ++aesl_llvm_cbe_1667_count);
  _assert(( char *)((&aesl_internal__OC_str9[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 36
#endif
])), ( char *)((&aesl_internal__OC_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 60
#endif
])), 517u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",517u);
}
  goto llvm_cbe_tmp__570;

llvm_cbe_tmp__570:
  if ((((unsigned long long )llvm_cbe_inputSize&18446744073709551615ULL) > ((unsigned long long )2147483647ull&18446744073709551615ULL))) {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )4294967295u;   /* for PHI node */
    goto llvm_cbe_tmp__572;
  } else {
    goto llvm_cbe_tmp__573;
  }

llvm_cbe_tmp__573:
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = trunc i64 %%inputSize to i32, !dbg !26 for 0x%I64xth hint within @addMerkleNodes  --> \n", ++aesl_llvm_cbe_1671_count);
  llvm_cbe_tmp__544 = (unsigned int )((unsigned int )llvm_cbe_inputSize&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__544);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 0, i64* %%revealedSize, align 8, !dbg !27 for 0x%I64xth hint within @addMerkleNodes  --> \n", ++aesl_llvm_cbe_1683_count);
  *(&llvm_cbe_revealedSize) = 0ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 0ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = call fastcc i64* @aesl_internal_getRevealedMerkleNodes(%%struct.tree_t* %%tree, i16* %%missingLeaves, i64 %%missingLeavesSize, i64* %%revealedSize), !dbg !24 for 0x%I64xth hint within @addMerkleNodes  --> \n", ++aesl_llvm_cbe_1684_count);
  llvm_cbe_tmp__545 = (signed long long *)aesl_internal_getRevealedMerkleNodes((l_struct_OC_tree_t *)llvm_cbe_tree, (signed short *)llvm_cbe_missingLeaves, llvm_cbe_missingLeavesSize, (signed long long *)(&llvm_cbe_revealedSize));
if (AESL_DEBUG_TRACE) {
printf("\nArgument missingLeavesSize = 0x%I64X",llvm_cbe_missingLeavesSize);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__545);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = load i64* %%revealedSize, align 8, !dbg !27 for 0x%I64xth hint within @addMerkleNodes  --> \n", ++aesl_llvm_cbe_1696_count);
  llvm_cbe_tmp__546 = (unsigned long long )*(&llvm_cbe_revealedSize);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__546);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = call fastcc i32 @aesl_internal_contains(i64* %%9, i64 %%10, i64 0), !dbg !27 for 0x%I64xth hint within @addMerkleNodes  --> \n", ++aesl_llvm_cbe_1697_count);
  llvm_cbe_tmp__547 = (unsigned int )aesl_internal_contains((signed long long *)llvm_cbe_tmp__545, llvm_cbe_tmp__546, 0ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__546);
printf("\nArgument  = 0x%I64X",0ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__547);
}
  if (((llvm_cbe_tmp__547&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__574;
  } else {
    goto llvm_cbe_tmp__575;
  }

llvm_cbe_tmp__575:
if (AESL_DEBUG_TRACE)
printf("\n  call void @_assert(i8* getelementptr inbounds ([37 x i8]* @aesl_internal_.str10, i64 0, i64 0), i8* getelementptr inbounds ([60 x i8]* @aesl_internal_.str1, i64 0, i64 0), i32 526) nounwind, !dbg !27 for 0x%I64xth hint within @addMerkleNodes  --> \n", ++aesl_llvm_cbe_1700_count);
  _assert(( char *)((&aesl_internal__OC_str10[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 37
#endif
])), ( char *)((&aesl_internal__OC_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 60
#endif
])), 526u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",526u);
}
  goto llvm_cbe_tmp__574;

llvm_cbe_tmp__574:
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds %%struct.tree_t* %%tree, i64 0, i32 2, !dbg !24 for 0x%I64xth hint within @addMerkleNodes  --> \n", ++aesl_llvm_cbe_1703_count);
  llvm_cbe_tmp__548 = (signed long long *)(&llvm_cbe_tree->field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds %%struct.tree_t* %%tree, i64 0, i32 1, !dbg !25 for 0x%I64xth hint within @addMerkleNodes  --> \n", ++aesl_llvm_cbe_1704_count);
  llvm_cbe_tmp__549 = ( char ***)(&llvm_cbe_tree->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds %%struct.tree_t* %%tree, i64 0, i32 3, !dbg !25 for 0x%I64xth hint within @addMerkleNodes  --> \n", ++aesl_llvm_cbe_1705_count);
  llvm_cbe_tmp__550 = ( char **)(&llvm_cbe_tree->field3);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_tmp__551__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__544;   /* for PHI node */
  llvm_cbe__2e_rec__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  llvm_cbe_storemerge__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__576;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__576:
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = phi i32 [ %%8, %%14 ], [ %%26, %%28  for 0x%I64xth hint within @addMerkleNodes  --> \n", ++aesl_llvm_cbe_1707_count);
  llvm_cbe_tmp__551 = (unsigned int )llvm_cbe_tmp__551__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__551);
printf("\n = 0x%X",llvm_cbe_tmp__544);
printf("\n = 0x%X",llvm_cbe_tmp__556);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec = phi i64 [ 0, %%14 ], [ %%.rec4, %%28  for 0x%I64xth hint within @addMerkleNodes  --> \n", ++aesl_llvm_cbe__2e_rec_count);
  llvm_cbe__2e_rec = (unsigned long long )llvm_cbe__2e_rec__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.rec = 0x%I64X",llvm_cbe__2e_rec);
printf("\n = 0x%I64X",0ull);
printf("\n.rec4 = 0x%I64X",llvm_cbe__2e_rec4);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge = phi i64 [ 0, %%14 ], [ %%39, %%28  for 0x%I64xth hint within @addMerkleNodes  --> \n", ++aesl_llvm_cbe_storemerge_count);
  llvm_cbe_storemerge = (unsigned long long )llvm_cbe_storemerge__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge = 0x%I64X",llvm_cbe_storemerge);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__567);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = getelementptr i8* %%input, i64 %%.re for 0x%I64xth hint within @addMerkleNodes  --> \n", ++aesl_llvm_cbe_1708_count);
  llvm_cbe_tmp__552 = ( char *)(&llvm_cbe_input[(((signed long long )llvm_cbe__2e_rec))]);
if (AESL_DEBUG_TRACE) {
printf("\n.rec = 0x%I64X",((signed long long )llvm_cbe__2e_rec));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = load i64* %%revealedSize, align 8, !dbg !27 for 0x%I64xth hint within @addMerkleNodes  --> \n", ++aesl_llvm_cbe_1719_count);
  llvm_cbe_tmp__553 = (unsigned long long )*(&llvm_cbe_revealedSize);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__553);
  if ((((unsigned long long )llvm_cbe_storemerge&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__553&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__577;
  } else {
    goto llvm_cbe_tmp__578;
  }

llvm_cbe_tmp__579:
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = getelementptr inbounds i64* %%9, i64 %%storemerge, !dbg !25 for 0x%I64xth hint within @addMerkleNodes  --> \n", ++aesl_llvm_cbe_1731_count);
  llvm_cbe_tmp__557 = (signed long long *)(&llvm_cbe_tmp__545[(((signed long long )llvm_cbe_storemerge))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge = 0x%I64X",((signed long long )llvm_cbe_storemerge));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = load i64* %%29, align 8, !dbg !25 for 0x%I64xth hint within @addMerkleNodes  --> \n", ++aesl_llvm_cbe_1732_count);
  llvm_cbe_tmp__558 = (unsigned long long )*llvm_cbe_tmp__557;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__558);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = load i8*** %%16, align 8, !dbg !25 for 0x%I64xth hint within @addMerkleNodes  --> \n", ++aesl_llvm_cbe_1733_count);
  llvm_cbe_tmp__559 = ( char **)*llvm_cbe_tmp__549;
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = getelementptr inbounds i8** %%31, i64 %%30, !dbg !25 for 0x%I64xth hint within @addMerkleNodes  --> \n", ++aesl_llvm_cbe_1734_count);
  llvm_cbe_tmp__560 = ( char **)(&llvm_cbe_tmp__559[(((signed long long )llvm_cbe_tmp__558))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__558));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = load i8** %%32, align 8, !dbg !25 for 0x%I64xth hint within @addMerkleNodes  --> \n", ++aesl_llvm_cbe_1735_count);
  llvm_cbe_tmp__561 = ( char *)*llvm_cbe_tmp__560;
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = call i8* @memcpy(i8* %%33, i8* %%20, i64 %%24 for 0x%I64xth hint within @addMerkleNodes  --> \n", ++aesl_llvm_cbe_1736_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__561, ( char *)llvm_cbe_tmp__552, llvm_cbe_tmp__554);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__554);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__562);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = load i64* %%15, align 8, !dbg !25 for 0x%I64xth hint within @addMerkleNodes  --> \n", ++aesl_llvm_cbe_1737_count);
  llvm_cbe_tmp__563 = (unsigned long long )*llvm_cbe_tmp__548;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__563);
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec4 = add i64 %%.rec, %%35, !dbg !25 for 0x%I64xth hint within @addMerkleNodes  --> \n", ++aesl_llvm_cbe__2e_rec4_count);
  llvm_cbe__2e_rec4 = (unsigned long long )((unsigned long long )(llvm_cbe__2e_rec&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__563&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.rec4 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_rec4&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = load i64* %%29, align 8, !dbg !25 for 0x%I64xth hint within @addMerkleNodes  --> \n", ++aesl_llvm_cbe_1738_count);
  llvm_cbe_tmp__564 = (unsigned long long )*llvm_cbe_tmp__557;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__564);
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = load i8** %%17, align 8, !dbg !25 for 0x%I64xth hint within @addMerkleNodes  --> \n", ++aesl_llvm_cbe_1739_count);
  llvm_cbe_tmp__565 = ( char *)*llvm_cbe_tmp__550;
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = getelementptr inbounds i8* %%37, i64 %%36, !dbg !25 for 0x%I64xth hint within @addMerkleNodes  --> \n", ++aesl_llvm_cbe_1740_count);
  llvm_cbe_tmp__566 = ( char *)(&llvm_cbe_tmp__565[(((signed long long )llvm_cbe_tmp__564))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__564));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 1, i8* %%38, align 1, !dbg !25 for 0x%I64xth hint within @addMerkleNodes  --> \n", ++aesl_llvm_cbe_1741_count);
  *llvm_cbe_tmp__566 = ((unsigned char )1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )1));
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = add i64 %%storemerge, 1, !dbg !28 for 0x%I64xth hint within @addMerkleNodes  --> \n", ++aesl_llvm_cbe_1742_count);
  llvm_cbe_tmp__567 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__567&18446744073709551615ull)));
  llvm_cbe_tmp__551__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__556;   /* for PHI node */
  llvm_cbe__2e_rec__PHI_TEMPORARY = (unsigned long long )llvm_cbe__2e_rec4;   /* for PHI node */
  llvm_cbe_storemerge__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__567;   /* for PHI node */
  goto llvm_cbe_tmp__576;

llvm_cbe_tmp__577:
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = load i64* %%15, align 8, !dbg !24 for 0x%I64xth hint within @addMerkleNodes  --> \n", ++aesl_llvm_cbe_1722_count);
  llvm_cbe_tmp__554 = (unsigned long long )*llvm_cbe_tmp__548;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__554);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = trunc i64 %%24 to i32, !dbg !24 for 0x%I64xth hint within @addMerkleNodes  --> \n", ++aesl_llvm_cbe_1723_count);
  llvm_cbe_tmp__555 = (unsigned int )((unsigned int )llvm_cbe_tmp__554&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__555);
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = sub i32 %%19, %%25, !dbg !24 for 0x%I64xth hint within @addMerkleNodes  --> \n", ++aesl_llvm_cbe_1724_count);
  llvm_cbe_tmp__556 = (unsigned int )((unsigned int )(llvm_cbe_tmp__551&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__555&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__556&4294967295ull)));
  if ((((signed int )llvm_cbe_tmp__556) < ((signed int )0u))) {
    llvm_cbe_tmp__568__PHI_TEMPORARY = (unsigned int )4294967295u;   /* for PHI node */
    goto llvm_cbe__2e_loopexit;
  } else {
    goto llvm_cbe_tmp__579;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__578:
if (AESL_DEBUG_TRACE)
printf("\n  %%. = select i1 %%41, i32 0, i32 -1, !dbg !26 for 0x%I64xth hint within @addMerkleNodes  --> \n", ++aesl_llvm_cbe__2e__count);
  llvm_cbe__2e_ = (unsigned int )((((llvm_cbe_tmp__551&4294967295U) == (0u&4294967295U))) ? ((unsigned int )0u) : ((unsigned int )4294967295u));
if (AESL_DEBUG_TRACE)
printf("\n. = 0x%X\n", llvm_cbe__2e_);
  llvm_cbe_tmp__568__PHI_TEMPORARY = (unsigned int )llvm_cbe__2e_;   /* for PHI node */
  goto llvm_cbe__2e_loopexit;

llvm_cbe__2e_loopexit:
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = phi i32 [ %%., %%40 ], [ -1, %%23  for 0x%I64xth hint within @addMerkleNodes  --> \n", ++aesl_llvm_cbe_1747_count);
  llvm_cbe_tmp__568 = (unsigned int )llvm_cbe_tmp__568__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__568);
printf("\n. = 0x%X",llvm_cbe__2e_);
printf("\n = 0x%X",4294967295u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = bitcast i64* %%9 to i8*, !dbg !27 for 0x%I64xth hint within @addMerkleNodes  --> \n", ++aesl_llvm_cbe_1748_count);
  llvm_cbe_tmp__569 = ( char *)(( char *)llvm_cbe_tmp__545);
if (AESL_DEBUG_TRACE)
printf("\n  call void @free(i8* %%43), !dbg !27 for 0x%I64xth hint within @addMerkleNodes  --> \n", ++aesl_llvm_cbe_1749_count);
  free(( char *)llvm_cbe_tmp__569);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__568;   /* for PHI node */
  goto llvm_cbe_tmp__572;

llvm_cbe_tmp__572:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ %%42, %%.loopexit ], [ -1, %%5  for 0x%I64xth hint within @addMerkleNodes  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",llvm_cbe_tmp__568);
printf("\n = 0x%X",4294967295u);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @addMerkleNodes}\n");
  return llvm_cbe_storemerge1;
}


static signed int aesl_internal_contains(signed long long *llvm_cbe_list, signed long long llvm_cbe_len, signed long long llvm_cbe_value) {
  static  unsigned long long aesl_llvm_cbe_1752_count = 0;
  static  unsigned long long aesl_llvm_cbe_1753_count = 0;
  static  unsigned long long aesl_llvm_cbe_1754_count = 0;
  static  unsigned long long aesl_llvm_cbe_1755_count = 0;
  static  unsigned long long aesl_llvm_cbe_1756_count = 0;
  static  unsigned long long aesl_llvm_cbe_1757_count = 0;
  static  unsigned long long aesl_llvm_cbe_1758_count = 0;
  static  unsigned long long aesl_llvm_cbe_1759_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge_count = 0;
  unsigned long long llvm_cbe_storemerge;
  unsigned long long llvm_cbe_storemerge__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1760_count = 0;
  static  unsigned long long aesl_llvm_cbe_1761_count = 0;
  static  unsigned long long aesl_llvm_cbe_1762_count = 0;
  static  unsigned long long aesl_llvm_cbe_1763_count = 0;
  static  unsigned long long aesl_llvm_cbe_1764_count = 0;
  static  unsigned long long aesl_llvm_cbe_1765_count = 0;
  signed long long *llvm_cbe_tmp__580;
  static  unsigned long long aesl_llvm_cbe_1766_count = 0;
  unsigned long long llvm_cbe_tmp__581;
  static  unsigned long long aesl_llvm_cbe_1767_count = 0;
  static  unsigned long long aesl_llvm_cbe_1768_count = 0;
  unsigned long long llvm_cbe_tmp__582;
  static  unsigned long long aesl_llvm_cbe_1769_count = 0;
  static  unsigned long long aesl_llvm_cbe_1770_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1771_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @aesl_internal_contains\n");
  llvm_cbe_storemerge__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__583;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__583:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge = phi i64 [ 0, %%0 ], [ %%7, %%3  for 0x%I64xth hint within @aesl_internal_contains  --> \n", ++aesl_llvm_cbe_storemerge_count);
  llvm_cbe_storemerge = (unsigned long long )llvm_cbe_storemerge__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge = 0x%I64X",llvm_cbe_storemerge);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__582);
}
  if ((((unsigned long long )llvm_cbe_storemerge&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_len&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__584;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe_tmp__585;
  }

llvm_cbe_tmp__584:
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds i64* %%list, i64 %%storemerge, !dbg !24 for 0x%I64xth hint within @aesl_internal_contains  --> \n", ++aesl_llvm_cbe_1765_count);
  llvm_cbe_tmp__580 = (signed long long *)(&llvm_cbe_list[(((signed long long )llvm_cbe_storemerge))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge = 0x%I64X",((signed long long )llvm_cbe_storemerge));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load i64* %%4, align 8, !dbg !24 for 0x%I64xth hint within @aesl_internal_contains  --> \n", ++aesl_llvm_cbe_1766_count);
  llvm_cbe_tmp__581 = (unsigned long long )*llvm_cbe_tmp__580;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__581);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = add i64 %%storemerge, 1, !dbg !25 for 0x%I64xth hint within @aesl_internal_contains  --> \n", ++aesl_llvm_cbe_1768_count);
  llvm_cbe_tmp__582 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__582&18446744073709551615ull)));
  if (((llvm_cbe_tmp__581&18446744073709551615ULL) == (llvm_cbe_value&18446744073709551615ULL))) {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )1u;   /* for PHI node */
    goto llvm_cbe_tmp__585;
  } else {
    llvm_cbe_storemerge__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__582;   /* for PHI node */
    goto llvm_cbe_tmp__583;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__585:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ 1, %%3 ], [ 0, %%1  for 0x%I64xth hint within @aesl_internal_contains  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",1u);
printf("\n = 0x%X",0u);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @aesl_internal_contains}\n");
  return llvm_cbe_storemerge1;
}


signed int verifyMerkleTree(l_struct_OC_tree_t *llvm_cbe_tree,  char **llvm_cbe_leafData,  char *llvm_cbe_salt, l_struct_OC_paramset_t *llvm_cbe_params) {
  static  unsigned long long aesl_llvm_cbe_1772_count = 0;
  static  unsigned long long aesl_llvm_cbe_1773_count = 0;
  static  unsigned long long aesl_llvm_cbe_1774_count = 0;
  static  unsigned long long aesl_llvm_cbe_1775_count = 0;
  static  unsigned long long aesl_llvm_cbe_1776_count = 0;
  static  unsigned long long aesl_llvm_cbe_1777_count = 0;
  static  unsigned long long aesl_llvm_cbe_1778_count = 0;
  static  unsigned long long aesl_llvm_cbe_1779_count = 0;
  static  unsigned long long aesl_llvm_cbe_1780_count = 0;
  static  unsigned long long aesl_llvm_cbe_1781_count = 0;
  static  unsigned long long aesl_llvm_cbe_1782_count = 0;
  static  unsigned long long aesl_llvm_cbe_1783_count = 0;
  static  unsigned long long aesl_llvm_cbe_1784_count = 0;
  static  unsigned long long aesl_llvm_cbe_1785_count = 0;
  static  unsigned long long aesl_llvm_cbe_1786_count = 0;
  static  unsigned long long aesl_llvm_cbe_1787_count = 0;
  static  unsigned long long aesl_llvm_cbe_1788_count = 0;
  static  unsigned long long aesl_llvm_cbe_1789_count = 0;
  static  unsigned long long aesl_llvm_cbe_1790_count = 0;
  static  unsigned long long aesl_llvm_cbe_1791_count = 0;
  signed long long *llvm_cbe_tmp__586;
  static  unsigned long long aesl_llvm_cbe_1792_count = 0;
  unsigned long long llvm_cbe_tmp__587;
  static  unsigned long long aesl_llvm_cbe_1793_count = 0;
  signed long long *llvm_cbe_tmp__588;
  static  unsigned long long aesl_llvm_cbe_1794_count = 0;
  unsigned long long llvm_cbe_tmp__589;
  static  unsigned long long aesl_llvm_cbe_1795_count = 0;
  unsigned long long llvm_cbe_tmp__590;
  static  unsigned long long aesl_llvm_cbe_1796_count = 0;
  static  unsigned long long aesl_llvm_cbe_1797_count = 0;
  static  unsigned long long aesl_llvm_cbe_1798_count = 0;
  static  unsigned long long aesl_llvm_cbe_1799_count = 0;
  static  unsigned long long aesl_llvm_cbe_1800_count = 0;
  static  unsigned long long aesl_llvm_cbe_1801_count = 0;
   char **llvm_cbe_tmp__591;
  static  unsigned long long aesl_llvm_cbe_1802_count = 0;
   char ***llvm_cbe_tmp__592;
  static  unsigned long long aesl_llvm_cbe_1803_count = 0;
  signed long long *llvm_cbe_tmp__593;
  static  unsigned long long aesl_llvm_cbe_1804_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge_count = 0;
  unsigned long long llvm_cbe_storemerge;
  unsigned long long llvm_cbe_storemerge__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1805_count = 0;
  static  unsigned long long aesl_llvm_cbe_1806_count = 0;
  static  unsigned long long aesl_llvm_cbe_1807_count = 0;
  static  unsigned long long aesl_llvm_cbe_1808_count = 0;
  static  unsigned long long aesl_llvm_cbe_1809_count = 0;
  static  unsigned long long aesl_llvm_cbe_1810_count = 0;
  static  unsigned long long aesl_llvm_cbe_1811_count = 0;
  static  unsigned long long aesl_llvm_cbe_1812_count = 0;
  static  unsigned long long aesl_llvm_cbe_1813_count = 0;
  static  unsigned long long aesl_llvm_cbe_1814_count = 0;
  static  unsigned long long aesl_llvm_cbe_1815_count = 0;
  static  unsigned long long aesl_llvm_cbe_1816_count = 0;
  unsigned long long llvm_cbe_tmp__594;
  static  unsigned long long aesl_llvm_cbe_1817_count = 0;
  static  unsigned long long aesl_llvm_cbe_1818_count = 0;
  static  unsigned long long aesl_llvm_cbe_1819_count = 0;
   char **llvm_cbe_tmp__595;
  static  unsigned long long aesl_llvm_cbe_1820_count = 0;
   char *llvm_cbe_tmp__596;
  static  unsigned long long aesl_llvm_cbe_1821_count = 0;
  static  unsigned long long aesl_llvm_cbe_1822_count = 0;
  static  unsigned long long aesl_llvm_cbe_1823_count = 0;
  unsigned long long llvm_cbe_tmp__597;
  static  unsigned long long aesl_llvm_cbe_1824_count = 0;
   char *llvm_cbe_tmp__598;
  static  unsigned long long aesl_llvm_cbe_1825_count = 0;
   char *llvm_cbe_tmp__599;
  static  unsigned long long aesl_llvm_cbe_1826_count = 0;
  unsigned char llvm_cbe_tmp__600;
  static  unsigned long long aesl_llvm_cbe_1827_count = 0;
  static  unsigned long long aesl_llvm_cbe_1828_count = 0;
  static  unsigned long long aesl_llvm_cbe_1829_count = 0;
   char **llvm_cbe_tmp__601;
  static  unsigned long long aesl_llvm_cbe_1830_count = 0;
   char **llvm_cbe_tmp__602;
  static  unsigned long long aesl_llvm_cbe_1831_count = 0;
   char *llvm_cbe_tmp__603;
  static  unsigned long long aesl_llvm_cbe_1832_count = 0;
  unsigned long long llvm_cbe_tmp__604;
  static  unsigned long long aesl_llvm_cbe_1833_count = 0;
   char *llvm_cbe_tmp__605;
  static  unsigned long long aesl_llvm_cbe_1834_count = 0;
   char *llvm_cbe_tmp__606;
  static  unsigned long long aesl_llvm_cbe_1835_count = 0;
   char *llvm_cbe_tmp__607;
  static  unsigned long long aesl_llvm_cbe_1836_count = 0;
  static  unsigned long long aesl_llvm_cbe_1837_count = 0;
  static  unsigned long long aesl_llvm_cbe_1838_count = 0;
  unsigned long long llvm_cbe_tmp__608;
  static  unsigned long long aesl_llvm_cbe_1839_count = 0;
  static  unsigned long long aesl_llvm_cbe_1840_count = 0;
  static  unsigned long long aesl_llvm_cbe_1841_count = 0;
  unsigned long long llvm_cbe_tmp__609;
  static  unsigned long long aesl_llvm_cbe_1842_count = 0;
  unsigned int llvm_cbe_tmp__610;
  static  unsigned long long aesl_llvm_cbe_1843_count = 0;
  unsigned long long llvm_cbe_tmp__611;
  static  unsigned long long aesl_llvm_cbe_1844_count = 0;
  static  unsigned long long aesl_llvm_cbe_1845_count = 0;
  static  unsigned long long aesl_llvm_cbe_1846_count = 0;
  static  unsigned long long aesl_llvm_cbe_1847_count = 0;
  static  unsigned long long aesl_llvm_cbe_1848_count = 0;
  static  unsigned long long aesl_llvm_cbe_1849_count = 0;
  static  unsigned long long aesl_llvm_cbe_1850_count = 0;
  static  unsigned long long aesl_llvm_cbe_1851_count = 0;
  static  unsigned long long aesl_llvm_cbe_1852_count = 0;
  static  unsigned long long aesl_llvm_cbe_1853_count = 0;
  static  unsigned long long aesl_llvm_cbe_1854_count = 0;
  static  unsigned long long aesl_llvm_cbe_1855_count = 0;
  static  unsigned long long aesl_llvm_cbe_1856_count = 0;
  static  unsigned long long aesl_llvm_cbe_1857_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_count = 0;
  unsigned long long llvm_cbe_storemerge12;
  unsigned long long llvm_cbe_storemerge12__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1858_count = 0;
  static  unsigned long long aesl_llvm_cbe_1859_count = 0;
  unsigned long long llvm_cbe_tmp__612;
  static  unsigned long long aesl_llvm_cbe_1860_count = 0;
  static  unsigned long long aesl_llvm_cbe_1861_count = 0;
  static  unsigned long long aesl_llvm_cbe_1862_count = 0;
  static  unsigned long long aesl_llvm_cbe_1863_count = 0;
  static  unsigned long long aesl_llvm_cbe_1864_count = 0;
  static  unsigned long long aesl_llvm_cbe_1865_count = 0;
  static  unsigned long long aesl_llvm_cbe_1866_count = 0;
  static  unsigned long long aesl_llvm_cbe_1867_count = 0;
  static  unsigned long long aesl_llvm_cbe_1868_count = 0;
  static  unsigned long long aesl_llvm_cbe_1869_count = 0;
  static  unsigned long long aesl_llvm_cbe_1870_count = 0;
  static  unsigned long long aesl_llvm_cbe_1871_count = 0;
  static  unsigned long long aesl_llvm_cbe_1872_count = 0;
  static  unsigned long long aesl_llvm_cbe_1873_count = 0;
  static  unsigned long long aesl_llvm_cbe_1874_count = 0;
   char *llvm_cbe_tmp__613;
  static  unsigned long long aesl_llvm_cbe_1875_count = 0;
  unsigned char llvm_cbe_tmp__614;
  static  unsigned long long aesl_llvm_cbe_1876_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e__count = 0;
  unsigned int llvm_cbe__2e_;
  static  unsigned long long aesl_llvm_cbe_1877_count = 0;
  static  unsigned long long aesl_llvm_cbe_1878_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @verifyMerkleTree\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.tree_t* %%tree, i64 0, i32 5, !dbg !24 for 0x%I64xth hint within @verifyMerkleTree  --> \n", ++aesl_llvm_cbe_1791_count);
  llvm_cbe_tmp__586 = (signed long long *)(&llvm_cbe_tree->field5);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i64* %%1, align 8, !dbg !24 for 0x%I64xth hint within @verifyMerkleTree  --> \n", ++aesl_llvm_cbe_1792_count);
  llvm_cbe_tmp__587 = (unsigned long long )*llvm_cbe_tmp__586;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__587);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.tree_t* %%tree, i64 0, i32 6, !dbg !24 for 0x%I64xth hint within @verifyMerkleTree  --> \n", ++aesl_llvm_cbe_1793_count);
  llvm_cbe_tmp__588 = (signed long long *)(&llvm_cbe_tree->field6);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i64* %%3, align 8, !dbg !24 for 0x%I64xth hint within @verifyMerkleTree  --> \n", ++aesl_llvm_cbe_1794_count);
  llvm_cbe_tmp__589 = (unsigned long long )*llvm_cbe_tmp__588;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__589);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = sub i64 %%2, %%4, !dbg !24 for 0x%I64xth hint within @verifyMerkleTree  --> \n", ++aesl_llvm_cbe_1795_count);
  llvm_cbe_tmp__590 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__587&18446744073709551615ull)) - ((unsigned long long )(llvm_cbe_tmp__589&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__590&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds %%struct.tree_t* %%tree, i64 0, i32 3, !dbg !24 for 0x%I64xth hint within @verifyMerkleTree  --> \n", ++aesl_llvm_cbe_1801_count);
  llvm_cbe_tmp__591 = ( char **)(&llvm_cbe_tree->field3);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds %%struct.tree_t* %%tree, i64 0, i32 1, !dbg !25 for 0x%I64xth hint within @verifyMerkleTree  --> \n", ++aesl_llvm_cbe_1802_count);
  llvm_cbe_tmp__592 = ( char ***)(&llvm_cbe_tree->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds %%struct.tree_t* %%tree, i64 0, i32 2, !dbg !25 for 0x%I64xth hint within @verifyMerkleTree  --> \n", ++aesl_llvm_cbe_1803_count);
  llvm_cbe_tmp__593 = (signed long long *)(&llvm_cbe_tree->field2);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__615;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__615:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge = phi i64 [ 0, %%0 ], [ %%31, %%30  for 0x%I64xth hint within @verifyMerkleTree  --> \n", ++aesl_llvm_cbe_storemerge_count);
  llvm_cbe_storemerge = (unsigned long long )llvm_cbe_storemerge__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge = 0x%I64X",llvm_cbe_storemerge);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__608);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = load i64* %%3, align 8, !dbg !24 for 0x%I64xth hint within @verifyMerkleTree  --> \n", ++aesl_llvm_cbe_1816_count);
  llvm_cbe_tmp__594 = (unsigned long long )*llvm_cbe_tmp__588;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__594);
  if ((((unsigned long long )llvm_cbe_storemerge&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__594&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__616;
  } else {
    goto llvm_cbe_tmp__617;
  }

llvm_cbe_tmp__618:
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = add i64 %%storemerge, 1, !dbg !27 for 0x%I64xth hint within @verifyMerkleTree  --> \n", ++aesl_llvm_cbe_1838_count);
  llvm_cbe_tmp__608 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__608&18446744073709551615ull)));
  llvm_cbe_storemerge__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__608;   /* for PHI node */
  goto llvm_cbe_tmp__615;

llvm_cbe_tmp__616:
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds i8** %%leafData, i64 %%storemerge, !dbg !26 for 0x%I64xth hint within @verifyMerkleTree  --> \n", ++aesl_llvm_cbe_1819_count);
  llvm_cbe_tmp__595 = ( char **)(&llvm_cbe_leafData[(((signed long long )llvm_cbe_storemerge))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge = 0x%I64X",((signed long long )llvm_cbe_storemerge));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load i8** %%13, align 8, !dbg !26 for 0x%I64xth hint within @verifyMerkleTree  --> \n", ++aesl_llvm_cbe_1820_count);
  llvm_cbe_tmp__596 = ( char *)*llvm_cbe_tmp__595;
  if (((llvm_cbe_tmp__596) == ((( char *)/*NULL*/0)))) {
    goto llvm_cbe_tmp__618;
  } else {
    goto llvm_cbe_tmp__619;
  }

llvm_cbe_tmp__620:
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = load i8*** %%7, align 8, !dbg !25 for 0x%I64xth hint within @verifyMerkleTree  --> \n", ++aesl_llvm_cbe_1829_count);
  llvm_cbe_tmp__601 = ( char **)*llvm_cbe_tmp__592;
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = getelementptr inbounds i8** %%23, i64 %%17, !dbg !25 for 0x%I64xth hint within @verifyMerkleTree  --> \n", ++aesl_llvm_cbe_1830_count);
  llvm_cbe_tmp__602 = ( char **)(&llvm_cbe_tmp__601[(((signed long long )llvm_cbe_tmp__597))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__597));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = load i8** %%24, align 8, !dbg !25 for 0x%I64xth hint within @verifyMerkleTree  --> \n", ++aesl_llvm_cbe_1831_count);
  llvm_cbe_tmp__603 = ( char *)*llvm_cbe_tmp__602;
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = load i64* %%8, align 8, !dbg !25 for 0x%I64xth hint within @verifyMerkleTree  --> \n", ++aesl_llvm_cbe_1832_count);
  llvm_cbe_tmp__604 = (unsigned long long )*llvm_cbe_tmp__593;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__604);
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = call i8* @memcpy(i8* %%25, i8* %%14, i64 %%26 for 0x%I64xth hint within @verifyMerkleTree  --> \n", ++aesl_llvm_cbe_1833_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__603, ( char *)llvm_cbe_tmp__596, llvm_cbe_tmp__604);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__604);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__605);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = load i8** %%6, align 8, !dbg !25 for 0x%I64xth hint within @verifyMerkleTree  --> \n", ++aesl_llvm_cbe_1834_count);
  llvm_cbe_tmp__606 = ( char *)*llvm_cbe_tmp__591;
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = getelementptr inbounds i8* %%28, i64 %%17, !dbg !25 for 0x%I64xth hint within @verifyMerkleTree  --> \n", ++aesl_llvm_cbe_1835_count);
  llvm_cbe_tmp__607 = ( char *)(&llvm_cbe_tmp__606[(((signed long long )llvm_cbe_tmp__597))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__597));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 1, i8* %%29, align 1, !dbg !25 for 0x%I64xth hint within @verifyMerkleTree  --> \n", ++aesl_llvm_cbe_1836_count);
  *llvm_cbe_tmp__607 = ((unsigned char )1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )1));
  goto llvm_cbe_tmp__618;

llvm_cbe_tmp__619:
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = add i64 %%storemerge, %%5, !dbg !24 for 0x%I64xth hint within @verifyMerkleTree  --> \n", ++aesl_llvm_cbe_1823_count);
  llvm_cbe_tmp__597 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__590&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__597&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = load i8** %%6, align 8, !dbg !24 for 0x%I64xth hint within @verifyMerkleTree  --> \n", ++aesl_llvm_cbe_1824_count);
  llvm_cbe_tmp__598 = ( char *)*llvm_cbe_tmp__591;
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = getelementptr inbounds i8* %%18, i64 %%17, !dbg !24 for 0x%I64xth hint within @verifyMerkleTree  --> \n", ++aesl_llvm_cbe_1825_count);
  llvm_cbe_tmp__599 = ( char *)(&llvm_cbe_tmp__598[(((signed long long )llvm_cbe_tmp__597))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__597));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = load i8* %%19, align 1, !dbg !24 for 0x%I64xth hint within @verifyMerkleTree  --> \n", ++aesl_llvm_cbe_1826_count);
  llvm_cbe_tmp__600 = (unsigned char )*llvm_cbe_tmp__599;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__600);
  if (((llvm_cbe_tmp__600&255U) == (((unsigned char )1)&255U))) {
    goto llvm_cbe_tmp__621;
  } else {
    goto llvm_cbe_tmp__620;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__617:
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = load i64* %%1, align 8, !dbg !25 for 0x%I64xth hint within @verifyMerkleTree  --> \n", ++aesl_llvm_cbe_1841_count);
  llvm_cbe_tmp__609 = (unsigned long long )*llvm_cbe_tmp__586;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__609);
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = trunc i64 %%33 to i32, !dbg !25 for 0x%I64xth hint within @verifyMerkleTree  --> \n", ++aesl_llvm_cbe_1842_count);
  llvm_cbe_tmp__610 = (unsigned int )((unsigned int )llvm_cbe_tmp__609&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__610);
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = sext i32 %%34 to i64, !dbg !25 for 0x%I64xth hint within @verifyMerkleTree  --> \n", ++aesl_llvm_cbe_1843_count);
  llvm_cbe_tmp__611 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__610);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__611);
  if (((llvm_cbe_tmp__610&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__611;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12 = phi i64 [ %%37, %%.lr.ph ], [ %%35, %%32  for 0x%I64xth hint within @verifyMerkleTree  --> \n", ++aesl_llvm_cbe_storemerge12_count);
  llvm_cbe_storemerge12 = (unsigned long long )llvm_cbe_storemerge12__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%I64X",llvm_cbe_storemerge12);
printf("\n = 0x%I64X",llvm_cbe_tmp__612);
printf("\n = 0x%I64X",llvm_cbe_tmp__611);
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call fastcc void @aesl_internal_computeParentHash(%%struct.tree_t* %%tree, i64 %%storemerge12, i8* %%salt, %%struct.paramset_t* %%params), !dbg !25 for 0x%I64xth hint within @verifyMerkleTree  --> \n", ++aesl_llvm_cbe_1858_count);
   /*tail*/ aesl_internal_computeParentHash((l_struct_OC_tree_t *)llvm_cbe_tree, llvm_cbe_storemerge12, ( char *)llvm_cbe_salt, (l_struct_OC_paramset_t *)llvm_cbe_params);
if (AESL_DEBUG_TRACE) {
printf("\nArgument storemerge12 = 0x%I64X",llvm_cbe_storemerge12);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = add i64 %%storemerge12, -1, !dbg !27 for 0x%I64xth hint within @verifyMerkleTree  --> \n", ++aesl_llvm_cbe_1859_count);
  llvm_cbe_tmp__612 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge12&18446744073709551615ull)) + ((unsigned long long )(18446744073709551615ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__612&18446744073709551615ull)));
  if (((llvm_cbe_tmp__612&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__612;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = load i8** %%6, align 8, !dbg !25 for 0x%I64xth hint within @verifyMerkleTree  --> \n", ++aesl_llvm_cbe_1874_count);
  llvm_cbe_tmp__613 = ( char *)*llvm_cbe_tmp__591;
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = load i8* %%39, align 1, !dbg !25 for 0x%I64xth hint within @verifyMerkleTree  --> \n", ++aesl_llvm_cbe_1875_count);
  llvm_cbe_tmp__614 = (unsigned char )*llvm_cbe_tmp__613;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__614);
if (AESL_DEBUG_TRACE)
printf("\n  %%. = sext i1 %%41 to i32, !dbg !25 for 0x%I64xth hint within @verifyMerkleTree  --> \n", ++aesl_llvm_cbe__2e__count);
  llvm_cbe__2e_ = (unsigned int )((signed int )(0-((llvm_cbe_tmp__614&255U) == (((unsigned char )0)&255U))));
if (AESL_DEBUG_TRACE)
printf("\n. = 0x%X\n", llvm_cbe__2e_);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @verifyMerkleTree}\n");
  return llvm_cbe__2e_;
llvm_cbe_tmp__621:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @verifyMerkleTree}\n");
  return 4294967295u;
}

