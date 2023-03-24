#include <bits/stdc++.h>
using namespace std;

int arr[1500001] = {0, 1};
long long n;

int solve()
{
    for (int i = 2; i < 1500000; i++)
        arr[i] = (arr[i - 1] + arr[i - 2]) % 1000000;

    return arr[n % 1500000];
}

int main()
{
    scanf("%lld", &n);
    printf("%d\n", solve());

    return 0;
}
