#ifndef DATETIME_TYPES_H
#define DATETIME_TYPES_H

#include "include/common_types.h"

namespace SystemLib {
    /**
     * \brief 日期格式
     */
    typedef enum TDataTimeFormat {
        kTDataTimeFormatInvalid = kValueInvalid,
        /** \brief 日期格式:YYYY-MM-DD HH:MM:SS */
        kTDataTimeFormatYYYYMMDDHHMMSS,
        /** \brief 日期格式:YYYY-MM-DD HH:MM */
        kTDataTimeFormatYYYYMMDDHHMM,
        /** \brief 日期格式:YYYY-MM-DD */
        kTDataTimeFormatYYYYMMDD,
        /** \brief 日期格式:HH:MM:SS */
        kTDataTimeFormatHHMMSS,
        /** \brief 日期格式:HH:MM */
        kTDataTimeFormatHHMM,
        kTDataTimeFormatMax,
        kTDataTimeFormatDefault = kTDataTimeFormatYYYYMMDDHHMMSS
    } TDataTimeFormat;
}

#endif // DATETIME_TYPES_H
