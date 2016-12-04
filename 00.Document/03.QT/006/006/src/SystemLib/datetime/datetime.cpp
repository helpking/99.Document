#include "include/SystemLib/datetime/datetime.h"
#include <stdio.h>
#include <memory.h>
#include <time.h>
#include <sys/time.h>

namespace SystemLib {

    /** \brief 初始化 */
    Datetime* Datetime::_instane = nullptr;

    Datetime* Datetime::GetIntance() {
        if(_instane == nullptr) {
            _instane = new Datetime();
        }
        return _instane;
    }

    Datetime::Datetime() {}
    Datetime::~Datetime() {}

    /**
     * \brief 取得本地时间
     * \param[in/out] ioBuffer 输出用Buffer
     * \param[in] iBufferLen 输出用Buffer长度
     * \param[in] iFormat 时间格式
     * \param[in] iMSecFlg 微秒取得Flg
     * \return 本地时间
     */
    TBool Datetime::getLocalTime(
            TChar* ioBuffer,
            const TS32 iBufferLen,
            const TDataTimeFormat iFormat,
            const TBool iMSecFlg /* = false */) {

        time_t now = time(NULL);
        tm* tm = localtime( &now );

        switch (iFormat) {
        case kTDataTimeFormatYYYYMMDDHHMMSS:
            {
                snprintf(ioBuffer, iBufferLen,
                         "%04d-%02d-%02d %02d:%02d:%02d",
                         tm->tm_year + 1900, tm->tm_mon, tm->tm_mday,
                         tm->tm_hour, tm->tm_min, tm->tm_sec);
            }
            break;
        case kTDataTimeFormatYYYYMMDDHHMM:
            {
                snprintf(ioBuffer, iBufferLen,
                         "%04d-%02d-%02d %02d:%02d",
                         tm->tm_year + 1900, tm->tm_mon, tm->tm_mday,
                         tm->tm_hour, tm->tm_min);
            }
            break;
        case kTDataTimeFormatYYYYMMDD:
            {
                snprintf(ioBuffer, iBufferLen,
                         "%04d-%02d-%02d",
                         tm->tm_year + 1900, tm->tm_mon, tm->tm_mday);
            }
            break;
        case kTDataTimeFormatHHMMSS:
            {
            snprintf(ioBuffer, iBufferLen,
                     "%02d:%02d:%02d",
                     tm->tm_hour, tm->tm_min, tm->tm_sec);
            }
            break;

        case kTDataTimeFormatHHMM:
            {
            snprintf(ioBuffer, iBufferLen,
                     "%02d:%02d",
                     tm->tm_hour, tm->tm_min);
            }
            break;
        default:
            {
                return false;
            }
            break;
        }

        if (iMSecFlg) {
            struct timeval tv;
            gettimeofday(&tv,NULL);

            time_t msec = tv.tv_usec / 1000;
            snprintf(ioBuffer, iBufferLen, "%s.%03ld", ioBuffer, msec);
        }
        return true;
    }

}
