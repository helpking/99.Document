#ifndef LOG_H
#define LOG_H

#include "include/common_macro.h"
#include "include/SystemLib/log/log_types.h"

namespace SystemLib {
    /**
     * \brief 日志类
     */
    class Log
    {
    public:
        static Log* GetIntance();

        ~Log();

        /**
         * \brief 日志输出
         * \param[in] iLogType 日志类型
         * \param[in] iLogFormat 日志格式
         */
        void Output(const TLogType iLogType, const TChar* iLogFormat, ...);
    protected:
        Log();

    private:
        static Log* _instane;
        /** \brief 日志No */
        TS64 log_no;

        /**
         * \brief 日志输出
         * \param[in] iLogNo 日志No
         * \param[in] iSystemDateTime 系统时刻
         * \param[in] iLogTypeMarkTxt 日志类型标识
         * \param[in] iLogTxt 日志
         */
        void Output(const TS64 iLogNo,
                    const TChar* iSystemDateTime,
                    const TChar* iLogTypeMarkTxt,
                    const TChar* iLogTxt);

        /**
         * \brief 日志输出
         * \param[in] iLogNo 日志No
         * \param[in] iLogTxt 日志
         */
        void OutputLog(const TChar* iLogTxt);

        /**
         * \brief 取得日志No
         * \return 日志No
         */
        _INLINE TS64 GetLogNo();

        /**
         * \brief 取得日志类型文本
         * \return 日志类型文本
         */
        _INLINE const TChar* GetLogTypeMarkTxt(const TLogType iLogType);
    };
    _INLINE TS64 Log::GetLogNo() {
        ++log_no;
        return log_no;
    };
    _INLINE const TChar* Log::GetLogTypeMarkTxt(const TLogType iLogType){
        switch (iLogType) {
        case kTLogTypeInfo:
            {
                return "[Info]";
            }
            break;
        case kTLogTypeWarning:
            {
                return "[Warning]";
            }
            break;
        case kTLogTypeError:
            {
                return "[Error]";
            }
            break;
        case kTLogTypeExcept:
            {
                return "[Except]";
            }
            break;
        default:
            return "[Unknow]";
            break;
        }
    };
}

#endif // LOG_H
