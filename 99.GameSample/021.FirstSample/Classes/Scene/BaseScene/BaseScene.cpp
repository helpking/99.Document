//
//  BaseScene.cpp
//  021.FirstSample
//
//  Created by 何 利強 on 2015/10/07.
//
//

#include "BaseScene.h"

USING_NS_UISCENE;

/**
 * @brief コンストラクター
 */
BaseScene::BaseScene()
: UiBaseNode_(nullptr)
, EntityBaseNode_(nullptr)
, sceneSize_(Size::ZERO)
{
    
}

/**
 * @brief デストラクター
 */
BaseScene::~BaseScene()
{
    CC_SAFE_RELEASE_NULL(UiBaseNode_);
    CC_SAFE_RELEASE_NULL(EntityBaseNode_);
}

void BaseScene::onEnter()
{
    CsbBase::onEnter();
}

/**
 * @brief 変数一覧の初期化
 */
void BaseScene::initCcsMemberVariables()
{
    CsbBase::initCcsMemberVariables();
    
    if (this->getBaseNode() == nullptr)
    {
        return;
    }
    
    // UI系の初期化
    CSB_MEMBER_VARIABLE_ASSIGNER(this->getBaseNode(), "UiBaseNode", cocos2d::Node*, this->UiBaseNode_);
    this->initUIMemberVariables(this->UiBaseNode_);
    
    // エンティティ系の初期化
    CSB_MEMBER_VARIABLE_ASSIGNER(this->getBaseNode(), "EntityBaseNode", cocos2d::Node*, this->EntityBaseNode_);
    this->initEntityMemberVariables(this->EntityBaseNode_);
}

/**
 * @brief UI系の変数一覧の初期化
 * @param[in] iUIBaseNode UIベイスノード
 */
bool BaseScene::initUIMemberVariables(Node* iUIBaseNode)
{
    if (iUIBaseNode == nullptr)
    {
        return false;
    }
    return true;
}

/**
 * @brief エンティティ系の変数一覧の初期化
 * @param[in] iEntityBaseNode エンティティベイスノード
 */
bool BaseScene::initEntityMemberVariables(Node* iEntityBaseNode)
{
    if (iEntityBaseNode == nullptr)
    {
        return false;
    }
    return true;
}

/**
 * @brief タッチコールバックの初期化
 * @param[in] iCallBackName コールバック名
 */
ui::Widget::ccWidgetTouchCallback BaseScene::initCcsOnTouchCallbackInfo(const std::string& iCallBackName)
{
    ui::Widget::ccWidgetTouchCallback callback = CsbBase::initCcsOnTouchCallbackInfo(iCallBackName);
    if (callback)
    {
        return callback;
    }
    return nullptr;
}

/**
 * @brief クリックコールバックの初期化
 * @param[in] iCallBackName コールバック名
 */
ui::Widget::ccWidgetClickCallback BaseScene::initCcsOnClickCallbackInfo(const std::string& iCallBackName)
{
    ui::Widget::ccWidgetClickCallback callback = CsbBase::initCcsOnClickCallbackInfo(iCallBackName);
    if (callback)
    {
        return callback;
    }
    return nullptr;
}

/**
 * @brief イベントコールバックの初期化
 * @param[in] iCallBackName コールバック名
 */
cocos2d::ui::Widget::ccWidgetEventCallback BaseScene::initCcsOnEnentCallbackInfo(const std::string& iCallBackName)
{
    ui::Widget::ccWidgetEventCallback callback = CsbBase::initCcsOnEnentCallbackInfo(iCallBackName);
    if (callback)
    {
        return callback;
    }
    return nullptr;
}

/**
 * @brief Csbファイルの情報を初期化する
 */
void BaseScene::initCsbFileInfo()
{
    // シーンの情報を初期化する
    this->initSceneInfo();
}

/**
 * @brief シーンのZOrderの情報を
 */
void BaseScene::initZOrderInfo()
{
    CsbBase::initZOrderInfo();
    
    if (this->UiBaseNode_)
    {
        this->UiBaseNode_->setZOrder(getZOrderByIdx(E_ZORDER_IDX::E_UI_BASE));
    }
    
    if (this->EntityBaseNode_)
    {
        this->EntityBaseNode_->setZOrder(getZOrderByIdx(E_ZORDER_IDX::E_ENTITY_BASE));
    }
}

/**
 * @brief シーンの情報を初期化する
 */
void BaseScene::initSceneInfo()
{
    this->sceneSize_ = CCDirector::getInstance()->getOpenGLView()->getDesignResolutionSize();
}