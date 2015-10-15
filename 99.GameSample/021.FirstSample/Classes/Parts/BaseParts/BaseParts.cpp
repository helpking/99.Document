//
//  BaseParts.cpp
//  021.FirstSample
//
//  Created by 何 利強 on 2015/10/07.
//
//

#include "BaseParts.h"

USING_NS_UIPARTS;

/**
 * @brief コンストラクター
 */
BaseParts::BaseParts()
{
}

/**
 * @brief デストラクター
 */
BaseParts::~BaseParts()
{
    
}

void BaseParts::onEnter()
{
    LoadFileBase::onEnter();
    
    if (this->getName().empty())
    {
        WARNING_LOG("-> Parts : name null!!!");
    }
    else
    {
        INFO_LOG("-> Parts : %s", this->getName().c_str());
    }
}


void BaseParts::onExit()
{
    INFO_LOG("<- Parts:%s", this->getName().c_str());
}

/**
 * @brief ロードファイルで指定された、変数一覧を初期化にする
 */
void BaseParts::initLoadFileMemberInfo()
{
    LoadFileBase::initLoadFileMemberInfo();
}

/**
 * @brief ロードファイルの情報を初期化する
 */
void BaseParts::initLoadFileInfo()
{
    // パーツの情報を初期化する
    this->initPartsInfo();
}

/**
 * @brief パーツの情報を初期化する
 */
void BaseParts::initPartsInfo()
{
    
}

/**
 * @brief タッチコールバックの初期化
 * @param[in] iCallBackName コールバック名
 */
Widget::ccWidgetTouchCallback BaseParts::initOnTouchCallbackInfo(const std::string& iCallBackName)
{
    ui::Widget::ccWidgetTouchCallback callback = LoadFileBase::initOnTouchCallbackInfo(iCallBackName);
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
Widget::ccWidgetClickCallback BaseParts::initOnClickCallbackInfo(const std::string& iCallBackName)
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
Widget::ccWidgetEventCallback BaseParts::initOnEnentCallbackInfo(const std::string& iCallBackName)
{
    Widget::ccWidgetEventCallback callback = LoadFileBase::initOnEnentCallbackInfo(iCallBackName);
    if (callback)
    {
        return callback;
    }
    return nullptr;
}
