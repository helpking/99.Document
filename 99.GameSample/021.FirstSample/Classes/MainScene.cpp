#include "MainScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "TopScene.h"
#include "ObjectFactory.h"
#include "GameManager.h"

#include "Singleton.h"

// Csbファイルローダー
#include "UtilsFileLoader.h"

USING_NS_CC;
USING_NS_COMMON_UTILS;

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
    
    // トップシーンでロードする
    auto rootNode = Singleton<UtilsFileLoader>::getInstance()->loadSceneFile(ResInfoPool::E_RES_ID::E_SCENE_TOP);
    addChild(rootNode);
    
    return true;
}