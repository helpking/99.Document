//
//  CommonHeader.h
//  021.FirstSample
//
//  Created by 何 利強 on 2015/10/17.
//
//

#ifndef _21_FirstSample_CommonHeader_h
#define _21_FirstSample_CommonHeader_h

#include "CommonMacro.h"

#ifdef COCOS2D_DEBUG

/**
 * @brief ログタイプ
 */
enum class E_LOG_TYPE
{
    E_INVALID,
    E_INFO,
    E_WARNING,
    E_ERROR,
    E_MAX
};

/**
 * @brief ログで、ミリ秒カウンターステタース
 */
enum class E_LOG_MSEC_CNT_STS
{
    E_INVALID,
    E_START,
    E_COUNTING,
    E_END,
    E_MAX
};

#endif

#endif
