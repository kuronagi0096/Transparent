#include "pch.h"
#include "TitleScene.h"

TitleScene::TitleScene() {
	//_actors.push_back(std::make_unique<~~~>());
}

void TitleScene::Update() {
	for (auto& actor : _actors) {
		actor->Update(0.0f);
	}
}

void TitleScene::Render() {
}