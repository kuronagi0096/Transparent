#include "AssetManager.h"


void AssetManager::Initialize(SDL_Renderer* renderer)
{
	_renderer = renderer;
}

SDL_Texture* AssetManager::LoadTexture(const std::string& filePath)
{
	auto it = _textures.find(filePath);
	if (it != _textures.end())
	{
		return it->second; // Return existing texture
	}
	SDL_Surface* surface = IMG_Load(filePath.c_str());
	if (!surface)
	{
		return nullptr; // Failed to load surface
	}
	SDL_Texture* texture = SDL_CreateTextureFromSurface(_renderer, surface);
	SDL_FreeSurface(surface);
	if (texture)
	{
		_textures[filePath] = texture; // Store the new texture
	}
	return texture; // Return the new texture
}

void AssetManager::Clear()
{
	for (auto& pair : _textures)
	{
		SDL_DestroyTexture(pair.second); // Destroy each texture
	}
	_textures.clear(); // Clear the map
}

AssetManager::~AssetManager()
{
	Clear(); // Ensure all textures are destroyed
}