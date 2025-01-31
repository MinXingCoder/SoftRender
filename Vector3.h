#pragma once
#include <cmath>
#include <iostream>

namespace math 
{
    template <typename T>
    class Vector3
    {
    public:
        T x, y, z, w;

        Vector3() 
        : x(0)
        , y(0)
        , z(0)
        , w(1)
        {}

        Vector3(T _x, T _y, T _z)
        : x(_x)
        , y(_y)
        , z(_z)
        , w(1)
        {}

        Vector3(T _x, T _y, T _z, T _w)
        : x(_x)
        , y(_y)
        , z(_z)
        , w(_w)
        {}

        Vector3<T> operator +(const Vector3<T>& right) const
        {
            Vector3<T> value(this->x + right.x, this->y + right.y, this->z + right.z);
            return value;
        }

        Vector3<T> operator -(const Vector3<T>& right) const
        {
            Vector3<T> value(this->x - right.x, this->y - right.y, this->z - right.z);
            return value;
        }

        Vector3<T> operator *(float v) const
        {
            Vector3<T> value(this->x * v, this->y * v, this->z * v);
            return value;
        }

        Vector3<T> operator /(float v) const 
        {
            Vector3<T> value(this->x / v, this->y / v; this->z / v);
            return value;
        }

        float Dot(const Vector3<T>& right) const 
        {
            return (this->x * right.x + this->y * right.y + this->z * right.z);
        }

        Vector3<T> Cross(const Vector3<T>& right) const 
        {
            Vector3<T> value(this->y * right.z - right.y * this->z,
                            this->z * right.x - this->x * right.z,
                            this->x * right.y - this->y * right.x);
            return value;
        }

        float SquareMagnitude(const Vector3<T>& right) const
        {
            return this->Dot(*this);
        }

        float Magnitude(const Vector3<T>& right) const 
        {
            return std::sqrt(SquareMagnitude(right));
        }

        Vector3<T> Normalize() const 
        {
            float v = this->Magnitude(*this);
            return (*this / v);
        }

        friend Vector3<T> Lerp(const Vector3<T>& left, const Vector3<T>& right, float t);

        void Standardization()
        {
            if(w == 0)
                return;
            
            x /= w;
            y /= w;
            z /= w;
            w = 1;
        }

        void Print() const
        {
            std::cout << "Vector3<T> " << "x: " << x
                    << "y: " << y
                    << "z: " << z << std::endl;
        }
    };

    template <typename T>
    Vector3<T> Lerp(const Vector3<T>& left, const Vector3<T>& right, float t)
    {
        return (left + (right - left) * t);
    }

    using Vector3f = Vector3<float>;
}