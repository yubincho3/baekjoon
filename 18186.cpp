#include <bits/stdc++.h>
using namespace std;

long long one[1000003];
long long two[1000003];
int n, b, c;

long long solve(void)
{
    long long ret = one[1] * b;

    if (b <= c)
    {
        for (int i = 2; i <= n; i++)
            ret += one[i] * b;

        return ret;
    }

    for (int i = 2; i <= n; i++)
    {
        long long minVal = min(one[i], one[i - 1]); // 이전 + 현재 -> 2개

        one[i] -= minVal;
        two[i] += minVal;
        ret += c * minVal;

        minVal = min(one[i], two[i - 1]); // 이전 두개 + 현재 -> 3개

        one[i] -= minVal;
        ret += c * minVal + b * one[i]; // 3개 만들고 남은건 1개로
    }

    return ret;
}

int main(void)
{
    scanf("%d %d %d", &n, &b, &c);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &one[i]);

    printf("%lld", solve());

    return 0;
}
