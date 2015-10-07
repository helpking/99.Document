//
//  BaseParts.h
//  021.FirstSample
//
//  Created by 何 利強 on 2015/10/07.
//
//

#ifndef ___21_FirstSample__BaseParts__
#define ___21_FirstSample__BaseParts__

#include "UICommon.h"

#include "CsbBase.h"

// Csbファイルローダー
#include "LoadCsbFile.h"

USING_NS_COMMON_CSB;

NS_BEGIN_UIPARTS

class BaseParts
: public CsbBase
{
public:
    
    /**
     * @brief コンストラクター
     */
    BaseParts();
    
    /**
     * @brief デストラクター
     */
    ~BaseParts();
    
    virtual void onEnter() override;
    
    /**
     * @brief 変数一覧の初期化
     */
    virtual void initCcsMemberVariables() override;
    
    /**
     * @brief タッチコールバックの初期化
     * @param[in] iCallBackName コールバック名
     */
    virtual ui::Widget::ccWidgetTouchCallback initCcsOnTouchCallbackInfo(const std::string& iCallBackName) override;
    
    /**
     * @brief クリックコールバックの初期化
     * @param[in] iCallBackName コールバック名
     */
    virtual ui::Widget::ccWidgetClickCallback initCcsOnClickCallbackInfo(const std::string& iCallBackName) override;
    
    /**
     * @brief イベントコールバックの初期化
     * @param[in] iCallBackName コールバック名
     */
    virtual ui::Widget::ccWidgetEventCallback initCcsOnEnentCallbackInfo(const std::string& iCallBackName) override;
    
protected:
    
    /**
     * @brief Csbファイルの情報を初期化する
     */
    virtual void initCsbFileInfo() override;
    
    /**
     * @brief パーツの情報を初期化する
     */
    virtual void initPartsInfo();
    
    /**
     * @brief パーツサイズを取得する
     * @return パーツサイズ
     */
    inline Size getSceneSize()
    {
        return this->getCsbBaseSize();
    };
    
private:
    
    
};


NS_END_UIPARTS

#endif /* defined(___21_FirstSample__BaseParts__) */
