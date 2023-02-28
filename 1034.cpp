#include <bits/stdc++.h>

using namespace std;

char arr[51][51];
int n, m, k;

int solve(void)
{
    int ret = 0;

    for (int i = 0; i < n; i++)
    {
        int zero = 0;
        for (int j = 0; j < m; j++)
            zero += arr[i][j] == '0';

        if (zero <= k && zero % 2 == k % 2)
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
                cnt += !strcmp(arr[i], arr[j]);

            ret = max(ret, cnt);
        }
    }

    return ret;
}

int main(void)
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", arr[i]);
    scanf("%d", &k);

    printf("%d\n", solve());

    return 0;
}

