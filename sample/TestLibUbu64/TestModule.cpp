#include "TestModule.hpp"
#include <SDL_opengl.h>
#include <SDL2TK/TimeSpan.hpp>
#include <iostream>
using namespace std;

TestModule::TestModule()
{
    PulseInterval(SDL2TK::TimeSpan::FromSeconds(1));
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
}

void TestModule::OnPulse()
{
    cout << "Pulse!" << endl;
}

void TestModule::OnResize(int width, int height)
{
    glViewport(0, 0, width, height);
    cout << "resize " << width << "x" << height << endl;
    cout << SDL2TK::TimeSpan::FromSDL().ToMilliseconds() << endl;
}
