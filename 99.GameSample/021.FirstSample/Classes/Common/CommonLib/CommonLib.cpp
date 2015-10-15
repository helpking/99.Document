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
 * @brief システム日付(YYYY/MM/DD HH:MM:SS)を取得する
 * @return システム日付
 */
const char* CommonLib::getSystemDateTime()
{
    time_t now = time(NULL);
    tm* tm = localtime( &now );
    
    const float msec = double( clock() ) / CLOCKS_PER_SEC;
    char buf[32];
    sprintf( buf, "%04d/%02d/%02d %02d:%02d:%02d.%03d",
            tm->tm_year+1900,
            tm->tm_mon+1,
            tm->tm_mday,
            tm->tm_hour,
            tm->tm_min,
            tm->tm_sec,
            int( ( msec - int(msec) ) * 1000 ));
    
    return std::string(buf).c_str();
}

/**
 * @brief データ（__Dictionary）をダンプする
 * @return iDictInfo データ
 * @return iTabCnt タブカウント
 * @param[in] iKey キー
 * @param[in] iTotalMsg メッセージ
 */
const char* CommonLib::DumpDictionary(__Dictionary* iDictInfo,
                                      const int iTabCnt,
                                      const char* iKey,
                                      const char* iTotalMsg)
{

#ifdef COCOS2D_DEBUG
    
    // タブカウントの設定
    int tabCntTmp = iTabCnt;
    
    // データの処理が始まる
    const char* retStrTmp = iTotalMsg;
    
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
const char* CommonLib::AppendDumpStartMark(const char* iTotalMsg,
                                           const int iTabCnt,
                                           const char* iKey)
{
    
    // スペースの処理
    int spaceCnt = iTabCnt * 4;
    char spaceBuf[spaceCnt+1];
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
const char* CommonLib::AppendDumpEndMark(const char* iTotalMsg,
                                         const int iTabCnt)
{
    // スペースの処理
    int spaceCnt = iTabCnt * 4;
    char spaceBuf[spaceCnt+1];
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
const char* CommonLib::getDumpSpaceByTabCnt(const char* iTotalMsg,
                                            const int iTabCnt,
                                            const char* iLoopKey,
                                            const char* iLoopDetail)
{
    
    // スペースの処理
    int spaceCnt = iTabCnt * 4;
    char spaceBuf[spaceCnt+1];
    memset(spaceBuf, 0x00000000, sizeof(spaceBuf));
    memset(spaceBuf, 0x00000020, sizeof(spaceBuf) - 1);
    
    __String* retStrTmp = nullptr;
    if (iTotalMsg)
    {
        retStrTmp = __String::createWithFormat("%s%s%s(S):%s\n", iTotalMsg, spaceBuf, iLoopKey, iLoopDetail);
    }
    else
    {
        retStrTmp = __String::createWithFormat("%s%s(S):%s\n", spaceBuf, iLoopKey, iLoopDetail);
    }
    
    
    return retStrTmp->getCString();
}