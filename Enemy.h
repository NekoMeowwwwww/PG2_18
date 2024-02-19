#pragma once
#include <Struct.h>

class Enemy {
protected:
public:
	static int Alive;

	Transform transform_;
	int r_;
	int speed_;

	Enemy(Transform transform, int r, int s, int a);
	~Enemy();
	void Update(char* keys, char* preKeys);
	void Draw();
};
