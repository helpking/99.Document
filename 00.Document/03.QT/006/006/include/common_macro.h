#ifndef COMMON_MACRO_H
#define COMMON_MACRO_H

#include "include/common_types.h"

/** \brief 全局宏定义 */
#define _INLINE inline

/** \brief 宏定义:声明Slots */
#define DECLARE_SLOT(targetAction) \
void on_##targetAction##_triggered()

/** \brief 宏定义:实现Slots */
#define APPLY_SLOT(className, targetAction) \
void className::on_##targetAction##_triggered()

///** \brief new重定义宏 */
//#define _MACRO_NEW(__FILE__, __LINE__) new
//#define new _MACRO_NEW(__FILE__, __LINE__)

#endif // COMMON_MACRO_H
