#include <bits/stdc++.h>
using namespace std;

char arr[10001][501];
bool check[10001][501];
int dy[] = {-1, 0, 1};
int w, h, ans;
bool back;

void dfs(int x, int y)
{
    check[y][x] = true;

    if (x == w - 1)
    {
        ans++;
        back = true;
        return;
    }

    for (int d = 0; d < 3 && !back; d++)
    {
        int nx = x + 1;
        int ny = y + dy[d];

        if (ny < 0 || ny >= h || arr[ny][nx] == 'x' || check[ny][nx])
            continue;

        dfs(nx, ny);
    }
}

int solve()
{
    for (int i = 0; i < h; i++)
    {
        dfs(0, i);
        back = false;
    }

    return ans;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> h >> w;
    for (int i = 0; i < h; i++)
        cin >> arr[i];

    cout << solve();

    return 0;
}
