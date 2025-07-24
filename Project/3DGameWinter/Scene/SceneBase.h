#pragma once

class SceneController;

class SceneBase
{
public:
	SceneBase(SceneController& controller);

	// �X�V�A�`��
	virtual void Update() abstract;
	virtual void Draw() = 0;

protected:
	SceneController& m_controller;
};

