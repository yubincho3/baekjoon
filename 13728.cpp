#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1e9 + 7;
int d[100001] = {1, 1, 2};
int n;

int solve()
{
    for (int i = 3; i <= n; i++)
        d[i] = (d[i - 1] + d[i - 2]) % MOD;

    int ret = 0;

    for (int i = 1; i <= n; i++)
    {
        ret += d[gcd(i + 1, n + 1) - 1];
        ret %= MOD;
    }

    return ret;
}

int main()
{
    scanf("%d", &n);
    printf("%d\n", solve());

    return 0;
}
