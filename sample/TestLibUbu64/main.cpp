#include "TestModule.hpp"
#include <SDL2TK/Window.hpp>

int main(int argc, char** argv)
{
    SDL_Init(SDL_INIT_VIDEO);
    {
        SDL2TK::Window window;
        TestModule tm;
        window.Run(tm);
    }
    SDL_Quit();
    return 0;
}
