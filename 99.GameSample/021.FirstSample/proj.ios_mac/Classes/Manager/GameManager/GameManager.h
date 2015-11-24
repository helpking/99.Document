//
//  GameManager.h
//  021.FirstSample
//
//  Created by 何 利強 on 2015/10/17.
//
//

#ifndef _21_FirstSample_GameManager_h
#define _21_FirstSample_GameManager_h

#include "ManagerMacro.h"
#include "ResInfoPool.h"
#include "Singleton.h"

USING_NS_RESINFO;

NS_BEGIN_MANAGER

/**
 * @brief マネジャー
 */
class GameManager
{
public:
    
    /**
     * @brief コンストラクター
     */
    GameManager();
    
    /**
     * @brief デストラクタ
     */
    ~GameManager();
    
private:
    
    /**
     * @brief 初期化する
     */
    void init();
};

NS_END_MANAGER

#endif
