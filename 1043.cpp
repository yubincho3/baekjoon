#include <bits/stdc++.h>
using namespace std;

vector<int> party[51];
vector<int> truth;
int parent[51];
int n, m, k, c, p;

int find(int x)
{
    if (x == parent[x])
        return x;

    return parent[x] = find(parent[x]);
}

int solve()
{
    int ret = m;

    for (int i = 1; i <= n; i++)
        parent[i] = i;

    for (int i = 0; i < m; i++)
    {
        int x = party[i][0];

        for (int j = 1; j < party[i].size(); j++)
        {
            int y = party[i][j];
            parent[find(y)] = find(x);
        }
    }

    for (int i = 0; i < m; i++)
    {
        bool flag = true;

        for (int j = 0; j < party[i].size() && flag; j++)
        {
            int x = party[i][j];

            for (int k = 0; k < truth.size() && flag; k++)
            {
                int y = truth[k];

                if (find(x) == find(y))
                    flag = false;
            }
        }

        ret -= !flag;
    }

    return ret;
}

int main()
{
    for (scanf("%d %d %d", &n, &m, &k); k--;)
    {
        scanf("%d", &p);
        truth.push_back(p);
    }
    for (int i = 0; i < m; i++)
    {
        for (scanf("%d", &c); c--;)
        {
            scanf("%d", &p);
            party[i].push_back(p);
        }
    }

    printf("%d\n", solve());

    return 0;
}
