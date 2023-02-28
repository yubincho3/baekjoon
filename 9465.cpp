#include <bits/stdc++.h>
using namespace std;

int dp[2][1000001];
int t, n;

int main(void)
{
	for (scanf("%d", &t); t--;)
	{
		scanf("%d", &n);
		for (int i = 0; i < 2; i++)
			for (int j = 2; j < n + 2; j++)
				scanf("%d", &dp[i][j]);
		
		for (int j = 2; j < n + 2; j++)
		{
			dp[0][j] += max(dp[1][j - 1], dp[1][j - 2]);
			dp[1][j] += max(dp[0][j - 1], dp[0][j - 2]);
		}
		
		printf("%d\n", max(dp[0][n + 1], dp[1][n + 1]));
	}
	
	return 0;
}

