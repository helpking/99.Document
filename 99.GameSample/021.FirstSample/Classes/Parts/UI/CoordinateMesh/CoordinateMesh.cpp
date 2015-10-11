//
//  CoordinateMesh.cpp
//  021.FirstSample
//
//  Created by 何 利強 on 2015/09/15.
//
//

#include "CoordinateMesh.h"
#include "Singleton.h"
#include "GameDraw.h"

USING_NS_UIPARTS;
USING_NS_COMMON_GDRAW;

// ファイルローダーを初期化する
FILE_LOADER_INIT(CoordinateMesh);

CoordinateMesh::CoordinateMesh()
{
    
}

CoordinateMesh::~CoordinateMesh()
{
}

// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
void CoordinateMesh::onEnter()
{
    BaseParts::onEnter();
    
    // ライン情報を初期化する
    this->initLineInfo(this->getPartsSize());
}

/**
 * @brief ロードファイルで指定された、変数一覧を初期化にする
 */
void CoordinateMesh::initLoadFileMemberInfo()
{
    BaseParts::initLoadFileMemberInfo();
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
}

/**
 * @brief ライン情報を初期化する
 * @param[in] iContentSize コンテンツサイズ
 */
void CoordinateMesh::initLineInfo(const cocos2d::Size& iContentSize)
{
    Size sizeTmp = Size::ZERO;
    sizeTmp.width = iContentSize.width;
    sizeTmp.height = 2.0f;
    
    Node* pLineTmp = Singleton<GameDraw>::getInstance()->drawLine(sizeTmp, Color4B::RED);
    
    pLineTmp->setPosition(Vec2(0.0f, 50.0f));
    this->getBaseNode()->addChild(pLineTmp);
}