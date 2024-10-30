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
public:
    enum class Status2
    {
        Awake,
        Game,
        GameOver,
        Pause,
    };
protected:
    Status2 currentStatus = Status2::Awake;
   /* Tree* tree1;
    Tree* tree2;*/

    //Player* player1; // 첫 번째 플레이어
    //Player* player2; // 두 번째 플레이어

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
    int score1 = 0;
    int score2 = 0;

    float timer1 = 0.f;
    float timer2 = 0.f;

    float gameTime1 = 5.f;
    float gameTime2 = 5.f;


    sf::Sound sfxDeath;
    sf::Sound sfxTimeOut;

    std::string sbIdDeath = "sound/death.wav";
    std::string sbIdTimeOut = "sound/out_of_time.wav";
public:
    Tree* tree1;
    Tree* tree2;

    Player* player1; // 첫 번째 플레이어
    Player* player2;
    SceneDev2();
    ~SceneDev2() = default;

    void Init() override;
    void Enter() override;
    void Exit() override;

    void Update(float dt) override;
    void Draw(sf::RenderWindow& window) override;
    void SetCenterMessage(const std::string& msg);
    void SetVisibleCenterMessage(bool visible);

    void SetScore(int score1, int score2);

    void SetStatus2(Status2 newStatus);
    void UpdateAwake(float dt);
    void UpdateGame(float dt);
    void UpdateGameOver(float dt);
    void UpdatePause(float dt);
    void ResetGame();
    void OnChop(Sides side, Player* player, Tree* tree);
};
