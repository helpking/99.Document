//
//  LoadFileBase.cpp
//  021.FirstSample
//
//  Created by 何 利強 on 2015/09/14.
//
//

#include "LoadFileBase.h"
#include "UIButton.h"

#include "Singleton.h"

USING_NS_INTERFACE_LAB;

LoadFileBase::LoadFileBase()
: BaseNode_(nullptr)
{
    
}
LoadFileBase::~LoadFileBase()
{
    CC_SAFE_RELEASE_NULL(BaseNode_);
}

// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
void LoadFileBase::onEnter()
{
    CCNode::onEnter();
    
    // ロードファイルで指定された、変数一覧を初期化にする
    this->initLoadFileMemberInfo();
    
    // ロードファイルの情報を初期化する
    this->initLoadFileInfo();
    
    // ZOrder情報を初期化する
    this->initZOrderInfo();
}

/**
 * @brief ロードファイルの情報を初期化する
 */
void LoadFileBase::initLoadFileInfo()
{
    
}

/**
 * @brief ロードファイルで指定された、変数一覧を初期化にする
 */
void LoadFileBase::initLoadFileMemberInfo()
{
    FILE_MEMBER_VARIABLE_ASSIGNER(this, "BaseNode", Node*, this->BaseNode_);
}

Widget::ccWidgetTouchCallback LoadFileBase::onLocateTouchCallback(const std::string &callBackName)
{
    return this->initOnTouchCallbackInfo(callBackName);
}

Widget::ccWidgetClickCallback LoadFileBase::onLocateClickCallback(const std::string &callBackName)
{
    return this->initOnClickCallbackInfo(callBackName);
}

Widget::ccWidgetEventCallback LoadFileBase::onLocateEventCallback(const std::string &callBackName)
{
    return this->initOnEnentCallbackInfo(callBackName);
}

/**
 * @brief タッチコールバックの初期化
 * @param[in] iCallBackName コールバック名
 */
Widget::ccWidgetTouchCallback LoadFileBase::initOnTouchCallbackInfo(const std::string& iCallBackName)
{
    if (iCallBackName == "onLoadFileTouch")
    {
        return CC_CALLBACK_2(LoadFileBase::onLoadFileTouch, this, iCallBackName);
    }
    return nullptr;
}

/**
 * @brief クリックコールバックの初期化
 * @param[in] iCallBackName コールバック名
 */
Widget::ccWidgetClickCallback LoadFileBase::initOnClickCallbackInfo(const std::string& iCallBackName)
{
    if (iCallBackName == "onLoadFileClick")
    {
        return CC_CALLBACK_1(LoadFileBase::onLoadFileClick, this, iCallBackName);
    }
    return nullptr;
}

/**
 * @brief イベントコールバックの初期化
 * @param[in] iCallBackName コールバック名
 */
Widget::ccWidgetEventCallback LoadFileBase::initOnEnentCallbackInfo(const std::string& iCallBackName)
{
    if (iCallBackName == "onLoadFileEvent")
    {
        return CC_CALLBACK_2(LoadFileBase::onLoadFileEvent, this, iCallBackName);
    }
    return nullptr;
}

void LoadFileBase::onLoadFileTouch(Ref* sender, Widget::TouchEventType type, const std::string &callBackName)
{
    CCLOG("[Debug:C I/A]LoadFileBase::onLoadFileTouch:[CallBackName:%s]", callBackName.c_str());
}

void LoadFileBase::onLoadFileClick(Ref* sender, const std::string &callBackName)
{
    CCLOG("[Debug:C I/A]LoadFileBase::onLoadFileClick:[CallBackName:%s]", callBackName.c_str());
}

void LoadFileBase::onLoadFileEvent(Ref* sender, int eventType, const std::string &callBackName)
{
    CCLOG("[Debug:C I/A]LoadFileBase::onLoadFileEvent:[CallBackName:%s]", callBackName.c_str());
}
