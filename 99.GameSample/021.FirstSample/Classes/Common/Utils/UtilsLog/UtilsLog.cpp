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

#define MAX_CHAR_BUFF_LEN                            16*1024

/**
 * @brief コンストラクタ
 */
UtilsLog::UtilsLog()
: logCnt_(0)
, logLastTime(-1)
, logNowTime(-1)
, logMSecCntStatus(E_LOG_MSEC_CNT_STS::E_INVALID)
{
    const std::string outPutFilePath = FileUtils::getInstance()->getWritablePath() + this->getLogFileName();
    logFile_.open( outPutFilePath.c_str(),
                 std::ios::out );
    OutputInfo("LogFile:%s", outPutFilePath.c_str());
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
 * @brief ログ出力開始関数（ミリ秒カウント開始）
 * @param[in] iFuncName メソッド名
 * @param[in] iSourceRowNo ソース行番号
 * @param[in] iLogType ログタイプ
 */
void UtilsLog::OutputMSecCntStart(const char* iFuncName,
                                  const int iSourceRowNo,
                                  const E_LOG_TYPE iLogType)
{
#ifdef COCOS2D_DEBUG
    
    // ログカウント
    ++this->logCnt_;
    // ミリ秒カウンター開始フラグ
    this->logMSecCntStatus = E_LOG_MSEC_CNT_STS::E_START;
    // 対比された時間を初期化する
    this->logLastTime = -1;
    this->logNowTime = -1;
    
    // 開始ログを出力する
    outputInline(iFuncName, iSourceRowNo, nullptr, this->logMSecCntStatus, iLogType);
    
#endif
}

/**
 * @brief ログ出力開始関数（ミリ秒カウント終了）
 * @param[in] iFuncName メソッド名
 * @param[in] iSourceRowNo ソース行番号
 * @param[in] iLogType ログタイプ
 */
void UtilsLog::OutputMSecCntEnd(const char* iFuncName,
                                const int iSourceRowNo,
                                const E_LOG_TYPE iLogType)
{
#ifdef COCOS2D_DEBUG
    
    // ログカウント
    ++this->logCnt_;
    // ミリ秒カウンター開始フラグ
    this->logMSecCntStatus = E_LOG_MSEC_CNT_STS::E_END;
    
    // 開始ログを出力する
    outputInline(iFuncName, iSourceRowNo, nullptr, this->logMSecCntStatus, iLogType);
    
    // ミリ秒カウンター開始フラグ
    this->logMSecCntStatus = E_LOG_MSEC_CNT_STS::E_INVALID;
    // 対比された時間を初期化する
    this->logLastTime = -1;
    this->logNowTime = -1;
    
#endif
}

/**
 * @brief ログ(普通)の出力関数
 * @param[in] iFormat ログフォーマット
 */
void UtilsLog::OutputInfo(const char* iFormat, ...)
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
    
    outputInline(szBuf, E_LOG_MSEC_CNT_STS::E_INVALID);
    
#endif
}

/**
 * @brief ログの出力関数
 * @param[in] iFuncName メソッド名
 * @param[in] iSourceRowNo ソース行番号
 * @param[in] iFormat ログフォーマット
 */
void UtilsLog::OutputInfo(const char* iFuncName,
                          const int iSourceRowNo,
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
    
    if (E_LOG_MSEC_CNT_STS::E_START == this->logMSecCntStatus)
    {
        this->logMSecCntStatus = E_LOG_MSEC_CNT_STS::E_COUNTING;
    }
    outputInline(iFuncName, iSourceRowNo, szBuf, this->logMSecCntStatus);
#endif
}

/**
 * @brief ログ(警告)の出力関数
 * @param[in] iFormat ログフォーマット
 */
void UtilsLog::OutputWarning(const char* iFormat, ...)
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

    outputInline(szBuf, E_LOG_MSEC_CNT_STS::E_INVALID, E_LOG_TYPE::E_WARNING);
#endif
}

/**
 * @brief ログ(警告)の出力関数
 * @param[in] iFuncName メソッド名
 * @param[in] iSourceRowNo ソース行番号
 * @param[in] iFormat ログフォーマット
 */
void UtilsLog::OutputWarning(const char* iFuncName,
                             const int iSourceRowNo,
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
    
    if (E_LOG_MSEC_CNT_STS::E_START == this->logMSecCntStatus)
    {
        this->logMSecCntStatus = E_LOG_MSEC_CNT_STS::E_COUNTING;
    }
    outputInline(iFuncName, iSourceRowNo, szBuf,  this->logMSecCntStatus, E_LOG_TYPE::E_WARNING);
#endif
}

/**
 * @brief ログ(エラー)の出力関数
 * @param[in] iFormat ログフォーマット
 */
void UtilsLog::OutputError(const char* iFormat, ...)
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
    
    outputInline(szBuf, E_LOG_MSEC_CNT_STS::E_INVALID, E_LOG_TYPE::E_ERROR);
#endif
}

/**
 * @brief ログ(エラー)の出力関数
 * @param[in] iFuncName メソッド名
 * @param[in] iSourceRowNo ソース行番号
 * @param[in] iFormat ログフォーマット
 */
void UtilsLog::OutputError(const char* iFuncName,
                           const int iSourceRowNo,
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
    
    if (E_LOG_MSEC_CNT_STS::E_START == this->logMSecCntStatus)
    {
        this->logMSecCntStatus = E_LOG_MSEC_CNT_STS::E_COUNTING;
    }
    outputInline(iFuncName, iSourceRowNo, szBuf, this->logMSecCntStatus, E_LOG_TYPE::E_ERROR);
#endif
}

/**
 * @brief ライン毎に、ログ(エラー)の出力関数
 * @param[in] iLogMsg ログメッセージ
 * @param[in] iMSecCntStatus ミリ秒カウンターステタース
 * @param[in] iLogType ログタイプ
 */
void UtilsLog::outputInline(const char* iLogMsg,
                            const E_LOG_MSEC_CNT_STS& iMSecCntStatus,
                            const E_LOG_TYPE iLogType)
{
    
    if (nullptr == iLogMsg)
    {
        return;
    }
    
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
        
        this->output(LineTmp.c_str(), iMSecCntStatus, iLogType);
        
        startPos = findPosTmp + strlen("¥n");
        logTmp = logTmp.substr(startPos);
        findPosTmp = logTmp.find("¥n");
    }
    
    if (logTmp.empty() == false)
    {
        this->output(logTmp.c_str(), iMSecCntStatus, iLogType);
    }
    
}

/**
 * @brief ライン毎に、ログ(エラー)の出力関数
 * @param[in] iFuncName メソッド名
 * @param[in] iSourceRowNo ソース行番号
 * @param[in] iLogMsg ログメッセージ
 * @param[in] iMSecCntStatus ミリ秒カウンターステタース
 * @param[in] iLogType ログタイプ
 */
void UtilsLog::outputInline(const char* iFuncName,
                            const int iSourceRowNo,
                            const char* iLogMsg,
                            const E_LOG_MSEC_CNT_STS& iMSecCntStatus,
                            const E_LOG_TYPE iLogType)
{
    
    // ソース情報を出力する
    this->outputSourceInfo(iFuncName, iSourceRowNo, iMSecCntStatus, iLogType);
 
    if (nullptr != iLogMsg)
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
            
            this->output(LineTmp.c_str(), iMSecCntStatus, iLogType);
            
            startPos = findPosTmp + strlen("¥n");
            logTmp = logTmp.substr(startPos);
            findPosTmp = logTmp.find("¥n");
        }
        
        if (logTmp.empty() == false)
        {
            this->output(logTmp.c_str(), iMSecCntStatus, iLogType);
        }
    }
}

/**
 * @brief ログの出力関数
 * @param[in] iLogMsg ログメッセージ
 * @param[in] iMSecCntStatus ミリ秒カウンターステタース
 * @param[in] iLogType ログタイプ
 */
void UtilsLog::output(const char* iLogMsg,
                      const E_LOG_MSEC_CNT_STS& iMSecCntStatus,
                      const E_LOG_TYPE iLogType)
{
    if (nullptr == iLogMsg)
    {
        return;
    }
    
    const bool isMSecCntFlg = this->isMSecCountUp(iMSecCntStatus);
    const char* SystemDateTime = nullptr;
    if (-1 == this->logLastTime )
    {
        SystemDateTime = CommonLib::getSystemDateTime(isMSecCntFlg, this->logLastTime).c_str();
    }
    else
    {
        SystemDateTime = CommonLib::getSystemDateTime(isMSecCntFlg, this->logNowTime).c_str();
    }
    
    char BuffTmp[MAX_CHAR_BUFF_LEN];
    memset(BuffTmp, 0x00000000, sizeof(BuffTmp));
    
    int deltaTime = (int)(this->logNowTime - this->logLastTime);
    deltaTime = MAX(0, deltaTime);
    
    switch (iLogType)
    {
        case E_LOG_TYPE::E_INFO:
        {
            switch (iMSecCntStatus) {
                case E_LOG_MSEC_CNT_STS::E_START:
                    sprintf(BuffTmp, "[%s][%08lu][Info   ][Debug:C I/A][S+%03d ms]%s", SystemDateTime, this->logCnt_, deltaTime, iLogMsg);
                    break;
                case E_LOG_MSEC_CNT_STS::E_COUNTING:
                    sprintf(BuffTmp, "[%s][%08lu][Info   ][Debug:C I/A][ +%03d ms]%s", SystemDateTime, this->logCnt_, deltaTime, iLogMsg);
                    break;
                case E_LOG_MSEC_CNT_STS::E_END:
                    sprintf(BuffTmp, "[%s][%08lu][Info   ][Debug:C I/A][E+%03d ms]%s", SystemDateTime, this->logCnt_, deltaTime, iLogMsg);
                    break;
                default:
                    sprintf(BuffTmp, "[%s][%08lu][Info   ][Debug:C I/A]%s", SystemDateTime, this->logCnt_, iLogMsg);
                    break;
            }
        }
            break;
        case E_LOG_TYPE::E_WARNING:
        {
            switch (iMSecCntStatus) {
                case E_LOG_MSEC_CNT_STS::E_START:
                    sprintf(BuffTmp, "[%s][%08lu][Warning][Debug:C I/A][S+%03d ms]%s", SystemDateTime, this->logCnt_, deltaTime, iLogMsg);
                    break;
                case E_LOG_MSEC_CNT_STS::E_COUNTING:
                    sprintf(BuffTmp, "[%s][%08lu][Warning][Debug:C I/A][ +%03d ms]%s", SystemDateTime, this->logCnt_, deltaTime, iLogMsg);
                    break;
                case E_LOG_MSEC_CNT_STS::E_END:
                    sprintf(BuffTmp, "[%s][%08lu][Warning][Debug:C I/A][E+%03d ms]%s", SystemDateTime, this->logCnt_, deltaTime, iLogMsg);
                    break;
                default:
                    sprintf(BuffTmp, "[%s][%08lu][Warning][Debug:C I/A]%s", SystemDateTime, this->logCnt_, iLogMsg);
                    break;
            }
        }
            break;
        case E_LOG_TYPE::E_ERROR:
        {
            switch (iMSecCntStatus) {
                case E_LOG_MSEC_CNT_STS::E_START:
                    sprintf(BuffTmp, "[%s][%08lu][Error  ][Debug:C I/A][S+%03d ms]%s", SystemDateTime, this->logCnt_, deltaTime, iLogMsg);
                    break;
                case E_LOG_MSEC_CNT_STS::E_COUNTING:
                    sprintf(BuffTmp, "[%s][%08lu][Error  ][Debug:C I/A][ +%03d ms]%s", SystemDateTime, this->logCnt_, deltaTime, iLogMsg);
                    break;
                case E_LOG_MSEC_CNT_STS::E_END:
                    sprintf(BuffTmp, "[%s][%08lu][Error  ][Debug:C I/A][E+%03d ms]%s", SystemDateTime, this->logCnt_, deltaTime, iLogMsg);
                    break;
                default:
                    sprintf(BuffTmp, "[%s][%08lu][Error  ][Debug:C I/A]%s", SystemDateTime, this->logCnt_, iLogMsg);
                    break;
            }
        }
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
 * @param[in] iMSecCntStatus ミリ秒カウンターステタース
 * @param[in] iLogType ログタイプ
 */
void UtilsLog::outputSourceInfo(const char* iFuncName,
                                const int iSourceRowNo,
                                const E_LOG_MSEC_CNT_STS& iMSecCntStatus,
                                const E_LOG_TYPE iLogType)
{
    
    const bool isMSecCntFlg = this->isMSecCountUp(iMSecCntStatus);
    
    const char* SystemDateTime = nullptr;
    if (-1 == this->logLastTime )
    {
        SystemDateTime = CommonLib::getSystemDateTime(isMSecCntFlg, this->logLastTime).c_str();
    }
    else
    {
        SystemDateTime = CommonLib::getSystemDateTime(isMSecCntFlg, this->logNowTime).c_str();
    }
    
    char BuffTmp[MAX_CHAR_BUFF_LEN];
    memset(BuffTmp, 0x00000000, sizeof(BuffTmp));
    
    int deltaTime = (int)(this->logNowTime - this->logLastTime);
    deltaTime = MAX(0, deltaTime);
    
    switch (iLogType)
    {
        case E_LOG_TYPE::E_INFO:
        {
            switch (iMSecCntStatus) {
                case E_LOG_MSEC_CNT_STS::E_START:
                    sprintf(BuffTmp, "[%s][%08lu][Info   ][Debug:C I/A][S+%03d ms][Source:%s(R%d)]", SystemDateTime, this->logCnt_, deltaTime, iFuncName, iSourceRowNo);
                    break;
                case E_LOG_MSEC_CNT_STS::E_COUNTING:
                    sprintf(BuffTmp, "[%s][%08lu][Info   ][Debug:C I/A][ +%03d ms][Source:%s(R%d)]", SystemDateTime, this->logCnt_, deltaTime, iFuncName, iSourceRowNo);
                    break;
                case E_LOG_MSEC_CNT_STS::E_END:
                    sprintf(BuffTmp, "[%s][%08lu][Info   ][Debug:C I/A][E+%03d ms][Source:%s(R%d)]", SystemDateTime, this->logCnt_, deltaTime, iFuncName, iSourceRowNo);
                    break;
                default:
                    sprintf(BuffTmp, "[%s][%08lu][Info   ][Debug:C I/A][Source:%s(R%d)]", SystemDateTime, this->logCnt_, iFuncName, iSourceRowNo);
                    break;
            }
        }
            break;
        case E_LOG_TYPE::E_WARNING:
        {
            switch (iMSecCntStatus) {
                case E_LOG_MSEC_CNT_STS::E_START:
                    sprintf(BuffTmp, "[%s][%08lu][Warning][Debug:C I/A][S+%03d ms][Source:%s(R%d)]", SystemDateTime, this->logCnt_, deltaTime, iFuncName, iSourceRowNo);
                    break;
                case E_LOG_MSEC_CNT_STS::E_COUNTING:
                    sprintf(BuffTmp, "[%s][%08lu][Warning][Debug:C I/A][ +%03d ms][Source:%s(R%d)]", SystemDateTime, this->logCnt_, deltaTime, iFuncName, iSourceRowNo);
                    break;
                case E_LOG_MSEC_CNT_STS::E_END:
                    sprintf(BuffTmp, "[%s][%08lu][Warning][Debug:C I/A][E+%03d ms][Source:%s(R%d)]", SystemDateTime, this->logCnt_, deltaTime, iFuncName, iSourceRowNo);
                    break;
                default:
                    sprintf(BuffTmp, "[%s][%08lu][Warning][Debug:C I/A][Source:%s(R%d)]", SystemDateTime, this->logCnt_, iFuncName, iSourceRowNo);
                    break;
            }
        }
            break;
        case E_LOG_TYPE::E_ERROR:
        {
            switch (iMSecCntStatus) {
                case E_LOG_MSEC_CNT_STS::E_START:
                    sprintf(BuffTmp, "[%s][%08lu][Error  ][Debug:C I/A][S+%03d ms][Source:%s(R%d)]", SystemDateTime, this->logCnt_, deltaTime, iFuncName, iSourceRowNo);
                    break;
                case E_LOG_MSEC_CNT_STS::E_COUNTING:
                    sprintf(BuffTmp, "[%s][%08lu][Error  ][Debug:C I/A][ +%03d ms][Source:%s(R%d)]", SystemDateTime, this->logCnt_, deltaTime, iFuncName, iSourceRowNo);
                    break;
                case E_LOG_MSEC_CNT_STS::E_END:
                    sprintf(BuffTmp, "[%s][%08lu][Error  ][Debug:C I/A][E+%03d ms][Source:%s(R%d)]", SystemDateTime, this->logCnt_, deltaTime, iFuncName, iSourceRowNo);
                    break;
                default:
                    sprintf(BuffTmp, "[%s][%08lu][Error  ][Debug:C I/A][Source:%s(R%d)]", SystemDateTime, this->logCnt_, iFuncName, iSourceRowNo);
                    break;
            }
        }
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