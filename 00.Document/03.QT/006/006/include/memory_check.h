#ifndef MEMORY_CHECK_H
#define MEMORY_CHECK_H

#include "include/common_types.h"
#include <stdio.h>
#include <iostream>

/**
 * \brief new操作符重载
 * \param[in] size 内存大小
 * \param[in] fileName 文件名
 * \param[in] lineNo 行号
 */
void *operator new(std::size_t size, const TChar* fileName, TS32 lineNo);

/**
 * \brief new[]操作符重载
 * \param[in] size 内存大小
 * \param[in] fileName 文件名
 * \param[in] lineNo 行号
 */
void *operator new[](std::size_t size, const TChar* fileName, TS32 lineNo);

/**
 * \brief 重载delete
 *        调用delete的时候，首先在表中查找当前指针的值，如果存在就删除
 *        expected-warning {{function previously declared with an explicit exception specification redeclared with an implicit exception specification}}
 * \param[in] ptr 内存指针
 */
void operator delete(void* ptr) throw();

/**
 * \brief 重载delete[]
 *        expected-warning {{function previously declared with an explicit exception specification redeclared with an implicit exception specification}}
 * \param[in] ptr 内存指针
 */
void operator delete[](void *ptr) throw();

static_assert(noexcept(operator delete(0)), "");
static_assert(noexcept(operator delete[](0)), "");

//#define new new(__FILE__, __LINE__)

#endif // MEMORY_CHECK_H
