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
#include "UtilsFileLoader.h"

USING_NS_UISCENE;
USING_NS_INTERFACE_LAB;
USING_NS_COMMON_UTILS;

// ファイルローダーを初期化する
FILE_LOADER_INIT(TopScene)

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
    
    LOGINFO("TopScene::onEnter");
    WARNINGINFO("TopScene::onEnter");
    ERRORINFO("TopScene::onEnter");
    BaseScene::onEnter();
    
    //加载动画：
    timeline::ActionTimeline *action = NULL;
    action = Singleton<UtilsFileLoader>::getInstance()->loadActionFile(ResInfoPool::E_RES_ID::E_PARTS_ROLE);
    action->gotoFrameAndPlay(0, 25, true);
    this->runAction(action);
    
    action = Singleton<UtilsFileLoader>::getInstance()->loadActionFile(ResInfoPool::E_RES_ID::E_PARTS_WINDMILL);
    action->gotoFrameAndPlay(0, 35, true);
    this->runAction(action);
    
    this->demoPlayerAction_ = Singleton<UtilsFileLoader>::getInstance()->loadActionFile(ResInfoPool::E_RES_ID::E_PARTS_DEMO_PLAYER);
    this->demoPlayerAction_->gotoFrameAndPlay(0, 316, true);
    this->runAction(this->demoPlayerAction_);
    
}

/**
 * @brief シーンの情報を初期化する
 */
void TopScene::initSceneInfo()
{
    BaseScene::initSceneInfo();
    auto coordinateMeshNode = Singleton<UtilsFileLoader>::getInstance()->loadPartsFile(ResInfoPool::E_RES_ID::E_PARTS_COORDINATE_MESH, this->getSceneSize());
    this->getUiBaseNode()->addChild(coordinateMeshNode);
}

/**
 * @brief UI系の変数一覧の初期化
 * @param[in] iUIBaseNode UIベイスノード
 */
bool TopScene::initUIMemberVariables(Node* iUIBaseNode)
{
    if (BaseScene::initUIMemberVariables(iUIBaseNode) == false)
    {
        return false;
    }
    FILE_MEMBER_VARIABLE_ASSIGNER(iUIBaseNode, "walkBtn", Button*, this->walkBtn_);;
    
    return true;
}

/**
 * @brief エンティティ系の変数一覧の初期化
 * @param[in] iEntityBaseNode エンティティベイスノード
 */
bool TopScene::initEntityMemberVariables(Node* iEntityBaseNode)
{
    if (BaseScene::initEntityMemberVariables(iEntityBaseNode) == false)
    {
        return false;
    }
    
    
    return true;
}

/**
 * @brief タッチコールバックの初期化
 * @param[in] iCallBackName コールバック名
 */
cocos2d::ui::Widget::ccWidgetTouchCallback TopScene::initOnTouchCallbackInfo(const std::string& iCallBackName)
{
    
    ui::Widget::ccWidgetTouchCallback callback = BaseScene::initOnTouchCallbackInfo(iCallBackName);
    if (callback)
    {
        return callback;
    }
    
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
