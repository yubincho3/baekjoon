#include <bits/stdc++.h>
using namespace std;

stack<int> stk;
int arr[1001];
int dp[1001];
int n, idx, mx;

int main(void)
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]);
		
		for (int j = 1; j < i; j++)
			if (arr[j] < arr[i])
				dp[i] = max(dp[i], dp[j]);
		
		dp[i]++;
		
		if (mx < dp[i])
		{
			mx = dp[i];
			idx = i;
		}
	}
	
	for (int i = idx; i >= 1; i--)
	{
		if (dp[i] == mx)
		{
			stk.push(arr[i]);
			mx--;
		}
	}
	
	printf("%d\n", stk.size());
	while (!stk.empty())
	{
		printf("%d ", stk.top());
		stk.pop();
	}
	
	return 0;
}

