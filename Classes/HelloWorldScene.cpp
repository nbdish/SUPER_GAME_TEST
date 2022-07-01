#include "HelloWorldScene.h"

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

   // auto label = Label::createWithSystemFont("Hello Cocos 2dx", "Arial", 48); // создаем метку для вывода текста. 
    auto touchListener = EventListenerTouchOneByOne::create();

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
    
   

  
    auto visibleSize = Director::getInstance()->getVisibleSize(); // получаем размеры вида просмотра (то, где будем рисовать)
    Vec2 origin = Director::getInstance()->getVisibleOrigin(); // получаем вектор смещения, для рисования на разных координатах
    
    carSprite = Sprite::create("car_right.png");
    carSprite->setPosition(cocos2d::Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));

    // label->setPosition(cocos2d::Vec2(400, 230)); // рисуем по заданным координатам. По - умолчанию у всех компонентов Cocos - 2dx точка отрисовки находится в середине, не слева сверху!
    this->addChild(carSprite, 0);
    
    


    this->scheduleUpdate(); // Работа Update
    // наконец добавляем метку как ребенка. второй параметр - это z - последовательность
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this); // вторым параметром указывается контрол, принимающий этот ввод
    return true;
}

void HelloWorld::update(float dt)
{
    



}

bool HelloWorld::onTouchBegan(Touch* touch,Event* event) 
{
    touch->getLocation(); // место нажатия
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
    cocos2d::log("touch moved");// полезный метод: логирует вывод в консоль
    
    auto position = touch->getLocation();
    //position = touch->getLocation();
    carSprite->setPosition(position); 
    
}

void HelloWorld::onTouchCancelled(Touch* touch, Event* event)
{
    cocos2d::log("touch cancelled");// полезный метод: логирует вывод в консоль
}
