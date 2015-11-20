//
//  GameDraw.h
//  021.FirstSample
//
//  Created by 何 利強 on 2015/10/06.
//
//

#ifndef ___21_FirstSample__GameDraw__
#define ___21_FirstSample__GameDraw__

#include "CommonHeader.h"

NS_BEGIN_NS_COMMON

class GameDraw
{
public:
    
    /**
     * @brief コンストラクター
     */
    GameDraw();
    
    /**
     * @brief デストラクタ
     */
    ~GameDraw();
    
    /**
     * @brief ラインを描画する
     * @param[in] iContentSize コンテンツサイズ
     * @param[in] iColor 色
     * @return 描画したライン
     */
    static LayerColor* drawLine(const Size& iContentSize,
                                const Color4B& iColor);
    
protected:
    
private:
};

NS_END_NS_COMMON

#endif /* defined(___21_FirstSample__GameDraw__) */
