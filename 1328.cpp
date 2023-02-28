#include <bits/stdc++.h>
using namespace std;

long long dp[101][101][101]; // n, l, r
int n, l, r;

long long solve(void)
{
	dp[1][1][1] = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			for (int k = 1; k <= i; k++)
			{
				dp[i][j][k] = (dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] +
						       dp[i - 1][j][k] * (i - 2)) % 1000000007;
			}
		}
	}
	
	return dp[n][l][r];
}

int main(void)
{
	scanf("%d %d %d", &n, &l, &r);
	printf("%lld\n", solve());
	
	return 0;
}

