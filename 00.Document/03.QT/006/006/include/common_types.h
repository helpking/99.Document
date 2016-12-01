#ifndef COMMON_TYPES_H
#define COMMON_TYPES_H

/**
 * \brief 基本变量重定义
 */
/**
 * \brief 8 bit signed
 */
#ifndef _INT8_T
#define _INT8_T
typedef	__signed char int8_t;
#endif /* _INT8_T */
typedef int8_t TS8;

#ifndef _UINT8_T
#define _UINT8_T
typedef unsigned char uint8_t;
#endif /* _UINT8_T */
/**
 * \brief 8 bit unsigned
 */
typedef uint8_t TU8;

#ifndef _INT16_T
#define _INT16_T
typedef	short int16_t;
#endif /* _INT16_T */
/**
 * \brief 16 bit signed
 */
typedef int16_t TS16;

#ifndef _UINT16_T
#define _UINT16_T
typedef unsigned short uint16_t;
#endif /* _UINT16_T */
/**
 * \brief 16 bit unsigned
 */
typedef uint16_t TU16;

#ifndef _INT32_T
#define _INT32_T
typedef	int	int32_t;
#endif /* _INT32_T */
/**
 * \brief 32 bit signed
 */
typedef int32_t TS32;

#ifndef _UINT32_T
#define _UINT32_T
typedef unsigned int uint32_t;
#endif /* _UINT32_T */
/**
 * \brief 32 bit unsigned
 */
typedef uint32_t TU32;

#ifndef _INT64_T
#define _INT64_T
typedef	long long int64_t;
#endif /* _INT64_T */
/**
 * \brief 64 bit signed
 */
typedef int64_t TS64;

#ifndef _UINT64_T
#define _UINT64_T
typedef unsigned long long uint64_t;
#endif /* _UINT64_T */
/**
 * \brief 64 bit unsigned
 */
typedef uint64_t TU64;

/**
 * \brief float
 */
typedef float TF32;
/**
 * \brief double
 */
typedef double TDouble;
/**
 * \brief byte
 */
typedef uint8_t TByte;

/**
 * \brief char
 */
typedef char TChar;

/**
 * \brief char
 */
typedef char16_t TChar16;

/**
 * \brief char
 */
typedef char32_t TChar36;

/**
 * \brief wchar
 */
typedef wchar_t TWchar;

/**
 * \brief intptr
 */
#ifdef intptr_t
  typedef intptr_t IntPtr;
#else
  typedef void* IntPtr;
#endif /* intptr_t */

/**
 *  \brief boolean
 */
typedef TS32 Bool;

#ifndef false
  /**
   *  \brief false
   */
  #define false  (0)
#endif  /* false */

#ifndef true
  /**
   *  \brief true
   */
  #define true  (1)
#endif  /* true */

/**
 * \brief 无效值
 */
const TS32 kValueInvalid = -1;

#endif // COMMON_TYPES_H
