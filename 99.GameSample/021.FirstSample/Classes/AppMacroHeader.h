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

#ifdef COCOS2D_DEBUG

#pragma mark -

#pragma mark LogMacro

//! ログ
#define INFO_LOG(format, ...)                           InterfaceLab::Singleton<Common::Utils::UtilsLog>::getInstance()->OutputInfo(__PRETTY_FUNCTION__, __LINE__, format, ##__VA_ARGS__);
#define WARNING_LOG(format, ...)                        InterfaceLab::Singleton<Common::Utils::UtilsLog>::getInstance()->OutputWarning(__PRETTY_FUNCTION__, __LINE__, format, ##__VA_ARGS__);
#define ERR_LOG(format, ...)                            InterfaceLab::Singleton<Common::Utils::UtilsLog>::getInstance()->OutputError(__PRETTY_FUNCTION__, __LINE__, format, ##__VA_ARGS__);

//! ログ(Timer)
//! ミリ秒カウント開始
#define LOG_TIMER_START(logType)                        InterfaceLab::Singleton<Common::Utils::UtilsLog>::getInstance()->OutputMSecCntStart(__PRETTY_FUNCTION__, __LINE__, logType);
#define INFO_LOG_TIMER_START()                          LOG_TIMER_START(E_LOG_TYPE::E_INFO)
#define WARNING_LOG_TIMER_START()                       LOG_TIMER_START(E_LOG_TYPE::E_WARNING)
#define ERR_LOG_TIMER_START()                           LOG_TIMER_START(E_LOG_TYPE::E_ERROR)
#define INFO_TIMER_LOG_(format, ...)                    InterfaceLab::Singleton<Common::Utils::UtilsLog>::getInstance()->OutputInfo(__PRETTY_FUNCTION__, __LINE__, format, ##__VA_ARGS__);
#define WARNING_TIMER_LOG_(format, ...)                 InterfaceLab::Singleton<Common::Utils::UtilsLog>::getInstance()->OutputWarning(__PRETTY_FUNCTION__, __LINE__, format, ##__VA_ARGS__);
#define ERR_TIMER_LOG_(format, ...)                     InterfaceLab::Singleton<Common::Utils::UtilsLog>::getInstance()->OutputError(__PRETTY_FUNCTION__, __LINE__, format, ##__VA_ARGS__);

//! カウントされたミリ秒を含んで、出力する
#define INFO_TIMER_LOG(format, ...)                     INFO_TIMER_LOG_(format, ##__VA_ARGS__);
#define WARNING_TIMER_LOG(format, ...)                  WARNING_TIMER_LOG_(format, ##__VA_ARGS__);
#define ERR_TIMER_LOG(format, ...)                      ERR_TIMER_LOG_(format, ##__VA_ARGS__);

//! ミリ秒カウント終了
#define LOG_TIMER_END(logType)                          InterfaceLab::Singleton<Common::Utils::UtilsLog>::getInstance()->OutputMSecCntEnd(__PRETTY_FUNCTION__, __LINE__, logType);
#define INFO_LOG_TIMER_END()                            LOG_TIMER_END(E_LOG_TYPE::E_INFO)
#define WARNING_LOG_TIMER_END()                         LOG_TIMER_END(E_LOG_TYPE::E_WARNING)
#define ERR_LOG_TIMER_END()                             LOG_TIMER_END(E_LOG_TYPE::E_ERROR)


//! データのダンプ
#define DUMP_DICT_INFO(dict)                            INFO_LOG("DUMP_DICT_INFO\n%s", CommonLib::DumpDictionary(dict));

#endif

#pragma mark -

#endif
