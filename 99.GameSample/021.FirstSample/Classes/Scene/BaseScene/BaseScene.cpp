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
: uiLayerBaseNode_(nullptr)
, sceneSize_(Size::ZERO)
{
    
}

/**
 * @brief デストラクター
 */
BaseScene::~BaseScene()
{
    CC_SAFE_RELEASE_NULL(uiLayerBaseNode_);
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
    
    CSB_MEMBER_VARIABLE_ASSIGNER(this, "uiLayerNode", cocos2d::Node*, this->uiLayerBaseNode_);
}

/**
 * @brief タッチコールバックの初期化
 * @param[in] iCallBackName コールバック名
 */
ui::Widget::ccWidgetTouchCallback BaseScene::initCcsOnTouchCallbackInfo(const std::string& iCallBackName)
{
    return CsbBase::initCcsOnTouchCallbackInfo(iCallBackName);
}

/**
 * @brief クリックコールバックの初期化
 * @param[in] iCallBackName コールバック名
 */
ui::Widget::ccWidgetClickCallback BaseScene::initCcsOnClickCallbackInfo(const std::string& iCallBackName)
{
    return CsbBase::initCcsOnClickCallbackInfo(iCallBackName);
}

/**
 * @brief イベントコールバックの初期化
 * @param[in] iCallBackName コールバック名
 */
cocos2d::ui::Widget::ccWidgetEventCallback BaseScene::initCcsOnEnentCallbackInfo(const std::string& iCallBackName)
{
    return CsbBase::initCcsOnEnentCallbackInfo(iCallBackName);
}

/**
 * @brief シーンの情報を初期化する
 */
void BaseScene::initSceneInfo()
{
    this->sceneSize_ = CCDirector::getInstance()->getOpenGLView()->getDesignResolutionSize();
}