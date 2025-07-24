#pragma once
#include "Vector3.h"
#include <DxLib.h>
#include <memory>

class Player
{
public:
	// �R���X�g���N�^�ƃf�X�g���N�^
	Player();
	virtual ~Player();

	// ������
	void Init();
	// �X�V
	void Update();
	// �`��
	void Draw();

	// �_���[�W���󂯂����̏������܂Ƃ߂�֐�
	void OnDamage();

private:
	// �v���C���[�̃��f��
	int m_model;
	// �v���C���[��HP
	int m_hp;
};

