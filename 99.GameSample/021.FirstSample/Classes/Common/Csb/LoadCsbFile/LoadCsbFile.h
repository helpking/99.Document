//
//  LoadCsbFile.h
//  021.FirstSample
//
//  Created by 何 利強 on 2015/10/17.
//
//

#ifndef ___21_FirstSample__LoadCsbFile__
#define ___21_FirstSample__LoadCsbFile__

#include "CsbMacro.h"
#include "ResInfoPool.h"

USING_NS_CC;
USING_NS_COCOS_STUDIO;

USING_NS_RESINFO;

NS_BEGIN_COMMON_CSB

/**
 * @brief Csbファイルをロードするクラス
 */
class LoadCsbFile
{
public:
    
    /**
     * @brief コンストラクター
     */
    LoadCsbFile();
    
    /**
     * @brief デストラクター
     */
    ~LoadCsbFile();
    
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
    
private:
    
    /**
     * @brief Csbパーツノードのコンテンツサイズをセットする
     * @param[in] iPartsNode Csbパーツノード
     * @param[in] iContentSize コンテンツサイズ
     * @param[in] iResId リソースID
     */
    void setContentSizeOfCsbParts(Node* iPartsNode,
                                  const cocos2d::Size& iContentSize,
                                  const ResInfoPool::E_RES_ID& iResId);
    
};

NS_END_COMMON_CSB

#endif /* defined(___21_FirstSample__LoadCsbFile__) */
