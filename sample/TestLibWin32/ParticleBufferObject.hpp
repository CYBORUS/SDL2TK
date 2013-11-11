#ifndef PARTICLEBUFFEROBJECT_HPP
#define PARTICLEBUFFEROBJECT_HPP

#include <SDL2TK/OpenGL/glew.h>

class ParticleBuilder;
class ParticleProgram;

class ParticleBufferObject
{
    public:
        ParticleBufferObject();
        ParticleBufferObject(const ParticleBuilder& builder);
        ParticleBufferObject(ParticleBufferObject&& other);
        ~ParticleBufferObject();

        ParticleBufferObject& operator=(ParticleBufferObject&& other);

        void Draw(const ParticleProgram& program) const;

    protected:
    private:
        ParticleBufferObject(const ParticleBufferObject&) = delete;
        ParticleBufferObject& operator=(const ParticleBufferObject&) = delete;

        GLuint _buffer;
        GLsizei _count;
};

#endif
