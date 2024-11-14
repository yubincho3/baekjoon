#include <bits/stdc++.h>
using namespace std;

constexpr long long INF = 0x7f7f7f7f7f7f7f7f;

vector<tuple<int, int, int>> edges;
long long dist[501];
int n, m, a, b, c;

vector<long long> solve()
{
    memset(dist, 0x7f, sizeof(dist));
    dist[1] = 0;

    for (int i = 1; i < n; i++)
    {
        for (auto [u, v, w_uv]: edges)
        {
            if (dist[u] != INF && dist[u] + w_uv < dist[v])
                dist[v] = dist[u] + w_uv;
        }
    }

    for (auto [u, v, w_uv]: edges)
        if (dist[u] != INF && dist[u] + w_uv < dist[v])
            return {-1};

    vector<long long> ret;

    for (int i = 2; i <= n; i++)
        ret.push_back(dist[i] == INF ? -1 : dist[i]);

    return ret;
}

int main()
{
    // cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    while (m--)
    {
        cin >> a >> b >> c;
        edges.emplace_back(a, b, c);
    }

    for (long long i: solve())
        cout << i << '\n';

    return 0;
}
