#include <iostream>
#include <cmath>

struct Vec3
{
    float X, Y, Z;
    Vec3(float _X, float _Y, float _Z) : X(_X), Y(_Y), Z(_Z) {};

    float DotProduct(const Vec3& rOther) const;
    Vec3 operator-(const Vec3& rOther) const;
    //Vec3 CrossProduct(const Vec3& rOther) const; # Not needed
    //Vec3 operator+(const Vec3& rOther) const; # Not needed
    //Vec3 operator*(float scale) const; # Not needed
    //Vec3 GetNormalized() const; # Not needed
    float GetLength() const;
};

struct SceneSetup
{
    Vec3 EnemyPos, PlayerPos, EnemySightDir;
    float EnemyFovDegree;
    bool EnemyShouldSeePlayer;
    SceneSetup(Vec3 EnemyPos, Vec3 PlayerPos, Vec3 EnemySightDir, float EnemyFovDegree, bool EnemyShouldSeePlayer) : EnemyPos(EnemyPos), PlayerPos(PlayerPos), EnemySightDir(EnemySightDir), EnemyFovDegree(EnemyFovDegree), EnemyShouldSeePlayer(EnemyShouldSeePlayer) {}
};
