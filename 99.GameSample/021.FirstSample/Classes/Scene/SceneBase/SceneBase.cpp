//
//  SceneBase.cpp
//  021.FirstSample
//
//  Created by 何 利強 on 2015/09/14.
//
//

#include "SceneBase.h"

USING_NS_CC;

namespace UScene
{
    SceneBase::SceneBase()
    {
        
    }
    SceneBase::~SceneBase()
    {
        
    }
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    void SceneBase::onEnter()
    {
        cocos2d::CCNode::onEnter();
    }
    
    cocos2d::ui::Widget::ccWidgetTouchCallback SceneBase::onLocateTouchCallback(const std::string &callBackName)
    {
        if (callBackName == "onTouch")
        {
            return CC_CALLBACK_2(SceneBase::onSceneTouch, this, callBackName);
        }
        return nullptr;
    }
    
    cocos2d::ui::Widget::ccWidgetClickCallback SceneBase::onLocateClickCallback(const std::string &callBackName)
    {
        if (callBackName == "onClick")
        {
            return CC_CALLBACK_1(SceneBase::onSceneClick, this, callBackName);
        }
        return nullptr;
    }
    
    cocos2d::ui::Widget::ccWidgetEventCallback SceneBase::onLocateEventCallback(const std::string &callBackName)
    {
        if (callBackName == "onEvent")
        {
            return CC_CALLBACK_2(SceneBase::onSceneEvent, this, callBackName);
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
