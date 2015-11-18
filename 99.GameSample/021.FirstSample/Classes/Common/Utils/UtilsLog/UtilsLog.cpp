//
//  UtilsLog.cpp
//  021.FirstSample
//
//  Created by 何 利強 on 2015/10/13.
//
//

#include "UtilsLog.h"
#include "CommonLib.h"

USING_NS_COMMON_UTILS;

USING_NS_COMMON;

#define MAX_CHAR_BUFF_LEN                            16 * 1024

/**
 * @brief コンストラクタ
 */
UtilsLog::UtilsLog()
: logCnt_(0)
{
    const std::string outPutFilePath = FileUtils::getInstance()->getWritablePath() + this->getLogFileName();
    logFile_.open( outPutFilePath.c_str(),
                 std::ios::out );
    long mSec = -1;
    OutputInfo(false, mSec, "LogFile:%s", outPutFilePath.c_str());
}

/**
 * @brief デストラクタ
 */
UtilsLog::~UtilsLog()
{
    // ログファイルをクローズする
    logFile_.close();
}

/**
 * @brief ログ(普通)の出力関数
 * @param[in] isTimerCountFlg 日付フォーマット
 * @param[in] iMSec ミリ秒
 * @param[in] iFormat ログフォーマット
 */
void UtilsLog::OutputInfo(const bool isTimerCountFlg,
                          long& iMSec,
                          const char* iFormat, ...)
{
#ifdef COCOS2D_DEBUG
    
    // ログカウント
    ++logCnt_;
    
    const int kMaxLogLen = MAX_CHAR_BUFF_LEN;
    char szBuf[kMaxLogLen];
    
    va_list ap;
    va_start(ap, iFormat);
    vsnprintf(szBuf, kMaxLogLen, iFormat, ap);
    va_end(ap);
    
    outputInline(szBuf, isTimerCountFlg, iMSec);
#endif
}

/**
 * @brief ログの出力関数
 * @param[in] iFuncName メソッド名
 * @param[in] iSourceRowNo ソース行番号
 * @param[in] isTimerCountFlg 日付フォーマット
 * @param[in] iMSec ミリ秒
 * @param[in] iFormat ログフォーマット
 */
void UtilsLog::OutputInfo(const char* iFuncName,
                          const int iSourceRowNo,
                          const bool isTimerCountFlg,
                          long& iMSec,
                          const char* iFormat, ...)
{
#ifdef COCOS2D_DEBUG
    
    // ログカウント
    ++logCnt_;
    
    const int kMaxLogLen = MAX_CHAR_BUFF_LEN;
    char szBuf[kMaxLogLen];
    
    va_list ap;
    va_start(ap, iFormat);
    vsnprintf(szBuf, kMaxLogLen, iFormat, ap);
    va_end(ap);
    
    outputInline(iFuncName, iSourceRowNo, szBuf, isTimerCountFlg, iMSec);
#endif
}

/**
 * @brief ログ(警告)の出力関数
 * @param[in] isTimerCountFlg 日付フォーマット
 * @param[in] iMSec ミリ秒
 * @param[in] iFormat ログフォーマット
 */
void UtilsLog::OutputWarning(const bool isTimerCountFlg,
                             long& iMSec,
                             const char* iFormat, ...)
{
#ifdef COCOS2D_DEBUG
    
    // ログカウント
    ++logCnt_;
    
    const int kMaxLogLen = MAX_CHAR_BUFF_LEN;
    char szBuf[kMaxLogLen];
    
    va_list ap;
    va_start(ap, iFormat);
    vsnprintf(szBuf, kMaxLogLen, iFormat, ap);
    va_end(ap);
    
    outputInline(szBuf, isTimerCountFlg, iMSec, E_LOG_TYPE::E_WARNING);
#endif
}

/**
 * @brief ログ(警告)の出力関数
 * @param[in] iFuncName メソッド名
 * @param[in] iSourceRowNo ソース行番号
 * @param[in] isTimerCountFlg 日付フォーマット
 * @param[in] iMSec ミリ秒
 * @param[in] iFormat ログフォーマット
 */
void UtilsLog::OutputWarning(const char* iFuncName,
                             const int iSourceRowNo,
                             const bool isTimerCountFlg,
                             long& iMSec,
                             const char* iFormat, ...)
{
#ifdef COCOS2D_DEBUG
    
    // ログカウント
    ++logCnt_;
    
    const int kMaxLogLen = MAX_CHAR_BUFF_LEN;
    char szBuf[kMaxLogLen];
    
    va_list ap;
    va_start(ap, iFormat);
    vsnprintf(szBuf, kMaxLogLen, iFormat, ap);
    va_end(ap);
    
    outputInline(iFuncName, iSourceRowNo, szBuf, isTimerCountFlg, iMSec, E_LOG_TYPE::E_WARNING);
#endif
}

/**
 * @brief ログ(エラー)の出力関数
 * @param[in] isTimerCountFlg 日付フォーマット
 * @param[in] iMSec ミリ秒
 * @param[in] iFormat ログフォーマット
 */
void UtilsLog::OutputError(const bool isTimerCountFlg,
                           long& iMSec,
                           const char* iFormat, ...)
{
#ifdef COCOS2D_DEBUG
    
    // ログカウント
    ++logCnt_;
    
    const int kMaxLogLen = MAX_CHAR_BUFF_LEN;
    char szBuf[kMaxLogLen];
    
    va_list ap;
    va_start(ap, iFormat);
    vsnprintf(szBuf, kMaxLogLen, iFormat, ap);
    va_end(ap);
    
    outputInline(szBuf, isTimerCountFlg, iMSec, E_LOG_TYPE::E_ERROR);
#endif
}

/**
 * @brief ログ(エラー)の出力関数
 * @param[in] iFuncName メソッド名
 * @param[in] iSourceRowNo ソース行番号
 * @param[in] isTimerCountFlg 日付フォーマット
 * @param[in] iMSec ミリ秒
 * @param[in] iFormat ログフォーマット
 */
void UtilsLog::OutputError(const char* iFuncName,
                           const int iSourceRowNo,
                           const bool isTimerCountFlg,
                           long& iMSec,
                           const char* iFormat, ...)
{
#ifdef COCOS2D_DEBUG
    
    // ログカウント
    ++logCnt_;
    
    const int kMaxLogLen = MAX_CHAR_BUFF_LEN;
    char szBuf[kMaxLogLen];
    
    va_list ap;
    va_start(ap, iFormat);
    vsnprintf(szBuf, kMaxLogLen, iFormat, ap);
    va_end(ap);
    
    outputInline(iFuncName, iSourceRowNo, szBuf, isTimerCountFlg, iMSec, E_LOG_TYPE::E_ERROR);
#endif
}

/**
 * @brief ライン毎に、ログ(エラー)の出力関数
 * @param[in] iLogMsg ログメッセージ
 * @param[in] isTimerCountFlg 日付フォーマット
 * @param[in] iMSec ミリ秒
 * @param[in] iLogType ログタイプ
 */
void UtilsLog::outputInline(const char* iLogMsg,
                            const bool isTimerCountFlg,
                            long& iMSec,
                            const E_LOG_TYPE iLogType)
{
    std::string logTmp = iLogMsg;
    size_t findPosTmp = logTmp.find("\n");
    while (findPosTmp != std::string::npos )
    {
        logTmp.replace(findPosTmp, strlen("\n"), "¥n");
        findPosTmp = logTmp.find("\n");
    }
    
    std::string LineTmp = logTmp;
    size_t startPos = 0;
    findPosTmp = logTmp.find("¥n");
    while (findPosTmp != std::string::npos )
    {
        LineTmp = logTmp.substr(0, findPosTmp);
        
        this->output(LineTmp.c_str(), isTimerCountFlg, iMSec, iLogType);
        
        startPos = findPosTmp + strlen("¥n");
        logTmp = logTmp.substr(startPos);
        findPosTmp = logTmp.find("¥n");
    }
    
    if (logTmp.empty() == false)
    {
        this->output(logTmp.c_str(), isTimerCountFlg, iMSec, iLogType);
    }
    
}

/**
 * @brief ライン毎に、ログ(エラー)の出力関数
 * @param[in] iFuncName メソッド名
 * @param[in] iSourceRowNo ソース行番号
 * @param[in] iLogMsg ログメッセージ
 * @param[in] isTimerCountFlg 日付フォーマット
 * @param[in] iMSec ミリ秒
 * @param[in] iLogType ログタイプ
 */
void UtilsLog::outputInline(const char* iFuncName,
                            const int iSourceRowNo,
                            const char* iLogMsg,
                            const bool isTimerCountFlg,
                            long& iMSec,
                            const E_LOG_TYPE iLogType)
{
    if (iLogMsg == nullptr)
    {
        return;
    }
    
    // ソース情報を出力する
    this->outputSourceInfo(iFuncName, iSourceRowNo, isTimerCountFlg, iMSec, iLogType);
    
    std::string logTmp = iLogMsg;
    size_t findPosTmp = logTmp.find("\n");
    while (findPosTmp != std::string::npos )
    {
        logTmp.replace(findPosTmp, strlen("\n"), "¥n");
        findPosTmp = logTmp.find("\n");
    }
    
    std::string LineTmp = logTmp;
    size_t startPos = 0;
    findPosTmp = logTmp.find("¥n");
    while (findPosTmp != std::string::npos )
    {
        LineTmp = logTmp.substr(0, findPosTmp);
        
        this->output(LineTmp.c_str(), isTimerCountFlg, iMSec, iLogType);
        
        startPos = findPosTmp + strlen("¥n");
        logTmp = logTmp.substr(startPos);
        findPosTmp = logTmp.find("¥n");
    }
    
    if (logTmp.empty() == false)
    {
        this->output(logTmp.c_str(), isTimerCountFlg, iMSec, iLogType);
    }
}

/**
 * @brief ログの出力関数
 * @param[in] iLogMsg ログメッセージ
 * @param[in] isTimerCountFlg 日付フォーマット
 * @param[in] iMSec ミリ秒
 * @param[in] iLogType ログタイプ
 */
void UtilsLog::output(const char* iLogMsg,
                      const bool isTimerCountFlg,
                      long& iMSec,
                      const E_LOG_TYPE iLogType)
{
    const char* SystemDateTime = CommonLib::getSystemDateTime(isTimerCountFlg, iMSec).c_str();
    
    char BuffTmp[MAX_CHAR_BUFF_LEN];
    memset(BuffTmp, 0x00000000, sizeof(BuffTmp));
    
    switch (iLogType)
    {
        case E_LOG_TYPE::E_INFO:
            sprintf(BuffTmp, "[%s][%08lu][Info   ][Debug:C I/A]%s", SystemDateTime, this->logCnt_, iLogMsg);
            break;
        case E_LOG_TYPE::E_WARNING:
            sprintf(BuffTmp, "[%s][%08lu][Warning][Debug:C I/A]%s", SystemDateTime, this->logCnt_, iLogMsg);
            break;
        case E_LOG_TYPE::E_ERROR:
            sprintf(BuffTmp, "[%s][%08lu][Error  ][Debug:C I/A]%s", SystemDateTime, this->logCnt_, iLogMsg);
            break;
        default:
            break;
    }
    
    CCLOG("%s", BuffTmp);
    
    // ログファイルへ
    sprintf(BuffTmp, "%s\n", BuffTmp);
    logFile_.write(BuffTmp, strlen(BuffTmp));
    logFile_.flush();
}

/**
 * @brief ログの出力関数
 * @param[in] iFuncName メソッド名
 * @param[in] iSourceRowNo ソース行番号
 * @param[in] isTimerCountFlg 日付フォーマット
 * @param[in] iMSec ミリ秒
 * @param[in] iLogType ログタイプ
 */
void UtilsLog::outputSourceInfo(const char* iFuncName,
                                const int iSourceRowNo,
                                const bool isTimerCountFlg,
                                long& iMSec,
                                const E_LOG_TYPE iLogType)
{
    const char* SystemDateTime = CommonLib::getSystemDateTime(isTimerCountFlg, iMSec).c_str();
    
    char BuffTmp[MAX_CHAR_BUFF_LEN];
    memset(BuffTmp, 0x00000000, sizeof(BuffTmp));
    
    switch (iLogType)
    {
        case E_LOG_TYPE::E_INFO:
            sprintf(BuffTmp, "[%s][%08lu][Info   ][Debug:C I/A][Source:%s(R%d)]", SystemDateTime, this->logCnt_, iFuncName, iSourceRowNo);
            break;
        case E_LOG_TYPE::E_WARNING:
            sprintf(BuffTmp, "[%s][%08lu][Warning][Debug:C I/A][Source:%s(R%d)]", SystemDateTime, this->logCnt_, iFuncName, iSourceRowNo);
            break;
        case E_LOG_TYPE::E_ERROR:
            sprintf(BuffTmp, "[%s][%08lu][Error  ][Debug:C I/A][Source:%s(R%d)]", SystemDateTime, this->logCnt_, iFuncName, iSourceRowNo);
            break;
        default:
            break;
    }
    
    CCLOG("%s", BuffTmp);
    
    // ログファイルへ
    sprintf(BuffTmp, "%s\n", BuffTmp);
    logFile_.write(BuffTmp, strlen(BuffTmp));
    logFile_.flush();
}

/**
 * @brief ログファイル名を取得する
 * @return ログファイル名
 */
const std::string UtilsLog::getLogFileName()
{
    time_t now = time(NULL);
    tm* tm = localtime( &now );
    
    const float msec = double( clock() ) / CLOCKS_PER_SEC;
    char buf[32];
    sprintf( buf, "%04d%02d%02d_%02d%02d%02d%03d.log",
            tm->tm_year+1900,
            tm->tm_mon+1,
            tm->tm_mday,
            tm->tm_hour,
            tm->tm_min,
            tm->tm_sec,
            int( ( msec - int(msec) ) * 1000 ));
    
    std::string fileName = std::string(buf);
    
    return fileName;
}