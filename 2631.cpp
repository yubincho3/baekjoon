#include <bits/stdc++.h>
using namespace std;

int arr[201];
int dp[201];
int n;

int solve(void)
{
	int ret = 0;
	
	for (int i = 0; i < n; i++)
	{
		int mx = 0;
		
		for (int j = 0; j < i; j++)
			if (arr[i] > arr[j])
				mx = max(mx, dp[j]);
		
		dp[i] = mx + 1;
		ret = max(ret, dp[i]);
	}
	
	return n - ret;
}

int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	
	printf("%d\n", solve());
	
	return 0;
}

