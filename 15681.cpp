#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_N = 10e5 + 1;

vector<int> conn[MAX_N];
bool visited[MAX_N];
int cnt[MAX_N];
int n, r, q, u, v;

int dfs(const int root)
{
    if (visited[root])
        return cnt[root];

    visited[root] = true;
    cnt[root] = 1;

    for (const int node: conn[root])
    {
        if (!visited[node])
        {
            cnt[node] = dfs(node);
            cnt[root] += cnt[node];
        }
    }

    return cnt[root];
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> r >> q;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        conn[u].push_back(v);
        conn[v].push_back(u);
    }

    dfs(r);

    while (q--)
    {
        cin >> u;
        cout << cnt[u] << '\n';
    }

    return 0;
}
