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
     * @brief システム日付を取得する(ミリ秒カウンター付き)
     * @param[in] isMSecCntFlg ミリ秒カウンターフラグ
     * @param[in] iMSec ミリ秒
     * @return システム日付
     */
    static const std::string getSystemDateTime(const bool isMSecCntFlg, TS64& iMSec);
    
    /**
     * @brief データ（__Dictionary）をダンプする
     * @param[in] iDictInfo データ
     * @param[in] iTabCnt タブカウント
     * @param[in] iKey キー
     * @param[in] iTotalMsg メッセージ
     */
    static const char* DumpDictionary(__Dictionary* iDictInfo,
                                      const TS32 iTabCnt = 0,
                                      const TChar* iKey = nullptr,
                                      const TChar* iTotalMsg = nullptr);
    
private:
    
    /**
     * @brief ダンプ開始マック文字列を取得する
     * @param[in] iTotalMsg メッセージ
     * @param[in] iTabCnt タブカウント
     * @param[in] iKey キー
     * @return　ダンプ開始マック文字列
     */
    static const char* AppendDumpStartMark(const char* iTotalMsg,
                                           const TS32 iTabCnt,
                                           const TChar* iKey = nullptr);
    
    /**
     * @brief ダンプ終了マック文字列を取得する
     * @param[in] iTotalMsg メッセージ
     * @param[in] iTabCnt タブカウント
     * @return　ダンプ終了マック文字列
     */
    static const char* AppendDumpEndMark(const TChar* iTotalMsg,
                                         const TS32 iTabCnt);
    
    /**
     * @brief タブカウントより、ダンプ用スペースを取得する
     * @param[in] iTotalMsg メッセージ
     * @param[in] iTabCnt タブカウント
     * @param[in] iLoopKey キー
     * @param[in] iLoopDetail 詳細メッセージ
     * @return　詳細メッセージ（スペース付き）
     */
    static const char* getDumpSpaceByTabCnt(const TChar* iTotalMsg,
                                            const TS32 iTabCnt,
                                            const TChar* iLoopKey,
                                            const TChar* iLoopDetail);
};

NS_END_NS_COMMON

#endif /* defined(___21_FirstSample__CommonLib__) */
