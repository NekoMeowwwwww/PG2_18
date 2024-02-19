#pragma once
#include "Bullet.h"

class Player {
public:
	Bullet* bullet_;
	Transform transform_;
	int r_;
	int speed_;

public:
	Player(Transform transform, int r, int speed);
	~Player();
	void Update(char* keys, char* preKeys);
	void Draw();
};