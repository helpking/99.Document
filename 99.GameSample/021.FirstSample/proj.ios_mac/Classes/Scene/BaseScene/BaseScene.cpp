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
    LoadFileBase::onEnter();
    
    if (this->getName().empty())
    {
        WARNING_LOG("-> Scene : name null!!!");
    }
    else
    {
        INFO_LOG("-> Scene : %s", this->getName().c_str());
    }
}


void BaseScene::onExit()
{
    INFO_LOG("<- Scene:%s", this->getName().c_str());
}

/**
 * @brief ロードファイルで指定された、変数一覧を初期化にする
 */
void BaseScene::initLoadFileMemberInfo()
{
    LoadFileBase::initLoadFileMemberInfo();
    
    if (this->getBaseNode() == nullptr)
    {
        return;
    }
    
    // UI系の初期化
    FILE_MEMBER_VARIABLE_ASSIGNER(this->getBaseNode(), "UiBaseNode", Node*, this->UiBaseNode_);
    this->initUIMemberVariables(this->UiBaseNode_);
    
    // エンティティ系の初期化
    FILE_MEMBER_VARIABLE_ASSIGNER(this->getBaseNode(), "EntityBaseNode", Node*, this->EntityBaseNode_);
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
Widget::ccWidgetTouchCallback BaseScene::initOnTouchCallbackInfo(const std::string& iCallBackName)
{
    Widget::ccWidgetTouchCallback callback = LoadFileBase::initOnTouchCallbackInfo(iCallBackName);
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
Widget::ccWidgetClickCallback BaseScene::initOnClickCallbackInfo(const std::string& iCallBackName)
{
    Widget::ccWidgetClickCallback callback = LoadFileBase::initOnClickCallbackInfo(iCallBackName);
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
Widget::ccWidgetEventCallback BaseScene::initOnEnentCallbackInfo(const std::string& iCallBackName)
{
    Widget::ccWidgetEventCallback callback = LoadFileBase::initOnEnentCallbackInfo(iCallBackName);
    if (callback)
    {
        return callback;
    }
    return nullptr;
}

/**
 * @brief ロードファイルの情報を初期化する
 */
void BaseScene::initLoadFileInfo()
{
    // シーンの情報を初期化する
    this->initSceneInfo();
}

/**
 * @brief シーンのZOrderの情報を
 */
void BaseScene::initZOrderInfo()
{
    LoadFileBase::initZOrderInfo();
    
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