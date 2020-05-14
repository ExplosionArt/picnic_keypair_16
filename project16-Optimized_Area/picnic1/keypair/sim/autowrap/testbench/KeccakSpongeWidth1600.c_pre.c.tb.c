// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.2 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
# 1 "C:/picnic_keypair_16-master/project16-Optimized_Area/sha3/KeccakSpongeWidth1600.c"
# 1 "C:/picnic_keypair_16-master/project16-Optimized_Area/sha3/KeccakSpongeWidth1600.c" 1
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 147 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:/picnic_keypair_16-master/project16-Optimized_Area/sha3/KeccakSpongeWidth1600.c" 2
# 16 "C:/picnic_keypair_16-master/project16-Optimized_Area/sha3/KeccakSpongeWidth1600.c"
# 1 "C:/picnic_keypair_16-master/project16-Optimized_Area/sha3/KeccakSpongeWidth1600.h" 1
# 19 "C:/picnic_keypair_16-master/project16-Optimized_Area/sha3/KeccakSpongeWidth1600.h"
# 1 "C:/picnic_keypair_16-master/project16-Optimized_Area/sha3/KeccakSponge-common.h" 1
# 19 "C:/picnic_keypair_16-master/project16-Optimized_Area/sha3/KeccakSponge-common.h"
# 1 "D:/Xilinx_Vivado/Vivado/2019.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\string.h" 1 3








# 1 "D:/Xilinx_Vivado/Vivado/2019.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 1 3
# 10 "D:/Xilinx_Vivado/Vivado/2019.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
# 1 "D:/Xilinx_Vivado/Vivado/2019.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include/_mingw_mac.h" 1 3
# 10 "D:/Xilinx_Vivado/Vivado/2019.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 2 3
# 277 "D:/Xilinx_Vivado/Vivado/2019.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
# 1 "D:/Xilinx_Vivado/Vivado/2019.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\vadefs.h" 1 3
# 13 "D:/Xilinx_Vivado/Vivado/2019.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\vadefs.h" 3
# 1 "D:/Xilinx_Vivado/Vivado/2019.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 1 3
# 674 "D:/Xilinx_Vivado/Vivado/2019.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
# 1 "D:/Xilinx_Vivado/Vivado/2019.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include/sdks/_mingw_directx.h" 1 3
# 674 "D:/Xilinx_Vivado/Vivado/2019.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 2 3

# 1 "D:/Xilinx_Vivado/Vivado/2019.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include/sdks/_mingw_ddk.h" 1 3
# 675 "D:/Xilinx_Vivado/Vivado/2019.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 2 3
# 13 "D:/Xilinx_Vivado/Vivado/2019.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\vadefs.h" 2 3


#pragma pack(push,_CRT_PACKING)








 typedef __builtin_va_list __gnuc_va_list;






  typedef __gnuc_va_list va_list;
# 102 "D:/Xilinx_Vivado/Vivado/2019.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\vadefs.h" 3
#pragma pack(pop)
# 277 "D:/Xilinx_Vivado/Vivado/2019.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 2 3


#pragma pack(push,_CRT_PACKING)
# 370 "D:/Xilinx_Vivado/Vivado/2019.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
__extension__ typedef unsigned long long size_t;
# 380 "D:/Xilinx_Vivado/Vivado/2019.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
__extension__ typedef long long ssize_t;
# 392 "D:/Xilinx_Vivado/Vivado/2019.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
__extension__ typedef long long intptr_t;
# 405 "D:/Xilinx_Vivado/Vivado/2019.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
__extension__ typedef unsigned long long uintptr_t;
# 418 "D:/Xilinx_Vivado/Vivado/2019.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
__extension__ typedef long long ptrdiff_t;
# 428 "D:/Xilinx_Vivado/Vivado/2019.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
typedef unsigned short wchar_t;







typedef unsigned short wint_t;
typedef unsigned short wctype_t;
# 456 "D:/Xilinx_Vivado/Vivado/2019.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
typedef int errno_t;




typedef long __time32_t;




__extension__ typedef long long __time64_t;







typedef __time64_t time_t;
# 607 "D:/Xilinx_Vivado/Vivado/2019.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
struct threadlocaleinfostruct;
struct threadmbcinfostruct;
typedef struct threadlocaleinfostruct *pthreadlocinfo;
typedef struct threadmbcinfostruct *pthreadmbcinfo;
struct __lc_time_data;

typedef struct localeinfo_struct {
  pthreadlocinfo locinfo;
  pthreadmbcinfo mbcinfo;
} _locale_tstruct,*_locale_t;



typedef struct tagLC_ID {
  unsigned short wLanguage;
  unsigned short wCountry;
  unsigned short wCodePage;
} LC_ID,*LPLC_ID;




typedef struct threadlocaleinfostruct {
  int refcount;
  unsigned int lc_codepage;
  unsigned int lc_collate_cp;
  unsigned long lc_handle[6];
  LC_ID lc_id[6];
  struct {
    char *locale;
    wchar_t *wlocale;
    int *refcount;
    int *wrefcount;
  } lc_category[6];
  int lc_clike;
  int mb_cur_max;
  int *lconv_intl_refcount;
  int *lconv_num_refcount;
  int *lconv_mon_refcount;
  struct lconv *lconv;
  int *ctype1_refcount;
  unsigned short *ctype1;
  const unsigned short *pctype;
  const unsigned char *pclmap;
  const unsigned char *pcumap;
  struct __lc_time_data *lc_time_curr;
} threadlocinfo;







const char *__mingw_get_crt_info (void);





#pragma pack(pop)
# 9 "D:/Xilinx_Vivado/Vivado/2019.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\string.h" 2 3
# 36 "D:/Xilinx_Vivado/Vivado/2019.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\string.h" 3
  __attribute__ ((__dllimport__)) void *__cdecl _memccpy(void *_Dst,const void *_Src,int _Val,size_t _MaxCount);
                void *__cdecl memchr(const void *_Buf ,int _Val,size_t _MaxCount);
  __attribute__ ((__dllimport__)) int __cdecl _memicmp(const void *_Buf1,const void *_Buf2,size_t _Size);
  __attribute__ ((__dllimport__)) int __cdecl _memicmp_l(const void *_Buf1,const void *_Buf2,size_t _Size,_locale_t _Locale);
  int __cdecl memcmp(const void *_Buf1,const void *_Buf2,size_t _Size);
  void *__cdecl memcpy(void * __restrict__ _Dst,const void * __restrict__ _Src,size_t _Size) ;
  void *__cdecl memset(void *_Dst,int _Val,size_t _Size);

  void *__cdecl memccpy(void *_Dst,const void *_Src,int _Val,size_t _Size) ;
  int __cdecl memicmp(const void *_Buf1,const void *_Buf2,size_t _Size) ;


  char *__cdecl _strset(char *_Str,int _Val) ;
  char *__cdecl _strset_l(char *_Str,int _Val,_locale_t _Locale) ;
  char *__cdecl strcpy(char * __restrict__ _Dest,const char * __restrict__ _Source);
  char *__cdecl strcat(char * __restrict__ _Dest,const char * __restrict__ _Source);
  int __cdecl strcmp(const char *_Str1,const char *_Str2);
  size_t __cdecl strlen(const char *_Str);
  size_t __cdecl strnlen(const char *_Str,size_t _MaxCount);
  void *__cdecl memmove(void *_Dst,const void *_Src,size_t _Size) ;
  __attribute__ ((__dllimport__)) char *__cdecl _strdup(const char *_Src);
                char *__cdecl strchr(const char *_Str,int _Val);
  __attribute__ ((__dllimport__)) int __cdecl _stricmp(const char *_Str1,const char *_Str2);
  __attribute__ ((__dllimport__)) int __cdecl _strcmpi(const char *_Str1,const char *_Str2);
  __attribute__ ((__dllimport__)) int __cdecl _stricmp_l(const char *_Str1,const char *_Str2,_locale_t _Locale);
  int __cdecl strcoll(const char *_Str1,const char *_Str2);
  __attribute__ ((__dllimport__)) int __cdecl _strcoll_l(const char *_Str1,const char *_Str2,_locale_t _Locale);
  __attribute__ ((__dllimport__)) int __cdecl _stricoll(const char *_Str1,const char *_Str2);
  __attribute__ ((__dllimport__)) int __cdecl _stricoll_l(const char *_Str1,const char *_Str2,_locale_t _Locale);
  __attribute__ ((__dllimport__)) int __cdecl _strncoll (const char *_Str1,const char *_Str2,size_t _MaxCount);
  __attribute__ ((__dllimport__)) int __cdecl _strncoll_l(const char *_Str1,const char *_Str2,size_t _MaxCount,_locale_t _Locale);
  __attribute__ ((__dllimport__)) int __cdecl _strnicoll (const char *_Str1,const char *_Str2,size_t _MaxCount);
  __attribute__ ((__dllimport__)) int __cdecl _strnicoll_l(const char *_Str1,const char *_Str2,size_t _MaxCount,_locale_t _Locale);
  size_t __cdecl strcspn(const char *_Str,const char *_Control);
  __attribute__ ((__dllimport__)) char *__cdecl _strerror(const char *_ErrMsg) ;
  char *__cdecl strerror(int) ;
  __attribute__ ((__dllimport__)) char *__cdecl _strlwr(char *_String) ;
  char *strlwr_l(char *_String,_locale_t _Locale) ;
  char *__cdecl strncat(char * __restrict__ _Dest,const char * __restrict__ _Source,size_t _Count) ;
  int __cdecl strncmp(const char *_Str1,const char *_Str2,size_t _MaxCount);
  __attribute__ ((__dllimport__)) int __cdecl _strnicmp(const char *_Str1,const char *_Str2,size_t _MaxCount);
  __attribute__ ((__dllimport__)) int __cdecl _strnicmp_l(const char *_Str1,const char *_Str2,size_t _MaxCount,_locale_t _Locale);
  char *strncpy(char * __restrict__ _Dest,const char * __restrict__ _Source,size_t _Count) ;
  __attribute__ ((__dllimport__)) char *__cdecl _strnset(char *_Str,int _Val,size_t _MaxCount) ;
  __attribute__ ((__dllimport__)) char *__cdecl _strnset_l(char *str,int c,size_t count,_locale_t _Locale) ;
                char *__cdecl strpbrk(const char *_Str,const char *_Control);
                char *__cdecl strrchr(const char *_Str,int _Ch);
  __attribute__ ((__dllimport__)) char *__cdecl _strrev(char *_Str);
  size_t __cdecl strspn(const char *_Str,const char *_Control);
                char *__cdecl strstr(const char *_Str,const char *_SubStr);
  char *__cdecl strtok(char * __restrict__ _Str,const char * __restrict__ _Delim) ;
  __attribute__ ((__dllimport__)) char *__cdecl _strupr(char *_String) ;
  __attribute__ ((__dllimport__)) char *_strupr_l(char *_String,_locale_t _Locale) ;
  size_t __cdecl strxfrm(char * __restrict__ _Dst,const char * __restrict__ _Src,size_t _MaxCount);
  __attribute__ ((__dllimport__)) size_t __cdecl _strxfrm_l(char * __restrict__ _Dst,const char * __restrict__ _Src,size_t _MaxCount,_locale_t _Locale);


  char *__cdecl strdup(const char *_Src) ;
  int __cdecl strcmpi(const char *_Str1,const char *_Str2) ;
  int __cdecl stricmp(const char *_Str1,const char *_Str2) ;
  char *__cdecl strlwr(char *_Str) ;
  int __cdecl strnicmp(const char *_Str1,const char *_Str,size_t _MaxCount) ;
  int __cdecl strncasecmp (const char *, const char *, size_t);
  int __cdecl strcasecmp (const char *, const char *);







  char *__cdecl strnset(char *_Str,int _Val,size_t _MaxCount) ;
  char *__cdecl strrev(char *_Str) ;
  char *__cdecl strset(char *_Str,int _Val) ;
  char *__cdecl strupr(char *_Str) ;





  __attribute__ ((__dllimport__)) wchar_t *__cdecl _wcsdup(const wchar_t *_Str);
  wchar_t *__cdecl wcscat(wchar_t * __restrict__ _Dest,const wchar_t * __restrict__ _Source) ;
                wchar_t *__cdecl wcschr(const wchar_t *_Str,wchar_t _Ch);
  int __cdecl wcscmp(const wchar_t *_Str1,const wchar_t *_Str2);
  wchar_t *__cdecl wcscpy(wchar_t * __restrict__ _Dest,const wchar_t * __restrict__ _Source) ;
  size_t __cdecl wcscspn(const wchar_t *_Str,const wchar_t *_Control);
  size_t __cdecl wcslen(const wchar_t *_Str);
  size_t __cdecl wcsnlen(const wchar_t *_Src,size_t _MaxCount);
  wchar_t *wcsncat(wchar_t * __restrict__ _Dest,const wchar_t * __restrict__ _Source,size_t _Count) ;
  int __cdecl wcsncmp(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount);
  wchar_t *wcsncpy(wchar_t * __restrict__ _Dest,const wchar_t * __restrict__ _Source,size_t _Count) ;
  wchar_t *__cdecl _wcsncpy_l(wchar_t * __restrict__ _Dest,const wchar_t * __restrict__ _Source,size_t _Count,_locale_t _Locale) ;
                wchar_t *__cdecl wcspbrk(const wchar_t *_Str,const wchar_t *_Control);
                wchar_t *__cdecl wcsrchr(const wchar_t *_Str,wchar_t _Ch);
  size_t __cdecl wcsspn(const wchar_t *_Str,const wchar_t *_Control);
                wchar_t *__cdecl wcsstr(const wchar_t *_Str,const wchar_t *_SubStr);
  wchar_t *__cdecl wcstok(wchar_t * __restrict__ _Str,const wchar_t * __restrict__ _Delim) ;
  __attribute__ ((__dllimport__)) wchar_t *__cdecl _wcserror(int _ErrNum) ;
  __attribute__ ((__dllimport__)) wchar_t *__cdecl __wcserror(const wchar_t *_Str) ;
  __attribute__ ((__dllimport__)) int __cdecl _wcsicmp(const wchar_t *_Str1,const wchar_t *_Str2);
  __attribute__ ((__dllimport__)) int __cdecl _wcsicmp_l(const wchar_t *_Str1,const wchar_t *_Str2,_locale_t _Locale);
  __attribute__ ((__dllimport__)) int __cdecl _wcsnicmp(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount);
  __attribute__ ((__dllimport__)) int __cdecl _wcsnicmp_l(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount,_locale_t _Locale);
  __attribute__ ((__dllimport__)) wchar_t *__cdecl _wcsnset(wchar_t *_Str,wchar_t _Val,size_t _MaxCount) ;
  __attribute__ ((__dllimport__)) wchar_t *__cdecl _wcsrev(wchar_t *_Str);
  __attribute__ ((__dllimport__)) wchar_t *__cdecl _wcsset(wchar_t *_Str,wchar_t _Val) ;
  __attribute__ ((__dllimport__)) wchar_t *__cdecl _wcslwr(wchar_t *_String) ;
  __attribute__ ((__dllimport__)) wchar_t *_wcslwr_l(wchar_t *_String,_locale_t _Locale) ;
  __attribute__ ((__dllimport__)) wchar_t *__cdecl _wcsupr(wchar_t *_String) ;
  __attribute__ ((__dllimport__)) wchar_t *_wcsupr_l(wchar_t *_String,_locale_t _Locale) ;
  size_t __cdecl wcsxfrm(wchar_t * __restrict__ _Dst,const wchar_t * __restrict__ _Src,size_t _MaxCount);
  __attribute__ ((__dllimport__)) size_t __cdecl _wcsxfrm_l(wchar_t * __restrict__ _Dst,const wchar_t * __restrict__ _Src,size_t _MaxCount,_locale_t _Locale);
  int __cdecl wcscoll(const wchar_t *_Str1,const wchar_t *_Str2);
  __attribute__ ((__dllimport__)) int __cdecl _wcscoll_l(const wchar_t *_Str1,const wchar_t *_Str2,_locale_t _Locale);
  __attribute__ ((__dllimport__)) int __cdecl _wcsicoll(const wchar_t *_Str1,const wchar_t *_Str2);
  __attribute__ ((__dllimport__)) int __cdecl _wcsicoll_l(const wchar_t *_Str1,const wchar_t *_Str2,_locale_t _Locale);
  __attribute__ ((__dllimport__)) int __cdecl _wcsncoll(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount);
  __attribute__ ((__dllimport__)) int __cdecl _wcsncoll_l(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount,_locale_t _Locale);
  __attribute__ ((__dllimport__)) int __cdecl _wcsnicoll(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount);
  __attribute__ ((__dllimport__)) int __cdecl _wcsnicoll_l(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount,_locale_t _Locale);


  wchar_t *__cdecl wcsdup(const wchar_t *_Str) ;

  int __cdecl wcsicmp(const wchar_t *_Str1,const wchar_t *_Str2) ;
  int __cdecl wcsnicmp(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount) ;
  wchar_t *__cdecl wcsnset(wchar_t *_Str,wchar_t _Val,size_t _MaxCount) ;
  wchar_t *__cdecl wcsrev(wchar_t *_Str) ;
  wchar_t *__cdecl wcsset(wchar_t *_Str,wchar_t _Val) ;
  wchar_t *__cdecl wcslwr(wchar_t *_Str) ;
  wchar_t *__cdecl wcsupr(wchar_t *_Str) ;
  int __cdecl wcsicoll(const wchar_t *_Str1,const wchar_t *_Str2) ;








# 1 "D:/Xilinx_Vivado/Vivado/2019.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\sec_api/string_s.h" 1 3








# 1 "D:/Xilinx_Vivado/Vivado/2019.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\string.h" 1 3
# 9 "D:/Xilinx_Vivado/Vivado/2019.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\sec_api/string_s.h" 2 3
# 175 "D:/Xilinx_Vivado/Vivado/2019.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\string.h" 2 3
# 20 "C:/picnic_keypair_16-master/project16-Optimized_Area/sha3/KeccakSponge-common.h" 2
# 1 "C:/picnic_keypair_16-master/project16-Optimized_Area/sha3/align.h" 1
# 21 "C:/picnic_keypair_16-master/project16-Optimized_Area/sha3/KeccakSponge-common.h" 2
# 20 "C:/picnic_keypair_16-master/project16-Optimized_Area/sha3/KeccakSpongeWidth1600.h" 2


# 1 "C:/picnic_keypair_16-master/project16-Optimized_Area/sha3/KeccakP-1600-SnP.h" 1
# 31 "C:/picnic_keypair_16-master/project16-Optimized_Area/sha3/KeccakP-1600-SnP.h"
void KeccakP1600_Initialize(void *state);
void KeccakP1600_AddByte(void *state, unsigned char data, unsigned int offset);
void KeccakP1600_AddBytes(void *state, const unsigned char *data, unsigned int offset, unsigned int length);
void KeccakP1600_OverwriteBytes(void *state, const unsigned char *data, unsigned int offset, unsigned int length);
void KeccakP1600_OverwriteWithZeroes(void *state, unsigned int byteCount);
void KeccakP1600_Permute_Nrounds(void *state, unsigned int nrounds);
void KeccakP1600_Permute_12rounds(void *state);
void KeccakP1600_Permute_24rounds(void *state);
void KeccakP1600_ExtractBytes(const void *state, unsigned char *data, unsigned int offset, unsigned int length);
void KeccakP1600_ExtractAndAddBytes(const void *state, const unsigned char *input, unsigned char *output, unsigned int offset, unsigned int length);
# 23 "C:/picnic_keypair_16-master/project16-Optimized_Area/sha3/KeccakSpongeWidth1600.h" 2
 __attribute__ ((aligned(8))) typedef struct KeccakWidth1600_SpongeInstanceStruct { unsigned char state[200]; unsigned int rate; unsigned int byteIOIndex; int squeezing; } KeccakWidth1600_SpongeInstance;
    int KeccakWidth1600_Sponge(unsigned int rate, unsigned int capacity, const unsigned char *input, size_t inputByteLen, unsigned char suffix, unsigned char *output, size_t outputByteLen); int KeccakWidth1600_SpongeInitialize(KeccakWidth1600_SpongeInstance *spongeInstance, unsigned int rate, unsigned int capacity); int KeccakWidth1600_SpongeAbsorb(KeccakWidth1600_SpongeInstance *spongeInstance, const unsigned char *data, size_t dataByteLen); int KeccakWidth1600_SpongeAbsorbLastFewBits(KeccakWidth1600_SpongeInstance *spongeInstance, unsigned char delimitedData); int KeccakWidth1600_SpongeSqueeze(KeccakWidth1600_SpongeInstance *spongeInstance, unsigned char *data, size_t dataByteLen);




    __attribute__ ((aligned(8))) typedef struct KeccakWidth1600_12rounds_SpongeInstanceStruct { unsigned char state[200]; unsigned int rate; unsigned int byteIOIndex; int squeezing; } KeccakWidth1600_12rounds_SpongeInstance;
    int KeccakWidth1600_12rounds_Sponge(unsigned int rate, unsigned int capacity, const unsigned char *input, size_t inputByteLen, unsigned char suffix, unsigned char *output, size_t outputByteLen); int KeccakWidth1600_12rounds_SpongeInitialize(KeccakWidth1600_12rounds_SpongeInstance *spongeInstance, unsigned int rate, unsigned int capacity); int KeccakWidth1600_12rounds_SpongeAbsorb(KeccakWidth1600_12rounds_SpongeInstance *spongeInstance, const unsigned char *data, size_t dataByteLen); int KeccakWidth1600_12rounds_SpongeAbsorbLastFewBits(KeccakWidth1600_12rounds_SpongeInstance *spongeInstance, unsigned char delimitedData); int KeccakWidth1600_12rounds_SpongeSqueeze(KeccakWidth1600_12rounds_SpongeInstance *spongeInstance, unsigned char *data, size_t dataByteLen);
# 17 "C:/picnic_keypair_16-master/project16-Optimized_Area/sha3/KeccakSpongeWidth1600.c" 2
# 65 "C:/picnic_keypair_16-master/project16-Optimized_Area/sha3/KeccakSpongeWidth1600.c"
int KeccakWidth1600_Sponge(unsigned int rate, unsigned int capacity, const unsigned char *input, size_t inputByteLen, unsigned char suffix, unsigned char *output, size_t outputByteLen)
{
    __attribute__ ((aligned(8))) unsigned char state[200];
    unsigned int partialBlock;
    const unsigned char *curInput = input;
    unsigned char *curOutput = output;
    unsigned int rateInBytes = rate/8;

    if (rate+capacity != 1600)
        return 1;
    if ((rate <= 0) || (rate > 1600) || ((rate % 8) != 0))
        return 1;
    if (suffix == 0)
        return 1;


                          ;
    KeccakP1600_Initialize(state);
# 94 "C:/picnic_keypair_16-master/project16-Optimized_Area/sha3/KeccakSpongeWidth1600.c"
    while(inputByteLen >= (size_t)rateInBytes) {



        KeccakP1600_AddBytes(state, curInput, 0, rateInBytes);
        KeccakP1600_Permute_24rounds(state);
        curInput += rateInBytes;
        inputByteLen -= rateInBytes;
    }


    partialBlock = (unsigned int)inputByteLen;



    KeccakP1600_AddBytes(state, curInput, 0, partialBlock);
# 120 "C:/picnic_keypair_16-master/project16-Optimized_Area/sha3/KeccakSpongeWidth1600.c"
    KeccakP1600_AddByte(state, suffix, partialBlock);

    if ((suffix >= 0x80) && (partialBlock == (rateInBytes-1)))
        KeccakP1600_Permute_24rounds(state);

    KeccakP1600_AddByte(state, 0x80, rateInBytes-1);
# 134 "C:/picnic_keypair_16-master/project16-Optimized_Area/sha3/KeccakSpongeWidth1600.c"
    KeccakP1600_Permute_24rounds(state);





    while(outputByteLen > (size_t)rateInBytes) {
        KeccakP1600_ExtractBytes(state, curOutput, 0, rateInBytes);
        KeccakP1600_Permute_24rounds(state);



        curOutput += rateInBytes;
        outputByteLen -= rateInBytes;
    }


    partialBlock = (unsigned int)outputByteLen;
    KeccakP1600_ExtractBytes(state, curOutput, 0, partialBlock);




    return 0;
}





int KeccakWidth1600_SpongeInitialize(KeccakWidth1600_SpongeInstance *instance, unsigned int rate, unsigned int capacity)
{
    if (rate+capacity != 1600)
        return 1;
    if ((rate <= 0) || (rate > 1600) || ((rate % 8) != 0))
        return 1;
                          ;
    KeccakP1600_Initialize(instance->state);
    instance->rate = rate;
    instance->byteIOIndex = 0;
    instance->squeezing = 0;

    return 0;
}



int KeccakWidth1600_SpongeAbsorb(KeccakWidth1600_SpongeInstance *instance, const unsigned char data[200], size_t dataByteLen)
{
    size_t i, j;
    int loop;
    unsigned int partialBlock;

    unsigned int rateInBytes = instance->rate/8;

    if (instance->squeezing)
        return 1;

    i = 0;

    while(i < dataByteLen) {
        if ((instance->byteIOIndex == 0) && (dataByteLen >= (i + rateInBytes))) {
# 206 "C:/picnic_keypair_16-master/project16-Optimized_Area/sha3/KeccakSpongeWidth1600.c"
                for(j=dataByteLen-i; j>=rateInBytes; j-=rateInBytes) {




                    for(loop=0;loop<rateInBytes;loop++)
                        KeccakP1600_AddByte(instance->state, data[loop], loop);
                    KeccakP1600_Permute_24rounds(instance->state);
                    data+=rateInBytes;
                }
                i = dataByteLen - j;



        }
        else {

            partialBlock = (dataByteLen - i);
            if (partialBlock+instance->byteIOIndex > rateInBytes)
                partialBlock = rateInBytes-instance->byteIOIndex;



            i += partialBlock;

            for(loop=0;loop<partialBlock;loop++)
                KeccakP1600_AddByte(instance->state, data[loop], (instance->byteIOIndex)+loop);


            data += partialBlock;
            instance->byteIOIndex += partialBlock;
            if (instance->byteIOIndex == rateInBytes) {
                KeccakP1600_Permute_24rounds(instance->state);
                instance->byteIOIndex = 0;
            }
        }
    }
    return 0;
}



int KeccakWidth1600_SpongeAbsorbLastFewBits(KeccakWidth1600_SpongeInstance *instance, unsigned char delimitedData)
{
    unsigned int rateInBytes = instance->rate/8;

    if (delimitedData == 0)
        return 1;
    if (instance->squeezing)
        return 1;
# 265 "C:/picnic_keypair_16-master/project16-Optimized_Area/sha3/KeccakSpongeWidth1600.c"
    KeccakP1600_AddByte(instance->state, delimitedData, instance->byteIOIndex);

    if ((delimitedData >= 0x80) && (instance->byteIOIndex == (rateInBytes-1)))
        KeccakP1600_Permute_24rounds(instance->state);

    KeccakP1600_AddByte(instance->state, 0x80, rateInBytes-1);
# 279 "C:/picnic_keypair_16-master/project16-Optimized_Area/sha3/KeccakSpongeWidth1600.c"
    KeccakP1600_Permute_24rounds(instance->state);
    instance->byteIOIndex = 0;
    instance->squeezing = 1;



    return 0;
}



int KeccakWidth1600_SpongeSqueeze(KeccakWidth1600_SpongeInstance *instance, unsigned char *data, size_t dataByteLen)
{
    size_t i, j;
    unsigned int partialBlock;
    unsigned int rateInBytes = instance->rate/8;
    unsigned char *curData;

    if (!instance->squeezing)
        KeccakWidth1600_SpongeAbsorbLastFewBits(instance, 0x01);

    i = 0;
    curData = data;
    while(i < dataByteLen) {
        if ((instance->byteIOIndex == rateInBytes) && (dataByteLen >= (i + rateInBytes))) {
            for(j=dataByteLen-i; j>=rateInBytes; j-=rateInBytes) {
                KeccakP1600_Permute_24rounds(instance->state);
                KeccakP1600_ExtractBytes(instance->state, curData, 0, rateInBytes);



                curData+=rateInBytes;
            }
            i = dataByteLen - j;
        }
        else {

            if (instance->byteIOIndex == rateInBytes) {
                KeccakP1600_Permute_24rounds(instance->state);
                instance->byteIOIndex = 0;
            }
            partialBlock = (unsigned int)(dataByteLen - i);
            if (partialBlock+instance->byteIOIndex > rateInBytes)
                partialBlock = rateInBytes-instance->byteIOIndex;
            i += partialBlock;

            KeccakP1600_ExtractBytes(instance->state, curData, instance->byteIOIndex, partialBlock);



            curData += partialBlock;
            instance->byteIOIndex += partialBlock;
        }
    }
    return 0;
}
# 402 "C:/picnic_keypair_16-master/project16-Optimized_Area/sha3/KeccakSpongeWidth1600.c"
int KeccakWidth1600_12rounds_Sponge(unsigned int rate, unsigned int capacity, const unsigned char *input, size_t inputByteLen, unsigned char suffix, unsigned char *output, size_t outputByteLen)
{
    __attribute__ ((aligned(8))) unsigned char state[200];
    unsigned int partialBlock;
    const unsigned char *curInput = input;
    unsigned char *curOutput = output;
    unsigned int rateInBytes = rate/8;

    if (rate+capacity != 1600)
        return 1;
    if ((rate <= 0) || (rate > 1600) || ((rate % 8) != 0))
        return 1;
    if (suffix == 0)
        return 1;


                          ;
    KeccakP1600_Initialize(state);
# 431 "C:/picnic_keypair_16-master/project16-Optimized_Area/sha3/KeccakSpongeWidth1600.c"
    while(inputByteLen >= (size_t)rateInBytes) {



        KeccakP1600_AddBytes(state, curInput, 0, rateInBytes);
        KeccakP1600_Permute_12rounds(state);
        curInput += rateInBytes;
        inputByteLen -= rateInBytes;
    }


    partialBlock = (unsigned int)inputByteLen;



    KeccakP1600_AddBytes(state, curInput, 0, partialBlock);
# 457 "C:/picnic_keypair_16-master/project16-Optimized_Area/sha3/KeccakSpongeWidth1600.c"
    KeccakP1600_AddByte(state, suffix, partialBlock);

    if ((suffix >= 0x80) && (partialBlock == (rateInBytes-1)))
        KeccakP1600_Permute_12rounds(state);

    KeccakP1600_AddByte(state, 0x80, rateInBytes-1);
# 471 "C:/picnic_keypair_16-master/project16-Optimized_Area/sha3/KeccakSpongeWidth1600.c"
    KeccakP1600_Permute_12rounds(state);





    while(outputByteLen > (size_t)rateInBytes) {
        KeccakP1600_ExtractBytes(state, curOutput, 0, rateInBytes);
        KeccakP1600_Permute_12rounds(state);



        curOutput += rateInBytes;
        outputByteLen -= rateInBytes;
    }


    partialBlock = (unsigned int)outputByteLen;
    KeccakP1600_ExtractBytes(state, curOutput, 0, partialBlock);




    return 0;
}





int KeccakWidth1600_12rounds_SpongeInitialize(KeccakWidth1600_12rounds_SpongeInstance *instance, unsigned int rate, unsigned int capacity)
{
    if (rate+capacity != 1600)
        return 1;
    if ((rate <= 0) || (rate > 1600) || ((rate % 8) != 0))
        return 1;
                          ;
    KeccakP1600_Initialize(instance->state);
    instance->rate = rate;
    instance->byteIOIndex = 0;
    instance->squeezing = 0;

    return 0;
}



int KeccakWidth1600_12rounds_SpongeAbsorb(KeccakWidth1600_12rounds_SpongeInstance *instance, const unsigned char data[200], size_t dataByteLen)
{
    size_t i, j;
    int loop;
    unsigned int partialBlock;

    unsigned int rateInBytes = instance->rate/8;

    if (instance->squeezing)
        return 1;

    i = 0;

    while(i < dataByteLen) {
        if ((instance->byteIOIndex == 0) && (dataByteLen >= (i + rateInBytes))) {
# 543 "C:/picnic_keypair_16-master/project16-Optimized_Area/sha3/KeccakSpongeWidth1600.c"
                for(j=dataByteLen-i; j>=rateInBytes; j-=rateInBytes) {




                    for(loop=0;loop<rateInBytes;loop++)
                        KeccakP1600_AddByte(instance->state, data[loop], loop);
                    KeccakP1600_Permute_12rounds(instance->state);
                    data+=rateInBytes;
                }
                i = dataByteLen - j;



        }
        else {

            partialBlock = (dataByteLen - i);
            if (partialBlock+instance->byteIOIndex > rateInBytes)
                partialBlock = rateInBytes-instance->byteIOIndex;



            i += partialBlock;

            for(loop=0;loop<partialBlock;loop++)
                KeccakP1600_AddByte(instance->state, data[loop], (instance->byteIOIndex)+loop);


            data += partialBlock;
            instance->byteIOIndex += partialBlock;
            if (instance->byteIOIndex == rateInBytes) {
                KeccakP1600_Permute_12rounds(instance->state);
                instance->byteIOIndex = 0;
            }
        }
    }
    return 0;
}



int KeccakWidth1600_12rounds_SpongeAbsorbLastFewBits(KeccakWidth1600_12rounds_SpongeInstance *instance, unsigned char delimitedData)
{
    unsigned int rateInBytes = instance->rate/8;

    if (delimitedData == 0)
        return 1;
    if (instance->squeezing)
        return 1;
# 602 "C:/picnic_keypair_16-master/project16-Optimized_Area/sha3/KeccakSpongeWidth1600.c"
    KeccakP1600_AddByte(instance->state, delimitedData, instance->byteIOIndex);

    if ((delimitedData >= 0x80) && (instance->byteIOIndex == (rateInBytes-1)))
        KeccakP1600_Permute_12rounds(instance->state);

    KeccakP1600_AddByte(instance->state, 0x80, rateInBytes-1);
# 616 "C:/picnic_keypair_16-master/project16-Optimized_Area/sha3/KeccakSpongeWidth1600.c"
    KeccakP1600_Permute_12rounds(instance->state);
    instance->byteIOIndex = 0;
    instance->squeezing = 1;



    return 0;
}



int KeccakWidth1600_12rounds_SpongeSqueeze(KeccakWidth1600_12rounds_SpongeInstance *instance, unsigned char *data, size_t dataByteLen)
{
    size_t i, j;
    unsigned int partialBlock;
    unsigned int rateInBytes = instance->rate/8;
    unsigned char *curData;

    if (!instance->squeezing)
        KeccakWidth1600_12rounds_SpongeAbsorbLastFewBits(instance, 0x01);

    i = 0;
    curData = data;
    while(i < dataByteLen) {
        if ((instance->byteIOIndex == rateInBytes) && (dataByteLen >= (i + rateInBytes))) {
            for(j=dataByteLen-i; j>=rateInBytes; j-=rateInBytes) {
                KeccakP1600_Permute_12rounds(instance->state);
                KeccakP1600_ExtractBytes(instance->state, curData, 0, rateInBytes);



                curData+=rateInBytes;
            }
            i = dataByteLen - j;
        }
        else {

            if (instance->byteIOIndex == rateInBytes) {
                KeccakP1600_Permute_12rounds(instance->state);
                instance->byteIOIndex = 0;
            }
            partialBlock = (unsigned int)(dataByteLen - i);
            if (partialBlock+instance->byteIOIndex > rateInBytes)
                partialBlock = rateInBytes-instance->byteIOIndex;
            i += partialBlock;

            KeccakP1600_ExtractBytes(instance->state, curData, instance->byteIOIndex, partialBlock);



            curData += partialBlock;
            instance->byteIOIndex += partialBlock;
        }
    }
    return 0;
}
