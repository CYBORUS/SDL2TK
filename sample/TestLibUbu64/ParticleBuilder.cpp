#include "ParticleBuilder.hpp"

ParticleBuilder::ParticleBuilder()
{
}

ParticleBuilder::ParticleBuilder(ParticleBuilder&& other)
    : _array(std::move(other._array))
{
}

ParticleBuilder::~ParticleBuilder()
{
}

void ParticleBuilder::Add(const SDL2TK::Vector4<GLfloat>& vertex,
    const SDL2TK::Vector4<GLfloat>& color,
    const SDL2TK::Vector3<GLfloat>& velocity,
    GLfloat startTime)
{
    _array.push_back(vertex.X());
    _array.push_back(vertex.Y());
    _array.push_back(vertex.Z());
    _array.push_back(vertex.W());

    _array.push_back(color.X());
    _array.push_back(color.Y());
    _array.push_back(color.Z());
    _array.push_back(color.W());

    _array.push_back(velocity.X());
    _array.push_back(velocity.Y());
    _array.push_back(velocity.Z());

    _array.push_back(startTime);
}
