//
//  ResInfoPool.cpp
//  021.FirstSample
//
//  Created by 何 利強 on 2015/10/17.
//
//

#include "ResInfoPool.h"

USING_NS_RESINFO_POOL

/**
 * @brief コンストラクター
 */
ResInfoPool::ResInfoPool()
{
    
}

/**
 * @brief デストラクタ
 */
ResInfoPool::~ResInfoPool()
{
    
}

/**
 * @brief リソース情報を追加する
 * @param[in] iResId リソースID
 */
ResInfoPool::S_RES_INFO ResInfoPool::getResInfo(const E_RES_ID iResId)
{
    ResInfoPool::S_RES_INFO retInfo;
    if (_resInfoPool.find(iResId) != _resInfoPool.end())
    {
        retInfo = _resInfoPool[iResId];
    }
    
    return retInfo;
}

/**
 * @brief リソース情報を追加する
 * @param[in] iResId リソースID
 * @param[in] iResInfo リソース情報
 */
void ResInfoPool::addResInfo(const E_RES_ID iResId,
                             const S_RES_INFO iResInfo)
{
    this->_resInfoPool[iResId] = iResInfo;
}
