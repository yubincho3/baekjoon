#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> arr;
int n, m, p;

void multMtrx(vector<vector<int>> &a, vector<vector<int>> &b)
{
    vector<vector<int>> multed(n, vector<int>(n, 0));

    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            for (int i = 0; i < n; i++)
            {
                multed[r][c] += a[r][i] * b[i][c];
                multed[r][c] %= m;
            }
            multed[r][c] %= m;
        }
    }

    swap(a, multed);
}

vector<vector<int>> solve()
{
    vector<vector<int>> ret(n, vector<int>(n, 0));

    for (int r = 0; r < n; r++)
        ret[r][r] = 1;

    while (p > 0)
    {
        if (p % 2 == 1)
            multMtrx(ret, arr);

        multMtrx(arr, arr);
        p /= 2;
    }

    arr.clear();

    return ret;
}

int main()
{
    while (true)
    {
        scanf("%d %d %d", &n, &m, &p);

        if (!(n + m + p))
            break;

        for (int r = 0; r < n; r++)
        {
            arr.emplace_back(n, 0);
            for (int c = 0; c < n; c++)
                scanf("%d", &arr[r][c]);
        }

        for (auto &v: solve())
        {
            for (int a: v)
                printf("%d ", a);
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}
