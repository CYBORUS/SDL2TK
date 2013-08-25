#include <SDL.h>
#include <SDL_opengl.h>
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cerr << "Failed to initialize SDL!\n";
        return 1;
    }

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    SDL_Window* window = SDL_CreateWindow("CYBORUS", SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, 512, 512, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    SDL_GLContext* context = (SDL_GLContext*)SDL_GL_CreateContext(window);

    SDL_GL_SetSwapInterval(1);

    glClearColor(1.0f, 1.0f, 0.0f, 1.0f);

    SDL_Event event;
    bool isRunning = true;

    while (isRunning)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT) isRunning = false;
        }

        glClear(GL_COLOR_BUFFER_BIT);
        SDL_GL_SwapWindow(window);
        SDL_Delay(1);
    }

    cout << "Hello, world!" << endl;

    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
