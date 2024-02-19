#include "Novice.h"
#include "Player.h"
#include "Bullet.h"

Player::Player(Transform transform, int r1, int speed) {
	transform_ = transform;
	r_ = r1;
	speed_ = speed;
	bullet_ = new Bullet({ 0,0 }, 10, 10, false);
}
Player::~Player() {
	delete bullet_;
}

void Player::Update(char* keys, char* preKeys) {
	if (keys[DIK_W] && preKeys[DIK_W]) {
		transform_.y -= speed_;
	}
	if (keys[DIK_S] && preKeys[DIK_S]) {
		transform_.y += speed_;
	}
	if (keys[DIK_A] && preKeys[DIK_A]) {
		transform_.x -= speed_;
	}
	if (keys[DIK_D] && preKeys[DIK_D]) {
		transform_.x += speed_;
	}
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE] && bullet_->isShot_ == false) {
		bullet_->transform_ = transform_;
		bullet_->isShot_ = true;
	}
	bullet_->Update();
}

void Player::Draw() {
	Novice::DrawEllipse(transform_.x, transform_.y, r_, r_, 0.0f, WHITE, kFillModeSolid);
	bullet_->Draw();
}
