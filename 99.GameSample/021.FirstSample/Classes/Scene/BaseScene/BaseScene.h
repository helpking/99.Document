//
//  BaseScene.h
//  021.FirstSample
//
//  Created by 何 利強 on 2015/10/07.
//
//

#ifndef ___21_FirstSample__BaseScene__
#define ___21_FirstSample__BaseScene__

#include "UICommon.h"

#include "CsbBase.h"

// Csbファイルローダー
#include "LoadCsbFile.h"

USING_NS_COMMON;
USING_NS_COMMON_CSB;

NS_BEGIN_UISCENE

/**
 * @brief ZOrderインデックス定義（外 -> 裏）
 */
enum class E_ZORDER_IDX
{
    E_INVALID = -1,
    
    /**
     * @brief UI系
     */
    E_UI_BASE,
    E_UI_POP_DLG,
    
    /**
     * @brief カレントシーン
     */
    E_CUR_SCENE,
    
    /**
     * @brief エンティティ系
     */
    E_ENTITY_BASE,
    
    E_MAX
};

class BaseScene
: public CsbBase
{
public:
    
    /**
     * @brief コンストラクター
     */
    BaseScene();
    
    /**
     * @brief デストラクター
     */
    ~BaseScene();
    
    virtual void onEnter() override;
    
    /**
     * @brief 変数一覧の初期化
     */
    void initCcsMemberVariables() override;
    
    /**
     * @brief タッチコールバックの初期化
     * @param[in] iCallBackName コールバック名
     */
    virtual cocos2d::ui::Widget::ccWidgetTouchCallback initCcsOnTouchCallbackInfo(const std::string& iCallBackName) override;
    
    /**
     * @brief クリックコールバックの初期化
     * @param[in] iCallBackName コールバック名
     */
    virtual cocos2d::ui::Widget::ccWidgetClickCallback initCcsOnClickCallbackInfo(const std::string& iCallBackName) override;
    
    /**
     * @brief イベントコールバックの初期化
     * @param[in] iCallBackName コールバック名
     */
    virtual cocos2d::ui::Widget::ccWidgetEventCallback initCcsOnEnentCallbackInfo(const std::string& iCallBackName) override;
    
    /**
     * @brief ZOrderを取得する
     * @param[in] iZorderIdx ZOrderインデックス
     */
    inline static int getZOrderByIdx(const E_ZORDER_IDX iZorderIdx)
    {
        int intRet = (int)E_ZORDER_IDX::E_INVALID;
        
        if (E_ZORDER_IDX::E_INVALID != iZorderIdx)
        {
            intRet = (int)E_ZORDER_IDX::E_MAX - (int)iZorderIdx;
        }
        
        return intRet;
    };
    
protected:
    
    /**
     * @brief Csbファイルの情報を初期化する
     */
    virtual void initCsbFileInfo() override;
    
    /**
     * @brief シーンのZOrderの情報を
     */
    virtual void initZOrderInfo() override;
    
    /**
     * @brief シーンの情報を初期化する
     */
    virtual void initSceneInfo();
    
    /**
     * @brief UI系の変数一覧の初期化
     */
    virtual void initUIMemberVariables() {};
    
    /**
     * @brief エンティティ系の変数一覧の初期化
     */
    virtual void initEntityMemberVariables() {};
    
    /**
     * @brief UIベイスノードを取得する
     * @return UIベイスノード
     */
    inline cocos2d::Node* getUiBaseNode()
    {
        return this->UiBaseNode_;
    };
    
    /**
     * @brief エンティティベイスノードを取得する
     * @return エンティティベイスノード
     */
    inline cocos2d::Node* getEntityBaseNode()
    {
        return this->EntityBaseNode_;
    };
    
    /**
     * @brief シーンサイズを取得する
     * @return シーンサイズ
     */
    inline Size getSceneSize()
    {
        return this->sceneSize_;
    };
    
private:
    
    //! UIベイスノード
    Node* UiBaseNode_;
    //! UIベイスノード
    Node* EntityBaseNode_;
    
    //! シーンサイズ
    Size sceneSize_;
    
};

NS_END_UISCENE


#endif /* defined(___21_FirstSample__BaseScene__) */
