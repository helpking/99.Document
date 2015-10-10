//
//  CsbMacro.cpp
//  021.FirstSample
//
//  Created by 何 利強 on 2015/10/07.
//
//

#include "CsbMacro.h"

/**
 * @brief 指定されたノード名で、ルートロードから、ノードを探す
 * @param[in] iSearchRootNode 1
 * @param[in] iNodeName 1
 * @return 探したいノード
 */
cocos2d::Node* RTNodeSearch(cocos2d::Node* iSearchRootNode, const char* iNodeName)
{
    cocos2d::Node* pRet = iSearchRootNode->getChildByName(iNodeName);
    if (pRet == nullptr)
    {
        for (auto loopNode : iSearchRootNode->getChildren())
        {
            pRet = RTNodeSearch(loopNode, iNodeName);
            if (pRet)
            {
                break;
            }
        }
    }
    return pRet;
}