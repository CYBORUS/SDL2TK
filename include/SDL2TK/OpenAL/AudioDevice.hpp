#ifndef AUDIODEVICE_HPP
#define AUDIODEVICE_HPP

#ifdef __WIN32__
#   include <al.h>
#   include <alc.h>
#else
#   include <AL/al.h>
#   include <AL/alc.h>
#endif

namespace SDL2TK
{
    class AudioDevice
    {
        public:
            AudioDevice();
            AudioDevice(AudioDevice&& other);
            ~AudioDevice();

            AudioDevice& operator=(AudioDevice&& other);

            bool Close();

            inline bool IsOpen() const { return _device != nullptr; }

        private:
            AudioDevice(const AudioDevice&) = delete;
            AudioDevice& operator=(const AudioDevice&) = delete;

            ALCdevice* _device;
    };
}

#endif
