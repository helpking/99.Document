//
//  MacroHeader.h
//  021.FirstSample
//
//  Created by 何 利強 on 2015/10/13.
//
//

#ifndef _21_FirstSample_MacroHeader_h
#define _21_FirstSample_MacroHeader_h

#include "UtilsLog.h"

//! ログ
#define NOR_LOG(format, ...)        InterfaceLab::Singleton<Common::Utils::UtilsLog>::getInstance()->OutputInfo(format, ##__VA_ARGS__)
#define WARNING_LOG(format, ...)    InterfaceLab::Singleton<Common::Utils::UtilsLog>::getInstance()->OutputWarning(format, ##__VA_ARGS__)
#define ERR_LOG(format, ...)        InterfaceLab::Singleton<Common::Utils::UtilsLog>::getInstance()->OutputError(format, ##__VA_ARGS__)

#endif
