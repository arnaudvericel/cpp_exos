struct Vec3
{
    static Vec3 VX, VY, VZ;
    float X, Y, Z;
    Vec3(float _x, float _y, float _z): X(_x), Y(_y), Z(_z) {}
    Vec3(): X(0.f), Y(0.f), Z(0.f) {}
    Vec3& operator=(const Vec3& other);
    Vec3 operator-(const Vec3& otherVec) const;
    Vec3 GetNormalized();
    Vec3 CrossProduct(const Vec3& otherVec);
    float DotProduct(const Vec3& otherVec);
};

struct LookAtMatrix
{
    Vec3 fwdAxis, sideAxis, upAxis, transVector;
    LookAtMatrix() = default;
    void Fill(const Vec3& forward, const Vec3& side, const Vec3& up, const Vec3& translation);
    void Display() const;
};
