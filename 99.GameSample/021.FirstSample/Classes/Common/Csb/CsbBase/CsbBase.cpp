//
//  CsbBase.cpp
//  021.FirstSample
//
//  Created by 何 利強 on 2015/09/14.
//
//

#include "CsbBase.h"
#include "UIButton.h"

#include "Singleton.h"

// Csbファイルローダー
#include "LoadCsbFile.h"

USING_NS_COMMON_CSB;

CsbBase::CsbBase()
: BaseNode_(nullptr)
{
    
}
CsbBase::~CsbBase()
{
    CC_SAFE_RELEASE_NULL(BaseNode_);
}

// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
void CsbBase::onEnter()
{
    CCNode::onEnter();
    
    // 変数一覧の初期化
    this->initCcsMemberVariables();
    
    // Csbファイルの情報を初期化する
    this->initCsbFileInfo();
}

/**
 * @brief Csbファイルの情報を初期化する
 */
void CsbBase::initCsbFileInfo()
{
    
}

/**
 * @brief 変数一覧の初期化
 */
void CsbBase::initCcsMemberVariables()
{
    CSB_MEMBER_VARIABLE_ASSIGNER(this, "BaseNode", cocos2d::Node*, this->BaseNode_);
}

ui::Widget::ccWidgetTouchCallback CsbBase::onLocateTouchCallback(const std::string &callBackName)
{
    return this->initCcsOnTouchCallbackInfo(callBackName);
}

ui::Widget::ccWidgetClickCallback CsbBase::onLocateClickCallback(const std::string &callBackName)
{
    return this->initCcsOnClickCallbackInfo(callBackName);
}

ui::Widget::ccWidgetEventCallback CsbBase::onLocateEventCallback(const std::string &callBackName)
{
    return this->initCcsOnEnentCallbackInfo(callBackName);
}

/**
 * @brief タッチコールバックの初期化
 * @param[in] iCallBackName コールバック名
 */
ui::Widget::ccWidgetTouchCallback CsbBase::initCcsOnTouchCallbackInfo(const std::string& iCallBackName)
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
ui::Widget::ccWidgetClickCallback CsbBase::initCcsOnClickCallbackInfo(const std::string& iCallBackName)
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
ui::Widget::ccWidgetEventCallback CsbBase::initCcsOnEnentCallbackInfo(const std::string& iCallBackName)
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
