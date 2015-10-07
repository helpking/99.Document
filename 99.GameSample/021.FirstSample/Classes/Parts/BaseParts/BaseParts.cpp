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
    CsbBase::onEnter();
}

/**
 * @brief 変数一覧の初期化
 */
void BaseParts::initCcsMemberVariables()
{
    CsbBase::initCcsMemberVariables();
}

/**
 * @brief Csbファイルの情報を初期化する
 */
void BaseParts::initCsbFileInfo()
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
ui::Widget::ccWidgetTouchCallback BaseParts::initCcsOnTouchCallbackInfo(const std::string& iCallBackName)
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
ui::Widget::ccWidgetClickCallback BaseParts::initCcsOnClickCallbackInfo(const std::string& iCallBackName)
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
ui::Widget::ccWidgetEventCallback BaseParts::initCcsOnEnentCallbackInfo(const std::string& iCallBackName)
{
    ui::Widget::ccWidgetEventCallback callback = CsbBase::initCcsOnEnentCallbackInfo(iCallBackName);
    if (callback)
    {
        return callback;
    }
    return nullptr;
}
