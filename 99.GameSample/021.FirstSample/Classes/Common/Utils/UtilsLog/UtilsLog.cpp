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
    
    const char* SystemDateTime = CommonLib::getSystemDateTime();
    
    CCLOG("[%s][Info][%s][Debug:C I/A]", SystemDateTime, szBuf);
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
    
    const char* SystemDateTime = CommonLib::getSystemDateTime();
    
    CCLOG("[%s][Warning][%s][Debug:C I/A]", SystemDateTime, szBuf);
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
    
    const char* SystemDateTime = CommonLib::getSystemDateTime();
    
    CCLOG("[%s][Error][%s][Debug:C I/A]", SystemDateTime, szBuf);
#endif
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