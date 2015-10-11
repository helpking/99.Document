//
//  GameManager.cpp
//  021.FirstSample
//
//  Created by 何利强 on 15-10-5.
//
//

#include "GameManager.h"
#include "ManagerHeader.h"

USING_NS_MANAGER

/**
 * @brief コンストラクター
 */
GameManager::GameManager()
{
    
}

/**
 * @brief デストラクタ
 */
GameManager::~GameManager()
{
    
}

/**
 * @brief 初期化する
 */
void GameManager::init()
{

}

/**
 * @brief Plistファイルを読み込む
 * @param[in] iFilePath ファイル
 */
void GameManager::loadPlistFile(const char* iFilePath)
{
    std::string fullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(iFilePath);
    CCDictionary* fileInfo = CCDictionary::createWithContentsOfFileThreadSafe(fullPath.c_str());
    if (fileInfo)
    {
        
    }
}


