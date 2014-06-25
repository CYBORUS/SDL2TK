#include "../include/SDL2TK/OpenAL/AudioDevice.hpp"

namespace SDL2TK
{
    AudioDevice::AudioDevice()
        : _device(alcOpenDevice(nullptr))
    {
    }

    AudioDevice::AudioDevice(AudioDevice&& other)
        : _device(other._device)
    {
        other._device = nullptr;
    }

    AudioDevice::~AudioDevice()
    {
        Close();
    }

    AudioDevice& AudioDevice::operator=(AudioDevice&& other)
    {
        if (this != &other)
        {
            Close();
            _device = other._device;
            other._device = nullptr;
        }

        return *this;
    }

    bool AudioDevice::Close()
    {
        ALboolean result = alcCloseDevice(_device);
        _device = nullptr;
        return result == AL_TRUE;
    }
}
