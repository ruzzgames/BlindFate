#pragma once
class GameObject
{
public:
	GameObject();
	void Init();
	void LoadContent();
	void Update();
	void Render();
	void UnloadContent();
	void Shutdown();
	~GameObject();
protected:

};