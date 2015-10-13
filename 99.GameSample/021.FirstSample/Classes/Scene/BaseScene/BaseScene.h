//
//  BaseScene.h
//  021.FirstSample
//
//  Created by 何 利強 on 2015/10/07.
//
//

#ifndef ___21_FirstSample__BaseScene__
#define ___21_FirstSample__BaseScene__

// Header File
#include "AppPlatform.h"

// LoadFileBase
#include "LoadFileBase.h"

USING_NS_INTERFACE_LAB;

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
: public LoadFileBase
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
     * @brief ロードファイルで指定された、変数一覧を初期化にする
     */
    void initLoadFileMemberInfo() override;
    
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
     * @brief ロードファイルの情報を初期化する
     */
    virtual void initLoadFileInfo() override;
    
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
     * @param[in] iUIBaseNode UIベイスノード
     */
    virtual bool initUIMemberVariables(Node* iUIBaseNode);
    
    /**
     * @brief エンティティ系の変数一覧の初期化
     * @param[in] iEntityBaseNode エンティティベイスノード
     */
    virtual bool initEntityMemberVariables(Node* iEntityBaseNode);
    
    /**
     * @brief UIベイスノードを取得する
     * @return UIベイスノード
     */
    inline Node* getUiBaseNode()
    {
        return this->UiBaseNode_;
    };
    
    /**
     * @brief エンティティベイスノードを取得する
     * @return エンティティベイスノード
     */
    inline Node* getEntityBaseNode()
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
