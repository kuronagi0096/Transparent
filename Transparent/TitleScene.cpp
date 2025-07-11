#include "pch.h"
#include "TitleScene.h"
#include "RendererComponent.h"
#include "TransformComponent.h"

TitleScene::TitleScene() {
	//_actors.push_back(std::make_unique<~~~>());
	_logoActor = new Actor(this, Actor::Active); // Assuming nullptr is a valid game pointer

	std::string logoPath = "../../Assets/Transparent_logo.png";
	RendererComponent* rendererComponent = new RendererComponent(_logoActor, logoPath);
	TransformComponent* transform = new TransformComponent(_logoActor);
	transform->_position = Vector3(960, 540, 0);
	transform->SetEnabled(true);
	_logoActor->AddComponent(transform); // Centered position
	_logoActor->AddComponent(rendererComponent);
	rendererComponent->SetEnabled(true);
	AddActor(_logoActor);
}

void TitleScene::Update() {
	for (auto& actor : _actors) {
		actor->Update(1.0f);
	}
	printf("TitleScene::Update() called.\n");
}

void TitleScene::Render() {
	for (auto& actor : _actors) {
		if (auto renderer = actor->GetComponent<RendererComponent>()) {
			
			renderer->Draw();
		}
	}
	printf("TitleScene::Render() called.\n");
}