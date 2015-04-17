#include "PlatformEnums.h"
#include "App.h"

#include "cocos2d.h"
#include "cocos-ext.h" //for test header
using namespace cocos2d;
#include "HelloWorldScene.h"

CCScene* HelloWorld::scene()
{
	// 'scene' is an autorelease object
	CCScene* scene = CCScene::create();
	
	// 'layer' is an autorelease object
	HelloWorld* layer = HelloWorld::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

HelloWorld* HelloWorld::create() 
{ 
	HelloWorld* pRet = new HelloWorld(); 
	
	if (pRet && pRet->init()) 
	{ 
		pRet->autorelease();
		return pRet;
	}

	return NULL;
} 

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	//////////////////////////////
	// 1. super init first
	if ( !CCLayer::init() )
	{
		return false;
	}

	/////////////////////////////
	// 3. add your codes below...
	std::string		e_str;
	std::wstring	w_str	= L"Hello";
	CCSize			size	= CCDirector::sharedDirector()->getWinSize();

	WideStrToUTF8(e_str, w_str);
	
	// create and initialize a label
	CCLabelTTF* pLabel = CCLabelTTF::create(e_str.c_str(), "Arial", 24);
	// ask director the window size
	
	// position the label on the center of the screen
	pLabel->setPosition( ccp(size.width / 2, size.height - 50) );

	// add the label as a child to this layer
	this->addChild(pLabel, 0);
		
	return true;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
	CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

void HelloWorld::onEnter()
{
	CCLayer::onEnter();

	CCActionInterval*	jump;
    CCFiniteTimeAction*	action;
	CCActionInterval*	rep;
	CCSize				wsize	= CCDirector::sharedDirector()->getWinSize();
	    // Or you can create an sprite using a filename. only PNG is supported now. Probably TIFF too
    m_grossini = CCSprite::create((GetBaseAppPath()+"game/grossini.png").c_str());
    m_grossini->retain();

	jump	= CCJumpBy::create(2, CCPointMake(wsize.width-80,0), 50, 4);
    action	= CCSequence::create( jump, jump->reverse(), NULL);
	rep		= CCRepeat::create(action, -1);
	
	m_grossini->setPosition(CCPointMake(40, wsize.height/2));
    m_grossini->runAction(rep);

	this->addChild(m_grossini, 1);
}

void HelloWorld::onExit()
{
    m_grossini->release();
	CCLayer::onExit();
}