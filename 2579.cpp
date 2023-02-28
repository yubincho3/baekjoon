#include <bits/stdc++.h>
using namespace std;

int arr[301];
int dp[301][3];
int n;

int main(void)
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", arr + i);
	
	dp[1][1] = arr[1];
	dp[2][1] = arr[2];
	for (int i = 2; i <= n; i++)
	{
		dp[i][1] = max(dp[i][1], max(dp[i - 2][1], dp[i - 2][2]) + arr[i]);
		dp[i][2] = max(dp[i][2], dp[i - 1][1] + arr[i]);
	}
	
	printf("%d\n", max(dp[n][1], dp[n][2]));
	
	return 0;
}

