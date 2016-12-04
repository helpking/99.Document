#ifndef DATETIME_H
#define DATETIME_H

#include "include/common_types.h"
#include "include/SystemLib/datetime/datetime_types.h"

namespace SystemLib {


    /** \brief 日期最大长度 */
    const TS32 kDateTimeMaxLength = 32;

    /**
     * \brief 日志类
     */
    class Datetime
    {
    public:
        static Datetime* GetIntance();
        ~Datetime();

        /**
         * \brief 取得本地时间
         * \param[in/out] ioBuffer 输出用Buffer
         * \param[in] iBufferLen 输出用Buffer长度
         * \param[in] iFormat 时间格式
         * \param[in] iMSecFlg 微秒取得Flg
         * \return 本地时间
         */
        TBool getLocalTime(TChar* ioBuffer,
                           const TS32 iBufferLen,
                           const TDataTimeFormat iFormat,
                           const TBool iMSecFlg = false);
    protected:
        Datetime();

    private:
        static Datetime* _instane;
    };
}

#endif // DATETIME_H
