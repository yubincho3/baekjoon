#include <bits/stdc++.h>
using namespace std;

bool notp[4000001];
int n;

int solve()
{
    vector<int> prime;

    for (int i = 2; i <= n; i++)
    {
        if (notp[i])
            continue;

        for (int j = 1; i * j <= n; j++)
            notp[i * j] = true;

        prime.push_back(i);
    }

    int lIdx = 0, rIdx = 0;
    int sum = prime[0];
    int ret = 0;

    while (lIdx < prime.size())
    {
        while (sum > n && lIdx < rIdx)
            sum -= prime[rIdx--];
        while (sum < n && rIdx < prime.size())
            sum += prime[++rIdx];

        ret += (sum == n);

        sum -= prime[lIdx++];
    }

    return ret;
}

int main()
{
    scanf("%d", &n);
    printf("%d\n", solve());

    return 0;
}
