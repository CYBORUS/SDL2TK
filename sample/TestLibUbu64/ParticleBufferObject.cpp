#include "ParticleBufferObject.hpp"
#include "ParticleBuilder.hpp"
#include "ParticleProgram.hpp"
#include <iostream>

static constexpr GLvoid* Offset(size_t offset)
{
    return (GLfloat*)0 + offset;
}

ParticleBufferObject::ParticleBufferObject()
    : _buffer(0)
    , _count(0)
{
}

ParticleBufferObject::ParticleBufferObject(const ParticleBuilder& builder)
    : _buffer(0)
{
    std::size_t size = builder._array.size();
    _count = size / 12;
    std::cerr << "particle count -- " << _count << '\n';

    if (_count > 0)
    {
        glGenBuffers(1, &_buffer);
        glBindBuffer(GL_ARRAY_BUFFER, _buffer);

        glBufferData(
            GL_ARRAY_BUFFER,
            size * sizeof(GLfloat),
            builder._array.data(),
            GL_STATIC_DRAW);
    }
}

ParticleBufferObject::ParticleBufferObject(ParticleBufferObject&& other)
    : _buffer(other._buffer)
    , _count(other._count)
{
    other._buffer = 0;
    other._count = 0;
}

ParticleBufferObject::~ParticleBufferObject()
{
    glDeleteBuffers(1, &_buffer);
}

ParticleBufferObject& ParticleBufferObject::operator=(
    ParticleBufferObject&& other)
{
    if (this != &other)
    {
        glDeleteBuffers(1, &_buffer);
        _buffer = other._buffer;
        _count = other._count;
        other._buffer = 0;
        other._count = 0;
    }

    return *this;
}

void ParticleBufferObject::Draw(const ParticleProgram& program) const
{
    const GLsizei stride = sizeof(GLfloat) * 12;

    glBindBuffer(GL_ARRAY_BUFFER, _buffer);
    glVertexAttribPointer(program._vertexAttribute, 4, GL_FLOAT, GL_FALSE,
        stride, Offset(0));
    glEnableVertexAttribArray(program._vertexAttribute);

    glVertexAttribPointer(program._colorAttribute, 4, GL_FLOAT, GL_FALSE,
        stride, Offset(4));
    glEnableVertexAttribArray(program._colorAttribute);

    glVertexAttribPointer(program._velocityAttribute, 3, GL_FLOAT, GL_FALSE,
        stride, Offset(8));
    glEnableVertexAttribArray(program._velocityAttribute);

    glVertexAttribPointer(program._startAttribute, 1, GL_FLOAT, GL_FALSE,
        stride, Offset(11));
    glEnableVertexAttribArray(program._startAttribute);

    glDrawArrays(GL_POINTS, 0, _count);

    glDisableVertexAttribArray(program._startAttribute);
    glDisableVertexAttribArray(program._velocityAttribute);
    glDisableVertexAttribArray(program._colorAttribute);
    glDisableVertexAttribArray(program._vertexAttribute);
}
