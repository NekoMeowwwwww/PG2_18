#include "Novice.h"
#include "Enemy.h"

Enemy::Enemy(Transform transform, int r, int s, int a) {
	transform_ = transform;
	r_ = r;
	speed_ = s;
	Alive = a;
}

Enemy::~Enemy(){
}

void Enemy::Update(char* keys, char* preKeys){
	transform_.x += speed_;
	if (Alive == 0) {
		if (transform_.x < r_) {
			speed_ = 10;
		}
		if (transform_.x > 1280 - r_) {
			speed_ -= 10;
		}
	}
	if (keys[DIK_R] && preKeys[DIK_R]) {
		Alive = false;
	}
}

void Enemy::Draw(){
	if (Alive == false) {
		Novice::DrawEllipse(transform_.x, transform_.y, r_, r_, 0.0f, RED, kFillModeSolid);
	}
}
