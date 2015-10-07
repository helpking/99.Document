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
#include "Singleton.h"

USING_NS_CC;

using namespace std;
using namespace cocos2d::ui;


USING_NS_UISCENE;

// Csbファイルローダーを初期化する
CSB_INIT_LOADER(TopScene)

TopScene::TopScene()
: demoPlayerAction_(nullptr)
, walkBtn_(nullptr)
{
    
}

TopScene::~TopScene()
{
    CC_SAFE_RELEASE_NULL(walkBtn_);
}

// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
void TopScene::onEnter()
{
    BaseScene::onEnter();
    
    //加载动画：
    timeline::ActionTimeline *action = NULL;
    action = Singleton<LoadCsbFile>::getInstance()->loadPartsAction(ResInfoPool::E_RES_ID::E_PARTS_ROLE);
    action->gotoFrameAndPlay(0, 25, true);
    this->runAction(action);
    
    action = Singleton<LoadCsbFile>::getInstance()->loadPartsAction(ResInfoPool::E_RES_ID::E_PARTS_WINDMILL);
    action->gotoFrameAndPlay(0, 35, true);
    this->runAction(action);
    
    this->demoPlayerAction_ = action = Singleton<LoadCsbFile>::getInstance()->loadPartsAction(ResInfoPool::E_RES_ID::E_PARTS_DEMO_PLAYER);
    this->demoPlayerAction_->gotoFrameAndPlay(0, 316, true);
    this->runAction(this->demoPlayerAction_);
    
    if (this->walkBtn_)
    {
        this->walkBtn_->setEnabled(false);
        this->walkBtn_->setTouchEnabled(false);
    }
}

/**
 * @brief シーンの情報を初期化する
 */
void TopScene::initSceneInfo()
{
    BaseScene::initSceneInfo();
    auto coordinateMeshNode = Singleton<LoadCsbFile>::getInstance()->loadPartsNormal(ResInfoPool::E_RES_ID::E_PARTS_COORDINATE_MESH,
                                                                                     this->getSceneSize());
    this->getUILayer()->addChild(coordinateMeshNode);
}

/**
 * @brief 変数一覧の初期化
 */
void TopScene::initCcsMemberVariables()
{
    BaseScene::initCcsMemberVariables();
    
    CSB_MEMBER_VARIABLE_ASSIGNER(this, "walkBtn", cocos2d::ui::Button*, this->walkBtn_);
}

/**
 * @brief タッチコールバックの初期化
 * @param[in] iCallBackName コールバック名
 */
cocos2d::ui::Widget::ccWidgetTouchCallback TopScene::initCcsOnTouchCallbackInfo(const std::string& iCallBackName)
{
    if (iCallBackName == "onWalkBtnTouch")
    {
        return CC_CALLBACK_2(TopScene::onWalkBtnTouch, this);
    }
    else if (iCallBackName == "onAttackBtnTouch")
    {
        return CC_CALLBACK_2(TopScene::onAttackBtnTouch, this);
    }
    return nullptr;
}


void TopScene::onWalkBtnTouch(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type)
{
    if (this->demoPlayerAction_)
    {
        this->stopAction(this->demoPlayerAction_);
    }
    
    this->demoPlayerAction_ = CSLoader::createTimeline("Parts/DemoPlayer.csb");
    this->demoPlayerAction_->gotoFrameAndPlay(115, 160, true);
    this->runAction(this->demoPlayerAction_);
}

void TopScene::onAttackBtnTouch(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type)
{
    if (this->demoPlayerAction_)
    {
        this->stopAction(this->demoPlayerAction_);
    }
    
    this->demoPlayerAction_ = CSLoader::createTimeline("Parts/DemoPlayer.csb");
    this->demoPlayerAction_->gotoFrameAndPlay(131, 250, false);
    this->runAction(this->demoPlayerAction_);
}
