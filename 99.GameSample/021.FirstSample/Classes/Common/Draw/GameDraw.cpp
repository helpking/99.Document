//
//  GameDraw.cpp
//  021.FirstSample
//
//  Created by 何 利強 on 2015/10/06.
//
//

#include "GameDraw.h"

USING_NS_COMMON;

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
LayerColor* GameDraw::drawLine(const Size& iContentSize,
                               const Color4B& iColor)
{
    LayerColor* retLayer = cocos2d::LayerColor::create(iColor,
                                                       iContentSize.width,
                                                       iContentSize.height);
    
    return retLayer;
}