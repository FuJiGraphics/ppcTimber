#pragma once
#include "Scene.h"
#include "player.h"
#include "EffectLog.h"
class Tree;
class TextGo;
class UiScore;
class Player;
class UiTimebar;
class Viewport;
class SpriteGo;


class SceneDev1 : public Scene
{

public:
    enum class Status
    {
        Awake,
        Game,
        GameOver,
        Pause,

    };
protected:
    
    Status currentStatus = Status::Awake;

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
    
    Tree* GetTree1() const { return tree1; }
    Tree* GetTree2() const { return tree2; }
    SceneDev1();
    ~SceneDev1() = default;

    void Init() override;
    void Enter() override;
    void Exit() override;

    void Update(float dt) override;
    void Draw(sf::RenderWindow& window) override;
    void SetCenterMessage(const std::string& msg);
    void SetVisibleCenterMessage(bool visible);

    void SetScore(int score1, int score2);

    void SetStatus(Status newStatus);
    void UpdateAwake(float dt);
    void UpdateGame(float dt);
    void UpdateGameOver(float dt);
    void UpdatePause(float dt);
    //void ResetGame();
    void OnChop(Sides side, Player* player, Tree* tree);

};