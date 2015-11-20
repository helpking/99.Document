//
//  AppConfig.cpp
//  021.FirstSample
//
//  Created by 何 利強 on 2015/10/15.
//
//

#include "AppConfig.h"

USING_NS_CONFIG;

// アプリ配置ファイル
#define APP_CONFIG_PATH                           "Config/Config.plist"

/**
 * @brief コンストラクタ
 */
AppConfig::AppConfig()
: confInfo_(nullptr)
{
    // アプリ配置ファイルをロードする
    this->loadConfFile(APP_CONFIG_PATH);
}

/**
 * @brief デストラクタ
 */
AppConfig::~AppConfig()
{
    CC_SAFE_RELEASE_NULL(this->confInfo_);
}

/**
 * @brief アプリ配置ファイル（Config.plist）をロードする
 * @param[in] iFilePath ファイル
 */
void AppConfig::loadConfFile(const char* iFilePath)
{
    std::string fullPath = FileUtils::getInstance()->fullPathForFilename(iFilePath);
    this->confInfo_ = __Dictionary::createWithContentsOfFileThreadSafe(fullPath.c_str());
    if (this->confInfo_)
    {
    }
}