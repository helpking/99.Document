#ifndef COMMON_H
#define COMMON_H

#include "include/common_types.h"
#include "include/memory_check.h"

/** \brief 全局宏定义 */
#define _INLINE inline

/** \brief new重定义宏 */
#define _MACRO_NEW(__FILE__, __LINE__) new
#define new _MACRO_NEW(__FILE__, __LINE__)

#endif // COMMON_H
