#include "pch.h"
#include "SDL_image.h"
#include "AssetManager.h"

SDL_Texture* AssetManager::LoadTexture(const std::string& fileName) {
	// Check if the texture is already loaded
	auto it = _textures.find(fileName);
	if (it != _textures.end()) {
		return it->second;
	}
	// Load the texture from file
	SDL_Surface* surface = IMG_Load(fileName.c_str());
	if (!surface) {
		SDL_Log("Failed to load texture: %s, %s", fileName.c_str(), IMG_GetError());
		return nullptr;
	}
	// Create a texture from the surface
	SDL_Texture* texture = SDL_CreateTextureFromSurface(_renderer, surface);
	SDL_FreeSurface(surface);
	if (!texture) {
		SDL_Log("Failed to create texture: %s, %s", fileName.c_str(), SDL_GetError());
		return nullptr;
	}
	// Store the texture in the map
	_textures[fileName] = texture;
	return texture;
}
void AssetManager::Clear() {
	for (auto& pair : _textures) {
		SDL_DestroyTexture(pair.second);
	}
	_textures.clear();
}