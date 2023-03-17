#include <bits/stdc++.h>
using namespace std;

long long a[3][3];
long long b[3];
int t;

long long determinant(long long m[3][3])
{
    return m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1]) -
           m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0]) +
           m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
}

double cramer(long long detAi, long long detA)
{
    double ret = (double)detAi / (double)detA;

    return abs(ret) < 0.0005 ? 0 : ret;
}

string solve()
{
    ostringstream ret;

    long long detA = determinant(a);
    long long det[3];

    for (int i = 0; i < 3; i++)
    {
        long long m[3][3];

        memcpy(m, a, sizeof(a));
        for (int r = 0; r < 3; r++)
            m[r][i] = b[r];

        det[i] = determinant(m);
        ret << det[i] << ' ';
    }

    ret << detA << '\n';

    if (detA == 0)
        ret << "No unique solution\n";
    else
    {
        ret << "Unique solution: ";
        ret << fixed << setprecision(3);
        ret << cramer(det[0], detA) << ' ';
        ret << cramer(det[1], detA) << ' ';
        ret << cramer(det[2], detA) << '\n';
    }

    return ret.str();
}

int main()
{
    for (scanf("%d", &t); t--;)
    {
        for (int r = 0; r < 3; r++)
        {
            for (int c = 0; c < 3; c++)
                scanf("%lld", &a[r][c]);
            scanf("%lld", &b[r]);
        }

        printf("%s\n", solve().c_str());
    }

    return 0;
}
