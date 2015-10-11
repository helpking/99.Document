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

// MARK:マクロ定義
// Csbファイル読み込む用名
#define FILE_READER_NAME(__CSB_NAME__)           CCString::createWithFormat("%sReader", __CSB_NAME__)->getCString()

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
     * @brief ファイルをロードする
     * @param[in] iResInfo リソース情報
     * @param[in] iContentSize コンテンツサイズ
     */
    Node* loadFile(const ResInfoPool::S_RES_INFO& iResInfo,
                   const Size& iContentSize = Size::ZERO);
    
    /**
     * @brief アクションファイルをロードする
     * @param[in] iResId リソースID
     */
    timeline::ActionTimeline* loadActionFile(const ResInfoPool::E_RES_ID iResId);
    
    /**
     * @brief シーンをロードする
     * @param[in] iSceneId シーンID
     * @param[in] iContentSize コンテンツサイズ
     */
    Node* loadSceneFile(const ResInfoPool::E_RES_ID iSceneId,
                        const Size& iContentSize = Size::ZERO);
    
    /**
     * @brief パーツファイル(普通)をロードする
     * @param[in] iPartsId パーツID
     * @param[in] iContentSize コンテンツサイズ
     */
    Node* loadPartsFile(const ResInfoPool::E_RES_ID iPartsId,
                        const Size& iContentSize = cocos2d::Size::ZERO);
    
protected:
    
    /**
     * @brief ロードファイルノードを作成する
     * @param[in] iFilePath ファイルパス
     * @return ロードファイルノード
     */
    Node* createLoadFileNode(const std::string& iFilePath);
    
    /**
     * @brief ロードファイルノードを作成する
     * @param[in] iFilePath ファイルパス
     * @return ロードファイルノード
     */
    timeline::ActionTimeline* createLoadActionTimeLine(const std::string& iFilePath);
    
    /**
     * @brief リソースIDで、ファイルローダーを登録する
     * @param[in] iResId リソースID
     * @return 登録成功フラグ
     */
    virtual bool registFileLoaderObject(const ResInfoPool::E_RES_ID iResId) { return true; };
    
    /**
     * @brief ロードされたファイルの情報をリセットする
     * @param[in] iPartsNode ロードされたファイルノード
     * @param[in] iContentSize コンテンツサイズ
     * @param[in] iResId リソースID
     */
    virtual void resetLoadFileInfo(Node* iLoaderFileNode,
                                   const Size& iContentSize,
                                   const ResInfoPool::E_RES_ID& iResId) {};
    
};

NS_END_NS_INTERFACE_LAB

#endif
