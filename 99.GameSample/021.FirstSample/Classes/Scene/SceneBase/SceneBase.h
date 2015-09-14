//
//  SceneBase.h
//  021.FirstSample
//
//  Created by 何 利強 on 2015/09/14.
//
//

#ifndef ___21_FirstSample__SceneBase__
#define ___21_FirstSample__SceneBase__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "cocostudio/WidgetCallBackHandlerProtocol.h"
#include "cocostudio/CocosStudioExport.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

namespace UScene
{
    
    class SceneBase
    : public cocos2d::Node
    , public cocostudio::WidgetCallBackHandlerProtocol
    {
    public:
        CREATE_FUNC(SceneBase)
        SceneBase();
        ~SceneBase();
        
        // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
        virtual void onEnter() override;
        
        virtual cocos2d::ui::Widget::ccWidgetTouchCallback onLocateTouchCallback(const std::string &callBackName);
        virtual cocos2d::ui::Widget::ccWidgetClickCallback onLocateClickCallback(const std::string &callBackName);
        virtual cocos2d::ui::Widget::ccWidgetEventCallback onLocateEventCallback(const std::string &callBackName);
        virtual void onSceneTouch(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type, const std::string &callBackName);
        virtual void onSceneClick(cocos2d::Ref* sender, const std::string &callBackName);
        virtual void onSceneEvent(cocos2d::Ref* sender, int eventType, const std::string &callBackName);
                
    private:
        
        cocos2d::CCLayer* uiLayer_;
    };
}

#endif /* defined(___21_FirstSample__SceneBase__) */
