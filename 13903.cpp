#include <bits/stdc++.h>
using namespace std;

constexpr size_t MAX_LEN = 1001;

int arr[MAX_LEN][MAX_LEN];
int dist[MAX_LEN][MAX_LEN];
int dx[11], dy[11];
int h, w, n;

int solve()
{
    queue<pair<int, int>> q;

    for (int i = 0; i < w; i++)
    {
        if (arr[0][i])
        {
            q.emplace(i, 0);
            dist[0][i] = 0;
        }
    }

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        if (y == h - 1)
            return dist[y][x];

        for (int i = 0; i < n; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= w || ny >= h)
                continue;

            if (dist[ny][nx] == -1 && arr[ny][nx])
            {
                q.emplace(nx, ny);
                dist[ny][nx] = dist[y][x] + 1;
            }
        }
    }

    return -1;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    memset(dist, -1, sizeof dist);

    cin >> h >> w;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> arr[i][j];

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> dy[i] >> dx[i];

    cout << solve();

    return 0;
}
