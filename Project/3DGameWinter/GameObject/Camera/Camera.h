#pragma once
#include "Vector3.h"
#include <DxLib.h>
#include <memory>

class Camera
{
public:
	Camera();
	~Camera();
	// 更新処理
	void Update();
	// カメラの初期化
	void SetCamera();

	// カメラの回転行列を取得
	float GetCamRotX() const { return m_cameraRotX; }
	float GetCamRotY() const { return m_cameraRotY; }

private:
	// カメラの位置
	Vector3 m_pos;
	// カメラの注視点
	Vector3 m_lookAtPos;
	// カメラの視野角
	float m_fov;
	// カメラの回転量
	float m_cameraRotX;
	float m_cameraRotY;
	// ロックオンフラグ
	bool m_isLockOn;
};

