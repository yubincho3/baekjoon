#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool arr[1000001];
ll mn, mx;

int solve()
{
    int ret = 0;

    for (ll i = 2; i * i <= mx; i++)
    {
        ll n = mn / (i * i) + !!(mn % (i * i));

        while (n * i * i <= mx)
            arr[n++ * i * i - mn] = true;
    }

    for (int i = 0; i <= mx - mn; i++)
        ret += !arr[i];

    return ret;
}

int main()
{
    scanf("%lld %lld", &mn, &mx);
    printf("%d\n", solve());

    return 0;
}