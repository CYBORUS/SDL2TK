#ifndef VECTOR4_HPP
#define VECTOR4_HPP

namespace SDL2TK
{
    template<typename T>
    class Vector4
    {
        public:
            constexpr Vector4() : _values{} {}
            constexpr Vector4(T x) : _values{x, 0, 0, 0} {}
            constexpr Vector4(T x, T y) : _values{x, y, 0, 0} {}
            constexpr Vector4(T x, T y, T z) : _values{x, y, z, 0} {}
            constexpr Vector4(T x, T y, T z, T w) : _values{x, y, z, w} {}

            constexpr T X() const { return _values[0]; }
            constexpr T Y() const { return _values[1]; }
            constexpr T Z() const { return _values[2]; }
            constexpr T W() const { return _values[3]; }

            void X(T value) { _values[0] = value; }
            void Y(T value) { _values[1] = value; }
            void Z(T value) { _values[2] = value; }
            void W(T value) { _values[3] = value; }

        private:
            T _values[4];
    };
}

#endif

