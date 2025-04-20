#include <SDL.h>
#include <iostream>



int WinMain(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL���������s: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow(
        "SDL2�e�X�g",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        640, 480,
        SDL_WINDOW_SHOWN
    );

    if (window == nullptr) {
        std::cout << "�E�B���h�E�쐬���s: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Delay(3000);  // 3�b�ԕ\��
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}