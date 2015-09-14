//
//  TopScene.cpp
//  021.FirstSample
//
//  Created by 何 利強 on 2015/09/14.
//
//

#include "TopScene.h"

#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace std;
using namespace cocos2d::ui;

namespace UScene
{
    
    TopScene::TopScene()
    {
        
    }
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    bool TopScene::init()
    {
//        //加载动画：
//        cocostudio::timeline::ActionTimeline *action = NULL;
//        action = CSLoader::createTimeline("Role.csb");
//        action->gotoFrameAndPlay(0, 25, true);
//        this->runAction(action);
//        
//        action = CSLoader::createTimeline("WindMill.csb");
//        action->gotoFrameAndPlay(0, 35, true);
//        this->runAction(action);
//        
//        action = CSLoader::createTimeline("DemoPlayer.csb");
//        action->gotoFrameAndPlay(0, 316, true);
//        this->runAction(action);
        
        return true;
    }
    
    cocos2d::ui::Widget::ccWidgetTouchCallback TopScene::onLocateTouchCallback(const string &callBackName)
    {
        if (callBackName == "onTouch")//判断事件名，返回对应的函数。下同
        {
            return CC_CALLBACK_2(TopScene::onTouch, this);
        }
        return nullptr;
    }
    
    cocos2d::ui::Widget::ccWidgetClickCallback TopScene::onLocateClickCallback(const string &callBackName)
    {
        if (callBackName == "onClick")
        {
            return CC_CALLBACK_1(TopScene::onClick, this);
        }
        return nullptr;
    }
    
    cocos2d::ui::Widget::ccWidgetEventCallback TopScene::onLocateEventCallback(const string &callBackName)
    {
        if (callBackName == "onEvent")
        {
            return CC_CALLBACK_2(TopScene::onEvent, this);
        }
        return nullptr;
    }
    
    void TopScene::onTouch(cocos2d::Ref* object, cocos2d::ui::Widget::TouchEventType type)
    {
        CCLOG("onTouch");
    }
    
    void TopScene::onClick(cocos2d::Ref* sender)
    { 
        CCLOG("onClick"); 
    } 
    
    void TopScene::onEvent(cocos2d::Ref* sender, int eventType) 
    { 
        CCLOG("onEvent"); 
    }
    
    static TopSceneReader* _instanceTopSceneReader = nullptr;
    TopSceneReader* TopSceneReader::getInstance()
    {
        if (!_instanceTopSceneReader)
        {
            _instanceTopSceneReader = new TopSceneReader();
        }
        return _instanceTopSceneReader;
    }
    
    void TopSceneReader::purge()
    {
        CC_SAFE_DELETE(_instanceTopSceneReader);
    }
    
    Node* TopSceneReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions)
    {
        TopScene* node = TopScene::create();
        setPropsWithFlatBuffers(node, nodeOptions);
        return node;
    }
}
