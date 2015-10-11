//
//  FileLoader.cpp
//  021.FirstSample
//
//  Created by 何 利強 on 2015/10/17.
//
//

// MARK:Header File
#include "FileLoader.h"
#include "ResInfoPool.h"
#include "Singleton.h"

// Csbファイル：シーン
#include "TopScene.h"

// Csbファイル：パーツ
#include "CoordinateMesh.h"

// MARK:Namespace
USING_NS_INTERFACE_LAB;

// MARK:Class define
/**
 * @brief コンストラクター
 */
FileLoader::FileLoader()
{
}

/**
 * @brief デストラクター
 */
FileLoader::~FileLoader()
{
    
}

/**
 * @brief ロードファイルノードを作成する
 * @param[in] iFilePath ファイルパス
 * @return ロードファイルノード
 */
Node* FileLoader::createLoadFileNode(const std::string& iFilePath)
{
    if (iFilePath.empty())
    {
        return nullptr;
    }
    return CSLoader::createNode(iFilePath);
}

/**
 * @brief ロードファイルノードを作成する
 * @param[in] iFilePath ファイルパス
 * @return ロードファイルノード
 */
timeline::ActionTimeline* FileLoader::createLoadActionTimeLine(const std::string& iFilePath)
{
    if (iFilePath.empty())
    {
        return nullptr;
    }
    return CSLoader::createTimeline(iFilePath);
}

/**
 * @brief ファイルをロードする
 * @param[in] iResInfo リソース情報
 * @param[in] iContentSize コンテンツサイズ
 */
Node* FileLoader::loadFile(const ResInfoPool::S_RES_INFO& iResInfo,
                           const Size& iContentSize)
{
    // リソースIDより、ファイルを登録する
    this->registFileLoaderObject(iResInfo.ResID);
    
    // ファイルノードを作成する
    Node* fileNodeRet = this->createLoadFileNode(iResInfo.Path);
    
    // ロードされたファイルノードをリセットする
    if (fileNodeRet)
    {
        this->resetLoadFileInfo(fileNodeRet, iContentSize, iResInfo.ResID);
    }
    
    return fileNodeRet;
}

/**
 * @brief シーンをロードする
 * @param[in] iSceneId シーンID
 * @param[in] iContentSize コンテンツサイズ
 */
Node* FileLoader::loadSceneFile(const ResInfoPool::E_RES_ID iSceneId,
                                const Size& iContentSize)
{
    
    // リスース情報を取得する
    ResInfoPool::S_RES_INFO resInfo = Singleton<ResInfoPool>::getInstance()->getResInfo(iSceneId);
    
    if (ResInfoPool::E_RES_TYPE::E_SCENE != resInfo.ResType)
    {
        return nullptr;
    }
 
    // シーンノードを作成する
    Node* sceneRet = this->loadFile(resInfo, iContentSize);
    
    return sceneRet;
}

/**
 * @brief Csbファイル(普通)をロードする
 * @param[in] iPartsId パーツID
 * @param[in] iContentSize コンテンツサイズ
 */
Node* FileLoader::loadPartsFile(const ResInfoPool::E_RES_ID iPartsId,
                                const cocos2d::Size& iContentSize)
{
    
    // リスース情報を取得する
    ResInfoPool::S_RES_INFO resInfo = Singleton<ResInfoPool>::getInstance()->getResInfo(iPartsId);
    
    if (ResInfoPool::E_RES_TYPE::E_PARTS_NORMAL != resInfo.ResType)
    {
        return nullptr;
    }
    
    // パーツを作成する
    Node* partsRet = this->loadFile(resInfo, iContentSize);
    
    return partsRet;
}

/**
 * @brief アクションファイルをロードする
 * @param[in] iResId リソースID
 */
timeline::ActionTimeline* FileLoader::loadActionFile(const ResInfoPool::E_RES_ID iResId)
{
    // リスース情報を取得する
    ResInfoPool::S_RES_INFO resInfo = Singleton<ResInfoPool>::getInstance()->getResInfo(iResId);
    if (ResInfoPool::E_RES_TYPE::E_PARTS_ACTION != resInfo.ResType)
    {
        return nullptr;
    }
    
    // パーツアクションをロードする
    timeline::ActionTimeline* action = this->createLoadActionTimeLine(resInfo.Path);
    
    return action;
}