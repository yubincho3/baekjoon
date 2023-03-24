#include <bits/stdc++.h>
using namespace std;

long long arr[100001];
int n;

// a[0]을 포함한다면, a의 나머지 원소는 홀수번 사용
// a[0]을 포함하지 않는다면, a의 나머지 원소는 짝수번 사용
// b[i] = a[0] ^ a[i](i != 0)로 한다.
// b[i]를 홀수번: a[0]과 a[i]의 사용횟수를 합치면 짝수가 된다.
// b[i]를 짝수번: a[0]과 a[i]의 사용횟수를 합치면 짝수가 된다.
long long solve()
{
    for (int i = n - 1; i >= 0; i--)
        arr[i] ^= arr[0];

    int piv = 0;

    // 최댓값인 10^18은 60자리 이진수
    for (int p = 59; p >= 0 && piv < n; p--)
    {
        if (~arr[piv] & 1ll << p)
        {
            bool doesntExist = true;

            for (int i = piv + 1; i < n; i++)
            {
                if (arr[i] & 1ll << p)
                {
                    arr[piv] ^= arr[i];
                    doesntExist = false;
                    break;
                }
            }

            if (doesntExist)
                continue;
        }

        for (int i = 0; i < n; i++)
        {
            if (piv == i || ~arr[i] & 1ll << p)
                continue;
            arr[i] ^= arr[piv];
        }

        piv++;
    }

    long long ret = 0;

    for (int i = 0; i < n; i++)
        ret ^= arr[i];

    return ret;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lld", &arr[i]);

    printf("%lld\n", solve());

    return 0;
}
