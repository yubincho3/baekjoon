#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_N = 500001;

int parent[MAX_N];
int level[MAX_N];
int n, m, x, y;

int find(int u)
{
    if (parent[u] != u)
        parent[u] = find(parent[u]);

    return parent[u];
}

bool merge(int u, int v)
{
    u = find(u);
    v = find(v);

    if (u == v)
        return false;

    if (level[u] > level[v])
        swap(u, v);

    if (level[u] == level[v])
        level[v]++;

    parent[u] = v;

    return true;
}

int solve()
{
    int ans = 0;

    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        if (!merge(x, y))
        {
            ans = i;
            break;
        }
    }

    return ans;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    cout << solve();

    return 0;
}
