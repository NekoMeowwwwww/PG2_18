#pragma once
#include "Struct.h"

class Bullet {
public:
	Transform transform_;
	int speed_;
	int r_;
	bool isShot_;

public:
	Bullet(Transform transform, int speed, int r, bool isShot);
	void Update();
	void Draw();
};