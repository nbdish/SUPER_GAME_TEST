#include "HelloWorldScene.h"
#include "GameOverScene.h"

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

    auto touchListener = EventListenerTouchOneByOne::create();

    auto visibleSize = Director::getInstance()->getVisibleSize(); // получаем размеры вида просмотра (то, где будем рисовать)
    Vec2 origin = Director::getInstance()->getVisibleOrigin(); // получаем вектор смещения, для рисования на разных координатах
    
    carSprite = Sprite::create("car.png");
    carSprite->setPosition(cocos2d::Vec2(65, 25));
    carSprite->setScale(1.75); // Масштабирование спрайта
    this->addChild(carSprite, 0);
    
    policeCarSprite = Sprite::create("car_police.png");
    policeCarSprite->setPosition(cocos2d::Vec2(575, 455));
    policeCarSprite->setScale(1.75); // Масштабирование спрайта
    this->addChild(policeCarSprite);

    this->moveRandom(policeCarSprite); // Функция рандомного движения полицейской машины

    this->scheduleUpdate(); // Работа Update

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
    touch->getLocation(); // место нажатия
    event->getCurrentTarget(); // на какой контрол мы кликнули, его адрес.
    event->getCurrentTarget()->getBoundingBox(); // ограничивающий бокс вокруг контрола
    carSprite->setPosition(Vec2(touch->getLocation().x, touch->getLocation().y));
    return true;
}

void HelloWorld::onTouchEnded(Touch* touch, Event* event)
{
    cocos2d::log("touch ended"); // полезный метод: логирует вывод в консоль
}

void HelloWorld::onTouchMoved(Touch* touch, Event* event)
{
    cocos2d::log("touch moved");// полезный метод: логирует вывод в консоль
    carSprite->setPosition(Vec2(touch->getLocation().x, touch->getLocation().y));
    
    Rect rect1 = carSprite->getBoundingBox();
    Rect rect2 = policeCarSprite->getBoundingBox();

    if (rect1.intersectsRect(rect2))
    {
        auto scene = GameOverScene::createScene();
        Director::getInstance()->pushScene(scene);
    }
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

}