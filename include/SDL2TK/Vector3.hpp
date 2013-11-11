#ifndef VECTOR3_HPP
#define VECTOR3_HPP

namespace SDL2TK
{
    template<typename T>
    class Vector3
    {
        public:
            constexpr Vector3() : _values{} {}
            constexpr Vector3(T x) : _values{x, 0, 0} {}
            constexpr Vector3(T x, T y) : _values{x, y, 0} {}
            constexpr Vector3(T x, T y, T z) : _values{x, y, z} {}

            constexpr T X() const { return _values[0]; }
            constexpr T Y() const { return _values[1]; }
            constexpr T Z() const { return _values[2]; }

            void X(T value) { _values[0] = value; }
            void Y(T value) { _values[1] = value; }
            void Z(T value) { _values[2] = value; }

        private:
            T _values[3];
    };
}

#endif
