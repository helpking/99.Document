//
//  CoordinateMesh.h
//  021.FirstSample
//
//  Created by 何 利強 on 2015/09/15.
//
//

#ifndef ___21_FirstSample__CoordinateMesh__
#define ___21_FirstSample__CoordinateMesh__

#include "UICommon.h"
#include "CsbBase.h"

NS_BEGIN_UIPARTS

USING_NS_COMMON_CSB

class CoordinateMesh
: public CsbBase
{
public:
    CREATE_FUNC(CoordinateMesh)
    CoordinateMesh();
    ~CoordinateMesh();
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual void onEnter() override;
    
    /**
     * @brief コンテンツサイズより、初期化を行う
     * @param[in] iContentSize コンテンツサイズ
     */
    void initWithContentSize(const cocos2d::Size& iContentSize);
    
private:
    
    /**
     * @brief ライン情報を初期化する
     * @param[in] iContentSize コンテンツサイズ
     */
    void initLineInfo(const cocos2d::Size& iContentSize);
};

// CSBファイルのローダー
CSB_CREATE_LOADER(CoordinateMesh);

NS_END_UIPARTS

#endif /* defined(___21_FirstSample__CoordinateMesh__) */
