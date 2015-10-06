//
//  GameDraw.cpp
//  021.FirstSample
//
//  Created by 何 利強 on 2015/10/06.
//
//

#include "GameDraw.h"

USING_NS_COMMON_GDRAW;

/**
 * @brief コンストラクター
 */
GameDraw::GameDraw()
{
    
}

/**
 * @brief デストラクタ
 */
GameDraw::~GameDraw()
{
    
}

/**
 * @brief ラインを描画する
 * @param[in] iContentSize コンテンツサイズ
 * @param[in] iColor 色
 * @return 描画したライン
 */
cocos2d::LayerColor* GameDraw::drawLine(const cocos2d::Size& iContentSize,
                                       const cocos2d::Color4B& iColor)
{
    cocos2d::LayerColor* retLayer = cocos2d::LayerColor::create(iColor,
                                                                iContentSize.width,
                                                                iContentSize.height);
    
    return retLayer;
}