//
//  UtilsFileLoader.cpp
//  021.FirstSample
//
//  Created by 何 利強 on 2015/10/11.
//
//

#pragma mark - 
#pragma mark ヘッダーファイル（共通）
#include "UtilsFileLoader.h"
#include "Singleton.h"

#pragma mark -
#pragma mark ヘッダーファイル（シーン）
#include "TopScene.h"

#pragma mark -
#pragma mark ヘッダーファイル（パーツ）
#include "CoordinateMesh.h"

USING_NS_COMMON_UTILS;
USING_NS_UISCENE;
USING_NS_UIPARTS;

/**
 * @brief コンストラクター
 */
UtilsFileLoader::UtilsFileLoader()
{
    
}

/**
 * @brief デストラクタ
 */
UtilsFileLoader::~UtilsFileLoader()
{
    
}

/**
 * @brief リソースIDで、ファイルローダーを登録する
 * @param[in] iResId リソースID
 * @return 登録成功フラグ
 */
bool UtilsFileLoader::registFileLoaderObject(const ResInfoPool::E_RES_ID iResId)
{
    if (FileLoader::registFileLoaderObject(iResId) == false)
    {
        return false;
    }
    
    // リスース情報を取得する
    ResInfoPool::S_RES_INFO resInfo = Singleton<ResInfoPool>::getInstance()->getResInfo(iResId);
    // リソースが無効、または、未存在の場合
    if (ResInfoPool::E_RES_TYPE::E_INVALID == resInfo.ResType)
    {
        return false;
    }
    
    // 登録する
    CSLoader* instance = CSLoader::getInstance();
    // シーンIDより、シーンをロースする
    switch (iResId)
    {
            // シーン
            // トップシーン
        case ResInfoPool::E_RES_ID::E_SCENE_TOP:
        {
            instance->registReaderObject(FILE_READER_NAME(resInfo.Name.c_str()),
                                         (ObjectFactory::Instance)TopSceneReader::getInstance);
        }
            break;
            
            // パーツ
        case ResInfoPool::E_RES_ID::E_PARTS_COORDINATE_MESH:
        {
            instance->registReaderObject(FILE_READER_NAME(resInfo.Name.c_str()),
                                         (ObjectFactory::Instance)CoordinateMeshReader::getInstance);
        }
            break;
        default:
            break;
    }
    
    return true;
}

/**
 * @brief ロードされたファイルの情報をリセットする
 * @param[in] iPartsNode ロードされたファイルノード
 * @param[in] iContentSize コンテンツサイズ
 * @param[in] iResId リソースID
 */
void UtilsFileLoader::resetLoadFileInfo(Node* iLoaderFileNode,
                                        const Size& iContentSize,
                                        const ResInfoPool::E_RES_ID& iResId)
{
    
}