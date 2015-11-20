//
//  Common.cpp
//  021.FirstSample
//
//  Created by 何 利強 on 2015/10/13.
//
//

#include "CommonLib.h"
#include "AppMacroHeader.h"

USING_NS_CC;
USING_NS_COMMON;


/**
 * @brief システム日付を取得する(ミリ秒カウンター付き)
 * @param[in] isMSecCntFlg ミリ秒カウンターフラグ
 * @param[in] iMSec ミリ秒
 * @return システム日付
 */
const std::string CommonLib::getSystemDateTime(const bool isMSecCntFlg, TS64& iMSec)
{
    time_t now = time(NULL);
    tm* tm = localtime( &now );
    
    TChar buf[32];
    sprintf( buf, "%04d/%02d/%02d %02d:%02d:%02d",
            tm->tm_year+1900,
            tm->tm_mon+1,
            tm->tm_mday,
            tm->tm_hour,
            tm->tm_min,
            tm->tm_sec);
    
    if (isMSecCntFlg == true)
    {
        struct timeval tv;
        gettimeofday(&tv,NULL);
        
        iMSec = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
    }
    
    return std::string(buf);
}

/**
 * @brief データ（__Dictionary）をダンプする
 * @return iDictInfo データ
 * @return iTabCnt タブカウント
 * @param[in] iKey キー
 * @param[in] iTotalMsg メッセージ
 */
const char* CommonLib::DumpDictionary(__Dictionary* iDictInfo,
                                      const TS32 iTabCnt,
                                      const TChar* iKey,
                                      const TChar* iTotalMsg)
{

#ifdef COCOS2D_DEBUG
    
    // タブカウントの設定
    TS32 tabCntTmp = iTabCnt;
    
    // データの処理が始まる
    const TChar* retStrTmp = iTotalMsg;
    
    // ダンプ開始マック文字列を取得する
    retStrTmp = AppendDumpStartMark(retStrTmp, tabCntTmp, iKey);
    
    DictElement* loopEle = nullptr;
    CCDICT_FOREACH(iDictInfo, loopEle)
    {
        // String
        __String* strTmp = dynamic_cast<__String*>(loopEle->getObject());
        if (strTmp)
        {
            retStrTmp = getDumpSpaceByTabCnt(retStrTmp, tabCntTmp + 1, loopEle->getStrKey(), strTmp->getCString());
        }
        
        // Dictionary
        __Dictionary* dictTmp = dynamic_cast<__Dictionary*>(loopEle->getObject());
        if (dictTmp)
        {
            retStrTmp = DumpDictionary(dictTmp, tabCntTmp + 1, loopEle->getStrKey(), retStrTmp);
        }
    }
    
    // ダンプ終了マック文字列を取得する
    retStrTmp = AppendDumpEndMark(retStrTmp, tabCntTmp);
    
    return retStrTmp;
#endif
    return nullptr;
}

/**
 * @brief ダンプ開始マック文字列を取得する
 * @param[in] iTotalMsg メッセージ
 * @param[in] iTabCnt タブカウント
 * @param[in] iKey キー
 * @return　ダンプ開始マック文字列
 */
const char* CommonLib::AppendDumpStartMark(const TChar* iTotalMsg,
                                           const TS32 iTabCnt,
                                           const TChar* iKey)
{
    
    // スペースの処理
    TS32 spaceCnt = iTabCnt * 4;
    TChar spaceBuf[spaceCnt+1];
    memset(spaceBuf, 0x00000000, sizeof(spaceBuf));
    memset(spaceBuf, 0x00000020, sizeof(spaceBuf) - 1);
    
    __String* retStrTmp = nullptr;
    if (iKey)
    {
        if (iTotalMsg)
        {
            retStrTmp = __String::createWithFormat("%s%s%s:{\n", iTotalMsg, spaceBuf, iKey);
        }
        else
        {
            retStrTmp = __String::createWithFormat("%s%s:{\n", spaceBuf, iKey);
        }
    }
    else
    {
        if (iTotalMsg)
        {
            retStrTmp = __String::createWithFormat("%s%s{\n", iTotalMsg, spaceBuf);
        }
        else
        {
            retStrTmp = __String::createWithFormat("%s{\n", spaceBuf);
        }
    }
    
    
    return retStrTmp->getCString();
}

/**
 * @brief ダンプ終了マック文字列を取得する
 * @param[in] iTotalMsg メッセージ
 * @param[in] iTabCnt タブカウント
 * @return　ダンプ終了マック文字列
 */
const char* CommonLib::AppendDumpEndMark(const TChar* iTotalMsg,
                                         const TS32 iTabCnt)
{
    // スペースの処理
    TS32 spaceCnt = iTabCnt * 4;
    TChar spaceBuf[spaceCnt+1];
    memset(spaceBuf, 0x00000000, sizeof(spaceBuf));
    memset(spaceBuf, 0x00000020, sizeof(spaceBuf) - 1);
    
    __String* retStrTmp = nullptr;
    if (iTotalMsg)
    {
        retStrTmp = __String::createWithFormat("%s%s}\n", iTotalMsg, spaceBuf);
    }
    else
    {
        retStrTmp = __String::createWithFormat("%s}\n", spaceBuf);
    }
    
    
    return retStrTmp->getCString();
}

/**
 * @brief タブカウントより、ダンプ用スペースを取得する
 * @param[in] iTotalMsg メッセージ
 * @param[in] iTabCnt タブカウント
 * @param[in] iLoopKey キー
 * @param[in] iLoopDetail 詳細メッセージ
 * @return　詳細メッセージ（スペース付き）
 */
const char* CommonLib::getDumpSpaceByTabCnt(const TChar* iTotalMsg,
                                            const TS32 iTabCnt,
                                            const TChar* iLoopKey,
                                            const TChar* iLoopDetail)
{
    
    // スペースの処理
    TS32 spaceCnt = iTabCnt * 4;
    TChar spaceBuf[spaceCnt+1];
    memset(spaceBuf, 0x00000000, sizeof(spaceBuf));
    memset(spaceBuf, 0x00000020, sizeof(spaceBuf) - 1);
    
    __String* retStrTmp = nullptr;
    if (iTotalMsg)
    {
        retStrTmp = __String::createWithFormat("%s%s%s:%s\n", iTotalMsg, spaceBuf, iLoopKey, iLoopDetail);
    }
    else
    {
        retStrTmp = __String::createWithFormat("%s%s:%s\n", spaceBuf, iLoopKey, iLoopDetail);
    }
    
    
    return retStrTmp->getCString();
}