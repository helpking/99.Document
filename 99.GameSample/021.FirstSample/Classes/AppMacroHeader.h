//
//  AppMacroHeader.h
//  021.FirstSample
//
//  Created by 何 利強 on 2015/10/13.
//
//

#ifndef _21_FirstSample_MacroHeader_h
#define _21_FirstSample_MacroHeader_h

#include "Singleton.h"
#include "UtilsLog.h"
#include "CommonLib.h"

//! ログ
#define INFO_LOG(format, ...)       long __mSec = -1; \
                                    InterfaceLab::Singleton<Common::Utils::UtilsLog>::getInstance()->OutputInfo(__PRETTY_FUNCTION__, __LINE__, false , __mSec, format, ##__VA_ARGS__);
#define WARNING_LOG(format, ...)    long __mSec = -1; \
                                    InterfaceLab::Singleton<Common::Utils::UtilsLog>::getInstance()->OutputWarning(__PRETTY_FUNCTION__, __LINE__, false , __mSec, format, ##__VA_ARGS__);
#define ERR_LOG(format, ...)        long __mSec = -1; \
                                    InterfaceLab::Singleton<Common::Utils::UtilsLog>::getInstance()->OutputError(__PRETTY_FUNCTION__, __LINE__, false , __mSec, format, ##__VA_ARGS__);

//! ログ(Timer)


//! データのダンプ
#define DUMP_DICT_INFO(dict)        INFO_LOG("DUMP_DICT_INFO\n%s", CommonLib::DumpDictionary(dict));

#endif
