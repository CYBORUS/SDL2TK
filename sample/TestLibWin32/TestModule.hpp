#ifndef TESTMODULE_HPP
#define TESTMODULE_HPP

#include "ParticleProgram.hpp"
#include <SDL2TK/Module.hpp>

class TestModule : public SDL2TK::Module
{
    public:
        TestModule();
        virtual ~TestModule();

        virtual void OnOpen();
        virtual void OnClose();
        virtual void OnLoop();
        virtual void OnPulse();

        virtual void OnResize(int width, int height);
    protected:
    private:
        ParticleProgram _program;
        SDL2TK::Matrix4x4<float> _perspectiveMatrix;
        SDL2TK::Matrix4x4<float> _modelViewMatrix;
        SDL2TK::Matrix4x4<float> _finalMatrix;
        float _time;
};

#endif
