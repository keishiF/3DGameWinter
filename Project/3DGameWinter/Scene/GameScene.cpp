#include "Camera/Camera.h"
#include "game.h"
#include "GameScene.h"
#include "Input.h"
#include "Player/Player.h"
#include "ResultScene.h"
#include "SceneController.h"
#include "TitleScene.h"
#include <cassert>

namespace
{
	constexpr int kFadeInterval = 60;
	// �t�B�[���h�̈�ӂ̒���
	constexpr float kFieldSize = 500.0f;
}

GameScene::GameScene(SceneController& controller) :
	SceneBase(controller),
	m_frame(),
	m_fadeFrame(kFadeInterval),
	m_blinkFrame(0),
	m_update(&GameScene::FadeInUpdate),
	m_draw(&GameScene::FadeDraw)
{
	m_player = std::make_shared<Player>();
	m_camera = std::make_shared<Camera>();
	m_camera->SetCamera();
}

GameScene::~GameScene()
{
}

void GameScene::Update()
{
	(this->*m_update)();
}

void GameScene::Draw()
{
	(this->*m_draw)();
}

void GameScene::NormalUpdate()
{
	auto& input = Input::GetInstance();
	++m_blinkFrame;

	m_player->Update();
	m_camera->Update();

	if (input.IsPress("LB"))
	{
		m_update = &GameScene::FadeOutUpdate;
		m_draw = &GameScene::FadeDraw;
		m_fadeFrame = 0;
	}
}

void GameScene::FadeInUpdate()
{
	if (--m_fadeFrame <= 0)
	{
		m_update = &GameScene::NormalUpdate;
		m_draw = &GameScene::NormalDraw;
	}
}

void GameScene::FadeOutUpdate()
{
	if (++m_fadeFrame >= kFadeInterval)
	{
		m_controller.ChangeScene(std::make_shared<ResultScene>(m_controller));

		// ����������ł���̂ł����]�v�ȏ����������Ă���Ƃ܂����̂�return;
		return;
	}
}

void GameScene::NormalDraw()
{
	// �_�Ō��ʂ̂��߂̏���
	if ((m_blinkFrame / 30) % 2 == 0)
	{
		DrawString(0, 0, "Game Scene", 0xffffff);
	}
	printf("frame %d\r", m_frame);

	DrawField();
	m_player->Draw();
}

void GameScene::FadeDraw()
{
	float rate = static_cast<float>(m_fadeFrame) / static_cast<float>(kFadeInterval);
	SetDrawBlendMode(DX_BLENDMODE_MULA, static_cast<int>(rate * 255));
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, 0x000000, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void GameScene::DrawField()
{
	// �O���b�h
	Vector3 start;
	Vector3 end;
	start = { -kFieldSize, 0.0f,0.0f };
	end = { kFieldSize, 0.0f,0.0f };
	for (int z = -kFieldSize; z <= kFieldSize; z += 50)
	{
		start.z = z;
		end.z = z;

		DrawLine3D(VGet(start.x, start.y, start.z), VGet(end.x, end.y, end.z), 0xff0000);
	}
	start = { 0.0f, 0.0f, -kFieldSize };
	end = { 0.0f, 0.0f, kFieldSize };
	for (int x = -kFieldSize; x <= kFieldSize; x += 50)
	{
		start.x = x;
		end.x = x;

		DrawLine3D(VGet(start.x, start.y, start.z), VGet(end.x, end.y, end.z), 0x0000ff);
	}
}
