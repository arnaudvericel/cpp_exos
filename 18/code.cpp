#include "code.h"

#define RAD_TO_DEGREE 180 / M_PI


float Vec3::DotProduct(const Vec3& rOther) const
{
    return X*rOther.X + Y*rOther.Y + Z*rOther.Z;
}

Vec3 Vec3::operator-(const Vec3& rOther) const
{
    return Vec3(X - rOther.X, Y - rOther.Y, Z - rOther.Z);
}

float Vec3::GetLength()
{
    return sqrt(X*X + Y*Y + Z*Z) 
}

Vec3 GetPlayerPosition()
{
    return Vec3(10., 0., 0.);
}

Vec3 GetEnemyPosition()
{
    return Vec3(0., 0., 0.);
}
Vec3 GetEnemySightDir()
{
    return Vec3(1., -1., 0.);
}

// Returns wether or not the enemy can see the player inside a cone <FovDegree> wide (90° by default) centered around its line of sight.
bool EnemyCanSeePlayer(float FovDegree=90.)
{
    Vec3 PlayerPos = GetPlayerPosition();
    Vec3 EnemyPos = GetEnemyPosition();
    Vec3 EnemySightDir = GetEnemySightDir();
    Vec3 EnemyToPlayerVector = PlayerPos - EnemyPos;
    float AngleInDegree = acos(EnemySightDir.DotProduct(EnemyToPlayerVector) / (EnemySightDir.GetLength() * EnemyToPlayerVector.GetLength())) * RAD_TO_DEGREE;
    return abs(AngleDegree) <= FovDegree / 2.;
}


int main()
{
    if (EnemyCanSeePlayer())
    {
        std::cout << "Enemy can see player" << std::endl;
    }
    else
    {
        std::cout << "Enemy cannot see player" << std::endl;
    }
    return 0;
}