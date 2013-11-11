#ifndef PARTICLEPROGRAM_HPP
#define PARTICLEPROGRAM_HPP

#include <SDL2TK/OpenGL/Program.hpp>
#include <SDL2TK/Matrix4x4.hpp>

class ParticleProgram
{
    public:
        ParticleProgram();
        ~ParticleProgram();

        inline void Use() { _program.Use(); }
        void SetMatrix(const SDL2TK::Matrix4x4<float>& matrix);
        void SetTime(float time);

    protected:
    private:
        SDL2TK::Program _program;
        GLint _timeUniform;
        GLint _matrixUniform;
        GLint _vertexAttribute;
        GLint _colorAttribute;
        GLint _velocityAttribute;
        GLint _startAttribute;

        friend class ParticleBufferObject;
};

#endif
