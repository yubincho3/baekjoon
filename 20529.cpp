#include <bits/stdc++.h>
using namespace std;

char str[100001][5];
int t, n;

int solve()
{
    int ret = INT_MAX;

    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                int sum = 0;

                for (int d = 0; d < 4; d++)
                    sum += (str[i][d] != str[j][d]) + (str[j][d] != str[k][d]) + (str[k][d] != str[i][d]);

                ret = min(ret, sum);
            }
        }
    }

    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    for (cin >> t; t--;)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> str[i];

        printf("%d\n", n > 32 ? 0 : solve());
    }

    return 0;
}
