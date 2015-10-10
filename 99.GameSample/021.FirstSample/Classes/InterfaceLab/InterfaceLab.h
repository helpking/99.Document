//
//  InterfaceLab.h
//  021.FirstSample
//
//  Created by 何利强 on 15-10-10.
//
//

#ifndef _21_FirstSample_InterfaceLab_h
#define _21_FirstSample_InterfaceLab_h

// MARK:ゲームツールライブ区分
#define GAME_TOOL_LAB_COCOSSTUDIO                   1
#define GAME_TOOL_LAB_KBN                           1

// MARK:Header File
#include "cocos2d.h"
#include "ResInfoPool.h"
#include "Singleton.h"

// MARK:CocosStudioHeader
#if (GAME_TOOL_LAB_KBN == GAME_TOOL_LAB_COCOSSTUDIO)

#include "cocostudio/CocoStudio.h"
#include "cocostudio/WidgetCallBackHandlerProtocol.h"
#include "cocostudio/CocosStudioExport.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

// cocostudio
#define USING_NS_COCOS_STUDIO                       using namespace cocostudio

// namespace
USING_NS_COCOS_STUDIO;

#endif

// MARK:InterFaceLab
#define USING_NS_INTERFACE_LAB                      using namespace InterfaceLab
#define NS_BEGIN_NS_INTERFACE_LAB                   namespace InterfaceLab {
#define NS_END_NS_INTERFACE_LAB                     }

// MARK:NameSpace
#define USING_NS_CC_UI                              using namespace cocos2d::ui

NS_BEGIN_NS_INTERFACE_LAB

USING_NS_CC;
USING_NS_CC_UI;
USING_NS_CC_MATH;
USING_NS_RESINFO;

/**
 * @brief インタフェースライブ
 */
class Interface
{
public:
    
    /**
     * @brief コンストラクター
     */
    Interface();
    
    /**
     * @brief デストラクタ
     */
    ~Interface();
};

NS_END_NS_INTERFACE_LAB

#endif
