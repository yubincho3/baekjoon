#include <bits/stdc++.h>
using namespace std;
using Pair = pair<int, int>;

pair<int, int> arr[101];
int dp[101];
int n, ans;

int comp(const Pair& a, const Pair& b)
{
	return a.first < b.first;
}

int main(void)
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &arr[i].first, &arr[i].second);
	
	sort(arr + 1, arr + n + 1, comp);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if(arr[i].second > arr[j].second)
				dp[i] = max(dp[i], dp[j] + 1);
		}
		ans = max(ans, dp[i]);
	}
	
	printf("%d\n", n - ans);
	
	return 0;
}

