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

/**
 * @brief コンストラクタ
 */
UtilsLog::UtilsLog()
{
    const std::string outPutFilePath = CCFileUtils::getInstance()->getWritablePath() + this->getLogFileName();
    logFile.open( outPutFilePath.c_str(),
                 std::ios::out );
    OutputInfo("LogFile:%s", outPutFilePath.c_str());
}

/**
 * @brief デストラクタ
 */
UtilsLog::~UtilsLog()
{
    // ログファイルをクローズする
    logFile.close();
}

/**
 * @brief ログの出力関数
 */
void UtilsLog::OutputInfo(const char* iFormat, ...)
{
#ifdef COCOS2D_DEBUG
    const int kMaxLogLen = 16*1024;
    char szBuf[kMaxLogLen];
    
    va_list ap;
    va_start(ap, iFormat);
    vsnprintf(szBuf, kMaxLogLen, iFormat, ap);
    va_end(ap);
    
    outputInline(szBuf);
#endif
}

/**
 * @brief ログ(警告)の出力関数
 */
void UtilsLog::OutputWarning(const char* iFormat, ...)
{
#ifdef COCOS2D_DEBUG
    const int kMaxLogLen = 16*1024;
    char szBuf[kMaxLogLen];
    
    va_list ap;
    va_start(ap, iFormat);
    vsnprintf(szBuf, kMaxLogLen, iFormat, ap);
    va_end(ap);
    
    outputInline(szBuf, E_LOG_TYPE::E_WARNING);
#endif
}

/**
 * @brief ログ(エラー)の出力関数
 */
void UtilsLog::OutputError(const char* iFormat, ...)
{
#ifdef COCOS2D_DEBUG
    const int kMaxLogLen = 16*1024;
    char szBuf[kMaxLogLen];
    
    va_list ap;
    va_start(ap, iFormat);
    vsnprintf(szBuf, kMaxLogLen, iFormat, ap);
    va_end(ap);
    
    outputInline(szBuf, E_LOG_TYPE::E_ERROR);
#endif
}

/**
 * @brief ライン毎に、ログ(エラー)の出力関数
 * @param[in] iLogMsg ログメッセージ
 * @param[in] iLogType ログタイプ
 */
void UtilsLog::outputInline(const char* iLogMsg,
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
        
        this->output(LineTmp.c_str(), iLogType);
        
        startPos = findPosTmp + strlen("¥n");
        logTmp = logTmp.substr(startPos);
        findPosTmp = logTmp.find("¥n");
    }
    
    if (logTmp.empty() == false)
    {
        this->output(logTmp.c_str(), iLogType);
    }
    
}

/**
 * @brief ログの出力関数
 * @param[in] iLogMsg ログメッセージ
 * @param[in] iLogType ログタイプ
 */
void UtilsLog::output(const char* iLogMsg,
                      const E_LOG_TYPE iLogType)
{
    const char* SystemDateTime = CommonLib::getSystemDateTime();
    switch (iLogType)
    {
        case E_LOG_TYPE::E_INFO:
            CCLOG("[%s][Info   ][Debug:C I/A]%s", SystemDateTime, iLogMsg);
            break;
        case E_LOG_TYPE::E_WARNING:
            CCLOG("[%s][Warning][Debug:C I/A]%s", SystemDateTime, iLogMsg);
            break;
        case E_LOG_TYPE::E_ERROR:
            CCLOG("[%s][Error  ][Debug:C I/A]%s", SystemDateTime, iLogMsg);
            break;
        default:
            break;
    }
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