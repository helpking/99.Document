#ifndef LOG_TYPES_H
#define LOG_TYPES_H

#include "include/common_types.h"

namespace SystemLib {
    /**
     * \brief 日志类型定义
     */
    typedef enum TLogType {
        kTLogTypeInvalid = kValueInvalid,
        /** \brief 情报（一般信息） */
        kTLogTypeInfo,
        /** \brief 警报 */
        kTLogTypeWarning,
        /** \brief 错误 */
        kTLogTypeError,
        /** \brief 异常或者例外 */
        kTLogTypeExcept,
        kTLogTypeMax,
        kTLogTypeDefault = kTLogTypeInfo
    }TLogType;

}

#endif // LOG_TYPES_H
