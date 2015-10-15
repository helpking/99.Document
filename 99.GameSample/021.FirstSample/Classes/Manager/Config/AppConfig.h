//
//  AppConfig.h
//  021.FirstSample
//
//  Created by 何 利強 on 2015/10/15.
//
//

#ifndef ___21_FirstSample__AppConfig__
#define ___21_FirstSample__AppConfig__

#include "ManagerHeader.h"

USING_NS_CC;
NS_BEGIN_CONFIG

class AppConfig
{
public:
    
    /**
     * @brief コンストラクタ
     */
    AppConfig();
    
    /**
     * @brief デストラクタ
     */
    ~AppConfig();
    
    /**
     * @brief アプリ配置情報を取得する
     * @return アプリ配置情報
     */
    inline __Dictionary* getConfigInfo()
    {
        return this->confInfo_;
    };
    
private:
    
    //! アプリ配置情報
    __Dictionary* confInfo_;
    
    /**
     * @brief アプリ配置ファイル（Config.plist）をロードする
     * @param[in] iFilePath ファイル
     */
    void loadConfFile(const char* iFilePath);
};

NS_END_CONFIG

#endif /* defined(___21_FirstSample__AppConfig__) */
