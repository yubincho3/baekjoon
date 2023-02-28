#include <bits/stdc++.h>
using namespace std;

int arr[100001];
int n, s;

int solve()
{
    int lIdx = 0, rIdx = 0;
    int sum = arr[0];
    int ret = n + 1;

    while (lIdx <= rIdx && rIdx < n)
    {
        if (sum < s)
            sum += arr[++rIdx];
        else
        {
            ret = min(ret, rIdx - lIdx + 1);
            sum -= arr[lIdx++];
        }
    }

    return (ret > n ? 0 : ret);
}

int main()
{
    scanf("%d %d", &n, &s);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("%d\n", solve());

    return 0;
}
