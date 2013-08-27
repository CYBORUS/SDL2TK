#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "Surface.hpp"
#include "Module.hpp"

namespace SDL2TK
{
    class Window
    {
        public:
            Window();
            Window(Window&& other);
            ~Window();

            Window& operator=(Window&& other);

            void SetIcon(const Surface& surface);
            void Run(Module& module);

        private:
            Window(const Window&) = delete;
            Window& operator=(const Window&) = delete;

            SDL_Window* _window;
            SDL_GLContext* _context;
    };
}

#endif
