//
//  SceneBase.cpp
//  021.FirstSample
//
//  Created by 何 利強 on 2015/09/14.
//
//

#include "SceneBase.h"
#include "UIButton.h"

USING_NS_CC;

namespace UScene
{
    SceneBase::SceneBase()
    : uiLayerNode_(nullptr)
    , sceneSize_(Size::ZERO)
    {
        
    }
    SceneBase::~SceneBase()
    {
        CC_SAFE_RELEASE_NULL(this->uiLayerNode_);
    }
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    void SceneBase::onEnter()
    {
        cocos2d::CCNode::onEnter();
        
        // シーンの情報を初期化する
        this->initSceneInfo();
        
        // 変数一覧の初期化
        this->initCcsMemberVariables();
    }
    
    /**
     * @brief シーンの情報を初期化する
     */
    void SceneBase::initSceneInfo()
    {
       this->sceneSize_ = CCDirector::getInstance()->getOpenGLView()->getDesignResolutionSize();
    }
    
    /**
     * @brief 変数一覧の初期化
     */
    void SceneBase::initCcsMemberVariables()
    {
        CSB_MEMBER_VARIABLE_ASSIGNER(this, "uiLayerNode", cocos2d::Node*, this->uiLayerNode_);
    }
    
    cocos2d::ui::Widget::ccWidgetTouchCallback SceneBase::onLocateTouchCallback(const std::string &callBackName)
    {
        return this->initCcsOnTouchCallbackInfo(callBackName);
    }
    
    cocos2d::ui::Widget::ccWidgetClickCallback SceneBase::onLocateClickCallback(const std::string &callBackName)
    {
        return this->initCcsOnClickCallbackInfo(callBackName);
    }
    
    cocos2d::ui::Widget::ccWidgetEventCallback SceneBase::onLocateEventCallback(const std::string &callBackName)
    {
        return this->initCcsOnEnentCallbackInfo(callBackName);
    }
    
    /**
     * @brief タッチコールバックの初期化
     * @param[in] iCallBackName コールバック名
     */
    cocos2d::ui::Widget::ccWidgetTouchCallback SceneBase::initCcsOnTouchCallbackInfo(const std::string& iCallBackName)
    {
        if (iCallBackName == "onSceneTouch")
        {
            return CC_CALLBACK_2(SceneBase::onSceneTouch, this, iCallBackName);
        }
        return nullptr;
    }
    
    /**
     * @brief クリックコールバックの初期化
     * @param[in] iCallBackName コールバック名
     */
    cocos2d::ui::Widget::ccWidgetClickCallback SceneBase::initCcsOnClickCallbackInfo(const std::string& iCallBackName)
    {
        if (iCallBackName == "onSceneClick")
        {
            return CC_CALLBACK_1(SceneBase::onSceneClick, this, iCallBackName);
        }
        return nullptr;
    }
    
    /**
     * @brief イベントコールバックの初期化
     * @param[in] iCallBackName コールバック名
     */
    cocos2d::ui::Widget::ccWidgetEventCallback SceneBase::initCcsOnEnentCallbackInfo(const std::string& iCallBackName)
    {
        if (iCallBackName == "onSceneEvent")
        {
            return CC_CALLBACK_2(SceneBase::onSceneEvent, this, iCallBackName);
        }
        return nullptr;
    }
    
    void SceneBase::onSceneTouch(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type, const std::string &callBackName)
    {
        CCLOG("[Debug:C I/A]SceneBase::onSceneTouch:[CallBackName:%s]", callBackName.c_str());
    }
    
    void SceneBase::onSceneClick(cocos2d::Ref* sender, const std::string &callBackName)
    {
        CCLOG("[Debug:C I/A]SceneBase::onSceneClick:[CallBackName:%s]", callBackName.c_str());
    }
    
    void SceneBase::onSceneEvent(cocos2d::Ref* sender, int eventType, const std::string &callBackName)
    {
        CCLOG("[Debug:C I/A]SceneBase::onSceneEvent:[CallBackName:%s]", callBackName.c_str());
    }
}
