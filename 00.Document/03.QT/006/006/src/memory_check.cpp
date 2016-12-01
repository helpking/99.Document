#include <malloc/malloc.h>
#include <stdlib.h>
#include "include/memory_check.h"

#include <iostream>

/**
 * \brief 存储信息定义
 */
typedef struct TMemInfo
{
    /** \brief 内存地址 */
    IntPtr ptr;
    /** \brief 文件名 */
    const TChar* fileName;
    /** \brief 行号 */
    TS32 lineNo;
}TMemInfo;

/** \brief 内存分配表 */
TMemInfo ptr_list[1024];
/** \brief 内存分配表项 */
TU32 ptrn = 0;

/** \brief 依据指针，查询记录这个分配的表项 */
TS32 find_ptr(void *p)
{
    for(TU32 i = 0; i < ptrn; i++)
    {
        if(ptr_list[i].ptr == p)
        {
            return i;
        }
    }
    return -1;
}

/** \brief 依据表项id，删除这个分配记录 */
void del_ptr(TU32 i) {
    while(i+1 < ptrn)
    {
        ptr_list[i] = ptr_list[i+1];
        i++;
    }
    ptrn--;
}

/** \brief 在程序退出前，检测是否有泄露 */
class process_end
{
public:
    ~process_end()
    {
        for(unsigned int i = 0; i < ptrn; i++)
        {
            printf("file: %s, line: %d Memory leak\n", ptr_list[i].fileName, ptr_list[i].lineNo);
        }
    }
};
/** \brief 用一个全局对象，在程序退出前，析构这个对象，然后检测开始 */
process_end pe;

/**
 * \brief new操作符重载
 * \param[in] size 内存大小
 * \param[in] fileName 文件名
 * \param[in] lineNo 行号
 */
void *operator new(size_t size, const TChar *fileName, TS32 lineNo) {

    void *p = malloc(size);

    ptr_list[ptrn].ptr = p;
    ptr_list[ptrn].fileName = fileName;
    ptr_list[ptrn].lineNo = lineNo;

    ptrn++;

    return p;
}

/**
 * \brief new[]操作符重载
 * \param[in] size 内存大小
 * \param[in] fileName 文件名
 * \param[in] lineNo 行号
 */
void *operator new[](size_t size, const TChar* fileName, TS32 lineNo) {
    return operator new(size, fileName, lineNo);
}

/**
 * \brief 重载delete
 *        调用delete的时候，首先在表中查找当前指针的值，如果存在就删除
 * \param[in] ptr 内存指针
 */
void operator delete(void* ptr) throw() {

    TS32 i = find_ptr(ptr);
    if(i >= 0)
    {
        free(ptr);
        del_ptr(i);
    }
    else
    {
        printf("delete unknown pointer\n");
    }
}

/**
 * \brief 重载delete[]
 * \param[in] ptr 内存指针
 */
void operator delete[](void *ptr) throw() {
    operator delete(ptr);
}
