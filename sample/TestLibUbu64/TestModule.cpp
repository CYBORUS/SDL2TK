#include "TestModule.hpp"
#include "ParticleBuilder.hpp"
#include <SDL2TK/TimeSpan.hpp>
#include <SDL2TK/OpenGL/Shader.hpp>
#include <SDL2TK/OpenGL/Program.hpp>
#include <SDL2TK/OpenGL/ProgramBuilder.hpp>
#include <iostream>
#include <random>
using namespace std;

TestModule::TestModule()
    : _time(0.0f)
{
    PulseInterval(SDL2TK::TimeSpan::FromSeconds(1) / 60);

    ParticleBuilder builder;

    mt19937 generator;
    uniform_real_distribution<float> distribution(0.0f, 1.0f);
    SDL2TK::Vector4<GLfloat> vertex(0.0f, 0.0f, 0.0f, 1.0f);

    for (int i = 0; i < 5000; ++i)
    {
        SDL2TK::Vector4<GLfloat> color;

        color.X(distribution(generator));
        //color.Y(0.0f);
        color.Y(distribution(generator));
        color.Z(distribution(generator));
        color.W(1.0f);

        SDL2TK::Vector3<GLfloat> velocity;

        velocity.X(distribution(generator) * 16.0f - 8.0f);
        velocity.Y(distribution(generator) * 16.0f);

        //cout << velocity.X() << " " << velocity.Y() << '\n';

        builder.Add(vertex, color, velocity, distribution(generator) * 16.0f);
    }

    cout.flush();

    _bufferObject = ParticleBufferObject(builder);
}

TestModule::~TestModule()
{
}

void TestModule::OnOpen()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glPointSize(4.0f);
}

void TestModule::OnClose()
{
}

void TestModule::OnLoop()
{
    glClear(GL_COLOR_BUFFER_BIT);
    _program.Use();
    _program.SetMatrix(_finalMatrix);
    _program.SetTime(_time);
    _bufferObject.Draw(_program);
}

void TestModule::OnPulse()
{
    const float TimeDelta = 1.0f / 64.0f;
    _time += TimeDelta;
    _finalMatrix.Multiply(_perspectiveMatrix, _modelViewMatrix);
}

void TestModule::OnResize(int width, int height)
{
    float aspectRatio = float(width) / float(height);

    glViewport(0, 0, width, height);

    _perspectiveMatrix.LoadIdentity();
    //_perspectiveMatrix.Perspective(SDL2TK::Rotation<float>::FromDegrees(30.0f),
        //aspectRatio, 1.0f, 1000.0f);
    _perspectiveMatrix.Orthographic(8.0f, aspectRatio);
    cout << _perspectiveMatrix << endl;
    cout << _modelViewMatrix << endl;

    cout << "resize " << width << "x" << height << endl;
    cout << SDL2TK::TimeSpan::FromSDL().ToMilliseconds() << endl;
}
