#include "game.h"
#include "Input.h"
#include "ResultScene.h"
#include "SceneController.h"
#include "TitleScene.h"
#include <cassert>
#include <cmath>
#include <cstring>
#include <DxLib.h>
#include <iostream>
#include <string>

namespace
{
	constexpr float kFadeInterval = 60;
}

ResultScene::ResultScene(SceneController& controller):
	SceneBase(controller),
	m_fadeFrame(kFadeInterval),
	m_blinkFrame(0),
	m_update(&ResultScene::FadeInUpdate),
	m_draw(&ResultScene::FadeDraw)
{
}

ResultScene::~ResultScene()
{
}

void ResultScene::Update()
{
	(this->*m_update)();
}

void ResultScene::Draw()
{
	(this->*m_draw)();
}

void ResultScene::NormalUpdate()
{
	auto& input = Input::GetInstance();
	++m_blinkFrame;

	if (input.IsPress("LB"))
	{
		m_update = &ResultScene::FadeOutUpdate;
		m_draw = &ResultScene::FadeDraw;
		m_fadeFrame = 0;
	}
}

void ResultScene::FadeInUpdate()
{
	if (m_fadeFrame-- <= 0)
	{
		m_update = &ResultScene::NormalUpdate;
		m_draw = &ResultScene::NormalDraw;
	}
}

void ResultScene::FadeOutUpdate()
{
	if (m_fadeFrame++ >= kFadeInterval)
	{
		m_controller.ChangeScene(std::make_shared<TitleScene>(m_controller));

		// ©•ª‚ª€‚ñ‚Å‚¢‚é‚Ì‚Å‚à‚µ—]Œv‚Èˆ—‚ª“ü‚Á‚Ä‚¢‚é‚Æ‚Ü‚¸‚¢‚Ì‚Åreturn;
		return;
	}
}

void ResultScene::NormalDraw()
{
	// “_–ÅŒø‰Ê‚Ì‚½‚ß‚ÌğŒ
	if ((m_blinkFrame / 30) % 2 == 0)
	{
		DrawString(0, 0, "Result Scene", 0xffffff);
	}
}

void ResultScene::FadeDraw()
{
	float rate = static_cast<float>(m_fadeFrame) / static_cast<float>(kFadeInterval);
	SetDrawBlendMode(DX_BLENDMODE_MULA, static_cast<int>(rate * 255));
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, 0x000000, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
