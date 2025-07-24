#pragma once
#include "SceneBase.h"
#include "Vector3.h"

class TitleScene final: public SceneBase
{
public:
	TitleScene(SceneController& controller);
	~TitleScene();

	virtual void Update() override;
	virtual void Draw() override;

private:
	int m_fadeFrame;
	int m_blinkFrame;

	using UpdateFunc_t = void(TitleScene::*)();
	using DrawFunc_t = void(TitleScene::*)();

	UpdateFunc_t m_update;
	DrawFunc_t m_draw;

	// �ʏ펞�X�V����
	void NormalUpdate();
	// �t�F�[�h�C��
	void FadeInUpdate();
	// �t�F�[�h�A�E�g
	void FadeOutUpdate();

	// �ʏ펞�`��
	void NormalDraw();
	// �t�F�[�h���̕`��
	void FadeDraw();
};

