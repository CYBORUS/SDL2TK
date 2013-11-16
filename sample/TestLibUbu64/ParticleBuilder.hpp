#ifndef PARTICLEBUILDER_HPP
#define PARTICLEBUILDER_HPP

#include <SDL2TK/OpenGL/glew.h>
#include <SDL2TK/Vector4.hpp>
#include <SDL2TK/Vector3.hpp>
#include <vector>

class ParticleBuilder
{
    public:
        ParticleBuilder();
        ParticleBuilder(ParticleBuilder&& other);
        ~ParticleBuilder();

        ParticleBuilder& operator=(ParticleBuilder&& other);

        void Add(const SDL2TK::Vector4<GLfloat>& vertex,
            const SDL2TK::Vector4<GLfloat>& color,
            const SDL2TK::Vector3<GLfloat>& velocity,
            GLfloat startTime);
    protected:
    private:
        ParticleBuilder(const ParticleBuilder&) = delete;
        ParticleBuilder& operator=(const ParticleBuilder&) = delete;

        std::vector<GLfloat> _array;

    friend class ParticleBufferObject;
};

#endif
