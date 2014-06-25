#include "../include/SDL2TK/OpenAL/AudioContext.hpp"

namespace SDL2TK
{
    AudioContext::AudioContext(const AudioDevice& device)
        : _context(alcCreateContext(device._device, nullptr))
    {
        MakeCurrent();
    }

    AudioContext::AudioContext(AudioContext&& other)
        : _context(other._context)
    {
        other._context = nullptr;
    }

    AudioContext::~AudioContext()
    {
        alcMakeContextCurrent(nullptr);
        alcDestroyContext(_context);
    }

    bool AudioContext::MakeCurrent() const
    {
        return alcMakeContextCurrent(_context) == ALC_TRUE;
    }
}
