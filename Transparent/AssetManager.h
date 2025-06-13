#pragma once
#include "Singleton.h"
class AssetManager
	: public Singleton<AssetManager>
{
public:
	SDL_Texture* LoadTexture(const std::string& fileName);
	void Clear();

private:
	std::unordered_map<std::string, SDL_Texture*> _textures;
	SDL_Renderer* _renderer; // Assume this is initialized elsewhere
};

