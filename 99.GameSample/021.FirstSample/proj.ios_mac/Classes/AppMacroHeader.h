//
//  AppMacroHeader.h
//  021.FirstSample
//
//  Created by 何 利強 on 2015/10/13.
//
//

#ifndef _21_FirstSample_MacroHeader_h
#define _21_FirstSample_MacroHeader_h

#include "UtilsLog.h"
#include "CommonLib.h"

#ifdef COCOS2D_DEBUG

#pragma mark -

#pragma mark LogMacro

//! ログ(Timer)
//! ミリ秒カウント開始
#define LOG_TIMER_START()                               Common::Singleton<Common::Utils::UtilsLog>::getInstance()->OutputMSecCntStart(__PRETTY_FUNCTION__, __LINE__);

//! ミリ秒カウント終了
#define LOG_TIMER_END()                                 Common::Singleton<Common::Utils::UtilsLog>::getInstance()->OutputMSecCntEnd(__PRETTY_FUNCTION__, __LINE__);

//! ログ
#define INFO_LOG(format, ...)                           Common::Singleton<Common::Utils::UtilsLog>::getInstance()->OutputInfo(__PRETTY_FUNCTION__, __LINE__, format, ##__VA_ARGS__);
#define WARNING_LOG(format, ...)                        Common::Singleton<Common::Utils::UtilsLog>::getInstance()->OutputWarning(__PRETTY_FUNCTION__, __LINE__, format, ##__VA_ARGS__);
#define ERR_LOG(format, ...)                            Common::Singleton<Common::Utils::UtilsLog>::getInstance()->OutputError(__PRETTY_FUNCTION__, __LINE__, format, ##__VA_ARGS__);

//! データのダンプ
#define DUMP_DICT_INFO(dict)                            INFO_LOG("DUMP_DICT_INFO\n%s", CommonLib::DumpDictionary(dict));

#endif

#pragma mark -

#endif
