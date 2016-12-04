#include "include/SystemLib/log/log.h"
#include "include/SystemLib/datetime/datetime.h"

#include <QDebug>

namespace SystemLib {

    /** \brief 初始化 */
    Log* Log::_instane = nullptr;

    /** \brief 日志最大长度 */
    const TS32 kLogMaxLength = 4096;

    Log* Log::GetIntance() {
        if(_instane == nullptr) {
            _instane = new Log();
        }
        return _instane;
    }

    Log::Log() : log_no(0) {}
    Log::~Log() {}

    /**
     * \brief 日志输出
     * \param[in] iLogType 日志类型
     * \param[in] iLogFormat 日志格式
     */
    void Log::Output(const TLogType iLogType, const TChar* iLogFormat, ...) {

        // 取得LogNo
        const TS64 logNo = this->GetLogNo();

        // 系统时刻取得
        TChar systemDateTime[kDateTimeMaxLength] = {""};
        const TBool bolFlg = Datetime::GetIntance()->getLocalTime(systemDateTime,
                                                                  kDateTimeMaxLength,
                                                                  kTDataTimeFormatYYYYMMDDHHMMSS,
                                                                  true);
        if(bolFlg == false) {
            snprintf(systemDateTime, kDateTimeMaxLength, "SystemDate Get Failed");
        }


        // 日志类型
        const TChar* logTypeMark = this->GetLogTypeMarkTxt(iLogType);

        // 指定参数设定
        TChar paramDetail[kLogMaxLength] = { "" };
        va_list ap;
        va_start(ap, iLogFormat);
        vsnprintf(paramDetail, kLogMaxLength, iLogFormat, ap);
        va_end(ap);

        std::string logTmp = paramDetail;
        size_t findPosTmp = logTmp.find("¥n");
        while (findPosTmp != std::string::npos )
        {
            logTmp.replace(findPosTmp, strlen("¥n"), "\n");
            findPosTmp = logTmp.find("¥n");
        }

        std::string LineTmp = logTmp;
        size_t startPos = 0;
        findPosTmp = logTmp.find("\n");
        while (findPosTmp != std::string::npos )
        {
            LineTmp = logTmp.substr(0, findPosTmp);
            this->Output(logNo, systemDateTime, logTypeMark, LineTmp.c_str());

            startPos = findPosTmp + strlen("\n");
            logTmp = logTmp.substr(startPos);
            findPosTmp = logTmp.find("\n");
        }

        if (logTmp.empty() == false)
        {
            this->Output(logNo, systemDateTime, logTypeMark, logTmp.c_str());
        }

    }

    /**
     * \brief 日志输出
     * \param[in] iLogNo 日志No
     * \param[in] iSystemDateTime 系统时刻
     * \param[in] iLogTypeMarkTxt 日志类型标识
     * \param[in] iLogTxt 日志
     */
    void Log::Output(
            const TS64 iLogNo,
            const TChar* iSystemDateTime,
            const TChar* iLogTypeMarkTxt,
            const TChar* iLogTxt) {

        TChar logBuffer[kLogMaxLength];

        snprintf(logBuffer, kLogMaxLength, "[%06lld][%s][%s]%s",
                 iLogNo, iSystemDateTime, iLogTypeMarkTxt, iLogTxt);
        this->OutputLog(logBuffer);

    }

    /**
     * \brief 日志输出
     * \param[in] iLogNo 日志No
     * \param[in] iLogTxt 日志
     */
    void Log::OutputLog(const TChar* iLogTxt) {
        if((iLogTxt == nullptr) || (std::strlen(iLogTxt) <= 0)) {
            return;
        }
        qDebug() << iLogTxt;
    }

}
