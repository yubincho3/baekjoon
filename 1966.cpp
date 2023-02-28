#include <bits/stdc++.h>
using namespace std;

queue<pair<int, int>> q;
vector<int> v;
int t, n, m, d;

int solve()
{
    int ret = 1;

    while (!q.empty())
    {
        if (q.front().first == v.back())
        {
            if (q.front().second == m)
                break;

            v.pop_back();
            ret++;
        }
        else
            q.push(q.front());

        q.pop();
    }

    while (!q.empty()) q.pop();
    v.clear();

    return ret;
}

int main()
{
    for (scanf("%d", &t); t--;)
    {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &d);
            v.push_back(d);
            q.push({d, i});
        }

        sort(v.begin(), v.end());
        printf("%d\n", solve());
    }

    return 0;
}
