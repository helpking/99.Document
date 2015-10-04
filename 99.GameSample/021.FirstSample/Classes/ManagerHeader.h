//
//  ManagerHeader.h
//  021.FirstSample
//
//  Created by 何利强 on 15-10-5.
//
//

#ifndef _21_FirstSample_ManagerHeader_h
#define _21_FirstSample_ManagerHeader_h

// マネジャー
#define USING_NS_MANAGER                                using namespace Manager;
#define NS_BEGIN_MANAGER                                namespace Manager {
#define NS_END_MANAGER                                  }

// シーン遷移履歴
#define USING_NS_SCENE_HISTORY                          using namespace Manager::History::Scene;
#define NS_BEGIN_SCENE_HISTORY                          namespace Manager {                              \
                                                            namespace History {                          \
                                                                namespace Scene {
#define NS_END_SCENE_HISTORY                                    }                                        \
                                                            }                                            \
                                                        }

// リスースプール
#define USING_NS_RESINFO_POOL                           using namespace Manager::ResInfoPool;
#define NS_BEGIN_RESINFO_POOL                           namespace Manager {                              \
                                                            namespace ResInfoPool {
#define NS_END_RESINFO_POOL                                 }                                            \
                                                        }

#endif
