#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Tuple = tuple<ll, int, int>;

vector<pair<int, ll>> road[10001];
ll dist[10001][21];
int n, m, k;

ll solve()
{
    if (n == 1)
        return 0;

    memset(dist, 0x7f, sizeof(dist));

    priority_queue<Tuple, vector<Tuple>, greater<>> pq;

    pq.emplace(0, 1, k);
    dist[1][k] = 0;

    ll ret = LONG_LONG_MAX;

    while (!pq.empty())
    {
        auto [nowDist, now, remain] = pq.top();
        pq.pop();

        if (now == n)
            ret = min(ret, dist[now][remain]);

        if (dist[now][remain] != nowDist)
            continue;

        for (auto [nxt, cost]: road[now])
        {
            if (dist[nxt][remain] > dist[now][remain] + cost)
            {
                pq.emplace(nowDist + cost, nxt, remain);
                dist[nxt][remain] = dist[now][remain] + cost;
            }

            if (remain > 0 && dist[nxt][remain - 1] > dist[now][remain])
            {
                pq.emplace(nowDist, nxt, remain - 1);
                dist[nxt][remain - 1] = dist[now][remain];
            }
        }
    }

    return ret;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    for (cin >> n >> m >> k; m--;)
    {
        int a, b, c;

        cin >> a >> b >> c;
        road[a].emplace_back(b, c);
        road[b].emplace_back(a, c);
    }

    cout << solve();

    return 0;
}
