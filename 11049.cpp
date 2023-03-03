#include <bits/stdc++.h>
using namespace std;

int arr[501][2]; // 행의 길이, 열의 길이 순서로 저장
int dp[501][501]; // a부터 b번째 행렬까지 계산하는 최솟값
int n;

int solve()
{
    // 시작점 기준으로 그 다음 몇 번째 행렬까지를 구간으로 할지
    for (int i = 1; i < n; i++)
    {
        // 구간의 시작점
        // 구간은 [j, i + j]
        for (int j = 1; i + j <= n; j++)
        {
            dp[j][i + j] = INT_MAX;
            // 구간을 2개로 나누는 피봇
            // [j, k]와 [k + 1, i + j] 두 구간의 행렬을 합침
            for (int k = j; k <= i + j; k++)
            {
                dp[j][i + j] = min(dp[j][k] + dp[k + 1][i + j] +
                                   arr[j][0] * arr[k][1] * arr[i + j][1], dp[j][i + j]);
            }
        }
    }

    return dp[1][n];
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d %d", &arr[i][0], &arr[i][1]);

    printf("%d\n", solve());

    return 0;
}
