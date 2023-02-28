#include <bits/stdc++.h>
#define Mod (long long)(1e9 + 7)
using namespace std;

int t, n;

int pow(int k)
{
    if (k == 0)
        return 1;

    long long mul = pow(k / 2);

    return (mul * mul % Mod) * (k % 2 + 1) % Mod;
}

int main()
{
    for (scanf("%d", &t); t--;)
    {
        scanf("%d", &n);
        printf("%d\n", n < 2 ?: pow(n - 2));
    }

    return 0;
}
