#pragma once

#include "cocos2d.h"


class HelloWorld : public cocos2d::Layer // класс сцены
{
public:
    static cocos2d::Scene* createScene(); // метод создания сцены
    cocos2d::Sprite* carSprite = cocos2d::Sprite::create("car1.png");
    cocos2d::Sprite* policeCarSprite = cocos2d::Sprite::create("car_police1.png");
    cocos2d::Sprite* backGround = cocos2d::Sprite::create("Grass/land_grass11.png");

    CREATE_FUNC(HelloWorld); // макрос, который раскрывается и генерирует экземпляр класса подконтрольный GC (GarbageCollector движка cocos-2dx)
    bool init() override; // метод инициализации
    void update(float dt); // инициализация update
    void moveRandom(cocos2d::Sprite* s); // инициализация moveRandom
    bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event) override; // клик
    virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event) override; // окончание клика
    virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event) override; // перемещение с зажатой кнопкой/пальцем
    virtual void onTouchCancelled(cocos2d::Touch* touch, cocos2d::Event* event) override; // отпускаем кнопку/пале    
};

