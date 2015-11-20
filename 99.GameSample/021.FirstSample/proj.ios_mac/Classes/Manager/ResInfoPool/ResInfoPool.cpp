//
//  ResInfoPool.cpp
//  021.FirstSample
//
//  Created by 何 利強 on 2015/10/17.
//
//

#include "ResInfoPool.h"

USING_NS_RESINFO;

/**
 * @brief コンストラクター
 */
ResInfoPool::ResInfoPool()
{
    // 初期化する
    this->init();
}

/**
 * @brief デストラクタ
 */
ResInfoPool::~ResInfoPool()
{
    
}

/**
 * @brief リソース情報を初期化する
 * @param[in] iResInfo リソース情報
 */
void ResInfoPool::initResInfo(S_RES_INFO& iResInfo)
{
    iResInfo.ResID = E_RES_ID::E_INVALID;
    iResInfo.ResType = E_RES_TYPE::E_INVALID;
    iResInfo.Name = "";
    iResInfo.Path = "";
}

/**
 * @brief 初期化する
 */
void ResInfoPool::init()
{
    // リソースの定義
    S_RES_INFO resInfo[] =
    {
        // シーン
        // トップシーン
        {E_RES_ID::E_SCENE_TOP,                     E_RES_TYPE::E_SCENE,
            "TopScene",                             "Scene/TopScene.csb"},
        
        // パーツ
        {E_RES_ID::E_PARTS_COORDINATE_MESH,         E_RES_TYPE::E_PARTS_NORMAL,
            "CoordinateMesh",                       "Parts/CoordinateMesh.csb"},
        {E_RES_ID::E_PARTS_DEMO_PLAYER,             E_RES_TYPE::E_PARTS_ACTION,
            "DemoPlayer",                           "Parts/DemoPlayer.csb"},
        {E_RES_ID::E_PARTS_ROLE,                    E_RES_TYPE::E_PARTS_ACTION,
            "Role",                                 "Parts/Role.csb"},
        {E_RES_ID::E_PARTS_WINDMILL,                E_RES_TYPE::E_PARTS_ACTION,
            "WindMill",                             "Parts/WindMill.csb"},
    };
    
    for (S_RES_INFO resInfoTmp : resInfo)
    {
        this->addResInfo(resInfoTmp.ResID, resInfoTmp);
    }
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
    else
    {
        // 無効化するため、初期化にする
        this->initResInfo(retInfo);
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
