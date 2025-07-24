#include "Player.h"
#include <cassert>

namespace
{
	// HP‚Ì‰Šú’l
	constexpr int kHp = 100;
	// ˆÚ“®‘¬“x
	constexpr float kSpeed = 7.5f;
}

Player::Player() :
	m_model(-1),
	m_hp(kHp)
{
}

Player::~Player()
{
	MV1DeleteModel(m_model);
}

void Player::Update()
{
	MV1SetPosition(m_model, VGet(0.0f, 0.0f, 0.0f));
}

void Player::Draw()
{
	MV1DrawModel(m_model);
}

void Player::OnDamage()
{
	m_hp--;
}

