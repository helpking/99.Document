//
//  BaseScene.h
//  021.FirstSample
//
//  Created by 何 利強 on 2015/10/07.
//
//

#ifndef ___21_FirstSample__BaseScene__
#define ___21_FirstSample__BaseScene__

#include "UICommon.h"

#include "CsbBase.h"

// Csbファイルローダー
#include "LoadCsbFile.h"

USING_NS_COMMON;
USING_NS_COMMON_CSB;

NS_BEGIN_UISCENE

class BaseScene
: public CsbBase
{
public:
    
    /**
     * @brief コンストラクター
     */
    BaseScene();
    
    /**
     * @brief デストラクター
     */
    ~BaseScene();
    
    virtual void onEnter() override;
    
    /**
     * @brief 変数一覧の初期化
     */
    virtual void initCcsMemberVariables() override;
    
    /**
     * @brief タッチコールバックの初期化
     * @param[in] iCallBackName コールバック名
     */
    virtual cocos2d::ui::Widget::ccWidgetTouchCallback initCcsOnTouchCallbackInfo(const std::string& iCallBackName) override;
    
    /**
     * @brief クリックコールバックの初期化
     * @param[in] iCallBackName コールバック名
     */
    virtual cocos2d::ui::Widget::ccWidgetClickCallback initCcsOnClickCallbackInfo(const std::string& iCallBackName) override;
    
    /**
     * @brief イベントコールバックの初期化
     * @param[in] iCallBackName コールバック名
     */
    virtual cocos2d::ui::Widget::ccWidgetEventCallback initCcsOnEnentCallbackInfo(const std::string& iCallBackName) override;
    
    /**
     * @brief UILayerノードを取得する
     * @return UILayerノード
     */
    inline cocos2d::Node* getUILayer()
    {
        return this->uiLayerBaseNode_;
    };
    
protected:
    
    /**
     * @brief シーンの情報を初期化する
     */
    virtual void initSceneInfo() override;
    
    /**
     * @brief シーンサイズを取得する
     * @return シーンサイズ
     */
    inline Size getSceneSize()
    {
        return this->sceneSize_;
    };
    
private:
    
    //! UIレイアベイスノード
    Node* uiLayerBaseNode_;
    
    //! シーンサイズ
    Size sceneSize_;
};

NS_END_UISCENE


#endif /* defined(___21_FirstSample__BaseScene__) */
