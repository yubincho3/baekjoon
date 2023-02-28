#include <bits/stdc++.h>
using namespace std;

int dp[4001][4001];
char str1[4001];
char str2[4001];

int solve(void)
{
	int ret = 0;
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	
	for (int i = 1; i <= len1; i++)
	{
		for (int j = 1; j <= len2; j++)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
				ret = max(ret, dp[i][j]);
			}
		}
	}
	
	return ret;
}

int main(void)
{
	scanf("%s %s", str1, str2);
	printf("%d\n", solve());
	
	return 0;
}

