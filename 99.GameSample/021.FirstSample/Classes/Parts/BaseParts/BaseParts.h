//
//  BaseParts.h
//  021.FirstSample
//
//  Created by 何 利強 on 2015/10/07.
//
//

#ifndef ___21_FirstSample__BaseParts__
#define ___21_FirstSample__BaseParts__

// LoadFileBase
#include "LoadFileBase.h"

// UI Header File
#include "UICommon.h"

USING_NS_INTERFACE_LAB;

NS_BEGIN_UIPARTS

class BaseParts
: public LoadFileBase
{
public:
    
    /**
     * @brief コンストラクター
     */
    BaseParts();
    
    /**
     * @brief デストラクター
     */
    ~BaseParts();
    
    virtual void onEnter() override;
    
    /**
     * @brief ロードファイルで指定された、変数一覧を初期化にする
     */
    virtual void initLoadFileMemberInfo() override;
    
    /**
     * @brief タッチコールバックの初期化
     * @param[in] iCallBackName コールバック名
     */
    virtual Widget::ccWidgetTouchCallback initOnTouchCallbackInfo(const std::string& iCallBackName) override;
    
    /**
     * @brief クリックコールバックの初期化
     * @param[in] iCallBackName コールバック名
     */
    virtual Widget::ccWidgetClickCallback initOnClickCallbackInfo(const std::string& iCallBackName) override;
    
    /**
     * @brief イベントコールバックの初期化
     * @param[in] iCallBackName コールバック名
     */
    virtual Widget::ccWidgetEventCallback initOnEnentCallbackInfo(const std::string& iCallBackName) override;
    
protected:
    
    /**
     * @brief ロードファイルの情報を初期化する
     */
    virtual void initLoadFileInfo() override;
    
    /**
     * @brief パーツの情報を初期化する
     */
    virtual void initPartsInfo();
    
    /**
     * @brief パーツサイズを取得する
     * @return パーツサイズ
     */
    inline Size getPartsSize()
    {
        return this->getBaseSize();
    };
    
private:
    
    
};


NS_END_UIPARTS

#endif /* defined(___21_FirstSample__BaseParts__) */
