//
//  TopScene.h
//  021.FirstSample
//
//  Created by 何 利強 on 2015/09/14.
//
//

#ifndef ___21_FirstSample__TopScene__
#define ___21_FirstSample__TopScene__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "cocostudio/WidgetCallBackHandlerProtocol.h"
#include "cocostudio/CocosStudioExport.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

#include "SceneBase.h"

namespace UScene
{
    
    class TopScene
    : public SceneBase
    {
    public:
        CREATE_FUNC(TopScene)
        TopScene();
                
        // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
        virtual void onEnter() override;
        
        virtual cocos2d::ui::Widget::ccWidgetTouchCallback onLocateTouchCallback(const std::string &callBackName) override;
        virtual void onWalkBtnTouch(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type, const std::string &callBackName);
        virtual void onAttackBtnTouch(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type, const std::string &callBackName);
        
    private:
        
        cocostudio::timeline::ActionTimeline* demoPlayer_;
        
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
