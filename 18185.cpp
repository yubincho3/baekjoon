#include <bits/stdc++.h>
using namespace std;

long long arr[10001];
long long cnt[10001][3];
int n;

long long solve(void)
{
    for (int i = 1; i < n; i++)
    {
        long long two = min(cnt[i][0], cnt[i + 1][0]);

        cnt[i + 1][0] -= two;
        cnt[i][0] -= two;
        cnt[i][1] += two;

        long long three = min(cnt[i - 1][1], cnt[i + 1][0]);

        cnt[i - 1][1] -= three;
        cnt[i + 1][0] -= three;
        cnt[i - 1][2] += three;
    }

    long long ret = 0;

    for (int i = 1; i <= n; i++)
        ret += cnt[i][0] * 3 + cnt[i][1] * 5 + cnt[i][2] * 7;

    return ret;
}

int main(void)
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &arr[i]);
        cnt[i][0] = arr[i];
    }

    printf("%lld\n", solve());

    return 0;
}
