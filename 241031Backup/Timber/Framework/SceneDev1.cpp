#include "stdafx.h"
#include "SceneDev1.h"
#include "SpriteGo.h"
#include "CloudGo.h"
#include "Tree.h"
#include "Player.h"
#include "TextGo.h"
#include "UiScore.h"
#include "UiTimebar.h"
#include "Viewport.h"



SceneDev1::SceneDev1() : Scene(SceneIds::Dev1)
{
    viewport1 = new Viewport(sf::FloatRect(0.f, 0.f, 0.5f, 1.f)); // 왼쪽 뷰포트
    viewport2 = new Viewport(sf::FloatRect(0.5f, 0.f, 0.5f, 1.f)); // 오른쪽 뷰포트
}

void SceneDev1::Init()
{
    std::cout << "SceneDev1::Init()" << std::endl;

    background1 = AddGo(new SpriteGo("graphics/background.png")); // 왼쪽 배경
    background1->sortingLayer = SortingLayers::Background;
    background1->sortingOrder = -1;
    background1->SetOrigin(Origins::MC);
    background1->SetPosition({ 1920 / 4, 1080 / 2 });

    background2 = AddGo(new SpriteGo("graphics/background.png")); // 오른쪽 배경
    background2->sortingLayer = SortingLayers::Background;
    background2->sortingOrder = -1;
    background2->SetOrigin(Origins::MC);
    background2->SetPosition({ 1920 / 4, 1080 / 2 });

    for (int i = 0; i < 3; ++i)
    {
        CloudGo* cloud = AddGo(new CloudGo("graphics/cloud.png"));
        cloud->sortingLayer = SortingLayers::Background;
        cloud->sortingOrder = 0;

        float xPos = static_cast<float>(rand() % 1920/4); // 화면 너비 내의 랜덤 x 좌표
        float yPos = static_cast<float>(rand() % (1080 / 3)); // 화면 높이 내의 랜덤 y 좌표 (상단 반만)
        cloud->SetPosition({ xPos, yPos });
    }

    TEXTURE_MGR.Load("graphics/tree.png");
    TEXTURE_MGR.Load("graphics/branch.png");
    TEXTURE_MGR.Load("graphics/player.png");
    TEXTURE_MGR.Load("graphics/rip.png");
    TEXTURE_MGR.Load("graphics/axe.png");
    TEXTURE_MGR.Load("graphics/log.png");

    tree1 = AddGo(new Tree("Tree1"));
    tree1->sortingLayer = SortingLayers::Background;
    tree1->sortingOrder = 1;

    tree2 = AddGo(new Tree("Tree2")); // 두 번째 나무
    tree2->sortingLayer = SortingLayers::Background;
    tree2->sortingOrder = 1;

    player1 = AddGo(new Player("Player1")); // 첫 번째 플레이어
    player2 = AddGo(new Player("Player2")); // 두 번째 플레이어
    player1->SetKeySetting(sf::Keyboard::A, sf::Keyboard::D);
    player2->SetKeySetting(sf::Keyboard::Left, sf::Keyboard::Right);


    centerMsg1 = AddGo(new TextGo("fonts/KOMIKAP_.ttf", "Center Message1"));
    centerMsg1->sortingLayer = SortingLayers::UI;

    centerMsg2 = AddGo(new TextGo("fonts/KOMIKAP_.ttf", "Center Message2"));
    centerMsg2->sortingLayer = SortingLayers::UI;

    uiScore1 = AddGo(new UiScore("fonts/KOMIKAP_.ttf", "Ui Score 1"));
    uiScore2 = AddGo(new UiScore("fonts/KOMIKAP_.ttf", "Ui Score 2"));

    uiTimer1 = AddGo(new UiTimebar("Ui Timer1"));
    uiTimer2 = AddGo(new UiTimebar("Ui Timer2"));

    Scene::Init();

    tree1->SetPosition({ 1920.f / 4, 1080.f - 200.f });
    tree1->SetScale({ 0.5f, 0.3f });
    tree2->SetPosition({ 1920.f / 4, 1080.f - 200.f });
    tree2->SetScale({ 0.5f, 0.3f });
    player1->SetPosition({ 1920.f / 4, 1080.f - 200.f }); // 왼쪽 플레이어 위치
    player2->SetPosition({ 1920.f / 4, 1080.f - 200.f }); // 오른쪽 플레이어 위치

    centerMsg1->text.setCharacterSize(50);
    centerMsg1->text.setFillColor(sf::Color::White);
    centerMsg1->SetPosition({ 1920 / 4, 1080 / 2 });

    centerMsg2->text.setCharacterSize(50);
    centerMsg2->text.setFillColor(sf::Color::White);
    centerMsg2->SetPosition({ 1920 / 4, 1080 / 2 });

    uiScore1->text.setCharacterSize(75);
    uiScore1->text.setFillColor(sf::Color::White);
    uiScore1->SetPosition({ 30.f, 30.f });

    uiScore2->text.setCharacterSize(75);
    uiScore2->text.setFillColor(sf::Color::White);
    uiScore2->SetPosition({ 30.f, 30.f });

    uiTimer1->Set({ 500.f, 100.f }, sf::Color::Red);
    uiTimer1->SetOrigin(Origins::ML);
    uiTimer1->SetPosition({ 1920.f / 2.f - 630.f, 1080.f - 200.f });
    uiTimer1->SetScale({ 0.6f, 0.5f });

    uiTimer2->Set({ 500.f, 100.f }, sf::Color::Red);
    uiTimer2->SetOrigin(Origins::ML);
    uiTimer2->SetPosition({ 1920.f / 2.f - 630.f, 1080.f - 200.f });
    uiTimer2->SetScale({ 0.6f, 0.5f });
}

void SceneDev1::Enter()
{
    TEXTURE_MGR.Load("graphics/background.png");
    TEXTURE_MGR.Load("graphics/cloud.png");
    TEXTURE_MGR.Load("graphics/tree.png");
    TEXTURE_MGR.Load("graphics/branch.png");
    TEXTURE_MGR.Load("graphics/log.png");
    TEXTURE_MGR.Load("graphics/player.png");
    TEXTURE_MGR.Load("graphics/rip.png");
    TEXTURE_MGR.Unload("graphics/log.png");
    FONT_MGR.Load("fonts/KOMIKAP_.ttf");
    SOUNDBUFFER_MGR.Load("sound/chop.wav");
    SOUNDBUFFER_MGR.Load(sbIdDeath);
    SOUNDBUFFER_MGR.Load(sbIdTimeOut);

    sfxDeath.setBuffer(SOUNDBUFFER_MGR.Get(sbIdDeath));
    sfxTimeOut.setBuffer(SOUNDBUFFER_MGR.Get(sbIdTimeOut));

    player1->SetSceneGame(this);

    player2->SetSceneGame(this);
    Scene::Enter();

    SetStatus(Status::Awake);
}

void SceneDev1::Exit()
{
    std::cout << "SceneDev1::Exit()" << std::endl;

    player1->SetSceneGame(nullptr);
    player2->SetSceneGame(nullptr);
    tree1->ClearEffectLog();
    tree2->ClearEffectLog();



    Scene::Exit();

    TEXTURE_MGR.Unload("graphics/cloud.png");
    TEXTURE_MGR.Unload("graphics/background.png");
    TEXTURE_MGR.Unload("graphics/tree.png");
    TEXTURE_MGR.Unload("graphics/branch.png");
    TEXTURE_MGR.Unload("graphics/log.png");
    TEXTURE_MGR.Unload("graphics/player.png");
    TEXTURE_MGR.Unload("graphics/rip.png");
    TEXTURE_MGR.Unload("graphics/axe.png");
    TEXTURE_MGR.Unload("graphics/log.png");
    FONT_MGR.Unload("fonts/KOMIKAP_.ttf");
    SOUNDBUFFER_MGR.Unload("sound/chop.wav");
    SOUNDBUFFER_MGR.Unload("sound/death.wav");
    SOUNDBUFFER_MGR.Unload("sound/out_of_time.wav");


}
void SceneDev1::Update(float dt)
{
    Scene::Update(dt);

    if (SCENE_MGR.GetCurrentScene() != this) return;

    if (currentStatus == Status::GameOver)
    {
        if (InputMgr::GetKeyDown(sf::Keyboard::Space))
        {
            player1->Reset();
            player2->Reset();
            tree1->Reset();
            tree2->Reset();
            SetStatus(Status::Awake);
        }
        return;
    }

    if (InputMgr::GetKeyDown(sf::Keyboard::Num2))
    {
        SCENE_MGR.ChangeScene(SceneIds::Dev2);
    }

    switch (currentStatus)
    {
    case SceneDev1::Status::Awake:
        UpdateAwake(dt);
        break;
    case SceneDev1::Status::Game:
        UpdateGame(dt);
        break;
    case SceneDev1::Status::GameOver:
        UpdateGameOver(dt);
        break;
    case SceneDev1::Status::Pause:
        UpdatePause(dt);
        break;
    }
}
void SceneDev1::Draw(sf::RenderWindow& window)
{
    viewport1->Apply(window);

    background1->Draw(window);
    for (auto& go : gameObjects)
    {
        CloudGo* cloud = dynamic_cast<CloudGo*>(go);
        if (cloud)
        {
            cloud->Draw(window); // 각 구름의 Draw 메서드 호출
        }
    }
    tree1->Draw(window);
    player1->Draw(window);
    uiScore1->Draw(window);
    uiTimer1->Draw(window);
    centerMsg1->Draw(window);

  
    // 두 번째 뷰포트 적용
    viewport2->Apply(window);

    background2->Draw(window);
    for (auto& go : gameObjects)
    {
        CloudGo* cloud = dynamic_cast<CloudGo*>(go);
        if (cloud)
        {
            cloud->Draw(window); // 각 구름의 Draw 메서드 호출
        }
    }
    tree2->Draw(window);
    player2->Draw(window);
    uiScore2->Draw(window);
    uiTimer2->Draw(window);
    centerMsg2->Draw(window);

}

void SceneDev1::SetCenterMessage(const std::string& msg)
{
    centerMsg1->text.setString(msg);
    centerMsg1->SetOrigin(Origins::MC);
    centerMsg2->text.setString(msg);
    centerMsg2->SetOrigin(Origins::MC);
}

void SceneDev1::SetVisibleCenterMessage(bool visible)
{
    centerMsg1->SetActive(visible);
    centerMsg2->SetActive(visible);

}

void SceneDev1::SetScore(int score1, int score2)
{

    this->score1 = score1;
    this->score2 = score2;

    uiScore1->SetScore(this->score1);
    uiScore2->SetScore(this->score2);
}

void SceneDev1::SetStatus(Status newStatus)
{
    Status prevStatus = currentStatus;
    currentStatus = newStatus;

    switch (currentStatus)
    {
    case SceneDev1::Status::Awake:
        FRAMEWORK.SetTimeScale(0.f);
        SetVisibleCenterMessage(true);
        SetCenterMessage("Press Enter To Start");
        score1 = 0;
        timer1 = gameTime1;
        uiTimer1->SetValue(1.f);
    
        score2 = 0;
        SetScore(score1, score2);
        timer2 = gameTime1;
        uiTimer2->SetValue(1.f);
  
     
        break;
    case SceneDev1::Status::Game:
        if (prevStatus == Status::GameOver)
        {
            score1 = 0;
            timer1 = gameTime1;
            uiTimer1->SetValue(1.f);
            score2 = 0;
            timer2 = gameTime1;
            uiTimer2->SetValue(1.f);
            SetScore(score1, score2);
            player1->Reset();
            tree1->Reset();

            player2->Reset();
            tree2->Reset();
  

        }
        FRAMEWORK.SetTimeScale(1.f);
        SetVisibleCenterMessage(false);
        SetCenterMessage("");
        break;
    case SceneDev1::Status::GameOver:
        FRAMEWORK.SetTimeScale(0.f);
        SetVisibleCenterMessage(true);
        break;
    case SceneDev1::Status::Pause:
        FRAMEWORK.SetTimeScale(0.f);
        SetVisibleCenterMessage(true);
        SetCenterMessage("PAUSE! ESC TO RESUME!");
        break;
    }
}

void SceneDev1::UpdateAwake(float dt)
{
    if (InputMgr::GetKeyDown(sf::Keyboard::Enter))
    {
        SetStatus(Status::Game);
        /*   SetCenterMessage("Press Enter To Start");*/

    }
}

void SceneDev1::UpdateGame(float dt)
{
    if (InputMgr::GetKeyDown(sf::Keyboard::Escape))
    {
        SetStatus(Status::Pause);
        return;
    }

    timer1 = Utils::Clamp(timer1 - dt, 0.f, gameTime1);
    timer2 = Utils::Clamp(timer2 - dt, 0.f, gameTime2);

    uiTimer1->SetValue(timer1 / gameTime1);
    uiTimer2->SetValue(timer2 / gameTime2);

    if (timer1 <= 0.f)
    {
        sfxTimeOut.play();

        player1->OnDie();
        SetCenterMessage("Time Over! Player 2 win");
        SetStatus(Status::GameOver);
        return;
    }
    if (timer2 <= 0.f)
    {
        sfxTimeOut.play();

        player2->OnDie();
        SetCenterMessage("Time Over! Player 1 win");
        SetStatus(Status::GameOver);
        return;
    }
}

void SceneDev1::UpdateGameOver(float dt)
{
    if (InputMgr::GetKeyDown(sf::Keyboard::Space))
    {
        player1->Reset();
        player2->Reset();
        tree1->Reset();
        tree2->Reset();
        SetScore(0, 0);
        SetStatus(Status::Awake);
    }
}

void SceneDev1::UpdatePause(float dt)
{
    if (InputMgr::GetKeyDown(sf::Keyboard::Escape))
    {
        SetStatus(Status::Game);
    }
}
void SceneDev1::OnChop(Sides side, Player* player, Tree* tree)
{

    if (player == player1) 
    {
        Sides branchSide = tree1->Chop(side);
        if (branchSide == side) // 나무에 대한 처리
        {
            sfxDeath.play();
            player1->OnDie();
       
            SetCenterMessage("Player 2 Win!");
   
            SetStatus(Status::GameOver);
        }
        else
        {
    
            SetScore(score1 + 100, score2);
            timer1 += 1.f;
        }
    }
     if (player == player2)
    {
        // 플레이어 2의 나무 자르기 처리
        Sides branchSide = tree2->Chop(side);
        if (branchSide == side) // 나무에 대한 처리
        {
            sfxDeath.play();
            player2->OnDie();
      
            SetCenterMessage("Player 1 Win!");
            SetStatus(Status::GameOver);
        }
        else
        {
            
            SetScore(score1, score2 + 100);
            timer2 += 1.f;
        }
    }
}



