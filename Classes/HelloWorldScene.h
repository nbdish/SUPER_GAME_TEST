#pragma once

#include "cocos2d.h"


class HelloWorld : public cocos2d::Layer // класс сцены
{
public:
    static cocos2d::Scene* createScene(); // метод создания сцены
    CREATE_FUNC(HelloWorld); // макрос, который раскрывается и генерирует экземпляр класса подконтрольный GC (GarbageCollector движка cocos-2dx)
    bool init() override; // метод инициализации

private:
    cocos2d::Sprite* carSprite = cocos2d::Sprite::create("car1.png");
    cocos2d::Sprite* ball = cocos2d::Sprite::create("ball_volley2.png");

private:
    void spawnSprite(cocos2d::Sprite* s, int layer, double scale, int x, int y);
    virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event) override; // окончание клика
    virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event) override; // перемещение с зажатой кнопкой/пальцем
    virtual void onTouchCancelled(cocos2d::Touch* touch, cocos2d::Event* event) override; // отпускаем кнопку/пале  
    void update(float dt); // инициализация update
    void moveRandom(cocos2d::Sprite* s); // инициализация moveRandom
    bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event) override; // клик
};

