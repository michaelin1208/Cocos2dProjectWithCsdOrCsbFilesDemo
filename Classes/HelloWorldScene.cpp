#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "editor-support/cocostudio/CocoStudio.h"

USING_NS_CC;

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
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.


//    //csb文件动画载入
//    auto rootNode = CSLoader::createNode("tmp.csb");
//    rootNode->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
//    addChild(rootNode);
//    auto action = CSLoader::createTimeline("tmp.csb");
//    rootNode->runAction(action);
//    action->gotoFrameAndPlay(0, true);
    //csd动画文件载入
    auto node = CSLoader::getInstance()->createNodeWithFlatBuffersForSimulator("Node.csd");
    node->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
    this->addChild(node);
    cocostudio::timeline::ActionTimeline* action = cocostudio::timeline::ActionTimelineCache::getInstance()->createActionWithFlatBuffersForSimulator("Node.csd");
    if (action)
    {
        node->runAction(action);
        action->gotoFrameAndPlay(0);
    }
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
