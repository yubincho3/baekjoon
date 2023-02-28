#include <bits/stdc++.h>
using namespace std;

char arr[41];
int dp[41];

int solve(void)
{
	int len = strlen(arr);
	
	dp[0] = dp[1] = 1;
	for (int i = 2; i <= len; i++)
	{
		int a = arr[i - 2] - '0';
		int b = arr[i - 1] - '0';
		
		if (b != 0)
			dp[i] += dp[i - 1];
		
		if (a != 0 && 10 * a + b <= 34)
			dp[i] += dp[i - 2];
	}
	
	return dp[len];
}

int main(void)
{
	scanf("%s", arr);
	printf("%d\n", solve());
	
	return 0;
}

