#ifndef AUDIOBUFFER_HPP
#define AUDIOBUFFER_HPP

#ifdef __WIN32__
#   include <al.h>
#else
#   include <AL/al.h>
#endif

namespace SDL2TK
{
    class AudioBuffer
    {
        public:
            AudioBuffer();
            AudioBuffer(AudioBuffer&& other);
            ~AudioBuffer();

            AudioBuffer& operator=(AudioBuffer&& other);

            static AudioBuffer FromWavFile(const char* path);

        private:
            AudioBuffer(const AudioBuffer&) = delete;
            AudioBuffer& operator=(const AudioBuffer&) = delete;

            ALuint _buffer;

            friend class AudioSource;
    };
}

#endif
