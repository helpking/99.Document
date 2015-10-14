//
//  ManagerMacro.h
//  021.FirstSample
//
//  Created by 何 利強 on 2015/10/14.
//
//

#ifndef _21_FirstSample_ManagerMacro_h
#define _21_FirstSample_ManagerMacro_h

// マネジャー
#define USING_NS_MANAGER                                using namespace Manager;
#define NS_BEGIN_MANAGER                                namespace Manager {
#define NS_END_MANAGER                                  }

// シーン遷移履歴
#define USING_NS_SCENE_HISTORY                          using namespace Manager::History::Scene;
#define NS_BEGIN_SCENE_HISTORY                          namespace Manager { \
                                                            namespace History { \
                                                                namespace Scene {
#define NS_END_SCENE_HISTORY                                    } \
                                                            } \
                                                        }

// リスース
#define USING_NS_RESINFO                                using namespace Manager::ResInfo;
#define NS_BEGIN_RESINFO                                namespace Manager { \
                                                            namespace ResInfo {
#define NS_END_RESINFO                                      } \
                                                        }

#endif
