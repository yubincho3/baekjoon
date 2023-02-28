#include <bits/stdc++.h>
using namespace std;

bool notp[10000001];
int n;

vector<int> solve()
{
    vector<int> v;

    for (int i = 2; i <= n; i++)
    {
        if (notp[i])
            continue;

        for (int j = 1; i * j <= n; j++)
            notp[i * j] = true;

        v.push_back(i);
    }

    vector<int> ret;

    for (int p: v)
    {
        while (n % p == 0)
        {
            ret.push_back(p);
            n /= p;
        }

        if (n == 1)
            break;
    }

    return ret;
}

int main()
{
    scanf("%d", &n);
    for (int i: solve())
        printf("%d\n", i);

    return 0;
}
