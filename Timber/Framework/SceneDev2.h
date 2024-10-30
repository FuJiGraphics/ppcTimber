#pragma once
#include "Scene.h"

class Tree;
class Player;
class TextGo;
class UiScore;
class UiTimebar;
class Viewport;
class SpriteGo;
class SceneDev2 : public Scene
{
protected:
    Tree* tree1;
    Tree* tree2;

    Player* player1; // ù ��° �÷��̾�
    Player* player2; // �� ��° �÷��̾�

    TextGo* centerMsg1;
    TextGo* centerMsg2;

    UiScore* uiScore1; // ù ��° �÷��̾� ���� UI
    UiScore* uiScore2; // �� ��° �÷��̾� ���� UI

    UiTimebar* uiTimer1;
    UiTimebar* uiTimer2;

    Viewport* viewport1; // ���� ����Ʈ
    Viewport* viewport2; // ������ ����Ʈ

    SpriteGo* background1;
    SpriteGo* background2;
public:
    SceneDev2();
    ~SceneDev2() = default;

    void Init() override;
    void Enter() override;
    void Exit() override;

    void Update(float dt) override;
    void Draw(sf::RenderWindow& window) override;
    //void SetCenterMessage(const std::string& msg);
    //void SetVisibleCenterMessage(bool visible);

    //void SetScore(int score);

    //void SetStatus(Status newStatus);
    //void UpdateAwake(float dt);
    //void UpdateGame(float dt);
    //void UpdateGameOver(float dt);
    //void UpdatePause(float dt);

    //void OnChop(Sides side);
};
