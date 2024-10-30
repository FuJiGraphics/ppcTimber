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

    Player* player1; // 첫 번째 플레이어
    Player* player2; // 두 번째 플레이어

    TextGo* centerMsg1;
    TextGo* centerMsg2;

    UiScore* uiScore1; // 첫 번째 플레이어 점수 UI
    UiScore* uiScore2; // 두 번째 플레이어 점수 UI

    UiTimebar* uiTimer1;
    UiTimebar* uiTimer2;

    Viewport* viewport1; // 왼쪽 뷰포트
    Viewport* viewport2; // 오른쪽 뷰포트

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
