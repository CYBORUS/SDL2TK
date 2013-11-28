#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstring>
#include <iostream>

namespace SDL2TK
{
    template<typename T> class Vector2;
    template<typename T> class Vector3;
    template<typename T> class Vector4;

    template<typename T>
    class Vector2
    {
        public:
            constexpr Vector2() : _values{0, 0} {}
            constexpr Vector2(T x) : _values{x, 0} {}
            constexpr Vector2(T x, T y) : _values{x, y} {}

            Vector2(const Vector2& other)
            {
                memcpy(_values, other._values, sizeof(T) * 2);
            }

            Vector2(const Vector3<T>& other)
            {
                memcpy(_values, other.ReadOnlyData(), sizeof(T) * 2);
            }

            Vector2(const Vector4<T>& other)
            {
                memcpy(_values, other.ReadOnlyData(), sizeof(T) * 2);
            }

            constexpr T* Data() { return _values; }
            constexpr const T* ReadOnlyData() const { return _values; }

        private:
            T _values[2];
    };

    template<typename T>
    class Vector3
    {
        public:
            constexpr Vector3() : _values{0, 0, 0} {}
            constexpr Vector3(T x) : _values{x, 0, 0} {}
            constexpr Vector3(T x, T y) : _values{x, y, 0} {}
            constexpr Vector3(T x, T y, T z) : _values{x, y, z} {}

            Vector3(const Vector2<T>& other)
            {
                memcpy(_values, other.ReadOnlyData(), sizeof(T) * 2);
                _values[2] = T(0);
            }

            Vector3(const Vector2<T>& other, T z)
            {
                memcpy(_values, other.ReadOnlyData(), sizeof(T) * 2);
                _values[2] = z;
            }

            Vector3(const Vector3& other)
            {
                memcpy(_values, other._values, sizeof(T) * 3);
            }

            Vector3(const Vector4<T>& other)
            {
                memcpy(_values, other.ReadOnlyData(), sizeof(T) * 3);
            }

            constexpr T* Data() { return _values; }
            constexpr const T* ReadOnlyData() const { return _values; }

            constexpr T X() const { return _values[0]; }
            constexpr T Y() const { return _values[1]; }
            constexpr T Z() const { return _values[2]; }

            void X(T value) { _values[0] = value; }
            void Y(T value) { _values[1] = value; }
            void Z(T value) { _values[2] = value; }

        private:
            T _values[3];
    };

    template<typename T>
    class Vector4
    {
        public:
            constexpr Vector4() : _values{0, 0, 0, 0} {}
            constexpr Vector4(T x) : _values{x, 0, 0, 0} {}
            constexpr Vector4(T x, T y) : _values{x, y, 0, 0} {}
            constexpr Vector4(T x, T y, T z) : _values{x, y, z, 0} {}
            constexpr Vector4(T x, T y, T z, T w) : _values{x, y, z, w} {}

            Vector4(const Vector2<T>& other)
            {
                memcpy(_values, other.ReadOnlyData(), sizeof(T) * 2);
                _values[2] = T(0);
                _values[3] = T(0);
            }

            Vector4(const Vector2<T>& other, T z)
            {
                memcpy(_values, other.ReadOnlyData(), sizeof(T) * 2);
                _values[2] = z;
                _values[3] = T(0);
            }

            Vector4(const Vector2<T>& other, T z, T w)
            {
                memcpy(_values, other.ReadOnlyData(), sizeof(T) * 2);
                _values[2] = z;
                _values[3] = w;
            }

            Vector4(const Vector3<T>& other)
            {
                memcpy(_values, other.ReadOnlyData(), sizeof(T) * 3);
                _values[3] = T(0);
            }

            Vector4(const Vector3<T>& other, T w)
            {
                memcpy(_values, other.ReadOnlyData(), sizeof(T) * 3);
                _values[3] = w;
            }

            Vector4(const Vector4& other)
            {
                memcpy(_values, other._values, sizeof(T) * 4);
            }

            constexpr T* Data() { return _values; }
            constexpr const T* ReadOnlyData() const { return _values; }

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

    template<typename T>
    std::ostream& operator<<(std::ostream& stream, const Vector2<T>& v)
    {
        return stream << v.X() << ", " << v.Y();
    }

    template<typename T>
    std::ostream& operator<<(std::ostream& stream, const Vector3<T>& v)
    {
        return stream << v.X() << ", " << v.Y() << ", " << v.Z();
    }

    template<typename T>
    std::ostream& operator<<(std::ostream& stream, const Vector4<T>& v)
    {
        return stream << v.X() << ", " << v.Y() << ", " << v.Z() << ", "
            << v.W();
    }

    typedef Vector2<float> Vector2F;
    typedef Vector3<float> Vector3F;
    typedef Vector4<float> Vector4F;

    typedef Vector2<double> Vector2D;
    typedef Vector3<double> Vector3D;
    typedef Vector4<double> Vector4D;
}

#endif
