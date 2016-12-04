#ifndef COMMON_H
#define COMMON_H

#include "include/common_types.h"
#include "include/common_macro.h"

#include "include/SystemLib/log/log.h"

// 日志输出宏
#define INFO_LOG(iFormat, ...) SystemLib::Log::GetIntance()->Output(SystemLib::kTLogTypeInfo, iFormat, ##__VA_ARGS__);
#define WARNING_LOG(iFormat, ...) SystemLib::Log::GetIntance()->Output(SystemLib::kTLogTypeWarning, iFormat, ##__VA_ARGS__);
#define ERROR_LOG(iFormat, ...) SystemLib::Log::GetIntance()->Output(SystemLib::kTLogTypeError, iFormat, ##__VA_ARGS__);
#define EXCEPT_LOG(iFormat, ...) SystemLib::Log::GetIntance()->Output(SystemLib::kTLogTypeExcept, iFormat, ##__VA_ARGS__);

#endif // COMMON_H
