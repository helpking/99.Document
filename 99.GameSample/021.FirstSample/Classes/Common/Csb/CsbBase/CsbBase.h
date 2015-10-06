//
//  CsbBase.h
//  021.FirstSample
//
//  Created by 何 利強 on 2015/09/14.
//
//

#ifndef ___21_FirstSample__CsbBase__
#define ___21_FirstSample__CsbBase__

#include "CsbMacro.h"

NS_BEGIN_COMMON_CSB

class CsbBase
: public cocos2d::Node
, public cocostudio::WidgetCallBackHandlerProtocol
{
public:
    CREATE_FUNC(CsbBase)
    CsbBase();
    ~CsbBase();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual void onEnter() override;
    
    virtual cocos2d::ui::Widget::ccWidgetTouchCallback onLocateTouchCallback(const std::string &callBackName);
    virtual cocos2d::ui::Widget::ccWidgetClickCallback onLocateClickCallback(const std::string &callBackName);
    virtual cocos2d::ui::Widget::ccWidgetEventCallback onLocateEventCallback(const std::string &callBackName);
    virtual void onSceneTouch(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type, const std::string &callBackName);
    virtual void onSceneClick(cocos2d::Ref* sender, const std::string &callBackName);
    virtual void onSceneEvent(cocos2d::Ref* sender, int eventType, const std::string &callBackName);
    
    /**
     * @brief 変数一覧の初期化
     */
    virtual void initCcsMemberVariables();
    
    /**
     * @brief タッチコールバックの初期化
     * @param[in] iCallBackName コールバック名
     */
    virtual cocos2d::ui::Widget::ccWidgetTouchCallback initCcsOnTouchCallbackInfo(const std::string& iCallBackName);
    
    /**
     * @brief クリックコールバックの初期化
     * @param[in] iCallBackName コールバック名
     */
    virtual cocos2d::ui::Widget::ccWidgetClickCallback initCcsOnClickCallbackInfo(const std::string& iCallBackName);
    
    /**
     * @brief イベントコールバックの初期化
     * @param[in] iCallBackName コールバック名
     */
    virtual cocos2d::ui::Widget::ccWidgetEventCallback initCcsOnEnentCallbackInfo(const std::string& iCallBackName);
    
    /**
     * @brief UILayerノードを取得する
     * @return UILayerノード
     */
    inline cocos2d::Node* getUILayer()
    {
        return this->uiLayerNode_;
    };
    
protected:
    
    /**
     * @brief シーンの情報を初期化する
     */
    virtual void initSceneInfo();
    
private:
    
    cocos2d::Node* uiLayerNode_;
    
    // 画面のサイズ
    cocos2d::Size sceneSize_;
};

NS_END_COMMON_CSB

#endif /* defined(___21_FirstSample__CsbBase__) */
