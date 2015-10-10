//
//  FileLoader.h
//  021.FirstSample
//
//  Created by 何利强 on 15-10-11.
//
//

#ifndef _21_FirstSample_FileLoader_h
#define _21_FirstSample_FileLoader_h

// MARK:Header File
#include "InterfaceLab.h"

NS_BEGIN_NS_INTERFACE_LAB

/**
 * @brief ファイルローダー
 */
class FileLoader
{
public:
    
    /**
     * @brief コンストラクター
     */
    FileLoader();
    
    /**
     * @brief デストラクター
     */
    ~FileLoader();
    
    /**
     * @brief シーンをロードする
     * @param[in] iSceneId シーンID
     */
    Node* loadScene(const ResInfoPool::E_RES_ID iSceneId);
    
    /**
     * @brief Csbファイル(普通)をロードする
     * @param[in] iPartsId パーツID
     * @param[in] iContentSize コンテンツサイズ
     */
    Node* loadPartsNormal(const ResInfoPool::E_RES_ID iPartsId,
                          const cocos2d::Size& iContentSize = cocos2d::Size::ZERO);
    
    /**
     * @brief Csbファイル(アクション)をロードする
     * @param[in] iPartsActionId パーツアクションID
     */
    timeline::ActionTimeline* loadPartsAction(const ResInfoPool::E_RES_ID iPartsActionId);
    
protected:
    
    /**
     * @brief クラス名で、ファイルローダーを登録する
     * @param[in] iClassName クラス名
     * @param[in] iInstance インスタンス
     */
    virtual void registFileLoaderObject(const std::string& iClassName,
                                        ObjectFactory::Instance iInstance){};
    
};

NS_END_NS_INTERFACE_LAB

#endif
