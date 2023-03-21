#include <bits/stdc++.h>
using namespace std;

double m[1001][1001];
int n;

void solve()
{
    if (m[0][0] == 0)
    {
        printf("-1");
        return;
    }

    vector<vector<double>> l(n, vector<double>(n, 0));
    vector<vector<double>> u(n, vector<double>(n, 0));

    l[0][0] = 1;
    u[0][0] = m[0][0];
    u[0][1] = m[0][1];
    for (int i = 1; i < n; i++)
    {
        l[i][i] = 1;
        l[i][i - 1] = m[i][i - 1] / u[i - 1][i - 1];
        u[i][i] = m[i][i] - l[i][i - 1] * m[i - 1][i];

        if (u[i][i] == 0)
        {
            printf("-1");
            return;
        }

        if (i != n - 1)
            u[i][i + 1] = m[i][i + 1];
    }

    for (auto &r: l)
    {
        for (double a: r)
            printf("%.3lf ", a);
        printf("\n");
    }
    for (auto &r: u)
    {
        for (double a: r)
            printf("%.3lf ", a);
        printf("\n");
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%lf", &m[i][j]);

    solve();

    return 0;
}
