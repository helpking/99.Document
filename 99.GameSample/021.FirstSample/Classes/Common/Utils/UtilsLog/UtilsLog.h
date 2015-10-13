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
     * @brief ログ(普通)の出力関数
     */
    void OutputInfo(const char* iFormat, ...);
    
    /**
     * @brief ログ(警告)の出力関数
     */
    void OutputWarning(const char* iFormat, ...);
    
    /**
     * @brief ログ(エラー)の出力関数
     */
    void OutputError(const char* iFormat, ...);
    
private:
    
    // ログファイル
    std::fstream logFile;
    
    /**
     * @brief ログファイル名を取得する
     * @return ログファイル名
     */
    const std::string getLogFileName();
    
};

NS_END_NS_COMMON_UTILS

#endif /* defined(___21_FirstSample__UtilsLog__) */
