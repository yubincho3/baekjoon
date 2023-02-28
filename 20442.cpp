#include <bits/stdc++.h>
using namespace std;

char str[3000001];

int solve()
{
    int n = strlen(str);

    deque<int> lk, rk;

    for (int i = 0, c = 0; i < n; i++)
    {
        if (str[i] == 'R')
            lk.push_back(c);
        else
            c++;
    }

    for (int i = n - 1, c = 0; i >= 0; i--)
    {
        if (str[i] == 'R')
            rk.push_front(c);
        else
            c++;
    }

    int lIdx = 0, rIdx = rk.size() - 1;
    int ret = 0;

    while (lIdx <= rIdx)
    {
        ret = max(ret, min(lk[lIdx], rk[rIdx]) * 2 + rIdx - lIdx + 1);

        if (lk[lIdx] < rk[rIdx])
            lIdx++;
        else
            rIdx--;
    }

    return ret;
}

int main()
{
    scanf("%s", str);
    printf("%d", solve());

    return 0;
}
