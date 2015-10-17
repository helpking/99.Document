//
//  TopScene.h
//  021.FirstSample
//
//  Created by 何 利強 on 2015/09/14.
//
//

#ifndef ___21_FirstSample__TopScene__
#define ___21_FirstSample__TopScene__

#include "UCommon.h"

#include "CsbBase.h"
#include "UIButton.h"

namespace UScene
{
    
    class TopScene
    : public CsbBase
    {
    public:
        CREATE_FUNC(TopScene)
        TopScene();
        ~TopScene();
        // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
        virtual void onEnter() override;
        
        virtual void onWalkBtnTouch(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type);
        virtual void onAttackBtnTouch(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type);
        
        /**
         * @brief 変数一覧の初期化
         */
        virtual void initCcsMemberVariables() override;
        
        /**
         * @brief タッチコールバックの初期化
         * @param[in] iCallBackName コールバック名
         */
        virtual cocos2d::ui::Widget::ccWidgetTouchCallback initCcsOnTouchCallbackInfo(const std::string& iCallBackName) override;
        
    private:
        
        cocostudio::timeline::ActionTimeline* demoPlayerAction_;
        
        cocos2d::ui::Button* walkBtn_;
        
    };
    
    class TopSceneReader : public cocostudio::NodeReader
    {
    public:
        TopSceneReader() {};
        ~TopSceneReader() {};
        static TopSceneReader* getInstance();
        static void purge();
        cocos2d::Node* createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions);
    };
}

#endif /* defined(___21_FirstSample__TopScene__) */
