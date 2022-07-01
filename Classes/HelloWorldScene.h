#pragma once

#include "cocos2d.h"

class HelloWorld : public cocos2d::Layer // класс сцены
{
public:
    static cocos2d::Scene* createScene(); // метод создания сцены
    bool init() override; // метод инициализации
    CREATE_FUNC(HelloWorld); // макрос, который раскрывается и генерирует экземпляр класса подконтрольный GC (GarbageCollector движка cocos-2dx)
    void update(float dt); // инициализация update
    cocos2d::Sprite* carSprite;
  //  cocos2d::Touch* touch;

    bool onTouchBegan(cocos2d::Touch* _touch, cocos2d::Event* event) override; // клик
    virtual void onTouchEnded(cocos2d::Touch* _touch, cocos2d::Event* event) override; // окончание клика
    virtual void onTouchMoved(cocos2d::Touch* _touch, cocos2d::Event* event) override; // перемещение с зажатой кнопкой/пальцем
    virtual void onTouchCancelled(cocos2d::Touch* _touch, cocos2d::Event* event) override; // отпускаем кнопку/палец

};

