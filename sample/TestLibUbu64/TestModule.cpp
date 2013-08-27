#include "TestModule.hpp"
#include <SDL_opengl.h>
#include <iostream>
using namespace std;

TestModule::TestModule()
{
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

void TestModule::OnResize(int width, int height)
{
    glViewport(0, 0, width, height);
    cerr << "resize " << width << "x" << height << '\n';
}
