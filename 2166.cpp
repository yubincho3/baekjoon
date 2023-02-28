#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<pair<ll, ll>> pos;
int n, x, y;

double solve()
{
    double ret = 0;

    for (int i = 1; i < n - 1; i++)
    {
        ret += (pos[i].first - pos[0].first) * (pos[i + 1].second - pos[0].second) -
               (pos[i].second - pos[0].second) * (pos[i + 1].first - pos[0].first);
    }

    return abs(ret) / 2;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &x, &y);
        pos.emplace_back(x, y);
    }

    printf("%.1f\n", solve());

    return 0;
}
