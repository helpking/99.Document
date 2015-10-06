//
//  CoordinateMesh.cpp
//  021.FirstSample
//
//  Created by 何 利強 on 2015/09/15.
//
//

#include "CoordinateMesh.h"
#include "GameDraw.h"

USING_NS_UIPARTS
USING_NS_COMMON_GDRAW

// Csbファイルローダーを初期化する
CSB_INIT_LOADER(CoordinateMesh);

CoordinateMesh::CoordinateMesh()
{
    
}

CoordinateMesh::~CoordinateMesh()
{
    
}

// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
void CoordinateMesh::onEnter()
{
    CsbBase::onEnter();
    
    //
//    cocos2d::LayerColor 
}

/**
 * @brief コンテンツサイズより、初期化を行う
 * @param[in] iContentSize コンテンツサイズ
 */
void CoordinateMesh::initWithContentSize(const cocos2d::Size& iContentSize)
{
    // コンテンツサイズをリセットする
    this->setContentSize(iContentSize);
    
    // 背景色を設定する
    this->setColor(cocos2d::Color3B::GRAY);
    
    // ライン情報を初期化する
    this->initLineInfo(iContentSize);
}

/**
 * @brief ライン情報を初期化する
 * @param[in] iContentSize コンテンツサイズ
 */
void CoordinateMesh::initLineInfo(const cocos2d::Size& iContentSize)
{
    
}