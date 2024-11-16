#include <bits/stdc++.h>
using namespace std;

constexpr size_t MAX_N = 501;

bool arr[MAX_N][MAX_N];
int income[MAX_N];
int t[MAX_N];
int tc, n, m, a, b;

void solve()
{
    stack<int> s;

    for (int i = 1; i <= n; i++)
        if (income[i] == 0)
            s.push(i);

    vector<int> ans;
    bool uncertain = false;

    while (!s.empty())
    {
        if (s.size() > 1)
            uncertain = true;

        int now = s.top();

        ans.push_back(now);
        s.pop();

        for (int i = 1; i <= n; i++)
        {
            if (!arr[now][i])
                continue;

            if (--income[i] == 0)
                s.push(i);
        }
    }

    if (ans.size() < n)
        cout << "IMPOSSIBLE\n";
    else if (uncertain)
        cout << "?\n";
    else
    {
        for (const int i: ans)
            cout << i << ' ';
        cout << '\n';
    }
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    for (cin >> tc; tc--;)
    {
        memset(arr, false, sizeof arr);
        memset(income, 0, sizeof income);

        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> t[i];

            for (int j = 1; j < i; j++)
                arr[t[j]][t[i]] = true;
            income[t[i]] = i - 1;
        }

        for (cin >> m; m--;)
        {
            cin >> a >> b;
            if (arr[b][a])
                swap(a, b);

            arr[a][b] = false;
            arr[b][a] = true;
            income[b]--;
            income[a]++;
        }

        solve();
    }

    return 0;
}
