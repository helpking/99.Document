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
    : demoPlayer_(nullptr)
    {
        
    }
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    void TopScene::onEnter()
    {
        SceneBase::onEnter();
        
        //加载动画：
        cocostudio::timeline::ActionTimeline *action = NULL;
        action = CSLoader::createTimeline("Role.csb");
        action->gotoFrameAndPlay(0, 25, true);
        this->runAction(action);
        
        action = CSLoader::createTimeline("WindMill.csb");
        action->gotoFrameAndPlay(0, 35, true);
        this->runAction(action);
        
        this->demoPlayer_ = CSLoader::createTimeline("DemoPlayer.csb");
        this->demoPlayer_->gotoFrameAndPlay(0, 316, true);
        this->runAction(this->demoPlayer_);
        
    }
    
    cocos2d::ui::Widget::ccWidgetTouchCallback TopScene::onLocateTouchCallback(const std::string &callBackName)
    {
        if (callBackName == "onWalkBtnTouch")
        {
            return CC_CALLBACK_2(TopScene::onWalkBtnTouch, this, callBackName);
        }
        else if (callBackName == "onAttackBtnTouch")
        {
            return CC_CALLBACK_2(TopScene::onAttackBtnTouch, this, callBackName);
        }
        return nullptr;
    }
    
    void TopScene::onWalkBtnTouch(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type, const std::string &callBackName)
    {
        if (this->demoPlayer_)
        {
            this->stopAction(this->demoPlayer_);
//            CC_SAFE_RELEASE_NULL(this->demoPlayer_);
        }
        
        this->demoPlayer_ = CSLoader::createTimeline("DemoPlayer.csb");
        this->demoPlayer_->gotoFrameAndPlay(115, 160, true);
        this->runAction(this->demoPlayer_);
    }
    
    void TopScene::onAttackBtnTouch(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type, const std::string &callBackName)
    {
        if (this->demoPlayer_)
        {
            this->stopAction(this->demoPlayer_);
//            CC_SAFE_RELEASE_NULL(this->demoPlayer_);
        }
        
        this->demoPlayer_ = CSLoader::createTimeline("DemoPlayer.csb");
        this->demoPlayer_->gotoFrameAndPlay(131, 250, true);
        this->runAction(this->demoPlayer_);
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
