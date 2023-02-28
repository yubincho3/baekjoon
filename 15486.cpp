#include <bits/stdc++.h>
using namespace std;

int arr[1500001][2];
int dp[1500051];
int n, t, p;

int solve(void)
{
	int ret = 0;
	
	for (int i = 1; i <= n + 1; i++)
	{
		ret = max(ret, dp[i]);
		
		if (i + arr[i][0] > n + 1)
			continue;
		
		dp[i + arr[i][0]] = max(dp[i + arr[i][0]], ret + arr[i][1]);
	}
	
	return ret;
}

int main(void)
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &arr[i][0], &arr[i][1]);
	
	printf("%d\n", solve());
	
	return 0;
}

