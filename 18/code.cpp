#include <vector>
#include "code.h"

#define RAD_TO_DEG 180 / M_PI
#define Scenarios std::vector<SceneSetup>

float Vec3::DotProduct(const Vec3& rOther) const
{
    return X*rOther.X + Y*rOther.Y + Z*rOther.Z;
}

Vec3 Vec3::operator-(const Vec3& rOther) const
{
    return Vec3(X - rOther.X, Y - rOther.Y, Z - rOther.Z);
}

float Vec3::GetLength() const
{
    return sqrt(X*X + Y*Y + Z*Z);
}

// Returns wether or not the enemy can see the player inside a cone <FovDegree> wide (90° by default) centered around its line of sight.
bool EnemyCanSeePlayer(const SceneSetup& Setup)
{
    Vec3 EnemyToPlayerVector = Setup.PlayerPos - Setup.EnemyPos;
    float AngleInDegree = acos(Setup.EnemySightDir.DotProduct(EnemyToPlayerVector)
                          / (Setup.EnemySightDir.GetLength() * EnemyToPlayerVector.GetLength()))
                          * RAD_TO_DEG;
    return abs(AngleInDegree) <= Setup.EnemyFovDegree / 2.;
}

Scenarios GetScenarios()
{
    Scenarios scenarios;
    // SceneSetup(EnemyPos, PlayerPos, EnemySightDir, EnemyFovDegree, EnemyShouldSeePlayer)
    scenarios.push_back(SceneSetup(Vec3(0., 0., 0.), Vec3(3., 0., 0.), Vec3(1., 1., 0.), 90., true));
    scenarios.push_back(SceneSetup(Vec3(0., 0., 0.), Vec3(3., 0., 0.), Vec3(1., 1., 0.), 60., false));
    scenarios.push_back(SceneSetup(Vec3(0., 0., 0.), Vec3(-3., 0., 0.), Vec3(1., 1., 0.), 180., false));
    scenarios.push_back(SceneSetup(Vec3(0., 0., 0.), Vec3(-3., 0., 0.), Vec3(0., 1., 0.), 180., true));
    scenarios.push_back(SceneSetup(Vec3(0., 0., 0.), Vec3(-3., 0., 0.), Vec3(-1., 1., 0.), 180., true));
    return scenarios;
}

int main()
{
    Scenarios scenarios = GetScenarios();
    //
    for (Scenarios::iterator it = scenarios.begin(); it != scenarios.end(); it++)
    {
        bool EnemyShouldSeePlayer = it->EnemyShouldSeePlayer;
        bool EnemySeesPlayer = EnemyCanSeePlayer(*it);
        //
        std::cout << "Scenario #" << it - scenarios.begin() + 1 << " : ";
        if (EnemyShouldSeePlayer == EnemySeesPlayer)
        {
            std::cout << "OK" << std::endl;
        }
        else
        {
            std::cout << "KO" << std::endl;
        }
    }
    return 0;
}
