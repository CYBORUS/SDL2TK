#include "TestModule.hpp"
#include <SDL2TK/TimeSpan.hpp>
#include <SDL2TK/OpenGL/Shader.hpp>
#include <SDL2TK/OpenGL/Program.hpp>
#include <SDL2TK/OpenGL/ProgramBuilder.hpp>
#include <iostream>
using namespace std;

TestModule::TestModule()
    : _time(0.0f)
{
    PulseInterval(SDL2TK::TimeSpan::FromSeconds(1) / 60);
}

TestModule::~TestModule()
{
}

void TestModule::OnOpen()
{
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
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
}

void TestModule::OnPulse()
{
    const float TimeDelta = 1.0f / 8.0f;
    _time += TimeDelta;
    _finalMatrix.Multiply(_perspectiveMatrix, _modelViewMatrix);
}

void TestModule::OnResize(int width, int height)
{
    float aspectRatio = float(width) / float(height);

    glViewport(0, 0, width, height);

    _perspectiveMatrix.LoadIdentity();
    _perspectiveMatrix.Perspective(SDL2TK::Rotation<float>::FromDegrees(30.0f),
        aspectRatio, 1.0f, 1000.0f);

    cout << "resize " << width << "x" << height << endl;
    cout << SDL2TK::TimeSpan::FromSDL().ToMilliseconds() << endl;
}
