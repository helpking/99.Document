#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "MainScene.h"
#include "ObjectFactory.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    CSLoader* instance = CSLoader::getInstance();
    //注意第一个参数必须是第一步填写的自定义类名加“Reader ”如上述的"MyClassReader"
    instance->registReaderObject("MainSceneReader",(ObjectFactory::Instance)UScene::MainSceneReader::getInstance);

    auto rootNode = CSLoader::createNode("MainScene.csb");
    addChild(rootNode);
    
    //加载动画：
    ActionTimeline *action = NULL;
    action = CSLoader::createTimeline("Role.csb");
    rootNode->runAction(action);
    action->gotoFrameAndPlay(0, 25, true);
    
    action = CSLoader::createTimeline("WindMill.csb");
    rootNode->runAction(action);
    action->gotoFrameAndPlay(0, 35, true);
    
    action = CSLoader::createTimeline("DemoPlayer.csb");
    rootNode->runAction(action);
    action->gotoFrameAndPlay(0, 316, true);

    return true;
}