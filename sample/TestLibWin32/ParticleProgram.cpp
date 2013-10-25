#include "ParticleProgram.hpp"
#include <SDL2TK/Tools.hpp>
#include <SDL2TK/OpenGL/ProgramBuilder.hpp>
#include <iostream>
using namespace std;

ParticleProgram::ParticleProgram()
    : _timeUniform(0)
    , _matrixUniform(0)
    , _vertexAttribute(0)
    , _colorAttribute(0)
    , _velocityAttribute(0)
    , _startAttribute(0)
{
    SDL2TK::Shader vertexShader(SDL2TK::Shader::Type::Vertex,
        SDL2TK::FileToString("particle.vertex.shader").c_str());

    if (vertexShader.HasErrors())
        cout << "vertex shader errors: " << vertexShader.Errors() << endl;

    SDL2TK::Shader fragmentShader(SDL2TK::Shader::Type::Fragment,
        SDL2TK::FileToString("particle.fragment.shader").c_str());

    if (fragmentShader.HasErrors())
        cout << "fragment shader errors: " << fragmentShader.Errors() << endl;

    SDL2TK::ProgramBuilder builder;
    builder.Attach(vertexShader);
    builder.Attach(fragmentShader);

    _program = builder.Link();

    if (_program.HasErrors())
    {
        cout << "program errors: " << _program.Errors() << endl;
    }
    else
    {
        _matrixUniform = _program.GetUniformLocation("MVPM");
        _timeUniform = _program.GetUniformLocation("Time");
        _vertexAttribute = _program.GetAttributeLocation("MCVertex");
        _colorAttribute = _program.GetAttributeLocation("MColor");
        _velocityAttribute = _program.GetAttributeLocation("Velocity");
        _startAttribute = _program.GetAttributeLocation("StartTime");
    }
}

ParticleProgram::~ParticleProgram()
{
}

void ParticleProgram::SetMatrix(const SDL2TK::Matrix4x4<float>& matrix)
{
    glUniformMatrix4fv(_matrixUniform, 1, GL_FALSE, matrix);
}

void ParticleProgram::SetTime(float time)
{
    glUniform1f(_timeUniform, time);
}
