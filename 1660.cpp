#include <bits/stdc++.h>
using namespace std;

int dp[1025][1025];
int n, m, t;

int main(void)
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &t);
			dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + t;
		}
	}
	
	while (m--)
	{
		int r1, c1, r2, c2;
		scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
		printf("%d\n", dp[r2][c2] - dp[r2][c1 - 1] - dp[r1 - 1][c2] + dp[r1 - 1][cz1 - 1]);
	}
	
	return 0;
}

