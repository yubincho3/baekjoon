#include <bits/stdc++.h>
using namespace std;

int arr[501];
int dp[501][501];
int sum[501];
int t, n;

int solve(void)
{
	for (int i = 1; i <= n; i++) // ±æÀÌ 
	{
		for (int j = 1; j <= n - i; j++) // ½ÃÀÛ ÀÎµ¦½º 
		{
			dp[j][i + j] = INT_MAX;
			for (int k = j; k < i + j; k++) // ÇÇº¿ 
			{
				int divided = dp[j][k] + dp[k + 1][i + j] + sum[i + j] - sum[j - 1];
				dp[j][i + j] = min(dp[j][i + j], divided);
			}
		}
	}
	
	return dp[1][n];
}

int main(void)
{
	for (scanf("%d", &t); t--;)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &arr[i]);
			sum[i] = sum[i - 1] + arr[i];
		}
		
		printf("%d\n", solve());
	}
	
	return 0;
}

