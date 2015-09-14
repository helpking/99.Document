#include "MainScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "TopScene.h"
#include "ObjectFactory.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* MainScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    CSLoader* instance = CSLoader::getInstance();
    //注意第一个参数必须是第一步填写的自定义类名加“Reader ”如上述的"MyClassReader"
    instance->registReaderObject("TopSceneReader",(ObjectFactory::Instance)UScene::TopSceneReader::getInstance);

    auto rootNode = CSLoader::createNode("TopScene.csb");
    addChild(rootNode);
    
//    //加载动画：
//    cocostudio::timeline::ActionTimeline *action = NULL;
//    action = CSLoader::createTimeline("Role.csb");
//    action->gotoFrameAndPlay(0, 25, true);
//    rootNode->runAction(action);
//    
//    action = CSLoader::createTimeline("WindMill.csb");
//    action->gotoFrameAndPlay(0, 35, true);
//    rootNode->runAction(action);
//    
//    action = CSLoader::createTimeline("DemoPlayer.csb");
//    action->gotoFrameAndPlay(0, 316, true);
//    rootNode->runAction(action);

    return true;
}