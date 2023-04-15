#include <iostream>
#include <cmath>

struct Vec3
{
    float X, Y, Z;
    Vec3(float X, float Y, float Z) : X(X), Y(Y), Z(Z) {};

    float DotProduct(const Vec3& rOther) const;
    Vec3 operator-(const Vec3& rOther) const;
    //Vec3 operator+(const Vec3& rOther) const; # Not needed
    //Vec3 operator*(float scale) const; # Not needed
    float GetLength() const;
};
