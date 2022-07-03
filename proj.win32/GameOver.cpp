#include "GameOver.h"

USING_NS_CC; // ������ ������������� ������������ ��� cocos2d::

Scene* GameOver::createScene()
{
    // ��� ���������, ������� ��������� Cocos - 2dx ��� ��������� ��� ��������� ���������� ������. ������� ��� �� ������� ������ �������� ����� delete ��� ������� � ���������������� ���������
    auto scene = Scene::create(); // ������� �����
    auto layer = GameOver::create(); // ������� ���� �����

    scene->addChild(layer); // ��������� ���� ��� ������� �� �����

    return scene;
}

bool GameOver::init()
{
    if (!Layer::init()) // ���� �� �� ����� ������������������� - ������ �������
    {
        return false;
    }

    auto label = Label::createWithSystemFont("GameOver", "Arial", 48); // ������� ����� ��� ������ ������. 
    auto visibleSize = Director::getInstance()->getVisibleSize(); // �������� ������� ���� ��������� (��, ��� ����� ��������)
    Vec2 origin = Director::getInstance()->getVisibleOrigin(); // �������� ������ ��������, ��� ��������� �� ������ �����������


    label->setPosition(cocos2d::Vec2(320, 240)); // ������ �� �������� �����������. �� - ��������� � ���� ����������� Cocos - 2dx ����� ��������� ��������� � ��������, �� ����� ������!
    this->addChild(label, 1);
    // ������� ��������� ����� ��� �������. ������ �������� - ��� z - ������������������
    return true;
}

