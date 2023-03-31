#include <bits/stdc++.h>
#define fastIO cin.tie(nullptr)->sync_with_stdio(false)
using namespace std;
using Pair = pair<int, int>;

vector<vector<pair<int, int>>> arr;
vector<int> cand;
int T, n, m, t;
int s, g, h;
int a, b, d;

void dijikstra(int dist[], int start)
{
    memset(dist, 0x7f, sizeof(int) * 2001);

    // dist, vertex 순서
    priority_queue<Pair, vector<Pair>, greater<>> pq;

    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty())
    {
        auto [nowD, nowV] = pq.top();
        pq.pop();

        for (auto [nextV, edgeD]: arr[nowV])
        {
            if (dist[nextV] > nowD + edgeD)
            {
                pq.push({nowD + edgeD, nextV});
                dist[nextV] = nowD + edgeD;
            }
        }
    }
}

set<int> solve()
{
    int dist_s[2001] = {};
    int dist_g[2001] = {};
    int dist_h[2001] = {};

    dijikstra(dist_s, s);
    dijikstra(dist_g, g);
    dijikstra(dist_h, h);

    set<int> ret;

    for (int e: cand)
    {
        if (dist_s[e] == dist_s[g] + dist_g[h] + dist_h[e] ||
            dist_s[e] == dist_s[h] + dist_h[g] + dist_g[e])
            ret.insert(e);
    }

    return ret;
}

int main()
{
    fastIO;
    for (cin >> T; T--;)
    {
        arr.clear();
        cand.clear();

        cin >> n >> m >> t;
        cin >> s >> g >> h;

        arr.resize(n + 1);
        while (m--)
        {
            cin >> a >> b >> d;
            arr[a].emplace_back(b, d);
            arr[b].emplace_back(a, d);
        }
        while (t--)
        {
            cin >> a;
            cand.push_back(a);
        }

        for (int i: solve())
            cout << i << ' ';
        cout << '\n';
    }

    return 0;
}
