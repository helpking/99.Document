//
//  ManagerMacro.h
//  021.FirstSample
//
//  Created by 何 利強 on 2015/10/14.
//
//

#ifndef _21_FirstSample_ManagerMacro_h
#define _21_FirstSample_ManagerMacro_h

#include "PlatformTypes.h"

// マネジャー
#define USING_NS_MANAGER                                using namespace Manager
#define NS_BEGIN_MANAGER                                namespace Manager {
#define NS_END_MANAGER                                  }

// シーン遷移履歴
#define USING_NS_SCENE_HISTORY                          using namespace Manager::History::Scene
#define NS_BEGIN_SCENE_HISTORY                          namespace Manager { \
                                                            namespace History { \
                                                                namespace Scene {
#define NS_END_SCENE_HISTORY                                    } \
                                                            } \
                                                        }

// Config
#define USING_NS_CONFIG                                 using namespace Manager::Config
#define NS_BEGIN_CONFIG                                 namespace Manager { \
                                                            namespace Config {
#define NS_END_CONFIG                                       } \
                                                        }

// リスース
#define USING_NS_RESINFO                                using namespace Manager::ResInfo
#define NS_BEGIN_RESINFO                                namespace Manager { \
                                                            namespace ResInfo {
#define NS_END_RESINFO                                      } \
                                                        }

#endif
