#include <bits/stdc++.h>
using namespace std;

bool dp[2001][2001];
int arr[2001];
int n, m, s, e;

int main(void)
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]);
		dp[i][i] = true;
	}
	
	for (int i = 2; i <= n; i++)
		dp[i - 1][i] = arr[i] == arr[i - 1];
	
	for (int i = 2; i < n; i++)
		for (int j = 1; j <= n - i; j++)
			if (arr[j] == arr[j + i] && dp[j + 1][j + i - 1])
				dp[j][j + i] = true;
	
	for (scanf("%d", &m); m--;)
	{
		scanf("%d %d", &s, &e);
		printf("%d\n", dp[s][e]);
	}
	
	return 0;
}

