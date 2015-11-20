//
//  UtilsLog.h
//  021.FirstSample
//
//  Created by 何 利強 on 2015/10/13.
//
//

#ifndef ___21_FirstSample__UtilsLog__
#define ___21_FirstSample__UtilsLog__

#include "CommonHeader.h"
#include <fstream>

NS_BEGIN_NS_COMMON_UTILS

/**
 * @brief ログ
 */
class UtilsLog
{
public:
    
    /**
     * @brief コンストラクタ
     */
    UtilsLog();
    
    /**
     * @brief デストラクタ
     */
    ~UtilsLog();
    
    /**
     * @brief ログ出力開始関数（ミリ秒カウント開始）
     * @param[in] iFuncName メソッド名
     * @param[in] iSourceRowNo ソース行番号
     */
    void OutputMSecCntStart(const TChar* iFuncName,
                            const TS16 iSourceRowNo);
    
    /**
     * @brief ログ出力開始関数（ミリ秒カウント終了）
     * @param[in] iFuncName メソッド名
     * @param[in] iSourceRowNo ソース行番号
     */
    void OutputMSecCntEnd(const TChar* iFuncName,
                          const TS16 iSourceRowNo);
    
    /**
     * @brief ログ(普通)の出力関数
     * @param[in] iFuncName メソッド名
     * @param[in] iSourceRowNo ソース行番号
     * @param[in] iFormat ログフォーマット
     */
    void OutputInfo(const TChar* iFuncName,
                    const TS16 iSourceRowNo,
                    const TChar* iFormat, ...);
    
    /**
     * @brief ログ(警告)の出力関数
     * @param[in] iFuncName メソッド名
     * @param[in] iSourceRowNo ソース行番号
     * @param[in] iFormat ログフォーマット
     */
    void OutputWarning(const TChar* iFuncName,
                       const TS16 iSourceRowNo,
                       const TChar* iFormat, ...);
    
    /**
     * @brief ログ(エラー)の出力関数
     * @param[in] iFuncName メソッド名
     * @param[in] iSourceRowNo ソース行番号
     * @param[in] iFormat ログフォーマット
     */
    void OutputError(const TChar* iFuncName,
                     const TS16 iSourceRowNo,
                     const TChar* iFormat, ...);
    
private:
    
    // ログファイル
    std::fstream logFile_;
    // ログカウント
    TS32 logCnt_;
    // ミリ秒カウンターステタース
    E_LOG_MSEC_CNT_STS logMSecCntStatus;
    // ログ出力用の時間（単位：ミリ秒）
    TS64 logLastTime;
    TS64 logNowTime;
    
    /**
     * @brief ログファイル名を取得する
     * @return ログファイル名
     */
    const std::string getLogFileName();
    
    /**
     * @brief ログ(普通)の出力関数
     * @param[in] iFormat ログフォーマット
     */
    void OutputInfo(const TChar* iFormat, ...);
    
    /**
     * @brief ログ(警告)の出力関数
     * @param[in] iFormat ログフォーマット
     */
    void OutputWarning(const TChar* iFormat, ...);
    
    /**
     * @brief ログ(エラー)の出力関数
     * @param[in] iFormat ログフォーマット
     */
    void OutputError(const TChar* iFormat, ...);
    
    /**
     * @brief ライン毎に、ログ(エラー)の出力関数
     * @param[in] iLogMsg ログメッセージ
     * @param[in] iMSecCntStatus ミリ秒カウンターステタース
     * @param[in] iLogType ログタイプ
     */
    void outputInline(const TChar* iLogMsg,
                      const E_LOG_MSEC_CNT_STS& iMSecCntStatus,
                      const E_LOG_TYPE iLogType = E_LOG_TYPE::E_INFO);
    
    /**
     * @brief ライン毎に、ログ(エラー)の出力関数
     * @param[in] iFuncName メソッド名
     * @param[in] iSourceRowNo ソース行番号
     * @param[in] iLogMsg ログメッセージ
     * @param[in] iMSecCntStatus ミリ秒カウンターステタース
     * @param[in] iLogType ログタイプ
     */
    void outputInline(const TChar* iFuncName,
                      const TS16 iSourceRowNo,
                      const TChar* iLogMsg,
                      const E_LOG_MSEC_CNT_STS& iMSecCntStatus,
                      const E_LOG_TYPE iLogType = E_LOG_TYPE::E_INFO);
    
    /**
     * @brief ログの出力関数
     * @param[in] iLogMsg ログメッセージ
     * @param[in] iMSecCntStatus ミリ秒カウンターステタース
     * @param[in] iLogType ログタイプ
     */
    void output(const TChar* iLogMsg,
                const E_LOG_MSEC_CNT_STS& iMSecCntStatus,
                const E_LOG_TYPE iLogType = E_LOG_TYPE::E_INFO);
    
    /**
     * @brief ログの出力関数
     * @param[in] iFuncName メソッド名
     * @param[in] iSourceRowNo ソース行番号
     * @param[in] iMSecCntStatus ミリ秒カウンターステタース
     * @param[in] iLogType ログタイプ
     */
    void outputSourceInfo(const TChar* iFuncName,
                          const TS16 iSourceRowNo,
                          const E_LOG_MSEC_CNT_STS& iMSecCntStatus,
                          const E_LOG_TYPE iLogType = E_LOG_TYPE::E_INFO);
    
    /**
     * @brief ミリ秒カウントアップかどうかの判定
     * @param[in] iMSecCntStatus ミリ秒カウンターステタース
     * @return true : ミリ秒をカウントする; false : ミリ秒をカウントしない
     */
    inline const bool isMSecCountUp(const E_LOG_MSEC_CNT_STS& iMSecCntStatus) const
    {
        return ( (E_LOG_MSEC_CNT_STS::E_INVALID < iMSecCntStatus) && (iMSecCntStatus < E_LOG_MSEC_CNT_STS::E_MAX) );
    };
    
};

NS_END_NS_COMMON_UTILS

#endif /* defined(___21_FirstSample__UtilsLog__) */
