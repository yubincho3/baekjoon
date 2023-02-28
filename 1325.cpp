#include <bits/stdc++.h>
using namespace std;

vector<int> arr[10001];
bool v[10001];
int n, m, a, b;

int dfs(int now)
{
    int ret = 1;

    v[now] = true;
    for (int nxt: arr[now])
    {
        if (!v[nxt])
        {
            v[nxt] = true;
            ret += dfs(nxt);
        }
    }

    return ret;
}

vector<int> solve()
{
    vector<int> ret;
    int maxCnt = 0;

    for (int i = 1; i <= n; i++, memset(v, 0, sizeof(v)))
    {
        int res = dfs(i);

        if (res > maxCnt)
        {
            maxCnt = res;
            ret.clear();
        }

        if (res == maxCnt)
            ret.push_back(i);
    }

    return ret;
}

int main()
{
    for (scanf("%d %d", &n, &m); m--;)
    {
        scanf("%d %d", &a, &b);
        arr[b].push_back(a);
    }

    for (int i: solve())
        printf("%d ", i);

    return 0;
}
