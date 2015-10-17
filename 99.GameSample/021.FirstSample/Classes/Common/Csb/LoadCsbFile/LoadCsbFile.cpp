//
//  LoadCsbFile.cpp
//  021.FirstSample
//
//  Created by 何 利強 on 2015/10/17.
//
//

#include "LoadCsbFile.h"

#include "TopScene.h"

USING_NS_COMMON_CSB;

LoadCsbFile* LoadCsbFile::_gInstance = nullptr;

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
 * @brief Csbファイルをロードする
 * @param[in] iCsbFilePath Csbファイル
 */
Node* LoadCsbFile::loadFile(const char* iCsbFilePath)
{
    CSLoader* instance = CSLoader::getInstance();
    instance->registReaderObject("TopSceneReader",(ObjectFactory::Instance)UIScene::TopSceneReader::getInstance);
    
    auto fileNode = CSLoader::createNode("Scene/TopScene.csb");
    return fileNode;
}