#include <bits/stdc++.h>
using namespace std;

int arr[6][6];
long long n, p;

void multMtrx(int a[6][6], int b[6][6])
{
    int multed[6][6] = {};

    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            for (int i = 0; i < n; i++)
                multed[r][c] += a[r][i] * b[i][c];
            multed[r][c] %= 1000;
        }
    }

    memcpy(a, multed, sizeof(multed));
}

string solve()
{
    int ans[6][6] = {};

    for (int i = 0; i < n; i++)
        ans[i][i] = 1;

    while (p > 0)
    {
        if (p % 2 == 1)
            multMtrx(ans, arr);

        multMtrx(arr, arr);
        p /= 2;
    }

    string ret;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ret += to_string(ans[i][j]);
            ret.push_back(' ');
        }

        ret.push_back('\n');
    }

    return ret;
}

int main()
{
    scanf("%lld %lld", &n, &p);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);

    printf("%s\n", solve().c_str());

    return 0;
}
