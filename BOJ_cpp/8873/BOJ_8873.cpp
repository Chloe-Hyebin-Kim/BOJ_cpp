#include <bits/stdc++.h>
using namespace std;
class Vector3
{
public:
    float x;
    float y;
    float z;

    Vector3()
    {
        x = 0;
        y = 0;
        z = 0;
    }

    Vector3(float _x, float _y, float _z)
    {
        x = _x;
        y = _y;
        z = _z;
    }

    // 벡터 덧셈
    friend Vector3 operator+(const Vector3& a, const Vector3& b)
    {
        float Vx = a.x + b.x;
        float Vy = a.y + b.y;
        float Vz = a.z + b.z;

        return Vector3(Vx, Vy, Vz);
    }

    // 벡터 뺄셈
    friend Vector3 operator-(const Vector3& a, const Vector3& b)
    {
        float Vx = a.x - b.x;
        float Vy = a.y - b.y;
        float Vz = a.z - b.z;

        return Vector3(Vx, Vy, Vz);
    }

    //내적 구하기(스칼라 곱)
    friend float operator*(const Vector3& a, const Vector3& b)
    {
        float Vx = a.x * b.x;
        float Vy = a.y * b.y;
        float Vz = a.z * b.z;

        return Vx + Vy + Vz;
    }

    // 두 벡터가 같을때
    bool operator==(Vector3 a)
    {
        if (x == a.x && y == a.y && z == a.z)
            return true;
        else
            return false;
    }

    // 정규화
    Vector3 Normalrize()
    {
        Vector3 normal;
        float magnitude = this->Magnitude();
        normal.x = x / magnitude;
        normal.y = y / magnitude;
        normal.z = z / magnitude;

        return normal;
    }

    float Magnitude() // 벡터 크기
    {
        auto magnitude = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
        return magnitude;
    }
};

void solution()
{
    int H, W;
    cin >> H >> W;
    vector<vector<int>> R(H);
    vector<vector<int>> G(H);
    vector<vector<int>> B(H);

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            int r;
            cin >> r;
            R[i].push_back(r);
        }
    }
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            int g;
            cin >> g;
            G[i].push_back(g);
        }
    }
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            int b;
            cin >> b;
            B[i].push_back(b);
        }
    }

    vector<Vector3> vectors;
    float accumulated = 0;
    float accumulatedr = 0;
    float accumulatedg = 0;
    float accumulatedb = 0;
    for (int i = 2; i < H - 2; i++)
    {
        for (int j = 2; j < W - 2; j++)
        {
            Vector3 resultRGB;
            Vector3 rgb = Vector3(R[i][j], G[i][j], B[i][j]);

            int checkCell = 1;
            for (int x = -checkCell; x <= checkCell; x++) {
                for (int y = -checkCell; y <= checkCell; y++) {
                    if (x == 0 && y == 0) continue;
                    resultRGB = resultRGB + (Vector3(R[i + x][j + y], G[i + x][j + y], B[i + x][j + y]) - rgb); //rgb0-rgb;
                }
            }
            accumulated += resultRGB.Magnitude();
            accumulatedr += resultRGB.x;
            accumulatedg += resultRGB.y;
            accumulatedb += resultRGB.z;
        }
    }

    accumulated /= H * W;
    accumulatedr /= H * W;
    accumulatedg /= H * W;
    accumulatedb /= H * W;

    int output = 4;
    if (accumulated > 195)
        output = 3;
    else if (accumulated > 85 && accumulated <= 195)
        output = 2;
    else if (accumulated > 35 & accumulated <= 85)
        output = 1;
    else output = 4;
    cout << output << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solution();
}
