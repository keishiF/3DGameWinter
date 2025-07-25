#pragma once
#include "SceneBase.h"
#include "Vector3.h"
#include <DxLib.h>
#include <memory>

class Player;
class Camera;
class GameScene final: public SceneBase
{
public:
	GameScene(SceneController& controller);
	~GameScene();

	virtual void Update() override;
	virtual void Draw() override;

private:
	int m_frame;
	int m_fadeFrame;
	int m_blinkFrame;

	using UpdateFunc_t = void(GameScene::*)();
	using DrawFunc_t = void(GameScene::*)();
	UpdateFunc_t m_update;
	DrawFunc_t m_draw;

	std::shared_ptr<Player> m_player;
	std::shared_ptr<Camera> m_camera;

	// 通常時更新処理
	void NormalUpdate();
	// フェードイン
	void FadeInUpdate();
	// フェードアウト
	void FadeOutUpdate();

	// 通常時描画
	void NormalDraw();
	// フェード時の描画
	void FadeDraw();

	// グリッドを描画
	void DrawField();
};

