#include "HelloWorldScene.h"
#include "GameOverScene.h"
#include <cmath>  

USING_NS_CC; // макрос использования пространства имён cocos2d::

Scene* HelloWorld::createScene()
{
    // все указатели, которые порождает Cocos - 2dx уже находятся под контролем выделенной памяти. Поэтому они не требуют явного удаления через delete или обертки в интеллектуальный указатель
    auto scene = Scene::create(); // создаем сцену
    auto layer = HelloWorld::create(); // создаем слой сцены

    scene->addChild(layer); // добавляем слой как ребенка на сцену
 
    return scene;
}


bool HelloWorld::init()
{

    if (!Layer::init()) // если мы не можем проинициализировать - просто выходим
    {
        return false;
    }

    this->scheduleUpdate(); // Работа Update
        
    spawnSprite(backGround, 0, 7.25);
    spawnSprite(carSprite, 1, 1,65,25);
    spawnSprite(ball, 1, 5,575,455);

    this->moveRandom(ball); // Функция рандомного движения полицейской машины

    auto touchListener = EventListenerTouchOneByOne::create();
      // Это лямбда - выражения. Если не знакомы - обязательно ознакомьтесь, очень сильный механизм.
    touchListener->onTouchBegan = [this](Touch* _touch, Event* event) -> bool {
        return onTouchBegan(_touch, event);
    };
    touchListener->onTouchEnded = [this](Touch* _touch, Event* event) {
        onTouchEnded(_touch, event);
    };
    touchListener->onTouchMoved = [this](Touch* _touch, Event* event) {
        onTouchMoved(_touch, event);
       
    };
    touchListener->onTouchCancelled = [this](Touch* _touch, Event* event) {
        onTouchCancelled(_touch, event);
    };
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

    return true;
}


bool HelloWorld::onTouchBegan(Touch* touch, Event* event)
{
    Point p =  touch->getLocation(); // место нажатия
    event->getCurrentTarget(); // на какой контрол мы кликнули, его адрес.
    event->getCurrentTarget()->getBoundingBox(); // ограничивающий бокс вокруг контрола
    
    return true;
}

void HelloWorld::onTouchEnded(Touch* touch, Event* event)
{
    cocos2d::log("touch ended"); // полезный метод: логирует вывод в консоль
}

void HelloWorld::onTouchMoved(Touch* touch, Event* event)
{
    Point p = touch->getLocation(); // место нажатия
    carSprite->setRotation(atan2((p.y - carSprite->getPositionY()), (p.x - carSprite->getPositionX())) * -180 / 3.1415926); // Поворот спрайта вслед за курсором
    carSprite->setPosition(Vec2(touch->getLocation().x, touch->getLocation().y));
}

void HelloWorld::onTouchCancelled(Touch* touch, Event* event)
{
    cocos2d::log("touch cancelled");// полезный метод: логирует вывод в консоль
}


void HelloWorld::moveRandom(Sprite* s)
{
    auto randomPoint = Vec2(rand() % 480, rand() % 320);

    auto moveTo = MoveTo::create(rand() % 5 + 1, randomPoint);
    auto delayTime = DelayTime::create(0.5);
    auto moveAgainFunc = CallFunc::create([=]()
        {
            moveRandom(s);
        });

    auto actions = Sequence::create(moveTo, delayTime, moveAgainFunc, nullptr);

    s->runAction(actions);
}

void HelloWorld::update(float dt)
{
    Rect rect1 = carSprite->getBoundingBox();
    Rect rect2 = ball->getBoundingBox();

    if (rect1.intersectsRect(rect2))
    {
        auto scene = GameOverScene::createScene();
        Director::getInstance()->pushScene(scene);
    }

}

void HelloWorld::spawnSprite(Sprite* s, int layer, double scale)
{
    auto visibleSize = Director::getInstance()->getVisibleSize(); // получаем размеры вида просмотра (то, где будем рисовать)
    Vec2 origin = Director::getInstance()->getVisibleOrigin(); // получаем вектор смещения, для рисования на разных координатах

    s->setPosition(cocos2d::Vec2(visibleSize.width / 2, visibleSize.height / 2));
    this->addChild(s, layer);
    s->setScale(scale);
}

void HelloWorld::spawnSprite(Sprite* s, int layer, double scale, int x,int y)
{
    s->setPosition(cocos2d::Vec2(x, y));
    this->addChild(s, layer);
    s->setScale(scale);
}