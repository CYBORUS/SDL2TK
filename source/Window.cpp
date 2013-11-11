#include "../include/SDL2TK/Window.hpp"

namespace SDL2TK
{
    Window::Window()
        : _window(nullptr)
        , _context(nullptr)
    {
        _window = SDL_CreateWindow("CYBORUS", SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED, 512, 512, SDL_WINDOW_OPENGL
            | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
        _context = (SDL_GLContext*)SDL_GL_CreateContext(_window);
        SDL_GL_SetSwapInterval(1);

        GLenum e = glewInit();
        (void)e;
    }

    Window::Window(Window&& other)
        : _window(other._window)
        , _context(other._context)
    {
        other._window = nullptr;
        other._context = nullptr;
    }

    Window::~Window()
    {
        SDL_GL_DeleteContext(_context);
        SDL_DestroyWindow(_window);
    }

    Window& Window::operator=(Window&& other)
    {
        if (this != &other)
        {
            _window = other._window;
            _context = other._context;
            other._window = nullptr;
            other._context = nullptr;
        }

        return *this;
    }

    void Window::SetIcon(const Surface& surface)
    {
        SDL_SetWindowIcon(_window, surface._surface);
    }

    void Window::Run(Module& module)
    {
        module._isRunning = true;
        module.OnOpen();
        module.OnResize(512, 512);

        TimeSpan lastPulse = TimeSpan::FromSDL();
        while (module.IsRunning())
        {
            module._suppressSwap = false;
            SDL_Event event;

            while (SDL_PollEvent(&event)) module.OnEvent(event);

            TimeSpan interval = TimeSpan::FromSDL() - lastPulse;

            while (interval >= module.PulseInterval())
            {
                module.OnPulse();
                interval -= module.PulseInterval();
                lastPulse += module.PulseInterval();
            }

            module.OnLoop();

            if (!module._suppressSwap) SDL_GL_SwapWindow(_window);

            SDL_Delay(1);
        }

        module.OnClose();
    }
}