#include "TestModule.hpp"
#include <SDL2TK/Window.hpp>
#include <SDL2TK/Matrix4x4.hpp>
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    SDL2TK::Rotation<double> rotation
        = SDL2TK::Rotation<double>::FromDegrees(180.0);
    SDL2TK::Matrix4x4<double> m;

    rotation = rotation + rotation;

    cout << rotation.ToRadians() << endl;
    cout << sizeof(SDL2TK::Module) << endl;

    SDL_Init(SDL_INIT_VIDEO);
    {
        SDL2TK::Window window;
        TestModule tm;
        window.Run(tm);
    }
    SDL_Quit();
    return 0;
}
