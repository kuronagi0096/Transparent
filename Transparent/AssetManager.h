#pragma once
#include "pch.h"
#include "SDL_image.h"
#include "Singleton.h"

class AssetManager : public Singleton<AssetManager>
{
	friend class Singleton<AssetManager>;
public:
	void Initialize(SDL_Renderer* renderer);
	SDL_Texture* LoadTexture(const std::string& filePath);
	void Clear();
	~AssetManager();
	SDL_Renderer* GetRenderer() const { return _renderer; }

private:
	SDL_Renderer* _renderer = nullptr;
	std::unordered_map<std::string, SDL_Texture*> _textures;
};

