#include <iostream>
#include <cmath>
#include "code.h"

Vec3 Vec3::VX = Vec3(1.f, 0.f, 0.f);
Vec3 Vec3::VY = Vec3(0.f, 1.f, 0.f);
Vec3 Vec3::VZ = Vec3(0.f, 0.f, 1.f);

Vec3 Vec3::operator-(const Vec3& other) const
{
    return Vec3(X-other.X, Y-other.Y, Z-other.Z);
}

Vec3& Vec3::operator=(const Vec3& other)
{
    X = other.X;
    Y = other.Y;
    Z = other.Z;
    return *this;
}

Vec3 Vec3::GetNormalized()
{
    float norm = sqrt(X*X + Y*Y + Z*Z);
    float x{0.f}, y{0.f}, z{0.f};
    //
    if (norm != 0.f)
    {
        x = X / norm;
        y = Y / norm;
        z = Z / norm;
    }
    return Vec3(x, y, z);
}

Vec3 Vec3::CrossProduct(const Vec3& otherVec)
{
    float x = Y*otherVec.Z - Z*otherVec.Y;
    float y = Z*otherVec.X - X*otherVec.Z;
    float z = X*otherVec.Y - Y*otherVec.X;
    //
    return Vec3(x, y, z);
}

float Vec3::DotProduct(const Vec3& otherVec)
{
    return X*otherVec.X + Y*otherVec.Y + Z*otherVec.Z;
}

void LookAtMatrix::Fill(const Vec3& forward, const Vec3& side, const Vec3& up, const Vec3& translation)
{
    fwdAxis = forward;
    sideAxis = side;
    upAxis = up;
    transVector = translation;
}

void LookAtMatrix::Display() const
{
    std::cout << sideAxis.X << "\t\t" << sideAxis.Y << "\t\t" << sideAxis.Z << "\t\t" << transVector.X << std::endl;
    std::cout << upAxis.X << "\t\t" << upAxis.Y << "\t\t" << upAxis.Z << "\t\t" << transVector.Y << std::endl;
    std::cout << -fwdAxis.Z << "\t\t" << -fwdAxis.Z << "\t\t" << -fwdAxis.Z << "\t\t" << transVector.Z << std::endl;
    std::cout << 0 << "\t\t" << 0 << "\t\t" << 0 << "\t\t" << 1 <<  std::endl;
}

/*
The LookAtMatrix is a 4x4 matrix that stores the local coordinate system in the camera's frame of reference (sub 3x3 matrix)
and an additionnal 3d vector that represents the translation to apply to the camera so that it can point to the target
In a right handed system, Y is the up vector.
*/
void BuildCameraMatrix(const Vec3& camPos, const Vec3& targetPos, LookAtMatrix& camMat)
{
    Vec3 fwd, side, up, translation;

    // the camera needs to look at the target along its local z axis, i.e. "forward"
    // the system needs to be normalized to create an orthonormal system
    fwd = (targetPos - camPos).GetNormalized();

    // the side axis is the result of the cross product between the global y direction ("up") and forward
    side = Vec3::VY.CrossProduct(fwd);

    // the "up" axis in the camera's frame of reference is the result of the cross product between side and fwd
    up = side.CrossProduct(fwd);

    // the translation to apply to the camera to point at the target is the result of
    // the projection (dot product) of its position along all 3 new axes
    // the minus signs are because we need to substract those distances to rightfully point at the target
    translation = Vec3(-side.DotProduct(camPos), -up.DotProduct(camPos), -fwd.DotProduct(camPos));

    camMat.Fill(fwd, side, up, translation);
}

int main()
{
    Vec3 camPos = Vec3(1.f, -2.f, 0.f);
    Vec3 targetPos = Vec3(1.f, 1.f, 1.f);
    LookAtMatrix camMat;

    BuildCameraMatrix(camPos, targetPos, camMat);

    camMat.Display();

    return 0;
}

/*
Output:
--
0.316228		0		    0		    -0.316228
0		        -0.1		0.3		    -0.2
-0.316228		-0.316228   -0.316228	1.89737
0		        0		    0		    1
--
*/
