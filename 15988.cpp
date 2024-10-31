#include <bits/stdc++.h>
#define MAX_N 1000001
#define MOD 1000000009
using namespace std;

long long arr[MAX_N] = {0, 1, 2, 4};
int t, n;

int solve()
{
    if (arr[n] == 0)
    {
        for (int i = 4; i <= n; i++)
        {
            if (arr[i] != 0)
                continue;

            arr[i] = (arr[i - 1] + arr[i - 2] + arr[i - 3]) % MOD;
        }
    }

    return arr[n];
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    for (cin >> t; t--;)
    {
        cin >> n;
        cout << solve() << '\n';
    }

    return 0;
}
