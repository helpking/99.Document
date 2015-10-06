//
//  LoadCsbFile.cpp
//  021.FirstSample
//
//  Created by 何 利強 on 2015/10/17.
//
//

#include "LoadCsbFile.h"

#include "ResInfoPool.h"
#include "Singleton.h"

// Csbファイル：シーン
#include "TopScene.h"

// Csbファイル：パーツ
#include "CoordinateMesh.h"

USING_NS_COMMON_CSB;
USING_NS_RESINFO;
USING_NS_UIPARTS;
USING_NS_UISCENE;

// Csbファイル読み込む用名
#define CSB_READER(__CSB_NAME__)        CCString::createWithFormat("%sReader", __CSB_NAME__)->getCString()

/**
 * @brief コンストラクター
 */
LoadCsbFile::LoadCsbFile()
{
}

/**
 * @brief デストラクター
 */
LoadCsbFile::~LoadCsbFile()
{
    
}

/**
 * @brief シーンをロードする
 * @param[in] iSceneId シーンID
 */
Node* LoadCsbFile::loadScene(const ResInfoPool::E_RES_ID iSceneId)
{
    
    // リスース情報を取得する
    ResInfoPool::S_RES_INFO resInfo = Singleton<ResInfoPool>::getInstance()->getResInfo(iSceneId);
    
    if (ResInfoPool::E_RES_TYPE::E_SCENE != resInfo.ResType)
    {
        return nullptr;
    }
 
    CSLoader* instance = CSLoader::getInstance();
    // シーンIDより、シーンをロースする
    switch (iSceneId)
    {
        case ResInfoPool::E_RES_ID::E_SCENE_TOP:
        {
            instance->registReaderObject(CSB_READER(resInfo.Name.c_str()),
                                         (ObjectFactory::Instance)TopSceneReader::getInstance);
        }
            break;
            
        default:
            break;
    }
    
    // シーンを作成する
    Node* sceneRet = CSLoader::createNode(resInfo.Path);
    
    return sceneRet;
}

/**
 * @brief Csbファイル(普通)をロードする
 * @param[in] iPartsId パーツID
 * @param[in] iContentSize コンテンツサイズ
 */
Node* LoadCsbFile::loadPartsNormal(const ResInfoPool::E_RES_ID iPartsId,
                                   const cocos2d::Size& iContentSize)
{
    
    // リスース情報を取得する
    ResInfoPool::S_RES_INFO resInfo = Singleton<ResInfoPool>::getInstance()->getResInfo(iPartsId);
    
    if (ResInfoPool::E_RES_TYPE::E_PARTS_NORMAL != resInfo.ResType)
    {
        return nullptr;
    }
    
    CSLoader* instance = CSLoader::getInstance();
    // シーンIDより、シーンをロースする
    switch (iPartsId)
    {
        case ResInfoPool::E_RES_ID::E_PARTS_COORDINATE_MESH:
        {
            instance->registReaderObject(CSB_READER(resInfo.Name.c_str()),
                                         (ObjectFactory::Instance)CoordinateMeshReader::getInstance);
        }
            break;
            
        default:
            break;
    }
    
    // パーツを作成する
    Node* partsRet = CSLoader::createNode(resInfo.Path);
    
    // Csbパーツノードのコンテンツサイズをセットする
    this->setContentSizeOfCsbParts(partsRet, iContentSize, iPartsId);
    
    return partsRet;
}

/**
 * @brief Csbパーツノードのコンテンツサイズをセットする
 * @param[in] iPartsNode Csbパーツノード
 * @param[in] iContentSize コンテンツサイズ
 * @param[in] iResId リソースID
 */
void LoadCsbFile::setContentSizeOfCsbParts(Node* iPartsNode,
                                           const cocos2d::Size& iContentSize,
                                           const ResInfoPool::E_RES_ID& iResId)
{
    // コンテンツサイズを設定する
    if (cocos2d::Size::ZERO.equals(iContentSize))
    {
        return;
    }
    
    {
        switch (iResId)
        {
            case ResInfoPool::E_RES_ID::E_PARTS_COORDINATE_MESH:
            {
                CoordinateMesh* coordinateMeshTmp = dynamic_cast<CoordinateMesh*>(iPartsNode);
                if (coordinateMeshTmp)
                {
                    coordinateMeshTmp->setContentSize(iContentSize);
                }
            }
                break;
                
            default:
                break;
        }
    }
}

/**
 * @brief Csbファイル(アクション)をロードする
 * @param[in] iPartsActionId パーツアクションID
 */
timeline::ActionTimeline* LoadCsbFile::loadPartsAction(const ResInfoPool::E_RES_ID iPartsActionId)
{
    // リスース情報を取得する
    ResInfoPool::S_RES_INFO resInfo = Singleton<ResInfoPool>::getInstance()->getResInfo(iPartsActionId);
    
    if (ResInfoPool::E_RES_TYPE::E_PARTS_ACTION != resInfo.ResType)
    {
        return nullptr;
    }
    
    // パーツアクションをロードする
    timeline::ActionTimeline* partsAction = NULL;
    partsAction = CSLoader::createTimeline(resInfo.Path);
    
    return partsAction;
}