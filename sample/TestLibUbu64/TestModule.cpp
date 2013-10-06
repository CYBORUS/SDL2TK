#include "TestModule.hpp"
#include <SDL2TK/TimeSpan.hpp>
#include <SDL2TK/OpenGL/Shader.hpp>
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

    const char* source = "#version 120\n"
        "uniform mat4 uMVPM;\n"
        "attribute vec3 iPosition;\n"
        "attribute vec2 iTexture;\n"
        "varying vec2 vTexture;\n"
        "void main(void)\n"
        "{\n"
        "vTexture = iTexture;\n"
        "vec4 p = vec4(iPosition, 1.0);\n"
        "gl_Position = uMVPM * p;\n"
        "}\n";

    SDL2TK::Shader shader(SDL2TK::Shader::Type::Vertex, source);

    cout << "errors: " << shader.Errors() << endl;
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
