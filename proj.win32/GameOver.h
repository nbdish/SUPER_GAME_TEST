#pragma once
#include "cocos2d.h"


class GameOver : public cocos2d::Layer // ����� �����
{
public:
    static cocos2d::Scene* createScene(); // ����� �������� �����
    bool init() override; // ����� �������������

    CREATE_FUNC(GameOver); // ������, ������� ������������ � ���������� ��������� ������ �������������� GC (GarbageCollector ������ cocos-2dx)
};


