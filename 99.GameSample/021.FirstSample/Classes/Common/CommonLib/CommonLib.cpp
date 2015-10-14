//
//  Common.cpp
//  021.FirstSample
//
//  Created by 何 利強 on 2015/10/13.
//
//

#include "CommonLib.h"

USING_NS_COMMON;

/**
 * @brief システム日付(YYYY/MM/DD HH:MM:SS)を取得する
 * @return システム日付
 */
const char* CommonLib::getSystemDateTime()
{
    time_t now = time(NULL);
    tm* tm = localtime( &now );
    
    const float msec = double( clock() ) / CLOCKS_PER_SEC;
    char buf[32];
    sprintf( buf, "%04d/%02d/%02d %02d:%02d:%02d.%03d",
            tm->tm_year+1900,
            tm->tm_mon+1,
            tm->tm_mday,
            tm->tm_hour,
            tm->tm_min,
            tm->tm_sec,
            int( ( msec - int(msec) ) * 1000 ));
    
    return std::string(buf).c_str();
}