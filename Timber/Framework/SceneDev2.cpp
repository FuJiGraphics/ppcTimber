#include "stdafx.h"
#include "SceneDev2.h"
#include "SpriteGo.h"
#include "CloudGo.h"
#include "Tree.h"
#include "Player.h"
#include "TextGo.h"
#include "UiScore.h"
#include "UiTimebar.h"
#include "Viewport.h"

SceneDev2::SceneDev2() : Scene(SceneIds::Dev2)
{
    viewport1 = new Viewport(sf::FloatRect(0.f, 0.f, 0.5f, 1.f)); // 왼쪽 뷰포트
    viewport2 = new Viewport(sf::FloatRect(0.5f, 0.f, 0.5f, 1.f)); // 오른쪽 뷰포트
}

void SceneDev2::Init()
{
    std::cout << "SceneDev2::Init()" << std::endl;

    background1 = AddGo(new SpriteGo("graphics/background.png")); // 왼쪽 배경
    background1->sortingLayer = SortingLayers::Background;
    background1->sortingOrder = -1;
    background1->SetOrigin(Origins::MC);
    background1->SetPosition({ 1920 / 4, 1080 / 2 });

    background2 = AddGo(new SpriteGo("graphics/background.png")); // 오른쪽 배경
    background2->sortingLayer = SortingLayers::Background;
    background2->sortingOrder = -1;
    background2->SetOrigin(Origins::MC);
    background2->SetPosition({ 1920  / 4, 1080 / 2 });

    for (int i = 0; i < 3; ++i)
    {
        CloudGo* cloud = AddGo(new CloudGo("graphics/cloud.png"));
        cloud->sortingLayer = SortingLayers::Background;
        cloud->sortingOrder = 0;
    }

    TEXTURE_MGR.Load("graphics/tree.png");
    TEXTURE_MGR.Load("graphics/branch.png");
    TEXTURE_MGR.Load("graphics/player.png");
    TEXTURE_MGR.Load("graphics/rip.png");
    TEXTURE_MGR.Load("graphics/axe.png");

    tree1 = AddGo(new Tree("Tree1"));
    tree2 = AddGo(new Tree("Tree2")); // 두 번째 나무

    player1 = AddGo(new Player("Player1")); // 첫 번째 플레이어
    player2 = AddGo(new Player("Player2")); // 두 번째 플레이어

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
    tree1->SetScale({ 0.3f, 0.3f });
    tree2->SetPosition({ 1920.f / 4, 1080.f - 200.f });
    tree2->SetScale({ 0.3f, 0.3f });
    player1->SetPosition({ 1920.f / 4, 1080.f - 200.f }); // 왼쪽 플레이어 위치
    player2->SetPosition({ 1920.f / 4, 1080.f - 200.f }); // 오른쪽 플레이어 위치

    centerMsg1->text.setCharacterSize(100);
    centerMsg1->text.setFillColor(sf::Color::White);
    centerMsg1->SetPosition({ 1920 / 4, 1080 / 2 });

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

void SceneDev2::Enter()
{
    TEXTURE_MGR.Load("graphics/background.png");
    TEXTURE_MGR.Load("graphics/cloud.png");
    TEXTURE_MGR.Load("graphics/tree.png");
    TEXTURE_MGR.Load("graphics/branch.png");
    TEXTURE_MGR.Load("graphics/log.png");
    TEXTURE_MGR.Load("graphics/player.png");
    TEXTURE_MGR.Load("graphics/rip.png");
    TEXTURE_MGR.Load("graphics/axe.png");
    FONT_MGR.Load("fonts/KOMIKAP_.ttf");
    SOUNDBUFFER_MGR.Load("sound/chop.wav");




   /* player1->SetSceneGame(this);

    player2->SetSceneGame(this);*/
    Scene::Enter();

    //SetStatus(Status::Awake);
}

void SceneDev2::Exit()
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
    FONT_MGR.Unload("fonts/KOMIKAP_.ttf");
    SOUNDBUFFER_MGR.Unload("sound/chop.wav");

}

void SceneDev2::Draw(sf::RenderWindow& window)
{
    viewport1->Apply(window);

    background1->Draw(window);
    tree1->Draw(window);
    player1->Draw(window);
    uiScore1->Draw(window);
    uiTimer1->Draw(window);
    centerMsg1->Draw(window);
  

    // 두 번째 뷰포트 적용
    viewport2->Apply(window);

    background2->Draw(window);
    tree2->Draw(window);
    player2->Draw(window);
    uiScore2->Draw(window);
    uiTimer2->Draw(window);
    centerMsg2->Draw(window);

}

void SceneDev2::Update(float dt)
{
    Scene::Update(dt);


}

