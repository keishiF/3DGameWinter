#pragma once

class SceneController;

class SceneBase
{
public:
	SceneBase(SceneController& controller);

	// XVA•`‰æ
	virtual void Update() abstract;
	virtual void Draw() = 0;

protected:
	SceneController& m_controller;
};

