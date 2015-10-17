//
//  CsbBase.cpp
//  021.FirstSample
//
//  Created by 何 利強 on 2015/09/14.
//
//

#include "CsbBase.h"
#include "UIButton.h"

USING_NS_CC;
USING_COMMON_CSB;

CsbBase::CsbBase()
: uiLayerNode_(nullptr)
, sceneSize_(Size::ZERO)
{
    
}
CsbBase::~CsbBase()
{
    CC_SAFE_RELEASE_NULL(this->uiLayerNode_);
}

// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
void CsbBase::onEnter()
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
void CsbBase::initSceneInfo()
{
    this->sceneSize_ = CCDirector::getInstance()->getOpenGLView()->getDesignResolutionSize();
}

/**
 * @brief 変数一覧の初期化
 */
void CsbBase::initCcsMemberVariables()
{
    CSB_MEMBER_VARIABLE_ASSIGNER(this, "uiLayerNode", cocos2d::Node*, this->uiLayerNode_);
}

cocos2d::ui::Widget::ccWidgetTouchCallback CsbBase::onLocateTouchCallback(const std::string &callBackName)
{
    return this->initCcsOnTouchCallbackInfo(callBackName);
}

cocos2d::ui::Widget::ccWidgetClickCallback CsbBase::onLocateClickCallback(const std::string &callBackName)
{
    return this->initCcsOnClickCallbackInfo(callBackName);
}

cocos2d::ui::Widget::ccWidgetEventCallback CsbBase::onLocateEventCallback(const std::string &callBackName)
{
    return this->initCcsOnEnentCallbackInfo(callBackName);
}

/**
 * @brief タッチコールバックの初期化
 * @param[in] iCallBackName コールバック名
 */
cocos2d::ui::Widget::ccWidgetTouchCallback CsbBase::initCcsOnTouchCallbackInfo(const std::string& iCallBackName)
{
    if (iCallBackName == "onSceneTouch")
    {
        return CC_CALLBACK_2(CsbBase::onSceneTouch, this, iCallBackName);
    }
    return nullptr;
}

/**
 * @brief クリックコールバックの初期化
 * @param[in] iCallBackName コールバック名
 */
cocos2d::ui::Widget::ccWidgetClickCallback CsbBase::initCcsOnClickCallbackInfo(const std::string& iCallBackName)
{
    if (iCallBackName == "onSceneClick")
    {
        return CC_CALLBACK_1(CsbBase::onSceneClick, this, iCallBackName);
    }
    return nullptr;
}

/**
 * @brief イベントコールバックの初期化
 * @param[in] iCallBackName コールバック名
 */
cocos2d::ui::Widget::ccWidgetEventCallback CsbBase::initCcsOnEnentCallbackInfo(const std::string& iCallBackName)
{
    if (iCallBackName == "onSceneEvent")
    {
        return CC_CALLBACK_2(CsbBase::onSceneEvent, this, iCallBackName);
    }
    return nullptr;
}

void CsbBase::onSceneTouch(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type, const std::string &callBackName)
{
    CCLOG("[Debug:C I/A]CsbBase::onSceneTouch:[CallBackName:%s]", callBackName.c_str());
}

void CsbBase::onSceneClick(cocos2d::Ref* sender, const std::string &callBackName)
{
    CCLOG("[Debug:C I/A]CsbBase::onSceneClick:[CallBackName:%s]", callBackName.c_str());
}

void CsbBase::onSceneEvent(cocos2d::Ref* sender, int eventType, const std::string &callBackName)
{
    CCLOG("[Debug:C I/A]CsbBase::onSceneEvent:[CallBackName:%s]", callBackName.c_str());
}
