#pragma once

class Scene;

class SceneMgr : public Singleton<SceneMgr>
{
	friend class Singleton<SceneMgr>;

protected:
	std::vector<Scene*> scenes;

	SceneMgr() = default;
	virtual ~SceneMgr() = default;

	SceneMgr(const SceneMgr&) = delete;
	SceneMgr& operator=(const SceneMgr&) = delete;

	void OnPreDraw();
	void OnPostDraw();

public:
	void Init();
	void Release();

	void Update(float dt);
	void LateUpdate(float dt);

	void Draw(sf::RenderWindow& window);

protected:
	sf::RenderTexture sceneFrameBuffer1;
	sf::RenderTexture sceneFrameBuffer2;
	sf::View camera1;
	sf::View camera2;
	sf::Sprite renderer;
};


#define SCENE_MGR (SceneMgr::Instance())

