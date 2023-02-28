#include <bits/stdc++.h>
using namespace std;

bool notp[246913];
int n;

int solve()
{
    int ret = 0;

    for (int i = n + 1; i <= n * 2; i++)
        ret += !notp[i];

    return ret;
}

int main()
{
    for (int i = 2; i < 246913; i++)
    {
        if (notp[i])
            continue;

        for (int j = 2; i * j < 246913; j++)
            notp[i * j] = true;
    }

    while (true)
    {
        scanf("%d", &n);

        if (n == 0)
            break;

        printf("%d\n", solve());
    }

    return 0;
}
