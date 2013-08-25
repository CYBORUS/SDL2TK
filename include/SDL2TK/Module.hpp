#ifndef MODULE_HPP
#define MODULE_HPP

#include <SDL.h>

namespace SDL2TK
{
    class Module
    {
        public:
            friend class Engine;

            Module();
            virtual ~Module();

            inline bool IsRunning() const { return _isRunning; };

            void OnEvent(const SDL_Event& inEvent);

            /// module operation
            virtual void OnOpen();
            virtual void OnClose();
            virtual void OnLoop();
            virtual void OnPulse();
            virtual void OnSecond(Uint32 framesPerSecond);

            /// input events
            virtual void OnInputFocus();
            virtual void OnInputBlur();
            virtual void OnKeyDown(const SDL_Keysym& keysym);
            virtual void OnKeyUp(const SDL_Keysym& keysym);
            virtual void OnMouseFocus();
            virtual void OnMouseBlur();
            virtual void OnMouseMove(const SDL_MouseMotionEvent& event);
            virtual void OnMouseWheel(const SDL_MouseWheelEvent& event);
            virtual void OnMouseButtonDown(const SDL_MouseButtonEvent& event);
            virtual void OnMouseButtonUp(const SDL_MouseButtonEvent& event);
            virtual void OnJoyAxis(const SDL_JoyAxisEvent& event);
            virtual void OnJoyButtonDown(const SDL_JoyButtonEvent& event);
            virtual void OnJoyButtonUp(const SDL_JoyButtonEvent& event);
            virtual void OnJoyHat(const SDL_JoyHatEvent& event);
            virtual void OnJoyBall(const SDL_JoyBallEvent& event);
            virtual void OnMinimize();
            virtual void OnMaximize();
            virtual void OnRestore();
            virtual void OnResize(int width, int height);
            virtual void OnExpose();
            virtual void OnExit();
            virtual void OnUser(Uint8 type, int code, void* data1, void* data2);

        protected:
            inline void IsRunning(bool isRunning) { _isRunning = isRunning; }

        private:
            bool _isRunning;
    };

}

#endif
