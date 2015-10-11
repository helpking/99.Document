//
//  InterfaceLab.cpp
//  021.FirstSample
//
//  Created by 何 利強 on 2015/10/11.
//
//

#include "InterfaceLab.h"

/**
 * @brief 指定されたノード名で、ルートロードから、ノードを探す
 * @param[in] iSearchRootNode 1
 * @param[in] iNodeName 1
 * @return 探したいノード
 */
Node* IRTNodeSearch(Node* iSearchRootNode, const char* iNodeName)
{
    cocos2d::Node* pRet = iSearchRootNode->getChildByName(iNodeName);
    if (pRet == nullptr)
    {
        for (auto loopNode : iSearchRootNode->getChildren())
        {
            pRet = IRTNodeSearch(loopNode, iNodeName);
            if (pRet)
            {
                break;
            }
        }
    }
    return pRet;
}