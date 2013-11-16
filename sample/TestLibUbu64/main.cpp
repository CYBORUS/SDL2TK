#include "TestModule.hpp"
#include <SDL2TK/Tools.hpp>
#include <SDL2TK/Matrix4x4.hpp>
#include <SDL2TK/Vector3.hpp>
#include <SDL2TK/Window.hpp>
#include <iostream>
#include <memory>
using namespace std;

int main(int argc, char** argv)
{
    const SDL2TK::Vector3<double> vec(2.222, 1.1, 1.25);
    cout << vec.X() << endl;

    SDL2TK::Rotation<double> rotation
        = SDL2TK::Rotation<double>::FromDegrees(180.0);
    SDL2TK::Matrix4x4<double> m;

    rotation = rotation + rotation;

    cout << rotation.ToRadians() << endl;
    cout << sizeof(SDL2TK::Module) << endl;

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
    {
        SDL2TK::Window window;
        shared_ptr<SDL2TK::Module> module = make_shared<TestModule>();
        window.Run(*module);
    }
    SDL_Quit();
    return 0;
}
