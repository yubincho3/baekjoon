#include <bits/stdc++.h>
using namespace std;

long long arr[100001];
int n;

long long solve()
{
    int row = 0;

    // 입력 최댓값인 10^18은 60자리 2진수
    for (int b = 59; b >= 0; b--)
    {
        // 현재 행의 b 자리가 1이 아니라면
        if (~arr[row] & 1ull << b)
        {
            bool doesntExist = true;

            for (int r = row + 1; r < n; r++)
            {
                // r번째 수는 b 자리가 1이라면
                if (arr[r] & 1ull << b)
                {
                    // 현재 수와 xor 연산하여 b 자리를 1로 만들어줌
                    arr[row] ^= arr[r];
                    doesntExist = false;
                    break;
                }
            }

            // 현재 비트 자리가 전부 0임
            if (doesntExist)
                continue;
        }

        // xor로 소거
        for (int i = 0; i < n; i++)
        {
            if (row == i || ~arr[i] & 1ull << b)
                continue;
            arr[i] ^= arr[row];
        }

        row++;
    }

    // 최댓값 계산
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
