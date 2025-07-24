#pragma once
#include "Vector3.h"
#include <DxLib.h>
#include <memory>

class Player
{
public:
	// コンストラクタとデストラクタ
	Player();
	virtual ~Player();

	// 初期化
	void Init();
	// 更新
	void Update();
	// 描画
	void Draw();

	// ダメージを受けた時の処理をまとめる関数
	void OnDamage();

private:
	// プレイヤーのモデル
	int m_model;
	// プレイヤーのHP
	int m_hp;
};

