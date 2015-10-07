//
//  CsbMacro.cpp
//  021.FirstSample
//
//  Created by 何 利強 on 2015/10/07.
//
//

#include "CsbMacro.h"

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