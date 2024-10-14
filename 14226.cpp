#include <bits/stdc++.h>
using namespace std;

bool visited[2001][2001];
int s;

void solve()
{
    queue<tuple<int, int, int>> q;

    q.emplace(0, 1, 0);
    visited[1][0] = 0;

    while (!q.empty())
    {
        auto [t, screen, clipboard] = q.front();
        q.pop();

        if (screen == s)
        {
            cout << t;
            return;
        }

        if (screen > 0 && screen < 2001)
        {
            // ctrl c
            if (!visited[screen][screen])
            {
                q.emplace(t + 1, screen, screen);
                visited[screen][screen] = true;
            }

            // backspace
            if (!visited[screen - 1][clipboard])
            {
                q.emplace(t + 1, screen - 1, clipboard);
                visited[screen - 1][clipboard] = true;
            }
        }

        // ctrl v
        if (screen + clipboard < 2001 && !visited[screen + clipboard][clipboard])
        {
            q.emplace(t + 1, screen + clipboard, clipboard);
            visited[screen + clipboard][clipboard] = true;
        }
    }
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> s;
    solve();

    return 0;
}
