#pragma once
#include "SceneBase.h"

class ResultScene final: public SceneBase
{
public:
    ResultScene(SceneController& controller);
    ~ResultScene();

    virtual void Update() override;
    virtual void Draw() override;

private:
	int m_fadeFrame;

	int m_blinkFrame;

	using UpdateFunc_t = void(ResultScene::*)();
	using DrawFunc_t = void(ResultScene::*)();

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

