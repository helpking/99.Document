//
//  TopScene.h
//  021.FirstSample
//
//  Created by 何 利強 on 2015/09/14.
//
//

#ifndef ___21_FirstSample__TopScene__
#define ___21_FirstSample__TopScene__

#include "UICommon.h"

#include "BaseScene.h"
#include "UIButton.h"

NS_BEGIN_UISCENE

class TopScene
: public BaseScene
{
public:
    CREATE_FUNC(TopScene)
    TopScene();
    ~TopScene();
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual void onEnter() override;
    
    virtual void onWalkBtnTouch(cocos2d::Ref* sender, Widget::TouchEventType type);
    virtual void onAttackBtnTouch(cocos2d::Ref* sender, Widget::TouchEventType type);
    
    /**
     * @brief タッチコールバックの初期化
     * @param[in] iCallBackName コールバック名
     */
    virtual Widget::ccWidgetTouchCallback initOnTouchCallbackInfo(const std::string& iCallBackName) override;
    
protected:
    
    /**
     * @brief シーンの情報を初期化する
     */
    virtual void initSceneInfo() override;
    
    /**
     * @brief UI系の変数一覧の初期化
     * @param[in] iUIBaseNode UIベイスノード
     */
    virtual bool initUIMemberVariables(Node* iUIBaseNode) override;
    
    /**
     * @brief エンティティ系の変数一覧の初期化
     * @param[in] iEntityBaseNode エンティティベイスノード
     */
    virtual bool initEntityMemberVariables(Node* iEntityBaseNode) override;
    
private:
    
    timeline::ActionTimeline* demoPlayerAction_;
    
    Button* walkBtn_;
    
};

// ファイルのローダー
FILE_LOADER_CREATE(TopScene);

NS_END_UISCENE

#endif /* defined(___21_FirstSample__TopScene__) */