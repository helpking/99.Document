//
//  CommonLib.h
//  021.FirstSample
//
//  Created by 何 利強 on 2015/10/13.
//
//

#ifndef ___21_FirstSample__CommonLib__
#define ___21_FirstSample__CommonLib__

#include "CommonHeader.h"

NS_BEGIN_NS_COMMON

/**
 * @brief 共通クラス
 */
class CommonLib
{
public:
    
    /**
     * @brief システム日付(YYYY/MM/DD HH:MM:SS)を取得する
     * @return システム日付
     */
    static const char* getSystemDateTime();
};

NS_END_NS_COMMON

#endif /* defined(___21_FirstSample__CommonLib__) */
