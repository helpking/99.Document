//
//  TitleScene.h
//  021.FirstSample
//
//  Created by 何 利強 on 2015/11/24.
//
//

#ifndef TitleScene_hpp
#define TitleScene_hpp

#include "UICommon.h"

#include "BaseScene.h"
#include "UIButton.h"

NS_BEGIN_UISCENE

class TitleScene
: public BaseScene
{
public:
    CREATE_FUNC(TitleScene)
    TitleScene();
    ~TitleScene();
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
FILE_LOADER_CREATE(TitleScene);

NS_END_UISCENE

#endif /* TitleScene_hpp */
